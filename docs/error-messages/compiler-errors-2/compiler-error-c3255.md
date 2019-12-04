---
title: Erro do compilador C3255
ms.date: 11/04/2016
f1_keywords:
- C3255
helpviewer_keywords:
- C3255
ms.assetid: 877ffca2-fd92-44b6-9060-6091b928b1c1
ms.openlocfilehash: 43538ce87e1d832fcfc4fca882a9f129b917aad5
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754206"
---
# <a name="compiler-error-c3255"></a>Erro do compilador C3255

' tipo de valor ': não é possível alocar dinamicamente este objeto de tipo de valor no heap nativo

Instâncias de um tipo de valor (consulte [classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md)) que contêm membros gerenciados podem ser criadas na pilha, mas não no heap.

O exemplo a seguir gera C3255:

```cpp
// C3255.cpp
// compile with: /clr
using namespace System;
value struct V {
   Object^ o;
};

value struct V2 {
   int i;
};

int main() {
   V* pv = new V;   // C3255
   V2* pv2 = new V2;
   V v2;
}
```
