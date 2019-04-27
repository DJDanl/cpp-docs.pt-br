---
title: Erro do compilador C3003
ms.date: 11/04/2016
f1_keywords:
- C3003
helpviewer_keywords:
- C3003
ms.assetid: 22e74f99-bb7f-4518-ab0d-934d5d49bcc7
ms.openlocfilehash: 6d15d8bde8855b8dcc4857492acdeb950731b503
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62152495"
---
# <a name="compiler-error-c3003"></a>Erro do compilador C3003

'diretiva: Nome de diretiva de OpenMP não permitido após cláusulas de diretiva

Um nome de diretiva de OpenMP não pode seguir uma cláusula de diretiva de OpenMP.

O exemplo a seguir gera C3003:

```
// C3003.c
// compile with: /openmp
int main()
{
   int x, y, z;
   #pragma omp parallel shared(x, y, z) for   // C3003
}
```