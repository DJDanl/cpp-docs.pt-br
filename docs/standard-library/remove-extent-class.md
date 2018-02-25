---
title: Classe remove_extent | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- type_traits/std::remove_extent
dev_langs:
- C++
helpviewer_keywords:
- remove_extent class
- remove_extent
ms.assetid: b9320862-3891-49fc-80bc-571eb2c035cf
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 688623cfb3976651d439e6af316a9ee809305ba9
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="removeextent-class"></a>Classe remove_extent
Cria tipo de elemento do tipo de matriz.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T>  
struct remove_extent;  
 
template <class T>  
using remove_extent_t = typename remove_extent<T>::type;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância de `remove_extent<T>` mantém um tipo modificado que é `T1` quando `T` é da forma `T1[N]`, caso contrário, `T`.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
#include <type_traits>   
#include <iostream>   
  
int main()   
    {   
    std::cout << "remove_extent_t<int> == "  
        << typeid(std::remove_extent_t<int>).name()  
        << std::endl;T  
    std::cout << "remove_extent_t<int[5]> == "  
        << typeid(std::remove_extent_t<int[5]>).name()  
        << std::endl;T  
    std::cout << "remove_extent_t<int[5][10]> == "  
        << typeid(std::remove_extent_t<int[5][10]>).name()  
        << std::endl;   
    return (0);   
    }  
```  
  
```Output  
remove_extent_t<int> == int  
remove_extent_t<int[5]> == int  
remove_extent_t<int[5][10]> == int [10]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe remove_all_extents](../standard-library/remove-all-extents-class.md)
