---
title: Aviso do compilador (nível 1) C4804
ms.date: 11/04/2016
f1_keywords:
- C4804
helpviewer_keywords:
- C4804
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
ms.openlocfilehash: aa2cdf0103a1ccc607f2e4a55e1d8f85bb8cc45d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233217"
---
# <a name="compiler-warning-level-1-c4804"></a>Aviso do compilador (nível 1) C4804

' Operation ': uso não seguro do tipo ' bool ' na operação

Esse aviso é para quando você usou uma **`bool`** variável ou valor de forma inesperada. Por exemplo, C4804 será gerado se você usar operadores como o operador unário negativo ( **-** ) ou o operador de complemento ( `~` ). O compilador avalia a expressão.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4804:

```cpp
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
