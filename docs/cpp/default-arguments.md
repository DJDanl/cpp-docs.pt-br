---
title: Argumentos padrão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- arguments [C++], function
- function declarators
- functions [C++], default arguments
- declaring functions [C++], declarators
- default arguments
- arguments [C++], default
- defaults [C++], arguments
ms.assetid: d32cf516-05cb-4d4d-b169-92f5649fdfa2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ddcd094ae828272744060cea5604865d17562890
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409191"
---
# <a name="default-arguments"></a>Argumentos padrão
Em muitos casos, as funções têm os argumentos que são usados com tão raramente que um valor padrão bastaria. Para resolver isso, a facilidade do argumento padrão permite especificar apenas os argumentos de uma função que são significativos em uma determinada chamada. Para ilustrar esse conceito, considere o exemplo apresentado [sobrecarregamento de função](../cpp/function-overloading.md).  
  
```cpp 
// Prototype three print functions.  
int print( char *s );                  // Print a string.  
int print( double dvalue );            // Print a double.  
int print( double dvalue, int prec );  // Print a double with a  
//  given precision.  
```  
  
 Em muitos aplicativos, uma opção razoável pode ser fornecida para `prec`, eliminando a necessidade de duas funções:  
  
```cpp 
// Prototype two print functions.  
int print( char *s );                    // Print a string.  
int print( double dvalue, int prec=2 );  // Print a double with a  
//  given precision.  
```  
  
 A implementação do `print` função é alterada ligeiramente para refletir o fato de que apenas uma dessas funções existe para o tipo **duplo**:  
  
```cpp 
// default_arguments.cpp  
// compile with: /EHsc /c  
  
// Print a double in specified precision.  
//  Positive numbers for precision indicate how many digits  
//  precision after the decimal point to show. Negative  
//  numbers for precision indicate where to round the number  
//  to the left of the decimal point.  
  
#include <iostream>  
#include <math.h>  
using namespace std;  
  
int print( double dvalue, int prec ) {  
   // Use table-lookup for rounding/truncation.  
   static const double rgPow10[] = {   
      10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1, 10E0,  
         10E1,  10E2,  10E3,  10E4, 10E5,  10E6  
   };  
   const int iPowZero = 6;  
   // If precision out of range, just print the number.  
   if( prec >= -6 && prec <= 7 )  
      // Scale, truncate, then rescale.  
      dvalue = floor( dvalue / rgPow10[iPowZero - prec] ) *  
      rgPow10[iPowZero - prec];  
   cout << dvalue << endl;  
   return cout.good();  
}  
```  
  
 Para invocar a nova função `print`, use o código a seguir:  
  
```cpp 
print( d );    // Precision of 2 supplied by default argument.  
print( d, 0 ); // Override default argument to achieve other  
//  results.  
```  
  
 Observe esses pontos ao usar os argumentos padrão:  
  
-   Os argumentos padrão são usados somente em chamadas de função onde os argumentos à direita são omitidos — devem ser os últimos argumentos. Dessa forma, o código a seguir é ilegal:  
  
    ```cpp 
    int print( double dvalue = 0.0, int prec );  
    ```  
  
-   Um argumento padrão não pode ser redefinido nas declarações posteriores mesmo se a redefinição for idêntica ao original. Portanto, o código a seguir gera um erro:  
  
    ```cpp 
    // Prototype for print function.  
    int print( double dvalue, int prec = 2 );  
  
    ...  
  
    // Definition for print function.  
    int print( double dvalue, int prec = 2 )  
    {  
    ...  
    }  
    ```  
  
     O problema com esse código é que a declaração da função na definição redefine o argumento padrão para `prec`.  
  
-   Os argumentos padrão adicionais podem ser adicionados por declarações posteriores.  
  
-   Os argumentos padrão podem ser fornecidos para ponteiros para as funções. Por exemplo:  
  
    ```cpp 
    int (*pShowIntVal)( int i = 0 );  
    ```  