---
title: Erro do compilador C2464
ms.date: 11/04/2016
f1_keywords:
- C2464
helpviewer_keywords:
- C2464
ms.assetid: ace953d6-b414-49ee-bfef-90578a8da00c
ms.openlocfilehash: b2d2766b11d15bdb666baa207591cc9ff279a280
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225469"
---
# <a name="compiler-error-c2464"></a>Erro do compilador C2464

' identifier ': não é possível usar ' New ' para alocar uma referência

Um identificador de referência foi alocado com o **`new`** operador. As referências não são objetos de memória, portanto **`new`** não podem retornar um ponteiro para eles. Use a sintaxe de declaração de variável padrão para declarar uma referência.

O exemplo a seguir gera C2464:

```cpp
// C2464.cpp
int main() {
   new ( int& ir );   // C2464
}
```
