---
title: _mbclen, mblen, _mblen_l, _mbclen_l
description: Descreve as funções Microsoft C Runtime Library (CRT) _mbclen, mblen, _mblen_l e _mbclen_l.
ms.date: 01/08/2020
api_name:
- _mbclen
- mblen
- _mblen_l
- _mbclen_l
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mblen
- ftclen
- _mbclen
- _mbclen_l
- tclen
- _ftclen
- _tclen
- mbclen
helpviewer_keywords:
- tclen function
- _mblen_l function
- _tclen function
- mblen_l function
- _mbclen function
- _mbclen_l function
- mbclen function
- mblen function
ms.assetid: d5eb92a0-b7a3-464a-aaf7-9890a8e3ed70
ms.openlocfilehash: 4676d850448af386a5aface69f616a4ac6f85cbf
ms.sourcegitcommit: 7bd3567fc6a0e7124aab51cad63bbdb44a99a848
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/08/2020
ms.locfileid: "75755073"
---
# <a name="_mbclen-mblen-_mblen_l-_mbclen_l"></a>_mbclen, mblen, _mblen_l, _mbclen_l

Obtém o comprimento e determina a validade de um caractere multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
size_t _mbclen(
   const unsigned char *c
);
size_t _mbclen_l(
   unsigned char const* c,
   _locale_t locale
);
int mblen(
   const char *mbstr,
   size_t count
);
int _mblen_l(
   const char *mbstr,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

\ de *c*
Caractere multibyte.

\ *mbstr*
Endereço de uma sequência de bytes de caracteres multibyte.

*contagem*\
O número de bytes a serem verificados.

\ de *localidade*
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**_mbclen** e **_mbclen_l** retornam 1 ou 2, de acordo com o comprimento do caractere de multibyte *c*. As funções sempre retornam 1 para UTF-8, independentemente de *c* ser multibyte ou não. Não há nenhum retorno de erro para **_mbclen**.

Se *mbstr* não for **nulo**, **mblen** e **_mblen_l** retornará o comprimento, em bytes, do caractere multibyte. As funções **mblen** e **_mblen_l** funcionam corretamente em UTF-8 e podem retornar um valor entre 1 e 3. Quando *mbstr* é **nulo** (ou aponta para o caractere nulo de caractere largo), **mblen** e **_mblen_l** retornam 0. O objeto que *mbstr* aponta deve formar um caractere multibyte válido dentro dos primeiros caracteres de *contagem* , ou **mblen** e **_mblen_l** retornar-1.

## <a name="remarks"></a>Comentários

A função **_mbclen** retorna o comprimento, em bytes, do caractere multibyte *c*. Se *c* não apontar para o byte de Lead de um caractere multibyte (conforme determinado por uma chamada implícita para [_ismbblead](ismbblead-ismbblead-l.md), o resultado de **_mbclen** será imprevisível.

**mblen** retorna o comprimento em bytes de *mbstr* se for um caractere multibyte válido. Ele também determina a validade do caractere multibyte associado à página de código. **mblen** examina a *contagem* ou menos bytes contidos em *mbstr*, mas não mais de **MB_CUR_MAX** bytes.

O valor de saída é afetado pela configuração de categoria de **LC_CTYPE** da localidade. As versões dessas funções sem o sufixo **_L** usam a localidade atual para esse comportamento dependente de localidade. O **_L** versões sufixadas se comportam da mesma forma, mas usam o parâmetro de localidade passado em vez disso. Para obter mais informações, consulte [setlocale](setlocale-wsetlocale.md) e [locale](../../c-runtime-library/locale.md).

**_mbclen**, **_mblen_l**e **_mbclen_l** são específicos da Microsoft, não fazem parte da biblioteca C padrão. Não recomendamos que você os use onde desejar código portátil. Para compatibilidade com C padrão, use **mblen** ou **mbrlen** em vez disso.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tclen**|É mapeado para um macro ou uma função embutida|**_mbclen**|É mapeado para um macro ou uma função embutida|

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbclen**|\<mbstring.h>|
|**mblen**|\<stdlib.h>|
|**_mblen_l**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_mblen.c
/* illustrates the behavior of the mblen function
*/

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
    int      i;
    char    *pmbc = (char *)malloc( sizeof( char ) );
    wchar_t  wc   = L'a';

    printf( "Convert wide character to multibyte character:\n" );
    wctomb_s( &i, pmbc, sizeof(char), wc );
    printf( "   Characters converted: %u\n", i );
    printf( "   Multibyte character: %x\n\n", *pmbc );

    i = mblen( pmbc, MB_CUR_MAX );
    printf( "Length in bytes of multibyte character %x: %u\n", *pmbc, i );

    pmbc = NULL;
    i = mblen( pmbc, MB_CUR_MAX );
    printf( "Length in bytes of NULL multibyte character %x: %u\n", pmbc, i );
}
```

```Output
Convert wide character to multibyte character:
   Characters converted: 1
   Multibyte character: 61

Length in bytes of multibyte character 61: 1
Length in bytes of NULL multibyte character 0: 0
```

## <a name="see-also"></a>Veja também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)\
[Localidade](../../c-runtime-library/locale.md)\
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)\
[_mbccpy, _mbccpy_l](mbccpy-mbccpy-l.md)\
\ [mbrlen](mbrlen.md)
[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)
