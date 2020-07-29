---
title: Aviso do compilador (nível 4) C4130
ms.date: 11/04/2016
f1_keywords:
- C4130
helpviewer_keywords:
- C4130
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
ms.openlocfilehash: 7b2fbccfd3b124220d6e310c01adace1d3e112c1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219957"
---
# <a name="compiler-warning-level-4-c4130"></a>Aviso do compilador (nível 4) C4130

' operator ': operação lógica no endereço de constante de cadeia de caracteres

O uso do operador com o endereço de um literal de cadeia de caracteres produz código inesperado.

O exemplo a seguir gera C4130:

```cpp
// C4130.cpp
// compile with: /W4
int main()
{
   char *pc;
   pc = "Hello";
   if (pc == "Hello") // C4130
   {
   }
}
```

A **`if`** instrução compara o valor armazenado no ponteiro `pc` para o endereço da cadeia de caracteres "Olá", que é alocada separadamente sempre que a cadeia de caracteres ocorre no código. A **`if`** instrução não compara a cadeia de caracteres apontada por `pc` com a cadeia de caracteres "Olá".

Para comparar cadeias de caracteres, use a `strcmp` função.
