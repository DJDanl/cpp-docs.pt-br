---
title: _set_output_format
ms.date: 11/04/2016
api_name:
- _set_output_format
api_location:
- msvcrt.dll
- msvcr120.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr110.dll
- msvcr80.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_output_format
- _set_output_format
helpviewer_keywords:
- _TWO_DIGIT_EXPONENT constant
- output formatting
- TWO_DIGIT_EXPONENT constant
- _set_output_format function
- set_output_format function
ms.assetid: 1cb48df8-44b4-4400-bd27-287831d6b3ff
ms.openlocfilehash: c855df4c29a53fd898b920f6446afe4e568ba5bb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360915"
---
# <a name="_set_output_format"></a>_set_output_format

Personaliza os formatos de saída usados pelas funções de E/S formatadas.

> [!IMPORTANT]
> Essa função está obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.

## <a name="syntax"></a>Sintaxe

```
unsigned int _set_output_format(
   unsigned int format
);
```

#### <a name="parameters"></a>Parâmetros

*format*<br/>
[in] Um valor que representa o formato a ser usado.

## <a name="return-value"></a>Valor retornado

O formato de saída anterior.

## <a name="remarks"></a>Comentários

`_set_output_format` é usado para configurar a saída das funções de E/S formatadas como [printf_s](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md). No momento, a única convenção de formatação que pode ser alterada por essa função é o número de dígitos exibidos nos expoentes na saída de números de ponto flutuante.

Por padrão, a saída de números de ponto flutuante por funções como `printf_s`, `wprintf_s` e funções relacionadas na biblioteca C padrão do Visual C++ imprime três dígitos para o expoente, mesmo que os três dígitos não sejam necessários para representar o valor do expoente. Zeros são usados para preencher o valor fazendo com que ele passe a ter três dígitos. `_set_output_format` permite que você altere esse comportamento de modo que apenas dois dígitos são impressos no expoente, a menos que um terceiro dígito seja exigido pelo tamanho do expoente.

Para habilitar os expoentes de dois dígitos, chame essa função com o parâmetro `_TWO_DIGIT_EXPONENT`, conforme mostrado no exemplo. Para desabilitar expoentes de dois dígitos, chame essa função com um argumento de 0.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_set_output_format`|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.

## <a name="example"></a>Exemplo

```C
// crt_set_output_format.c
#include <stdio.h>

void printvalues(double x, double y)
{
   printf_s("%11.4e %11.4e\n", x, y);
   printf_s("%11.4E %11.4E\n", x, y);
   printf_s("%11.4g %11.4g\n", x, y);
   printf_s("%11.4G %11.4G\n", x, y);
}

int main()
{
   double x = 1.211E-5;
   double y = 2.3056E-112;
   unsigned int old_exponent_format;

   // Use the default format
   printvalues(x, y);

   // Enable two-digit exponent format
   old_exponent_format = _set_output_format(_TWO_DIGIT_EXPONENT);

   printvalues(x, y);

   // Disable two-digit exponent format
   _set_output_format( old_exponent_format );

   printvalues(x, y);
}
```

```Output
1.2110e-005 2.3056e-112
1.2110E-005 2.3056E-112
1.211e-005  2.306e-112
1.211E-005  2.306E-112
1.2110e-05 2.3056e-112
1.2110E-05 2.3056E-112
  1.211e-05  2.306e-112
  1.211E-05  2.306E-112
1.2110e-005 2.3056e-112
1.2110E-005 2.3056E-112
1.211e-005  2.306e-112
1.211E-005  2.306E-112
```

## <a name="see-also"></a>Confira também

[printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)<br/>
[_get_output_format](../c-runtime-library/get-output-format.md)
