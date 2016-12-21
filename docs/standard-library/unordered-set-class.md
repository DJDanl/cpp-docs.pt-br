---
title: "Classe unordered_set | Microsoft Docs"
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
  - "std.tr1.unordered_set"
  - "std::tr1::unordered_set"
  - "unordered_set/std::tr1::unordered_set"
  - "tr1::unordered_set"
  - "unordered_set"
  - "tr1.unordered_set"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unordered_set"
  - "Classe unordered_set [TR1]"
ms.assetid: ac08084e-05a7-48c0-9ae4-d40c529922dd
caps.latest.revision: 23
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unordered_set
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos do tipo `const Key`.  A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket.  Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente.  Cada elemento serve como uma chave de classificação e um valor.  A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência \(tempo constante\), pelo menos quando todos os buckets forem de comprimento aproximadamente igual.  No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência \(tempo linear\).  Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
## Sintaxe  
  
```  
template<class Key,  
    class Hash = std::hash<Key>,  
    class Pred = std::equal_to<Key>,  
    class Alloc = std::allocator<Key> >  
    class unordered_set;  
```  
  
#### Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Key`|O tipo principal.|  
|`Hash`|O tipo de objeto da função de hash.|  
|`Pred`|O tipo de objeto da função de comparação de igualdade.|  
|`Alloc`|A classe do alocador.|  
  
## Membros  
  
|||  
|-|-|  
|Definição do tipo|Descrição|  
|[unordered\_set::allocator\_type](../Topic/unordered_set::allocator_type.md)|O tipo de um distribuidor para gerenciar o armazenamento.|  
|[unordered\_set::const\_iterator](../Topic/unordered_set::const_iterator.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[unordered\_set::const\_local\_iterator](../Topic/unordered_set::const_local_iterator.md)|O tipo de um iterador de bucket de constante para a sequência controlada.|  
|[unordered\_set::const\_pointer](../Topic/unordered_set::const_pointer.md)|O tipo de um ponteiro de constante para um elemento.|  
|[unordered\_set::const\_reference](../Topic/unordered_set::const_reference.md)|O tipo de uma referência de constante para um elemento.|  
|[unordered\_set::difference\_type](../Topic/unordered_set::difference_type.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[unordered\_set::hasher](../Topic/unordered_set::hasher.md)|O tipo de função de hash.|  
|[unordered\_set::iterator](../Topic/unordered_set::iterator.md)|O tipo de um iterador para a sequência controlada.|  
|[unordered\_set::key\_equal](../Topic/unordered_set::key_equal.md)|O tipo da função de comparação.|  
|[unordered\_set::key\_type](../Topic/unordered_set::key_type.md)|O tipo de uma chave de classificação.|  
|[unordered\_set::local\_iterator](../Topic/unordered_set::local_iterator.md)|O tipo de um iterador de bucket para a sequência controlada.|  
|[unordered\_set::pointer](../Topic/unordered_set::pointer.md)|O tipo de um ponteiro para um elemento.|  
|[unordered\_set::reference](../Topic/unordered_set::reference.md)|O tipo de uma referência para um elemento.|  
|[unordered\_set::size\_type](../Topic/unordered_set::size_type.md)|O tipo de uma distância sem sinal entre dois elementos.|  
|[unordered\_set::value\_type](../Topic/unordered_set::value_type.md)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[unordered\_set::begin](../Topic/unordered_set::begin.md)|Designa o início da sequência controlada.|  
|[unordered\_set::bucket](../Topic/unordered_set::bucket.md)|Obtém o número de buckets de um valor de chave.|  
|[unordered\_set::bucket\_count](../Topic/unordered_set::bucket_count.md)|Obtém o número de buckets.|  
|[unordered\_set::bucket\_size](../Topic/unordered_set::bucket_size.md)|Obtém o tamanho de um bucket.|  
|[unordered\_set::cbegin](../Topic/unordered_set::cbegin.md)|Designa o início da sequência controlada.|  
|[unordered\_set::cend](../Topic/unordered_set::cend.md)|Designa o fim da sequência controlada.|  
|[unordered\_set::clear](../Topic/unordered_set::clear.md)|Remove todos os elementos.|  
|[unordered\_set::count](../Topic/unordered_set::count.md)|Localiza o número de elementos que correspondem a uma chave especificada.|  
|[unordered\_set::emplace](../Topic/unordered_set::emplace.md)|Adiciona um elemento construído no lugar.|  
|[unordered\_set::emplace\_hint](../Topic/unordered_set::emplace_hint.md)|Adiciona um elemento construído no lugar, com dica.|  
|[unordered\_set::empty](../Topic/unordered_set::empty.md)|Testa se nenhum elemento está presente.|  
|[unordered\_set::end](../Topic/unordered_set::end.md)|Designa o fim da sequência controlada.|  
|[unordered\_set::equal\_range](../Topic/unordered_set::equal_range.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[unordered\_set::erase](../Topic/unordered_set::erase.md)|Remove os elementos em posições especificadas.|  
|[unordered\_set::find](../Topic/unordered_set::find.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[unordered\_set::get\_allocator](../Topic/unordered_set::get_allocator.md)|Obtém o objeto de alocador armazenado.|  
|[unordered\_set::hash\_function](../Topic/unordered_set::hash_function.md)|Obtém o objeto armazenado da função de hash.|  
|[unordered\_set::insert](../Topic/unordered_set::insert.md)|Adiciona elementos.|  
|[unordered\_set::key\_eq](../Topic/unordered_set::key_eq.md)|Obtém o objeto armazenado da função de comparação.|  
|[unordered\_set::load\_factor](../Topic/unordered_set::load_factor.md)|Conta a média de elementos por bucket.|  
|[unordered\_set::max\_bucket\_count](../Topic/unordered_set::max_bucket_count.md)|Obtém o número máximo de buckets.|  
|[unordered\_set::max\_load\_factor](../Topic/unordered_set::max_load_factor.md)|Obtém ou define o máximo de elementos por bucket.|  
|[unordered\_set::max\_size](../Topic/unordered_set::max_size.md)|Obtém o tamanho máximo da sequência controlada.|  
|[unordered\_set::rehash](../Topic/unordered_set::rehash.md)|Recria a tabela de hash.|  
|[unordered\_set::size](../Topic/unordered_set::size.md)|Conta o número de elementos.|  
|[unordered\_set::swap](../Topic/unordered_set::swap.md)|Alterna o conteúdo de dois contêineres.|  
|[unordered\_set::unordered\_set](../Topic/unordered_set::unordered_set.md)|Constrói um objeto contêiner.|  
  
|||  
|-|-|  
|Operadores|Descrição|  
|[unordered\_set::operator\=](../Topic/unordered_set::operator=.md)|Copia uma tabela de hash.|  
  
## Comentários  
 O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered\_set::key\_equal](../Topic/unordered_set::key_equal.md) e um objeto de função de hash do tipo [unordered\_set::hasher](../Topic/unordered_set::hasher.md).  Você acessa o primeiro objeto armazenado chamando a função membro [unordered\_set::key\_eq](../Topic/unordered_set::key_eq.md)`()`; e acessa o segundo objeto armazenado chamando a função membro [unordered\_set::hash\_function](../Topic/unordered_set::hash_function.md)`()`.  Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará true somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`.  Diferentemente da classe de modelo [Classe unordered\_multiset](../standard-library/unordered-multiset-class.md), um objeto da classe de modelo `unordered_set` garante que `key_eq()(X, Y)` seja sempre false para um dos dois elementos da sequência controlada. \(As chaves são exclusivas.\)  
  
 O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket.  Se a inserção de um elemento fizer com que [unordered\_set::load\_factor](../Topic/unordered_set::load_factor.md)`()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recriará a tabela de hash conforme a necessidade.  
  
 A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets.  Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada.  No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.  
  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered\_set::allocator\_type](../Topic/unordered_set::allocator_type.md).  Esse objeto de alocador deve ter a mesma interface externa que um objeto da classe de modelo `allocator`.  Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
## Requisitos  
 **Cabeçalho:** \<unordered\_set\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<unordered\_set\>](../standard-library/unordered-set.md)   
 [Contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)