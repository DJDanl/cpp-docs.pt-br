---
title: clock
ms.date: 11/04/2016
api_name:
- clock
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- clock
helpviewer_keywords:
- processor time used, calculating
- time, calculating processor
- clock function
- processor time used
- calculating processor time used
ms.assetid: 3e1853dd-498f-49ba-b06a-f2315f20904e
ms.openlocfilehash: 836d0c6448adb4c99a251a0e97aa642e30362dcb
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939125"
---
# <a name="clock"></a>clock

Calcula a hora do relógio usada pelo processo de chamada.

## <a name="syntax"></a>Sintaxe

```C
clock_t clock( void );
```

## <a name="return-value"></a>Valor de retorno

O tempo decorrido desde a inicialização do CRT no início do processo, medido em unidades de **CLOCKS_PER_SEC** por segundo. Se o tempo decorrido estiver indisponível ou excedeu o tempo máximo positivo que pode ser registrado como um tipo **clock_t** , a função retornará o valor `(clock_t)(-1)`.

## <a name="remarks"></a>Comentários

A função **Clock** informa quanto tempo do relógio de parede passou desde a inicialização do CRT durante o início do processo. Observe que essa função não está estritamente em conformidade com ISO C, que especifica o tempo de CPU líquido como o valor retornado. Para obter tempos de CPU, use a função Win32 [GetProcessTimes](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocesstimes). Para determinar o tempo decorrido em segundos, divida o valor retornado pela função **Clock** pela macro **CLOCKS_PER_SEC**.

Dado tempo suficiente, o valor retornado pelo **relógio** pode exceder o valor máximo positivo de **clock_t**. Quando o processo tiver sido executado mais tempo, o valor retornado pelo relógio `(clock_t)(-1)`será sempre, conforme especificado pelo C99 padrão ISO (7.23.2.1) e pelo padrão ISO C11 (7.27.2.1). A Microsoft implementa **clock_t** como um **longo**, um inteiro de 32 bits assinado e a macro **CLOCKS_PER_SEC** é definida como 1000. Isso fornece um valor de retorno de função de **relógio** máximo de 2147483,647 segundos ou cerca de 24,8 dias. Não confie no valor retornado pelo **relógio** em processos que foram executados por mais tempo do que esse período. Você pode usar a função de [tempo](time-time32-time64.md) de 64 bits ou a função [QueryPerformanceCounter](/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter) do Windows para registrar tempos decorridos do processo de muitos anos.

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
