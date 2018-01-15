---
title: Classe add_const | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::add_const
dev_langs: C++
helpviewer_keywords:
- add_const class
- add_const
ms.assetid: 1262a1eb-8c9c-4dd6-9f43-88ba280182f1
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 23032c0906e789dcf24c8e81b3988f6bbe1c7392
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="addconst-class"></a>Classe add_const
Cria o tipo const do tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty>  
struct add_const;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do modificador de tipo mantém um tipo modificado que será `Ty` se `Ty` for uma referência, uma função ou um tipo qualificado como const, caso contrário, será `const Ty`.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__add_const.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
int main()   
{   
    std::add_const<int>::type *p = (const int *)0;   
  
    p = p;  // to quiet "unused" warning   
    std::cout << "add_const<int> == "   
        << typeid(*p).name() << std::endl;   
  
    return (0);   
}  
```  
  
```Output  
add_const<int> == int  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe remove_const](../standard-library/remove-const-class.md)
