---
title: _get_output_format
ms.date: 11/04/2016
api_name:
- _get_output_format
api_location:
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr80.dll
- msvcrt.dll
- msvcr90.dll
- msvcr120.dll
- msvcr110.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- get_output_format
- _get_output_format
helpviewer_keywords:
- output formatting
- get_output_format function
- _get_output_format function
ms.assetid: 0ce42f3b-3479-41c4-bcbf-1d21f7ee37e7
ms.openlocfilehash: 20afa988bc4fdf3bc3a6ff073a48a1cc00ff84c5
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70944364"
---
# <a name="_get_output_format"></a>_get_output_format

Obtém o valor atual do sinalizador de formato de saída.

> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.

## <a name="syntax"></a>Sintaxe

```
unsigned int _get_output_format();
```

## <a name="return-value"></a>Valor de retorno

O valor atual do sinalizador de formato de saída.

## <a name="remarks"></a>Comentários

O sinalizador de formato de saída controla os recursos da E/S formatada. No momento, o sinalizador tem dois valores possíveis: 0 e `_TWO_DIGIT_EXPONENT`. Se `_TWO_DIGIT_EXPONENT` for definido, os números de ponto flutuante serão impressos com apenas dois dígitos no expoente, a menos que um terceiro dígito seja exigido pelo tamanho do expoente. Se o sinalizador for zero, a saída de ponto flutuante exibirá três dígitos do expoente, usando zeros se necessário para preencher o valor até atingir os três dígitos.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_get_output_format`|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.

## <a name="see-also"></a>Consulte também

[Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)<br/>
[printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)<br/>
[_set_output_format](../c-runtime-library/set-output-format.md)
