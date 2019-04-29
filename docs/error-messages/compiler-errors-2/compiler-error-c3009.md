---
title: Erro do compilador C3009
ms.date: 11/04/2016
f1_keywords:
- C3009
helpviewer_keywords:
- C3009
ms.assetid: aded5985-f5fd-4c3e-a157-16be55ec1313
ms.openlocfilehash: a1f4a20396e97c6b868a5678958970813b638499
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350316"
---
# <a name="compiler-error-c3009"></a>Erro do compilador C3009

'Rótulo': ir diretamente para o bloco estruturado de OpenMP não permitido

Código não é possível saltar para dentro ou fora de um bloco de OpenMP.

O exemplo a seguir gera C3009:

```
// C3009.c
// compile with: /openmp
int main() {
   #pragma omp parallel
   {
   lbl2:;
   }
   goto lbl2;   // C3009
}
```