---
title: Erro do compilador C2646
ms.date: 11/04/2016
f1_keywords:
- C2646
helpviewer_keywords:
- C2646
ms.assetid: 92ff1f02-5eaf-40a5-8b7a-a682f149e967
ms.openlocfilehash: c02d7216df42681ae2ec733ae932d22861c1f0ee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62282203"
---
# <a name="compiler-error-c2646"></a>Erro do compilador C2646

um struct anônimo ou união no global ou escopo de namespace deve ser declarado como static

Um struct anônimo ou uma união tem global ou escopo de namespace, mas não é declarado `static`.

O exemplo a seguir gera C2646 e mostra como corrigi-lo:

```
// C2646.cpp
// compile with: /c
union { int i; };   // C2646 not static

// OK
static union { int j; };
union U { int i; };
```