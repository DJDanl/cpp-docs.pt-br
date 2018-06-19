---
title: difftime, _difftime32, _difftime64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _difftime32
- difftime
- _difftime64
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
- _difftime64
- difftime
- difftime64
- _difftime32
- difftime32
dev_langs:
- C++
helpviewer_keywords:
- _difftime32 function
- difftime function
- time, finding the difference
- difftime64 function
- _difftime64 function
- difftime32 function
ms.assetid: 4cc0ac2b-fc7b-42c0-8283-8c9d10c566d0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a972a8f7ee2cc5e97c22afeaa21f86e4b4d6d509
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32398715"
---
# <a name="difftime-difftime32-difftime64"></a>difftime, _difftime32, _difftime64

Encontra a diferença entre duas vezes.

## <a name="syntax"></a>Sintaxe

```C
double difftime( time_t timeEnd, time_t timeStart );
double _difftime32( __time32_t timeEnd, __time32_t timeStart );
double _difftime64( __time64_t timeEnd, __time64_t timeStart );
```

### <a name="parameters"></a>Parâmetros

*InícioHorário de término*<br/>
Hora de término.

*TimeStart*<br/>
Hora de início.

## <a name="return-value"></a>Valor de retorno

**difftime** retorna o tempo decorrido em segundos, de *timeStart* para *inícioHorário de término*. O valor retornado é um número de ponto flutuante de precisão dupla. O valor retornado pode ser 0, indicando um erro.

## <a name="remarks"></a>Comentários

O **difftime** função calcula a diferença entre os dois valores de tempo fornecido *timeStart* e *inícioHorário de término*.

O valor de tempo fornecido deve se ajustar dentro do intervalo de **time_t**. **time_t** é um valor de 64 bits. Portanto, o fim do intervalo foi estendido de 23:59:59, 18 de janeiro de 2038, UTC até 23:59:59, 31 de dezembro de 3000. O intervalo inferior do **time_t** ainda é meia-noite de 1º de janeiro de 1970.

**difftime** é uma função embutida que é avaliada como **difftime32** ou **difftime64** dependendo se **_USE_32BIT_TIME_T** está definido. _difftime32 e _difftime64 podem ser usados diretamente para forçar o uso de determinado tamanho do tipo de hora.

Essas funções validam seus parâmetros. Se um dos parâmetros for zero ou negativo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam 0 e defina **errno** para **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**difftime**|\<time.h>|
|**_difftime32**|\<time.h>|
|**_difftime64**|\<time.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_difftime.c
// This program calculates the amount of time
// needed to do a floating-point multiply 100 million times.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

double RangedRand( float range_min, float range_max)
{
   // Generate random numbers in the half-closed interval
   // [range_min, range_max). In other words,
   // range_min <= random number < range_max
   return ((double)rand() / (RAND_MAX + 1) * (range_max - range_min)
            + range_min);
}

int main( void )
{
   time_t   start, finish;
   long     loop;
   double   result, elapsed_time;
   double   arNums[3];

   // Seed the random-number generator with the current time so that
   // the numbers will be different every time we run.
   srand( (unsigned)time( NULL ) );

   arNums[0] = RangedRand(1, FLT_MAX);
   arNums[1] = RangedRand(1, FLT_MAX);
   arNums[2] = RangedRand(1, FLT_MAX);
   printf( "Using floating point numbers %.5e %.5e %.5e\n", arNums[0], arNums[1], arNums[2] );

   printf( "Multiplying 2 numbers 100 million times...\n" );

   time( &start );
   for( loop = 0; loop < 100000000; loop++ )
      result = arNums[loop%3] * arNums[(loop+1)%3];
   time( &finish );

   elapsed_time = difftime( finish, start );
   printf( "\nProgram takes %6.0f seconds.\n", elapsed_time );
}

```

```Output
Using random floating point numbers 1.04749e+038 2.01482e+038 1.72737e+038Multiplying 2 floating point numbers 100 million times...Program takes      3 seconds.Multiplying 2 floating point numbers 500 million times...

Program takes      5 seconds.
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
