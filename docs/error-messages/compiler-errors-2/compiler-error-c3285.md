---
title: Erro do compilador C3285
ms.date: 11/04/2016
f1_keywords:
- C3285
helpviewer_keywords:
- C3285
ms.assetid: 04e8f210-d67e-4810-b153-e1efe2986c8f
ms.openlocfilehash: 6bc211fb2394a9a2989702c13e19bd63ea8a5ad7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62381326"
---
# <a name="compiler-error-c3285"></a>Erro do compilador C3285

para cada instrução não pode operar em variáveis do tipo 'type'

O `for each` repete um grupo de instruções inseridas para cada elemento em uma matriz ou uma coleção de objetos.

Ver [para cada um, no](../../dotnet/for-each-in.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3285.

```
// C3285.cpp
// compile with: /clr
int main() {
   for each (int i in 0) {}   // C3285

   array<int> ^p = { 1, 2, 3 };
   for each (int j in p) {}   // OK
}
```