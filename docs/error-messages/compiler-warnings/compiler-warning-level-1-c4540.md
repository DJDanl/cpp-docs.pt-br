---
title: Compilador aviso (nível 1) C4540
ms.date: 11/04/2016
f1_keywords:
- C4540
helpviewer_keywords:
- C4540
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
ms.openlocfilehash: 86f6cd866f7708277ebba436ba7c076086dc9c8c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160699"
---
# <a name="compiler-warning-level-1-c4540"></a>Compilador aviso (nível 1) C4540

dynamic_cast usado para converter para base inacessível ou ambígua; teste de tempo de execução falhará ('type1' em 'type2')

Você usou `dynamic_cast` para converter de um tipo para outro. O compilador determinou que a conversão sempre falhará (retornar **nulo**) porque uma classe base está inacessível (`private`, por exemplo) ou ambíguas (aparecem mais de uma vez na hierarquia de classe, por exemplo).

A seguir mostra um exemplo de como esse aviso. Classe **B** é derivado da classe **um**. O programa usa `dynamic_cast` converter da classe **B** (a classe derivada) a classe **um**, que sempre falhará porque classe **B** é `private` e, portanto, inacessível. Alterando o acesso de **um** à **público** resolverá o aviso.

```
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