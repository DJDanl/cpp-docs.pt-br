---
title: Erro do compilador C3900
ms.date: 11/04/2016
f1_keywords:
- C3900
helpviewer_keywords:
- C3900
ms.assetid: a94cc561-8fa8-4344-9e01-e81ff462fae5
ms.openlocfilehash: 35df94ccfcd7942f9057cb37ceee349c09b80607
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59776243"
---
# <a name="compiler-error-c3900"></a>Erro do compilador C3900

'member': não é permitida no escopo atual

Blocos de propriedade podem conter declarações de função e definições de função embutida somente. Não há membros diferentes funções são permitidos em blocos de propriedade. Não há funções de typedefs, operadores ou amigo são permitidas. Para obter mais informações, consulte [propriedade](../../extensions/property-cpp-component-extensions.md).

Definições de eventos só podem conter funções e métodos de acesso.

O exemplo a seguir gera C3900:

```
// C3900.cpp
// compile with: /clr
ref class X {
   property int P {
      void set(int);   // OK
      int i;   // C3900 variable declaration
   };
};
```

O exemplo a seguir gera C3900:

```
// C3900b.cpp
// compile with: /clr
using namespace System;
delegate void H();
ref class X {
   event H^ E {
      int m;   // C3900

      // OK
      void Test() {}

      void add( H^ h ) {}
      void remove( H^ h ) {}
      void raise( ) {}
   }
};
```