---
title: Aviso do compilador (nível 1) C4288
ms.date: 11/04/2016
f1_keywords:
- C4288
helpviewer_keywords:
- C4288
ms.assetid: 6aaeb139-90cd-457a-9d37-65687042736f
ms.openlocfilehash: a732614ac5d71168ece8ada8e468afa5ba54c1f9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220074"
---
# <a name="compiler-warning-level-1-c4288"></a>Aviso do compilador (nível 1) C4288

> extensão não padrão usada: ' var ': a variável de controle de loop declarada no loop for é usada fora do escopo de loop for; Ele está em conflito com a declaração no escopo externo

Ao compilar com [`/Ze`](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc: forScope-**, uma variável declarada em um **`for`** loop foi usada após o escopo [do loop for](../../cpp/for-statement-cpp.md). Uma extensão da Microsoft para a linguagem C++ permite que essa variável permaneça no escopo e C4288 o lembra de que a primeira declaração da variável não é usada.

Consulte [`/Zc:forScope`](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar a extensão da Microsoft em **`for`** loops com/Ze.

O exemplo a seguir gera C4288:

```cpp
// C4288.cpp
// compile with: /W1 /c /Zc:forScope-
int main() {
   int i = 0;    // not used in this program
   for (int i = 0 ; ; ) ;
   i++;   // C4288 using for-loop declaration of i
}
```
