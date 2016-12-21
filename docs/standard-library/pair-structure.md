---
title: "Estrutura pair | Microsoft Docs"
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
  - "utility/std::pair"
  - "pair"
  - "std::pair"
  - "std.pair"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe pair"
ms.assetid: 539d3d67-80a2-4170-b347-783495d42109
caps.latest.revision: 20
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura pair
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma estrutura que fornece a capacidade de tratar os dois objetos como um único objeto.  
  
## Sintaxe  
  
```  
template<class T1, class T2>  
   struct pair   
   {  
   typedef T1 first_type;  
   typedef T2 second_type;  
   T1 first;  
   T2 second;  
  
   constexpr pair( );  
   constexpr pair(  
      const T1& Val1,   
      const T2& Val2  
   );  
  
   template<class Other1, class Other2>  
      constexpr pair(  
         const pair<Other1, Other2>& Right  
      );  
  
template<class Other1, class Other2>  
      constexpr pair(  
        const pair <Other1 Val1, Other2 Val2>&& Right  
      );  
  
   template<class Other1, class Other2>  
      constexpr pair(  
         Other1&& Val1, Other2&& Val2  
      );  
   };  
```  
  
#### Parâmetros  
 `Val1`  
 Valor Inicializando o primeiro elemento da`pair`.  
  
 `Val2`  
 Valor Inicializando o segundo elemento de`pair`.  
  
 `Right`  
 Um par cujos valores serão usados para inicializar os elementos de outro par.  
  
## Valor de retorno  
 O primeiro construtor \(padrão\) inicializa o primeiro elemento do par ao padrão de tipo**T1**e o segundo elemento padrão do tipo**T2**.  
  
 O segundo construtor inicializa o primeiro elemento do par de`Val1`e o segundo para*Val2.*  
  
 O terceiro construtor \(modelo\) inicializa o primeiro elemento do par de`Right`.**primeiro**e o segundo para`Right`.**segunda**.  
  
 O quarto construtor inicializa o primeiro elemento do par de`Val1`e o segundo para*Val2*usando[Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## Comentários  
 A estrutura de modelo armazena um par de objetos do tipo**T1**e**T2**respectivamente.  O tipo**first\_type**é o mesmo que o parâmetro de modelo**T1**e o tipo**second\_type**é o mesmo que o parâmetro de modelo**T2**.  **T1**e**T2**cada precisa fornecer apenas um construtor padrão, um construtor de argumento único e um destruidor.  Todos os membros do tipo`pair`são públicos, como o tipo é declarado como um`struct`em vez de como um**classe**.  Os dois usos mais comuns para um par são tipos como retorno para funções que retornam dois valores e como elementos para as classes de contêiner associativo[classe map](../Topic/map%20Class.md)e[classe multimap](../standard-library/multimap-class.md)que tem uma chave e um tipo de valor associado a cada elemento.  O segundo atende aos requisitos de um contêiner de par associativo e tem um tipo de valor do formulário`pair`\<**const**`key_type``mapped_type`\>.  
  
## Exemplo  
  
```  
// utility_pair.cpp  
// compile with: /EHsc  
#include <utility>  
#include <map>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Using the constructor to declare and initialize a pair  
   pair <int, double> p1 ( 10, 1.1e-2 );  
  
   // Compare using the helper function to declare and initialize a pair  
   pair <int, double> p2;  
   p2 = make_pair ( 10, 2.22e-1 );  
  
   // Making a copy of a pair  
   pair <int, double> p3 ( p1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl;  
  
   // Using a pair for a map element  
   map <int, int> m1;  
   map <int, int>::iterator m1_Iter;  
  
   typedef pair <int, int> Map_Int_Pair;  
  
   m1.insert ( Map_Int_Pair ( 1, 10 ) );  
   m1.insert ( Map_Int_Pair ( 2, 20 ) );  
   m1.insert ( Map_Int_Pair ( 3, 30 ) );  
  
   cout << "The element pairs of the map m1 are:";  
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )  
      cout << " ( " << m1_Iter -> first << ", "  
           << m1_Iter -> second << " )";  
   cout   << "." << endl;  
  
   // Using pair as a return type for a function  
   pair< map<int,int>::iterator, bool > pr1, pr2;  
   pr1 = m1.insert ( Map_Int_Pair ( 4, 40 ) );  
   pr2 = m1.insert ( Map_Int_Pair (1, 10 ) );  
  
   if( pr1.second == true )  
   {  
      cout << "The element (4,40) was inserted successfully in m1."  
           << endl;  
   }  
   else     
   {  
      cout << "The element with a key value of\n"  
           << " ( (pr1.first) -> first ) = " << ( pr1.first ) -> first   
           << " is already in m1,\n so the insertion failed." << endl;  
   }  
  
   if( pr2.second == true )  
   {  
      cout << "The element (1,10) was inserted successfully in m1."  
           << endl;  
   }  
   else     
   {  
      cout << "The element with a key value of\n"  
           << " ( (pr2.first) -> first ) = " << ( pr2.first ) -> first   
           << " is already in m1,\n so the insertion failed." << endl;  
   }  
}  
```  
  
  **O p1 par é: \(10, 0.011\).  O p2 par é: \(10, 0.222\).  O par p3 é: \(10, 0.011\).  Os pares de elemento de m1 o mapa são: \(1, 10\) \(2, 20\) \(3, 30\).  O elemento \(4,40\) foi inserido com êxito no m1.  O elemento com um valor de chave**  
 **\(\(pr2.first\) \-\> primeiro\) \= 1 já está sendo m1,**  
 **a inserção de falha.**    
## Requisitos  
 **Cabeçalho:** \<utility\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Operador lógico de par](../misc/pair-logical-operator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)