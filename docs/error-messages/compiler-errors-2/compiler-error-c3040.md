---
title: Erro do compilador C3040
ms.date: 11/04/2016
f1_keywords:
- C3040
helpviewer_keywords:
- C3040
ms.assetid: 29e857ac-74f0-4ec6-becf-9026e38c160e
ms.openlocfilehash: b0bc4956cfc08ae50026827d78136a70b82d568e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62349991"
---
# <a name="compiler-error-c3040"></a>Erro do compilador C3040

'var': tipo de variável em cláusula 'reduction' é incompatível com o operador de reduction 'operator'

Uma variável em uma [redução](../../parallel/openmp/reference/reduction.md) cláusula não pode ser usada com o operador de redução.

O exemplo a seguir gera C3040:

```
// C3040.cpp
// compile with: /openmp /c
#include "omp.h"
double d;

int main() {
   #pragma omp parallel reduction(&:d)   // C3040
      ;

   #pragma omp parallel reduction(-:d)  // OK
      ;
}
```