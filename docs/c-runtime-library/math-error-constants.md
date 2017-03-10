---
title: "Constantes de erro de matemática | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _PLOSS
- _UNDERFLOW
- _TLOSS
- _SING
- _DOMAIN
- _OVERFLOW
dev_langs:
- C++
helpviewer_keywords:
- _TLOSS constant
- _SING constant
- PLOSS constant
- UNDERFLOW constant
- _UNDERFLOW constant
- _OVERFLOW constant
- DOMAIN constant
- OVERFLOW constant
- TLOSS constant
- SING constant
- _DOMAIN constant
- _PLOSS constant
- math error constants
ms.assetid: 4be933a6-674e-45a5-8ac9-090023542f5b
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c2e474cf701ca543b059c1aa941208decadfeb78
ms.lasthandoff: 02/25/2017

---
# <a name="math-error-constants"></a>Constantes de erro de matemática
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <math.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 As rotinas matemáticas da biblioteca em tempo de execução podem gerar erros de constantes de matemática.  
  
 Esses erros, descritos a seguir, correspondem aos tipos de exceções definidos na MATEMÁTICA. H e são retornados pela função `_matherr` quando ocorre um erro de matemática.  
  
|Constante|Significado|  
|--------------|-------------|  
|`_DOMAIN`|O argumento de função está fora do domínio da função.|  
|`_OVERFLOW`|O resultado é muito grande para ser representado no tipo de retorno da função.|  
|`_PLOSS`|Ocorreu uma perda parcial de significância.|  
|`_SING`|Singularidade da argumento: o argumento de função tem valor inválido. (Por exemplo, o valor 0 é passado para a função que requer um valor diferente de zero.)|  
|`_TLOSS`|Ocorreu uma perda total de significância.|  
|`_UNDERFLOW`|O resultado é muito pequeno para ser representado.|  
  
## <a name="see-also"></a>Consulte também  
 [_matherr](../c-runtime-library/reference/matherr.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
