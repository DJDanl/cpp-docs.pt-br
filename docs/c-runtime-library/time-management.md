---
title: Gerenciamento de tempo
ms.date: 11/04/2016
f1_keywords:
- c.memory
helpviewer_keywords:
- dates, run-time library members
- time, time management
- date functions
- time functions
ms.assetid: 93599220-c011-45d5-978f-12182abfdd2f
ms.openlocfilehash: 67b993325c7f9c649d1509ce2c1ecf09a2404bc8
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51328923"
---
# <a name="time-management"></a>Gerenciamento de tempo

Use essas funções para obter a hora atual e converter, ajustar e armazená-lo conforme necessário. A hora atual é a hora do sistema.

As rotinas **_ftime** e **localtime** usam a variável de ambiente **TZ**. Se **TZ** não for definido, a biblioteca em tempo de execução tentará usar as informações de fuso horário especificadas pelo sistema operacional. Se essa informação não estiver disponível, essas funções usam o valor padrão de PST8PDT. Para saber mais sobre **TZ**, veja [_tzset](../c-runtime-library/reference/tzset.md). Consulte também [_daylight, timezone e _tzname](../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

### <a name="time-routines"></a>Rotinas de Tempo

|Função|Use|
|--------------|---------|
|[asctime, _wasctime](../c-runtime-library/reference/asctime-wasctime.md), [asctime_s, _wasctime_s](../c-runtime-library/reference/asctime-s-wasctime-s.md)|Converter a hora do tipo **struct tm** em sequência de caracteres. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[clock](../c-runtime-library/reference/clock.md)|Retorne a hora do relógio decorrida no processo.|
|[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [_ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)|Converter a hora do tipo **time_t**, **__time32_t** ou **__time64_t** em cadeia de caracteres. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[difftime, _difftime32, _difftime64](../c-runtime-library/reference/difftime-difftime32-difftime64.md)|Calcula a diferença entre duas horas.|
|[_ftime, _ftime32, _ftime64](../c-runtime-library/reference/ftime-ftime32-ftime64.md),[_ftime_s, _ftime32_s, _ftime64_s](../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md)|Armazenar a hora atual do sistema em variável do tipo **struct _timeb** ou tipo **struct __timeb64**. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[_futime, _futime32, _futime64](../c-runtime-library/reference/futime-futime32-futime64.md)|Definir hora da modificação em arquivo aberto|
|[gmtime, _gmtime32, _gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md), [gmtime_s, _gmtime32_s, _gmtime64_s](../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)|Converter a hora do tipo **time_t** em **struct tm** ou do tipo **__time64_t** em **struct tm**. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[localtime, _localtime32, _localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md), [localtime_s, _localtime32_s, _localtime64_s](../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)|Converter a hora do tipo **time_t** em **struct tm** ou do tipo **__time64_t** em **struct tm** com correção local. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[_mkgmtime, _mkgmtime32, _mkgmtime64](../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)|Converta a hora em valor de calendário o horário em valor de calendário na Hora de Greenwich.|
|[mktime, _mktime32, _mktime64](../c-runtime-library/reference/mktime-mktime32-mktime64.md)|Converter a hora em valor de calendário.|
|[_strdate, _wstrdate](../c-runtime-library/reference/strdate-wstrdate.md), [_strdate_s, _wstrdate_s](../c-runtime-library/reference/strdate-s-wstrdate-s.md)|Retorna a data atual do sistema como cadeia de caracteres. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)|Formato de cadeia de caracteres de data e hora para uso internacional.|
|[_strtime, _wstrtime](../c-runtime-library/reference/strtime-wstrtime.md), [_strtime_s, _wstrtime_s](../c-runtime-library/reference/strtime-s-wstrtime-s.md)|Retorna a hora atual do sistema como cadeia de caracteres. As versões dessas funções com o sufixo **_s** são mais seguras.|
|[time, _time32, _time64](../c-runtime-library/reference/time-time32-time64.md)|Obter a hora atual do sistema como tipo **time_t**, **__time32_t** ou como tipo **__time64_t**.|
|[_tzset](../c-runtime-library/reference/tzset.md)|Definir variáveis de tempo externas da variável de ambiente de hora **TZ**.|
|[_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md)|Definir o tempo de modificação de arquivo especificado usando a hora atual ou valor de hora armazenados na estrutura.|

> [!NOTE]
> Em todas as versões do Microsoft C/C++, exceto na versão 7.0 do Microsoft C/C++, e em todas as versões do Visual C++, a função time retorna a hora atual como o número de segundos passados desde a meia-noite de 1º de janeiro de 1970. Na versão 7.0 do Microsoft C/C++, **time** retornava a hora atual como o número de segundos passados desde a meia-noite de 31 de dezembro de 1899.

> [!NOTE]
> Em versões do Visual C++ e do Microsoft C/C++ anteriores ao Visual C++ 2005, **time_t** era um **long** **int** (32 bits) e, portanto, não pode ser usado para datas anteriores a 3:14:07 de 19 de janeiro de 2038, UTC. **time_t** agora é equivalente a **__time64_t** por padrão, mas definir **_USE_32BIT_TIME_T** altera **time_t** para **__time32_t** e força muitas funções de tempo para chamar as versões que usam **time_t** 32 bits. Para saber mais, veja [tipos padrão](../c-runtime-library/standard-types.md) e comentários na documentação para as funções de tempo individuais.

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
