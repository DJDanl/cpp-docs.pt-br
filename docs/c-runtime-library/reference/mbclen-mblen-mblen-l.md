---
title: _mbclen, mblen, _mblen_l, _mbclen_l
description: Descreve as funções de _mbclen, mblen, _mblen_l e _mbclen_l da Microsoft C Runtime Library (CRT).
ms.date: 4/2/2020
api_name:
- _mbclen
- mblen
- _mblen_l
- _mbclen_l
- _o__mbclen
- _o__mbclen_l
- _o__mblen_l
- _o_mblen
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 76e8771898d8baa65f275304a9aefdcaeeb5b3bd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341118"
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

*C*\
Caractere multibyte.

*Mbstr*\
Endereço de uma sequência de bytes de caracteres multibyte.

*Contar*\
O número de bytes a serem verificados.

*Localidade*\
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_mbclen** e **_mbclen_l** retornar 1 ou 2, de acordo com o comprimento do caractere multibyte *c*. As funções sempre retornam 1 para UTF-8, seja *c* é multibyte ou não. Não há retorno de erro para **_mbclen.**

Se *mbstr* não for **NULL**, **mblen** e **_mblen_l** retornar o comprimento, em bytes, do caractere multibyte. As funções **mblen** e **_mblen_l** funcionam corretamente no UTF-8, podendo retornar um valor entre 1 e 3. Quando *mbstr* é **NULL** (ou aponta para o caractere nulo de caractere sumido de caractere s), **mblen** e **_mblen_l** retorno 0. O objeto que *mbstr* aponta deve formar um caractere multibyte válido dentro dos caracteres da primeira *contagem,* ou **mblen** e **_mblen_l** retorno -1.

## <a name="remarks"></a>Comentários

A função **_mbclen** retorna o comprimento, em bytes, do caractere multibyte *c*. Se *c* não aponta para o byte principal de um caractere multibyte (como determinado por uma chamada implícita para [_ismbblead,](ismbblead-ismbblead-l.md)o resultado de **_mbclen** é imprevisível.

**mblen** retorna o comprimento em bytes de *mbstr* se for um caractere multibyte válido. Também determina a validade de caracteres multibytes associada à página de código. **mblen** examina *a contagem* ou menos bytes contidos em *mbstr,* mas não mais do que **MB_CUR_MAX** bytes.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** do local. As versões dessas funções sem o **sufixo _l** usam a localidade atual para este comportamento dependente da localidade. As **_l** versões sufixadas se comportam da mesma forma, mas usam o parâmetro local passado em seu lugar. Para obter mais informações, consulte [setlocale](setlocale-wsetlocale.md) e [Locale](../../c-runtime-library/locale.md).

**_mbclen**, **_mblen_l**e **_mbclen_l** são específicos da Microsoft, não fazem parte da biblioteca Padrão C. Não recomendamos usá-los onde quiser código portátil. Para compatibilidade padrão C, use **mblen** ou **mbrlen** em vez disso.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tclen**|É mapeado para um macro ou uma função embutida|**_mbclen**|É mapeado para um macro ou uma função embutida|

## <a name="requirements"></a>Requisitos

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

## <a name="see-also"></a>Confira também

[Classificação de Caracteres](../../c-runtime-library/character-classification.md)\
[Localidade](../../c-runtime-library/locale.md)\
[Interpretação de sequências de caracteres multibytes](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)\
[_mbccpy _mbccpy_l.](mbccpy-mbccpy-l.md)\
[Mbrlen](mbrlen.md)\
[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)
