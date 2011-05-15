import "ide"

class NodeProperties : Window
{
   tabCycle = true;
   background = activeBorder;
   hasClose = true;
   borderStyle = sizable;
   isModal = true;
   text = "Properties";
   //size = { 280, 260 };

   ProjectNode node, topNode;

   Label pathLabel { parent = this, position = { 10, 60 }, labeledWindow = path };
   EditBox path
   {
      this, textHorzScroll = true, position = { 10, 80 }, size = { 260 }, text = "Path";
      anchor = { left = 10, top = 80, right = 10 };
   };
   
   Label absolutePathLabel { parent = this, position = { 10, 110 }, labeledWindow = absolutePath };
   EditBox absolutePath
   {
      this, background = activeBorder, textHorzScroll = true, readOnly = true;
      position = { 10, 130 }, size = { 260 }, text = "Absolute Path";
      anchor = { left = 10, top = 130, right = 10 };
   };
   
   Label nameLabel { parent = this, position = { 10, 10 }, labeledWindow = name };
   EditBox name
   {
      this, textHorzScroll = true, position = { 10, 30 }, size = { 260 }, text = "Name";
      anchor = { left = 10, top = 30, right = 10 };
      NotifyModified = NameNotifyModified;
   };

   bool NameNotifyModified(EditBox editBox)
   {
      char filePath[MAX_LOCATION];
      char * oldName = node.name;

      node.name = null;
      GetLastDirectory(name.contents, filePath);
      if(topNode.Find(filePath, false))
      {
         MessageBox { type = ok, master = this, text = filePath, contents = "File with same name already in project." }.Modal();
         node.name = oldName;
         return false;
      }
      delete oldName;
      node.name = CopyString(filePath);
      if(node.type == folder)
      {
         strcpy(filePath, (node.parent.type == project) ? "" : node.parent.path);
         PathCatSlash(filePath, node.name);
         delete node.path;
         node.path = CopyString(filePath);
         MakeSystemPath(filePath);
         path.contents = filePath;
      }

      UpdateFileName();
      return true;
   }

   bool PathNotifyModified(EditBox editBox)
   {
      delete node.path;
      node.path = CopyUnixPath(path.contents);

      if(node.type == resources)
      {
         master.modifiedDocument = true;
         node.project.topNode.modified = true;
         ide.projectView.Update(null);
      }
      else
         UpdateFileName();
      return true;
   }

   property ProjectNode node
   {
      set
      {
         Size minSize = { 280, 260 };
         
         // name              { 10,  10 }    { 10,  30 }
         // path              { 10,  60 }    { 10,  80 }
         // absolutePath      { 10, 110 }    { 10, 130 }

         node = value;
         if(node)
         {
            for(topNode = node; topNode && topNode.parent; topNode = topNode.parent);

            switch(node.type)
            {
               case project:
               {
                  minSize.h = 160;
                  QuickReadOnly(path);
                  break;
               }
               case file:
               {
                  minSize.h = 160;
                  break;
               }
               case folder:
               case resources:
               {
                  minSize.h = 110;
                  absolutePath.visible = false;
                  absolutePathLabel.visible = false;
                  if(node.type == resources) QuickReadOnly(name);
                  break;
               }
            }

            // project:    - name path absolute - 
            // file
            //   in res:   - name path absolute - 
            //   not:      - name path absolute - 
            // folder:     - name               -
            // resources:  - name path          -
            
            name.contents = node.name;
            {
               char temp[MAX_LOCATION];
               path.contents = node.path ? GetSystemPathBuffer(temp, node.path) : "";
            }
            if(node.type != folder && node.type != resources)
            {
               char filePath[MAX_LOCATION];
               GetSystemPathBuffer(filePath, topNode.path);
               if(node.path) PathCat(filePath, node.path);
               PathCat(filePath, node.name);
               if(node.type == project)
                  ChangeExtension(filePath, ProjectExtension, filePath);
               absolutePath.contents = filePath;
            }
         }
         minClientSize = minSize;
      }
   }

   void QuickReadOnly(EditBox editBox)
   {
      editBox.textHorzScroll = true;
      editBox.readOnly = true;
      editBox.background = activeBorder;
   }

   bool OnKeyDown(Key key, unichar ch)
   {
      if(key == escape || key == enter || key == keyPadEnter)
      {
         Destroy(0);
         return false;
      }
      return true;
   }

   void OnDestroy()
   {
      if(!node.name || strcmp(name.contents, node.name))
         NameNotifyModified(name);
      {
         String s = CopyUnixPath(path.contents);
         if(strcmp(s, node.path))
            PathNotifyModified(path);
         delete s;
      }
   }

   void UpdateFileName()
   {
      char filePath[MAX_LOCATION];
      Project prj = node.project;

      GetSystemPathBuffer(filePath, topNode.path);
      PathCat(filePath, node.path);
      PathCat(filePath, node.name);
      if(node.type == project)
      {
         ChangeExtension(filePath, ProjectExtension, filePath);
         absolutePath.contents = filePath;
         master.fileName = filePath;
      }
      else
         absolutePath.contents = filePath;

      name.modifiedDocument = false;
      if(path)
         path.modifiedDocument = false;
      if(absolutePath)
         absolutePath.modifiedDocument = false;

      if(prj)
      {
         master.modifiedDocument = true;
         prj.topNode.modified = true;
         ide.projectView.Update(null);
         prj.ModifiedAllConfigs(true, false, false, true);
      }
   }
}
