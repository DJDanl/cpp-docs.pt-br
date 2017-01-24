---
title: "Convers&#245;es definidas pelo usu&#225;rio (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "conversões definidas pelo usuário [C++]"
ms.assetid: 8010fd59-2775-4e9a-a6ed-58055032d66f
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es definidas pelo usu&#225;rio (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta seção discute conversões definidos pelo usuário \(UDC\) quando um dos tipos na conversão é uma referência ou uma instância de um tipo de valor ou de referência.  
  
## Conversões implícitas e explícitas  
 Uma conversão definido pelo usuário pode ser implícita ou explícita.  Uma CDU deve ser implícita se a conversão não resulta em uma perda de informações.  Se não for uma CDU explícita deve ser definida.  
  
 O construtor nativo de uma classe pode ser usada para converter uma referência ou um tipo de valor em uma classe nativo.  
  
 Para obter mais informações sobre conversões, consulte [Boxing](../windows/boxing-cpp-component-extensions.md) e [Conversões padrão](../cpp/standard-conversions.md).  
  
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
  
  **em N::N**  
**em N::N**   
## Converso\-de operadores  
 Converso\- dos operadores crie um objeto da classe na qual o operador é definido de um objeto de alguma outra classe.  
  
 O padrão C\+\+ não oferece suporte a converso\- dos operadores; o padrão C\+\+ usar construtores para essa finalidade.  No entanto, ao usar tipos de CLR, Visual C\+\+ fornece suporte sintático para chamar converso\- dos operadores.  
  
 Para interoperar bem com outros idiomas compatíveis com CLS, talvez você queira incluir cada construtor unário definido pelo usuário para uma determinada classe com o correspondente converso\- do operador.  
  
 Converso\- dos operadores:  
  
-   Será definido como funções estáticas.  
  
-   Pode ser implícito \(para as conversões que não perdem a precisão como o curto\-à\- int\) ou explícito, quando pode haver uma perda de precisão.  
  
-   Retornará um objeto contentor da classe.  
  
-   Terá “” do tipo como o único tipo de parâmetro.  
  
 O exemplo a seguir mostra um implícita e explícita “converso\- de”, operador \(UDC\) definido pelo usuário de conversão.  
  
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
  
  **o operador**  
**no construtor**  
**10**  
**1**   
## Converso\- a operadores  
 Converso\- a operadores converter um objeto da classe na qual o operador é definido como outro objeto.  O exemplo a seguir mostra um implícito, converso\- a, operador definido pelo usuário de conversão:  
  
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
  
  **10** Um tipo definido pelo usuário explícito converso\- ao operador de conversão é apropriado para as conversões que perderão potencialmente dados de algum modo.  Para invocar um explícito converso\-ao operador, uma conversão deve ser usada.  
  
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
  
  **10.3**  
**10**   
## Para converter classes genéricas  
 Você pode converter uma classe genérico para o T.  
  
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
  
  **True** Um construtor convertendo utiliza um tipo e usá\-los para criar um objeto.  Convertendo um construtor é chamado com inicialização direta; as conversões não invocarão converter construtores.  Por padrão, convertendo os construtores são explícita para tipos de CLR.  
  
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
  
  **5**  
**R** Neste exemplo de código, uma função estática de conversão implícita faz a mesma coisa que um construtor explícito de conversão.  
  
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
  
  **13**  
**12**  
**500**  
**2000**   
## Consulte também  
 [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)