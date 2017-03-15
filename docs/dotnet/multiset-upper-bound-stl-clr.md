---
title: "multiset::upper_bound (STL/CLR) | Microsoft Docs"
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
  - "cliext::multiset::upper_bound"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro upper_bound [STL/CLR]"
ms.assetid: 4a5af99f-a2a1-45be-9b01-c0055d4d0e35
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# multiset::upper_bound (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Localiza de extremidade do intervalo que corresponde a uma chave especificada.  
  
## Sintaxe  
  
```  
iterator upper_bound(key_type key);  
```  
  
#### Parâmetros  
 key  
 Valor de chave para pesquisar por.  
  
## Comentários  
 A função de membro o elemento determina o último `X` na sequência controlada que tem o equivalente de ordenação da `key`.  Se tal elemento existe, ou se `X` é o elemento mais recente na sequência controlada, retorna [multiset::end](../dotnet/multiset-end-stl-clr.md)`()`; se não retorna um iterador que designa o primeiro elemento além de `X`.  Use\-a para localizar atualmente o término de uma sequência de elementos na sequência controlada que correspondem a uma chave especificada.  
  
## Exemplo  
  
```  
// cliext_multiset_upper_bound.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
    Mymultiset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("upper_bound(L'x')==end() = {0}",   
        c1.upper_bound(L'x') == c1.end());   
  
    System::Console::WriteLine("*upper_bound(L'a') = {0}",   
        *c1.upper_bound(L'a'));   
    System::Console::WriteLine("*upper_bound(L'b') = {0}",   
        *c1.upper_bound(L'b'));   
    return (0);   
    }  
  
```  
  
  **um b c**  
**upper\_bound\(L'x'\)\=\=end\(\) \= retifica**  
**\*upper\_bound \(L'a\) \= b**  
**\*upper\_bound \(L'b\) \= c**   
## Requisitos  
 cliext \<\/conjunto de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [multiset](../dotnet/multiset-stl-clr.md)   
 [multiset::count](../dotnet/multiset-count-stl-clr.md)   
 [multiset::equal\_range](../dotnet/multiset-equal-range-stl-clr.md)   
 [multiset::find](../Topic/multiset::find%20\(STL-CLR\).md)   
 [multiset::lower\_bound](../Topic/multiset::lower_bound%20\(STL-CLR\).md)