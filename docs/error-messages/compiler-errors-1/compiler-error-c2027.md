---
title: Erro do compilador C2027
ms.date: 11/04/2016
f1_keywords:
- C2027
helpviewer_keywords:
- C2027
ms.assetid: a39150c0-ec04-45ec-934c-a838bfe76627
ms.openlocfilehash: 901e9b791616c5684b352c1fda7687f67b895d9c
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447367"
---
# <a name="compiler-error-c2027"></a>Erro do compilador C2027

uso do tipo indefinido 'type'

Um tipo não pode ser usado até que ele está definido. Para resolver o erro, certifique-se de que o tipo é totalmente definido antes de fazer referência a ele.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2027.

```
// C2027.cpp
class C;
class D {
public:
   void func() {
   }
};

int main() {
   C *pC;
   pC->func();   // C2027

   D *pD;
   pD->func();
}
```

## <a name="example"></a>Exemplo

É possível declarar um ponteiro para um tipo declarado mas indefinido. Mas C++ não permite uma referência a um tipo indefinido.

O exemplo a seguir gera C2027.

```
// C2027_b.cpp
class A;
A& CreateA();

class B;
B* CreateB();

int main() {
   CreateA();   // C2027
   CreateB();   // OK
}
```