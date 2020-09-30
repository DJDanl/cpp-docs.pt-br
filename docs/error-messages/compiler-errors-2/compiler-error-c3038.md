---
title: Erro do compilador C3038
ms.date: 11/04/2016
f1_keywords:
- C3038
helpviewer_keywords:
- C3038
ms.assetid: 140ada3e-5636-43ef-a4ee-22a9f66a771f
ms.openlocfilehash: 7da7dcf1f03c05511ba4bb970e898bc06b9ae3bd
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508418"
---
# <a name="compiler-error-c3038"></a>Erro do compilador C3038

' var ': a variável na cláusula ' Private ' não pode ser uma variável de redução no contexto delimitador

Variáveis que aparecem na cláusula [Reduction](../../parallel/openmp/reference/openmp-clauses.md#reduction) de uma diretiva Parallel não podem ser especificadas em uma cláusula [Private](../../parallel/openmp/reference/openmp-clauses.md#private-openmp) em uma diretiva de compartilhamento de trabalho que se associa à construção paralela.

O exemplo a seguir gera C3038:

```cpp
// C3038.cpp
// compile with: /openmp /c
int g_i, g_i2;

int main() {
   int i;

   #pragma omp parallel reduction(+: g_i)
   {
      #pragma omp for private(g_i)   // C3038
      // try the following line instead
      // #pragma omp for private(g_i2)
      for (i = 0; i < 10; ++i)
         g_i += i;
   }
}
```
