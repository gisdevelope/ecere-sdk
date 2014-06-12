/* Code generated from eC source file: freeAst.ec */
#if defined(_WIN32)
#define __runtimePlatform 1
#elif defined(__APPLE__)
#define __runtimePlatform 3
#else
#define __runtimePlatform 2
#endif
#if defined(__GNUC__)
typedef long long int64;
typedef unsigned long long uint64;
#ifndef _WIN32
#define __declspec(x)
#endif
#elif defined(__TINYC__)
#include <stdarg.h>
#define __builtin_va_list va_list
#define __builtin_va_start va_start
#define __builtin_va_end va_end
#ifdef _WIN32
#define strcasecmp stricmp
#define strncasecmp strnicmp
#define __declspec(x) __attribute__((x))
#else
#define __declspec(x)
#endif
typedef long long int64;
typedef unsigned long long uint64;
#else
typedef __int64 int64;
typedef unsigned __int64 uint64;
#endif
#ifdef __BIG_ENDIAN__
#define __ENDIAN_PAD(x) (8 - (x))
#else
#define __ENDIAN_PAD(x) 0
#endif
#include <stdint.h>
#include <sys/types.h>

#if /*defined(_W64) || */(defined(__WORDSIZE) && __WORDSIZE == 8) || defined(__x86_64__)
#define _64BIT 1
#else
#define _64BIT 0
#endif

#define arch_PointerSize                  sizeof(void *)
#define structSize_Instance               (_64BIT ? 24 : 12)
#define structSize_Module                 (_64BIT ? 560 : 300)

struct __ecereNameSpace__ecere__com__Instance;

extern void *  __ecereNameSpace__ecere__com__eSystem_New(unsigned int size);

extern void *  __ecereNameSpace__ecere__com__eSystem_New0(unsigned int size);

extern void *  __ecereNameSpace__ecere__com__eSystem_Renew(void *  memory, unsigned int size);

extern void *  __ecereNameSpace__ecere__com__eSystem_Renew0(void *  memory, unsigned int size);

extern void __ecereNameSpace__ecere__com__eSystem_Delete(void *  memory);

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__BTNode;

struct __ecereNameSpace__ecere__sys__BTNode;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__BinaryTree;

struct __ecereNameSpace__ecere__sys__BinaryTree
{
struct __ecereNameSpace__ecere__sys__BTNode * root;
int count;
int (*  CompareKey)(struct __ecereNameSpace__ecere__sys__BinaryTree * tree, uintptr_t a, uintptr_t b);
void (*  FreeKey)(void *  key);
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__OldList;

struct __ecereNameSpace__ecere__sys__OldList
{
void *  first;
void *  last;
int count;
unsigned int offset;
unsigned int circ;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Method;

struct __ecereNameSpace__ecere__com__Method
{
const char *  name;
struct __ecereNameSpace__ecere__com__Method * parent;
struct __ecereNameSpace__ecere__com__Method * left;
struct __ecereNameSpace__ecere__com__Method * right;
int depth;
int (*  function)();
int vid;
int type;
struct __ecereNameSpace__ecere__com__Class * _class;
void *  symbol;
const char *  dataTypeString;
struct Type * dataType;
int memberAccess;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Property;

struct __ecereNameSpace__ecere__com__Property
{
struct __ecereNameSpace__ecere__com__Property * prev;
struct __ecereNameSpace__ecere__com__Property * next;
const char *  name;
unsigned int isProperty;
int memberAccess;
int id;
struct __ecereNameSpace__ecere__com__Class * _class;
const char *  dataTypeString;
struct __ecereNameSpace__ecere__com__Class * dataTypeClass;
struct Type * dataType;
void (*  Set)(void * , int);
int (*  Get)(void * );
unsigned int (*  IsSet)(void * );
void *  data;
void *  symbol;
int vid;
unsigned int conversion;
unsigned int watcherOffset;
const char *  category;
unsigned int compiled;
unsigned int selfWatchable;
unsigned int isWatchable;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_CodePosition;

struct CodePosition
{
int line;
int charPos;
int pos;
int included;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Location;

struct Location
{
struct CodePosition start;
struct CodePosition end;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Attrib;

struct Attrib
{
struct Location loc;
int type;
struct __ecereNameSpace__ecere__sys__OldList *  attribs;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ExtDecl;

struct ExtDecl
{
struct Location loc;
int type;
union
{
char * s;
struct Attrib * attr;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassDefinition;

struct ClassDefinition
{
struct ClassDefinition * prev;
struct ClassDefinition * next;
struct Location loc;
struct Specifier * _class;
struct __ecereNameSpace__ecere__sys__OldList *  baseSpecs;
struct __ecereNameSpace__ecere__sys__OldList *  definitions;
struct Symbol * symbol;
struct Location blockStart;
struct Location nameLoc;
int endid;
int declMode;
unsigned int deleteWatchable;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Context;

struct Context
{
struct Context * parent;
struct __ecereNameSpace__ecere__sys__BinaryTree types;
struct __ecereNameSpace__ecere__sys__BinaryTree classes;
struct __ecereNameSpace__ecere__sys__BinaryTree symbols;
struct __ecereNameSpace__ecere__sys__BinaryTree structSymbols;
int nextID;
int simpleID;
struct __ecereNameSpace__ecere__sys__BinaryTree templateTypes;
struct ClassDefinition * classDef;
unsigned int templateTypesOnly;
unsigned int hasNameSpace;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Instantiation;

struct Instantiation
{
struct Instantiation * prev;
struct Instantiation * next;
struct Location loc;
struct Specifier * _class;
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList *  members;
struct Symbol * symbol;
unsigned int fullSet;
unsigned int isConstant;
unsigned char *  data;
struct Location nameLoc;
struct Location insideLoc;
unsigned int built;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Declaration;

struct Declaration
{
struct Declaration * prev;
struct Declaration * next;
struct Location loc;
int type;
union
{
struct
{
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct __ecereNameSpace__ecere__sys__OldList *  declarators;
} __attribute__ ((gcc_struct)) __anon1;
struct Instantiation * inst;
struct
{
struct Identifier * id;
struct Expression * exp;
} __attribute__ ((gcc_struct)) __anon2;
} __attribute__ ((gcc_struct)) __anon1;
struct Specifier * extStorage;
struct Symbol * symbol;
int declMode;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Statement;

struct Statement
{
struct Statement * prev;
struct Statement * next;
struct Location loc;
int type;
union
{
struct __ecereNameSpace__ecere__sys__OldList *  expressions;
struct
{
struct Identifier * id;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) labeled;
struct
{
struct Expression * exp;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) caseStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * declarations;
struct __ecereNameSpace__ecere__sys__OldList * statements;
struct Context * context;
unsigned int isSwitch;
} __attribute__ ((gcc_struct)) compound;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
struct Statement * elseStmt;
} __attribute__ ((gcc_struct)) ifStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) switchStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) whileStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) doWhile;
struct
{
struct Statement * init;
struct Statement * check;
struct __ecereNameSpace__ecere__sys__OldList * increment;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) forStmt;
struct
{
struct Identifier * id;
} __attribute__ ((gcc_struct)) gotoStmt;
struct
{
struct Specifier * spec;
char * statements;
struct __ecereNameSpace__ecere__sys__OldList * inputFields;
struct __ecereNameSpace__ecere__sys__OldList * outputFields;
struct __ecereNameSpace__ecere__sys__OldList * clobberedFields;
} __attribute__ ((gcc_struct)) asmStmt;
struct
{
struct Expression * watcher;
struct Expression * object;
struct __ecereNameSpace__ecere__sys__OldList * watches;
} __attribute__ ((gcc_struct)) _watch;
struct
{
struct Identifier * id;
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct __ecereNameSpace__ecere__sys__OldList * filter;
struct Statement * stmt;
} __attribute__ ((gcc_struct)) forEachStmt;
struct Declaration * decl;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TypeName;

struct TypeName
{
struct TypeName * prev;
struct TypeName * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  qualifiers;
struct Declarator * declarator;
int classObjectType;
struct Expression * bitCount;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Initializer;

struct Initializer
{
struct Initializer * prev;
struct Initializer * next;
struct Location loc;
int type;
union
{
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList *  list;
} __attribute__ ((gcc_struct)) __anon1;
unsigned int isConstant;
struct Identifier * id;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__DataValue;

struct __ecereNameSpace__ecere__com__DataValue
{
union
{
char c;
unsigned char uc;
short s;
unsigned short us;
int i;
unsigned int ui;
void *  p;
float f;
double d;
long long i64;
uint64 ui64;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Expression;

struct Expression
{
struct Expression * prev;
struct Expression * next;
struct Location loc;
int type;
union
{
struct
{
char *  constant;
struct Identifier * identifier;
} __attribute__ ((gcc_struct)) __anon1;
struct Statement * compound;
struct Instantiation * instance;
struct
{
char *  string;
unsigned int intlString;
unsigned int wideString;
} __attribute__ ((gcc_struct)) __anon2;
struct __ecereNameSpace__ecere__sys__OldList *  list;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * specifiers;
struct Declarator * decl;
} __attribute__ ((gcc_struct)) _classExp;
struct
{
struct Identifier * id;
} __attribute__ ((gcc_struct)) classData;
struct
{
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList * arguments;
struct Location argLoc;
} __attribute__ ((gcc_struct)) call;
struct
{
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList * index;
} __attribute__ ((gcc_struct)) index;
struct
{
struct Expression * exp;
struct Identifier * member;
int memberType;
unsigned int thisPtr;
} __attribute__ ((gcc_struct)) member;
struct
{
int op;
struct Expression * exp1;
struct Expression * exp2;
} __attribute__ ((gcc_struct)) op;
struct TypeName * typeName;
struct Specifier * _class;
struct
{
struct TypeName * typeName;
struct Expression * exp;
} __attribute__ ((gcc_struct)) cast;
struct
{
struct Expression * cond;
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Expression * elseExp;
} __attribute__ ((gcc_struct)) cond;
struct
{
struct TypeName * typeName;
struct Expression * size;
} __attribute__ ((gcc_struct)) _new;
struct
{
struct TypeName * typeName;
struct Expression * size;
struct Expression * exp;
} __attribute__ ((gcc_struct)) _renew;
struct
{
char * table;
struct Identifier * id;
} __attribute__ ((gcc_struct)) db;
struct
{
struct Expression * ds;
struct Expression * name;
} __attribute__ ((gcc_struct)) dbopen;
struct
{
struct TypeName * typeName;
struct Initializer * initializer;
} __attribute__ ((gcc_struct)) initializer;
struct
{
struct Expression * exp;
struct TypeName * typeName;
} __attribute__ ((gcc_struct)) vaArg;
} __attribute__ ((gcc_struct)) __anon1;
unsigned int debugValue;
struct __ecereNameSpace__ecere__com__DataValue val;
uint64 address;
unsigned int hasAddress;
struct Type * expType;
struct Type * destType;
unsigned int usage;
int tempCount;
unsigned int byReference;
unsigned int isConstant;
unsigned int addedThis;
unsigned int needCast;
unsigned int thisPtr;
unsigned int opDestType;
unsigned int needTemplateCast;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplateDatatype;

struct TemplateDatatype
{
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * decl;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplateArgument;

struct TemplateArgument
{
struct TemplateArgument * prev;
struct TemplateArgument * next;
struct Location loc;
struct Identifier * name;
int type;
union
{
struct Expression * expression;
struct Identifier * identifier;
struct TemplateDatatype * templateDatatype;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplateParameter;

struct TemplateParameter
{
struct TemplateParameter * prev;
struct TemplateParameter * next;
struct Location loc;
int type;
struct Identifier * identifier;
union
{
struct TemplateDatatype * dataType;
int memberType;
} __attribute__ ((gcc_struct)) __anon1;
struct TemplateArgument * defaultArgument;
const char *  dataTypeString;
struct Type * baseType;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Specifier;

struct Specifier
{
struct Specifier * prev;
struct Specifier * next;
struct Location loc;
int type;
union
{
int specifier;
struct
{
struct ExtDecl * extDecl;
char *  name;
struct Symbol * symbol;
struct __ecereNameSpace__ecere__sys__OldList *  templateArgs;
} __attribute__ ((gcc_struct)) __anon1;
struct
{
struct Identifier * id;
struct __ecereNameSpace__ecere__sys__OldList *  list;
struct __ecereNameSpace__ecere__sys__OldList *  baseSpecs;
struct __ecereNameSpace__ecere__sys__OldList *  definitions;
unsigned int addNameSpace;
struct Context * ctx;
struct ExtDecl * extDeclStruct;
} __attribute__ ((gcc_struct)) __anon2;
struct Expression * expression;
struct Specifier * _class;
struct TemplateParameter * templateParameter;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Identifier;

struct Identifier
{
struct Identifier * prev;
struct Identifier * next;
struct Location loc;
struct Symbol * classSym;
struct Specifier * _class;
char *  string;
struct Identifier * badID;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Pointer;

struct Pointer
{
struct Pointer * prev;
struct Pointer * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  qualifiers;
struct Pointer * pointer;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Declarator;

struct Declarator
{
struct Declarator * prev;
struct Declarator * next;
struct Location loc;
int type;
struct Symbol * symbol;
struct Declarator * declarator;
union
{
struct Identifier * identifier;
struct
{
struct Expression * exp;
struct Expression * posExp;
struct Attrib * attrib;
} __attribute__ ((gcc_struct)) structDecl;
struct
{
struct Expression * exp;
struct Specifier * enumClass;
} __attribute__ ((gcc_struct)) array;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * parameters;
} __attribute__ ((gcc_struct)) function;
struct
{
struct Pointer * pointer;
} __attribute__ ((gcc_struct)) pointer;
struct
{
struct ExtDecl * extended;
} __attribute__ ((gcc_struct)) extended;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_FunctionDefinition;

struct FunctionDefinition
{
struct FunctionDefinition * prev;
struct FunctionDefinition * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * declarator;
struct __ecereNameSpace__ecere__sys__OldList *  declarations;
struct Statement * body;
struct __ecereNameSpace__ecere__com__Class * _class;
struct __ecereNameSpace__ecere__sys__OldList attached;
int declMode;
struct Type * type;
struct Symbol * propSet;
int tempCount;
unsigned int propertyNoThis;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_DBTableDef;

struct DBTableDef
{
char *  name;
struct Symbol * symbol;
struct __ecereNameSpace__ecere__sys__OldList *  definitions;
int declMode;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_External;

struct External
{
struct External * prev;
struct External * next;
struct Location loc;
int type;
struct Symbol * symbol;
union
{
struct FunctionDefinition * function;
struct ClassDefinition * _class;
struct Declaration * declaration;
char *  importString;
struct Identifier * id;
struct DBTableDef * table;
} __attribute__ ((gcc_struct)) __anon1;
int importType;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ModuleImport;

struct ModuleImport
{
struct ModuleImport * prev;
struct ModuleImport * next;
char *  name;
struct __ecereNameSpace__ecere__sys__OldList classes;
struct __ecereNameSpace__ecere__sys__OldList functions;
int importType;
int importAccess;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassImport;

struct ClassImport
{
struct ClassImport * prev;
struct ClassImport * next;
char *  name;
struct __ecereNameSpace__ecere__sys__OldList methods;
struct __ecereNameSpace__ecere__sys__OldList properties;
unsigned int itself;
int isRemote;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Symbol;

struct Symbol
{
char *  string;
struct Symbol * parent;
struct Symbol * left;
struct Symbol * right;
int depth;
struct Type * type;
union
{
struct __ecereNameSpace__ecere__com__Method * method;
struct __ecereNameSpace__ecere__com__Property * _property;
struct __ecereNameSpace__ecere__com__Class * registered;
} __attribute__ ((gcc_struct)) __anon1;
int id;
int idCode;
union
{
struct
{
struct External * pointerExternal;
struct External * structExternal;
} __attribute__ ((gcc_struct)) __anon1;
struct
{
struct External * externalGet;
struct External * externalSet;
struct External * externalPtr;
struct External * externalIsSet;
} __attribute__ ((gcc_struct)) __anon2;
struct
{
struct External * methodExternal;
struct External * methodCodeExternal;
} __attribute__ ((gcc_struct)) __anon3;
} __attribute__ ((gcc_struct)) __anon2;
unsigned int imported;
unsigned int declaredStructSym;
struct __ecereNameSpace__ecere__com__Class * _class;
unsigned int declaredStruct;
unsigned int needConstructor;
unsigned int needDestructor;
char *  constructorName;
char *  structName;
char *  className;
char *  destructorName;
struct ModuleImport * module;
struct ClassImport * _import;
struct Location nameLoc;
unsigned int isParam;
unsigned int isRemote;
unsigned int isStruct;
unsigned int fireWatchersDone;
int declaring;
unsigned int classData;
unsigned int isStatic;
char *  shortName;
struct __ecereNameSpace__ecere__sys__OldList *  templateParams;
struct __ecereNameSpace__ecere__sys__OldList templatedClasses;
struct Context * ctx;
int isIterator;
struct Expression * propCategory;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Type;

struct Type
{
struct Type * prev;
struct Type * next;
int refCount;
union
{
struct Symbol * _class;
struct
{
struct __ecereNameSpace__ecere__sys__OldList members;
char *  enumName;
} __attribute__ ((gcc_struct)) __anon1;
struct
{
struct Type * returnType;
struct __ecereNameSpace__ecere__sys__OldList params;
struct Symbol * thisClass;
unsigned int staticMethod;
struct TemplateParameter * thisClassTemplate;
} __attribute__ ((gcc_struct)) __anon2;
struct
{
struct __ecereNameSpace__ecere__com__Method * method;
struct __ecereNameSpace__ecere__com__Class * methodClass;
struct __ecereNameSpace__ecere__com__Class * usedClass;
} __attribute__ ((gcc_struct)) __anon3;
struct
{
struct Type * arrayType;
int arraySize;
struct Expression * arraySizeExp;
unsigned int freeExp;
struct Symbol * enumClass;
} __attribute__ ((gcc_struct)) __anon4;
struct Type * type;
struct TemplateParameter * templateParameter;
} __attribute__ ((gcc_struct)) __anon1;
int kind;
unsigned int size;
char *  name;
char *  typeName;
int classObjectType;
int alignment;
unsigned int offset;
int bitFieldCount;
int count;
unsigned int isSigned : 1;
unsigned int constant : 1;
unsigned int truth : 1;
unsigned int byReference : 1;
unsigned int extraParam : 1;
unsigned int directClassAccess : 1;
unsigned int computing : 1;
unsigned int keepCast : 1;
unsigned int passAsTemplate : 1;
unsigned int dllExport : 1;
unsigned int attrStdcall : 1;
unsigned int declaredWithStruct : 1;
unsigned int typedByReference : 1;
unsigned int casted : 1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Class;

struct __ecereNameSpace__ecere__com__Class
{
struct __ecereNameSpace__ecere__com__Class * prev;
struct __ecereNameSpace__ecere__com__Class * next;
const char *  name;
int offset;
int structSize;
void * *  _vTbl;
int vTblSize;
unsigned int (*  Constructor)(void * );
void (*  Destructor)(void * );
int offsetClass;
int sizeClass;
struct __ecereNameSpace__ecere__com__Class * base;
struct __ecereNameSpace__ecere__sys__BinaryTree methods;
struct __ecereNameSpace__ecere__sys__BinaryTree members;
struct __ecereNameSpace__ecere__sys__BinaryTree prop;
struct __ecereNameSpace__ecere__sys__OldList membersAndProperties;
struct __ecereNameSpace__ecere__sys__BinaryTree classProperties;
struct __ecereNameSpace__ecere__sys__OldList derivatives;
int memberID;
int startMemberID;
int type;
struct __ecereNameSpace__ecere__com__Instance * module;
struct __ecereNameSpace__ecere__com__NameSpace *  nameSpace;
const char *  dataTypeString;
struct Type * dataType;
int typeSize;
int defaultAlignment;
void (*  Initialize)();
int memberOffset;
struct __ecereNameSpace__ecere__sys__OldList selfWatchers;
const char *  designerClass;
unsigned int noExpansion;
const char *  defaultProperty;
unsigned int comRedefinition;
int count;
int isRemote;
unsigned int internalDecl;
void *  data;
unsigned int computeSize;
int structAlignment;
int destructionWatchOffset;
unsigned int fixed;
struct __ecereNameSpace__ecere__sys__OldList delayedCPValues;
int inheritanceAccess;
const char *  fullName;
void *  symbol;
struct __ecereNameSpace__ecere__sys__OldList conversions;
struct __ecereNameSpace__ecere__sys__OldList templateParams;
struct __ecereNameSpace__ecere__com__ClassTemplateArgument *  templateArgs;
struct __ecereNameSpace__ecere__com__Class * templateClass;
struct __ecereNameSpace__ecere__sys__OldList templatized;
int numParams;
unsigned int isInstanceClass;
unsigned int byValueSystemClass;
} __attribute__ ((gcc_struct));

extern long long __ecereNameSpace__ecere__com__eClass_GetProperty(struct __ecereNameSpace__ecere__com__Class * _class, const char *  name);

extern void __ecereNameSpace__ecere__com__eClass_SetProperty(struct __ecereNameSpace__ecere__com__Class * _class, const char *  name, long long value);

extern void __ecereNameSpace__ecere__com__eInstance_FireSelfWatchers(struct __ecereNameSpace__ecere__com__Instance * instance, struct __ecereNameSpace__ecere__com__Property * _property);

extern void __ecereNameSpace__ecere__com__eInstance_SetMethod(struct __ecereNameSpace__ecere__com__Instance * instance, const char *  name, void *  function);

extern void __ecereNameSpace__ecere__com__eInstance_IncRef(struct __ecereNameSpace__ecere__com__Instance * instance);

extern void __ecereNameSpace__ecere__com__eInstance_StopWatching(struct __ecereNameSpace__ecere__com__Instance * instance, struct __ecereNameSpace__ecere__com__Property * _property, struct __ecereNameSpace__ecere__com__Instance * object);

extern void __ecereNameSpace__ecere__com__eInstance_Watch(void *  instance, struct __ecereNameSpace__ecere__com__Property * _property, void *  object, void (*  callback)(void * , void * ));

extern void __ecereNameSpace__ecere__com__eInstance_FireWatchers(struct __ecereNameSpace__ecere__com__Instance * instance, struct __ecereNameSpace__ecere__com__Property * _property);

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Instance;

struct __ecereNameSpace__ecere__com__Instance
{
void * *  _vTbl;
struct __ecereNameSpace__ecere__com__Class * _class;
int _refCount;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__DataMember;

struct __ecereNameSpace__ecere__com__DataMember
{
struct __ecereNameSpace__ecere__com__DataMember * prev;
struct __ecereNameSpace__ecere__com__DataMember * next;
const char *  name;
unsigned int isProperty;
int memberAccess;
int id;
struct __ecereNameSpace__ecere__com__Class * _class;
const char *  dataTypeString;
struct __ecereNameSpace__ecere__com__Class * dataTypeClass;
struct Type * dataType;
int type;
int offset;
int memberID;
struct __ecereNameSpace__ecere__sys__OldList members;
struct __ecereNameSpace__ecere__sys__BinaryTree membersAlpha;
int memberOffset;
int structAlignment;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__SerialBuffer;

struct __ecereNameSpace__ecere__com__SerialBuffer
{
unsigned char *  _buffer;
unsigned int count;
unsigned int _size;
unsigned int pos;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__ClassTemplateArgument;

struct __ecereNameSpace__ecere__com__ClassTemplateArgument
{
union
{
struct
{
const char *  dataTypeString;
struct __ecereNameSpace__ecere__com__Class * dataTypeClass;
} __attribute__ ((gcc_struct)) __anon1;
struct __ecereNameSpace__ecere__com__DataValue expression;
struct
{
const char *  memberString;
union
{
struct __ecereNameSpace__ecere__com__DataMember * member;
struct __ecereNameSpace__ecere__com__Property * prop;
struct __ecereNameSpace__ecere__com__Method * method;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct)) __anon2;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

void __ecereMethod___ecereNameSpace__ecere__sys__OldList_Remove(struct __ecereNameSpace__ecere__sys__OldList * this, void *  item);

void FreeList(struct __ecereNameSpace__ecere__sys__OldList * list, void (* FreeFunction)(void *))
{
if(list != (((void *)0)))
{
struct __ecereNameSpace__ecere__sys__Item * item;

while((item = list->first))
{
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Remove(list, item);
FreeFunction(item);
}
(__ecereNameSpace__ecere__com__eSystem_Delete(list), list = 0);
}
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__NamedLink64;

struct __ecereNameSpace__ecere__sys__NamedLink64
{
struct __ecereNameSpace__ecere__sys__NamedLink64 * prev;
struct __ecereNameSpace__ecere__sys__NamedLink64 * next;
char *  name;
long long data;
} __attribute__ ((gcc_struct));

void FreeExpression(struct Expression * exp);

void FreeType(struct Type * type)
{
if(type)
{
type->refCount--;
if(type->refCount <= 0)
{
switch(type->kind)
{
case 15:
{
struct __ecereNameSpace__ecere__sys__NamedLink64 * member, * next;

if(type->__anon1.__anon1.enumName)
(__ecereNameSpace__ecere__com__eSystem_Delete(type->__anon1.__anon1.enumName), type->__anon1.__anon1.enumName = 0);
for(member = type->__anon1.__anon1.members.first; member; member = next)
{
next = member->next;
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Remove(&type->__anon1.__anon1.members, member);
(__ecereNameSpace__ecere__com__eSystem_Delete(member->name), member->name = 0);
((member ? (__ecereClass___ecereNameSpace__ecere__sys__NamedLink64->Destructor ? __ecereClass___ecereNameSpace__ecere__sys__NamedLink64->Destructor((void *)member) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(member)) : 0), member = 0);
}
break;
}
case 9:
case 10:
{
struct Type * member, * next;

(__ecereNameSpace__ecere__com__eSystem_Delete(type->__anon1.__anon1.enumName), type->__anon1.__anon1.enumName = 0);
for(member = type->__anon1.__anon1.members.first; member; member = next)
{
next = member->next;
if(member->refCount == 1)
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Remove(&type->__anon1.__anon1.members, member);
FreeType(member);
}
break;
}
case 11:
{
struct Type * param, * next;

if(type->__anon1.__anon2.returnType)
FreeType(type->__anon1.__anon2.returnType);
for(param = type->__anon1.__anon2.params.first; param; param = next)
{
next = param->next;
FreeType(param);
}
break;
}
case 12:
if(type->__anon1.__anon4.freeExp && type->__anon1.__anon4.arraySizeExp)
FreeExpression(type->__anon1.__anon4.arraySizeExp);
case 13:
if(type->__anon1.type)
FreeType(type->__anon1.type);
break;
}
(__ecereNameSpace__ecere__com__eSystem_Delete(type->name), type->name = 0);
(__ecereNameSpace__ecere__com__eSystem_Delete(type->typeName), type->typeName = 0);
((type ? (__ecereClass_Type->Destructor ? __ecereClass_Type->Destructor((void *)type) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(type)) : 0), type = 0);
}
}
}

void FreeTemplateParameter(struct TemplateParameter * param);

void FreeContext(struct Context * context);

void __ecereMethod___ecereNameSpace__ecere__sys__OldList_Delete(struct __ecereNameSpace__ecere__sys__OldList * this, void *  item);

void FreeSymbol(struct Symbol * symbol)
{
struct __ecereNameSpace__ecere__sys__OldLink * link;

if(symbol->propCategory)
FreeExpression(symbol->propCategory);
FreeType(symbol->type);
while((link = symbol->templatedClasses.first))
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Delete(&symbol->templatedClasses, link);
(__ecereNameSpace__ecere__com__eSystem_Delete(symbol->string), symbol->string = 0);
if(symbol->templateParams)
FreeList(symbol->templateParams, (void *)(FreeTemplateParameter));
(__ecereNameSpace__ecere__com__eSystem_Delete(symbol->constructorName), symbol->constructorName = 0);
(__ecereNameSpace__ecere__com__eSystem_Delete(symbol->structName), symbol->structName = 0);
(__ecereNameSpace__ecere__com__eSystem_Delete(symbol->className), symbol->className = 0);
(__ecereNameSpace__ecere__com__eSystem_Delete(symbol->destructorName), symbol->destructorName = 0);
(__ecereNameSpace__ecere__com__eSystem_Delete(symbol->shortName), symbol->shortName = 0);
if(symbol->ctx)
{
FreeContext(symbol->ctx);
((symbol->ctx ? (__ecereClass_Context->Destructor ? __ecereClass_Context->Destructor((void *)symbol->ctx) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(symbol->ctx)) : 0), symbol->ctx = 0);
}
((symbol ? (__ecereClass_Symbol->Destructor ? __ecereClass_Symbol->Destructor((void *)symbol) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(symbol)) : 0), symbol = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_MethodImport;

struct MethodImport
{
struct MethodImport * prev;
struct MethodImport * next;
char *  name;
unsigned int isVirtual;
} __attribute__ ((gcc_struct));

void FreeMethodImport(struct MethodImport * imp)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(imp->name), imp->name = 0);
}

void FreePropertyImport(struct MethodImport * imp)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(imp->name), imp->name = 0);
}

void __ecereMethod___ecereNameSpace__ecere__sys__OldList_Free(struct __ecereNameSpace__ecere__sys__OldList * this, void (*  freeFn)(void * ));

void FreeClassImport(struct ClassImport * imp)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(imp->name), imp->name = 0);
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Free(&imp->methods, (void *)(FreeMethodImport));
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Free(&imp->properties, (void *)(FreePropertyImport));
}

void FreeFunctionImport(struct ClassImport * imp)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(imp->name), imp->name = 0);
}

void FreeModuleImport(struct ModuleImport * imp)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(imp->name), imp->name = 0);
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Free(&imp->classes, (void *)(FreeClassImport));
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Free(&imp->functions, (void *)(FreeFunctionImport));
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Definition;

struct Definition
{
struct Definition * prev;
struct Definition * next;
char *  name;
int type;
} __attribute__ ((gcc_struct));

void FreeModuleDefine(struct Definition * def)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(def->name), def->name = 0);
}

void FreeExcludedSymbols(struct __ecereNameSpace__ecere__sys__OldList * excludedSymbols)
{
struct Symbol * symbol;

while((symbol = excludedSymbols->first))
{
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Remove(excludedSymbols, symbol);
FreeSymbol(symbol);
}
}

void FreeIdentifier(struct Identifier * id);

void FreeTemplateDataType(struct TemplateDatatype * type);

void FreeTemplateArgument(struct TemplateArgument * arg)
{
switch(arg->type)
{
case 2:
if(arg->__anon1.expression)
FreeExpression(arg->__anon1.expression);
break;
case 1:
if(arg->__anon1.identifier)
FreeIdentifier(arg->__anon1.identifier);
break;
case 0:
if(arg->__anon1.templateDatatype)
FreeTemplateDataType(arg->__anon1.templateDatatype);
break;
}
if(arg->name)
FreeIdentifier(arg->name);
((arg ? (__ecereClass_TemplateArgument->Destructor ? __ecereClass_TemplateArgument->Destructor((void *)arg) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(arg)) : 0), arg = 0);
}

void FreeDeclarator(struct Declarator * decl);

void FreeSpecifier(struct Specifier * spec);

void FreeTemplateDataType(struct TemplateDatatype * type)
{
if(type->decl)
FreeDeclarator(type->decl);
if(type->specifiers)
FreeList(type->specifiers, (void *)(FreeSpecifier));
((type ? (__ecereClass_TemplateDatatype->Destructor ? __ecereClass_TemplateDatatype->Destructor((void *)type) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(type)) : 0), type = 0);
}

void FreeTemplateParameter(struct TemplateParameter * param)
{
if(param->identifier)
{
FreeIdentifier(param->identifier);
}
if(param->type == 0 || param->type == 2)
{
if(param->__anon1.dataType)
FreeTemplateDataType(param->__anon1.dataType);
}
if(param->defaultArgument)
FreeTemplateArgument(param->defaultArgument);
if(param->baseType)
FreeType(param->baseType);
((param ? (__ecereClass_TemplateParameter->Destructor ? __ecereClass_TemplateParameter->Destructor((void *)param) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(param)) : 0), param = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplatedType;

void FreeTemplateType(struct TemplatedType * type)
{
((type ? (__ecereClass_TemplatedType->Destructor ? __ecereClass_TemplatedType->Destructor((void *)type) : 0, __ecereClass___ecereNameSpace__ecere__sys__BTNode->Destructor ? __ecereClass___ecereNameSpace__ecere__sys__BTNode->Destructor((void *)type) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(type)) : 0), type = 0);
}

extern struct Context * curContext;

extern struct Context * globalContext;

void __ecereMethod___ecereNameSpace__ecere__sys__BinaryTree_Remove(struct __ecereNameSpace__ecere__sys__BinaryTree * this, struct __ecereNameSpace__ecere__sys__BTNode * node);

void FreeContext(struct Context * context)
{
struct Symbol * symbol;

if(context == curContext)
curContext = globalContext;
while((symbol = (struct Symbol *)context->types.root))
{
__ecereMethod___ecereNameSpace__ecere__sys__BinaryTree_Remove(&context->types, (struct __ecereNameSpace__ecere__sys__BTNode *)symbol);
FreeSymbol(symbol);
}
while((symbol = (struct Symbol *)context->classes.root))
{
__ecereMethod___ecereNameSpace__ecere__sys__BinaryTree_Remove(&context->classes, (struct __ecereNameSpace__ecere__sys__BTNode *)symbol);
FreeSymbol(symbol);
}
while((symbol = (struct Symbol *)context->symbols.root))
{
__ecereMethod___ecereNameSpace__ecere__sys__BinaryTree_Remove(&context->symbols, (struct __ecereNameSpace__ecere__sys__BTNode *)symbol);
FreeSymbol(symbol);
}
while((symbol = (struct Symbol *)context->structSymbols.root))
{
__ecereMethod___ecereNameSpace__ecere__sys__BinaryTree_Remove(&context->structSymbols, (struct __ecereNameSpace__ecere__sys__BTNode *)symbol);
FreeSymbol(symbol);
}
while((symbol = (struct Symbol *)context->templateTypes.root))
{
__ecereMethod___ecereNameSpace__ecere__sys__BinaryTree_Remove(&context->templateTypes, (struct __ecereNameSpace__ecere__sys__BTNode *)symbol);
FreeTemplateType((struct TemplatedType *)symbol);
}
context->nextID = 0;
context->simpleID = 0;
context->parent = (((void *)0));
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Enumerator;

struct Enumerator
{
struct Enumerator * prev;
struct Enumerator * next;
struct Location loc;
struct Identifier * id;
struct Expression * exp;
} __attribute__ ((gcc_struct));

void FreeEnumerator(struct Enumerator * enumerator)
{
if(enumerator->id)
FreeIdentifier(enumerator->id);
if(enumerator->exp)
FreeExpression(enumerator->exp);
((enumerator ? (__ecereClass_Enumerator->Destructor ? __ecereClass_Enumerator->Destructor((void *)enumerator) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(enumerator)) : 0), enumerator = 0);
}

void FreeSpecifierContents(struct Specifier * spec);

void FreeSpecifier(struct Specifier * spec)
{
if(spec)
{
FreeSpecifierContents(spec);
((spec ? (__ecereClass_Specifier->Destructor ? __ecereClass_Specifier->Destructor((void *)spec) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(spec)) : 0), spec = 0);
}
}

void FreeExtDecl(struct ExtDecl * extDecl);

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassFunction;

struct ClassFunction
{
struct ClassFunction * prev;
struct ClassFunction * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * declarator;
struct __ecereNameSpace__ecere__sys__OldList *  declarations;
struct Statement * body;
struct __ecereNameSpace__ecere__com__Class * _class;
struct __ecereNameSpace__ecere__sys__OldList attached;
int declMode;
struct Type * type;
struct Symbol * propSet;
unsigned int isVirtual;
unsigned int isConstructor;
unsigned int isDestructor;
unsigned int dontMangle;
int id;
int idCode;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_PropertyDef;

struct PropertyDef
{
struct PropertyDef * prev;
struct PropertyDef * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * declarator;
struct Identifier * id;
struct Statement * getStmt;
struct Statement * setStmt;
struct Statement * issetStmt;
struct Symbol * symbol;
struct Expression * category;
struct
{
unsigned int conversion : 1;
unsigned int isWatchable : 1;
unsigned int isDBProp : 1;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_PropertyWatch;

struct PropertyWatch
{
struct PropertyWatch * prev;
struct PropertyWatch * next;
struct Location loc;
struct Statement * compound;
struct __ecereNameSpace__ecere__sys__OldList *  properties;
unsigned int deleteWatch;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassDef;

struct ClassDef
{
struct ClassDef * prev;
struct ClassDef * next;
struct Location loc;
int type;
union
{
struct Declaration * decl;
struct ClassFunction * function;
struct __ecereNameSpace__ecere__sys__OldList *  defProperties;
struct PropertyDef * propertyDef;
struct PropertyWatch * propertyWatch;
char *  designer;
struct Identifier * defaultProperty;
struct
{
struct Identifier * id;
struct Initializer * initializer;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct)) __anon1;
int memberAccess;
void *  object;
} __attribute__ ((gcc_struct));

void FreeClassDef(struct ClassDef * def);

void FreeSpecifierContents(struct Specifier * spec)
{
switch(spec->type)
{
case 1:
(__ecereNameSpace__ecere__com__eSystem_Delete(spec->__anon1.__anon1.name), spec->__anon1.__anon1.name = 0);
if(spec->__anon1.__anon1.templateArgs)
{
FreeList(spec->__anon1.__anon1.templateArgs, (void *)(FreeTemplateArgument));
spec->__anon1.__anon1.templateArgs = (((void *)0));
}
break;
case 5:
if(spec->__anon1.__anon1.extDecl)
{
FreeExtDecl(spec->__anon1.__anon1.extDecl);
spec->__anon1.__anon1.extDecl = (((void *)0));
}
break;
case 2:
if(spec->__anon1.__anon2.baseSpecs)
{
FreeList(spec->__anon1.__anon2.baseSpecs, (void *)(FreeSpecifier));
spec->__anon1.__anon2.baseSpecs = (((void *)0));
}
if(spec->__anon1.__anon2.id)
{
FreeIdentifier(spec->__anon1.__anon2.id);
spec->__anon1.__anon2.id = (((void *)0));
}
if(spec->__anon1.__anon2.list)
{
FreeList(spec->__anon1.__anon2.list, (void *)(FreeEnumerator));
spec->__anon1.__anon2.list = (((void *)0));
}
if(spec->__anon1.__anon2.definitions)
{
FreeList(spec->__anon1.__anon2.definitions, (void *)(FreeClassDef));
spec->__anon1.__anon2.definitions = (((void *)0));
}
break;
case 3:
case 4:
if(spec->__anon1.__anon2.id)
{
FreeIdentifier(spec->__anon1.__anon2.id);
spec->__anon1.__anon2.id = (((void *)0));
}
if(spec->__anon1.__anon2.definitions)
{
FreeList(spec->__anon1.__anon2.definitions, (void *)(FreeClassDef));
spec->__anon1.__anon2.definitions = (((void *)0));
}
if(spec->__anon1.__anon2.baseSpecs)
{
FreeList(spec->__anon1.__anon2.baseSpecs, (void *)(FreeSpecifier));
spec->__anon1.__anon2.baseSpecs = (((void *)0));
}
if(spec->__anon1.__anon2.extDeclStruct)
{
FreeExtDecl(spec->__anon1.__anon2.extDeclStruct);
spec->__anon1.__anon2.extDeclStruct = (((void *)0));
}
if(spec->__anon1.__anon2.ctx)
{
FreeContext(spec->__anon1.__anon2.ctx);
((spec->__anon1.__anon2.ctx ? (__ecereClass_Context->Destructor ? __ecereClass_Context->Destructor((void *)spec->__anon1.__anon2.ctx) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(spec->__anon1.__anon2.ctx)) : 0), spec->__anon1.__anon2.ctx = 0);
}
break;
case 7:
if(spec->__anon1._class)
{
FreeSpecifier(spec->__anon1._class);
spec->__anon1._class = (((void *)0));
}
break;
}
}

void FreeIdentifier(struct Identifier * id)
{
if(id->badID)
FreeIdentifier(id->badID);
(__ecereNameSpace__ecere__com__eSystem_Delete(id->string), id->string = 0);
if(id->_class)
FreeSpecifier(id->_class);
((id ? (__ecereClass_Identifier->Destructor ? __ecereClass_Identifier->Destructor((void *)id) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(id)) : 0), id = 0);
}

void FreeTypeName(struct TypeName * typeName)
{
if(typeName->qualifiers)
FreeList(typeName->qualifiers, (void *)(FreeSpecifier));
if(typeName->declarator)
FreeDeclarator(typeName->declarator);
if(typeName->bitCount)
FreeExpression(typeName->bitCount);
((typeName ? (__ecereClass_TypeName->Destructor ? __ecereClass_TypeName->Destructor((void *)typeName) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(typeName)) : 0), typeName = 0);
}

static void _FreeExpression(struct Expression * exp, unsigned int freePointer);

void FreeExpContents(struct Expression * exp)
{
_FreeExpression(exp, 0);
}

void FreeExpression(struct Expression * exp)
{
_FreeExpression(exp, 1);
}

void FreeInstance(struct Instantiation * inst);

void FreeStatement(struct Statement * stmt);

void FreeInitializer(struct Initializer * initializer);

static void _FreeExpression(struct Expression * exp, unsigned int freePointer)
{
switch(exp->type)
{
case 13:
case 26:
FreeExpression(exp->__anon1._new.size);
FreeTypeName(exp->__anon1._new.typeName);
break;
case 14:
case 27:
FreeExpression(exp->__anon1._renew.exp);
FreeExpression(exp->__anon1._renew.size);
FreeTypeName(exp->__anon1._renew.typeName);
break;
case 2:
(__ecereNameSpace__ecere__com__eSystem_Delete(exp->__anon1.__anon1.constant), exp->__anon1.__anon1.constant = 0);
break;
case 0:
if(exp->__anon1.__anon1.identifier)
FreeIdentifier(exp->__anon1.__anon1.identifier);
break;
case 1:
if(exp->__anon1.instance)
{
FreeInstance(exp->__anon1.instance);
exp->__anon1.instance = (((void *)0));
}
break;
case 3:
(__ecereNameSpace__ecere__com__eSystem_Delete(exp->__anon1.__anon2.string), exp->__anon1.__anon2.string = 0);
break;
case 4:
if(exp->__anon1.op.exp1)
FreeExpression(exp->__anon1.op.exp1);
if(exp->__anon1.op.exp2)
FreeExpression(exp->__anon1.op.exp2);
break;
case 5:
{
FreeList(exp->__anon1.list, (void *)(FreeExpression));
break;
}
case 6:
{
if(exp->__anon1.index.exp)
FreeExpression(exp->__anon1.index.exp);
if(exp->__anon1.index.index)
FreeList(exp->__anon1.index.index, (void *)(FreeExpression));
break;
}
case 7:
{
if(exp->__anon1.call.exp)
FreeExpression(exp->__anon1.call.exp);
if(exp->__anon1.call.arguments)
FreeList(exp->__anon1.call.arguments, (void *)(FreeExpression));
break;
}
case 8:
case 9:
if(exp->__anon1.member.exp)
FreeExpression(exp->__anon1.member.exp);
if(exp->__anon1.member.member)
FreeIdentifier(exp->__anon1.member.member);
break;
case 10:
FreeTypeName(exp->__anon1._new.typeName);
break;
case 36:
FreeTypeName(exp->__anon1._new.typeName);
break;
case 11:
if(exp->__anon1.cast.exp)
FreeExpression(exp->__anon1.cast.exp);
FreeTypeName(exp->__anon1.cast.typeName);
break;
case 12:
{
if(exp->__anon1.cond.cond)
FreeExpression(exp->__anon1.cond.cond);
if(exp->__anon1.cond.exp)
FreeList(exp->__anon1.cond.exp, (void *)(FreeExpression));
if(exp->__anon1.cond.elseExp)
FreeExpression(exp->__anon1.cond.elseExp);
break;
}
case 23:
{
if(exp->__anon1.compound)
FreeStatement(exp->__anon1.compound);
break;
}
case 32:
{
if(exp->__anon1.list)
FreeList(exp->__anon1.list, (void *)(FreeExpression));
break;
}
case 33:
{
if(exp->__anon1.initializer.typeName)
FreeTypeName(exp->__anon1.initializer.typeName);
if(exp->__anon1.initializer.initializer)
FreeInitializer(exp->__anon1.initializer.initializer);
break;
}
case 16:
break;
case 24:
if(exp->__anon1._classExp.specifiers)
FreeList(exp->__anon1._classExp.specifiers, (void *)(FreeSpecifier));
if(exp->__anon1._classExp.decl)
FreeDeclarator(exp->__anon1._classExp.decl);
break;
case 29:
case 31:
case 30:
if(exp->__anon1.db.id)
FreeIdentifier(exp->__anon1.db.id);
(__ecereNameSpace__ecere__com__eSystem_Delete(exp->__anon1.db.table), exp->__anon1.db.table = 0);
break;
case 28:
if(exp->__anon1.dbopen.ds)
FreeExpression(exp->__anon1.dbopen.ds);
if(exp->__anon1.dbopen.name)
FreeExpression(exp->__anon1.dbopen.name);
break;
case 34:
if(exp->__anon1.vaArg.exp)
FreeExpression(exp->__anon1.vaArg.exp);
if(exp->__anon1.vaArg.typeName)
FreeTypeName(exp->__anon1.vaArg.typeName);
break;
case 35:
if(exp->__anon1.list)
FreeList(exp->__anon1.list, (void *)(FreeExpression));
break;
case 15:
if(exp->__anon1._class)
FreeSpecifier(exp->__anon1._class);
break;
case 25:
if(exp->__anon1.classData.id)
FreeIdentifier(exp->__anon1.classData.id);
break;
case 18:
if(exp->__anon1.__anon1.identifier)
FreeIdentifier(exp->__anon1.__anon1.identifier);
break;
case 20:
(__ecereNameSpace__ecere__com__eSystem_Delete(exp->__anon1.__anon1.constant), exp->__anon1.__anon1.constant = 0);
break;
case 37:
case 19:
if(exp->__anon1.member.exp)
FreeExpression(exp->__anon1.member.exp);
if(exp->__anon1.member.member)
FreeIdentifier(exp->__anon1.member.member);
break;
case 38:
if(exp->__anon1.call.exp)
FreeExpression(exp->__anon1.call.exp);
if(exp->__anon1.call.arguments)
FreeList(exp->__anon1.call.arguments, (void *)(FreeExpression));
break;
case 17:
case 21:
case 22:
break;
}
if(freePointer)
{
if(exp->expType)
FreeType(exp->expType);
if(exp->destType)
FreeType(exp->destType);
((exp ? (__ecereClass_Expression->Destructor ? __ecereClass_Expression->Destructor((void *)exp) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(exp)) : 0), exp = 0);
}
}

void FreePointer(struct Pointer * pointer)
{
if(pointer->pointer)
FreePointer(pointer->pointer);
if(pointer->qualifiers)
FreeList(pointer->qualifiers, (void *)(FreeSpecifier));
((pointer ? (__ecereClass_Pointer->Destructor ? __ecereClass_Pointer->Destructor((void *)pointer) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(pointer)) : 0), pointer = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Attribute;

struct Attribute
{
struct Attribute * prev;
struct Attribute * next;
struct Location loc;
char * attr;
struct Expression * exp;
} __attribute__ ((gcc_struct));

void FreeAttribute(struct Attribute * attr);

void FreeAttrib(struct Attrib * attr)
{
if(attr->attribs)
FreeList(attr->attribs, (void *)(FreeAttribute));
((attr ? (__ecereClass_Attrib->Destructor ? __ecereClass_Attrib->Destructor((void *)attr) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(attr)) : 0), attr = 0);
}

void FreeAttribute(struct Attribute * attr)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(attr->attr), attr->attr = 0);
if(attr->exp)
FreeExpression(attr->exp);
((attr ? (__ecereClass_Attribute->Destructor ? __ecereClass_Attribute->Destructor((void *)attr) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(attr)) : 0), attr = 0);
}

void FreeExtDecl(struct ExtDecl * extDecl)
{
if(extDecl->type == 1 && extDecl->__anon1.attr)
FreeAttrib(extDecl->__anon1.attr);
else if(extDecl->type == 0)
(__ecereNameSpace__ecere__com__eSystem_Delete(extDecl->__anon1.s), extDecl->__anon1.s = 0);
((extDecl ? (__ecereClass_ExtDecl->Destructor ? __ecereClass_ExtDecl->Destructor((void *)extDecl) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(extDecl)) : 0), extDecl = 0);
}

void FreeDeclarator(struct Declarator * decl)
{
if(decl->declarator)
FreeDeclarator(decl->declarator);
switch(decl->type)
{
case 0:
if(decl->__anon1.structDecl.exp)
FreeExpression(decl->__anon1.structDecl.exp);
if(decl->__anon1.structDecl.posExp)
FreeExpression(decl->__anon1.structDecl.posExp);
if(decl->__anon1.structDecl.attrib)
FreeAttrib(decl->__anon1.structDecl.attrib);
break;
case 1:
FreeIdentifier(decl->__anon1.identifier);
break;
case 2:
break;
case 3:
if(decl->__anon1.array.exp)
FreeExpression(decl->__anon1.array.exp);
if(decl->__anon1.array.enumClass)
FreeSpecifier(decl->__anon1.array.enumClass);
break;
case 4:
FreeList(decl->__anon1.function.parameters, (void *)(FreeTypeName));
break;
case 5:
if(decl->__anon1.pointer.pointer)
FreePointer(decl->__anon1.pointer.pointer);
break;
case 6:
case 7:
if(decl->__anon1.extended.extended)
FreeExtDecl(decl->__anon1.extended.extended);
break;
}
((decl ? (__ecereClass_Declarator->Destructor ? __ecereClass_Declarator->Destructor((void *)decl) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(decl)) : 0), decl = 0);
}

void FreePropertyWatch(struct PropertyWatch * watcher)
{
if(watcher->properties)
FreeList(watcher->properties, (void *)(FreeIdentifier));
if(watcher->compound)
FreeStatement(watcher->compound);
((watcher ? (__ecereClass_PropertyWatch->Destructor ? __ecereClass_PropertyWatch->Destructor((void *)watcher) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(watcher)) : 0), watcher = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_AsmField;

struct AsmField
{
struct AsmField * prev;
struct AsmField * next;
struct Location loc;
char *  command;
struct Expression * expression;
struct Identifier * symbolic;
} __attribute__ ((gcc_struct));

void FreeAsmField(struct AsmField * field)
{
if(field->expression)
FreeExpression(field->expression);
if(field->symbolic)
FreeIdentifier(field->symbolic);
(__ecereNameSpace__ecere__com__eSystem_Delete(field->command), field->command = 0);
((field ? (__ecereClass_AsmField->Destructor ? __ecereClass_AsmField->Destructor((void *)field) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(field)) : 0), field = 0);
}

void FreeDeclaration(struct Declaration * decl);

void FreeStatement(struct Statement * stmt)
{
switch(stmt->type)
{
case 13:
{
if(stmt->__anon1.asmStmt.spec)
FreeSpecifier(stmt->__anon1.asmStmt.spec);
if(stmt->__anon1.asmStmt.inputFields)
FreeList(stmt->__anon1.asmStmt.inputFields, (void *)(FreeAsmField));
if(stmt->__anon1.asmStmt.outputFields)
FreeList(stmt->__anon1.asmStmt.outputFields, (void *)(FreeAsmField));
if(stmt->__anon1.asmStmt.clobberedFields)
FreeList(stmt->__anon1.asmStmt.clobberedFields, (void *)(FreeAsmField));
(__ecereNameSpace__ecere__com__eSystem_Delete(stmt->__anon1.asmStmt.statements), stmt->__anon1.asmStmt.statements = 0);
break;
}
case 0:
if(stmt->__anon1.labeled.stmt)
FreeStatement(stmt->__anon1.labeled.stmt);
break;
case 1:
if(stmt->__anon1.caseStmt.exp)
FreeExpression(stmt->__anon1.caseStmt.exp);
if(stmt->__anon1.caseStmt.stmt)
FreeStatement(stmt->__anon1.caseStmt.stmt);
break;
case 14:
if(stmt->__anon1.decl)
FreeDeclaration(stmt->__anon1.decl);
break;
case 2:
{
if(stmt->__anon1.compound.declarations)
FreeList(stmt->__anon1.compound.declarations, (void *)(FreeDeclaration));
if(stmt->__anon1.compound.statements)
FreeList(stmt->__anon1.compound.statements, (void *)(FreeStatement));
if(stmt->__anon1.compound.context)
{
FreeContext(stmt->__anon1.compound.context);
((stmt->__anon1.compound.context ? (__ecereClass_Context->Destructor ? __ecereClass_Context->Destructor((void *)stmt->__anon1.compound.context) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(stmt->__anon1.compound.context)) : 0), stmt->__anon1.compound.context = 0);
}
break;
}
case 3:
{
if(stmt->__anon1.expressions)
FreeList(stmt->__anon1.expressions, (void *)(FreeExpression));
break;
}
case 4:
{
if(stmt->__anon1.ifStmt.exp)
FreeList(stmt->__anon1.ifStmt.exp, (void *)(FreeExpression));
if(stmt->__anon1.ifStmt.stmt)
FreeStatement(stmt->__anon1.ifStmt.stmt);
if(stmt->__anon1.ifStmt.elseStmt)
FreeStatement(stmt->__anon1.ifStmt.elseStmt);
break;
}
case 5:
{
if(stmt->__anon1.switchStmt.exp)
FreeList(stmt->__anon1.switchStmt.exp, (void *)(FreeExpression));
if(stmt->__anon1.switchStmt.stmt)
FreeStatement(stmt->__anon1.switchStmt.stmt);
break;
}
case 6:
{
if(stmt->__anon1.whileStmt.exp)
FreeList(stmt->__anon1.whileStmt.exp, (void *)(FreeExpression));
if(stmt->__anon1.whileStmt.stmt)
FreeStatement(stmt->__anon1.whileStmt.stmt);
break;
}
case 7:
{
if(stmt->__anon1.doWhile.stmt)
FreeStatement(stmt->__anon1.doWhile.stmt);
if(stmt->__anon1.doWhile.exp)
FreeList(stmt->__anon1.doWhile.exp, (void *)(FreeExpression));
break;
}
case 8:
{
if(stmt->__anon1.forStmt.init)
FreeStatement(stmt->__anon1.forStmt.init);
if(stmt->__anon1.forStmt.check)
FreeStatement(stmt->__anon1.forStmt.check);
if(stmt->__anon1.forStmt.increment)
FreeList(stmt->__anon1.forStmt.increment, (void *)(FreeExpression));
if(stmt->__anon1.forStmt.stmt)
FreeStatement(stmt->__anon1.forStmt.stmt);
break;
}
case 18:
{
if(stmt->__anon1.forEachStmt.id)
FreeIdentifier(stmt->__anon1.forEachStmt.id);
if(stmt->__anon1.forEachStmt.exp)
FreeList(stmt->__anon1.forEachStmt.exp, (void *)(FreeExpression));
if(stmt->__anon1.forEachStmt.filter)
FreeList(stmt->__anon1.forEachStmt.filter, (void *)(FreeExpression));
if(stmt->__anon1.forEachStmt.stmt)
FreeStatement(stmt->__anon1.forEachStmt.stmt);
break;
}
case 9:
break;
case 10:
break;
case 11:
break;
case 12:
if(stmt->__anon1.expressions)
FreeList(stmt->__anon1.expressions, (void *)(FreeExpression));
break;
case 17:
case 15:
case 16:
{
if(stmt->__anon1._watch.watcher)
FreeExpression(stmt->__anon1._watch.watcher);
if(stmt->__anon1._watch.object)
FreeExpression(stmt->__anon1._watch.object);
if(stmt->__anon1._watch.watches)
FreeList(stmt->__anon1._watch.watches, (stmt->type == 17) ? (void *)FreePropertyWatch : (void *)FreeIdentifier);
break;
}
}
((stmt ? (__ecereClass_Statement->Destructor ? __ecereClass_Statement->Destructor((void *)stmt) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(stmt)) : 0), stmt = 0);
}

void FreeInitializer(struct Initializer * initializer)
{
switch(initializer->type)
{
case 1:
FreeList(initializer->__anon1.list, (void *)(FreeInitializer));
break;
case 0:
if(initializer->__anon1.exp)
FreeExpression(initializer->__anon1.exp);
break;
}
if(initializer->id)
FreeIdentifier(initializer->id);
((initializer ? (__ecereClass_Initializer->Destructor ? __ecereClass_Initializer->Destructor((void *)initializer) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(initializer)) : 0), initializer = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_InitDeclarator;

struct InitDeclarator
{
struct InitDeclarator * prev;
struct InitDeclarator * next;
struct Location loc;
struct Declarator * declarator;
struct Initializer * initializer;
} __attribute__ ((gcc_struct));

void FreeInitDeclarator(struct InitDeclarator * decl)
{
if(decl->declarator)
FreeDeclarator(decl->declarator);
if(decl->initializer)
FreeInitializer(decl->initializer);
((decl ? (__ecereClass_InitDeclarator->Destructor ? __ecereClass_InitDeclarator->Destructor((void *)decl) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(decl)) : 0), decl = 0);
}

void FreeDeclaration(struct Declaration * decl)
{
if(decl->symbol && !decl->symbol->type)
{
}
switch(decl->type)
{
case 0:
{
if(decl->__anon1.__anon1.specifiers)
FreeList(decl->__anon1.__anon1.specifiers, (void *)(FreeSpecifier));
if(decl->__anon1.__anon1.declarators)
FreeList(decl->__anon1.__anon1.declarators, (void *)(FreeDeclarator));
if(decl->extStorage)
FreeSpecifier(decl->extStorage);
break;
}
case 1:
{
if(decl->__anon1.__anon1.specifiers)
FreeList(decl->__anon1.__anon1.specifiers, (void *)(FreeSpecifier));
if(decl->__anon1.__anon1.declarators)
FreeList(decl->__anon1.__anon1.declarators, (void *)(FreeInitDeclarator));
break;
}
case 2:
if(decl->__anon1.inst)
FreeInstance(decl->__anon1.inst);
break;
case 3:
{
if(decl->__anon1.__anon2.exp)
FreeExpression(decl->__anon1.__anon2.exp);
if(decl->__anon1.__anon2.id)
FreeIdentifier(decl->__anon1.__anon2.id);
break;
}
}
((decl ? (__ecereClass_Declaration->Destructor ? __ecereClass_Declaration->Destructor((void *)decl) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(decl)) : 0), decl = 0);
}

void FreeFunction(struct FunctionDefinition * func)
{
if(func->body)
FreeStatement(func->body);
if(func->declarator)
FreeDeclarator(func->declarator);
if(func->specifiers)
FreeList(func->specifiers, (void *)(FreeSpecifier));
if(func->declarations)
FreeList(func->declarations, (void *)(FreeDeclaration));
if(func->type)
FreeType(func->type);
((func ? (__ecereClass_FunctionDefinition->Destructor ? __ecereClass_FunctionDefinition->Destructor((void *)func) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(func)) : 0), func = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_MemberInit;

struct MemberInit
{
struct MemberInit * prev;
struct MemberInit * next;
struct Location loc;
struct Location realLoc;
struct __ecereNameSpace__ecere__sys__OldList *  identifiers;
struct Initializer * initializer;
unsigned int used;
unsigned int variable;
unsigned int takeOutExp;
} __attribute__ ((gcc_struct));

void FreeMemberInit(struct MemberInit * init)
{
if(init->initializer)
FreeInitializer(init->initializer);
if(init->identifiers)
FreeList(init->identifiers, (void *)(FreeIdentifier));
((init ? (__ecereClass_MemberInit->Destructor ? __ecereClass_MemberInit->Destructor((void *)init) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(init)) : 0), init = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_MembersInit;

struct MembersInit
{
struct MembersInit * prev;
struct MembersInit * next;
struct Location loc;
int type;
union
{
struct __ecereNameSpace__ecere__sys__OldList *  dataMembers;
struct ClassFunction * function;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

void FreeClassFunction(struct ClassFunction * func);

void FreeMembersInit(struct MembersInit * init)
{
if(init->type == 0 && init->__anon1.dataMembers)
FreeList(init->__anon1.dataMembers, (void *)(FreeMemberInit));
if(init->type == 1 && init->__anon1.function)
{
FreeClassFunction(init->__anon1.function);
}
((init ? (__ecereClass_MembersInit->Destructor ? __ecereClass_MembersInit->Destructor((void *)init) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(init)) : 0), init = 0);
}

extern struct Symbol * FindClass(const char *  name);

extern void __ecereNameSpace__ecere__com__eInstance_DecRef(struct __ecereNameSpace__ecere__com__Instance * instance);

void FreeInstance(struct Instantiation * inst)
{
if(inst->members)
{
FreeList(inst->members, (void *)(FreeMembersInit));
}
if(inst->exp)
FreeExpression(inst->exp);
if(inst->data)
{
struct Symbol * classSym = FindClass(inst->_class->__anon1.__anon1.name);
struct __ecereNameSpace__ecere__com__Class * _class = classSym ? classSym->__anon1.registered : (((void *)0));

if(_class)
{
if(_class->type == 0)
{
struct __ecereNameSpace__ecere__com__Instance * instance = (struct __ecereNameSpace__ecere__com__Instance *)inst->data;

(__ecereNameSpace__ecere__com__eInstance_DecRef(instance), instance = 0);
}
else if(_class->type == 5)
{
if(_class->Destructor)
_class->Destructor((struct __ecereNameSpace__ecere__com__Instance *)inst->data);
(__ecereNameSpace__ecere__com__eSystem_Delete(inst->data), inst->data = 0);
}
else if(_class->type == 1)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(inst->data), inst->data = 0);
}
}
else
{
struct __ecereNameSpace__ecere__com__Instance * instance = (struct __ecereNameSpace__ecere__com__Instance *)inst->data;

(__ecereNameSpace__ecere__com__eInstance_DecRef(instance), instance = 0);
}
}
if(inst->_class)
FreeSpecifier(inst->_class);
((inst ? (__ecereClass_Instantiation->Destructor ? __ecereClass_Instantiation->Destructor((void *)inst) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(inst)) : 0), inst = 0);
}

void FreeClassFunction(struct ClassFunction * func)
{
if(func->declarator && func->declarator->symbol)
{
}
if(func->type)
FreeType(func->type);
if(func->body)
FreeStatement(func->body);
if(func->declarator)
FreeDeclarator(func->declarator);
if(func->specifiers)
FreeList(func->specifiers, (void *)(FreeSpecifier));
if(func->declarations)
FreeList(func->declarations, (void *)(FreeDeclaration));
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Free(&func->attached, (((void *)0)));
((func ? (__ecereClass_ClassFunction->Destructor ? __ecereClass_ClassFunction->Destructor((void *)func) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(func)) : 0), func = 0);
}

void FreeProperty(struct PropertyDef * def)
{
if(def->specifiers)
FreeList(def->specifiers, (void *)(FreeSpecifier));
if(def->declarator)
FreeDeclarator(def->declarator);
if(def->id)
FreeIdentifier(def->id);
if(def->getStmt)
FreeStatement(def->getStmt);
if(def->setStmt)
FreeStatement(def->setStmt);
if(def->issetStmt)
FreeStatement(def->issetStmt);
if(def->category)
FreeExpression(def->category);
if(def->symbol)
{
}
((def ? (__ecereClass_PropertyDef->Destructor ? __ecereClass_PropertyDef->Destructor((void *)def) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(def)) : 0), def = 0);
}

void FreeClassDef(struct ClassDef * def)
{
switch(def->type)
{
case 2:
if(def->__anon1.decl)
FreeDeclaration(def->__anon1.decl);
break;
case 1:
{
FreeList(def->__anon1.defProperties, (void *)(FreeMemberInit));
break;
}
case 0:
if(def->__anon1.function)
FreeClassFunction(def->__anon1.function);
break;
case 3:
if(def->__anon1.propertyDef)
FreeProperty(def->__anon1.propertyDef);
break;
case 10:
if(def->__anon1.propertyDef)
FreeProperty(def->__anon1.propertyDef);
break;
case 13:
break;
case 9:
{
if(def->__anon1.decl)
FreeDeclaration(def->__anon1.decl);
break;
}
case 5:
{
(__ecereNameSpace__ecere__com__eSystem_Delete(def->__anon1.designer), def->__anon1.designer = 0);
break;
}
case 7:
break;
case 6:
break;
case 11:
if(def->__anon1.__anon1.id)
FreeIdentifier(def->__anon1.__anon1.id);
if(def->__anon1.__anon1.initializer)
FreeInitializer(def->__anon1.__anon1.initializer);
break;
case 8:
{
if(def->__anon1.defaultProperty)
FreeIdentifier(def->__anon1.defaultProperty);
break;
}
case 12:
break;
case 4:
{
if(def->__anon1.propertyWatch)
FreePropertyWatch(def->__anon1.propertyWatch);
break;
}
}
((def ? (__ecereClass_ClassDef->Destructor ? __ecereClass_ClassDef->Destructor((void *)def) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(def)) : 0), def = 0);
}

void FreeClass(struct ClassDefinition * _class)
{
if(_class->definitions)
FreeList(_class->definitions, (void *)(FreeClassDef));
if(_class->_class)
FreeSpecifier(_class->_class);
if(_class->baseSpecs)
FreeList(_class->baseSpecs, (void *)(FreeSpecifier));
((_class ? (__ecereClass_ClassDefinition->Destructor ? __ecereClass_ClassDefinition->Destructor((void *)_class) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(_class)) : 0), _class = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_DBIndexItem;

struct DBIndexItem
{
struct DBIndexItem * prev;
struct DBIndexItem * next;
struct Identifier * id;
int order;
} __attribute__ ((gcc_struct));

void FreeDBIndexItem(struct DBIndexItem * item)
{
if(item->id)
FreeIdentifier(item->id);
((item ? (__ecereClass_DBIndexItem->Destructor ? __ecereClass_DBIndexItem->Destructor((void *)item) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(item)) : 0), item = 0);
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_DBTableEntry;

struct DBTableEntry
{
struct DBTableEntry * prev;
struct DBTableEntry * next;
int type;
struct Identifier * id;
union
{
struct
{
struct TypeName * dataType;
char *  name;
} __attribute__ ((gcc_struct)) __anon1;
struct __ecereNameSpace__ecere__sys__OldList *  items;
} __attribute__ ((gcc_struct)) __anon1;
} __attribute__ ((gcc_struct));

void FreeDBTableEntry(struct DBTableEntry * entry)
{
if(entry->id)
FreeIdentifier(entry->id);
switch(entry->type)
{
case 0:
if(entry->__anon1.__anon1.dataType)
FreeTypeName(entry->__anon1.__anon1.dataType);
if(entry->__anon1.__anon1.name)
(__ecereNameSpace__ecere__com__eSystem_Delete(entry->__anon1.__anon1.name), entry->__anon1.__anon1.name = 0);
break;
case 1:
if(entry->__anon1.items)
FreeList(entry->__anon1.items, (void *)(FreeDBIndexItem));
break;
}
((entry ? (__ecereClass_DBTableEntry->Destructor ? __ecereClass_DBTableEntry->Destructor((void *)entry) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(entry)) : 0), entry = 0);
}

void FreeDBTable(struct DBTableDef * table)
{
if(table->definitions)
FreeList(table->definitions, (void *)(FreeDBTableEntry));
if(table->name)
(__ecereNameSpace__ecere__com__eSystem_Delete(table->name), table->name = 0);
((table ? (__ecereClass_DBTableDef->Destructor ? __ecereClass_DBTableDef->Destructor((void *)table) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(table)) : 0), table = 0);
}

void FreeExternal(struct External * external)
{
switch(external->type)
{
case 0:
if(external->__anon1.function)
FreeFunction(external->__anon1.function);
break;
case 1:
if(external->__anon1.declaration)
FreeDeclaration(external->__anon1.declaration);
break;
case 2:
if(external->__anon1._class)
FreeClass(external->__anon1._class);
break;
case 3:
(__ecereNameSpace__ecere__com__eSystem_Delete(external->__anon1.importString), external->__anon1.importString = 0);
break;
case 4:
FreeIdentifier(external->__anon1.id);
break;
case 5:
if(external->__anon1.table)
FreeDBTable(external->__anon1.table);
break;
}
((external ? (__ecereClass_External->Destructor ? __ecereClass_External->Destructor((void *)external) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(external)) : 0), external = 0);
}

void FreeASTTree(struct __ecereNameSpace__ecere__sys__OldList * ast)
{
if(ast != (((void *)0)))
{
struct External * external;

while((external = ast->first))
{
__ecereMethod___ecereNameSpace__ecere__sys__OldList_Remove(ast, external);
FreeExternal(external);
}
(__ecereNameSpace__ecere__com__eSystem_Delete(ast), ast = 0);
}
}

static void FreeDataMember(struct __ecereNameSpace__ecere__com__DataMember * parentMember)
{
struct __ecereNameSpace__ecere__com__DataMember * dataMember;

for(dataMember = parentMember->members.first; dataMember; dataMember = dataMember->next)
{
if(dataMember->type == 2 || dataMember->type == 1)
FreeDataMember(dataMember);
if(dataMember->dataType)
{
FreeType(dataMember->dataType);
dataMember->dataType = (((void *)0));
}
}
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__ClassProperty;

struct __ecereNameSpace__ecere__com__ClassProperty
{
const char *  name;
struct __ecereNameSpace__ecere__com__ClassProperty * parent;
struct __ecereNameSpace__ecere__com__ClassProperty * left;
struct __ecereNameSpace__ecere__com__ClassProperty * right;
int depth;
void (*  Set)(struct __ecereNameSpace__ecere__com__Class *, long long);
long long (*  Get)(struct __ecereNameSpace__ecere__com__Class *);
const char *  dataTypeString;
struct Type * dataType;
unsigned int constant;
} __attribute__ ((gcc_struct));

static void FreeClassProperties(struct __ecereNameSpace__ecere__com__ClassProperty * classProp)
{
if(classProp->left)
FreeClassProperties(classProp->left);
if(classProp->right)
FreeClassProperties(classProp->right);
if(classProp->dataType)
{
FreeType(classProp->dataType);
classProp->dataType = (((void *)0));
}
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__NameSpace;

struct __ecereNameSpace__ecere__com__NameSpace
{
const char *  name;
struct __ecereNameSpace__ecere__com__NameSpace *  btParent;
struct __ecereNameSpace__ecere__com__NameSpace *  left;
struct __ecereNameSpace__ecere__com__NameSpace *  right;
int depth;
struct __ecereNameSpace__ecere__com__NameSpace *  parent;
struct __ecereNameSpace__ecere__sys__BinaryTree nameSpaces;
struct __ecereNameSpace__ecere__sys__BinaryTree classes;
struct __ecereNameSpace__ecere__sys__BinaryTree defines;
struct __ecereNameSpace__ecere__sys__BinaryTree functions;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Module;

struct __ecereNameSpace__ecere__com__Module
{
struct __ecereNameSpace__ecere__com__Instance * application;
struct __ecereNameSpace__ecere__sys__OldList classes;
struct __ecereNameSpace__ecere__sys__OldList defines;
struct __ecereNameSpace__ecere__sys__OldList functions;
struct __ecereNameSpace__ecere__sys__OldList modules;
struct __ecereNameSpace__ecere__com__Instance * prev;
struct __ecereNameSpace__ecere__com__Instance * next;
const char *  name;
void *  library;
void *  Unload;
int importType;
int origImportType;
struct __ecereNameSpace__ecere__com__NameSpace privateNameSpace;
struct __ecereNameSpace__ecere__com__NameSpace publicNameSpace;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__ClassTemplateParameter;

struct __ecereNameSpace__ecere__com__ClassTemplateParameter
{
struct __ecereNameSpace__ecere__com__ClassTemplateParameter * prev;
struct __ecereNameSpace__ecere__com__ClassTemplateParameter * next;
const char *  name;
int type;
union
{
const char *  dataTypeString;
int memberType;
} __attribute__ ((gcc_struct)) __anon1;
struct __ecereNameSpace__ecere__com__ClassTemplateArgument defaultArg;
void *  param;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__GlobalFunction;

struct __ecereNameSpace__ecere__com__GlobalFunction
{
struct __ecereNameSpace__ecere__com__GlobalFunction * prev;
struct __ecereNameSpace__ecere__com__GlobalFunction * next;
const char *  name;
int (*  function)();
struct __ecereNameSpace__ecere__com__Instance * module;
struct __ecereNameSpace__ecere__com__NameSpace *  nameSpace;
const char *  dataTypeString;
struct Type * dataType;
void *  symbol;
} __attribute__ ((gcc_struct));

extern unsigned int inCompiler;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__IteratorPointer;

struct __ecereNameSpace__ecere__com__IteratorPointer;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__MapIterator;

struct __ecereNameSpace__ecere__com__MapIterator
{
struct __ecereNameSpace__ecere__com__Instance * container;
struct __ecereNameSpace__ecere__com__IteratorPointer * pointer;
} __attribute__ ((gcc_struct));

extern struct __ecereNameSpace__ecere__com__Instance * loadedModules;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Iterator;

struct __ecereNameSpace__ecere__com__Iterator
{
struct __ecereNameSpace__ecere__com__Instance * container;
struct __ecereNameSpace__ecere__com__IteratorPointer * pointer;
} __attribute__ ((gcc_struct));

extern void __ecereNameSpace__ecere__com__eModule_Unload(struct __ecereNameSpace__ecere__com__Instance * fromModule, struct __ecereNameSpace__ecere__com__Instance * module);

extern struct __ecereNameSpace__ecere__com__Instance * __thisModule;

struct __ecereNameSpace__ecere__sys__BTNode * __ecereProp___ecereNameSpace__ecere__sys__BinaryTree_Get_first(struct __ecereNameSpace__ecere__sys__BinaryTree * this);

extern struct __ecereNameSpace__ecere__com__Property * __ecereProp___ecereNameSpace__ecere__sys__BinaryTree_first;

struct __ecereNameSpace__ecere__sys__BTNode * __ecereProp___ecereNameSpace__ecere__sys__BTNode_Get_next(struct __ecereNameSpace__ecere__sys__BTNode * this);

extern struct __ecereNameSpace__ecere__com__Property * __ecereProp___ecereNameSpace__ecere__sys__BTNode_next;

struct __ecereNameSpace__ecere__com__Instance * __ecereProp___ecereNameSpace__ecere__com__MapIterator_Get_map(struct __ecereNameSpace__ecere__com__MapIterator * this);

void __ecereProp___ecereNameSpace__ecere__com__MapIterator_Set_map(struct __ecereNameSpace__ecere__com__MapIterator * this, struct __ecereNameSpace__ecere__com__Instance * value);

extern struct __ecereNameSpace__ecere__com__Property * __ecereProp___ecereNameSpace__ecere__com__MapIterator_map;

unsigned int __ecereMethod___ecereNameSpace__ecere__com__Iterator_Next();

uint64 __ecereProp___ecereNameSpace__ecere__com__Iterator_Get_data(struct __ecereNameSpace__ecere__com__Iterator * this);

void __ecereProp___ecereNameSpace__ecere__com__Iterator_Set_data(struct __ecereNameSpace__ecere__com__Iterator * this, uint64 value);

extern struct __ecereNameSpace__ecere__com__Property * __ecereProp___ecereNameSpace__ecere__com__Iterator_data;

int __ecereVMethodID___ecereNameSpace__ecere__com__Container_Remove;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__List;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__LinkList;

struct __ecereNameSpace__ecere__com__LinkList
{
void * first;
void * last;
int count;
} __attribute__ ((gcc_struct));

unsigned int __ecereMethod___ecereNameSpace__ecere__com__Iterator_Index(struct __ecereNameSpace__ecere__com__Iterator * this, const uint64 index, unsigned int create);

int __ecereVMethodID___ecereNameSpace__ecere__com__Container_GetFirst;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Map;

void FreeModuleData(struct __ecereNameSpace__ecere__com__Instance * module)
{
struct __ecereNameSpace__ecere__com__Class * _class;
struct __ecereNameSpace__ecere__com__GlobalFunction * function;

for(_class = ((struct __ecereNameSpace__ecere__com__Module *)(((char *)module + structSize_Instance)))->classes.first; _class; _class = _class->next)
{
struct __ecereNameSpace__ecere__com__DataMember * dataMember;
struct __ecereNameSpace__ecere__com__Method * method;
struct __ecereNameSpace__ecere__com__ClassTemplateParameter * param;

if(_class->dataType)
{
FreeType(_class->dataType);
_class->dataType = (((void *)0));
}
for(dataMember = _class->membersAndProperties.first; dataMember; dataMember = dataMember->next)
{
if(dataMember->isProperty)
{
struct __ecereNameSpace__ecere__com__Property * prop = (struct __ecereNameSpace__ecere__com__Property *)dataMember;

if(prop->symbol)
{
FreeSymbol(prop->symbol);
}
}
else
{
if(dataMember->type == 2 || dataMember->type == 1)
FreeDataMember(dataMember);
}
if(dataMember->dataType)
{
FreeType(dataMember->dataType);
dataMember->dataType = (((void *)0));
}
}
for(dataMember = _class->conversions.first; dataMember; dataMember = dataMember->next)
{
struct __ecereNameSpace__ecere__com__Property * prop = (struct __ecereNameSpace__ecere__com__Property *)dataMember;

if(prop->symbol)
{
FreeSymbol(prop->symbol);
}
if(prop->dataType)
{
FreeType(prop->dataType);
prop->dataType = (((void *)0));
}
}
if(__ecereProp___ecereNameSpace__ecere__sys__BinaryTree_Get_first(&_class->classProperties))
FreeClassProperties((struct __ecereNameSpace__ecere__com__ClassProperty *)__ecereProp___ecereNameSpace__ecere__sys__BinaryTree_Get_first(&_class->classProperties));
for(method = (struct __ecereNameSpace__ecere__com__Method *)__ecereProp___ecereNameSpace__ecere__sys__BinaryTree_Get_first(&_class->methods); method; method = (struct __ecereNameSpace__ecere__com__Method *)__ecereProp___ecereNameSpace__ecere__sys__BTNode_Get_next(((struct __ecereNameSpace__ecere__sys__BTNode *)method)))
{
if(method->dataType)
{
FreeType(method->dataType);
method->dataType = (((void *)0));
}
if(method->symbol)
{
FreeSymbol(method->symbol);
}
}
for(param = _class->templateParams.first; param; param = param->next)
{
if(param->param)
{
FreeTemplateParameter(param->param);
param->param = (((void *)0));
}
}
}
for(function = ((struct __ecereNameSpace__ecere__com__Module *)(((char *)module + structSize_Instance)))->functions.first; function; function = function->next)
{
if(function->dataType)
FreeType(function->dataType);
if(function->symbol)
FreeSymbol(function->symbol);
}
if(!inCompiler)
{
struct __ecereNameSpace__ecere__com__MapIterator mapIt = (mapIt.container = (void *)0, mapIt.pointer = (void *)0, __ecereProp___ecereNameSpace__ecere__com__MapIterator_Set_map(&mapIt, loadedModules), mapIt);

while(__ecereMethod___ecereNameSpace__ecere__com__Iterator_Next((void *)(&mapIt)))
{
struct __ecereNameSpace__ecere__com__Instance * list = ((struct __ecereNameSpace__ecere__com__Instance *)__ecereProp___ecereNameSpace__ecere__com__Iterator_Get_data((void *)(&mapIt)));
struct __ecereNameSpace__ecere__com__Iterator it =
{
list, 0
};
unsigned int found = 0;

while(__ecereMethod___ecereNameSpace__ecere__com__Iterator_Next(&it))
{
if(((struct __ecereNameSpace__ecere__com__Instance *)__ecereProp___ecereNameSpace__ecere__com__Iterator_Get_data(&it)) == module)
{
((void (*)(struct __ecereNameSpace__ecere__com__Instance *, struct __ecereNameSpace__ecere__com__IteratorPointer * it))__extension__ ({
struct __ecereNameSpace__ecere__com__Instance * __internal_ClassInst = list;

__internal_ClassInst ? __internal_ClassInst->_vTbl : __ecereClass___ecereNameSpace__ecere__com__List->_vTbl;
})[__ecereVMethodID___ecereNameSpace__ecere__com__Container_Remove])(list, it.pointer);
found = 1;
break;
}
}
if(found)
{
if(((struct __ecereNameSpace__ecere__com__LinkList *)(((char *)list + structSize_Instance)))->count == 1)
{
struct __ecereNameSpace__ecere__com__Instance * mod = (((struct __ecereNameSpace__ecere__com__Instance *)(__extension__ ({
struct __ecereNameSpace__ecere__com__Iterator __internalIterator =
{
list, 0
};

__ecereMethod___ecereNameSpace__ecere__com__Iterator_Index(&__internalIterator, ((uint64)(0)), 0);
((struct __ecereNameSpace__ecere__com__Instance *)__ecereProp___ecereNameSpace__ecere__com__Iterator_Get_data(&__internalIterator));
}))));

((void (*)(struct __ecereNameSpace__ecere__com__Instance *, struct __ecereNameSpace__ecere__com__IteratorPointer * it))__extension__ ({
struct __ecereNameSpace__ecere__com__Instance * __internal_ClassInst = list;

__internal_ClassInst ? __internal_ClassInst->_vTbl : __ecereClass___ecereNameSpace__ecere__com__List->_vTbl;
})[__ecereVMethodID___ecereNameSpace__ecere__com__Container_Remove])(list, ((struct __ecereNameSpace__ecere__com__IteratorPointer * (*)(struct __ecereNameSpace__ecere__com__Instance *))__extension__ ({
struct __ecereNameSpace__ecere__com__Instance * __internal_ClassInst = list;

__internal_ClassInst ? __internal_ClassInst->_vTbl : __ecereClass___ecereNameSpace__ecere__com__List->_vTbl;
})[__ecereVMethodID___ecereNameSpace__ecere__com__Container_GetFirst])(list));
((void (*)(struct __ecereNameSpace__ecere__com__Instance *, struct __ecereNameSpace__ecere__com__IteratorPointer * it))__extension__ ({
struct __ecereNameSpace__ecere__com__Instance * __internal_ClassInst = loadedModules;

__internal_ClassInst ? __internal_ClassInst->_vTbl : __ecereClass___ecereNameSpace__ecere__com__Map->_vTbl;
})[__ecereVMethodID___ecereNameSpace__ecere__com__Container_Remove])(loadedModules, mapIt.pointer);
(__ecereNameSpace__ecere__com__eInstance_DecRef(list), list = 0);
__ecereNameSpace__ecere__com__eModule_Unload(((struct __ecereNameSpace__ecere__com__Module *)(((char *)__thisModule + structSize_Instance)))->application, mod);
}
break;
}
}
}
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Application;

struct __ecereNameSpace__ecere__com__Application
{
int argc;
const char * *  argv;
int exitCode;
unsigned int isGUIApp;
struct __ecereNameSpace__ecere__sys__OldList allModules;
char *  parsedCommand;
struct __ecereNameSpace__ecere__com__NameSpace systemNameSpace;
} __attribute__ ((gcc_struct));

void FreeTypeData(struct __ecereNameSpace__ecere__com__Instance * privateModule)
{
struct __ecereNameSpace__ecere__com__Instance * m;

for(m = ((struct __ecereNameSpace__ecere__com__Application *)(((char *)((struct __ecereNameSpace__ecere__com__Module *)(((char *)privateModule + structSize_Instance)))->application + structSize_Module)))->allModules.first; m; m = ((struct __ecereNameSpace__ecere__com__Module *)(((char *)m + structSize_Instance)))->next)
{
FreeModuleData(m);
}
FreeModuleData(privateModule);
}

extern struct __ecereNameSpace__ecere__com__GlobalFunction * __ecereNameSpace__ecere__com__eSystem_RegisterFunction(const char *  name, const char *  type, void *  func, struct __ecereNameSpace__ecere__com__Instance * module, int declMode);

void __ecereRegisterModule_freeAst(struct __ecereNameSpace__ecere__com__Instance * module)
{
struct __ecereNameSpace__ecere__com__Class __attribute__((unused)) * class;

__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeList", "void FreeList(ecere::sys::OldList list, void (* FreeFunction)(void *))", FreeList, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeType", "void FreeType(Type type)", FreeType, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeSymbol", "void FreeSymbol(Symbol symbol)", FreeSymbol, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeMethodImport", "void FreeMethodImport(MethodImport imp)", FreeMethodImport, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreePropertyImport", "void FreePropertyImport(MethodImport imp)", FreePropertyImport, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeClassImport", "void FreeClassImport(ClassImport imp)", FreeClassImport, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeFunctionImport", "void FreeFunctionImport(ClassImport imp)", FreeFunctionImport, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeModuleImport", "void FreeModuleImport(ModuleImport imp)", FreeModuleImport, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeModuleDefine", "void FreeModuleDefine(Definition def)", FreeModuleDefine, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeExcludedSymbols", "void FreeExcludedSymbols(ecere::sys::OldList excludedSymbols)", FreeExcludedSymbols, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeTemplateArgument", "void FreeTemplateArgument(TemplateArgument arg)", FreeTemplateArgument, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeTemplateDataType", "void FreeTemplateDataType(TemplateDatatype type)", FreeTemplateDataType, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeTemplateParameter", "void FreeTemplateParameter(TemplateParameter param)", FreeTemplateParameter, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeTemplateType", "void FreeTemplateType(TemplatedType type)", FreeTemplateType, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeContext", "void FreeContext(Context context)", FreeContext, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeEnumerator", "void FreeEnumerator(Enumerator enumerator)", FreeEnumerator, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeSpecifier", "void FreeSpecifier(Specifier spec)", FreeSpecifier, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeSpecifierContents", "void FreeSpecifierContents(Specifier spec)", FreeSpecifierContents, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeIdentifier", "void FreeIdentifier(Identifier id)", FreeIdentifier, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeTypeName", "void FreeTypeName(TypeName typeName)", FreeTypeName, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeExpContents", "void FreeExpContents(Expression exp)", FreeExpContents, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeExpression", "void FreeExpression(Expression exp)", FreeExpression, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreePointer", "void FreePointer(Pointer pointer)", FreePointer, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeAttrib", "void FreeAttrib(Attrib attr)", FreeAttrib, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeAttribute", "void FreeAttribute(Attribute attr)", FreeAttribute, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeExtDecl", "void FreeExtDecl(ExtDecl extDecl)", FreeExtDecl, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeDeclarator", "void FreeDeclarator(Declarator decl)", FreeDeclarator, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreePropertyWatch", "void FreePropertyWatch(PropertyWatch watcher)", FreePropertyWatch, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeAsmField", "void FreeAsmField(AsmField field)", FreeAsmField, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeStatement", "void FreeStatement(Statement stmt)", FreeStatement, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeInitializer", "void FreeInitializer(Initializer initializer)", FreeInitializer, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeInitDeclarator", "void FreeInitDeclarator(InitDeclarator decl)", FreeInitDeclarator, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeDeclaration", "void FreeDeclaration(Declaration decl)", FreeDeclaration, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeFunction", "void FreeFunction(FunctionDefinition func)", FreeFunction, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeMemberInit", "void FreeMemberInit(MemberInit init)", FreeMemberInit, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeMembersInit", "void FreeMembersInit(MembersInit init)", FreeMembersInit, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeInstance", "void FreeInstance(Instantiation inst)", FreeInstance, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeClassFunction", "void FreeClassFunction(ClassFunction func)", FreeClassFunction, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeProperty", "void FreeProperty(PropertyDef def)", FreeProperty, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeClassDef", "void FreeClassDef(ClassDef def)", FreeClassDef, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeClass", "void FreeClass(ClassDefinition _class)", FreeClass, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeDBIndexItem", "void FreeDBIndexItem(DBIndexItem item)", FreeDBIndexItem, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeDBTableEntry", "void FreeDBTableEntry(DBTableEntry entry)", FreeDBTableEntry, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeDBTable", "void FreeDBTable(DBTableDef table)", FreeDBTable, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeExternal", "void FreeExternal(External external)", FreeExternal, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeASTTree", "void FreeASTTree(ecere::sys::OldList ast)", FreeASTTree, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeModuleData", "void FreeModuleData(ecere::com::Module module)", FreeModuleData, module, 2);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("FreeTypeData", "void FreeTypeData(ecere::com::Module privateModule)", FreeTypeData, module, 1);
}

void __ecereUnregisterModule_freeAst(struct __ecereNameSpace__ecere__com__Instance * module)
{

}

