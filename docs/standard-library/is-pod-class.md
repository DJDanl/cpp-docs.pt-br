---
title: Classe is_pod | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::is_pod
dev_langs:
- C++
helpviewer_keywords:
- is_pod class
- is_pod
ms.assetid: d73ebdee-746b-4082-9fa4-2db71432eb0e
caps.latest.revision: 20
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: efe54ef10c8ab8102e17efdbf8e38f217ec2e0df
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="ispod-class"></a>Classe is_pod
Testa se o tipo é um POD.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct is_pod;
```  
  
#### <a name="parameters"></a>Parâmetros  
*T*  
O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
`is_pod<T>::value` será `true` se o tipo *T* for POD (Plain Old Data). Caso contrário, será `false`.  
  
Tipos aritméticos, tipos de enumeração, tipos de ponteiro e tipos de ponteiro para membro são POD.  
  
Uma versão qualificada para CV de um tipo POD também é um tipo POD.  
  
Uma matriz de POD também é POD.  
  
Um struct ou união, de que todos os membros de dados não estáticos forem POD, também será POD se não tiver:  
  
-   nenhum construtor declarado pelo usuário.  
  
-   nenhum membro de dados não estáticos particular ou protegido.  
  
-   Nenhuma classe base.  
  
-   nenhuma função virtual.  
  
-   nenhum membro de dados não estáticos do tipo de referência.  
  
-   nenhum operador de atribuição de cópia definido pelo usuário.  
  
-   nenhum destruidor definido pelo usuário.  
  
Portanto, é possível compilar recursivamente structs e matrizes POD que contêm structs e matrizes POD.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// std__type_traits__is_pod.cpp   
// compile with: /EHsc   
#include <type_traits>   
#include <iostream>   
  
struct trivial {   
    int val;   
};   
  
struct throws {   
    throws() {}  // User-declared ctor, so not POD
  
    int val;   
};   
  
int main() {   
    std::cout << "is_pod<trivial> == " << std::boolalpha   
        << std::is_pod<trivial>::value << std::endl;   
    std::cout << "is_pod<int> == " << std::boolalpha   
        << std::is_pod<int>::value << std::endl;   
    std::cout << "is_pod<throws> == " << std::boolalpha   
        << std::is_pod<throws>::value << std::endl;   
  
    return (0);   
}  
```  
  
```Output  
is_pod<trivial> == true  
is_pod<int> == true  
is_pod<throws> == false  
```  
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** \<type_traits>  
  
**Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
[<type_traits>](../standard-library/type-traits.md)




