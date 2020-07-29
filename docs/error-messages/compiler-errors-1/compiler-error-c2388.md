---
title: Erro do compilador C2388
ms.date: 11/04/2016
f1_keywords:
- C2388
helpviewer_keywords:
- C2388
ms.assetid: 764ad2d7-cb04-425f-ba30-70989488c4a4
ms.openlocfilehash: 50148f4fb5c3af33d8de8b005f75f491b0540271
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225495"
---
# <a name="compiler-error-c2388"></a>Erro do compilador C2388

' Symbol ': um símbolo não pode ser declarado com ambos __declspec (AppDomain) e \_ _declspec (processo)

Os `appdomain` `process` **`__declspec`** modificadores e não podem ser usados no mesmo símbolo. O armazenamento de uma variável existe por processo ou por domínio de aplicativo.

Para obter mais informações, consulte [AppDomain](../../cpp/appdomain.md) e [process](../../cpp/process.md).

O exemplo a seguir gera C2388:

```cpp
// C2388.cpp
// compile with: /clr /c
__declspec(process) __declspec(appdomain) int i;   // C2388
__declspec(appdomain) int i;   // OK
```
