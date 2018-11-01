---
title: Erro do compilador C3224
ms.date: 11/04/2016
f1_keywords:
- C3224
helpviewer_keywords:
- C3224
ms.assetid: 129be22f-8f3e-4fc6-9ccd-d27d8ef91251
ms.openlocfilehash: dc64ca1aeef66eeb554be1316bf9433145b50cc3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50473158"
---
# <a name="compiler-error-c3224"></a>Erro do compilador C3224

'type': nenhuma classe de generic sobrecarregada leva 'número' argumentos de tipo genérico

O compilador não conseguiu encontrar uma sobrecarga apropriada.

O exemplo a seguir gera C3224:

```
// C3224.cs
// compile with: /target:library
public class C<T> {}
public class C<T,U> {}
```

E, em seguida,

```
// C3224b.cpp
// compile with: /clr
#using "C3224.dll"
int main() {
   C<int,int,int>^ c = gcnew C<int,int,int>();   // C3224
   C<int,int>^ c2 = gcnew C<int,int>();   // OK
}
```