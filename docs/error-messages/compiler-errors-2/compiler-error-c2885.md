---
title: Erro do compilador C2885
ms.date: 11/04/2016
f1_keywords:
- C2885
helpviewer_keywords:
- C2885
ms.assetid: 7743e5f3-a034-44b4-9ee8-5a6254c27f8c
ms.openlocfilehash: 8174faed09bdffbdc6974390cceb7c17661eab4b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652121"
---
# <a name="compiler-error-c2885"></a>Erro do compilador C2885

'class::identifier': não uma declaração de using válida em escopo diferente de classe

Você usou uma [usando](../../cpp/using-declaration.md) declaração incorretamente.

## <a name="example"></a>Exemplo

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: não é válido ter um `using` declaração para um tipo aninhado, você deve qualificar explicitamente cada feitas para o tipo aninhado, coloque o tipo em um nome de referência espaço ou criar um typedef.

O exemplo a seguir gera C2885.

```
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

Se você usar o `using` palavra-chave com um membro de classe C++ requer que você definir esse membro dentro de outra classe (uma classe derivada).

O exemplo a seguir gera C2885.

```
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