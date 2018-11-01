---
title: Erro do compilador C3670
ms.date: 11/04/2016
f1_keywords:
- C3670
helpviewer_keywords:
- C3670
ms.assetid: d0fa9c6e-8f90-48c7-9066-31b4fa5942eb
ms.openlocfilehash: d3acfd9d4d09c53fac0b2c5a2462c56dfd54e6d8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598543"
---
# <a name="compiler-error-c3670"></a>Erro do compilador C3670

'override': não é possível substituir o método de classe base inacessível 'method'

Uma substituição só podem ocorrer em uma função cujo nível de acesso torna disponível em um tipo derivado. Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).

O exemplo a seguir gera C3670:

```
// C3670.cpp
// compile with: /clr /c
public ref class C {
// Uncomment the following line to resolve.
// public:
   virtual void g() { }
};

public ref class D : public C {
public:
   virtual void f() new sealed = C::g {};   // C3670
};
```