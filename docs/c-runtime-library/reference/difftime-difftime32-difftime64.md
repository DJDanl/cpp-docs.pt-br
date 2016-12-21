---
title: "difftime, _difftime32, _difftime64 | Microsoft Docs"
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
  - "_difftime32"
  - "difftime"
  - "_difftime64"
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
  - "_difftime64"
  - "difftime"
  - "difftime64"
  - "_difftime32"
  - "difftime32"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _difftime32"
  - "Função difftime"
  - "hora, localizando a diferença"
  - "Função difftime64"
  - "Função _difftime64"
  - "Função difftime32"
ms.assetid: 4cc0ac2b-fc7b-42c0-8283-8c9d10c566d0
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# difftime, _difftime32, _difftime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Localiza a diferença entre duas vezes.  
  
## Sintaxe  
  
```  
double difftime(   
   time_t timer1,  
   time_t timer0   
);  
double _difftime32(   
   __time32_t timer1,  
   __time32_t timer0   
);  
double _difftime64(   
   __time64_t timer1,  
   __time64_t timer0   
);  
```  
  
#### Parâmetros  
 `timer1`  
 Hora de término.  
  
 `timer0`  
 Hora de início.  
  
## Valor de retorno  
 `difftime` Retorna o tempo decorrido em segundos, de `timer0` para `timer1`. O valor retornado é um número de ponto flutuante de precisão dupla. O valor de retorno pode ser 0, indicando um erro.  
  
## Comentários  
 O `difftime` função calcula a diferença entre os dois valores de tempo fornecido `timer0` e `timer1`.  
  
 O valor de tempo fornecido deve se ajustar dentro do intervalo de `time_t`.`time_t` é um valor de 64 bits. Portanto, o fim do intervalo foi estendido de 23:59:59 18 de janeiro de 2038, UTC a 23:59:59, 31 de dezembro de 3000. O intervalo inferior do `time_t` ainda é meia\-noite de 1º de janeiro de 1970.  
  
 `difftime` é uma função embutida que é avaliada como `_difftime32` ou `_difftime64` dependendo se `_USE_32BIT_TIME_T` está definido. difftime32 e difftime64 podem ser usados diretamente para forçar o uso de um determinado tamanho do tipo hora.  
  
 Essas funções validam seus parâmetros. Se os parâmetros é zero ou negativo, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornam 0 e defina `errno` para `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`difftime`|\< h \>|  
|`_difftime32`|\< h \>|  
|`_difftime64`|\< h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
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
Uso de ponto flutuante aleatório números 1.04749e + 038 2.01482e + 038 1.72737e + 038Multiplying 2 de ponto flutuante números 100 milhões de vezes... Programa usa 3 segundos. Multiplicação 2 flutuante aponte números 500 milhões de vezes... Programa demora 5 segundos.  
```  
  
## Equivalência do .NET Framework  
 [System::DateTime:: subtrair](https://msdn.microsoft.com/en-us/library/system.datetime.subtract.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)