---
title: copysign, copysignf, copysignl, _copysign, _copysignf, _copysignl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- copysignf
- copysignl
- _copysignl
- _copysign
- _copysignf
- copysign
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
- _copysignl
- copysign
- copysignf
- _copysign
- copysignl
- _copysignf
dev_langs: C++
helpviewer_keywords:
- copysignl function
- _copysignl function
- copysign function
- _copysignf function
- _copysign function
- copysignf function
ms.assetid: 009216d6-72a2-402d-aa6c-91d924b2c9e4
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 419b1a520ff7310dec7eda5b4d49d6f56df38b54
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="copysign-copysignf-copysignl-copysign-copysignf-copysignl"></a>copysign, copysignf, copysignl, _copysign, _copysignf, _copysignl
Retorna um valor que tem a magnitude de um argumento e o sinal de outro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double copysign(   
   double x,  
   double y   
);  
float copysign(   
   float x,  
   float y   
); // C++ only  
long double copysign(   
   long double x,  
   long double y   
); // C++ only  
float copysignf(   
   float x,  
   float y   
); // C++ only  
long double copysignl(   
   long double x,  
   long double y   
); // C++ only  
double _copysign(   
   double x,  
   double y   
);  
long double _copysignl(   
   long double x,  
   long double y   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 O valor de ponto flutuante retornado como a magnitude do resultado.  
  
 `y`  
 O valor de ponto flutuante retornado como o sinal do resultado.  
  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)  
  
## <a name="return-value"></a>Valor de retorno  
 As funções `copysign` retornam um valor de ponto flutuante que combina a magnitude de `x` e o sinal de `y`. Nenhum erro é retornado.  
  
## <a name="remarks"></a>Comentários  
 Como C++ permite sobrecargas, é possível chamar sobrecargas de `copysign` e que utilizam e retornam valores de `float` ou `long double`. Em um programa C, `copysign` sempre toma e retorna um `double`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_copysign`|\<float.h>|  
|`copysign`, `copysignf`, `copysignl`, `_copysignf`, `_copysignl`|\<math.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [fabs, fabsf, fabsl](../../c-runtime-library/reference/fabs-fabsf-fabsl.md)   
 [_chgsign, _chgsignf, _chgsignl](../../c-runtime-library/reference/chgsign-chgsignf-chgsignl.md)