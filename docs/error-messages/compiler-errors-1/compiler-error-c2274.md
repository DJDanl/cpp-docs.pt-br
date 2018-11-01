---
title: Erro do compilador C2274
ms.date: 11/04/2016
f1_keywords:
- C2274
helpviewer_keywords:
- C2274
ms.assetid: 8e874903-f499-45ef-8291-f821eee4cc1c
ms.openlocfilehash: f2fcb75098f18ad113ba68959035b37d9cddd6e9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50667019"
---
# <a name="compiler-error-c2274"></a>Erro do compilador C2274

'type': inválido como lado direito de '.' operador

Um tipo é exibido como o operando à direita de um operador de acesso de membro (.).

Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definido pelo usuário. Use a palavra-chave `operator` entre o período e `type`.

O exemplo a seguir gera C2286:

```
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