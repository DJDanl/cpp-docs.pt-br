---
title: Compilador (nível 4) de aviso C4703 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4703
dev_langs:
- C++
helpviewer_keywords:
- C4703
ms.assetid: 5dad454e-69e3-4931-9168-050a861c05f8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d47cc6eb5692e39bfaa810bc15862bffb30083f2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33296101"
---
# <a name="compiler-warning-level-4-c4703"></a>Compilador C4703 de aviso (nível 4)
Potencialmente não inicializada variável de ponteiro local 'name' usado  
  
 A variável de ponteiro local *nome* pode ter sido usado sem receber um valor. Isso pode levar a resultados imprevisíveis.  
  
## <a name="example"></a>Exemplo  
 O código a seguir gera C4701 e C4703.  
  
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
  
```Output  
c:\src\test.cpp(10) : warning C4701: potentially uninitialized local variable 'p' used  
c:\src\test.cpp(10) : warning C4703: potentially uninitialized local pointer variable 'p' used  
  
```  
  
 Para corrigir esse aviso, inicialize a variável, conforme mostrado neste exemplo:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Compilador C4701 de aviso (nível 4)](../../error-messages/compiler-warnings/compiler-warning-level-4-c4701.md)   
 [Avisos, /sdl e melhorar a detecção de variável não inicializada](http://blogs.msdn.com/b/sdl/archive/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection.aspx)