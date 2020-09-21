---
title: Erro do compilador C2440
ms.date: 03/28/2017
f1_keywords:
- C2440
helpviewer_keywords:
- C2440
ms.assetid: 36e6676c-f04f-4715-8ba1-f096c4bf3b44
ms.openlocfilehash: 74c5032338b3f4cf30bdb75bdf070cee7b67ce58
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742106"
---
# <a name="compiler-error-c2440"></a>Erro do compilador C2440

' Conversion ': não é possível converter de ' type1 ' em ' type2 '

O compilador não pode converter de `type1` para `type2` .

C2440 pode ser causado se você tentar inicializar um não const **`char*`** (ou `wchar_t*` ) usando um literal de cadeia de caracteres no código C++, quando a opção de conformidade do compilador [/Zc: strictStrings](../../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) estiver definida. Em C, o tipo de um literal de cadeia de caracteres é matriz de **`char`** , mas em C++, é uma matriz de `const char` .

## <a name="examples"></a>Exemplos

Este exemplo gera C2440:

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

C2440 também pode ser causado se você tentar converter um ponteiro para membro para void *. O próximo exemplo gera C2440:

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

C2440 também pode ser causado se você tentar converter de um tipo que só está em frente, mas não definido. Este exemplo gera C2440:

```cpp
// c2440a.cpp
struct Base { }; // Defined

struct Derived; // Forward declaration, not defined

Base * func(Derived * d) {
    return static_cast<Base *>(d); // error C2440: 'static_cast' : cannot convert from 'Derived *' to 'Base *'
}
```

Os erros de C2440 nas linhas 15 e 16 do exemplo a seguir são qualificados com a `Incompatible calling conventions for UDT return value` mensagem. Um *UDT* é um tipo definido pelo usuário, como uma classe, struct ou Union. Esses tipos de erros de incompatibilidade são causados quando a Convenção de chamada de um UDT especificado no tipo de retorno de uma declaração de encaminhamento está em conflito com a Convenção de chamada real do UDT e quando um ponteiro de função está envolvido.

No exemplo, primeiro há declarações de encaminhamento para uma struct e para uma função que retorna a estrutura; o compilador pressupõe que a estrutura usa a Convenção de chamada C++. Em seguida, está a definição de struct, que, por padrão, usa a Convenção de chamada C. Como o compilador não conhece a Convenção de chamada da estrutura até que ela termine de ler a estrutura inteira, a Convenção de chamada para a estrutura no tipo de retorno de `get_c2` também é considerada C++.

A struct é seguida por outra declaração de função que retorna a struct, mas neste ponto, o compilador sabe que a Convenção de chamada da struct é C++. Da mesma forma, o ponteiro de função, que retorna a struct, é definido após a definição de struct para que o compilador saiba que o struct usa a Convenção de chamada C++.

Para resolver o C2440 que ocorre devido a convenções de chamada incompatíveis, declare as funções que retornam um UDT após a definição de UDT.

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

C2440 também pode ocorrer se você atribuir zero a um ponteiro interior:

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

C2440 também pode ocorrer para um uso incorreto de uma conversão definida pelo usuário. Por exemplo, quando um operador de conversão tiver sido definido como **`explicit`** , o compilador não poderá usá-lo em uma conversão implícita. Para obter mais informações sobre conversões definidas pelo usuário, consulte [conversões definidas pelo usuário (C++/CLI)](../../dotnet/user-defined-conversions-cpp-cli.md)). Este exemplo gera C2440:

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

C2440 também pode ocorrer se você tentar criar uma instância de uma matriz de Visual C++ cujo tipo é um <xref:System.Array> .  Saiba mais em [Matrizes](../../extensions/arrays-cpp-component-extensions.md).  O próximo exemplo gera C2440:

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

C2440 também pode ocorrer devido a alterações no recurso de atributos.  O exemplo a seguir gera C2440.

```cpp
// c2440f.cpp
// compile with: /LD
[ module(name="PropDemoLib", version=1.0) ];   // C2440
// try the following line instead
// [ module(name="PropDemoLib", version="1.0") ];
```

O compilador do Microsoft C++ não permite mais que o [operador de const_cast](../../cpp/const-cast-operator.md) a converta quando o código-fonte que usa a programação **/CLR** é compilado.

Para resolver esse C2440, use o operador cast correto. Para obter mais informações, consulte [converter operadores](../../cpp/casting-operators.md).

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

C2440 pode ocorrer devido a alterações de conformidade para o compilador no Visual Studio 2015 atualização 3. Anteriormente, o compilador incorretamente tratava determinadas expressões distintas como o mesmo tipo ao identificar uma correspondência de modelo para uma **`static_cast`** operação. Agora, o compilador distingue os tipos corretamente, e o código que dependia do **`static_cast`** comportamento anterior é rompido. Para corrigir esse problema, altere o argumento de modelo para corresponder ao tipo de parâmetro de modelo ou use uma **`reinterpret_cast`** conversão C-Style.

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

### <a name="copy-list-initialization"></a>Inicialização de lista de cópia

O Visual Studio 2017 e posterior gera corretamente erros de compilador relacionados à criação de objetos usando listas de inicializadores que não foram capturadas no Visual Studio 2015 e podem levar a falhas ou a um comportamento de tempo de execução indefinido. Em C++ 17 Copy-List-Initialization, o compilador é necessário para considerar um construtor explícito para resolução de sobrecarga, mas deve gerar um erro se essa sobrecarga for realmente escolhida.

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

### <a name="cv-qualifiers-in-class-construction"></a>Qualificadores CV na construção de classe

No Visual Studio 2015, às vezes, o compilador ignora incorretamente o qualificador CV ao gerar um objeto de classe por meio de uma chamada do construtor. Eventualmente, isso pode gerar uma falha ou comportamento inesperado do runtime. O exemplo a seguir é compilado no Visual Studio 2015, mas gera um erro do compilador no Visual Studio 2017 e posterior:

```cpp
struct S
{
    S(int);
    operator int();
};

int i = (const S)0; // error C2440
```

Para corrigir o erro, declare o operador int() como const.
