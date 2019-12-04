---
title: Erro do compilador C2464
ms.date: 11/04/2016
f1_keywords:
- C2464
helpviewer_keywords:
- C2464
ms.assetid: ace953d6-b414-49ee-bfef-90578a8da00c
ms.openlocfilehash: e4952f4702d871ecf1c818b1fc7394e54a1a295f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743881"
---
# <a name="compiler-error-c2464"></a>Erro do compilador C2464

' identifier ': não é possível usar ' New ' para alocar uma referência

Um identificador de referência foi alocado com o operador de `new`. As referências não são objetos de memória, portanto `new` não pode retornar um ponteiro para eles. Use a sintaxe de declaração de variável padrão para declarar uma referência.

O exemplo a seguir gera C2464:

```cpp
// C2464.cpp
int main() {
   new ( int& ir );   // C2464
}
```
