---
title: Classe remove_all_extents | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- type_traits/std::remove_all_extents
dev_langs:
- C++
helpviewer_keywords:
- remove_all_extents class
- remove_all_extents
ms.assetid: 548dc536-82e7-423a-b8c1-443d66d9632e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d527deeeaea38bb57d9edf32d7325b1684ea8a5c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="removeallextents-class"></a>Classe remove_all_extents
Cria tipo de não matriz do tipo de matriz.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct remove_all_extents;

template <class T>  
using remove_all_extents_t = typename remove_all_extents<T>::type;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância de `remove_all_extents<T>` mantém um tipo modificado que é o tipo de elemento do tipo de matriz `T` com todas as dimensões da matriz removidas ou `T` se `T` não for um tipo de matriz.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::cout << "remove_all_extents<int> == "   
        << typeid(std::remove_all_extents_t<int>).name()   
        << std::endl;   
    std::cout << "remove_all_extents_t<int[5]> == "   
        << typeid(std::remove_all_extents_t<int[5]>).name()   
        << std::endl;   
    std::cout << "remove_all_extents_t<int[5][10]> == "   
        << typeid(std::remove_all_extents_t<int[5][10]>).name()   
        << std::endl;   
  
    return (0);   
    }  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe remove_extent](../standard-library/remove-extent-class.md)
