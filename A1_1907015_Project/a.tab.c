
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "a.y"

    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;
    extern FILE *yyout;
    
    // Symbol table structure
    struct SymbolTable {
    char* name;
    int isAssigned;
    int intValue;
    float floatValue;
    int dataType;  // 0 for INT, 1 for FLOAT, add more if needed
    };

    struct FunctionTable {
    char* name;
    int no_of_param;
    int return_value_int;
    float return_value_float;
    int return_type;  // 0 for INT, 1 for FLOAT, add more if needed
    };
    
    struct SymbolTable* searchVariable(char* name);
    struct FunctionTable* searchFunction(char* name);

    

    int type_of_data;
    int condition_val = 1;
    /*int loop_inc_val;
    int loop_inc_op;
    int loop_ini_val;
    int loop_con_st_val;
    int loop_con_end_val;
    int loop_con_op;*/
    int no_of_func_param=0;

    // Function to insert a new variable into the symbol table
    void insertVariable(char* name, int isAssigned, int intValue, float floatValue, int dataType);
    void insertFunction(char* name, int no_of_param, int return_value_int, float return_value_float, int return_type);

    void yyerror(char *s); //declaration
    #define MAX_SYMBOLS 100
    struct SymbolTable symbolTable[MAX_SYMBOLS];
    struct FunctionTable functionTable[MAX_SYMBOLS];

int index = 0;
int functionTableSize = 0;


/* Line 189 of yacc.c  */
#line 125 "a.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     FLOAT = 260,
     INPUT = 261,
     SIN = 262,
     COS = 263,
     TAN = 264,
     FACTORIAL = 265,
     PRIME = 266,
     FUNC = 267,
     RETURN = 268,
     HEADERFILE = 269,
     MAINSTART = 270,
     SINGLE_LINE_COMMENT = 271,
     MULTI_LINE_COMMENT = 272,
     INT = 273,
     HASH = 274,
     DOT = 275,
     LT = 276,
     GT = 277,
     NEWLINE = 278,
     TAB = 279,
     SPACE = 280,
     HASH_HASH = 281,
     COMMENT = 282,
     IF = 283,
     ELSE = 284,
     SHOW = 285,
     LOOP = 286,
     IFX = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 65 "a.y"

    int intValue;
        float floatValue;
        char *stringValue;
 



/* Line 214 of yacc.c  */
#line 202 "a.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 214 "a.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    46,     2,     2,     2,     2,
      41,    42,    36,    34,    45,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      32,    40,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    12,    15,    16,    19,
      23,    25,    27,    28,    31,    34,    37,    40,    43,    46,
      49,    52,    60,    68,    74,    80,    86,    92,    98,   111,
     113,   114,   116,   120,   122,   124,   130,   132,   134,   136,
     138,   140,   142,   144,   146,   163,   167,   169,   170,   183,
     192,   193,   198,   204,   208,   212,   216,   220,   222,   224,
     228,   232,   236,   240,   242,   246,   252,   254,   256,   258,
     262,   266,   270,   274,   278,   282,   286,   290,   294,   298,
     302,   306,   308,   312,   318,   320
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    53,    -1,    50,    52,    -1,    51,
      -1,    -1,    14,    51,    -1,    -1,    59,    52,    -1,    54,
      56,    55,    -1,    15,    -1,    39,    -1,    -1,    56,    73,
      -1,    56,    72,    -1,    56,    68,    -1,    56,    69,    -1,
      56,    66,    -1,    56,    63,    -1,    56,    58,    -1,    56,
      57,    -1,     3,    40,     6,    41,     5,    42,    43,    -1,
       3,    40,     6,    41,     4,    42,    43,    -1,    11,    41,
       4,    42,    43,    -1,    10,    41,     4,    42,    43,    -1,
       7,    41,     5,    42,    43,    -1,     8,    41,     5,    42,
      43,    -1,     9,    41,     5,    42,    43,    -1,    60,    76,
       3,    41,    61,    42,    44,    56,    13,    62,    43,    39,
      -1,    12,    -1,    -1,    71,    -1,    61,    45,    71,    -1,
       5,    -1,     4,    -1,     3,    41,    61,    42,    43,    -1,
      32,    -1,    33,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    31,    46,    67,    46,
       3,    64,     4,    46,     3,    40,     3,    65,     4,    46,
      56,    46,    -1,     3,    40,     4,    -1,     3,    -1,    -1,
      68,    28,    41,    70,    42,    44,    56,    39,    29,    44,
      56,    39,    -1,    68,    28,    41,    70,    42,    44,    56,
      39,    -1,    -1,     3,    40,    71,    43,    -1,    30,    41,
      74,    42,    43,    -1,    71,    32,    71,    -1,    71,    33,
      71,    -1,    71,    32,    71,    -1,    71,    33,    71,    -1,
       4,    -1,     3,    -1,    71,    34,    71,    -1,    71,    35,
      71,    -1,    71,    36,    71,    -1,    71,    37,    71,    -1,
      16,    -1,    76,     3,    75,    -1,    76,     3,    40,    74,
      75,    -1,     5,    -1,     4,    -1,     3,    -1,    74,    34,
       3,    -1,    74,    34,     4,    -1,    74,    34,     5,    -1,
      74,    35,     3,    -1,    74,    35,     4,    -1,    74,    35,
       5,    -1,    74,    36,     3,    -1,    74,    36,     4,    -1,
      74,    36,     5,    -1,    74,    37,     3,    -1,    74,    37,
       4,    -1,    74,    37,     5,    -1,    43,    -1,    45,     3,
      75,    -1,    45,     3,    40,    74,    75,    -1,    18,    -1,
       5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    83,    85,    86,    87,    89,    90,    93,
      95,    97,   105,   106,   107,   108,   109,   111,   112,   113,
     114,   118,   140,   166,   183,   196,   201,   206,   218,   227,
     228,   229,   230,   233,   238,   247,   263,   264,   265,   266,
     269,   270,   271,   272,   274,   369,   385,   400,   401,   402,
     406,   407,   429,   435,   447,   459,   471,   486,   487,   505,
     506,   507,   508,   512,   517,   528,   548,   549,   550,   568,
     586,   587,   588,   606,   607,   608,   626,   627,   629,   647,
     648,   650,   651,   661,   674,   675
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "FLOAT", "INPUT", "SIN",
  "COS", "TAN", "FACTORIAL", "PRIME", "FUNC", "RETURN", "HEADERFILE",
  "MAINSTART", "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT", "INT", "HASH",
  "DOT", "LT", "GT", "NEWLINE", "TAB", "SPACE", "HASH_HASH", "COMMENT",
  "IF", "ELSE", "SHOW", "LOOP", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "IFX", "'}'", "'='", "'('", "')'", "';'", "'{'", "','", "'#'", "$accept",
  "start", "header", "header1", "header2", "user_function", "main",
  "main2", "main3", "mainbegin2", "user_input", "builtin_function",
  "function", "func_start", "parameter_list", "return_val",
  "function_call", "loop_con_symbol", "loop_inc_symbol", "loop_structure",
  "initialize", "if_structure", "statement", "condition", "expression",
  "comment", "var_dec", "var_dec2", "var_dec1", "data_type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    60,    62,    43,    45,    42,    47,   287,   125,
      61,    40,    41,    59,   123,    44,    35
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    52,    52,    53,
      54,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    59,    60,
      61,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    67,    67,    68,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     2,     0,     2,     3,
       1,     1,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     7,     7,     5,     5,     5,     5,     5,    12,     1,
       0,     1,     3,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,    16,     3,     1,     0,    12,     8,
       0,     4,     5,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     3,     5,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     5,     0,     0,     7,     4,     6,     1,    10,     2,
      12,    29,     3,     7,     0,    47,     8,    85,    84,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,    11,
       9,    20,    19,    18,    17,    15,    16,    14,    13,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    58,    57,     0,     0,     0,    31,     0,
       0,     0,     0,     0,    68,    67,    66,     0,    46,     0,
       0,     0,    81,     0,    64,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    35,    32,    25,
      26,    27,    24,    23,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    52,    45,     0,     0,
       0,     0,    65,     0,    82,    12,     0,     0,    36,    37,
       0,    12,    53,    54,     0,    47,    22,    21,     0,    47,
      83,     0,     0,    49,    34,    33,     0,     0,     0,     0,
       0,    12,    28,     0,    47,    40,    41,    42,    43,     0,
      48,     0,    12,    47,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    12,     9,    10,    30,    15,
      31,    32,    13,    14,    57,   156,    33,   140,   169,    34,
      69,    35,    36,    96,    58,    37,    38,    67,    74,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -129
static const yytype_int16 yypact[] =
{
       6,     6,    50,    53,    40,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,    40,     0,    46,  -129,  -129,  -129,    78,
      -6,    58,    74,    76,    82,    87,  -129,    92,    41,  -129,
    -129,  -129,  -129,  -129,  -129,    63,  -129,  -129,  -129,   105,
     102,    37,    42,   140,   161,   162,   164,   165,    11,   167,
     131,    39,    42,  -129,  -129,   132,   -13,    65,    -9,   129,
     133,   134,   135,   136,  -129,  -129,  -129,    24,   139,   128,
      42,    11,  -129,   177,  -129,    67,    70,    42,    42,    42,
      42,  -129,   138,    42,   141,   142,   143,   144,   145,   127,
     150,   153,   156,   146,   178,   180,   148,   115,   101,    43,
     147,   151,   152,   103,   103,  -129,  -129,  -129,    -9,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,   130,   154,
      42,    42,  -129,    11,  -129,  -129,   149,   157,  -129,  -129,
     191,  -129,    -9,    -9,   101,   111,  -129,  -129,   155,    62,
    -129,   160,   193,   168,  -129,  -129,   159,   163,   166,   169,
     196,  -129,  -129,    60,    95,  -129,  -129,  -129,  -129,   200,
    -129,   170,  -129,     1,  -129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,   204,   194,  -129,  -129,  -129,  -128,
    -129,  -129,  -129,  -129,   171,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,   -41,  -129,  -129,   -70,   -96,   192
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    98,   132,   134,    20,    17,    17,   145,    21,    22,
      23,    24,    25,   149,    64,    65,    66,    26,    18,    18,
       1,    77,    78,    79,    80,    77,    78,    79,    80,    97,
      81,    27,    28,   164,    41,    42,   103,   104,   105,   106,
      53,    54,   108,    55,   173,    53,    54,   174,   150,    20,
       7,    17,    11,    21,    22,    23,    24,    25,    89,    90,
      91,    92,    26,   144,    18,    20,    93,    17,     8,    21,
      22,    23,    24,    25,   101,   102,    27,    28,    26,    71,
      18,    40,    72,   133,    73,    29,    72,    49,    73,   142,
     143,    50,    27,    28,   165,   166,   167,   168,    20,    43,
      17,   153,    21,    22,    23,    24,    25,    82,    51,   100,
      83,    26,    83,    18,    20,    44,    17,    45,    21,    22,
      23,    24,    25,    46,   151,    27,    28,    26,    47,    18,
     114,   115,   116,    48,   170,    89,    90,    91,    92,    79,
      80,    27,    28,    52,    72,    59,    73,   130,   131,    77,
      78,    79,    80,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   138,   139,   154,   155,    60,    61,    62,    63,
      68,    84,    70,    76,    95,    85,    86,    87,    88,    94,
      99,   107,   127,   128,   109,   110,   111,   112,   113,   126,
     129,   135,   146,   136,   137,   148,   157,   158,   141,   163,
     147,   152,   159,   160,   171,     6,    19,    16,   162,     0,
     161,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,     0,     0,    75
};

static const yytype_int16 yycheck[] =
{
      41,    71,    98,    99,     3,     5,     5,   135,     7,     8,
       9,    10,    11,   141,     3,     4,     5,    16,    18,    18,
      14,    34,    35,    36,    37,    34,    35,    36,    37,    70,
      43,    30,    31,   161,    40,    41,    77,    78,    79,    80,
       3,     4,    83,     6,   172,     3,     4,    46,   144,     3,
       0,     5,    12,     7,     8,     9,    10,    11,    34,    35,
      36,    37,    16,   133,    18,     3,    42,     5,    15,     7,
       8,     9,    10,    11,     4,     5,    30,    31,    16,    40,
      18,     3,    43,    40,    45,    39,    43,    46,    45,   130,
     131,    28,    30,    31,    34,    35,    36,    37,     3,    41,
       5,    39,     7,     8,     9,    10,    11,    42,     3,    42,
      45,    16,    45,    18,     3,    41,     5,    41,     7,     8,
       9,    10,    11,    41,    13,    30,    31,    16,    41,    18,
       3,     4,     5,    41,    39,    34,    35,    36,    37,    36,
      37,    30,    31,    41,    43,     5,    45,    32,    33,    34,
      35,    36,    37,     3,     4,     5,     3,     4,     5,     3,
       4,     5,    32,    33,     4,     5,     5,     5,     4,     4,
       3,    42,    41,    41,    46,    42,    42,    42,    42,    40,
       3,    43,     4,     3,    43,    43,    43,    43,    43,    43,
      42,    44,    43,    42,    42,     4,     3,    29,    44,     3,
      43,    46,    43,    40,     4,     1,    14,    13,    39,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    48,    49,    50,    51,    51,     0,    15,    53,
      54,    12,    52,    59,    60,    56,    52,     5,    18,    76,
       3,     7,     8,     9,    10,    11,    16,    30,    31,    39,
      55,    57,    58,    63,    66,    68,    69,    72,    73,    76,
       3,    40,    41,    41,    41,    41,    41,    41,    41,    46,
      28,     3,    41,     3,     4,     6,    71,    61,    71,     5,
       5,     5,     4,     4,     3,     4,     5,    74,     3,    67,
      41,    40,    43,    45,    75,    61,    41,    34,    35,    36,
      37,    43,    42,    45,    42,    42,    42,    42,    42,    34,
      35,    36,    37,    42,    40,    46,    70,    71,    74,     3,
      42,     4,     5,    71,    71,    71,    71,    43,    71,    43,
      43,    43,    43,    43,     3,     4,     5,     3,     4,     5,
       3,     4,     5,     3,     4,     5,    43,     4,     3,    42,
      32,    33,    75,    40,    75,    44,    42,    42,    32,    33,
      64,    44,    71,    71,    74,    56,    43,    43,     4,    56,
      75,    13,    46,    39,     4,     5,    62,     3,    29,    43,
      40,    44,    39,     3,    56,    34,    35,    36,    37,    65,
      39,     4,    46,    56,    46
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 87 "a.y"
    {printf("HEADERFILE included\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 95 "a.y"
    {printf("\n\nMain Started.\n\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 97 "a.y"
    { printf("\n\n");
            printSymbolTable();
            printf("\n\n");
            printFunctionTable();
    printf("\n\nMain ENDED\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 118 "a.y"
    {
        
        struct SymbolTable* variable = searchVariable((yyvsp[(1) - (7)].stringValue));
            if(variable){
                printf("\nUser input is at variable %s with value %f\n",(yyvsp[(1) - (7)].stringValue),(yyvsp[(5) - (7)].floatValue));
                if (variable->dataType == 0) {
                    variable->isAssigned = 1;
                    variable->intValue = (yyvsp[(5) - (7)].floatValue);
                    variable->floatValue = (yyvsp[(5) - (7)].floatValue);
                } else if (variable->dataType == 1) {
                    variable->isAssigned = 1;
                    variable->intValue = (yyvsp[(5) - (7)].floatValue);
                    variable->floatValue = (yyvsp[(5) - (7)].floatValue);
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable not declared.\n");
            }

    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 140 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(1) - (7)].stringValue));
            if(variable){
                printf("\nUser input is at variable %s with value %d\n",(yyvsp[(1) - (7)].stringValue),(yyvsp[(5) - (7)].intValue));
                if (variable->dataType == 0) {
                    variable->isAssigned = 1;
                    variable->intValue = (yyvsp[(5) - (7)].intValue);
                    variable->floatValue = (yyvsp[(5) - (7)].intValue);
                } else if (variable->dataType == 1) {
                    variable->isAssigned = 1;
                    variable->intValue = (yyvsp[(5) - (7)].intValue);
                    variable->floatValue = (yyvsp[(5) - (7)].intValue);
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable not declared.\n");
            }
        ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 166 "a.y"
    {
            // this will check if prime or not
            int n, i, flag = 0;
            n = (yyvsp[(3) - (5)].intValue);
            if (n == 0 || n == 1){flag = 1;}
                        
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) { printf("%d is a prime number.", n); }
            else{
                printf("\n%d is not a prime number.\n", n);
            }
        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 183 "a.y"
    {
        // this will find FACTORIAL of a value
            int n, i;
            n = (yyvsp[(3) - (5)].intValue);
            unsigned long long fact = 1;
        if (n < 0){ printf("Error! Factorial of a negative number doesn't exist.");}
        else {
                for (i = 1; i <= n; ++i) {
                    fact *= i;
                }
                printf("\nFactorial of %d = %llu\n", n, fact);
        }
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 196 "a.y"
    {
        float i = (yyvsp[(3) - (5)].floatValue);
        float sin_value = sin(i);
        printf("The value of sin(%f) : %f \n", i, sin_value);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 201 "a.y"
    {
        float i = (yyvsp[(3) - (5)].floatValue);
        float cos_value = cos(i);
        printf("The value of cos(%f) : %f \n", i, cos_value)
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 206 "a.y"
    {
        float i = (yyvsp[(3) - (5)].floatValue);
        float tan_value = tan(i);
        printf("The value of tan(%f) : %f \n", i, tan_value);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 218 "a.y"
    {
    
    //printf("Number of parameter of this function is %d\n",no_of_func_param);
    insertFunction((yyvsp[(3) - (12)].stringValue), no_of_func_param, (yyvsp[(10) - (12)].floatValue), (yyvsp[(10) - (12)].floatValue), (yyvsp[(2) - (12)].intValue));
    //printf("Return value is %f\n",$10);
    no_of_func_param=0;
    printf("User defined function ended\n");
    //printFunctionTable();
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 227 "a.y"
    {printf("\n\nUser defined function started\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 229 "a.y"
    {no_of_func_param++; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 230 "a.y"
    {no_of_func_param++; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 233 "a.y"
    {  
                (yyval.floatValue) = (yyvsp[(1) - (1)].floatValue); // Store the parsed float value
                //printf("float %f %f\n",$1,$$);
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 238 "a.y"
    {   
                (yyval.floatValue) = (yyvsp[(1) - (1)].intValue); // Store the parsed integer value
                printf("float %d %d\n",(yyvsp[(1) - (1)].intValue),(yyval.floatValue));
        ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 247 "a.y"
    {
    struct FunctionTable* func = searchFunction((yyvsp[(1) - (5)].stringValue));
            if(func){
                if(func->no_of_param!=no_of_func_param){
                    printf("\nNo of parameter do not match\n");
                }
                else{
                    printf("\nUser defined Funtion Called\n");
                }
            }
             else {
                printf("\nFunction does not exist.\n");
            }
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 263 "a.y"
    {(yyval.intValue)=1;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 264 "a.y"
    {(yyval.intValue)=2;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 265 "a.y"
    {(yyval.intValue)=3;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 266 "a.y"
    {(yyval.intValue)=4;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 269 "a.y"
    {(yyval.intValue)=1; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 270 "a.y"
    {(yyval.intValue)=2;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 271 "a.y"
    {(yyval.intValue)=3;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 272 "a.y"
    {(yyval.intValue)=4;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 274 "a.y"
    {
        if((yyvsp[(6) - (16)].intValue)==1){
            if((yyvsp[(12) - (16)].intValue)==1){
                for(int i=(yyvsp[(3) - (16)].intValue);i<(yyvsp[(7) - (16)].intValue);i=i+(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==2){
                for(int i=(yyvsp[(3) - (16)].intValue);i<(yyvsp[(7) - (16)].intValue);i=i-(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==3){
                for(int i=(yyvsp[(3) - (16)].intValue);i<(yyvsp[(7) - (16)].intValue);i=i*(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==4){
                for(int i=(yyvsp[(3) - (16)].intValue);i<(yyvsp[(7) - (16)].intValue);i=i/(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
        }
        else if((yyvsp[(6) - (16)].intValue)==2){
            if((yyvsp[(12) - (16)].intValue)==1){
                for(int i=(yyvsp[(3) - (16)].intValue);i>(yyvsp[(7) - (16)].intValue);i=i+(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==2){
                for(int i=(yyvsp[(3) - (16)].intValue);i>(yyvsp[(7) - (16)].intValue);i=i-(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==3){
                for(int i=(yyvsp[(3) - (16)].intValue);i>(yyvsp[(7) - (16)].intValue);i=i*(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==4){
                for(int i=(yyvsp[(3) - (16)].intValue);i>(yyvsp[(7) - (16)].intValue);i=i/(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
        }
        else if((yyvsp[(6) - (16)].intValue)==3){
            if((yyvsp[(12) - (16)].intValue)==1){
                for(int i=(yyvsp[(3) - (16)].intValue);i<=(yyvsp[(7) - (16)].intValue);i=i+(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==2){
                for(int i=(yyvsp[(3) - (16)].intValue);i<=(yyvsp[(7) - (16)].intValue);i=i-(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==3){
                for(int i=(yyvsp[(3) - (16)].intValue);i<=(yyvsp[(7) - (16)].intValue);i=i*(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==4){
                for(int i=(yyvsp[(3) - (16)].intValue);i<=(yyvsp[(7) - (16)].intValue);i=i/(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
        }
        else if((yyvsp[(6) - (16)].intValue)==4){
            if((yyvsp[(12) - (16)].intValue)==1){
                for(int i=(yyvsp[(3) - (16)].intValue);i>=(yyvsp[(7) - (16)].intValue);i=i+(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==2){
                for(int i=(yyvsp[(3) - (16)].intValue);i>=(yyvsp[(7) - (16)].intValue);i=i-(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==3){
                for(int i=(yyvsp[(3) - (16)].intValue);i>=(yyvsp[(7) - (16)].intValue);i=i*(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
            else if((yyvsp[(12) - (16)].intValue)==4){
                for(int i=(yyvsp[(3) - (16)].intValue);i>=(yyvsp[(7) - (16)].intValue);i=i/(yyvsp[(13) - (16)].intValue)){
                    printf("value of var is %d\n",i);
                }
            }
        }

        printf("LOOP ENDED\n");
        
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 369 "a.y"
    {

            printf("\n\nLOOP STARTED\n");
            //loop_ini_val = $3;
                //printf("came to initialization\n");
                struct SymbolTable* variable = searchVariable((yyvsp[(1) - (3)].stringValue));
            if(variable){
                variable->intValue = (yyvsp[(3) - (3)].intValue);
                variable->floatValue = (yyvsp[(3) - (3)].intValue); 
                variable->isAssigned = 1;
                (yyval.intValue) = (yyvsp[(3) - (3)].intValue);
            }
             else {
                printf("Variable not declared.\n");
            }
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 385 "a.y"
    {
                    printf("\n\nLOOP STARTED\n");

            struct SymbolTable* variable = searchVariable((yyvsp[(1) - (1)].stringValue));
            if(variable){
                //loop_ini_val = variable->intValue ;
                (yyval.intValue) = variable->intValue;
            }
             else {
                printf("Variable not declared.\n");
            }
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 401 "a.y"
    { printf("\n  IF ELSE executed\n"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 402 "a.y"
    { printf("\n  IF executed\n"); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 407 "a.y"
    {
            //printf("statement\n");

            if(condition_val==1){
                struct SymbolTable* variable = searchVariable((yyvsp[(1) - (4)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    variable->intValue = (yyvsp[(3) - (4)].floatValue);
                    variable->floatValue = (yyvsp[(3) - (4)].floatValue);
                    variable->isAssigned = 1;
                } else {
                    // Handle other data types as needed
                    printf("Variable %s Not declared\n",(yyvsp[(1) - (4)].stringValue));
                }
            }
            //printSymbolTable();
         }
         else{
            condition_val=1;
         }
            
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 429 "a.y"
    {
            printf("\nprinting : %f\n",(yyvsp[(3) - (5)].floatValue));
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 435 "a.y"
    {  
       // printf("came to initialization <\n");
        /*loop_con_st_val = $1;
        loop_con_op = 1;
        loop_con_end_val = $3;*/
        if((yyvsp[(1) - (3)].floatValue)<(yyvsp[(3) - (3)].floatValue)){
             (yyval.intValue) = 1; } 
             else{
                (yyval.intValue)=0;
                condition_val=0;
             }
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 447 "a.y"
    {
        //printf("came to initialization >\n");
        /*loop_con_st_val = $1;
        loop_con_op = 2;
        loop_con_end_val = $3;*/
        if((yyvsp[(1) - (3)].floatValue)>(yyvsp[(3) - (3)].floatValue)){
             (yyval.intValue) = 1; } 
             else{
                (yyval.intValue)=0;
                condition_val=0;
             }
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 459 "a.y"
    {
        //printf("came to initialization <=\n");
        /*loop_con_st_val = $1;
        loop_con_op = 3;
        loop_con_end_val = $3;*/
        if((yyvsp[(1) - (3)].floatValue)<=(yyvsp[(3) - (3)].floatValue)){
             (yyval.intValue) = 1; } 
             else{
                (yyval.intValue)=0;
                condition_val=0;
             }
        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 471 "a.y"
    {
       // printf("came to initialization >=\n");
        /*loop_con_st_val = $1;
        loop_con_op = 4;
        loop_con_end_val = $3;*/
        if((yyvsp[(1) - (3)].floatValue)>=(yyvsp[(3) - (3)].floatValue)){
             (yyval.intValue) = 1; } 
             else{
                (yyval.intValue)=0;
                condition_val=0;
             }
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 486 "a.y"
    {(yyval.floatValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 487 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(1) - (1)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    (yyval.floatValue) = variable->intValue;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    (yyval.floatValue) = variable->floatValue;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 505 "a.y"
    {(yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) + (yyvsp[(3) - (3)].floatValue);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 506 "a.y"
    {(yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) - (yyvsp[(3) - (3)].floatValue);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 507 "a.y"
    {(yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) * (yyvsp[(3) - (3)].floatValue);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 508 "a.y"
    {(yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) / (yyvsp[(3) - (3)].floatValue);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 512 "a.y"
    {printf("\n\nSINGLE_LINE_COMMENT\n\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 517 "a.y"
    {
                
                struct SymbolTable* var = searchVariable((yyvsp[(2) - (3)].stringValue));
                if (var) {
                    printf("variable %s already exists\n",(yyvsp[(2) - (3)].stringValue));
                } else {
                    type_of_data = (yyvsp[(1) - (3)].intValue);
                    insertVariable((yyvsp[(2) - (3)].stringValue), 0, 0, 0, (yyvsp[(1) - (3)].intValue));
                    printf("Variable %s is declared\n",(yyvsp[(2) - (3)].stringValue));
                }   
            ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 528 "a.y"
    {
                
                struct SymbolTable* var = searchVariable((yyvsp[(2) - (5)].stringValue));
                if (var) {
                    printf("variable %s already exists\n",(yyvsp[(2) - (5)].stringValue));
                } else {
                    type_of_data = (yyvsp[(1) - (5)].intValue);
                    
                    if((yyvsp[(1) - (5)].intValue)==0||(yyvsp[(1) - (5)].intValue)==1){
                        insertVariable((yyvsp[(2) - (5)].stringValue), 1, (yyvsp[(4) - (5)].floatValue), (yyvsp[(4) - (5)].floatValue), (yyvsp[(1) - (5)].intValue));
                        printf("Variable %s is declared \n",(yyvsp[(2) - (5)].stringValue));
                    }
                    else{
                        printf("Type is not matched, give int or float\n");
                    }
                    
                     
                }
            ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 548 "a.y"
    { (yyval.floatValue) = (yyvsp[(1) - (1)].floatValue);  ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 549 "a.y"
    {   (yyval.floatValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 550 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(1) - (1)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    (yyval.floatValue) = variable->intValue;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    (yyval.floatValue) = variable->floatValue;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 568 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(3) - (3)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    (yyval.floatValue) = variable->intValue + (yyvsp[(1) - (3)].floatValue);
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    (yyval.floatValue) = variable->floatValue + (yyvsp[(1) - (3)].floatValue);
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 586 "a.y"
    {  (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) + (yyvsp[(3) - (3)].intValue) ;  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 587 "a.y"
    {  (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) + (yyvsp[(3) - (3)].floatValue) ;  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 588 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(3) - (3)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) - variable->intValue ;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) - variable->floatValue;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
                }
            } else {
                printf("Variable does not exist.\n");
            }
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 606 "a.y"
    { (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) - (yyvsp[(3) - (3)].intValue) ; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 607 "a.y"
    { (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) - (yyvsp[(3) - (3)].floatValue) ; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 608 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(3) - (3)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    (yyval.floatValue) = variable->intValue * (yyvsp[(1) - (3)].floatValue);
                   // printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    (yyval.floatValue) = variable->floatValue * (yyvsp[(1) - (3)].floatValue);
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable %s does not exist.\n", variable);
            }
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 626 "a.y"
    {  (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) * (yyvsp[(3) - (3)].intValue) ;  ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 627 "a.y"
    {  (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) * (yyvsp[(3) - (3)].floatValue) ;  ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 629 "a.y"
    {
            struct SymbolTable* variable = searchVariable((yyvsp[(3) - (3)].stringValue));
            if(variable){
                if (variable->dataType == 0) {
                    (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) / variable->intValue;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) / variable->floatValue ;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 647 "a.y"
    {  (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) / (yyvsp[(3) - (3)].intValue);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 648 "a.y"
    { (yyval.floatValue) = (yyvsp[(1) - (3)].floatValue) / (yyvsp[(3) - (3)].floatValue);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 651 "a.y"
    {
       // printf("ID is %s\n",$2);
                struct SymbolTable* var = searchVariable((yyvsp[(2) - (3)].stringValue));
                if (var) {
                    printf("variable %s already exists\n",(yyvsp[(2) - (3)].stringValue));
                } else {
                    insertVariable((yyvsp[(2) - (3)].stringValue), 0, 0, 0, type_of_data);
                    printf("Variable %s is declared\n",(yyvsp[(2) - (3)].stringValue));
                }
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 661 "a.y"
    {
       // printf("%s value is %d\n",$2,$4);
                struct SymbolTable* var = searchVariable((yyvsp[(2) - (5)].stringValue));
                if (var) {
                    printf("variable %s already exists\n",(yyvsp[(2) - (5)].stringValue));
                } else {
                    
                    insertVariable((yyvsp[(2) - (5)].stringValue), 1, (yyvsp[(4) - (5)].floatValue), (yyvsp[(4) - (5)].floatValue), type_of_data);
                    printf("Variable %s is declared\n",(yyvsp[(2) - (5)].stringValue));

                }
        ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 674 "a.y"
    { (yyval.intValue) = 0;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 675 "a.y"
    { (yyval.intValue) = 1;;}
    break;



/* Line 1455 of yacc.c  */
#line 2465 "a.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 682 "a.y"

int main()
{

    // Open a file for writing
    FILE *outputFile = fopen("output.txt", "w");

    // Check if the file opened successfully
    if (outputFile == NULL) {
        perror("Error opening output.txt");
        return EXIT_FAILURE;
    }
    if (freopen("output.txt", "w", stdout) == NULL)
    {
        perror("freopen");
        return EXIT_FAILURE;
    }
    
   yyin = freopen("wlc.txt","r",stdin);
    yyparse();
    printf("\nParser is finished");
    
    fclose(outputFile);


    return 0;
}


void yyerror(char *s)
{
    printf("Error %s\n",s);
    return;
}





// Symbol table management
struct SymbolTable* searchVariable(char* name) {
    // Implement your search logic here
     for (int i = 0; i < index; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return &symbolTable[i];
        }
    }
    return NULL;
}

void insertVariable(char* name, int isAssigned, int intValue, float floatValue, int dataType) {
    
    struct SymbolTable* symbol = searchVariable(name);

    if (symbol) {
        // Variable already exists, handle accordingly
        printf("Variable %s already exists\n", name);
    } else {
        if (index < MAX_SYMBOLS) {
            symbolTable[index].name = strdup(name);
            symbolTable[index].isAssigned = isAssigned;
            symbolTable[index].intValue = intValue;
            symbolTable[index].floatValue = floatValue;
            symbolTable[index].dataType = dataType;
            
            index++;

        } else {
            printf("Symbol table is full. Cannot insert %s\n", name);
        }
    }
}


void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Name", "IsAssigned", "IntValue", "FloatValue", "DataType");

    for (int i = 0; i < index; i++) {
        printf("%-20s%-15d", symbolTable[i].name, symbolTable[i].isAssigned);

        if (symbolTable[i].dataType == 0) {
            printf("%-15d%-15s%-15s\n", symbolTable[i].intValue, "-", "INT");
        } else if (symbolTable[i].dataType == 1) {
            printf("%-15s%-15.2f%-15s\n", "-", symbolTable[i].floatValue, "FLOAT");
        } else {
            // Handle other data types if needed
            printf("%-15s%-15s%-15s\n", "-", "-", "UNKNOWN");
        }
    }
}



//

// function table management
struct FunctionTable* searchFunction(char* name) {
    // Implement your search logic here
     for (int i = 0; i < functionTableSize; i++) {
        if (strcmp(functionTable[i].name, name) == 0) {
            return &functionTable[i];
        }
    }
    return NULL;
}

void insertFunction(char* name, int no_of_param, int return_value_int, float return_value_float, int return_type) {
   
    struct FunctionTable* symbol = searchFunction(name);

    if (symbol) {
        // Variable already exists, handle accordingly
        printf("Function %s already exists\n", name);
    } else {
        if (functionTableSize < MAX_SYMBOLS) {
            functionTable[functionTableSize].name = strdup(name);
            functionTable[functionTableSize].no_of_param = no_of_param;
            functionTable[functionTableSize].return_value_int = return_value_int;
            functionTable[functionTableSize].return_value_float = return_value_float;
            functionTable[functionTableSize].return_type = return_type;
            
            functionTableSize++;

           
        } else {
            printf("Symbol table is full. Cannot insert %s\n", name);
        }
    }
}

void printFunctionTable() {
    printf("Function Table:\n");
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Name", "No_of_Param", "Return_Int", "Return_Float", "Return_Type");

    for (int i = 0; i < functionTableSize; i++) {
        printf("%-20s%-15d", functionTable[i].name, functionTable[i].no_of_param);

        if (functionTable[i].return_type == 0) {
            printf("%-15d%-15s%-15s\n", functionTable[i].return_value_int, "-", "INT");
        } else if (functionTable[i].return_type == 1) {
            printf("%-15s%-15.2f%-15s\n", "-", functionTable[i].return_value_float, "FLOAT");
        } else {
            // Handle other return types if needed
            printf("%-15s%-15s%-15s\n", "-", "-", "UNKNOWN");
        }
    }
}

