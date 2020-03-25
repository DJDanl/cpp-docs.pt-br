---
title: Aviso do compilador C4485
ms.date: 11/04/2016
f1_keywords:
- C4485
helpviewer_keywords:
- C4485
ms.assetid: a6f2b437-ca93-4dcd-b9cb-df415e10df86
ms.openlocfilehash: c92f805eb2960336ed34f5da93b6c13f46bf15ac
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165139"
---
# <a name="compiler-warning-c4485"></a>Aviso do compilador C4485

' override_function ': corresponde ao método de classe ref base ' base_class_function ', mas não está marcado como ' New ' ou ' override '; ' New ' (e ' virtual ') é assumido

Um acessador substitui, com ou sem a palavra-chave `virtual`, uma função de acessador de classe base, mas o especificador `override` ou `new` não era parte da assinatura da função de substituição. Adicione o `new` ou o especificador de `override` para resolver este aviso.

Consulte [substituir](../../extensions/override-cpp-component-extensions.md) e [novo (novo slot em vtable)](../../extensions/new-new-slot-in-vtable-cpp-component-extensions.md) para obter mais informações.

C4485 é sempre emitido como um erro. Use o pragma de [aviso](../../preprocessor/warning.md) para suprimir C4485.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4485

```cpp
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
