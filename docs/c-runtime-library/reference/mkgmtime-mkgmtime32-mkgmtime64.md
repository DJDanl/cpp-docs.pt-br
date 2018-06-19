---
title: _mkgmtime, _mkgmtime32, _mkgmtime64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _mkgmtime32
- _mkgmtime64
- _mkgmtime
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
- _mkgmtime64
- mkgmtime32
- _mkgmtime32
- mkgmtime
- mkgmtime64
- _mkgmtime
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bcb587cf5504f661512ccf88cf4f15d0555e2f18
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405134"
---
# <a name="mkgmtime-mkgmtime32-mkgmtime64"></a>_mkgmtime, _mkgmtime32, _mkgmtime64

Converte uma hora de UTC representada por um **struct** **tm** para uma hora de UTC representado por um **time_t** tipo.

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
Um ponteiro para a hora de UTC como um **struct** **tm** para converter.

## <a name="return-value"></a>Valor de retorno

Uma quantidade de tipo **__time32_t** ou **__time64_t** que representa o número de segundos passados desde a meia-noite de 1 de janeiro de 1970, em tempo Universal Coordenado (UTC). Se a data está fora do intervalo (consulte a seção comentários) ou a entrada não pode ser interpretada como uma hora válida, o valor de retorno é -1.

## <a name="remarks"></a>Comentários

O **mkgmtime32** e **mkgmtime64** funções convertem uma hora UTC para um **__time32_t** ou **__time64_t** tipo que representa o tempo em UTC. Para converter a hora local em hora UTC, use **mktime**, **mktime32**, e **mktime64** em vez disso.

**mkgmtime** é uma função embutida que é avaliada como **mkgmtime64**, e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo 32-bit **time_t**, você pode definir **_USE_32BIT_TIME_T**. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038 (o intervalo máximo de 32 bits **time_t**), e não é permitido em todos os em plataformas de 64 bits.

O tempo de estrutura passada será alterado da seguinte maneira da mesma maneira como eles são alterados com o **_mktime** funções: o **tm_wday** e **tm_yday** campos são definidos como novo valores com base nos valores de **tm_mday** e **tm_year**. Ao especificar um **tm** estrutura de tempo, defina o **tm_isdst** campo para:

- Zero (0) para indicar que o horário padrão está em vigor.

- Um valor maior que 0 para indicar que o horário de verão está em vigor.

- Um valor menor que zero para fazer que com o código da biblioteca de tempo de execução C calcule se o horário padrão, ou o horário de verão está em vigor.

A biblioteca em tempo de execução C usa a variável de ambiente TZ para determinar o horário de verão correto. Se TZ não for definido, o sistema operacional será consultado para obter o comportamento de horário de verão regional correto. **tm_isdst** é um campo obrigatório. Se não estiver definida, seu valor será indefinido e o valor de retorno **mktime** é imprevisível.

O intervalo da **mkgmtime32** função é de 1 de janeiro de 1970, meia-noite UTC de 23:59:59 18 de janeiro de 2038, UTC. O intervalo de **mkgmtime64** é de 1 de janeiro de 1970, meia-noite UTC a 23:59:59, 31 de dezembro de 3000 UTC. Uma data fora do intervalo resulta em um valor de retorno de -1. O intervalo de **mkgmtime** depende **_USE_32BIT_TIME_T** está definido. Se não definido (padrão) o intervalo é de **mkgmtime64**; caso contrário, o intervalo é limitado para o intervalo de 32 bits de **mkgmtime32**.

Observe que **gmtime** e **localtime** usar um único buffer estaticamente alocado para a conversão. Se você fornecer esse buffer para **mkgmtime**, o conteúdo anterior será destruído.

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
