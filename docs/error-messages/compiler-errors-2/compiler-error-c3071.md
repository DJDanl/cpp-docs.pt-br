---
title: Erro do compilador C3071
ms.date: 11/04/2016
f1_keywords:
- C3071
helpviewer_keywords:
- C3071
ms.assetid: 69879e66-a60e-4058-9bbd-d5c5e2d8ee37
ms.openlocfilehash: 6960dbf62fd30b822f0d7c7a3c46a29a4115913f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428343"
---
# <a name="compiler-error-c3071"></a>Erro do compilador C3071

o operador 'operator' só pode ser aplicado a uma instância de uma classe ref ou um tipo de valor

Um operador CLR não pode ser usado em um tipo nativo. O operador pode ser usado em uma classe ref ou uma struct de referência (um tipo de valor), mas não um tipo nativo, como int ou um alias para um tipo nativo como System::Int32. Esses tipos não podem ser convertidos de código C++ de forma que se refere à variável nativa, portanto, o operador não pode ser usado.

Para obter mais informações, consulte [operador de referência de acompanhamento](../../windows/tracking-reference-operator-cpp-component-extensions.md).

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