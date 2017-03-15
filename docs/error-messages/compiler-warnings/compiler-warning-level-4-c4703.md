---
title: "Compilador aviso (nível 4) C4703 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4703
dev_langs:
- C++
helpviewer_keywords:
- C4703
ms.assetid: 5dad454e-69e3-4931-9168-050a861c05f8
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 75aa17d24abfad3eec3bc74f82218af6ceedadec
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4703"></a>Compilador C4703 de aviso (nível 4)
Variável de ponteiro local 'name' usada potencialmente foi cancelada  
  
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
 [Avisos, /sdl e melhorando a detecção de variável não inicializada](http://blogs.msdn.com/b/sdl/archive/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection.aspx)
