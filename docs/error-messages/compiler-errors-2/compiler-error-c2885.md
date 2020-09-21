---
title: Erro do compilador C2885
ms.date: 11/04/2016
f1_keywords:
- C2885
helpviewer_keywords:
- C2885
ms.assetid: 7743e5f3-a034-44b4-9ee8-5a6254c27f8c
ms.openlocfilehash: 1953cb8fb9f80c5c1f967e10583c2b7303075f59
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742665"
---
# <a name="compiler-error-c2885"></a>Erro do compilador C2885

' classe:: identificador ': não é uma declaração using válida em escopo diferente de classe

Você usou uma declaração de [uso](../../cpp/using-declaration.md) incorreta.

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: não é mais válido ter uma **`using`** declaração para um tipo aninhado; você deve qualificar explicitamente cada referência feita ao tipo aninhado, colocar o tipo em um namespace ou criar um typedef.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2885.

```cpp
// C2885.cpp
namespace MyNamespace {
   class X1 {};
}

struct MyStruct {
   struct X1 {
      int i;
   };
};

int main () {
   using MyStruct::X1;   // C2885

   // OK
   using MyNamespace::X1;
   X1 myX1;

   MyStruct::X1 X12;

   typedef MyStruct::X1 abc;
   abc X13;
   X13.i = 9;
}
```

Se você usar a **`using`** palavra-chave com um membro de classe, o C++ exigirá que você defina esse membro dentro de outra classe (uma classe derivada).

O exemplo a seguir gera C2885.

```cpp
// C2885_b.cpp
// compile with: /c
class A {
public:
   int i;
};

void z() {
   using A::i;   // C2885 not in a class
}

class B : public A {
public:
   using A::i;
};
```
