---
title: Erro do compilador C2761
ms.date: 11/04/2016
f1_keywords:
- C2761
helpviewer_keywords:
- C2761
ms.assetid: 38c79a05-b56d-485b-820f-95e8c0cb926f
ms.openlocfilehash: fbe2b3089d387d356073febf2b27bbb44b6be7e3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759497"
---
# <a name="compiler-error-c2761"></a>Erro do compilador C2761

"function": redeclaração de função membro não permitida

Você não pode redeclarar uma função de membro. Você pode defini-lo, mas não redeclará-lo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2761.

```cpp
// C2761.cpp
class a {
   int t;
   void test();
};

void a::a;     // C2761
void a::test;  // C2761
```

## <a name="example"></a>Exemplo

Não é possível definir membros não estáticos de uma classe ou estrutura.  O exemplo a seguir gera C2761.

```cpp
// C2761_b.cpp
// compile with: /c
struct C {
   int s;
   static int t;
};

int C::s;   // C2761
int C::t;   // OK
```
