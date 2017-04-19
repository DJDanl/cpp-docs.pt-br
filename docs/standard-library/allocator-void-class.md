---
title: Classe allocator&lt;void&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- memory/std::allocator<void>
- allocator<void>
dev_langs:
- C++
helpviewer_keywords:
- allocator<void> class
ms.assetid: abfb40f5-c600-46a6-b130-f42c6535b2bd
caps.latest.revision: 18
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
ms.openlocfilehash: 5d21bcb7ca33578fbda5fe6e4c961bc23592bef8
ms.lasthandoff: 02/25/2017

---
# <a name="allocatorltvoidgt-class"></a>Classe allocator&lt;void&gt;
Uma especialização do alocador de classe de modelo para o tipo `void`, definindo os tipos que fazem sentido nesse contexto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <>
class allocator<void> {
    typedef void *pointer;
    typedef const void *const_pointer;
    typedef void value_type;
    template <class Other>
    struct rebind;
    allocator();
    allocator(const allocator<void>&);

    template <class Other>
    allocator(const allocator<Other>&);

    template <class Other>
    allocator<void>& operator=(const allocator<Other>&);
};
```  
  
## <a name="remarks"></a>Comentários  
 A classe explicitamente especializa a classe de modelo [allocator](../standard-library/allocator-class.md) para tipo *void.* Seus construtores e o operador de atribuição comportam-se da mesma maneira que a classe de modelo, mas define somente os seguintes tipos:  
  
- [const_pointer](../standard-library/allocator-class.md#allocator__const_pointer).  
  
- [pointer](../standard-library/allocator-class.md#allocator__pointer).  
  
- [value_type](../standard-library/allocator-class.md#allocator__value_type).  
  
- [rebind](../standard-library/allocator-class.md#allocator__rebind), um modelo de classe aninhada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<memory>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




