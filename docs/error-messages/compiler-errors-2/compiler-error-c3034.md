---
title: Erro do compilador C3034
ms.date: 11/04/2016
f1_keywords:
- C3034
helpviewer_keywords:
- C3034
ms.assetid: 49db8bac-2720-4622-94e3-7988f1603fa3
ms.openlocfilehash: 56ae2ddf35148fe263e406f48526cd68c4f91352
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74748288"
---
# <a name="compiler-error-c3034"></a>Erro do compilador C3034

Diretiva de OpenMP ' directive1 ' não pode ser aninhada diretamente dentro da diretiva ' directive2 '

Algumas diretivas não podem ser aninhadas. Para corrigir esse erro, você pode mesclar as instruções de ambas as diretivas no bloco de uma diretiva ou pode construir diretivas consecutivas.

O exemplo a seguir gera C3034:

```cpp
// C3034.cpp
// compile with: /openmp /link vcomps.lib
int main() {

   #pragma omp single
   {
      #pragma omp single   // C3034
      {
      ;
      }
   }

   // Two consecutive single clauses are OK.
   #pragma omp single
   {
   }

   #pragma omp single
   {
   }
}
```
