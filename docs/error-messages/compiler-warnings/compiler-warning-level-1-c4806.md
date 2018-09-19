---
title: Compilador aviso (nível 1) C4806 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4806
dev_langs:
- C++
helpviewer_keywords:
- C4806
ms.assetid: 79eb74cd-b925-4b5b-84e1-8ae6f33e38b3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b580500c3887fe60b7864280ad5ca1804752f2ae
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062599"
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