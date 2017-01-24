---
title: "Classe insert_iterator | Microsoft Docs"
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
  - "std::insert_iterator"
  - "iterator/std::insert_iterator"
  - "std.insert_iterator"
  - "insert_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe insert_iterator"
  - "Classe insert_iterator, sintaxe"
ms.assetid: d5d86405-872e-4e3b-9e68-c69a2b7e8221
caps.latest.revision: 17
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe insert_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um adaptador de iterador que atende aos requisitos de um iterador de saída.  Insere, em vez de substituições, elementos em uma sequência e, dessa forma, fornece semânticas que são diferentes da semântica de substituição fornecida pelos iteradores dos contêineres associativos e de sequência do C\+\+.  A classe `insert_iterator` é modelada no tipo do contêiner que está sendo adaptado.  
  
## Sintaxe  
  
```  
template <class Container> class insert_iterator;  
```  
  
#### Parâmetros  
 `Container`  
 O tipo de contêiner no qual os elementos deverão ser inseridos por um `insert_iterator`.  
  
## Comentários  
 O contêiner do tipo **Container** deve atender aos requisitos de um contêiner de tamanho variável e ter uma função membro de inserção de dois argumentos, em que os parâmetros sejam do tipo **Container::iterator** e **Container::value\_type** e que retorne um tipo **Container::iterator**.  Os contêineres associativos classificados e de sequência da Biblioteca de Modelos Padrão atendem a esses requisitos e podem ser adaptados para uso com `insert_iterator`s.  Para contêineres associativos, o argumento de posição é tratado como uma dica, que tem o potencial de aumentar ou degradar o desempenho, dependendo da qualidade da dica.  Um `insert_iterator` sempre deve ser inicializado com seu contêiner.  
  
### Construtores  
  
|||  
|-|-|  
|[insert\_iterator](../Topic/insert_iterator::insert_iterator.md)|Constrói um `insert_iterator` que insere um elemento em uma posição especificada em um contêiner.|  
  
### Typedefs  
  
|||  
|-|-|  
|[container\_type](../Topic/insert_iterator::container_type.md)|Um tipo que representa o contêiner no qual uma inserção geral deve ser feita.|  
|[reference](../Topic/insert_iterator::reference.md)|Um tipo que fornece uma referência a um elemento em uma sequência controlada pelo contêiner associado.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*](../Topic/insert_iterator::operator*.md)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída \*`i` \= `x` para uma inserção geral.|  
|[operator\+\+](../Topic/insert_iterator::operator++.md)|Incrementa o `insert_iterator` para o próximo local no qual um valor pode ser armazenado.|  
|[operator\=](../Topic/insert_iterator::operator=.md)|Operador de atribuição usado para implementar a expressão do iterador de saída \*`i` \= `x` para uma inserção geral.|  
  
## Requisitos  
 **Cabeçalho**: \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)