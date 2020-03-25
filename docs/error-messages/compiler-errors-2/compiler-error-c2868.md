---
title: Erro do compilador C2868
ms.date: 11/04/2016
f1_keywords:
- C2868
helpviewer_keywords:
- C2868
ms.assetid: 6ff5837b-e66d-44d1-9d17-80af35e08d08
ms.openlocfilehash: 0cbcf7dc80aedc554594f88992059f98b7091c21
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201625"
---
# <a name="compiler-error-c2868"></a>Erro do compilador C2868

> '*Identifier*': sintaxe inválida para declaração de using; nome qualificado esperado

Uma [declaração using](../../cpp/using-declaration.md) requer um *nome qualificado*, uma sequência separada do operador de escopo (`::`) de namespace, classe ou nomes de enumeração que termina com o nome do identificador. Um operador de resolução de escopo único pode ser usado para introduzir um nome do namespace global.

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
