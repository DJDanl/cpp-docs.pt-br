---
title: Classe is_abstract | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_abstract
dev_langs: C++
helpviewer_keywords:
- is_abstract class
- is_abstract
ms.assetid: 8867f660-3434-404c-ba90-c26607a5e0d2
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d5d535a50aaab7445f39a02967964d002fc83d49
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="isabstract-class"></a>Classe is_abstract
Testa se o tipo é uma classe abstrata.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty>  
struct is_abstract;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem pelo menos uma função virtual pura; caso contrário, será falsa.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__is_abstract.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial   
    {   
    int val;   
    };   
  
struct abstract   
    {   
    virtual int val() = 0;   
    };   
  
int main()   
    {   
    std::cout << "is_abstract<trivial> == " << std::boolalpha   
        << std::is_abstract<trivial>::value << std::endl;   
    std::cout << "is_abstract<abstract> == " << std::boolalpha   
        << std::is_abstract<abstract>::value << std::endl;   
  
    return (0);   
    }  
```  
  
```Output  
is_abstract<trivial> == false  
is_abstract<abstract> == true  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe is_polymorphic](../standard-library/is-polymorphic-class.md)
