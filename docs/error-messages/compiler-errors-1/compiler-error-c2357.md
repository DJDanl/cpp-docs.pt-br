---
title: Erro do compilador C2357
ms.date: 11/04/2016
f1_keywords:
- C2357
helpviewer_keywords:
- C2357
ms.assetid: d1083945-0ea2-4385-9e66-8c665978806c
ms.openlocfilehash: ce1926468bac7e44485be5c0a0944fdf12dce3d8
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759913"
---
# <a name="compiler-error-c2357"></a>Erro do compilador C2357

' identifier ': deve ser uma função do tipo ' type '

Seu código declara uma versão da função `atexit` que não corresponde à versão declarada internamente pelo compilador. Declare `atexit` da seguinte maneira:

```
int __cdecl atexit(void (__cdecl *)());
```

Para obter mais informações, consulte [init_seg](../../preprocessor/init-seg.md).

O exemplo a seguir gera C2357:

```cpp
// C2357.cpp
// compile with: /c
// C2357 expected
#pragma warning(disable : 4075)
// Uncomment the following line to resolve.
// int __cdecl myexit(void (__cdecl *)());
#pragma init_seg(".mine$m",myexit)
```
