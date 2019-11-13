---
title: Aviso do compilador (nível 1) C4803
ms.date: 11/04/2016
f1_keywords:
- C4803
helpviewer_keywords:
- C4803
ms.assetid: 2552f3a6-c418-49f4-98a2-a929857be658
ms.openlocfilehash: ebf7b3baec3519a142c7a1835aa15a980974bb48
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052344"
---
# <a name="compiler-warning-level-1-c4803"></a>Aviso do compilador (nível 1) C4803

' method ': o método Raise tem uma classe de armazenamento diferente do do evento, ' Event '

Os métodos de evento devem ter a mesma classe de armazenamento que a declaração de evento. O compilador ajusta os métodos do evento para que as classes de armazenamento sejam as mesmas.

Esse aviso pode ocorrer se você tiver uma classe que implementa um evento de uma interface. O compilador não gera implicitamente um método raise para um evento em uma interface. Quando você implementa essa interface em uma classe, o compilador gera implicitamente um método Raise e esse método não será virtual, portanto, o aviso. Para obter mais informações sobre eventos, consulte [evento](../../extensions/event-cpp-component-extensions.md).

Consulte pragma de [aviso](../../preprocessor/warning.md) para obter informações sobre como desativar um aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4803.

```cpp
// C4803.cpp
// compile with: /clr /W1
using namespace System;

public delegate void Del();

ref struct E {
   Del ^ _pd1;
   event Del ^ E1 {
      void add (Del ^ pd1) {
         _pd1 = dynamic_cast<Del ^>(Delegate::Combine(_pd1, pd1));
      }

      void remove(Del^ pd1) {
         _pd1 = dynamic_cast<Del^> (Delegate::Remove(_pd1, pd1));
      }

      virtual void raise() {   // C4803 warning (remove virtual)
         if (_pd1)
            _pd1();
      }
   }

   void func() {
      Console::WriteLine("In E::func()");
   }
};

int main() {
   E ^ ep = gcnew E;
   ep->E1 += gcnew Del(ep, &E::func);
   ep->E1();
   ep->E1 -= gcnew Del(ep, &E::func);
   ep->E1();
}
```
