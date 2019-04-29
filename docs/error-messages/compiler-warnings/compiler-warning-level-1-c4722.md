---
title: Compilador aviso (nível 1) C4722
ms.date: 11/04/2016
f1_keywords:
- C4722
helpviewer_keywords:
- C4722
ms.assetid: d8660710-f67b-4f59-a5fd-59259475529e
ms.openlocfilehash: 320061c2daf2be042afe45828af637638399beaf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62327282"
---
# <a name="compiler-warning-level-1-c4722"></a>Compilador aviso (nível 1) C4722

'function': destruidor nunca retorna, potencial perda de memória

O fluxo de controle termina com um destruidor. O thread ou todo o programa será encerrado e não podem ser liberados recursos alocados.  Além disso, se um destruidor será chamado para desenrolamento de pilha durante o processamento de exceção, o comportamento do executável é indefinido.

Para resolver, remova a chamada de função que faz com que o destruidor não retornar.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4722:

```
// C4722.cpp
// compile with: /O1 /W1 /c
#include <stdlib.h>
class C {
public:
   C();
   ~C() { exit(1); };   // C4722
};

extern void func (C*);

void Test(){
   C x;
   func(&x);
   // control will not leave Test because destructor will exit
}
```