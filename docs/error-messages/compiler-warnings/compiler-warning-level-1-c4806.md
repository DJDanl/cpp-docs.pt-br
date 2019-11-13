---
title: Aviso do compilador (nível 1) C4806
ms.date: 11/04/2016
f1_keywords:
- C4806
helpviewer_keywords:
- C4806
ms.assetid: 79eb74cd-b925-4b5b-84e1-8ae6f33e38b3
ms.openlocfilehash: dae6ed7d7a38daf0ce525ae62409823212db711b
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052359"
---
# <a name="compiler-warning-level-1-c4806"></a>Aviso do compilador (nível 1) C4806

' Operation ': operação não segura: nenhum valor do tipo ' type ' promovido para o tipo ' type ' pode ser igual à constante fornecida

Essa mensagem avisa sobre o código como `b == 3`, em que `b` tem o tipo `bool`. As regras de promoção fazem com que `bool` sejam promovidas para `int`. Isso é legal, mas nunca é **verdade**. O exemplo a seguir gera C4806:

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