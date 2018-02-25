---
title: Operadores &lt;functional&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- functional/std::operator!=
- functional/std::operator==
dev_langs:
- C++
helpviewer_keywords:
- functional operators
ms.assetid: d4b3c760-f3e2-4b65-bdaa-d42e8dd6f5e1
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cf3e013ade27636b8cba3e2eeb5473440f9e14eb
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltfunctionalgt-operators"></a>Operadores &lt;functional&gt;
|||  
|-|-|  
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|  
  
##  <a name="op_eq_eq"></a>  operator==  
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
  
##  <a name="op_neq"></a>  operator!=  
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

