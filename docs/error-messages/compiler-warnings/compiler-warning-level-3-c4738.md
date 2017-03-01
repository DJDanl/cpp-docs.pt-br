---
title: "Compilador aviso (nível 3) C4738 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4738
dev_langs:
- C++
helpviewer_keywords:
- C4738
ms.assetid: 9094895f-7eec-46c2-83d3-249b761d585e
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4c05725e155f4b3f5de4a17f66ae15d3b2885a1e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4738"></a>Compilador C4738 de aviso (nível 3)
armazenando o resultado float de 32 bits na memória, possível perda de desempenho  
  
 C4738 avisa que o resultado de uma atribuição, converter, passou um argumento ou outra operação pode precisar ser arredondado ou que a operação foi executado sem registros e precisava usar memória (derramamento). Isso pode resultar em perda de desempenho.  
  
 Para resolver esse aviso e evitar arredondamento, compilar com [/fp:fast](../../build/reference/fp-specify-floating-point-behavior.md) ou use `double`s em vez de `float`s.  
  
 Para resolver esse aviso e evitar a falta de registros, alterar a ordem de cálculo e modificar seu uso de inlining  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4738:  
  
```  
// C4738.cpp  
// compile with: /c /fp:precise /O2 /W3  
// processor: x86  
#include <stdio.h>  
  
#pragma warning(default : 4738)  
  
float func(float f)  
{  
    return f;  
}  
  
int main()  
{  
    extern float f, f1, f2;  
    double d = 0.0;  
  
    f1 = func(d);  
    f2 = (float) d;  
    f = f1 + f2;   // C4738  
    printf_s("%f\n", f);  
}  
```
