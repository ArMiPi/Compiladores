/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int yylex();
extern char* yytext;
extern int line;
extern int column;
extern char* current_line;
void yyerror(char *s);


#line 84 "sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_HASHTAG = 3,                    /* HASHTAG  */
  YYSYMBOL_DEFINE = 4,                     /* DEFINE  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_TIMES = 6,                      /* TIMES  */
  YYSYMBOL_L_CURLY_BRACKET = 7,            /* L_CURLY_BRACKET  */
  YYSYMBOL_R_CURLY_BRACKET = 8,            /* R_CURLY_BRACKET  */
  YYSYMBOL_L_SQUARE_BRACKET = 9,           /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 10,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_L_PAREN = 14,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 15,                   /* R_PAREN  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_CHAR = 17,                      /* CHAR  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_PRINTF = 24,                    /* PRINTF  */
  YYSYMBOL_STRING = 25,                    /* STRING  */
  YYSYMBOL_SCANF = 26,                     /* SCANF  */
  YYSYMBOL_AMPERSAND = 27,                 /* AMPERSAND  */
  YYSYMBOL_EXIT = 28,                      /* EXIT  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_PLUS_ASSIGN = 30,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 31,              /* MINUS_ASSIGN  */
  YYSYMBOL_QUESTION = 32,                  /* QUESTION  */
  YYSYMBOL_COLON = 33,                     /* COLON  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_BITWISE_OR = 36,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 37,               /* BITWISE_XOR  */
  YYSYMBOL_EQUAL = 38,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 39,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 40,                 /* LESS_THAN  */
  YYSYMBOL_LESS_EQUAL = 41,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_THAN = 42,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 43,             /* GREATER_EQUAL  */
  YYSYMBOL_L_SHIFT = 44,                   /* L_SHIFT  */
  YYSYMBOL_R_SHIFT = 45,                   /* R_SHIFT  */
  YYSYMBOL_MINUS = 46,                     /* MINUS  */
  YYSYMBOL_PLUS = 47,                      /* PLUS  */
  YYSYMBOL_DIV = 48,                       /* DIV  */
  YYSYMBOL_MOD = 49,                       /* MOD  */
  YYSYMBOL_INC = 50,                       /* INC  */
  YYSYMBOL_DEC = 51,                       /* DEC  */
  YYSYMBOL_BITWISE_COMP = 52,              /* BITWISE_COMP  */
  YYSYMBOL_NOT = 53,                       /* NOT  */
  YYSYMBOL_CHARACTER = 54,                 /* CHARACTER  */
  YYSYMBOL_NUM_INTEGER = 55,               /* NUM_INTEGER  */
  YYSYMBOL_NUM_HEXA = 56,                  /* NUM_HEXA  */
  YYSYMBOL_NUM_OCTAL = 57,                 /* NUM_OCTAL  */
  YYSYMBOL_OTHER = 58,                     /* OTHER  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_Programa = 60,                  /* Programa  */
  YYSYMBOL_DecOuFunc = 61,                 /* DecOuFunc  */
  YYSYMBOL_DecOuFuncPrime = 62,            /* DecOuFuncPrime  */
  YYSYMBOL_Declaracoes = 63,               /* Declaracoes  */
  YYSYMBOL_Funcao = 64,                    /* Funcao  */
  YYSYMBOL_VezesLoop = 65,                 /* VezesLoop  */
  YYSYMBOL_FuncaoLoop = 66,                /* FuncaoLoop  */
  YYSYMBOL_DeclaracaoVars = 67,            /* DeclaracaoVars  */
  YYSYMBOL_DeclaracaoVarsLoop = 68,        /* DeclaracaoVarsLoop  */
  YYSYMBOL_ColcheteExpressaoLoop = 69,     /* ColcheteExpressaoLoop  */
  YYSYMBOL_DeclaracaoVarsAtribuicao = 70,  /* DeclaracaoVarsAtribuicao  */
  YYSYMBOL_DeclaracaoVarsLoopPrime = 71,   /* DeclaracaoVarsLoopPrime  */
  YYSYMBOL_DeclaracaoProt = 72,            /* DeclaracaoProt  */
  YYSYMBOL_Parametros = 73,                /* Parametros  */
  YYSYMBOL_ParametrosOpLoop = 74,          /* ParametrosOpLoop  */
  YYSYMBOL_ParametrosLoop = 75,            /* ParametrosLoop  */
  YYSYMBOL_ParametrosLoopPrime = 76,       /* ParametrosLoopPrime  */
  YYSYMBOL_Tipo = 77,                      /* Tipo  */
  YYSYMBOL_Bloco = 78,                     /* Bloco  */
  YYSYMBOL_Comandos = 79,                  /* Comandos  */
  YYSYMBOL_ComandosPrime = 80,             /* ComandosPrime  */
  YYSYMBOL_ListaComandos = 81,             /* ListaComandos  */
  YYSYMBOL_OpElse = 82,                    /* OpElse  */
  YYSYMBOL_OpExpressao = 83,               /* OpExpressao  */
  YYSYMBOL_OpVirgulaExpressao = 84,        /* OpVirgulaExpressao  */
  YYSYMBOL_Expressao = 85,                 /* Expressao  */
  YYSYMBOL_ExpressaoPrime = 86,            /* ExpressaoPrime  */
  YYSYMBOL_ExpressaoAtribuicao = 87,       /* ExpressaoAtribuicao  */
  YYSYMBOL_AtribuicaoOperador = 88,        /* AtribuicaoOperador  */
  YYSYMBOL_ExpressaoCondicional = 89,      /* ExpressaoCondicional  */
  YYSYMBOL_ExpressaoCondicionalPrime = 90, /* ExpressaoCondicionalPrime  */
  YYSYMBOL_ExpressaoOrLogico = 91,         /* ExpressaoOrLogico  */
  YYSYMBOL_ExpressaoOrLogicoPrime = 92,    /* ExpressaoOrLogicoPrime  */
  YYSYMBOL_ExpressaoAndLogico = 93,        /* ExpressaoAndLogico  */
  YYSYMBOL_ExpressaoAndLogicoPrime = 94,   /* ExpressaoAndLogicoPrime  */
  YYSYMBOL_ExpressaoOr = 95,               /* ExpressaoOr  */
  YYSYMBOL_ExpressaoOrPrime = 96,          /* ExpressaoOrPrime  */
  YYSYMBOL_ExpressaoXor = 97,              /* ExpressaoXor  */
  YYSYMBOL_ExpressaoXorPrime = 98,         /* ExpressaoXorPrime  */
  YYSYMBOL_ExpressaoAnd = 99,              /* ExpressaoAnd  */
  YYSYMBOL_ExpressaoAndPrime = 100,        /* ExpressaoAndPrime  */
  YYSYMBOL_ExpressaoIgualdade = 101,       /* ExpressaoIgualdade  */
  YYSYMBOL_ExpressaoIgualdadePrime = 102,  /* ExpressaoIgualdadePrime  */
  YYSYMBOL_IgualdadeOperador = 103,        /* IgualdadeOperador  */
  YYSYMBOL_ExpressaoRelacional = 104,      /* ExpressaoRelacional  */
  YYSYMBOL_ExpressaoRelacionalPrime = 105, /* ExpressaoRelacionalPrime  */
  YYSYMBOL_RelacionalOperador = 106,       /* RelacionalOperador  */
  YYSYMBOL_ExpressaoShift = 107,           /* ExpressaoShift  */
  YYSYMBOL_ExpressaoShiftPrime = 108,      /* ExpressaoShiftPrime  */
  YYSYMBOL_ShiftOperador = 109,            /* ShiftOperador  */
  YYSYMBOL_ExpressaoAditiva = 110,         /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoAditivaPrime = 111,    /* ExpressaoAditivaPrime  */
  YYSYMBOL_AdicaoOperador = 112,           /* AdicaoOperador  */
  YYSYMBOL_ExpressaoMultiplicativa = 113,  /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoMultiplicativaPrime = 114, /* ExpressaoMultiplicativaPrime  */
  YYSYMBOL_MultOperador = 115,             /* MultOperador  */
  YYSYMBOL_ExpressaoCast = 116,            /* ExpressaoCast  */
  YYSYMBOL_ExpressaoUnaria = 117,          /* ExpressaoUnaria  */
  YYSYMBOL_UnarioOperador = 118,           /* UnarioOperador  */
  YYSYMBOL_ExpressaoPosFixa = 119,         /* ExpressaoPosFixa  */
  YYSYMBOL_ExpressaoPosFixaPrime = 120,    /* ExpressaoPosFixaPrime  */
  YYSYMBOL_OpExpressaoAtribuicaoLoop = 121, /* OpExpressaoAtribuicaoLoop  */
  YYSYMBOL_ExpressaoAtribuicaoLoop = 122,  /* ExpressaoAtribuicaoLoop  */
  YYSYMBOL_ExpressaoAtribuicaoLoopPrime = 123, /* ExpressaoAtribuicaoLoopPrime  */
  YYSYMBOL_ExpressaoPrimaria = 124,        /* ExpressaoPrimaria  */
  YYSYMBOL_Numero = 125                    /* Numero  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    79,    80,    83,    84,    88,    89,    90,
      93,    96,    97,   100,   101,   104,   107,   110,   111,   114,
     115,   118,   119,   122,   125,   128,   129,   132,   135,   136,
     139,   140,   141,   144,   147,   150,   151,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   167,   168,
     171,   172,   175,   176,   179,   182,   183,   186,   187,   190,
     191,   192,   195,   198,   199,   202,   204,   205,   208,   211,
     212,   215,   218,   219,   222,   225,   226,   229,   232,   233,
     238,   240,   241,   243,   244,   248,   250,   251,   253,   254,
     255,   256,   260,   262,   263,   265,   266,   270,   272,   273,
     275,   276,   280,   282,   283,   285,   286,   287,   291,   292,
     295,   296,   297,   298,   301,   302,   303,   304,   305,   306,
     309,   310,   313,   314,   315,   316,   319,   320,   323,   326,
     327,   330,   331,   332,   333,   334,   337,   338,   339
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "HASHTAG", "DEFINE",
  "IDENTIFIER", "TIMES", "L_CURLY_BRACKET", "R_CURLY_BRACKET",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "SEMICOLON", "COMMA",
  "L_PAREN", "R_PAREN", "INT", "CHAR", "VOID", "DO", "WHILE", "IF", "ELSE",
  "FOR", "PRINTF", "STRING", "SCANF", "AMPERSAND", "EXIT", "RETURN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "QUESTION", "COLON", "OR", "AND",
  "BITWISE_OR", "BITWISE_XOR", "EQUAL", "NOT_EQUAL", "LESS_THAN",
  "LESS_EQUAL", "GREATER_THAN", "GREATER_EQUAL", "L_SHIFT", "R_SHIFT",
  "MINUS", "PLUS", "DIV", "MOD", "INC", "DEC", "BITWISE_COMP", "NOT",
  "CHARACTER", "NUM_INTEGER", "NUM_HEXA", "NUM_OCTAL", "OTHER", "$accept",
  "Programa", "DecOuFunc", "DecOuFuncPrime", "Declaracoes", "Funcao",
  "VezesLoop", "FuncaoLoop", "DeclaracaoVars", "DeclaracaoVarsLoop",
  "ColcheteExpressaoLoop", "DeclaracaoVarsAtribuicao",
  "DeclaracaoVarsLoopPrime", "DeclaracaoProt", "Parametros",
  "ParametrosOpLoop", "ParametrosLoop", "ParametrosLoopPrime", "Tipo",
  "Bloco", "Comandos", "ComandosPrime", "ListaComandos", "OpElse",
  "OpExpressao", "OpVirgulaExpressao", "Expressao", "ExpressaoPrime",
  "ExpressaoAtribuicao", "AtribuicaoOperador", "ExpressaoCondicional",
  "ExpressaoCondicionalPrime", "ExpressaoOrLogico",
  "ExpressaoOrLogicoPrime", "ExpressaoAndLogico",
  "ExpressaoAndLogicoPrime", "ExpressaoOr", "ExpressaoOrPrime",
  "ExpressaoXor", "ExpressaoXorPrime", "ExpressaoAnd", "ExpressaoAndPrime",
  "ExpressaoIgualdade", "ExpressaoIgualdadePrime", "IgualdadeOperador",
  "ExpressaoRelacional", "ExpressaoRelacionalPrime", "RelacionalOperador",
  "ExpressaoShift", "ExpressaoShiftPrime", "ShiftOperador",
  "ExpressaoAditiva", "ExpressaoAditivaPrime", "AdicaoOperador",
  "ExpressaoMultiplicativa", "ExpressaoMultiplicativaPrime",
  "MultOperador", "ExpressaoCast", "ExpressaoUnaria", "UnarioOperador",
  "ExpressaoPosFixa", "ExpressaoPosFixaPrime", "OpExpressaoAtribuicaoLoop",
  "ExpressaoAtribuicaoLoop", "ExpressaoAtribuicaoLoopPrime",
  "ExpressaoPrimaria", "Numero", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    14,  -172,  -172,  -172,    24,    20,  -172,  -172,  -172,
    -172,    46,    56,  -172,    20,  -172,    46,    66,    61,   185,
    -172,  -172,     6,  -172,  -172,  -172,   169,  -172,  -172,  -172,
    -172,   238,   238,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
      62,  -172,    47,    48,    45,    50,    51,    57,   -10,     1,
      25,    31,    -2,     0,   185,    13,  -172,  -172,   185,    49,
      74,     9,    46,    72,   185,  -172,  -172,   185,  -172,   185,
    -172,   185,  -172,   185,  -172,   185,  -172,   185,  -172,   185,
    -172,  -172,  -172,  -172,   185,  -172,  -172,  -172,  -172,  -172,
     185,  -172,  -172,  -172,   185,  -172,  -172,  -172,   185,  -172,
    -172,  -172,  -172,   185,  -172,  -172,  -172,   185,  -172,  -172,
     185,   185,  -172,  -172,  -172,    79,    75,  -172,    46,   185,
      84,    49,  -172,    77,  -172,  -172,    65,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,    91,    90,
      89,  -172,    96,  -172,   101,  -172,    46,  -172,    88,    49,
      46,   185,   185,  -172,   185,  -172,  -172,  -172,    96,   113,
    -172,    88,  -172,   112,   106,   107,   108,   109,   111,   114,
     185,  -172,   118,    88,   115,  -172,  -172,  -172,  -172,   119,
      96,   123,   116,   185,   185,   185,   121,   122,   185,   125,
    -172,  -172,  -172,    88,  -172,    49,  -172,  -172,   134,   135,
     137,   141,   120,   136,   139,  -172,  -172,  -172,   185,   112,
     112,   185,   185,   140,   129,   145,   143,  -172,   138,   147,
    -172,   149,   157,  -172,   151,   112,  -172,   185,  -172,   152,
    -172,  -172,   153,   159,   112,  -172,  -172
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    30,    31,    32,     0,     6,     3,     4,     8,
       9,    12,     0,     1,     6,     2,    12,     0,     0,     0,
       5,    11,    18,    15,   131,   115,     0,   134,   114,   117,
     116,     0,     0,   118,   119,   133,   136,   137,   138,     7,
      56,    57,    64,    67,    70,    73,    76,    79,    82,    87,
      94,    99,   104,   108,     0,   110,   120,   132,     0,    26,
      20,     0,    12,     0,     0,   111,   112,     0,    54,     0,
      62,     0,    65,     0,    68,     0,    71,     0,    74,     0,
      77,    83,    84,    80,     0,    88,    89,    90,    91,    85,
       0,    95,    96,    92,     0,   100,   101,    97,     0,   105,
     106,   107,   102,     0,    59,    60,    61,     0,   113,   108,
       0,   127,   123,   124,   121,     0,     0,    25,    12,     0,
      22,    14,    23,     0,   135,    55,     0,    66,    69,    72,
      75,    78,    81,    86,    93,    98,   103,    58,     0,   130,
       0,   126,    18,    24,     0,    19,    12,    16,     0,    14,
      12,     0,     0,   122,     0,   128,   125,    17,    18,     0,
      21,     0,    46,     0,     0,     0,     0,     0,     0,     0,
      51,    47,     0,    36,     0,    13,   109,    63,   129,    29,
      18,     0,     0,     0,     0,    51,     0,     0,     0,     0,
      50,    10,    34,    36,    45,     0,    27,    33,     0,     0,
       0,     0,    53,     0,     0,    44,    35,    28,     0,     0,
       0,    51,     0,     0,     0,     0,     0,    39,    49,     0,
      52,     0,     0,    43,     0,     0,    38,    51,    41,     0,
      37,    48,     0,     0,     0,    42,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,   172,   162,  -172,  -172,    -8,    28,  -116,    27,
    -123,  -172,  -172,  -172,  -172,  -172,   -17,  -172,   -25,  -151,
      18,   -13,  -167,  -172,  -171,  -172,   -19,  -172,   -94,  -172,
      29,  -172,   117,  -172,   124,  -172,   126,  -172,   105,  -172,
     127,  -172,   100,  -172,  -172,   110,  -172,  -172,   104,  -172,
    -172,    97,  -172,  -172,    99,  -172,  -172,   -52,   -22,  -172,
    -172,  -172,  -172,    53,  -172,  -172,  -172
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,    14,    15,     7,     8,   159,   148,     9,    18,
      60,   120,   147,    10,    61,   116,   117,   196,    11,   171,
     172,   192,   173,   226,   189,   213,   174,    68,    40,   107,
      41,    70,    42,    72,    43,    74,    44,    76,    45,    78,
      46,    80,    47,    83,    84,    48,    89,    90,    49,    93,
      94,    50,    97,    98,    51,   102,   103,    52,    53,    54,
      55,   114,   140,   141,   155,    56,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    62,   108,    17,    99,   149,   193,    63,    21,    65,
      66,   104,   182,   137,   201,    58,   121,   139,    12,   157,
      59,   122,   110,     1,    13,   145,   193,   111,    81,    82,
     105,   106,   109,   149,   118,   179,     2,     3,     4,   115,
     219,    85,    86,    87,    88,    63,   100,   101,   125,   109,
     126,   109,    16,   109,   123,   109,   232,   109,   217,   218,
     139,    19,   109,   112,   113,     2,     3,     4,   109,    91,
      92,    22,   109,    23,   231,    67,   109,    95,    96,    69,
      73,   109,    71,   236,    79,   119,    75,   124,    77,   142,
     143,   138,   151,    24,    25,   161,   150,   146,   152,   176,
     162,   153,    26,   154,   156,    58,   158,   163,   164,   165,
     144,   166,   167,    27,   168,    28,   169,   170,   180,   161,
     183,   184,   185,   186,   150,   187,   191,   194,   188,   109,
     109,   197,   195,   212,    29,    30,   198,   205,    31,    32,
      33,    34,    35,    36,    37,    38,   202,   203,   208,   214,
     209,   190,   210,   211,   215,   221,   222,   223,   224,   227,
     225,   228,   229,   230,   199,   200,   190,   233,   234,   204,
     118,   235,     6,   160,    24,    25,    20,   175,   207,   181,
     206,   177,   130,    26,   132,     2,     3,     4,   127,   216,
      24,    25,   190,   220,    27,   135,    28,   128,   134,    26,
     133,   129,   136,     0,     0,     0,   131,   178,   190,     0,
      27,     0,    28,     0,     0,    29,    30,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,    29,    30,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    24,    25,     0,     0,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      19,    26,    54,    11,     6,   121,   173,    26,    16,    31,
      32,    11,   163,   107,   185,     9,     7,   111,     4,   142,
      14,    12,     9,     3,     0,   119,   193,    14,    38,    39,
      30,    31,    54,   149,    59,   158,    16,    17,    18,    58,
     211,    40,    41,    42,    43,    64,    48,    49,    67,    71,
      69,    73,     6,    75,    62,    77,   227,    79,   209,   210,
     154,     5,    84,    50,    51,    16,    17,    18,    90,    44,
      45,     5,    94,    12,   225,    13,    98,    46,    47,    32,
      35,   103,    34,   234,    27,    11,    36,    15,    37,    10,
      15,   110,    15,     5,     6,     7,   121,    13,    33,   151,
      12,    10,    14,    13,    15,     9,     5,    19,    20,    21,
     118,    23,    24,    25,    26,    27,    28,    29,     5,     7,
      14,    14,    14,    14,   149,    14,     8,    12,    14,   151,
     152,     8,    13,    13,    46,    47,    20,    12,    50,    51,
      52,    53,    54,    55,    56,    57,    25,    25,    14,    13,
      15,   170,    15,    12,    15,    15,    27,    12,    15,    12,
      22,    12,     5,    12,   183,   184,   185,    15,    15,   188,
     195,    12,     0,   146,     5,     6,    14,   149,   195,   161,
     193,   152,    77,    14,    84,    16,    17,    18,    71,   208,
       5,     6,   211,   212,    25,    98,    27,    73,    94,    14,
      90,    75,   103,    -1,    -1,    -1,    79,   154,   227,    -1,
      25,    -1,    27,    -1,    -1,    46,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    16,    17,    18,    60,    61,    63,    64,    67,
      72,    77,     4,     0,    61,    62,     6,    65,    68,     5,
      62,    65,     5,    12,     5,     6,    14,    25,    27,    46,
      47,    50,    51,    52,    53,    54,    55,    56,    57,    85,
      87,    89,    91,    93,    95,    97,    99,   101,   104,   107,
     110,   113,   116,   117,   118,   119,   124,   125,     9,    14,
      69,    73,    77,    85,    14,   117,   117,    13,    86,    32,
      90,    34,    92,    35,    94,    36,    96,    37,    98,    27,
     100,    38,    39,   102,   103,    40,    41,    42,    43,   105,
     106,    44,    45,   108,   109,    46,    47,   111,   112,     6,
      48,    49,   114,   115,    11,    30,    31,    88,   116,   117,
       9,    14,    50,    51,   120,    85,    74,    75,    77,    11,
      70,     7,    12,    65,    15,    85,    85,    91,    93,    95,
      97,    99,   101,   104,   107,   110,   113,    87,    85,    87,
     121,   122,    10,    15,    65,    87,    13,    71,    66,    67,
      77,    15,    33,    10,    13,   123,    15,    69,     5,    65,
      68,     7,    12,    19,    20,    21,    23,    24,    26,    28,
      29,    78,    79,    81,    85,    66,   116,    89,   122,    69,
       5,    79,    78,    14,    14,    14,    14,    14,    14,    83,
      85,     8,    80,    81,    12,    13,    76,     8,    20,    85,
      85,    83,    25,    25,    85,    12,    80,    75,    14,    15,
      15,    12,    13,    84,    13,    15,    85,    78,    78,    83,
      85,    15,    27,    12,    15,    22,    82,    12,    12,     5,
      12,    78,    83,    15,    15,    12,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    71,    71,    72,    73,    74,    74,    75,    76,    76,
      77,    77,    77,    78,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    90,    90,    91,    92,    92,    93,    94,
      94,    95,    96,    96,    97,    98,    98,    99,   100,   100,
     101,   102,   102,   103,   103,   104,   105,   105,   106,   106,
     106,   106,   107,   108,   108,   109,   109,   110,   111,   111,
     112,   112,   113,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   117,   117,   118,   118,   118,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   121,   121,   122,   123,
     123,   124,   124,   124,   124,   124,   125,   125,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     0,     4,     1,     1,
       8,     2,     0,     2,     0,     3,     5,     4,     0,     2,
       0,     2,     0,     5,     3,     1,     0,     5,     2,     0,
       1,     1,     1,     3,     2,     2,     0,     7,     6,     5,
       9,     6,     8,     5,     3,     2,     1,     1,     2,     0,
       1,     0,     2,     0,     2,     2,     0,     1,     3,     1,
       1,     1,     2,     4,     0,     2,     2,     0,     2,     2,
       0,     2,     2,     0,     2,     2,     0,     2,     2,     0,
       2,     2,     0,     1,     1,     2,     2,     0,     1,     1,
       1,     1,     2,     2,     0,     1,     1,     2,     2,     0,
       1,     1,     2,     2,     0,     1,     1,     1,     1,     5,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     1,     3,     1,     0,     2,     2,
       0,     1,     1,     1,     1,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Programa: DecOuFunc DecOuFuncPrime  */
#line 76 "sintatico.y"
                                   {}
#line 1395 "sintatico.tab.c"
    break;

  case 3: /* DecOuFunc: Declaracoes  */
#line 79 "sintatico.y"
                       {}
#line 1401 "sintatico.tab.c"
    break;

  case 4: /* DecOuFunc: Funcao  */
#line 80 "sintatico.y"
                                   {}
#line 1407 "sintatico.tab.c"
    break;

  case 5: /* DecOuFuncPrime: DecOuFunc DecOuFuncPrime  */
#line 83 "sintatico.y"
                                         {}
#line 1413 "sintatico.tab.c"
    break;

  case 6: /* DecOuFuncPrime: %empty  */
#line 84 "sintatico.y"
                    {}
#line 1419 "sintatico.tab.c"
    break;

  case 7: /* Declaracoes: HASHTAG DEFINE IDENTIFIER Expressao  */
#line 88 "sintatico.y"
                                                 {}
#line 1425 "sintatico.tab.c"
    break;

  case 8: /* Declaracoes: DeclaracaoVars  */
#line 89 "sintatico.y"
                                    {}
#line 1431 "sintatico.tab.c"
    break;

  case 9: /* Declaracoes: DeclaracaoProt  */
#line 90 "sintatico.y"
                            {}
#line 1437 "sintatico.tab.c"
    break;

  case 10: /* Funcao: Tipo VezesLoop IDENTIFIER Parametros L_CURLY_BRACKET FuncaoLoop Comandos R_CURLY_BRACKET  */
#line 93 "sintatico.y"
                                                                                                 {}
#line 1443 "sintatico.tab.c"
    break;

  case 11: /* VezesLoop: TIMES VezesLoop  */
#line 96 "sintatico.y"
                           {}
#line 1449 "sintatico.tab.c"
    break;

  case 12: /* VezesLoop: %empty  */
#line 97 "sintatico.y"
                   {}
#line 1455 "sintatico.tab.c"
    break;

  case 13: /* FuncaoLoop: DeclaracaoVars FuncaoLoop  */
#line 100 "sintatico.y"
                                      {}
#line 1461 "sintatico.tab.c"
    break;

  case 14: /* FuncaoLoop: %empty  */
#line 101 "sintatico.y"
                    {}
#line 1467 "sintatico.tab.c"
    break;

  case 15: /* DeclaracaoVars: Tipo DeclaracaoVarsLoop SEMICOLON  */
#line 104 "sintatico.y"
                                                  {}
#line 1473 "sintatico.tab.c"
    break;

  case 16: /* DeclaracaoVarsLoop: VezesLoop IDENTIFIER ColcheteExpressaoLoop DeclaracaoVarsAtribuicao DeclaracaoVarsLoopPrime  */
#line 107 "sintatico.y"
                                                                                                                {}
#line 1479 "sintatico.tab.c"
    break;

  case 17: /* ColcheteExpressaoLoop: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ColcheteExpressaoLoop  */
#line 110 "sintatico.y"
                                                                                         {}
#line 1485 "sintatico.tab.c"
    break;

  case 18: /* ColcheteExpressaoLoop: %empty  */
#line 111 "sintatico.y"
                                           {}
#line 1491 "sintatico.tab.c"
    break;

  case 19: /* DeclaracaoVarsAtribuicao: ASSIGN ExpressaoAtribuicao  */
#line 114 "sintatico.y"
                                                     {}
#line 1497 "sintatico.tab.c"
    break;

  case 20: /* DeclaracaoVarsAtribuicao: %empty  */
#line 115 "sintatico.y"
                                                  {}
#line 1503 "sintatico.tab.c"
    break;

  case 21: /* DeclaracaoVarsLoopPrime: COMMA DeclaracaoVarsLoop  */
#line 118 "sintatico.y"
                                                  {}
#line 1509 "sintatico.tab.c"
    break;

  case 22: /* DeclaracaoVarsLoopPrime: %empty  */
#line 119 "sintatico.y"
                                     {}
#line 1515 "sintatico.tab.c"
    break;

  case 23: /* DeclaracaoProt: Tipo VezesLoop IDENTIFIER Parametros SEMICOLON  */
#line 122 "sintatico.y"
                                                               {}
#line 1521 "sintatico.tab.c"
    break;

  case 24: /* Parametros: L_PAREN ParametrosOpLoop R_PAREN  */
#line 125 "sintatico.y"
                                             {}
#line 1527 "sintatico.tab.c"
    break;

  case 25: /* ParametrosOpLoop: ParametrosLoop  */
#line 128 "sintatico.y"
                                 {}
#line 1533 "sintatico.tab.c"
    break;

  case 26: /* ParametrosOpLoop: %empty  */
#line 129 "sintatico.y"
                              {}
#line 1539 "sintatico.tab.c"
    break;

  case 27: /* ParametrosLoop: Tipo VezesLoop IDENTIFIER ColcheteExpressaoLoop ParametrosLoopPrime  */
#line 132 "sintatico.y"
                                                                                    {}
#line 1545 "sintatico.tab.c"
    break;

  case 28: /* ParametrosLoopPrime: COMMA ParametrosLoop  */
#line 135 "sintatico.y"
                                          {}
#line 1551 "sintatico.tab.c"
    break;

  case 29: /* ParametrosLoopPrime: %empty  */
#line 136 "sintatico.y"
                             {}
#line 1557 "sintatico.tab.c"
    break;

  case 30: /* Tipo: INT  */
#line 139 "sintatico.y"
          {}
#line 1563 "sintatico.tab.c"
    break;

  case 31: /* Tipo: CHAR  */
#line 140 "sintatico.y"
               {}
#line 1569 "sintatico.tab.c"
    break;

  case 32: /* Tipo: VOID  */
#line 141 "sintatico.y"
               {}
#line 1575 "sintatico.tab.c"
    break;

  case 33: /* Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET  */
#line 144 "sintatico.y"
                                                {}
#line 1581 "sintatico.tab.c"
    break;

  case 34: /* Comandos: ListaComandos ComandosPrime  */
#line 147 "sintatico.y"
                                      {}
#line 1587 "sintatico.tab.c"
    break;

  case 35: /* ComandosPrime: ListaComandos ComandosPrime  */
#line 150 "sintatico.y"
                                           {}
#line 1593 "sintatico.tab.c"
    break;

  case 36: /* ComandosPrime: %empty  */
#line 151 "sintatico.y"
                   {}
#line 1599 "sintatico.tab.c"
    break;

  case 37: /* ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON  */
#line 154 "sintatico.y"
                                                                  {}
#line 1605 "sintatico.tab.c"
    break;

  case 38: /* ListaComandos: IF L_PAREN Expressao R_PAREN Bloco OpElse  */
#line 155 "sintatico.y"
                                                                     {}
#line 1611 "sintatico.tab.c"
    break;

  case 39: /* ListaComandos: WHILE L_PAREN Expressao R_PAREN Bloco  */
#line 156 "sintatico.y"
                                                                 {}
#line 1617 "sintatico.tab.c"
    break;

  case 40: /* ListaComandos: FOR L_PAREN OpExpressao SEMICOLON OpExpressao SEMICOLON OpExpressao R_PAREN Bloco  */
#line 157 "sintatico.y"
                                                                                                             {}
#line 1623 "sintatico.tab.c"
    break;

  case 41: /* ListaComandos: PRINTF L_PAREN STRING OpVirgulaExpressao R_PAREN SEMICOLON  */
#line 158 "sintatico.y"
                                                                                      {}
#line 1629 "sintatico.tab.c"
    break;

  case 42: /* ListaComandos: SCANF L_PAREN STRING COMMA AMPERSAND IDENTIFIER R_PAREN SEMICOLON  */
#line 159 "sintatico.y"
                                                                                             {}
#line 1635 "sintatico.tab.c"
    break;

  case 43: /* ListaComandos: EXIT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 160 "sintatico.y"
                                                                    {}
#line 1641 "sintatico.tab.c"
    break;

  case 44: /* ListaComandos: RETURN OpExpressao SEMICOLON  */
#line 161 "sintatico.y"
                                                        {}
#line 1647 "sintatico.tab.c"
    break;

  case 45: /* ListaComandos: Expressao SEMICOLON  */
#line 162 "sintatico.y"
                                               {}
#line 1653 "sintatico.tab.c"
    break;

  case 46: /* ListaComandos: SEMICOLON  */
#line 163 "sintatico.y"
                         {}
#line 1659 "sintatico.tab.c"
    break;

  case 47: /* ListaComandos: Bloco  */
#line 164 "sintatico.y"
                                 {}
#line 1665 "sintatico.tab.c"
    break;

  case 48: /* OpElse: ELSE Bloco  */
#line 167 "sintatico.y"
                   {}
#line 1671 "sintatico.tab.c"
    break;

  case 49: /* OpElse: %empty  */
#line 168 "sintatico.y"
            {}
#line 1677 "sintatico.tab.c"
    break;

  case 50: /* OpExpressao: Expressao  */
#line 171 "sintatico.y"
                       {}
#line 1683 "sintatico.tab.c"
    break;

  case 51: /* OpExpressao: %empty  */
#line 172 "sintatico.y"
                     {}
#line 1689 "sintatico.tab.c"
    break;

  case 52: /* OpVirgulaExpressao: COMMA Expressao  */
#line 175 "sintatico.y"
                                    {}
#line 1695 "sintatico.tab.c"
    break;

  case 53: /* OpVirgulaExpressao: %empty  */
#line 176 "sintatico.y"
                                    {}
#line 1701 "sintatico.tab.c"
    break;

  case 54: /* Expressao: ExpressaoAtribuicao ExpressaoPrime  */
#line 179 "sintatico.y"
                                              {}
#line 1707 "sintatico.tab.c"
    break;

  case 55: /* ExpressaoPrime: COMMA Expressao  */
#line 182 "sintatico.y"
                                {}
#line 1713 "sintatico.tab.c"
    break;

  case 56: /* ExpressaoPrime: %empty  */
#line 183 "sintatico.y"
                    {}
#line 1719 "sintatico.tab.c"
    break;

  case 57: /* ExpressaoAtribuicao: ExpressaoCondicional  */
#line 186 "sintatico.y"
                                          {}
#line 1725 "sintatico.tab.c"
    break;

  case 58: /* ExpressaoAtribuicao: ExpressaoUnaria AtribuicaoOperador ExpressaoAtribuicao  */
#line 187 "sintatico.y"
                                                                                            {}
#line 1731 "sintatico.tab.c"
    break;

  case 59: /* AtribuicaoOperador: ASSIGN  */
#line 190 "sintatico.y"
                           {}
#line 1737 "sintatico.tab.c"
    break;

  case 60: /* AtribuicaoOperador: PLUS_ASSIGN  */
#line 191 "sintatico.y"
                                            {}
#line 1743 "sintatico.tab.c"
    break;

  case 61: /* AtribuicaoOperador: MINUS_ASSIGN  */
#line 192 "sintatico.y"
                                                 {}
#line 1749 "sintatico.tab.c"
    break;

  case 62: /* ExpressaoCondicional: ExpressaoOrLogico ExpressaoCondicionalPrime  */
#line 195 "sintatico.y"
                                                                  {}
#line 1755 "sintatico.tab.c"
    break;

  case 63: /* ExpressaoCondicionalPrime: QUESTION Expressao COLON ExpressaoCondicional  */
#line 198 "sintatico.y"
                                                                         {}
#line 1761 "sintatico.tab.c"
    break;

  case 64: /* ExpressaoCondicionalPrime: %empty  */
#line 199 "sintatico.y"
                                           {}
#line 1767 "sintatico.tab.c"
    break;

  case 65: /* ExpressaoOrLogico: ExpressaoAndLogico ExpressaoOrLogicoPrime  */
#line 202 "sintatico.y"
                                                             {}
#line 1773 "sintatico.tab.c"
    break;

  case 66: /* ExpressaoOrLogicoPrime: OR ExpressaoOrLogico  */
#line 204 "sintatico.y"
                                             {}
#line 1779 "sintatico.tab.c"
    break;

  case 67: /* ExpressaoOrLogicoPrime: %empty  */
#line 205 "sintatico.y"
                                    {}
#line 1785 "sintatico.tab.c"
    break;

  case 68: /* ExpressaoAndLogico: ExpressaoOr ExpressaoAndLogicoPrime  */
#line 208 "sintatico.y"
                                                        {}
#line 1791 "sintatico.tab.c"
    break;

  case 69: /* ExpressaoAndLogicoPrime: AND ExpressaoAndLogico  */
#line 211 "sintatico.y"
                                                {}
#line 1797 "sintatico.tab.c"
    break;

  case 70: /* ExpressaoAndLogicoPrime: %empty  */
#line 212 "sintatico.y"
                                 {}
#line 1803 "sintatico.tab.c"
    break;

  case 71: /* ExpressaoOr: ExpressaoXor ExpressaoOrPrime  */
#line 215 "sintatico.y"
                                           {}
#line 1809 "sintatico.tab.c"
    break;

  case 73: /* ExpressaoOrPrime: %empty  */
#line 219 "sintatico.y"
                          {}
#line 1815 "sintatico.tab.c"
    break;

  case 74: /* ExpressaoXor: ExpressaoAnd ExpressaoXorPrime  */
#line 222 "sintatico.y"
                                             {}
#line 1821 "sintatico.tab.c"
    break;

  case 75: /* ExpressaoXorPrime: BITWISE_XOR ExpressaoXor  */
#line 225 "sintatico.y"
                                            {}
#line 1827 "sintatico.tab.c"
    break;

  case 76: /* ExpressaoXorPrime: %empty  */
#line 226 "sintatico.y"
                       {}
#line 1833 "sintatico.tab.c"
    break;

  case 77: /* ExpressaoAnd: ExpressaoIgualdade ExpressaoAndPrime  */
#line 229 "sintatico.y"
                                                   {}
#line 1839 "sintatico.tab.c"
    break;

  case 78: /* ExpressaoAndPrime: AMPERSAND ExpressaoAnd  */
#line 232 "sintatico.y"
                                          {}
#line 1845 "sintatico.tab.c"
    break;

  case 79: /* ExpressaoAndPrime: %empty  */
#line 233 "sintatico.y"
                           {}
#line 1851 "sintatico.tab.c"
    break;

  case 80: /* ExpressaoIgualdade: ExpressaoRelacional ExpressaoIgualdadePrime  */
#line 238 "sintatico.y"
                                                                {}
#line 1857 "sintatico.tab.c"
    break;

  case 81: /* ExpressaoIgualdadePrime: IgualdadeOperador ExpressaoIgualdade  */
#line 240 "sintatico.y"
                                                              {}
#line 1863 "sintatico.tab.c"
    break;

  case 82: /* ExpressaoIgualdadePrime: %empty  */
#line 241 "sintatico.y"
                                 {}
#line 1869 "sintatico.tab.c"
    break;

  case 83: /* IgualdadeOperador: EQUAL  */
#line 243 "sintatico.y"
                         {}
#line 1875 "sintatico.tab.c"
    break;

  case 84: /* IgualdadeOperador: NOT_EQUAL  */
#line 244 "sintatico.y"
                                             {}
#line 1881 "sintatico.tab.c"
    break;

  case 85: /* ExpressaoRelacional: ExpressaoShift ExpressaoRelacionalPrime  */
#line 248 "sintatico.y"
                                                             {}
#line 1887 "sintatico.tab.c"
    break;

  case 86: /* ExpressaoRelacionalPrime: RelacionalOperador ExpressaoRelacional  */
#line 250 "sintatico.y"
                                                                 {}
#line 1893 "sintatico.tab.c"
    break;

  case 87: /* ExpressaoRelacionalPrime: %empty  */
#line 251 "sintatico.y"
                                      {}
#line 1899 "sintatico.tab.c"
    break;

  case 88: /* RelacionalOperador: LESS_THAN  */
#line 253 "sintatico.y"
                              {}
#line 1905 "sintatico.tab.c"
    break;

  case 89: /* RelacionalOperador: LESS_EQUAL  */
#line 254 "sintatico.y"
                                               {}
#line 1911 "sintatico.tab.c"
    break;

  case 90: /* RelacionalOperador: GREATER_THAN  */
#line 255 "sintatico.y"
                                                 {}
#line 1917 "sintatico.tab.c"
    break;

  case 91: /* RelacionalOperador: GREATER_EQUAL  */
#line 256 "sintatico.y"
                                                  {}
#line 1923 "sintatico.tab.c"
    break;

  case 92: /* ExpressaoShift: ExpressaoAditiva ExpressaoShiftPrime  */
#line 260 "sintatico.y"
                                                     {}
#line 1929 "sintatico.tab.c"
    break;

  case 93: /* ExpressaoShiftPrime: ShiftOperador ExpressaoShift  */
#line 262 "sintatico.y"
                                                  {}
#line 1935 "sintatico.tab.c"
    break;

  case 94: /* ExpressaoShiftPrime: %empty  */
#line 263 "sintatico.y"
                             {}
#line 1941 "sintatico.tab.c"
    break;

  case 95: /* ShiftOperador: L_SHIFT  */
#line 265 "sintatico.y"
                       {}
#line 1947 "sintatico.tab.c"
    break;

  case 96: /* ShiftOperador: R_SHIFT  */
#line 266 "sintatico.y"
                                   {}
#line 1953 "sintatico.tab.c"
    break;

  case 97: /* ExpressaoAditiva: ExpressaoMultiplicativa ExpressaoAditivaPrime  */
#line 270 "sintatico.y"
                                                                {}
#line 1959 "sintatico.tab.c"
    break;

  case 98: /* ExpressaoAditivaPrime: AdicaoOperador ExpressaoAditiva  */
#line 272 "sintatico.y"
                                                       {}
#line 1965 "sintatico.tab.c"
    break;

  case 99: /* ExpressaoAditivaPrime: %empty  */
#line 273 "sintatico.y"
                                   {}
#line 1971 "sintatico.tab.c"
    break;

  case 100: /* AdicaoOperador: MINUS  */
#line 275 "sintatico.y"
                      {}
#line 1977 "sintatico.tab.c"
    break;

  case 101: /* AdicaoOperador: PLUS  */
#line 276 "sintatico.y"
                                 {}
#line 1983 "sintatico.tab.c"
    break;

  case 102: /* ExpressaoMultiplicativa: ExpressaoCast ExpressaoMultiplicativaPrime  */
#line 280 "sintatico.y"
                                                                    {}
#line 1989 "sintatico.tab.c"
    break;

  case 103: /* ExpressaoMultiplicativaPrime: MultOperador ExpressaoMultiplicativa  */
#line 282 "sintatico.y"
                                                                   {}
#line 1995 "sintatico.tab.c"
    break;

  case 104: /* ExpressaoMultiplicativaPrime: %empty  */
#line 283 "sintatico.y"
                                              {}
#line 2001 "sintatico.tab.c"
    break;

  case 105: /* MultOperador: TIMES  */
#line 285 "sintatico.y"
                    {}
#line 2007 "sintatico.tab.c"
    break;

  case 106: /* MultOperador: DIV  */
#line 286 "sintatico.y"
                              {}
#line 2013 "sintatico.tab.c"
    break;

  case 107: /* MultOperador: MOD  */
#line 287 "sintatico.y"
                              {}
#line 2019 "sintatico.tab.c"
    break;

  case 108: /* ExpressaoCast: ExpressaoUnaria  */
#line 291 "sintatico.y"
                               {}
#line 2025 "sintatico.tab.c"
    break;

  case 109: /* ExpressaoCast: L_PAREN Tipo VezesLoop R_PAREN ExpressaoCast  */
#line 292 "sintatico.y"
                                                                        {}
#line 2031 "sintatico.tab.c"
    break;

  case 110: /* ExpressaoUnaria: ExpressaoPosFixa  */
#line 295 "sintatico.y"
                                  {}
#line 2037 "sintatico.tab.c"
    break;

  case 111: /* ExpressaoUnaria: INC ExpressaoUnaria  */
#line 296 "sintatico.y"
                                                 {}
#line 2043 "sintatico.tab.c"
    break;

  case 112: /* ExpressaoUnaria: DEC ExpressaoUnaria  */
#line 297 "sintatico.y"
                                                 {}
#line 2049 "sintatico.tab.c"
    break;

  case 113: /* ExpressaoUnaria: UnarioOperador ExpressaoCast  */
#line 298 "sintatico.y"
                                                          {}
#line 2055 "sintatico.tab.c"
    break;

  case 114: /* UnarioOperador: AMPERSAND  */
#line 301 "sintatico.y"
                          {}
#line 2061 "sintatico.tab.c"
    break;

  case 115: /* UnarioOperador: TIMES  */
#line 302 "sintatico.y"
                                  {}
#line 2067 "sintatico.tab.c"
    break;

  case 116: /* UnarioOperador: PLUS  */
#line 303 "sintatico.y"
                                 {}
#line 2073 "sintatico.tab.c"
    break;

  case 117: /* UnarioOperador: MINUS  */
#line 304 "sintatico.y"
                                  {}
#line 2079 "sintatico.tab.c"
    break;

  case 118: /* UnarioOperador: BITWISE_COMP  */
#line 305 "sintatico.y"
                                         {}
#line 2085 "sintatico.tab.c"
    break;

  case 119: /* UnarioOperador: NOT  */
#line 306 "sintatico.y"
                                {}
#line 2091 "sintatico.tab.c"
    break;

  case 120: /* ExpressaoPosFixa: ExpressaoPrimaria  */
#line 309 "sintatico.y"
                                    {}
#line 2097 "sintatico.tab.c"
    break;

  case 121: /* ExpressaoPosFixa: ExpressaoPosFixa ExpressaoPosFixaPrime  */
#line 310 "sintatico.y"
                                                                     {}
#line 2103 "sintatico.tab.c"
    break;

  case 122: /* ExpressaoPosFixaPrime: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET  */
#line 313 "sintatico.y"
                                                                   {}
#line 2109 "sintatico.tab.c"
    break;

  case 123: /* ExpressaoPosFixaPrime: INC  */
#line 314 "sintatico.y"
                                   {}
#line 2115 "sintatico.tab.c"
    break;

  case 124: /* ExpressaoPosFixaPrime: DEC  */
#line 315 "sintatico.y"
                                       {}
#line 2121 "sintatico.tab.c"
    break;

  case 125: /* ExpressaoPosFixaPrime: L_PAREN OpExpressaoAtribuicaoLoop R_PAREN  */
#line 316 "sintatico.y"
                                                                             {}
#line 2127 "sintatico.tab.c"
    break;

  case 126: /* OpExpressaoAtribuicaoLoop: ExpressaoAtribuicaoLoop  */
#line 319 "sintatico.y"
                                                   {}
#line 2133 "sintatico.tab.c"
    break;

  case 127: /* OpExpressaoAtribuicaoLoop: %empty  */
#line 320 "sintatico.y"
                                               {}
#line 2139 "sintatico.tab.c"
    break;

  case 128: /* ExpressaoAtribuicaoLoop: ExpressaoAtribuicao ExpressaoAtribuicaoLoopPrime  */
#line 323 "sintatico.y"
                                                                          {}
#line 2145 "sintatico.tab.c"
    break;

  case 129: /* ExpressaoAtribuicaoLoopPrime: COMMA ExpressaoAtribuicaoLoop  */
#line 326 "sintatico.y"
                                                            {}
#line 2151 "sintatico.tab.c"
    break;

  case 130: /* ExpressaoAtribuicaoLoopPrime: %empty  */
#line 327 "sintatico.y"
                                              {}
#line 2157 "sintatico.tab.c"
    break;

  case 131: /* ExpressaoPrimaria: IDENTIFIER  */
#line 330 "sintatico.y"
                              {}
#line 2163 "sintatico.tab.c"
    break;

  case 132: /* ExpressaoPrimaria: Numero  */
#line 331 "sintatico.y"
                                          {}
#line 2169 "sintatico.tab.c"
    break;

  case 133: /* ExpressaoPrimaria: CHARACTER  */
#line 332 "sintatico.y"
                                             {}
#line 2175 "sintatico.tab.c"
    break;

  case 134: /* ExpressaoPrimaria: STRING  */
#line 333 "sintatico.y"
                                          {}
#line 2181 "sintatico.tab.c"
    break;

  case 135: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 334 "sintatico.y"
                                                             {}
#line 2187 "sintatico.tab.c"
    break;

  case 136: /* Numero: NUM_INTEGER  */
#line 337 "sintatico.y"
                    {}
#line 2193 "sintatico.tab.c"
    break;

  case 137: /* Numero: NUM_HEXA  */
#line 338 "sintatico.y"
                     {}
#line 2199 "sintatico.tab.c"
    break;

  case 138: /* Numero: NUM_OCTAL  */
#line 339 "sintatico.y"
                      {}
#line 2205 "sintatico.tab.c"
    break;


#line 2209 "sintatico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 342 "sintatico.y"


void yyerror(char *s){
	int columnError = column-((int)strlen(yytext));
	printf("error:syntax:%d:%d: %s\n", line, columnError, yytext);
	printf("%s", current_line);
	int i;
	for(i = 0; i < columnError-1; i++)
		printf(" ");
	printf("^");
	exit(0);
}

int main(int argc, char **argv){
    yyparse();
	printf("SUCCESSFUL COMPILATION.");
    return 0;
}
