---
title: Compilador aviso (nível 3) C4738 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4738
dev_langs:
- C++
helpviewer_keywords:
- C4738
ms.assetid: 9094895f-7eec-46c2-83d3-249b761d585e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 50b94cde2f8809b8ce56dc599804d11b8d058166
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4738"></a>Compilador C4738 de aviso (nível 3)
armazenando o resultado float de 32 bits na memória, possível perda de desempenho  
  
 C4738 avisa que o resultado de uma atribuição, converter, passou um argumento ou outra operação pode precisar ser arredondado ou que a operação ficou sem registros e necessárias para usar memória (derramada). Isso pode resultar em perda de desempenho.  
  
 Para resolver este aviso e evitar arredondamento, compile com [Fast](../../build/reference/fp-specify-floating-point-behavior.md) ou use `double` em vez de `float`.  
  
 Para resolver este aviso e evitar a falta de registros, alterar a ordem de cálculo e modificar seu uso de inlining  
  
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