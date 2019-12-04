---
title: Erro do compilador C3919
ms.date: 11/04/2016
f1_keywords:
- C3919
helpviewer_keywords:
- C3919
ms.assetid: 5f8eddda-d751-478b-930d-e18f7191ddfb
ms.openlocfilehash: 78a42b264129ee365e664b1242c8aa58dd1244bd
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758470"
---
# <a name="compiler-error-c3919"></a>Erro do compilador C3919

' event_method ': função deve possuir tipo ' type '

Um método de acessador de eventos não foi declarado corretamente.

Para obter mais informações sobre eventos, consulte [evento](../../extensions/event-cpp-component-extensions.md).

O exemplo a seguir gera C3919:

```cpp
// C3919.cpp
// compile with: /clr /c
using namespace System;
delegate void D(String^);
ref class R {
   event D^ e {
      int add(int);   // C3919
      int remove(int);   // C3919

      void add(D^);   // OK
      void remove(D^);   // OK
   }
};
```
