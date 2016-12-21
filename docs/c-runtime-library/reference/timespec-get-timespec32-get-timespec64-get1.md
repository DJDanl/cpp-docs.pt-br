---
title: "timespec_get, _timespec32_get, _timespec64_get | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "timespec_get"
  - "_timespec32_get"
  - "_timespec64_get"
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
  - "timespec_get"
  - "_timespec32_get"
  - "_timespec64_get"
  - "time/timespec_get"
  - "time/_timespec32_get"
  - "time/_timespec64_get"
  - "timespec"
  - "_timespec32"
  - "_timespec64"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função timespec_get"
  - "função _timespec32_get"
  - "função _timespec64_get"
ms.assetid: ed757258-b4f2-4c1d-a91b-22ea6ffce4ab
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# timespec_get, _timespec32_get, _timespec64_get
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o intervalo apontado pelo primeiro argumento para o horário do calendário atual, conforme a base de tempo especificado.  
  
## Sintaxe  
  
```  
int timespec_get(  
    struct timespec* const time_spec,  
    int const base  
);  
int _timespec32_get(  
    struct _timespec32* const time_spec,  
    int const base  
);  
int _timespec64_get(  
    struct _timespec64* const time_spec,  
    int const base  
);  
  
```  
  
#### Parâmetros  
 `time_spec`  
 Ponteiro para uma estrutura que é definido para o tempo em segundos e nanossegundos desde o início da época.  
  
 `base`  
 Um valor específico da implementação diferente de zero que especifica a base de tempo.  
  
## Valor de retorno  
 O valor de `base` se for bem\-sucedido, caso contrário, retornará zero.  
  
## Comentários  
 O `timespec_get` funções definir a hora atual na estrutura apontada para o `time_spec` argumento. Todas as versões dessa estrutura tem dois membros, `tv_sec` e `tv_nsec`. O `tv_sec` valor é definido para o número inteiro de segundos e `tv_nsec` o número integral de nanossegundos, arredondado para a resolução do relógio do sistema, desde o início da época especificado por `base`.  
  
 **Específico da Microsoft**  
  
 Suportam a essas funções só `TIME_UTC` como o `base` valor. Isso define o `time_spec` valor para o número de segundos e nanossegundos desde a época Iniciar, meia\-noite de 1º de janeiro de 1970, Tempo Universal Coordenado \(UTC\). Em um `struct _timespec32`, `tv_sec` é um `__time32_t` valor. Em um `struct _timespec64`, `tv_sec` é um `__time64_t` valor. Em um `struct timespec`, `tv_sec` é um `time_t` tipo, que é de 32 bits ou 64 bits de comprimento, dependendo se a macro do pré\-processador \_USE\_32BIT\_TIME\_T está definido. O `timespec_get` é uma função embutida que chama `_timespec32_get` se \_USE\_32BIT\_TIME\_T for definido; caso contrário, ele chama `_timespec64_get`.  
  
 **Fim de específico da Microsoft**  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`timespec_get`, `_timespec32_get`, `_timespec64_get`|C: \< h \> C\+\+: \< ctime \> ou \< h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_utime, \_utime32, \_utime64, \_wutime, \_wutime32, \_wutime64](../../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md)