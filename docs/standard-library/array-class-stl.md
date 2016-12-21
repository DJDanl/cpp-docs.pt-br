---
title: "Classe array (STL) | Microsoft Docs"
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
  - "array/std::tr1::array"
  - "std.tr1.array"
  - "array"
  - "std::tr1::array"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe array [TR1]"
ms.assetid: fdfd43a5-b2b5-4b9e-991f-93bf10fb4293
caps.latest.revision: 22
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe array (STL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla uma sequência de comprimento`N`de elementos do tipo`Ty`.  A sequência é armazenada como uma matriz de`Ty`contido na`array<Ty, N>`objeto.  
  
## Sintaxe  
  
```  
template<class Ty, std::size_t N>  
    class array;  
```  
  
#### Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Ty`|O tipo de um elemento.|  
|`N`|O número de elementos.|  
  
## Membros  
  
|||  
|-|-|  
|Definição do tipo|Descrição|  
|[array::const\_iterator](../Topic/array::const_iterator.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[array::const\_pointer](../Topic/array::const_pointer.md)|O tipo de um ponteiro de constante para um elemento.|  
|[array::const\_reference](../Topic/array::const_reference.md)|O tipo de uma referência de constante para um elemento.|  
|[array::const\_reverse\_iterator](../Topic/array::const_reverse_iterator.md)|O tipo de um iterador inverso constante para a sequência controlada.|  
|[array::difference\_type](../Topic/array::difference_type.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[array::iterator](../Topic/array::iterator.md)|O tipo de um iterador para a sequência controlada.|  
|[array::pointer](../Topic/array::pointer.md)|O tipo de um ponteiro para um elemento.|  
|[array::reference](../Topic/array::reference.md)|O tipo de uma referência para um elemento.|  
|[array::reverse\_iterator](../Topic/array::reverse_iterator.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[array::size\_type](../Topic/array::size_type.md)|O tipo de uma distância sem sinal entre dois elementos.|  
|[array::value\_type](../Topic/array::value_type.md)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[array::array](../Topic/array::array.md)|Constrói um objeto de matriz.|  
|[array::assign](../Topic/array::assign.md)|Substitui todos os elementos.|  
|[array::at](../Topic/array::at.md)|Acessa um elemento em uma posição especificada.|  
|[array::back](../Topic/array::back.md)|Acessa o último elemento.|  
|[array::begin](../Topic/array::begin.md)|Designa o início da sequência controlada.|  
|[array::cbegin](../Topic/array::cbegin.md)|Retorna um iterador const acesso aleatório para o primeiro elemento na matriz.|  
|[array::cend](../Topic/array::cend.md)|Retorna um iterador const acesso aleatório que aponta além do fim da matriz.|  
|[array::crbegin](../Topic/array::crbegin.md)|Retorna um iterador const para o primeiro elemento em uma matriz invertida.|  
|[array::crend](../Topic/array::crend.md)|Retorna um iterador const para o final de uma matriz invertida.|  
|[array::data](../Topic/array::data.md)|Obtém o endereço do primeiro elemento.|  
|[array::empty](../Topic/array::empty.md)|Testes se elementos estão presentes.|  
|[array::end](../Topic/array::end.md)|Designa o fim da sequência controlada.|  
|[array::fill](../Topic/array::fill.md)|Substitui todos os elementos com um valor especificado.|  
|[array::front](../Topic/array::front.md)|Acessa o primeiro elemento.|  
|[array::max\_size](../Topic/array::max_size.md)|Conta o número de elementos.|  
|[array::rbegin](../Topic/array::rbegin.md)|Designa o início da sequência controlada invertido.|  
|[array::rend](../Topic/array::rend.md)|Designa o fim da sequência controlada invertido.|  
|[array::size](../Topic/array::size.md)|Conta o número de elementos.|  
|[array::swap](../Topic/array::swap.md)|Alterna o conteúdo de dois contêineres.|  
  
|||  
|-|-|  
|Operador|Descrição|  
|[array::operator\=](../Topic/array::operator=.md)|Substitui a sequência controlada.|  
|[array::operator](../Topic/array::operator.md)|Acessa um elemento em uma posição especificada.|  
  
## Comentários  
 O tipo tem um construtor padrão`array()`e um operador de atribuição padrão`operator=`e atende aos requisitos de um`aggregate`.  Portanto, os objetos do tipo`array<Ty, N>`podem ser inicializados usando um inicializador de agregação.  Por exemplo,  
  
```  
array<int, 4> ai = { 1, 2, 3 };  
```  
  
 cria o objeto`ai`que contém inteiro quatro valores, inicializa os três primeiros elementos com os valores 1, 2 e 3, respectivamente e inicializa o quarto elemento como 0.  
  
## Requisitos  
 **Cabeçalho:** \<array\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<array\>](../standard-library/array.md)