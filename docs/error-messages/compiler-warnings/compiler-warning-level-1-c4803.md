---
title: Compilador aviso (nível 1) C4803
ms.date: 11/04/2016
f1_keywords:
- C4803
helpviewer_keywords:
- C4803
ms.assetid: 2552f3a6-c418-49f4-98a2-a929857be658
ms.openlocfilehash: bb8f5fe9d55a44193325a2fcfe9ef7675a2b3b89
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406490"
---
# <a name="compiler-warning-level-1-c4803"></a>Compilador aviso (nível 1) C4803

'method': o método raise possui uma classe de armazenamento diferente do evento, 'event'

Métodos de evento devem ter a mesma classe de armazenamento que a declaração de evento. O compilador ajusta os métodos do evento para que as classes de armazenamento são os mesmos.

Esse aviso pode ocorrer se você tiver uma classe que implementa um evento de uma interface. O compilador não gera implicitamente um método para disparar um evento em uma interface. Quando você implementa essa interface em uma classe, implicitamente o compilador gera um método raise e esse método não será virtual, portanto, o aviso. Para obter mais informações sobre eventos, consulte [evento](../../extensions/event-cpp-component-extensions.md).

Ver [aviso](../../preprocessor/warning.md) pragma para obter informações sobre como desativar um aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4803.

```
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
