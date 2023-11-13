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
extern int linha;
extern int coluna;
extern char* yytext;
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
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_SWITCH = 8,                     /* SWITCH  */
  YYSYMBOL_CASE = 9,                       /* CASE  */
  YYSYMBOL_DEFAULT = 10,                   /* DEFAULT  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_TYPEDEF = 16,                   /* TYPEDEF  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 20,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_REMAINDER = 22,                 /* REMAINDER  */
  YYSYMBOL_INC = 23,                       /* INC  */
  YYSYMBOL_DEC = 24,                       /* DEC  */
  YYSYMBOL_BITWISE_AND = 25,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 26,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_NOT = 27,               /* BITWISE_NOT  */
  YYSYMBOL_BITWISE_XOR = 28,               /* BITWISE_XOR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LOGICAL_AND = 30,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 31,                /* LOGICAL_OR  */
  YYSYMBOL_EQUAL = 32,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 33,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 34,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 35,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL = 36,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 37,             /* GREATER_EQUAL  */
  YYSYMBOL_R_SHIFT = 38,                   /* R_SHIFT  */
  YYSYMBOL_L_SHIFT = 39,                   /* L_SHIFT  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 41,                /* ADD_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 42,              /* MINUS_ASSIGN  */
  YYSYMBOL_SEMICOLON = 43,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_COLON = 45,                     /* COLON  */
  YYSYMBOL_L_PAREN = 46,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 47,                   /* R_PAREN  */
  YYSYMBOL_L_CURLY_BRACKET = 48,           /* L_CURLY_BRACKET  */
  YYSYMBOL_R_CURLY_BRACKET = 49,           /* R_CURLY_BRACKET  */
  YYSYMBOL_L_SQUARE_BRACKET = 50,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 51,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_TERNARY_CONDITIONAL = 52,       /* TERNARY_CONDITIONAL  */
  YYSYMBOL_NUMBER_SIGN = 53,               /* NUMBER_SIGN  */
  YYSYMBOL_POINTER = 54,                   /* POINTER  */
  YYSYMBOL_PRINTF = 55,                    /* PRINTF  */
  YYSYMBOL_SCANF = 56,                     /* SCANF  */
  YYSYMBOL_DEFINE = 57,                    /* DEFINE  */
  YYSYMBOL_EXIT = 58,                      /* EXIT  */
  YYSYMBOL_NUM_OCTAL = 59,                 /* NUM_OCTAL  */
  YYSYMBOL_NUM_HEXA = 60,                  /* NUM_HEXA  */
  YYSYMBOL_NUM_INTEGER = 61,               /* NUM_INTEGER  */
  YYSYMBOL_CHARACTER = 62,                 /* CHARACTER  */
  YYSYMBOL_STRING = 63,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 64,                /* IDENTIFIER  */
  YYSYMBOL_OTHER = 65,                     /* OTHER  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_Programa = 67,                  /* Programa  */
  YYSYMBOL_DeclaracoesFuncao = 68,         /* DeclaracoesFuncao  */
  YYSYMBOL_DeclaracoesFuncaoPrime = 69,    /* DeclaracoesFuncaoPrime  */
  YYSYMBOL_Declaracoes = 70,               /* Declaracoes  */
  YYSYMBOL_Funcao = 71,                    /* Funcao  */
  YYSYMBOL_PointerIter = 72,               /* PointerIter  */
  YYSYMBOL_FuncaoIter = 73,                /* FuncaoIter  */
  YYSYMBOL_DeclaracaoVariaveis = 74,       /* DeclaracaoVariaveis  */
  YYSYMBOL_DeclaracaoVariaveisIter = 75,   /* DeclaracaoVariaveisIter  */
  YYSYMBOL_ExpressaoIter = 76,             /* ExpressaoIter  */
  YYSYMBOL_DeclaracaoVariaveisAtribuicao = 77, /* DeclaracaoVariaveisAtribuicao  */
  YYSYMBOL_DeclaracaoVariaveisIterPrime = 78, /* DeclaracaoVariaveisIterPrime  */
  YYSYMBOL_DeclaracaoPrototipo = 79,       /* DeclaracaoPrototipo  */
  YYSYMBOL_Parametros = 80,                /* Parametros  */
  YYSYMBOL_ParametrosOpIter = 81,          /* ParametrosOpIter  */
  YYSYMBOL_ParametrosIter = 82,            /* ParametrosIter  */
  YYSYMBOL_ParametrosIterPrime = 83,       /* ParametrosIterPrime  */
  YYSYMBOL_Tipo = 84,                      /* Tipo  */
  YYSYMBOL_Bloco = 85,                     /* Bloco  */
  YYSYMBOL_Comandos = 86,                  /* Comandos  */
  YYSYMBOL_ComandosPrime = 87,             /* ComandosPrime  */
  YYSYMBOL_ListaComandos = 88,             /* ListaComandos  */
  YYSYMBOL_OpElse = 89,                    /* OpElse  */
  YYSYMBOL_OpExpressao = 90,               /* OpExpressao  */
  YYSYMBOL_OpVirgulaExpressao = 91,        /* OpVirgulaExpressao  */
  YYSYMBOL_Expressao = 92,                 /* Expressao  */
  YYSYMBOL_ExpressaoPrime = 93,            /* ExpressaoPrime  */
  YYSYMBOL_ExpressaoAtribuicao = 94,       /* ExpressaoAtribuicao  */
  YYSYMBOL_AtribuicaoOperador = 95,        /* AtribuicaoOperador  */
  YYSYMBOL_ExpressaoCondicional = 96,      /* ExpressaoCondicional  */
  YYSYMBOL_ExpressaoCondicionalPrime = 97, /* ExpressaoCondicionalPrime  */
  YYSYMBOL_ExpressaoOrLogico = 98,         /* ExpressaoOrLogico  */
  YYSYMBOL_ExpressaoOrLogicoPrime = 99,    /* ExpressaoOrLogicoPrime  */
  YYSYMBOL_ExpressaoAndLogico = 100,       /* ExpressaoAndLogico  */
  YYSYMBOL_ExpressaoAndLogicoPrime = 101,  /* ExpressaoAndLogicoPrime  */
  YYSYMBOL_ExpressaoOr = 102,              /* ExpressaoOr  */
  YYSYMBOL_ExpressaoOrPrime = 103,         /* ExpressaoOrPrime  */
  YYSYMBOL_ExpressaoXor = 104,             /* ExpressaoXor  */
  YYSYMBOL_ExpressaoXorPrime = 105,        /* ExpressaoXorPrime  */
  YYSYMBOL_ExpressaoAnd = 106,             /* ExpressaoAnd  */
  YYSYMBOL_ExpressaoAndPrime = 107,        /* ExpressaoAndPrime  */
  YYSYMBOL_ExpressaoIgualdade = 108,       /* ExpressaoIgualdade  */
  YYSYMBOL_ExpressaoIgualdadePrime = 109,  /* ExpressaoIgualdadePrime  */
  YYSYMBOL_IgualdadeOperador = 110,        /* IgualdadeOperador  */
  YYSYMBOL_ExpressaoRelacional = 111,      /* ExpressaoRelacional  */
  YYSYMBOL_ExpressaoRelacionalPrime = 112, /* ExpressaoRelacionalPrime  */
  YYSYMBOL_OperadorRelacional = 113,       /* OperadorRelacional  */
  YYSYMBOL_ExpressaoShift = 114,           /* ExpressaoShift  */
  YYSYMBOL_ExpressaoShiftPrime = 115,      /* ExpressaoShiftPrime  */
  YYSYMBOL_Shift = 116,                    /* Shift  */
  YYSYMBOL_ExpressaoAditiva = 117,         /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoAditivaPrime = 118,    /* ExpressaoAditivaPrime  */
  YYSYMBOL_MaisMenos = 119,                /* MaisMenos  */
  YYSYMBOL_ExpressaoMultiplicativa = 120,  /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoMultiplicativaPrime = 121, /* ExpressaoMultiplicativaPrime  */
  YYSYMBOL_Multiplicadores = 122,          /* Multiplicadores  */
  YYSYMBOL_ExpressaoCast = 123,            /* ExpressaoCast  */
  YYSYMBOL_ExpressaoUnaria = 124,          /* ExpressaoUnaria  */
  YYSYMBOL_OperadorUnario = 125,           /* OperadorUnario  */
  YYSYMBOL_ExpressaoPosFixa = 126,         /* ExpressaoPosFixa  */
  YYSYMBOL_ExpressaoPosFixaPrime = 127,    /* ExpressaoPosFixaPrime  */
  YYSYMBOL_OpExpressaoAtribuicaoIter = 128, /* OpExpressaoAtribuicaoIter  */
  YYSYMBOL_ExpressaoAtribuicaoIter = 129,  /* ExpressaoAtribuicaoIter  */
  YYSYMBOL_ExpressaoAtribuicaoIterPrime = 130, /* ExpressaoAtribuicaoIterPrime  */
  YYSYMBOL_ExpressaoPrimaria = 131,        /* ExpressaoPrimaria  */
  YYSYMBOL_Numero = 132                    /* Numero  */
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
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    86,    87,    90,    91,    94,    95,    96,
      99,   102,   103,   106,   107,   110,   113,   116,   117,   120,
     121,   124,   125,   128,   131,   134,   135,   138,   141,   142,
     145,   146,   147,   150,   153,   156,   157,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   173,   174,
     177,   178,   181,   182,   185,   188,   189,   192,   193,   196,
     197,   198,   201,   204,   205,   208,   211,   212,   215,   218,
     219,   222,   225,   226,   229,   232,   233,   236,   239,   240,
     243,   246,   247,   250,   251,   254,   257,   258,   261,   262,
     263,   264,   267,   270,   271,   274,   275,   278,   281,   282,
     285,   286,   289,   292,   293,   296,   297,   298,   301,   302,
     305,   306,   307,   308,   311,   312,   313,   314,   315,   316,
     319,   320,   323,   324,   325,   326,   329,   330,   333,   336,
     337,   340,   341,   342,   343,   344,   347,   348,   349
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
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "CHAR",
  "RETURN", "BREAK", "SWITCH", "CASE", "DEFAULT", "DO", "WHILE", "FOR",
  "IF", "ELSE", "TYPEDEF", "STRUCT", "PLUS", "MINUS", "MULTIPLY", "DIV",
  "REMAINDER", "INC", "DEC", "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT",
  "BITWISE_XOR", "NOT", "LOGICAL_AND", "LOGICAL_OR", "EQUAL", "NOT_EQUAL",
  "LESS_THAN", "GREATER_THAN", "LESS_EQUAL", "GREATER_EQUAL", "R_SHIFT",
  "L_SHIFT", "ASSIGN", "ADD_ASSIGN", "MINUS_ASSIGN", "SEMICOLON", "COMMA",
  "COLON", "L_PAREN", "R_PAREN", "L_CURLY_BRACKET", "R_CURLY_BRACKET",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "TERNARY_CONDITIONAL",
  "NUMBER_SIGN", "POINTER", "PRINTF", "SCANF", "DEFINE", "EXIT",
  "NUM_OCTAL", "NUM_HEXA", "NUM_INTEGER", "CHARACTER", "STRING",
  "IDENTIFIER", "OTHER", "$accept", "Programa", "DeclaracoesFuncao",
  "DeclaracoesFuncaoPrime", "Declaracoes", "Funcao", "PointerIter",
  "FuncaoIter", "DeclaracaoVariaveis", "DeclaracaoVariaveisIter",
  "ExpressaoIter", "DeclaracaoVariaveisAtribuicao",
  "DeclaracaoVariaveisIterPrime", "DeclaracaoPrototipo", "Parametros",
  "ParametrosOpIter", "ParametrosIter", "ParametrosIterPrime", "Tipo",
  "Bloco", "Comandos", "ComandosPrime", "ListaComandos", "OpElse",
  "OpExpressao", "OpVirgulaExpressao", "Expressao", "ExpressaoPrime",
  "ExpressaoAtribuicao", "AtribuicaoOperador", "ExpressaoCondicional",
  "ExpressaoCondicionalPrime", "ExpressaoOrLogico",
  "ExpressaoOrLogicoPrime", "ExpressaoAndLogico",
  "ExpressaoAndLogicoPrime", "ExpressaoOr", "ExpressaoOrPrime",
  "ExpressaoXor", "ExpressaoXorPrime", "ExpressaoAnd", "ExpressaoAndPrime",
  "ExpressaoIgualdade", "ExpressaoIgualdadePrime", "IgualdadeOperador",
  "ExpressaoRelacional", "ExpressaoRelacionalPrime", "OperadorRelacional",
  "ExpressaoShift", "ExpressaoShiftPrime", "Shift", "ExpressaoAditiva",
  "ExpressaoAditivaPrime", "MaisMenos", "ExpressaoMultiplicativa",
  "ExpressaoMultiplicativaPrime", "Multiplicadores", "ExpressaoCast",
  "ExpressaoUnaria", "OperadorUnario", "ExpressaoPosFixa",
  "ExpressaoPosFixaPrime", "OpExpressaoAtribuicaoIter",
  "ExpressaoAtribuicaoIter", "ExpressaoAtribuicaoIterPrime",
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
       5,  -172,  -172,  -172,   -28,    26,     5,  -172,  -172,  -172,
    -172,    11,   -27,  -172,     5,  -172,    11,    -7,    22,   116,
    -172,  -172,   -22,  -172,  -172,  -172,  -172,   231,   231,  -172,
    -172,  -172,    92,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
      31,  -172,    28,    50,    52,    57,    58,    60,   -10,    -1,
       7,    59,    42,    27,   116,    -8,  -172,  -172,    68,   116,
      47,   -23,   116,  -172,  -172,    11,    41,   116,  -172,   116,
    -172,   116,  -172,   116,  -172,   116,  -172,   116,  -172,   116,
    -172,  -172,  -172,  -172,   116,  -172,  -172,  -172,  -172,  -172,
     116,  -172,  -172,  -172,   116,  -172,  -172,  -172,   116,  -172,
    -172,  -172,  -172,   116,  -172,  -172,  -172,   116,  -172,  -172,
    -172,  -172,   116,   116,  -172,    43,  -172,    11,    38,   116,
      48,  -172,    68,    46,  -172,  -172,    53,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,    55,    54,
    -172,    49,  -172,    39,    56,  -172,    11,  -172,   184,    68,
      11,   116,   116,   116,  -172,  -172,  -172,    56,  -172,    40,
    -172,   116,    61,    67,    74,    76,  -172,   184,    77,    78,
      79,  -172,    65,   184,    62,  -172,  -172,  -172,  -172,    63,
      56,    83,  -172,   117,   116,   116,   116,    81,    69,    70,
     116,  -172,  -172,   184,  -172,    68,  -172,  -172,    85,    90,
     101,    99,  -172,   103,   104,   102,  -172,  -172,   116,    61,
     116,    61,   116,   110,   125,   115,   112,  -172,   118,   145,
    -172,   120,   105,  -172,   127,   116,    61,  -172,  -172,   121,
    -172,   126,  -172,   129,    61,  -172,  -172
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    32,    30,    31,     0,     0,     6,     3,     4,     8,
       9,    12,     0,     1,     6,     2,    12,     0,     0,     0,
       5,    11,    18,    15,   116,   117,   115,     0,     0,   114,
     118,   119,     0,   138,   137,   136,   133,   134,   131,     7,
      56,    57,    64,    67,    70,    73,    76,    79,    82,    87,
      94,    99,   104,   108,     0,   110,   120,   132,    26,     0,
      20,     0,     0,   111,   112,    12,     0,     0,    54,     0,
      62,     0,    65,     0,    68,     0,    71,     0,    74,     0,
      77,    83,    84,    80,     0,    88,    90,    89,    91,    85,
       0,    96,    95,    92,     0,   100,   101,    97,     0,   105,
     106,   107,   102,     0,    59,    60,    61,     0,   113,   108,
     123,   124,   127,     0,   121,     0,    25,    12,     0,     0,
      22,    23,    14,     0,   135,    55,     0,    66,    69,    72,
      75,    78,    81,    86,    93,    98,   103,    58,   130,     0,
     126,     0,    24,     0,    18,    19,    12,    16,     0,    14,
      12,     0,     0,     0,   128,   125,   122,    18,    17,     0,
      21,    51,     0,     0,     0,     0,    46,     0,     0,     0,
       0,    47,     0,    36,     0,    13,   109,    63,   129,    29,
      18,     0,    50,     0,     0,    51,     0,     0,     0,     0,
       0,    10,    34,    36,    45,     0,    27,    44,     0,     0,
       0,     0,    33,    53,     0,     0,    35,    28,     0,     0,
      51,     0,     0,     0,     0,     0,     0,    39,     0,    49,
      52,     0,     0,    43,     0,    51,     0,    38,    41,     0,
      37,     0,    48,     0,     0,    42,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,   174,   167,  -172,  -172,    -9,    33,  -105,    37,
    -125,  -172,  -172,  -172,  -172,  -172,   -11,  -172,   -31,  -150,
      18,    -6,  -152,  -172,  -171,  -172,   -19,  -172,  -101,  -172,
      34,  -172,   123,  -172,   119,  -172,   113,  -172,   122,  -172,
     131,  -172,   128,  -172,  -172,   111,  -172,  -172,   106,  -172,
    -172,   107,  -172,  -172,   114,  -172,  -172,   -49,   -24,  -172,
    -172,  -172,  -172,    66,  -172,  -172,  -172
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,    14,    15,     7,     8,   159,   148,     9,    18,
      60,   120,   147,    10,    61,   115,   116,   196,    11,   171,
     172,   192,   173,   227,   181,   213,   174,    68,    40,   107,
      41,    70,    42,    72,    43,    74,    44,    76,    45,    78,
      46,    80,    47,    83,    84,    48,    89,    90,    49,    93,
      94,    50,    97,    98,    51,   102,   103,    52,    53,    54,
      55,   114,   139,   140,   154,    56,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    65,    17,    63,    64,   108,   137,    21,     1,     2,
       3,   138,   183,    66,   200,   110,   111,   149,   145,   158,
     121,   193,    81,    82,    58,   122,    13,   117,    59,    12,
     109,    16,   179,    85,    86,    87,    88,    19,   112,   218,
     118,   193,   113,    66,   149,    91,    92,   109,   125,   109,
     126,   109,   138,   109,   231,   109,   123,    22,     4,   217,
     109,   219,    99,   100,   101,    23,   109,   104,   105,   106,
     109,     1,     2,     3,   109,    67,   232,    95,    96,   109,
      69,    71,    73,    75,   236,    79,    77,   119,   124,   144,
     142,   150,   146,   151,   141,     1,     2,     3,   152,   153,
     156,   155,   176,   157,   180,   194,    59,   195,   143,   167,
      24,    25,    26,   184,   191,    27,    28,    29,   150,    30,
     185,    31,   186,   188,   189,   190,   197,   109,   109,   198,
     202,   208,   203,   204,    24,    25,    26,   209,    32,    27,
      28,    29,   182,    30,   210,    31,   211,   212,   214,   215,
     222,    33,    34,    35,    36,    37,    38,   221,   223,   224,
     226,   225,    32,   228,   117,   199,   182,   201,   233,   229,
     230,   205,   235,   234,     6,    33,    34,    35,    36,    37,
      38,    20,   175,   160,   207,   187,   177,   206,   129,   216,
     161,   182,   128,   220,   127,   162,   163,   164,   165,   130,
     134,   133,    24,    25,    26,   135,   182,    27,    28,    29,
     131,    30,   132,    31,     0,     0,     0,   136,     0,   178,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
      32,     0,   167,     0,     0,     0,     0,     0,     0,   168,
     169,     0,   170,    33,    34,    35,    36,    37,    38,    24,
      25,    26,     0,     0,    27,    28,    29,     0,    30,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      19,    32,    11,    27,    28,    54,   107,    16,     3,     4,
       5,   112,   162,    32,   185,    23,    24,   122,   119,   144,
      43,   173,    32,    33,    46,    48,     0,    58,    50,    57,
      54,    20,   157,    34,    35,    36,    37,    64,    46,   210,
      59,   193,    50,    62,   149,    38,    39,    71,    67,    73,
      69,    75,   153,    77,   225,    79,    65,    64,    53,   209,
      84,   211,    20,    21,    22,    43,    90,    40,    41,    42,
      94,     3,     4,     5,    98,    44,   226,    18,    19,   103,
      52,    31,    30,    26,   234,    25,    28,    40,    47,    51,
      47,   122,    44,    47,   113,     3,     4,     5,    45,    44,
      51,    47,   151,    64,    64,    43,    50,    44,   117,    48,
      18,    19,    20,    46,    49,    23,    24,    25,   149,    27,
      46,    29,    46,    46,    46,    46,    43,   151,   152,    12,
      49,    46,    63,    63,    18,    19,    20,    47,    46,    23,
      24,    25,   161,    27,    43,    29,    47,    44,    44,    47,
      25,    59,    60,    61,    62,    63,    64,    47,    43,    47,
      15,    43,    46,    43,   195,   184,   185,   186,    47,    64,
      43,   190,    43,    47,     0,    59,    60,    61,    62,    63,
      64,    14,   149,   146,   195,   167,   152,   193,    75,   208,
       6,   210,    73,   212,    71,    11,    12,    13,    14,    77,
      94,    90,    18,    19,    20,    98,   225,    23,    24,    25,
      79,    27,    84,    29,    -1,    -1,    -1,   103,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      46,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    18,
      19,    20,    -1,    -1,    23,    24,    25,    -1,    27,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    53,    67,    68,    70,    71,    74,
      79,    84,    57,     0,    68,    69,    20,    72,    75,    64,
      69,    72,    64,    43,    18,    19,    20,    23,    24,    25,
      27,    29,    46,    59,    60,    61,    62,    63,    64,    92,
      94,    96,    98,   100,   102,   104,   106,   108,   111,   114,
     117,   120,   123,   124,   125,   126,   131,   132,    46,    50,
      76,    80,    46,   124,   124,    84,    92,    44,    93,    52,
      97,    31,    99,    30,   101,    26,   103,    28,   105,    25,
     107,    32,    33,   109,   110,    34,    35,    36,    37,   112,
     113,    38,    39,   115,   116,    18,    19,   118,   119,    20,
      21,    22,   121,   122,    40,    41,    42,    95,   123,   124,
      23,    24,    46,    50,   127,    81,    82,    84,    92,    40,
      77,    43,    48,    72,    47,    92,    92,    98,   100,   102,
     104,   106,   108,   111,   114,   117,   120,    94,    94,   128,
     129,    92,    47,    72,    51,    94,    44,    78,    73,    74,
      84,    47,    45,    44,   130,    47,    51,    64,    76,    72,
      75,     6,    11,    12,    13,    14,    43,    48,    55,    56,
      58,    85,    86,    88,    92,    73,   123,    96,   129,    76,
      64,    90,    92,    85,    46,    46,    46,    86,    46,    46,
      46,    49,    87,    88,    43,    44,    83,    43,    12,    92,
      90,    92,    49,    63,    63,    92,    87,    82,    46,    47,
      43,    47,    44,    91,    44,    47,    92,    85,    90,    85,
      92,    47,    25,    43,    47,    43,    15,    89,    43,    64,
      43,    90,    85,    47,    47,    43,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    70,    70,    70,
      71,    72,    72,    73,    73,    74,    75,    76,    76,    77,
      77,    78,    78,    79,    80,    81,    81,    82,    83,    83,
      84,    84,    84,    85,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    93,    93,    94,    94,    95,
      95,    95,    96,    97,    97,    98,    99,    99,   100,   101,
     101,   102,   103,   103,   104,   105,   105,   106,   107,   107,
     108,   109,   109,   110,   110,   111,   112,   112,   113,   113,
     113,   113,   114,   115,   115,   116,   116,   117,   118,   118,
     119,   119,   120,   121,   121,   122,   122,   122,   123,   123,
     124,   124,   124,   124,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   128,   128,   129,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   132
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
  case 2: /* Programa: DeclaracoesFuncao DeclaracoesFuncaoPrime  */
#line 83 "sintatico.y"
                                                   {}
#line 1405 "sintatico.tab.c"
    break;

  case 3: /* DeclaracoesFuncao: Declaracoes  */
#line 86 "sintatico.y"
                               {}
#line 1411 "sintatico.tab.c"
    break;

  case 4: /* DeclaracoesFuncao: Funcao  */
#line 87 "sintatico.y"
                 {}
#line 1417 "sintatico.tab.c"
    break;

  case 5: /* DeclaracoesFuncaoPrime: DeclaracoesFuncao DeclaracoesFuncaoPrime  */
#line 90 "sintatico.y"
                                                                 {}
#line 1423 "sintatico.tab.c"
    break;

  case 6: /* DeclaracoesFuncaoPrime: %empty  */
#line 91 "sintatico.y"
          {}
#line 1429 "sintatico.tab.c"
    break;

  case 7: /* Declaracoes: NUMBER_SIGN DEFINE IDENTIFIER Expressao  */
#line 94 "sintatico.y"
                                                     {}
#line 1435 "sintatico.tab.c"
    break;

  case 8: /* Declaracoes: DeclaracaoVariaveis  */
#line 95 "sintatico.y"
                              {}
#line 1441 "sintatico.tab.c"
    break;

  case 9: /* Declaracoes: DeclaracaoPrototipo  */
#line 96 "sintatico.y"
                              {}
#line 1447 "sintatico.tab.c"
    break;

  case 10: /* Funcao: Tipo PointerIter IDENTIFIER Parametros L_CURLY_BRACKET FuncaoIter Comandos R_CURLY_BRACKET  */
#line 99 "sintatico.y"
                                                                                                   {}
#line 1453 "sintatico.tab.c"
    break;

  case 11: /* PointerIter: MULTIPLY PointerIter  */
#line 102 "sintatico.y"
                                  {}
#line 1459 "sintatico.tab.c"
    break;

  case 12: /* PointerIter: %empty  */
#line 103 "sintatico.y"
          {}
#line 1465 "sintatico.tab.c"
    break;

  case 13: /* FuncaoIter: DeclaracaoVariaveis FuncaoIter  */
#line 106 "sintatico.y"
                                           {}
#line 1471 "sintatico.tab.c"
    break;

  case 14: /* FuncaoIter: %empty  */
#line 107 "sintatico.y"
          {}
#line 1477 "sintatico.tab.c"
    break;

  case 15: /* DeclaracaoVariaveis: Tipo DeclaracaoVariaveisIter SEMICOLON  */
#line 110 "sintatico.y"
                                                            {}
#line 1483 "sintatico.tab.c"
    break;

  case 16: /* DeclaracaoVariaveisIter: PointerIter IDENTIFIER ExpressaoIter DeclaracaoVariaveisAtribuicao DeclaracaoVariaveisIterPrime  */
#line 113 "sintatico.y"
                                                                                                                         {}
#line 1489 "sintatico.tab.c"
    break;

  case 17: /* ExpressaoIter: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoIter  */
#line 116 "sintatico.y"
                                                                         {}
#line 1495 "sintatico.tab.c"
    break;

  case 18: /* ExpressaoIter: %empty  */
#line 117 "sintatico.y"
          {}
#line 1501 "sintatico.tab.c"
    break;

  case 19: /* DeclaracaoVariaveisAtribuicao: ASSIGN ExpressaoAtribuicao  */
#line 120 "sintatico.y"
                                                          {}
#line 1507 "sintatico.tab.c"
    break;

  case 20: /* DeclaracaoVariaveisAtribuicao: %empty  */
#line 121 "sintatico.y"
          {}
#line 1513 "sintatico.tab.c"
    break;

  case 21: /* DeclaracaoVariaveisIterPrime: COMMA DeclaracaoVariaveisIter  */
#line 124 "sintatico.y"
                                                            {}
#line 1519 "sintatico.tab.c"
    break;

  case 22: /* DeclaracaoVariaveisIterPrime: %empty  */
#line 125 "sintatico.y"
          {}
#line 1525 "sintatico.tab.c"
    break;

  case 23: /* DeclaracaoPrototipo: Tipo PointerIter IDENTIFIER Parametros SEMICOLON  */
#line 128 "sintatico.y"
                                                                      {}
#line 1531 "sintatico.tab.c"
    break;

  case 24: /* Parametros: L_PAREN ParametrosOpIter R_PAREN  */
#line 131 "sintatico.y"
                                             {}
#line 1537 "sintatico.tab.c"
    break;

  case 25: /* ParametrosOpIter: ParametrosIter  */
#line 134 "sintatico.y"
                                 {}
#line 1543 "sintatico.tab.c"
    break;

  case 26: /* ParametrosOpIter: %empty  */
#line 135 "sintatico.y"
          {}
#line 1549 "sintatico.tab.c"
    break;

  case 27: /* ParametrosIter: Tipo PointerIter IDENTIFIER ExpressaoIter ParametrosIterPrime  */
#line 138 "sintatico.y"
                                                                              {}
#line 1555 "sintatico.tab.c"
    break;

  case 28: /* ParametrosIterPrime: COMMA ParametrosIter  */
#line 141 "sintatico.y"
                                          {}
#line 1561 "sintatico.tab.c"
    break;

  case 29: /* ParametrosIterPrime: %empty  */
#line 142 "sintatico.y"
          {}
#line 1567 "sintatico.tab.c"
    break;

  case 30: /* Tipo: INT  */
#line 145 "sintatico.y"
          {}
#line 1573 "sintatico.tab.c"
    break;

  case 31: /* Tipo: CHAR  */
#line 146 "sintatico.y"
               {}
#line 1579 "sintatico.tab.c"
    break;

  case 32: /* Tipo: VOID  */
#line 147 "sintatico.y"
               {}
#line 1585 "sintatico.tab.c"
    break;

  case 33: /* Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET  */
#line 150 "sintatico.y"
                                                {}
#line 1591 "sintatico.tab.c"
    break;

  case 34: /* Comandos: ListaComandos ComandosPrime  */
#line 153 "sintatico.y"
                                      {}
#line 1597 "sintatico.tab.c"
    break;

  case 35: /* ComandosPrime: ListaComandos ComandosPrime  */
#line 156 "sintatico.y"
                                           {}
#line 1603 "sintatico.tab.c"
    break;

  case 36: /* ComandosPrime: %empty  */
#line 157 "sintatico.y"
          {}
#line 1609 "sintatico.tab.c"
    break;

  case 37: /* ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON  */
#line 160 "sintatico.y"
                                                                  {}
#line 1615 "sintatico.tab.c"
    break;

  case 38: /* ListaComandos: IF L_PAREN Expressao R_PAREN Bloco OpElse  */
#line 161 "sintatico.y"
                                                    {}
#line 1621 "sintatico.tab.c"
    break;

  case 39: /* ListaComandos: WHILE L_PAREN Expressao R_PAREN Bloco  */
#line 162 "sintatico.y"
                                                {}
#line 1627 "sintatico.tab.c"
    break;

  case 40: /* ListaComandos: FOR L_PAREN OpExpressao SEMICOLON OpExpressao SEMICOLON OpExpressao R_PAREN Bloco  */
#line 163 "sintatico.y"
                                                                                            {}
#line 1633 "sintatico.tab.c"
    break;

  case 41: /* ListaComandos: PRINTF L_PAREN STRING OpVirgulaExpressao R_PAREN SEMICOLON  */
#line 164 "sintatico.y"
                                                                     {}
#line 1639 "sintatico.tab.c"
    break;

  case 42: /* ListaComandos: SCANF L_PAREN STRING COMMA BITWISE_AND IDENTIFIER R_PAREN SEMICOLON  */
#line 165 "sintatico.y"
                                                                              {}
#line 1645 "sintatico.tab.c"
    break;

  case 43: /* ListaComandos: EXIT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 166 "sintatico.y"
                                                   {}
#line 1651 "sintatico.tab.c"
    break;

  case 44: /* ListaComandos: RETURN OpExpressao SEMICOLON  */
#line 167 "sintatico.y"
                                       {}
#line 1657 "sintatico.tab.c"
    break;

  case 45: /* ListaComandos: Expressao SEMICOLON  */
#line 168 "sintatico.y"
                              {}
#line 1663 "sintatico.tab.c"
    break;

  case 46: /* ListaComandos: SEMICOLON  */
#line 169 "sintatico.y"
                    {}
#line 1669 "sintatico.tab.c"
    break;

  case 47: /* ListaComandos: Bloco  */
#line 170 "sintatico.y"
                {}
#line 1675 "sintatico.tab.c"
    break;

  case 48: /* OpElse: ELSE Bloco  */
#line 173 "sintatico.y"
                   {}
#line 1681 "sintatico.tab.c"
    break;

  case 49: /* OpElse: %empty  */
#line 174 "sintatico.y"
          {}
#line 1687 "sintatico.tab.c"
    break;

  case 50: /* OpExpressao: Expressao  */
#line 177 "sintatico.y"
                       {}
#line 1693 "sintatico.tab.c"
    break;

  case 51: /* OpExpressao: %empty  */
#line 178 "sintatico.y"
          {}
#line 1699 "sintatico.tab.c"
    break;

  case 52: /* OpVirgulaExpressao: COMMA Expressao  */
#line 181 "sintatico.y"
                                    {}
#line 1705 "sintatico.tab.c"
    break;

  case 53: /* OpVirgulaExpressao: %empty  */
#line 182 "sintatico.y"
          {}
#line 1711 "sintatico.tab.c"
    break;

  case 54: /* Expressao: ExpressaoAtribuicao ExpressaoPrime  */
#line 185 "sintatico.y"
                                              {}
#line 1717 "sintatico.tab.c"
    break;

  case 55: /* ExpressaoPrime: COMMA Expressao  */
#line 188 "sintatico.y"
                                {}
#line 1723 "sintatico.tab.c"
    break;

  case 56: /* ExpressaoPrime: %empty  */
#line 189 "sintatico.y"
          {}
#line 1729 "sintatico.tab.c"
    break;

  case 57: /* ExpressaoAtribuicao: ExpressaoCondicional  */
#line 192 "sintatico.y"
                                          {}
#line 1735 "sintatico.tab.c"
    break;

  case 58: /* ExpressaoAtribuicao: ExpressaoUnaria AtribuicaoOperador ExpressaoAtribuicao  */
#line 193 "sintatico.y"
                                                                 {}
#line 1741 "sintatico.tab.c"
    break;

  case 59: /* AtribuicaoOperador: ASSIGN  */
#line 196 "sintatico.y"
                           {}
#line 1747 "sintatico.tab.c"
    break;

  case 60: /* AtribuicaoOperador: ADD_ASSIGN  */
#line 197 "sintatico.y"
                     {}
#line 1753 "sintatico.tab.c"
    break;

  case 61: /* AtribuicaoOperador: MINUS_ASSIGN  */
#line 198 "sintatico.y"
                       {}
#line 1759 "sintatico.tab.c"
    break;

  case 62: /* ExpressaoCondicional: ExpressaoOrLogico ExpressaoCondicionalPrime  */
#line 201 "sintatico.y"
                                                                  {}
#line 1765 "sintatico.tab.c"
    break;

  case 63: /* ExpressaoCondicionalPrime: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional  */
#line 204 "sintatico.y"
                                                                                    {}
#line 1771 "sintatico.tab.c"
    break;

  case 64: /* ExpressaoCondicionalPrime: %empty  */
#line 205 "sintatico.y"
          {}
#line 1777 "sintatico.tab.c"
    break;

  case 65: /* ExpressaoOrLogico: ExpressaoAndLogico ExpressaoOrLogicoPrime  */
#line 208 "sintatico.y"
                                                             {}
#line 1783 "sintatico.tab.c"
    break;

  case 66: /* ExpressaoOrLogicoPrime: LOGICAL_OR ExpressaoOrLogico  */
#line 211 "sintatico.y"
                                                     {}
#line 1789 "sintatico.tab.c"
    break;

  case 67: /* ExpressaoOrLogicoPrime: %empty  */
#line 212 "sintatico.y"
          {}
#line 1795 "sintatico.tab.c"
    break;

  case 68: /* ExpressaoAndLogico: ExpressaoOr ExpressaoAndLogicoPrime  */
#line 215 "sintatico.y"
                                                        {}
#line 1801 "sintatico.tab.c"
    break;

  case 69: /* ExpressaoAndLogicoPrime: LOGICAL_AND ExpressaoAndLogico  */
#line 218 "sintatico.y"
                                                        {}
#line 1807 "sintatico.tab.c"
    break;

  case 70: /* ExpressaoAndLogicoPrime: %empty  */
#line 219 "sintatico.y"
          {}
#line 1813 "sintatico.tab.c"
    break;

  case 71: /* ExpressaoOr: ExpressaoXor ExpressaoOrPrime  */
#line 222 "sintatico.y"
                                           {}
#line 1819 "sintatico.tab.c"
    break;

  case 72: /* ExpressaoOrPrime: BITWISE_OR ExpressaoOr  */
#line 225 "sintatico.y"
                                         {}
#line 1825 "sintatico.tab.c"
    break;

  case 73: /* ExpressaoOrPrime: %empty  */
#line 226 "sintatico.y"
          {}
#line 1831 "sintatico.tab.c"
    break;

  case 74: /* ExpressaoXor: ExpressaoAnd ExpressaoXorPrime  */
#line 229 "sintatico.y"
                                             {}
#line 1837 "sintatico.tab.c"
    break;

  case 75: /* ExpressaoXorPrime: BITWISE_XOR ExpressaoXor  */
#line 232 "sintatico.y"
                                            {}
#line 1843 "sintatico.tab.c"
    break;

  case 76: /* ExpressaoXorPrime: %empty  */
#line 233 "sintatico.y"
          {}
#line 1849 "sintatico.tab.c"
    break;

  case 77: /* ExpressaoAnd: ExpressaoIgualdade ExpressaoAndPrime  */
#line 236 "sintatico.y"
                                                   {}
#line 1855 "sintatico.tab.c"
    break;

  case 78: /* ExpressaoAndPrime: BITWISE_AND ExpressaoAnd  */
#line 239 "sintatico.y"
                                            {}
#line 1861 "sintatico.tab.c"
    break;

  case 79: /* ExpressaoAndPrime: %empty  */
#line 240 "sintatico.y"
          {}
#line 1867 "sintatico.tab.c"
    break;

  case 80: /* ExpressaoIgualdade: ExpressaoRelacional ExpressaoIgualdadePrime  */
#line 243 "sintatico.y"
                                                                {}
#line 1873 "sintatico.tab.c"
    break;

  case 81: /* ExpressaoIgualdadePrime: IgualdadeOperador ExpressaoIgualdade  */
#line 246 "sintatico.y"
                                                              {}
#line 1879 "sintatico.tab.c"
    break;

  case 82: /* ExpressaoIgualdadePrime: %empty  */
#line 247 "sintatico.y"
          {}
#line 1885 "sintatico.tab.c"
    break;

  case 83: /* IgualdadeOperador: EQUAL  */
#line 250 "sintatico.y"
                         {}
#line 1891 "sintatico.tab.c"
    break;

  case 84: /* IgualdadeOperador: NOT_EQUAL  */
#line 251 "sintatico.y"
                    {}
#line 1897 "sintatico.tab.c"
    break;

  case 85: /* ExpressaoRelacional: ExpressaoShift ExpressaoRelacionalPrime  */
#line 254 "sintatico.y"
                                                             {}
#line 1903 "sintatico.tab.c"
    break;

  case 86: /* ExpressaoRelacionalPrime: OperadorRelacional ExpressaoRelacional  */
#line 257 "sintatico.y"
                                                                 {}
#line 1909 "sintatico.tab.c"
    break;

  case 87: /* ExpressaoRelacionalPrime: %empty  */
#line 258 "sintatico.y"
          {}
#line 1915 "sintatico.tab.c"
    break;

  case 88: /* OperadorRelacional: LESS_THAN  */
#line 261 "sintatico.y"
                              {}
#line 1921 "sintatico.tab.c"
    break;

  case 89: /* OperadorRelacional: LESS_EQUAL  */
#line 262 "sintatico.y"
                     {}
#line 1927 "sintatico.tab.c"
    break;

  case 90: /* OperadorRelacional: GREATER_THAN  */
#line 263 "sintatico.y"
                       {}
#line 1933 "sintatico.tab.c"
    break;

  case 91: /* OperadorRelacional: GREATER_EQUAL  */
#line 264 "sintatico.y"
                        {}
#line 1939 "sintatico.tab.c"
    break;

  case 92: /* ExpressaoShift: ExpressaoAditiva ExpressaoShiftPrime  */
#line 267 "sintatico.y"
                                                     {}
#line 1945 "sintatico.tab.c"
    break;

  case 93: /* ExpressaoShiftPrime: Shift ExpressaoShift  */
#line 270 "sintatico.y"
                                          {}
#line 1951 "sintatico.tab.c"
    break;

  case 94: /* ExpressaoShiftPrime: %empty  */
#line 271 "sintatico.y"
          {}
#line 1957 "sintatico.tab.c"
    break;

  case 95: /* Shift: L_SHIFT  */
#line 274 "sintatico.y"
                {}
#line 1963 "sintatico.tab.c"
    break;

  case 96: /* Shift: R_SHIFT  */
#line 275 "sintatico.y"
                  {}
#line 1969 "sintatico.tab.c"
    break;

  case 97: /* ExpressaoAditiva: ExpressaoMultiplicativa ExpressaoAditivaPrime  */
#line 278 "sintatico.y"
                                                                {}
#line 1975 "sintatico.tab.c"
    break;

  case 98: /* ExpressaoAditivaPrime: MaisMenos ExpressaoAditiva  */
#line 281 "sintatico.y"
                                                  {}
#line 1981 "sintatico.tab.c"
    break;

  case 99: /* ExpressaoAditivaPrime: %empty  */
#line 282 "sintatico.y"
          {}
#line 1987 "sintatico.tab.c"
    break;

  case 100: /* MaisMenos: PLUS  */
#line 285 "sintatico.y"
                {}
#line 1993 "sintatico.tab.c"
    break;

  case 101: /* MaisMenos: MINUS  */
#line 286 "sintatico.y"
                {}
#line 1999 "sintatico.tab.c"
    break;

  case 102: /* ExpressaoMultiplicativa: ExpressaoCast ExpressaoMultiplicativaPrime  */
#line 289 "sintatico.y"
                                                                    {}
#line 2005 "sintatico.tab.c"
    break;

  case 103: /* ExpressaoMultiplicativaPrime: Multiplicadores ExpressaoMultiplicativa  */
#line 292 "sintatico.y"
                                                                      {}
#line 2011 "sintatico.tab.c"
    break;

  case 104: /* ExpressaoMultiplicativaPrime: %empty  */
#line 293 "sintatico.y"
          {}
#line 2017 "sintatico.tab.c"
    break;

  case 105: /* Multiplicadores: MULTIPLY  */
#line 296 "sintatico.y"
                          {}
#line 2023 "sintatico.tab.c"
    break;

  case 106: /* Multiplicadores: DIV  */
#line 297 "sintatico.y"
              {}
#line 2029 "sintatico.tab.c"
    break;

  case 107: /* Multiplicadores: REMAINDER  */
#line 298 "sintatico.y"
                    {}
#line 2035 "sintatico.tab.c"
    break;

  case 108: /* ExpressaoCast: ExpressaoUnaria  */
#line 301 "sintatico.y"
                               {}
#line 2041 "sintatico.tab.c"
    break;

  case 109: /* ExpressaoCast: L_PAREN Tipo PointerIter R_PAREN ExpressaoCast  */
#line 302 "sintatico.y"
                                                         {}
#line 2047 "sintatico.tab.c"
    break;

  case 110: /* ExpressaoUnaria: ExpressaoPosFixa  */
#line 305 "sintatico.y"
                                  {}
#line 2053 "sintatico.tab.c"
    break;

  case 111: /* ExpressaoUnaria: INC ExpressaoUnaria  */
#line 306 "sintatico.y"
                              {}
#line 2059 "sintatico.tab.c"
    break;

  case 112: /* ExpressaoUnaria: DEC ExpressaoUnaria  */
#line 307 "sintatico.y"
                              {}
#line 2065 "sintatico.tab.c"
    break;

  case 113: /* ExpressaoUnaria: OperadorUnario ExpressaoCast  */
#line 308 "sintatico.y"
                                       {}
#line 2071 "sintatico.tab.c"
    break;

  case 114: /* OperadorUnario: BITWISE_AND  */
#line 311 "sintatico.y"
                            {}
#line 2077 "sintatico.tab.c"
    break;

  case 115: /* OperadorUnario: MULTIPLY  */
#line 312 "sintatico.y"
                   {}
#line 2083 "sintatico.tab.c"
    break;

  case 116: /* OperadorUnario: PLUS  */
#line 313 "sintatico.y"
               {}
#line 2089 "sintatico.tab.c"
    break;

  case 117: /* OperadorUnario: MINUS  */
#line 314 "sintatico.y"
                {}
#line 2095 "sintatico.tab.c"
    break;

  case 118: /* OperadorUnario: BITWISE_NOT  */
#line 315 "sintatico.y"
                      {}
#line 2101 "sintatico.tab.c"
    break;

  case 119: /* OperadorUnario: NOT  */
#line 316 "sintatico.y"
              {}
#line 2107 "sintatico.tab.c"
    break;

  case 120: /* ExpressaoPosFixa: ExpressaoPrimaria  */
#line 319 "sintatico.y"
                                    {}
#line 2113 "sintatico.tab.c"
    break;

  case 121: /* ExpressaoPosFixa: ExpressaoPosFixa ExpressaoPosFixaPrime  */
#line 320 "sintatico.y"
                                                 {}
#line 2119 "sintatico.tab.c"
    break;

  case 122: /* ExpressaoPosFixaPrime: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET  */
#line 323 "sintatico.y"
                                                                   {}
#line 2125 "sintatico.tab.c"
    break;

  case 123: /* ExpressaoPosFixaPrime: INC  */
#line 324 "sintatico.y"
              {}
#line 2131 "sintatico.tab.c"
    break;

  case 124: /* ExpressaoPosFixaPrime: DEC  */
#line 325 "sintatico.y"
              {}
#line 2137 "sintatico.tab.c"
    break;

  case 125: /* ExpressaoPosFixaPrime: L_PAREN OpExpressaoAtribuicaoIter R_PAREN  */
#line 326 "sintatico.y"
                                                    {}
#line 2143 "sintatico.tab.c"
    break;

  case 126: /* OpExpressaoAtribuicaoIter: ExpressaoAtribuicaoIter  */
#line 329 "sintatico.y"
                                                   {}
#line 2149 "sintatico.tab.c"
    break;

  case 127: /* OpExpressaoAtribuicaoIter: %empty  */
#line 330 "sintatico.y"
          {}
#line 2155 "sintatico.tab.c"
    break;

  case 128: /* ExpressaoAtribuicaoIter: ExpressaoAtribuicao ExpressaoAtribuicaoIterPrime  */
#line 333 "sintatico.y"
                                                                          {}
#line 2161 "sintatico.tab.c"
    break;

  case 129: /* ExpressaoAtribuicaoIterPrime: COMMA ExpressaoAtribuicaoIter  */
#line 336 "sintatico.y"
                                                            {}
#line 2167 "sintatico.tab.c"
    break;

  case 130: /* ExpressaoAtribuicaoIterPrime: %empty  */
#line 337 "sintatico.y"
          {}
#line 2173 "sintatico.tab.c"
    break;

  case 131: /* ExpressaoPrimaria: IDENTIFIER  */
#line 340 "sintatico.y"
                              {}
#line 2179 "sintatico.tab.c"
    break;

  case 132: /* ExpressaoPrimaria: Numero  */
#line 341 "sintatico.y"
                 {}
#line 2185 "sintatico.tab.c"
    break;

  case 133: /* ExpressaoPrimaria: CHARACTER  */
#line 342 "sintatico.y"
                    {}
#line 2191 "sintatico.tab.c"
    break;

  case 134: /* ExpressaoPrimaria: STRING  */
#line 343 "sintatico.y"
                 {}
#line 2197 "sintatico.tab.c"
    break;

  case 135: /* ExpressaoPrimaria: L_PAREN Expressao R_PAREN  */
#line 344 "sintatico.y"
                                    {}
#line 2203 "sintatico.tab.c"
    break;

  case 136: /* Numero: NUM_INTEGER  */
#line 347 "sintatico.y"
                    {}
#line 2209 "sintatico.tab.c"
    break;

  case 137: /* Numero: NUM_HEXA  */
#line 348 "sintatico.y"
                   {}
#line 2215 "sintatico.tab.c"
    break;

  case 138: /* Numero: NUM_OCTAL  */
#line 349 "sintatico.y"
                    {}
#line 2221 "sintatico.tab.c"
    break;


#line 2225 "sintatico.tab.c"

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

#line 352 "sintatico.y"


void yyerror(char *s){
	int columnError = coluna-((int)strlen(yytext));
	printf("error:syntax:%d:%d: %s\n", linha, columnError, yytext);
	printf("%s", yytext);
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
