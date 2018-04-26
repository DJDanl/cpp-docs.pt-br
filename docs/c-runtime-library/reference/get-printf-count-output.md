---
title: _get_printf_count_output | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- '%n format'
- get_printf_count_output function
- _get_printf_count_output function
ms.assetid: 850f9f33-8319-433e-98d8-6a694200d994
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8b96aab9e075386f71439a5c528fcf072097d389
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="getprintfcountoutput"></a>_get_printf_count_output

Indica se [printf, printf_l, and wprintf, wprintf_l](printf-printf-l-wprintf-wprintf-l.md)-família de funções de suporte a **%n** formato.

## <a name="syntax"></a>Sintaxe

```C
int _get_printf_count_output();
```

## <a name="return-value"></a>Valor de retorno

Diferente de zero se **%n** tem suporte, 0 se **%n** não tem suporte.

## <a name="remarks"></a>Comentários

Se **%n** é não suportado (o padrão), encontrar **%n** na cadeia de formato de qualquer um do **printf** funções invocará o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se **%n** suporte está habilitado (consulte [set_printf_count_output](set-printf-count-output.md)), em seguida, **%n** irão se comportar conforme descrito em [sintaxe de especificação de formato: printf e and wprintf Funções](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_printf_count_output**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_set_printf_count_output](set-printf-count-output.md).

## <a name="see-also"></a>Consulte também

[_set_printf_count_output](set-printf-count-output.md)<br/>
