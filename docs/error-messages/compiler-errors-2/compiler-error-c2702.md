---
title: Erro do compilador C2702
description: Descreve o erro C2702 do compilador C/C++ do Microsoft.
ms.date: 08/25/2020
f1_keywords:
- C2702
helpviewer_keywords:
- C2702
ms.assetid: 6def15d4-9a8d-43e7-ae35-42d7cb57c27e
ms.openlocfilehash: 83210f6ab261a5ae6dd7320182c3f4c3539ff4d1
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898429"
---
# <a name="compiler-error-c2702"></a>Erro do compilador C2702

> `__except` pode não aparecer no bloco de terminação

Um manipulador de exceção ( **`__try`** / **`__except`** ) não pode ser aninhado dentro de um **`__finally`** bloco.

O exemplo a seguir gera C2702:

```cpp
// C2702.cpp
// processor: x86 IPF
int Counter;
int main() {
   __try {}
   __finally {
      __try {}   // C2702
      __except( Counter ) {}   // C2702
   }
}
```
