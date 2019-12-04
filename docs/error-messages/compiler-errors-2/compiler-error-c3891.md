---
title: Erro do compilador C3891
ms.date: 11/04/2016
f1_keywords:
- C3891
helpviewer_keywords:
- C3891
ms.assetid: 6e1a9458-97f5-4580-bc0f-aa97a1bfd20d
ms.openlocfilehash: 4b5ef8b837033a149455c040f748f479aa3f424d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74736393"
---
# <a name="compiler-error-c3891"></a>Erro do compilador C3891

' var ': um membro de dados literal não pode ser usado como um l-Value

Uma variável [literal](../../extensions/literal-cpp-component-extensions.md) é const e seu valor não pode ser alterado após ser inicializado na declaração.

O exemplo a seguir gera C3891:

```cpp
// C3891.cpp
// compile with: /clr
ref struct Y1 {
   literal int staticConst = 9;
};

int main() {
   Y1::staticConst = 0;   // C3891
}
```
