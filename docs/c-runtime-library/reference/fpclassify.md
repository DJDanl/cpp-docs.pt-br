---
title: fpclassify | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fpclassify
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
apitype: HeaderDef
f1_keywords:
- fpclassify
- math/fpclassify
helpviewer_keywords:
- fpclassify macro
- fpclassify function
ms.assetid: bf549499-7ff9-4a58-8692-f2d1cb6bab81
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 630fc297e1885831331a051820350f765a5f0681
ms.lasthandoff: 02/25/2017

---
# <a name="fpclassify"></a>fpclassify
Retorna a classificação de ponto flutuante do argumento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fpclassify(   
   /* floating-point */ x   
);  
  
int fpclassify(   
   float x   
); // C++ only  
  
int fpclassify(   
   double x   
); // C++ only  
  
int fpclassify(   
   long double x   
); // C++ only  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 O valor de ponto flutuante a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 `fpclassify` retorna um valor inteiro que indica a classe de ponto flutuante do argumento `x`. Esta tabela mostra os possíveis valores retornados por `fpclassify`, definidos em \<math.h>.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`FP_NAN`|Um NaN silencioso, indeterminado ou com sinalização|  
|`FP_INFINITE`|Um infinito positivo ou negativo|  
|`FP_NORMAL`|Um valor positivo ou negativo normalizado diferente de zero|  
|`FP_SUBNORMAL`|Um valor positivo ou negativo desnormalizado|  
|`FP_ZERO`|Um valor de zero positivo ou negativo|  
  
## <a name="remarks"></a>Comentários  
 Em C, `fpclassify` é uma macro; em C++, `fpclassify` é uma função sobrecarregada usando tipos de argumento de `float`, `double` ou `long double`. Nos dois casos, o valor retornado depende do tipo efetivo da expressão de argumento e não de qualquer representação intermediária. Por exemplo, um valor normal de `double` ou `long double` pode se tornar um valor infinito, desnormalizado ou de zero quando convertido em um `float`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função/Macro|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|  
|---------------------|---------------------------|-------------------------------|  
|`fpclassify`|\<math.h>|\<math.h> ou \<cmath>|  
  
 O macro `fpclassify` e as funções `fpclassify` estão em conformidade com as especificações C99 e C++11. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isnan, _isnan, _isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)
