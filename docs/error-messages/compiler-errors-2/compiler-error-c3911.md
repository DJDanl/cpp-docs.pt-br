---
title: Erro do compilador C3911
ms.date: 11/04/2016
f1_keywords:
- C3911
helpviewer_keywords:
- C3911
ms.assetid: b786da59-0e99-479d-bc0d-551126e940f2
ms.openlocfilehash: 6c00a3bb388130d9a570e9fd731a9ed1200ed179
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622177"
---
# <a name="compiler-error-c3911"></a>Erro do compilador C3911

'event_accessor_method': função deve ter o tipo 'assinatura'

Método de acessador de um evento não foi declarado corretamente.

Para obter mais informações, consulte [evento](../../windows/event-cpp-component-extensions.md).

O exemplo a seguir gera C3911:

```
// C3911.cpp
// compile with: /clr
using namespace System;
delegate void H(String^, int);

ref class X {
   event H^ E1 {
      void add() {}   // C3911
      // try the following line instead
      // void add(H ^ h) {}

      void remove(){}
      // try the following line instead
      // void remove(H ^ h) {}

      void raise(){}
      // try the following line instead
      // void raise(String ^ s, int i) {}
   };
};
```