---
title: Erro do compilador C2734
ms.date: 11/04/2016
f1_keywords:
- C2734
helpviewer_keywords:
- C2734
ms.assetid: e53a77b7-825c-42d1-a655-90e1c93b833e
ms.openlocfilehash: b4952f4705ad94133000fe6d84117cb04a5aa850
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87206816"
---
# <a name="compiler-error-c2734"></a>Erro do compilador C2734

' identifier ': o objeto const deve ser inicializado se não for extern

O identificador é declarado **`const`** , mas não inicializado ou **`extern`** .

O exemplo a seguir gera C2734:

```cpp
// C2734.cpp
const int j;   // C2734
extern const int i;   // OK, declared as extern
```
