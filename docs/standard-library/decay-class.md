---
title: Classe decay | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::decay
dev_langs:
- C++
helpviewer_keywords:
- decay class
ms.assetid: 96baa2fd-c8e0-49af-be91-ba375ba7f9dc
caps.latest.revision: 20
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: c24872ee58c740776285c715f1d03b16e811d9c6
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="decay-class"></a>Classe decay
Produz o tipo passado por valor. Torna o tipo não referência, não const, não volátil ou cria um ponteiro para o tipo com base em uma função ou em um tipo de matriz.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct decay;

template <class T>  
using decay_t = typename decay<T>::type;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
 Use o modelo de decay para produzir o tipo resultante como se o tipo tivesse sido passado por valor como um argumento. O membro de classe de modelo typedef `type` mantém um tipo modificado que é definido nos seguintes estágios:  
  
-   O tipo `U` é definido como `remove_reference<T>::type`.  
  
-   Se `is_array<U>::value` for verdadeiro, o tipo modificado `type` será `remove_extent<U>::type *`.  
  
-   Caso contrário, se `is_function<U>::value` for verdadeiro, o tipo modificado `type` será `add_pointer<U>::type`.  
  
-   Caso contrário, o tipo modificado `type` será `remove_cv<U>::type`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




