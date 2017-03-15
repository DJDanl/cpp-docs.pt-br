---
title: "list::merge (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::merge"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "membro merge [STL/CLR]"
ms.assetid: f8e93cd3-bd08-4086-859b-08a2899cc9a6
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::merge (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Mescla duas sequências ordenadas controladas.  
  
## Sintaxe  
  
```  
void merge(list<Value>% right);  
template<typename Pred2>  
    void merge(list<Value>% right, Pred2 pred);  
```  
  
#### Parâmetros  
 pred  
 Comparador para pares do elemento.  
  
 direita  
 Contêiner a ser mesclado em.  
  
## Comentários  
 A primeira função de membro remove todos os elementos de sequência controlada por `right` e inserir na sequência controlada.  Ambas as sequências devem ser ordenadas por `operator<` anteriormente \-\- os elementos não devem diminuir o valor como você passa com uma ou outra sequência.  A sequência resultante também estiver ordenada por `operator<`.  Você usa essa função de membro para mesclar duas sequências também esse aumento no valor em uma sequência que aumenta no valor.  
  
 A segunda função de membro se comportará da mesma forma que os primeiros, exceto que as sequências são ordenadas por `pred` \-\- `pred``(X, Y)` deve ser false para qualquer elemento que `X` seguir o elemento `Y` na sequência.  Você usará para mesclar duas sequências ordenadas por uma função de predicado ou para delegá\-las que você especifica.  
  
 Ambas as funções executam uma mesclagem estável \-\- nenhum par de elementos em uma das sequências controladas originais é invertido na sequência resultante controlada.  Além disso, se um par de elementos `X` e controlada `Y` na sequência resultante tem a ordenação equivalente \-\- `!(X < Y) && !(X < Y)` \-\- um elemento de sequência controlada original aparecer antes de um elemento de sequência controlada por `right`.  
  
## Exemplo  
  
```  
// cliext_list_merge.cpp   
// compile with: /clr   
#include <cliext/list>   
  
typedef cliext::list<wchar_t> Mylist;   
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'c');   
    c1.push_back(L'e');   
  
// display initial contents " a c e"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    cliext::list<wchar_t> c2;   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
    c2.push_back(L'f');   
  
// display initial contents " b d f"   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// merge and display   
    cliext::list<wchar_t> c3(c1);   
    c3.merge(c2);   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c2.size() = {0}", c2.size());   
  
// sort descending, merge descending, and redisplay   
    c1.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    c3.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    c3.merge(c1, cliext::greater<wchar_t>());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c1.size() = {0}", c1.size());   
    return (0);   
    }  
  
```  
  
  **c e**  
 **b de f**  
 **um b e c de f**  
**c2.size\(\) \= 0**  
 **C. a E.**  
 **f b para c e d**  
 **f e c e d um b para c**  
**c1.size\(\) \= 0**   
## Requisitos  
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::sort](../dotnet/list-sort-stl-clr.md)   
 [list::splice](../Topic/list::splice%20\(STL-CLR\).md)