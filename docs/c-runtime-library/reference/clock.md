---
title: clock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: d7deb43509e9d5b74d43006b81326a3fa0cbf09b
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="clock"></a>clock

Calcula a hora do relógio usada pelo processo de chamada.

## <a name="syntax"></a>Sintaxe

```C
clock_t clock( void );
```

## <a name="return-value"></a>Valor de retorno

O tempo decorrido desde a inicialização do CRT no início do processo, medido em **CLOCKS_PER_SEC** unidades por segundo. Se o tempo decorrido está indisponível ou excedeu o tempo máximo positivo que pode ser registrado como um **clock_t** tipo, a função retorna o valor `(clock_t)(-1)`.

## <a name="remarks"></a>Comentários

O **relógio** função informa quanto tempo de relógio se passou desde a inicialização do CRT durante a inicialização do processo. Observe que essa função não está estritamente em conformidade com ISO C, que especifica o tempo de CPU líquido como o valor retornado. Para obter tempos de CPU, use a função Win32 [GetProcessTimes](https://msdn.microsoft.com/library/windows/desktop/ms683223). Para determinar o tempo decorrido em segundos, divida o valor retornado pelo **relógio** função pela macro **CLOCKS_PER_SEC**.

Dado um tempo suficiente, o valor retornado por **relógio** pode exceder o máximo valor positivo de **clock_t**. Quando o processo ficou mais, o valor retornado por **relógio** é sempre `(clock_t)(-1)`, conforme especificado pelo padrão ISO C99 (7.23.2.1) e ISO C11 padrão (7.27.2.1). Microsoft implementa **clock_t** como um **longo**, um inteiro de 32 bits e o **CLOCKS_PER_SEC** macro está definida como 1.000. Isso permite um máximo **relógio** função de valor de retorno de 2147483.647 segundos ou sobre 24.8 dias. Não confie no valor retornado por **relógio** em processos executados por mais do que esse período de tempo. Você pode usar de 64 bits [tempo](time-time32-time64.md) função ou o Windows [QueryPerformanceCounter](https://msdn.microsoft.com/library/windows/desktop/ms644904) função tempo de processo de registro de muitos anos.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**clock**|\<time.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[difftime, _difftime32, _difftime64](difftime-difftime32-difftime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
