---
title: Classe aligned_storage | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- aligned_storage
- std::aligned_storage
- type_traits/std::aligned_storage
dev_langs:
- C++
helpviewer_keywords:
- aligned_storage class
- aligned_storage
ms.assetid: f255e345-1f05-4d07-81e4-017f420839fb
caps.latest.revision: 23
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
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: 0da44c2fb505b2edbce9e5ccb028a6e167b4cf17
ms.lasthandoff: 02/25/2017

---
# <a name="alignedstorage-class"></a>Classe aligned_storage
Cria tipo alinhado adequadamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <std::size_t Len, std::size_t Align>  
struct aligned_storage;  
 
template <std::size_t Len, std::size_t Align = alignment_of<max_align_t>::value>  
using aligned_storage_t = typename aligned_storage<Len, Align>::type;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Len`  
 O tamanho do objeto.  
  
 `Align`  
 O alinhamento do objeto.  
  
## <a name="remarks"></a>Comentários  
 O typedef do membro de modelo `type` é sinônimo de um tipo POD com alinhamento `Align` e tamanho `Len`. `Align` deve ser igual a `alignment_of<T>::value` para algum tipo `T` ou para o alinhamento padrão.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
#include <type_traits>   
#include <iostream>   
  
typedef std::aligned_storage<sizeof (int),   
    std::alignment_of<double>::value>::type New_type;   
int main()   
    {   
    std::cout << "alignment_of<int> == "   
        << std::alignment_of<int>::value << std::endl;   
    std::cout << "aligned to double == "   
        << std::alignment_of<New_type>::value << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
alignment_of<int> == 4  
aligned to double == 8  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe alignment_of](../standard-library/alignment-of-class.md)

