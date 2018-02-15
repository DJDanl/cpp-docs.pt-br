---
title: abs, labs, llabs, _abs64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- abs
- _abs64
- labs
- llabs
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
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- stdlib/_abs64
- math/abs
- _abs64
- abs
- labs
- math/labs
- llabs
- math/llabs
- cmath/abs
dev_langs:
- C++
helpviewer_keywords:
- absolute values
- abs function
- abs64 function
- _abs64 function
- calculating absolute values
ms.assetid: 60f789d1-4a1e-49f5-9e4e-0bdb277ea26a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1dc1e7532c715a045c2b76c3be2ef915f82693a1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="abs-labs-llabs-abs64"></a>abs, labs, llabs, _abs64
Calcula o valor absoluto do argumento.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `n`  
 Valor numérico.  
  
## <a name="return-value"></a>Valor de retorno  
 As funções `abs`, `labs`, `llabs` e `_abs64` retornam o valor absoluto do parâmetro `n`. Nenhum erro é retornado.  
  
## <a name="remarks"></a>Comentários  
 Como C++ permite sobrecarga, é possível chamar sobrecargas de `abs` que usam e retornam valores `long`, `long long`, `float`, `double` e `long double`. Essas sobrecargas são definidas no cabeçalho \<cmath>. Em um programa C, `abs` sempre usa e retorna um int.  
  
 **Seção específica da Microsoft**  
  
 Como o intervalo de inteiros negativos que podem ser representados usando qualquer tipo integral é maior que o intervalo de inteiros positivos que podem ser representados usando esse tipo, é possível fornecer para essas funções um argumento que não possa ser convertido. Se o valor absoluto do argumento não puder ser representado pelo tipo de retorno, as funções `abs` retornarão o valor do argumento inalterado. Especificamente, `abs(INT_MIN)` retorna `INT_MIN`, `labs(LONG_MIN)` retorna `LONG_MIN`, `llabs(LLONG_MIN)` retorna `LLONG_MIN` e `_abs64(_I64_MIN)` retorna `_I64_MIN`. Isso significa que as funções `abs` não podem ser usadas para assegurar um valor positivo.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|  
|-------------|-----------------------|---------------------------|  
|`abs`, `labs`, `llabs`|\<math.h> ou \<stdlib.h>|\<cmath>, \<cstdlib>, \<stdlib.h> ou \<math.h>|  
|`_abs64`|\<stdlib.h>|\<cstdlib> ou \<stdlib.h>|  
  
 Para usar as versões sobrecarregadas do `abs` no C++, você deve incluir o cabeçalho \<cmath>.  
  
## <a name="example"></a>Exemplo  
 O programa calcula e exibe os valores absolutos de vários números.  
  
```C  
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
The absolute value of -4 is 4  
The absolute value of -41567 is 41567  
The absolute value of -9876543210 is 9876543210  
The absolute value of 0xffffffffffffffff is 0x0000000000000001  
Microsoft implementation-specific results:  
 abs(INT_MIN) returns -2147483648  
 labs(LONG_MIN) returns -2147483648  
 llabs(LLONG_MIN) returns -9223372036854775808  
 _abs64(_I64_MIN) returns 0x8000000000000000  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_cabs](../../c-runtime-library/reference/cabs.md)   
 [fabs, fabsf, fabsl](../../c-runtime-library/reference/fabs-fabsf-fabsl.md)   
 [imaxabs](../../c-runtime-library/reference/imaxabs.md)
