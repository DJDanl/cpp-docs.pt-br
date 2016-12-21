---
title: "Complex &lt; double &gt; | Microsoft Docs"
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
  - "std.complex<double>"
  - "complex<double>"
  - "std::complex<double>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "função Complex < double >"
ms.assetid: 0d0b9d2a-9b9b-410b-82a0-86b6df127e47
caps.latest.revision: 23
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Complex &lt; double &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que armazena um par ordenado de objetos do tipo **duplo***,* o primeiro que representa a parte de um número complexo e o segundo real que representa a parte imaginária.  
  
## Sintaxe  
  
```  
template<>  
   class complex<double> {  
public:  
   constexpr complex(  
      double _RealVal = 0,   
      double _ImagVal = 0  
   );  
  
   constexpr complex(  
      const complex<double>& _ComplexNum  
   );  
   constexpr explicit complex(  
      const complex<long double>& _ComplexNum  
   );  
   // rest same as template class complex  
};  
```  
  
#### Parâmetros  
 `_RealVal`  
 O valor do tipo **duplo** para a parte real do número complexo sendo construído.  
  
 `_ImagVal`  
 O valor do tipo **duplo** para a parte imaginária do número complexo sendo construído.  
  
 `_ComplexNum`  
 O número complexo do tipo **float** ou do tipo `long double` cujos partes reais e imaginários são usados para inicializar um número complexo do tipo **duplo** sendo construído.  
  
## Valor de retorno  
 Um número complexo do tipo **duplo**.  
  
## Comentários  
 A especialização explícita da classe modelo complexa para uma classe complexa do tipo **duplo** difere apenas em construtores define a classe de modelo. A conversão de **float** para **duplo** pode ser implícito, mas a conversão de `long double` para **duplo** é necessária para ser **explícita**. O uso de **explícita** regras de início com a conversão de tipo usando sintaxe de atribuição.  
  
 Para obter mais informações sobre a classe de modelo `complex`, consulte [Classe complex](../standard-library/complex-class.md). Para obter uma lista de membros da classe modelo `complex`, consulte.  
  
## Exemplo  
  
```  
// complex_comp_dbl.cpp  
// compile with: /EHsc  
#include <complex>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
  
   // The first constructor specifies real & imaginary parts  
   complex <double> c1 ( 4.0 , 5.0 );  
   cout << "Specifying initial real & imaginary parts,\n"  
        << " as type double gives c1 = " << c1 << endl;  
  
   // The second constructor initializes values of the real &  
   // imaginary parts using those of complex number of type float  
   complex <float> c2float ( 4.0 , 5.0 );  
   complex <double> c2double ( c2float );  
   cout << "Implicit conversion from type float to type double,"  
        << "\n gives c2double = " << c2double << endl;  
  
   // The third constructor initializes values of the real &  
   // imaginary parts using those of a complex number  
   // of type long double  
   complex <long double> c3longdouble ( 4.0 , 5.0 );  
   complex <double> c3double ( c3longdouble );  
   cout << "Explicit conversion from type float to type double,"  
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
  
 **Especificar partes reais e imaginários iniciais, como tipo double dá c1 \= \(4,5\) conversão implícita de tipo float para o tipo double, c2double dá \= \(4,5\) conversão explícita do tipo float para o tipo double, c3longdouble dá \= \(4,5\) o resto de c3 é recuperado de c3 usando: abs \(c3\) \= 6.40312 argumento de c3 é recuperado do uso de c3: arg \(c3\) \= radianos 0.896055, que é 51.3402 graus.**   
## Requisitos  
 **Cabeçalho**: \< complexo \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe complex](../standard-library/complex-class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)