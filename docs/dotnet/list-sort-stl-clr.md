---
title: "list::sort (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::sort"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro sort [STL/CLR]"
ms.assetid: f811d5f4-a19e-4194-8765-1e68097c52f0
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::sort (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Classifica a sequência controlada.  
  
## Sintaxe  
  
```  
void sort();  
template<typename Pred2>  
    void sort(Pred2 pred);  
```  
  
#### Parâmetros  
 pred  
 Comparador para pares do elemento.  
  
## Comentários  
 A primeira função de membro reorganiza os elementos na sequência controlada de modo que sejam classificados por `operator<` \-\- os elementos não diminuir o valor como você passa com a sequência.  Você usa essa função de membro para classificar a sequência em ordem crescente.  
  
 A segunda função de membro se comportará da mesma forma que os primeiros, exceto que a sequência é solicitada por `pred` \-\- `pred``(X, Y)` é false para qualquer elemento que `X` seguir o elemento `Y` na sequência resultante.  Você usará para classificar a sequência em uma ordem que você especifica para uma função ou um delegação de predicado.  
  
 Ambas as funções executam um tipo estável \-\- nenhum par de elementos na sequência controlada original é invertido na sequência resultante controlada.  
  
## Exemplo  
  
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
  
  **um b c**  
 **b para c**  
 **um b c**   
## Requisitos  
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::merge](../dotnet/list-merge-stl-clr.md)   
 [list::reverse \(STL\/CLR\)](../dotnet/list-reverse-stl-clr.md)   
 [list::splice](../Topic/list::splice%20\(STL-CLR\).md)   
 [list::unique](../dotnet/list-unique-stl-clr.md)