---
title: "Cont&#234;ineres e objetos em paralelo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos paralelos"
  - "contêineres paralelos"
  - "contêineres simultâneos"
ms.assetid: 90ab715c-29cd-48eb-8e76-528619aab466
caps.latest.revision: 34
caps.handback.revision: 34
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres e objetos em paralelo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca de padrões paralelos (PPL) inclui vários contêineres e objetos que fornecem acesso thread-safe para seus elementos.  
  
 Um *contêiner simultânea* fornece acesso de prova de simultaneidade para as operações mais importantes. A funcionalidade desses contêineres é parecido com aqueles que são fornecidos pelo modelo Biblioteca STL (Standard). Por exemplo, o [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) classe é semelhante a [std:: Vector](../../standard-library/vector-class.md) classe, exceto que o `concurrent_vector` classe permite que você acrescente elementos em paralelo. Use contêineres simultâneos quando você tiver código paralelo que requer acesso de leitura e gravação no mesmo contêiner.  
  
 Um *objeto simultâneo* compartilhada simultaneamente entre componentes. Um processo que calcula o estado de um objeto simultâneo em paralelo produz o mesmo resultado que outro processo que computa o mesmo estado em série. O [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe é um exemplo de um tipo de objeto simultâneas. O `combinable` classe permite executar cálculos em paralelo e, em seguida, combinar essas computações em um resultado final. Use objetos simultâneos quando caso contrário, você pode usar um mecanismo de sincronização, por exemplo, um mutex para sincronizar o acesso a uma variável compartilhada ou recurso.  
  
##  <a name="a-nametopa-sections"></a><a name="top"></a> Seções  
 Este tópico descreve os seguintes contêineres paralelos e objetos em detalhes.  
  
 Contêineres simultâneos:  
  
-   [Classe concurrent_vector](#vector)  
  
    -   [Vetor e diferenças entre concurrent_vector](#vector-differences)  
  
    -   [Operações de prova de simultaneidade](#vector-safety)  
  
    -   [Segurança de exceção](#vector-exceptions)  
  
-   [Classe concurrent_queue](#queue)  
  
    -   [Fila e as diferenças entre concurrent_queue](#queue-differences)  
  
    -   [Operações de prova de simultaneidade](#queue-safety)  
  
    -   [Suporte a iterador](#queue-iterators)  
  
-   [Classe concurrent_unordered_map](#unordered_map)  
  
    -   [Unordered_map e diferenças entre concurrent_unordered_map](#map-differences)  
  
    -   [Operações de prova de simultaneidade](#map-safety)  
  
-   [Classe concurrent_unordered_multimap](#unordered_multimap)  
  
-   [Classe concurrent_unordered_set](#unordered_set)  
  
-   [Classe concurrent_unordered_multiset](#unordered_multiset)  
  
 Objetos simultâneos:  
  
-   [Classe combinable](#combinable)  
  
    -   [Métodos e recursos](#combinable-features)  
  
    -   [Exemplos](#combinable-examples)  
  
##  <a name="a-namevectora-concurrentvector-class"></a><a name="vector"></a> Classe concurrent_vector  
 O [concurrency::concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md) classe é uma classe de contêiner de sequência que, assim como o [std:: Vector](../../standard-library/vector-class.md) classe, permite que você acesse aleatoriamente seus elementos. O `concurrent_vector` operações de acesso de classe permite que o acréscimo de prova de simultaneidade e elemento. Acrescentar operações não invalidar ponteiros existentes ou iteradores. Operações de acesso e a passagem do iterador também são prova de simultaneidade.  
  
###  <a name="a-namevector-differencesa-differences-between-concurrentvector-and-vector"></a><a name="vector-differences"></a> Vetor e diferenças entre concurrent_vector  
 O `concurrent_vector` classe parecida com a `vector` classe. A complexidade de acrescentar, acesso de elemento e operações de acesso do iterador em uma `concurrent_vector` objeto são os mesmos para uma `vector` objeto. Os pontos a seguir ilustram onde `concurrent_vector` difere `vector`:  
  
-   Acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador em uma `concurrent_vector` objeto são prova de simultaneidade.  
  
-   Você pode adicionar elementos apenas até o fim de uma `concurrent_vector` objeto. O `concurrent_vector` classe não fornece o `insert` método.  
  
-   Um `concurrent_vector` não usar o objeto [semântica de movimentação](../../cpp/rvalue-reference-declarator-amp-amp.md) quando você anexar a ele.  
  
-   O `concurrent_vector` classe não fornece a `erase` ou `pop_back` métodos. Assim como acontece com `vector`, use o [Limpar](../Topic/concurrent_vector::clear%20Method.md) método para remover todos os elementos de uma `concurrent_vector` objeto.  
  
-   O `concurrent_vector` classe não armazenar seus elementos de forma contígua na memória. Portanto, você não pode usar o `concurrent_vector` classe em todas as maneiras que você pode usar uma matriz. Por exemplo, para uma variável chamada `v` do tipo `concurrent_vector`, a expressão `&v[0]+2` produz um comportamento indefinido.  
  
-   O `concurrent_vector` classe define o [grow_by](../Topic/concurrent_vector::grow_by%20Method.md) e [grow_to_at_least](../Topic/concurrent_vector::grow_to_at_least%20Method.md) métodos. Esses métodos se parecer com o [redimensionamento](../Topic/concurrent_vector::resize%20Method.md) método, exceto que eles são prova de simultaneidade.  
  
-   Um `concurrent_vector` objeto não realocar seus elementos quando anexado a ele ou redimensioná-lo. Isso permite que os ponteiros existentes e iteradores permaneça válido durante operações simultâneas.  
  
-   O tempo de execução não define uma versão especializada do `concurrent_vector` para tipo `bool`.  
  
###  <a name="a-namevector-safetya-concurrency-safe-operations"></a><a name="vector-safety"></a> Operações de prova de simultaneidade  
 Todos os métodos que acrescentar a ou aumentam o tamanho de um `concurrent_vector` de objeto ou acessar um elemento em um `concurrent_vector` de objeto, são prova de simultaneidade. A exceção a essa regra é o `resize` método.  
  
 A tabela a seguir mostra o comum `concurrent_vector` métodos e operadores de prova de simultaneidade.  
  
||||  
|-|-|-|  
|[em](../Topic/concurrent_vector::at%20Method.md)|[final](../Topic/concurrent_vector::end%20Method.md)|[operador &#91; &#93;](../Topic/concurrent_vector::operatorOperator.md)|  
|[começar](../Topic/concurrent_vector::begin%20Method.md)|[frente](../Topic/concurrent_vector::front%20Method.md)|[push_back](../Topic/concurrent_vector::push_back%20Method.md)|  
|[Voltar](../Topic/concurrent_vector::back%20Method.md)|[grow_by](../Topic/concurrent_vector::grow_by%20Method.md)|[rbegin](../Topic/concurrent_vector::rbegin%20Method.md)|  
|[capacidade](../Topic/concurrent_vector::capacity%20Method.md)|[grow_to_at_least](../Topic/concurrent_vector::grow_to_at_least%20Method.md)|[rend](../Topic/concurrent_vector::rend%20Method.md)|  
|[vazio](../Topic/concurrent_vector::empty%20Method.md)|[max_size](../Topic/concurrent_vector::max_size%20Method.md)|[tamanho](../Topic/concurrent_vector::size%20Method.md)|  
  
 Operações que o tempo de execução fornece compatibilidade com a STL, por exemplo, `reserve`, não são prova de simultaneidade. A tabela a seguir mostra os métodos e operadores que não são aceitas simultaneidade comuns.  
  
|||  
|-|-|  
|[atribuir](../Topic/concurrent_vector::assign%20Method.md)|[reservar](../Topic/concurrent_vector::reserve%20Method.md)|  
|[Limpar](../Topic/concurrent_vector::clear%20Method.md)|[redimensionar](../Topic/concurrent_vector::resize%20Method.md)|  
|[operador =](../Topic/concurrent_vector::operator=%20Operator.md)|[shrink_to_fit](../Topic/concurrent_vector::shrink_to_fit%20Method.md)|  
  
 As operações que modificam o valor de elementos existentes não são prova de simultaneidade. Usar um objeto de sincronização como um [reader_writer_lock](../Topic/reader_writer_lock%20Class.md) objeto sincronizar leitura simultâneas e operações de gravação ao mesmo elemento de dados. Para obter mais informações sobre objetos de sincronização, consulte [estruturas de dados](../Topic/Synchronization%20Data%20Structures.md).  
  
 Quando você converte o código existente que usa `vector` usar `concurrent_vector`, operações simultâneas podem causar o comportamento do seu aplicativo para alterar. Por exemplo, considere o seguinte programa que executa simultaneamente duas tarefas em uma `concurrent_vector` objeto. A primeira tarefa acrescenta elementos adicionais para uma `concurrent_vector` objeto. A segunda tarefa computa a soma de todos os elementos no mesmo objeto.  
  
 [!code-cpp[concrt-vector-safety#1](../../parallel/concrt/codesnippet/CPP/parallel-containers-and-objects_1.cpp)]  
  
 Embora o `end` método é prova de simultaneidade, uma chamada simultânea para o [push_back](../Topic/concurrent_vector::push_back%20Method.md) método faz com que o valor retornado por `end` para alterar. O número de elementos que atravessa o iterador é indeterminado. Portanto, esse programa pode produzir um resultado diferente cada vez que você executá-lo.  
  
###  <a name="a-namevector-exceptionsa-exception-safety"></a><a name="vector-exceptions"></a> Segurança de exceção  
 Se uma operação de crescimento ou atribuição lança uma exceção, o estado do `concurrent_vector` objeto se torna inválido. O comportamento de uma `concurrent_vector` objeto está em um estado inválido for indefinido, a menos que indicado de outra forma. No entanto, o destruidor sempre libera a memória que aloca o objeto, mesmo que o objeto está em estado inválido.  
  
 O tipo de dados dos elementos do vetor, `T`, deve atender aos seguintes requisitos. Caso contrário, o comportamento da `concurrent_vector` classe é indefinido.  
  
-   O destruidor não deve lançar.  
  
-   Se lançar o construtor padrão ou cópia, o destruidor não deve ser declarado usando o `virtual` palavra-chave e ele devem funcionar corretamente com memória inicializada.  
  
 [[Top](#top)]  
  
##  <a name="a-namequeuea-concurrentqueue-class"></a><a name="queue"></a> Classe concurrent_queue  
 O [concurrency::concurrent_queue](../Topic/concurrent_queue%20Class.md) classe, assim como o [std::queue](../../standard-library/queue-class.md) da classe, que lhe permite acessar sua frente e elementos de volta. O `concurrent_queue` classe habilita prova de simultaneidade enqueue e dequeue operações. O `concurrent_queue` classe também fornece suporte a iterador não prova de simultaneidade.  
  
###  <a name="a-namequeue-differencesa-differences-between-concurrentqueue-and-queue"></a><a name="queue-differences"></a> Fila e as diferenças entre concurrent_queue  
 O `concurrent_queue` classe parecida com a `queue` classe. Os pontos a seguir ilustram onde `concurrent_queue` difere `queue`:  
  
-   Enqueue e dequeue operações em um `concurrent_queue` objeto são prova de simultaneidade.  
  
-   O `concurrent_queue` classe oferece suporte a iterador não prova de simultaneidade.  
  
-   O `concurrent_queue` classe não fornece a `front` ou `pop` métodos. O `concurrent_queue` classe substitui esses métodos definindo o [try_pop](../Topic/concurrent_queue::try_pop%20Method.md) método.  
  
-   O `concurrent_queue` classe não fornece o `back` método. Portanto, você não pode referenciar o final da fila.  
  
-   O `concurrent_queue` classe fornece a [unsafe_size](../Topic/concurrent_queue::unsafe_size%20Method.md) método em vez do `size` método. O `unsafe_size` método não é uma prova de simultaneidade.  
  
###  <a name="a-namequeue-safetya-concurrency-safe-operations"></a><a name="queue-safety"></a> Operações de prova de simultaneidade  
 Todos os métodos que enfileirar a ou remover da fila de uma `concurrent_queue` objeto são prova de simultaneidade.  
  
 A tabela a seguir mostra o comum `concurrent_queue` métodos e operadores de prova de simultaneidade.  
  
|||  
|-|-|  
|[vazio](../Topic/concurrent_queue::empty%20Method.md)|[envio por push](../Topic/concurrent_queue::push%20Method.md)|  
|[get_allocator](../Topic/concurrent_queue::get_allocator%20Method.md)|[try_pop](../Topic/concurrent_queue::try_pop%20Method.md)|  
  
 Embora o `empty` método é prova de simultaneidade, uma operação simultânea pode causar a fila aumentar ou reduzir antes do `empty` método retorna.  
  
 A tabela a seguir mostra os métodos e operadores que não são aceitas simultaneidade comuns.  
  
|||  
|-|-|  
|[Limpar](../Topic/concurrent_queue::clear%20Method.md)|[unsafe_end](../Topic/concurrent_queue::unsafe_end%20Method.md)|  
|[unsafe_begin](../Topic/concurrent_queue::unsafe_begin%20Method.md)|[unsafe_size](../Topic/concurrent_queue::unsafe_size%20Method.md)|  
  
###  <a name="a-namequeue-iteratorsa-iterator-support"></a><a name="queue-iterators"></a> Suporte a iterador  
 O `concurrent_queue` fornece iteradores que não são prova de simultaneidade. É recomendável que você use esses iteradores somente para depuração.  
  
 Um `concurrent_queue` iterador atravessa elementos na direção progressiva. A tabela a seguir mostra os operadores que oferece suporte a cada iterador.  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[operador + +](http://msdn.microsoft.com/pt-br/4cfdd07e-927a-42f8-aaa0-d6881687f413)|Avança para o próximo item na fila. Este operador está sobrecarregado para fornecer a semântica de incremento pré e pós-incremento.|  
|[operador *](http://msdn.microsoft.com/pt-br/a0e671fc-76e6-4fb4-b95c-ced4dd2b2017)|Recupera uma referência ao item atual.|  
|[operador ->](http://msdn.microsoft.com/pt-br/41fa393d-ae1e-4a38-bb4b-19e8df709ca9)|Recupera um ponteiro para o item atual.|  
  
 [[Top](#top)]  
  
##  <a name="a-nameunorderedmapa-concurrentunorderedmap-class"></a><a name="unordered_map"></a> Classe concurrent_unordered_map  
 O [HYPERLINK "file:///C:\\\Users\\\thompet\\\AppData\\\Local\\\Temp\\\DxEditor\\\DduePreview\\\Default\\\798d7037-df37-4310-858b-6f590bbf6ebf\\\HTM\\\html\\\a217b4ac-af2b-4d41-94eb-09a75ee28622" concurrency::concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) é uma classe de contêiner associativo que, assim como o [std::unordered_map](../../standard-library/unordered-map-class.md) da classe, controla uma sequência de comprimento variado de elementos do tipo [std::pair \< chave const, Ty >](../../standard-library/pair-structure.md). Considere um mapa não ordenado como um dicionário que você pode adicionar um par de chave e valor para ou pesquisar um valor por chave. Essa classe é útil quando você tem vários threads ou tarefas que têm acesso a um contêiner compartilhado, insira nele ou atualizá-lo simultaneamente.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_map`. Este exemplo insere as chaves de caractere no intervalo ['a', ' i']. Como a ordem das operações é indeterminada, o valor final para cada chave também é indeterminado. No entanto, é seguro executar as inserções em paralelo.  
  
 [!code-cpp[concrt-unordered-map-structure#1](../../parallel/concrt/codesnippet/CPP/parallel-containers-and-objects_2.cpp)]  
  
 Para obter um exemplo que usa `concurrent_unordered_map` para executar um mapa e reduzir a operação em paralelo, consulte [como: executar o mapa e reduzir operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).  
  
###  <a name="a-namemap-differencesa-differences-between-concurrentunorderedmap-and-unorderedmap"></a><a name="map-differences"></a> Unordered_map e diferenças entre concurrent_unordered_map  
 O `concurrent_unordered_map` classe parecida com a `unordered_map` classe. Os pontos a seguir ilustram onde `concurrent_unordered_map` difere `unordered_map`:  
  
-   O `erase`, `bucket`, `bucket_count`, e `bucket_size` métodos são nomeados `unsafe_erase`, `unsafe_bucket`, `unsafe_bucket_count`, e `unsafe_bucket_size`, respectivamente. O `unsafe_` convenção de nomenclatura indica que esses métodos não são prova de simultaneidade. Para obter mais informações sobre segurança de simultaneidade, consulte [operações com segurança de simultaneidade](#map-safety).  
  
-   Operações de inserção não invalidar ponteiros existentes ou iteradores, nem fazerem alterar a ordem dos itens que já existem no mapa. Inserir e percorrer as operações podem ocorrer simultaneamente.  
  
-   `concurrent_unordered_map` oferece suporte a encaminha apenas a iteração.  
  
-   Inserção não invalidar ou atualizar os iteradores que são retornados pelo `equal_range`. Inserção pode acrescentar itens diferentes para o final do intervalo. O iterador begin aponta para um item igual.  
  
 Para ajudar a evitar o deadlock, nenhum método de `concurrent_unordered_map` mantém um bloqueio quando ele chama o alocador de memória, funções de hash ou outro código definido pelo usuário. Além disso, você deve garantir que a função de hash sempre avalia chaves iguais para o mesmo valor. As funções de hash melhor distribuir chaves uniformemente entre o espaço de código de hash.  
  
###  <a name="a-namemap-safetya-concurrency-safe-operations"></a><a name="map-safety"></a> Operações de prova de simultaneidade  
 O `concurrent_unordered_map` classe permite operações de inserção e acesso de elemento de prova de simultaneidade. Operações de inserção não invalida iteradores ou ponteiros existentes. Operações de acesso e a passagem do iterador também são prova de simultaneidade. A tabela a seguir mostra comumente usados `concurrent_unordered_map` métodos e operadores de prova de simultaneidade.  
  
|||||  
|-|-|-|-|  
|[em](../Topic/concurrent_unordered_map::at%20Method.md)|`count`|`find`|[key_eq](../Topic/concurrent_unordered_map::key_eq%20Method.md)|  
|`begin`|`empty`|`get_allocator`|`max_size`|  
|`cbegin`|`end`|`hash_function`|[operador &#91; &#93;](../Topic/concurrent_unordered_map::operatorOperator.md)|  
|`cend`|`equal_range`|[Inserir](../Topic/concurrent_unordered_map::insert%20Method.md)|`size`|  
  
 Embora o `count` método pode ser chamado com segurança de threads em execução simultaneamente, diferentes threads podem receber resultados diferentes se um novo valor simultaneamente é inserido no contêiner.  
  
 A tabela a seguir mostra os métodos mais usados e os operadores que não são prova de simultaneidade.  
  
||||  
|-|-|-|  
|`clear`|`max_load_factor`|`rehash`|  
|`load_factor`|[operador =](../Topic/concurrent_unordered_map::operator=%20Operator.md)|[troca](../Topic/concurrent_unordered_map::swap%20Method.md)|  
  
 Além desses métodos, qualquer método começa com `unsafe_` também não é prova de simultaneidade.  
  
 [[Top](#top)]  
  
##  <a name="a-nameunorderedmultimapa-concurrentunorderedmultimap-class"></a><a name="unordered_multimap"></a> Classe concurrent_unordered_multimap  
 O [concurrency::concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md) classe parecida com a `concurrent_unordered_map` classe exceto que ela permite vários valores mapear para a mesma chave. Ele também difere `concurrent_unordered_map` das seguintes maneiras:  
  
-   O [concurrent_unordered_multimap:: Insert](../Topic/concurrent_unordered_multimap::insert%20Method.md) método retorna um iterador em vez de `std::pair<iterator, bool>`.  
  
-   O `concurrent_unordered_multimap` não fornece a classe `operator[]` nem `at` método.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_multimap`. Este exemplo insere as chaves de caractere no intervalo ['a', ' i']. `concurrent_unordered_multimap` permite que uma chave para ter vários valores.  
  
 [!code-cpp[concrt-unordered-multimap-structure#1](../../parallel/concrt/codesnippet/CPP/parallel-containers-and-objects_3.cpp)]  
  
 [[Top](#top)]  
  
##  <a name="a-nameunorderedseta-concurrentunorderedset-class"></a><a name="unordered_set"></a> Classe concurrent_unordered_set  
 O [concurrency::concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md) classe parecida com a `concurrent_unordered_map` classe exceto que ele gerencia valores em vez de pares de chave e valor. O `concurrent_unordered_set` não fornece a classe `operator[]` nem `at` método.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_set`. Este exemplo insere valores de caractere no intervalo ['a', ' i']. É seguro executar as inserções em paralelo.  
  
 [!code-cpp[concrt-unordered-set#1](../../parallel/concrt/codesnippet/CPP/parallel-containers-and-objects_4.cpp)]  
  
 [[Top](#top)]  
  
##  <a name="a-nameunorderedmultiseta-concurrentunorderedmultiset-class"></a><a name="unordered_multiset"></a> Classe concurrent_unordered_multiset  
 O [concurrency::concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md) classe parecida com a `concurrent_unordered_set` classe exceto que ela permite valores duplicados. Ele também difere `concurrent_unordered_set` das seguintes maneiras:  
  
-   O [concurrent_unordered_multiset:: Insert](../Topic/concurrent_unordered_multiset::insert%20Method.md) método retorna um iterador em vez de `std::pair<iterator, bool>`.  
  
-   O `concurrent_unordered_multiset` não fornece a classe `operator[]` nem `at` método.  
  
 O exemplo a seguir mostra a estrutura básica para o uso de `concurrent_unordered_multiset`. Este exemplo insere valores de caractere no intervalo ['a', ' i']. `concurrent_unordered_multiset` permite que um valor ocorrer várias vezes.  
  
 [!CODE [concrt-unordered-multiset#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-unordered-multiset#1)]  
  
 [[Top](#top)]  
  
##  <a name="a-namecombinablea-combinable-class"></a><a name="combinable"></a> Classe combinable  
 O [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe fornece armazenamento reutilizável, thread local que permite realizar cálculos refinados e mescle os cálculos em um resultado final. Você pode pensar uma `combinable` objeto como uma variável de redução.  
  
 O `combinable` classe é útil quando você tem um recurso que é compartilhado entre vários threads ou tarefas. O `combinable` classe ajuda a eliminar o estado compartilhado, fornecendo acesso a recursos compartilhados de forma livre de bloqueio. Portanto, essa classe fornece uma alternativa ao uso de um mecanismo de sincronização, por exemplo, um mutex para sincronizar o acesso aos dados compartilhados de vários threads.  
  
###  <a name="a-namecombinable-featuresa-methods-and-features"></a><a name="combinable-features"></a> Métodos e recursos  
 A tabela a seguir mostra alguns dos métodos importantes da `combinable` classe. Para obter mais informações sobre todos os `combinable` métodos de classe, consulte [classe Combinável](../../parallel/concrt/reference/combinable-class.md).  
  
|Método|Descrição|  
|------------|-----------------|  
|[local](../Topic/combinable::local%20Method.md)|Recupera uma referência à variável local que está associado com o contexto do thread atual.|  
|[Limpar](../Topic/combinable::clear%20Method.md)|Remove todas as variáveis locais de thread do `combinable` objeto.|  
|[combinar](../Topic/combinable::combine%20Method.md)<br /><br /> [combine_each](../Topic/combinable::combine_each%20Method.md)|Usa a função de combinar fornecido para gerar um valor final do conjunto de todos os cálculos de thread local.|  
  
 O `combinable` classe é uma classe de modelo que é parametrizada no resultado final mesclado. Se você chamar o construtor padrão, o `T` o tipo de parâmetro do modelo deve ter um construtor padrão e um construtor de cópia. Se o `T` tipo de parâmetro de modelo não tem um construtor padrão, chame a versão sobrecarregada do construtor que assume uma função de inicialização como seu parâmetro.  
  
 Você pode armazenar dados adicionais em uma `combinable` objeto depois de chamar o [combinar](../Topic/combinable::combine%20Method.md) ou [combine_each](../Topic/combinable::combine_each%20Method.md) métodos. Você também pode chamar o `combine` e `combine_each` métodos várias vezes. Se nenhum valor local em um `combinable` objeto alterações, o `combine` e `combine_each` métodos produzem o mesmo resultado sempre que eles são chamados.  
  
###  <a name="a-namecombinable-examplesa-examples"></a><a name="combinable-examples"></a> Exemplos  
 Para obter exemplos sobre como usar o `combinable` da classe, consulte os seguintes tópicos:  
  
-   [Como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)  
  
-   [Como: usar Combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)  
  
 [[Top](#top)]  
  
## <a name="related-topics"></a>Tópicos relacionados  
 [Como: usar contêineres em paralelo para aumentar a eficiência](../Topic/How%20to:%20Use%20Parallel%20Containers%20to%20Increase%20Efficiency.md)  
 Mostra como usar contêineres em paralelo para armazenar de forma eficiente e acessar dados em paralelo.  
  
 [Como: usar Combinável para melhorar o desempenho](../../parallel/concrt/how-to-use-combinable-to-improve-performance.md)  
 Mostra como usar o `combinable` de classe para eliminar o estado compartilhado e, portanto, melhorar o desempenho.  
  
 [Como: usar Combinável para combinar conjuntos](../../parallel/concrt/how-to-use-combinable-to-combine-sets.md)  
 Mostra como usar um `combine` função mesclar thread local conjuntos de dados.  
  
 [Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)  
 Descreve a PPL, que fornece um modelo de programação fundamental que promove a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.  
  
## <a name="reference"></a>Referência  
 [Classe concurrent_vector](../../parallel/concrt/reference/concurrent-vector-class.md)  
  
 [Classe concurrent_queue](../Topic/concurrent_queue%20Class.md)  
  
 [Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)  
  
 [Classe concurrent_unordered_multimap](../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)  
  
 [Classe concurrent_unordered_set](../../parallel/concrt/reference/concurrent-unordered-set-class.md)  
  
 [Classe concurrent_unordered_multiset](../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)  
  
 [Classe combinable](../../parallel/concrt/reference/combinable-class.md)
