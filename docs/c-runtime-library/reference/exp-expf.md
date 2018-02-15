---
title: exp, expf, expl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- expf
- expl
- exp
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
- _expl
- expf
- expl
- exp
dev_langs:
- C++
helpviewer_keywords:
- exponential calculations
- expf function
- expl function
- calculating exponentials
- exp function
ms.assetid: 7070016d-1143-407e-9e9a-6b059bb88867
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 95d84c81b8f6cc5ea99cd6153da73ea0e96167b8
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="exp-expf-expl"></a>exp, expf, expl
Calcula o exponencial.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double exp(   
   double x  
);  
float exp(  
   float x  
);  // C++ only  
long double exp(  
   long double x  
);  // C++ only  
float expf(   
   float x  
);  
long double expl(  
   long double x  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `x`  
 Valor de ponto flutuante para exponentiate a base do logaritmo natural *e* por.  
  
## <a name="return-value"></a>Valor de retorno  
 O `exp` funções retornam o valor exponencial do parâmetro de ponto flutuante, *x*, se for bem-sucedido. Ou seja, o resultado é *e*<sup>*x*</sup>, onde *e* é a base do logaritmo natural. Estouro, a função retorna INF (infinito) e estouro negativo, `exp` retornará 0.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-----------|-------------------|-----------------------|  
|± Silencioso NaN, indeterminado|Nenhum|_DOMAIN|  
|± Infinito|INVALID|_DOMAIN|  
|x ≥ 7,097827e+002|INEXACT+OVERFLOW|OVERFLOW|  
|X ≤ -7,083964e+002|INEXACT+UNDERFLOW|UNDERFLOW|  
  
 O `exp` função tem uma implementação que usa extensões Streaming SIMD 2 (SSE2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](../../c-runtime-library/reference/set-sse2-enable.md).  
  
## <a name="remarks"></a>Comentários  
 O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de `exp` que levam um **float** ou **long double** argumento. Em um programa C, `exp` sempre usa e retorna um **duplo**.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C necessário|Cabeçalho C++ necessário|  
|--------------|---------------------|---|  
|`exp`, `expf`|\<math.h>|\<cmath> ou \<math.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_exp.c  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x = 2.302585093, y;  
  
   y = exp( x );  
   printf( "exp( %f ) = %f\n", x, y );  
}  
```  
  
```Output  
exp( 2.302585 ) = 10.000000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [log, logf, log10, log10f](../../c-runtime-library/reference/log-logf-log10-log10f.md)   
 [_CIexp](../../c-runtime-library/ciexp.md)