---
title: Compilador aviso (nível 1) C4804
ms.date: 11/04/2016
f1_keywords:
- C4804
helpviewer_keywords:
- C4804
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
ms.openlocfilehash: 28b3e49717993a3bf20c8cfec5938d698266c0f9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476070"
---
# <a name="compiler-warning-level-1-c4804"></a>Compilador aviso (nível 1) C4804

'operation': uso não seguro de tipo 'bool' em operação

Esse aviso é para quando você tiver usado um `bool` variável ou um valor de forma inesperada. Por exemplo, C4804 será gerado se você usar operadores, como o operador unário negativo (**-**) ou o operador de complemento (`~`). O compilador avalia a expressão.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4804:

```
// C4804.cpp
// compile with: /W1

int main()
{
   bool i = true;
   if (-i)   // C4804, remove the '-' to resolve
   {
      i = false;
   }
}
```