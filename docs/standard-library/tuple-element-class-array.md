---
title: "Classe &lt; array &gt; tuple_element | Microsoft Docs"
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
  - "std.tr1.tuple_element"
  - "tuple_element"
  - "std::tr1::tuple_element"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe < array > (TR1) tuple_element"
ms.assetid: 99201ca4-190a-4d9e-9013-de95ddfe5901
caps.latest.revision: 21
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe &lt; array &gt; tuple_element
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Encapsula o tipo de um elemento de matriz.  
  
## Sintaxe  
  
```  
// CLASS tuple_element (find element by index)  
template<size_t Index, class Tuple>  
struct tuple_element;  
  
template<size_t Index, class T, size_t Size>  
struct tuple_element<Index, array<T, Size>>  
  
// tuple_element for const  
template<size_t Index, class Tuple>  
struct tuple_element<Index, const Tuple>;  
  
// tuple_element for volatile  
template<size_t Index, class Tuple>  
struct tuple_element<Index, volatile Tuple>;  
  
// tuple_element for const volatile  
template<size_t Index, class Tuple>  
struct tuple_element<Index, const volatile Tuple>;  
  
template<size_t Index, class Tuple>  
using tuple_element_t = typename tuple_element<Index, Tuple>::type;  
  
```  
  
## Parâmetros  
 `Index`  
 A posição do elemento.  
  
 `T`  
 O tipo de um elemento.  
  
 `N`  
 O tamanho da matriz.  
  
## Comentários  
 Essa classe de modelo é uma especialização da classe modelo [Classe tuple\_element](../standard-library/tuple-element-class-tuple.md) para matrizes. Essa classe fornece uma interface para uma matriz como uma tupla de N elementos, cada um deles tem o mesmo tipo. Cada especialização tem um typedef aninhado `type` que é um sinônimo para o tipo do `Index` elemento o `array`, com qualquer qualificações const volátil preservadas.  
  
## Exemplo  
  
```  
  
#include <array>   
#include <iostream>   
  
using namespace std;  
typedef array<int, 4> MyArray;  
  
int main()  
{  
    MyArray c0 { 0, 1, 2, 3 };  
  
    for (const auto& e : c0)  
    {  
        cout << " " << e;  
    }  
    cout << endl;  
  
    // display first element " 0"   
    tuple_element<0, MyArray>::type val = c0.front();  
    cout << " " << val << endl;  
}  
  
/*  
Output:  
0 1 2 3  
0  
*/  
  
```  
  
## Requisitos  
 **Cabeçalho:** \< array \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<array\>](../standard-library/array.md)   
 [\<tuple\>](../standard-library/tuple.md)   
 [Classe tuple\_element](../standard-library/tuple-element-class-tuple.md)