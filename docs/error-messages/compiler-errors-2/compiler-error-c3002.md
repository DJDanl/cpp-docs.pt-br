---
title: Erro do compilador C3002
ms.date: 11/04/2016
f1_keywords:
- C3002
helpviewer_keywords:
- C3002
ms.assetid: 2d4241a7-c8eb-4d43-a128-dca255d137bc
ms.openlocfilehash: 677c88747198a2ac95a84e788a5fd16456b6372b
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302192"
---
# <a name="compiler-error-c3002"></a>Erro do compilador C3002

' nome1 nome2 ': vários nomes de diretiva de OpenMP

Não são permitidos vários nomes de diretiva.

O exemplo a seguir gera C3002:

```c
// C3002.c
// compile with: /openmp
int main()
{
   #pragma omp parallel single   // C3002
}
```
