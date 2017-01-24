---
title: "Abs, laborat&#243;rios, llabs, abs64 | Microsoft Docs"
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
  - "abs"
  - "_abs64"
  - "labs"
  - "llabs"
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
  - "api-ms-win-crt-utility-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "stdlib/_abs64"
  - "math/abs"
  - "_abs64"
  - "abs"
  - "labs"
  - "math/labs"
  - "llabs"
  - "math/llabs"
  - "cmath/abs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "valores absolutos"
  - "Função abs"
  - "Função abs64"
  - "Função _abs64"
  - "calculando valores absolutos"
ms.assetid: 60f789d1-4a1e-49f5-9e4e-0bdb277ea26a
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Abs, laborat&#243;rios, llabs, abs64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o valor absoluto do argumento.  
  
## Sintaxe  
  
```  
int abs(   
   int n   
);  
long abs(   
   long n   
);   // C++ only  
long long abs(   
   long long n   
);   // C++ only  
double abs(   
   double n   
);   // C++ only  
long double abs(  
   long double n  
);   // C++ only  
float abs(  
   float n   
);   // C++ only  
long labs(  
   long n   
);  
long long llabs(  
   long long n   
);  
__int64 _abs64(   
   __int64 n   
);  
```  
  
#### Parâmetros  
 `n`  
 Valor numérico.  
  
## Valor de retorno  
 O `abs`, `labs`, `llabs` e `_abs64` funções retornam o valor absoluto do parâmetro `n`. Não há nenhum retorno de erro.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `abs` que tomam e retornam `long`, `long long`, `float`, `double`, e `long double` valores. Essas sobrecargas são definidas no cabeçalho \< cmath \>. Em um programa C, `abs` sempre toma e retorna um inteiro.  
  
 **Específico da Microsoft**  
  
 Como o intervalo de inteiros negativos que podem ser representados usando qualquer tipo integral é maior que o intervalo de números inteiros positivos que podem ser representados por meio desse tipo, é possível fornecer um argumento para essas funções não podem ser convertidos. Se o valor absoluto do argumento não pode ser representado pelo tipo de retorno, o `abs` funções retornam o valor do argumento inalterado. Especificamente, `abs(INT_MIN)` retorna `INT_MIN`, `labs(LONG_MIN)` retorna `LONG_MIN`, `llabs(LLONG_MIN)` retorna `LLONG_MIN`, e `_abs64(_I64_MIN)` retorna `_I64_MIN`. Isso significa que o `abs` funções não podem ser usadas para garantir um valor positivo.  
  
 **Fim de específico da Microsoft**  
  
## Requisitos  
  
|Rotina|Cabeçalho C necessário|Cabeçalho C\+\+ necessário|  
|------------|----------------------------|--------------------------------|  
|`abs`, `labs`, `llabs`|\< Math \> ou \< stdlib. h \>|\< cmath \>, \< cstdlib \>, \< stdlib. h \> ou \< Math \>|  
|`_abs64`|\< stdlib. h \>|\< cstdlib \> ou \< stdlib. h \>|  
  
 Para usar as versões sobrecarregadas dos `abs` em C\+\+, você deve incluir o cabeçalho \< cmath \>.  
  
## Exemplo  
 O programa calcula e exibe os valores absolutos de vários números.  
  
```c  
// crt_abs.c  
// Build: cl /W3 /TC crt_abs.c  
// This program demonstrates the use of the abs function  
// by computing and displaying the absolute values of  
// several numbers.  
  
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include <limits.h>  
  
int main( void )  
{  
    int ix = -4;  
    long lx = -41567L;  
    long long llx = -9876543210LL;  
    __int64 wx = -1;  
  
    // absolute 32 bit integer value  
    printf_s("The absolute value of %d is %d\n", ix, abs(ix));  
  
    // absolute long integer value  
    printf_s("The absolute value of %ld is %ld\n", lx, labs(lx));  
  
    // absolute long long integer value  
    printf_s("The absolute value of %lld is %lld\n", llx, llabs(llx));  
  
    // absolute 64 bit integer value  
    printf_s("The absolute value of 0x%.16I64x is 0x%.16I64x\n", wx,   
        _abs64(wx));  
  
    // Integer error cases:  
    printf_s("Microsoft implementation-specific results:\n");  
    printf_s(" abs(INT_MIN) returns %d\n", abs(INT_MIN));  
    printf_s(" labs(LONG_MIN) returns %ld\n", labs(LONG_MIN));  
    printf_s(" llabs(LLONG_MIN) returns %lld\n", llabs(LLONG_MIN));  
    printf_s(" _abs64(_I64_MIN) returns 0x%.16I64x\n", _abs64(_I64_MIN));  
}  
```  
  
```Output  
O valor absoluto de -4 é 4 o valor absoluto de-41567 é 41567 o valor absoluto de-9876543210 é 9876543210 é o valor absoluto de 0xffffffffffffffff 0x0000000000000001 resultados de implementação específica da Microsoft: abs(INT_MIN) retorna -2147483648 labs(LONG_MIN) retorna -2147483648 llabs(LLONG_MIN) retorna -9223372036854775808 _abs64(_I64_MIN) retorna 0x8000000000000000  
  
```  
  
## Equivalência do .NET Framework  
 [System::Math::ABS](https://msdn.microsoft.com/en-us/library/system.math.abs.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_cabs](../Topic/_cabs.md)   
 [fabs, fabsf, fabsl](../../c-runtime-library/reference/fabs-fabsf-fabsl.md)   
 [imaxabs](../Topic/imaxabs.md)