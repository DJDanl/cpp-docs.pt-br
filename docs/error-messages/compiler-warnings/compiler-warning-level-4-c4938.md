---
title: Compilador aviso (nível 4) C4938 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4938
dev_langs:
- C++
helpviewer_keywords:
- C4938
ms.assetid: 6acac81a-9d23-465e-b700-ed4b6e8edcd0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e140f3885aec66d01d5f7e28245c10e952bedde3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46107436"
---
# <a name="compiler-warning-level-4-c4938"></a>Compilador aviso (nível 4) C4938

'var': variável de redução de ponto flutuante pode causar resultados inconsistentes sob /fp: strict ou #pragma fenv_access

Você não deve usar [/fp: strict](../../build/reference/fp-specify-floating-point-behavior.md) ou [fenv_access](../../preprocessor/fenv-access.md) com OpenMP reduções de ponto flutuantes, porque a soma é computada em uma ordem diferente. Assim, os resultados podem diferir dos resultados sem /openmp.

O exemplo a seguir gera C4938:

```
// C4938.cpp
// compile with: /openmp /W4 /fp:strict /c
// #pragma fenv_access(on)
extern double *a;

double test(int first, int last) {
   double sum = 0.0;
   #pragma omp parallel for reduction(+: sum)   // C4938
   for (int i = first ; i <= last ; ++i)
      sum += a[i];
   return sum;
}
```

Sem paralelização explícita, a soma é calculada da seguinte maneira:

```
sum = a[first] + a[first + 1] + ... + a[last];
```

Com paralelização explícita (e dois threads), a soma é calculada da seguinte maneira:

```
sum1 = a[first] + ... a[first + last / 2];
sum2 = a[(first + last / 2) + 1] + ... a[last];
sum = sum1 + sum2;
```