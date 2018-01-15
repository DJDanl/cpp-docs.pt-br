---
title: Classe aligned_union | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::aligned_union
dev_langs: C++
helpviewer_keywords: aligned_union
ms.assetid: 9931a44d-3a67-4f29-a0f6-d47a7cf560ac
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d217ee9687320e89f4c63469ab0dfff48e633ce9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="alignedunion-class"></a>Classe aligned_union
Fornece um tipo POD alinhado adequadamente e grande o suficiente para armazenar um tipo de união e o tamanho necessário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <std::size_t Len, class... Types>  
struct aligned_union;  
 
template <std::size_t Len, class... Types>  
using aligned_union_t = typename aligned_union<Len, Types...>::type;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Len`  
 O valor de alinhamento do maior tipo na união.  
  
 `Types`  
 Os tipos distintos na união subjacente.  
  
## <a name="remarks"></a>Comentários  
 Use a classe de modelo para obter o alinhamento e o tamanho necessários para armazenar uma união no armazenamento não inicializado. O typedef de membro `type` nomeia um tipo POD adequado para o armazenamento de qualquer tipo listado em `Types`. O tamanho mínimo é `Len`. O membro estático `alignment_value` do tipo `std::size_t` contém o alinhamento mais estrito exigido de todos os tipos listados em `Types`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar `aligned_union` para alocar um buffer de pilha alinhado para colocar uma união.  
  
```  
// std__type_traits__aligned_union.cpp  
#include <iostream>  
#include <type_traits>  
  
union U_type  
{  
    int i;  
    float f;  
    double d;  
    U_type(float e) : f(e) {}  
};  
  
typedef std::aligned_union<16, int, float, double>::type aligned_U_type;  
  
int main()  
{  
    // allocate memory for a U_type aligned on a 16-byte boundary  
    aligned_U_type au;  
    // do placement new in the aligned memory on the stack  
    U_type* u = new (&au) U_type(1.0f);  
    if (nullptr != u)  
    {  
        std::cout << "value of u->i is " << u->i << std::endl;  
        // must clean up placement objects manually!  
        u->~U_type();  
    }  
}  
```  
  
```Output  
value of u->i is 1065353216  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe alignment_of](../standard-library/alignment-of-class.md)
