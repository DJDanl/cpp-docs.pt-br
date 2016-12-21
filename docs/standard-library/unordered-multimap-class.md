---
title: "Classe unordered_multimap | Microsoft Docs"
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
  - "unordered_map/std::tr1::unordered_multimap"
  - "tr1.unordered_multimap"
  - "unordered_multimap"
  - "std.tr1.unordered_multimap"
  - "tr1::unordered_multimap"
  - "std::tr1::unordered_multimap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unordered_multimap"
  - "Classe unordered_multimap [TR1]"
ms.assetid: 4baead6c-5870-4b85-940f-a47d6b891c27
caps.latest.revision: 28
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unordered_multimap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const Key, Ty>`.  A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket.  Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente.  Cada elemento armazena dois objetos, uma chave de classificação e um valor.  A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência \(tempo constante\), pelo menos quando todos os buckets forem de comprimento aproximadamente igual.  No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência \(tempo linear\).  Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
## Sintaxe  
  
```  
template<class Key,  
    class Ty,  
    class Hash = std::hash<Key>,  
    class Pred = std::equal_to<Key>,  
    class Alloc = std::allocator<Key> >  
    class unordered_multimap;  
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
|[unordered\_multimap::allocator\_type](../Topic/unordered_multimap::allocator_type.md)|O tipo de um distribuidor para gerenciar o armazenamento.|  
|[unordered\_multimap::const\_iterator](../Topic/unordered_multimap::const_iterator.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[unordered\_multimap::const\_local\_iterator](../Topic/unordered_multimap::const_local_iterator.md)|O tipo de um iterador de bucket de constante para a sequência controlada.|  
|[unordered\_multimap::const\_pointer](../Topic/unordered_multimap::const_pointer.md)|O tipo de um ponteiro de constante para um elemento.|  
|[unordered\_multimap::const\_reference](../Topic/unordered_multimap::const_reference.md)|O tipo de uma referência de constante para um elemento.|  
|[unordered\_multimap::difference\_type](../Topic/unordered_multimap::difference_type.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[unordered\_multimap::hasher](../Topic/unordered_multimap::hasher.md)|O tipo de função de hash.|  
|[unordered\_multimap::iterator](../Topic/unordered_multimap::iterator.md)|O tipo de um iterador para a sequência controlada.|  
|[unordered\_multimap::key\_equal](../Topic/unordered_multimap::key_equal.md)|O tipo da função de comparação.|  
|[unordered\_multimap::key\_type](../Topic/unordered_multimap::key_type.md)|O tipo de uma chave de classificação.|  
|[unordered\_multimap::local\_iterator](../Topic/unordered_multimap::local_iterator.md)|O tipo de um iterador de bucket para a sequência controlada.|  
|[unordered\_multimap::mapped\_type](../Topic/unordered_multimap::mapped_type.md)|O tipo de um valor mapeado associado a cada chave.|  
|[unordered\_multimap::pointer](../Topic/unordered_multimap::pointer.md)|O tipo de um ponteiro para um elemento.|  
|[unordered\_multimap::reference](../Topic/unordered_multimap::reference.md)|O tipo de uma referência para um elemento.|  
|[unordered\_multimap::size\_type](../Topic/unordered_multimap::size_type.md)|O tipo de uma distância sem sinal entre dois elementos.|  
|[unordered\_multimap::value\_type](../Topic/unordered_multimap::value_type.md)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[unordered\_multimap::begin](../Topic/unordered_multimap::begin.md)|Designa o início da sequência controlada.|  
|[unordered\_multimap::bucket](../Topic/unordered_multimap::bucket.md)|Obtém o número de buckets de um valor de chave.|  
|[unordered\_multimap::bucket\_count](../Topic/unordered_multimap::bucket_count.md)|Obtém o número de buckets.|  
|[unordered\_multimap::bucket\_size](../Topic/unordered_multimap::bucket_size.md)|Obtém o tamanho de um bucket.|  
|[unordered\_multimap::cbegin](../Topic/unordered_multimap::cbegin.md)|Designa o início da sequência controlada.|  
|[unordered\_multimap::cend](../Topic/unordered_multimap::cend.md)|Designa o fim da sequência controlada.|  
|[unordered\_multimap::clear](../Topic/unordered_multimap::clear.md)|Remove todos os elementos.|  
|[unordered\_multimap::count](../Topic/unordered_multimap::count.md)|Localiza o número de elementos que correspondem a uma chave especificada.|  
|[unordered\_multimap::emplace](../Topic/unordered_multimap::emplace.md)|Adiciona um elemento construído no lugar.|  
|[unordered\_multimap::emplace\_hint](../Topic/unordered_multimap::emplace_hint.md)|Adiciona um elemento construído no lugar, com dica.|  
|[unordered\_multimap::empty](../Topic/unordered_multimap::empty.md)|Testa se nenhum elemento está presente.|  
|[unordered\_multimap::end](../Topic/unordered_multimap::end.md)|Designa o fim da sequência controlada.|  
|[unordered\_multimap::equal\_range](../Topic/unordered_multimap::equal_range.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[unordered\_multimap::erase](../Topic/unordered_multimap::erase.md)|Remove os elementos em posições especificadas.|  
|[unordered\_multimap::find](../Topic/unordered_multimap::find.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[unordered\_multimap::get\_allocator](../Topic/unordered_multimap::get_allocator.md)|Obtém o objeto de alocador armazenado.|  
|[unordered\_multimap::hash\_function](../Topic/unordered_multimap::hash_function.md)|Obtém o objeto armazenado da função de hash.|  
|[unordered\_multimap::insert](../Topic/unordered_multimap::insert.md)|Adiciona elementos.|  
|[unordered\_multimap::key\_eq](../Topic/unordered_multimap::key_eq.md)|Obtém o objeto armazenado da função de comparação.|  
|[unordered\_multimap::load\_factor](../Topic/unordered_multimap::load_factor.md)|Conta a média de elementos por bucket.|  
|[unordered\_multimap::max\_bucket\_count](../Topic/unordered_multimap::max_bucket_count.md)|Obtém o número máximo de buckets.|  
|[unordered\_multimap::max\_load\_factor](../Topic/unordered_multimap::max_load_factor.md)|Obtém ou define o máximo de elementos por bucket.|  
|[unordered\_multimap::max\_size](../Topic/unordered_multimap::max_size.md)|Obtém o tamanho máximo da sequência controlada.|  
|[unordered\_multimap::rehash](../Topic/unordered_multimap::rehash.md)|Recria a tabela de hash.|  
|[unordered\_multimap::size](../Topic/unordered_multimap::size.md)|Conta o número de elementos.|  
|[unordered\_multimap::swap](../Topic/unordered_multimap::swap.md)|Alterna o conteúdo de dois contêineres.|  
|[unordered\_multimap::unordered\_multimap](../Topic/unordered_multimap::unordered_multimap.md)|Constrói um objeto contêiner.|  
  
|||  
|-|-|  
|Operador|Descrição|  
|[unordered\_multimap::operator\=](../Topic/unordered_multimap::operator=.md)|Copia uma tabela de hash.|  
  
## Comentários  
 O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered\_multimap::key\_equal](../Topic/unordered_multimap::key_equal.md) e um objeto de função de hash do tipo [unordered\_multimap::hasher](../Topic/unordered_multimap::hasher.md).  Você acessa o primeiro objeto armazenado chamando a função membro [unordered\_multimap::key\_eq](../Topic/unordered_multimap::key_eq.md)`()`; e acessa o segundo objeto armazenado chamando a função membro [unordered\_multimap::hash\_function](../Topic/unordered_multimap::hash_function.md)`()`.  Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará true somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`.  Diferentemente da classe de modelo [Classe unordered\_map](../standard-library/unordered-map-class.md), um objeto da classe de modelo `unordered_multimap` não garante que `key_eq()(X, Y)` seja sempre false para um dos dois elementos da sequência controlada. \(As chaves não precisam ser exclusivas.\)  
  
 O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket.  Se a inserção de um elemento fizer com que [unordered\_multimap::load\_factor](../Topic/unordered_multimap::load_factor.md)`()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recriará a tabela de hash conforme a necessidade.  
  
 A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets.  Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada.  No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.  
  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered\_multimap::allocator\_type](../Topic/unordered_multimap::allocator_type.md).  Esse objeto de alocador deve ter a mesma interface externa que um objeto da classe de modelo `allocator`.  Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
## Requisitos  
 **Cabeçalho:** \<unordered\_map\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<unordered\_map\>](../standard-library/unordered-map.md)   
 [Contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)