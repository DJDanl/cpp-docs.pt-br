---
title: Contêineres e objetos em paralelo
ms.date: 03/27/2019
helpviewer_keywords:
- parallel objects
- parallel containers
- concurrent containers
ms.assetid: 90ab715c-29cd-48eb-8e76-528619aab466
ms.openlocfilehash: f3fb2bb57c8bcf65de0a7f74f2992050d8257429
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363055"
---
# <a name="parallel-containers-and-objects"></a>Contêineres e objetos em paralelo

A Biblioteca de Padrões Paralelos (PPL) inclui vários contêineres e objetos que fornecem acesso seguro aos seus elementos.

Um *contêiner simultâneo* fornece acesso seguro à moeda às operações mais importantes. Aqui, a segurança da concorrência significa que ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elementos, ou de uma determinada ordem transversal. A funcionalidade desses recipientes se assemelha àquelas fornecidas pela Biblioteca Padrão C++. Por exemplo, a classe [de concorrência::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) se assemelha à classe `concurrent_vector` [std::vetor,](../../standard-library/vector-class.md) exceto que a classe permite que você apêndice elementos em paralelo. Use recipientes simultâneos quando tiver um código paralelo que exija acesso à leitura e gravação ao mesmo contêiner.

Um *objeto simultâneo* é compartilhado simultaneamente entre os componentes. Um processo que calcula o estado de um objeto simultâneo em paralelo produz o mesmo resultado de outro processo que calcula o mesmo estado serialmente. A [classe simultânea::combinável](../../parallel/concrt/reference/combinable-class.md) é um exemplo de um tipo de objeto simultâneo. A `combinable` classe permite que você execute cálculos em paralelo e, em seguida, combine esses cálculos em um resultado final. Use objetos simultâneos quando você usar um mecanismo de sincronização, por exemplo, um mutex, para sincronizar o acesso a uma variável ou recurso compartilhado.

## <a name="sections"></a><a name="top"></a>Seções

Este tópico descreve em detalhes os seguintes recipientes e objetos paralelos.

Recipientes simultâneos:

- [classe concurrent_vector](#vector)

  - [Diferenças entre concurrent_vector e vetor](#vector-differences)

  - [Operações seguras de concorrência](#vector-safety)

  - [Segurança de exceção](#vector-exceptions)

- [classe concurrent_queue](#queue)

  - [Diferenças entre concurrent_queue e fila](#queue-differences)

  - [Operações seguras de concorrência](#queue-safety)

  - [Suporte ao Temporterizador](#queue-iterators)

- [Classe concurrent_unordered_map](#unordered_map)

  - [Diferenças entre concurrent_unordered_map e unordered_map](#map-differences)

  - [Operações seguras de concorrência](#map-safety)

- [classe concurrent_unordered_multimap](#unordered_multimap)

- [Classe concurrent_unordered_set](#unordered_set)

- [classe concurrent_unordered_multiset](#unordered_multiset)

Objetos simultâneos:

- [classe combinável](#combinable)

  - [Métodos e Recursos](#combinable-features)

  - [Exemplos](#combinable-examples)

## <a name="concurrent_vector-class"></a><a name="vector"></a>classe concurrent_vector

A [classe de si00:concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) é uma classe de contêiner de seqüência que, assim como a classe [std::vector,](../../standard-library/vector-class.md) permite que você acesse aleatoriamente seus elementos. A `concurrent_vector` classe permite operações de acesso e acesso a elementos sem caixa. As operações de apêndice não invalidam ponteiros ou iteradores existentes. O acesso ao tempo e as operações transversais também são seguros para a concorrência. Aqui, a segurança da concorrência significa que ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elementos, ou de uma determinada ordem transversal.

### <a name="differences-between-concurrent_vector-and-vector"></a><a name="vector-differences"></a>Diferenças entre concurrent_vector e vetor

A `concurrent_vector` classe se assemelha `vector` muito à classe. A complexidade das operações de apêndice, `concurrent_vector` acesso a elementos `vector` e iteradores em um objeto são as mesmas de um objeto. Os seguintes `concurrent_vector` pontos ilustram onde difere de: `vector`

- Apêndice, acesso a elementos, acesso ao iterador e operações transversais de iterador em um `concurrent_vector` objeto são seguros para a concorrência.

- Você pode adicionar elementos apenas `concurrent_vector` ao final de um objeto. A `concurrent_vector` classe não `insert` fornece o método.

- Um `concurrent_vector` objeto não usa [semântica de movimento](../../cpp/rvalue-reference-declarator-amp-amp.md) quando você anexa a ele.

- A `concurrent_vector` classe não `erase` fornece `pop_back` os ou métodos. Como `vector`com , use o método [claro](reference/concurrent-vector-class.md#clear) para remover todos os elementos de um `concurrent_vector` objeto.

- A `concurrent_vector` classe não armazena seus elementos contíguos na memória. Portanto, você não `concurrent_vector` pode usar a classe de todas as maneiras que você pode usar uma matriz. Por exemplo, para `v` uma `concurrent_vector`variável chamada `&v[0]+2` de tipo, a expressão produz comportamento indefinido.

- A `concurrent_vector` classe define os métodos [grow_by](reference/concurrent-vector-class.md#grow_by) e [grow_to_at_least.](reference/concurrent-vector-class.md#grow_to_at_least) Esses métodos se assemelham ao método [de redimensionamento,](reference/concurrent-vector-class.md#resize) exceto que são seguros para a concorrência.

- Um `concurrent_vector` objeto não realoca seus elementos quando você o adere ou redimensiona. Isso permite que ponteiros e iteradores existentes permaneçam válidos durante operações simultâneas.

- O tempo de execução não `concurrent_vector` define `bool`uma versão especializada do tipo .

### <a name="concurrency-safe-operations"></a><a name="vector-safety"></a>Operações seguras de concorrência

Todos os métodos que apelam `concurrent_vector` ou aumentam o tamanho `concurrent_vector` de um objeto, ou acessam um elemento em um objeto, são seguros para a concorrência. Aqui, a segurança da concorrência significa que ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elementos, ou de uma determinada ordem transversal. A exceção a `resize` esta regra é o método.

A tabela a `concurrent_vector` seguir mostra os métodos e operadores comuns que são seguros para a concorrência.

||||
|-|-|-|
|[Em](reference/concurrent-vector-class.md#at)|[end](reference/concurrent-vector-class.md#end)|[operator&#91;&#93;](reference/concurrent-vector-class.md#operator_at)|
|[Começar](reference/concurrent-vector-class.md#begin)|[Frente](reference/concurrent-vector-class.md#front)|[push_back](reference/concurrent-vector-class.md#push_back)|
|[Voltar](reference/concurrent-vector-class.md#back)|[grow_by](reference/concurrent-vector-class.md#grow_by)|[rbegin](reference/concurrent-vector-class.md#rbegin)|
|[Capacidade](reference/concurrent-vector-class.md#capacity)|[grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least)|[rend](reference/concurrent-vector-class.md#rend)|
|[Vazio](reference/concurrent-vector-class.md#empty)|[Max_size](reference/concurrent-vector-class.md#max_size)|[Tamanho](reference/concurrent-vector-class.md#size)|

As operações que o tempo de execução proporciona para `reserve`compatibilidade com a Biblioteca Padrão C++, por exemplo, não são seguras para a concorrência. A tabela a seguir mostra os métodos e operadores comuns que não são seguros para a concorrência.

|||
|-|-|
|[Atribuir](reference/concurrent-vector-class.md#assign)|[Reserva](reference/concurrent-vector-class.md#reserve)|
|[Claro](reference/concurrent-vector-class.md#clear)|[Redimensionar](reference/concurrent-vector-class.md#resize)|
|[operador=](reference/concurrent-vector-class.md#operator_eq)|[shrink_to_fit](reference/concurrent-vector-class.md#shrink_to_fit)|

Operações que modificam o valor dos elementos existentes não são seguras para a concorrência. Use um objeto de sincronização como um objeto [reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) para sincronizar operações simultâneas de leitura e gravação para o mesmo elemento de dados. Para obter mais informações sobre objetos de sincronização, consulte [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md).

Quando você converte o `vector` código `concurrent_vector`existente que usa para usar, as operações simultâneas podem fazer com que o comportamento do seu aplicativo mude. Por exemplo, considere o seguinte programa que executa simultaneamente duas tarefas em um `concurrent_vector` objeto. A primeira tarefa anexa elementos adicionais a um `concurrent_vector` objeto. A segunda tarefa calcula a soma de todos os elementos no mesmo objeto.

[!code-cpp[concrt-vector-safety#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_1.cpp)]

Embora `end` o método seja seguro para a concorrência, uma chamada simultânea ao `end` método [push_back](reference/concurrent-vector-class.md#push_back) faz com que o valor que é devolvido seja devolvido por mudança. O número de elementos que o tempo rterador atravessa é indeterminado. Portanto, este programa pode produzir um resultado diferente a cada vez que você executá-lo. Quando o tipo de elemento não é trivial, é possível `push_back` `end` que uma condição de raça exista entre e chamadas. O `end` método pode retornar um elemento que está alocado, mas não totalmente inicializado.

### <a name="exception-safety"></a><a name="vector-exceptions"></a>Segurança de exceção

Se uma operação de crescimento ou atribuição `concurrent_vector` abrir uma exceção, o estado do objeto se torna inválido. O comportamento `concurrent_vector` de um objeto que está em um estado inválido é indefinido, a menos que seja declarado o contrário. No entanto, o destruidor sempre libera a memória que o objeto aloca, mesmo que o objeto esteja em um estado inválido.

O tipo de dados `T`dos elementos vetoriais deve atender aos seguintes requisitos. Caso contrário, o `concurrent_vector` comportamento da classe é indefinido.

- O destruidor não deve jogar.

- Se o construtor padrão ou copiar for arremessado, o destruidor não `virtual` deve ser declarado usando a palavra-chave e deve funcionar corretamente com memória inicializada zero.

[[Top](#top)]

## <a name="concurrent_queue-class"></a><a name="queue"></a>classe concurrent_queue

A [classe de concomitantes::concurrent_queue,](../../parallel/concrt/reference/concurrent-queue-class.md) assim como a classe [std::fila,](../../standard-library/queue-class.md) permite que você acesse seus elementos front e back. A `concurrent_queue` classe permite operações de fila e fila de fila sifiladas. Aqui, a segurança da concorrência significa que ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elementos, ou de uma determinada ordem transversal. A `concurrent_queue` classe também fornece suporte de iterator que não é seguro para a concorrência.

### <a name="differences-between-concurrent_queue-and-queue"></a><a name="queue-differences"></a>Diferenças entre concurrent_queue e fila

A `concurrent_queue` classe se assemelha `queue` muito à classe. Os seguintes `concurrent_queue` pontos ilustram onde difere de: `queue`

- As operações de enfileirar `concurrent_queue` e desfilar em um objeto são seguras para a concorrência.

- A `concurrent_queue` classe fornece suporte de iterator que não é seguro para a concorrência.

- A `concurrent_queue` classe não `front` fornece `pop` os ou métodos. A `concurrent_queue` classe substitui esses métodos definindo o método [try_pop.](reference/concurrent-queue-class.md#try_pop)

- A `concurrent_queue` classe não `back` fornece o método. Portanto, você não pode referenciar o fim da fila.

- A `concurrent_queue` classe [unsafe_size](reference/concurrent-queue-class.md#unsafe_size) fornece o método `size` unsafe_size em vez do método. O `unsafe_size` método não é seguro para a concorrência.

### <a name="concurrency-safe-operations"></a><a name="queue-safety"></a>Operações seguras de concorrência

Todos os métodos que enfileiram ou `concurrent_queue` desfilam de um objeto são seguros para a concorrência. Aqui, a segurança da concorrência significa que ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elementos, ou de uma determinada ordem transversal.

A tabela a `concurrent_queue` seguir mostra os métodos e operadores comuns que são seguros para a concorrência.

|||
|-|-|
|[Vazio](reference/concurrent-queue-class.md#empty)|[Empurrar](reference/concurrent-queue-class.md#push)|
|[get_allocator](reference/concurrent-queue-class.md#get_allocator)|[Try_pop](reference/concurrent-queue-class.md#try_pop)|

Embora `empty` o método seja seguro contra moedas, uma operação simultânea pode `empty` fazer com que a fila cresça ou diminua antes que o método retorne.

A tabela a seguir mostra os métodos e operadores comuns que não são seguros para a concorrência.

|||
|-|-|
|[Claro](reference/concurrent-queue-class.md#clear)|[unsafe_end](reference/concurrent-queue-class.md#unsafe_end)|
|[unsafe_begin](reference/concurrent-queue-class.md#unsafe_begin)|[unsafe_size](reference/concurrent-queue-class.md#unsafe_size)|

### <a name="iterator-support"></a><a name="queue-iterators"></a>Suporte ao Temporterizador

Os `concurrent_queue` dispositivos de proteção fornecem que não são seguros para a concorrência. Recomendamos que você use estes iteradores apenas para depuração.

Um `concurrent_queue` iterador atravessa elementos apenas na direção dianteira. A tabela a seguir mostra os operadores que cada iterador suporta.

|Operador|Descrição|
|--------------|-----------------|
|`operator++`|Avança para o próximo item na fila. Este operador está sobrecarregado para fornecer semântica pré-incremento e pós-incremento.|
|`operator*`|Recupera uma referência ao item atual.|
|`operator->`|Recupera um ponteiro para o item atual.|

[[Top](#top)]

## <a name="concurrent_unordered_map-class"></a><a name="unordered_map"></a>Classe concurrent_unordered_map

A [classe de concurrency::concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) é uma classe de contêiner associativo que, assim como a classe [std::unordered_map,](../../standard-library/unordered-map-class.md) controla uma seqüência de comprimento variável de elementos do tipo [std::pair\<const Key, Ty>](../../standard-library/pair-structure.md). Pense em um mapa não ordenado como um dicionário para o que você pode adicionar um par de tecla e valor ou procurar um valor por chave. Essa classe é útil quando você tem vários threads ou tarefas que têm que acessar simultaneamente um contêiner compartilhado, inseri-lo ou atualizá-lo.

O exemplo a seguir mostra `concurrent_unordered_map`a estrutura básica para o uso . Este exemplo insere teclas de caracteres no intervalo ['a', 'i']. Como a ordem das operações é indeterminada, o valor final de cada chave também é indeterminado. No entanto, é seguro realizar as inserções em paralelo.

[!code-cpp[concrt-unordered-map-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_2.cpp)]

Para um exemplo `concurrent_unordered_map` que usa para executar um mapa e reduzir a operação em paralelo, consulte [Como executar o mapa e reduzir as operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).

### <a name="differences-between-concurrent_unordered_map-and-unordered_map"></a><a name="map-differences"></a>Diferenças entre concurrent_unordered_map e unordered_map

A `concurrent_unordered_map` classe se assemelha `unordered_map` muito à classe. Os seguintes `concurrent_unordered_map` pontos ilustram onde difere de: `unordered_map`

- Os `erase` `bucket`métodos `bucket_count` `bucket_size` são nomeados `unsafe_erase` `unsafe_bucket` `unsafe_bucket_count` `unsafe_bucket_size`e, respectivamente, os métodos e os métodos. A `unsafe_` convenção de nomeação indica que esses métodos não são seguros para a concorrência. Para obter mais informações sobre segurança de simultíuo, consulte [Operações Seguras de Concorrência](#map-safety).

- As operações de inserção não invalidam ponteiros ou iteradores existentes, nem alteram a ordem dos itens que já existem no mapa. As operações de inserção e travessia podem ocorrer simultaneamente.

- `concurrent_unordered_map`suporta apenas iteração para a frente.

- A inserção não invalida ou atualiza os `equal_range`iteradores que são devolvidos por . A inserção pode anexar itens desiguais ao final do intervalo. O iterador de início aponta para um item igual.

Para ajudar a evitar `concurrent_unordered_map` o impasse, nenhum método de bloqueio segura um bloqueio quando ele chama o alocador de memória, funções hash ou outro código definido pelo usuário. Além disso, você deve garantir que a função hash sempre avalie chaves iguais para o mesmo valor. As melhores funções de hash distribuem chaves uniformemente através do espaço do código hash.

### <a name="concurrency-safe-operations"></a><a name="map-safety"></a>Operações seguras de concorrência

A `concurrent_unordered_map` classe permite operações de inserção e acesso a elementos simultâneos. As operações de inserção não invalidam ponteiros ou iteradores existentes. O acesso ao tempo e as operações transversais também são seguros para a concorrência. Aqui, a segurança da concorrência significa que ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elementos, ou de uma determinada ordem transversal. A tabela a seguir `concurrent_unordered_map` mostra os métodos e operadores comumente utilizados que são seguros contra a concorrência.

|||||
|-|-|-|-|
|[Em](reference/concurrent-unordered-map-class.md#at)|`count`|`find`|[Key_eq](reference/concurrent-unordered-map-class.md#key_eq)|
|`begin`|`empty`|`get_allocator`|`max_size`|
|`cbegin`|`end`|`hash_function`|[operator&#91;&#93;](reference/concurrent-unordered-map-class.md#operator_at)|
|`cend`|`equal_range`|[Inserir](reference/concurrent-unordered-map-class.md#insert)|`size`|

Embora `count` o método possa ser chamado com segurança a partir de threads em execução simultânea, diferentes segmentos podem receber resultados diferentes se um novo valor for inserido simultaneamente no recipiente.

A tabela a seguir mostra os métodos e operadores comumente utilizados que não são seguros para a concorrência.

||||
|-|-|-|
|`clear`|`max_load_factor`|`rehash`|
|`load_factor`|[operador=](reference/concurrent-unordered-map-class.md#operator_eq)

Além desses métodos, qualquer método `unsafe_` que comece também não é seguro para a concorrência.

[[Top](#top)]

## <a name="concurrent_unordered_multimap-class"></a><a name="unordered_multimap"></a>classe concurrent_unordered_multimap

A [classe de si00::concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md) se assemelha muito à `concurrent_unordered_map` classe, exceto que permite que vários valores mapeiem para a mesma chave. Também difere das `concurrent_unordered_map` seguintes maneiras:

- O [método concurrent_unordered_multimap::insert](reference/concurrent-unordered-multimap-class.md#insert) retorna um `std::pair<iterator, bool>`iterizador em vez de .

- A `concurrent_unordered_multimap` classe não `operator[]` fornece `at` nem o método.

O exemplo a seguir mostra `concurrent_unordered_multimap`a estrutura básica para o uso . Este exemplo insere teclas de caracteres no intervalo ['a', 'i']. `concurrent_unordered_multimap`permite que uma chave tenha múltiplos valores.

[!code-cpp[concrt-unordered-multimap-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_3.cpp)]

[[Top](#top)]

## <a name="concurrent_unordered_set-class"></a><a name="unordered_set"></a>classe concurrent_unordered_set

A [classe de si00::concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md) se assemelha muito à `concurrent_unordered_map` classe, exceto que gerencia valores em vez de pares de chaves e valores. A `concurrent_unordered_set` classe não `operator[]` fornece `at` nem o método.

O exemplo a seguir mostra `concurrent_unordered_set`a estrutura básica para o uso . Este exemplo insere valores de caracteres na faixa ['a', 'i']. É seguro realizar as inserções em paralelo.

[!code-cpp[concrt-unordered-set#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_4.cpp)]

[[Top](#top)]

## <a name="concurrent_unordered_multiset-class"></a><a name="unordered_multiset"></a>classe concurrent_unordered_multiset

A [classe de si00::concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md) se assemelha muito à `concurrent_unordered_set` classe, exceto que permite valores duplicados. Também difere das `concurrent_unordered_set` seguintes maneiras:

- O [método concurrent_unordered_multiset::insert](reference/concurrent-unordered-multiset-class.md#insert) retorna um `std::pair<iterator, bool>`iterizador em vez de .

- A `concurrent_unordered_multiset` classe não `operator[]` fornece `at` nem o método.

O exemplo a seguir mostra `concurrent_unordered_multiset`a estrutura básica para o uso . Este exemplo insere valores de caracteres na faixa ['a', 'i']. `concurrent_unordered_multiset`permite que um valor ocorra várias vezes.

[!code-cpp[concrt-unordered-multiset#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_5.cpp)]

[[Top](#top)]

## <a name="combinable-class"></a><a name="combinable"></a>classe combinável

A [classe simultânea::classe combinada](../../parallel/concrt/reference/combinable-class.md) fornece armazenamento local reutilizável e de rosca que permite que você execute cálculos de grãos finos e, em seguida, mesclar esses cálculos em um resultado final. Você pode pensar `combinable` em um objeto como uma variável de redução.

A `combinable` classe é útil quando você tem um recurso que é compartilhado entre vários tópicos ou tarefas. A `combinable` classe ajuda você a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de forma livre de bloqueio. Portanto, essa classe fornece uma alternativa ao uso de um mecanismo de sincronização, por exemplo, um mutex, para sincronizar o acesso a dados compartilhados de vários threads.

### <a name="methods-and-features"></a><a name="combinable-features"></a>Métodos e Recursos

A tabela a seguir mostra alguns `combinable` dos métodos importantes da classe. Para obter mais `combinable` informações sobre todos os métodos de classe, consulte [Classe combinada](../../parallel/concrt/reference/combinable-class.md).

|Método|Descrição|
|------------|-----------------|
|[Local](reference/combinable-class.md#local)|Recupera uma referência à variável local que está associada ao contexto atual do segmento.|
|[Claro](reference/combinable-class.md#clear)|Remove todas as variáveis locais `combinable` de rosca do objeto.|
|[Combinar](reference/combinable-class.md#combine)<br /><br /> [Combine_each](reference/combinable-class.md#combine_each)|Usa a função combinada fornecida para gerar um valor final a partir do conjunto de todos os cálculos locais de thread.|

A `combinable` classe é uma classe de modelo que é parametrizada no resultado final mesclado. Se você chamar o construtor `T` padrão, o tipo de parâmetro de modelo deve ter um construtor padrão e um construtor de cópias. Se `T` o tipo de parâmetro de modelo não tiver um construtor padrão, chame a versão sobrecarregada do construtor que toma uma função de inicialização como seu parâmetro.

Você pode armazenar dados `combinable` adicionais em um objeto depois de chamar os métodos [de combinação](reference/combinable-class.md#combine) ou [combine_each.](reference/combinable-class.md#combine_each) Você também pode `combine` `combine_each` chamar os métodos várias vezes. Se nenhum valor `combinable` local em `combine` um `combine_each` objeto mudar, os métodos produzem o mesmo resultado toda vez que são chamados.

### <a name="examples"></a><a name="combinable-examples"></a> Exemplos

Para exemplos sobre como `combinable` usar a classe, consulte os seguintes tópicos:

- [Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)

- [Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)

[[Top](#top)]

## <a name="related-topics"></a>Tópicos Relacionados

[Como usar contêineres em paralelo para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)<br/>
Mostra como usar recipientes paralelos para armazenar e acessar dados de forma eficiente em paralelo.

[Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)<br/>
Mostra como usar `combinable` a classe para eliminar o estado compartilhado e, assim, melhorar o desempenho.

[Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)<br/>
Mostra como usar `combine` uma função para mesclar conjuntos de dados locais de segmento.

[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)<br/>
Descreve o PPL, que fornece um modelo de programação imperativo que promove escalabilidade e facilidade de uso para o desenvolvimento de aplicações simultâneas.

## <a name="reference"></a>Referência

[classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)

[classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)

[Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)

[classe concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)

[Classe concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md)

[classe concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)

[classe combinável](../../parallel/concrt/reference/combinable-class.md)
