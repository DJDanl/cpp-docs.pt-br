---
title: Erro do compilador C2594
ms.date: 11/04/2016
f1_keywords:
- C2594
helpviewer_keywords:
- C2594
ms.assetid: 68cd708f-266e-44b0-a211-3e3ab63b11bf
ms.openlocfilehash: 75e3b438dd69f8879fdc2273a8f0357229941340
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386896"
---
# <a name="compiler-error-c2594"></a>Erro do compilador C2594

'operator': conversões ambíguas de 'type1' em 'type2'

Nenhuma conversão de *type1* à *type2* foi mais direta do que qualquer outro. Sugerimos duas soluções possíveis para converter do *type1* à *type2*. A primeira opção é definir uma conversão direta do *type1* à *type2*, e a segunda opção é especificar uma sequência de conversões de *type1* para  *type2*.

O exemplo a seguir gera C2594. A resolução sugerida para o erro é uma sequência de conversões:

```
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