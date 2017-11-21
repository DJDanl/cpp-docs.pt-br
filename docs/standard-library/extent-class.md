---
title: Classe extent | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::extent
dev_langs: C++
helpviewer_keywords:
- extent class
- extent
ms.assetid: 6d16263d-90b2-4330-9ec7-b59ed898792d
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 185cb6108801b31c19301a0f7488352a6948f5bb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="extent-class"></a>Classe extent
Obtém uma dimensão de matriz.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty, unsigned I = 0>  
struct extent;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
 `I`  
 A matriz associada à consulta.  
  
## <a name="remarks"></a>Comentários  
 Se `Ty` é um tipo de matriz que tem pelo menos `I` dimensões, a consulta de tipo contém o número de elementos na dimensão especificada por `I`. Se `Ty` não é um tipo de matriz ou sua classificação é menor que `I` ou se `I` é zero e `Ty` é do tipo "matriz desconhecida associada à `U`", a consulta de tipo mantém o valor 0.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__extent.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::cout << "extent 0 == "   
        << std::extent<int[5][10]>::value << std::endl;   
    std::cout << "extent 1 == "   
        << std::extent<int[5][10], 1>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
extent 0 == 5  
extent 1 == 10  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe remove_all_extents](../standard-library/remove-all-extents-class.md)   
 [Classe remove_extent](../standard-library/remove-extent-class.md)
