---
title: Compilador aviso (nível 1) C4806
ms.date: 11/04/2016
f1_keywords:
- C4806
helpviewer_keywords:
- C4806
ms.assetid: 79eb74cd-b925-4b5b-84e1-8ae6f33e38b3
ms.openlocfilehash: b6fc5708d4e2f9982ceaab57260f13e134e4d247
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50578250"
---
# <a name="compiler-warning-level-1-c4806"></a>Compilador aviso (nível 1) C4806

'operation': operação não segura: nenhum valor do tipo 'type' promovido para o tipo 'type' pode ser igual à constante fornecida

Essa mensagem adverte em relação ao código, como `b == 3`, onde `b` tem o tipo `bool`. A promoção de regras causa `bool` para ser promovido a `int`. Isso é legal, mas nunca pode ser **verdadeira**. O exemplo a seguir gera C4806:

```
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