---
title: Erro do compilador C3764
ms.date: 11/04/2016
f1_keywords:
- C3764
helpviewer_keywords:
- C3764
ms.assetid: af5d254c-8d4a-4dda-aad9-3c5c1257c868
ms.openlocfilehash: 3ede846c9068978ad5d283e97b1c96d3527bf67c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757222"
---
# <a name="compiler-error-c3764"></a>Erro do compilador C3764

' override_function ': não é possível substituir o método de classe base ' base_class_function '

O compilador detectou uma substituição mal formada. Por exemplo, a função de classe base não foi `virtual`. Para obter mais informações, consulte [substituir](../../extensions/override-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3764.

```cpp
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

C3764 também pode ocorrer quando um método de classe base é explicitamente e nomeado como substituído. O exemplo a seguir gera C3764.

```cpp
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
