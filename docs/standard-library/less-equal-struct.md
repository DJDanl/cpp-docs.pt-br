---
title: "Struct less_equal | Microsoft Docs"
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
  - "std::less_equal"
  - "xfunctional/std::less_equal"
  - "std.less_equal"
  - "less_equal"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função less_equal"
  - "Struct less_equal"
ms.assetid: 32085782-c7e0-4310-9b40-8aa3c1bff211
caps.latest.revision: 23
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct less_equal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um predicado binário que executa menor ou igual a operação \(\)`operator<=`em seus argumentos.  
  
## Sintaxe  
  
```  
template<class Type = void>  
   struct less_equal : public binary_function <Type, Type, bool>   
   {  
      bool operator()(  
         const Type& Left,   
         const Type& Right  
      ) const;  
   };  
  
// specialized transparent functor for operator<=  
template<>  
   struct less_equal<void>  
   {  
      template<class Type1, class Type2>  
      auto operator()(Type1&& Left, Type2&& Right) const  
         -> decltype(std::forward<Type1>(Left)  
            <= std::forward<Type2>(Right));  
   };  
  
```  
  
#### Parâmetros  
 `Type`, `Type1`, `Type2`  
 Qualquer tipo que ofereça suporte `operator<=` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo do menor ou igual a operação.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type1`.  
  
 `Right`  
 O operando direito de menor ou igual a operação.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type2`.  
  
## Valor de retorno  
 O resultado de `Left``<=``Right`.  O modelo especializado aperfeiçoa a transmissão de resultado, que contém o tipo retornado por `operator<=`.  
  
## Comentários  
 O predicado`Type`\> fornece a ordenação binária `less_equal`\<fraco restrito de um conjunto de valores do elemento do tipo `Type` em classes de equivalência, se e somente se este tipo satisfaz os requisitos matemáticos padrão para o seja ordenado.  As especializações para qualquer tipo de ponteiro gerenciem a ordenação global de elementos, que todos os elementos de valores distintos são colocados em relação às outras.  
  
## Exemplo  
  
```  
// functional_less_equal.cpp  
// compile with: /EHsc  
#define _CRT_RAND_S  
#include <stdlib.h>  
#include <vector>  
#include <algorithm>  
#include <functional>  
#include <cstdlib>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
   vector <int>::iterator Iter1;  
   vector <int>::reverse_iterator rIter1;  
   unsigned int randomNumber;  
  
   int i;  
   for ( i = 0 ; i < 5 ; i++ )  
   {  
      if ( rand_s( &randomNumber ) == 0 )  
      {  
         // Convert the random number to be between 1 - 50000  
         // This is done for readability purposes  
         randomNumber = ( unsigned int) ((double)randomNumber /   
            (double) UINT_MAX * 50000) + 1;  
  
         v1.push_back( randomNumber );  
      }  
   }  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      v1.push_back( 2836 );  
   }  
  
   cout << "Original vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   // To sort in ascending order,  
   // use the binary predicate less_equal<int>( )  
   sort( v1.begin( ), v1.end( ), less_equal<int>( ) );  
   cout << "Sorted vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
}  
```  
  
## Saída de Exemplo  
  
```  
Original vector v1 = ( 31247 37154 48755 15251 6205 2836 2836 2836 )  
Sorted vector v1 = ( 2836 2836 2836 6205 15251 31247 37154 48755 )  
```  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)