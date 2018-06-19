---
title: 'List:: splice (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::list::splice
dev_langs:
- C++
helpviewer_keywords:
- splice member [STL/CLR]
ms.assetid: ebc424b9-8341-4a88-b101-86d56324f5ac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: e0c92faf6a4ec84e6ed65c58d02337038398d37e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33135944"
---
# <a name="listsplice-stlclr"></a>list::splice (STL/CLR)
Restitch links entre nós.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void splice(iterator where, list<Value>% right);  
void splice(iterator where, list<Value>% right,  
    iterator first);  
void splice(iterator where, list<Value>% right,  
    iterator first, iterator last);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 primeiro  
 Início do intervalo para juntar.  
  
 last  
 Fim do intervalo para juntar.  
  
 direita  
 Contêiner a fusão de.  
  
 onde  
 Onde no contêiner para juntar antes.  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro insere a sequência controlada por `right` antes do elemento na sequência controlada apontada pelo `where`. Também remove elementos de `right`. (`%right` não deve ser igual a `this`.) Você pode usá-lo para juntar todos de uma lista para outra.  
  
 A segunda função de membro remove o elemento apontado pelo `first` na sequência controlada por `right` e insere-o antes do elemento na sequência controlada apontada pelo `where`. (Se `where` `==` `first` `||` `where` `== ++first`, não ocorre nenhuma alteração.) Você pode usá-lo para juntar a um único elemento de uma lista para outra.  
  
 A terceira função do membro insere subintervalo designado pelo [`first`, `last`) da sequência controlada por `right` antes do elemento na sequência controlada apontada pelo `where`. Ele também remove o subintervalo original da sequência controlada por `right`. (Se `right` `==` `this`, o intervalo de [`first`, `last`) não deve incluir o elemento apontado pelo `where`.) Você pode usá-lo para juntar uma subsequência de zero ou mais elementos de uma lista para outra.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_list_splice.cpp   
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
  
// splice to a new list   
    cliext::list<wchar_t> c2;   
    c2.splice(c2.begin(), c1);   
    System::Console::WriteLine("c1.size() = {0}", c1.size());   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// return one element   
    c1.splice(c1.end(), c2, c2.begin());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// return remaining elements   
    c1.splice(c1.begin(), c2, c2.begin(), c2.end());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c2.size() = {0}", c2.size());   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
c1.size() = 0  
 a b c  
 a  
 b c  
 b c a  
c2.size() = 0  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [List:: Assign (STL/CLR)](../dotnet/list-assign-stl-clr.md)   
 [List:: Insert (STL/CLR)](../dotnet/list-insert-stl-clr.md)   
 [list::merge (STL/CLR)](../dotnet/list-merge-stl-clr.md)