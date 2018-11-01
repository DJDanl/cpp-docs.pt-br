---
title: _get_daylight
ms.date: 11/04/2016
apiname:
- __daylight
- _get_daylight
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_daylight
- _get_daylight
helpviewer_keywords:
- get_daylight function
- daylight saving time offset
- _get_daylight function
ms.assetid: f85a6ba3-e187-4ca7-aed7-ffc694c8ac4c
ms.openlocfilehash: 03c3386e59379f460d3c07dc310153d990c02b05
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50444636"
---
# <a name="getdaylight"></a>_get_daylight

Recupera a diferença de horário para o horário de verão em horas.

## <a name="syntax"></a>Sintaxe

```C
error_t _get_daylight( int* hours );
```

### <a name="parameters"></a>Parâmetros

*Horas*<br/>
A diferença em horas para o horário de verão.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um **errno** se ocorrer um erro de valor.

## <a name="remarks"></a>Comentários

O **get_daylight** função recupera o número de horas no horário de verão como um número inteiro. Se o horário de verão estiver em vigor, a diferença de horário é de uma hora (embora algumas regiões tenham uma diferença de horário de duas horas).

Se *horas* é **nulo**, o manipulador de parâmetro inválido será invocado conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retorna **EINVAL**.

É recomendável usar essa função em vez da macro **Daylight** ou a função preterida **__daylight**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_daylight**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_dstbias](get-dstbias.md)<br/>
[_get_timezone](get-timezone.md)<br/>
[_get_tzname](get-tzname.md)<br/>
