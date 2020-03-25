---
title: Aviso do compilador (nível 1) C4722
ms.date: 11/04/2016
f1_keywords:
- C4722
helpviewer_keywords:
- C4722
ms.assetid: d8660710-f67b-4f59-a5fd-59259475529e
ms.openlocfilehash: 3fee3296eba4476680f4948b4a1f7fdee03e8840
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175201"
---
# <a name="compiler-warning-level-1-c4722"></a>Aviso do compilador (nível 1) C4722

' function ': o destruidor nunca retorna, possível perda de memória

O fluxo de controle é encerrado em um destruidor. O thread ou todo o programa será encerrado e os recursos alocados não poderão ser liberados.  Além disso, se um destruidor for chamado para o desenrolamento de pilha durante o processamento de exceção, o comportamento do executável será indefinido.

Para resolver, remova a chamada de função que faz com que o destruidor não retorne.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4722:

```cpp
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
