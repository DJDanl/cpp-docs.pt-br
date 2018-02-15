---
title: pow, powf, powl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- powl
- pow
- powf
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
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- powl
- pow
- _powl
- powf
dev_langs:
- C++
helpviewer_keywords:
- exponential calculations
- powl function
- _powl function
- exponentiation
- powers, calculating
- calculating exponentials
- powf function
- pow function
ms.assetid: e75c33ed-2e59-48b1-be40-81da917324f1
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 09b618e557fffadd3bfffb431fc7e89458c4f420
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="pow-powf-powl"></a>pow, powf, powl
Calcula `x` elevado à potência de `y`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double pow(  
   double x,  
   double y   
);  
double pow(  
   double x,  
   int y  
);  // C++ only  
float pow(  
   float x,  
   float y   
);  // C++ only  
float pow(  
   float x,  
   int y  
);  // C++ only  
long double pow(  
   long double x,  
   long double y  
);  // C++ only  
long double pow(  
   long double x,  
   int y  
);  // C++ only  
float powf(  
   float x,  
   float y   
);  
long double powl(  
   long double x,  
   long double y  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Base.  
  
 `y`  
 Expoente.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o valor de `x`<sup>y</sup>. Nenhuma mensagem de erro é impressa em estouro ou estouro negativo.  
  
|Valores de x e y|Valor retornado de pow|  
|-----------------------|-------------------------|  
|`x` \< > 0 e `y` = 0.0|1|  
|`x` = 0.0 e `y` = 0.0|1|  
|`x` = 0.0 e `y` < 0|INF|  
  
## <a name="remarks"></a>Comentários  
 `pow` não reconhece valores de ponto flutuante integrais maiores que 2<sup>64</sup> (por exemplo, `1.0E100`).  
  
 `pow` tem uma implementação que usa SSE2 (Extensões SIMD de Streaming 2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](../../c-runtime-library/reference/set-sse2-enable.md).  
  
 Como C++ permite sobrecargas, você pode chamar qualquer uma das várias sobrecargas de `pow`. Em um programa C, `pow` sempre usa dois valores duplos e retorna um valor duplo.  
  
 A sobrecarga `pow(int, int)` não está mais disponível. Se você usar essa sobrecarga, o compilador poderá emitir C2668. Para evitar esse problema, converta o primeiro parâmetro para `double`, `float` ou `long double`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`pow`, `powf`, `powl`|\<math.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_pow.c  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x = 2.0, y = 3.0, z;  
  
   z = pow( x, y );  
   printf( "%.1f to the power of %.1f is %.1f\n", x, y, z );  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
2.0 to the power of 3.0 is 8.0  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [exp, expf, expl](../../c-runtime-library/reference/exp-expf.md)   
 [log, logf, log10, log10f](../../c-runtime-library/reference/log-logf-log10-log10f.md)   
 [sqrt, sqrtf, sqrtl](../../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)   
 [_CIpow](../../c-runtime-library/cipow.md)