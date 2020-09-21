---
title: Erro do compilador C2761
ms.date: 11/04/2016
f1_keywords:
- C2761
helpviewer_keywords:
- C2761
ms.assetid: 38c79a05-b56d-485b-820f-95e8c0cb926f
ms.openlocfilehash: 7493934879068109c582a85592f485c1d391e2de
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743380"
---
# <a name="compiler-error-c2761"></a>Erro do compilador C2761

"function": redeclaração de função membro não permitida

Você não pode redeclarar uma função de membro. Você pode defini-lo, mas não redeclará-lo.

## <a name="examples"></a>Exemplos

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
