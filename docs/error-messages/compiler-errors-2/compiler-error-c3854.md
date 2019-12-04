---
title: Erro do compilador C3854
ms.date: 11/04/2016
f1_keywords:
- C3854
helpviewer_keywords:
- C3854
ms.assetid: 32a9ead0-c6c7-485a-8802-c7b1fe921d3a
ms.openlocfilehash: 8c62117e9437233f614aa0e57a3848fcb8dd0c79
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754843"
---
# <a name="compiler-error-c3854"></a>Erro do compilador C3854

a expressão à esquerda de ' = ' é avaliada como uma função. Não é possível atribuir a uma função (uma função não é um l-Value)

Uma referência não pode ser reinicializada. A desreferência de uma referência a uma função produz uma função, que é um Rvalue, à qual você não pode atribuir. Portanto, você não pode atribuir por meio de uma referência a uma função.

O exemplo a seguir gera C3854:

```cpp
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
