---
title: _fpclass, _fpclassf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _fpclass
- _fpclassf
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
- fpclass
- _fpclass
- _fpclassf
- math/_fpclass
- float/_fpclass
- math/_fpclassf
dev_langs:
- C++
helpviewer_keywords:
- fpclass function
- floating-point numbers, IEEE representation
- _fpclass function
- _fpclassf function
ms.assetid: 2774872d-3543-446f-bc72-db85f8b95a6b
caps.latest.revision: 13
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 9f061841ea6f4050945caeb2cacb9acfdce77c44
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="fpclass-fpclassf"></a>_fpclass, _fpclassf
Retorna um valor que indica a classificação de ponto flutuante do argumento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _fpclass(   
   double x   
);  
  
int _fpclassf(   
   float x   
); /* x64 only */  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 O valor de ponto flutuante a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 As funções `_fpclass` e `_fpclassf` retornam um valor inteiro que indica a classificação de ponto flutuante do argumento `x`. A classificação pode ter um dos valores a seguir, definidos em \<float.>.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`_FPCLASS_SNAN`|Sinalização de NaN|  
|`_FPCLASS_QNAN`|NaN silencioso|  
|`_FPCLASS_NINF`|Infinito negativo (-INF)|  
|`_FPCLASS_NN`|Negativo normalizado diferente de zero|  
|`_FPCLASS_ND`|Negativo desnormalizado|  
|`_FPCLASS_NZ`|Zero negativo (- 0)|  
|`_FPCLASS_PZ`|0 positivo (+0)|  
|`_FPCLASS_PD`|Positivo desnormalizado|  
|`_FPCLASS_PN`|Positivo normalizado diferente de zero|  
|`_FPCLASS_PINF`|Infinito positivo (+INF)|  
  
## <a name="remarks"></a>Comentários  
 As funções `_fpclass` e `_fpclassf` são específicas da Microsoft. Elas são semelhantes a [fpclassify](../../c-runtime-library/reference/fpclassify.md), mas retornam informações mais detalhadas sobre o argumento. A função `_fpclassf` só está disponível quando compilada para a plataforma x64.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fpclass`|\<float.h>|  
  
 Para obter mais informações sobre compatibilidade e conformidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isnan, _isnan, _isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)   
 [fpclassify](../../c-runtime-library/reference/fpclassify.md)
