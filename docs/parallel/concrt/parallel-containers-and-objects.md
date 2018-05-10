---
title: Paralelo de objetos e contêineres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parallel objects
- parallel containers
- concurrent containers
ms.assetid: 90ab715c-29cd-48eb-8e76-528619aab466
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 168705c5d7497a0bcbede505760d49cdb63a3762
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="parallel-containers-and-objects"></a>Contêineres e objetos em paralelo
A biblioteca de padrões paralelos (PPL) inclui vários contêineres e objetos que fornecem acesso thread-safe para seus elementos.  
  
 Um *simultâneo contêiner* fornece acesso seguro a simultaneidade para as operações mais importantes. A funcionalidade desses contêineres se parece com aquelas que são fornecidas pela biblioteca C++ padrão. Por exemplo, o [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) é semelhante a [std:: Vector](../../standard-library/vector-class.md) classe, exceto que o `concurrent_vector` classe permite que você acrescentar elementos em paralelo. Use contêineres simultâneos quando você tiver código paralelo que requer acesso de leitura e gravação ao mesmo contêiner.  
  
 Um *simultâneo objeto* compartilhado simultaneamente entre componentes. Um processo que calcula o estado de um objeto simultâneo em paralelo produz o mesmo resultado de outro processo que calcula o mesmo estado em série. O [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe é um exemplo de um tipo de objeto simultâneas. O `combinable` classe permite realizar cálculos em paralelo e, em seguida, combinar os cálculos em um resultado final. Use objetos simultâneos quando caso contrário, você pode usar um mecanismo de sincronização, por exemplo, um mutex para sincronizar o acesso a uma variável compartilhada ou um recurso.  
  
##  <a name="top"></a> Seções  
 Este tópico descreve os seguintes contêineres paralelos e objetos em detalhes.  
  
 Contêineres simultâneos:  
  
-   [Classe concurrent_vector](#ctor)  
  
    -   [Vetor e diferenças entre concurrent_vector](#ctor)  
  
    -   [Operações com segurança de simultaneidade](#ctor)  
  
    -   [Exceção de segurança](#ctor)  
  
-   [Classe concurrent_queue](#queue)  
  
    -   [Fila e diferenças entre concurrent_queue](#queue-differences)  
  
    -   [Operações com segurança de simultaneidade](#queue-safety)  
  
    -   [Suporte de iterador](#queue-iterators)  
  
-   [Classe concurrent_unordered_map](#unordered_map)  
  
    -   [Unordered_map e diferenças entre concurrent_unordered_map](#map-differences)  
  
    -   [Operações com segurança de simultaneidade](#map-safety)  
  
-   [Classe concurrent_unordered_multimap](#unordered_multimap)  
  
-   [Classe concurrent_unordered_set](#unordered_set)  
  
-   [Classe concurrent_unordered_multiset](#unordered_multiset)  
  
 Objetos simultâneos:  
  
-   [Classe combinable](#combinable)  
  
    -   [Métodos e recursos](#combinable-features)  
  
    -   [Exemplos](#combinable-examples)  
  
##  <a name="vector"></a> Classe concurrent_vector  
 O [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) classe é uma classe de contêiner de sequência que, assim como o [std:: Vector](../../standard-library/vector-class.md) classe, permite que você acesse aleatoriamente seus elementos. O `concurrent_vector` habilita classe append seguro de simultaneidade e elemento operações de acesso. Acrescentar operações não invalidar ponteiros existentes ou iteradores. Operações de acesso e a passagem de iterador também são simultaneidade-safe.  
  
###  <a name="vector-differences"></a> Vetor e diferenças entre concurrent_vector  
 O `concurrent_vector` classe parecida com a `vector` classe. A complexidade de acrescentar, acesso de elemento e operações de acesso do iterador em uma `concurrent_vector` objeto são os mesmos para uma `vector` objeto. Os pontos a seguir ilustram onde `concurrent_vector` difere `vector`:  
  
-   Acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador em uma `concurrent_vector` objeto são aceitas de simultaneidade.  
  
-   Você pode adicionar elementos apenas até o fim de uma `concurrent_vector` objeto. O `concurrent_vector` classe não fornecerá a `insert` método.  
  
-   Um `concurrent_vector` objeto não usa [mover semântica](../../cpp/rvalue-reference-declarator-amp-amp.md) quando você acrescentar a ele.  
  

-   O `concurrent_vector` classe não fornecerá a `erase` ou `pop_back` métodos. Assim como acontece com `vector`, use o [limpar](reference/concurrent-vector-class.md#clear) método para remover todos os elementos de uma `concurrent_vector` objeto.  
  
-   O `concurrent_vector` classe não armazenar seus elementos de forma contígua na memória. Portanto, você não pode usar o `concurrent_vector` classe em todas as maneiras que você pode usar uma matriz. Por exemplo, para uma variável chamada `v` do tipo `concurrent_vector`, a expressão `&v[0]+2` produz um comportamento indefinido.  
  
-   O `concurrent_vector` classe define o [grow_by](reference/concurrent-vector-class.md#grow_by) e [grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least) métodos. Esses métodos são semelhantes a [redimensionamento](reference/concurrent-vector-class.md#resize) método, exceto que eles sejam seguros de simultaneidade.  
  
-   Um `concurrent_vector` objeto não realocar seus elementos quando anexado a ele ou redimensioná-la. Isso permite que os ponteiros existentes e iteradores permaneça válido durante as operações simultâneas.  
  
-   O tempo de execução não define uma versão especializada do `concurrent_vector` para tipo `bool`.  
  
###  <a name="vector-safety"></a> Operações com segurança de simultaneidade  
 Todos os métodos que acrescentam ao ou aumentam o tamanho de um `concurrent_vector` de objeto ou acessar um elemento em um `concurrent_vector` de objeto, são aceitas de simultaneidade. A exceção a essa regra é o `resize` método.  
  
 A tabela a seguir mostra comuns `concurrent_vector` métodos e operadores que são aceitas de simultaneidade.  
  
||||  
|-|-|-|  

|[em](reference/concurrent-vector-class.md#at)|[final](reference/concurrent-vector-class.md#end)|[operador&#91;&#93;](reference/concurrent-vector-class.md#operator_at)|  
|[Iniciar](reference/concurrent-vector-class.md#begin)|[frontal](reference/concurrent-vector-class.md#front)|[push_back](reference/concurrent-vector-class.md#push_back)|  
|[volta](reference/concurrent-vector-class.md#back)|[grow_by](reference/concurrent-vector-class.md#grow_by)|[rbegin](reference/concurrent-vector-class.md#rbegin)|  
|[capacidade](reference/concurrent-vector-class.md#capacity)|[grow_to_at_least](reference/concurrent-vector-class.md#grow_to_at_least)|[rend](reference/concurrent-vector-class.md#rend)|  
|[vazio](reference/concurrent-vector-class.md#empty)|[max_size](reference/concurrent-vector-class.md#max_size)|[tamanho](reference/concurrent-vector-class.md#size)|  

  
 Operações que o tempo de execução fornece compatibilidade com a biblioteca C++ padrão, por exemplo, `reserve`, não são seguras de simultaneidade. A tabela a seguir mostra os métodos e operadores que não são seguras de simultaneidade comuns.  
  
|||  
|-|-|  

|[atribuir](reference/concurrent-vector-class.md#assign)|[reservar](reference/concurrent-vector-class.md#reserve)|  
|[Limpar](reference/concurrent-vector-class.md#clear)|[redimensionar](reference/concurrent-vector-class.md#resize)|  
|[operador =](reference/concurrent-vector-class.md#operator_eq)|[shrink_to_fit](reference/concurrent-vector-class.md#shrink_to_fit)|  
  
 As operações que modificar o valor de elementos existentes não são seguras de simultaneidade. Usar um objeto de sincronização, como um [reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) objeto sincronizar leitura simultânea e operações de gravação para o mesmo elemento de dados. Para obter mais informações sobre objetos de sincronização, consulte [estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md).  
  
 Quando você converte o código existente que usa `vector` usar `concurrent_vector`, operações simultâneas podem causar o comportamento do seu aplicativo para alterar. Por exemplo, considere o seguinte programa que simultaneamente executa duas tarefas em um `concurrent_vector` objeto. A primeira tarefa acrescenta elementos adicionais para um `concurrent_vector` objeto. A segunda tarefa calcula a soma de todos os elementos no mesmo objeto.  
  
 [!code-cpp[concrt-vector-safety#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_1.cpp)]  
  

 Embora o `end` método é seguro de simultaneidade, uma chamada simultânea para o [push_back](reference/concurrent-vector-class.md#push_back) método faz com que o valor retornado por `end` para alterar. O número de elementos que atravessa o iterador é indeterminado. Portanto, este programa pode produzir um resultado diferente cada vez que você executá-lo.  
  
###  <a name="vector-exceptions"></a> Exceção de segurança  
 Se uma operação de crescimento ou atribuição lança uma exceção, o estado do `concurrent_vector` objeto torna-se inválido. O comportamento de um `concurrent_vector` objeto que está em um estado inválido está indefinido, a menos que indicado de outra forma. No entanto, o destruidor sempre libera a memória que aloca o objeto, mesmo se o objeto está em um estado inválido.  
  
 O tipo de dados dos elementos vetoriais, `T`, deve atender aos seguintes requisitos. Caso contrário, o comportamento do `concurrent_vector` classe é indefinido.  
  
-   O destruidor não deve lançar.  
  
-   Se lançar o construtor padrão ou cópia, o destruidor não deve ser declarado usando a `virtual` palavra-chave e devem funcionar corretamente com memória inicializada do zero.  
  
 [[Superior](#top)]  
  
##  <a name="queue"></a> Classe concurrent_queue  
 O [concurrency::concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) classe, como o [std::queue](../../standard-library/queue-class.md) classe, permite a você acessar frontal e elementos de volta. O `concurrent_queue` classe habilita simultaneidade safe enqueue e dequeue operações. O `concurrent_queue` classe também fornece suporte de iterador que não é seguro de simultaneidade.  
  
###  <a name="queue-differences"></a> Fila e diferenças entre concurrent_queue  
 O `concurrent_queue` classe parecida com a `queue` classe. Os pontos a seguir ilustram onde `concurrent_queue` difere `queue`:  
  
-   Enqueue e dequeue operações em um `concurrent_queue` objeto são aceitas de simultaneidade.  
  
-   O `concurrent_queue` classe fornece suporte de iterador não é segura para simultaneidade.  
  

-   O `concurrent_queue` classe não fornecerá a `front` ou `pop` métodos. O `concurrent_queue` classe substitui esses métodos definindo o [try_pop](reference/concurrent-queue-class.md#try_pop) método.  
  
-   O `concurrent_queue` classe não fornecerá a `back` método. Portanto, você não pode referenciar o final da fila.  
  
-   O `concurrent_queue` classe fornece a [unsafe_size](reference/concurrent-queue-class.md#unsafe_size) método em vez do `size` método. O `unsafe_size` método não é seguro de simultaneidade.  

  
###  <a name="queue-safety"></a> Operações com segurança de simultaneidade  
 Todos os métodos que enfileirar a ou remover da fila de uma `concurrent_queue` objeto são aceitas de simultaneidade.  
  
 A tabela a seguir mostra comuns `concurrent_queue` métodos e operadores que são aceitas de simultaneidade.  
  
|||  
|-|-|  
|[empty](reference/concurrent-queue-class.md#empty)|[push](reference/concurrent-queue-class.md#push)|  
|[get_allocator](reference/concurrent-queue-class.md#get_allocator)|[try_pop](reference/concurrent-queue-class.md#try_pop)|  


  
 Embora o `empty` método é seguro de simultaneidade, uma operação simultânea pode fazer com que a fila seja ampliada ou reduzida antes do `empty` método retorna.  
  
 A tabela a seguir mostra os métodos e operadores que não são seguras de simultaneidade comuns.  
  
|||  
|-|-|  
|[clear](reference/concurrent-queue-class.md#clear)|[unsafe_end](reference/concurrent-queue-class.md#unsafe_end)|  
|[unsafe_begin](reference/concurrent-queue-class.md#unsafe_begin)|[unsafe_size](reference/concurrent-queue-class.md#unsafe_size)|  


  
###  <a name="queue-iterators"></a> Suporte de iterador  
 O `concurrent_queue` fornece iteradores que não são seguras de simultaneidade. É recomendável que você use esses iteradores apenas para depuração.  
  
 Um `concurrent_queue` iterador atravessa os elementos no sentido de encaminhamento somente. A tabela a seguir mostra os operadores que oferece suporte a cada iterador.  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operator++](http://msdn.microsoft.com/en-us/4cfdd07e-927a-42f8-aaa0-d6881687f413)|Avança para o próximo item na fila. Este operador está sobrecarregado para fornecer a semântica de incremento pré e pós-incremento.|  
|[operator*](http://msdn.microsoft.com/en-us/a0e671fc-76e6-4fb4-b95c-ced4dd2b2017)|Recupera uma referência ao item atual.|  
|[operator->](http://msdn.microsoft.com/en-us/41fa393d-ae1e-4a38-bb4b-19e8df709ca9)|Recupera um ponteiro para o item atual.|  
  
 [[Superior](#top)]  
  
##  <a name="unordered_map"></a> Classe concurrent_unordered_map  
 O [HYPERLINK "file:///C:\\\Users\\\thompet\\\AppData\\\Local\\\Temp\\\DxEditor\\\DduePreview\\\Default \\\798d7037-df37-4310-858b-6f590bbf6ebf\\\HTM\\\html\\\a217b4ac-af2b-4d41-94eb-09a75ee28622 "concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) classe é um classe de contêiner associativa que, assim como o [std:: unordered_map](../../standard-library/unordered-map-class.md) classe, controla uma sequência de comprimento variável de elementos do tipo [STD\<chave const, Ty >](../../standard-library/pair-structure.md). Considere um mapa não ordenado como um dicionário que você pode adicionar um par de chave e valor para ou procurar um valor por chave. Essa classe é útil quando você tem vários threads ou tarefas que precisam acessar um contêiner compartilhado simultaneamente, inseri-lo ou atualizá-lo.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_map`. Este exemplo insere chaves de caractere no intervalo ['a', ' i']. Como a ordem das operações é indeterminada, o valor final para cada chave também é indeterminado. No entanto, é seguro executar as inserções em paralelo.  
  
 [!code-cpp[concrt-unordered-map-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_2.cpp)]  
  
 Para obter um exemplo que usa `concurrent_unordered_map` para executar um mapa e reduzir a operação em paralelo, consulte [como: executar o mapa e reduzir operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).  
  
###  <a name="map-differences"></a> Unordered_map e diferenças entre concurrent_unordered_map  
 O `concurrent_unordered_map` classe parecida com a `unordered_map` classe. Os pontos a seguir ilustram onde `concurrent_unordered_map` difere `unordered_map`:  
  
-   O `erase`, `bucket`, `bucket_count`, e `bucket_size` métodos são nomeados `unsafe_erase`, `unsafe_bucket`, `unsafe_bucket_count`, e `unsafe_bucket_size`, respectivamente. O `unsafe_` convenção de nomenclatura indica que esses métodos não são seguras de simultaneidade. Para obter mais informações sobre segurança de simultaneidade, consulte [operações com segurança de simultaneidade](#map-safety).  
  
-   Operações de inserção não invalidar ponteiros existentes ou iteradores nem das mudanças a ordem dos itens que já existe no mapa. Inserir e percorrer as operações podem ocorrer simultaneamente.  
  
-   `concurrent_unordered_map` dá suporte a encaminha apenas a iteração.  
  
-   Inserção não invalidar ou atualizar os iteradores que são retornados pelo `equal_range`. Inserção pode acrescentar itens diferentes para o fim do intervalo. O iterador de begin aponta para um item igual.  
  
 Para ajudar a evitar deadlock, nenhum método de `concurrent_unordered_map` mantém um bloqueio quando ele chama o alocador de memória, as funções de hash ou outro código definido pelo usuário. Além disso, você deve garantir que a função de hash sempre avalia chaves iguais para o mesmo valor. As funções de hash melhor distribuem chaves uniformemente o espaço de código de hash.  
  
###  <a name="map-safety"></a> Operações com segurança de simultaneidade  
 O `concurrent_unordered_map` classe permite que operações de inserção e acesso ao elemento com segurança de simultaneidade. Operações de inserção não invalidar ponteiros existentes ou iteradores. Operações de acesso e a passagem de iterador também são simultaneidade-safe. A tabela a seguir mostra o uso geral `concurrent_unordered_map` métodos e operadores que são aceitas de simultaneidade.  
  
|||||  
|-|-|-|-|  
|[at](reference/concurrent-unordered-map-class.md#at)|`count`|`find`|[key_eq](reference/concurrent-unordered-map-class.md#key_eq)|  
|`begin`|`empty`|`get_allocator`|`max_size`|  
|`cbegin`|`end`|`hash_function`|[operator&#91;&#93;](reference/concurrent-unordered-map-class.md#operator_at)|  
|`cend`|`equal_range`|[insert](reference/concurrent-unordered-map-class.md#insert)|`size`|  
  
 Embora o `count` método pode ser chamado com segurança de threads em execução simultaneamente, threads diferentes podem receber resultados diferentes se um novo valor simultaneamente é inserido no contêiner.  
  
 A tabela a seguir mostra os métodos mais usados e operadores que não são seguras de simultaneidade.  
  
||||  
|-|-|-|  
|`clear`|`max_load_factor`|`rehash`|  
|`load_factor`|[operator=](reference/concurrent-unordered-map-class.md#operator_eq) 


  
 Além desses métodos, qualquer método que que começa com `unsafe_` também não é seguro de simultaneidade.  
  
 [[Superior](#top)]  
  
##  <a name="unordered_multimap"></a> Classe concurrent_unordered_multimap  
 O [concurrency::concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md) classe parecida com a `concurrent_unordered_map` classe exceto que ela permite vários valores mapear para a mesma chave. Também é diferente da `concurrent_unordered_map` das seguintes maneiras:  
  
-   O [concurrent_unordered_multimap:: Insert](reference/concurrent-unordered-multimap-class.md#insert) método retorna um iterador em vez de `std::pair<iterator, bool>`.  

  
-   O `concurrent_unordered_multimap` classe não fornecerá `operator[]` nem o `at` método.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_multimap`. Este exemplo insere chaves de caractere no intervalo ['a', ' i']. `concurrent_unordered_multimap` permite que uma chave para ter vários valores.  
  
 [!code-cpp[concrt-unordered-multimap-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_3.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="unordered_set"></a> Classe concurrent_unordered_set  
 O [concurrency::concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md) classe parecida com a `concurrent_unordered_map` classe exceto que ele gerencia valores em vez de pares de chave e valor. O `concurrent_unordered_set` classe não fornecerá `operator[]` nem o `at` método.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_set`. Este exemplo insere valores de caractere no intervalo ['a', ' i']. É seguro executar as inserções em paralelo.  
  
 [!code-cpp[concrt-unordered-set#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_4.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="unordered_multiset"></a> Classe concurrent_unordered_multiset  
 O [concurrency::concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md) classe parecida com a `concurrent_unordered_set` classe exceto que ela permite valores duplicados. Também é diferente da `concurrent_unordered_set` das seguintes maneiras:  
  

-   O [concurrent_unordered_multiset:: Insert](reference/concurrent-unordered-multiset-class.md#insert) método retorna um iterador em vez de `std::pair<iterator, bool>`.  

  
-   O `concurrent_unordered_multiset` classe não fornecerá `operator[]` nem o `at` método.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_multiset`. Este exemplo insere valores de caractere no intervalo ['a', ' i']. `concurrent_unordered_multiset` permite que um valor ocorrer várias vezes.  
  
 [!code-cpp[concrt-unordered-multiset#1](../../parallel/concrt/codesnippet/cpp/parallel-containers-and-objects_5.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="combinable"></a> Classe combinable  
 O [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe fornece armazenamento reutilizável e local de thread, que permite executar computações refinadas e, em seguida, mesclar os cálculos em um resultado final. Você pode pensar uma `combinable` objeto como uma variável de redução.  
  
 O `combinable` classe é útil quando você tem um recurso que é compartilhado entre vários threads ou tarefas. O `combinable` classe ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de forma livre de bloqueios. Portanto, essa classe fornece uma alternativa ao uso de um mecanismo de sincronização, por exemplo, um mutex para sincronizar o acesso aos dados compartilhados de vários threads.  
  
###  <a name="combinable-features"></a> Métodos e recursos  
 A tabela a seguir mostra alguns dos métodos importantes do `combinable` classe. Para obter mais informações sobre todos os `combinable` métodos de classe, consulte [classe combinable](../../parallel/concrt/reference/combinable-class.md).  
  
|Método|Descrição|  
|------------|-----------------|  
|[local](reference/combinable-class.md#local)|Recupera uma referência à variável local que está associado com o contexto do thread atual.|  
|[clear](reference/combinable-class.md#clear)|Remove todas as variáveis de local de thread do `combinable` objeto.|  
|[combine](reference/combinable-class.md#combine)<br /><br /> [combine_each](reference/combinable-class.md#combine_each)|Usa a função de combinação fornecida para gerar um valor final do conjunto de todos os cálculos de local de thread.|  
  
 O `combinable` classe é uma classe de modelo no resultado final mesclado com parâmetros. Se você chamar o construtor padrão, o `T` o tipo de parâmetro de modelo deve ter um construtor padrão e um construtor de cópia. Se o `T` tipo de parâmetro de modelo não tem um construtor padrão, chame a versão sobrecarregada do construtor que usa uma função de inicialização como seu parâmetro.  
  
 Você pode armazenar dados adicionais em uma `combinable` objeto depois de chamar o [combinar](reference/combinable-class.md#combine) ou [combine_each](reference/combinable-class.md#combine_each) métodos. Você também pode chamar o `combine` e `combine_each` métodos várias vezes. Se nenhum valor local em um `combinable` objeto alterações, o `combine` e `combine_each` métodos produzem o mesmo resultado sempre que eles são chamados.  
  
###  <a name="combinable-examples"></a> Exemplos  
 Para obter exemplos sobre como usar o `combinable` de classe, consulte os tópicos a seguir:  
  
-   [Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)  
  
-   [Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)  
  
 [[Superior](#top)]  
  
## <a name="related-topics"></a>Tópicos relacionados  
 [Como usar contêineres em paralelo para aumentar a eficiência](../../parallel/concrt/how-to-use-parallel-containers-to-increase-efficiency.md)  
 Mostra como usar contêineres paralelos para armazenar de forma eficiente e acessar dados em paralelo.  
  
 [Como usar combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)  
 Mostra como usar o `combinable` de classe para eliminar o estado compartilhado e, assim, melhorar o desempenho.  
  
 [Como usar combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)  
 Mostra como usar um `combine` função para mesclar o local de thread de conjuntos de dados.  
  
 [PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)  
 Descreve a PPL, que fornece um modelo de programação imperativo que promova a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.  
  
## <a name="reference"></a>Referência  
 [Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)  
  
 [Classe concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md)  
  
 [Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)  
  
 [Classe concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)  
  
 [Classe concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md)  
  
 [Classe concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)  
  
 [Classe combinable](../../parallel/concrt/reference/combinable-class.md)
