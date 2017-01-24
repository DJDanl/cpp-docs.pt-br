---
title: "Como: definir e consumir Classes e estruturas (C++ /CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "estruturas [C++]"
  - "classes [C++], criando"
ms.assetid: 1c03cb0d-1459-4b5e-af65-97d6b3094fd7
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como definir e consumir classes e estruturas (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo mostra como definir e consumir tipos de referência definidos pelo usuário e tipos de valor em [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)].  
  
##  <a name="a-namebkmkcontentsa-contents"></a><a name="BKMK_Contents"></a> Conteúdo  
 [Instanciação de objetos](#BKMK_Object_instantiation)  
  
 [Classes implicitamente abstratas](#BKMK_Implicitly_abstract_classes)  
  
 [Visibilidade de tipo](#BKMK_Type_visibility)  
  
 [Visibilidade de membro](#BKMK_Member_visibility)  
  
 [Classes nativas públicas e privadas](#BKMK_Public_and_private_native_classes)  
  
 [Construtores estáticos](#BKMK_Static_constructors)  
  
 [Semântica do ponteiro](#BKMK_Semantics_of_the_this_pointer)  
  
 [Funções ocultar por assinatura](#BKMK_Hide_by_signature_functions)  
  
 [Construtores de cópia](#BKMK_Copy_constructors)  
  
 [Destruidores e finalizadores](#BKMK_Destructors_and_finalizers)  
  
##  <a name="a-namebkmkobjectinstantiationa-object-instantiation"></a><a name="BKMK_Object_instantiation"></a> Instanciação de objetos  
 Tipos de valor e tipos de referência (ref) só podem ser instanciados no heap gerenciado, não na pilha ou no heap nativo.  
  
```  
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
  
##  <a name="a-namebkmkimplicitlyabstractclassesa-implicitly-abstract-classes"></a><a name="BKMK_Implicitly_abstract_classes"></a> Classes implicitamente abstratas  
 Um *classe abstrata implicitamente* não pode ser instanciada. Uma classe é abstrata implicitamente se o tipo base da classe é uma interface e a classe não implementa todas as funções de membro da interface.  
  
 Se não for possível criar objetos de uma classe que é derivada de uma interface, o motivo pode ser que a classe é abstrata implicitamente. Para obter mais informações sobre classes abstratas, consulte [abstrato](../windows/abstract-cpp-component-extensions.md).  
  
 O exemplo de código a seguir demonstra que o `MyClass` classe não pode ser instanciada como função `MyClass::func2` não está implementado. Para habilitar o exemplo compilar, remova os comentários `MyClass::func2`.  
  
```  
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
  
##  <a name="a-namebkmktypevisibilitya-type-visibility"></a><a name="BKMK_Type_visibility"></a> Visibilidade de tipo  
 Você pode controlar a visibilidade de tipos common language runtime (CLR) para que, se um assembly for referenciado, tipos no assembly podem estar visível ou não é visível fora do assembly.  
  
 `public` indica que um tipo é visível para qualquer arquivo de origem que contém um `#using` diretiva para o assembly que contém o tipo.  `private` indica que um tipo não é visível para os arquivos de origem que contêm um `#using` diretiva para o assembly que contém o tipo. No entanto, os tipos privados são visíveis dentro do mesmo assembly. Por padrão, a visibilidade de uma classe é `private`.  
  
 Por padrão, antes do Visual C++ 2005, tipos nativos tinham acessibilidade pública fora do assembly. Habilitar [C4692 de aviso do compilador (nível 1)](../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md) para ajudá-lo a ver onde privados tipos nativos são usados incorretamente. Use o [make_public](../preprocessor/make-public.md) pragma para fornecer acessibilidade pública para um tipo nativo em um arquivo de código fonte não podem ser modificados.  
  
 Para obter mais informações, consulte [#using diretiva](../preprocessor/hash-using-directive-cpp.md).  
  
 O exemplo a seguir mostra como declarar tipos e especifique sua acessibilidade e, em seguida, acessar esses tipos dentro do assembly. Obviamente, se um assembly com tipos privados referenciado usando `#using`, somente os tipos públicos no assembly serão visíveis.  
  
```  
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
  
 Agora, vamos reescrever o exemplo anterior para que ele é compilado como uma DLL.  
  
```  
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
  
 O exemplo a seguir mostra como acessar tipos fora do assembly. Neste exemplo, o cliente consome o componente é criado no exemplo anterior.  
  
```  
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
  
##  <a name="a-namebkmkmembervisibilitya-member-visibility"></a><a name="BKMK_Member_visibility"></a> Visibilidade de membro  
 Você pode fazer acesso a um membro de uma classe pública de dentro do mesmo assembly diferente de acesso a ele de fora do assembly usando pares de especificadores de acesso `public`, `protected`, e `private`  
  
 Esta tabela resume o efeito dos especificadores de acesso de vários:  
  
|Especificador|Efeito|  
|---------------|------------|  
|público|Membro é acessível dentro e fora do assembly.  Consulte [pública](../cpp/public-cpp.md) para obter mais informações.|  
|private|Membro não está acessível, nem dentro como fora do assembly.  Consulte [particular](../Topic/private%20\(C++\).md) para obter mais informações.|  
|protected|Membro é acessível dentro e fora do assembly, mas apenas para tipos derivados.  Consulte [protegido](../Topic/protected%20\(C++\).md) para obter mais informações.|  
|interno|Membro é público dentro do assembly, mas privada fora do assembly.  `internal` é uma palavra-chave contextual.  Para obter mais informações, consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).|  
|público público protegido - ou - protegido|Membro é público dentro do assembly, mas protegidos fora do assembly.|  
|particular privada protegida - ou - protegida|Membro é protegido dentro do assembly, mas privada fora do assembly.|  
  
 O exemplo a seguir mostra um tipo público que tem membros que são declarados com a acessibilidade diferente e, em seguida, mostra o acesso a esses membros de dentro do assembly.  
  
```  
  
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
  
 Agora vamos criar o exemplo anterior como uma DLL.  
  
```  
  
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
  
 O exemplo a seguir consome o componente que é criado no exemplo anterior e, portanto, mostra como acessar os membros de fora do assembly.  
  
```  
  
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
  
##  <a name="a-namebkmkpublicandprivatenativeclassesa-public-and-private-native-classes"></a><a name="BKMK_Public_and_private_native_classes"></a> Classes nativas públicas e privadas  
 Um tipo nativo pode ser referenciado de um tipo gerenciado.  Por exemplo, uma função em um tipo gerenciado pode levar um parâmetro cujo tipo é uma estrutura nativa.  Se o tipo gerenciado e a função públicas em um assembly, em seguida, o tipo nativo deve também ser público.  
  
```  
  
// native type  
public struct N {  
   N(){}  
   int i;  
};  
```  
  
 Em seguida, crie o arquivo de código fonte que consome o tipo nativo:  
  
```  
  
// compile with: /clr /LD  
#include "mcppv2_ref_class3.h"  
// public managed type  
public ref struct R {  
   // public function that takes a native type  
   void f(N nn) {}  
};  
```  
  
 Agora, compile um cliente:  
  
```  
  
// compile with: /clr  
#using "mcppv2_ref_class3.dll"  
  
#include "mcppv2_ref_class3.h"  
  
int main() {  
   R ^r = gcnew R;  
   N n;  
   r->f(n);  
}  
```  
  
##  <a name="a-namebkmkstaticconstructorsa-static-constructors"></a><a name="BKMK_Static_constructors"></a> Construtores estáticos  
 Um tipo CLR — por exemplo, uma classe ou struct — pode ter um construtor estático pode ser usado para inicializar membros de dados estáticos.  Um construtor estático é chamado no máximo uma vez e é chamado antes de qualquer membro estático do tipo é acessado na primeira vez.  
  
 Um construtor de instância sempre é executado após um construtor estático.  
  
 O compilador não pode embutir uma chamada para um construtor se a classe tem um construtor estático.  O compilador não pode embutir uma chamada para qualquer função de membro se a classe é um tipo de valor, tem um construtor estático e não tem um construtor de instância.  O CLR pode embutido a chamada, mas o compilador não pode.  
  
 Defina um construtor estático como uma função de membro particular, como ele se destina a ser chamado apenas pelo CLR.  
  
 Para obter mais informações sobre os construtores estáticos, consulte [como: definir um construtor estático de Interface (C + + / CLI)](../dotnet/how-to-define-an-interface-static-constructor-cpp-cli.md) .  
  
```  
  
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
  
##  <a name="a-namebkmksemanticsofthethispointera-semantics-of-the-this-pointer"></a><a name="BKMK_Semantics_of_the_this_pointer"></a> Semântica do ponteiro  
 Quando você estiver usando Visual C++ para definir tipos, o `this` ponteiro em um tipo de referência é do tipo "identificador". O `this` ponteiro em um tipo de valor é do tipo "ponteiro interior".  
  
 Essas semânticas diferentes do `this` ponteiro pode causar um comportamento inesperado quando um indexador padrão é chamado. O exemplo a seguir mostra a maneira correta de acessar um indexador padrão em um tipo de referência e um tipo de valor.  
  
 Para obter mais informações, consulte  
  
-   [Operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)  
  
-   [interior_ptr (C + + / CLI)](../windows/interior-ptr-cpp-cli.md)  
  
-   [Como: usar propriedades indexadas](../misc/how-to-use-indexed-properties.md)  
  
```  
  
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
  
##  <a name="a-namebkmkhidebysignaturefunctionsa-hide-by-signature-functions"></a><a name="BKMK_Hide_by_signature_functions"></a> Funções ocultar por assinatura  
 No C++ padrão, uma função em uma classe base é oculta por uma função que tem o mesmo nome em uma classe derivada, mesmo que a função de classe derivada não tem o mesmo número ou tipo de parâmetros. Isso é conhecido como *Ocultar pelo nome* semântica. Em um tipo de referência, uma função em uma classe base pode apenas ser ocultada por uma função em uma classe derivada se o nome e a lista de parâmetros são os mesmos. Isso é conhecido como *Ocultar por assinatura* semântica.  
  
 Uma classe é considerada uma classe de ocultar por assinatura quando todas as suas funções são marcadas nos metadados como `hidebysig`. Por padrão, todas as classes que são criadas em **/clr** ter `hidebysig` funções. No entanto, uma classe que é compilada usando **/CLR: oldSyntax** não tem `hidebysig` funções; em vez disso, eles são funções ocultar por nome. Quando uma classe tem `hidebysig` funções, o compilador não oculta funções por nome em todas as classes base diretas, mas se o compilador encontra uma classe ocultar por nome em uma cadeia de herança, ele continua esse comportamento ocultar por nome.  
  
 Ocultar por assinatura, semântica quando uma função é chamada em um objeto, o compilador identifica a classe mais derivada que contém uma função que pode satisfazer a chamada de função. Se houver apenas uma função na classe que pode atender a chamada, o compilador chama essa função. Se houver mais de uma função na classe que pode atender a chamada, o compilador usa regras de resolução para determinar a função para chamar de sobrecarga. Para obter mais informações sobre regras de sobrecarga, consulte [sobrecarga de função](../cpp/function-overloading.md).  
  
 Para uma chamada de função fornecida, uma função em uma classe base pode ter uma assinatura que o torna uma correspondência um pouco melhor do que uma função em uma classe derivada. No entanto, se a função foi chamada explicitamente em um objeto da classe derivada, a função na classe derivada é chamada.  
  
 Porque o valor de retorno não é considerado parte da assinatura da função, uma função de classe base é ocultada se ele tem o mesmo nome e utiliza o mesmo número e tipo dos argumentos como uma função de classe derivada, mesmo que ele difere no tipo do valor de retorno.  
  
 O exemplo a seguir mostra que uma função em uma classe base não está oculta por uma função em uma classe derivada.  
  
```  
  
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
  
 O próximo exemplo mostra que o compilador do Visual C++ chama uma função na classe mais derivada — mesmo se uma conversão é necessária para corresponder um ou mais dos parâmetros — e não chamar uma função em uma classe base que é mais adequado para a chamada de função.  
  
```  
  
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
  
```  
  
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
  
 O exemplo a seguir define um componente que é compilado usando **/CLR: oldSyntax**. Classes que são definidas usando extensões gerenciadas para C++ têm funções de membro de ocultar por nome.  
  
```  
  
// compile with: /clr:oldSyntax /LD  
using namespace System;  
public __gc struct Base0 {  
   void Test() {   
      Console::WriteLine("in Base0::Test");  
   }  
};  
  
public __gc struct Base1 : public Base0 {  
   void Test(int i) {   
      Console::WriteLine("in Base1::Test");  
   }  
};  
```  
  
 O exemplo a seguir consome o componente é criado no exemplo anterior. Observe como ocultar por assinatura funcionalidade não se aplica a classes base dos tipos que são compilados usando **/CLR: oldSyntax**.  
  
```  
  
// compile with: /clr:oldSyntax /LD  
// compile with: /clr  
using namespace System;  
#using "hide_by_signature_4.dll"  
  
ref struct Derived : public Base1 {  
   void Test(int i, int j) {   
      Console::WriteLine("Derived::Test");  
   }  
};  
  
int main() {  
   Derived ^ t = gcnew Derived;  
   t->Test(8, 8);   // OK  
   t->Test(8);   // OK  
   t->Test();   // C2661  
}  
```  
  
##  <a name="a-namebkmkcopyconstructorsa-copy-constructors"></a><a name="BKMK_Copy_constructors"></a> Construtores de cópia  
 O padrão C++ informa que um construtor de cópia é chamado quando um objeto é movido, de modo que um objeto é criado e destruído no mesmo endereço.  
  
 No entanto, quando **/clr** é usado para compilar e uma função que é compilada para chamadas MSIL nascido na função onde uma classe nativa — ou mais — é passado por valor e onde a classe nativa tem um construtor de cópia e/ou um destruidor, nenhum construtor de cópia é chamado e o objeto é destruído em um endereço diferente de onde ele foi criado. Isso pode causar problemas se a classe tem um ponteiro para o próprio, ou se o código está acompanhando objetos através do endereço.  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md).  
  
 O exemplo a seguir demonstra quando um construtor de cópia não será gerado.  
  
```  
  
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
  
##  <a name="a-namebkmkdestructorsandfinalizersa-destructors-and-finalizers"></a><a name="BKMK_Destructors_and_finalizers"></a> Destruidores e finalizadores  
 Destruidores em um tipo de referência realizar uma determinística limpeza de recursos. Os finalizadores limpar recursos não gerenciados e podem ser chamados de forma determinista, o destruidor ou forma não determinística pelo coletor de lixo. Para obter informações sobre destruidores em C++ padrão, consulte [destruidores](../cpp/destructors-cpp.md).  
  
```  
class classname {  
   ~classname() {}   // destructor  
   ! classname() {}   // finalizer  
};  
```  
  
 O comportamento de destruidores em uma classe gerenciada do Visual C++ difere das extensões gerenciadas para C++. Para obter mais informações sobre essa alteração, consulte [alterações na semântica do destruidor](../dotnet/changes-in-destructor-semantics.md).  
  
 O coletor de lixo do CLR exclui objetos gerenciados não utilizados e libera sua memória quando elas não são mais necessárias. No entanto, um tipo pode usar recursos que o coletor de lixo não sabe como liberar. Esses recursos são conhecidos como recursos não gerenciados (nativo identificadores de arquivo, por exemplo). É recomendável que você libera todos os recursos não gerenciados no finalizador. Como os recursos gerenciados são liberados de forma não determinística pelo coletor de lixo, não é seguro referir-se recursos gerenciados em um finalizador porque é possível que o coletor de lixo já foi limpo recurso gerenciado.  
  
 Um finalizador do Visual C++ não é igual a <xref:System.Object.Finalize%2A> método. (A documentação do CLR usa finalizador e <xref:System.Object.Finalize%2A> método como sinônimo). O <xref:System.Object.Finalize%2A> método é chamado pelo coletor de lixo, que chama cada finalizador em uma cadeia de herança de classe. Diferentemente destruidores do Visual C++, uma chamada finalizador da classe derivada não faz com que o compilador chamar o finalizador em todas as classes base.  
  
 Como o compilador do Visual C++ oferece suporte a liberação determinística dos recursos, não tente implementar o <xref:System.IDisposable.Dispose%2A> ou <xref:System.Object.Finalize%2A> métodos. No entanto, se você estiver familiarizado com esses métodos, aqui está como um finalizador do Visual C++ e um destruidor que chama o finalizador mapeiam para o <xref:System.IDisposable.Dispose%2A> padrão:  
  
```  
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
  
 Um tipo gerenciado também pode usar os recursos gerenciados que preferir a versão de forma determinista e não deixar o coletor de lixo libere forma não determinística em algum momento depois que o objeto não é mais necessário. A liberação determinística de recursos pode melhorar significativamente o desempenho.  
  
 O compilador do Visual C++ permite a definição de um destruidor de forma determinista limpar objetos. Use o destruidor para liberar todos os recursos que você deseja liberar de forma determinista.  Se um finalizador estiver presente, chamá-lo de destruidor, para evitar a duplicação de código.  
  
```  
  
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
  
 Se o código que consome seu tipo não chama o destruidor, o coletor de lixo eventualmente libera todos os recursos gerenciados.  
  
 A presença de um destruidor não implica a presença de um finalizador. No entanto, a presença de um finalizador implica que você deve definir um destruidor e chamar o finalizador desse destruidor. Isso possibilita a liberação determinística de recursos não gerenciados.  
  
 Chamar o destruidor suprime — usando <xref:System.GC.SuppressFinalize%2A>— finalização do objeto. Se o destruidor não é chamado, o finalizador do tipo eventualmente será chamado pelo coletor de lixo.  
  
 Limpeza de forma determinista de recursos do objeto chamando o destruidor pode melhorar o desempenho em comparação ao permitir que o CLR forma não determinística finalize o objeto.  
  
 Código escrito em Visual C++ e compilado usando **/clr** executa o destruidor do tipo se:  
  
-   Um objeto que é criado usando a semântica da pilha sai do escopo. Para obter mais informações, consulte [semântica da pilha do C++ para tipos de referência](../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
-   Uma exceção é lançada durante a construção do objeto.  
  
-   O objeto é um membro de um objeto cujo destruidor é executado.  
  
-   Você chama o [Excluir](../cpp/delete-operator-cpp.md) operador em uma alça ([operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)).  
  
-   Você chama explicitamente o destruidor.  
  
 Se o tipo está sendo consumido por um cliente que é escrito em outro idioma, o destruidor é chamado como segue:  
  
-   Em uma chamada para <xref:System.IDisposable.Dispose%2A>.  
  
-   Em uma chamada para `Dispose(void)` no tipo.  
  
-   Se o tipo sai do escopo em c# `using` instrução.  
  
 Se você criar um objeto do tipo de referência no heap gerenciado (não usando a semântica da pilha para tipos de referência), use [try-finally](../cpp/try-finally-statement.md) sintaxe para garantir que uma exceção não impede que o destruidor de execução.  
  
```  
  
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
  
 Se o tipo tem um destruidor, o compilador gera um `Dispose` método que implementa <xref:System.IDisposable>. Se um tipo que é escrito em Visual C++ e tem um destruidor é consumido de outro idioma, chamar `IDisposable::Dispose` nesse tipo faz com que o destruidor do tipo a ser chamado. Quando o tipo é consumido de um cliente do Visual C++, você não pode chamar diretamente `Dispose`; em vez disso, chame o destruidor usando o `delete` operador.  
  
 Se o tipo tem um finalizador, o compilador gera um `Finalize(void)` método substitui <xref:System.Object.Finalize%2A>.  
  
 Se um tipo tem um finalizador ou um destruidor, o compilador gera um `Dispose(bool)` método, de acordo com o padrão de design. (Para obter informações, consulte [Padrão de descarte](../Topic/Dispose%20Pattern.md)). Não é possível criar ou chamar explicitamente `Dispose(bool)` no Visual C++.  
  
 Se um tipo tem uma classe base que está em conformidade com o padrão de design, os destruidores de todas as classes base são chamados quando o destruidor da classe derivada é chamado. (Se o tipo é escrito em Visual C++, o compilador garante que seus tipos de implementam esse padrão). Em outras palavras, o destruidor de uma classe de referência encadeia suas bases e membros conforme especificado pelo padrão C++ — primeiro o destruidor da classe é executar, então os destruidores de seus membros na ordem inversa da ordem na qual eles foram construídos e, finalmente, os destruidores de suas classes base na ordem inversa da ordem na qual eles foram construídos.  
  
 Destruidores e finalizadores não são permitidos em tipos de valor ou interfaces.  
  
 Um finalizador só pode ser definido ou declarado em um tipo de referência. Como um construtor e destruidor, um finalizador não tem nenhum tipo de retorno.  
  
 Após a execução do finalizador de um objeto, os finalizadores em todas as classes base também são chamados, começando com o tipo menos derivado. Os finalizadores para membros de dados não são automaticamente encadeados pelo finalizador da classe.  
  
 Se um finalizador exclui um ponteiro nativo em um tipo gerenciado, você deve garantir que as referências a ou através do ponteiro nativo não são coletadas prematuramente; chamar o destruidor do tipo gerenciado em vez de usar <xref:System.GC.KeepAlive%2A>.  
  
 Em tempo de compilação, você pode detectar se um tipo tem um finalizador ou um destruidor. Para obter mais informações, consulte [suporte a compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 O exemplo a seguir mostra dois tipos, que tem recursos não gerenciados e que tem recursos de forma determinista lançadas gerenciados.  
  
```  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md)   
 [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md)