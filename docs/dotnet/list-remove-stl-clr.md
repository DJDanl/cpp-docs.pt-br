---
title: "list::remove (STL/CLR) | Microsoft Docs"
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
  - "cliext::list::remove"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Membro remove [STL/CLR]"
ms.assetid: eaf598ee-e8fd-4cc0-be69-ca81a80e1d51
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::remove (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove um elemento com um valor especificado.  
  
## Sintaxe  
  
```  
void remove(value_type val);  
```  
  
#### Parâmetros  
 val  
 Valor do elemento a ser removido.  
  
## Comentários  
 A função de membro remove um elemento na sequência controlada para que `((System::Object^)``val``)->Equals((System::Object^)x)` é true \(se houver\).  Use\-a para apagar um elemento arbitrário com o valor especificado.  
  
## Exemplo  
  
```  
// cliext_list_remove.cpp   
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
  
// fail to remove and redisplay   
    c1.remove(L'A');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();  
  
// remove and redisplay   
    c1.remove(L'b');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
 **um b c**  
 **c**   
## Requisitos  
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::clear](../dotnet/list-clear-stl-clr.md)   
 [list::erase](../dotnet/list-erase-stl-clr.md)   
 [list::remove\_if](../dotnet/list-remove-if-stl-clr.md)