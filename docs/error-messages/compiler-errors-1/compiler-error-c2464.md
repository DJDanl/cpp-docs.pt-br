---
title: Erro do compilador C2464
ms.date: 11/04/2016
f1_keywords:
- C2464
helpviewer_keywords:
- C2464
ms.assetid: ace953d6-b414-49ee-bfef-90578a8da00c
ms.openlocfilehash: a00ac997f73175eeab08a0132128e48e8fc58feb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338890"
---
# <a name="compiler-error-c2464"></a>Erro do compilador C2464

'identifier': não é possível usar 'new' para alocar uma referência

Um identificador de referência foi alocado com o `new` operador. As referências não são objetos de memória, portanto, `new` não pode retornar um ponteiro para eles. Use a sintaxe de declaração de variável padrão para declarar uma referência.

O exemplo a seguir gera C2464:

```
// C2464.cpp
int main() {
   new ( int& ir );   // C2464
}
```