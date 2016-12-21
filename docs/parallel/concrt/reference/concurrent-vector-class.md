---
title: "Classe concurrent_vector | Microsoft Docs"
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
  - "concurrent_vector/Concurrency::concurrent_vector"
  - "concurrent_vector/concurrency::concurrent_vector"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe concurrent_vector"
ms.assetid: a217b4ac-af2b-4d41-94eb-09a75ee28622
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe concurrent_vector
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `concurrent_vector` é uma classe do contêiner de sequência que permite de acesso aleatório a qualquer elemento.  Habilita simultaneidade\- seguro, anexa acesso do elemento, o acesso de iterador, e operações de passagem do iterador.  
  
## Sintaxe  
  
```  
template<  
   typename _Ty,  
   class _Ax  
>  
class concurrent_vector: protected details::_Allocator_base<_Ty, _Ax>, private details::_Concurrent_vector_base_v4;  
```  
  
#### Parâmetros  
 `_Ty`  
 O tipo de dados dos elementos a serem armazenados no vetor.  
  
 `_Ax`  
 O tipo que representa o objeto armazenado do alocador que encapsula os detalhes sobre a alocação e a desalocação de memória para o vetor simultâneo.  Esse argumento é opcional e o valor padrão é `allocator<``_Ty``>`.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`allocator_type`|Um tipo que representa a classe do alocador do vetor simultâneo.|  
|`const_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler um elemento de `const` em um vetor simultâneo.|  
|`const_pointer`|Um tipo que fornece um ponteiro para um elemento de `const` em um vetor simultâneo.|  
|`const_reference`|Um tipo que fornece uma referência a um elemento de `const` armazenados em um vetor simultânea para ler e executar operações de `const` .|  
|`const_reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que possa ser lido por qualquer elemento de `const` no vetor simultâneo.|  
|`difference_type`|Um tipo que fornece a distância assinado entre dois elementos em um vetor simultâneo.|  
|`iterator`|Um tipo que fornece um iterador de acesso aleatório que possa ser lido por qualquer elemento em um vetor simultâneo.  A alteração de um elemento que usa o iterador não é simultaneidade\-segura.|  
|`pointer`|Um tipo que fornece um ponteiro para um elemento em um vetor simultâneo.|  
|`reference`|Um tipo que fornece uma referência a um elemento armazenados em um vetor simultâneo.|  
|`reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que possa ser lido por qualquer elemento em um vetor simultânea de reversão.  A alteração de um elemento que usa o iterador não é simultaneidade\-segura.|  
|`size_type`|Um tipo que conta o número de elementos em um vetor simultâneo.|  
|`value_type`|Um tipo que representa o tipo de dados armazenados em um vetor simultâneo.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor concurrent\_vector::concurrent\_vector](../Topic/concurrent_vector::concurrent_vector%20Constructor.md)|Sobrecarregado.  Constrói um vetor simultâneo.|  
|[Destruidor concurrent\_vector::~concurrent\_vector](../Topic/concurrent_vector::~concurrent_vector%20Destructor.md)|Apaga todos os elementos e destrói este vetor simultâneo.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método concurrent\_vector::assign](../Topic/concurrent_vector::assign%20Method.md)|Sobrecarregado.  Apaga os elementos de vetor simultâneos e atribui ou cópias de `_N` de `_Item`, ou os valores especificados pelo iterador variam \[`_Begin`, `_End`\).  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::at](../Topic/concurrent_vector::at%20Method.md)|Sobrecarregado.  Fornece acesso ao elemento no índice especificado no vetor simultâneo.  Esse método é simultaneidade\- seguro para operações de leitura, e também ao cultivar o vetor, desde que você tiver assegurado que o valor `_Index` é menor que o tamanho de vetor simultâneo.|  
|[Método concurrent\_vector::back](../Topic/concurrent_vector::back%20Method.md)|Sobrecarregado.  Retorna uma referência ou uma referência de `const` ao elemento o mais recente no vetor simultâneo.  Se o vetor simultânea estiver vazia, o valor de retorno será indefinido.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::begin](../Topic/concurrent_vector::begin%20Method.md)|Sobrecarregado.  Retorna um iterador do tipo `iterator` ou `const_iterator` ao início do vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::capacity](../Topic/concurrent_vector::capacity%20Method.md)|Retorna o tamanho máximo que o vetor simultânea pode ficar sem precisar alocar mais memória.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::cbegin](../Topic/concurrent_vector::cbegin%20Method.md)|Retorna um iterador do tipo `const_iterator` ao início do vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::cend](../Topic/concurrent_vector::cend%20Method.md)|Retorna um iterador do tipo `const_iterator` ao final de vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::clear](../Topic/concurrent_vector::clear%20Method.md)|Apaga todos os elementos no vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::crbegin](../Topic/concurrent_vector::crbegin%20Method.md)|Retorna um iterador do tipo `const_reverse_iterator` ao início do vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::crend](../Topic/concurrent_vector::crend%20Method.md)|Retorna um iterador do tipo `const_reverse_iterator` ao final de vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::empty](../Topic/concurrent_vector::empty%20Method.md)|Os testa se o vetor simultânea estiver vazia no momento em que esse método são chamados.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::end](../Topic/concurrent_vector::end%20Method.md)|Sobrecarregado.  Retorna um iterador do tipo `iterator` ou `const_iterator` ao final de vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::front](../Topic/concurrent_vector::front%20Method.md)|Sobrecarregado.  Retorna uma referência ou uma referência de `const` ao primeiro elemento no vetor simultâneo.  Se o vetor simultânea estiver vazia, o valor de retorno será indefinido.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::get\_allocator](../Topic/concurrent_vector::get_allocator%20Method.md)|Retorna uma cópia do alocador usado para construir o vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::grow\_by](../Topic/concurrent_vector::grow_by%20Method.md)|Sobrecarregado.  Este crescerá vetor simultânea os elementos de `_Delta` .  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::grow\_to\_at\_least](../Topic/concurrent_vector::grow_to_at_least%20Method.md)|Este crescerá vetor simultânea até que tenha pelo menos os elementos de `_N` .  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::max\_size](../Topic/concurrent_vector::max_size%20Method.md)|Retorna o número máximo de elementos que o vetor simultânea pode conter.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::push\_back](../Topic/concurrent_vector::push_back%20Method.md)|Sobrecarregado.  Adiciona o item específico ao final de vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::rbegin](../Topic/concurrent_vector::rbegin%20Method.md)|Sobrecarregado.  Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao início do vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::rend](../Topic/concurrent_vector::rend%20Method.md)|Sobrecarregado.  Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final de vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::reserve](../Topic/concurrent_vector::reserve%20Method.md)|Aloca espaço suficiente para atingir o vetor simultânea para dimensionar `_N` sem precisar alocar mais memória posteriormente.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::resize](../Topic/concurrent_vector::resize%20Method.md)|Sobrecarregado.  Altera o tamanho de vetor simultânea ao tamanho solicitado, excluindo ou adicionando elementos conforme necessário.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::shrink\_to\_fit](../Topic/concurrent_vector::shrink_to_fit%20Method.md)|Compacta a representação interna de vetor simultânea para reduzir a fragmentação e otimizar o uso da memória.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::size](../Topic/concurrent_vector::size%20Method.md)|Retorna o número de elementos no vetor simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_vector::swap](../Topic/concurrent_vector::swap%20Method.md)|Alterna o conteúdo de dois vetores simultâneas.  Este método não é seguro em simultaneidade.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador concurrent\_vector::operator](../Topic/concurrent_vector::operatorOperator.md)|Sobrecarregado.  Fornece acesso ao elemento no índice especificado no vetor simultâneo.  Esse método é simultaneidade\- seguro para operações de leitura, e também ao cultivar o vetor, desde que você tiver assegurado que o valor `_Index` é menor que o tamanho de vetor simultâneo.|  
|[Operador concurrent\_vector::operator\=](../Topic/concurrent_vector::operator=%20Operator.md)|Sobrecarregado.  Atribui o conteúdo de outro objeto `concurrent_vector` nesse.  Este método não é seguro em simultaneidade.|  
  
## Comentários  
 Para obter informações detalhadas sobre a classe `concurrent_vector`, consulte [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## Hierarquia de Herança  
 `_Concurrent_vector_base_v4`  
  
 `_Allocator_base`  
  
 `concurrent_vector`  
  
## Requisitos  
 **Cabeçalho:** concurrent\_vector.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)