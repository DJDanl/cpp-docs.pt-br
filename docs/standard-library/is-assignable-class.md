---
title: Classe is_assignable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- is_assignable
- type_traits/std::is_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_assignable
ms.assetid: 53444287-c8be-4ad2-9487-a85c066a4f84
caps.latest.revision: 14
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
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: 208853a8e173797a37da60a824d06341e279ea34
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="isassignable-class"></a>Classe is_assignable
Testa se um valor do tipo `From` pode ser atribuído a um tipo `To`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class To, class From>  
struct is_assignable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 Para  
 O tipo do objeto que recebe a atribuição.  
  
 De  
 O tipo do objeto que fornece o valor.  
  
## <a name="remarks"></a>Comentários  
 A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formada. `From` e `To` devem ser tipos completos, `void` ou matrizes de limite desconhecido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




