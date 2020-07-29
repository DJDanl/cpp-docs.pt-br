---
title: Erro do compilador C2273
ms.date: 11/04/2016
f1_keywords:
- C2273
helpviewer_keywords:
- C2273
ms.assetid: 3c682c66-97bf-4a23-a22c-d9a26a92bf95
ms.openlocfilehash: f5780c299eb4da03ece3611ee55062ee7ebcdaae
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212781"
---
# <a name="compiler-error-c2273"></a>Erro do compilador C2273

' type ': inválido como lado direito do operador '-> '

Um tipo é exibido como o operando à direita de um `->` operador.

Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definida pelo usuário. Use a palavra-chave **`operator`** entre-> e `type` .

O exemplo a seguir gera C2273:

```cpp
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
