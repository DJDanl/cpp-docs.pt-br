---
title: localtime, _localtime32, _localtime64
ms.date: 4/2/2020
api_name:
- _localtime64
- _localtime32
- localtime
- _o__localtime32
- _o__localtime64
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
- localtime64
- _localtime64
- localtime32
- localtime
- _localtime32
helpviewer_keywords:
- localtime32 function
- _localtime32 function
- _localtime64 function
- localtime64 function
- localtime function
- time, converting values
ms.assetid: 4260ec3d-43ee-4538-b998-402a282bb9b8
ms.openlocfilehash: 21496b71c354c7bed7b87526dc40bc9b24865da2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342132"
---
# <a name="localtime-_localtime32-_localtime64"></a>localtime, _localtime32, _localtime64

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

## <a name="return-value"></a>Valor retornado

Retorne um ponteiro para o resultado da estrutura ou **NULL** se a data passada para a função for:

- Antes da meia-noite de 1º de janeiro de 1970.

- Após 03:14:07, 19 de janeiro de 2038, UTC (usando **_time32** e **time32_t**).

- Depois de 23:59:59, 31 de dezembro de 3000, UTC (usando **_time64** e **__time64_t**).

**_localtime64**, que utiliza a estrutura **__time64_t,** permite que as datas sejam expressas até 23:59:59, 31 de dezembro de 2000, tempo universal coordenado (UTC), enquanto **_localtime32** representa datas até 23:59:59 janeiro 18, 2038, UTC.

**localtime** é uma função inline que avalia **para _localtime64**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Fazer isso fará com que o **local** avalie **para _localtime32**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

Os campos do tipo de estrutura [tm armazenam](../../c-runtime-library/standard-types.md) os seguintes valores, cada um dos quais é um **int**:

|Campo|Descrição|
|-|-|
|**tm_sec**|Segundos após minuto (0 - 59).|
|**tm_min**|Minutos após hora (0 - 59).|
|**tm_hour**|Horário sofris desde a meia-noite (0 - 23).|
|**tm_mday**|Dia do mês (1 - 31).|
|**tm_mon**|Mês (0 - 11; Janeiro = 0).|
|**tm_year**|Ano (ano atual menos 1900).|
|**tm_wday**|Dia da semana (0 - 6; Domingo = 0).|
|**tm_yday**|Dia do ano (0 - 365; 1 º de janeiro = 0).|
|**Tm_isdst**|O valor será positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status do horário de verão for desconhecido.|

Se a variável de ambiente **TZ** estiver definida, a biblioteca de tempo de execução C assume regras apropriadas aos Estados Unidos para implementar o cálculo do tempo de verão (DST).

## <a name="remarks"></a>Comentários

A função **local-hora** converte um tempo armazenado como um [valor time_t](../../c-runtime-library/standard-types.md) e armazena o resultado em uma estrutura do tipo [tm](../../c-runtime-library/standard-types.md). A **fonte** de longo *valorTime* representa os segundos decorridos desde meia-noite (00:00:00), 1 de janeiro de 1970, UTC. Esse valor geralmente é obtido a partir da função [de tempo.](time-time32-time64.md)

As versões de 32 bits e 64 bits do [gmtime,](gmtime-gmtime32-gmtime64.md) [mktime,](mktime-mktime32-mktime64.md) [mkgmtime](mkgmtime-mkgmtime32-mkgmtime64.md)e **localtime** usam uma única estrutura **tm** por thread para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

**localtime** corrige para o fuso horário local se o usuário definir pela primeira vez a variável ambiente global **TZ**. Quando **o TZ** é definido, três outras variáveis de ambiente (**_timezone**, **_daylight**e **_tzname**) também são definidas automaticamente. Se a variável **TZ** não estiver definida, o **local-hora** tentará usar as informações de fuso horário especificadas no aplicativo Data/Hora no Painel de Controle. Se tais informações não puderem ser obtidas, o PST8PDT (Fuso Horário do Pacífico) será usado por padrão. Consulte [tzset](tzset.md) para obter uma descrição dessas variáveis. **TZ** é uma extensão da Microsoft e não faz parte da definição padrão ANSI de **hora local**.

> [!NOTE]
> O ambiente de destino deve tentar determinar se o horário de verão está em vigor.

Essas funções validam seus parâmetros. Se *sourceTime* for um ponteiro nulo ou se o valor *sourceTime* for negativo, essas funções invocarão um manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, as funções retornam **NULL** e definem **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**hora do** **_localtime32**, **_localtime64**|\<time.h>|\<ctime> \<ou time.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
