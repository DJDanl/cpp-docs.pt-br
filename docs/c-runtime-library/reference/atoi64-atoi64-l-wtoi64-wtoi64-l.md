---
title: _atoi64, _atoi64_l, _wtoi64, _wtoi64_l
ms.date: 4/2/2020
api_name:
- _atoi64_l
- _wtoi64
- _atoi64
- _wtoi64_l
- _o__atoi64
- _o__atoi64_l
- _o__wtoi64
- _o__wtoi64_l
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
- _atoi64
- _tstoi64
- _ttoi64
- wtoi64
- _tstoi64_l
- atoi64
- _wtoi64_l
- _wtoi64
- wtoi64_l
- _atoi64_l
- atoi64_l
helpviewer_keywords:
- tstoi64 function
- wtoi64 function
- atoi64_l function
- _ttoi64 function
- string conversion, to integers
- wtoi64_l function
- atoi64 function
- _tstoi64 function
- _atoi64_l function
- _wtoi64_l function
- ttoi64 function
- _wtoi64 function
- _atoi64 function
ms.assetid: 2c3e30fd-545d-4222-8364-0c5905df9526
ms.openlocfilehash: 103b100b293ff183dd89f3e7c2f291f9d49519e6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348825"
---
# <a name="_atoi64-_atoi64_l-_wtoi64-_wtoi64_l"></a>_atoi64, _atoi64_l, _wtoi64, _wtoi64_l

Converte uma cadeia de caracteres em um inteiro de 64 bits.

## <a name="syntax"></a>Sintaxe

```C
__int64 _atoi64(
   const char *str
);
__int64 _wtoi64(
   const wchar_t *str
);
__int64 _atoi64_l(
   const char *str,
   _locale_t locale
);
__int64 _wtoi64_l(
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

Cada função retorna o **valor __int64** produzido interpretando os caracteres de entrada como um número. O valor de retorno é 0 para **_atoi64** se a entrada não puder ser convertida em um valor desse tipo.

No caso de transbordamento com grandes valores integrais positivos, **_atoi64** retorna **I64_MAX** e **I64_MIN** no caso de transbordamento com grandes valores integrais negativos.

Em todos os casos fora de alcance, **errno** é definido como **ERANGE**. Se o parâmetro passado for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam 0.

## <a name="remarks"></a>Comentários

Essas funções convertem uma cadeia de caracteres em um valor inteiro de 64 bits.

A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. A função para de ler a cadeia de caracteres de entrada no primeiro caractere que não consegue reconhecer como parte de um número. Esse caractere pode ser o caractere nulo ('\0' ou L'\0') que encerra a cadeia de caracteres.

O argumento *str* para **_atoi64** tem a seguinte forma:

> [*espaço em branco*] [*sinal]* [*dígitos*]

Um *espaço em branco* consiste em caracteres de espaço ou guia, que são ignorados; *sinal* é mais (+) ou menos (-); e *os dígitos* são um ou mais dígitos.

**_wtoi64** é idêntica ao **_atoi64** exceto que é preciso uma seqüência de caracteres larga como parâmetro.

As versões dessas funções com o **sufixo _l** são idênticas, exceto que eles usam o parâmetro local passado em vez do local atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tstoi64**|**_atoi64**|**_atoi64**|**_wtoi64**|
|**_ttoi64**|**_atoi64**|**_atoi64**|**_wtoi64**|

## <a name="requirements"></a>Requisitos

|Rotinas|Cabeçalho necessário|
|--------------|---------------------|
|**_atoi64** **_atoi64_l**|\<stdlib.h>|
|**_wtoi64** **_wtoi64_l.**|\<stdlib.h> ou \<wchar.h>|

## <a name="example"></a>Exemplo

Este programa mostra como os números armazenados como strings podem ser convertidos em valores numéricos usando as funções **_atoi64.**

```C
// crt_atoi64.c
// This program shows how numbers stored as
// strings can be converted to numeric values
// using the _atoi64 functions.
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main( void )
{
    char    *str = NULL;
    __int64 value = 0;

    // An example of the _atoi64 function
    // with leading and trailing white spaces.
    str = "  -2309 ";
    value = _atoi64( str );
    printf( "Function: _atoi64( \"%s\" ) = %d\n", str, value );

    // Another example of the _atoi64 function
    // with an arbitrary decimal point.
    str = "314127.64";
    value = _atoi64( str );
    printf( "Function: _atoi64( \"%s\" ) = %d\n", str, value );

    // Another example of the _atoi64 function
    // with an overflow condition occurring.
    str = "3336402735171707160320";
    value = _atoi64( str );
    printf( "Function: _atoi64( \"%s\" ) = %d\n", str, value );
    if (errno == ERANGE)
    {
       printf("Overflow condition occurred.\n");
    }
}
```

```Output
Function: _atoi64( "  -2309 " ) = -2309
Function: _atoi64( "314127.64" ) = 314127
Function: _atoi64( "3336402735171707160320" ) = -1
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
