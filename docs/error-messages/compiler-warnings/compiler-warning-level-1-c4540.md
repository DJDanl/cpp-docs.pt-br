---
title: Compilador aviso (nível 1) C4540 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4540
dev_langs:
- C++
helpviewer_keywords:
- C4540
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e3f553bd1f910c7b17e079dc1f03664c78383e3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042761"
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