---
title: Erro do compilador C3764
ms.date: 11/04/2016
f1_keywords:
- C3764
helpviewer_keywords:
- C3764
ms.assetid: af5d254c-8d4a-4dda-aad9-3c5c1257c868
ms.openlocfilehash: 2570ee9abb148b919242de7786cd6fa91765286f
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58773574"
---
# <a name="compiler-error-c3764"></a>Erro do compilador C3764

'override_function': não é possível substituir o método da classe base 'base_class_function'

O compilador detectou uma substituição mal formado. Por exemplo, a função de classe base não era `virtual`. Para obter mais informações, consulte [substituir](../../extensions/override-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3764.

```
// C3764.cpp
// compile with: /clr /c
public ref struct A {
   void g(int);
   virtual void h(int);
};

public ref struct B : A {
   virtual void g(int) override {}   // C3764
   virtual void h(int) override {}   // OK
};
```

## <a name="example"></a>Exemplo

C3764 também pode ocorrer quando um método de classe base é explicitamente e nomeado substituído. O exemplo a seguir gera C3764.

```
// C3764_b.cpp
// compile with: /clr /c
ref struct A {
   virtual void Test() {}
};

ref struct B : public A {
   virtual void Test() override {}
   virtual void Test2() = A::Test {}   // C3764
};
```