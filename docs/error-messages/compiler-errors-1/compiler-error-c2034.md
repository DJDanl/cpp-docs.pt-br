---
title: Erro do compilador C2034
ms.date: 11/04/2016
f1_keywords:
- C2034
helpviewer_keywords:
- C2034
ms.assetid: 953d70fa-bde9-4ce6-a55d-741e7bc63ff4
ms.openlocfilehash: 4b4fe769f78e5f826ba08d4819019210f21f860f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50479671"
---
# <a name="compiler-error-c2034"></a>Erro do compilador C2034

'identifier': tipo de campo de bits muito pequeno para número de bits

O número de bits na declaração do campo de bits excede o tamanho do tipo base.

O exemplo a seguir gera C2034:

```
// C2034.cpp
struct A {
   char test : 9;   // C2034, char has 8 bits
};
```

Solução possível:

```
// C2034b.cpp
// compile with: /c
struct A {
   char test : 8;
};
```