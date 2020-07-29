---
title: Aviso do compilador (nível 1) C4806
ms.date: 11/04/2016
f1_keywords:
- C4806
helpviewer_keywords:
- C4806
ms.assetid: 79eb74cd-b925-4b5b-84e1-8ae6f33e38b3
ms.openlocfilehash: 0d3b0aa05ca5fff16b3cd28c11e3bf8290de1b3b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225339"
---
# <a name="compiler-warning-level-1-c4806"></a>Aviso do compilador (nível 1) C4806

' Operation ': operação não segura: nenhum valor do tipo ' type ' promovido para o tipo ' type ' pode ser igual à constante fornecida

Essa mensagem avisa sobre o código como `b == 3` , onde `b` tem o tipo **`bool`** . As regras de promoção fazem com que **`bool`** sejam promovidas para **`int`** . Isso é legal, mas nunca pode ser **`true`** . O exemplo a seguir gera C4806:

```cpp
// C4806.cpp
// compile with: /W1
int main()
{
   bool b = true;
   // try..
   // int b = true;

   if (b == 3)   // C4806
   {
      b = false;
   }
}
```
