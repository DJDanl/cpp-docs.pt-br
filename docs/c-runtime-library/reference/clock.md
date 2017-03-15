---
title: clock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- clock
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
- clock
dev_langs:
- C++
helpviewer_keywords:
- processor time used, calculating
- time, calculating processor
- clock function
- processor time used
- calculating processor time used
ms.assetid: 3e1853dd-498f-49ba-b06a-f2315f20904e
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3a226377499df1747a022325b762b3cdfdd35ea6
ms.lasthandoff: 02/25/2017

---
# <a name="clock"></a>clock
Calcula a hora do relógio usada pelo processo de chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
clock_t clock( void );  
```  
  
## <a name="return-value"></a>Valor retornado  
O tempo decorrido desde a inicialização do CRT no início do processo, medido em `CLOCKS_PER_SEC` unidades por segundo. Se o tempo decorrido não estiver disponível ou tiver excedido o tempo máximo positivo que pode ser gravado como um tipo `clock_t`, a função retornará o valor `(clock_t)(-1)`.   
  
## <a name="remarks"></a>Comentários  
A função `clock` informa quantas horas do relógio se passaram desde a inicialização do CRT durante o início do processo. Observe que essa função não está estritamente em conformidade com ISO C, que especifica o tempo de CPU líquido como o valor retornado. Para obter tempos de CPU, use a função Win32 [GetProcessTimes](https://msdn.microsoft.com/library/windows/desktop/ms683223). Para determinar o tempo decorrido em segundos, divida o valor retornado pela função `clock` pela macro `CLOCKS_PER_SEC`.  
  
Com tempo suficiente, o valor retornado por `clock` poderá exceder o valor máximo positivo de `clock_t`. Quando o processo tiver sido executado por mais tempo, o valor retornado por `clock` sempre será `(clock_t)(-1)`, conforme especificado pelo padrão ISO C99 (7.23.2.1) e ISO C11 (7.27.2.1). A Microsoft implementa `clock_t` como uma `long`, um inteiro assinado de 32 bits e a macro `CLOCKS_PER_SEC` é definida como 1.000. Isso gera um valor retornado de função `clock` máximo de 2147483,647 segundos ou cerca de 24,8 dias. Não dependa do valor retornado por `clock` em processos que tenham sido executados por mais tempo que esse período. Você pode usar a função `time` de 64 bits ou a função [QueryPerformanceCounter](https://msdn.microsoft.com/library/windows/desktop/ms644904) do Windows para registrar tempos de processo decorridos de muitos anos.  

## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`clock`|\<time.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_clock.c  
// This sample uses clock() to 'sleep' for three 
// seconds, then determines how long it takes  
// to execute an empty loop 600000000 times.  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
// Pauses for a specified number of milliseconds.  
void do_sleep( clock_t wait )  
{  
   clock_t goal;  
   goal = wait + clock();  
   while( goal > clock() )  
      ;  
}  
  
const long num_loops = 600000000L;

int main( void )  
{  
   long    i = num_loops;  
   clock_t start, finish;  
   double  duration;  
  
   // Delay for a specified time.  
   printf( "Delay for three seconds\n" );  
   do_sleep( (clock_t)3 * CLOCKS_PER_SEC );  
   printf( "Done!\n" );  
  
   // Measure the duration of an event.  
   start = clock();  
   while( i-- )   
      ;  
   finish = clock();  
   duration = (double)(finish - start) / CLOCKS_PER_SEC;  
   printf( "Time to do %ld empty loops is ", num_loops );  
   printf( "%2.3f seconds\n", duration );  
}  
```  
  
```Output  
Delay for three seconds  
Done!  
Time to do 600000000 empty loops is 1.354 seconds  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [difftime, _difftime32, _difftime64](../../c-runtime-library/reference/difftime-difftime32-difftime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)
