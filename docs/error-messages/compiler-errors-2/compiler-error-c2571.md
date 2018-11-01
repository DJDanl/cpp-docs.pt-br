---
title: Erro do compilador C2571
ms.date: 11/04/2016
f1_keywords:
- C2571
helpviewer_keywords:
- C2571
ms.assetid: c6522616-dee9-4d7d-9bf8-30a7e1deaadf
ms.openlocfilehash: d7d4898e5f0b55c50a4c18cef053cc150394d7e0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50485066"
---
# <a name="compiler-error-c2571"></a>Erro do compilador C2571

'function': função virtual não pode estar em union 'union'

Uma união é declarada com uma função virtual. Você pode declarar uma função virtual somente em uma classe ou estrutura.  Possíveis resoluções:

1. Altere a união para uma classe ou estrutura.

1. Tornar a função não virtual.

O exemplo a seguir gera C2571:

```
// C2571.cpp
// compile with: /c
union A {
   virtual void func1();   // C2571
   void func2();   // OK
};
```