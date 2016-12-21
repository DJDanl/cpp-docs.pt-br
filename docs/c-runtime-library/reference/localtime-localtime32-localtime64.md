---
title: "localtime, _localtime32, _localtime64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_localtime64"
  - "_localtime32"
  - "localtime"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-time-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "localtime64"
  - "_localtime64"
  - "localtime32"
  - "localtime"
  - "_localtime32"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função localtime32"
  - "Função _localtime32"
  - "Função _localtime64"
  - "Função localtime64"
  - "Função localtime"
  - "tempo, convertendo valores"
ms.assetid: 4260ec3d-43ee-4538-b998-402a282bb9b8
caps.latest.revision: 28
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# localtime, _localtime32, _localtime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter um valor de tempo e corrigir o fuso horário local. Versões mais seguras dessas funções estão disponíveis; consulte [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md).  
  
## Sintaxe  
  
```  
struct tm *localtime(  
   const time_t *timer   
);  
struct tm *_localtime32(  
   const __time32_t *timer  
);  
struct tm *_localtime64(  
   const __time64_t *timer   
);  
```  
  
#### Parâmetros  
 `timer`  
 Ponteiro para hora armazenado.  
  
## Valor de retorno  
 Retornar um ponteiro para o resultado da estrutura, ou `NULL` se a data passada para a função é:  
  
-   Antes da meia\-noite de 1º de janeiro de 1970.  
  
-   Após 03:14:07 de 19 de janeiro de 2038, UTC \(usando `_time32` e `time32_t`\).  
  
-   Após a 23:59:59 em 31 de dezembro de 3000, UTC \(usando `_time64` e `__time64_t`\).  
  
 `_localtime64`, que usa o `__time64_t` estrutura, permite que as datas sejam expressas backup a 23:59:59, 31 de dezembro de 3000 a universal coordenado \(UTC\), enquanto `_localtime32` representa datas até 23:59:59 18 de janeiro de 2038, UTC.  
  
 `localtime` é uma função embutida que é avaliada como `_localtime64`, e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t`como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`. Fazer isso fará com que `localtime` para avaliar a `_localtime32`. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038, e não é permitido em plataformas de 64 bits.  
  
 Os campos do tipo estrutura [tm](../../c-runtime-library/standard-types.md) armazenar valores a seguir, cada um deles é um `int`:  
  
 `tm_sec`  
 Segundos após o minuto \(0\-59\).  
  
 `tm_min`  
 Minutos após a hora \(0\-59\).  
  
 `tm_hour`  
 Horas após a meia\-noite \(0\-23\).  
  
 `tm_mday`  
 Dia do mês \(1\-31\).  
  
 `tm_mon`  
 Mês \(0 – 11; Janeiro \= 0\).  
  
 `tm_year`  
 Ano \(ano atual menos 1900\).  
  
 `tm_wday`  
 Dia da semana \(0 – 6; Domingo \= 0\).  
  
 `tm_yday`  
 Dia do ano \(0 a 365; 1 de janeiro \= 0\).  
  
 `tm_isdst`  
 Valor positivo se o horário de verão está em vigor; 0 se o horário de verão não estiver em vigor. valor negativo se o status do horário de verão é desconhecido. Se o `TZ` variável de ambiente é definida, a biblioteca de tempo de execução C assumirá as regras apropriadas para os Estados Unidos para implementar o cálculo de – horário de verão \(DST\).  
  
## Comentários  
 O `localtime` função converte uma hora armazenada como um [time\_t](../../c-runtime-library/standard-types.md) valor e armazena o resultado em uma estrutura do tipo `tm`. O `long` valor `timer` representa os segundos passados desde a meia\-noite \(00: 00:00\), 1 de janeiro de 1970, UTC. Esse valor geralmente é obtido o `time` função.  
  
 Ambas as versões de 32 bits e 64 bits do `gmtime`, `mktime`, `mkgmtime`, e `localtime` todos usam um único `tm` estrutura por thread para a conversão. Cada chamada para uma dessas rotinas destrói o resultado da chamada anterior.  
  
 `localtime` corrige o fuso horário local se o usuário primeiro define a variável de ambiente global `TZ`. Quando `TZ` estiver definido, três variáveis de ambiente \(`_timezone`, `_daylight`, e `_tzname`\) são definidas automaticamente também. Se o `TZ` variável não for definida, `localtime` tenta usar as informações de fuso horário especificadas no aplicativo de data\/hora no painel de controle. Se essas informações não podem ser obtidas, PST8PDT, o que significa o fuso horário do Pacífico, é usado por padrão. Consulte [tzset](../Topic/_tzset.md) para obter uma descrição dessas variáveis.`TZ` é uma extensão da Microsoft e não faz parte da definição padrão ANSI de `localtime`.  
  
> [!NOTE]
>  O ambiente de destino deve tentar determinar se o horário de verão está em vigor.  
  
 Essas funções validam seus parâmetros. Se `timer` for um ponteiro nulo, ou se o valor do timer for negativo, essas funções chamar um manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornam `NULL` e defina `errno` para `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`localtime`|\< h \>|  
|`_localtime32`|\< h \>|  
|`_localtime64`|\< h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_localtime.cpp  
// compile with: /W3  
/* This program uses _time64 to get the current time   
 * and then uses localtime64() to convert this time to a structure   
 * representing the local time. The program converts the result   
 * from a 24-hour clock to a 12-hour clock and determines the   
 * proper extension (AM or PM).  
 */  
  
#include <stdio.h>  
#include <string.h>  
#include <time.h>  
  
int main( void )  
{  
        struct tm *newtime;  
        char am_pm[] = "AM";  
        __time64_t long_time;  
  
        _time64( &long_time );           // Get time as 64-bit integer.  
                                         // Convert to local time.  
        newtime = _localtime64( &long_time ); // C4996  
        // Note: _localtime64 deprecated; consider _localetime64_s  
  
        if( newtime->tm_hour > 12 )        // Set up extension.  
                strcpy_s( am_pm, sizeof(am_pm), "PM" );  
        if( newtime->tm_hour > 12 )        // Convert from 24-hour  
                newtime->tm_hour -= 12;    //   to 12-hour clock.  
        if( newtime->tm_hour == 0 )        // Set hour to 12 if midnight.  
                newtime->tm_hour = 12;  
  
        char buff[30];  
        asctime_s( buff, sizeof(buff), newtime );  
        printf( "%.19s %s\n", buff, am_pm );  
}  
```  
  
```Output  
12 de fevereiro ter 10:05:58 AM  
```  
  
## Equivalência do .NET Framework  
 [System::DateTime::ToLocalTime](https://msdn.microsoft.com/en-us/library/system.datetime.tolocaltime.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_tzset](../Topic/_tzset.md)