---
title: "Erro do Compilador C2440 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2440"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2440"
ms.assetid: 36e6676c-f04f-4715-8ba1-f096c4bf3b44
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2440
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'conversion': não é possível converter de 'type1' para 'type2'  
  
 O compilador não pode converter de "`type1`" em "`type2`".  
  
## Exemplo  
 O C2440 pode ser causado se você tentar inicializar uma `char*` não constante \(ou `wchar_t*`\) usando um literal de cadeia de caracteres no código C\+\+, quando a opção de compatibilidade de compilador [\/Zc:strictStrings](../../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) é definida.  No C, o tipo de um literal de cadeia de caracteres é matriz de `char`, mas no C\+\+, é matriz de `const` `char`.  Este exemplo gera C2440:  
  
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
  
## Exemplo  
 O C2440 também pode ser causado se você tentar converter um ponteiro para o membro para void\*.  O exemplo a seguir produz C2440:  
  
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
  
## Exemplo  
 O C2440 também poderá ser causado se você tentar converter de um tipo que seja somente declarado encaminhado mas não definido.  Este exemplo gera C2440:  
  
```cpp  
// c2440a.cpp   
struct Base { }; // Defined  
  
struct Derived; // Forward declaration, not defined  
  
Base * func(Derived * d) {  
    return static_cast<Base *>(d); // error C2440: 'static_cast' : cannot convert from 'Derived *' to 'Base *'  
}  
  
```  
  
## Exemplo  
 Os erros C2440 nas linhas 15 e 16 do exemplo a seguir são qualificados com a mensagem `Incompatible calling conventions for UDT return value`. \(Um UDT é um tipo definido pelo usuário, como uma classe, um estrutura, ou uma união.\) Esses tipos de erros de incompatibilidade são causados quando a convenção de chamada de um UDT especificado no tipo de retorno de uma declaração de encaminhamento conflita com a convenção real de chamada do UDT e quando um ponteiro de função está envolvido.  
  
 No exemplo, primeiro há declarações de avanço para uma estrutura e para uma função que retorna a estrutura; o compilador pressupõe que a estrutura usa a convenção de chamada do C\+\+.  A próxima é a definição de estrutura, que, por padrão, usa a convenção de chamada do C.  Como o compilador não conhece a convenção de chamada de estrutura até que ele termine de ler a estrutura inteira, a convenção de chamada da estrutura no tipo de retorno de `get_c2` será considerada como sendo C\+\+.  
  
 A estrutura é seguida por outra declaração de função que retorna a estrutura mas, nesse ponto, o compilador sabe que a convenção de chamada de estrutura é C\+\+.  De maneira semelhante, o ponteiro de função, que retorna a estrutura, é definido após a definição da estrutura de modo que o compilador saiba que a estrutura usa a convenção de chamada do C\+\+.  
  
 Para resolver C2440 que ocorre devido as convenções de chamada incompatíveis, declare as funções que retornam UDT após a definição UDT.  
  
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
  
## Exemplo  
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
  
## Exemplo  
 O C2440 também pode ocorrer para um uso incorreto de uma conversão definida pelo usuário.  Para obter mais informações sobre conversões definidas por usuário, consulte [Conversões definidas pelo usuário](../../dotnet/user-defined-conversions-cpp-cli.md)\).  Este exemplo gera C2440:  
  
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
  
## Exemplo  
 O C2440 também pode ocorrer se você tentar criar uma instância de uma matriz do Visual C\+\+ cujo tipo seja <xref:System.Array>.  Para obter mais informações, consulte [Arrays](../../windows/arrays-cpp-component-extensions.md).  O exemplo a seguir produz C2440:  
  
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
  
## Exemplo  
 O C2440 também pode ocorrer devido as alterações no recurso de atributos.  O exemplo a seguir produz C2440.  
  
```cpp  
// c2440f.cpp  
// compile with: /LD  
[ module(name="PropDemoLib", version=1.0) ];   // C2440  
// try the following line instead  
// [ module(name="PropDemoLib", version="1.0") ];  
```  
  
## Exemplo  
 O compilador do Visual C\+\+ não permite mais que o [Operador const\_cast](../Topic/const_cast%20Operator.md) exija um downcast quando o código\-fonte que usa a programação **\/clr** é criado.  
  
 Para resolver esse C2440, use o operador de conversão correto.  Para obter mais informações, consulte [Operadores de conversão](../../cpp/casting-operators.md).  
  
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
  
## Exemplo  
 O C2440 também pode ser gerado com **\/clr:oldSyntax**:  
  
```cpp  
// c2440h.cpp  
// compile with: /clr:oldSyntax  
__gc class Base {};  
__gc class Derived : public Base {};  
int main() {  
   Derived *d = new Derived;  
   Base *b = d;  
   d = const_cast<Derived*>(b);   // C2440  
   d = dynamic_cast<Derived*>(b);   // OK  
}  
```