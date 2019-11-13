---
title: Aviso do compilador (nível 1) C4717
ms.date: 11/04/2016
f1_keywords:
- C4717
helpviewer_keywords:
- C4717
ms.assetid: 5ef3c6c7-8599-4714-a973-0f5b69cdab3c
ms.openlocfilehash: 0bc95cc770914a1c02a7a40f9754415c2f013d63
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051340"
---
# <a name="compiler-warning-level-1-c4717"></a>Aviso do compilador (nível 1) C4717

"function": recursivo em todos os caminhos de controle, função causará estouro de pilha de tempo de execução

Cada caminho por meio de uma função contém uma chamada para a função. Como não há nenhuma maneira de sair da função sem primeiro chamar a si mesma recursivamente, a função nunca será encerrada.

O exemplo a seguir gera C4717:

```cpp
// C4717.cpp
// compile with: /W1 /c
// C4717 expected
int func(int x) {
   if (x > 1)
      return func(x - 1); // recursive call
   else {
      int y = func(0) + 1; // recursive call
      return y;
   }
}

int main(){
   func(1);
}
```