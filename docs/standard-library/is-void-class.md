---
title: Classe is_void | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_void
dev_langs: C++
helpviewer_keywords:
- is_void class
- is_void
ms.assetid: 99b0de3b-1b38-4949-b053-080e5363174e
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 25d35d0ea17849fbccc40c1a0d67886feda79e2b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="isvoid-class"></a>Classe is_void
Testa se o tipo é nulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T>  
struct is_void;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `T` for `void` ou uma forma de `void` qualificada por CV; caso contrário, será falsa.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__is_void.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
int main()   
    {   
    std::cout << "is_void<trivial> == " << std::boolalpha   
        << std::is_void<trivial>::value << std::endl;   
    std::cout << "is_void<void()> == " << std::boolalpha   
        << std::is_void<void()>::value << std::endl;   
    std::cout << "is_void<void> == " << std::boolalpha   
        << std::is_void<void>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
is_void<trivial> == false  
is_void<void()> == false  
is_void<void> == true  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)

