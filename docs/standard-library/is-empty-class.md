---
title: Classe is_empty | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_empty
dev_langs: C++
helpviewer_keywords:
- is_empty class
- is_empty
ms.assetid: 44a6fc92-7e55-4fbe-9a24-2a0ce2dccba0
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4511c87fcda1e4ccf582442c481cfa1b044f957d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="isempty-class"></a>Classe is_empty
Testa se o tipo é uma classe vazia.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty>  
struct is_empty;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe vazia; caso contrário, será falsa.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__is_empty.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct empty   
    {   
    };   
  
struct trivial   
    {   
    int val;   
    };   
  
int main()   
    {   
    std::cout << "is_empty<trivial> == " << std::boolalpha   
        << std::is_empty<trivial>::value << std::endl;   
    std::cout << "is_empty<empty> == " << std::boolalpha   
        << std::is_empty<empty>::value << std::endl;   
    std::cout << "is_empty<int> == " << std::boolalpha   
        << std::is_empty<int>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
is_empty<trivial> == false  
is_empty<empty> == true  
is_empty<int> == false  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)

