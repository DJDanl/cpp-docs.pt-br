---
title: _tzset
ms.date: 11/04/2016
apiname:
- _tzset
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
- _tzset
helpviewer_keywords:
- _tzset function
- time environment variables
- environment variables, setting time
ms.assetid: 3f6ed537-b414-444d-b272-5dd377481930
ms.openlocfilehash: 33fd1cc0a618fccc4a59e5aff059d3f2cdeec8fe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661750"
---
# <a name="tzset"></a>_tzset

Define variáveis de ambiente de tempo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
void _tzset( void );
```

## <a name="remarks"></a>Comentários

O **tzset** função usa a configuração atual da variável de ambiente **TZ** para atribuir valores a três variáveis globais: **Daylight**, **TimeZone** , e **tzname**. Essas variáveis são usadas pelo [ftime](ftime-ftime32-ftime64.md) e [localtime](localtime-localtime32-localtime64.md) funções para fazer correções de hora universal coordenada (UTC) para a hora local e pela [tempo](time-time32-time64.md) função Calcule o UTC de horário do sistema. Use a sintaxe a seguir para definir a **TZ** variável de ambiente:

> **Definir TZ =**_tzn_ \[ **+** &#124; **-**]*hh* \[ **:**_mm_\[**:**_ss_]] [*dzn*]

|Parâmetro|Descrição|
|-|-|
*tzn*|Nome de fuso horário de três letras, como PST. Você deve especificar o deslocamento correto da hora local em UTC.
*hh*|Diferença de horas entre UTC e hora local. Sinal (+) opcional para valores positivos.
*mm*|Minutos. Separados dos *hh* por dois-pontos (**:**).
*ss*|Segundos. Separados dos *mm* por dois-pontos (**:**).
*dzn*|Fuso horário de verão com três letras, como PDT. Se o horário de verão nunca estiver em vigor na localidade, defina **TZ** sem um valor para *dzn*. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão).

> [!NOTE]
> Tome cuidado ao calcular o sinal da diferença de tempo. Como a diferença de tempo é o deslocamento de hora local em UTC (e não o contrário), o sinal pode ser o oposto do que você intuitivamente poderia esperar. Para fusos horários à frente do UTC, a diferença de tempo é negativa; para aqueles antes do UTC, a diferença é positiva.

Por exemplo, para definir a **TZ** variável de ambiente para corresponder ao fuso horário atual na Alemanha, insira o seguinte na linha de comando:

> **Definir TZ = 1GDT GST**

Esse comando usa o GST para indicar o horário padrão alemão, pressupõe que o UTC está uma hora atrás da Alemanha (ou, em outras palavras, que a Alemanha está uma hora à frente do UTC) e assume que a Alemanha observa o horário de verão.

Se o **TZ** valor não for definido, **tzset** tenta usar as informações de fuso horário especificadas pelo sistema operacional. No sistema operacional Windows, essas informações são especificadas no aplicativo de Data/Hora no Painel de controle. Se **tzset** não é possível obter essas informações, ele usa PST8PDT por padrão, o que significa o fuso horário do Pacífico.

Com base nas **TZ** valor de variável de ambiente, os seguintes valores são atribuídos às variáveis globais **Daylight**, **TimeZone**, e **tzname** quando **tzset** é chamado:

|Variável global|Descrição|Valor padrão|
|---------------------|-----------------|-------------------|
|**Daylight**|Um valor diferente de zero se uma zona-o horário de verão for especificada na **TZ** configuração; caso contrário, 0.|1|
|**TimeZone**|Diferença em segundos entre a hora local e o UTC.|28800 (28.800 segundos é igual a 8 horas)|
|**tzname**[0]|O valor do nome do fuso horário de cadeia de caracteres **TZ** variável de ambiente; vazio se **TZ** não foi definido.|PST|
|**tzname**[1]|Valor de cadeia de caracteres de horário de verão-fuso horário; vazio se o horário de verão-fuso horário for omitido da **TZ** variável de ambiente.|PDT|

Os valores padrão mostrados na tabela anterior para **Daylight** e o **tzname** matriz correspondem a "PST8PDT." Se o fuso horário de verão for omitido dos **TZ** variável de ambiente, o valor de **Daylight** é 0 e o [ftime](ftime-ftime32-ftime64.md), [gmtime](gmtime-gmtime32-gmtime64.md)e [localtime](localtime-localtime32-localtime64.md) funções retornarão 0 para seus sinalizadores de DST.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_tzset**|\<time.h>|

O **tzset** função é específico da Microsoft. Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_tzset.cpp
// This program uses _tzset to set the global variables
// named _daylight, _timezone, and _tzname. Since TZ is
// not being explicitly set, it uses the system time.

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
    _tzset();
    int daylight;
    _get_daylight( &daylight );
    printf( "_daylight = %d\n", daylight );
    long timezone;
    _get_timezone( &timezone );
    printf( "_timezone = %ld\n", timezone );
    size_t s;
    char tzname[100];
    _get_tzname( &s, tzname, sizeof(tzname), 0 );
    printf( "_tzname[0] = %s\n", tzname );
    exit( 0 );
}
```

```Output
_daylight = 1
_timezone = 28800
_tzname[0] = Pacific Standard Time
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64](utime-utime32-utime64-wutime-wutime32-wutime64.md)<br/>
