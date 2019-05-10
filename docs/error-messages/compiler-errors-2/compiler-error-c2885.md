---
title: Erro do compilador C2885
ms.date: 11/04/2016
f1_keywords:
- C2885
helpviewer_keywords:
- C2885
ms.assetid: 7743e5f3-a034-44b4-9ee8-5a6254c27f8c
ms.openlocfilehash: ff5e770052301e95f694d3712f95b82732c2faba
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447690"
---
# <a name="compiler-error-c2885"></a>Erro do compilador C2885

'class::identifier': não uma declaração de using válida em escopo diferente de classe

Você usou uma [usando](../../cpp/using-declaration.md) declaração incorretamente.

## <a name="example"></a>Exemplo

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: ele não é mais válido para ter um `using` declaração para um tipo aninhado, você deve qualificar explicitamente cada referência feitas para o tipo aninhado, coloque o tipo em um n amespace, ou crie um typedef.

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