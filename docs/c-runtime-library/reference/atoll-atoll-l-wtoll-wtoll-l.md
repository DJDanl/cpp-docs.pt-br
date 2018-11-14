---
title: atoll, _atoll_l, _wtoll, _wtoll_l
ms.date: 11/04/2016
apiname:
- _wtoll
- _atoll_l
- _wtoll_l
- atoll
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
- _tstoll_l
- _wtoll
- _atoll_l
- _ttoll
- _tstoll
- _wtoll_l
- atoll
helpviewer_keywords:
- atoll function
- _wtoll_l function
- _wtoll function
- _atoll_l function
ms.assetid: 5e85fcac-b351-4882-bff2-6e7c469b7fa8
ms.openlocfilehash: 7933b3e25185b5abdbd10c1b3fd616742bb28f92
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51521564"
---
# <a name="atoll-atolll-wtoll-wtolll"></a>atoll, _atoll_l, _wtoll, _wtoll_l

Converte uma cadeia de caracteres para um **longo** **longo** inteiro.

## <a name="syntax"></a>Sintaxe

```C
long long atoll(
   const char *str
);
long long _wtoll(
   const wchar_t *str
);
long long _atoll_l(
   const char *str,
   _locale_t locale
);
long long _wtoll_l(
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

Cada função retorna o **longo** **longo** valor é produzido Interpretando os caracteres de entrada como um número. O valor de retorno **Atol** é 0 se a entrada não pode ser convertida em um valor desse tipo.

Estouro com grandes valores inteiros positivos **Atol** retorna **LLONG_MAX**, e para estouro com grandes valores inteiros negativos, ele retorna **LLONG_MIN**.

Em todos os casos de fora do intervalo, **errno** é definido como **ERANGE**. Se o parâmetro passado for **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornam 0.

## <a name="remarks"></a>Comentários

Essas funções convertem uma cadeia de caracteres para um **longo** **longo** valor inteiro.

A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. A função para de ler a cadeia de caracteres de entrada no primeiro caractere que não consegue reconhecer como parte de um número. Esse caractere pode ser o caractere nulo ('\0' ou '\0' L) que encerra a cadeia de caracteres.

O *str* argumento **Atol** tem a seguinte forma:

> [*espaço em branco*] [*sinal*] [*dígitos*]

Um *espaço em branco* consiste em caracteres de espaço ou tabulação, que são ignorados; *sinal* é um sinal de mais (+) ou menos (-); e *dígitos* são um ou mais dígitos.

**wtoll** é idêntica à **Atol** exceto que assume uma cadeia de caracteres largos como um parâmetro.

As versões dessas funções que têm o **l** sufixo são idênticas às versões que não têm, exceto que usarem o parâmetro de localidade passado em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tstoll**|**atoll**|**atoll**|**_wtoll**|
|**_tstoll_l**|**_atoll_l**|**_atoll_l**|**_wtoll_l**|
|**_ttoll**|**_atoll**|**_atoll**|**_wtoll**|

## <a name="requirements"></a>Requisitos

|Rotinas|Cabeçalho necessário|
|--------------|---------------------|
|**Atol**, **atoll_l**|\<stdlib.h>|
|**wtoll**, **wtoll_l**|\<stdlib.h> ou \<wchar.h>|

## <a name="example"></a>Exemplo

Esse programa mostra como usar o **Atol** funções para converter números armazenados como cadeias de caracteres para valores numéricos.

```C
// crt_atoll.c
// Build with: cl /W4 /Tc crt_atoll.c
// This program shows how to use the atoll
// functions to convert numbers stored as
// strings to numeric values.
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    char *str = NULL;
    long long value = 0;

    // An example of the atoll function
    // with leading and trailing white spaces.
    str = "  -27182818284 ";
    value = atoll(str);
    printf("Function: atoll(\"%s\") = %lld\n", str, value);

    // Another example of the atoll function
    // with an arbitrary decimal point.
    str = "314127.64";
    value = atoll(str);
    printf("Function: atoll(\"%s\") = %lld\n", str, value);

    // Another example of the atoll function
    // with an overflow condition occurring.
    str = "3336402735171707160320";
    value = atoll(str);
    printf("Function: atoll(\"%s\") = %lld\n", str, value);
    if (errno == ERANGE)
    {
       printf("Overflow condition occurred.\n");
    }
}
```

```Output
Function: atoll("  -27182818284 ") = -27182818284
Function: atoll("314127.64") = 314127
Function: atoll("3336402735171707160320") = 9223372036854775807
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
