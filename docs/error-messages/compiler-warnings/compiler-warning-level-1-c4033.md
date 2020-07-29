---
title: Aviso do compilador (nível 1) C4033
ms.date: 11/04/2016
f1_keywords:
- C4033
helpviewer_keywords:
- C4033
ms.assetid: 189a9ec3-ff6d-49dd-b9b2-530b28bbb7c9
ms.openlocfilehash: bace6057a7a2981bba2d628d8eb21c67f01c3a22
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230747"
---
# <a name="compiler-warning-level-1-c4033"></a>Aviso do compilador (nível 1) C4033

' function ' deve retornar um valor

A função não retorna um valor. Um valor indefinido é retornado.

Funções que usam **`return`** sem um valor de retorno devem ser declaradas como tipo **`void`** .

Esse erro é para o código de linguagem C.

O exemplo a seguir gera C4033:

```c
// C4033.c
// compile with: /W1 /LD
int test_1(int x)   // C4033 expected
{
   if (x)
   {
      return;   // C4033
   }
}
```
