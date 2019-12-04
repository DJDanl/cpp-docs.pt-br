---
title: Erro do compilador C2679
ms.date: 11/04/2016
f1_keywords:
- C2679
helpviewer_keywords:
- C2679
ms.assetid: 1a5f9d00-9190-4aa6-bc72-949f68ec136f
ms.openlocfilehash: 2b9238493e7925f2786df2acb7ecad80eb6ca2eb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760316"
---
# <a name="compiler-error-c2679"></a>Erro do compilador C2679

' operator ' binário: nenhum operador encontrado que usa um operando à direita do tipo ' type ' (ou não há uma conversão aceitável)

Para usar o operador, você deve sobrecarregar para o tipo especificado ou definir uma conversão para um tipo para o qual o operador é definido.

O exemplo a seguir gera C2679:

```cpp
// C2679.cpp
class C {
public:
   C();   // no constructor with an int argument
} c;

class D {
public:
   D(int) {}
   D(){}
} d;

int main() {
   c = 10;   // C2679
   d = 10;   // OK
}
```
