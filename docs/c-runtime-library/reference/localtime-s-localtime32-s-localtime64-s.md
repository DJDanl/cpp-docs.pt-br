---
title: localtime_s, _localtime32_s, _localtime64_s
ms.date: 11/04/2016
apiname:
- _localtime64_s
- _localtime32_s
- localtime_s
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
ms.openlocfilehash: 44b2eb2515035d56143a2aab251437a92515e652
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157261"
---
# <a name="localtimes-localtime32s-localtime64s"></a>localtime_s, _localtime32_s, _localtime64_s

Converte um **time_t** tempo valor para um **tm** estruturar e corrige o fuso horário local. Estas são versões de [localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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
|Não **nulo** (aponta para a memória válida)|**NULL**|**EINVAL**|Todos os campos definidos como -1|Sim|
|Não **nulo** (aponta para a memória válida)|menor que 0 ou maior que **_MAX__TIME64_T**|**EINVAL**|Todos os campos definidos como -1|Não|

Caso as duas primeiras condições de erro ocorram, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornar **EINVAL**.

## <a name="remarks"></a>Comentários

O **_localtime32_s** função converte uma hora armazenada como um [time_t](../../c-runtime-library/standard-types.md) valor e armazena o resultado em uma estrutura do tipo [tm](../../c-runtime-library/standard-types.md). O **longo** valor *sourceTime* representa os segundos passados desde a meia-noite (00: 00:00) de 1º de janeiro de 1970, UTC. Esse valor geralmente é obtido do [tempo](time-time32-time64.md) função.

**_localtime32_s** corrige de acordo com o fuso horário local se o usuário define primeiramente a variável de ambiente global **TZ**. Quando **TZ** for definido, três outras variáveis de ambiente (**TimeZone**, **Daylight**, e **tzname**) são definidas automaticamente também. Se o **TZ** variável não for definida, **localtime32_s** tenta usar as informações de fuso horário especificadas no aplicativo de data/hora no painel de controle. Se tais informações não puderem ser obtidas, o PST8PDT (fuso horário do Pacífico) será usado por padrão. Consulte [tzset](tzset.md) para obter uma descrição dessas variáveis. **TZ** é uma extensão da Microsoft e não faz parte da definição do padrão ANSI **localtime**.

> [!NOTE]
> O ambiente de destino deve tentar determinar se o horário de verão está em vigor.

**_localtime64_s**, que usa o **__time64_t** estrutura, permite que as datas sejam expressas até 23:59:59, 18 de janeiro, 3001, coordenado universal (UTC), enquanto **_localtime32_s** representa as datas por meio do 23:59:59 18 de janeiro de 2038, UTC.

**localtime_s** é uma função embutida que é avaliada como **_localtime64_s**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo 32-bit **time_t**, você pode definir **_USE_32BIT_TIME_T**. Essa ação fará **localtime_s** para avaliar a **_localtime32_s**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

Os campos do tipo de estrutura [tm](../../c-runtime-library/standard-types.md) armazenam valores a seguir, cada um deles é um **int**.

|Campo|Descrição|
|-|-|
|**tm_sec**|Segundos após o minuto (0 – 59).|
|**tm_min**|Minutos após a hora (0 – 59).|
|**tm_hour**|Horas desde a meia-noite (0 – 23).|
|**tm_mday**|Dia do mês (1 a 31).|
|**tm_mon**|Mês (0 – 11; Janeiro = 0).|
|**tm_year**|Ano (ano atual menos 1900).|
|**tm_wday**|Dia da semana (0 – 6; Domingo = 0).|
|**tm_yday**|Dia do ano (0 – 365; 1 de janeiro = 0).|
|**tm_isdst**|O valor será positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status do horário de verão for desconhecido.|

Se o **TZ** variável de ambiente é definida, a biblioteca de tempo de execução C presume que as regras dos Estados Unidos para implementar o cálculo do horário de verão (DST).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**localtime_s**, **_localtime32_s**, **_localtime64_s**|\<time.h>|\<ctime > ou \<time. h >|

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
