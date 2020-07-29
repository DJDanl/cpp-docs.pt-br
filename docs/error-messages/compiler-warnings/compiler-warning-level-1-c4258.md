---
title: Aviso do compilador (nível 1) C4258
ms.date: 11/04/2016
f1_keywords:
- C4258
helpviewer_keywords:
- C4258
ms.assetid: bbb75e6d-6693-4e62-8ed3-b006a0ec55e3
ms.openlocfilehash: a192fb9d8dc046bb3493b90b85371175520ccf95
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230721"
---
# <a name="compiler-warning-level-1-c4258"></a>Aviso do compilador (nível 1) C4258

' Variable ': a definição do loop for é ignorada; a definição do escopo de circunscrição é usada "

Em [/ze](../../build/reference/za-ze-disable-language-extensions.md) e [/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md), as variáveis definidas em um loop [for](../../cpp/for-statement-cpp.md) saem do escopo após o **`for`** encerramento do loop. Esse aviso ocorre se uma variável com o mesmo nome que a variável de loop, mas definida no loop delimitador, for usada novamente no escopo que contém o **`for`** loop. Por exemplo:

```cpp
// C4258.cpp
// compile with: /Zc:forScope /W1
int main()
{
   int i;
   {
      for (int i =0; i < 1; i++)
         ;
      i = 20;   // C4258 i (in for loop) has gone out of scope
   }
}
```
