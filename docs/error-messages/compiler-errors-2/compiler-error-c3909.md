---
title: Erro do compilador C3909
ms.date: 11/04/2016
f1_keywords:
- C3909
helpviewer_keywords:
- C3909
ms.assetid: 0a443132-e53f-42dc-a58b-f086da3e7bfd
ms.openlocfilehash: 95de97a27fc42e98247675b1b48325593ff3c21e
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58778202"
---
# <a name="compiler-error-c3909"></a>Erro do compilador C3909

aWinRT ou declaração de evento gerenciado deve ocorrer em um WinRT ou tipo gerenciado

Um evento de tempo de execução do Windows ou gerenciado foi declarado em um tipo nativo. Para corrigir esse erro, declare eventos em tipos de tempo de execução do Windows ou tipos gerenciados.

Para obter mais informações, consulte [evento](../../extensions/event-cpp-component-extensions.md).

O exemplo a seguir gera C3909 e mostra como corrigi-lo:

```
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