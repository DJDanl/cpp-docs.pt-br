---
title: Compilador aviso (nível 1) C4572
ms.date: 11/04/2016
f1_keywords:
- C4572
helpviewer_keywords:
- C4572
ms.assetid: 482dee5a-29bd-4fc3-b769-9dfd4cd2a964
ms.openlocfilehash: b4d3356522faacfc343c33908b64597387fbe51c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50521049"
---
# <a name="compiler-warning-level-1-c4572"></a>Compilador aviso (nível 1) C4572

Atributo [ParamArray] é preterido sob /clr, use '...' em vez disso

Um estilo obsoleto para especificar uma lista de argumentos de variável foi usado. Ao compilar para o CLR, use a sintaxe de reticências, em vez de <xref:System.ParamArrayAttribute>. Para obter mais informações, consulte [listas de argumentos variáveis (...) (C + + / CLI) ](../../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4572.

```
// C4572.cpp
// compile with: /clr /W1
void Func([System::ParamArray] array<int> ^);   // C4572
void Func2(... array<int> ^){}   // OK

int main() {
   Func2(1, 2, 3);
}
```