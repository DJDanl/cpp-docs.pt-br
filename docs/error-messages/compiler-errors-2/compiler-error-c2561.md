---
title: Erro do compilador C2561 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2561
dev_langs:
- C++
helpviewer_keywords:
- C2561
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8611af23ab884a853fc751ae82c636753993495b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46070698"
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