---
title: "complex&lt;long double&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::complex<long double>"
  - "complex<long double>"
  - "std.complex<long double>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função complex<long double>"
ms.assetid: 37591991-b385-46e9-b727-d534dbc10432
caps.latest.revision: 20
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# complex&lt;long double&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que armazena um par ordenado de objetos do tipo`long double`o primeiro que representa a parte de um número complexo e o segundo real que representa a parte imaginária.  
  
## Sintaxe  
  
```  
template<>  
   class complex<long double> {  
public:  
   constexpr complex(  
      long double _RealVal = 0,   
      long double _ImagVal = 0  
   );  
complex(  
      constexpr complex<long double>& _ComplexNum  
   );  
   // rest same as template class complex  
};  
```  
  
#### Parâmetros  
 `_RealVal`  
 O valor do tipo**long double**para a parte real do número complexo sendo construído.  
  
 `_ImagVal`  
 O valor do tipo`long double`para a parte imaginária do número complexo sendo construído.  
  
 `_ComplexNum`  
 O número complexo do tipo**duplo**ou do tipo**float**cujos partes reais e imaginários são usados para inicializar um número complexo do tipo`long double`sendo construído.  
  
## Valor de retorno  
 Um número complexo do tipo`long double`.  
  
## Comentários  
 A especialização explícita da classe de modelo complexa para uma classe complexa do tipo`long double`difere somente nos construtores define a classe de modelo.  A conversão de`long double`para**float**tem permissão para ser implícitas, mas a conversão de**duplo**para`long double`deve ser**explícita**.  O uso de**explícita**regras de início com a conversão de tipo usando sintaxe de atribuição.  
  
 Para obter mais informações sobre a classe de modelo`complex`consulte[Classe complex](../standard-library/complex-class.md).  Para obter uma lista de membros da classe de modelo`complex`consulte.  
  
## Exemplo  
  
```  
// complex_comp_ld.cpp  
// compile with: /EHsc  
#include <complex>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
  
   // The first constructor specifies real & imaginary parts  
   complex <long double> c1 ( 4.0 , 5.0 );  
   cout << "Specifying initial real & imaginary parts,\n"  
        << " as type float gives c1 = " << c1 << endl;  
  
   // The second constructor initializes values of the real &  
   // imaginary parts using those of complex number of type float  
   complex <float> c2float ( 1.0 , 3.0 );  
   complex <long double> c2longdouble ( c2float );  
   cout << "Implicit conversion from type float to type long double,"  
        << "\n gives c2longdouble = " << c2longdouble << endl;  
  
   // The third constructor initializes values of the real &  
   // imaginary parts using those of a complex number  
   // of type double  
   complex <double> c3double ( 3.0 , 4.0 );  
   complex <long double> c3longdouble ( c3double );  
   cout << "Implicit conversion from type long double to type float,"  
        << "\n gives c3longdouble = " << c3longdouble << endl;  
  
   // The modulus and argument of a complex number can be recovered  
   double absc3 = abs ( c3longdouble );  
   double argc3 = arg ( c3longdouble );  
   cout << "The modulus of c3 is recovered from c3 using: abs ( c3 ) = "  
        << absc3 << endl;  
   cout << "Argument of c3 is recovered from c3 using:\n arg ( c3 ) = "  
        << argc3 << " radians, which is " << argc3 * 180 / pi  
        << " degrees." << endl;  
}  
```  
  
  **Especificando partes reais e imaginários iniciais,**  
 **como o tipo float dá c1 \= \(4,5\)**  
**Conversão implícita de tipo flutuante para o tipo long double,**  
 **Fornece c2longdouble \= \(1,3\)**  
**Conversão implícita de tipo long double para o tipo float,**  
 **Fornece c3longdouble \= \(3,4\)**  
**O resto de c3 é recuperado do uso de c3: abs \(c3\) \= 5**  
**Argumento de c3 é recuperado de c3 usando:**  
 **arg \(c3\) \= 0.927295 radianos, que é 53.1301 graus.**   
## Requisitos  
 **Cabeçalho**: \< complexos \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe complex](../standard-library/complex-class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)