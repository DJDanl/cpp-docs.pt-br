---
title: Classe add_rvalue_reference | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::add_rvalue_reference
- add_rvalue_reference
dev_langs:
- C++
helpviewer_keywords:
- add_rvalue_reference Class
ms.assetid: 76b0cb7c-1031-45d0-b409-f03ab0297580
caps.latest.revision: 11
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 8fdf9ef9e5f8fe21be1c1a5d1947fbe7c050e9fe
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="addrvaluereference-class"></a>Classe add_rvalue_reference
Criará um tipo de referência de rvalue do parâmetro de modelo, se for um tipo de objeto ou de função. Caso contrário, devido à semântica de recolhimento de referência, o tipo será igual ao do parâmetro de modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <class T>
struct add_rvalue_reference;

template <class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
```  
  
#### <a name="parameters"></a>Parâmetros  
 T  
 O tipo a ser modificado.  
  
## <a name="remarks"></a>Comentários  
 A classe `add_rvalue_reference` tem um membro chamado `type`, que é um alias para o tipo de uma referência de rvalue ao parâmetro de modelo `T`. A semântica de recolhimento de referência implica que, para `T` de tipos que não são de objeto nem de função, `T&&` é um `T`. Por exemplo, quando `T` é um tipo de referência de lvalue, `add_rvalue_reference<T>::type` é o tipo de referência de lvalue, não uma referência de rvalue.  
  
 Para facilitar, <type_traits> define o modelo auxiliar `add_rvalue_reference_t`, que cria um alias para o membro `type` de `add_rvalue_reference`.  
  
## <a name="example"></a>Exemplo  
 Este exemplo de código usa static_assert para mostrar como os tipos de referência de rvalue são criados usando `add_rvalue_reference` e `add_rvalue_reference_t`, e como o resultado de `add_rvalue_reference` em um tipo de referência de lvalue não é uma referência de rvalue, mas recolhe ao tipo de referência de lvalue.  
  
```cpp  
// ex_add_rvalue_reference.cpp  
// Build by using: cl /EHsc /W4 ex_add_rvalue_reference.cpp  
#include <type_traits>   
#include <iostream>   
#include <string>  
  
using namespace std;  
int main()  
{  
    static_assert(is_same<add_rvalue_reference<string>::type, string&&>::value,   
        "Expected add_rvalue_reference_t<string> to be string&&");  
    static_assert(is_same<add_rvalue_reference_t<string*>, string*&&>::value,   
        "Expected add_rvalue_reference_t<string*> to be string*&&");  
    static_assert(is_same<add_rvalue_reference<string&>::type, string&>::value,   
        "Expected add_rvalue_reference_t<string&> to be string&");  
    static_assert(is_same<add_rvalue_reference_t<string&&>, string&&>::value,   
        "Expected add_rvalue_reference_t<string&&> to be string&&");  
    cout << "All static_assert tests of add_rvalue_reference passed." << endl;  
    return 0;  
}  
  
/*Output:  
All static_assert tests of add_rvalue_reference passed.  
*/  
```  
  
## <a name="requirements"></a>Requisitos  
 Cabeçalho: <type_traits> Namespace: std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe add_lvalue_reference](../standard-library/add-lvalue-reference-class.md)   
 [Classe is_rvalue_reference](../standard-library/is-rvalue-reference-class.md)

