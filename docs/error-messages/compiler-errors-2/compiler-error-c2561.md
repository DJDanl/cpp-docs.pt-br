---
title: Erro do compilador C2561
ms.date: 11/04/2016
f1_keywords:
- C2561
helpviewer_keywords:
- C2561
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
ms.openlocfilehash: 9c42a2da662a286f3e6887f6a1dba381687136bf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87206959"
---
# <a name="compiler-error-c2561"></a>Erro do compilador C2561

' identifier ': a função deve retornar um valor

A função foi declarada como retornando um valor, mas a definição da função não contém uma **`return`** instrução.

Esse erro pode ser causado por um protótipo de função incorreto:

1. Se a função não retornar um valor, declare a função com o tipo de retorno [void](../../cpp/void-cpp.md).

1. Verifique se todas as ramificações possíveis da função retornam um valor do tipo declarado no protótipo.

1. As funções do C++ que contêm rotinas de assembly embutidas que armazenam o valor de retorno no `AX` registro podem precisar de uma instrução return. Copie o valor em `AX` para uma variável temporária e retorne essa variável da função.

O exemplo a seguir gera C2561:

```cpp
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
