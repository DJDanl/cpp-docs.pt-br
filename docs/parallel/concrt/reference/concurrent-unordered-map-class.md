---
title: "Classe concurrent_unordered_map | Microsoft Docs"
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
  - "concurrent_unordered_map/concurrency::concurrent_unordered_map"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe concurrent_unordered_map"
ms.assetid: b2d879dd-87ef-4af9-a266-a5443fd538b8
caps.latest.revision: 13
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe concurrent_unordered_map
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `concurrent_unordered_map` é um contêiner protegido contra simultaneidade que controla uma sequência de variação dos elementos de tipo `std::pair<const _Key_type, _Element_type>`.  A sequência é representada em uma forma que permite acréscimo protegido contra simultaneidade, acesso de elemento, acesso de iterador, e operações de passagem de iterador.  
  
## Sintaxe  
  
```  
template <  
   typename _Key_type,  
   typename _Element_type,  
   typename _Hasher = std::tr1::hash<_Key_type>,  
   typename _Key_equality = std::equal_to<_Key_type>,  
   typename _Allocator_type = std::allocator<std::pair<const _Key_type,  
   _Element_type> >  
>  
, typename _Key_equality = std::equal_to<_Key_type>, typename _Allocator_type = std::allocator<std::pair<const _Key_type, _Element_type> > > class concurrent_unordered_map : public details::_Concurrent_hash< details::_Concurrent_unordered_map_traits<_Key_type, _Element_type, details::_Hash_compare<_Key_type, _Hasher, _Key_equality>, _Allocator_type, false> >;  
```  
  
#### Parâmetros  
 `_Key_type`  
 O tipo principal.  
  
 `_Element_type`  
 O tipo mapeado.  
  
 `_Hasher`  
 O tipo de objeto da função hash.  Esse argumento é opcional e o valor padrão é `std::tr1::hash<``_Key_type``>`.  
  
 `_Key_equality`  
 O tipo de objeto da função de comparação de igualdade.  Esse argumento é opcional e o valor padrão é `std::equal_to<``_Key_type``>`.  
  
 `_Allocator_type`  
 O tipo que representa o objeto armazenado do distribuidor que encapsula detalhes sobre a alocação e a desalocação de memória para o mapa simultâneo não ordenado.  Esse argumento é opcional e o valor padrão é `std::allocator<std::pair<``_Key_type`, `_Element_type``>>`.  
  
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
|`mapped_type`|O tipo de um valor mapeado associado com cada chave.|  
|`pointer`|O tipo de um ponteiro para um elemento.|  
|`reference`|O tipo de uma referência para um elemento.|  
|`size_type`|O tipo de uma distância não assinada entre dois elementos.|  
|`value_type`|O tipo de um elemento.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor concurrent\_unordered\_map::concurrent\_unordered\_map](../Topic/concurrent_unordered_map::concurrent_unordered_map%20Constructor.md)|Sobrecarregado.  Constrói um mapa simultâneo não ordenado.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método concurrent\_unordered\_map::at](../Topic/concurrent_unordered_map::at%20Method.md)|Sobrecarregado.  Localiza um elemento em `concurrent_unordered_map` com um valor de chave especificado.  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_unordered\_map::hash\_function](../Topic/concurrent_unordered_map::hash_function%20Method.md)|Obtém o objeto armazenado da função hash.|  
|[Método concurrent\_unordered\_map::insert](../Topic/concurrent_unordered_map::insert%20Method.md)|Sobrecarregado.  Adiciona elementos ao objeto `concurrent_unordered_map`.|  
|[Método concurrent\_unordered\_map::key\_eq](../Topic/concurrent_unordered_map::key_eq%20Method.md)|Obtém o objeto armazenado da função de comparação de igualdade.|  
|[Método concurrent\_unordered\_map::swap](../Topic/concurrent_unordered_map::swap%20Method.md)|Alterna o conteúdo de dois objetos de `concurrent_unordered_map` .  Este método não é seguro em simultaneidade.|  
|[Método concurrent\_unordered\_map::unsafe\_erase](../Topic/concurrent_unordered_map::unsafe_erase%20Method.md)|Sobrecarregado.  Remove os elementos de `concurrent_unordered_map` em posições especificadas.  Este método não é seguro em simultaneidade.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador concurrent\_unordered\_map::operator](../Topic/concurrent_unordered_map::operatorOperator.md)|Sobrecarregado.  Localiza ou insere um elemento com a chave especificada.  Este método não é seguro em simultaneidade.|  
|[Operador concurrent\_unordered\_map::operator\=](../Topic/concurrent_unordered_map::operator=%20Operator.md)|Sobrecarregado.  Atribui o conteúdo de outro objeto `concurrent_unordered_map` nesse.  Este método não é seguro em simultaneidade.|  
  
## Comentários  
 Para obter informações detalhadas sobre a classe `concurrent_unordered_map`, consulte [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## Hierarquia de Herança  
 `_Traits`  
  
 `_Concurrent_hash`  
  
 `concurrent_unordered_map`  
  
## Requisitos  
 **Cabeçalho:** concurrent\_unordered\_map.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)