---
title: Erro do compilador C2203 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2203
dev_langs:
- C++
helpviewer_keywords:
- C2203
ms.assetid: 5497df43-86f6-43d5-b6cb-723c4c589b10
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6db497a7967e0cefc16ecb6e5a71874f86179b29
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053759"
---
# <a name="compiler-error-c2203"></a>Erro do compilador C2203

Excluir operador não é possível especificar limites para uma matriz

Com o **/Za** opção (ANSI), o `delete` operador pode excluir uma matriz inteira, mas não partes ou membros específicos da matriz.

O exemplo a seguir gera C2203:

```
// C2203.cpp
// compile with: /Za
int main() {
   int *ar = new int[10];
   delete [4] ar;   // C2203
   // try the following line instead
   // delete [] ar;
}
```