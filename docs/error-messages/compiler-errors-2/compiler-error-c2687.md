---
title: Erro do compilador C2687
ms.date: 11/04/2016
f1_keywords:
- C2687
helpviewer_keywords:
- C2687
ms.assetid: 1d24b24a-cd0f-41cc-975c-b08dcfb7f402
ms.openlocfilehash: f3e728033a3230d628242aab341377be2f6670ca
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760251"
---
# <a name="compiler-error-c2687"></a>Erro do compilador C2687

' type ': a declaração de exceção não pode ser ' void ' ou denotar um tipo incompleto ou um ponteiro ou uma referência a um tipo incompleto

Para que um tipo seja parte de uma declaração de exceção, ele deve ser definido e não nulo.

O exemplo a seguir gera C2687:

```cpp
// C2687.cpp
class C;

int main() {
   try {}
   catch (C) {}   // C2687 error
}
```

Resolução possível:

```cpp
// C2687b.cpp
// compile with: /EHsc
class C {};

int main() {
   try {}
   catch (C) {}
}
```
