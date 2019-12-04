---
title: Erro do compilador C3909
ms.date: 11/04/2016
f1_keywords:
- C3909
helpviewer_keywords:
- C3909
ms.assetid: 0a443132-e53f-42dc-a58b-f086da3e7bfd
ms.openlocfilehash: 69613a1058bd5178ea4c03931664dd00bad7a101
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74748990"
---
# <a name="compiler-error-c3909"></a>Erro do compilador C3909

aWinRT ou declaração de evento gerenciado deve ocorrer em um tipo de WinRT ou gerenciado

Um evento Windows Runtime ou evento gerenciado foi declarado em um tipo nativo. Para corrigir esse erro, declare eventos em tipos de Windows Runtime ou tipos gerenciados.

Para obter mais informações, consulte [evento](../../extensions/event-cpp-component-extensions.md).

O exemplo a seguir gera C3909 e mostra como corrigi-lo:

```cpp
// C3909.cpp
// compile with: /clr /c
delegate void H();
class X {
   event H^ E;   // C3909 - use ref class X instead
};

ref class Y {
   static event H^ E {
      void add(H^) {}
      void remove( H^ h ) {}
      void raise( ) {}
   }
};
```
