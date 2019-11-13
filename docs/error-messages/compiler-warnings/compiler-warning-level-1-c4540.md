---
title: Aviso do compilador (nível 1) C4540
ms.date: 11/04/2016
f1_keywords:
- C4540
helpviewer_keywords:
- C4540
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
ms.openlocfilehash: 8e514f4f3cf0cc3ee95ff709eda307b143ab3b1c
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965693"
---
# <a name="compiler-warning-level-1-c4540"></a>Aviso do compilador (nível 1) C4540

dynamic_cast usado para converter para base inacessível ou ambígua; o teste de tempo de execução falhará (' type1 ' para ' type2 ')

Você usou `dynamic_cast` para converter de um tipo para outro. O compilador determinou que a conversão sempre falharia (retornando **NULL**) porque uma classe base é inacessível (`private`, por exemplo) ou ambígua (aparece mais de uma vez na hierarquia de classes, por exemplo).

Veja a seguir um exemplo desse aviso. A classe **B** é derivada da classe **A**. O programa usa `dynamic_cast` para conversão da classe **b** (a classe derivada) para a classe **A**, que sempre falhará porque a classe **b** está `private` e, portanto, inacessível. Alterar o acesso de **um** para **público** resolverá o aviso.

```cpp
// C4540.cpp
// compile with: /W1

struct A {
   virtual void g() {}
};

struct B : private A {
   virtual void g() {}
};

int main() {
   B b;
   A * ap = dynamic_cast<A*>(&b);   // C4540
}
```