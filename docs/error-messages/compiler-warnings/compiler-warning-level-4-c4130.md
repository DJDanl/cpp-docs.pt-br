---
title: Aviso do compilador (nível 4) C4130
ms.date: 11/04/2016
f1_keywords:
- C4130
helpviewer_keywords:
- C4130
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
ms.openlocfilehash: b55594608eccc5d1e5e764bffb73ecb3787af1e4
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541590"
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

A instrução **If** compara o valor armazenado no ponteiro `pc` ao endereço da cadeia de caracteres "Olá", que é alocada separadamente cada vez que a cadeia de caracteres ocorre no código. A instrução **If** não compara a cadeia de caracteres apontada por `pc` com a cadeia de caracteres "Olá".

Para comparar cadeias de caracteres, use a função `strcmp`.