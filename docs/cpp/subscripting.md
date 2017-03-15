---
title: "Subscripting | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], assinatura"
  - "sobrecarga de operador, exemplos"
  - "operadores [C++], sobrecarga"
  - "Operador subscript"
  - "Operador subscript, sobrecarregado"
  - "assinatura"
ms.assetid: eb151281-6733-401d-9787-39ab6754c62c
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Subscripting
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador subscrito \(**\[ \]**\), como o operador de chamada da função, é considerado um operador binário.  O operador subscrito deve ser uma função de membro não estático que usa um único argumento.  Este argumento ou pode ser de qualquer tipo e designa o subscrito de matriz desejado.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um vetor de tipo `int` que implementa a verificação dos limites:  
  
```  
// subscripting.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
class IntVector {  
public:  
   IntVector( int cElements );  
   ~IntVector() { delete [] _iElements; }  
   int& operator[](int nSubscript);  
private:  
   int *_iElements;  
   int _iUpperBound;  
};  
  
// Construct an IntVector.  
IntVector::IntVector( int cElements ) {  
   _iElements = new int[cElements];  
   _iUpperBound = cElements;  
}  
  
// Subscript operator for IntVector.  
int& IntVector::operator[](int nSubscript) {  
   static int iErr = -1;  
  
   if( nSubscript >= 0 && nSubscript < _iUpperBound )  
      return _iElements[nSubscript];  
   else {  
      clog << "Array bounds violation." << endl;  
      return iErr;  
   }  
}  
  
// Test the IntVector class.  
int main() {  
   IntVector v( 10 );  
   int i;  
  
   for( i = 0; i <= 10; ++i )  
      v[i] = i;  
  
   v[3] = v[9];  
  
   for ( i = 0; i <= 10; ++i )  
      cout << "Element: [" << i << "] = " << v[i] << endl;  
}  
```  
  
  **Violação dos limites de matriz.**  
**Elemento: \[0\] \= 0**  
**Elemento: \[1\] \= 1**  
**Elemento: \[2\] \= 2**  
**Elemento: \[3\] \= 9**  
**Elemento: \[4\] \= 4**  
**Elemento: \[5\] \= 5**  
**Elemento: \[6\] \= 6**  
**Elemento: \[7\] \= 7**  
**Elemento: \[8\] \= 8**  
**Elemento: \[9\] \= 9**  
**Violação dos limites de matriz.**  
**Elemento: \[10\] \= 10**   
## Comentários  
 Quando `i` atinge 10 no programa anterior, `operator[]` detecta que um subscrito fora dos limites está sendo usado e emite uma mensagem de erro.  
  
 Observe que a função `operator[]` retorna um tipo de referência.  Isso a torna um l\-value, permitindo usar as expressões subscritas em ambos os lados dos operadores de atribuição.  
  
## Consulte também  
 [Sobrecarga de operador](../cpp/operator-overloading.md)