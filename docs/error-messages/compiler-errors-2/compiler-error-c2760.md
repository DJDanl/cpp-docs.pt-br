---
title: Erro do compilador C2760
ms.date: 11/04/2016
f1_keywords:
- C2760
helpviewer_keywords:
- C2760
ms.assetid: 585757fd-d519-43f3-94e5-50316ac8b90b
ms.openlocfilehash: 24c33d90c0f91aa3c4b01142902afc4333c1c732
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50550560"
---
# <a name="compiler-error-c2760"></a>Erro do compilador C2760

Erro de sintaxe: esperado 'Nome1' não 'nome2'

Um operador de conversão é usado com um operador inválido.

O exemplo a seguir gera C2760:

```
// C2760.cpp
class B {};
class D : public B {};

void f(B* pb) {
    D* pd1 = static_cast<D*>(pb);
    D* pd2 = static_cast<D*>=(pb);  // C2760
    D* pd3 = static_cast<D*=(pb);   // C2760
}
```