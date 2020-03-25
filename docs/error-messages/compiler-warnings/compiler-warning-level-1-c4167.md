---
title: Aviso do compilador (nível 1) C4167
ms.date: 11/04/2016
f1_keywords:
- C4167
helpviewer_keywords:
- C4167
ms.assetid: 74a420bd-9371-4167-b1ee-74dd8680f97b
ms.openlocfilehash: 99d60bc08a077ae1637b80eac6775c8fa2571a1e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163592"
---
# <a name="compiler-warning-level-1-c4167"></a>Aviso do compilador (nível 1) C4167

função: disponível somente como uma função intrínseca

A **função #pragma** tenta forçar o compilador a usar uma chamada convencional para uma função que deve ser usada em forma intrínseca. O pragma é ignorado.

Para evitar esse aviso, remova a **função #pragma**.

## <a name="example"></a>Exemplo

```cpp
// C4167.cpp
// compile with: /W1
#include <malloc.h>
#pragma function(_alloca )   // C4167: _alloca() is intrinsic only
int main(){}
```
