---
title: _get_timezone
ms.date: 11/04/2016
api_name:
- _get_timezone
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
- api-ms-win-crt-time-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _get_timezone
- get_timezone
helpviewer_keywords:
- time zones
- get_timezone function
- _get_timezone function
ms.assetid: 30ab0838-0ae9-4a2f-bfe6-a49ee443b21e
ms.openlocfilehash: cf77ca21383bcae6919b6c1d00b99c082ef99919
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70955629"
---
# <a name="_get_timezone"></a>_get_timezone

Recupera a diferença em segundos entre o UTC (Tempo Universal Coordenado) e a hora local.

## <a name="syntax"></a>Sintaxe

```C
error_t _get_timezone(
    long* seconds
);
```

### <a name="parameters"></a>Parâmetros

*seg*<br/>
A diferença, em segundos, entre o UTC e a hora local.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um valor **errno** se ocorrer um erro.

## <a name="remarks"></a>Comentários

A função **_get_timezone** recupera a diferença em segundos entre o UTC e a hora local como um inteiro. O valor padrão é de 28.800 segundos para a Hora Padrão do Pacífico (oito horas antes do UTC).

Se *segundos* for **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_timezone**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_daylight](get-daylight.md)<br/>
[_get_dstbias](get-dstbias.md)<br/>
[_get_tzname](get-tzname.md)<br/>
