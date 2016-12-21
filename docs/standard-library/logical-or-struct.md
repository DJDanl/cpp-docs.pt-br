---
title: "Struct logical_or | Microsoft Docs"
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
  - "std.logical_or"
  - "std::logical_or"
  - "logical_or"
  - "xfunctional/std::logical_or"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe logical_or"
  - "Struct logical_or"
ms.assetid: ec8143f8-5755-4e7b-8025-507fb6bf6911
caps.latest.revision: 22
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct logical_or
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um objeto predefinido de função que executa a operação de`operator||`disjunção lógica \(\) em seus argumentos.  
  
## Sintaxe  
  
```  
template<class Type = void>  
   struct logical_or : public binary_function<Type, Type, bool>   
   {  
      bool operator()(  
         const Type& Left,   
         const Type& Right  
      ) const;  
   };  
  
// specialized transparent functor for operator||  
template<>  
   struct logical_or<void>  
   {  
      template<class Type1, class Type2>  
      auto operator()(Type1&& Left, Type2&& Right) const  
         -> decltype(std::forward<Type1>(Left)  
            || std::forward<Type2>(Right));  
   };  
  
```  
  
#### Parâmetros  
 `Type`, `Type1`, `Type2`  
 Qualquer tipo que ofereça suporte `operator||` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo da operação de disjunção lógica.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type1`.  
  
 `Right`  
 O operando direito da operação de disjunção lógica.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type2`.  
  
## Valor de retorno  
 O resultado de `Left``||``Right`.  O modelo especializado aperfeiçoa a transmissão de resultado, que contém o tipo que é retornado por `operator||`.  
  
## Comentários  
 Para tipos definidos pelo usuário, não há nenhum procurar um caminho mais curto de avaliação do operando.  Os dois argumentos forem avaliados por `operator||`.  
  
## Exemplo  
  
```  
// functional_logical_or.cpp  
// compile with: /EHsc  
#include <deque>  
#include <algorithm>  
#include <functional>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   deque <bool> d1, d2, d3( 7 );  
   deque <bool>::iterator iter1, iter2, iter3;  
  
   int i;  
   for ( i = 0 ; i < 7 ; i++ )  
   {  
      d1.push_back((bool)((rand() % 2) != 0));  
   }  
  
   int j;  
   for ( j = 0 ; j < 7 ; j++ )  
   {  
      d2.push_back((bool)((rand() % 2) != 0));  
   }  
  
   cout << boolalpha;    // boolalpha I/O flag on  
  
   cout << "Original deque:\n d1 = ( " ;  
   for ( iter1 = d1.begin( ) ; iter1 != d1.end( ) ; iter1++ )  
      cout << *iter1 << " ";  
   cout << ")" << endl;  
  
   cout << "Original deque:\n d2 = ( " ;  
   for ( iter2 = d2.begin( ) ; iter2 != d2.end( ) ; iter2++ )  
      cout << *iter2 << " ";  
   cout << ")" << endl;  
  
   // To find element-wise disjunction of the truth values  
   // of d1 & d2, use the logical_or function object  
   transform( d1.begin( ), d1.end( ), d2.begin( ),  
      d3.begin( ), logical_or<bool>( ) );  
   cout << "The deque which is the disjuction of d1 & d2 is:\n d3 = ( " ;  
   for ( iter3 = d3.begin( ) ; iter3 != d3.end( ) ; iter3++ )  
      cout << *iter3 << " ";  
   cout << ")" << endl;  
}  
```  
  
  **Deque original:**  
 **d1 \= false \(false true false true false true\)**  
**Deque original:**  
 **d2 \= true \(true false true false false retificam\)**  
**O deque que é o disjuction de d1 & d2 é:**  
 **d3 \= true \(true true false true retificam true\)**   
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)