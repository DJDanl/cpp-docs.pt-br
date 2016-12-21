---
title: "Compilador C4701 de aviso (n&#237;vel 4) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4701"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4701"
ms.assetid: d7c76c66-1f3f-4d3c-abe4-5d94c84a5a1f
caps.latest.revision: 12
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4701 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Variável local potencialmente não inicializada “name” usado  
  
 A variável local *name* pode ter sido usado sem ser atribuído um valor.  Isso pode levar a resultados imprevisíveis.  
  
## Exemplo  
 O seguinte código gerenciado C4701 e C4703.  
  
```cpp  
#include <malloc.h>  
  
void func(int size)  
{  
    void* p;  
    if (size < 256) {  
        p = malloc(size);  
    }  
  
    if (p != nullptr) // C4701 and C4703  
        free(p);  
}  
  
void main()  
{  
    func(9);  
}  
```  
  
  **c:\\src\\test.cpp\(10\) : C4701 de aviso: variável local potencialmente não inicializada “p” usado**  
 **c:\\src\\test.cpp\(10\) : C4703 de aviso: variável de ponteiro local potencialmente não inicializada “p” usado** Para corrigir esse aviso, inicializando a variável conforme mostrado neste exemplo:  
  
```cpp  
#include <malloc.h>  
  
void func(int size)  
{  
    void* p = nullptr;  
    if (size < 256) {  
        p = malloc(size);  
    }  
  
    if (p != nullptr)  
        free(p);  
}  
  
void main()  
{  
    func(9);  
}  
```  
  
## Consulte também  
 [Compilador C4703 de aviso \(nível 4\)](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)   
 [Avisos, \/sdl, e melhoria na detecção variável não inicializada](http://blogs.msdn.com/b/sdl/archive/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection.aspx)