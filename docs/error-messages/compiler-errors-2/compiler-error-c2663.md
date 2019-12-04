---
title: Erro do compilador C2663
ms.date: 11/04/2016
f1_keywords:
- C2663
helpviewer_keywords:
- C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
ms.openlocfilehash: f07b63202d8f171dfb69f4bb294b392152b9290b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756026"
---
# <a name="compiler-error-c2663"></a>Erro do compilador C2663

' function ': sobrecargas de número não têm conversões legais para ponteiro ' this '

O compilador não pôde converter `this` em nenhuma das versões sobrecarregadas da função membro.

Esse erro pode ser causado pela invocação de uma função de membro não`const` em um objeto `const`.  Possíveis resoluções:

1. Remova a `const` da declaração de objeto.

1. Adicione `const` a uma das sobrecargas de função de membro.

O exemplo a seguir gera C2663:

```cpp
// C2663.cpp
struct C {
   void f() volatile {}
   void f() {}
};

struct D {
   void f() volatile;
   void f() const {}
};

const C *pcc;
const D *pcd;

int main() {
   pcc->f();    // C2663
   pcd->f();    // OK
}
```
