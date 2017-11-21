---
title: 'Como: definir e usar delegados (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: delegates
ms.assetid: 1cdf3420-89c1-47c0-b796-aa984020e0f8
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 22483b1b1e90c406d1a2f6bd1731f15008b58daa
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-define-and-use-delegates-ccli"></a>Como definir e usar delegados (C++/CLI)
Este artigo mostra como definir e consumir representantes no C + + CLI.  
  
 Embora o .NET Framework fornece um número de delegates, às vezes, você talvez precise definir novos delegados.  
  
 O exemplo de código a seguir define um delegado chamado `MyCallback`. O código de manipulação de eventos — a função que é chamada quando esse delegado novo é acionado — deve ter um tipo de retorno `void` e tomar uma <xref:System.String> referência.  
  
 A função principal usa um método estático que é definido por `SomeClass` para instanciar o `MyCallback` delegate. O representante torna-se um método alternativo de chamar essa função, conforme demonstrado enviando a cadeia de caracteres "única" para o objeto do representante. Em seguida, mais instâncias do `MyCallback` são vinculados e, em seguida, executado por uma chamada para o objeto do representante.  
  
```  
  
      // use_delegate.cpp  
// compile with: /clr  
using namespace System;  
  
ref class SomeClass  
{  
public:  
   static void Func(String^ str)  
   {  
      Console::WriteLine("static SomeClass::Func - {0}", str);  
   }  
};  
  
ref class OtherClass  
{  
public:  
   OtherClass( Int32 n )   
   {  
      num = n;  
   }  
  
   void Method(String^ str)   
   {  
      Console::WriteLine("OtherClass::Method - {0}, num = {1}",   
         str, num);  
   }  
  
   Int32 num;  
};  
  
delegate void MyCallback(String^ str);  
  
int main( )   
{  
   MyCallback^ callback = gcnew MyCallback(SomeClass::Func);     
   callback("single");   
  
   callback += gcnew MyCallback(SomeClass::Func);     
  
   OtherClass^ f = gcnew OtherClass(99);  
   callback += gcnew MyCallback(f, &OtherClass::Method);  
  
   f = gcnew OtherClass(100);  
   callback += gcnew MyCallback(f, &OtherClass::Method);  
  
   callback("chained");  
  
   return 0;  
}  
```  
  
 **Saída**  
  
```Output  
static SomeClass::Func - single  
static SomeClass::Func - chained  
static SomeClass::Func - chained  
OtherClass::Method - chained, num = 99  
OtherClass::Method - chained, num = 100  
```  
  
 O próximo exemplo de código mostra como associar um delegado um membro de uma classe de valor.  
  
```  
// mcppv2_del_mem_value_class.cpp  
// compile with: /clr  
using namespace System;  
public delegate void MyDel();  
  
value class A {  
public:  
   void func1() {  
      Console::WriteLine("test");  
   }  
};  
  
int main() {  
   A a;  
   A^ ah = a;  
   MyDel^ f = gcnew MyDel(a, &A::func1);   // implicit box of a  
   f();  
   MyDel^ f2 = gcnew MyDel(ah, &A::func1);  
   f2();  
}  
```  
  
 **Saída**  
  
```Output  
test  
test  
```  
  
## <a name="how-to-compose-delegates"></a>Como compor delegados  
 Você pode usar o "`-`" operador para remover um delegado de componente de um delegado composto.  
  
```  
// mcppv2_compose_delegates.cpp  
// compile with: /clr  
using namespace System;  
  
delegate void MyDelegate(String ^ s);  
  
ref class MyClass {  
public:  
   static void Hello(String ^ s) {  
      Console::WriteLine("Hello, {0}!", s);  
   }  
  
   static void Goodbye(String ^ s) {  
      Console::WriteLine("  Goodbye, {0}!", s);  
   }  
};  
  
int main() {  
  
   MyDelegate ^ a = gcnew MyDelegate(MyClass::Hello);  
   MyDelegate ^ b = gcnew MyDelegate(MyClass::Goodbye);  
   MyDelegate ^ c = a + b;  
   MyDelegate ^ d = c - a;  
  
   Console::WriteLine("Invoking delegate a:");  
   a("A");  
   Console::WriteLine("Invoking delegate b:");  
   b("B");  
   Console::WriteLine("Invoking delegate c:");  
   c("C");  
   Console::WriteLine("Invoking delegate d:");  
   d("D");  
}  
```  
  
 **Saída**  
  
```Output  
Invoking delegate a:  
Hello, A!  
Invoking delegate b:  
  Goodbye, B!  
Invoking delegate c:  
Hello, C!  
  Goodbye, C!  
Invoking delegate d:  
  Goodbye, D!  
```  
  
## <a name="pass-a-delegate-to-a-native-function-that-expects-a-function-pointer"></a>Transmitir um delegado ^ para uma função nativa que espera um ponteiro de função  
 De um componente gerenciado você pode chamar uma função nativa com função parâmetros de ponteiro em que a função nativa, em seguida, pode chamar a função de membro de delegado do componente gerenciado.  
  
 Este exemplo cria o arquivo. dll que exporta a função nativa:  
  
```  
// delegate_to_native_function.cpp  
// compile with: /LD  
#include < windows.h >  
extern "C" {  
   __declspec(dllexport)  
   void nativeFunction(void (CALLBACK *mgdFunc)(const char* str)) {  
      mgdFunc("Call to Managed Function");  
   }  
}  
```  
  
 O próximo exemplo consome o. dll e transmite um identificador de representante para a função nativa que espera um ponteiro de função.  
  
```  
// delegate_to_native_function_2.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
delegate void Del(String ^s);  
public ref class A {  
public:  
   void delMember(String ^s) {  
      Console::WriteLine(s);  
   }  
};  
  
[DllImportAttribute("delegate_to_native_function", CharSet=CharSet::Ansi)]  
extern "C" void nativeFunction(Del ^d);  
  
int main() {  
   A ^a = gcnew A;  
   Del ^d = gcnew Del(a, &A::delMember);  
   nativeFunction(d);   // Call to native function  
}  
```  
  
 **Saída**  
  
```Output  
Call to Managed Function  
```  
  
## <a name="to-associate-delegates-with-unmanaged-functions"></a>Para associar delegados a funções não gerenciadas  
 Para associar um delegado com uma função nativa, você deve incluir a função nativa em um tipo gerenciado e declarar a função a ser chamado por meio de `PInvoke`.  
  
```  
// mcppv2_del_to_umnangd_func.cpp  
// compile with: /clr  
#pragma unmanaged  
extern "C" void printf(const char*, ...);  
class A {  
public:  
   static void func(char* s) {  
      printf(s);  
   }  
};  
  
#pragma managed  
public delegate void func(char*);   
  
ref class B {  
   A* ap;  
  
public:  
   B(A* ap):ap(ap) {}  
   void func(char* s) {  
      ap->func(s);   
   }  
};  
  
int main() {  
   A* a = new A;  
   B^ b = gcnew B(a);  
   func^ f = gcnew func(b, &B::func);  
   f("hello");  
   delete a;  
}  
```  
  
 **Saída**  
  
```Output  
hello  
```  
  
## <a name="to-use-unbound-delegates"></a>Para usar os delegados não associados  
 Você pode usar um delegate não associado para passar uma instância do tipo cuja função você deseja chamar quando o representante é chamado.  
  
 Delegados não associados são especialmente úteis se você deseja iterar pelos objetos em uma coleção — usando [para cada um, no](../dotnet/for-each-in.md) palavras-chave — e chamar uma função de membro em cada instância.  
  
 Aqui está como declarar, criar uma instância e chamada associadas e não vinculados delegados:  
  
|Ação|Associado delegados|Delegados não associados|  
|------------|---------------------|-----------------------|  
|Declare|A assinatura do delegado deve corresponder à assinatura da função que você deseja chamar por meio de representante.|O primeiro parâmetro da assinatura do delegado é o tipo de `this` para o objeto que você deseja chamar.<br /><br /> Após o primeiro parâmetro, a assinatura do delegado deve corresponder à assinatura da função que você deseja chamar por meio de representante.|  
|Criar uma instância|Quando você cria uma instância de um delegado associado, você pode especificar uma função de instância, ou uma função de membro global ou estática.<br /><br /> Para especificar uma função de instância, o primeiro parâmetro é uma instância do tipo cuja função de membro que você deseja chamar e o segundo parâmetro é o endereço da função que você deseja chamar.<br /><br /> Se você deseja chamar uma função de membro global ou estática, basta passe o nome de uma função global ou o nome da função de membro estático.|Quando você instancia um delegate não associado, passe apenas o endereço da função que você deseja chamar.|  
|Chamada|Quando você chama um delegado associado, apenas passe os parâmetros necessários para a assinatura do delegado.|Mesmo que um limite delegado, mas lembre-se de que o primeiro parâmetro deve ser uma instância do objeto que contém a função que você deseja chamar.|  
  
 Este exemplo demonstra como declarar e criar uma instância e chamar delegados não associados:  
  
```  
// unbound_delegates.cpp  
// compile with: /clr  
ref struct A {  
   A(){}  
   A(int i) : m_i(i) {}  
   void Print(int i) { System::Console::WriteLine(m_i + i);}  
  
private:  
   int m_i;  
};  
  
value struct V {  
   void Print() { System::Console::WriteLine(m_i);}  
   int m_i;  
};  
  
delegate void Delegate1(A^, int i);  
delegate void Delegate2(A%, int i);  
  
delegate void Delegate3(interior_ptr<V>);  
delegate void Delegate4(V%);  
  
delegate void Delegate5(int i);  
delegate void Delegate6();  
  
int main() {  
   A^ a1 = gcnew A(1);  
   A% a2 = *gcnew A(2);  
  
   Delegate1 ^ Unbound_Delegate1 = gcnew Delegate1(&A::Print);  
   // delegate takes a handle  
   Unbound_Delegate1(a1, 1);  
   Unbound_Delegate1(%a2, 1);  
  
   Delegate2 ^ Unbound_Delegate2 = gcnew Delegate2(&A::Print);  
   // delegate takes a tracking reference (must deference the handle)  
   Unbound_Delegate2(*a1, 1);  
   Unbound_Delegate2(a2, 1);  
  
   // instantiate a bound delegate to an instance member function  
   Delegate5 ^ Bound_Del = gcnew Delegate5(a1, &A::Print);  
   Bound_Del(1);  
  
   // instantiate value types  
   V v1 = {7};  
   V v2 = {8};  
  
   Delegate3 ^ Unbound_Delegate3 = gcnew Delegate3(&V::Print);  
   Unbound_Delegate3(&v1);  
   Unbound_Delegate3(&v2);  
  
   Delegate4 ^ Unbound_Delegate4 = gcnew Delegate4(&V::Print);  
   Unbound_Delegate4(v1);  
   Unbound_Delegate4(v2);  
  
   Delegate6 ^ Bound_Delegate3 = gcnew Delegate6(v1, &V::Print);  
   Bound_Delegate3();  
}  
```  
  
 **Saída**  
  
```Output  
2  
3  
2  
3  
2  
7  
8  
7  
8  
7  
```  
  
 O próximo exemplo mostra como usar delegados não associados e o [para cada um, no](../dotnet/for-each-in.md) palavras-chave para iterar por meio de objetos em uma coleção e chamar uma função de membro em cada instância.  
  
```  
// unbound_delegates_2.cpp  
// compile with: /clr  
using namespace System;  
  
ref class RefClass {  
   String^ _Str;  
  
public:  
   RefClass( String^ str ) : _Str( str ) {}  
   void Print() { Console::Write( _Str ); }  
};  
  
delegate void PrintDelegate( RefClass^ );  
  
int main() {  
   PrintDelegate^ d = gcnew PrintDelegate( &RefClass::Print );  
  
   array< RefClass^ >^ a = gcnew array<RefClass^>( 10 );  
  
   for ( int i = 0; i < a->Length; ++i )  
      a[i] = gcnew RefClass( i.ToString() );  
  
   for each ( RefClass^ R in a )  
      d( R );  
  
   Console::WriteLine();  
}  
```  
  
 Este exemplo cria um delegate não associado às funções do acessador de propriedade:  
  
```  
// unbound_delegates_3.cpp  
// compile with: /clr  
ref struct B {  
   property int P1 {  
      int get() { return m_i; }  
      void set(int i) { m_i = i; }  
   }  
  
private:  
   int m_i;  
};  
  
delegate void DelBSet(B^, int);  
delegate int DelBGet(B^);  
  
int main() {  
   B^ b = gcnew B;  
  
   DelBSet^ delBSet = gcnew DelBSet(&B::P1::set);  
   delBSet(b, 11);  
  
   DelBGet^ delBGet = gcnew DelBGet(&B::P1::get);     
   System::Console::WriteLine(delBGet(b));  
}  
```  
  
 **Saída**  
  
```Output  
11  
```  
  
 O exemplo a seguir mostra como invocar um delegado multicast, onde uma instância está associada e uma instância é desassociada.  
  
```  
// unbound_delegates_4.cpp  
// compile with: /clr  
ref class R {  
public:  
   R(int i) : m_i(i) {}  
  
   void f(R ^ r) {  
      System::Console::WriteLine("in f(R ^ r)");  
   }  
  
   void f() {  
      System::Console::WriteLine("in f()");  
   }  
  
private:  
   int m_i;  
};  
  
delegate void Del(R ^);  
  
int main() {  
   R ^r1 = gcnew R(11);  
   R ^r2 = gcnew R(12);  
  
   Del^ d = gcnew Del(r1, &R::f);  
   d += gcnew Del(&R::f);  
   d(r2);  
};  
```  
  
 **Saída**  
  
```Output  
in f(R ^ r)  
in f()  
```  
  
 O próximo exemplo mostra como criar e chamar um delegado genérico não associado.  
  
```  
// unbound_delegates_5.cpp  
// compile with: /clr  
ref struct R {  
   R(int i) : m_i(i) {}  
  
   int f(R ^) { return 999; }  
   int f() { return m_i + 5; }  
  
   int m_i;  
};  
  
value struct V {  
   int f(V%) { return 999; }  
   int f() { return m_i + 5; }   
  
   int m_i;  
};  
  
generic <typename T>  
delegate int Del(T t);  
  
generic <typename T>  
delegate int DelV(T% t);  
  
int main() {     
   R^ hr = gcnew R(7);  
   System::Console::WriteLine((gcnew Del<R^>(&R::f))(hr));  
  
   V v;  
   v.m_i = 9;  
   System::Console::WriteLine((gcnew DelV<V >(&V::f))(v) );  
}  
```  
  
 **Saída**  
  
```Output  
12  
14  
```  
  
## <a name="see-also"></a>Consulte também  
 [delegate (Extensões de componentes do C++)](../windows/delegate-cpp-component-extensions.md)