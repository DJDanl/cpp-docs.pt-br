---
title: Erro do compilador C2274
ms.date: 11/04/2016
f1_keywords:
- C2274
helpviewer_keywords:
- C2274
ms.assetid: 8e874903-f499-45ef-8291-f821eee4cc1c
ms.openlocfilehash: fd807dedb6c300860611d07212b8fc8952a90a65
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758665"
---
# <a name="compiler-error-c2274"></a>Erro do compilador C2274

' type ': inválido como lado direito do operador '. '

Um tipo aparece como o operando direito de um operador de acesso de membro (.).

Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definida pelo usuário. Use a palavra-chave `operator` entre o período e o `type`.

O exemplo a seguir gera C2286:

```cpp
// C2274.cpp
struct MyClass {
   operator int() {
      return 0;
   }
};

int main() {
   MyClass ClassName;
   int i = ClassName.int();   // C2274
   int j = ClassName.operator int();   // OK
}
```
