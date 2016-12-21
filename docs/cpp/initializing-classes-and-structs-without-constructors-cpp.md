---
title: "Inicializando classes e structs sem construtores (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: 3e55c3d6-1c6b-4084-b9e5-221b151402f4
caps.latest.revision: 3
caps.handback.revision: 1
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializando classes e structs sem construtores (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Nem sempre é necessário definir um construtor para uma classe, especialmente aqueles que são relativamente simples.  Os usuários podem inicializar objetos de uma classe ou estrutura usando inicialização uniforme, conforme mostrado no exemplo a seguir:  
  
```  
struct TempData  
{  
    int StationId;  
    time_t time;  
    double current;  
    double max;  
    double min;  
};  
  
int _tmain(int argc, _TCHAR* argv[])  
{  
    // Member initialization:  
    TempData td { 45978, GetCurrentTime(), 28.9, 37.0, 16.7 };  
  
    // Default initialization = {0,0,0,0,0}  
    TempData td_default {};  
  
    //Error C4700 uninitialized local variable  
    TempData td_noInit;   
    return 0;  
}  
```  
  
## Consulte também  
 [Classes e structs](../Topic/Classes%20and%20Structs%20\(C++\).md)   
 [Construtores](../cpp/constructors-cpp.md)