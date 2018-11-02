---
title: Erro do compilador C2090
ms.date: 11/04/2016
f1_keywords:
- C2090
helpviewer_keywords:
- C2090
ms.assetid: e8176e55-382b-453d-aa27-6597f0274afd
ms.openlocfilehash: d805a4d6e0da0e94288ac36c6680a952b7633b86
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50469388"
---
# <a name="compiler-error-c2090"></a>Erro do compilador C2090

função retorna matriz

Uma função não pode retornar uma matriz. Em vez disso, retorne um ponteiro para uma matriz.

O exemplo a seguir gera C2090:

```
// C2090.cpp
int func1(void)[] {}   // C2090
```

Solução possível:

```
// C2090b.cpp
// compile with: /c
int* func2(int * i) {
   return i;
}
```