---
title: Erro do compilador C2460
ms.date: 11/04/2016
f1_keywords:
- C2460
helpviewer_keywords:
- C2460
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
ms.openlocfilehash: a7d20a7658a75a492e19b9e81acaa3b6fce5cae7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743933"
---
# <a name="compiler-error-c2460"></a>Erro do compilador C2460

' identifier1 ': usa ' identifier2 ', que está sendo definido

Uma classe ou estrutura (`identifier2`) é declarada como um membro de si mesma (`identifier1`). Não são permitidas definições recursivas de classes e estruturas.

O exemplo a seguir gera C2460:

```cpp
// C2460.cpp
class C {
   C aC;    // C2460
};
```

Em vez disso, use uma referência de ponteiro na classe.

```cpp
// C2460.cpp
class C {
   C * aC;    // OK
};
```
