---
title: Erro do compilador C2027
ms.date: 11/04/2016
f1_keywords:
- C2027
helpviewer_keywords:
- C2027
ms.assetid: a39150c0-ec04-45ec-934c-a838bfe76627
ms.openlocfilehash: 59d0e5d5a5f0957f2d73cdb863ccee9a2dd2a026
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743250"
---
# <a name="compiler-error-c2027"></a>Erro do compilador C2027

uso de tipo indefinido ' type '

Um tipo não pode ser usado até que seja definido. Para resolver o erro, verifique se o tipo está totalmente definido antes de fazer referência a ele.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2027.

```cpp
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

É possível declarar um ponteiro para um tipo declarado, mas indefinido. Mas o C++ não permite uma referência a um tipo indefinido.

O exemplo a seguir gera C2027.

```cpp
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
