---
title: Aviso do compilador (nível 1) C4551
ms.date: 11/04/2016
f1_keywords:
- C4551
helpviewer_keywords:
- C4551
ms.assetid: 458b59bd-e2d7-425f-9ba6-268ff200424f
ms.openlocfilehash: d4e7467efa8308e1044e8b7a166174c173dab166
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966362"
---
# <a name="compiler-warning-level-1-c4551"></a>Aviso do compilador (nível 1) C4551

lista de argumentos ausente na chamada de função

Uma chamada de função deve incluir os parênteses de abertura e fechamento após o nome da função, mesmo que a função não aceite parâmetros.

O exemplo a seguir gera C4551:

```cpp
// C4551.cpp
// compile with: /W1
void function1() {
}

int main() {
   function1;   // C4551
   function1();   // OK
}
```