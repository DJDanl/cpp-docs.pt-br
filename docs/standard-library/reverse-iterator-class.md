---
title: "Classe reverse_iterator | Microsoft Docs"
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
  - "reverse_iterator"
  - "std::reverse_iterator"
  - "std.reverse_iterator"
  - "xutility/std::reverse_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe reverse_iterator"
ms.assetid: c0b34d04-ae9a-4999-9aff-28b313897ffa
caps.latest.revision: 21
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe reverse_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo é um adaptador de iterador que descreve um objeto de iterador inverso que se comporta como um iterador bidirecional ou de acesso aleatório, somente em sentido inverso.  Ela permite a travessia regressiva de um intervalo.  
  
## Sintaxe  
  
```  
template <class RandomIterator>  
class reverse_iterator  
```  
  
#### Parâmetros  
 RandomIterator  
 O tipo que representa o iterador a ser adaptado para operar no sentido inverso.  
  
## Comentários  
 Os contêineres existentes da Biblioteca de Modelo Padrão também definem os tipos `reverse_iterator` e `const_reverse_iterator`, bem como possuem funções membro `rbegin` e `rend` que retornam iteradores inversos.  Esses iteradores apresentam semântica de substituição.  O adaptador `reverse_iterator` complementa essa funcionalidade, pois oferece semântica de inserção e também pode ser usado com fluxos.  
  
 Os `reverse_iterator`s que exigem um iterador bidirecional não devem chamar nenhuma das funções membro `operator+=`, `operator+`, `operator-=`, `operator-` ou `operator[]`, que podem ser usadas apenas com iteradores de acesso aleatório.  
  
 Se o intervalo de um iterador for \[`_First`, \_Last\), em que o colchete à esquerda indica a inclusão em \_*First* e o parêntese à direita indica a inclusão do elemento até \_*Left*, o próprio \_*Left*  será excluído.  Os mesmos elementos são incluídos na sequência invertida \[**rev** – `_First`, **rev** – \_*Left*\), de modo que, se \_*Left* for um elemento depois do fim em uma sequência, o primeiro elemento **rev** – \_*First* na sequência inversa apontará para \*\(\_*Left* – 1 \).  A identidade que relaciona a todos os iteradores inversos a seus iteradores subjacentes é:  
  
 &\*\(**reverse\_iterator** \( *i* \) \) \=\= &\*\( *i* – 1 \).  
  
 Na prática, isso significa que na sequência invertida, reverse\_iterator fará referência ao elemento que está uma posição depois \(à direita do\) do elemento ao qual o iterador se referiu na sequência original.  Desse modo, se um iterador tratou o elemento 6 na sequência \(2, 4, 6, 8\), `reverse_iterator` tratará o elemento 4 na sequência inversa \(8, 6, 4, 2\).  
  
### Construtores  
  
|||  
|-|-|  
|[reverse\_iterator](../Topic/reverse_iterator::reverse_iterator.md)|Constrói um `reverse_iterator` padrão ou um `reverse_iterator` de um iterador subjacente.|  
  
### Typedefs  
  
|||  
|-|-|  
|[difference\_type](../Topic/reverse_iterator::difference_type.md)|Um tipo que fornece a diferença entre dois `reverse_iterator`s que se referem a elementos no mesmo contêiner.|  
|[iterator\_type](../Topic/reverse_iterator::iterator_type.md)|Um tipo que fornece um iterador subjacente para um `reverse_iterator`.|  
|[pointer](../Topic/reverse_iterator::pointer.md)|Um tipo que fornece um ponteiro para um elemento tratado por um `reverse_iterator`.|  
|[reference](../Topic/reverse_iterator::reference.md)|Um tipo que fornece uma referência a um elemento tratado por um `reverse_iterator`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[base](../Topic/reverse_iterator::base.md)|Recupera o iterador subjacente de seu `reverse_iterator`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*](../Topic/reverse_iterator::operator*.md)|Retorna o elemento tratado por um `reverse_iterator`.|  
|[operator\+](../Topic/reverse_iterator::operator+.md)|Adiciona um deslocamento a um iterador e retorna o novo `reverse_iterator` que trata o elemento inserido na nova posição de deslocamento.|  
|[operator\+\+](../Topic/reverse_iterator::operator++.md)|Incrementa o `reverse_iterator` até o próximo elemento.|  
|[operator\+\=](../Topic/reverse_iterator::operator+=.md)|Adiciona um deslocamento especificado de um `reverse_iterator`.|  
|[operator\-](../Topic/reverse_iterator::operator-.md)|Subtrai um deslocamento de um `reverse_iterator` e retorna um `reverse_iterator` que trata o elemento na posição do deslocamento.|  
|[operator\-\-](../Topic/reverse_iterator::operator--.md)|Decrementa o `reverse_iterator` para o elemento anterior.|  
|[operator\-\=](../Topic/reverse_iterator::operator-=.md)|Subtrai um deslocamento especificado de um `reverse_iterator`.|  
|[operator\-\>](../Topic/reverse_iterator::operator-%3E.md)|Retorna um ponteiro para o elemento tratado pelo `reverse_iterator`.|  
|[operator&#91;&#93;](../Topic/reverse_iterator::operator.md)|Retorna uma referência a um deslocamento do elemento tratado por um `reverse_iterator` por um número especificado de posições.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)