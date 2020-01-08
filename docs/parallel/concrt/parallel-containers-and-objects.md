---
title: Contêineres e objetos em paralelo
ms.date: 03/27/2019
helpviewer_keywords:
- parallel objects
- parallel containers
- concurrent containers
ms.assetid: 90ab715c-29cd-48eb-8e76-528619aab466
ms.openlocfilehash: a2a44d267e16115f1b5a6ecb76308a66fc7abc8b
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302296"
---
# <a name="parallel-containers-and-objects"></a>Contêineres e objetos em paralelo

A PPL (biblioteca de padrões paralelos) inclui vários contêineres e objetos que fornecem acesso seguro ao thread aos seus elementos.

Um *contêiner simultâneo* fornece acesso seguro à simultaneidade às operações mais importantes. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A funcionalidade desses contêineres é semelhante àquelas fornecidas pela biblioteca C++ padrão. Por exemplo, a classe [Concurrency:: concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) se assemelha à classe [std:: vector](../../standard-library/vector-class.md) , exceto que a classe `concurrent_vector` permite acrescentar elementos em paralelo. Use contêineres simultâneos quando você tiver código paralelo que exija acesso de leitura e gravação ao mesmo contêiner.

Um *objeto simultâneo* é compartilhado simultaneamente entre os componentes. Um processo que computa o estado de um objeto simultâneo em paralelo produz o mesmo resultado de outro processo que computa o mesmo estado em série. A classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) é um exemplo de um tipo de objeto simultâneo. A classe `combinable` permite que você execute cálculos em paralelo e, em seguida, combine esses cálculos em um resultado final. Use objetos simultâneos quando, de outra forma, você usaria um mecanismo de sincronização, por exemplo, um mutex, para sincronizar o acesso a uma variável ou recurso compartilhado.

##  <a name="top"></a>As

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

- [Classe combinable](#combinable)

   - [Métodos e recursos](#combinable-features)

   - [Exemplos](#combinable-examples)

##  <a name="vector"></a>Classe concurrent_vector

A classe [Concurrency:: concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) é uma classe de contêiner de sequência que, assim como a classe [std:: vector](../../standard-library/vector-class.md) , permite que você acesse seus elementos aleatoriamente. A classe `concurrent_vector` permite operações de acesso de elemento e acréscimo com segurança de simultaneidade. As operações de acréscimo não invalidam os ponteiros ou os iteradores existentes. As operações de acesso e passagem de iterador também são protegidas por simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

###  <a name="vector-differences"></a>Diferenças entre concurrent_vector e vetor

A classe `concurrent_vector` é parecida com a classe `vector`. A complexidade do acréscimo, do acesso a elementos e das operações de acesso do iterador em um objeto `concurrent_vector` são as mesmas para um objeto `vector`. Os seguintes pontos ilustram onde `concurrent_vector` diferem de `vector`:

- Acréscimo, acesso de elemento, acesso de iterador e operações de percurso de iterador em um objeto de `concurrent_vector` são seguros para simultaneidade.

- Você pode adicionar elementos somente ao final de um objeto `concurrent_vector`. A classe `concurrent_vector` não fornece o método `insert`.

- Um objeto `concurrent_vector` não usa a [semântica de movimentação](../../cpp/rvalue-reference-declarator-amp-amp.md) quando você se anexa a ele.

- A classe `concurrent_vector` não fornece os métodos `erase` ou `pop_back`. Assim como ocorre com `vector`, use o método [Clear](reference/concurrent-vector-class.md#clear) para remover todos os elementos de um objeto `concurrent_vector`.

- A classe `concurrent_vector` não armazena seus elementos de forma contígua na memória. Portanto, você não pode usar a classe `concurrent_vector` de todas as maneiras que você pode usar uma matriz. Por exemplo, para uma variável chamada `v` do tipo `concurrent_vector`, a expressão `&v[0]+2` produz um comportamento indefinido.

- A classe `concurrent_vector` define os métodos [grow_by](reference/concurrent-vector-class.md#grow_by) e [grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least) . Esses métodos se assemelham ao método [redimensionar](reference/concurrent-vector-class.md#resize) , exceto que eles são seguros para simultaneidade.

- Um objeto `concurrent_vector` não realoca seus elementos quando você o anexa a ele ou o redimensiona. Isso permite que os ponteiros e os iteradores existentes permaneçam válidos durante as operações simultâneas.

- O tempo de execução não define uma versão especializada de `concurrent_vector` para o tipo `bool`.

###  <a name="vector-safety"></a>Operações protegidas por simultaneidade

Todos os métodos que acrescentam ou aumentam o tamanho de um objeto `concurrent_vector` ou acessam um elemento em um objeto `concurrent_vector`, são seguros para simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A exceção a essa regra é o método `resize`.

A tabela a seguir mostra os métodos comuns de `concurrent_vector` e os operadores que são seguros para simultaneidade.

||||
|-|-|-|
|[at](reference/concurrent-vector-class.md#at)|[end](reference/concurrent-vector-class.md#end)|[operator&#91;&#93;](reference/concurrent-vector-class.md#operator_at)|
|[begin](reference/concurrent-vector-class.md#begin)|[front](reference/concurrent-vector-class.md#front)|[push_back](reference/concurrent-vector-class.md#push_back)|
|[back](reference/concurrent-vector-class.md#back)|[grow_by](reference/concurrent-vector-class.md#grow_by)|[rbegin](reference/concurrent-vector-class.md#rbegin)|
|[capacity](reference/concurrent-vector-class.md#capacity)|[grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least)|[rend](reference/concurrent-vector-class.md#rend)|
|[empty](reference/concurrent-vector-class.md#empty)|[max_size](reference/concurrent-vector-class.md#max_size)|[size](reference/concurrent-vector-class.md#size)|

As operações que o tempo de execução fornece para C++ compatibilidade com a biblioteca padrão, por exemplo, `reserve`, não são seguras para simultaneidade. A tabela a seguir mostra os métodos e operadores comuns que não são seguros para simultaneidade.

|||
|-|-|
|[assign](reference/concurrent-vector-class.md#assign)|[reserve](reference/concurrent-vector-class.md#reserve)|
|[clear](reference/concurrent-vector-class.md#clear)|[resize](reference/concurrent-vector-class.md#resize)|
|[operator=](reference/concurrent-vector-class.md#operator_eq)|[shrink_to_fit](reference/concurrent-vector-class.md#shrink_to_fit)|

As operações que modificam o valor dos elementos existentes não são seguras para simultaneidade. Use um objeto de sincronização, como um objeto [reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) , para sincronizar operações simultâneas de leitura e gravação no mesmo elemento de dados. Para obter mais informações sobre objetos de sincronização, consulte [Synchronization data structures](../../parallel/concrt/synchronization-data-structures.md).

Quando você converte o código existente que usa `vector` para usar `concurrent_vector`, as operações simultâneas podem fazer com que o comportamento do aplicativo seja alterado. Por exemplo, considere o seguinte programa que executa simultaneamente duas tarefas em um objeto `concurrent_vector`. A primeira tarefa acrescenta elementos adicionais a um objeto `concurrent_vector`. A segunda tarefa computa a soma de todos os elementos no mesmo objeto.

[!code-cpp[concrt-vector-safety#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_1.cpp)]

Embora o método de `end` seja seguro para simultaneidade, uma chamada simultânea para o método [push_back](reference/concurrent-vector-class.md#push_back) faz com que o valor retornado por `end` seja alterado. O número de elementos que o iterador percorre é indeterminado. Portanto, esse programa pode produzir um resultado diferente cada vez que você executá-lo. Quando o tipo de elemento não é trivial, é possível que haja uma condição de corrida entre `push_back` e `end` chamadas. O método `end` pode retornar um elemento que é alocado, mas não totalmente inicializado.

###  <a name="vector-exceptions"></a>Segurança de exceção

Se uma operação de crescimento ou de atribuição lançar uma exceção, o estado do objeto de `concurrent_vector` se tornará inválido. O comportamento de um objeto `concurrent_vector` que está em um estado inválido é indefinido, a menos que declarado de outra forma. No entanto, o destruidor sempre libera a memória que o objeto aloca, mesmo se o objeto estiver em um estado inválido.

O tipo de dados dos elementos de vetor, `T`, deve atender aos seguintes requisitos. Caso contrário, o comportamento da classe `concurrent_vector` é indefinido.

- O destruidor não deve gerar.

- Se o construtor padrão ou de cópia for acionado, o destruidor não deve ser declarado usando a palavra-chave `virtual` e deve funcionar corretamente com memória inicializada com zero.

[[Superior](#top)]

##  <a name="queue"></a>Classe concurrent_queue

A classe [Concurrency:: concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) , assim como a classe [std:: Queue](../../standard-library/queue-class.md) , permite que você acesse seus elementos front e back. A classe `concurrent_queue` permite operações de enfileiramento e remoção da fila protegidas por simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A classe `concurrent_queue` também fornece suporte a iteradores que não é seguro para simultaneidade.

###  <a name="queue-differences"></a>Diferenças entre concurrent_queue e fila

A classe `concurrent_queue` é parecida com a classe `queue`. Os seguintes pontos ilustram onde `concurrent_queue` diferem de `queue`:

- As operações Enqueue e recolocar na fila em um objeto `concurrent_queue` são seguras para simultaneidade.

- A classe `concurrent_queue` fornece suporte a iteradores que não é seguro para simultaneidade.

- A classe `concurrent_queue` não fornece os métodos `front` ou `pop`. A classe `concurrent_queue` substitui esses métodos definindo o método [try_pop](reference/concurrent-queue-class.md#try_pop) .

- A classe `concurrent_queue` não fornece o método `back`. Portanto, você não pode fazer referência ao final da fila.

- A classe `concurrent_queue` fornece o método [unsafe_size](reference/concurrent-queue-class.md#unsafe_size) em vez do método `size`. O método `unsafe_size` não é seguro para simultaneidade.

###  <a name="queue-safety"></a>Operações protegidas por simultaneidade

Todos os métodos que se enfileiram ou desenfileiram de um objeto `concurrent_queue` são seguros para simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

A tabela a seguir mostra os métodos comuns de `concurrent_queue` e os operadores que são seguros para simultaneidade.

|||
|-|-|
|[empty](reference/concurrent-queue-class.md#empty)|[push](reference/concurrent-queue-class.md#push)|
|[get_allocator](reference/concurrent-queue-class.md#get_allocator)|[try_pop](reference/concurrent-queue-class.md#try_pop)|

Embora o método de `empty` seja seguro para simultaneidade, uma operação simultânea pode fazer com que a fila cresça ou diminua antes que o método `empty` retorne.

A tabela a seguir mostra os métodos e operadores comuns que não são seguros para simultaneidade.

|||
|-|-|
|[clear](reference/concurrent-queue-class.md#clear)|[unsafe_end](reference/concurrent-queue-class.md#unsafe_end)|
|[unsafe_begin](reference/concurrent-queue-class.md#unsafe_begin)|[unsafe_size](reference/concurrent-queue-class.md#unsafe_size)|

###  <a name="queue-iterators"></a>Suporte a iteradores

O `concurrent_queue` fornece iteradores que não são seguros para simultaneidade. Recomendamos que você use esses iteradores somente para depuração.

Um iterador de `concurrent_queue` atravessa elementos apenas na direção de avanço. A tabela a seguir mostra os operadores aos quais cada iterador dá suporte.

|Operador|Descrição|
|--------------|-----------------|
|`operator++`|Avança para o próximo item na fila. Esse operador é sobrecarregado para fornecer a semântica de incremento e pós-backup.|
|`operator*`|Recupera uma referência para o item atual.|
|`operator->`|Recupera um ponteiro para o item atual.|

[[Superior](#top)]

##  <a name="unordered_map"></a>Classe concurrent_unordered_map

A classe [Concurrency:: concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) é uma classe de contêiner associativa que, assim como a classe [std:: unordered_map](../../standard-library/unordered-map-class.md) , controla uma sequência de comprimento variável de elementos do tipo [std::p Air\<const Key, Ty >](../../standard-library/pair-structure.md). Imagine um mapa não ordenado como um dicionário que você pode adicionar um par de chave e valor ou pesquisar um valor por chave. Essa classe é útil quando você tem vários threads ou tarefas que precisam acessar simultaneamente um contêiner compartilhado, inseri-lo ou atualizá-lo.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_map`. Este exemplo insere chaves de caractere no intervalo [' a ', ' i ']. Como a ordem das operações não é determinada, o valor final de cada chave também é indeterminado. No entanto, é seguro executar as inserções em paralelo.

[!code-cpp[concrt-unordered-map-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_2.cpp)]

Para obter um exemplo que usa `concurrent_unordered_map` para executar um mapa e reduzir a operação em paralelo, consulte [como: executar mapear e reduzir operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).

###  <a name="map-differences"></a>Diferenças entre concurrent_unordered_map e unordered_map

A classe `concurrent_unordered_map` é parecida com a classe `unordered_map`. Os seguintes pontos ilustram onde `concurrent_unordered_map` diferem de `unordered_map`:

- Os métodos `erase`, `bucket`, `bucket_count`e `bucket_size` são nomeados `unsafe_erase`, `unsafe_bucket`, `unsafe_bucket_count`e `unsafe_bucket_size`, respectivamente. A Convenção de nomenclatura `unsafe_` indica que esses métodos não são seguros para simultaneidade. Para obter mais informações sobre a segurança de simultaneidade, consulte [operações protegidas por simultaneidade](#map-safety).

- As operações de inserção não invalidam os ponteiros ou os iteradores existentes, nem alteram a ordem dos itens que já existem no mapa. As operações INSERT e Traversal podem ocorrer simultaneamente.

- `concurrent_unordered_map` dá suporte apenas à iteração de encaminhamento.

- A inserção não invalida nem atualiza os iteradores que são retornados pelo `equal_range`. A inserção pode acrescentar itens desiguais ao final do intervalo. O iterador inicial aponta para um item igual.

Para ajudar a evitar o deadlock, nenhum método de `concurrent_unordered_map` mantém um bloqueio quando chama o alocador de memória, funções de hash ou outro código definido pelo usuário. Além disso, você deve garantir que a função de hash sempre avalie as chaves iguais com o mesmo valor. As melhores funções de hash distribuem chaves uniformemente no espaço de código hash.

###  <a name="map-safety"></a>Operações protegidas por simultaneidade

A classe `concurrent_unordered_map` permite operações de acesso de elemento e inserção protegidas por simultaneidade. As operações de inserção não invalidam os ponteiros ou os iteradores existentes. As operações de acesso e passagem de iterador também são protegidas por simultaneidade. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica. A tabela a seguir mostra os métodos de `concurrent_unordered_map` comumente usados e os operadores que são seguros para simultaneidade.

|||||
|-|-|-|-|
|[at](reference/concurrent-unordered-map-class.md#at)|`count`|`find`|[key_eq](reference/concurrent-unordered-map-class.md#key_eq)|
|`begin`|`empty`|`get_allocator`|`max_size`|
|`cbegin`|`end`|`hash_function`|[operator&#91;&#93;](reference/concurrent-unordered-map-class.md#operator_at)|
|`cend`|`equal_range`|[insert](reference/concurrent-unordered-map-class.md#insert)|`size`|

Embora o método `count` possa ser chamado com segurança de threads em execução simultânea, diferentes threads poderão receber resultados diferentes se um novo valor for inserido simultaneamente no contêiner.

A tabela a seguir mostra os métodos e operadores usados com frequência que não são seguros para simultaneidade.

||||
|-|-|-|
|`clear`|`max_load_factor`|`rehash`|
|`load_factor`|[operator=](reference/concurrent-unordered-map-class.md#operator_eq)

Além desses métodos, qualquer método que comece com `unsafe_` também não é seguro para simultaneidade.

[[Superior](#top)]

##  <a name="unordered_multimap"></a>Classe concurrent_unordered_multimap

A classe [Concurrency:: concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md) é parecida com a classe `concurrent_unordered_map`, exceto que ela permite que vários valores sejam mapeados para a mesma chave. Ele também difere de `concurrent_unordered_map` das seguintes maneiras:

- O método [concurrent_unordered_multimap:: Insert](reference/concurrent-unordered-multimap-class.md#insert) retorna um iterador em vez de `std::pair<iterator, bool>`.

- A classe `concurrent_unordered_multimap` não fornece `operator[]` nem o método `at`.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_multimap`. Este exemplo insere chaves de caractere no intervalo [' a ', ' i ']. `concurrent_unordered_multimap` permite que uma chave tenha vários valores.

[!code-cpp[concrt-unordered-multimap-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_3.cpp)]

[[Superior](#top)]

##  <a name="unordered_set"></a>Classe concurrent_unordered_set

A classe [Concurrency:: concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md) é parecida com a classe `concurrent_unordered_map`, exceto pelo fato de que ela gerencia valores em vez de pares chave e valor. A classe `concurrent_unordered_set` não fornece `operator[]` nem o método `at`.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_set`. Este exemplo insere valores de caractere no intervalo [' a ', ' i ']. É seguro executar as inserções em paralelo.

[!code-cpp[concrt-unordered-set#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_4.cpp)]

[[Superior](#top)]

##  <a name="unordered_multiset"></a>Classe concurrent_unordered_multiset

A classe [Concurrency:: concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md) é parecida com a classe `concurrent_unordered_set`, exceto que ela permite valores duplicados. Ele também difere de `concurrent_unordered_set` das seguintes maneiras:

- O método [concurrent_unordered_multiset:: Insert](reference/concurrent-unordered-multiset-class.md#insert) retorna um iterador em vez de `std::pair<iterator, bool>`.

- A classe `concurrent_unordered_multiset` não fornece `operator[]` nem o método `at`.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_multiset`. Este exemplo insere valores de caractere no intervalo [' a ', ' i ']. `concurrent_unordered_multiset` permite que um valor ocorra várias vezes.

[!code-cpp[concrt-unordered-multiset#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_5.cpp)]

[[Superior](#top)]

##  <a name="combinable"></a>Classe combinável

A classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) fornece armazenamento reutilizável e local de thread que permite executar computações refinadas e mesclar esses cálculos em um resultado final. Você pode considerar um objeto `combinable` como uma variável de redução.

A classe `combinable` é útil quando você tem um recurso que é compartilhado entre vários threads ou tarefas. A classe `combinable` ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de maneira sem bloqueio. Portanto, essa classe fornece uma alternativa ao uso de um mecanismo de sincronização, por exemplo, um mutex, para sincronizar o acesso a dados compartilhados de vários threads.

###  <a name="combinable-features"></a>Métodos e recursos

A tabela a seguir mostra alguns dos métodos importantes da classe `combinable`. Para obter mais informações sobre todos os métodos de classe de `combinable`, consulte [classe combinável](../../parallel/concrt/reference/combinable-class.md).

|Método|Descrição|
|------------|-----------------|
|[local](reference/combinable-class.md#local)|Recupera uma referência à variável local que está associada ao contexto de thread atual.|
|[clear](reference/combinable-class.md#clear)|Remove todas as variáveis de local de thread do objeto `combinable`.|
|[combine](reference/combinable-class.md#combine)<br /><br /> [combine_each](reference/combinable-class.md#combine_each)|Usa a função de combinação fornecida para gerar um valor final do conjunto de todos os cálculos de thread-local.|

A classe `combinable` é uma classe de modelo que é parametrizada no resultado mesclado final. Se você chamar o construtor padrão, o tipo de parâmetro de `T` modelo deverá ter um construtor padrão e um construtor de cópia. Se o tipo de parâmetro de modelo `T` não tiver um construtor padrão, chame a versão sobrecarregada do construtor que usa uma função de inicialização como seu parâmetro.

Você pode armazenar dados adicionais em um objeto `combinable` depois de chamar os métodos [Combine](reference/combinable-class.md#combine) ou [combine_each](reference/combinable-class.md#combine_each) . Você também pode chamar os métodos `combine` e `combine_each` várias vezes. Se nenhum valor local em um objeto `combinable` for alterado, os métodos `combine` e `combine_each` produzirão o mesmo resultado toda vez que forem chamados.

###  <a name="combinable-examples"></a> Exemplos

Para obter exemplos de como usar a classe `combinable`, consulte os seguintes tópicos:

- [Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)

- [Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)

[[Superior](#top)]

## <a name="related-topics"></a>Tópicos relacionados

[Como usar contêineres em paralelo para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)<br/>
Mostra como usar contêineres paralelos para armazenar e acessar dados em paralelo de forma eficiente.

[Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br/>
Mostra como usar a classe `combinable` para eliminar o estado compartilhado e, assim, melhorar o desempenho.

[Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)<br/>
Mostra como usar uma função `combine` para mesclar conjuntos de dados locais de thread.

[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
Descreve a PPL, que fornece um modelo de programação imperativo que promove a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.

## <a name="reference"></a>Referência

[Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)

[Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)

[Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)

[Classe concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)

[Classe concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md)

[Classe concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)

[Classe combinable](../../parallel/concrt/reference/combinable-class.md)
