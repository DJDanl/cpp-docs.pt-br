---
title: Compilador (nível 1) de aviso C4750 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4750
dev_langs:
- C++
helpviewer_keywords:
- C4750
ms.assetid: b0b2c938-7d2a-4c36-8270-7daee15ffee3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ffe378f8d2466e702c90127e44f3b48831abf50
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282438"
---
# <a name="compiler-warning-level-1-c4750"></a>Compilador C4750 de aviso (nível 1)
'Identificador': função com alloca () embutida dentro de um loop  
  
 A função 'Identificador' força expansão embutidos da [alloca](../../c-runtime-library/reference/alloca.md) função dentro de um loop, o que pode causar um estouro de pilha quando o loop é executado.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Certifique-se de que a função 'Identificador' não é modificada com a [forceinline](../../cpp/inline-functions-cpp.md) especificador.  
  
2.  Certifique-se de que a função 'Identificador' não contém um [alloca](../../c-runtime-library/reference/alloca.md) função que está contida em um loop.  
  
3.  Não especifique o [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/Ox](../../build/reference/ox-full-optimization.md), ou [/Og](../../build/reference/og-global-optimizations.md) switch de compilação.  
  
4.  Local de [alloca](../../c-runtime-library/reference/alloca.md) funcionar em um [tente-exceto instrução](../../cpp/try-except-statement.md) que irá detectar um estouro de pilha.  
  
## <a name="example"></a>Exemplo  
 O código a seguir exemplo chama `MyFunction` em um loop e `MyFunction` chama o `_alloca` função. O `__forceinline` modificador faz com que a expansão embutidos da `_alloca` função.  
  
```  
// c4750.cpp  
// compile with: /O2 /W1 /c  
#include <intrin.h>  
  
char * volatile newstr;  
  
__forceinline void myFunction(void) // C4750 warning  
{  
// The _alloca function does not require a __try/__except   
// block because the example uses compiler option /c.  
    newstr = (char * volatile) _alloca(1000);  
}  
  
int main(void)  
{  
    for (int i=0; i<50000; i++)  
       myFunction();  
    return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [_alloca](../../c-runtime-library/reference/alloca.md)