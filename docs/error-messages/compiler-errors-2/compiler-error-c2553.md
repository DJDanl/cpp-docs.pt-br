---
title: Erro do compilador C2553
ms.date: 11/04/2016
f1_keywords:
- C2553
helpviewer_keywords:
- C2553
ms.assetid: 64bc1e9a-627f-4ce9-b7bc-dc911bdb9180
ms.openlocfilehash: aa3e97d576e994878ab5b080363c4c09b79f42ed
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756780"
---
# <a name="compiler-error-c2553"></a>Erro do compilador C2553

' base_function ': tipo de retorno da função virtual de substituição difere de ' override_function '

Uma função em uma classe derivada tentou substituir uma função virtual em uma classe base, mas a função de classe derivada não tinha o mesmo tipo de retorno que a função de classe base.  Uma assinatura de função de substituição deve corresponder à assinatura da função que está sendo substituída.

O exemplo a seguir gera C2553:

```cpp
// C2553.cpp
// compile with: /clr /c
ref struct C {
   virtual void f();
};

ref struct D : C {
   virtual int f() override ;   // C2553

   // try the following line instead
   // virtual void f() override;
};
```
