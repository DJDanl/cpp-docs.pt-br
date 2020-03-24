---
title: Erro do compilador C2668
ms.date: 03/28/2017
f1_keywords:
- C2668
helpviewer_keywords:
- C2668
ms.assetid: 041e9627-1c76-420e-a653-cfc83f933bd3
ms.openlocfilehash: f59cb33bed15847ed1a7a2dbe99ea030babf3337
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177151"
---
# <a name="compiler-error-c2668"></a>Erro do compilador C2668

' function ': chamada ambígua para função sobrecarregada

Não foi possível resolver a chamada de função sobrecarregada especificada. Talvez você queira converter explicitamente um ou mais dos parâmetros reais.

Você também pode obter esse erro por meio de uso de modelo. Se, na mesma classe, você tiver uma função de membro regular e uma função de membro de modelo com a mesma assinatura, o modelo um deverá vir primeiro. Essa é uma limitação da implementação atual do Visual C++.

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

Outra maneira de resolver esse erro é com uma [declaração using](../../cpp/using-declaration.md):

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

A conversão em uma conversão usando constante 0 é ambígua, pois int requer uma conversão tanto para Long quanto para void *. Para resolver esse erro, converta 0 para o tipo exato do parâmetro de função que está sendo usado para que nenhuma conversão precise ocorrer (esse código será válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET C++).

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

Esse erro pode ocorrer porque o CRT agora tem formas flutuantes e duplas de todas as funções matemáticas.

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

Esse erro pode ocorrer porque o pow (int, int) foi removido do Math. h no CRT.

```cpp
// C2668e.cpp
#include <math.h>
int main() {
   pow(9,9);   // C2668
   pow((double)9,9);   // OK
}
```

## <a name="example"></a>Exemplo

Esse código tem êxito no Visual Studio 2015, mas falha no Visual Studio 2017 e posterior com C2668. No Visual Studio 2015, o compilador tratou a inicialização de lista de cópia de maneira incorreta da mesma maneira que a inicialização de cópia regular; ele considerou somente a conversão de construtores para a resolução de sobrecarga.

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
