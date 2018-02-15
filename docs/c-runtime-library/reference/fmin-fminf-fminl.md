---
title: fmin, fminf, fminl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- fmin
- fminf
- fminl
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
- fmin
- fminf
- fminl
- math/fmin
- math/fminf
- math/fminl
helpviewer_keywords:
- fmin function
- fminf function
- fminl function
ms.assetid: 1916dfb5-99c1-4b0d-aefb-513525c3f2ac
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d90de1e734b2d2da4770c7a5ad85a5ee60a15408
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fmin-fminf-fminl"></a>fmin, fminf, fminl
Determina o menor dos dois valores especificados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double fmin(  
   double x,   
   double y  
);  
  
float fmin(  
   float x,   
   float y  
); //C++ only  
  
long double fmin(  
   long double x,   
   long double y  
); //C++ only  
  
float fminf(  
   float x,   
   float y  
);  
  
long double fminl(  
   long double x,   
   long double y  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 O primeiro valor a ser comparado.  
  
 `y`  
 O segundo valor a ser comparado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará o menor entre `x` e `y`.  
  
|Entrada|Resultado|  
|-----------|------------|  
|`x` é NaN|`y`|  
|`y` é NaN|`x`|  
|`x` e `y` são NaN|NaN|  
  
 A função não faz com que [_matherr](../../c-runtime-library/reference/matherr.md) seja invocado, não causa exceções de ponto flutuante e não altera o valor de `errno`.  
  
## <a name="remarks"></a>Comentários  
 Uma vez que C++ permite sobrecargas, é possível chamar sobrecargas de `fmin` que utilizam e retornam tipos duplos flutuantes e longos. Em um programa C, `fmin` sempre usa e retorna um duplo.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`fmin`, `fminf`, `fminl`|C: \<math.h><br />C++: \<math.h> ou \<cmath>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  
 [fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)  