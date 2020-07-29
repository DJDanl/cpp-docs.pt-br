---
title: Erro do compilador C2940
ms.date: 11/04/2016
f1_keywords:
- C2940
helpviewer_keywords:
- C2940
ms.assetid: af6bf2bf-8de6-4cfd-bbf0-4c6b32a30edf
ms.openlocfilehash: b951b7f50c5735f59692582486c9bf57b2f67cd4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233386"
---
# <a name="compiler-error-c2940"></a>Erro do compilador C2940

' class ': tipo-classe-ID redefinido como um typedef local

Você não pode usar uma classe genérica ou de modelo como um local **`typedef`** .

O exemplo a seguir gera C2940:

```cpp
// C2940.cpp
template<class T>
struct TC {};
int main() {
   typedef int TC<int>;   // C2940
   typedef int TC;   // OK
}
```

C2940 também pode ocorrer ao usar genéricos:

```cpp
// C2940b.cpp
// compile with: /clr
generic<class T>
ref struct GC { };

int main() {
   typedef int GC<int>;   // C2940
   typedef int GC;
}
```
