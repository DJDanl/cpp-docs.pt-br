---
title: "Struct not_equal_to | Microsoft Docs"
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
  - "std.not_equal_to"
  - "std::not_equal_to"
  - "not_equal_to"
  - "xfunctional/std::not_equal_to"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função not_equal_to"
  - "Struct not_equal_to"
ms.assetid: 333fce09-4f51-44e0-ba26-533bccffd485
caps.latest.revision: 19
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct not_equal_to
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um predicado binário que executa a operação de desigualdade \(`operator!=`\) em seus argumentos.  
  
## Sintaxe  
  
```  
template<class Type = void>  
   struct not_equal_to : public binary_function<Type, Type, bool>   
   {  
      bool operator()(  
         const Type& Left,   
         const Type& Right  
      ) const;  
   };  
  
// specialized transparent functor for operator!=  
template<>  
   struct not_equal_to<void>  
   {  
      template<class Type1, class Type2>  
      auto operator()(Type1&& Left, Type2&& Right) const  
      -> decltype(std::forward<Type1>(Left)  
         != std::forward<Type2>(Right));  
   };  
  
```  
  
#### Parâmetros  
 `Type`, `Type1`, `Type2`  
 Qualquer tipo que ofereça suporte `operator!=` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo de uma operação de desigualdade.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type1`.  
  
 `Right`  
 O operando direito da operação de desigualdade.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type2`.  
  
## Valor de retorno  
 O resultado de `Left``!=``Right`.  O modelo especializado aperfeiçoa a transmissão de resultado, que contém o tipo que é retornado por `operator!=`.  
  
## Comentários  
 Os objetos do tipo `Type` devem ser igualdade\- comparáveis.  Isso exige que `operator!=` definida no conjunto de objetos satisfaz as propriedades matemáticas de uma relação de equivalência.  Todos os tipos numéricos internos e do ponteiro satisfazem esse requisito.  
  
## Exemplo  
  
```  
// functional_not_equal_to.cpp  
// compile with: /EHsc  
#include <vector>  
#include <functional>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
   vector <double> v1, v2, v3 (6);  
   vector <double>::iterator Iter1, Iter2, Iter3;  
  
   int i;  
   for ( i = 0 ; i <= 5 ; i+=2 )  
   {  
      v1.push_back( 2.0 *i );  
      v1.push_back( 2.0 * i + 1.0 );  
   }  
  
   int j;  
   for ( j = 0 ; j <= 5 ; j+=2 )  
   {  
      v2.push_back( - 2.0 * j );  
      v2.push_back( 2.0 * j + 1.0 );  
   }  
  
   cout << "The vector v1 = ( " ;  
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )  
      cout << *Iter1 << " ";  
   cout << ")" << endl;  
  
   cout << "The vector v2 = ( " ;  
   for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )  
      cout << *Iter2 << " ";  
   cout << ")" << endl;  
  
   // Testing for the element-wise equality between v1 & v2  
   transform ( v1.begin( ), v1.end( ), v2.begin( ), v3.begin ( ),   
      not_equal_to<double>( ) );  
  
   cout << "The result of the element-wise not_equal_to comparsion\n"  
      << "between v1 & v2 is: ( " ;  
   for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )  
      cout << *Iter3 << " ";  
   cout << ")" << endl;  
}  
```  
  
  **O vetor v1 \= \(0 1 4 5 8 9\)**  
**O vetor v2 \= \(\-0 1 \-4 5 \-8 9\)**  
**O resultado de comparsion elemento no not\_equal\_to**  
**entre v1 & v2 é: \(0 0 1 0 1 0\)**   
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)