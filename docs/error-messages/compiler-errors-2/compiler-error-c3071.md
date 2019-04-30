---
title: Erro do compilador C3071
ms.date: 11/04/2016
f1_keywords:
- C3071
helpviewer_keywords:
- C3071
ms.assetid: 69879e66-a60e-4058-9bbd-d5c5e2d8ee37
ms.openlocfilehash: 1debe431711681a98b9472c85864d84373ec42d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406633"
---
# <a name="compiler-error-c3071"></a>Erro do compilador C3071

o operador 'operator' só pode ser aplicado a uma instância de uma classe ref ou um tipo de valor

Um operador CLR não pode ser usado em um tipo nativo. O operador pode ser usado em uma classe ref ou uma struct de referência (um tipo de valor), mas não um tipo nativo, como int ou um alias para um tipo nativo como System::Int32. Esses tipos não podem ser convertidos de código C++ de forma que se refere à variável nativa, portanto, o operador não pode ser usado.

Para obter mais informações, consulte [operador de referência de acompanhamento](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3071.

```
// C3071.cpp
// compile with: /clr
class N {};
ref struct R {};

int main() {
   N n;
   %n;   // C3071

   R r;
   R ^ r2 = %r;   // OK
}
```