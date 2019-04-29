---
title: Erro do compilador C2553
ms.date: 11/04/2016
f1_keywords:
- C2553
helpviewer_keywords:
- C2553
ms.assetid: 64bc1e9a-627f-4ce9-b7bc-dc911bdb9180
ms.openlocfilehash: 11cb2b83d958f0c59d05034a716a022f00b326ec
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62353178"
---
# <a name="compiler-error-c2553"></a>Erro do compilador C2553

'base_function': função virtual de substituição retornar o tipo é diferente de 'override_function'

Tentativa de uma função em uma classe derivada substituir uma função virtual em uma classe base, mas a função de classe derivada não tinha o mesmo tipo de retorno da função de classe base.  Uma assinatura de função de substituição deve corresponder à assinatura da função que está sendo substituída.

O exemplo a seguir gera C2553:

```
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