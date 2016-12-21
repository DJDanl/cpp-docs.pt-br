---
title: "Classe slice_array | Microsoft Docs"
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
  - "slice_array"
  - "valarray/std::slice_array"
  - "std.slice_array"
  - "std::slice_array"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe slice_array"
ms.assetid: a182d5f7-f35c-4e76-86f2-b5ac64ddc846
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe slice_array
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe interna, auxiliar do modelo que da suporte a objetos do intervalo fornecendo operações entre as matrizes de subconjunto definido pela fração de um valarray.  
  
## Sintaxe  
  
```  
template<class Type>  
   class slice_array : public slice {  
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
 A classe descreve um objeto que armazena uma referência a um objeto da classe [valarray](../standard-library/valarray-class.md)**\<Tipo\>**, junto com um objeto da classe [fatia](../Topic/slice%20Class.md), que descreve a sequência de elementos para selecionar do objeto de **valarray\<Type\>** .  
  
 A classe do modelo é criada indiretamente por determinadas operações valarray e não pode ser usada diretamente no programa.  Uma classe interna, auxiliar de modelo usada pelo operador subscrito de fatias:  
  
 ::\<`operator[]` \> de`slice_array`\<**Tipo**`valarray`**Tipo**\(`slice`\).  
  
 Cria um objeto de **slice\_array\<Type\>** somente escrevendo uma expressão de formato [SL va &#91;&#93;](../Topic/valarray::operator.md), para uma fatia **sl** de **va**valarray.  As funções de membro da classe slice\_array se comportam como as assinaturas correspondentes de função definidas para **valarray\<Type\>**, com exceção de que somente a sequência de elementos selecionados é afetada.  A sequência controlada por slice\_array é definida pelos três parâmetros do construtor de intervalo, do índice do primeiro elemento da fatia, o número de elementos, e a distância entre os elementos.  Um slice\_array divisão de **va** valarray declarado por **va**\[`slice`\(2, 5, 3\)\] seleciona os elementos com índices, 2, 5, 8, 11 e 14 de **va**.  Os índices devem ser válidas para que o procedimento seja válidos.  
  
## Exemplo  
 Consulte o exemplo de [slice::slice](../Topic/slice::slice.md) para obter um exemplo de como declarar e usar um slice\_array.  
  
## Requisitos  
 **Cabeçalho:** \<valarray\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)