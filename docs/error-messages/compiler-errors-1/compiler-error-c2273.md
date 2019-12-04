---
title: Erro do compilador C2273
ms.date: 11/04/2016
f1_keywords:
- C2273
helpviewer_keywords:
- C2273
ms.assetid: 3c682c66-97bf-4a23-a22c-d9a26a92bf95
ms.openlocfilehash: 9cd46f7a8a0762fcae2bdec15b9b4be6384adb25
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758678"
---
# <a name="compiler-error-c2273"></a>Erro do compilador C2273

' type ': inválido como lado direito do operador '-> '

Um tipo é exibido como o operando direito de um operador de `->`.

Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definida pelo usuário. Use a palavra-chave `operator` entre-> e `type`.

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
