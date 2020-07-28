---
title: Erro do compilador C2683
ms.date: 11/04/2016
f1_keywords:
- C2683
helpviewer_keywords:
- C2683
ms.assetid: db605e4f-601b-4d05-92a1-c43ca24de08d
ms.openlocfilehash: cd629b093bdc3992a8ea69f498b1e1cdab1b8826
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214627"
---
# <a name="compiler-error-c2683"></a>Erro do compilador C2683

' cast ': ' type ' não é um tipo polimórfico

Você não pode usar [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter de uma classe não polimórfica (uma classe sem funções virtuais).

Você pode usar [static_cast](../../cpp/static-cast-operator.md) para executar conversões de tipos não polimórficos. No entanto, **`static_cast`** o não executa uma verificação de tempo de execução.

O exemplo a seguir gera C2683:

```cpp
// C2683.cpp
// compile with: /c
class B { };
class D : public B { };

void f(B* pb) {
   D* pd1 = dynamic_cast<D*>(pb);  // C2683
   D* pd1 = static_cast<D*>(pb);   // OK
}
```
