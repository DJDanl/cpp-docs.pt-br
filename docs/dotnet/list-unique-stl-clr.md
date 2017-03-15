---
title: "list::unique (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::list::unique"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro exclusivo [STL/CLR]"
ms.assetid: c3a29e4e-0ec1-4472-b050-7a9511037132
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::unique (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove os elementos adjacentes que passam um teste especificado.  
  
## Sintaxe  
  
```  
void unique();  
template<typename Pred2>  
    void unique(Pred2 pred);  
```  
  
#### Parâmetros  
 pred  
 Comparador para pares do elemento.  
  
## Comentários  
 A primeira função de membro remove da sequência controlada \(\) erases cada elemento que compara o igual a seu elemento acima \-\- se o elemento `X` precede o elemento `Y` e `X == Y`, a função de membro remove `Y`.  Use\-a para remover todas menos uma cópia de cada subsequência de elementos adjacentes que comparam iguais.  Observe que se a sequência controlada está ordenada, como chamar [list::sort](../dotnet/list-sort-stl-clr.md)`()`, a função de membro apenas deixa os elementos com os valores exclusivos. \(Como o nome\).  
  
 A segunda função de membro se comportará da mesma forma que os primeiros, exceto que remove cada elemento `Y` que segue um elemento `X` para que `pred``(X, Y)`.  Você usará para remover todas menos uma cópia de cada subsequência de elementos adjacentes que satisfazem a uma função de predicado ou delega\-o que você especifica.  Observe que se a sequência controlada está ordenada, como chamar `sort(``pred``)`, a função de membro apenas deixa os elementos que não têm o equivalente que regras com nenhum outro elemento.  
  
## Exemplo  
  
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
  
  **um b c**  
 **um b c**  
 **a um**   
## Requisitos  
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::remove](../dotnet/list-remove-stl-clr.md)   
 [list::remove\_if](../dotnet/list-remove-if-stl-clr.md)   
 [list::sort](../dotnet/list-sort-stl-clr.md)