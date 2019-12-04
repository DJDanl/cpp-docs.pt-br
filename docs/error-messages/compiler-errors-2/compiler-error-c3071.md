---
title: Erro do compilador C3071
ms.date: 11/04/2016
f1_keywords:
- C3071
helpviewer_keywords:
- C3071
ms.assetid: 69879e66-a60e-4058-9bbd-d5c5e2d8ee37
ms.openlocfilehash: 26a95b18970aef450c6fdf718910aa3f816fd778
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759406"
---
# <a name="compiler-error-c3071"></a>Erro do compilador C3071

operador "Operator" só pode ser aplicado a uma instância de uma ref class ou um tipo de valor

Um operador CLR não pode ser usado em um tipo nativo. O operador pode ser usado em uma ref class ou uma struct ref (um tipo Value), mas não um tipo nativo, como int ou um alias para um tipo nativo, como System:: Int32. Esses tipos não podem ser embutidos no C++ código de forma que se refira à variável nativa, portanto, o operador não pode ser usado.

Para obter mais informações, consulte [Control Reference Operator](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3071.

```cpp
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
