---
title: Compilador aviso (nível 1) C4272 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4272
dev_langs:
- C++
helpviewer_keywords:
- C4272
ms.assetid: 0d6c1de4-2eef-42c4-b861-c221f8b495ef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 00e30646c9fe56132da9cf87ba71cb54ae6a3e8f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052953"
---
# <a name="compiler-warning-level-1-c4272"></a>Compilador aviso (nível 1) C4272

'function': está marcado como __declspec(dllimport); deve especificar a convenção de chamada nativa ao importar uma função.

É um erro ao exportar uma função marcada com o [clrcall](../../cpp/clrcall.md) convenção de chamada e o compilador emite esse aviso se você tentar importar uma função marcada como `__clrcall`.

O exemplo a seguir gera C4272:

```
// C4272.cpp
// compile with: /c /W1 /clr
__declspec(dllimport) void __clrcall Test();   // C4272
__declspec(dllimport) void Test2();   // OK
```