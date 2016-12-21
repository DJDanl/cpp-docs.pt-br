---
title: "Classe &lt; utility &gt; tuple_element | Microsoft Docs"
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
  - "Classe < utility > (TR1) tuple_element"
ms.assetid: f9db79e8-685c-49e3-97ee-81763e516ce3
caps.latest.revision: 20
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe &lt; utility &gt; tuple_element
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Encapsula o tipo de um `pair` elemento.  
  
## Sintaxe  
  
```  
// CLASS tuple_element (find element by index)  
template<size_t Index, class Tuple>  
struct tuple_element;  
  
// struct to determine type of element 0 in pair  
template<class Ty1, class Ty2>  
struct tuple_element<0, pair<Ty1, Ty2> >;  
  
// struct to determine type of element 1 in pair  
template<class Ty1, class Ty2>  
struct tuple_element<1, pair<Ty1, Ty2> >;  
  
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
  
#### Parâmetros  
 Índice  
 A posição do elemento; par esse valor é 0 ou 1.  
  
 `T1`  
 O tipo do primeiro elemento do par.  
  
 `T2`  
 O tipo do segundo elemento do par.  
  
 tipo  
  
## Comentários  
 Os modelos são especializações da classe modelo [Classe tuple\_element](../standard-library/tuple-element-class-tuple.md). Cada um tem um único membro typedef, `type`, que é um sinônimo para o tipo de elemento na posição especificada no `pair`, com qualquer qualificações constantes e\/ou voláteis preservadas.`tuple_element_t` é um alias conveniente para `tuple_element<N, pair<T1, T2>>::type`. Use o [Função get](../Topic/get%20Function%20%3Cutility%3E.md) para retornar o elemento em uma posição especificada ou \(no C \+ \+ 14 \/ Visual Studio 2015\) de um tipo especificado.  
  
## Exemplo  
  
```  
#include <utility>   
#include <iostream>   
  
using namespace std;  
  
typedef pair<int, double> MyPair;  
int main()  
{  
    MyPair c0(0, 1.333);  
  
    // display contents " 0 1"   
    cout << " " << get<0>(c0);  
    cout << " " << get<1>(c0) << endl;  
  
    // display first element " 0" by index  
    tuple_element<0, MyPair>::type val = get<0>(c0);  
    cout << " " << val;  
  
    // display second element by type   
    tuple_element<1, MyPair>::type val2 = get<double>(c0);  
    cout << " " << val2 << endl;  
}  
  
/*  
Output:  
0 1.333  
0 1.333  
*/  
```  
  
## Requisitos  
 **Cabeçalho:** \< utility \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<utility\>](../standard-library/utility.md)   
 [Função get](../Topic/get%20Function%20%3Cutility%3E.md)   
 [Classe tuple\_size](../standard-library/tuple-size-class-utility.md)