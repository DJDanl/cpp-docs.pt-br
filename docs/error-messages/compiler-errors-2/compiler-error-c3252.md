---
title: Erro do compilador C3252
ms.date: 11/04/2016
f1_keywords:
- C3252
helpviewer_keywords:
- C3252
ms.assetid: aa9ad096-e9ac-41c7-8ad9-b966751c7c75
ms.openlocfilehash: fbfe3ffaca66cad4922b5771ee8c9003acba7571
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754323"
---
# <a name="compiler-error-c3252"></a>Erro do compilador C3252

' method ': não é possível reduzir a acessibilidade de um método virtual em um tipo gerenciado ou WinRT

Uma classe que implementa um método virtual de uma classe base ou de qualquer método de uma interface não pode reduzir o acesso desse método.

Observe que todos os métodos em uma interface são públicos.

O exemplo a seguir gera C3252 e mostra como corrigi-lo:

```cpp
// C3252.cpp
// compile with: /clr /c
ref class A {
public:
   virtual void f1() {}
};

ref class B : public A {
// To fix, uncomment the following line:
// public:
   virtual void f1() override sealed {}   // C3252, make this method public
};
```
