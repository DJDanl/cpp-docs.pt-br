---
title: _get_timezone
ms.date: 4/2/2020
api_name:
- _get_timezone
- _o__get_timezone
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 94dfae1aaaddf9c545af4309d3ddc62a0bcb33f6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344901"
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

*Segundos*<br/>
A diferença, em segundos, entre o UTC e a hora local.

## <a name="return-value"></a>Valor retornado

Zero se for bem sucedido ou **um valor errno** se ocorrer um erro.

## <a name="remarks"></a>Comentários

A função **_get_timezone** recupera a diferença em segundos entre UTC e hora local como um inteiro. O valor padrão é de 28.800 segundos para a Hora Padrão do Pacífico (oito horas antes do UTC).

Se *o segundo* for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_timezone**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_daylight](get-daylight.md)<br/>
[_get_dstbias](get-dstbias.md)<br/>
[_get_tzname](get-tzname.md)<br/>
