---
title: Compilador aviso (nível 1) C4167
ms.date: 11/04/2016
f1_keywords:
- C4167
helpviewer_keywords:
- C4167
ms.assetid: 74a420bd-9371-4167-b1ee-74dd8680f97b
ms.openlocfilehash: 8155fabacef4c9c9acc97b315f7267c23d032f12
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496675"
---
# <a name="compiler-warning-level-1-c4167"></a>Compilador aviso (nível 1) C4167

função: disponível apenas como uma função intrínseca

O **#pragma função** tenta forçar o compilador a usar uma chamada para uma função que deve ser usada no formulário intrínseco de convencional. O pragma é ignorado.

Para evitar esse aviso, remova os **#pragma função**.

## <a name="example"></a>Exemplo

```
// C4167.cpp
// compile with: /W1
#include <malloc.h>
#pragma function(_alloca )   // C4167: _alloca() is intrinsic only
int main(){}
```