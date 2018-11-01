---
title: Compilador aviso (nível 1) C4258
ms.date: 11/04/2016
f1_keywords:
- C4258
helpviewer_keywords:
- C4258
ms.assetid: bbb75e6d-6693-4e62-8ed3-b006a0ec55e3
ms.openlocfilehash: a3ce4c81a86920baddfc1b277df0236a96254be4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478255"
---
# <a name="compiler-warning-level-1-c4258"></a>Compilador aviso (nível 1) C4258

'variable': definição a partir o loop é ignorada; a definição do escopo delimitador é usada"

Sob [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md), variáveis definidas em um [para](../../cpp/for-statement-cpp.md) loop saem do escopo após o **para** loop termina. Este aviso ocorre se uma variável com o mesmo nome da variável de loop, mas definido no loop delimitador, é usada novamente no escopo que contém o **para** loop. Por exemplo:

```
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