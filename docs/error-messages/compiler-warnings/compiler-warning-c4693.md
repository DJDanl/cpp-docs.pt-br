---
title: Aviso do compilador C4693
ms.date: 10/25/2017
f1_keywords:
- C4693
helpviewer_keywords:
- C4693
ms.assetid: 72d8db01-5e6f-4794-8731-76107e8f064a
ms.openlocfilehash: cac5918eb4a1689fd215e07272958eeca48247ad
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58781894"
---
# <a name="compiler-warning-c4693"></a>Aviso do compilador C4693

> 'class': uma classe sealed abstract não pode ter quaisquer membros de instância 'Test'

Se um tipo é marcado [lacrado](../../extensions/sealed-cpp-component-extensions.md) e [abstrata](../../extensions/abstract-cpp-component-extensions.md), ele só pode ter membros estáticos.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4693.

```cpp
// C4693.cpp
// compile with: /clr /c
public ref class Public_Ref_Class sealed abstract {
public:
   void Test() {}   // C4693
   static void Test2() {}   // OK
};
```