---
title: Rotinas is, isw
ms.date: 11/04/2016
api_location:
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110.dll
- msvcr120.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- isw
- is
helpviewer_keywords:
- is routines
- isw routines
ms.assetid: 1e171a57-2cde-41f6-a75f-a080fa3c12e5
ms.openlocfilehash: 632bd371f8a6da4b57eeb1ce88e2a37eb6923355
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839381"
---
# <a name="is-isw-routines"></a>Rotinas is, isw

:::row:::
   :::column span="":::
      [isalnum, iswalnum, _isalnum_l, _iswalnum_l](../c-runtime-library/reference/isalnum-iswalnum-isalnum-l-iswalnum-l.md)\
      [isalpha, iswalpha, _isalpha_l, _iswalpha_l](../c-runtime-library/reference/isalpha-iswalpha-isalpha-l-iswalpha-l.md)\
      [isascii, __isascii, iswascii](../c-runtime-library/reference/isascii-isascii-iswascii.md)\
      [IsBlank, iswblank, _isblank_l, _iswblank_l](../c-runtime-library/reference/isblank-iswblank-isblank-l-iswblank-l.md)\
      [iscntrl, iswcntrl, _iscntrl_l, _iswcntrl_l](../c-runtime-library/reference/iscntrl-iswcntrl-iscntrl-l-iswcntrl-l.md)\
      [iscsym, iscsymf, __iscsym, \_ _iswcsym, \_ _iscsymf, \_ _iswcsymf, _iscsym_l, _iswcsym_l, _iscsymf_l, _iswcsymf_l](../c-runtime-library/reference/iscsym-functions.md)\
      [_isctype, iswctype, _isctype_l, _iswctype_l](../c-runtime-library/reference/isctype-iswctype-isctype-l-iswctype-l.md)\
      [isdigit, iswdigit, _isdigit_l, _iswdigit_l](../c-runtime-library/reference/isdigit-iswdigit-isdigit-l-iswdigit-l.md)
   :::column-end:::
   :::column span="":::
      [isgraph, iswgraph, _isgraph_l, _iswgraph_l](../c-runtime-library/reference/isgraph-iswgraph-isgraph-l-iswgraph-l.md)\
      [isleadbyte, _isleadbyte_l](../c-runtime-library/reference/isleadbyte-isleadbyte-l.md)\
      [islow, iswlower, _islower_l, _iswlower_l](../c-runtime-library/reference/islower-iswlower-islower-l-iswlower-l.md)\
      [isprint, iswprint, _isprint_l, _iswprint_l](../c-runtime-library/reference/isprint-iswprint-isprint-l-iswprint-l.md)\
      [ispunct, iswpunct, _ispunct_l, _iswpunct_l](../c-runtime-library/reference/ispunct-iswpunct-ispunct-l-iswpunct-l.md)\
      [isspace, iswspace, _isspace_l, _iswspace_l](../c-runtime-library/reference/isspace-iswspace-isspace-l-iswspace-l.md)\
      [IsUpper, _isupper_l, iswupper, _iswupper_l](../c-runtime-library/reference/isupper-isupper-l-iswupper-iswupper-l.md)\
      [isxdigit, iswxdigit, _isxdigit_l, _iswxdigit_l](../c-runtime-library/reference/isxdigit-iswxdigit-isxdigit-l-iswxdigit-l.md)
   :::column-end:::
:::row-end:::

## <a name="remarks"></a>Comentários

Essas rotinas testam caracteres com relação a condições especificadas.

As rotinas **is** produzem resultados significativos para qualquer argumento inteiro de -1 (`EOF`) a **UCHAR_MAX** (0xFF), inclusivo. O tipo de argumento esperado é **`int`** .

> [!CAUTION]
> Para as rotinas **is** , a passagem de um argumento do tipo **`char`** pode gerar resultados imprevisíveis. Um caractere de byte único SBCS ou MBCS de **`char`** um tipo com um valor maior que 0x7F é negativo. Se um **`char`** for passado, o compilador poderá converter o valor em um **`signed int`** ou um **`signed long`** . Esse valor pode ter sua assinatura estendida pelo compilador, com resultados inesperados.

As rotinas **isw** produzem resultados significativos para qualquer valor inteiro de - 1 (**WEOF**) a 0xFFFF, inclusivo. O tipo de dados **wint_t** é definido em WCHAR. H como um **`unsigned short`** ; ele pode conter qualquer caractere largo ou o valor de**WEOF**(fim do arquivo) de caractere largo.

O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar.

Na localidade "C", as condições de teste para as rotinas **is** são as seguintes:

`isalnum`<br/>
Alfanuméricos (A – Z, a – z ou 0 – 9).

`isalpha`<br/>
Alfabéticos (A – Z ou a – z).

`__isascii`<br/>
Caracteres ASCII (0x00 – 0x7F).

`isblank`<br/>
Tabulação horizontal ou caractere de espaço (0x09 ou 0x20).

`iscntrl`<br/>
Caractere de controle (0x00 – 0x1F ou 0x7F).

`__iscsym`<br/>
Letra, sublinhado ou dígito.

`__iscsymf`<br/>
Letra ou sublinhado.

`isdigit`<br/>
Dígito decimal (0 – 9).

`isgraph`<br/>
Caractere imprimível, exceto espaço ( ).

`islower`<br/>
Letra minúscula (a – z).

`isprint`<br/>
Caracteres imprimíveis, incluindo espaço (0x20 – 0x7E).

`ispunct`<br/>
Caractere de pontuação.

`isspace`<br/>
Caractere de espaço em branco (0x09 – 0x0D ou 0x20).

`isupper`<br/>
Letra maiúscula (A – Z).

`isxdigit`<br/>
Dígito hexadecimal (A – F, a – f ou 0 – 9).

Para as rotinas **isw**, o resultado do teste para a condição especificada é independente da localidade. As condições de teste para as funções **isw** são as seguintes:

`iswalnum`<br/>
`iswalpha` ou `iswdigit`.

`iswalpha`<br/>
Qualquer caractere largo que faça parte de um conjunto definido pela implementação para o qual nenhum dos `iswcntrl`, `iswdigit`, `iswpunct` ou `iswspace` é diferente de zero. `iswalpha` retorna não zero somente para caracteres largos para os quais `iswupper` ou `iswlower` é diferente de zero.

`iswascii`<br/>
Representação de caractere largo de caractere ASCII (0x0000 – 0x007F).

`iswblank`<br/>
Caracteres largos que correspondem ao caractere de espaço padrão, ou que seja de um conjunto de caracteres largos definidos pela implementação para os quais `iswalnum` é false. Os caracteres em branco padrão são espaço (L' ') e tabulação horizontal (L'\t').

`iswcntrl`<br/>
Caractere largo de controle.

`__iswcsym`<br/>
Qualquer caractere largo para o qual `isalnum` seja true, ou o caractere '_'.

`__iswcsymf`<br/>
Qualquer caractere largo para o qual `iswalpha` seja true, ou o caractere '_'.

`iswctype`<br/>
O caractere tem uma propriedade especificada pelo argumento `desc`. Para cada valor válido do argumento `desc` de `iswctype`, há uma rotina de classificação de caractere largo equivalente, conforme mostra a tabela a seguir:

### <a name="equivalence-of-iswctypec-desc-to-other-isw-testing-routines"></a>Equivalência de iswctype(c, desc) com outras rotinas de teste de isw

|Valor do argumento *desc*|iswctype( *c, desc* ) equivalente|
|------------------------------|----------------------------------------|
|**_ALPHA**|**iswalpha (** `c` **)**|
|**_ALPHA** &#124; **_DIGIT**|**iswalnum(** `c` **)**|
|**_BLANK**|**iswblank (** `c` **)**|
|**_CONTROL**|**iswcntrl(** `c` **)**|
|**_DIGIT**|**iswdigit(** `c` **)**|
|**_ALPHA** &#124; **_DIGIT** &#124; **_PUNCT**|**iswgraph (** `c` **)**|
|**_LOWER**|**iswlower(** `c` **)**|
|**_ALPHA** &#124; **_BLANK** &#124; **_DIGIT** &#124; **_PUNCT**|**iswprint (** `c` **)**|
|**_PUNCT**|**iswpunct (** `c` **)**|
|**_BLANK**|**iswblank (** `c` **)**|
|**_SPACE**|**iswspace(** `c` **)**|
|**_UPPER**|**iswupper(** `c` **)**|
|**_HEX**|**iswxdigit (** `c` **)**|

`iswdigit`<br/>
Caractere largo correspondente a um caractere de dígito decimal.

`iswgraph`<br/>
Caractere largo imprimível exceto caractere largo de espaço (L' ').

`iswlower`<br/>
Letra minúscula, ou uma que faça parte de um conjunto de caracteres largos definidos pela implementação para o qual nenhum dos `iswcntrl`, `iswdigit`, `iswpunct` ou `iswspace` é diferente de zero. `iswlower` retorna zero somente para caracteres largos que correspondem a letras minúsculas.

`iswprint`<br/>
Caractere largo imprimível, incluindo caractere de espaço largo (L' ').

`iswpunct`<br/>
Caractere largo imprimível que não é um caractere largo de espaço (L' ') ou um caractere largo para o qual `iswalnum` é diferente de zero.

`iswspace`<br/>
Caracteres largo que corresponde ao caractere de espaço em branco padrão, ou que seja de um conjunto de caracteres largos definido pela implementação para o qual `iswalnum` é false. Os caracteres de espaço em branco padrão são: espaço (L' '), avanço de página (L'\f'), nova linha (L'\n'), retorno de carro (L'\r'), tabulação horizontal (L'\t') e tabulação vertical (L'\v').

`iswupper`<br/>
Caractere largo maiúsculo ou um que faça parte de um conjunto de caracteres largos definidos pela implementação para o qual nenhum dos `iswcntrl`, `iswdigit`, `iswpunct` ou `iswspace` é diferente de zero. `iswupper` retorna não zero somente para caracteres largos que correspondem a caracteres maiúsculos.

`iswxdigit`<br/>
Caractere largo que corresponde a um caractere de dígito hexadecimal.

## <a name="example"></a>Exemplo

```C
// crt_isfam.c
/* This program tests all characters between 0x0
* and 0x7F, then displays each character with abbreviations
* for the character-type codes that apply.
*/

#include <stdio.h>
#include <ctype.h>

int main( void )
{
   int ch;
   for( ch = 0; ch <= 0x7F; ch++ )
   {
      printf( "%.2x  ", ch );
      printf( " %c", isprint( ch )  ? ch   : ' ' );
      printf( "%4s", isalnum( ch )  ? "AN" : "" );
      printf( "%3s", isalpha( ch )  ? "A"  : "" );
      printf( "%3s", __isascii( ch )  ? "AS" : "" );
      printf( "%3s", iscntrl( ch )  ? "C"  : "" );
      printf( "%3s", __iscsym( ch )  ? "CS "  : "" );
      printf( "%3s", __iscsymf( ch )  ? "CSF"  : "" );
      printf( "%3s", isdigit( ch )  ? "D"  : "" );
      printf( "%3s", isgraph( ch )  ? "G"  : "" );
      printf( "%3s", islower( ch )  ? "L"  : "" );
      printf( "%3s", ispunct( ch )  ? "PU" : "" );
      printf( "%3s", isspace( ch )  ? "S"  : "" );
      printf( "%3s", isprint( ch )  ? "PR" : "" );
      printf( "%3s", isupper( ch )  ? "U"  : "" );
      printf( "%3s", isxdigit( ch ) ? "X"  : "" );
      printf( ".\n" );
   }
}
```

## <a name="output"></a>Saída

```Output
00            AS  C                              .
01            AS  C                              .
02            AS  C                              .
03            AS  C                              .
04            AS  C                              .
05            AS  C                              .
06            AS  C                              .
07            AS  C                              .
08            AS  C                              .
09            AS  C                    S         .
0a            AS  C                    S         .
0b            AS  C                    S         .
0c            AS  C                    S         .
0d            AS  C                    S         .
0e            AS  C                              .
0f            AS  C                              .
10            AS  C                              .
11            AS  C                              .
12            AS  C                              .
13            AS  C                              .
14            AS  C                              .
15            AS  C                              .
16            AS  C                              .
17            AS  C                              .
18            AS  C                              .
19            AS  C                              .
1a            AS  C                              .
1b            AS  C                              .
1c            AS  C                              .
1d            AS  C                              .
1e            AS  C                              .
1f            AS  C                              .
20            AS                       S PR      .
21   !        AS              G    PU    PR      .
22   "        AS              G    PU    PR      .
23   #        AS              G    PU    PR      .
24   $        AS              G    PU    PR      .
25   %        AS              G    PU    PR      .
26   &        AS              G    PU    PR      .
27   '        AS              G    PU    PR      .
28   (        AS              G    PU    PR      .
29   )        AS              G    PU    PR      .
2a   *        AS              G    PU    PR      .
2b   +        AS              G    PU    PR      .
2c   ,        AS              G    PU    PR      .
2d   -        AS              G    PU    PR      .
2e   .        AS              G    PU    PR      .
2f   /        AS              G    PU    PR      .
30   0  AN    AS   CS      D  G          PR     X.
31   1  AN    AS   CS      D  G          PR     X.
32   2  AN    AS   CS      D  G          PR     X.
33   3  AN    AS   CS      D  G          PR     X.
34   4  AN    AS   CS      D  G          PR     X.
35   5  AN    AS   CS      D  G          PR     X.
36   6  AN    AS   CS      D  G          PR     X.
37   7  AN    AS   CS      D  G          PR     X.
38   8  AN    AS   CS      D  G          PR     X.
39   9  AN    AS   CS      D  G          PR     X.
3a   :        AS              G    PU    PR      .
3b   ;        AS              G    PU    PR      .
3c   <        AS              G    PU    PR      .
3d   =        AS              G    PU    PR      .
3e   >        AS              G    PU    PR      .
3f   ?        AS              G    PU    PR      .
40   @        AS              G    PU    PR      .
41   A  AN  A AS   CS CSF     G          PR  U  X.
42   B  AN  A AS   CS CSF     G          PR  U  X.
43   C  AN  A AS   CS CSF     G          PR  U  X.
44   D  AN  A AS   CS CSF     G          PR  U  X.
45   E  AN  A AS   CS CSF     G          PR  U  X.
46   F  AN  A AS   CS CSF     G          PR  U  X.
47   G  AN  A AS   CS CSF     G          PR  U   .
48   H  AN  A AS   CS CSF     G          PR  U   .
49   I  AN  A AS   CS CSF     G          PR  U   .
4a   J  AN  A AS   CS CSF     G          PR  U   .
4b   K  AN  A AS   CS CSF     G          PR  U   .
4c   L  AN  A AS   CS CSF     G          PR  U   .
4d   M  AN  A AS   CS CSF     G          PR  U   .
4e   N  AN  A AS   CS CSF     G          PR  U   .
4f   O  AN  A AS   CS CSF     G          PR  U   .
50   P  AN  A AS   CS CSF     G          PR  U   .
51   Q  AN  A AS   CS CSF     G          PR  U   .
52   R  AN  A AS   CS CSF     G          PR  U   .
53   S  AN  A AS   CS CSF     G          PR  U   .
54   T  AN  A AS   CS CSF     G          PR  U   .
55   U  AN  A AS   CS CSF     G          PR  U   .
56   V  AN  A AS   CS CSF     G          PR  U   .
57   W  AN  A AS   CS CSF     G          PR  U   .
58   X  AN  A AS   CS CSF     G          PR  U   .
59   Y  AN  A AS   CS CSF     G          PR  U   .
5a   Z  AN  A AS   CS CSF     G          PR  U   .
5b   [        AS              G    PU    PR      .
5c   \        AS              G    PU    PR      .
5d   ]        AS              G    PU    PR      .
5e   ^        AS              G    PU    PR      .
5f   _        AS   CS CSF     G    PU    PR      .
60   `        AS              G    PU    PR      .
61   a  AN  A AS   CS CSF     G  L       PR     X.
62   b  AN  A AS   CS CSF     G  L       PR     X.
63   c  AN  A AS   CS CSF     G  L       PR     X.
64   d  AN  A AS   CS CSF     G  L       PR     X.
65   e  AN  A AS   CS CSF     G  L       PR     X.
66   f  AN  A AS   CS CSF     G  L       PR     X.
67   g  AN  A AS   CS CSF     G  L       PR      .
68   h  AN  A AS   CS CSF     G  L       PR      .
69   i  AN  A AS   CS CSF     G  L       PR      .
6a   j  AN  A AS   CS CSF     G  L       PR      .
6b   k  AN  A AS   CS CSF     G  L       PR      .
6c   l  AN  A AS   CS CSF     G  L       PR      .
6d   m  AN  A AS   CS CSF     G  L       PR      .
6e   n  AN  A AS   CS CSF     G  L       PR      .
6f   o  AN  A AS   CS CSF     G  L       PR      .
70   p  AN  A AS   CS CSF     G  L       PR      .
71   q  AN  A AS   CS CSF     G  L       PR      .
72   r  AN  A AS   CS CSF     G  L       PR      .
73   s  AN  A AS   CS CSF     G  L       PR      .
74   t  AN  A AS   CS CSF     G  L       PR      .
75   u  AN  A AS   CS CSF     G  L       PR      .
76   v  AN  A AS   CS CSF     G  L       PR      .
77   w  AN  A AS   CS CSF     G  L       PR      .
78   x  AN  A AS   CS CSF     G  L       PR      .
79   y  AN  A AS   CS CSF     G  L       PR      .
7a   z  AN  A AS   CS CSF     G  L       PR      .
7b   {        AS              G    PU    PR      .
7c   |        AS              G    PU    PR      .
7d   }        AS              G    PU    PR      .
7e   ~        AS              G    PU    PR      .
7f            AS  C                              .
```

## <a name="see-also"></a>Confira também

[Classificação de caracteres](../c-runtime-library/character-classification.md)<br/>
[Localidade](../c-runtime-library/locale.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[para funções](../c-runtime-library/to-functions.md)
