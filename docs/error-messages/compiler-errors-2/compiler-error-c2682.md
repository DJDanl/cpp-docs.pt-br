---
title: Erro do compilador C2682
ms.date: 11/04/2016
f1_keywords:
- C2682
helpviewer_keywords:
- C2682
ms.assetid: 30c6a7c4-f5f7-4fe8-81a8-c48938521ab4
ms.openlocfilehash: 2697ce5a790fffe762d97ca3380853514de6d437
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220256"
---
# <a name="compiler-error-c2682"></a>Erro do compilador C2682

Não é possível usar casting_operator para converter de ' type1 ' para ' type2 '

Um operador de conversão tentou converter entre tipos incompatíveis. Por exemplo, você não pode usar o operador de [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter um ponteiro para uma referência. O **`dynamic_cast`** operador não pode ser usado para converter qualificadores ausentes. Todos os qualificadores nos tipos devem corresponder.

Você pode usar o **`const_cast`** operador para remover atributos como **`const`** , **`volatile`** ou **`__unaligned`** .

O exemplo a seguir gera C2682:

```cpp
// C2682.cpp
class A { virtual void f(); };
class B: public A {};

void g(A* pa) {
    B& rb = dynamic_cast<B&>(pa); // C2682
}
```

O exemplo a seguir gera C2682:

```cpp
// C2682b.cpp
// compile with: /clr
ref struct R{};
ref struct RR : public R{};
ref struct H {
   RR^ r ;
   short s;
   int i;
};

int main() {
   H^ h = gcnew H();
   interior_ptr<int>lr = &(h->i);
   interior_ptr<short>ssr = safe_cast<interior_ptr<short> >(lr);   // C2682
   interior_ptr<short>ssr = reinterpret_cast<interior_ptr<short> >(lr);   // OK
}
```
