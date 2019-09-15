---
title: _mkgmtime, _mkgmtime32, _mkgmtime64
ms.date: 11/04/2016
api_name:
- _mkgmtime32
- _mkgmtime64
- _mkgmtime
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
- _mkgmtime64
- mkgmtime32
- _mkgmtime32
- mkgmtime
- mkgmtime64
- _mkgmtime
helpviewer_keywords:
- mkgmtime32 function
- time functions
- mkgmtime function
- _mkgmtime function
- converting times
- mkgmtime64 function
- _mkgmtime64 function
- _mkgmtime32 function
- time, converting
ms.assetid: b4ca2b67-e198-4f43-b3e2-e8ad6bd01867
ms.openlocfilehash: fcd1e3fdcca37d7e5bb381c234a6d8555ce2766c
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951665"
---
# <a name="_mkgmtime-_mkgmtime32-_mkgmtime64"></a>_mkgmtime, _mkgmtime32, _mkgmtime64

Converte uma hora UTC representada por uma **struct** **TM** em uma hora UTC representada por um tipo **time_t** .

## <a name="syntax"></a>Sintaxe

```C
time_t _mkgmtime(
   struct tm* timeptr
);
__time32_t _mkgmtime32(
   struct tm* timeptr
);
__time64_t _mkgmtime64(
   struct tm* timeptr
);
```

### <a name="parameters"></a>Parâmetros

*timeptr*<br/>
Um ponteiro para a hora UTC como um **struct** **TM** a ser convertido.

## <a name="return-value"></a>Valor de retorno

Uma quantidade do tipo **__time32_t** ou **__time64_t** que representa o número de segundos decorridos desde a meia-noite, 1º de janeiro de 1970, em UTC (tempo Universal Coordenado). Se a data estiver fora do intervalo (consulte a seção comentários) ou se a entrada não puder ser interpretada como uma hora válida, o valor de retorno será-1.

## <a name="remarks"></a>Comentários

As funções **_mkgmtime32** e **_mkgmtime64** convertem uma hora UTC em um tipo **__time32_t** ou **__time64_t** que representa a hora em UTC. Para converter uma hora local em hora UTC, use **mktime**, **_mktime32**e **_mktime64** em vez disso.

**_mkgmtime** é uma função embutida que é avaliada como **_mkgmtime64**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Isso não é recomendável porque seu aplicativo pode falhar após 18 de janeiro de 2038 (o intervalo máximo de um **time_t**de 32 bits) e não é permitido em plataformas de 64 bits.

A estrutura de tempo passada será alterada da seguinte maneira, da mesma forma que elas são alteradas com as funções **_mktime** : os **campos tm_wday** e **tm_yday** são definidos para novos valores com base nos valores de **tm_mday** e **tm_year**. Ao especificar um tempo de estrutura de **TM** , defina o campo **tm_isdst** como:

- Zero (0) para indicar que o horário padrão está em vigor.

- Um valor maior que 0 para indicar que o horário de verão está em vigor.

- Um valor menor que zero para fazer que com o código da biblioteca de tempo de execução C calcule se o horário padrão, ou o horário de verão está em vigor.

A biblioteca em tempo de execução C usa a variável de ambiente TZ para determinar o horário de verão correto. Se TZ não for definido, o sistema operacional será consultado para obter o comportamento de horário de verão regional correto. **tm_isdst** é um campo obrigatório. Se não estiver definido, seu valor será indefinido e o valor de retorno de **mktime** será imprevisível.

O intervalo da função **_mkgmtime32** é da meia-noite, 1º de janeiro de 1970, utc a 23:59:59 18 de janeiro de 2038, UTC. O intervalo de **_mkgmtime64** é da meia-noite, 1º de janeiro de 1970, utc a 23:59:59, 31 de dezembro de 3000, UTC. Uma data fora do intervalo resulta em um valor de retorno de-1. O intervalo de **_mkgmtime** depende se **_USE_32BIT_TIME_T** está definido. Se não estiver definido (o padrão), o intervalo será o de **_mkgmtime64**; caso contrário, o intervalo será limitado ao intervalo de 32 bits de **_mkgmtime32**.

Observe que **gmtime** e **localtime** usam um único buffer alocado estaticamente para a conversão. Se você fornecer esse buffer para **mkgmtime**, os conteúdos anteriores serão destruídos.

## <a name="example"></a>Exemplo

```C
// crt_mkgmtime.c
#include <stdio.h>
#include <time.h>

int main()
{
    struct tm t1, t2;
    time_t now, mytime, gmtime;
    char buff[30];

    time( & now );

    _localtime64_s( &t1, &now );
    _gmtime64_s( &t2, &now );

    mytime = mktime(&t1);
    gmtime = _mkgmtime(&t2);

    printf("Seconds since midnight, January 1, 1970\n");
    printf("My time: %I64d\nGM time (UTC): %I64d\n\n", mytime, gmtime);

    /* Use asctime_s to display these times. */

    _localtime64_s( &t1, &mytime );
    asctime_s( buff, sizeof(buff), &t1 );
    printf( "Local Time: %s\n", buff );

    _gmtime64_s( &t2, &gmtime );
    asctime_s( buff, sizeof(buff), &t2 );
    printf( "Greenwich Mean Time: %s\n", buff );

}
```

### <a name="sample-output"></a>Saída de Exemplo

```Output
Seconds since midnight, January 1, 1970
My time: 1171588492
GM time (UTC): 1171588492

Local Time: Thu Feb 15 17:14:52 2007

Greenwich Mean Time: Fri Feb 16 01:14:52 2007
```

O exemplo a seguir mostra como a estrutura incompleta é preenchida com os valores calculados do dia da semana e dia do ano.

```C
// crt_mkgmtime2.c
#include <stdio.h>
#include <time.h>
#include <memory.h>

int main()
{
    struct tm t1, t2;
    time_t gmtime;
    char buff[30];

    memset(&t1, 0, sizeof(struct tm));
    memset(&t2, 0, sizeof(struct tm));

    t1.tm_mon = 1;
    t1.tm_isdst = 0;
    t1.tm_year = 103;
    t1.tm_mday = 12;

    // The day of the week and year will be incorrect in the output here.
    asctime_s( buff, sizeof(buff), &t1);
    printf("Before calling _mkgmtime, t1 = %s t.tm_yday = %d\n",
            buff, t1.tm_yday );

    gmtime = _mkgmtime(&t1);

    // The correct day of the week and year were determined.
    asctime_s( buff, sizeof(buff), &t1);
    printf("After calling _mkgmtime, t1 = %s t.tm_yday = %d\n",
            buff, t1.tm_yday );

}
```

### <a name="output"></a>Saída

```Output
Before calling _mkgmtime, t1 = Sun Feb 12 00:00:00 2003
t.tm_yday = 0
After calling _mkgmtime, t1 = Wed Feb 12 00:00:00 2003
t.tm_yday = 42
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
