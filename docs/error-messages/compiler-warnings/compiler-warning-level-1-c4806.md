---
title: Aviso do compilador (nível 1) C4806
ms.date: 11/04/2016
f1_keywords:
- C4806
helpviewer_keywords:
- C4806
ms.assetid: 79eb74cd-b925-4b5b-84e1-8ae6f33e38b3
ms.openlocfilehash: 5895e9bf489e240b1eff6f1499b711047ea74b9b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175045"
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
