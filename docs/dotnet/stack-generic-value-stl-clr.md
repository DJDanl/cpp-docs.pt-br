---
title: Stack::generic_value (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- cliext::stack::generic_value
dev_langs:
- C++
helpviewer_keywords:
- generic_value member [STL/CLR]
ms.assetid: f918f5e6-5cb6-480e-8548-13e15026ffde
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 17e65bcae544224bb8987e1ffae084aafcb6b86a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stackgenericvalue-stlclr"></a>stack::generic_value (STL/CLR)
O tipo de um elemento para uso com a interface genérica para o contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef GValue generic_value;  
```  
  
## <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo `GValue` que descreve o valor do elemento armazenados para uso com a interface genérica para esta classe de contêiner do modelo. (`GValue` é `value_type` ou `value_type^` se `value_type` é um tipo de referência.)  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_stack_generic_value.cpp   
// compile with: /clr   
#include <cliext/stack>   
  
typedef cliext::stack<wchar_t> Mystack;   
int main()   
    {   
    Mystack c1;   
    c1.push(L'a');   
    c1.push(L'b');   
    c1.push(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in c1.get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// get interface to container   
    Mystack::generic_container^ gc1 = %c1;   
    for each (wchar_t elem in gc1->get_container())   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display in reverse using generic_value   
    for (; !gc1->empty(); gc1->pop())   
        {   
        Mystack::generic_value elem = gc1->top();   
  
        System::Console::Write(" {0}", elem);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
a b c  
c b a  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/pilha >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [pilha (STL/CLR)](../dotnet/stack-stl-clr.md)   
 [Stack::generic_container (STL/CLR)](../dotnet/stack-generic-container-stl-clr.md)   
 [stack::value_type (STL/CLR)](../dotnet/stack-value-type-stl-clr.md)