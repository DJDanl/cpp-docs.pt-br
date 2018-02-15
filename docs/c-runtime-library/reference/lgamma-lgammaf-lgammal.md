---
title: lgamma, lgammaf, lgammal | Microsoft Docs
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
- lgamma
- lgammaf
- lgammal
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
- lgamma
- lgammaf
- lgammal
- math/lgamma
- math/lgammaf
- math/lgammal
dev_langs:
- C++
helpviewer_keywords:
- lgamma function
- lgammal function
- lgammaf function
ms.assetid: 6e326c58-7077-481a-a329-c82ae56ae9e6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e7ef4a64252342484a1c6aa68722013f1e6bffdf
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="lgamma-lgammaf-lgammal"></a>lgamma, lgammaf, lgammal
Determina o logaritmo natural do valor absoluto da função gama do valor especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double lgamma(  
   double x  
);  
  
float lgamma(  
   float x  
); //C++ only  
  
long double lgamma(  
   long double x  
); //C++ only  
  
float lgammaf(  
   float x  
);  
  
long double lgammal(  
   long double x  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `x`  
 O valor a ser computado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará o logaritmo natural do valor absoluto da função gama de `x.`  
  
|Problema|Valor de|  
|-----------|------------|  
|`x` = NaN|NaN|  
|`x` = ±0|+INFINITY|  
|`x`= inteiro negativo|+INFINITY|  
|±INFINITY|+INFINITY|  
|erro de polo|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|  
|erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|  
  
 Os erros são relatados conforme especificado em [_matherr](../../c-runtime-library/reference/matherr.md).  
  
## <a name="remarks"></a>Comentários  
 Uma vez que C++ permite sobrecargas, é possível chamar sobrecargas de `lgamma` que utilizam e retornam tipos duplos flutuantes e longos. Em um programa C, `lgamma` sempre usa e retorna um duplo.  
  
 Se x for um número racional, essa função retornará o logaritmo do fatorial de (`x`-1).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`lgamma`,                `lgammaf`,  `lgammal`|\<math.h>|\<cmath>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [tgamma, tgammaf, tgammal](../../c-runtime-library/reference/tgamma-tgammaf-tgammal.md)