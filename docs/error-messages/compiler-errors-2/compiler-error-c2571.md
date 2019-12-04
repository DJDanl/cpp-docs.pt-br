---
title: Erro do compilador C2571
ms.date: 11/04/2016
f1_keywords:
- C2571
helpviewer_keywords:
- C2571
ms.assetid: c6522616-dee9-4d7d-9bf8-30a7e1deaadf
ms.openlocfilehash: 7bd87f0732e1a632b8c86cc57fab1a0f104b2c77
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755493"
---
# <a name="compiler-error-c2571"></a>Erro do compilador C2571

' function ': a função virtual não pode estar na União ' Union '

Uma União é declarada com uma função virtual. Você pode declarar uma função virtual somente em uma classe ou estrutura.  Possíveis resoluções:

1. Altere a União para uma classe ou estrutura.

1. Torne a função não virtual.

O exemplo a seguir gera C2571:

```cpp
// C2571.cpp
// compile with: /c
union A {
   virtual void func1();   // C2571
   void func2();   // OK
};
```
