---
title: "Classe tuple | Microsoft Docs"
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
  - "tr1::tuple"
  - "std.tr1.tuple"
  - "tuple"
  - "tr1.tuple"
  - "std::tr1::tuple"
  - "tuple/std::tr1::tuple"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe tuple"
  - "Classe tuple [TR1]"
ms.assetid: c38749be-ae4d-41f3-98ea-6aa3250de9a3
caps.latest.revision: 19
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe tuple
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Envolve uma sequência de comprimento fixo de elementos.  
  
## Sintaxe  
  
```  
template<class T1, class T2, ..., class TN>  
class tuple {  
public:  
    tuple();  
    explicit tuple(P1, P2, ..., PN);              // 0 < N  
    tuple(const tuple&);  
    template <class U1, class U2, ..., class UN>  
        tuple(const tuple<U1, U2, ..., UN>&);  
    template <class U1, class U2>  
        tuple(const pair<U1, U2>&);               // N == 2  
    void swap(tuple& right);  
    tuple& operator=(const tuple&);  
    template <class U1, class U2, ..., class UN>  
        tuple& operator=(const tuple<U1, U2, ..., UN>&);  
    template <class U1, class U2>  
        tuple& operator=(const pair<U1, U2>&);    // N == 2  
    };  
```  
  
#### Parâmetros  
 `TN`  
 O tipo do Nth elemento tuple.  
  
## Comentários  
 A classe do modelo descreve um objeto que armazena objetos do Em tipos `T1`, `T2`,…, `TN`, respectivamente, onde onde `0 <= N <= Nmax`.  A extensão de uma instância `tuple<T1, T2, ..., TN>` de tupla é o número `N` de seus argumentos do modelo.  O índice do argumento `Ti` do modelo e o valor armazenado correspondente desse tipo é `i - 1`.  Portanto, quando é numerarmos os tipos de 1 a N nesta documentação, o intervalo de correspondência dos valores de índice de 0 a N \- 1.  
  
## Exemplo  
  
```  
// tuple.cpp  
// compile with: /EHsc  
  
#include <vector>  
#include <iomanip>  
#include <iostream>  
#include <tuple>  
#include <string>  
  
using namespace std;  
  
typedef tuple <int, double, string> ids;  
  
void print_ids(const ids& i)  
{  
   cout << "( "  
        << get<0>(i) << ", "   
        << get<1>(i) << ", "   
        << get<2>(i) << " )." << endl;  
}  
  
int main( )  
{  
   // Using the constructor to declare and initialize a tuple  
   ids p1(10, 1.1e-2, "one");  
  
   // Compare using the helper function to declare and initialize a tuple  
   ids p2;  
   p2 = make_tuple(10, 2.22e-1, "two");  
  
   // Making a copy of a tuple  
   ids p3(p1);  
  
   cout.precision(3);  
   cout << "The tuple p1 is: ( ";  
   print_ids(p1);  
   cout << "The tuple p2 is: ( ";  
   print_ids(p2);  
   cout << "The tuple p3 is: ( ";  
   print_ids(p3);  
  
   vector<ids> v;  
  
   v.push_back(p1);  
   v.push_back(p2);  
   v.push_back(make_tuple(3, 3.3e-2, "three"));  
  
   cout << "The tuples in the vector are" << endl;  
   for(vector<ids>::const_iterator i = v.begin(); i != v.end(); ++i)  
   {  
      print_ids(*i);  
   }  
}  
```  
  
  **A tupla p1 é: \(10, 0,011, um\).**  
**A tupla p2 é: \(10, 0,222, os dois\).**  
**A tupla p3 é: \(10, 0,011, um\).**  
**As tuplas no vetor são**  
**\(10, 0,011, um\).**  
**\(10, 0,222, os dois\).**  
**\(3, 0,033, três\).**   
## Requisitos  
 tupla \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<tuple\>](../standard-library/tuple.md)   
 [Função make\_tuple](../Topic/make_tuple%20Function.md)