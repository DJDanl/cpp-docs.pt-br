---
title: Aviso do compilador (nível 1) C4272
ms.date: 11/04/2016
f1_keywords:
- C4272
helpviewer_keywords:
- C4272
ms.assetid: 0d6c1de4-2eef-42c4-b861-c221f8b495ef
ms.openlocfilehash: 747b9e60ad2b8b0036c6eac50d44c2d70277384f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163121"
---
# <a name="compiler-warning-level-1-c4272"></a>Aviso do compilador (nível 1) C4272

' function ': está marcado como __declspec (dllimport); é necessário especificar uma Convenção de chamada nativa ao importar uma função.

É um erro exportar uma função marcada com a Convenção de chamada [__clrcall](../../cpp/clrcall.md) e o compilador emite esse aviso se você tentar importar uma função marcada `__clrcall`.

O exemplo a seguir gera C4272:

```cpp
// C4272.cpp
// compile with: /c /W1 /clr
__declspec(dllimport) void __clrcall Test();   // C4272
__declspec(dllimport) void Test2();   // OK
```
