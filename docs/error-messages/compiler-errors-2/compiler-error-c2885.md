---
title: Erro do compilador C2885
ms.date: 11/04/2016
f1_keywords:
- C2885
helpviewer_keywords:
- C2885
ms.assetid: 7743e5f3-a034-44b4-9ee8-5a6254c27f8c
ms.openlocfilehash: 9b6b7bb54d5dce48dc6fce517eb0c909b0284da2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233438"
---
# <a name="compiler-error-c2885"></a>Erro do compilador C2885

' classe:: identificador ': não é uma declaração using válida em escopo diferente de classe

Você usou uma declaração de [uso](../../cpp/using-declaration.md) incorreta.

## <a name="example"></a>Exemplo

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: não é mais válido ter uma **`using`** declaração para um tipo aninhado; você deve qualificar explicitamente cada referência feita ao tipo aninhado, colocar o tipo em um namespace ou criar um typedef.

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

## <a name="example"></a>Exemplo

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
