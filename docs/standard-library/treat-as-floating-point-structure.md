---
title: Estrutura treat_as_floating_point | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- chrono/std::chrono::treat_as_floating_point
dev_langs:
- C++
ms.assetid: d0a2161c-bbb2-4924-8961-7568d5ad5434
caps.latest.revision: 13
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2a0b5e3ee0d244466a4f40a9b0557da715b736a8
ms.lasthandoff: 02/25/2017

---
# <a name="treatasfloatingpoint-structure"></a>Estrutura treat_as_floating_point
Especifica se `Rep` pode ser tratado como um tipo de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Rep>  
struct treat_as_floating_point : is_floating_point<Rep>;  
```  
  
## <a name="remarks"></a>Comentários  
 `Rep` pode ser tratado como um tipo de ponto flutuante somente quando a especialização `treat_as_floating_point<Rep>` é derivada de [true_type](../standard-library/type-traits-typedefs.md#true_type_typedef). A classe de modelo pode ser especializada para um tipo definido pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** chrono  
  
 **Namespace:** std::chrono  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono>](../standard-library/chrono.md)


