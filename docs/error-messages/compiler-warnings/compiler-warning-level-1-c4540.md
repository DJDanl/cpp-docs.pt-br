---
title: Aviso do compilador (nível 1) C4540
ms.date: 11/04/2016
f1_keywords:
- C4540
helpviewer_keywords:
- C4540
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
ms.openlocfilehash: 13935e7eebdf3e7b7e89fad8c55d410cf2788e4d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230643"
---
# <a name="compiler-warning-level-1-c4540"></a>Aviso do compilador (nível 1) C4540

dynamic_cast usado para converter para base inacessível ou ambígua; o teste de tempo de execução falhará (' type1 ' para ' type2 ')

Você usou **`dynamic_cast`** para converter de um tipo para outro. O compilador determinou que a conversão sempre falharia (retornando **NULL**) porque uma classe base é inacessível ( **`private`** , por exemplo) ou ambígua (aparece mais de uma vez na hierarquia de classe, por exemplo).

Veja a seguir um exemplo desse aviso. A classe **B** é derivada da classe **A**. O programa usa **`dynamic_cast`** para converter da classe **b** (a classe derivada) para a classe **A**, que sempre falhará porque a classe **b** é **`private`** e, portanto, inacessível. Alterar o acesso de **um** para **`public`** resolverá o aviso.

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
