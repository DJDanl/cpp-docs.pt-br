---
title: Erro do compilador C2663
ms.date: 11/04/2016
f1_keywords:
- C2663
helpviewer_keywords:
- C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
ms.openlocfilehash: f9746ecb41e873fb1d929a939c78f1817dc0e2f9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220269"
---
# <a name="compiler-error-c2663"></a>Erro do compilador C2663

' function ': sobrecargas de número não têm conversões legais para ponteiro ' this '

O compilador não pôde converter **`this`** para nenhuma das versões sobrecarregadas da função membro.

Esse erro pode ser causado pela invocação de uma **`const`** função não membro em um **`const`** objeto.  Possíveis resoluções:

1. Remova o **`const`** da declaração de objeto.

1. Adicione **`const`** a uma das sobrecargas de função de membro.

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
