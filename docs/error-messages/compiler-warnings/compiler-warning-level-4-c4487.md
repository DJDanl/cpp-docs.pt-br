---
title: Compilador aviso (nível 4) C4487 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4487
dev_langs:
- C++
helpviewer_keywords:
- C4487
ms.assetid: 796144cf-cd3c-4edc-b6a4-96192b7eb4f0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ffc1a25d362cad95f2aad43d626e4918955903f5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46135833"
---
# <a name="compiler-warning-level-4-c4487"></a>Compilador aviso (nível 4) C4487

'derived_class_function': corresponde ao método não virtual herdado 'base_class_function', mas não está explicitamente marcado como 'new'

Uma função em uma classe derivada tem a mesma assinatura como uma função de classe base não virtuais. C4487 lembra você de que a função de classe derivada substitui a função de classe base. Marcar explicitamente a função de classe derivada como `new` para resolver este aviso.

Para obter mais informações, consulte [novo (novo slot em vtable)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4487.

```
// C4487.cpp
// compile with: /W4 /clr
using namespace System;
public ref struct B {
   void f() { Console::WriteLine("in B::f"); }
   void g() { Console::WriteLine("in B::g"); }
};

public ref struct D : B {
   void f() { Console::WriteLine("in D::f"); }   // C4487
   void g() new { Console::WriteLine("in D::g"); }   // OK
};

int main() {
   B ^ a = gcnew D;
   // will call base class functions
   a->f();
   a->g();
}
```