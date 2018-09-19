---
title: Erro do compilador C2563 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2563
dev_langs:
- C++
helpviewer_keywords:
- C2563
ms.assetid: 54abba68-6458-4ca5-894d-3babdb7b3552
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eec8526df1c5ff69899dd0a2d103cb5f28d4c00c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46067396"
---
# <a name="compiler-error-c2563"></a>Erro do compilador C2563

incompatibilidade na lista de parâmetros formais

Lista de parâmetros formais de uma função (ou um ponteiro para uma função) não corresponde às de outra função (ou ponteiro para uma função de membro). Como resultado, a atribuição de funções ou ponteiros não pode ser feita.

O exemplo a seguir gera C2563:

```
// C2563.cpp
void func( int );
void func( int, int );
int main() {
   void *fp();
   fp = func;   // C2563
}
```