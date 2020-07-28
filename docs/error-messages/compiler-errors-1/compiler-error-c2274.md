---
title: Erro do compilador C2274
ms.date: 11/04/2016
f1_keywords:
- C2274
helpviewer_keywords:
- C2274
ms.assetid: 8e874903-f499-45ef-8291-f821eee4cc1c
ms.openlocfilehash: 5907664ba367d6e4005698e112d0a19f3a2a26e9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220373"
---
# <a name="compiler-error-c2274"></a>Erro do compilador C2274

' type ': inválido como lado direito do operador '. '

Um tipo aparece como o operando direito de um operador de acesso de membro (.).

Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definida pelo usuário. Use a palavra-chave **`operator`** entre o ponto e o `type` .

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
