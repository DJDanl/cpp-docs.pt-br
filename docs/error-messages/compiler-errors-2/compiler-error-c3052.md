---
title: Erro do compilador C3052
ms.date: 11/04/2016
f1_keywords:
- C3052
helpviewer_keywords:
- C3052
ms.assetid: 87480c42-1ceb-4775-8d20-88c54a7bb6a6
ms.openlocfilehash: ed9c27e1602f9372cb9137615ef66932a8df960c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62265770"
---
# <a name="compiler-error-c3052"></a>Erro do compilador C3052

'var': variável não aparece em uma cláusula de compartilhamento de dados em uma cláusula default (none)

Se [default (none)](../../parallel/openmp/reference/default-openmp.md) é usada, qualquer variável usada no bloco estruturado deve ser explicitamente especificado como um [compartilhado](../../parallel/openmp/reference/shared-openmp.md) ou [privada](../../parallel/openmp/reference/private-openmp.md).

O exemplo a seguir gera C3052:

```
// C3052.cpp
// compile with: /openmp /c
int main() {
   int n1 = 1;

   #pragma omp parallel default(none) // shared(n1) private(n1)
   {
      n1 = 0;   // C3052 use either a shared or private clause
   }
}
```