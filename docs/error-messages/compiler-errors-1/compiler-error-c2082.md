---
title: Erro do compilador C2082
ms.date: 11/04/2016
f1_keywords:
- C2082
helpviewer_keywords:
- C2082
ms.assetid: 87a6d442-157c-46e8-9bff-8388f8338ae0
ms.openlocfilehash: 754a079a152fd3aeaf4da4e27633a4a3476a8959
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757703"
---
# <a name="compiler-error-c2082"></a>Erro do compilador C2082

redefinição do parâmetro formal ' identifier '

Um parâmetro formal para uma função é declarado novamente dentro do corpo da função. Para resolver o erro, remova a redefinição.

O exemplo a seguir gera C2082:

```cpp
// C2082.cpp
void func(int i) {
   int i;   // C2082
   int ii;   // OK
}
```
