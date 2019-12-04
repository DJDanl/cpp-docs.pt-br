---
title: Erro fatal C1310
ms.date: 11/04/2016
f1_keywords:
- C1310
helpviewer_keywords:
- C1310
ms.assetid: ac48aa51-8023-42fe-b844-3f8bf228fbef
ms.openlocfilehash: bd8baeb3cfe1624eaf292b3a54fc15a46ea68e11
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746975"
---
# <a name="fatal-error-c1310"></a>Erro fatal C1310

otimizações guiadas por perfil não estão disponíveis com OpenMP

Você não poderá vincular com [/LTCG: PGI](../../build/reference/ltcg-link-time-code-generation.md) qualquer módulo que foi compilado com [/GL](../../build/reference/gl-whole-program-optimization.md).

O exemplo a seguir gera C1310:

```cpp
// C1310.cpp
// compile with: /openmp /GL /link /LTCG:PGI
// C1310 expected
int main()
{
   int i = 0, j = 10;

   #pragma omp parallel
   {
      #pragma omp for
      for (i = 0; i < 0; i++)
         --j;
   }
}
```
