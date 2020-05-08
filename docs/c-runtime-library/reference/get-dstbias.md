---
title: _get_dstbias
ms.date: 4/2/2020
api_name:
- _get_dstbias
- __dstbias
- _o___dstbias
- _o__get_dstbias
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 845310928ec4707afe15bccc7ff5b979e7da69b6
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919376"
---
# <a name="_get_dstbias"></a>_get_dstbias

Recupera a diferença de horário para o horário de verão em segundos.

## <a name="syntax"></a>Sintaxe

```C
error_t _get_dstbias( int* seconds );
```

### <a name="parameters"></a>Parâmetros

*seg*<br/>
A diferença em segundos para o horário de verão.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou um valor **errno** se ocorrer um erro.

## <a name="remarks"></a>Comentários

A função **_get_dstbias** recupera o número de segundos no horário de verão como um inteiro. Se o horário de verão estiver em vigor, a diferença padrão é de 3600 segundos, que é o número de segundos em uma hora (embora algumas regiões tenham uma diferença de duas horas).

Se *segundos* for **nulo**, o manipulador de parâmetro inválido será invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **EINVAL**.

Recomendamos que você use essa função em vez da macro **_dstbias** ou da função preterida **__dstbias**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_dstbias**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_daylight](get-daylight.md)<br/>
[_get_timezone](get-timezone.md)<br/>
[_get_tzname](get-tzname.md)<br/>
