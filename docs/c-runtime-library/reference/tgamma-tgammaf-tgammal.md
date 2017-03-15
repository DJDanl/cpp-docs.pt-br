---
title: tgamma, tgammaf, tgammal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- tgamma
- tgammaf
- tgammal
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
- tgamma
- tgammaf
- tgammal
- math/tgamma
- math/tgammaf
- math/tgammal
dev_langs:
- C++
helpviewer_keywords:
- tgamma function
- tgammaf function
- tgammal function
ms.assetid: f1bd2681-8af2-48a9-919d-5358fd068acd
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1418ef72ccc2bb374997e8e266fc2db1e778bca6
ms.lasthandoff: 02/25/2017

---
# <a name="tgamma-tgammaf-tgammal"></a>tgamma, tgammaf, tgammal
Determina a função gama do valor especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double tgamma(  
   double x  
);  
  
float tgamma(  
   float x  
); //C++ only  
  
long double tgamma(  
   long double x  
); //C++ only  
  
float tgammaf(  
   float x  
);  
  
long double tgammal(  
   long double x  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `x`  
 O valor do qual o gama será encontrado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se tiver êxito, retornará o gama de `x`.  
  
 Poderá ocorrer um erro de intervalo se a magnitude de `x` for muito grande ou muito pequena para o tipo de dados. Um erro de domínio ou de intervalo poderá ocorrer se `x` <=0.  
  
|Problema|Valor de|  
|-----------|------------|  
|x = ±0|±INFINITY|  
|x = inteiro negativo|NaN|  
|x =  -INFINITY|NaN|  
|x = +INFINITY|+INFINITY|  
|x = NaN|NaN|  
|erro de domínio|NaN|  
|erro de polo|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|  
|erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|  
|erro de intervalo de estouro negativo|o valor correto, após o arredondamento.|  
  
 Os erros são relatados conforme especificado em [_matherr](../../c-runtime-library/reference/matherr.md).  
  
## <a name="remarks"></a>Comentários  
 Como o C++ permite sobrecarga, é possível chamar sobrecargas de tgamma que usam e retornam tipos duplos flutuantes e longos. Em um programa C, tgamma sempre usa e retorna um duplo.  
  
 Se x for um número natural, essa função retornará o fatorial de (x-1).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`tgamma`,                `tgammaf`,  `tgammal`|\<math.h>|\<cmath>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [lgamma, lgammaf, lgammal](../../c-runtime-library/reference/lgamma-lgammaf-lgammal.md)
