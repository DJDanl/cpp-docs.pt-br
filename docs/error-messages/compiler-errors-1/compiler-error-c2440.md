---
title: Erro do compilador C2440
ms.date: 03/28/2017
f1_keywords:
- C2440
helpviewer_keywords:
- C2440
ms.assetid: 36e6676c-f04f-4715-8ba1-f096c4bf3b44
ms.openlocfilehash: c85a8284c91037e981f0d1ea82507b49be8121a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338929"
---
# <a name="compiler-error-c2440"></a>Erro do compilador C2440

'conversion': não é possível converter de 'type1' em 'type2'

O compilador não pode ser convertido de `type1` para `type2`.

## <a name="example"></a>Exemplo

O C2440 pode ser causado se você tentar inicializar não const `char*` (ou `wchar_t*`) por meio de uma cadeia de caracteres literal no código C++, quando a opção de conformidade do compilador [/ZC: strictstrings](../../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) está definido. Em C, o tipo de um literal de cadeia de caracteres é matriz de `char`, mas em C++, é matriz de `const char`. Este exemplo gera C2440:

```cpp
// C2440s.cpp
// Build: cl /Zc:strictStrings /W3 C2440s.cpp
// When built, the compiler emits:
// error C2440: 'initializing' : cannot convert from 'const char [5]'
// to 'char *'
//        Conversion from string literal loses const qualifier (see
// /Zc:strictStrings)

int main() {
   char* s1 = "test"; // C2440
   const char* s2 = "tests"; // OK
}
```

## <a name="example"></a>Exemplo

O C2440 também pode ser causado se você tentar converter um ponteiro para membro para void *. O exemplo a seguir produz C2440:

```cpp
// C2440.cpp
class B {
public:
   void  f(){;}

   typedef void (B::*pf)();

   void f2(pf pf) {
       (this->*pf)();
       void* pp = (void*)pf;   // C2440
   }

   void f3() {
      f2(f);
   }
};
```

## <a name="example"></a>Exemplo

O C2440 também pode ser causado se você tentar converter de um tipo que é somente declarado encaminhado mas não definido. Este exemplo gera C2440:

```cpp
// c2440a.cpp
struct Base { }; // Defined

struct Derived; // Forward declaration, not defined

Base * func(Derived * d) {
    return static_cast<Base *>(d); // error C2440: 'static_cast' : cannot convert from 'Derived *' to 'Base *'
}
```

## <a name="example"></a>Exemplo

Os erros C2440 nas linhas 15 e 16 do exemplo a seguir estão qualificados com o `Incompatible calling conventions for UDT return value` mensagem. Um *UDT* é um tipo definido pelo usuário, como uma classe, struct ou união. Esses tipos de erros de incompatibilidade são causados quando a convenção de chamada de um UDT especificado no tipo de retorno de uma declaração de encaminhamento conflita com a convenção de chamada real do UDT e quando um ponteiro de função está envolvido.

No exemplo, primeiro há declarações de encaminhamento para um struct em uma função que retorna a estrutura; o compilador pressupõe que a estrutura usa a convenção de chamada de C++. Em seguida é a definição de struct, que, por padrão, usa o C convenção de chamada. Porque o compilador não sabe a convenção de chamada de estrutura até que ele termine de ler todo o struct, a convenção de chamada da estrutura no tipo de retorno de `get_c2` também é considerada como sendo C++.

A estrutura é seguida por outra declaração de função que retorna a estrutura, mas neste ponto, o compilador sabe que a convenção de chamada do struct é C++. Da mesma forma, o ponteiro de função, que retorna o struct, é definido após a definição da estrutura, de modo que o compilador sabe que a estrutura usa a convenção de chamada de C++.

Para resolver C2440 que ocorre devido as convenções de chamada incompatíveis, declare as funções que retornam UDT após a definição de UDT.

```cpp
// C2440b.cpp
struct MyStruct;

MyStruct get_c1();

struct MyStruct {
   int i;
   static MyStruct get_C2();
};

MyStruct get_C3();

typedef MyStruct (*FC)();

FC fc1 = &get_c1;   // C2440, line 15
FC fc2 = &MyStruct::get_C2;   // C2440, line 16
FC fc3 = &get_C3;

class CMyClass {
public:
   explicit CMyClass( int iBar)
      throw()   {
   }

   static CMyClass get_c2();
};

int main() {
   CMyClass myclass = 2;   // C2440
   // try one of the following
   // CMyClass myclass{2};
   // CMyClass myclass(2);

   int *i;
   float j;
   j = (float)i;   // C2440, cannot cast from pointer to int to float
}
```

## <a name="example"></a>Exemplo

O C2440 também pode ocorrer se você atribuir zero a um ponteiro interior:

```cpp
// C2440c.cpp
// compile with: /clr
int main() {
   array<int>^ arr = gcnew array<int>(100);
   interior_ptr<int> ipi = &arr[0];
   ipi = 0;   // C2440
   ipi = nullptr;   // OK
}
```

## <a name="example"></a>Exemplo

O C2440 também pode ocorrer para um uso incorreto de uma conversão definida pelo usuário. Por exemplo, quando um operador de conversão foi definido como `explicit`, o compilador não pode usá-lo em uma conversão implícita. Para obter mais informações sobre conversões definidas pelo usuário, consulte [conversões definidas pelo usuário (C++/CLI)](../../dotnet/user-defined-conversions-cpp-cli.md)). Este exemplo gera C2440:

```cpp
// C2440d.cpp
// compile with: /clr
value struct MyDouble {
   double d;
   // convert MyDouble to Int32
   static explicit operator System::Int32 ( MyDouble val ) {
      return (int)val.d;
   }
};

int main() {
   MyDouble d;
   int i;
   i = d;   // C2440
   // Uncomment the following line to resolve.
   // i = static_cast<int>(d);
}
```

## <a name="example"></a>Exemplo

O C2440 também pode ocorrer se você tentar criar uma instância de uma matriz do Visual C++ cujo tipo é um <xref:System.Array>.  Para obter mais informações, consulte [matrizes](../../extensions/arrays-cpp-component-extensions.md).  O exemplo a seguir produz C2440:

```cpp
// C2440e.cpp
// compile with: /clr
using namespace System;
int main() {
   array<int>^ intArray = Array::CreateInstance(__typeof(int), 1);   // C2440
   // try the following line instead
   // array<int>^ intArray = safe_cast<array<int> ^>(Array::CreateInstance(__typeof(int), 1));
}
```

## <a name="example"></a>Exemplo

O C2440 também pode ocorrer devido a alterações no recurso de atributos.  O exemplo a seguir produz C2440.

```cpp
// c2440f.cpp
// compile with: /LD
[ module(name="PropDemoLib", version=1.0) ];   // C2440
// try the following line instead
// [ module(name="PropDemoLib", version="1.0") ];
```

## <a name="example"></a>Exemplo

O Visual C++ compilador não permite mais que o [operador const_cast](../../cpp/const-cast-operator.md) downcast quando código-fonte que usa **/clr** programação é compilada.

Para resolver esse C2440, use o operador de conversão correto. Para obter mais informações, consulte [operadores de conversão](../../cpp/casting-operators.md).

Este exemplo gera C2440:

```cpp
// c2440g.cpp
// compile with: /clr
ref class Base {};
ref class Derived : public Base {};
int main() {
   Derived ^d = gcnew Derived;
   Base ^b = d;
   d = const_cast<Derived^>(b);   // C2440
   d = dynamic_cast<Derived^>(b);   // OK
}
```

## <a name="example"></a>Exemplo

O C2440 pode ocorrer devido a alterações de conformidade para o compilador no Visual Studio 2015 atualização 3. Anteriormente, o compilador incorretamente consideradas determinadas expressões distintas do mesmo tipo ao identificar uma correspondência de modelo para um `static_cast` operação. Agora, o compilador distingue os tipos corretamente e de código que contavam com anterior `static_cast` comportamento é interrompido. Para corrigir esse problema, altere o argumento de modelo para corresponder ao tipo de parâmetro de modelo, ou usar um `reinterpret_cast` ou conversão C-style.

Este exemplo gera C2440:

```cpp
// c2440h.cpp

template<int *a>
struct S1 {};

int g;
struct S2 : S1<&g> {
};

int main()
{
    S2 s;
    static_cast<S1<&*&g>>(s); // C2440 in VS 2015 Update 3
    // This compiles correctly:
    // static_cast<S1<&g>>(s);
}

This error can appear in ATL code that uses the SINK_ENTRY_INFO macro defined in <atlcom.h>.
```

## <a name="example"></a>Exemplo

### <a name="copy-list-initialization"></a>Inicialização de lista de cópia

Visual Studio 2017 e posterior corretamente gerarão erros de compilador relacionados à criação de objetos usando listas de inicializador que não foram detectadas no Visual Studio 2015 e podem causar falhas ou comportamento de tempo de execução indefinido. No C + + 17 copy-list-initialization, o compilador deverá considerar um construtor explícito para resolução de sobrecarga, mas deverá gerar um erro se essa sobrecarga for realmente escolhida.

O exemplo a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017.

```cpp
// C2440j.cpp
struct A
{
    explicit A(int) {}
    A(double) {}
};

int main()
{
    const A& a2 = { 1 }; // error C2440: 'initializing': cannot
                         // convert from 'int' to 'const A &'
}
```

Para corrigir o erro, use a inicialização direta:

```cpp
// C2440k.cpp
struct A
{
    explicit A(int) {}
    A(double) {}
};

int main()
{
    const A& a2{ 1 };
}
```

## <a name="example"></a>Exemplo

### <a name="cv-qualifiers-in-class-construction"></a>Qualificadores CV na construção de classe

No Visual Studio 2015, às vezes, o compilador ignora incorretamente o qualificador CV ao gerar um objeto de classe por meio de uma chamada do construtor. Eventualmente, isso pode gerar uma falha ou comportamento inesperado do tempo de execução. O exemplo a seguir é compilado no Visual Studio 2015, mas gera um erro do compilador no Visual Studio 2017 e posterior:

```cpp
struct S
{
    S(int);
    operator int();
};

int i = (const S)0; // error C2440
```

Para corrigir o erro, declare o operador int() como const.
