---
title: "localtime_s, _localtime32_s, _localtime64_s | Microsoft Docs"
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
  - "_localtime64_s"
  - "_localtime32_s"
  - "localtime_s"
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
  - "_localtime32_s"
  - "localtime32_s"
  - "localtime_s"
  - "localtime64_s"
  - "_localtime64_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _localtime64_s"
  - "Função localtime32_s"
  - "Função _localtime32_s"
  - "Função localtime64_s"
  - "tempo, convertendo valores"
  - "Função localtime_s"
ms.assetid: 842d1dc7-d6f8-41d3-b340-108d4b90df54
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# localtime_s, _localtime32_s, _localtime64_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um valor de hora e corrige o fuso horário local. Essas são versões de [localtime, localtime32, localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t localtime_s(  
   struct tm* _tm,  
   const time_t *time   
);  
errno_t _localtime32_s(  
   struct tm* _tm,  
   const time32_t *time   
);  
errno_t _localtime64_s(  
   struct tm* _tm,  
   const _time64_t *time   
);  
```  
  
#### Parâmetros  
 `_tm`  
 Ponteiro para a estrutura de tempo a ser preenchido.  
  
 `time`  
 Ponteiro para a hora armazenado.  
  
## Valor de retorno  
 Zero se tiver êxito. O valor de retorno é um código de erro se houver uma falha. Códigos de erro são definidos em errno. Para obter uma lista desses erros, consulte [errno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
### Condições de erro  
  
|`_tm`|`time`|Valor de retorno|O valor `_tm`|Invoca o manipulador de parâmetro inválido|  
|-----------|------------|----------------------|-------------------|------------------------------------------------|  
|`NULL`|qualquer|`EINVAL`|Não modificado|Sim|  
|Não `NULL` \(aponta para memória válido\)|`NULL`|`EINVAL`|Todos os campos definidos como \-1|Sim|  
|Não `NULL` \(aponta para memória válido\)|menor que 0 ou maior que `_MAX__TIME64_T`|`EINVAL`|Todos os campos definidos como \-1|Não|  
  
 No caso do primeiro condições de erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definir `errno` para `EINVAL` e retornar `EINVAL`.  
  
## Comentários  
 O `_localtime32_s` função converte uma hora armazenada como um [time\_t](../../c-runtime-library/standard-types.md) valor e armazena o resultado em uma estrutura do tipo `tm`. O `long` valor `timer` representa os segundos passados desde a meia\-noite \(00: 00:00\), 1 de janeiro de 1970, UTC. Esse valor geralmente é obtido o `time` função.  
  
 `_localtime32_s` corrige o fuso horário local se o usuário primeiro define a variável de ambiente global `TZ`. Quando `TZ` estiver definido, três variáveis de ambiente \(`_timezone`, `_daylight`, e `_tzname`\) são definidas automaticamente também. Se o `TZ` variável não for definida, `localtime32_s` tenta usar as informações de fuso horário especificadas no aplicativo de data\/hora no painel de controle. Se essas informações não podem ser obtidas, PST8PDT, o que significa o fuso horário do Pacífico, é usado por padrão. Consulte [tzset](../Topic/_tzset.md) para obter uma descrição dessas variáveis.`TZ` é uma extensão da Microsoft e não faz parte da definição padrão ANSI de `localtime`.  
  
> [!NOTE]
>  O ambiente de destino deve tentar determinar se o horário de verão está em vigor.  
  
 `_localtime64_s`, que usa o `__time64_t` estrutura, permite que as datas sejam expressas backup a 23:59:59, 31 de dezembro de 3000 a universal coordenado \(UTC\), enquanto `_localtime32_s` representa datas até 23:59:59 18 de janeiro de 2038, UTC.  
  
 `localtime_s` é uma função embutida que é avaliada como `_localtime64_s`, e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`. Fazer isso fará com que `localtime_s` para avaliar a `_localtime32_s`. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038, e não é permitido em plataformas de 64 bits.  
  
 Os campos do tipo estrutura [tm](../../c-runtime-library/standard-types.md) armazenar valores a seguir, cada um deles é um `int`.  
  
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
 Valor positivo se o horário de verão está em vigor; 0 se o horário de verão não estiver em vigor. valor negativo se o status do horário de verão é desconhecido. Se o `TZ` variável de ambiente é definida, a biblioteca de tempo de execução C assumirá as regras apropriadas para os Estados Unidos para implementar o cálculo do horário de verão \(DST\).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`localtime_s`|\< h \>|  
|`_localtime32_s`|\< h \>|  
|`_localtime64_s`|\< h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_localtime_s.c  
/* This program uses _time64 to get the current time   
 * and then uses _localtime64_s() to convert this time to a structure   
 * representing the local time. The program converts the result   
 * from a 24-hour clock to a 12-hour clock and determines the   
 * proper extension (AM or PM).  
 */  
  
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
                newtime.tm_hour -= 12;    // to 12-hour clock.   
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
  
## Saída de exemplo  
  
```  
Fri Apr 25 01:19:27 PM  
```  
  
## Equivalência do .NET Framework  
 [System::DateTime::ToLocalTime](https://msdn.microsoft.com/en-us/library/system.datetime.tolocaltime.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_tzset](../Topic/_tzset.md)