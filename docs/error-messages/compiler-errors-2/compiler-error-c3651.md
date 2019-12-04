---
title: Erro do compilador C3651
ms.date: 11/04/2016
f1_keywords:
- C3651
helpviewer_keywords:
- C3651
ms.assetid: a03e692e-c219-4654-9827-8415cfa5a22d
ms.openlocfilehash: 9468b1e9193bfa52ed133f6fdfa398e02e40c4ef
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756312"
---
# <a name="compiler-error-c3651"></a>Erro do compilador C3651

' member ': não pode ser usado como uma substituição explícita, deve ser um membro de uma classe base

Uma substituição explícita foi especificada, mas a função que está sendo substituída estava em um tipo que não é um tipo base.

Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md).

O exemplo a seguir gera C3651:

```cpp
// C3651.cpp
// compile with: /clr /c
ref class C {
public:
   virtual void func2();
};

ref class Other {
public:
   virtual void func();
};

ref class D : public C {
public:
   virtual void func() new sealed = Other::func;   // C3651
   virtual void func2() new sealed = C::func2;   // OK
};
```
