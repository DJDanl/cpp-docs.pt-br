---
title: Erro do compilador C2180 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2180
dev_langs:
- C++
helpviewer_keywords:
- C2180
ms.assetid: ea71b39e-b977-48a7-b7bd-af68ef5e263b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c74912b92162cbfcada3630ed6a6845b67045d0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46084140"
---
# <a name="compiler-error-c2180"></a>Erro do compilador C2180

expressão de controle possui tipo 'type'

A expressão de controle em uma `if`, `while`, `for`, ou `do` instrução é uma expressão convertida em `void`. Para corrigir esse problema, altere a expressão de controle para um que produz um `bool` ou um tipo que pode ser convertido em `bool`.

O exemplo a seguir gera C2180:

```
// C2180.c

int main() {
   while ((void)1)   // C2180
      return 1;
   while (1)         // OK
      return 0;
}
```