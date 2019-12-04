---
title: Erro do compilador C2675
ms.date: 11/04/2016
f1_keywords:
- C2675
helpviewer_keywords:
- C2675
ms.assetid: 4b92a12b-bff8-4dd5-a109-620065fc146c
ms.openlocfilehash: 0b7b81ce7314fbad02d6873403fc5cf1bdd54709
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760368"
---
# <a name="compiler-error-c2675"></a>Erro do compilador C2675

' operator ' unário: ' type ' não define este operador ou uma conversão para um tipo aceitável para o operador predefinido

C2675 também pode ocorrer ao usar um operador unário, e o tipo não define o operador ou uma conversão para um tipo aceitável para o operador predefinido. Para usar o operador, você deve sobrecarregar para o tipo especificado ou definir uma conversão para um tipo para o qual o operador é definido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2675.

```cpp
// C2675.cpp
struct C {
   C(){}
} c;

struct D {
   D(){}
   void operator-(){}
} d;

int main() {
   -c;   // C2675
   -d;   // OK
}
```
