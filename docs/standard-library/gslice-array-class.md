---
title: "Classe gslice_array | Microsoft Docs"
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
  - "std::gslice_array"
  - "gslice_array"
  - "valarray/std::gslice_array"
  - "std.gslice_array"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe gslice_array"
ms.assetid: ad1b4514-b14a-4baf-a293-d5a8e8674c75
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe gslice_array
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe interna, auxiliar de modelo que oferecem suporte a fatia geral objetos fornecendo operações entre as matrizes de subconjunto definidas pela fatia geral de um valarray.  
  
## Sintaxe  
  
```  
template<class Type>  
   class gslice_array : public gsplice {  
public:  
   typedef Type value_type;  
   void operator=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator=(  
      const Type& x  
   ) const;  
  
   void operator*=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator/=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator%=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator+=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator-=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator^=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator&=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator|=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator<<=(  
      const valarray<Type>& x  
   ) const;  
  
   void operator>>=(  
      const valarray<Type>& x  
   ) const;  
  
// The rest is private or implementation defined  
}  
```  
  
## Comentários  
 A classe descreve um objeto que armazena uma referência a um objeto **va** da classe [valarray](../standard-library/valarray-class.md)**\<Tipo\>**, junto com um objeto **gs** da classe [gslice](../Topic/gslice%20Class.md) que descreve a sequência de elementos para selecionar do objeto de **valarray\<Type\>** .  
  
 Cria um objeto de **gslice\_array\<Type\>** somente escrevendo uma expressão de formato [va &#91;gs&#93;](../Topic/valarray::operator.md).  As funções de membro da classe gslice\_array se comportam como as assinaturas correspondentes de função definidas para **valarray\<Type\>**, com exceção de que somente a sequência de elementos selecionados é afetada.  
  
 A classe do modelo é criada indiretamente por determinadas operações valarray e não pode ser usada diretamente no programa.  Uma classe auxiliar interna do modelo é usado pelo operador subscrito de fatias:  
  
 ::\<`operator[]` \> de`gslice_array`\<**Tipo**\>`valarray`**Tipo**\(**const gslice&**\).  
  
 Cria um objeto de **gslice\_array\<Type\>** somente escrevendo uma expressão de formato **va\[gsl\]**, para uma fatia **gsl** de **va**valarray.  As funções de membro da classe gslice\_array se comportam como as assinaturas correspondentes de função definidas para **valarray\<Type\>**, com exceção de que somente a sequência de elementos selecionados é afetada.  A sequência controlada por gslice\_array é definida pelos três parâmetros do construtor de intervalo, do índice do primeiro elemento da primeira fatia, o número de elementos em cada fatia, e a distância entre os elementos em cada fatia.  
  
 No exemplo a seguir:  
  
```  
const size_t lv[] = {2, 3};  
const size_t dv[] = {7, 2};  
const valarray<size_t> len(lv, 2), str(dv, 2);  
// va[gslice(3, len, str)] selects elements with  
//   indices 3, 5, 7, 10, 12, 14  
```  
  
 Os índices devem ser válidas para que o procedimento seja válidos.  
  
## Exemplo  
 Consulte o exemplo de [gslice::gslice](../Topic/gslice::gslice.md) para obter um exemplo de como declarar e usar um slice\_array.  
  
## Requisitos  
 **Cabeçalho:** \<valarray\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)