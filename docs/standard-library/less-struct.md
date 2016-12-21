---
title: "Struct less | Microsoft Docs"
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
  - "std::less"
  - "std.less"
  - "less"
  - "xfunctional/std::less"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Struct less"
  - "Função less"
ms.assetid: 39349da3-11cd-4774-b2cc-b46af5aae5d7
caps.latest.revision: 24
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct less
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um predicado binário que executa menor que a operação \(\)`operator<`em seus argumentos.  
  
## Sintaxe  
  
```  
template<class Type = void>  
   struct less : public binary_function <Type, Type, bool>   
   {  
      bool operator()(  
         const Type& Left,   
         const Type& Right  
      ) const;  
   };  
  
// specialized transparent functor for operator<  
template<>  
   struct less<void>  
   {  
      template<class Type1, class Type2>  
      auto operator()(Type1&& Left, Type2&& Right) const  
         -> decltype(std::forward<Type1>(Left)  
            < std::forward<Type2>(Right));  
   };  
  
```  
  
#### Parâmetros  
 `Type`, `Type1`, `Type2`  
 Qualquer tipo que ofereça suporte `operator<` que usa operandos dos tipos especificados ou inferidos.  
  
 `Left`  
 O operando esquerdo do menor que a operação.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type1`.  
  
 `Right`  
 O operando direito de menor que a operação.  O modelo unspecialized usa um argumento de referência de lvalue do tipo `Type`.  O modelo especializado aperfeiçoa a transmissão de argumentos de referência de lvalue e de rvalue de tipo inferido `Type2`.  
  
## Valor de retorno  
 O resultado de `Left``<``Right`.  O modelo especializado aperfeiçoa a transmissão de resultado, que contém o tipo que é retornado por `operator<`.  
  
## Comentários  
 O predicado`Type`\> fornece a ordenação binária `less`\<fraco restrito de um conjunto de valores do elemento do tipo `Type` em classes de equivalência, se e somente se este tipo satisfaz os requisitos matemáticos padrão para o seja ordenado.  As especializações para qualquer tipo de ponteiro gerenciem a ordenação global de elementos, que todos os elementos de valores distintos são colocados em relação às outras.  
  
## Exemplo  
  
```  
// functional_less.cpp  
// compile with: /EHsc  
#include <vector>  
#include <algorithm>  
#include <functional>  
#include <iostream>  
  
struct MyStruct {  
   MyStruct(int i) : m_i(i){}  
  
   bool operator < (const MyStruct & rhs) const {  
      return m_i < rhs.m_i;  
   }     
  
   int m_i;  
};  
  
int main() {  
   using namespace std;  
   vector <MyStruct> v1;  
   vector <MyStruct>::iterator Iter1;  
   vector <MyStruct>::reverse_iterator rIter1;  
  
   int i;  
   for ( i = 0 ; i < 7 ; i++ )       
       v1.push_back( MyStruct(rand()));  
  
   cout << "Original vector v1 = ( " ;  
   for ( Iter1 = v1.begin() ; Iter1 != v1.end() ; Iter1++ )   
cout << Iter1->m_i << " ";  
   cout << ")" << endl;  
  
   // To sort in ascending order,  
   sort( v1.begin( ), v1.end( ), less<MyStruct>());  
  
   cout << "Sorted vector v1 = ( " ;  
   for ( Iter1 = v1.begin() ; Iter1 != v1.end() ; Iter1++ )   
cout << Iter1->m_i << " ";  
   cout << ")" << endl;  
 }  
```  
  
## Saída  
  
```  
Original vector v1 = ( 41 18467 6334 26500 19169 15724 11478 )  
Sorted vector v1 = ( 41 6334 11478 15724 18467 19169 26500 )  
```  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)