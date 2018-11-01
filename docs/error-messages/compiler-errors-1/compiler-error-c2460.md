---
title: Erro do compilador C2460
ms.date: 11/04/2016
f1_keywords:
- C2460
helpviewer_keywords:
- C2460
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
ms.openlocfilehash: 414b6e53cf1610a55db984a1127bfc884102494f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50589582"
---
# <a name="compiler-error-c2460"></a>Erro do compilador C2460

'identifier1': usa 'identifier2', que está sendo definido

Uma classe ou estrutura (`identifier2`) é declarada como um membro de si mesmo (`identifier1`). Não são permitidas definições de recursiva de classes e estruturas.

O exemplo a seguir gera C2460:

```
// C2460.cpp
class C {
   C aC;    // C2460
};
```

Em vez disso, use uma referência de ponteiro na classe.

```
// C2460.cpp
class C {
   C * aC;    // OK
};
```