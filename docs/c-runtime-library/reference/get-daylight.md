---
title: _get_daylight
ms.date: 4/2/2020
api_name:
- __daylight
- _get_daylight
- _o___daylight
- _o__get_daylight
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
- get_daylight
- _get_daylight
helpviewer_keywords:
- get_daylight function
- daylight saving time offset
- _get_daylight function
ms.assetid: f85a6ba3-e187-4ca7-aed7-ffc694c8ac4c
ms.openlocfilehash: 0abab77b1429b263c7e5d84a6d395f0411ebf8a4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345309"
---
# <a name="_get_daylight"></a>_get_daylight

Recupera a diferença de horário para o horário de verão em horas.

## <a name="syntax"></a>Sintaxe

```C
error_t _get_daylight( int* hours );
```

### <a name="parameters"></a>Parâmetros

*Horas*<br/>
A diferença em horas para o horário de verão.

## <a name="return-value"></a>Valor retornado

Zero se for bem sucedido ou **um valor errno** se ocorrer um erro.

## <a name="remarks"></a>Comentários

A função **_get_daylight** recupera o número de horas no horário de verão como um inteiro. Se o horário de verão estiver em vigor, a diferença de horário é de uma hora (embora algumas regiões tenham uma diferença de horário de duas horas).

Se *as horas* **forem NULAS,** o manipulador de parâmetros inválidos será invocado conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

Recomendamos que você use esta função em vez do **_daylight** macro ou da função depreciada **__daylight**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_daylight**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_dstbias](get-dstbias.md)<br/>
[_get_timezone](get-timezone.md)<br/>
[_get_tzname](get-tzname.md)<br/>
