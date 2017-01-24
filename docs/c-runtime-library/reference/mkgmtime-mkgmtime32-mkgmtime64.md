---
title: "_mkgmtime, _mkgmtime32, _mkgmtime64 | Microsoft Docs"
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
  - "_mkgmtime32"
  - "_mkgmtime64"
  - "_mkgmtime"
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
  - "_mkgmtime64"
  - "mkgmtime32"
  - "_mkgmtime32"
  - "mkgmtime"
  - "mkgmtime64"
  - "_mkgmtime"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função mkgmtime32"
  - "funções de tempo"
  - "Função mkgmtime"
  - "Função _mkgmtime"
  - "convertendo horários"
  - "Função mkgmtime64"
  - "Função _mkgmtime64"
  - "Função _mkgmtime32"
  - "tempo, convertendo"
ms.assetid: b4ca2b67-e198-4f43-b3e2-e8ad6bd01867
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mkgmtime, _mkgmtime32, _mkgmtime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma hora UTC representada por um `tm``struct` para uma hora UTC representado por um `time_t` tipo.  
  
## Sintaxe  
  
```  
  
time_t _mkgmtime(  
   struct tm*   
timeptr  
);  
__time32_t _mkgmtime32(  
   struct tm*   
timeptr  
);  
__time64_t _mkgmtime64(  
   struct tm*   
timeptr  
);  
  
```  
  
#### Parâmetros  
 `timeptr`  
 Um ponteiro para a hora UTC como um `struct``tm` para converter.  
  
## Valor de retorno  
 Uma quantidade de tipo `__time32_t` ou `__time64_t` que representa o número de segundos passados desde a meia\-noite de 1 de janeiro de 1970, em tempo Universal Coordenado \(UTC\). Se a data está fora do intervalo \(consulte a seção comentários\) ou a entrada não pode ser interpretada como uma hora válida, o valor de retorno será – 1.  
  
## Comentários  
 O `_mkgmtime32` e `_mkgmtime64` funções convertem uma hora UTC em um `__time32_t` ou `__time64_t` tipo que representa a hora em UTC. Para converter uma hora local em hora UTC, use `mktime`, `_mktime32`, e `_mktime64` em vez disso.  
  
 `_mkgmtime` é uma função embutida que é avaliada como `_mkgmtime64`, e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t`como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038 \(o intervalo máximo de 32 bits `time_t`\), e não é permitido em todas as plataformas de 64 bits.  
  
 O tempo passada estrutura será alterado da seguinte maneira, da mesma forma como eles são alterados com o `_mktime` funções: a `tm_wday` e `tm_yday` campos são definidos como novos valores com base nos valores de `tm_mday` e `tm_year`. Ao especificar um `tm` horário de estrutura, defina o `tm_isdst` campo para:  
  
-   Zero \(0\) para indicar que a hora padrão está em vigor.  
  
-   Um valor maior que 0 para indicar que o horário de verão está em vigor.  
  
-   Um valor menor que zero para que o código da biblioteca de tempo de execução C de computação se hora padrão ou o horário de verão está em vigor.  
  
 A biblioteca de tempo de execução C usa a variável de ambiente TZ para determinar o horário de verão correto. Se TZ não for definido, o sistema operacional é consultado para obter o verão regionais correto comportamento de tempo.`tm_isdst` é um campo obrigatório. Se não estiver definida, seu valor é indefinido e o valor de retorno de `mktime` é imprevisível.  
  
 O intervalo da `_mkgmtime32` função é de 1º de janeiro de 1970, meia\-noite UTC para 23:59:59 18 de janeiro de 2038, UTC. O intervalo de `_mkgmtime64` é de 1º de janeiro de 1970, meia\-noite UTC a 23:59:59, 31 de dezembro de 3000, UTC. Uma data fora do intervalo resulta em um valor de retorno de\-1. O intervalo de `_mkgmtime` depende se `_USE_32BIT_TIME_T` está definido. Se não definido \(padrão\) o intervalo é de `_mkgmtime64`; caso contrário, o intervalo será limitado ao intervalo 32 bits de `_mkgmtime32`.  
  
 Observe que `gmtime` e `localtime` usam um único buffer alocado estaticamente para a conversão. Se você fornecer desse buffer `mkgmtime`, o conteúdo anterior é destruído.  
  
## Exemplo  
  
```  
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
  
## Saída de exemplo  
  
```  
Seconds since midnight, January 1, 1970  
My time: 1171588492  
GM time (UTC): 1171588492  
  
Local Time: Thu Feb 15 17:14:52 2007  
  
Greenwich Mean Time: Fri Feb 16 01:14:52 2007  
```  
  
 O exemplo a seguir mostra como a estrutura incompleta é preenchida com os valores calculados de dia da semana e dia do ano.  
  
```  
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
  
## Saída  
  
```  
Before calling _mkgmtime, t1 = Sun Feb 12 00:00:00 2003  
 t.tm_yday = 0  
After calling _mkgmtime, t1 = Wed Feb 12 00:00:00 2003  
 t.tm_yday = 42  
```  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)