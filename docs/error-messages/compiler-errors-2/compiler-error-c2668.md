---
title: Erro do compilador C2668 | Microsoft Docs
ms.custom: ''
ms.date: 03/28/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2668
dev_langs:
- C++
helpviewer_keywords:
- C2668
ms.assetid: 041e9627-1c76-420e-a653-cfc83f933bd3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 23bb1a6fcf64590670ede2eb6aca232a5a3b4f5c
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48889980"
---
# <a name="compiler-error-c2668"></a>Erro do compilador C2668

'function': chamada ambígua à função sobrecarregada

A chamada de função sobrecarregada especificado não pôde ser resolvida. Você talvez queira converter explicitamente um ou mais dos parâmetros reais.

Você também pode obter esse erro por meio do uso do modelo. Se, na mesma classe, você tem uma função de membro regular e uma função de membro personalizado com a mesma assinatura, um modelo deve vir primeiro. Essa é uma limitação da implementação atual do Visual C++.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2668:

```cpp
// C2668.cpp
struct A {};
struct B : A {};
struct X {};
struct D : B, X {};

void func( X, X ){}
void func( A, B ){}
D d;
int main() {
   func( d, d );   // C2668 D has an A, B, and X
   func( (X)d, (X)d );   // OK, uses func( X, X )
}
```

## <a name="example"></a>Exemplo

Outra maneira de resolver esse erro é com um [usando a declaração](../../cpp/using-declaration.md):

```cpp
// C2668b.cpp
// compile with: /EHsc /c
// C2668 expected
#include <iostream>
class TypeA {
public:
   TypeA(int value) {}
};

class TypeB {
   TypeB(int intValue);
   TypeB(double dbValue);
};

class TestCase {
public:
   void AssertEqual(long expected, long actual, std::string
                    conditionExpression = "");
};

class AppTestCase : public TestCase {
public:
   // Uncomment the following line to resolve.
   // using TestCase::AssertEqual;
   void AssertEqual(const TypeA expected, const TypeA actual,
                    std::string conditionExpression = "");
   void AssertEqual(const TypeB expected, const TypeB actual,
                    std::string conditionExpression = "");
};

class MyTestCase : public AppTestCase {
   void TestSomething() {
      int actual = 0;
      AssertEqual(0, actual, "Value");
   }
};
```

## <a name="example"></a>Exemplo

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: conversão ambígua na conversão da constante 0.

Conversão de uma conversão usando a constante 0 é ambíguo, pois int requer uma conversão ambos os longos e para void *. Para resolver esse erro, converta 0 para o tipo exato do parâmetro de função que está sendo usado de forma que nenhuma conversão precisa acontecer (esse código será válido nas versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++).

```cpp
// C2668c.cpp
#include "stdio.h"
void f(long) {
   printf_s("in f(long)\n");
}
void f(void*) {
   printf_s("in f(void*)\n");
}
int main() {
   f((int)0);   // C2668

   // OK
   f((long)0);
   f((void*)0);
}
```

## <a name="example"></a>Exemplo

Esse erro pode ocorrer porque o CRT agora tem float e double formas de todas as funções de matemática.

```cpp
// C2668d.cpp
#include <math.h>
int main() {
   int i = 0;
   float f;
   f = cos(i);   // C2668
   f = cos((float)i);   // OK
}
```

## <a name="example"></a>Exemplo

Esse erro pode ocorrer porque a pow (int, int) foi removido do Math. h no CRT.

```cpp
// C2668e.cpp
#include <math.h>
int main() {
   pow(9,9);   // C2668
   pow((double)9,9);   // OK
}
```

## <a name="example"></a>Exemplo

Esse código foi bem-sucedido no Visual Studio 2015, mas falha no Visual Studio 2017 e posterior com C2668. No Visual Studio 2015, o compilador tratou a inicialização de lista de cópia de maneira incorreta da mesma maneira que a inicialização de cópia regular; ele considerou somente a conversão de construtores para a resolução de sobrecarga.

```cpp
struct A {
    explicit A(int) {}
};

struct B {
    B(int) {}
};

void f(const A&) {}
void f(const B&) {}

int main()
{
    f({ 1 }); // error C2668: 'f': ambiguous call to overloaded function
}
```