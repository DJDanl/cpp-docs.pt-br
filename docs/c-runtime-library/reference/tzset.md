---
title: _tzset
ms.date: 4/2/2020
api_name:
- _tzset
- _o__tzset
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
- _tzset
helpviewer_keywords:
- _tzset function
- time environment variables
- environment variables, setting time
ms.assetid: 3f6ed537-b414-444d-b272-5dd377481930
ms.openlocfilehash: b2537a3bbfd2b5cec6bdf149c520aac7e3344b1e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362197"
---
# <a name="_tzset"></a>_tzset

Define variáveis de ambiente de tempo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
void _tzset( void );
```

## <a name="remarks"></a>Comentários

A função **_tzset** usa a configuração atual da variável ambiente **TZ** para atribuir valores a três variáveis globais: **_daylight,** **_timezone**e **_tzname**. Essas variáveis são usadas pelas funções [_ftime](ftime-ftime32-ftime64.md) e [localtime](localtime-localtime32-localtime64.md) para fazer correções do tempo universal coordenado (UTC) para o horário local, e pela função de [tempo](time-time32-time64.md) para calcular UTC a partir do tempo do sistema. Use a seguinte sintaxe para definir a variável de ambiente **TZ:**

> **conjunto TZ=**_tzn_ \[ **+** **-**&#124;]*hh*\[**:**_mm_\[**:**_ss_]*[dzn*]

|Parâmetro|Descrição|
|-|-|
| *Tzn* | Nome de fuso horário de três letras, como PST. Você deve especificar o deslocamento correto da hora local em UTC. |
| *hh* | Diferença de horas entre UTC e hora local. Sinal (+) opcional para valores positivos. |
| *Mm* | Minutos. Separado de *hh* por um cólon (**: ).** |
| *ss* | Segundos. Separado de *mm* por um cólon **(: ).** |
| *dzn* | Fuso horário de verão com três letras, como PDT. Se o horário de verão nunca estiver em vigor na localidade, defina **TZ** sem um valor para *dzn*. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão). |

> [!NOTE]
> Tome cuidado ao calcular o sinal da diferença de tempo. Como a diferença de tempo é o deslocamento de hora local em UTC (e não o contrário), o sinal pode ser o oposto do que você intuitivamente poderia esperar. Para fusos horários à frente do UTC, a diferença de tempo é negativa; para aqueles antes do UTC, a diferença é positiva.

Por exemplo, para definir a variável de ambiente **TZ** para corresponder ao fuso horário atual na Alemanha, digite o seguinte na linha de comando:

> **definir TZ=GST-1GDT**

Esse comando usa o GST para indicar o horário padrão alemão, pressupõe que o UTC está uma hora atrás da Alemanha (ou, em outras palavras, que a Alemanha está uma hora à frente do UTC) e assume que a Alemanha observa o horário de verão.

Se o valor **TZ** não estiver definido, **_tzset** tentativas de usar as informações de fuso horário especificadas pelo sistema operacional. No sistema operacional Windows, essas informações são especificadas no aplicativo de Data/Hora no Painel de controle. Se **_tzset** não puder obter essas informações, ele usará PST8PDT por padrão, o que significa o fuso horário do Pacífico.

Com base no valor variável do ambiente **TZ,** os seguintes valores são atribuídos às variáveis globais **_daylight**, **_timezone**e **_tzname** quando **_tzset** é chamado:

|Variável global|Descrição|Valor padrão|
|---------------------|-----------------|-------------------|
|**_daylight**|Valor não zero se um fuso horário de verão for especificado na configuração **TZ;** caso contrário, 0.|1|
|**_timezone**|Diferença em segundos entre a hora local e o UTC.|28800 (28.800 segundos é igual a 8 horas)|
|**_tzname**[0]|Valor da string do nome do fuso horário da variável ambiental **TZ;** vazio se **TZ** não foi definido.|PST|
|**_tzname**[1]|Valor da corda do fuso horário de verão; vazio se o fuso horário de verão for omitido da variável ambiental **TZ.**|PDT|

Os valores padrão mostrados na tabela anterior para **_daylight** e a matriz **_tzname** correspondem a "PST8PDT". Se a zona DST for omitida da variável ambiental **TZ,** o valor de **_daylight** é 0 e as [funções _ftime](ftime-ftime32-ftime64.md), [gmtime](gmtime-gmtime32-gmtime64.md)e [localtime](localtime-localtime32-localtime64.md) retornam 0 para suas bandeiras DST.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_tzset**|\<time.h>|

A função **_tzset** é específica da Microsoft. Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64](utime-utime32-utime64-wutime-wutime32-wutime64.md)<br/>
