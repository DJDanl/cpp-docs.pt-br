---
title: Compilador aviso (nível 1) C4167 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4167
dev_langs:
- C++
helpviewer_keywords:
- C4167
ms.assetid: 74a420bd-9371-4167-b1ee-74dd8680f97b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c154a91c21bf0b35493bb8033e5453ef1c536267
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46082177"
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