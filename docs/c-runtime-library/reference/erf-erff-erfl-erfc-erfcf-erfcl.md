---
title: erf, erff, erfl, erfc, erfcf, erfcl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- erff
- erfl
- erf
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
- erfl
- erf
- erff
dev_langs:
- C++
helpviewer_keywords:
- erfl function
- erff function
- erf function
ms.assetid: 144d90d3-e437-41c2-a659-cd57596023b5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fa60c6bb6c3c11a596589a411a7d094cc41c65fa
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="erf-erff-erfl-erfc-erfcf-erfcl"></a>erf, erff, erfl, erfc, erfcf, erfcl
Computa a função de erro ou a função de erro complementar de um valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double erf(  
   double x  
);  
float erf(  
   float x  
); // C++ only  
long double erf(  
   long double x  
); // C++ only  
float erff(  
   float x  
);  
long double erfl(  
   long double x  
);  
double erfc(  
   double x  
);  
float erfc(  
   float x  
); // C++ only  
long double erfc(  
   long double x  
); // C++ only  
float erfcf(  
   float x  
);  
long double erfcl(  
   long double x  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Um valor de ponto flutuante.  
  
## <a name="return-value"></a>Valor de retorno  
 As funções `erf` retornam a função de erro em Gauss de `x`. As funções `erfc` retornam a função de erro complementar em Gauss de `x`.  
  
## <a name="remarks"></a>Comentários  
 As funções `erf` calculam a função de erro em Gauss de x, definida como:  
  
 ![A função de erro de x](../../c-runtime-library/reference/media/crt_erf_formula.PNG "CRT_erf_formula")  
  
 A função de erro Gauss complementar é definida como 1 - erf(x). As funções `erf` retornam um valor no intervalo de -1,0 a 1,0. Nenhum erro é retornado. As funções `erfc` retornam um valor no intervalo de 0 a 2. Se `x` for grande demais para `erfc`, a variável `errno` é definida como `ERANGE`.  
  
 Como C++ permite sobrecargas, é possível chamar sobrecargas de `erf` e `erfc` que tomam e retornam tipos `float` e `long double`. Em um programa C, `erf` e `erfc` sempre tomam e retornam um `double`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`erf`, `erff`, `erfl`, `erfc`, `erfcf`, `erfcl`|\<math.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)