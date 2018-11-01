---
title: Erro do compilador C2110
ms.date: 11/04/2016
f1_keywords:
- C2110
helpviewer_keywords:
- C2110
ms.assetid: 48fd76ed-90d6-4a60-9c7b-f6ce9355b4ca
ms.openlocfilehash: b20e68ec032abdfae9afb1c94fed064010275149
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646960"
---
# <a name="compiler-error-c2110"></a>Erro do compilador C2110

'+': não é possível adicionar dois ponteiros

Foi feita uma tentativa para adicionar dois valores de ponteiro, usando o sinal de adição ( `+` ) operador.

O exemplo a seguir gera C2110:

```
// C2110.cpp
int main() {
   int a = 0;
   int *pa;
   int *pb;
   a = pa + pb;   // C2110
}
```