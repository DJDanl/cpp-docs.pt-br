---
title: atol, _atol_l, _wtol, _wtol_l
ms.date: 4/2/2020
api_name:
- atol
- _wtol_l
- _wtol
- _atol_l
- _o__atol_l
- _o__wtol
- _o__wtol_l
- _o_atol
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
- api-ms-win-crt-convert-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _atol_l
- _ttol_l
- _tstol_l
- _tstol
- _wtol
- _ttol
- _wtol_l
helpviewer_keywords:
- tstol function
- atol function
- ttol function
- _atol_l function
- _tstol_l function
- string conversion, to integers
- _tstol function
- _ttol function
- _ttol_l function
- atol_l function
- wtol_l function
- _wtol_l function
- wtol function
- _wtol function
ms.assetid: cedfc21c-2d64-4e9c-bd04-bdf60b12db46
ms.openlocfilehash: 30f8375814259cac8c3d7216c636b69acbc7e90a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348752"
---
# <a name="atol-_atol_l-_wtol-_wtol_l"></a>atol, _atol_l, _wtol, _wtol_l

Converte uma cadeia de caracteres em um inteiro longo.

## <a name="syntax"></a>Sintaxe

```C
long atol(
   const char *str
);
long _atol_l(
   const char *str,
   _locale_t locale
);
long _wtol(
   const wchar_t *str
);
long _wtol_l(
   const wchar_t *str,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Cadeia de caracteres a ser convertida.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Cada função retorna o **longo** valor produzido interpretando os caracteres de entrada como um número. O valor de retorno é 0L para **atol** se a entrada não puder ser convertida em um valor desse tipo.

No caso de transbordamento com grandes valores integrais positivos, **o retorno da Atol** **LONG_MAX;** no caso de transbordamento com grandes valores integrais negativos, **LONG_MIN** é devolvido. Em todos os casos fora de alcance, **errno** é definido como **ERANGE**. Se o parâmetro passado for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam 0.

## <a name="remarks"></a>Comentários

Essas funções convertem uma seqüência de caracteres em um longo valor inteiro **(atol).**

A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. A função para de ler a cadeia de caracteres de entrada no primeiro caractere que não consegue reconhecer como parte de um número. Esse caractere pode ser o caractere nulo ('\0' ou L'\0') que encerra a cadeia de caracteres.

O argumento *str* para **atol** tem a seguinte forma:

> [*espaço em branco*] [*sinal]* [*dígitos*]]

Um *espaço em branco* consiste em caracteres de espaço ou guia, que são ignorados; *sinal* é mais (+) ou menos (-); e *os dígitos* são um ou mais dígitos.

**_wtol** é idêntico ao **atol,** exceto que é preciso uma seqüência de caracteres largo.

As versões dessas funções com o **sufixo _l** são idênticas, exceto que eles usam o parâmetro local passado em vez do local atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tstol**|**atol**|**atol**|**_wtol**|
|**_ttol**|**atol**|**atol**|**_wtol**|

## <a name="requirements"></a>Requisitos

|Rotinas|Cabeçalho necessário|
|--------------|---------------------|
|**atol**|\<stdlib.h>|
|**_atol_l,** **_wtol** **_wtol_l**|\<stdlib.h> e \<wchar.h>|

## <a name="example"></a>Exemplo

Este programa mostra como os números armazenados como strings podem ser convertidos em valores numéricos usando a função **atol.**

```C
// crt_atol.c
// This program shows how numbers stored as
// strings can be converted to numeric values
// using the atol functions.
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main( void )
{
    char    *str = NULL;
    long    value = 0;

    // An example of the atol function
    // with leading and trailing white spaces.
    str = "  -2309 ";
    value = atol( str );
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );

    // Another example of the atol function
    // with an arbitrary decimal point.
    str = "314127.64";
    value = atol( str );
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );

    // Another example of the atol function
    // with an overflow condition occurring.
    str = "3336402735171707160320";
    value = atol( str );
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );
    if (errno == ERANGE)
    {
       printf("Overflow condition occurred.\n");
    }
}
```

```Output
Function: atol( "  -2309 " ) = -2309
Function: atol( "314127.64" ) = 314127
Function: atol( "3336402735171707160320" ) = 2147483647
Overflow condition occurred.
```

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[_ecvt](ecvt.md)<br/>
[_fcvt](fcvt.md)<br/>
[_gcvt](gcvt.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[_atodbl, _atodbl_l, _atoldbl, _atoldbl_l, _atoflt, _atoflt_l](atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)<br/>
