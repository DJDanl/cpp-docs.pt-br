---
title: "Classe unordered_multiset | Microsoft Docs"
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
  - "tr1::unordered_multiset"
  - "std::tr1::unordered_multiset"
  - "unordered_multiset"
  - "std.tr1.unordered_multiset"
  - "unordered_set/std::tr1::unordered_multiset"
  - "tr1.unordered_multiset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unordered_multiset"
  - "Classe unordered_multiset [TR1]"
ms.assetid: 70c8dfc5-492a-4af2-84f5-1aa9cb04b71c
caps.latest.revision: 24
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unordered_multiset
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que controla uma sequência de comprimento variado de elementos do tipo `const Key`.  A sequência é ordenada sem muita rigidez por uma função de hash, que particiona a sequência em um conjunto ordenado de subsequências chamado bucket.  Dentro de cada bucket uma função de comparação determina se um par de elementos tem ordenação equivalente.  Cada elemento serve como uma chave de classificação e um valor.  A sequência é representada de forma a permitir pesquisa, inserção e remoção de um elemento com um número arbitrário de operações que podem ser independentes do número de elementos na sequência \(tempo constante\), pelo menos quando todos os buckets forem de comprimento aproximadamente igual.  No pior caso, quando todos os elementos estiverem em um bucket, o número de operações será proporcional ao número de elementos na sequência \(tempo linear\).  Além disso, inserir um elemento não invalida iteradores, e remover um elemento invalida apenas os iteradores que apontam o elemento removido.  
  
## Sintaxe  
  
```  
template<class Key,  
    class Hash = std::hash<Key>,  
    class Pred = std::equal_to<Key>,  
    class Alloc = std::allocator<Key> >  
    class unordered_multiset;  
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
|[unordered\_multiset::allocator\_type](../Topic/unordered_multiset::allocator_type.md)|O tipo de um distribuidor para gerenciar o armazenamento.|  
|[unordered\_multiset::const\_iterator](../Topic/unordered_multiset::const_iterator.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[unordered\_multiset::const\_local\_iterator](../Topic/unordered_multiset::const_local_iterator.md)|O tipo de um iterador de bucket de constante para a sequência controlada.|  
|[unordered\_multiset::const\_pointer](../Topic/unordered_multiset::const_pointer.md)|O tipo de um ponteiro de constante para um elemento.|  
|[unordered\_multiset::const\_reference](../Topic/unordered_multiset::const_reference.md)|O tipo de uma referência de constante para um elemento.|  
|[unordered\_multiset::difference\_type](../Topic/unordered_multiset::difference_type.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[unordered\_multiset::hasher](../Topic/unordered_multiset::hasher.md)|O tipo de função de hash.|  
|[unordered\_multiset::iterator](../Topic/unordered_multiset::iterator.md)|O tipo de um iterador para a sequência controlada.|  
|[unordered\_multiset::key\_equal](../Topic/unordered_multiset::key_equal.md)|O tipo da função de comparação.|  
|[unordered\_multiset::key\_type](../Topic/unordered_multiset::key_type.md)|O tipo de uma chave de classificação.|  
|[unordered\_multiset::local\_iterator](../Topic/unordered_multiset::local_iterator.md)|O tipo de um iterador de bucket para a sequência controlada.|  
|[unordered\_multiset::pointer](../Topic/unordered_multiset::pointer.md)|O tipo de um ponteiro para um elemento.|  
|[unordered\_multiset::reference](../Topic/unordered_multiset::reference.md)|O tipo de uma referência para um elemento.|  
|[unordered\_multiset::size\_type](../Topic/unordered_multiset::size_type.md)|O tipo de uma distância sem sinal entre dois elementos.|  
|[unordered\_multiset::value\_type](../Topic/unordered_multiset::value_type.md)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[unordered\_multiset::begin](../Topic/unordered_multiset::begin.md)|Designa o início da sequência controlada.|  
|[unordered\_multiset::bucket](../Topic/unordered_multiset::bucket.md)|Obtém o número de buckets de um valor de chave.|  
|[unordered\_multiset::bucket\_count](../Topic/unordered_multiset::bucket_count.md)|Obtém o número de buckets.|  
|[unordered\_multiset::bucket\_size](../Topic/unordered_multiset::bucket_size.md)|Obtém o tamanho de um bucket.|  
|[unordered\_multiset::cbegin](../Topic/unordered_multiset::cbegin.md)|Designa o início da sequência controlada.|  
|[unordered\_multiset::cend](../Topic/unordered_multiset::cend.md)|Designa o fim da sequência controlada.|  
|[unordered\_multiset::clear](../Topic/unordered_multiset::clear.md)|Remove todos os elementos.|  
|[unordered\_multiset::count](../Topic/unordered_multiset::count.md)|Localiza o número de elementos que correspondem a uma chave especificada.|  
|[unordered\_multiset::emplace](../Topic/unordered_multiset::emplace.md)|Adiciona um elemento construído no lugar.|  
|[unordered\_multiset::emplace\_hint](../Topic/unordered_multiset::emplace_hint.md)|Adiciona um elemento construído no lugar, com dica.|  
|[unordered\_multiset::empty](../Topic/unordered_multiset::empty.md)|Testa se nenhum elemento está presente.|  
|[unordered\_multiset::end](../Topic/unordered_multiset::end.md)|Designa o fim da sequência controlada.|  
|[unordered\_multiset::equal\_range](../Topic/unordered_multiset::equal_range.md)|Localiza o intervalo que corresponde a uma chave especificada.|  
|[unordered\_multiset::erase](../Topic/unordered_multiset::erase.md)|Remove os elementos em posições especificadas.|  
|[unordered\_multiset::find](../Topic/unordered_multiset::find.md)|Localiza um elemento que corresponde a uma chave especificada.|  
|[unordered\_multiset::get\_allocator](../Topic/unordered_multiset::get_allocator.md)|Obtém o objeto de alocador armazenado.|  
|[unordered\_multiset::hash\_function](../Topic/unordered_multiset::hash_function.md)|Obtém o objeto armazenado da função de hash.|  
|[unordered\_multiset::insert](../Topic/unordered_multiset::insert.md)|Adiciona elementos.|  
|[unordered\_multiset::key\_eq](../Topic/unordered_multiset::key_eq.md)|Obtém o objeto armazenado da função de comparação.|  
|[unordered\_multiset::load\_factor](../Topic/unordered_multiset::load_factor.md)|Conta a média de elementos por bucket.|  
|[unordered\_multiset::max\_bucket\_count](../Topic/unordered_multiset::max_bucket_count.md)|Obtém o número máximo de buckets.|  
|[unordered\_multiset::max\_load\_factor](../Topic/unordered_multiset::max_load_factor.md)|Obtém ou define o máximo de elementos por bucket.|  
|[unordered\_multiset::max\_size](../Topic/unordered_multiset::max_size.md)|Obtém o tamanho máximo da sequência controlada.|  
|[unordered\_multiset::rehash](../Topic/unordered_multiset::rehash.md)|Recria a tabela de hash.|  
|[unordered\_multiset::size](../Topic/unordered_multiset::size.md)|Conta o número de elementos.|  
|[unordered\_multiset::swap](../Topic/unordered_multiset::swap.md)|Alterna o conteúdo de dois contêineres.|  
|[unordered\_multiset::unordered\_multiset](../Topic/unordered_multiset::unordered_multiset.md)|Constrói um objeto contêiner.|  
  
|||  
|-|-|  
|Operador|Descrição|  
|[unordered\_multiset::operator\=](../Topic/unordered_multiset::operator=.md)|Copia uma tabela de hash.|  
  
## Comentários  
 O objeto ordena a sequência que ele controla chamando dois objetos armazenados, um objeto de função de comparação do tipo [unordered\_multiset::key\_equal](../Topic/unordered_multiset::key_equal.md) e um objeto de função de hash do tipo [unordered\_multiset::hasher](../Topic/unordered_multiset::hasher.md).  Você acessa o primeiro objeto armazenado chamando a função membro [unordered\_multiset::key\_eq](../Topic/unordered_multiset::key_eq.md)`()`; e acessa o segundo objeto armazenado chamando a função membro [unordered\_multiset::hash\_function](../Topic/unordered_multiset::hash_function.md)`()`.  Especificamente, para todos os valores `X` e `Y` do tipo `Key`, a chamada `key_eq()(X, Y)` retornará true somente se os dois valores de argumento tiverem ordem equivalente; a chamada `hash_function()(keyval)` resulta em uma distribuição de valores do tipo `size_t`.  Diferentemente da classe de modelo [Classe unordered\_set](../standard-library/unordered-set-class.md), um objeto da classe de modelo `unordered_multiset` não garante que `key_eq()(X, Y)` seja sempre false para um dos dois elementos da sequência controlada. \(As chaves não precisam ser exclusivas.\)  
  
 O objeto também armazena um fator de carga máximo, que especifica o número máximo médio desejado de elementos por bucket.  Se a inserção de um elemento fizer com que [unordered\_multiset::load\_factor](../Topic/unordered_multiset::load_factor.md)`()` exceda o fator de carga máximo, o contêiner aumentará o número de buckets e recriará a tabela de hash conforme a necessidade.  
  
 A ordem real de elementos na sequência controlada depende da função de hash, da função de comparação, da ordem de inserção, do fator máximo de carga e do número atual de buckets.  Você não pode fazer uma previsão geral da ordem dos elementos na sequência controlada.  No entanto, você sempre terá certeza de que qualquer subconjunto de elementos que tenha ordem equivalente será adjacente na sequência de controle.  
  
 O objeto aloca e libera armazenamento para a sequência que controla por meio de um objeto armazenado de alocador do tipo [unordered\_multiset::allocator\_type](../Topic/unordered_multiset::allocator_type.md).  Esse objeto de alocador deve ter a mesma interface externa que um objeto da classe de modelo `allocator`.  Observe que o objeto de alocador armazenado não é copiado quando o objeto de contêiner é atribuído.  
  
## Requisitos  
 **Cabeçalho:** \<unordered\_set\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<unordered\_set\>](../standard-library/unordered-set.md)   
 [Contêineres](../Topic/Containers%20\(Modern%20C++\).md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)