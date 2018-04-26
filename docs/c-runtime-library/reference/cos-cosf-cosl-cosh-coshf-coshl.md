---
title: cos, cosf, cosl, cosh, coshf, coshl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- coshl
- cosh
- cos
- cosl
- cosf
- coshf
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
- coshl
- cos
- cosf
- cosh
- cosl
- coshf
dev_langs:
- C++
helpviewer_keywords:
- cosines
- cosl function
- calculating cosine
- cosf function
- cos function
- cosh function
- coshf function
- trigonometric functions
- cosines, calculating
- coshl function
- hyperbolic functions
ms.assetid: ae90435e-6b68-4a47-a81f-be87d5c08f16
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b9ef8330842f090c5a63cfea65886e6b7c25cee3
ms.sourcegitcommit: 9a3a3d59176043ae60584482c2572c07f757b320
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/19/2018
---
# <a name="cos-cosf-cosl-cosh-coshf-coshl"></a>cos, cosf, cosl, cosh, coshf, coshl
Calcula o cosseno (`cos`, `cosf` ou `cosl`) ou o cosseno hiperbólico (`cosh`, `coshf` ou `coshl`).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double cos(   
   double x   
);  
float cos(  
   float x   
);  // C++ only  
long double cos(  
   long double x  
);  // C++ only  
float cosf(   
   float x   
);  
long double cosl(  
   long double x  
);  
double cosh(   
   double x   
);  
float cosh(  
   float x   
);  // C++ only  
long double cosh(  
   long double x  
);  // C++ only  
float coshf(  
   float x   
);  
long double coshl(  
   long double x  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Ângulo em radianos.  
  
## <a name="return-value"></a>Valor de retorno  
 O cosseno ou o cosseno hiperbólico de `x`. Se `x` é maior que ou igual a 263, ou menor ou igual a -263, perda de significância no resultado de uma chamada para `cos`, `cosf`, ou `cosl` ocorre.  
  
 Por padrão, se o resultado for muito grande em uma chamada a `cosh`, `coshf` ou `coshl`, a função retornará `HUGE_VAL` e definirá `errno` como `ERANGE`.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-----------|-------------------|-----------------------|  
|± `QNAN`,`IND`|nenhum|`_DOMAIN`|  
|± ∞ (`cosf`, `cos`, `cosl`)|`INVALID`|`_DOMAIN`|  
|x ≥ 7,104760e+002 (`cosh`, `coshf`, `coshl`)|`INEXACT`+`OVERFLOW`|`OVERFLOW`|  
  
## <a name="remarks"></a>Comentários  
 Como o C++ permite sobrecarga, é possível chamar sobrecargas de `cos` e `cosh` que usam e retornam os valores `float` ou `long double`. Em um programa C, `cos` e `cosh` sempre tomam e retornam um `double`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`cos`, `cosh`, `cosf`, `coshf`, `cosl`, `coshl`|\<math.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo em [sin, sinf, sinl, sinh, sinhf, sinhl](../../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [acos, acosf, acosl](../../c-runtime-library/reference/acos-acosf-acosl.md)   
 [asin, asinf, asinl](../../c-runtime-library/reference/asin-asinf-asinl.md)   
 [atan, atanf, atanl, atan2, atan2f, atan2l](../../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)   
 [_matherr](../../c-runtime-library/reference/matherr.md)   
 [sin, sinf, sinl, sinh, sinhf, sinhl](../../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)   
 [tan, tanf, tanl, tanh, tanhf, tanhl](../../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)   
 [_CIcos](../../c-runtime-library/cicos.md)