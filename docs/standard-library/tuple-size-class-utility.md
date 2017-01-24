---
title: "Classe &lt; utility &gt; tuple_size | Microsoft Docs"
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
  - "tuple_size"
  - "std::tr1::tuple_size"
  - "std.tr1.tuple_size"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "< utility > (TR1) da classe tuple_size"
ms.assetid: 36d04207-ed87-4c11-9875-150c59833b79
caps.latest.revision: 21
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe &lt; utility &gt; tuple_size
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Encapsula `pair` contagem do elemento.  
  
## Sintaxe  
  
```  
template<class Tuple>  
struct tuple_size;  
  
template<class T1, class T2>  
struct tuple_size<pair<T1, T2>>   : integral_constant<size_t, 2>  
  
// size of const tuple  
template<class Tuple>  
struct tuple_size<const Tuple>;  
  
// size of volatile tuple  
template<class Tuple>  
struct tuple_size<volatile Tuple>;  
  
// size of const volatile tuple  
template<class Tuple>  
struct tuple_size<const volatile Tuple>;  
```  
  
#### Parâmetros  
 `T1`  
 O tipo do primeiro elemento do par.  
  
 `T2`  
 O tipo do segundo elemento do par.  
  
## Comentários  
 O modelo é uma especialização da classe modelo [Classe tuple\_size](../standard-library/tuple-size-class-tuple.md). Ela tem um membro `value` que é uma expressão constante integral cujo valor é 2.  
  
## Exemplo  
  
```  
#include <utility>   
#include <iostream>   
  
using namespace std;  
  
typedef pair<int, double> MyPair;  
  
int main()  
{  
    MyPair c0(0, 1.1);  
  
    // display contents " 0 1.1"   
    cout << " " << get<0>(c0);  
    cout << " " << get<1>(c0) << endl;  
  
    // display size " 2"   
    cout << " " << tuple_size<MyPair>::value << endl;  
  
}  
  
/*  
Output:  
0 1.1  
2  
*/  
```  
  
## Requisitos  
 **Cabeçalho:** \< utility \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<utility\>](../standard-library/utility.md)   
 [Função get](../Topic/get%20Function%20%3Cutility%3E.md)   
 [Classe tuple\_element](../standard-library/tuple-element-class-utility.md)