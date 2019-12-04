---
title: Erro do compilador C3039
ms.date: 11/04/2016
f1_keywords:
- C3039
helpviewer_keywords:
- C3039
ms.assetid: 02776f16-f57a-4ffd-b7f7-9c696b633e08
ms.openlocfilehash: 344fd32e66881c2529ddb1f9185c25752f0a736c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754973"
---
# <a name="compiler-error-c3039"></a>Erro do compilador C3039

' var ': a variável de índice na instrução de OpenMP ' for ' não pode ser uma variável de Reduction

Uma variável de índice é implicitamente privada, portanto, a variável não pode ser usada em uma cláusula de [redução](../../parallel/openmp/reference/reduction.md) na diretiva [paralela](../../parallel/openmp/reference/parallel.md) delimitadora.

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
