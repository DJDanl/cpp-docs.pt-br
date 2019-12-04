---
title: Erro do compilador C2086
ms.date: 11/04/2016
f1_keywords:
- C2086
helpviewer_keywords:
- C2086
ms.assetid: 4329bf72-90c8-444c-8524-4ef75e6b2139
ms.openlocfilehash: 417763e8c26918d3cd83702b283244d1c13d9d1f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74735743"
---
# <a name="compiler-error-c2086"></a>Erro do compilador C2086

' identificador ': redefinição

O identificador é definido mais de uma vez ou uma declaração subsequente difere de uma anterior.

C2086 também pode ser o resultado da compilação incremental para um assembly C# referenciado. Recompile C# o assembly para resolver esse erro.

O exemplo a seguir gera C2086:

```cpp
// C2086.cpp
main() {
  int a;
  int a;   // C2086 not an error in ANSI C
}
```
