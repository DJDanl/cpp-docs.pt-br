---
title: Erro do compilador C2473
ms.date: 11/04/2016
f1_keywords:
- C2473
helpviewer_keywords:
- C2473
ms.assetid: 6bb7dbf5-b198-490f-860e-fd64d0c2a284
ms.openlocfilehash: 2f7ce0e18070c2b5ee6ebb2284d5564b3d750d77
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743712"
---
# <a name="compiler-error-c2473"></a>Erro do compilador C2473

' identifier ': é semelhante a uma definição de função, mas não há nenhuma lista de parâmetros.

O compilador detectou a aparência de uma função, sem a lista de parâmetros.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2473.

```cpp
// C2473.cpp
// compile with: /clr /c
class A {
   int i {}   // C2473
};

class B {
   int i() {}   // OK
};
```
