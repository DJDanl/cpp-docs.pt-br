---
title: Erro do compilador C2663
ms.date: 11/04/2016
f1_keywords:
- C2663
helpviewer_keywords:
- C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
ms.openlocfilehash: d74326e49edd980896276e2c6e67526d8d769cb7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360288"
---
# <a name="compiler-error-c2663"></a>Erro do compilador C2663

'function': sobrecargas número não ter nenhuma conversões legais para ponteiro 'this'

O compilador não foi possível converter `this` para qualquer uma das versões sobrecarregadas da função de membro.

Esse erro pode ser causado pela invocação de um não -`const` função de membro em uma `const` objeto.  Possíveis resoluções:

1. Remover o `const` da declaração de objeto.

1. Adicionar `const` para uma das sobrecargas de função de membro.

O exemplo a seguir gera C2663:

```
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