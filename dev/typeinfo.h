/* Copyright (c) Microsoft Corporation. All rights reserved. */
/* Metadata for SOAP processing -jvh 2003 */
#ifndef __TYPEINFO_H_
#define __TYPEINFO_H_ 1

#include <mmlite.h>
#include <util/list-double2.h>
#include <wsif.h>
#include <soapif.h>

#define TOKEN_invalid (-1)

/* This is the dynamic type (layout) of the entry that follows */
typedef enum _ENTRY_TYPE {
    ENTRY_TYPE_ANY,
    ENTRY_TYPE_STRING,
    ENTRY_TYPE_ATTR,
    ENTRY_TYPE_NS_TABLE,
    ENTRY_TYPE_TEMPLATE,
    ENTRY_TYPE_METHOD,
    ENTRY_TYPE_XNS,
    ENTRY_TYPE_XNS_REF
} ENTRY_TYPE;

#define ENTRY_TYPE_INTERFACE ENTRY_TYPE_METHOD
#define ENTRY_TYPE_STRUCT ENTRY_TYPE_METHOD
#define ENTRY_TYPE_ARG ENTRY_TYPE_METHOD
#define ENTRY_TYPE_FIELD ENTRY_TYPE_METHOD

#define ENTRY_FLAGS_CONST        1 /* Not from heap */
#define ENTRY_FLAGS_UNQUALIFIED  2 /* XML content model expects no ns prefix */
#define ENTRY_FLAGS_METHOD_SCODE 4 /* method returns SCODE */
#define ENTRY_FLAGS_NAMELESS     8 /* do not output XML wrapper element */
#define ENTRY_FLAGS_METHOD_CIMCOMPAT  16 /* output extra elem_INPUT / elem_OUTPUT wrapper element */
#define ENTRY_FLAGS_METHOD_FULLY_QUALIFIED  32 /* Ouput QNAME fully qualified instead of using namespace prefix */

typedef struct _ANY_ENTRY {
    /* XXX Byte order dependent. (little endian assumed).
     * XXX AtomicInc used on entire struct.
     */
    UINT8 Type;
    UINT8 Flags;
    UINT16 RefCnt;
} ANY_ENTRY, *PANY_ENTRY;
typedef const struct _ANY_ENTRY *CPANY_ENTRY;

/* Subtype of any entry of type ENTRY_TYPE_METHOD */
enum DESCR_TYPE {
    DESCR_TYPE_ANY = 0,
    DESCR_TYPE_INTERFACE,
    DESCR_TYPE_METHOD,
    DESCR_TYPE_METHOD_RESPONSE,
    DESCR_TYPE_STRUCT,
    ARG_INT, /* xsd:int */
    ARG_INT64,   /* xsd:decimal */
    ARG_STRING,  /* xsd:string    sizeis or fixed size required for OUT */
    ARG_GUID,
    ARG_URI,     /* xsd:anyURI    marshaled as string */
    ARG_DATETIME,/* xsd:dateTime xsd:duration */
    ARG_FLOAT,   /* xsd:float */
    ARG_BOOL,    /* xsd:boolean */
    ARG_BLOB,    /* xsd:base64Binary
                  memory block. sizeis and lengthis for OUT, lengthis for IN
                  */
    ARG_IBUFFER, /* Binary data, encapsulated in IBuffer */
    ARG_OBJECT,  /* Object ref, serialized as URL */
    ARG_ANYTYPE, /* (16) Polymorphic: typeof QNAME contains actual type */

    ARG_THIS,    /* this pointer of virtual method */
    ARG_LISTNODE, /* node for linking into a list. Serialized as sequence. */
    ARG_LISTHEAD, /* Pointer to element that contains LISTNODE */
    ARG_CONTINUATION, /* non-remoted: current soap context */
    ARG_QNAME,   /* type of arg, DESCR_TYPE or structd */
    ARG_BITMAP,  /* selector bitmap: which fields to send / were received */
    ARG_STRUCT,
    DESCR_TYPE_COUNT            /* not used, max value */
};
#if defined(__cplusplus)
#else
typedef UINT32 DESCR_TYPE;
#endif

/* Encoding for string/BLOB/IBUFFER. Instructs serializer. */
#define ARGUMENT_DESCR_ENCODING_MASK     0x0007
#define ARGUMENT_DESCR_ENC_PLAIN              0
#define ARGUMENT_DESCR_ENC_CDATA              1
#define ARGUMENT_DESCR_ENC_BIN                2
#define ARGUMENT_DESCR_ENC_XOP                3
#define ARGUMENT_DESCR_ENC_BASE64             4
//#define ARGUMENT_DESCR_ENC_ATTR             5

//#define ARGUMENT_DESCR_ENC_NONE             6

//unused                                    5-7


//unused                                 0x0008

#define ARGUMENT_DESCR_FLAGS_IN          0x0010
#define ARGUMENT_DESCR_FLAGS_OUT         0x0020
#define ARGUMENT_DESCR_FLAGS_RETURN      0x0040
#define ARGUMENT_DESCR_FLAGS_OPTIONAL    0x0080
#define ARGUMENT_DESCR_FLAGS_MODIFIER_OF 0x0100
#define ARGUMENT_DESCR_FLAGS_ARRAY       0x0200
#define ARGUMENT_DESCR_FLAGS_BYREF       0x0400
#define ARGUMENT_DESCR_FLAGS_HEADER      0x0800
#define ARGUMENT_DESCR_FLAGS_TEXT        0x1000
#define ARGUMENT_DESCR_FLAGS_ATTRIBUTE   0x2000
#define ARGUMENT_DESCR_FLAGS_NONE        0x4000

#define ARGUMENT_DESCR_FLAGS_ISRESPONSE 0x8000 /* internal */
typedef UINT16 ARGUMENT_DESCR_FLAGS;

typedef struct _METHOD_DESCR *PARGUMENT_DESCR, *PINTERFACE_DESCR;
typedef const struct _METHOD_DESCR *CPARGUMENT_DESCR;
typedef const struct _METHOD_DESCR *CPMETHOD_DESCR;
typedef const struct _METHOD_DESCR *CPINTERFACE_DESCR;
typedef const struct _METHOD_DESCR *CPENTRY_DESCR;

/* table of namespace entries */
typedef struct _NS_TABLE {
    struct _ANY_ENTRY any;

    UINT Count;          /* 0 is empty */
    PANY_ENTRY Table[1];
} *PNS_TABLE;
typedef const struct _NS_TABLE *CPNS_TABLE;

/* Descriptor for storing strings */
typedef struct _STR_ENTRY {
    struct _ANY_ENTRY any;

    _TCHAR Str[1];
} STR_ENTRY, *PSTR_ENTRY;
typedef const struct _STR_ENTRY *CPSTR_ENTRY;

/* Probably temporary? */
enum nstype {
    NSTYPE_UNRESOLVED,
    NSTYPE_INTERFACE,
    NSTYPE_STRUCT,
    NSTYPE_ANY                  /* default default namespace */
};

typedef struct _STRING_TABLE_ENTRY *PSTRING_TABLE_ENTRY;
struct _STRING_TABLE_ENTRY {
    struct _STRING_TABLE_ENTRY *next;
    _TCHAR String[1];
};

/* Declared in saxif.xml */
struct XMLNAMESPACE {
    struct _ANY_ENTRY any;

    const _TCHAR *name;
    const _TCHAR *QName;
    enum nstype nstype;
    UINT16 id;            /* binary id for this namespace */
    UINT16 uri_length;    /* The part of QName that gets prepended to Action */
    CPINTERFACE_DESCR ifd;
    CPNS_TABLE entries;

    CPXMLNAMESPACE next;
};

/* This one is used simply for keeping track of "current namespace" */
typedef struct _XMLNAMESPACEREF {
    struct _ANY_ENTRY any;

    CPXMLNAMESPACE Xns;
    PSTR_ENTRY Prefix;          /* not yet used XXX */
    UINT xmldepth;              /* when validity ends */    
} *PXNS_REF_ENTRY;

/* Special "pointers" */
#define XMLNS_NONE ((PXMLNAMESPACE) 0)
/* The namespace in an xmlns:foo attribute */
#define XMLNS_DECLARE ((PXMLNAMESPACE) 1)
/* The empty namespace */
#define XMLNS_EMPTY GetNamespace(_T(""), 0)

/* Not everything needed by an interface fit into the same struct and
 * I didn't want to make the descriptor bigger for everyone so I added
 * this as an extension.
 */
struct _INTERFACE_EXTRAS {
    CPXMLNAMESPACE namespaces;
    REFIID iid;
    CPINTERFACE_DESCR SuperClass;
    CPINTERFACE_DESCR next;     /* Global list */
    UINT total_table_size;
};

/* This is really five different structs: interface, method, arg, struct, field
 * Since it was impossible to statically initialize unions and I wanted
 * everything in one big array, I had to make it one type. There is some
 * overlap but mostly they are similar items. The defined names try to make
 * the resultant code more understandable believe it or not.
 */
typedef struct _METHOD_DESCR {
    ANY_ENTRY any;
    const _TCHAR *name;
    INT16 NameToken;
    INT16 ResponseNameToken;
    CPARGUMENT_DESCR ptable;
#define _structd ptable         /* (arg/field) */
    UINT16  table_size;         /* (method/struct/iface) */
#define _Flags table_size       /* (arg/field) */
    INT16 Token;                /* (all) - index into table, binary token */
    DESCR_TYPE descr_type;      /* (all) */
    UINT16 FrameOffset;         /* (arg/field) */
#define _FrameSize FrameOffset  /* (method/struct) */
    /* ArraySize: (arg)
     * Fixed size if SizeIs/LengthIs not provided.
     * Maximum size otherwise (size-of generated for server).
     */
    UINT16 ArraySize;           /* (arg/field) */
#define _stacksize ArraySize    /* (method) */
#define _ListNodeOffset ArraySize    /* (arg/field) when ARG_LISTHEAD */
    INT8 TypeIsArg;            /* (arg/field) */
    INT8 SelectorIsArg;            /* (arg/field) */
    INT16 SizeIsArg;
#define _StupidCallAdjust SizeIsArg /* zero for cdecl. Stack adjust after call. (method) */
    INT16 LengthIsArg;
#define _Ordinal LengthIsArg    /* v-table index (method) */
    const struct _INTERFACE_EXTRAS *iface_extras;
//#define _responsename iface_extras /* (method) */

#define _structXns iface_extras /* (arg/field) _structd is in different ns */
} *PMETHOD_DESCR;

/* Temporary XXX */
struct TypeInfo {
    CPINTERFACE_DESCR ifacelist;
    UINT        interfacecount;
    CPXMLNAMESPACE XXXnamespaces;
    CPXMLNAMESPACE defaultns;
};

extern CPNS_TABLE pTheNamespaceNamespace;

#endif /* __TYPEINFO_H_ */