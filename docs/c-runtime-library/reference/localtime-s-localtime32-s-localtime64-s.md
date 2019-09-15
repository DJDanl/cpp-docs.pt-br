---
title: localtime_s, _localtime32_s, _localtime64_s
ms.date: 07/09/2019
api_name:
- _localtime64_s
- _localtime32_s
- localtime_s
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
ms.openlocfilehash: c00a5d23441612d0e70bfafd571bcb25250edb09
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953333"
---
# <a name="localtime_s-_localtime32_s-_localtime64_s"></a>localtime_s, _localtime32_s, _localtime64_s

Converte um valor de hora de **time_t** em uma estrutura **TM** e corrige o fuso horário local. Estas são versões de [localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de Erro

|*tmDest*|*sourceTime*|Valor retornado|Valor em *tmDest*|Invoca um manipulador de parâmetro inválido|
|-----------|------------|------------------|--------------------|---------------------------------------|
|**NULL**|qualquer|**EINVAL**|Não modificado|Sim|
|Not **NULL** (aponta para memória válida)|**NULL**|**EINVAL**|Todos os campos definidos como -1|Sim|
|Not **NULL** (aponta para memória válida)|menor que 0 ou maior que **_MAX__TIME64_T**|**EINVAL**|Todos os campos definidos como -1|Não|

Caso as duas primeiras condições de erro ocorram, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

A função **localtime_s** converte uma hora armazenada como um valor de [time_t](../../c-runtime-library/standard-types.md) e armazena o resultado em uma estrutura do tipo [TM](../../c-runtime-library/standard-types.md). O valor de **time_t** *sourcetime* representa os segundos decorridos desde a meia-noite (00:00:00), 1º de janeiro de 1970, UTC. Esse valor geralmente é obtido da função [time](time-time32-time64.md) .

o **localtime_s** é corrigido para o fuso horário local se o usuário primeiro define a variável de ambiente global **TZ**. Quando a **TZ** é definida, três outras variáveis de ambiente ( **_timezone**, **_daylight**e **_tzname**) também são definidas automaticamente. Se a variável **TZ** não for definida, **localtime_s** tentará usar as informações de fuso horário especificadas no aplicativo de data/hora no painel de controle. Se tais informações não puderem ser obtidas, o PST8PDT (fuso horário do Pacífico) será usado por padrão. Consulte [tzset](tzset.md) para obter uma descrição dessas variáveis. O **TZ** é uma extensão da Microsoft e não faz parte da definição padrão ANSI de **localtime**.

> [!NOTE]
> O ambiente de destino deve tentar determinar se o horário de verão está em vigor.

**_localtime64_s**, que usa a estrutura **__time64_t** , permite que as datas sejam expressadas até 23:59:59, 18 de janeiro de 3001, UTC (tempo Universal Coordenado), enquanto **_localtime32_s** representa datas até 23:59:59 de janeiro de 18 2038, UTC.

**localtime_s** é uma função embutida que é avaliada como **_localtime64_s**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Isso fará com que o **localtime_s** seja avaliado para **_localtime32_s**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

Os campos do tipo de estrutura [TM](../../c-runtime-library/standard-types.md) armazenam os valores a seguir, sendo que cada um é um **inteiro**.

|Campo|Descrição|
|-|-|
|**tm_sec**|Segundos após o minuto (0-59).|
|**tm_min**|Minutos após a hora (0-59).|
|**tm_hour**|Horas desde a meia-noite (0-23).|
|**tm_mday**|Dia do mês (1-31).|
|**tm_mon**|Mês (0-11; Janeiro = 0).|
|**tm_year**|Ano (ano atual menos 1900).|
|**tm_wday**|Dia da semana (0-6; Domingo = 0).|
|**tm_yday**|Dia do ano (0-365; 1 de janeiro = 0).|
|**tm_isdst**|O valor será positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status do horário de verão for desconhecido.|

Se a variável de ambiente do **TZ** for definida, a biblioteca de tempo de execução do C assumirá as regras apropriadas para a Estados Unidos para implementar o cálculo do horário de Verão (DST).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**localtime_s**, **_localtime32_s**, **_localtime64_s**|\<time.h>|\<CTime > ou \<time. h >|

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

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
