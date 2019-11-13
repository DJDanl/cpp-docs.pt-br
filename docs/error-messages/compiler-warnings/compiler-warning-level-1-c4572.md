---
title: Aviso do compilador (nível 1) C4572
ms.date: 11/04/2016
f1_keywords:
- C4572
helpviewer_keywords:
- C4572
ms.assetid: 482dee5a-29bd-4fc3-b769-9dfd4cd2a964
ms.openlocfilehash: 52285f391af0a8028307cbbc320af33f9cb1fca5
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965955"
---
# <a name="compiler-warning-level-1-c4572"></a>Aviso do compilador (nível 1) C4572

O atributo [ParamArray] está preterido em/CLR, use '... ' Stead

Um estilo obsoleto para especificar uma lista de argumentos variáveis foi usado. Ao compilar para o CLR, use a sintaxe de reticências em vez de <xref:System.ParamArrayAttribute>. Para obter mais informações, consulte [listas de argumentos variáveis (...C++) (/CLI)](../../extensions/variable-argument-lists-dot-dot-dot-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4572.

```cpp
// C4572.cpp
// compile with: /clr /W1
void Func([System::ParamArray] array<int> ^);   // C4572
void Func2(... array<int> ^){}   // OK

int main() {
   Func2(1, 2, 3);
}
```