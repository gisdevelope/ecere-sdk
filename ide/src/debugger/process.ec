default:
#define uint _uint

#include <unistd.h>
#ifdef __WIN32__
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>
#else

#define uint _uint
#define property _property
#define new _new
#define class _class
#define Window    X11Window
#define Cursor    X11Cursor
#define Font      X11Font
#define Display   X11Display
#define Time      X11Time
#define KeyCode   X11KeyCode

#include <signal.h>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xresource.h>
#include <X11/Xutil.h>
#include <sys/fcntl.h>

#undef Window
#undef Cursor
#undef Font
#undef Display
#undef Time
#undef KeyCode
#undef uint
#undef new
#undef property
#undef class

#endif
#undef uint

private:

import "ide"

#ifdef __WIN32__
static bool CALLBACK EnumWindowsBringToTop(HWND hwnd, LPARAM lParam)
{
   int pid;
   GetWindowThreadProcessId(hwnd, &pid);
   if(pid == lParam)
      BringWindowToTop(hwnd);
   return true;
}

static bool CALLBACK EnumWindowsSetForeground(HWND hwnd, LPARAM lParam)
{
   int pid;
   GetWindowThreadProcessId(hwnd, &pid);
   if(pid == lParam)
   {
      for(;;)
      {
         HWND parent = GetParent(hwnd);
         if(parent) hwnd = parent; else break;
      }
      SetForegroundWindow(hwnd); //SetForegroundWindow( GetAncestor(hwnd, GA_ROOTOWNER));
      return false;                                                                  
   }
   return true;
}

class ShowProcessWindowsThread : Thread
{
   int processId;
   unsigned int Main()
   {
      if(processId)
      {
         EnumWindows(EnumWindowsSetForeground, processId);
         EnumWindows(EnumWindowsBringToTop, processId);
      }
      return 0;
   }
}
#else

extern void * __attribute__((stdcall)) IS_XGetDisplay();
static Atom xa_NET_WM_PID, xa_activeWindow;

static void WaitForViewableWindow(X11Display * xGlobalDisplay, X11Window * window)
{
   int c;
   XFlush(xGlobalDisplay);
   for(c = 0; c<4; c++) 
   // while(true)
   {
      XWindowAttributes attributes = { 0 };
      XGetWindowAttributes(xGlobalDisplay, (uint)window, &attributes);
      if(attributes.map_state == IsViewable)
         break;
      else
         Sleep(1.0 / 18.2);
   }
}

static void EnumWindowBringToTop(X11Display * xGlobalDisplay, X11Window window, int processId)
{
   Atom xa_type;
   X11Window * root = null, * parent = null, ** children = null;
   int numWindows = 0;
   int format, len, fill;

   if(XQueryTree(xGlobalDisplay, window, (uint *)&root, (uint *)&parent, (uint **)&children, &numWindows))
   {
      int c;
      for(c = 0; c<numWindows; c++)
      {
         byte * data;
         if(XGetWindowProperty(xGlobalDisplay, (uint)children[c], xa_NET_WM_PID, 0, 1, False,
                               XA_CARDINAL, &xa_type, &format, &len, &fill,
                               &data) != Success)
         {
            // printf("cant get _NET_WM_PID property\n");
            break;
         }
      
         if(data)
         {
            int pid = *(int *)data;
            //printf("pid: %d\n", pid);
            if(pid == processId)
            {
               // printf("Found one window with processID\n");
               {
                  XRaiseWindow(xGlobalDisplay, (uint)children[c]);
                  WaitForViewableWindow(xGlobalDisplay, children[c]);
                  if(xa_activeWindow)
                  {
                     XClientMessageEvent event = { 0 };
                     event.type = ClientMessage;
                     event.message_type = xa_activeWindow;
                     event.display = xGlobalDisplay;
                     event.serial = 0;
                     event.window = (uint)children[c];
                     event.send_event = 1;
                     event.format = 32;
                     event.data.l[0] = 0;
                     
                     XSendEvent(xGlobalDisplay, DefaultRootWindow(xGlobalDisplay), bool::false, SubstructureRedirectMask | SubstructureNotifyMask, (union _XEvent *)&event);
                  }
                  else
                     XSetInputFocus(xGlobalDisplay, (uint)children[c], RevertToPointerRoot, CurrentTime);
               }
            }
         }
         else
            EnumWindowBringToTop(xGlobalDisplay, (uint)children[c], processId);
      }
   }
   if(children)
      XFree(children);
}

#endif

void Process_ShowWindows(int processId)
{
#ifdef __WIN32__
   ShowProcessWindowsThread thread { processId = processId };
   thread.Create();
#else
   if(processId)
   {
      X11Display * xGlobalDisplay = IS_XGetDisplay();
      xa_NET_WM_PID = XInternAtom(xGlobalDisplay, "_NET_WM_PID", True);
      xa_activeWindow = XInternAtom(xGlobalDisplay, "_NET_ACTIVE_WINDOW", True);
      EnumWindowBringToTop(xGlobalDisplay, DefaultRootWindow(xGlobalDisplay), processId);
   }
#endif
}

bool Process_Break(int processId)
{
   bool result = false;
#ifdef __WIN32__
   HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
   if(handle)
   {
      DWORD remoteThreadId;
      HANDLE hRemoteThread;
      static void * debugBreakAddress;
      if(!debugBreakAddress)
      {
         HINSTANCE hDll = LoadLibrary("kernel32");
         debugBreakAddress = GetProcAddress(hDll, "DebugBreak");
         FreeLibrary(hDll);
      }
      hRemoteThread = CreateRemoteThread(handle, null, 0, debugBreakAddress, 0, 0, &remoteThreadId);
      if(hRemoteThread)
      {
         //DebugBreakProcess(handle);  // this worked only in winxp, right?
         //GenerateConsoleCtrlEvent(CTRL_C_EVENT, processId);  // this had no effect, right?
         result = true;
         CloseHandle(hRemoteThread);
      }
      CloseHandle(handle);
   }
#else
   kill(processId, SIGTRAP);
   result = true;
#endif
   return result;
}

int Process_GetCurrentProcessId()
{
#ifdef __WIN32__
   DWORD currentProcessId = GetCurrentProcessId();
   return currentProcessId;
#else
   return (int)getpid();
#endif
}

int Process_GetChildExeProcessId(const int parentProcessId, const char * exeFile)
{
#ifdef __WIN32__
   HANDLE hProcessSnap;
   PROCESSENTRY32 pe32;
   
   int childProcessId = 0;
   
   hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
   
   if(hProcessSnap != INVALID_HANDLE_VALUE)
   {
      pe32.dwSize = sizeof(PROCESSENTRY32);
   
      if(Process32First(hProcessSnap, &pe32))
      {
         do
         {
            if(pe32.th32ParentProcessID == parentProcessId)
            {
               //if(strstr(exeFile, pe32.szExeFile) == exeFile)
               if(SearchString(exeFile, 0, pe32.szExeFile, false, false) == exeFile)
               {
                  childProcessId = pe32.th32ProcessID;
                  break;
               }
            }
         } while(Process32Next(hProcessSnap, &pe32));
      }
      CloseHandle(hProcessSnap);
   }
   return childProcessId;
#elif defined(__linux__)
   FileListing listing { "/proc/" };
   while(listing.Find())
   {
      if(listing.stats.attribs.isDirectory)
      {
         int process = atoi(listing.name);
         if(process)
         {
            int ppid = 0;
            bool found = false;
            char fileName[256];
            File f;
            strcpy(fileName, listing.path);
            PathCat(fileName, "status");
            if((f = FileOpen(fileName, read)))
            {
               char buffer[256];
               while(f.GetLine(buffer, 256))
               {
                  if(!strncmp(buffer, "Name:", 5))
                  {
                     char * string = strstr(buffer + 6, exeFile);
                     if(!string || strcmp(string, exeFile))
                        break;
                     found = true;
                  }
                  else if(!strncmp(buffer, "PPid:", 5))
                  {
                     ppid = atoi(buffer + 6);
                     break;
                  }
               }
               delete f;
            }
            if(found && ppid == parentProcessId)
            {
               listing.Stop();
               return process;
            }
         }
      }
   }
   return 0;
#endif
}
