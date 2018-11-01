---
title: _atoi64, _atoi64_l, _wtoi64, _wtoi64_l
ms.date: 11/04/2016
apiname:
- _atoi64_l
- _wtoi64
- _atoi64
- _wtoi64_l
apilocation:
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
apitype: DLLExport
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
ms.openlocfilehash: c80480be8895db6afe499d5426b91dcde786d654
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515473"
---
# <a name="atoi64-atoi64l-wtoi64-wtoi64l"></a>_atoi64, _atoi64_l, _wtoi64, _wtoi64_l

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

*str*<br/>
Cadeia de caracteres a ser convertida.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada função retorna o **__int64** valor produzido Interpretando os caracteres de entrada como um número. O valor de retorno é 0 para **_atoi64** se a entrada não pode ser convertida em um valor desse tipo.

No caso de estouro com grandes valores inteiros positivos **_atoi64** retorna **I64_MAX** e **I64_MIN** no caso de estouro com grandes valores inteiros negativos.

Em todos os casos de fora do intervalo, **errno** é definido como **ERANGE**. Se o parâmetro passado é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornam 0.

## <a name="remarks"></a>Comentários

Essas funções convertem uma cadeia de caracteres em um valor inteiro de 64 bits.

A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. A função para de ler a cadeia de caracteres de entrada no primeiro caractere que não consegue reconhecer como parte de um número. Esse caractere pode ser o caractere nulo ('\0' ou L'\0') que encerra a cadeia de caracteres.

O *str* argumento **_atoi64** tem a seguinte forma:

> [*espaço em branco*] [*sinal*] [*dígitos*]

Um *espaço em branco* consiste em caracteres de espaço ou tabulação, que são ignorados; *sinal* é um sinal de mais (+) ou menos (-); e *dígitos* são um ou mais dígitos.

**_wtoi64** é idêntica à **_atoi64** exceto que assume uma cadeia de caracteres largos como um parâmetro.

As versões dessas funções com o **l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tstoi64**|**_atoi64**|**_atoi64**|**_wtoi64**|
|**_ttoi64**|**_atoi64**|**_atoi64**|**_wtoi64**|

## <a name="requirements"></a>Requisitos

|Rotinas|Cabeçalho necessário|
|--------------|---------------------|
|**_atoi64**, **_atoi64_l**|\<stdlib.h>|
|**_wtoi64**, **_wtoi64_l**|\<stdlib.h> ou \<wchar.h>|

## <a name="example"></a>Exemplo

Esse programa mostra como os números armazenados como cadeias de caracteres podem ser convertidos em valores numéricos usando o **_atoi64** funções.

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

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[_ecvt](ecvt.md)<br/>
[_fcvt](fcvt.md)<br/>
[_gcvt](gcvt.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[_atodbl, _atodbl_l, _atoldbl, _atoldbl_l, _atoflt, _atoflt_l](atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)<br/>
