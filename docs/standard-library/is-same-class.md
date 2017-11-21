---
title: Classe is_same | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_same
dev_langs: C++
helpviewer_keywords:
- is_same class
- is_same
ms.assetid: d9df6c1d-c270-4ec2-802a-af275648dd1d
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 896d01a648c056ffa4f40b3cdccda2ff057b0e5a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="issame-class"></a>Classe is_same
Testa se dois tipos são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty1, class Ty2>  
struct is_same;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty1`  
 O primeiro tipo a ser consultado.  
  
 `Ty2`  
 O segundo tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se os tipos `Ty1` e `Ty2` forem o mesmo tipo; caso contrário, será falsa.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__is_same.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct base   
    {   
    int val;   
    };   
  
struct derived   
    : public base   
    {   
    };   
  
int main()   
    {   
    std::cout << "is_same<base, base> == " << std::boolalpha   
        << std::is_same<base, base>::value << std::endl;   
    std::cout << "is_same<base, derived> == " << std::boolalpha   
        << std::is_same<base, derived>::value << std::endl;   
    std::cout << "is_same<derived, base> == " << std::boolalpha   
        << std::is_same<derived, base>::value << std::endl;   
    std::cout << "is_same<int, int> == " << std::boolalpha   
        << std::is_same<int, int>::value << std::endl;   
    std::cout << "is_same<int, const int> == " << std::boolalpha   
        << std::is_same<int, const int>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
is_same<base, base> == true  
is_same<base, derived> == false  
is_same<derived, base> == false  
is_same<int, int> == true  
is_same<int, const int> == false  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe is_convertible](../standard-library/is-convertible-class.md)   
 [Classe is_base_of](../standard-library/is-base-of-class.md)
