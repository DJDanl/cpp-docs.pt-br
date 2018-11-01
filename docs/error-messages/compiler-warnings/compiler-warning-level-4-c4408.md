---
title: Compilador aviso (nível 4) C4408
ms.date: 11/04/2016
f1_keywords:
- C4408
helpviewer_keywords:
- C4408
ms.assetid: 8488a186-ed1d-425c-aaeb-c72472c1da68
ms.openlocfilehash: 3c7613d42bbd0ac7fa58a0b95ba68efb60d9f50a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553862"
---
# <a name="compiler-warning-level-4-c4408"></a>Compilador aviso (nível 4) C4408

anonymousstruct ou união não declarou nenhum membro de dados

Um struct anônimo ou união deve ter pelo menos um membro de dados.

O exemplo a seguir gera C4408:

```
// C4408.cpp
// compile with: /W4 /LD
static union
{
   // int i;
};
// a named union can have no data members
// } MyUnion;
```