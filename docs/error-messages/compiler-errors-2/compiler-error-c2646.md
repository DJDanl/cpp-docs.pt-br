---
title: Erro do compilador C2646
ms.date: 11/04/2016
f1_keywords:
- C2646
helpviewer_keywords:
- C2646
ms.assetid: 92ff1f02-5eaf-40a5-8b7a-a682f149e967
ms.openlocfilehash: a05c98564c4e45dc380690c1b8c9bace5fc14cf4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216148"
---
# <a name="compiler-error-c2646"></a>Erro do compilador C2646

um struct ou Union anônima no escopo global ou de namespace deve ser declarado estático

Um struct ou Union anônima tem escopo global ou de namespace, mas não está declarado **`static`** .

O exemplo a seguir gera C2646 e mostra como corrigi-lo:

```cpp
// C2646.cpp
// compile with: /c
union { int i; };   // C2646 not static

// OK
static union { int j; };
union U { int i; };
```
