---
title: Classe remove_pointer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::remove_pointer
dev_langs: C++
helpviewer_keywords:
- remove_pointer class
- remove_pointer
ms.assetid: 2cd4e417-32fb-4f53-bd16-4e8a98240832
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: efc240a12835da1bda0fe840e347200a4f58bcc2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="removepointer-class"></a>Classe remove_pointer
Cria o tipo do ponteiro para tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T>  
struct remove_pointer;  
 
template <class T>  
using remove_pointer_t = typename remove_pointer<T>::type;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância de `remove_pointer<T>` mantém um tipo modificado que é `T1` quando `T` é da forma `T1*`, `T1* const`, `T1* volatile` ou `T1* const volatile`, caso contrário `T`.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    int *p = (std::remove_pointer_t<int *> *)0;   
  
    p = p;  // to quiet "unused" warning   
    std::cout << "remove_pointer_t<int *> == "   
        << typeid(*p).name() << std::endl;   
  
    return (0);   
    }  
```  
  
```Output  
remove_pointer_t<int *> == int  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe add_pointer](../standard-library/add-pointer-class.md)
