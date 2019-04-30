---
title: Erro do compilador C3013
ms.date: 11/04/2016
f1_keywords:
- C3013
helpviewer_keywords:
- C3013
ms.assetid: f896777d-27e6-4b6d-baab-1567317f3374
ms.openlocfilehash: 378d15263b00fdc408565fef1c04d7d1b30b30d5
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345566"
---
# <a name="compiler-error-c3013"></a>Erro do compilador C3013

'cláusula': cláusula deve aparecer apenas uma vez na diretiva de 'diretiva' OpenMP

Uma cláusula apareceu duas vezes na mesma diretiva. Exclua uma ocorrência da cláusula.

O exemplo a seguir gera C3013:

```
// C3013.cpp
// compile with: /openmp
int main() {
   int a, b, c, x, y, z;

   #pragma omp parallel shared(a,b,c) private(x)

   #pragma omp for nowait private(x) nowait   // C3013
   // The previous line generates C3013, with two nowait clauses
   // try the following line instead:
   // #pragma omp for nowait private(x)
   for (a = 0 ; a < 10 ; ++a) {
   }
}
```