---
title: Erro do compilador C3854 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3854
dev_langs:
- C++
helpviewer_keywords:
- C3854
ms.assetid: 32a9ead0-c6c7-485a-8802-c7b1fe921d3a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d94d2462662fd5f99e80ba205b8e2df41d7c716b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099545"
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