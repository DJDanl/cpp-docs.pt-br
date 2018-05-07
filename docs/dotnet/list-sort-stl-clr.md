---
title: 'List:: Sort (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::list::sort
dev_langs:
- C++
helpviewer_keywords:
- sort member [STL/CLR]
ms.assetid: f811d5f4-a19e-4194-8765-1e68097c52f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 670b18e5901ef264474256a1a1e57cde7a28ef01
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="listsort-stlclr"></a>list::sort (STL/CLR)
Ordena a sequência controlada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void sort();  
template<typename Pred2>  
    void sort(Pred2 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Pred  
 Comparador para pares do elemento.  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro reorganiza os elementos na sequência controlada de modo que elas são ordenadas por `operator<` – elementos não diminuir à medida que você percorre a sequência. Você pode usar essa função de membro para classificar a sequência em ordem crescente.  
  
 A segunda função de membro se comporta como o primeiro, exceto que a sequência é ordenada pela `pred`  --  `pred(X, Y)` é false para qualquer elemento `X` que segue o elemento `Y` na sequência resultante. Você pode usá-lo para classificar a sequência em uma ordem que você especificar uma função de predicado ou delegado.  
  
 As funções de executam uma classificação estável - nenhum par de elementos na sequência controlada original é revertida na sequência controlada resultante.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_list_sort.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// sort descending and redisplay   
    c1.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// sort ascending and redisplay   
    c1.sort();   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
c b a  
a b c  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [List:: Merge (STL/CLR)](../dotnet/list-merge-stl-clr.md)   
 [List:: reverse (STL/CLR)](../dotnet/list-reverse-stl-clr.md)   
 [List:: splice (STL/CLR)](../dotnet/list-splice-stl-clr.md)   
 [list::unique (STL/CLR)](../dotnet/list-unique-stl-clr.md)