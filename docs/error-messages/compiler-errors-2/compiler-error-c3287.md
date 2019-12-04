---
title: Erro do compilador C3287
ms.date: 11/04/2016
f1_keywords:
- C3287
helpviewer_keywords:
- C3287
ms.assetid: c1fa73d2-2c82-4136-a7da-0e75e3b420ad
ms.openlocfilehash: f0f3441b749e3ae074e18e1132dcc4003eba3ba3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74749601"
---
# <a name="compiler-error-c3287"></a>Erro do compilador C3287

o tipo ' type ' (tipo de retorno de GetEnumerator) deve ter uma função de membro MoveNext pública adequada e uma propriedade Current pública

As classes de coleção definidas pelo usuário devem conter definições para `MoveNext` e `Current`.

Consulte [como: iterar em uma coleção definida pelo usuário com for each](../../dotnet/how-to-iterate-over-a-user-defined-collection-with-for-each.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3287.

```cpp
// C3287.cpp
// compile with: /clr
using namespace System;

ref struct R {
   bool MoveNext() {
      return true;
   }
   property Object^ Current {
      Object^ get() {
         Object ^ o = gcnew Object;
         return o;
      }
   }
};

ref struct R2 {
   R ^GetEnumerator() {
      R^ r = gcnew R;
      return r;
   }
};

ref struct T {};

ref struct T2 {
   T ^GetEnumerator() {
      T^ t = gcnew T;
      return t;
   }
};

int main() {
   for each (int i in gcnew T2) {}   // C3287
   for each (int i in gcnew R2) {}   // OK
}
```
