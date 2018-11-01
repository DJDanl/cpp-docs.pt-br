---
title: Erro do compilador C2273
ms.date: 11/04/2016
f1_keywords:
- C2273
helpviewer_keywords:
- C2273
ms.assetid: 3c682c66-97bf-4a23-a22c-d9a26a92bf95
ms.openlocfilehash: f2ed5c49a9f8243fd5c9c302caf2876493c26bc3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526334"
---
# <a name="compiler-error-c2273"></a>Erro do compilador C2273

'type': inválido como lado direito do operador '->'

Um tipo é exibido como o operando à direita de um `->` operador.

Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definido pelo usuário. Use a palavra-chave `operator` entre -> e `type`.

O exemplo a seguir gera C2273:

```
// C2273.cpp
struct MyClass {
   operator int() {
      return 0;
   }
};
int main() {
   MyClass * ClassPtr = new MyClass;
   int i = ClassPtr->int();   // C2273
   int j = ClassPtr-> operator int();   // OK
}
```