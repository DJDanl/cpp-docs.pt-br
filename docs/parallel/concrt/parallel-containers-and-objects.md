---
title: Contêineres e objetos em paralelo
ms.date: 03/27/2019
helpviewer_keywords:
- parallel objects
- parallel containers
- concurrent containers
ms.assetid: 90ab715c-29cd-48eb-8e76-528619aab466
ms.openlocfilehash: bcf3ead9fe945ecb2246fdb28b7f67cd51b1238b
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565942"
---
# <a name="parallel-containers-and-objects"></a>Contêineres e objetos em paralelo

A biblioteca de padrões paralelos (PPL) inclui vários contêineres e objetos que fornecem acesso thread-safe aos seus elementos.

Um *simultânea contêiner* fornece acesso seguro em simultaneidade para as operações mais importantes. A funcionalidade desses contêineres se parece com aquelas que são fornecidas pela biblioteca padrão C++. Por exemplo, o [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) é semelhante a [std:: Vector](../../standard-library/vector-class.md) classe, exceto que o `concurrent_vector` classe permite que você acrescentar elementos em paralelo. Use contêineres simultâneos quando você tiver código paralelo que requer acesso de leitura e gravação para o mesmo contêiner.

Um *simultâneo objeto* é compartilhada simultaneamente entre componentes. Um processo que calcula o estado de um objeto simultâneo em paralelo produz o mesmo resultado que outro processo que computa o mesmo estado em série. O [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe é um exemplo de um tipo de objeto simultâneas. O `combinable` classe permite fazer cálculos em paralelo e, em seguida, combinar esses cálculos em um resultado final. Use objetos simultâneos quando caso contrário, você pode usar um mecanismo de sincronização, por exemplo, um mutex para sincronizar o acesso a uma variável compartilhada ou recurso.

##  <a name="top"></a> Seções

Este tópico descreve os seguintes contêineres paralelos e objetos em detalhes.

Contêineres simultâneos:

- [Classe concurrent_vector](#vector)

   - [Vetor e diferenças entre concurrent_vector](#vector-differences)

   - [Operações de prova de simultaneidade](#vector-safety)

   - [Segurança de exceção](#vector-exceptions)

- [Classe concurrent_queue](#queue)

   - [Fila e as diferenças entre concurrent_queue](#queue-differences)

   - [Operações de prova de simultaneidade](#queue-safety)

   - [Suporte ao iterador](#queue-iterators)

- [Classe concurrent_unordered_map](#unordered_map)

   - [Unordered_map e diferenças entre concurrent_unordered_map](#map-differences)

   - [Operações de prova de simultaneidade](#map-safety)

- [Classe concurrent_unordered_multimap](#unordered_multimap)

- [Classe concurrent_unordered_set](#unordered_set)

- [Classe concurrent_unordered_multiset](#unordered_multiset)

Objetos simultâneos:

- [Classe combinable](#combinable)

   - [Métodos e recursos](#combinable-features)

   - [Exemplos](#combinable-examples)

##  <a name="vector"></a> Classe concurrent_vector

O [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) classe é uma classe de contêiner de sequência que, assim como o [std:: Vector](../../standard-library/vector-class.md) de classe, permite que você acesse aleatoriamente seus elementos. O `concurrent_vector` operações de acesso de classe permite que o acréscimo de prova de simultaneidade e o elemento. Acrescentar operações não invalidem existentes ponteiros ou iteradores. Operações de acesso e passagem de iterador também são seguro em simultaneidade.

###  <a name="vector-differences"></a> Vetor e diferenças entre concurrent_vector

O `concurrent_vector` classe parecida com a `vector` classe. A complexidade de acréscimo, acesso de elemento e operações de acesso de iterador em um `concurrent_vector` objeto são os mesmos para uma `vector` objeto. Os pontos a seguir ilustram onde `concurrent_vector` difere `vector`:

- Acrescentar, acesso de elemento, acesso de iterador e operações de passagem de iterador em um `concurrent_vector` objeto são seguro em simultaneidade.

- Você pode adicionar elementos apenas até o fim de um `concurrent_vector` objeto. O `concurrent_vector` classe não fornece o `insert` método.

- Um `concurrent_vector` objeto não utilize [semântica de movimentação](../../cpp/rvalue-reference-declarator-amp-amp.md) quando você acrescentar a ele.

- O `concurrent_vector` classe não fornece a `erase` ou `pop_back` métodos. Assim como acontece com `vector`, use o [desmarque](reference/concurrent-vector-class.md#clear) método para remover todos os elementos de um `concurrent_vector` objeto.

- O `concurrent_vector` não armazena seus elementos contiguamente na memória. Portanto, é possível usar o `concurrent_vector` classe em todas as maneiras que você pode usar uma matriz. Por exemplo, para uma variável nomeada `v` do tipo `concurrent_vector`, a expressão `&v[0]+2` produz um comportamento indefinido.

- O `concurrent_vector` classe define o [grow_by](reference/concurrent-vector-class.md#grow_by) e [grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least) métodos. Esses métodos se parecer com o [redimensionar](reference/concurrent-vector-class.md#resize) método, exceto que eles são a prova de simultaneidade.

- Um `concurrent_vector` objeto não realocar seus elementos quando você acrescentar a ele ou redimensioná-la. Isso permite que os ponteiros existentes e iteradores permaneça válido durante as operações simultâneas.

- O tempo de execução não define uma versão especializada da `concurrent_vector` para tipo `bool`.

###  <a name="vector-safety"></a> Operações de prova de simultaneidade

Todos os métodos que acrescentar a ou aumentam o tamanho de um `concurrent_vector` do objeto ou acessar um elemento em um `concurrent_vector` de objeto, são a prova de simultaneidade. A exceção a essa regra é o `resize` método.

A tabela a seguir mostra o comum `concurrent_vector` métodos e operadores de prova de simultaneidade.

||||
|-|-|-|
|[at](reference/concurrent-vector-class.md#at)|[end](reference/concurrent-vector-class.md#end)|[operator&#91;&#93;](reference/concurrent-vector-class.md#operator_at)|
|[begin](reference/concurrent-vector-class.md#begin)|[front](reference/concurrent-vector-class.md#front)|[push_back](reference/concurrent-vector-class.md#push_back)|
|[back](reference/concurrent-vector-class.md#back)|[grow_by](reference/concurrent-vector-class.md#grow_by)|[rbegin](reference/concurrent-vector-class.md#rbegin)|
|[capacity](reference/concurrent-vector-class.md#capacity)|[grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least)|[rend](reference/concurrent-vector-class.md#rend)|
|[empty](reference/concurrent-vector-class.md#empty)|[max_size](reference/concurrent-vector-class.md#max_size)|[size](reference/concurrent-vector-class.md#size)|

As operações que o tempo de execução fornece para compatibilidade com a biblioteca padrão C++, por exemplo, `reserve`, não está protegido contra simultaneidade. A tabela a seguir mostra os métodos e operadores que não estão protegido contra simultaneidade comuns.

|||
|-|-|
|[assign](reference/concurrent-vector-class.md#assign)|[reserve](reference/concurrent-vector-class.md#reserve)|
|[clear](reference/concurrent-vector-class.md#clear)|[resize](reference/concurrent-vector-class.md#resize)|
|[operator=](reference/concurrent-vector-class.md#operator_eq)|[shrink_to_fit](reference/concurrent-vector-class.md#shrink_to_fit)|

As operações que modificam o valor de elementos existentes não são seguro em simultaneidade. Usar um objeto de sincronização, como um [reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) objeto sincronizar leitura simultâneas e operações de gravação ao mesmo elemento de dados. Para obter mais informações sobre objetos de sincronização, consulte [estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md).

Quando você converte código existente que usa `vector` usar `concurrent_vector`, operações simultâneas podem causar o comportamento do seu aplicativo para alterar. Por exemplo, considere o seguinte programa que simultaneamente executa duas tarefas em um `concurrent_vector` objeto. A primeira tarefa acrescenta elementos adicionais a um `concurrent_vector` objeto. A segunda tarefa calcula a soma de todos os elementos no mesmo objeto.

[!code-cpp[concrt-vector-safety#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_1.cpp)]

Embora o `end` método é seguro em simultaneidade, uma chamada simultânea para o [push_back](reference/concurrent-vector-class.md#push_back) método faz com que o valor retornado por `end` alterar. O número de elementos que atravessa o iterador é indeterminado. Portanto, esse programa pode produzir um resultado diferente cada vez que você executá-lo.

###  <a name="vector-exceptions"></a> Segurança de exceção

Se uma operação de crescimento ou atribuição lança uma exceção, o estado do `concurrent_vector` objeto se torna inválido. O comportamento de um `concurrent_vector` objeto que está em um estado inválido for indefinido, a menos que indicado de outra forma. No entanto, o destruidor sempre libera a memória que o objeto aloca, mesmo se o objeto está em um estado inválido.

O tipo de dados dos elementos do vetor, `T`, deve atender aos requisitos a seguir. Caso contrário, o comportamento do `concurrent_vector` classe é indefinido.

- O destruidor não deve lançar.

- Se o construtor padrão ou de cópia gerará, o destruidor não deve ser declarado usando a `virtual` palavra-chave e ele devem funcionar corretamente com memória inicializada do zero.

[[Top](#top)]

##  <a name="queue"></a> Classe concurrent_queue

O [concurrency::concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) classe, assim como o [std:: Queue](../../standard-library/queue-class.md) de classe, permite que você acessar da parte frontal e elementos de volta. O `concurrent_queue` permite enfileirar de prova de simultaneidade de classe e operações de remoção da fila. O `concurrent_queue` classe também fornece suporte a iterador não seguro em simultaneidade.

###  <a name="queue-differences"></a> Fila e as diferenças entre concurrent_queue

O `concurrent_queue` classe parecida com a `queue` classe. Os pontos a seguir ilustram onde `concurrent_queue` difere `queue`:

- Enqueue e dequeue de operações em um `concurrent_queue` objeto são seguro em simultaneidade.

- O `concurrent_queue` classe oferece suporte a iterador não seguro em simultaneidade.

- O `concurrent_queue` classe não fornece a `front` ou `pop` métodos. O `concurrent_queue` classe substitui esses métodos, definindo o [try_pop](reference/concurrent-queue-class.md#try_pop) método.

- O `concurrent_queue` classe não fornece o `back` método. Portanto, você não pode referenciar o final da fila.

- O `concurrent_queue` classe fornece a [unsafe_size](reference/concurrent-queue-class.md#unsafe_size) método em vez do `size` método. O `unsafe_size` método não é seguro em simultaneidade.

###  <a name="queue-safety"></a> Operações de prova de simultaneidade

Todos os métodos que enfileiram a ou remover da fila de um `concurrent_queue` objeto são seguro em simultaneidade.

A tabela a seguir mostra o comum `concurrent_queue` métodos e operadores de prova de simultaneidade.

|||
|-|-|
|[empty](reference/concurrent-queue-class.md#empty)|[push](reference/concurrent-queue-class.md#push)|
|[get_allocator](reference/concurrent-queue-class.md#get_allocator)|[try_pop](reference/concurrent-queue-class.md#try_pop)|

Embora o `empty` método é protegido contra simultaneidade, uma operação simultânea pode fazer com que a fila seja ampliada ou reduzida antes do `empty` retorno do método.

A tabela a seguir mostra os métodos e operadores que não estão protegido contra simultaneidade comuns.

|||
|-|-|
|[clear](reference/concurrent-queue-class.md#clear)|[unsafe_end](reference/concurrent-queue-class.md#unsafe_end)|
|[unsafe_begin](reference/concurrent-queue-class.md#unsafe_begin)|[unsafe_size](reference/concurrent-queue-class.md#unsafe_size)|

###  <a name="queue-iterators"></a> Suporte ao iterador

O `concurrent_queue` fornece iteradores que não estão protegido contra simultaneidade. É recomendável que você use esses iteradores somente para depuração.

Um `concurrent_queue` iterador atravessa os elementos na direção progressiva. A tabela a seguir mostra os operadores que dá suporte a cada iterador.

|Operador|Descrição|
|--------------|-----------------|
|`operator++`|Avança para o próximo item na fila. Este operador está sobrecarregado para fornecer a semântica de pré-incremento e pós-incremento.|
|`operator*`|Recupera uma referência ao item atual.|
|`operator->`|Recupera um ponteiro para o item atual.|

[[Top](#top)]

##  <a name="unordered_map"></a> Classe concurrent_unordered_map

O [concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) é uma classe de contêiner associativo que, assim como o [std:: unordered_map](../../standard-library/unordered-map-class.md) de classe, controla uma sequência de comprimento variado de elementos do tipo [std:: Pair\<const Key, Ty >](../../standard-library/pair-structure.md). Pense em um mapa não ordenado como um dicionário que você pode adicionar um par de chave e valor para ou procurar um valor por chave. Essa classe é útil quando você tem vários threads ou tarefas que precisam acessar um contêiner compartilhado, inserir nela ou atualizá-lo simultaneamente.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_map`. Este exemplo insere as chaves de caractere no intervalo ['a', ' i']. Como a ordem das operações é indeterminada, o valor final para cada chave também é indeterminado. No entanto, é seguro executar as inserções em paralelo.

[!code-cpp[concrt-unordered-map-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_2.cpp)]

Para obter um exemplo que usa `concurrent_unordered_map` para executar um mapa e reduzir a operação em paralelo, consulte [como: Executar o mapa e reduzir as operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).

###  <a name="map-differences"></a> Unordered_map e diferenças entre concurrent_unordered_map

O `concurrent_unordered_map` classe parecida com a `unordered_map` classe. Os pontos a seguir ilustram onde `concurrent_unordered_map` difere `unordered_map`:

- O `erase`, `bucket`, `bucket_count`, e `bucket_size` métodos são nomeados `unsafe_erase`, `unsafe_bucket`, `unsafe_bucket_count`, e `unsafe_bucket_size`, respectivamente. O `unsafe_` convenção de nomenclatura indica que esses métodos não são seguro em simultaneidade. Para obter mais informações sobre segurança de simultaneidade, consulte [operações com segurança de simultaneidade](#map-safety).

- Operações de inserção não invalidem existentes ponteiros ou iteradores, nem alterarem a ordem dos itens que já existem no mapa. Inserir e percorrer as operações podem ocorrer simultaneamente.

- `concurrent_unordered_map` dá suporte a encaminha somente a iteração.

- Inserção não invalidar ou atualizar os iteradores que são retornados pelo `equal_range`. Inserção pode acrescentar itens diferentes para o fim do intervalo. O iterador begin aponta para um item igual.

Para ajudar a evitar o deadlock, nenhum método de `concurrent_unordered_map` mantém um bloqueio quando ele chama o alocador de memória, as funções de hash ou outro código definido pelo usuário. Além disso, você deve garantir que a função de hash sempre avalia chaves iguais para o mesmo valor. As funções de hash melhor distribuem chaves uniformemente entre o espaço de código hash.

###  <a name="map-safety"></a> Operações de prova de simultaneidade

O `concurrent_unordered_map` classe permite que operações de inserção e acesso de elemento de prova de simultaneidade. Operações de inserção não invalidem existentes ponteiros ou iteradores. Operações de acesso e passagem de iterador também são seguro em simultaneidade. A tabela a seguir mostra os comumente usados `concurrent_unordered_map` métodos e operadores de prova de simultaneidade.

|||||
|-|-|-|-|
|[at](reference/concurrent-unordered-map-class.md#at)|`count`|`find`|[key_eq](reference/concurrent-unordered-map-class.md#key_eq)|
|`begin`|`empty`|`get_allocator`|`max_size`|
|`cbegin`|`end`|`hash_function`|[operator&#91;&#93;](reference/concurrent-unordered-map-class.md#operator_at)|
|`cend`|`equal_range`|[insert](reference/concurrent-unordered-map-class.md#insert)|`size`|

Embora o `count` método pode ser chamado com segurança de threads em execução simultânea, diferentes threads podem receber resultados diferentes se simultaneamente, um novo valor é inserido no contêiner.

A tabela a seguir mostra os operadores que não estão protegido contra simultaneidade e métodos mais usados.

||||
|-|-|-|
|`clear`|`max_load_factor`|`rehash`|
|`load_factor`|[operator=](reference/concurrent-unordered-map-class.md#operator_eq)

Além desses métodos, qualquer método que que começa com `unsafe_` também não é seguro em simultaneidade.

[[Top](#top)]

##  <a name="unordered_multimap"></a> Classe concurrent_unordered_multimap

O [concurrency::concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md) classe parecida com a `concurrent_unordered_map` , exceto que ele permite vários valores mapear para a mesma chave de classe. Também é diferente da `concurrent_unordered_map` das seguintes maneiras:

- O [concurrent_unordered_multimap:: Insert](reference/concurrent-unordered-multimap-class.md#insert) método retorna um iterador em vez de `std::pair<iterator, bool>`.

- O `concurrent_unordered_multimap` classe não fornece `operator[]` nem o `at` método.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_multimap`. Este exemplo insere as chaves de caractere no intervalo ['a', ' i']. `concurrent_unordered_multimap` permite que uma chave para ter vários valores.

[!code-cpp[concrt-unordered-multimap-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_3.cpp)]

[[Top](#top)]

##  <a name="unordered_set"></a> Classe concurrent_unordered_set

O [concurrency::concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md) classe parecida com a `concurrent_unordered_map` classe, exceto que ele gerencia valores em vez de pares chave-valor. O `concurrent_unordered_set` classe não fornece `operator[]` nem o `at` método.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_set`. Este exemplo insere valores de caractere no intervalo ['a', ' i']. É seguro executar as inserções em paralelo.

[!code-cpp[concrt-unordered-set#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_4.cpp)]

[[Top](#top)]

##  <a name="unordered_multiset"></a> Classe concurrent_unordered_multiset

O [concurrency::concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md) classe parecida com a `concurrent_unordered_set` classe, exceto que ela permite valores duplicados. Também é diferente da `concurrent_unordered_set` das seguintes maneiras:

- O [concurrent_unordered_multiset:: Insert](reference/concurrent-unordered-multiset-class.md#insert) método retorna um iterador em vez de `std::pair<iterator, bool>`.

- O `concurrent_unordered_multiset` classe não fornece `operator[]` nem o `at` método.

O exemplo a seguir mostra a estrutura básica para usar `concurrent_unordered_multiset`. Este exemplo insere valores de caractere no intervalo ['a', ' i']. `concurrent_unordered_multiset` permite que um valor ocorrer várias vezes.

[!code-cpp[concrt-unordered-multiset#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_5.cpp)]

[[Top](#top)]

##  <a name="combinable"></a> Classe combinable

O [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe fornece armazenamento reutilizável, locais de thread que lhe permite realizar cálculos refinados e, em seguida, mesclar esses cálculos em um resultado final. Você pode pensar uma `combinable` objeto como uma variável de redução.

O `combinable` classe é útil quando você tiver um recurso que é compartilhado entre vários threads ou tarefas. O `combinable` classe ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de maneira sem bloqueio. Portanto, essa classe fornece uma alternativa ao uso de um mecanismo de sincronização, por exemplo, um mutex para sincronizar o acesso aos dados compartilhados de vários threads.

###  <a name="combinable-features"></a> Métodos e recursos

A tabela a seguir mostra alguns dos métodos importantes do `combinable` classe. Para obter mais informações sobre todos os `combinable` métodos de classe, consulte [classe combinable](../../parallel/concrt/reference/combinable-class.md).

|Método|Descrição|
|------------|-----------------|
|[local](reference/combinable-class.md#local)|Recupera uma referência à variável local que está associado com o contexto do thread atual.|
|[clear](reference/combinable-class.md#clear)|Remove todas as variáveis locais de thread do `combinable` objeto.|
|[combine](reference/combinable-class.md#combine)<br /><br /> [combine_each](reference/combinable-class.md#combine_each)|Usa a função de combinação fornecida para gerar um valor final do conjunto de todos os cálculos de local de thread.|

O `combinable` é uma classe de modelo que é parametrizada no resultado final mesclado. Se você chamar o construtor padrão, o `T` tipo de parâmetro de modelo deve ter um construtor padrão e um construtor de cópia. Se o `T` tipo de parâmetro de modelo não tem um construtor padrão, chame a versão sobrecarregada do construtor que usa uma função de inicialização como seu parâmetro.

Você pode armazenar dados adicionais em uma `combinable` do objeto depois de chamar o [combinar](reference/combinable-class.md#combine) ou [combine_each](reference/combinable-class.md#combine_each) métodos. Você também pode chamar o `combine` e `combine_each` métodos várias vezes. Se nenhum valor local em um `combinable` objeto alterações, o `combine` e `combine_each` métodos produzem o mesmo resultado toda vez que eles são chamados.

###  <a name="combinable-examples"></a> Exemplos

Para obter exemplos sobre como usar o `combinable` de classe, consulte os seguintes tópicos:

- [Como: Usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)

- [Como: Usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)

[[Top](#top)]

## <a name="related-topics"></a>Tópicos relacionados

[Como: Usar contêineres em paralelo para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)<br/>
Mostra como usar contêineres em paralelo com eficiência armazenar e acessar dados em paralelo.

[Como: Usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br/>
Mostra como usar o `combinable` de classe para eliminar o estado compartilhado e, assim, melhorar o desempenho.

[Como: Usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)<br/>
Mostra como usar um `combine` função para mesclar os locais de thread de conjuntos de dados.

[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
Descreve o PPL, que fornece um modelo de programação imperativo que promove a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.

## <a name="reference"></a>Referência

[Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)

[Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)

[Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)

[Classe concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)

[Classe concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md)

[Classe concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)

[Classe combinable](../../parallel/concrt/reference/combinable-class.md)
