---
title: Erro do compilador C3039
ms.date: 11/04/2016
f1_keywords:
- C3039
helpviewer_keywords:
- C3039
ms.assetid: 02776f16-f57a-4ffd-b7f7-9c696b633e08
ms.openlocfilehash: ea6efbfa95992b04ade5496e8c7253ee87319a93
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508370"
---
# <a name="compiler-error-c3039"></a>Erro do compilador C3039

' var ': a variável de índice na instrução de OpenMP ' for ' não pode ser uma variável de Reduction

Uma variável de índice é implicitamente privada, portanto, a variável não pode ser usada em uma cláusula de [redução](../../parallel/openmp/reference/openmp-clauses.md#reduction) na diretiva [paralela](../../parallel/openmp/reference/openmp-directives.md#parallel) delimitadora.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3039:

```cpp
// C3039.cpp
// compile with: /openmp /c
int g_i;

int main() {
   int i;

   #pragma omp parallel reduction(+: i)
   {
      #pragma omp for
      for (i = 0; i < 10; ++i)   // C3039
         g_i += i;
   }
}
```
