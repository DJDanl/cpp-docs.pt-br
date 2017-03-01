---
title: Classe add_volatile | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- add_volatile
- std::add_volatile
- type_traits/std::add_volatile
dev_langs:
- C++
helpviewer_keywords:
- add_volatile class
- add_volatile
ms.assetid: cde57277-d764-402d-841e-97611ebaab14
caps.latest.revision: 21
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
translationtype: Machine Translation
ms.sourcegitcommit: 8630a5c0b97b85e0dc75e8b470974bb7d223a511
ms.openlocfilehash: c770950bfb69eaee2fde9aca63b0010f5a2da26a
ms.lasthandoff: 02/25/2017

---
# <a name="addvolatile-class"></a>Classe add_volatile
Cria um tipo volátil do tipo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty>  
struct add_volatile;  
 
template <class T>
using add_volatile_t = typename add_volatile<T>::type;  
```  
  
### <a name="parameters"></a>Parâmetros  
*T*  
O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
Uma instância de `add_volatile<T>` tem um typedef do membro `type` que será *T* se *T* for uma referência, uma função ou um tipo qualificado como volátil, caso contrário, será `volatile` *T*. O alias `add_volatile_t` é um atalho para acessar o typedef do membro `type`. 
  
## <a name="example"></a>Exemplo  
  
```cpp  
#include <type_traits>   
#include <iostream>   
  
int main()   
{   
    std::add_volatile_t<int> *p = (volatile int *)0;   
  
    p = p;  // to quiet "unused" warning   
    std::cout << "add_volatile<int> == "   
        << typeid(*p).name() << std::endl;   
  
    return (0);   
} 
```  
  
```Output  
add_volatile<int> == int  
```  
  
## <a name="requirements"></a>Requisitos  

**Cabeçalho:** \<type_traits>  
  
**Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
[<type_traits>](../standard-library/type-traits.md)   
[Classe remove_volatile](../standard-library/remove-volatile-class.md)

