---
title: Erro do compilador C2868
ms.date: 11/04/2016
f1_keywords:
- C2868
helpviewer_keywords:
- C2868
ms.assetid: 6ff5837b-e66d-44d1-9d17-80af35e08d08
ms.openlocfilehash: 4cb259ed0f43831226fb7e1a1ccf7b28bcef7819
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614767"
---
# <a name="compiler-error-c2868"></a>Erro do compilador C2868

> '*identificador*': sintaxe inválida para declaração de using; esperado nome qualificado

Um [usando a declaração](../../cpp/using-declaration.md) requer uma *nome qualificado*, um operador de escopo (`::`) separados por sequência de nomes de namespace, classe ou enumeração que termina com o nome do identificador. Um operador de resolução de escopo único pode ser usado para introduzir um nome de namespace global.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2868 e também mostra o uso correto:

```cpp
// C2868.cpp
class X {
public:
   int i;
};

class Y : X {
public:
   using X::i;   // OK
};

int main() {
   using X;   // C2868
}
```