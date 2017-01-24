---
title: "Struct greater_equal | Microsoft Docs"
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
  - "std.greater_equal"
  - "greater_equal"
  - "std::greater_equal"
  - "xfunctional/std::greater_equal"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Struct greater_equal"
  - "Função greater_equal"
ms.assetid: a8ba911b-7af8-4653-b972-d8618f4df7d5
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct greater_equal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um predicado binário que executa maior ou igual a operação \(\)`operator>=`em seus argumentos.  
  
## Sintaxe  
  
```  
template<class Type = void>  
   struct greater_equal : public binary_function <Type, Type, bool>   
   {  
      bool operator()(  
         const Type& Left,   
         const Type& Right  
      ) const;  
   };  
  
// specialized transparent functor for operator>=  
template<>  
   struct greater_equal<void>  
   {  
      template<class Type1, class Type2>  
      auto operator()(Type1&& Left, Type2&& Right) const  
         -> decltype(std::forward<Type1>(Left)  
            >= std::forward<Type2>(Right));  
   };  
  
```  
  
#### Parâmetros  
 `Type`, `Type1`, `Type2`  
 Qualquer tipo que ofereça suporte `operator>=` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo do maior ou igual a operação.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type1`.  
  
 `Right`  
 O operando direito de maior ou igual a operação.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type2`.  
  
## Valor de retorno  
 O resultado de `Left``>=``Right`.  O modelo especializado aperfeiçoa a transmissão de resultado, que contém o tipo que é retornado por `operator>=`.  
  
## Comentários  
 O predicado`Type`\> fornece a ordenação binária `greater_equal`\<fraco restrito de um conjunto de valores do elemento do tipo `Type` em classes de equivalência, se e somente se este tipo satisfaz os requisitos matemáticos padrão para o seja ordenado.  As especializações para qualquer tipo de ponteiro gerenciem a ordenação global de elementos, que todos os elementos de valores distintos são colocados em relação às outras.  
  
## Exemplo  
  
```  
// functional_greater_equal.cpp  
// compile with: /EHsc  
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
  
   int i;  
   v1.push_back( 6262 );  
   v1.push_back( 6262 );  
   for ( i = 0 ; i < 5 ; i++ )  
   {  
      v1.push_back( rand( ) );  
   }  
  
   cout << "Original vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   // To sort in ascending order,  
   // use default binary predicate less<int>( )  
   sort( v1.begin( ), v1.end( ) );  
   cout << "Sorted vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   // To sort in descending order,   
   // specify binary predicate greater_equal<int>( )  
   sort( v1.begin( ), v1.end( ), greater_equal<int>( ) );  
   cout << "Resorted vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
}  
```  
  
## Saída  
  
```  
Original vector v1 = ( 6262 6262 41 18467 6334 26500 19169 )  
Sorted vector v1 = ( 41 6262 6262 6334 18467 19169 26500 )  
Resorted vector v1 = ( 26500 19169 18467 6334 6262 6262 41 )  
```  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)