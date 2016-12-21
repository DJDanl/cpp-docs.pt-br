---
title: "make_collection (STL/CLR) | Microsoft Docs"
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
  - "cliext::make_collection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função make_collection [STL/CLR]"
ms.assetid: c25fb0cb-ebd8-4198-a565-bad28d32ee19
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# make_collection (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Faça `range_adapter` de um par de iterador.  
  
## Sintaxe  
  
```  
template<typename Iter>  
    range_adapter<Iter> make_collection(Iter first, Iter last);  
```  
  
#### Parâmetros  
 ITER  
 O tipo dos iteradores ajustados.  
  
 primeiro  
 Primeiro iterador a quebra de texto.  
  
 last  
 Dependendo de iterador a quebra de texto.  
  
## Comentários  
 A função do modelo retorna `gcnew range_adapter<Iter>(``first``,` `last``)`.  Use\-a para construir um objeto de `range_adapter``<Iter>` de um par de iteradores.  
  
## Exemplo  
  
```  
// cliext_make_collection.cpp   
// compile with: /clr   
#include <cliext/adapter>   
#include <cliext/deque>   
  
typedef cliext::deque<wchar_t> Mycont;   
typedef cliext::range_adapter<Mycont::iterator> Myrange;   
int main()   
    {   
    cliext::deque<wchar_t> d1;   
    d1.push_back(L'a');   
    d1.push_back(L'b');   
    d1.push_back(L'c');   
  
// display contents " a b c"   
    for each (wchar_t elem in d1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Collections::ICollection^ p1 =   
        cliext::make_collection(d1.begin(), d1.end());   
    System::Console::WriteLine("Count = {0}", p1->Count);   
    System::Console::WriteLine("IsSynchronized = {0}",   
        p1->IsSynchronized);   
    System::Console::WriteLine("SyncRoot not nullptr = {0}",   
        p1->SyncRoot != nullptr);   
  
// copy the sequence   
    cli::array<System::Object^>^ a1 = gcnew cli::array<System::Object^>(5);   
  
    a1[0] = L'|';   
    p1->CopyTo(a1, 1);   
    a1[4] = L'|';   
    for each (wchar_t elem in a1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    return (0);   
    }  
  
```  
  
  **um b c**  
**Contagem \= 3**  
**IsSynchronized \= false**  
**O nullptr de SyncRoot não \= retifica**  
 **&#124; um b c &#124;**   
## Requisitos  
 cliext \<\/adaptador de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [range\_adapter](../dotnet/range-adapter-stl-clr.md)