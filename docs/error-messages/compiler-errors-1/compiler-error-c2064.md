---
title: Erro do compilador C2064
ms.date: 11/04/2016
f1_keywords:
- C2064
helpviewer_keywords:
- C2064
ms.assetid: 6cda05da-f437-4f50-9813-ae69538713a3
ms.openlocfilehash: cd62ea825e3ae7d9e4acc1cb6d93d4bc102be0eb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737316"
---
# <a name="compiler-error-c2064"></a>Erro do compilador C2064

o termo não é avaliado para uma função usando N argumentos

É feita uma chamada para uma função por meio de uma expressão. A expressão não é avaliada como um ponteiro para uma função que usa o número especificado de argumentos.

Neste exemplo, o código tenta chamar não funções como funções. O exemplo a seguir gera C2064:

```cpp
// C2064.cpp
int i, j;
char* p;
void func() {
   j = i();    // C2064, i is not a function
   p();        // C2064, p doesn't point to a function
}
```

Você deve chamar ponteiros para funções de membro não estáticas do contexto de uma instância de objeto. O exemplo a seguir gera C2064 e mostra como corrigi-lo:

```cpp
// C2064b.cpp
struct C {
   void func1(){}
   void func2(){}
};

typedef void (C::*pFunc)();

int main() {
   C c;
   pFunc funcArray[2] = {&C::func1, &C::func2};
   (funcArray[0])();    // C2064
   (c.*funcArray[0])(); // OK - function called in instance context
}
```

Dentro de uma classe, os ponteiros de função de membro também devem indicar o contexto do objeto de chamada. O exemplo a seguir gera C2064 e mostra como corrigi-lo:

```cpp
// C2064d.cpp
// Compile by using: cl /c /W4 C2064d.cpp
struct C {
   typedef void (C::*pFunc)();
   pFunc funcArray[2];
   void func1(){}
   void func2(){}
   C() {
      funcArray[0] = &C::func1;
      funcArray[1] = &C::func2;
   }
   void func3() {
      (funcArray[0])();   // C2064
      (this->*funcArray[0])(); // OK - called in this instance context
   }
};
```
