---
title: Erro do compilador C3764 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3764
dev_langs:
- C++
helpviewer_keywords:
- C3764
ms.assetid: af5d254c-8d4a-4dda-aad9-3c5c1257c868
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b57b9005eacc6e4a59adecc38b40027fffb5bcf1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46096997"
---
# <a name="compiler-error-c3764"></a>Erro do compilador C3764

'override_function': não é possível substituir o método da classe base 'base_class_function'

O compilador detectou uma substituição mal formado. Por exemplo, a função de classe base não era `virtual`. Para obter mais informações, consulte [substituir](../../windows/override-cpp-component-extensions.md).

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