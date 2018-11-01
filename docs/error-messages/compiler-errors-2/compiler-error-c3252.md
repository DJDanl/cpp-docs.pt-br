---
title: Erro do compilador C3252
ms.date: 11/04/2016
f1_keywords:
- C3252
helpviewer_keywords:
- C3252
ms.assetid: aa9ad096-e9ac-41c7-8ad9-b966751c7c75
ms.openlocfilehash: ee9245fb8eb89b9234e76dc10304b1d05bc1fdcb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50600367"
---
# <a name="compiler-error-c3252"></a>Erro do compilador C3252

'method': não é possível reduzir acessibilidade de um método virtual em um gerenciado ou um tipo de WinRT

Uma classe que implementa um método virtual de uma classe base ou qualquer método de uma interface não é possível reduzir o acesso desse método.

Observe que todos os métodos em uma interface públicos.

O exemplo a seguir gera C3252 e mostra como corrigi-lo:

```
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