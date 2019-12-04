---
title: Erro do compilador C2939
ms.date: 11/04/2016
f1_keywords:
- C2939
helpviewer_keywords:
- C2939
ms.assetid: 455b050b-f2dc-4b5b-bd6a-e1f81d3d1644
ms.openlocfilehash: 97aa24eccb5cec7d74f7f7660260fa8b5f6d8d7d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754609"
---
# <a name="compiler-error-c2939"></a>Erro do compilador C2939

' class ': tipo-classe-ID redefinida como uma variável de dados local

Você não pode usar uma classe genérica ou de modelo como uma variável de dados local.

Esse erro pode ser causado se as chaves forem correspondidas incorretamente.

O exemplo a seguir gera C2939:

```cpp
// C2939.cpp
template<class T>
struct TC { };
int main() {
   int TC<int>;   // C2939
   int TC;   // OK
}
```

C2939 também pode ocorrer ao usar genéricos:

```cpp
// C2939b.cpp
// compile with: /clr
generic<class T>
ref struct GC { };

int main() {
   int GC<int>;   // C2939
   int GC;   // OK
}
```
