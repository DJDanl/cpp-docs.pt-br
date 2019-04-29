---
title: Erro do compilador C3039
ms.date: 11/04/2016
f1_keywords:
- C3039
helpviewer_keywords:
- C3039
ms.assetid: 02776f16-f57a-4ffd-b7f7-9c696b633e08
ms.openlocfilehash: 69be1b25254119108e517cee2f1e14368e0163f3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350095"
---
# <a name="compiler-error-c3039"></a>Erro do compilador C3039

'var': variável de índice em OpenMP 'instrução for' não pode ser uma variável de reduction

Uma variável de índice é implicitamente privada, portanto, a variável não pode ser usada em uma [redução](../../parallel/openmp/reference/reduction.md) cláusula em circunscrição [paralela](../../parallel/openmp/reference/parallel.md) diretiva.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3039:

```
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