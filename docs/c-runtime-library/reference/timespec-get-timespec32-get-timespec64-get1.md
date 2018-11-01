---
title: timespec_get, _timespec32_get, _timespec64_get1
ms.date: 11/04/2016
apiname:
- timespec_get
- _timespec32_get
- _timespec64_get
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
- timespec_get
- _timespec32_get
- _timespec64_get
- time/timespec_get
- time/_timespec32_get
- time/_timespec64_get
- timespec
- _timespec32
- _timespec64
helpviewer_keywords:
- timespec_get function
- _timespec32_get function
- _timespec64_get function
ms.assetid: ed757258-b4f2-4c1d-a91b-22ea6ffce4ab
ms.openlocfilehash: c1d0cbaf194060d816e31d397a9319ef47f75371
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50638445"
---
# <a name="timespecget-timespec32get-timespec64get"></a>timespec_get, _timespec32_get, _timespec64_get

Define o intervalo apontado pelo primeiro argumento com o horário do calendário atual, de acordo com a base de tempo especificada.

## <a name="syntax"></a>Sintaxe

```C
int timespec_get(
    struct timespec* const time_spec,
    int const base
);
int _timespec32_get(
    struct _timespec32* const time_spec,
    int const base
);
int _timespec64_get(
    struct _timespec64* const time_spec,
    int const base
);

```

### <a name="parameters"></a>Parâmetros

*time_spec*<br/>
Ponteiro para um struct definido com a hora em segundos e nanossegundos desde o início da época.

*base*<br/>
Um valor específico à implementação diferente de zero que especifica a base de tempo.

## <a name="return-value"></a>Valor de retorno

O valor de *base* se for bem-sucedido, caso contrário, ele retornará zero.

## <a name="remarks"></a>Comentários

O **timespec_get** funções definem a hora atual no struct apontado pelo *time_spec* argumento. Todas as versões desse struct têm dois membros, **tv_sec** e **tv_nsec**. O **tv_sec** valor é definido como o número inteiro de segundos e **tv_nsec** com o número integral de nanossegundos, arredondado para a resolução do relógio do sistema, desde o início da época especificado por *base*.

**Seção específica da Microsoft**

Essas funções dão suporte apenas **TIME_UTC** como o *base* valor. Isso define a *time_spec* valor para o número de segundos e nanossegundos desde o início da época, meia-noite de 1º de janeiro de 1970, Tempo Universal Coordenado (UTC). Em um **struct** **_timespec32**, **tv_sec** é um **__time32_t** valor. Em um **struct** **_timespec64**, **tv_sec** é um **__time64_t** valor. Em um **struct** **timespec**, **tv_sec** é um **time_t** tipo, que é de 32 ou 64 bits de comprimento, dependendo se o pré-processador macro _USE_32BIT_TIME_T está definida. O **timespec_get** função é uma função embutida que chama **_timespec32_get** se _USE_32BIT_TIME_T for definido; caso contrário, ele chama **_timespec64_get**.

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**timespec_get**, **_timespec32_get**, **_timespec64_get**|C: \<time.h>, C++: \<ctime> ou \<time.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64](utime-utime32-utime64-wutime-wutime32-wutime64.md)<br/>
