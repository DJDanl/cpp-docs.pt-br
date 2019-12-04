---
title: Erro do compilador C2027
ms.date: 11/04/2016
f1_keywords:
- C2027
helpviewer_keywords:
- C2027
ms.assetid: a39150c0-ec04-45ec-934c-a838bfe76627
ms.openlocfilehash: 62cf208d9d0025afba06d32a15b9a1e50777c473
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750995"
---
# <a name="compiler-error-c2027"></a>Erro do compilador C2027

uso de tipo indefinido ' type '

Um tipo não pode ser usado até que seja definido. Para resolver o erro, verifique se o tipo está totalmente definido antes de fazer referência a ele.

## <a name="example"></a>Exemplo

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

## <a name="example"></a>Exemplo

É possível declarar um ponteiro para um tipo declarado, mas indefinido. Mas C++ não permite uma referência a um tipo indefinido.

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
