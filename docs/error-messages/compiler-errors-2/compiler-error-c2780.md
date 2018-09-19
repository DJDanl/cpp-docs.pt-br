---
title: Erro do compilador C2780 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2780
dev_langs:
- C++
helpviewer_keywords:
- C2780
ms.assetid: 423793d8-a3b2-4f35-85f8-ae1d043e2b69
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a7e0bac3957ece3d2b0363f57a99443e9a3cf992
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024067"
---
# <a name="compiler-error-c2780"></a>Erro do compilador C2780

'declaração de ': espera argumentos de N - M fornecido

Um modelo de função tem muitos ou poucos argumentos.

O exemplo a seguir gera C2780 e mostra como corrigi-lo:

```
// C2780.cpp
template<typename T>
void f(T, T){}

int main() {
   f(1);  // C2780
   // try the following line instead
   // f(1,2);
}
```