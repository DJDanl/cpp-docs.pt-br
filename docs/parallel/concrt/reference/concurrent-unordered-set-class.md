---
title: "Classe concurrent_unordered_set | Microsoft Docs"
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
  - "concurrent_unordered_set/concurrency::concurrent_unordered_set"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe concurrent_unordered_set"
ms.assetid: c61f9a9a-4fd9-491a-9251-e300737ecf4b
caps.latest.revision: 12
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe concurrent_unordered_set
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe `concurrent_unordered_set` é um contêiner protegido contra simultaneidade que controla uma sequência de comprimento variado de elementos do tipo \_Key\_type.  A sequência é representada em uma forma que permite acréscimo protegido contra simultaneidade, acesso de elemento, acesso de iterador e operações de passagem de iterador.  
  
## Sintaxe  
  
```  
template <  
   typename _Key_type,  
   typename _Hasher = std::tr1::hash<_Key_type>,  
   typename _Key_equality = std::equal_to<_Key_type>,  
   typename _Allocator_type = std::allocator<_Key_type>  
>  
, typename _Key_equality = std::equal_to<_Key_type>, typename _Allocator_type = std::allocator<_Key_type> > class concurrent_unordered_set : public details::_Concurrent_hash< details::_Concurrent_unordered_set_traits<_Key_type, details::_Hash_compare<_Key_type, _Hasher, _Key_equality>, _Allocator_type, false> >;  
```  
  
#### Parâmetros  
 `_Key_type`  
 O tipo principal.  
  
 `_Hasher`  
 O tipo de objeto da função hash.  Esse argumento é opcional e o valor padrão é `std::tr1::hash<``_Key_type``>`.  
  
 `_Key_equality`  
 O tipo de objeto da função de comparação de igualdade.  Esse argumento é opcional e o valor padrão é `std::equal_to<``_Key_type``>`.  
  
 `_Allocator_type`  
 O tipo que representa o objeto armazenado do alocador que encapsula os detalhes sobre a alocação e a desalocação de memória para o conjunto simultâneo não ordenado.  Esse argumento é opcional e o valor padrão é `std::allocator<``_Key_type``>`.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`allocator_type`|O tipo de um distribuidor para gerenciar o armazenamento.|  
|`const_iterator`|O tipo de um iterador de constante para a sequência controlada.|  
|`const_local_iterator`|O tipo de um iterador de compartimento de constante para a sequência controlada.|  
|`const_pointer`|O tipo de um ponteiro constante para um elemento.|  
|`const_reference`|O tipo de uma referência constante para um elemento.|  
|`difference_type`|O tipo de uma distância assinada entre dois elementos.|  
|`hasher`|O tipo da função hash.|  
|`iterator`|O tipo de um iterador para a sequência controlada.|  
|`key_equal`|O tipo da função de comparação.|  
|`key_type`|O tipo de uma chave classificação.|  
|`local_iterator`|O tipo de um iterador de compartimento de memória para a sequência controlada.|  
|`pointer`|O tipo de um ponteiro para um elemento.|  
|`reference`|O tipo de uma referência para um elemento.|  
|`size_type`|O tipo de uma distância não assinada entre dois elementos.|  
|`value_type`|O tipo de um elemento.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor concurrent\_unordered\_set::concurrent\_unordered\_set](../Topic/concurrent_unordered_set::concurrent_unordered_set%20Constructor.md)|Sobrecarregado.  Constrói um conjunto simultâneo não ordenado.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método concurrent\_unordered\_set::hash\_function](../Topic/concurrent_unordered_set::hash_function%20Method.md)|Retorna o objeto armazenado da função hash.|  
|[Método concurrent\_unordered\_set::insert](../Topic/concurrent_unordered_set::insert%20Method.md)|Sobrecarregado.  Adiciona elementos ao objeto `concurrent_unordered_set`.|  
|[Método concurrent\_unordered\_set::key\_eq](../Topic/concurrent_unordered_set::key_eq%20Method.md)|Retorna o objeto armazenado da função de comparação de igualdade.|  
|[Método concurrent\_unordered\_set::swap](../Topic/concurrent_unordered_set::swap%20Method.md)|Alterna o conteúdo de dois objetos de `concurrent_unordered_set` .  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_unordered\_set::unsafe\_erase](../Topic/concurrent_unordered_set::unsafe_erase%20Method.md)|Sobrecarregado.  Remove os elementos de `concurrent_unordered_set` em posições especificadas.  Este método não é seguro em simultaneidade.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador concurrent\_unordered\_set::operator\=](../Topic/concurrent_unordered_set::operator=%20Operator.md)|Sobrecarregado.  Atribui o conteúdo de outro objeto `concurrent_unordered_set` nesse.  Este método não é seguro em simultaneidade.|  
  
## Comentários  
 Para obter informações detalhadas sobre a classe `concurrent_unordered_set`, consulte [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## Hierarquia de Herança  
 `_Traits`  
  
 `_Concurrent_hash`  
  
 `concurrent_unordered_set`  
  
## Requisitos  
 **Cabeçalho:** concurrent\_unordered\_set.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)