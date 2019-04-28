---
title: Erro do compilador C3654
ms.date: 11/04/2016
f1_keywords:
- C3654
helpviewer_keywords:
- C3654
ms.assetid: 57d96e3f-6bbb-4eaa-934b-26c23b4ceb2e
ms.openlocfilehash: e66f0071a3d086c84a51c8b69e52b06643344c4d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62227090"
---
# <a name="compiler-error-c3654"></a>Erro do compilador C3654

'texto': erro de sintaxe em substituição explícita

Uma cadeia de caracteres inesperada estava em uma substituição explícita. Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md).

O exemplo a seguir gera C3654:

```
// C3654.cpp
// compile with: /clr /c
public ref struct B {
   virtual void f() = 0;
   virtual void g() = 0;
   virtual void h() = 0;
};

public ref struct Q : B {
   virtual void f() = B::f, 3 {}   // C3654
   // try the following line instead
   // virtual void g() = B::g, B::h {}
};
```