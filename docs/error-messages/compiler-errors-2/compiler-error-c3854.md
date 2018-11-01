---
title: Erro do compilador C3854
ms.date: 11/04/2016
f1_keywords:
- C3854
helpviewer_keywords:
- C3854
ms.assetid: 32a9ead0-c6c7-485a-8802-c7b1fe921d3a
ms.openlocfilehash: 3b48e2c65003537102864fdafe7db70b06ade029
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437785"
---
# <a name="compiler-error-c3854"></a>Erro do compilador C3854

expressão à esquerda de '=' é avaliada como uma função. Não é possível atribuir a uma função (uma função não é um l-value)

Uma referência não pode ser reinicializada. Desreferenciar uma referência a uma função resulta em uma função, que é um rvalue, aos quais você não pode atribuir. Portanto, é possível atribuir por meio de uma referência a uma função.

O exemplo a seguir gera C3854:

```
// C3854.cpp
int afunc(int i)
{
   return i;
}

typedef int (& rFunc_t)(int);
typedef int (* pFunc_t)(int);

int main()
{
   rFunc_t rf = afunc;   // OK binding a reference to function
   pFunc_t pf = &afunc;   // OK initializing a pointer to function

   *pf = &afunc;   // C3854
   // try the following line instead
   // pf = &afunc;
   *rf = &afunc;   // C3854
}
```