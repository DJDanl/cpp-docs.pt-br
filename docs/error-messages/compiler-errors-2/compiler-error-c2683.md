---
title: Erro do compilador C2683
ms.date: 11/04/2016
f1_keywords:
- C2683
helpviewer_keywords:
- C2683
ms.assetid: db605e4f-601b-4d05-92a1-c43ca24de08d
ms.openlocfilehash: 49e4897ad5db866aa1ca42589859bedff12718df
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62266862"
---
# <a name="compiler-error-c2683"></a>Erro do compilador C2683

'cast': 'type' não é um tipo polimórfico

Não é possível usar [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter de uma classe não é polimórfico (uma classe com nenhuma função virtual).

Você pode usar [static_cast](../../cpp/static-cast-operator.md) para realizar conversões de tipos não polimórficos. No entanto, `static_cast` não realiza uma verificação de tempo de execução.

O exemplo a seguir gera C2683:

```
// C2683.cpp
// compile with: /c
class B { };
class D : public B { };

void f(B* pb) {
   D* pd1 = dynamic_cast<D*>(pb);  // C2683
   D* pd1 = static_cast<D*>(pb);   // OK
}
```