---
title: Erro do compilador C2646
ms.date: 11/04/2016
f1_keywords:
- C2646
helpviewer_keywords:
- C2646
ms.assetid: 92ff1f02-5eaf-40a5-8b7a-a682f149e967
ms.openlocfilehash: a5c4dbc967c304fc6b13eb00e2c7093380ec8be9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758210"
---
# <a name="compiler-error-c2646"></a>Erro do compilador C2646

um struct ou Union anônima no escopo global ou de namespace deve ser declarado estático

Um struct ou Union anônima tem escopo global ou de namespace, mas não está declarado `static`.

O exemplo a seguir gera C2646 e mostra como corrigi-lo:

```cpp
// C2646.cpp
// compile with: /c
union { int i; };   // C2646 not static

// OK
static union { int j; };
union U { int i; };
```
