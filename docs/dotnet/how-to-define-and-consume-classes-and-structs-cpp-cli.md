---
title: 'Como: definir e consumir classes e estruturas (C++/CLI)'
description: Como criar e usar tipos de classe e struct definidos pelo usuário no código C++/CLI.
ms.date: 09/25/2020
helpviewer_keywords:
- structs [C++]
- classes [C++], instantiating
ms.assetid: 1c03cb0d-1459-4b5e-af65-97d6b3094fd7
ms.openlocfilehash: 17d0885d42febc1d2789c8711b54a76066ee8176
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414575"
---
# <a name="how-to-define-and-consume-classes-and-structs-ccli"></a>Como: definir e consumir classes e estruturas (C++/CLI)

Este artigo mostra como definir e consumir tipos de referência definidos pelo usuário e tipos de valor em C++/CLI.

## <a name="object-instantiation"></a><a name="BKMK_Object_instantiation"></a> Instanciação de objeto

Tipos de referência (ref) só podem ser instanciados no heap gerenciado, não na pilha ou no heap nativo. Tipos de valor podem ser instanciados na pilha ou no heap gerenciado.

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

## <a name="implicitly-abstract-classes"></a><a name="BKMK_Implicitly_abstract_classes"></a> Classes implicitamente abstratas

Uma *classe abstrata implicitamente* não pode ser instanciada. Uma classe é implicitamente abstrata quando:

- o tipo base da classe é uma interface e
- a classe não implementa todas as funções de membro da interface.

Talvez você não consiga construir objetos de uma classe derivada de uma interface. O motivo pode ser que a classe é implicitamente abstrata. Para obter mais informações sobre classes abstratas, consulte [abstract](../extensions/abstract-cpp-component-extensions.md).

O exemplo de código a seguir demonstra que a `MyClass` classe não pode ser instanciada porque a função `MyClass::func2` não está implementada. Para habilitar o exemplo a ser compilado, remova a marca de comentário `MyClass::func2` .

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

## <a name="type-visibility"></a><a name="BKMK_Type_visibility"></a> Visibilidade de tipo

Você pode controlar a visibilidade dos tipos de Common Language Runtime (CLR). Quando o assembly é referenciado, você controla se os tipos no assembly estão visíveis ou não estão visíveis fora do assembly.

`public` indica que um tipo é visível para qualquer arquivo de origem que contenha uma `#using` diretiva para o assembly que contém o tipo.  `private` indica que um tipo não é visível para os arquivos de origem que contêm uma `#using` diretiva para o assembly que contém o tipo. No entanto, os tipos privados são visíveis dentro do mesmo assembly. Por padrão, a visibilidade de uma classe é `private` .

Por padrão, antes do Visual Studio 2005, os tipos nativos tinham acessibilidade pública fora do assembly. Habilite o [aviso do compilador (nível 1) C4692](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) para ajudá-lo a ver onde tipos nativos privados são usados incorretamente. Use o [make_public](../preprocessor/make-public.md) pragma para fornecer acessibilidade pública a um tipo nativo em um arquivo de código-fonte que você não pode modificar.

Para obter mais informações, confira [Diretiva #using](../preprocessor/hash-using-directive-cpp.md).

O exemplo a seguir mostra como declarar tipos e especificar sua acessibilidade e, em seguida, acessar esses tipos dentro do assembly. Se um assembly que tem tipos privados for referenciado usando `#using` , somente tipos públicos no assembly estarão visíveis.

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

Agora, vamos reescrever o exemplo anterior para que ele seja compilado como uma DLL.

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

O exemplo a seguir mostra como acessar tipos fora do assembly. Neste exemplo, o cliente consome o componente que foi criado no exemplo anterior.

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

## <a name="member-visibility"></a><a name="BKMK_Member_visibility"></a> Visibilidade do membro

Você pode fazer o acesso a um membro de uma classe pública de dentro do mesmo assembly diferente do acesso a ele de fora do assembly usando pares dos especificadores de acesso **`public`** , **`protected`** e **`private`**

Esta tabela resume o efeito dos vários especificadores de acesso:

|Especificador|Efeito|
|---------------|------------|
|`public`|O membro é acessível dentro e fora do assembly. Para obter mais informações, confira [`public`](../cpp/public-cpp.md).|
|`private`|O membro está inacessível, dentro e fora do assembly.  Para obter mais informações, confira [`private`](../cpp/private-cpp.md).|
|`protected`|O membro é acessível dentro e fora do assembly, mas somente para tipos derivados. Para obter mais informações, confira [`protected`](../cpp/protected-cpp.md).|
|`internal`|O membro é público dentro do assembly, mas privado fora do assembly. `internal` é uma palavra-chave sensível ao contexto.  Saiba mais em [Palavras-chave contextuais](../extensions/context-sensitive-keywords-cpp-component-extensions.md).|
|`public protected` - ou - `protected public`|O membro é público dentro do assembly, mas protegido fora do assembly.|
|`private protected` - ou - `protected private`|O membro é protegido dentro do assembly, mas privado fora do assembly.|

O exemplo a seguir mostra um tipo público que tem membros que são declarados usando especificadores de acesso diferentes. Em seguida, ele mostra o acesso a esses membros de dentro do assembly.

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

Agora, vamos criar o exemplo anterior como uma DLL.

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

O exemplo a seguir consome o componente que é criado no exemplo anterior. Ele mostra como acessar os membros de fora do assembly.

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

## <a name="public-and-private-native-classes"></a><a name="BKMK_Public_and_private_native_classes"></a> Classes nativas públicas e privadas

Um tipo nativo pode ser referenciado de um tipo gerenciado.  Por exemplo, uma função em um tipo gerenciado pode usar um parâmetro cujo tipo é uma estrutura nativa.  Se o tipo e a função gerenciados forem públicos em um assembly, o tipo nativo também deverá ser público.

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

## <a name="static-constructors"></a><a name="BKMK_Static_constructors"></a> Construtores estáticos

Um tipo CLR — por exemplo, uma classe ou struct — pode ter um construtor estático que pode ser usado para inicializar membros de dados estáticos.  Um construtor estático é chamado no máximo uma vez e é chamado antes que qualquer membro estático do tipo seja acessado pela primeira vez.

Um construtor de instância sempre é executado após um construtor estático.

O compilador não poderá embutir uma chamada para um construtor se a classe tiver um construtor estático. O compilador não poderá embutir uma chamada para qualquer função de membro se a classe for um tipo de valor, tiver um construtor estático e não tiver um construtor de instância. O CLR pode embutir a chamada, mas o compilador não pode.

Defina um construtor estático como uma função de membro privado, pois ele deve ser chamado apenas pelo CLR.

Para obter mais informações sobre construtores estáticos, consulte [como: definir um construtor estático de interface (C++/CLI)](../dotnet/how-to-define-an-interface-static-constructor-cpp-cli.md) .

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

## <a name="semantics-of-the-this-pointer"></a><a name="BKMK_Semantics_of_the_this_pointer"></a> Semântica do `this` ponteiro

Quando você estiver usando C++ \CLI para definir tipos, o **`this`** ponteiro em um tipo de referência será do tipo *Handle*. O **`this`** ponteiro em um tipo de valor é do tipo *ponteiro interior*.

Essas semânticas diferentes do **`this`** ponteiro podem causar um comportamento inesperado quando um indexador padrão é chamado. O exemplo a seguir mostra a maneira correta de acessar um indexador padrão em um tipo de referência e um tipo de valor.

Para obter mais informações, consulte [manipulador para operador de objeto (^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md) e [interior_ptr (C++/CLI)](../extensions/interior-ptr-cpp-cli.md)

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

## <a name="hide-by-signature-functions"></a><a name="BKMK_Hide_by_signature_functions"></a> Funções de ocultar por assinatura

No C++ padrão, uma função em uma classe base é ocultada por uma função que tem o mesmo nome em uma classe derivada, mesmo que a função de classe derivada não tenha o mesmo tipo ou número de parâmetros. Ele é conhecido como semântica *de ocultar por nome* . Em um tipo de referência, uma função em uma classe base só será ocultada por uma função em uma classe derivada se o nome e a lista de parâmetros forem iguais. Ele é conhecido como semântica de *ocultar por assinatura* .

Uma classe é considerada uma classe de ocultar por assinatura quando todas as suas funções são marcadas nos metadados como `hidebysig` . Por padrão, todas as classes que são criadas em **`/clr`** têm `hidebysig` funções. Quando uma classe tem `hidebysig` funções, o compilador não oculta funções por nome em qualquer classe base direta, mas se o compilador encontrar uma classe de ocultar por nome em uma cadeia de herança, ele continuará o comportamento de ocultar por nome.

Na semântica de ocultar por assinatura, quando uma função é chamada em um objeto, o compilador identifica a classe mais derivada que contém uma função que pode atender à chamada de função. Se houver apenas uma função na classe que satisfaça a chamada, o compilador chamará essa função. Se houver mais de uma função na classe que possa atender à chamada, o compilador usará regras de resolução de sobrecarga para determinar qual função chamar. Para obter mais informações sobre regras de sobrecarga, consulte [sobrecarga de função](../cpp/function-overloading.md).

Para uma determinada chamada de função, uma função em uma classe base pode ter uma assinatura que o torna uma correspondência um pouco melhor do que uma função em uma classe derivada. No entanto, se a função foi explicitamente chamada em um objeto da classe derivada, a função na classe derivada é chamada.

Como o valor de retorno não é considerado parte da assinatura de uma função, uma função de classe base ficará oculta se tiver o mesmo nome e usará o mesmo tipo e número de argumentos como uma função de classe derivada, mesmo se ele for diferente no tipo do valor de retorno.

O exemplo a seguir mostra que uma função em uma classe base não está ocultada por uma função em uma classe derivada.

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

O exemplo a seguir mostra que o compilador do Microsoft C++ chama uma função na classe mais derivada, mesmo que uma conversão seja necessária para corresponder a um ou mais parâmetros — e não chamar uma função em uma classe base que seja uma correspondência melhor para a chamada de função.

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

O exemplo a seguir mostra que é possível ocultar uma função mesmo que a classe base tenha a mesma assinatura que a classe derivada.

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

## <a name="copy-constructors"></a><a name="BKMK_Copy_constructors"></a> Copiar construtores

O padrão C++ diz que um construtor de cópia é chamado quando um objeto é movido, de modo que um objeto é criado e destruído no mesmo endereço.

No entanto, quando uma função que é compilada para MSIL chama uma função nativa em que uma classe nativa — ou mais de uma — é passada por valor e onde a classe nativa tem um construtor de cópia ou um destruidor, nenhum construtor de cópia é chamado e o objeto é destruído em um endereço diferente daquele em que foi criado. Esse comportamento pode causar problemas se a classe tiver um ponteiro em si mesma ou se o código estiver rastreando objetos por endereço.

Para obter mais informações, consulte [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

O exemplo a seguir demonstra quando um construtor de cópia não é gerado.

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

## <a name="destructors-and-finalizers"></a><a name="BKMK_Destructors_and_finalizers"></a> Destruidores e finalizadores

Os destruidores em um tipo de referência fazem uma limpeza determinística dos recursos. Os finalizadores limpam recursos não gerenciados e podem ser chamados de forma determinística pelo destruidor ou não determinístico pelo coletor de lixo. Para obter informações sobre destruidores no C++ padrão, consulte [destruidores](../cpp/destructors-cpp.md).

```cpp
class classname {
   ~classname() {}   // destructor
   ! classname() {}   // finalizer
};
```

O coletor de lixo do CLR exclui objetos gerenciados não utilizados e libera sua memória quando eles não são mais necessários. No entanto, um tipo pode usar recursos que o coletor de lixo não sabe como liberar. Esses recursos são conhecidos como recursos *não gerenciados* (identificadores de arquivo nativo, por exemplo). Recomendamos que você libere todos os recursos não gerenciados no finalizador. O coletor de lixo libera recursos gerenciados de forma não determinística, portanto, não é seguro fazer referência a recursos gerenciados em um finalizador. Isso ocorre porque é possível que o coletor de lixo já as tenha limpo.

Um finalizador Visual C++ não é o mesmo que o <xref:System.Object.Finalize%2A> método. (A documentação do CLR usa o finalizador e o <xref:System.Object.Finalize%2A> método como sinônimos). O <xref:System.Object.Finalize%2A> método é chamado pelo coletor de lixo, que invoca cada finalizador em uma cadeia de herança de classe. Ao contrário de destruidores Visual C++, uma chamada de finalizador de classe derivada não faz com que o compilador invoque o finalizador em todas as classes base.

Como o compilador do Microsoft C++ oferece suporte à versão determinística de recursos, não tente implementar os <xref:System.IDisposable.Dispose%2A> <xref:System.Object.Finalize%2A> métodos ou. No entanto, se você estiver familiarizado com esses métodos, veja como um Visual C++ finalizador e um destruidor que chama o mapa do finalizador para o <xref:System.IDisposable.Dispose%2A> padrão:

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

Um tipo gerenciado também pode usar recursos gerenciados que você prefere liberar de forma determinística. Talvez você não queira que o coletor de lixo libere um objeto de forma não determinística em algum momento depois que o objeto não for mais necessário. A versão determinística dos recursos pode melhorar significativamente o desempenho.

O compilador do Microsoft C++ permite a definição de um destruidor para limpar de forma determinística os objetos. Use o destruidor para liberar todos os recursos que você deseja liberar de forma determinística.  Se um finalizador estiver presente, chame-o do destruidor para evitar a duplicação de código.

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

Se o código que consome o tipo não chamar o destruidor, o coletor de lixo eventualmente liberará todos os recursos gerenciados.

A presença de um destruidor não implica a presença de um finalizador. No entanto, a presença de um finalizador implica que você deve definir um destruidor e chamar o finalizador a partir desse destruidor. Essa chamada fornece a versão determinística de recursos não gerenciados.

Chamar o destruidor suprime — usando <xref:System.GC.SuppressFinalize%2A> – finalização do objeto. Se o destruidor não for chamado, o finalizador do tipo será eventualmente chamado pelo coletor de lixo.

Você pode melhorar o desempenho chamando o destruidor para limpar determinísticamente os recursos do objeto, em vez de permitir que o CLR Finalize o objeto de forma não determinística.

O código escrito em Visual C++ e compilado usando **`/clr`** executa o destruidor de um tipo se:

- Um objeto que é criado usando semântica de pilha sai do escopo. Para obter mais informações, consulte [semântica de pilha C++ para tipos de referência](../dotnet/cpp-stack-semantics-for-reference-types.md).

- Uma exceção é lançada durante a construção do objeto.

- O objeto é um membro em um objeto cujo destruidor está sendo executado.

- Você chama o operador [delete](../cpp/delete-operator-cpp.md) em um identificador ([identificador para operador de objeto (^)](../extensions/handle-to-object-operator-hat-cpp-component-extensions.md)).

- Você chama explicitamente o destruidor.

Se um cliente escrito em outra linguagem consumir o tipo, o destruidor será chamado da seguinte maneira:

- Em uma chamada para <xref:System.IDisposable.Dispose%2A> .

- Em uma chamada para `Dispose(void)` no tipo.

- Se o tipo sair do escopo em uma instrução C# **`using`** .

Se você não estiver usando semânticas de pilha para tipos de referência e criar um objeto de um tipo de referência no heap gerenciado, use a sintaxe [try-finally](../cpp/try-finally-statement.md) para garantir que uma exceção não impeça que o destruidor seja executado.

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

Se o seu tipo tiver um destruidor, o compilador gerará um `Dispose` método que implementa <xref:System.IDisposable> . Se um tipo que é escrito em Visual C++ e tem um destruidor que é consumido de outro idioma, `IDisposable::Dispose` a chamada a esse tipo faz com que o destruidor do tipo seja chamado. Quando o tipo é consumido de um cliente Visual C++, você não pode chamar diretamente `Dispose` ; em vez disso, chame o destruidor usando o **`delete`** operador.

Se o seu tipo tiver um finalizador, o compilador gerará um `Finalize(void)` método que substitui <xref:System.Object.Finalize%2A> .

Se um tipo tiver um finalizador ou um destruidor, o compilador gerará um `Dispose(bool)` método, de acordo com o padrão de design. (Para obter informações, veja [padrão Dispose](/dotnet/standard/design-guidelines/dispose-pattern)). Você não pode criar explicitamente ou chamar `Dispose(bool)` em Visual C++.

Se um tipo tiver uma classe base que esteja de acordo com o padrão de design, os destruidores para todas as classes base serão chamados quando o destruidor para a classe derivada for chamado. (Se o tipo for escrito em Visual C++, o compilador garantirá que seus tipos implementem esse padrão.) Em outras palavras, o destruidor de uma classe de referência se encadeia a suas bases e membros conforme especificado pelo padrão C++. Primeiro, o destruidor da classe é executado. Em seguida, os destruidores para seus membros são executados no inverso da ordem em que foram construídos. Por fim, os destruidores para suas classes base são executados no inverso da ordem em que foram construídos.

Destruidores e finalizadores não são permitidos em tipos de valores ou interfaces.

Um finalizador só pode ser definido ou declarado em um tipo de referência. Como um construtor e destruidor, um finalizador não tem nenhum tipo de retorno.

Depois que o finalizador de um objeto é executado, os finalizadores em qualquer classe base também são chamados, começando com o tipo menos derivado. Os finalizadores para membros de dados não são automaticamente encadeados pelo finalizador de uma classe.

Se um finalizador excluir um ponteiro nativo em um tipo gerenciado, você deverá garantir que as referências para ou por meio do ponteiro nativo não sejam coletadas prematuramente. Chame o destruidor no tipo gerenciado em vez de usar <xref:System.GC.KeepAlive%2A> .

No momento da compilação, você pode detectar se um tipo tem um finalizador ou um destruidor. Saiba mais em [Suporte para compilador de traços de tipo](../extensions/compiler-support-for-type-traits-cpp-component-extensions.md).

O próximo exemplo mostra dois tipos: um que tem recursos não gerenciados e um que tem recursos gerenciados que são liberados de forma determinística.

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

[Classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md)
