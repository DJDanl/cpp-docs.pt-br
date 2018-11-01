---
title: Compilador aviso (nível 1) C4353
ms.date: 11/04/2016
f1_keywords:
- C4353
helpviewer_keywords:
- C4353
ms.assetid: 6e79f186-ed82-4c95-9923-0ad5bb9c4db1
ms.openlocfilehash: 305c1156ae8dc664edba17287786db50bfabbd18
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50483687"
---
# <a name="compiler-warning-level-1-c4353"></a>Compilador aviso (nível 1) C4353

extensão não padrão usada: constante 0 como expressão de função. Use NOOP' função intrínseca

Não é possível usar o constante 0 (zero) como uma expressão de função. Para obter mais informações, consulte [NOOP](../../intrinsics/noop.md).

O exemplo a seguir gera C4353:

```
// C4353.cpp
// compile with: /W1
void MyPrintf(void){};
#define X 0
#if X
   #define DBPRINT MyPrint
#else
   #define DBPRINT 0   // C4353 expected
#endif
int main(){
DBPRINT();
}
```