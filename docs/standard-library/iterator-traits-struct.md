---
title: "Struct iterator_traits | Microsoft Docs"
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
  - "std::iterator_traits"
  - "xutility/std::iterator_traits"
  - "iterator_traits"
  - "std.iterator_traits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe iterator_traits"
  - "Struct iterator_traits"
ms.assetid: 8b92c2c5-f658-402f-8ca1-e7ae301b8514
caps.latest.revision: 19
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct iterator_traits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma estrutura de auxiliar do modelo usado para especificar todas as definições de tipo críticos que um iterador deve ter.  
  
## Sintaxe  
  
```  
template<class Iterator>  
    struct iterator_traits {  
        typedef typename Iterator::iterator_category iterator_category;  
        typedef typename Iterator::value_type value_type;  
        typedef typename Iterator::difference_type difference_type;  
        typedef difference_type distance_type;  
        typedef typename Iterator::pointer pointer;  
        typedef typename Iterator::reference reference;  
    };  
template<class Type>  
    struct iterator_traits<Type*> {  
        typedef random_access_iterator_tag iterator_category;  
        typedef Type value_type;  
        typedef ptrdiff_t difference_type;  
        typedef difference_type distance_type;  
        typedef Type *pointer;  
        typedef Type& reference;  
    };  
template<class Type>  
    struct iterator_traits<const Type*> {  
        typedef random_access_iterator_tag iterator_category;  
        typedef Type value_type;  
        typedef ptrdiff_t difference_type;  
        typedef difference_type distance_type;  
        typedef const Type *pointer;  
        typedef const Type& reference;  
    };  
```  
  
## Comentários  
 O struct do modelo define os tipos de membro  
  
-   **iterator\_category**: um sinônimo para **Iterator::iterator\_category**.  
  
-   `value_type`: um sinônimo para **Iterator::value\_type**.  
  
-   `difference_type`: um sinônimo para **Iterator::difference\_type**.  
  
-   `distance_type`: um sinônimo para **Iterator::difference\_type.**  
  
-   **pointer**: um sinônimo para **Iterator::pointer**.  
  
-   **reference**: um sinônimo para **Iterator::reference**.  
  
 As especializações parciais determinam os tipos importantes associados a um ponteiro de objeto do tipo **Type \*** ou de const **Type \***.  
  
 Nessa implementação você também pode usar várias funções de modelo que não utilizam a especialização parcial:  
  
```  
template<class Category, class Type, class Diff>  
C _Iter_cat(const iterator<Category, Ty, Diff>&);  
template<class Ty>  
    random_access_iterator_tag _Iter_cat(const Ty *);  
  
template<class Category, class Ty, class Diff>  
Ty *_Val_type(const iterator<Category, Ty, Diff>&);  
template<class Ty>  
    Ty *_Val_type(const Ty *);  
  
template<class Category, class Ty, class Diff>  
Diff *_Dist_type(const iterator<Category, Ty, Diff>&);  
template<class Ty>  
    ptrdiff_t *_Dist_type(const Ty *);  
```  
  
 determinam quais vários tipos dos mesmos mais indiretamente.  Você usa estas funções como argumentos em uma chamada de função.  Seu único propósito é fornecer um parâmetro de classe útil do modelo para a função chamada.  
  
## Exemplo  
  
```  
// iterator_traits.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <iterator>  
#include <vector>  
#include <list>  
  
using namespace std;  
  
template< class it >  
void  
function( it i1, it i2 )  
{  
   iterator_traits<it>::iterator_category cat;  
   cout << typeid( cat ).name( ) << endl;  
   while ( i1 != i2 )  
   {  
      iterator_traits<it>::value_type x;  
      x = *i1;  
      cout << x << " ";  
      i1++;  
   };     
   cout << endl;  
};  
  
int main( )   
{  
   vector<char> vc( 10,'a' );  
   list<int> li( 10 );  
   function( vc.begin( ), vc.end( ) );  
   function( li.begin( ), li.end( ) );  
}  
```  
  
  **std::random\_access\_iterator\_tag da estrutura**  
**a um**   
**std::bidirectional\_iterator\_tag da estrutura**  
**0 0 0 0 0 0 0 0 0 0**    
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)