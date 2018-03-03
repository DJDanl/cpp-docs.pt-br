---
title: 'List:: Unique (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cliext::list::unique
dev_langs:
- C++
helpviewer_keywords:
- unique member [STL/CLR]
ms.assetid: c3a29e4e-0ec1-4472-b050-7a9511037132
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 056f15dc0e7808a7f0ada7267a60e13d4c75d83b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="listunique-stlclr"></a>list::unique (STL/CLR)
Remove elementos adjacentes que são passados a um teste especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void unique();  
template<typename Pred2>  
    void unique(Pred2 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Pred  
 Comparador para pares do elemento.  
  
## <a name="remarks"></a>Comentários  
 Remove a primeira função de membro na sequência controlada (apaga) cada elemento que compara igual a seu elemento anterior - se elemento `X` precede o elemento `Y` e `X == Y`, remove a função de membro `Y`. Você usá-lo para remover apenas uma cópia de cada subsequência de elementos adjacentes que compare igual. Observe que, se a sequência controlada for solicitada, como ao chamar [List:: Sort (STL/CLR)](../dotnet/list-sort-stl-clr.md)`()`, a função de membro deixa somente elementos com valores exclusivos. (Portanto, o nome).  
  
 A segunda função de membro se comporta como o primeiro, exceto que ela remove cada elemento `Y` seguindo um elemento `X` para o qual `pred(X, Y)`. Você pode usá-lo para remover apenas uma cópia de cada subsequência de elementos adjacentes que satisfazem a uma função de predicado ou representante que você especificar. Observe que, se a sequência controlada for solicitada, como ao chamar `sort(pred)`, a função de membro deixa somente os elementos que não têm equivalente os pedidos com todos os outros elementos.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_list_unique.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display contents after unique   
    cliext::list<wchar_t> c2(c1);   
    c2.unique();   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// display contents after unique(not_equal_to)   
    c2 = c1;   
    c2.unique(cliext::not_equal_to<wchar_t>());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a a b c  
a b c  
a a  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [List:: Remove (STL/CLR)](../dotnet/list-remove-stl-clr.md)   
 [List:: remove_if (STL/CLR)](../dotnet/list-remove-if-stl-clr.md)   
 [list::sort (STL/CLR)](../dotnet/list-sort-stl-clr.md)