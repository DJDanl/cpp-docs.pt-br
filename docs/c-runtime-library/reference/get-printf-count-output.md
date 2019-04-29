---
title: _get_printf_count_output
ms.date: 11/04/2016
apiname:
- _get_printf_count_output
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_printf_count_output
- _get_printf_count_output
helpviewer_keywords:
- '%n format'
- get_printf_count_output function
- _get_printf_count_output function
ms.assetid: 850f9f33-8319-433e-98d8-6a694200d994
ms.openlocfilehash: 477e4a9e987f27bd70b9707e91b9ea9d84b69993
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62332047"
---
# <a name="getprintfcountoutput"></a>_get_printf_count_output

Indica se [printf, printf_l, wprintf, wprintf_l](printf-printf-l-wprintf-wprintf-l.md)-suporte a funções da família de **%n** formato.

## <a name="syntax"></a>Sintaxe

```C
int _get_printf_count_output();
```

## <a name="return-value"></a>Valor de retorno

Diferente de zero se **%n** tem suporte, 0 se **%n** não tem suporte.

## <a name="remarks"></a>Comentários

Se **%n** é não suportado (o padrão), encontrar **%n** na cadeia de caracteres de formato de qualquer um dos **printf** funções invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se **%n** suporte está habilitado (consulte [set_printf_count_output](set-printf-count-output.md)), em seguida, **%n** irão se comportar conforme descrito em [sintaxe de especificação de formato: printf e wprintf Funções](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_printf_count_output**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_set_printf_count_output](set-printf-count-output.md).

## <a name="see-also"></a>Consulte também

[_set_printf_count_output](set-printf-count-output.md)<br/>
