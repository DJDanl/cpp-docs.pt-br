---
title: _get_dstbias
ms.date: 11/04/2016
apiname:
- _get_dstbias
- __dstbias
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
- __dstbias
- _get_dstbias
- get_dstbias
helpviewer_keywords:
- __dstbias
- daylight saving time offset
- get_dstbias function
- _get_dstbias function
ms.assetid: e751358c-1ecc-411b-ae2c-81b2ec54ea45
ms.openlocfilehash: 61807f854dc9c2f7de6f0acd5bbf4668987ce49e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62332371"
---
# <a name="getdstbias"></a>_get_dstbias

Recupera a diferença de horário para o horário de verão em segundos.

## <a name="syntax"></a>Sintaxe

```C
error_t _get_dstbias( int* seconds );
```

### <a name="parameters"></a>Parâmetros

*seconds*<br/>
A diferença em segundos para o horário de verão.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um **errno** se ocorrer um erro de valor.

## <a name="remarks"></a>Comentários

O **get_dstbias** função recupera o número de segundos no horário de verão como um número inteiro. Se o horário de verão estiver em vigor, a diferença padrão é de 3600 segundos, que é o número de segundos em uma hora (embora algumas regiões tenham uma diferença de duas horas).

Se *segundos* é **nulo**, o manipulador de parâmetro inválido será invocado conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retorna **EINVAL**.

É recomendável usar essa função em vez da macro **dstbias** ou a função preterida **__dstbias**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_dstbias**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_daylight](get-daylight.md)<br/>
[_get_timezone](get-timezone.md)<br/>
[_get_tzname](get-tzname.md)<br/>
