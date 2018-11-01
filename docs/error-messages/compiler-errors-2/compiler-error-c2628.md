---
title: Erro do compilador C2628
ms.date: 11/04/2016
f1_keywords:
- C2628
helpviewer_keywords:
- C2628
ms.assetid: 19a25e77-d5be-4107-88d5-0745b6281f98
ms.openlocfilehash: 90df41ba8ae85e57e40848f8b50f4c1df7c7b541
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50664939"
---
# <a name="compiler-error-c2628"></a>Erro do compilador C2628

'type1' seguido de 'type2' é inválido (você esqueceu um ';'?)

Um ponto e vírgula pode estar ausente.

O exemplo a seguir gera C2628:

```
// C2628.cpp
class CMyClass {}
int main(){}   // C2628 error
```

Solução possível:

```
// C2628b.cpp
class CMyClass {};
int main(){}
```