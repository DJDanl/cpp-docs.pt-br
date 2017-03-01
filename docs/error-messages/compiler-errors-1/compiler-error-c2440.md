---
title: C2440 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2440
dev_langs:
- C++
helpviewer_keywords:
- C2440
ms.assetid: 36e6676c-f04f-4715-8ba1-f096c4bf3b44
caps.latest.revision: 27
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 5f0472f7d318de24c38898388906a264cf56db7b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2440"></a>C2440 de erro do compilador
'conversion': não é possível converter de 'type1' em 'type2'  
  
O compilador não pode converter de `type1` para `type2`.  
  
## <a name="example"></a>Exemplo  
C2440 pode ser causado se você tentar inicializar não const `char*` (ou `wchar_t*`) usando uma cadeia de caracteres literal no código C++, quando a opção de conformidade do compilador [/ZC: strictstrings](../../build/reference/zc-strictstrings-disable-string-literal-type-conversion.md) está definido. Em C, o tipo de um literal de cadeia de caracteres é a matriz de `char`, mas em C++, ele é a matriz de `const char`. Este exemplo gera C2440:  
  
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
 C2440 também pode ser causado se você tentar converter um ponteiro para membro void *. O exemplo a seguir gera C2440:  
  
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
 C2440 também pode ser causado se você tentar converter de um tipo que é declarado apenas para frente, mas não definido. Este exemplo gera C2440:  
  
```cpp  
// c2440a.cpp   
struct Base { }; // Defined  
  
struct Derived; // Forward declaration, not defined  
  
Base * func(Derived * d) {  
    return static_cast<Base *>(d); // error C2440: 'static_cast' : cannot convert from 'Derived *' to 'Base *'  
}  
  
```  
  
## <a name="example"></a>Exemplo  
 Os erros de C2440 nas linhas 15 e 16 do próximo exemplo estão qualificados com o `Incompatible calling conventions for UDT return value` mensagem. A *UDT* é um tipo definido pelo usuário, como uma classe, estrutura ou união. Esses tipos de erros de incompatibilidade são causados quando a convenção de chamada de um UDT especificado no tipo de retorno de um conflito de declaração de encaminhamento com a convenção de chamada real do UDT e um ponteiro de função está envolvido.  
  
 No exemplo, pela primeira vez há declarações de encaminhamento para uma estrutura em uma função que retorna a estrutura; o compilador pressupõe que a estrutura usa a convenção de chamada de C++. Em seguida é a definição de estrutura, que, por padrão, usa o C convenção de chamada. Porque o compilador não sabe a convenção de chamada da estrutura até terminar de ler a estrutura inteira, a convenção de chamada para a estrutura no tipo de retorno de `get_c2` também é considerado como C++.  
  
 A estrutura é seguida por outra declaração de função que retorna a estrutura, mas neste ponto, o compilador sabe que a convenção de chamada do struct é C++. Da mesma forma, o ponteiro de função, que retorna a estrutura, é definido após a definição de estrutura para que o compilador sabe que a estrutura usa a convenção de chamada de C++.  
  
 Para resolver C2440 ocorre devido às convenções de chamada incompatíveis, declare funções que retornam uma UDT após a definição de UDT.  
  
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
 C2440 também pode ocorrer se você atribuir zero para um ponteiro interno:  
  
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
 C2440 também pode ocorrer para um uso incorreto de uma conversão definida pelo usuário. Por exemplo, quando um operador de conversão foi definido como `explicit`, o compilador não pode usá-lo em uma conversão implícita. Para obter mais informações sobre conversões definidas pelo usuário, consulte [conversões definidas pelo usuário (C + + / CLI)](../../dotnet/user-defined-conversions-cpp-cli.md)). Este exemplo gera C2440:  
  
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
 C2440 também pode ocorrer se você tentar criar uma instância de uma matriz do Visual C++ cujo tipo é <xref:System.Array>.</xref:System.Array>  Para obter mais informações, consulte [matrizes](../../windows/arrays-cpp-component-extensions.md).  O exemplo a seguir gera C2440:  
  
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
 C2440 também pode ocorrer devido a alterações no recurso de atributos.  O exemplo a seguir gera C2440.  
  
```cpp  
// c2440f.cpp  
// compile with: /LD  
[ module(name="PropDemoLib", version=1.0) ];   // C2440  
// try the following line instead  
// [ module(name="PropDemoLib", version="1.0") ];  
```  
  
## <a name="example"></a>Exemplo  
 O compilador do Visual C++ não permite que o [operador const_cast](../../cpp/const-cast-operator.md) converter para baixo ao código-fonte que usa **/clr** programação é compilada.  
  
 Para resolver essa C2440, use o operador cast correto. Para obter mais informações, consulte [operadores de conversão](../../cpp/casting-operators.md).  
  
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
C2440 pode ocorrer devido a alterações de conformidade do compilador no Visual Studio 2015 atualização 3. Anteriormente, o compilador incorretamente consideradas determinadas expressões distintas do mesmo tipo ao identificar uma correspondência de modelo para um `static_cast` operação. Agora, o compilador distingue os tipos corretamente e código que dependiam anterior `static_cast` comportamento for interrompido. Para corrigir esse problema, altere o argumento de modelo para corresponder ao tipo de parâmetro de modelo ou usar um `reinterpret_cast` ou lançamento de estilo C.
  
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

