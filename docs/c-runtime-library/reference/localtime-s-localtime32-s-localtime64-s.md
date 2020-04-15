---
title: localtime_s, _localtime32_s, _localtime64_s
ms.date: 4/2/2020
api_name:
- _localtime64_s
- _localtime32_s
- localtime_s
- _o__localtime32_s
- _o__localtime64_s
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
- _localtime32_s
- localtime32_s
- localtime_s
- localtime64_s
- _localtime64_s
helpviewer_keywords:
- _localtime64_s function
- localtime32_s function
- _localtime32_s function
- localtime64_s function
- time, converting values
- localtime_s function
ms.assetid: 842d1dc7-d6f8-41d3-b340-108d4b90df54
ms.openlocfilehash: 3c5d194da85eb5d008dfc9cf19f222ebb575747d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342116"
---
# <a name="localtime_s-_localtime32_s-_localtime64_s"></a>localtime_s, _localtime32_s, _localtime64_s

Converte um valor de tempo **time_t** em uma estrutura **tm** e corrige para o fuso horário local. Estas são versões de [localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t localtime_s(
   struct tm* const tmDest,
   time_t const* const sourceTime
);
errno_t _localtime32_s(
   struct tm* tmDest,
   __time32_t const* sourceTime
);
errno_t _localtime64_s(
   struct tm* tmDest,
   __time64_t const* sourceTime
);
```

### <a name="parameters"></a>Parâmetros

*tmDest*<br/>
Ponteiro para a estrutura de hora a ser preenchida.

*sourceTime*<br/>
Ponteiro para a hora armazenada.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de erro

|*tmDest*|*sourceTime*|Valor retornado|Valor em *tmDest*|Invoca um manipulador de parâmetro inválido|
|-----------|------------|------------------|--------------------|---------------------------------------|
|**NULO**|any|**Einval**|Não modificado|Sim|
|Não **NULL** (pontos para memória válida)|**NULO**|**Einval**|Todos os campos definidos como -1|Sim|
|Não **NULL** (pontos para memória válida)|menos de 0 ou maior que **_MAX__TIME64_T**|**Einval**|Todos os campos definidos como -1|Não|

Caso as duas primeiras condições de erro ocorram, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam **EINVAL**.

## <a name="remarks"></a>Comentários

A função **localtime_s** converte um tempo armazenado como um [valor time_t](../../c-runtime-library/standard-types.md) e armazena o resultado em uma estrutura do tipo [tm](../../c-runtime-library/standard-types.md). A **fonte de** valor *time_tTime* representa os segundos decorridos desde meia-noite (00:00:00), 1 de janeiro de 1970, UTC. Esse valor geralmente é obtido a partir da função [de tempo.](time-time32-time64.md)

**localtime_s** corrige para o fuso horário local se o usuário definir pela primeira vez a variável ambiente global **TZ**. Quando **o TZ** é definido, três outras variáveis de ambiente (**_timezone**, **_daylight**e **_tzname**) também são definidas automaticamente. Se a variável **TZ** não estiver definida, **localtime_s** tentativas de usar as informações de fuso horário especificadas no aplicativo Data/Hora no Painel de Controle. Se tais informações não puderem ser obtidas, o PST8PDT (fuso horário do Pacífico) será usado por padrão. Consulte [tzset](tzset.md) para obter uma descrição dessas variáveis. **TZ** é uma extensão da Microsoft e não faz parte da definição padrão ANSI de **hora local**.

> [!NOTE]
> O ambiente de destino deve tentar determinar se o horário de verão está em vigor.

**_localtime64_s**, que utiliza a estrutura **__time64_t,** permite que as datas sejam expressas até 23:59:59, 18 de janeiro de 3001, tempo universal coordenado (UTC), enquanto **_localtime32_s** representa datas até 23:59:59 janeiro 18, 2038, UTC.

**localtime_s** é uma função inline que avalia **_localtime64_s**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Fazer isso fará **com que localtime_s** avalie para **_localtime32_s**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

Os campos da estrutura tipo [tm armazenam](../../c-runtime-library/standard-types.md) os seguintes valores, cada um dos quais é um **int**.

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

Se a variável de ambiente **TZ** for definida, a biblioteca de tempo de execução C assume regras apropriadas aos Estados Unidos para implementar o cálculo do horário de verão (DST).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**localtime_s,** **_localtime32_s** **_localtime64_s**|\<time.h>|\<ctime> \<ou time.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_localtime_s.c
// This program uses _time64 to get the current time
// and then uses _localtime64_s() to convert this time to a structure
// representing the local time. The program converts the result
// from a 24-hour clock to a 12-hour clock and determines the
// proper extension (AM or PM).

#include <stdio.h>
#include <string.h>
#include <time.h>

int main( void )
{
    struct tm newtime;
    char am_pm[] = "AM";
    __time64_t long_time;
    char timebuf[26];
    errno_t err;

    // Get time as 64-bit integer.
    _time64( &long_time );
    // Convert to local time.
    err = _localtime64_s( &newtime, &long_time );
    if (err)
    {
        printf("Invalid argument to _localtime64_s.");
        exit(1);
    }
    if( newtime.tm_hour > 12 )        // Set up extension.
        strcpy_s( am_pm, sizeof(am_pm), "PM" );
    if( newtime.tm_hour > 12 )        // Convert from 24-hour
        newtime.tm_hour -= 12;        // to 12-hour clock.
    if( newtime.tm_hour == 0 )        // Set hour to 12 if midnight.
        newtime.tm_hour = 12;

    // Convert to an ASCII representation.
    err = asctime_s(timebuf, 26, &newtime);
    if (err)
    {
        printf("Invalid argument to asctime_s.");
        exit(1);
    }
    printf( "%.19s %s\n", timebuf, am_pm );
}
```

```Output
Fri Apr 25 01:19:27 PM
```

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
