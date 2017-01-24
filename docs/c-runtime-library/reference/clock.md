---
title: "clock | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "clock"
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
  - "clock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "calculando tempo de processador usado"
  - "Função clock"
  - "tempo de processador usado"
  - "tempo de processador usado, calculando"
  - "hora, calculando processador"
ms.assetid: 3e1853dd-498f-49ba-b06a-f2315f20904e
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# clock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o tempo do relógio usado pelo processo de chamada.  
  
## Sintaxe  
  
```  
clock_t clock( void );  
```  
  
## Valor de retorno  
 A hora do relógio decorrido desde o início do processo \(tempo decorrido em tempos de segundos `CLOCKS_PER_SEC`\).  Se a quantidade de tempo decorrido estiver disponível, a função retorna – 1, convertido como um `clock_t`.  
  
## Comentários  
 O `clock` função informa quanto tempo do relógio usado pelo processo de chamada.  Observe que isso não é estritamente em conformidade com ISO C99, que especifica o tempo de CPU net como o valor de retorno.  Para obter o tempo de CPU, use o Win32 [GetProcessTimes](http://msdn.microsoft.com/library/windows/desktop/ms683223) função.  
  
 Um temporizador é aproximadamente igual a 1 \/`CLOCKS_PER_SEC` segundos.  Tendo tempo suficiente, o valor retornado por `clock` pode exceder o valor máximo positivo de `clock_t` e se torna negativa, ou exceder o máximo absoluto e passam.  Não confie nesse valor para o tempo total decorrido em processos executados por mais de 214,748 segundos ou aproximadamente 59 horas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`clock`|\<time.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_clock.c  
// This example prompts for how long  
// the program is to run and then continuously  
// displays the elapsed time for that period.  
//  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
void sleep( clock_t wait );  
  
int main( void )  
{  
   long    i = 6000000L;  
   clock_t start, finish;  
   double  duration;  
  
   // Delay for a specified time.  
   printf( "Delay for three seconds\n" );  
   sleep( (clock_t)3 * CLOCKS_PER_SEC );  
   printf( "Done!\n" );  
  
   // Measure the duration of an event.  
   printf( "Time to do %ld empty loops is ", i );  
   start = clock();  
   while( i-- )   
      ;  
   finish = clock();  
   duration = (double)(finish - start) / CLOCKS_PER_SEC;  
   printf( "%2.1f seconds\n", duration );  
}  
  
// Pauses for a specified number of milliseconds.  
void sleep( clock_t wait )  
{  
   clock_t goal;  
   goal = wait + clock();  
   while( goal > clock() )  
      ;  
}  
```  
  
  **Atraso de três segundos**  
**Concluído\!  Tempo para fazer 6000000 loops vazios é 0,1 segundos**    
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [difftime, \_difftime32, \_difftime64](../../c-runtime-library/reference/difftime-difftime32-difftime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)