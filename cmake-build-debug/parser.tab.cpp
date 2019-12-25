/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"

    #include "parser.hpp"

    #include<iostream>
    using namespace std;

    int yylex();
    int yyerror(char const*);
    SymbolTable symbolTable;
    void checkOpTypes(Node*, Node*, int);
    void exitOnFalse(bool);


#line 84 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_GUY_PC_CLIONPROJECTS_HW3_1_CMAKE_BUILD_DEBUG_PARSER_TAB_HPP_INCLUDED
# define YY_YY_HOME_GUY_PC_CLIONPROJECTS_HW3_1_CMAKE_BUILD_DEBUG_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    BYTE = 260,
    B = 261,
    BOOL = 262,
    ENUM = 263,
    TRUE = 264,
    FALSE = 265,
    RETURN = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    BREAK = 270,
    CONTINUE = 271,
    PRECOND = 272,
    SC = 273,
    COMMA = 274,
    LPAREN = 275,
    RPAREN = 276,
    LBRACE = 277,
    RBRACE = 278,
    ID = 279,
    NUM = 280,
    STRING = 281,
    NOT = 282,
    AND = 283,
    OR = 284,
    ASSIGN = 285,
    EQUAL = 286,
    NOTEQUAL = 287,
    LESS = 288,
    GREATER = 289,
    LESSEQUAL = 290,
    GREATEREQUAL = 291,
    ADD = 292,
    SUB = 293,
    DIV = 294,
    MUL = 295,
    NO_ELSE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_HOME_GUY_PC_CLIONPROJECTS_HW3_1_CMAKE_BUILD_DEBUG_PARSER_TAB_HPP_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

#define YYUNDEFTOK  2
#define YYMAXUTOK   296

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    54,    55,    58,    58,    69,    72,    78,
      83,    84,    89,    89,    99,   100,   103,   106,   112,   116,
     122,   133,   134,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   154,   163,
     168,   174,   190,   208,   209,   212,   214,   216,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "ENUM", "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "PRECOND", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ID", "NUM", "STRING", "NOT", "AND", "OR", "ASSIGN", "EQUAL",
  "NOTEQUAL", "LESS", "GREATER", "LESSEQUAL", "GREATEREQUAL", "ADD", "SUB",
  "DIV", "MUL", "NO_ELSE", "$accept", "Program", "Enums", "EnumDecl",
  "$@1", "EnumeratorList", "Enumerator", "Funcs", "FuncDecl", "@2",
  "RetType", "Formals", "FormalsList", "FormalDecl", "Statements",
  "Statement", "EnumType", "MarkerWhileOn", "NewScope", "Call", "ExpList",
  "Type", "Exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-39)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,   -13,    32,    88,    -6,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,    88,    15,   -47,   -47,    18,   -47,    24,    23,
     278,   -47,   -15,   -47,    34,   -47,    40,    44,    23,    54,
     -47,   278,   -47,   -47,   -47,    61,   -47,    62,    63,    -3,
      69,   -47,    79,    80,   -47,    21,   -47,    38,   -47,    72,
      93,    96,   101,   -47,   -47,   -47,     9,   128,   162,   -47,
     300,   -47,    95,   300,   151,   -47,   -47,    62,   292,   300,
     -47,   -47,     7,   -47,     8,   170,   220,   -47,   301,   -47,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   240,   300,   223,   -47,   173,   186,   118,   -47,
     300,   -47,   300,   300,   -47,   313,   323,   105,   127,   150,
     172,   227,    78,    25,   -12,   176,   -47,    62,   260,   -47,
     -47,   300,   -47,   141,   164,   301,   200,    62,   -47,   -47,
     -47,    62,   -47,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    10,     3,     5,     1,    15,    45,    46,
      47,     2,    10,     0,    14,     4,     0,    11,     0,     0,
      16,     9,     0,     7,     0,    17,    18,     0,     0,     0,
      12,     0,    20,     8,     6,     0,    19,     0,     0,     0,
       0,    39,     0,     0,    40,     0,    26,     0,    21,     0,
       0,     0,     5,    58,    59,    31,     0,    53,    55,    57,
       0,    54,     0,     0,     0,    36,    37,     0,     0,     0,
      13,    22,     0,    30,     0,     0,     0,    56,    60,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,    43,     0,    25,
       0,    24,     0,     0,    48,    61,    62,    63,    64,    65,
      66,    67,    68,    49,    50,    52,    51,     0,     0,    23,
      41,     0,    29,     0,     0,    69,    33,     0,    44,    28,
      27,     0,    35,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   225,     5,   -47,   -47,   204,   221,   -47,   -47,
     -47,   -47,   205,   -47,   175,   -46,   -47,   -47,   -47,   -37,
     119,     0,    19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    46,    16,    22,    23,    11,    12,    35,
      13,    24,    25,    26,    47,    48,    49,    64,    67,    61,
      96,    51,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    71,     1,    14,    28,     4,    53,    54,    29,     4,
      50,     5,    14,     8,     9,    55,    10,    56,    53,    54,
      27,    57,    58,    59,    60,    99,   101,    90,    91,    56,
      50,    27,     6,    57,    58,    59,    60,   100,   102,    18,
      19,    68,     8,     9,    20,    10,    38,    21,    71,    39,
      40,    69,    41,    42,    43,    30,    75,    50,    62,    31,
      44,    70,    45,    89,    90,    91,     8,     9,    32,    10,
      38,   126,    34,    39,    40,    76,    41,    42,    43,    78,
      50,   132,    92,    37,    44,   133,    45,    52,    98,    63,
      50,     7,     8,     9,    50,    10,    72,    65,    66,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    73,   118,    79,   -39,    88,    89,    90,    91,   123,
      74,   124,   125,    80,    81,   -38,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   122,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    80,    81,    68,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   129,
      84,    85,    86,    87,    88,    89,    90,    91,    77,    80,
      81,    93,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   130,   -39,    85,    86,    87,    88,    89,    90,
      91,   103,    80,    81,   120,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   121,   -39,    86,    87,    88,
      89,    90,    91,   131,    80,    81,    91,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     8,     9,    15,
      10,    38,    33,    17,    39,    40,    36,    41,    42,    43,
     128,   104,    94,     0,     0,    44,   119,    45,    80,    81,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   117,   -39,    87,    88,    89,    90,    91,    80,    81,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   127,     8,     9,     0,    10,     0,     0,    80,    81,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    53,    54,     0,     0,     0,     0,     0,     0,    53,
      54,     0,    56,    95,     0,     0,    57,    58,    59,    60,
      56,     0,     0,     0,    57,    58,    59,    60,     0,    80,
      81,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    81,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      37,    47,     8,     3,    19,     0,     9,    10,    23,     4,
      47,    24,    12,     4,     5,    18,     7,    20,     9,    10,
      20,    24,    25,    26,    27,    18,    18,    39,    40,    20,
      67,    31,     0,    24,    25,    26,    27,    30,    30,    24,
      22,    20,     4,     5,    20,     7,     8,    24,    94,    11,
      12,    30,    14,    15,    16,    21,    56,    94,    39,    19,
      22,    23,    24,    38,    39,    40,     4,     5,    24,     7,
       8,   117,    18,    11,    12,    56,    14,    15,    16,    60,
     117,   127,    63,    22,    22,   131,    24,    24,    69,    20,
     127,     3,     4,     5,   131,     7,    24,    18,    18,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    18,    93,    18,    36,    37,    38,    39,    40,   100,
      24,   102,   103,    28,    29,    24,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    18,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    28,    29,    20,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    18,
      33,    34,    35,    36,    37,    38,    39,    40,     6,    28,
      29,    20,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    18,    33,    34,    35,    36,    37,    38,    39,
      40,    21,    28,    29,    21,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    34,    35,    36,    37,
      38,    39,    40,    13,    28,    29,    40,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     4,     5,     4,
       7,     8,    28,    12,    11,    12,    31,    14,    15,    16,
     121,    21,    67,    -1,    -1,    22,    23,    24,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    21,    35,    36,    37,    38,    39,    40,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    21,     4,     5,    -1,     7,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    -1,    20,    21,    -1,    -1,    24,    25,    26,    27,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    43,    44,    45,    24,     0,     3,     4,     5,
       7,    49,    50,    52,    63,    44,    46,    49,    24,    22,
      20,    24,    47,    48,    53,    54,    55,    63,    19,    23,
      21,    19,    24,    48,    18,    51,    54,    22,     8,    11,
      12,    14,    15,    16,    22,    24,    45,    56,    57,    58,
      61,    63,    24,     9,    10,    18,    20,    24,    25,    26,
      27,    61,    64,    20,    59,    18,    18,    60,    20,    30,
      23,    57,    24,    18,    24,    63,    64,     6,    64,    18,
      28,    29,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    64,    20,    56,    21,    62,    64,    64,    18,
      30,    18,    30,    21,    21,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    21,    64,    23,
      21,    19,    18,    64,    64,    64,    57,    21,    62,    18,
      18,    13,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    46,    45,    47,    47,    48,
      49,    49,    51,    50,    52,    52,    53,    53,    54,    54,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    59,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     7,     1,     3,     1,
       0,     2,     0,     9,     1,     1,     0,     1,     1,     3,
       2,     1,     2,     4,     3,     3,     1,     5,     5,     4,
       2,     2,     3,     5,     7,     6,     2,     2,     2,     0,
       0,     4,     3,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 46 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                          if (!symbolTable.hasMain) {
                              output::errorMainMissing();
                              exit(0);
                          }
                      }
#line 1510 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 5:
#line 58 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                       if (symbolTable.isAlreadyDefined(((IdNode*)yyvsp[0])->name)) {
                           output::errorDef(yyvsp[0]->lineno, ((IdNode*)yyvsp[0])->name);
                           exit(0);
                       }
                   }
#line 1521 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 6:
#line 63 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                            yyval = new EnumDeclNode(((IdNode*)yyvsp[-5])->name, yyvsp[-5]->lineno);
                            exitOnFalse(symbolTable.addEnum((IdNode*)yyvsp[-5], ((EnumeratorListNode*)yyvsp[-3])->enums));
                       }
#line 1530 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 7:
#line 69 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                            yyval = new EnumeratorListNode(((EnumeratorNode*)yyvsp[0])->name, yyvsp[0]->lineno);
                        }
#line 1538 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 8:
#line 72 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                                    yyval = yyvsp[0];
                                    ((EnumeratorListNode*)yyval)->add(((EnumeratorNode*)yyvsp[-2])->name, yyvsp[-2]->lineno);
                                }
#line 1547 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 9:
#line 78 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                    yyval = new EnumeratorNode(((IdNode*)yyvsp[0])->name, yyvsp[0]->lineno);
                }
#line 1555 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 11:
#line 84 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                        yyval = yyvsp[0];
                     }
#line 1563 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 12:
#line 89 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                if (symbolTable.isAlreadyDefined(((IdNode*)yyvsp[-3])->name)) {
                    output::errorDef(yyvsp[-3]->lineno, ((IdNode*)yyvsp[-3])->name);
                    exit(0);
                }
                exitOnFalse(symbolTable.addFunction((IdNode*)yyvsp[-3], ((TypeNode*)yyvsp[-4])->type, ((FormalsNode*)yyvsp[-1])->types, ((FormalsNode*)yyvsp[-1])->names));
                yyval = new StatementNode();
            }
#line 1576 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 13:
#line 96 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { symbolTable.endScope(); }
#line 1582 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 14:
#line 99 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1588 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 15:
#line 100 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1594 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 16:
#line 103 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
            yyval = new FormalsNode();
        }
#line 1602 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 17:
#line 107 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
            yyval = new FormalsNode(((FormalsListNode*)yyvsp[0])->types, ((FormalsListNode*)yyvsp[0])->names, yyvsp[0]->lineno);
        }
#line 1610 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 18:
#line 112 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                yyval = new FormalsListNode(((FormalDeclNode*)yyvsp[0])->type, ((FormalDeclNode*)yyvsp[0])->name, yyvsp[0]->lineno);
            }
#line 1618 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 19:
#line 116 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                yyval = yyvsp[0];
                ((FormalsListNode*)yyval)->add(((FormalDeclNode*)yyvsp[-2])->type, ((FormalDeclNode*)yyvsp[-2])->name, yyvsp[-2]->lineno);
            }
#line 1627 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 20:
#line 123 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                if (symbolTable.isAlreadyDefined(((IdNode*)yyvsp[0])->name)) {
                    output::errorDef(yyvsp[0]->lineno, ((IdNode*)yyvsp[0])->name);
                    exit(0);
                }
                exitOnFalse(symbolTable.addVar((IdNode*)yyvsp[0], ((TypeNode*)yyvsp[-1])->type));
                yyval = new FormalDeclNode(((TypeNode*)yyvsp[-1])->type, ((IdNode*)yyvsp[0])->name, yyvsp[0]->lineno);
            }
#line 1640 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 21:
#line 133 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1646 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 22:
#line 134 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1652 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 23:
#line 137 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1658 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 24:
#line 138 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1664 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 25:
#line 139 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1670 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 26:
#line 140 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1676 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 27:
#line 141 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1682 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 28:
#line 142 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1688 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 29:
#line 143 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1694 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 30:
#line 144 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1700 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 31:
#line 145 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1706 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 32:
#line 146 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1712 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 33:
#line 147 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1718 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 34:
#line 148 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1724 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 35:
#line 149 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1730 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 36:
#line 150 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1736 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 37:
#line 151 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1742 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 38:
#line 154 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                        if (!symbolTable.isEnumDefined(((IdNode*)yyvsp[0])->name)) {
                            output::errorUndefEnum(yyvsp[0]->lineno, ((IdNode*)yyvsp[0])->name);
                            exit(0);
                        }

                   }
#line 1754 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 39:
#line 163 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                            symbolTable.newInnerScope(true /*isWhileScope*/);
                        }
#line 1762 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 40:
#line 169 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                        symbolTable.newInnerScope();
                    }
#line 1770 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 41:
#line 175 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                            if (!symbolTable.isDefinedFunction(((IdNode*)yyvsp[-3])->name)) {
                                output::errorUndefFunc(yyvsp[-3]->lineno, ((IdNode*)yyvsp[-3])->name);
                                exit(0);
                            }

                            vector<Types> args = symbolTable.getFunctionArgs(((IdNode*)yyvsp[-3])->name);
                            if (!((ExpListNode*)yyvsp[-1])->compareType(args)) {
                                vector<string> argTypes = typeToStringVector(args);
                                output::errorPrototypeMismatch(yyvsp[-3]->lineno, ((IdNode*)yyvsp[-3])->name, argTypes);
                                exit(0);
                            } 
                        
                            yyval = new CallNode(symbolTable.getType(((IdNode*)yyvsp[-3])->name), yyvsp[-3]->lineno);
                        }
#line 1790 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 42:
#line 191 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {
                            if (!symbolTable.isDefinedFunction(((IdNode*)yyvsp[-2])->name)) {
                                output::errorUndefFunc(yyvsp[-2]->lineno, ((IdNode*)yyvsp[-2])->name);
                                exit(0);
                            }

                            vector<Types> args = symbolTable.getFunctionArgs(((IdNode*)yyvsp[-2])->name);
                            if (args.size() != 0) {
                                vector<string> argTypes = typeToStringVector(args);
                                output::errorPrototypeMismatch(yyvsp[-2]->lineno, ((IdNode*)yyvsp[-2])->name, argTypes);
                                exit(0);
                            } 
                        
                            yyval = new CallNode(symbolTable.getType(((IdNode*)yyvsp[-2])->name), yyvsp[-2]->lineno);
                        }
#line 1810 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 43:
#line 208 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1816 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 44:
#line 209 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1822 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 45:
#line 213 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1828 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 46:
#line 215 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1834 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 47:
#line 217 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    { yyval = yyvsp[0]; }
#line 1840 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 48:
#line 220 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1846 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 49:
#line 221 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1852 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 50:
#line 222 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1858 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 51:
#line 223 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1864 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 52:
#line 224 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1870 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 53:
#line 225 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1876 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 54:
#line 226 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1882 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 55:
#line 227 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1888 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 56:
#line 228 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1894 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 57:
#line 229 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {   }
#line 1900 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 58:
#line 230 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {   }
#line 1906 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 59:
#line 231 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1912 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 60:
#line 232 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1918 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 61:
#line 233 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1924 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 62:
#line 234 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1930 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 63:
#line 235 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1936 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 64:
#line 236 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1942 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 65:
#line 237 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1948 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 66:
#line 238 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1954 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 67:
#line 239 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1960 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 68:
#line 240 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1966 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;

  case 69:
#line 241 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"
    {  }
#line 1972 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"
    break;


#line 1976 "/home/guy-pc/CLionProjects/HW3.1/cmake-build-debug/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 243 "/home/guy-pc/CLionProjects/HW3.1/parser.ypp"


int main()
{
    yyparse();
    symbolTable.endScope();
    return 0;
}

void exitOnFalse(bool b) {
    if (!b) {
        exit(0);
    }
}