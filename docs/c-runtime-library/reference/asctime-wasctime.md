---
title: asctime, _wasctime | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wasctime
- asctime
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
- _tasctime
- asctime
- _wasctime
dev_langs:
- C++
helpviewer_keywords:
- asctime function
- tasctime function
- wasctime function
- _tasctime function
- _wasctime function
- time structure conversion
- time, converting
ms.assetid: 974f1727-10ff-4ed4-8cac-2eb2d681f576
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2b18edc9e61f7065fcac1fe6231012bd232ccc18
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32396190"
---
# <a name="asctime-wasctime"></a>asctime, _wasctime

Converter um **tm** estrutura como uma cadeia de caracteres de tempo. Versões mais seguras dessas funções estão disponíveis; consulte [asctime_s, wasctime_s](asctime-s-wasctime-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *asctime(
   const struct tm *timeptr
);
wchar_t *_wasctime(
   const struct tm *timeptr
);
```

### <a name="parameters"></a>Parâmetros

*timeptr*<br/>
Estrutura de hora/data.

## <a name="return-value"></a>Valor de retorno

**asctime** retorna um ponteiro para o resultado de cadeia de caracteres; **wasctime** retorna um ponteiro para o resultado de cadeia de caracteres largos. Não há nenhum valor retornado de erro.

## <a name="remarks"></a>Comentários

Versões mais seguras dessas funções estão disponíveis; consulte [asctime_s, wasctime_s](asctime-s-wasctime-s.md).

O **asctime** função converte uma hora armazenada como uma estrutura para uma cadeia de caracteres. O *timeptr* valor normalmente é obtido de uma chamada para **gmtime** ou **localtime**, que retornam um ponteiro para um **tm** estrutura, definido no momento. H.

|membro timeptr|Valor|
|--------------------|-----------|
|**tm_hour**|Horas desde a meia-noite (0-23)|
|**tm_isdst**|Positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status de horário de verão for desconhecido. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão).|
|**tm_mday**|Dia do mês (1-31)|
|**tm_min**|Minutos após a hora (0-59)|
|**tm_mon**|Mês (0-11; Janeiro = 0)|
|**tm_sec**|Segundos após o minuto (0-59)|
|**tm_wday**|Dia da semana (0 a 6; Domingo = 0)|
|**tm_yday**|Dia do ano (365 0; 1 de janeiro = 0)|
|**tm_year**|Ano (ano atual menos 1900)|

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Para obter mais informações sobre a configuração da hora local, consulte as funções [time](time-time32-time64.md), [_ftime](ftime-ftime32-ftime64.md) e [localtime](localtime-localtime32-localtime64.md) e a função [_tzset](tzset.md) para saber como definir variáveis globais e de ambiente de fuso horário.

O resultado de cadeia de caracteres produzido por **asctime** contém exatamente 26 caracteres e tem o formato `Wed Jan 02 02:03:55 1980\n\0`. Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha e o caractere nulo ocupam as duas últimas posições da cadeia de caracteres. **asctime** usa um único buffer alocado estaticamente para manter a cadeia de caracteres de retorno. Cada chamada para essa função destrói o resultado da chamada anterior.

**wasctime** é uma versão de caractere largo de **asctime**. **wasctime** e **asctime** se comportam de forma idêntica caso contrário.

Essas funções validam seus parâmetros. Se *timeptr* é um ponteiro nulo ou se ele contiver valores fora do intervalo, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função retorna **nulo** e define **errno** para **EINVAL**.

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tasctime**|**asctime**|**asctime**|**_wasctime**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**asctime**|\<time.h>|
|**_wasctime**|\<time.h> ou \<wchar.h>|

## <a name="example"></a>Exemplo

Este programa coloca a hora do sistema em inteiro longo **aclock**, converte-o para a estrutura **newtime** e converte-o em forma de cadeia de caracteres de saída, usando o **asctime**função.

```C
// crt_asctime.c
// compile with: /W3

#include <time.h>
#include <stdio.h>

int main( void )
{
    struct tm   *newTime;
    time_t      szClock;

    // Get time in seconds
    time( &szClock );

    // Convert time to struct tm form
    newTime = localtime( &szClock );

    // Print local time as a string.
    printf_s( "Current date and time: %s", asctime( newTime ) ); // C4996
    // Note: asctime is deprecated; consider using asctime_s instead
}
```

```Output
Current date and time: Sun Feb 03 11:38:58 2002
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
