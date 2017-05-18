---
title: Classe is_move_constructible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- is_move_constructible
- type_traits/std::is_move_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_move_constructible
ms.assetid: becdf076-7419-488d-a335-78adf2478b9b
caps.latest.revision: 12
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
ms.openlocfilehash: 91f451ef7ec496791d6a1a8d28965dbb5b684584
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ismoveconstructible-class"></a>Classe is_move_constructible
Testa se o tipo tem um construtor de movimentação.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
struct is_move_constructible;
```  
  
#### <a name="parameters"></a>Parâmetros  
 T  
 O tipo a ser avaliado  
  
## <a name="remarks"></a>Comentários  
 Um predicado de tipo será avaliado como verdadeiro se o tipo `T` puder ser construído usando uma operação de movimentação. Esse predicado é equivalente a `is_constructible<T, T&&>`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




