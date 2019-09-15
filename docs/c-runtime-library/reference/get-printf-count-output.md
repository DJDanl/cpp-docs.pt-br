---
title: _get_printf_count_output
ms.date: 11/04/2016
api_name:
- _get_printf_count_output
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
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- get_printf_count_output
- _get_printf_count_output
helpviewer_keywords:
- '%n format'
- get_printf_count_output function
- _get_printf_count_output function
ms.assetid: 850f9f33-8319-433e-98d8-6a694200d994
ms.openlocfilehash: 15b37ac759821ad56cc5c03c9b98719d8f0cc19a
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70955716"
---
# <a name="_get_printf_count_output"></a>_get_printf_count_output

Indica se as funções [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)-Family dão suporte ao formato **% n** .

## <a name="syntax"></a>Sintaxe

```C
int _get_printf_count_output();
```

## <a name="return-value"></a>Valor de retorno

Diferente de zero se **% n** tiver suporte, 0 se **% n** não for suportado.

## <a name="remarks"></a>Comentários

Se **% n** não for suportado (o padrão), encontrar **% n** na cadeia de caracteres de formato de qualquer uma das funções **printf** invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o suporte a **% n** estiver habilitado (consulte [_set_printf_count_output](set-printf-count-output.md)), **% n** se comportará conforme descrito em [sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_printf_count_output**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_set_printf_count_output](set-printf-count-output.md).

## <a name="see-also"></a>Consulte também

[_set_printf_count_output](set-printf-count-output.md)<br/>
