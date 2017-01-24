---
title: "Classe unordered_map | Microsoft Docs"
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
  - "std::tr1::unordered_map"
  - "std.tr1.unordered_map"
  - "tr1.unordered_map"
  - "tr1::unordered_map"
  - "unordered_map"
  - "unordered_map/std::tr1::unordered_map"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unordered_map"
  - "Classe unordered_map [TR1]"
ms.assetid: 7cf7cfa1-16e7-461c-a9b2-3b8d8ec24e0d
caps.latest.revision: 20
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unordered_map
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const Key, Ty>`.  A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket.  Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente.  Cada elemento armazena dois objetos, uma chave de classificação e um valor.  A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência \(tempo constante\), pelo menos quando todos os buckets forem de comprimento aproximadamente igual.  No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência \(tempo linear\).  Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
## Sintaxe  
  
```  
template<class Key,  
    class Ty,  
    class Hash = std::hash<Key>,  
    class Pred = std::equal_to<Key>,  
    class Alloc = std::allocator<std::pair<const Key, Ty> > >  
    class unordered_map;  
```  
  
#### Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Key`|O tipo principal.|  
|`Ty`|O tipo mapeado.|  
|`Hash`|O tipo de objeto da função de hash.|  
|`Pred`|O tipo de objeto da função de comparação de igualdade.|  
|`Alloc`|A classe do alocador.|  
  
## Membros  
  
|||  
|-|-|  
|Definição do tipo|Descrição|  
|[unordered\_map::allocator\_type](../Topic/unordered_map::allocator_type.md)|O tipo de um distribuidor para gerenciar o armazenamento.|  
|[unordered\_map::const\_iterator](../Topic/unordered_map::const_iterator.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[unordered\_map::const\_local\_iterator](../Topic/unordered_map::const_local_iterator.md)|O tipo de um iterador de bucket de constante para a sequência controlada.|  
|[unordered\_map::const\_pointer](../Topic/unordered_map::const_pointer.md)|O tipo de um ponteiro de constante para um elemento.|  
|[unordered\_map::const\_reference](../Topic/unordered_map::const_reference.md)|O tipo de uma referência de constante para um elemento.|  
|[unordered\_map::difference\_type](../Topic/unordered_map::difference_type.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[unordered\_map::hasher](../Topic/unordered_map::hasher.md)|O tipo de função de hash.|  
|[unordered\_map::iterator](../Topic/unordered_map::iterator.md)|O tipo de um iterador para a sequência controlada.|  
|[unordered\_map::key\_equal](../Topic/unordered_map::key_equal.md)|O tipo da função de comparação.|  
|[unordered\_map::key\_type](../Topic/unordered_map::key_type.md)|O tipo de uma chave de classificação.|  
|[unordered\_map::local\_iterator](../Topic/unordered_map::local_iterator.md)|O tipo de um iterador de bucket para a sequência controlada.|  
|[unordered\_map::mapped\_type](../Topic/unordered_map::mapped_type.md)|O tipo de um valor mapeado associado a cada chave.|  
|[unordered\_map::pointer](../Topic/unordered_map::pointer.md)|O tipo de um ponteiro para um elemento.|  
|[unordered\_map::reference](../Topic/unordered_map::reference.md)|O tipo de uma referência para um elemento.|  
|[unordered\_map::size\_type](../Topic/unordered_map::size_type.md)|O tipo de uma distância sem sinal entre dois elementos.|  
|[unordered\_map::value\_type](../Topic/unordered_map::value_type.md)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[unordered\_map::at](../Topic/unordered_map::at.md)|Localiza um elemento com a chave especificada.|  
|[unordered\_map::begin](../Topic/unordered_map::begin.md)|Designa o início da sequência controlada.|  
|[unordered\_map::bucket](../Topic/unordered_map::bucket.md)|Obtém o número de buckets de um valor de chave.|  
|[unordered\_map::bucket\_count](../Topic/unordered_map::bucket_count.md)|Obtém o número de buckets.|  
|[unordered\_map::bucket\_size](../Topic/unordered_map::bucket_size.md)|Obtém o tamanho de um bucket.|  
|[unordered\_map::cbegin](../Topic/unordered_map::cbegin.md)|Designa o início da sequência controlada.|  
|[unordered\_map::cend](../Topic/unordered_map::cend.md)|Designa o fim da sequência controlada.|  
|[unordered\_map::clear](../Topic/unordered_map::clear.md)|Remove todos os elementos.|  
|[unordered\_map::count](../Topic/unordered_map::count.md)|Localiza o número de elementos que correspondem a uma chave especificada.|  
|[unordered\_map::emplace](../Topic/unordered_map::emplace.md)|Adiciona um elemento construído no lugar.|  
|[unordered\_map::emplace\_hint](../Topic/unordered_map::emplace_hint.md)|Adiciona um elemento construído no lugar, com dica.|  
|[unordered\_map::empty](../Topic/unordered_map::empty.md)|Testa se nenhum elemento está presente.|  
|[unordered\_map::end](../Topic/unordered_map::end.md)|Designa o fim da sequência controlada.|  
|[unordered\_map::equal\_range](../Topic/unordered_map::equal_range.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[unordered\_map::erase](../Topic/unordered_map::erase.md)|Remove os elementos em posições especificadas.|  
|[unordered\_map::find](../Topic/unordered_map::find.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[unordered\_map::get\_allocator](../Topic/unordered_map::get_allocator.md)|Obtém o objeto de alocador armazenado.|  
|[unordered\_map::hash\_function](../Topic/unordered_map::hash_function.md)|Obtém o objeto armazenado da função de hash.|  
|[unordered\_map::insert](../Topic/unordered_map::insert.md)|Adiciona elementos.|  
|[unordered\_map::key\_eq](../Topic/unordered_map::key_eq.md)|Obtém o objeto armazenado da função de comparação.|  
|[unordered\_map::load\_factor](../Topic/unordered_map::load_factor.md)|Conta a média de elementos por bucket.|  
|[unordered\_map::max\_bucket\_count](../Topic/unordered_map::max_bucket_count.md)|Obtém o número máximo de buckets.|  
|[unordered\_map::max\_load\_factor](../Topic/unordered_map::max_load_factor.md)|Obtém ou define o máximo de elementos por bucket.|  
|[unordered\_map::max\_size](../Topic/unordered_map::max_size.md)|Obtém o tamanho máximo da sequência controlada.|  
|[unordered\_map::rehash](../Topic/unordered_map::rehash.md)|Recria a tabela de hash.|  
|[unordered\_map::size](../Topic/unordered_map::size.md)|Conta o número de elementos.|  
|[unordered\_map::swap](../Topic/unordered_map::swap.md)|Alterna o conteúdo de dois contêineres.|  
|[unordered\_map::unordered\_map](../Topic/unordered_map::unordered_map.md)|Constrói um objeto contêiner.|  
  
|||  
|-|-|  
|Operador|Descrição|  
|[unordered\_map::operator](../Topic/unordered_map::operator.md)|Localiza ou insere um elemento com a chave especificada.|  
|[unordered\_map::operator\=](../Topic/unordered_map::operator=.md)|Copia uma tabela de hash.|  
  
## Comentários  
 O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered\_map::key\_equal](../Topic/unordered_map::key_equal.md) e um objeto de função de hash do tipo [unordered\_map::hasher](../Topic/unordered_map::hasher.md).  Você acessa o primeiro objeto armazenado chamando a função membro [unordered\_map::key\_eq](../Topic/unordered_map::key_eq.md)`()`; e acessa o segundo objeto armazenado chamando a função membro [unordered\_map::hash\_function](../Topic/unordered_map::hash_function.md)`()`.  Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará true somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`.  Diferentemente da classe de modelo [Classe unordered\_multimap](../standard-library/unordered-multimap-class.md), um objeto da classe de modelo `unordered_map` garante que `key_eq()(X, Y)` seja sempre false para um dos dois elementos da sequência controlada. \(As chaves são exclusivas.\)  
  
 O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket.  Se a inserção de um elemento fizer com que [unordered\_map::load\_factor](../Topic/unordered_map::load_factor.md)`()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recriará a tabela de hash conforme a necessidade.  
  
 A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets.  Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada.  No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.  
  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered\_map::allocator\_type](../Topic/unordered_map::allocator_type.md).  Esse objeto de alocador deve ter a mesma interface externa que um objeto da classe de modelo `allocator`.  Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
## Requisitos  
 **Cabeçalho:** \<unordered\_map\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<unordered\_map\>](../standard-library/unordered-map.md)   
 [Contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)