---
title: localtime, _localtime32, _localtime64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _localtime64
- _localtime32
- localtime
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
- localtime64
- _localtime64
- localtime32
- localtime
- _localtime32
dev_langs:
- C++
helpviewer_keywords:
- localtime32 function
- _localtime32 function
- _localtime64 function
- localtime64 function
- localtime function
- time, converting values
ms.assetid: 4260ec3d-43ee-4538-b998-402a282bb9b8
caps.latest.revision: 28
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 32b462dfbe794d1817fa727736452e961a2b1dfd
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="localtime-localtime32-localtime64"></a>localtime, _localtime32, _localtime64

Converte um valor temporal e o corrige de acordo com o fuso horário local. Versões mais seguras dessas funções estão disponíveis; consulte [localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md).

## <a name="syntax"></a>Sintaxe

```C
struct tm *localtime( const time_t *sourceTime );
struct tm *_localtime32( const __time32_t *sourceTime );
struct tm *_localtime64( const __time64_t *sourceTime );
```

### <a name="parameters"></a>Parâmetros

*sourceTime*<br/>
Ponteiro para a hora armazenada.

## <a name="return-value"></a>Valor de retorno

Retornar um ponteiro para o resultado de estrutura, ou **nulo** se a data passada para a função é:

- Antes da meia-noite de 1º de janeiro de 1970.

- Após 03:14:07, 19 de janeiro de 2038, a UTC (usando **time32** e **time32_t**).

- Após a 23:59:59, 31 de dezembro de 3000 a UTC (usando **time64** e **__time64_t**).

**localtime64**, que usa o **__time64_t** estrutura, permite que as datas sejam expressas backup a 23:59:59, 31 de dezembro de 3000 a tempo universal coordenado (UTC), enquanto **localtime32** representa as datas até 23:59:59 18 de janeiro de 2038, UTC.

**LocalTime** é uma função embutida que é avaliada como **localtime64**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo 32-bit **time_t**, você pode definir **_USE_32BIT_TIME_T**. Fazer isso fará com que **localtime** para avaliar a **localtime32**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

Os campos do tipo de estrutura [tm](../../c-runtime-library/standard-types.md) armazenar valores a seguir, cada um deles é um **int**:

|Campo|Descrição|
|-|-|
|**tm_sec**|Segundos após minuto (0 - 59).|
|**tm_min**|Minutos após a hora (0 - 59).|
|**tm_hour**|Horas desde a meia-noite (0 - 23).|
|**tm_mday**|Dia do mês (1-31).|
|**tm_mon**|Mês (0 - 11; Janeiro = 0).|
|**tm_year**|Ano (ano atual menos 1900).|
|**tm_wday**|Dia da semana (0 - 6; Domingo = 0).|
|**tm_yday**|Dia do ano (0 - 365; 1 de janeiro = 0).|
|**tm_isdst**|O valor será positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status do horário de verão for desconhecido.|

Se o **TZ** variável de ambiente é definida, a biblioteca de tempo de execução C assumirá as regras apropriadas para os Estados Unidos para implementar o cálculo de – horário de verão (DST).

## <a name="remarks"></a>Comentários

O **localtime** função converte uma hora armazenada como um [time_t](../../c-runtime-library/standard-types.md) valor e armazena o resultado em uma estrutura de tipo [tm](../../c-runtime-library/standard-types.md). O **longo** valor *sourceTime* representa os segundos decorridos desde a meia-noite (00: 00:00), 1 de janeiro de 1970, UTC. Esse valor normalmente é obtido o [tempo](time-time32-time64.md) função.

Ambas as versões de 32 bits e 64 bits do [gmtime](gmtime-gmtime32-gmtime64.md), [mktime](mktime-mktime32-mktime64.md), [mkgmtime](mkgmtime-mkgmtime32-mkgmtime64.md), e **localtime** usam um único **tm** estrutura por thread para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

**LocalTime** corrige para o fuso horário local se o usuário define primeiramente a variável de ambiente global **TZ**. Quando **TZ** for definida, três variáveis de ambiente (**TimeZone**, **Daylight**, e **tzname**) são definidas automaticamente também. Se o **TZ** variável não for definida, **localtime** tenta usar as informações de fuso horário especificadas no aplicativo de data/hora no painel de controle. Se tais informações não puderem ser obtidas, o PST8PDT (Fuso Horário do Pacífico) será usado por padrão. Consulte [tzset](tzset.md) para obter uma descrição dessas variáveis. **TZ** é uma extensão da Microsoft e não faz parte da definição padrão ANSI de **localtime**.

> [!NOTE]
> O ambiente de destino deve tentar determinar se o horário de verão está em vigor.

Essas funções validam seus parâmetros. Se *sourceTime* é um ponteiro nulo, ou se o *sourceTime* valor for negativo, essas funções para chamar um manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução é permitida para continuar, as funções retornam **nulo** e defina **errno** para **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**LocalTime**, **localtime32**, **localtime64**|\<time.h>|\<ctime > ou \<time.h >|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_localtime.cpp
// compile with: /W3
// This program uses _time64 to get the current time
// and then uses localtime64() to convert this time to a structure
// representing the local time. The program converts the result
// from a 24-hour clock to a 12-hour clock and determines the
// proper extension (AM or PM).

#include <stdio.h>
#include <string.h>
#include <time.h>

int main( void )
{
    struct tm *newtime;
    char am_pm[] = "AM";
    __time64_t long_time;

    _time64( &long_time );             // Get time as 64-bit integer.
                                       // Convert to local time.
    newtime = _localtime64( &long_time ); // C4996
    // Note: _localtime64 deprecated; consider _localetime64_s

    if( newtime->tm_hour > 12 )        // Set up extension.
        strcpy_s( am_pm, sizeof(am_pm), "PM" );
    if( newtime->tm_hour > 12 )        // Convert from 24-hour
        newtime->tm_hour -= 12;        //   to 12-hour clock.
    if( newtime->tm_hour == 0 )        // Set hour to 12 if midnight.
        newtime->tm_hour = 12;

    char buff[30];
    asctime_s( buff, sizeof(buff), newtime );
    printf( "%.19s %s\n", buff, am_pm );
}
```

```Output
Tue Feb 12 10:05:58 AM
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
