---
title: Classe add_cv | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::add_cv
dev_langs:
- C++
helpviewer_keywords:
- add_cv class
- add_cv
ms.assetid: a5572c78-a097-45d7-b476-ed4876889dea
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 90d31b9eaa9baf3f282fb5cc57e0c75c7480e489
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="addcv-class"></a>Classe add_cv
Cria o tipo const volátil do tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T>  
struct add_cv;  
 
template <class T>
using add_cv_t = typename add_cv<T>::type;  
```  
  
#### <a name="parameters"></a>Parâmetros  
*T*  
O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
Uma instância do tipo modificado `add_cv<T>` tem um typedef do membro `type` equivalente a *T* modificado por [add_volatile](../standard-library/add-volatile-class.md) e [add_const](../standard-library/add-const-class.md), a menos que *T* já tenha os qualificadores cv, seja uma referência ou uma função.  
  
O tipo auxiliar `add_cv_t<T>` é um atalho para acessar o typedef `type` do membro `add_cv<T>`.
  
## <a name="example"></a>Exemplo  
  
```cpp  
// add_cv.cpp
// compile by using: cl /EHsc /W4 add_cv.cpp
#include <type_traits>   
#include <iostream>   

struct S {
    void f() { 
        std::cout << "invoked non-cv-qualified S.f()" << std::endl; 
    }
    void f() const { 
        std::cout << "invoked const S.f()" << std::endl; 
    }
    void f() volatile { 
        std::cout << "invoked volatile S.f()" << std::endl; 
    }
    void f() const volatile { 
        std::cout << "invoked const volatile S.f()" << std::endl; 
    }
};

template <class T>
void invoke() {
    T t;
    ((T *)&t)->f(); 
}

int main()
{
    invoke<S>();
    invoke<std::add_const<S>::type>();
    invoke<std::add_volatile<S>::type>();
    invoke<std::add_cv<S>::type>();
}  
```  
  
```Output  
invoked non-cv-qualified S.f()
invoked const S.f()
invoked volatile S.f()
invoked const volatile S.f()  
```  
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** \<type_traits>  
**Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
[<type_traits>](../standard-library/type-traits.md)   
[Classe remove_const](../standard-library/remove-const-class.md)   
[Classe remove_volatile](../standard-library/remove-volatile-class.md)

