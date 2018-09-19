---
title: Compilador aviso (nível 1) C4722 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4722
dev_langs:
- C++
helpviewer_keywords:
- C4722
ms.assetid: d8660710-f67b-4f59-a5fd-59259475529e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0f450120ff05c7e13888bf4b4ce4425405525b4c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46112493"
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