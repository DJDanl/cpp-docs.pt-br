---
title: Erro do compilador C2027
ms.date: 11/04/2016
f1_keywords:
- C2027
helpviewer_keywords:
- C2027
ms.assetid: a39150c0-ec04-45ec-934c-a838bfe76627
ms.openlocfilehash: 3f3fac9d5410595fe5653e257d97d2fd7c858545
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62303483"
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

É possível declarar um ponteiro para um tipo declarado mas indefinido.  Mas o Visual C++ não permite uma referência a um tipo indefinido.

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