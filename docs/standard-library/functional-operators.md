---
title: Operadores &lt;functional&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::operator!=
- functional/std::operator!=
- std::operator==
- functional/std::operator==
dev_langs:
- C++
helpviewer_keywords:
- functional operators
ms.assetid: d4b3c760-f3e2-4b65-bdaa-d42e8dd6f5e1
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 0194fbc3e45c270ca7537285c5c6b4e768c65a90
ms.openlocfilehash: 3a4ab558f46f99850aed286865ae5dbbd7d4a6af
ms.lasthandoff: 02/25/2017

---
# <a name="ltfunctionalgt-operators"></a>Operadores &lt;functional&gt;
|||  
|-|-|  
|[operator!=](#operator_neq)|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_eq_eq"></a>  operator==  
 Testa se o objeto que pode ser chamado está vazio.  
  
```  
template <class Fty>  
bool operator==(const function<Fty>& f, null_ptr_type npc);

template <class Fty>  
bool operator==(null_ptr_type npc, const function<Fty>& f);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Fty`  
 O tipo de função a ser encapsulada.  
  
 `f`  
 O objeto de função  
  
 `npc`  
 Um ponteiro nulo.  
  
### <a name="remarks"></a>Comentários  
 Os operadores usam um argumento que é uma referência a um objeto `function` e um argumento que é uma constante de ponteiro nulo. Ambos retornam true somente se o objeto `function` estiver vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__functional__operator_eq.cpp
// compile with: /EHsc   
#include <functional>   
#include <iostream>   

int neg(int val)
{
    return (-val);
}

int main()
{
    std::function<int(int)> fn0;
    std::cout << std::boolalpha << "empty == "
        << (fn0 == 0) << std::endl;

    std::function<int(int)> fn1(neg);
    std::cout << std::boolalpha << "empty == "
        << (fn1 == 0) << std::endl;

    return (0);
}
  
```  
  
```Output  
empty == true  
empty == false  
```  
  
##  <a name="operator_neq"></a>  operator!=  
 Testa se o objeto que pode ser chamado não está vazio.  
  
```  
template <class Fty>  
bool operator!=(const function<Fty>& f, null_ptr_type npc);

template <class Fty>  
bool operator!=(null_ptr_type npc, const function<Fty>& f);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Fty`  
 O tipo de função a ser encapsulada.  
  
 `f`  
 O objeto de função  
  
 `npc`  
 Um ponteiro nulo.  
  
### <a name="remarks"></a>Comentários  
 Os operadores usam um argumento que é uma referência a um objeto `function` e um argumento que é uma constante de ponteiro nulo. Ambos retornam true somente se o objeto `function` não estiver vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__functional__operator_ne.cpp   
// compile with: /EHsc   
#include <functional>   
#include <iostream>   
  
int neg(int val)   
    {   
    return (-val);   
    }   
  
int main()   
    {   
    std::function<int (int)> fn0;   
    std::cout << std::boolalpha << "not empty == "   
        << (fn0 != 0) << std::endl;   
  
    std::function<int (int)> fn1(neg);   
    std::cout << std::boolalpha << "not empty == "   
        << (fn1 != 0) << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
not empty == false  
not empty == true  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<functional>](../standard-library/functional.md)


