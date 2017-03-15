---
title: "Compilador aviso (nível 1) C4750 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4750
dev_langs:
- C++
helpviewer_keywords:
- C4750
ms.assetid: b0b2c938-7d2a-4c36-8270-7daee15ffee3
caps.latest.revision: 5
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
ms.sourcegitcommit: 84f0628de933344eb23dc6325679abdcd3699c3a
ms.openlocfilehash: 6e22ef89b92a5b584979abbd370f82b482cf74e0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4750"></a>Compilador C4750 de aviso (nível 1)
'identifier': função com _alloca() embutidas em um loop  
  
 A função 'identifier' força a expansão embutida do [alloca](../../c-runtime-library/reference/alloca.md) função dentro de um loop, o que pode causar um estouro de pilha quando o loop é executado.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Certifique-se de que a função 'identifier' não é modificada com a [forceinline](../../cpp/inline-functions-cpp.md) especificador.  
  
2.  Certifique-se de que a função 'identifier' não contém um [alloca](../../c-runtime-library/reference/alloca.md) função que está contida em um loop.  
  
3.  Não especifique o [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/Ox](../../build/reference/ox-full-optimization.md), ou [/Og](../../build/reference/og-global-optimizations.md) comutador de compilação.  
  
4.  Local de [alloca](../../c-runtime-library/reference/alloca.md) funcionem em uma [tente-exceto instrução](../../cpp/try-except-statement.md) que irá capturar um estouro de pilha.  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo de código chama `MyFunction` em um loop e `MyFunction` chama o `_alloca` função. O `__forceinline` modificador faz com que a expansão embutida do `_alloca` função.  
  
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
