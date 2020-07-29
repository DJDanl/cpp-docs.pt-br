---
title: Contêineres e objetos em paralelo
ms.date: 03/27/2019
helpviewer_keywords:
- parallel objects
- parallel containers
- concurrent containers
ms.assetid: 90ab715c-29cd-48eb-8e76-528619aab466
ms.openlocfilehash: dffe9b3490f52645414643ebc23ab78553abafff
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213899"
---
# <a name="parallel-containers-and-objects"></a>Contêineres e objetos em paralelo

A PPL (biblioteca de padrões paralelos) inclui vários contêineres e objetos que fornecem acesso seguro ao thread aos seus elementos.

Um *contêiner simultâneo* fornece acesso seguro à simultaneidade às operações mais importantes. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A funcionalidade desses contêineres é semelhante àquelas fornecidas pela biblioteca padrão do C++. Por exemplo, a classe [Concurrency:: concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) se assemelha à classe [std:: vector](../../standard-library/vector-class.md) , exceto que a `concurrent_vector` classe permite acrescentar elementos em paralelo. Use contêineres simultâneos quando você tiver código paralelo que exija acesso de leitura e gravação ao mesmo contêiner.

Um *objeto simultâneo* é compartilhado simultaneamente entre os componentes. Um processo que computa o estado de um objeto simultâneo em paralelo produz o mesmo resultado de outro processo que computa o mesmo estado em série. A classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) é um exemplo de um tipo de objeto simultâneo. A `combinable` classe permite que você execute cálculos em paralelo e, em seguida, combine esses cálculos em um resultado final. Use objetos simultâneos quando, de outra forma, você usaria um mecanismo de sincronização, por exemplo, um mutex, para sincronizar o acesso a uma variável ou recurso compartilhado.

## <a name="sections"></a><a name="top"></a>As

Este tópico descreve os seguintes contêineres e objetos paralelos em detalhes.

Contêineres simultâneos:

- [Classe concurrent_vector](#vector)

  - [Diferenças entre concurrent_vector e vetor](#vector-differences)

  - [Operações protegidas por simultaneidade](#vector-safety)

  - [Segurança de exceção](#vector-exceptions)

- [Classe concurrent_queue](#queue)

  - [Diferenças entre concurrent_queue e fila](#queue-differences)

  - [Operações protegidas por simultaneidade](#queue-safety)

  - [Suporte a iteradores](#queue-iterators)

- [Classe concurrent_unordered_map](#unordered_map)

  - [Diferenças entre concurrent_unordered_map e unordered_map](#map-differences)

  - [Operações protegidas por simultaneidade](#map-safety)

- [Classe concurrent_unordered_multimap](#unordered_multimap)

- [Classe concurrent_unordered_set](#unordered_set)

- [Classe concurrent_unordered_multiset](#unordered_multiset)

Objetos simultâneos:

- [Classe combinável](#combinable)

  - [Métodos e recursos](#combinable-features)

  - [Exemplos](#combinable-examples)

## <a name="concurrent_vector-class"></a><a name="vector"></a>Classe concurrent_vector

A classe [Concurrency:: concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) é uma classe de contêiner de sequência que, assim como a classe [std:: vector](../../standard-library/vector-class.md) , permite que você acesse seus elementos aleatoriamente. A `concurrent_vector` classe permite operações de acesso de elemento e acréscimo com segurança de simultaneidade. As operações de acréscimo não invalidam os ponteiros ou os iteradores existentes. As operações de acesso e passagem de iterador também são protegidas por simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

### <a name="differences-between-concurrent_vector-and-vector"></a><a name="vector-differences"></a>Diferenças entre concurrent_vector e vetor

A `concurrent_vector` classe é parecida com a `vector` classe. A complexidade do acréscimo, do acesso a elementos e das operações de acesso do iterador em um `concurrent_vector` objeto é a mesma de um `vector` objeto. Os seguintes pontos ilustram onde `concurrent_vector` diferem de `vector` :

- Acréscimo, acesso de elemento, acesso de iterador e operações de percurso de iterador em um `concurrent_vector` objeto são seguros para simultaneidade.

- Você pode adicionar elementos somente ao final de um `concurrent_vector` objeto. A `concurrent_vector` classe não fornece o `insert` método.

- Um `concurrent_vector` objeto não usa a [semântica de movimentação](../../cpp/rvalue-reference-declarator-amp-amp.md) quando você se anexa a ele.

- A `concurrent_vector` classe não fornece os `erase` métodos ou `pop_back` . Assim como acontece com `vector` , use o método [Clear](reference/concurrent-vector-class.md#clear) para remover todos os elementos de um `concurrent_vector` objeto.

- A `concurrent_vector` classe não armazena seus elementos de forma contígua na memória. Portanto, você não pode usar a `concurrent_vector` classe de todas as maneiras que você pode usar uma matriz. Por exemplo, para uma variável chamada `v` de tipo `concurrent_vector` , a expressão `&v[0]+2` produz um comportamento indefinido.

- A `concurrent_vector` classe define os métodos [grow_by](reference/concurrent-vector-class.md#grow_by) e [grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least) . Esses métodos se assemelham ao método [redimensionar](reference/concurrent-vector-class.md#resize) , exceto que eles são seguros para simultaneidade.

- Um `concurrent_vector` objeto não realoca seus elementos quando você o anexa a ele ou o redimensiona. Isso permite que os ponteiros e os iteradores existentes permaneçam válidos durante as operações simultâneas.

- O tempo de execução não define uma versão especializada do `concurrent_vector` para o tipo **`bool`** .

### <a name="concurrency-safe-operations"></a><a name="vector-safety"></a>Operações protegidas por simultaneidade

Todos os métodos que acrescentam ou aumentam o tamanho de um `concurrent_vector` objeto ou acessam um elemento em um `concurrent_vector` objeto, são seguros para simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A exceção a essa regra é o `resize` método.

A tabela a seguir mostra os `concurrent_vector` métodos e operadores comuns que são seguros para simultaneidade.

||||
|-|-|-|
|[at](reference/concurrent-vector-class.md#at)|[completo](reference/concurrent-vector-class.md#end)|[operator&#91;&#93;](reference/concurrent-vector-class.md#operator_at)|
|[Comece](reference/concurrent-vector-class.md#begin)|[dianteiro](reference/concurrent-vector-class.md#front)|[push_back](reference/concurrent-vector-class.md#push_back)|
|[Voltar](reference/concurrent-vector-class.md#back)|[grow_by](reference/concurrent-vector-class.md#grow_by)|[rbegin](reference/concurrent-vector-class.md#rbegin)|
|[recurso](reference/concurrent-vector-class.md#capacity)|[grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least)|[rend](reference/concurrent-vector-class.md#rend)|
|[empty](reference/concurrent-vector-class.md#empty)|[max_size](reference/concurrent-vector-class.md#max_size)|[size](reference/concurrent-vector-class.md#size)|

As operações que o tempo de execução fornece para compatibilidade com a biblioteca padrão C++, por exemplo, `reserve` não são seguras para simultaneidade. A tabela a seguir mostra os métodos e operadores comuns que não são seguros para simultaneidade.

|||
|-|-|
|[assign](reference/concurrent-vector-class.md#assign)|[reservado](reference/concurrent-vector-class.md#reserve)|
|[formatação](reference/concurrent-vector-class.md#clear)|[alonga](reference/concurrent-vector-class.md#resize)|
|[operador =](reference/concurrent-vector-class.md#operator_eq)|[shrink_to_fit](reference/concurrent-vector-class.md#shrink_to_fit)|

As operações que modificam o valor dos elementos existentes não são seguras para simultaneidade. Use um objeto de sincronização, como um objeto [reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) , para sincronizar operações simultâneas de leitura e gravação no mesmo elemento de dados. Para obter mais informações sobre objetos de sincronização, consulte [Synchronization data structures](../../parallel/concrt/synchronization-data-structures.md).

Quando você converte o código existente que usa o `vector` para usar `concurrent_vector` , as operações simultâneas podem fazer com que o comportamento do seu aplicativo seja alterado. Por exemplo, considere o seguinte programa que executa simultaneamente duas tarefas em um `concurrent_vector` objeto. A primeira tarefa acrescenta elementos adicionais a um `concurrent_vector` objeto. A segunda tarefa computa a soma de todos os elementos no mesmo objeto.

[!code-cpp[concrt-vector-safety#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_1.cpp)]

Embora o `end` método seja seguro para simultaneidade, uma chamada simultânea para o método [push_back](reference/concurrent-vector-class.md#push_back) faz com que o valor retornado por `end` seja alterado. O número de elementos que o iterador percorre é indeterminado. Portanto, esse programa pode produzir um resultado diferente cada vez que você executá-lo. Quando o tipo de elemento não é trivial, é possível que uma condição de corrida exista entre `push_back` e `end` chame. O `end` método pode retornar um elemento que é alocado, mas não totalmente inicializado.

### <a name="exception-safety"></a><a name="vector-exceptions"></a>Segurança de exceção

Se uma operação de crescimento ou de atribuição lançar uma exceção, o estado do `concurrent_vector` objeto se tornará inválido. O comportamento de um `concurrent_vector` objeto que está em um estado inválido é indefinido, a menos que declarado de outra forma. No entanto, o destruidor sempre libera a memória que o objeto aloca, mesmo se o objeto estiver em um estado inválido.

O tipo de dados dos elementos de vetor, `T` , deve atender aos seguintes requisitos. Caso contrário, o comportamento da `concurrent_vector` classe será indefinido.

- O destruidor não deve gerar.

- Se o construtor padrão ou de cópia for acionado, o destruidor não deve ser declarado usando a **`virtual`** palavra-chave e deve funcionar corretamente com memória inicializada com zero.

[[Superior](#top)]

## <a name="concurrent_queue-class"></a><a name="queue"></a>Classe concurrent_queue

A classe [Concurrency:: concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) , assim como a classe [std:: Queue](../../standard-library/queue-class.md) , permite que você acesse seus elementos front e back. A `concurrent_queue` classe habilita as operações de enfileiramento seguro de simultaneidade e remoção da fila. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A `concurrent_queue` classe também fornece suporte de iterador que não é seguro para simultaneidade.

### <a name="differences-between-concurrent_queue-and-queue"></a><a name="queue-differences"></a>Diferenças entre concurrent_queue e fila

A `concurrent_queue` classe é parecida com a `queue` classe. Os seguintes pontos ilustram onde `concurrent_queue` diferem de `queue` :

- As operações Enqueue e recolocar na fila em um `concurrent_queue` objeto são protegidas por simultaneidade.

- A `concurrent_queue` classe fornece suporte de iterador que não é seguro para simultaneidade.

- A `concurrent_queue` classe não fornece os `front` métodos ou `pop` . A `concurrent_queue` classe substitui esses métodos definindo o método [try_pop](reference/concurrent-queue-class.md#try_pop) .

- A `concurrent_queue` classe não fornece o `back` método. Portanto, você não pode fazer referência ao final da fila.

- A `concurrent_queue` classe fornece o método [unsafe_size](reference/concurrent-queue-class.md#unsafe_size) em vez do `size` método. O `unsafe_size` método não é seguro para simultaneidade.

### <a name="concurrency-safe-operations"></a><a name="queue-safety"></a>Operações protegidas por simultaneidade

Todos os métodos que se enfileiram ou desenfileiram de um `concurrent_queue` objeto são seguros para simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

A tabela a seguir mostra os `concurrent_queue` métodos e operadores comuns que são seguros para simultaneidade.

|||
|-|-|
|[empty](reference/concurrent-queue-class.md#empty)|[push](reference/concurrent-queue-class.md#push)|
|[get_allocator](reference/concurrent-queue-class.md#get_allocator)|[try_pop](reference/concurrent-queue-class.md#try_pop)|

Embora o `empty` método seja seguro para simultaneidade, uma operação simultânea pode fazer com que a fila cresça ou diminua antes que o `empty` método retorne.

A tabela a seguir mostra os métodos e operadores comuns que não são seguros para simultaneidade.

|||
|-|-|
|[formatação](reference/concurrent-queue-class.md#clear)|[unsafe_end](reference/concurrent-queue-class.md#unsafe_end)|
|[unsafe_begin](reference/concurrent-queue-class.md#unsafe_begin)|[unsafe_size](reference/concurrent-queue-class.md#unsafe_size)|

### <a name="iterator-support"></a><a name="queue-iterators"></a>Suporte a iteradores

O `concurrent_queue` fornece iteradores que não são seguros para simultaneidade. Recomendamos que você use esses iteradores somente para depuração.

Um `concurrent_queue` iterador percorre elementos apenas na direção de avanço. A tabela a seguir mostra os operadores aos quais cada iterador dá suporte.

|Operador|Descrição|
|--------------|-----------------|
|`operator++`|Avança para o próximo item na fila. Esse operador é sobrecarregado para fornecer a semântica de incremento e pós-backup.|
|`operator*`|Recupera uma referência para o item atual.|
|`operator->`|Recupera um ponteiro para o item atual.|

[[Superior](#top)]

## <a name="concurrent_unordered_map-class"></a><a name="unordered_map"></a>Classe concurrent_unordered_map

A classe [Concurrency:: concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) é uma classe de contêiner associativa que, assim como a classe [std:: unordered_map](../../standard-library/unordered-map-class.md) , controla uma sequência de comprimento variável de elementos do tipo [std::p \<const Key, Ty> Air](../../standard-library/pair-structure.md). Imagine um mapa não ordenado como um dicionário que você pode adicionar um par de chave e valor ou pesquisar um valor por chave. Essa classe é útil quando você tem vários threads ou tarefas que precisam acessar simultaneamente um contêiner compartilhado, inseri-lo ou atualizá-lo.

O exemplo a seguir mostra a estrutura básica para usar o `concurrent_unordered_map` . Este exemplo insere chaves de caractere no intervalo [' a ', ' i ']. Como a ordem das operações não é determinada, o valor final de cada chave também é indeterminado. No entanto, é seguro executar as inserções em paralelo.

[!code-cpp[concrt-unordered-map-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_2.cpp)]

Para obter um exemplo que usa `concurrent_unordered_map` o para executar um mapa e reduzir a operação em paralelo, consulte [como: executar mapear e reduzir operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).

### <a name="differences-between-concurrent_unordered_map-and-unordered_map"></a><a name="map-differences"></a>Diferenças entre concurrent_unordered_map e unordered_map

A `concurrent_unordered_map` classe é parecida com a `unordered_map` classe. Os seguintes pontos ilustram onde `concurrent_unordered_map` diferem de `unordered_map` :

- Os `erase` `bucket` métodos,, `bucket_count` e `bucket_size` são nomeados `unsafe_erase` , `unsafe_bucket` , `unsafe_bucket_count` e `unsafe_bucket_size` , respectivamente. A `unsafe_` Convenção de nomenclatura indica que esses métodos não são seguros para simultaneidade. Para obter mais informações sobre a segurança de simultaneidade, consulte [operações protegidas por simultaneidade](#map-safety).

- As operações de inserção não invalidam os ponteiros ou os iteradores existentes, nem alteram a ordem dos itens que já existem no mapa. As operações INSERT e Traversal podem ocorrer simultaneamente.

- `concurrent_unordered_map`dá suporte apenas à iteração de encaminhamento.

- A inserção não invalida nem atualiza os iteradores que são retornados pelo `equal_range` . A inserção pode acrescentar itens desiguais ao final do intervalo. O iterador inicial aponta para um item igual.

Para ajudar a evitar o deadlock, nenhum método de `concurrent_unordered_map` mantém um bloqueio ao chamar o alocador de memória, as funções de hash ou outros códigos definidos pelo usuário. Além disso, você deve garantir que a função de hash sempre avalie as chaves iguais com o mesmo valor. As melhores funções de hash distribuem chaves uniformemente no espaço de código hash.

### <a name="concurrency-safe-operations"></a><a name="map-safety"></a>Operações protegidas por simultaneidade

A `concurrent_unordered_map` classe permite operações de acesso de elemento e inserção com segurança de simultaneidade. As operações de inserção não invalidam os ponteiros ou os iteradores existentes. As operações de acesso e passagem de iterador também são protegidas por simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A tabela a seguir mostra os métodos comumente usados `concurrent_unordered_map` e os operadores que são seguros para simultaneidade.

|||||
|-|-|-|-|
|[at](reference/concurrent-unordered-map-class.md#at)|`count`|`find`|[key_eq](reference/concurrent-unordered-map-class.md#key_eq)|
|`begin`|`empty`|`get_allocator`|`max_size`|
|`cbegin`|`end`|`hash_function`|[operator&#91;&#93;](reference/concurrent-unordered-map-class.md#operator_at)|
|`cend`|`equal_range`|[insert](reference/concurrent-unordered-map-class.md#insert)|`size`|

Embora o `count` método possa ser chamado com segurança de threads em execução simultânea, diferentes threads podem receber resultados diferentes se um novo valor for inserido simultaneamente no contêiner.

A tabela a seguir mostra os métodos e operadores usados com frequência que não são seguros para simultaneidade.

||||
|-|-|-|
|`clear`|`max_load_factor`|`rehash`|
|`load_factor`|[operador =](reference/concurrent-unordered-map-class.md#operator_eq)

Além desses métodos, qualquer método que comece com o `unsafe_` também não é seguro para simultaneidade.

[[Superior](#top)]

## <a name="concurrent_unordered_multimap-class"></a><a name="unordered_multimap"></a>Classe concurrent_unordered_multimap

A classe [Concurrency:: concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md) é parecida com a `concurrent_unordered_map` classe, exceto que ela permite que vários valores sejam mapeados para a mesma chave. Ele também difere das `concurrent_unordered_map` seguintes maneiras:

- O método [concurrent_unordered_multimap:: Insert](reference/concurrent-unordered-multimap-class.md#insert) retorna um iterador em vez de `std::pair<iterator, bool>` .

- A `concurrent_unordered_multimap` classe não fornece `operator[]` nem o `at` método.

O exemplo a seguir mostra a estrutura básica para usar o `concurrent_unordered_multimap` . Este exemplo insere chaves de caractere no intervalo [' a ', ' i ']. `concurrent_unordered_multimap`permite que uma chave tenha vários valores.

[!code-cpp[concrt-unordered-multimap-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_3.cpp)]

[[Superior](#top)]

## <a name="concurrent_unordered_set-class"></a><a name="unordered_set"></a>Classe concurrent_unordered_set

A classe [Concurrency:: concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md) é parecida com a `concurrent_unordered_map` classe, exceto pelo fato de que ela gerencia valores em vez de pares de chave e valor. A `concurrent_unordered_set` classe não fornece `operator[]` nem o `at` método.

O exemplo a seguir mostra a estrutura básica para usar o `concurrent_unordered_set` . Este exemplo insere valores de caractere no intervalo [' a ', ' i ']. É seguro executar as inserções em paralelo.

[!code-cpp[concrt-unordered-set#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_4.cpp)]

[[Superior](#top)]

## <a name="concurrent_unordered_multiset-class"></a><a name="unordered_multiset"></a>Classe concurrent_unordered_multiset

A classe [Concurrency:: concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md) é parecida com a `concurrent_unordered_set` classe, exceto que ela permite valores duplicados. Ele também difere das `concurrent_unordered_set` seguintes maneiras:

- O método [concurrent_unordered_multiset:: Insert](reference/concurrent-unordered-multiset-class.md#insert) retorna um iterador em vez de `std::pair<iterator, bool>` .

- A `concurrent_unordered_multiset` classe não fornece `operator[]` nem o `at` método.

O exemplo a seguir mostra a estrutura básica para usar o `concurrent_unordered_multiset` . Este exemplo insere valores de caractere no intervalo [' a ', ' i ']. `concurrent_unordered_multiset`permite que um valor ocorra várias vezes.

[!code-cpp[concrt-unordered-multiset#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_5.cpp)]

[[Superior](#top)]

## <a name="combinable-class"></a><a name="combinable"></a>Classe combinável

A classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) fornece armazenamento reutilizável e local de thread que permite executar computações refinadas e mesclar esses cálculos em um resultado final. Você pode considerar um `combinable` objeto como uma variável de redução.

A `combinable` classe é útil quando você tem um recurso que é compartilhado entre vários threads ou tarefas. A `combinable` classe ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de maneira sem bloqueio. Portanto, essa classe fornece uma alternativa ao uso de um mecanismo de sincronização, por exemplo, um mutex, para sincronizar o acesso a dados compartilhados de vários threads.

### <a name="methods-and-features"></a><a name="combinable-features"></a>Métodos e recursos

A tabela a seguir mostra alguns dos métodos importantes da `combinable` classe. Para obter mais informações sobre todos os `combinable` métodos de classe, consulte [classe combinável](../../parallel/concrt/reference/combinable-class.md).

|Método|Descrição|
|------------|-----------------|
|[local](reference/combinable-class.md#local)|Recupera uma referência à variável local que está associada ao contexto de thread atual.|
|[formatação](reference/combinable-class.md#clear)|Remove todas as variáveis de local de thread do `combinable` objeto.|
|[Combine](reference/combinable-class.md#combine)<br /><br /> [combine_each](reference/combinable-class.md#combine_each)|Usa a função de combinação fornecida para gerar um valor final do conjunto de todos os cálculos de thread-local.|

A `combinable` classe é uma classe de modelo que é parametrizada no resultado de mesclagem final. Se você chamar o construtor padrão, o `T` tipo de parâmetro de modelo deverá ter um construtor padrão e um construtor de cópia. Se o `T` tipo de parâmetro de modelo não tiver um construtor padrão, chame a versão sobrecarregada do construtor que usa uma função de inicialização como seu parâmetro.

Você pode armazenar dados adicionais em um `combinable` objeto depois de chamar os métodos [combine](reference/combinable-class.md#combine) ou [combine_each](reference/combinable-class.md#combine_each) . Você também pode chamar os `combine` `combine_each` métodos e várias vezes. Se nenhum valor local em um `combinable` objeto for alterado, `combine` os `combine_each` métodos e produzirão o mesmo resultado toda vez que forem chamados.

### <a name="examples"></a><a name="combinable-examples"></a> Exemplos

Para obter exemplos de como usar a `combinable` classe, consulte os seguintes tópicos:

- [Como: usar o combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)

- [Como: usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)

[[Superior](#top)]

## <a name="related-topics"></a>Tópicos Relacionados

[Como: usar contêineres paralelos para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)<br/>
Mostra como usar contêineres paralelos para armazenar e acessar dados em paralelo de forma eficiente.

[Como: usar o combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br/>
Mostra como usar a `combinable` classe para eliminar o estado compartilhado e, assim, melhorar o desempenho.

[Como: usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)<br/>
Mostra como usar uma `combine` função para mesclar conjuntos de dados locais de thread.

[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
Descreve a PPL, que fornece um modelo de programação imperativo que promove a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.

## <a name="reference"></a>Referência

[Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)

[Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)

[Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)

[Classe concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)

[Classe concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md)

[Classe concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)

[Classe combinável](../../parallel/concrt/reference/combinable-class.md)
