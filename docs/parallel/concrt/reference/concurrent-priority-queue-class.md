---
title: "Classe concurrent_priority_queue | Microsoft Docs"
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
  - "concurrent_priority_queue/concurrency::concurrent_priority_queue"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe concurrent_priority_queue"
ms.assetid: 3e740381-0f4e-41fc-8b66-ad0bb55f17a3
caps.latest.revision: 9
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe concurrent_priority_queue
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `concurrent_priority_queue` é um contêiner que permite que vários threads simultaneamente empurrem e itens aparecem.  Os itens são aparecidos em ordem de prioridade em que a prioridade é determinada por um funtor fornecido como um argumento do modelo.  
  
## Sintaxe  
  
```  
template <  
   typename _Ty,  
   typename _Compare=std::less<_Ty>,  
   typename _Ax = std::allocator<_Ty>  
>  
, typename _Ax = std::allocator<_Ty> > class concurrent_priority_queue;  
```  
  
#### Parâmetros  
 `_Ty`  
 O tipo de dados dos elementos a serem armazenados na fila de prioridade.  
  
 `_Compare`  
 O tipo de objeto de função que pode comparar dois valores do elemento como chaves de tipo para determinar a ordem relativa na fila de prioridade.  Esse argumento é opcional e o predicado binário `less<``_Ty``>` é o valor padrão.  
  
 `_Ax`  
 O tipo que representa o objeto armazenado do alocador que encapsula detalhes sobre alocação e a desalocação de memória para a fila de prioridade simultâneo.  Esse argumento é opcional e o valor padrão é `allocator<``_Ty``>`.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`allocator_type`|Um tipo que representa a classe do alocador para a fila de prioridade simultâneo.|  
|`const_reference`|Um tipo que representa uma referência de const a um elemento do tipo armazenadas em uma fila de prioridade simultâneo.|  
|`reference`|Um tipo que representa uma referência a um elemento do tipo armazenadas em uma fila de prioridade simultâneo.|  
|`size_type`|Um tipo que conta o número de elementos em uma fila de prioridade simultâneo.|  
|`value_type`|Um tipo que representa o tipo de dados armazenados em uma fila de prioridade simultâneo.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor concurrent\_priority\_queue::concurrent\_priority\_queue](../Topic/concurrent_priority_queue::concurrent_priority_queue%20Constructor.md)|Sobrecarregado.  Constrói uma fila de prioridade simultâneo.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método concurrent\_priority\_queue::clear](../Topic/concurrent_priority_queue::clear%20Method.md)|Apaga todos os elementos na prioridade simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_priority\_queue::empty](../Topic/concurrent_priority_queue::empty%20Method.md)|Os testa se a fila de prioridade simultânea estiver vazia no momento em que esse método são chamados.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_priority\_queue::get\_allocator](../Topic/concurrent_priority_queue::get_allocator%20Method.md)|Retorna uma cópia do alocador usado para construir a fila de prioridade simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_priority\_queue::push](../Topic/concurrent_priority_queue::push%20Method.md)|Sobrecarregado.  Adiciona um elemento à fila de prioridade simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_priority\_queue::size](../Topic/concurrent_priority_queue::size%20Method.md)|Retorna o número de elementos na fila de prioridade simultâneo.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_priority\_queue::swap](../Topic/concurrent_priority_queue::swap%20Method.md)|Alterna o conteúdo de duas filas de prioridade simultâneas.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_priority\_queue::try\_pop](../Topic/concurrent_priority_queue::try_pop%20Method.md)|Remove e retorna o elemento a prioridade mais alta da fila se a fila está vazio.  Este método não é seguro em simultaneidade.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador concurrent\_priority\_queue::operator\=](../Topic/concurrent_priority_queue::operator=%20Operator.md)|Sobrecarregado.  Atribui o conteúdo de outro objeto `concurrent_priority_queue` nesse.  Este método não é seguro em simultaneidade.|  
  
## Comentários  
 Para obter informações detalhadas sobre a classe `concurrent_priority_queue`, consulte [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## Hierarquia de Herança  
 `concurrent_priority_queue`  
  
## Requisitos  
 **Cabeçalho:** concurrent\_priority\_queue.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)