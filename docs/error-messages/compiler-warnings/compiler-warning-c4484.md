---
title: Aviso do compilador C4484
ms.date: 11/04/2016
f1_keywords:
- C4484
helpviewer_keywords:
- C4484
ms.assetid: 3d30e5b3-2297-45b7-a37a-1360056fdd0e
ms.openlocfilehash: c168c91f8259b744ed10dd72701d34fd60b98681
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165152"
---
# <a name="compiler-warning-c4484"></a>Aviso do compilador C4484

' override_function ': corresponde ao método de classe ref base ' base_class_function ', mas não está marcado como ' virtual ', ' New ' ou ' override '; ' New ' (e not ' virtual ') é assumido

Ao compilar com **/CLR**, o compilador não substituirá implicitamente uma função de classe base, o que significa que a função receberá um novo slot na vtable. Para resolver, especifique explicitamente se uma função é uma substituição.

Para obter mais informações, consulte:

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [override](../../extensions/override-cpp-component-extensions.md)

- [novo (novo slot em vtable)](../../extensions/new-new-slot-in-vtable-cpp-component-extensions.md)

C4484 é sempre emitido como um erro. Use o pragma de [aviso](../../preprocessor/warning.md) para suprimir C4484.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4484.

```cpp
// C4484.cpp
// compile with: /clr
ref struct A {
   virtual void Test() {}
};

ref struct B : A {
   void Test() {}   // C4484
};

// OK
ref struct C {
   virtual void Test() {}
   virtual void Test2() {}
};

ref struct D : C {
   virtual void Test() new {}
   virtual void Test2() override {}
};
```
