---
title: Conversões definidas pelo usuário (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- user-defined conversions [C++]
ms.assetid: 8010fd59-2775-4e9a-a6ed-58055032d66f
ms.openlocfilehash: bb7a30382bc586f4d324d47ef6e6757fac83f5ae
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988383"
---
# <a name="user-defined-conversions-ccli"></a>Conversões definidas pelo usuário (C++/CLI)

Esta seção aborda as conversões definidas pelo usuário (UDC) quando um dos tipos na conversão é uma referência ou instância de um tipo de valor ou tipo de referência.

## <a name="implicit-and-explicit-conversions"></a>Conversões implícitas e explícitas

Uma conversão definida pelo usuário pode ser implícita ou explícita.  Um UDC deve ser implícito se a conversão não resultar em perda de informações. Caso contrário, um UDC explícito deverá ser definido.

Um construtor de classe nativa pode ser usado para converter uma referência ou tipo de valor em uma classe nativa.

Para obter mais informações sobre conversões, consulte [conversões](../cpp/standard-conversions.md) [Boxing](../extensions/boxing-cpp-component-extensions.md) e Standard.

```cpp
// mcpp_User_Defined_Conversions.cpp
// compile with: /clr
#include "stdio.h"
ref class R;
class N;

value class V {
   static operator V(R^) {
      return V();
   }
};

ref class R {
public:
   static operator N(R^);
   static operator V(R^) {
      System::Console::WriteLine("in R::operator N");
      return V();
   }
};

class N {
public:
   N(R^) {
      printf("in N::N\n");
   }
};

R::operator N(R^) {
   System::Console::WriteLine("in R::operator N");
   return N(nullptr);
}

int main() {
   // Direct initialization:
   R ^r2;
   N n2(r2);   // direct initialization, calls constructor
   static_cast<N>(r2);   // also direct initialization

   R ^r3;
   // ambiguous V::operator V(R^) and R::operator V(R^)
   // static_cast<V>(r3);
}
```

**Saída**

```Output
in N::N
in N::N
```

## <a name="convert-from-operators"></a>Converter de operadores

Os operadores de conversão-from criam um objeto da classe na qual o operador é definido de um objeto de alguma outra classe.

Standard C++ não oferece suporte a operadores de conversão-from; o C++ padrão usa construtores para essa finalidade. No entanto, ao usar tipos CLR C++ , o Visual fornece suporte sintático para chamar operadores de conversão-from.

Para interoperar bem com outras linguagens em conformidade com CLS, você pode desejar encapsular cada Construtor unário definido pelo usuário para uma determinada classe com um operador de conversão de correspondente.

Operadores de conversão-from:

- Deve ser definido como funções estáticas.

- Pode ser implícito (para conversões que não perdem precisão, como Short-to-int) ou Explicit, quando pode haver perda de precisão.

- Deve retornar um objeto da classe que o contém.

- Deve ter o tipo "from" como o único tipo de parâmetro.

O exemplo a seguir mostra um operador de conversão definida pelo usuário, implícita e explícita.

```cpp
// clr_udc_convert_from.cpp
// compile with: /clr
value struct MyDouble {
   double d;

   MyDouble(int i) {
      d = static_cast<double>(i);
      System::Console::WriteLine("in constructor");
   }

   // Wrap the constructor with a convert-from operator.
   // implicit UDC because conversion cannot lose precision
   static operator MyDouble (int i) {
      System::Console::WriteLine("in operator");
      // call the constructor
      MyDouble d(i);
      return d;
   }

   // an explicit user-defined conversion operator
   static explicit operator signed short int (MyDouble) {
      return 1;
   }
};

int main() {
   int i = 10;
   MyDouble md = i;
   System::Console::WriteLine(md.d);

   // using explicit user-defined conversion operator requires a cast
   unsigned short int j = static_cast<unsigned short int>(md);
   System::Console::WriteLine(j);
}
```

**Saída**

```Output
in operator
in constructor
10
1
```

## <a name="convert-to-operators"></a>Operadores de conversão para

Os operadores Convert-to convertem um objeto da classe na qual o operador é definido como algum outro objeto. O exemplo a seguir mostra um operador de conversão implícita, Convert-to, definido pelo usuário:

```cpp
// clr_udc_convert_to.cpp
// compile with: /clr
using namespace System;
value struct MyInt {
   Int32 i;

   // convert MyInt to String^
   static operator String^ ( MyInt val ) {
      return val.i.ToString();
   }

   MyInt(int _i) : i(_i) {}
};

int main() {
   MyInt mi(10);
   String ^s = mi;
   Console::WriteLine(s);
}
```

**Saída**

```Output
10
```

Um operador de conversão explícita definido pelo usuário explícito é apropriado para conversões que potencialmente perdem dados de alguma maneira. Para invocar um operador Convert-to explícito, uma conversão deve ser usada.

```cpp
// clr_udc_convert_to_2.cpp
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
   d.d = 10.3;
   System::Console::WriteLine(d.d);
   int i = 0;
   i = static_cast<int>(d);
   System::Console::WriteLine(i);
}
```

**Saída**

```Output
10.3
10
```

## <a name="to-convert-generic-classes"></a>Para converter classes genéricas

Você pode converter uma classe genérica em T.

```cpp
// clr_udc_generics.cpp
// compile with: /clr
generic<class T>
public value struct V {
   T mem;
   static operator T(V v) {
      return v.mem;
   }

   void f(T t) {
      mem = t;
   }
};

int main() {
   V<int> v;
   v.f(42);
   int i = v;
   i += v;
   System::Console::WriteLine(i == (42 * 2) );
}
```

**Saída**

```Output
True
```

Um construtor de conversão usa um tipo e o usa para criar um objeto.  Um construtor de conversão é chamado somente com inicialização direta; as conversões não invocarão os construtores de conversão. Por padrão, os construtores de conversão são explícitos para tipos CLR.

```cpp
// clr_udc_converting_constructors.cpp
// compile with: /clr
public ref struct R {
   int m;
   char c;

   R(int i) : m(i) { }
   R(char j) : c(j) { }
};

public value struct V {
   R^ ptr;
   int m;

   V(R^ r) : ptr(r) { }
   V(int i) : m(i) { }
};

int main() {
   R^ r = gcnew R(5);

   System::Console::WriteLine( V(5).m);
   System::Console::WriteLine( V(r).ptr);
}
```

**Saída**

```Output
5
R
```

Neste exemplo de código, uma função de conversão estática implícita faz a mesma coisa que um construtor de conversão explícito.

```
public value struct V {
   int m;
   V(int i) : m(i) {}
   static operator V(int i) {
      V v(i*100);
      return v;
   }
};

public ref struct R {
   int m;
   R(int i) : m(i) {}
   static operator R^(int i) {
      return gcnew R(i*100);
   }
};

int main() {
   V v(13);   // explicit
   R^ r = gcnew R(12);   // explicit

   System::Console::WriteLine(v.m);
   System::Console::WriteLine(r->m);

   // explicit ctor can't be called here: not ambiguous
   v = 5;
   r = 20;

   System::Console::WriteLine(v.m);
   System::Console::WriteLine(r->m);
}
```

**Saída**

```Output
13
12
500
2000
```

## <a name="see-also"></a>Consulte também

[Classes e Structs](../extensions/classes-and-structs-cpp-component-extensions.md)
