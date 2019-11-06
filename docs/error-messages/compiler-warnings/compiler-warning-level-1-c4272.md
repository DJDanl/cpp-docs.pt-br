---
title: Aviso do compilador (nível 1) C4272
ms.date: 11/04/2016
f1_keywords:
- C4272
helpviewer_keywords:
- C4272
ms.assetid: 0d6c1de4-2eef-42c4-b861-c221f8b495ef
ms.openlocfilehash: 13c56c2261cd069e7edec63921c198e2bee56c95
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626695"
---
# <a name="compiler-warning-level-1-c4272"></a>Aviso do compilador (nível 1) C4272

' function ': está marcado como _ declspec (dllimport); é necessário especificar uma Convenção de chamada nativa ao importar uma função.

É um erro exportar uma função marcada com a Convenção de chamada [_ unclrcall](../../cpp/clrcall.md) e o compilador emite esse aviso se você tentar importar uma função marcada `__clrcall`.

O exemplo a seguir gera C4272:

```cpp
// C4272.cpp
// compile with: /c /W1 /clr
__declspec(dllimport) void __clrcall Test();   // C4272
__declspec(dllimport) void Test2();   // OK
```