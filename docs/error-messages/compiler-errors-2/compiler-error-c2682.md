---
title: Erro do compilador C2682
ms.date: 11/04/2016
f1_keywords:
- C2682
helpviewer_keywords:
- C2682
ms.assetid: 30c6a7c4-f5f7-4fe8-81a8-c48938521ab4
ms.openlocfilehash: c1ce0132ed0db418359effe60f59e1eb2d3cc221
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760277"
---
# <a name="compiler-error-c2682"></a>Erro do compilador C2682

Não é possível usar casting_operator para converter de ' type1 ' para ' type2 '

Um operador de conversão tentou converter entre tipos incompatíveis. Por exemplo, você não pode usar o operador de [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter um ponteiro para uma referência. O operador de `dynamic_cast` não pode ser usado para converter qualificadores ausentes. Todos os qualificadores nos tipos devem corresponder.

Você pode usar o operador de `const_cast` para remover atributos como `const`, `volatile`ou `__unaligned`.

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
