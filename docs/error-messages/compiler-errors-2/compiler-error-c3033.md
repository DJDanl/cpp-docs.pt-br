---
title: Erro do compilador C3033
ms.date: 11/04/2016
f1_keywords:
- C3033
helpviewer_keywords:
- C3033
ms.assetid: 8628b6bb-a650-4ed2-af13-57acd2f7ddbb
ms.openlocfilehash: 57c2cc120a5c155d02e0e601dc2ff8924badbe67
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460886"
---
# <a name="compiler-error-c3033"></a>Erro do compilador C3033

'var': variável em cláusula 'cláusula' não pode ter tipo qualificado como const

Os valores passados para determinados cláusulas não podem ser `const` variáveis.

O exemplo a seguir gera C3033:

```
// C3033.cpp
// compile with: /openmp /link vcomps.lib
int main() {
   const int val = 1;
   int val2 = 1;

   #pragma omp parallel reduction(+ : val)   // C3033
   ;

   #pragma omp parallel reduction(+ : val2)   // OK
   ;
}
```