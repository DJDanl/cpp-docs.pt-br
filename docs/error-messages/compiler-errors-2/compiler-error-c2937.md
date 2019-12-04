---
title: Erro do compilador C2937
ms.date: 11/04/2016
f1_keywords:
- C2937
helpviewer_keywords:
- C2937
ms.assetid: 95671ca3-79f7-4b56-a5f2-a92296da1629
ms.openlocfilehash: f682cd6346d214f4173226d78301f563083ef607
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758366"
---
# <a name="compiler-error-c2937"></a>Erro do compilador C2937

' class ': tipo-classe-ID redefinido como um typedef global

Você não pode usar uma classe genérica ou de modelo como um `typedef`global.

O exemplo a seguir gera C2937:

```cpp
// C2937.cpp
// compile with: /c
template<class T>
struct TC { };
typedef int TC<int>;   // C2937
typedef TC<int> c;   // OK
```

C2937 também pode ocorrer ao usar genéricos:

```cpp
// C2937b.cpp
// compile with: /clr
generic<class T>
ref struct GC { };
typedef int GC<int>;   // C2937
typedef GC<int> xx;   // OK
```
