---
title: "List:: Resize (STL CLR) | Microsoft Docs"
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
  - "cliext::list::resize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "redimensionar membro [STL/CLR]"
ms.assetid: c4b8d41f-a62b-4dbc-8568-0e0a9da24016
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list::resize (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Altera o número de elementos.  
  
## Sintaxe  
  
```  
void resize(size_type new_size);  
void resize(size_type new_size, value_type val);  
```  
  
#### Parâmetros  
 new\_size  
 Novo tamanho da sequência controlada.  
  
 Val  
 Valor do elemento de preenchimento.  
  
## Comentários  
 As funções de membro ambos Certifique\-se de que [list::size \(STL\/CLR\)](../dotnet/list-size-stl-clr.md)`()` daqui em diante retorna `new_size`. Se ele deve fazer a sequência controlada mais longo, a primeira função de membro acrescenta elementos com valor `value_type()`, enquanto a segunda função de membro acrescenta elementos com o valor `val`. Para tornar a sequência controlada mais curta, ambas as funções de membro efetivamente apagar o último elemento [list::size \(STL\/CLR\)](../dotnet/list-size-stl-clr.md)`() -` `new_size` vezes. Você pode usá\-lo para garantir que a sequência controlada tem tamanho `new_size`, corte ou preenchimento atual sequência controlada.  
  
## Exemplo  
  
```  
// cliext_list_resize.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
// construct an empty container and pad with default values   
    cliext::list<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
    c1.resize(4);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// resize to empty   
    c1.resize(0);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// resize and pad   
    c1.resize(5, L'x');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
Size () = 0 0 0 0 0 Size () = 0x x x x x  
```  
  
## Requisitos  
 **Cabeçalho:** \< cliext\/lista \>  
  
 **Namespace:** cliext  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [list::clear](../dotnet/list-clear-stl-clr.md)   
 [list::erase](../dotnet/list-erase-stl-clr.md)   
 [list::insert](../dotnet/list-insert-stl-clr.md)