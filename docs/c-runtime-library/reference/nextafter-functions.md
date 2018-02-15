---
title: nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- nextafterf
- _nextafterf
- nextafter
- nextafterl
- _nextafter
- nexttoward
- nexttowardf
- nexttowardl
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
- nextafter
- _nextafter
- nextafterf
- nextafterl
- _nextafterf
- math/nextafter
- math/nextafterf
- math/nextafterl
- nexttoward
- nexttowardf
- nexttowardl
- math/nexttoward
- math/nexttowardf
- math/nexttowardl
dev_langs:
- C++
helpviewer_keywords:
- _nextafter function
- nextafter function
- _nextafterf function
- nextafterf function
- nextafterl function
- nexttoward function
- nexttowardf function
- nexttowardl function
ms.assetid: 9785bfb9-de53-4bd0-9637-f05fa0c1f6ab
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a4fe078e00b28f09284f3b91ad93ee1393bea108
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="nextafter-nextafterf-nextafterl-nextafter-nextafterf-nexttoward-nexttowardf-nexttowardl"></a>nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl
Retorna o próximo valor de ponto flutuante representável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double nextafter(  
   double x,  
   double y   
);  
  
float nextafter(  
   float x,  
   float y   
); /* C++ only, requires <cmath> */  
  
long double nextafter(  
   long double x,  
   long double y   
); /* C++ only, requires <cmath> */  
  
float nextafterf(  
   float x,  
   float y   
);   
  
long double nextafterl(  
   long double x,  
   long double y   
);  
  
double _nextafter(  
   double x,  
   double y   
);  
  
float _nextafterf(  
   float x,  
   float y   
); /* x64 only */  
  
double nexttoward(  
   double x,  
   long double y   
);  
  
float nexttoward(  
   float x,  
   long double y   
); /* C++ only, requires <cmath> */  
  
long double nexttoward(  
   long double x,  
   long double y   
); /* C++ only, requires <cmath> */  
  
float nexttowardf(  
   float x,  
   long double y   
);   
  
long double nexttowardl(  
   long double x,  
   long double y   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 O valor do ponto flutuante a ser iniciado.  
  
 `y`  
 O valor do ponto flutuante a ser destinado.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o próximo valor de ponto flutuante representável do tipo de retorno após `x` na direção de `y`. Se `x`=`y`, a função retornará `y`, convertido para o tipo de retorno, com nenhuma exceção acionada. Se `x` não for igual a `y` e o resultado for um denormal ou zero, os estados de exceção de ponto flutuante FE_UNDERFLOW e FE_INEXACT serão definidos e o resultado correto será retornado. Se `x` ou `y` for um NAN, o valor retornado será um dos NANs de entrada. Se `x` for finito e o resultado for infinito ou não representável no tipo, um infinito corretamente assinado ou NAN será retornado, os estados de exceção de ponto flutuante FE_OVERFLOW e FE_INEXACT serão definidos e `errno` será definido como ERANGE.  
  
## <a name="remarks"></a>Comentários  
 As famílias de função `nextafter` e `nexttoward` são equivalentes, exceto o tipo de parâmetro de `y`. Se `x` e `y` forem iguais, o valor retornado será `y` convertido para o tipo de retorno.  
  
 Como C++ permite sobrecargas, se você incluir \<cmath> será possível chamar sobrecargas de `nextafter` e `nexttoward` que retornam os tipos `float` e `long double`. Em um programa C, `nextafter` e `nexttoward` sempre retornam `double`.  
  
 As funções `_nextafter` e `_nextafterf` são específicas da Microsoft. A função `_nextafterf` só está disponível quando compilada para x64.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|  
|-------------|---------------------------|-------------------------------|  
|`nextafter`, `nextafterf`, `nextafterl`, `_nextafterf`, `nexttoward`, `nexttowardf`, `nexttowardl`|\<math.h>|\<math.h> ou \<cmath>|  
|`_nextafter`|\<float.h>|\<float.h> ou \<cfloat>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isnan, _isnan, _isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)