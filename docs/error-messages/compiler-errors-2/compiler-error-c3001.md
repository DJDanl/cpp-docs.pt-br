---
title: Erro do compilador C3001
ms.date: 11/04/2016
f1_keywords:
- C3001
helpviewer_keywords:
- C3001
ms.assetid: d0e03478-1b44-47e5-8f5b-70415fa1f8bc
ms.openlocfilehash: 1eaf34b0830722b5eae61ec24b54a9edf6cea24c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526588"
---
# <a name="compiler-error-c3001"></a>Erro do compilador C3001

'error_text': esperado um nome de diretiva de OpenMP

O `omp` pragma deve ser seguido por uma diretiva.

O exemplo a seguir gera C3001:

```
// C3001.c
// compile with: /openmp
int main()
{
   #pragma omp   // C3001 missing token
}
```