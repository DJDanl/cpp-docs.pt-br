---
title: Aviso do compilador C4485
ms.date: 11/04/2016
f1_keywords:
- C4485
helpviewer_keywords:
- C4485
ms.assetid: a6f2b437-ca93-4dcd-b9cb-df415e10df86
ms.openlocfilehash: 7138f1a3cecaaf75fbab01fd1aee18529b7a3a84
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652435"
---
# <a name="compiler-warning-c4485"></a>Aviso do compilador C4485

'override_function': corresponde ao método de classe ref base 'base_class_function', mas não está marcado como 'new' ou 'override'; 'new' (e 'virtual') são assumidos

Substitui um acessador, com ou sem o `virtual` palavra-chave, uma função de acessador de classe base, mas o `override` ou `new` especificador não era parte da assinatura de função de substituição. Adicione a `new` ou `override` especificador para resolver este aviso.

Ver [substituir](../../windows/override-cpp-component-extensions.md) e [novo (novo slot em vtable)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md) para obter mais informações.

C4485 sempre é emitido como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para suprimir C4485.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4485

```
// C4485.cpp
// compile with: /clr
delegate void Del();

ref struct A {
   virtual event Del ^E;
};

ref struct B : A {
   virtual event Del ^E;   // C4485
};

ref struct C : B {
   virtual event Del ^E {
      void raise() override {}
      void add(Del ^) override {}
      void remove(Del^) override {}
   }
};
```