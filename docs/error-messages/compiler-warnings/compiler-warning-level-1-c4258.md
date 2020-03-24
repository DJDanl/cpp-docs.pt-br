---
title: Aviso do compilador (nível 1) C4258
ms.date: 11/04/2016
f1_keywords:
- C4258
helpviewer_keywords:
- C4258
ms.assetid: bbb75e6d-6693-4e62-8ed3-b006a0ec55e3
ms.openlocfilehash: 198873792743a9ccdee94d44e2a0599348589ee6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163200"
---
# <a name="compiler-warning-level-1-c4258"></a>Aviso do compilador (nível 1) C4258

' Variable ': a definição do loop for é ignorada; a definição do escopo de circunscrição é usada "

Em [/ze](../../build/reference/za-ze-disable-language-extensions.md) e [/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md), as variáveis definidas em um loop [for](../../cpp/for-statement-cpp.md) saem do escopo depois que o loop **for** termina. Esse aviso ocorre se uma variável com o mesmo nome que a variável de loop, mas definida no loop delimitador, for usada novamente no escopo que contém o loop **for** . Por exemplo:

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
