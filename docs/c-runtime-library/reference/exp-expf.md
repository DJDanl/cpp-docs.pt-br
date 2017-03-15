---
title: exp, expf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- expf
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
- exp
dev_langs:
- C++
helpviewer_keywords:
- exponential calculations
- expf function
- calculating exponentials
- exp function
ms.assetid: 7070016d-1143-407e-9e9a-6b059bb88867
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 4f6fb2d2dc585633915587ff7b6e5cfbd69c4deb
ms.lasthandoff: 02/25/2017

---
# <a name="exp-expf"></a>exp, expf
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
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
## <a name="return-value"></a>Valor de retorno  
 A função `exp` retorna o valor exponencial do parâmetro de ponto flutuante, `x`, se for bem-sucedido. Ou seja, o resultado é e elevado a `x`, em que e é a base do logaritmo natural. No estouro, a função retorna INF (infinito) e, no estouro negativo, `exp` retorna 0.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-----------|-------------------|-----------------------|  
|± QNAN,IND|Nenhum|_DOMAIN|  
|± ∞|INVALID|_DOMAIN|  
|x ≥ 7,097827e+002|INEXACT+OVERFLOW|OVERFLOW|  
|X ≤ -7,083964e+002|INEXACT+UNDERFLOW|UNDERFLOW|  
  
 `exp` tem uma implementação que usa SSE2 (Extensões SIMD de Streaming 2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](../../c-runtime-library/reference/set-sse2-enable.md).  
  
## <a name="remarks"></a>Comentários  
 C++ permite sobrecargas, de modo que você pode chamar sobrecargas de `exp`. Em um programa C, `exp` sempre usa e retorna um duplo.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`exp`, `expf`|\<math.h>|  
  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::Math::Exp](https://msdn.microsoft.com/en-us/library/system.math.exp.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [log, logf, log10, log10f](../../c-runtime-library/reference/log-logf-log10-log10f.md)   
 [_CIexp](../../c-runtime-library/ciexp.md)
