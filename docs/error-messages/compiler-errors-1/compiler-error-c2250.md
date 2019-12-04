---
title: Erro do compilador C2250
ms.date: 11/04/2016
f1_keywords:
- C2250
helpviewer_keywords:
- C2250
ms.assetid: f990986f-5c7d-4af4-a25c-b35540f1e217
ms.openlocfilehash: 472aabf00fecd000f274d97b5753ed8460ff867f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758860"
---
# <a name="compiler-error-c2250"></a>Erro do compilador C2250

' identifier ': herança ambígua de ' class:: member '

A classe derivada herda mais de uma substituição de uma função virtual de uma classe base virtual. Essas substituições são ambíguas na classe derivada.

O exemplo a seguir gera C2286:

```cpp
// C2250.cpp
// compile with: /c
// C2250 expected
struct V {
   virtual void vf();
};

struct A : virtual V {
   void vf();
};

struct B : virtual V {
   void vf();
};

struct D : A, B {
   // Uncomment the following line to resolve.
   // void vf();
};
```
