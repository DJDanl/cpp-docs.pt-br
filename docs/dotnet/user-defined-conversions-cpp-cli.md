---
title: Conversões definidas pelo usuário (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- user-defined conversions [C++]
ms.assetid: 8010fd59-2775-4e9a-a6ed-58055032d66f
ms.openlocfilehash: 8f168582e56e77f1ec848928b7ffd36879ba341a
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58772417"
---
# <a name="user-defined-conversions-ccli"></a>Conversões definidas pelo usuário (C++/CLI)

Esta seção discute as conversões definidas pelo usuário (UDC) quando um dos tipos na conversão é uma instância de um tipo de referência ou tipo de valor ou referência.

## <a name="implicit-and-explicit-conversions"></a>Conversões implícitas e explícitas

Uma conversão definida pelo usuário pode ser implícitas ou explícitas.  Um UDC deve ser implícito se a conversão não resulta na perda de informações. Caso contrário, um UDC explícita deve ser definida.

Construtor da classe um nativo pode ser usado para converter um tipo de valor ou referência a uma classe nativa.

Para obter mais informações sobre conversões, consulte [conversão Boxing](../extensions/boxing-cpp-component-extensions.md) e [conversões padrão](../cpp/standard-conversions.md).

```
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

Converter de operadores criar um objeto da classe na qual o operador está definido de um objeto de alguma outra classe.

C++ padrão não dá suporte a operadores convert-from; C++ padrão usa os construtores para essa finalidade. No entanto, ao usar tipos CLR, Visual C++ dão suporte sintático para converter de operadores de chamada.

Para interoperar com outras linguagens compatíveis com CLS, talvez você queira encapsular cada construtor unário definido pelo usuário para uma determinada classe com um operador de conversão de correspondente.

Operadores Convert-from:

- Deve ser definido como funções estáticas.

- Qualquer um pode ser implícita (para as conversões que não perderá precisão como short-int) ou explícita, quando pode haver uma perda de precisão.

- Deve retornar um objeto da classe recipiente.

- Deve ter o tipo "de" como o tipo de parâmetro exclusivo.

O exemplo a seguir mostra um implícita e explícita "convert-from", o operador de conversão definida pelo usuário (UDC).

```
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

## <a name="convert-to-operators"></a>Converter em operadores

Operadores Convert para converter um objeto da classe na qual o operador está definido para algum outro objeto. O exemplo a seguir mostra um implícita, convert-to, o operador de conversão definida pelo usuário:

```
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

Um operador de conversão explícitas definidas pelo usuário convert-to é apropriado para as conversões que o risco de perder dados de alguma forma. Para invocar um operador para convert explícito, uma conversão deve ser usada.

```
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

Você pode converter uma classe genérica para T.

```
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

Um construtor de conversão usa um tipo e usa-o para criar um objeto.  Um construtor de conversão é chamado com a inicialização direta apenas; conversões não irá chamar construtores de conversão. Por padrão, construtores de conversão são explícitos para tipos de CLR.

```
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

No exemplo de código, uma função de conversão implícita de estática faz a mesma coisa que um construtor de conversão explícita.

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
