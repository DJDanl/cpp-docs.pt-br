---
title: Como definir e consumir classes e estruturas (C++/CLI)
ms.date: 09/12/2018
helpviewer_keywords:
- structs [C++]
- classes [C++], instantiating
ms.assetid: 1c03cb0d-1459-4b5e-af65-97d6b3094fd7
ms.openlocfilehash: 5bec92ce2bd97f11723cdf59c58b7331b39565f2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370190"
---
# <a name="how-to-define-and-consume-classes-and-structs-ccli"></a>Como definir e consumir classes e estruturas (C++/CLI)

Este artigo mostra como definir e consumir tipos de referência e tipos de valor definidos pelo usuário em C++/CLI.

## <a name="contents"></a><a name="BKMK_Contents"></a>Conteúdo

[Instantiva de objetos](#BKMK_Object_instantiation)

[Classes implicitamente abstratas](#BKMK_Implicitly_abstract_classes)

[Visibilidade do tipo](#BKMK_Type_visibility)

[Visibilidade dos membros](#BKMK_Member_visibility)

[Aulas nativas públicas e privadas](#BKMK_Public_and_private_native_classes)

[Construtores estáticos](#BKMK_Static_constructors)

[Semântica deste ponteiro](#BKMK_Semantics_of_the_this_pointer)

[Funções de ocultação por assinatura](#BKMK_Hide_by_signature_functions)

[Construtores de cópia](#BKMK_Copy_constructors)

[Destruidores e finalizadores](#BKMK_Destructors_and_finalizers)

## <a name="object-instantiation"></a><a name="BKMK_Object_instantiation"></a>Instantiva de objetos

Os tipos de referência (ref) só podem ser instanciados no heap gerenciado, não na pilha ou no heap nativo. Os tipos de valor podem ser instanciados na pilha ou no heap gerenciado.

```cpp
// mcppv2_ref_class2.cpp
// compile with: /clr
ref class MyClass {
public:
   int i;

   // nested class
   ref class MyClass2 {
   public:
      int i;
   };

   // nested interface
   interface struct MyInterface {
      void f();
   };
};

ref class MyClass2 : public MyClass::MyInterface {
public:
   virtual void f() {
      System::Console::WriteLine("test");
   }
};

public value struct MyStruct {
   void f() {
      System::Console::WriteLine("test");
   }
};

int main() {
   // instantiate ref type on garbage-collected heap
   MyClass ^ p_MyClass = gcnew MyClass;
   p_MyClass -> i = 4;

   // instantiate value type on garbage-collected heap
   MyStruct ^ p_MyStruct = gcnew MyStruct;
   p_MyStruct -> f();

   // instantiate value type on the stack
   MyStruct p_MyStruct2;
   p_MyStruct2.f();

   // instantiate nested ref type on garbage-collected heap
   MyClass::MyClass2 ^ p_MyClass2 = gcnew MyClass::MyClass2;
   p_MyClass2 -> i = 5;
}
```

## <a name="implicitly-abstract-classes"></a><a name="BKMK_Implicitly_abstract_classes"></a>Classes implicitamente abstratas

Uma *classe implicitamente abstrata* não pode ser instanciada. Uma classe é implicitamente abstrata se o tipo base da classe for uma interface e a classe não implementar todas as funções de membro da interface.

Se você é incapaz de construir objetos de uma classe derivada de uma interface, a razão pode ser que a classe é implicitamente abstrata. Para obter mais informações sobre classes abstratas, consulte [resumo](../extensions/abstract-cpp-component-extensions.md).

O exemplo de código `MyClass` a seguir demonstra que `MyClass::func2` a classe não pode ser instanciada porque a função não é implementada. Para habilitar o exemplo para `MyClass::func2`compilar, não comentar .

```cpp
// mcppv2_ref_class5.cpp
// compile with: /clr
interface struct MyInterface {
   void func1();
   void func2();
};

ref class MyClass : public MyInterface {
public:
   void func1(){}
   // void func2(){}
};

int main() {
   MyClass ^ h_MyClass = gcnew MyClass;   // C2259
                                          // To resolve, uncomment MyClass::func2.
}
```

## <a name="type-visibility"></a><a name="BKMK_Type_visibility"></a>Visibilidade do tipo

Você pode controlar a visibilidade dos tipos de tempo de execução de linguagem comum (CLR) de modo que, se um conjunto for referenciado, os tipos no conjunto possam ser visíveis ou não visíveis fora do conjunto.

`public`indica que um tipo é visível para `#using` qualquer arquivo de origem que contenha uma diretiva para o conjunto que contenha o tipo.  `private`indica que um tipo não é visível `#using` para arquivos de origem que contêm uma diretiva para o conjunto que contém o tipo. No entanto, tipos privados são visíveis dentro do mesmo conjunto. Por padrão, a visibilidade para `private`uma classe é .

Por padrão antes do Visual Studio 2005, os tipos nativos tinham acessibilidade pública fora da montagem. Habilite [o aviso do compilador (nível 1) C4692](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) para ajudá-lo a ver onde os tipos nativos privados são usados incorretamente. Use o [make_public](../preprocessor/make-public.md) pragma para dar acessibilidade pública a um tipo nativo em um arquivo de código fonte que você não pode modificar.

Para obter mais informações, confira [Diretiva #using](../preprocessor/hash-using-directive-cpp.md).

A amostra a seguir mostra como declarar tipos e especificar sua acessibilidade e, em seguida, acessar esses tipos dentro do conjunto. Claro, se uma montagem que tenha tipos `#using`privados é referenciada usando, apenas tipos públicos na montagem são visíveis.

```cpp
// type_visibility.cpp
// compile with: /clr
using namespace System;
// public type, visible inside and outside assembly
public ref struct Public_Class {
   void Test(){Console::WriteLine("in Public_Class");}
};

// private type, visible inside but not outside assembly
private ref struct Private_Class {
   void Test(){Console::WriteLine("in Private_Class");}
};

// default accessibility is private
ref class Private_Class_2 {
public:
   void Test(){Console::WriteLine("in Private_Class_2");}
};

int main() {
   Public_Class ^ a = gcnew Public_Class;
   a->Test();

   Private_Class ^ b = gcnew Private_Class;
   b->Test();

   Private_Class_2 ^ c = gcnew Private_Class_2;
   c->Test();
}
```

**Saída**

```Output
in Public_Class
in Private_Class
in Private_Class_2
```

Agora, vamos reescrever a amostra anterior para que ela seja construída como um DLL.

```cpp
// type_visibility_2.cpp
// compile with: /clr /LD
using namespace System;
// public type, visible inside and outside the assembly
public ref struct Public_Class {
   void Test(){Console::WriteLine("in Public_Class");}
};

// private type, visible inside but not outside the assembly
private ref struct Private_Class {
   void Test(){Console::WriteLine("in Private_Class");}
};

// by default, accessibility is private
ref class Private_Class_2 {
public:
   void Test(){Console::WriteLine("in Private_Class_2");}
};
```

A próxima amostra mostra como acessar tipos fora do conjunto. Nesta amostra, o cliente consome o componente que é construído na amostra anterior.

```cpp
// type_visibility_3.cpp
// compile with: /clr
#using "type_visibility_2.dll"
int main() {
   Public_Class ^ a = gcnew Public_Class;
   a->Test();

   // private types not accessible outside the assembly
   // Private_Class ^ b = gcnew Private_Class;
   // Private_Class_2 ^ c = gcnew Private_Class_2;
}
```

**Saída**

```Output
in Public_Class
```

## <a name="member-visibility"></a><a name="BKMK_Member_visibility"></a>Visibilidade dos membros

Você pode fazer acesso a um membro de uma classe pública de dentro da mesma assembléia diferente do `public` `protected`acesso a ele de fora da montagem usando pares dos especificadores de acesso , e`private`

Esta tabela resume o efeito dos vários especificadores de acesso:

|Especificador|Efeito|
|---------------|------------|
|públicos|O membro é acessível dentro e fora da assembléia.  Consulte [o público](../cpp/public-cpp.md) para obter mais informações.|
|particulares|O membro não é acessível, nem dentro nem fora da assembléia.  Consulte [o private](../cpp/private-cpp.md) para obter mais informações.|
|protegidos|O membro é acessível dentro e fora da montagem, mas apenas para tipos derivados.  Consulte [protegidos](../cpp/protected-cpp.md) para obter mais informações.|
|interno|O membro é público dentro da assembléia, mas privado fora da assembléia.  `internal`é uma palavra-chave sensível ao contexto.  Saiba mais em [Palavras-chave contextuais](../extensions/context-sensitive-keywords-cpp-component-extensions.md).|
|público protegido -ou- público protegido|O membro é público dentro da assembléia, mas protegido fora da assembléia.|
|privado protegido - ou - privado protegido|O membro é protegido dentro da assembléia, mas privado fora da assembléia.|

A amostra a seguir mostra um tipo público que tem membros que são declarados com as diferentes acessibilidades e, em seguida, mostra o acesso desses membros de dentro da assembléia.

```cpp
// compile with: /clr
using namespace System;
// public type, visible inside and outside the assembly
public ref class Public_Class {
public:
   void Public_Function(){System::Console::WriteLine("in Public_Function");}

private:
   void Private_Function(){System::Console::WriteLine("in Private_Function");}

protected:
   void Protected_Function(){System::Console::WriteLine("in Protected_Function");}

internal:
   void Internal_Function(){System::Console::WriteLine("in Internal_Function");}

protected public:
   void Protected_Public_Function(){System::Console::WriteLine("in Protected_Public_Function");}

public protected:
   void Public_Protected_Function(){System::Console::WriteLine("in Public_Protected_Function");}

private protected:
   void Private_Protected_Function(){System::Console::WriteLine("in Private_Protected_Function");}

protected private:
   void Protected_Private_Function(){System::Console::WriteLine("in Protected_Private_Function");}
};

// a derived type, calls protected functions
ref struct MyClass : public Public_Class {
   void Test() {
      Console::WriteLine("=======================");
      Console::WriteLine("in function of derived class");
      Protected_Function();
      Protected_Private_Function();
      Private_Protected_Function();
      Console::WriteLine("exiting function of derived class");
      Console::WriteLine("=======================");
   }
};

int main() {
   Public_Class ^ a = gcnew Public_Class;
   MyClass ^ b = gcnew MyClass;
   a->Public_Function();
   a->Protected_Public_Function();
   a->Public_Protected_Function();

   // accessible inside but not outside the assembly
   a->Internal_Function();

   // call protected functions
   b->Test();

   // not accessible inside or outside the assembly
   // a->Private_Function();
}
```

**Saída**

```Output
in Public_Function
in Protected_Public_Function
in Public_Protected_Function
in Internal_Function
=======================
in function of derived class
in Protected_Function
in Protected_Private_Function
in Private_Protected_Function
exiting function of derived class
=======================
```

Agora vamos construir a amostra anterior como um DLL.

```cpp
// compile with: /clr /LD
using namespace System;
// public type, visible inside and outside the assembly
public ref class Public_Class {
public:
   void Public_Function(){System::Console::WriteLine("in Public_Function");}

private:
   void Private_Function(){System::Console::WriteLine("in Private_Function");}

protected:
   void Protected_Function(){System::Console::WriteLine("in Protected_Function");}

internal:
   void Internal_Function(){System::Console::WriteLine("in Internal_Function");}

protected public:
   void Protected_Public_Function(){System::Console::WriteLine("in Protected_Public_Function");}

public protected:
   void Public_Protected_Function(){System::Console::WriteLine("in Public_Protected_Function");}

private protected:
   void Private_Protected_Function(){System::Console::WriteLine("in Private_Protected_Function");}

protected private:
   void Protected_Private_Function(){System::Console::WriteLine("in Protected_Private_Function");}
};

// a derived type, calls protected functions
ref struct MyClass : public Public_Class {
   void Test() {
      Console::WriteLine("=======================");
      Console::WriteLine("in function of derived class");
      Protected_Function();
      Protected_Private_Function();
      Private_Protected_Function();
      Console::WriteLine("exiting function of derived class");
      Console::WriteLine("=======================");
   }
};
```

A amostra a seguir consome o componente criado na amostra anterior e, assim, mostra como acessar os membros de fora da montagem.

```cpp
// compile with: /clr
#using "type_member_visibility_2.dll"
using namespace System;
// a derived type, calls protected functions
ref struct MyClass : public Public_Class {
   void Test() {
      Console::WriteLine("=======================");
      Console::WriteLine("in function of derived class");
      Protected_Function();
      Protected_Public_Function();
      Public_Protected_Function();
      Console::WriteLine("exiting function of derived class");
      Console::WriteLine("=======================");
   }
};

int main() {
   Public_Class ^ a = gcnew Public_Class;
   MyClass ^ b = gcnew MyClass;
   a->Public_Function();

   // call protected functions
   b->Test();

   // can't be called outside the assembly
   // a->Private_Function();
   // a->Internal_Function();
   // a->Protected_Private_Function();
   // a->Private_Protected_Function();
}
```

**Saída**

```Output
in Public_Function
=======================
in function of derived class
in Protected_Function
in Protected_Public_Function
in Public_Protected_Function
exiting function of derived class
=======================
```

## <a name="public-and-private-native-classes"></a><a name="BKMK_Public_and_private_native_classes"></a>Aulas nativas públicas e privadas

Um tipo nativo pode ser referenciado a partir de um tipo gerenciado.  Por exemplo, uma função em um tipo gerenciado pode tomar um parâmetro cujo tipo é uma estrutura nativa.  Se o tipo e a função gerenciados forem públicos em uma montagem, então o tipo nativo também deve ser público.

```cpp
// native type
public struct N {
   N(){}
   int i;
};
```

Em seguida, crie o arquivo de código-fonte que consome o tipo nativo:

```cpp
// compile with: /clr /LD
#include "mcppv2_ref_class3.h"
// public managed type
public ref struct R {
   // public function that takes a native type
   void f(N nn) {}
};
```

Agora, compile um cliente:

```cpp
// compile with: /clr
#using "mcppv2_ref_class3.dll"

#include "mcppv2_ref_class3.h"

int main() {
   R ^r = gcnew R;
   N n;
   r->f(n);
}
```

## <a name="static-constructors"></a><a name="BKMK_Static_constructors"></a>Construtores estáticos

Um tipo CLR , por exemplo, uma classe ou estruturação , pode ter um construtor estático que pode ser usado para inicializar membros de dados estáticos.  Um construtor estático é chamado no máximo uma vez, e é chamado antes que qualquer membro estático do tipo seja acessado pela primeira vez.

Um construtor de instâncias sempre corre atrás de um construtor estático.

O compilador não pode inforrar uma chamada para um construtor se a classe tiver um construtor estático.  O compilador não pode inforrar uma chamada para qualquer função de membro se a classe for um tipo de valor, tiver um construtor estático e não tiver um construtor de instâncias.  A CLR pode inforrar a chamada, mas o compilador não pode.

Defina um construtor estático como uma função de membro privado, porque ele é destinado a ser chamado apenas pela CLR.

Para obter mais informações sobre construtores estáticos, consulte [Como: Definir um Construtor Estático de Interface (C++/CLI)](../dotnet/how-to-define-an-interface-static-constructor-cpp-cli.md) .

```cpp
// compile with: /clr
using namespace System;

ref class MyClass {
private:
   static int i = 0;

   static MyClass() {
      Console::WriteLine("in static constructor");
      i = 9;
   }

public:
   static void Test() {
      i++;
      Console::WriteLine(i);
   }
};

int main() {
   MyClass::Test();
   MyClass::Test();
}
```

**Saída**

```Output
in static constructor
10
11
```

## <a name="semantics-of-the-this-pointer"></a><a name="BKMK_Semantics_of_the_this_pointer"></a>Semântica deste ponteiro

Quando você está usando o Visual C++ para definir tipos, o `this` ponteiro em um tipo de referência é do tipo "handle". O `this` ponteiro em um tipo de valor é do tipo "ponteiro interior".

Essas diferentes semânticas do `this` ponteiro podem causar comportamento inesperado quando um indexador padrão é chamado. O exemplo seguinte mostra a maneira correta de acessar um indexador padrão tanto em um tipo de árbitro quanto em um tipo de valor.

Para obter mais informações, consulte

- [Operador Handle to Object (^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md)

- [interior_ptr (C++/CLI)](../extensions/interior-ptr-cpp-cli.md)

```cpp
// compile with: /clr
using namespace System;

ref struct A {
   property Double default[Double] {
      Double get(Double data) {
         return data*data;
      }
   }

   A() {
      // accessing default indexer
      Console::WriteLine("{0}", this[3.3]);
   }
};

value struct B {
   property Double default[Double] {
      Double get(Double data) {
         return data*data;
      }
   }
   void Test() {
      // accessing default indexer
      Console::WriteLine("{0}", this->default[3.3]);
   }
};

int main() {
   A ^ mya = gcnew A();
   B ^ myb = gcnew B();
   myb->Test();
}
```

**Saída**

```Output
10.89
10.89
```

## <a name="hide-by-signature-functions"></a><a name="BKMK_Hide_by_signature_functions"></a>Funções de ocultação por assinatura

No C++padrão, uma função em uma classe base é oculta por uma função que tem o mesmo nome em uma classe derivada, mesmo que a função de classe derivada não tenha o mesmo número ou tipo de parâmetros. Isso é chamado de semântica *de ocultação de nome.* Em um tipo de referência, uma função em uma classe base só pode ser ocultada por uma função em uma classe derivada se tanto o nome quanto a lista de parâmetros forem os mesmos. Isso é conhecido como semântica *de esconde-por-assinatura.*

Uma classe é considerada uma classe oculta por assinatura quando todas as `hidebysig`suas funções são marcadas nos metadados como . Por padrão, todas as classes criadas `hidebysig` em **/clr** têm funções. Quando uma `hidebysig` classe tem funções, o compilador não oculta funções por nome em nenhuma classe de base direta, mas se o compilador encontra uma classe oculta por nome em uma cadeia de herança, ele continua esse comportamento de ocultação por nome.

Sob semântica ocultada por assinatura, quando uma função é chamada em um objeto, o compilador identifica a classe mais derivada que contém uma função que poderia satisfazer a chamada de função. Se houver apenas uma função na classe que possa satisfazer a chamada, o compilador chama essa função. Se houver mais de uma função na classe que possa satisfazer a chamada, o compilador usa regras de resolução de sobrecarga para determinar qual função chamar. Para obter mais informações sobre regras de sobrecarga, consulte [Sobrecarga de função](../cpp/function-overloading.md).

Para uma determinada chamada de função, uma função em uma classe base pode ter uma assinatura que a torna uma combinação ligeiramente melhor do que uma função em uma classe derivada. No entanto, se a função foi explicitamente chamada em um objeto da classe derivada, a função na classe derivada é chamada.

Como o valor de retorno não é considerado parte da assinatura de uma função, uma função de classe base é oculta se tiver o mesmo nome e levar o mesmo número e tipo de argumentos como uma função de classe derivada, mesmo que difere no tipo de valor de retorno.

A amostra a seguir mostra que uma função em uma classe base não é oculta por uma função em uma classe derivada.

```cpp
// compile with: /clr
using namespace System;
ref struct Base {
   void Test() {
      Console::WriteLine("Base::Test");
   }
};

ref struct Derived : public Base {
   void Test(int i) {
      Console::WriteLine("Derived::Test");
   }
};

int main() {
   Derived ^ t = gcnew Derived;
   // Test() in the base class will not be hidden
   t->Test();
}
```

**Saída**

```Output
Base::Test
```

A próxima amostra mostra que o compilador Microsoft C++ chama uma função na classe mais derivada — mesmo que uma conversão seja necessária para corresponder a um ou mais dos parâmetros — e não chame uma função em uma classe base que seja melhor compatível com a chamada de função.

```cpp
// compile with: /clr
using namespace System;
ref struct Base {
   void Test2(Single d) {
      Console::WriteLine("Base::Test2");
   }
};

ref struct Derived : public Base {
   void Test2(Double f) {
      Console::WriteLine("Derived::Test2");
   }
};

int main() {
   Derived ^ t = gcnew Derived;
   // Base::Test2 is a better match, but the compiler
   // calls a function in the derived class if possible
   t->Test2(3.14f);
}
```

**Saída**

```Output
Derived::Test2
```

A amostra a seguir mostra que é possível ocultar uma função mesmo que a classe base tenha a mesma assinatura da classe derivada.

```cpp
// compile with: /clr
using namespace System;
ref struct Base {
   int Test4() {
      Console::WriteLine("Base::Test4");
      return 9;
   }
};

ref struct Derived : public Base {
   char Test4() {
      Console::WriteLine("Derived::Test4");
      return 'a';
   }
};

int main() {
   Derived ^ t = gcnew Derived;

   // Base::Test4 is hidden
   int i = t->Test4();
   Console::WriteLine(i);
}
```

**Saída**

```Output
Derived::Test4
97
```

## <a name="copy-constructors"></a><a name="BKMK_Copy_constructors"></a>Copiar construtores

O padrão C++ diz que um construtor de cópiaé quando um objeto é movido, de tal forma que um objeto é criado e destruído no mesmo endereço.

No entanto, quando **/clr** é usado para compilar e uma função que é compilada para o MSIL chama uma função nativa onde uma classe nativa - ou mais de uma - é passada por valor e onde a classe nativa tem um construtor de cópia e/ou destructor, nenhum construtor de cópia é chamado e o objeto é destruído em um endereço diferente do que foi criado. Isso pode causar problemas se a classe tiver um ponteiro em si mesma, ou se o código estiver rastreando objetos por endereço.

Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md).

A amostra a seguir demonstra quando um construtor de cópias não é gerado.

```cpp
// compile with: /clr
#include<stdio.h>

struct S {
   int i;
   static int n;

   S() : i(n++) {
      printf_s("S object %d being constructed, this=%p\n", i, this);
   }

   S(S const& rhs) : i(n++) {
      printf_s("S object %d being copy constructed from S object "
               "%d, this=%p\n", i, rhs.i, this);
   }

   ~S() {
      printf_s("S object %d being destroyed, this=%p\n", i, this);
   }
};

int S::n = 0;

#pragma managed(push,off)
void f(S s1, S s2) {
   printf_s("in function f\n");
}
#pragma managed(pop)

int main() {
   S s;
   S t;
   f(s,t);
}
```

**Saída**

```Output
S object 0 being constructed, this=0018F378
S object 1 being constructed, this=0018F37C
S object 2 being copy constructed from S object 1, this=0018F380
S object 3 being copy constructed from S object 0, this=0018F384
S object 4 being copy constructed from S object 2, this=0018F2E4
S object 2 being destroyed, this=0018F380
S object 5 being copy constructed from S object 3, this=0018F2E0
S object 3 being destroyed, this=0018F384
in function f
S object 5 being destroyed, this=0018F2E0
S object 4 being destroyed, this=0018F2E4
S object 1 being destroyed, this=0018F37C
S object 0 being destroyed, this=0018F378
```

## <a name="destructors-and-finalizers"></a><a name="BKMK_Destructors_and_finalizers"></a>Destruidores e finalizadores

Os destruidores em um tipo de referência realizam uma limpeza determinística dos recursos. Os finalizadores limpam recursos não gerenciados e podem ser chamados determinicamente pelo destruidor ou não determinicamente pelo coletor de lixo. Para obter informações sobre os destruidores no Padrão C++, consulte [Destructors](../cpp/destructors-cpp.md).

```cpp
class classname {
   ~classname() {}   // destructor
   ! classname() {}   // finalizer
};
```

O comportamento dos destruidores em uma classe Visual C++ gerenciada difere das extensões gerenciadas para C++. Para obter mais informações sobre essa mudança, consulte [Alterações na Semântica Destructor](../dotnet/changes-in-destructor-semantics.md).

O coletor de lixo CLR exclui objetos gerenciados não utilizados e libera sua memória quando eles não são mais necessários. No entanto, um tipo pode usar recursos que o coletor de lixo não sabe como liberar. Esses recursos são conhecidos como recursos não gerenciados (alças de arquivo nativas, por exemplo). Recomendamos que você libere todos os recursos não gerenciados no finalizador. Como os recursos gerenciados são liberados de forma não determinista pelo coletor de lixo, não é seguro se referir a recursos gerenciados em um finalizador porque é possível que o coletor de lixo já tenha limpado esse recurso gerenciado.

Um finalizador Visual C++ não <xref:System.Object.Finalize%2A> é o mesmo que o método. (A documentação da CLR usa finalizador e o <xref:System.Object.Finalize%2A> método sinônimo). O <xref:System.Object.Finalize%2A> método é chamado pelo coletor de lixo, que invoca cada finalizador em uma cadeia de herança de classe. Ao contrário dos destructores Visuais C++, uma chamada finalizador de classe derivada não faz com que o compilador invoque o finalizador em todas as classes base.

Como o compilador Microsoft C++ suporta liberação determinística de recursos, não tente implementar ou <xref:System.IDisposable.Dispose%2A> <xref:System.Object.Finalize%2A> métodos. No entanto, se você está familiarizado com esses métodos, veja como um finalizador Visual C++ e <xref:System.IDisposable.Dispose%2A> um destruidor que chama o mapa finalizador para o padrão:

```cpp
// Visual C++ code
ref class T {
   ~T() { this->!T(); }   // destructor calls finalizer
   !T() {}   // finalizer
};

// equivalent to the Dispose pattern
void Dispose(bool disposing) {
   if (disposing) {
      ~T();
   } else {
      !T();
   }
}
```

Um tipo gerenciado também pode usar recursos gerenciados que você prefere liberar determinicamente, e não deixar para o coletor de lixo liberar não determinicamente em algum momento depois que o objeto não é mais necessário. A liberação determinística de recursos pode melhorar significativamente o desempenho.

O compilador Microsoft C++ permite a definição de um destructor para limpar objetos determinicamente. Use o destruidor para liberar todos os recursos que você deseja liberar determinicamente.  Se um finalizador estiver presente, ligue-o do destruidor, para evitar a duplicação do código.

```cpp
// compile with: /clr /c
ref struct A {
   // destructor cleans up all resources
   ~A() {
      // clean up code to release managed resource
      // ...
      // to avoid code duplication,
      // call finalizer to release unmanaged resources
      this->!A();
   }

   // finalizer cleans up unmanaged resources
   // destructor or garbage collector will
   // clean up managed resources
   !A() {
      // clean up code to release unmanaged resources
      // ...
   }
};
```

Se o código que consome seu tipo não chamar o destruidor, o coletor de lixo eventualmente libera todos os recursos gerenciados.

A presença de um destruidor não implica a presença de um finalizador. No entanto, a presença de um finalizador implica que você deve definir um destruidor e chamar o finalizador daquele destruidor. Isso prevê a liberação determinística de recursos não gerenciados.

Chamar o destructor suprime — usando <xref:System.GC.SuppressFinalize%2A>— finalização do objeto. Se o destruidor não for chamado, o finalizador do seu tipo será eventualmente chamado pelo coletor de lixo.

Limpar determinicamente os recursos do seu objeto chamando o destruidor pode melhorar o desempenho em comparação com deixar que a CLR finalize o objeto de forma não determinista.

Código que é escrito no Visual C++ e compilado usando **/clr** executa o destruidor de um tipo se:

- Um objeto criado usando semântica stack sai do escopo. Para obter mais informações, consulte [C++ Stack Semantics for Reference Types](../dotnet/cpp-stack-semantics-for-reference-types.md).

- Uma exceção é lançada durante a construção do objeto.

- O objeto é um membro em um objeto cujo destruidor está funcionando.

- Você chama o operador [de exclusão](../cpp/delete-operator-cpp.md) em uma alça[(Handle to Object Operator (^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md)).

- Você chama explicitamente o destruidor.

Se o seu tipo está sendo consumido por um cliente que está escrito em outro idioma, o destruidor é chamado da seguinte forma:

- Em uma <xref:System.IDisposable.Dispose%2A>chamada para.

- Em uma `Dispose(void)` chamada para o tipo.

- Se o tipo sair do escopo `using` em uma declaração C#.

Se você criar um objeto de um tipo de referência no heap gerenciado (não usando semântica de pilha para tipos de referência), use a sintaxe [try-finally](../cpp/try-finally-statement.md) para garantir que uma exceção não impeça o destructor de ser executado.

```cpp
// compile with: /clr
ref struct A {
   ~A() {}
};

int main() {
   A ^ MyA = gcnew A;
   try {
      // use MyA
   }
   finally {
      delete MyA;
   }
}
```

Se o seu tipo tiver um destruidor, o `Dispose` compilador gera <xref:System.IDisposable>um método que implementa . Se um tipo que está escrito no Visual C++ e tem um destruidor que `IDisposable::Dispose` é consumido de outra língua, chamar esse tipo faz com que o destructor do tipo seja chamado. Quando o tipo é consumido a partir de um cliente `Dispose`Visual C++, você não pode ligar diretamente; em vez disso, chame o destruidor `delete` usando o operador.

Se o seu tipo tiver um finalizador, o compilador gera um `Finalize(void)` método que substitui <xref:System.Object.Finalize%2A>.

Se um tipo tiver um finalizador ou um destruidor, o `Dispose(bool)` compilador gera um método, de acordo com o padrão de design. (Para informações, consulte [Padrão de descarte](/dotnet/standard/design-guidelines/dispose-pattern)). Você não pode explicitamente `Dispose(bool)` autor ou chamada no Visual C++.

Se um tipo tiver uma classe base que esteja em conformidade com o padrão de design, os destruidores de todas as classes base são chamados quando o destruidor para a classe derivada é chamado. (Se seu tipo estiver escrito no Visual C++, o compilador garante que seus tipos implementem esse padrão.) Em outras palavras, o destruidor de uma classe de referência cadeias para suas bases e membros conforme especificado pelo padrão C++ — primeiro o destructor da classe é executado, em seguida, os destructores para seus membros no inverso da ordem em que foram construídos, e finalmente os destruidores para suas classes base no inverso da ordem em que foram construídos.

Destruidores e finalizadores não são permitidos dentro de tipos de valor ou interfaces.

Um finalizador só pode ser definido ou declarado em um tipo de referência. Como um construtor e destruidor, um finalizador não tem nenhum tipo de retorno.

Depois que o finalizador de um objeto é executado, finalizadores em qualquer classe base também são chamados, começando com o tipo menos derivado. Os finalizadores para membros de dados não são automaticamente acorrentados pelo finalizador de uma classe.

Se um finalizador excluir um ponteiro nativo em um tipo gerenciado, você deve garantir que as referências para ou através do ponteiro nativo não sejam coletadas prematuramente; chamar o destruidor no tipo gerenciado em vez <xref:System.GC.KeepAlive%2A>de usar .

Na hora da compilação, você pode detectar se um tipo tem um finalizador ou um destruidor. Saiba mais em [Suporte para compilador de traços de tipo](../extensions/compiler-support-for-type-traits-cpp-component-extensions.md).

A próxima amostra mostra dois tipos, um que tem recursos não gerenciados e outro que gerencia recursos que são liberados determinicamente.

```cpp
// compile with: /clr
#include <vcclr.h>
#include <stdio.h>
using namespace System;
using namespace System::IO;

ref class SystemFileWriter {
   FileStream ^ file;
   array<Byte> ^ arr;
   int bufLen;

public:
   SystemFileWriter(String ^ name) : file(File::Open(name, FileMode::Append)),
                                     arr(gcnew array<Byte>(1024)) {}

   void Flush() {
      file->Write(arr, 0, bufLen);
      bufLen = 0;
   }

   ~SystemFileWriter() {
      Flush();
      delete file;
   }
};

ref class CRTFileWriter {
   FILE * file;
   array<Byte> ^ arr;
   int bufLen;

   static FILE * getFile(String ^ n) {
      pin_ptr<const wchar_t> name = PtrToStringChars(n);
      FILE * ret = 0;
      _wfopen_s(&ret, name, L"ab");
      return ret;
   }

public:
   CRTFileWriter(String ^ name) : file(getFile(name)), arr(gcnew array<Byte>(1024) ) {}

   void Flush() {
      pin_ptr<Byte> buf = &arr[0];
      fwrite(buf, 1, bufLen, file);
      bufLen = 0;
   }

   ~CRTFileWriter() {
      this->!CRTFileWriter();
   }

   !CRTFileWriter() {
      Flush();
      fclose(file);
   }
};

int main() {
   SystemFileWriter w("systest.txt");
   CRTFileWriter ^ w2 = gcnew CRTFileWriter("crttest.txt");
}
```

## <a name="see-also"></a>Confira também

[Classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md)<br/>
[Classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md)
