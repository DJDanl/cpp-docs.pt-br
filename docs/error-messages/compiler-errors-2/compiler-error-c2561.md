---
title: Erro do compilador C2561
ms.date: 11/04/2016
f1_keywords:
- C2561
helpviewer_keywords:
- C2561
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
ms.openlocfilehash: 8350c5baf129b88c178be280d2da7fe856c6cf57
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62368416"
---
# <a name="compiler-error-c2561"></a>Erro do compilador C2561

'identifier': função deve retornar um valor

A função foi declarada como retornando um valor, mas a definição de função não contém um `return` instrução.

Esse erro pode ser causado por um protótipo de função incorreto:

1. Se a função não retornar um valor, declare a função com o tipo de retorno [void](../../cpp/void-cpp.md).

1. Verifique se todas as possíveis ramificações da função retornam um valor do tipo declarado no protótipo.

1. Funções de C++ que contém rotinas de assembly embutido que armazenam o valor de retorno de `AX` register pode precisar de uma instrução return. Copie o valor no `AX` a uma variável temporária e essa variável de retorno da função.

O exemplo a seguir gera C2561:

```
// C2561.cpp
int Test(int x) {
   if (x) {
      return;   // C2561
      // try the following line instead
      // return 1;
   }
   return 0;
}

int main() {
   Test(1);
}
```