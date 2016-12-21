---
title: "Classe tuple_size &lt; array &gt; | Microsoft Docs"
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
  - "Classe tuple_size < array > (TR1)"
ms.assetid: ef95ffee-59b4-4396-817f-487d4486772d
caps.latest.revision: 20
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe tuple_size &lt; array &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ajusta o tamanho de uma matriz.  
  
## Sintaxe  
  
```  
template<class Tuple>  
struct tuple_size;  
  
// struct to determine number of elements in array  
template<class T, size_t Size>  
struct tuple_size<array<T, Size> >  
: integral_constant<size_t, Size>;  
  
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
  
## Parâmetros de modelo  
 `T`  
 O tipo de um elemento.  
  
 `Size`  
 O tamanho da matriz.  
  
## Comentários  
 Esse modelo é uma especialização da classe modelo [Classe tuple\_size](../standard-library/tuple-size-class-tuple.md). Ela tem um membro `value` que é uma expressão constante integral cujo valor é `N`, que é o tamanho da matriz.  
  
## Exemplo  
  
```  
#include <array>   
#include <iostream>   
  
using namespace std;  
  
typedef array<int, 4> MyArray;  
  
int main()  
{  
    MyArray c0 { 0, 1, 2, 3 };  
  
    // display contents " 0 1 2 3"   
    for (const auto& e : c0)  
    {  
        cout << e;  
    }  
    cout << endl;  
  
    // display size " 4"   
    cout << " " << tuple_size<MyArray>::value << endl;  
}  
/*  
Output:  
0123  
4  
*/  
  
```  
  
## Requisitos  
 **Cabeçalho:** \< array \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<array\>](../standard-library/array.md)   
 [\<tuple\>](../standard-library/tuple.md)   
 [Classe tuple\_size](../standard-library/tuple-size-class-tuple.md)