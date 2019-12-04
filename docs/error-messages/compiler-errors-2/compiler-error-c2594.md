---
title: Erro do compilador C2594
ms.date: 11/04/2016
f1_keywords:
- C2594
helpviewer_keywords:
- C2594
ms.assetid: 68cd708f-266e-44b0-a211-3e3ab63b11bf
ms.openlocfilehash: ade657f9ada2a2249d2f96b7caada7b9719195d1
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759328"
---
# <a name="compiler-error-c2594"></a>Erro do compilador C2594

' operator ': conversões ambíguas de ' type1 ' para ' type2 '

Nenhuma conversão de *type1* para *type2* era mais direta do que qualquer outra. Sugerimos duas soluções possíveis para converter de *type1* para *type2*. A primeira opção é definir uma conversão direta de *type1* para *type2*, e a segunda opção é especificar uma sequência de conversões de *type1* para *type2*.

O exemplo a seguir gera C2594. A resolução sugerida para o erro é uma sequência de conversões:

```cpp
// C2594.cpp
// compile with: /c
struct A{};
struct I1 : A {};
struct I2 : A {};
struct D : I1, I2 {};

A *f (D *p) {
   return (A*) (p);    // C2594

// try the following line instead
// return static_cast<A *>(static_cast<I1 *>(p));
}
```
