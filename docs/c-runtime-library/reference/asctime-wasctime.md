---
title: asctime, _wasctime
ms.date: 4/2/2020
api_name:
- _wasctime
- asctime
- _o__wasctime
- _o_asctime
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
- _tasctime
- asctime
- _wasctime
helpviewer_keywords:
- asctime function
- tasctime function
- wasctime function
- _tasctime function
- _wasctime function
- time structure conversion
- time, converting
ms.assetid: 974f1727-10ff-4ed4-8cac-2eb2d681f576
ms.openlocfilehash: bda14f3b6046378ad23148371f354bb910163d3c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350474"
---
# <a name="asctime-_wasctime"></a>asctime, _wasctime

Converta uma estrutura de tempo **tm** em uma seqüência de caracteres. Versões mais seguras dessas funções estão disponíveis; consulte [asctime_s, wasctime_s](asctime-s-wasctime-s.md).

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

## <a name="return-value"></a>Valor retornado

**asctime** retorna um ponteiro para o resultado da seqüência de caracteres; **_wasctime** retorna um ponteiro para o resultado da seqüência de caracteres de grande porte. Não há nenhum valor retornado de erro.

## <a name="remarks"></a>Comentários

Versões mais seguras dessas funções estão disponíveis; consulte [asctime_s, wasctime_s](asctime-s-wasctime-s.md).

A função **asctime** converte um tempo armazenado como uma estrutura para uma seqüência de caracteres. O valor *do timeptr* geralmente é obtido a partir de uma chamada para **gmtime** ou **hora local,** que ambos retornam um ponteiro para uma estrutura **tm,** definida em TEMPO. H.

|membro timeptr|Valor|
|--------------------|-----------|
|**tm_hour**|Horários desde a meia-noite (0-23)|
|**Tm_isdst**|Positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status de horário de verão for desconhecido. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão).|
|**tm_mday**|Dia do mês (1-31)|
|**tm_min**|Minutos após hora (0-59)|
|**tm_mon**|Mês (0-11; Janeiro = 0)|
|**tm_sec**|Segundos após minuto (0-59)|
|**tm_wday**|Dia da semana (0-6; Domingo = 0)|
|**tm_yday**|Dia do ano (0-365; Janeiro 1 = 0)|
|**tm_year**|Ano (ano atual menos 1900)|

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Para obter mais informações sobre a configuração da hora local, consulte as funções [time](time-time32-time64.md), [_ftime](ftime-ftime32-ftime64.md) e [localtime](localtime-localtime32-localtime64.md) e a função [_tzset](tzset.md) para saber como definir variáveis globais e de ambiente de fuso horário.

O resultado da seqüência produzida por **asctime** contém exatamente 26 caracteres e tem a forma `Wed Jan 02 02:03:55 1980\n\0`. Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha e o caractere nulo ocupam as duas últimas posições da cadeia de caracteres. **asctime** usa um único buffer, estáticamente alocado para segurar a seqüência de retorno. Cada chamada para essa função destrói o resultado da chamada anterior.

**_wasctime** é uma versão de grande caráter do **asctime**. **_wasctime** e **asctime** se comportem de forma idêntica de outra forma.

Essas funções validam seus parâmetros. Se *o timeptr* for um ponteiro nulo ou se contiver valores fora de alcance, o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna **NULL** e define **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tasctime**|**asctime**|**asctime**|**_wasctime**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**asctime**|\<time.h>|
|**_wasctime**|\<time.h> ou \<wchar.h>|

## <a name="example"></a>Exemplo

Este programa coloca o tempo do sistema no **relógio**inteiro longo, traduz-o para a estrutura **newtime** e, em seguida, converte-o em forma de string para saída, usando a função **asctime.**

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

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
