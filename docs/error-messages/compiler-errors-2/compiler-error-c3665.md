---
title: Erro do compilador C3665
ms.date: 11/04/2016
f1_keywords:
- C3665
helpviewer_keywords:
- C3665
ms.assetid: 893bb47e-8de1-43aa-af7d-fa47ad149ee9
ms.openlocfilehash: 4b0c019b2425b314f5b3503db41042d917283aa8
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758171"
---
# <a name="compiler-error-c3665"></a>Erro do compilador C3665

' destruidor ': especificador de substituição ' keyword ' não permitido em um destruidor/finalizador

Foi usada uma palavra-chave que não é permitida em um destruidor ou finalizador.

Por exemplo, um novo slot não pode ser solicitado em um destruidor ou finalizador.  Para obter mais informações, consulte substituições e destruidores [explícitos](../../extensions/explicit-overrides-cpp-component-extensions.md) [e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

O exemplo a seguir gera C3665:

```cpp
// C3665.cpp
// compile with: /clr
public ref struct R {
   virtual ~R() { }
   virtual void a() { }
};

public ref struct S : R {
   virtual ~S() new {}   // C3665
   virtual void a() new {}   // OK
};
```
