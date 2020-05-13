---
title: Algoritmos paralelos
ms.date: 11/19/2018
helpviewer_keywords:
- parallel algorithms [Concurrency Runtime]
ms.assetid: 045dca7b-4d73-4558-a44c-383b88a28473
ms.openlocfilehash: a31787172c89e23e5eb32aa203b9f541584c0f68
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363205"
---
# <a name="parallel-algorithms"></a>Algoritmos paralelos

A Biblioteca de Padrões Paralelos (PPL) fornece algoritmos que executam simultaneamente trabalhos em coletas de dados. Esses algoritmos se assemelham aos fornecidos pela C++ Standard Library.

Os algoritmos paralelos são compostos a partir da funcionalidade existente no Tempo de Execução de Concorrência. Por exemplo, a [simultâneo::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algorithm usa uma [simultânea::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto para executar as iterações de loop paralelos. As `parallel_for` partições de algoritmo funcionam de forma ideal, dado o número disponível de recursos de computação.

## <a name="sections"></a><a name="top"></a>Seções

- [O Algoritmo parallel_for](#parallel_for)

- [O Algoritmo parallel_for_each](#parallel_for_each)

- [O Algoritmo parallel_for_each](#parallel_invoke)

- [Os Algoritmos parallel_transform e parallel_reduce](#parallel_transform_reduce)

  - [O Algoritmo parallel_transform](#parallel_transform)

  - [O Algoritmo parallel_reduce](#parallel_reduce)

  - [Exemplo: Realizando Mapeamento e Redução em Paralelo](#map_reduce_example)

- [Particionando Trabalho](#partitions)

- [Classificação Paralela](#parallel_sorting)

  - [Escolhendo um Algoritmo de Classificação](#choose_sort)

## <a name="the-parallel_for-algorithm"></a><a name="parallel_for"></a>O algoritmo parallel_for

A [simulta::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algorithm executa repetidamente a mesma tarefa em paralelo. Cada uma dessas tarefas é parametrizada por um valor de iteração. Este algoritmo é útil quando você tem um corpo de loop que não compartilha recursos entre iterações desse loop.

O `parallel_for` algoritmo particiona tarefas de uma maneira ideal para execução paralela. Ele usa um algoritmo de roubo de trabalho e roubo de alcance para equilibrar essas partições quando as cargas de trabalho são desequilibradas. Quando uma iteração de loop bloqueia cooperativamente, o tempo de execução redistribui a gama de iterações atribuídas ao segmento atual para outros segmentos ou processadores. Da mesma forma, quando um segmento completa uma série de iterações, o tempo de execução redistribui o trabalho de outros segmentos para esse segmento. O `parallel_for` algoritmo também suporta *paralelismo aninhado.* Quando um loop paralelo contém outro loop paralelo, o tempo de execução coordena o processamento de recursos entre os corpos de loop de forma eficiente para execução paralela.

O `parallel_for` algoritmo tem várias versões sobrecarregadas. A primeira versão tem um valor inicial, um valor final e uma função de trabalho (uma expressão lambda, objeto de função ou ponteiro de função). A segunda versão tem um valor inicial, um valor final, um valor pelo qual pisar e uma função de trabalho. A primeira versão desta função usa 1 como valor de passo. As demais versões levam objetos `parallel_for` particionadores, que permitem especificar como deve haver intervalos de partição entre os segmentos. Particionários são explicados com mais detalhes na seção [Trabalho de particionamento](#partitions) neste documento.

Você pode `for` converter muitos `parallel_for`loops para usar . No entanto, o `parallel_for` `for` algoritmo difere da afirmação das seguintes maneiras:

- O `parallel_for` `parallel_for` algoritmo não executa as tarefas em uma ordem pré-determinada.

- O `parallel_for` algoritmo não suporta condições arbitrárias de terminação. O `parallel_for` algoritmo pára quando o valor atual da variável `last`de iteração é um a menos que .

- O `_Index_type` parâmetro do tipo deve ser um tipo integral. Este tipo integral pode ser assinado ou não assinado.

- A iteração do loop deve ser para a frente. O `parallel_for` algoritmo lança uma exceção do tipo `_Step` [std::invalid_argument](../../standard-library/invalid-argument-class.md) se o parâmetro for menor que 1.

- O mecanismo de manipulação `parallel_for` de exceções para `for` o algoritmo difere do de um loop. Se várias exceções ocorrerem simultaneamente em um corpo de loop paralelo, o tempo `parallel_for`de execução propaga apenas uma das exceções ao segmento que chamou de . Além disso, quando uma iteração de loop lança uma exceção, o tempo de execução não interrompe imediatamente o loop geral. Em vez disso, o loop é colocado no estado cancelado e o tempo de execução descarta quaisquer tarefas que ainda não tenham sido iniciadas. Para obter mais informações sobre o tratamento de exceções e algoritmos paralelos, consulte [Manipulação de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Embora `parallel_for` o algoritmo não suporte condições arbitrárias de término, você pode usar o cancelamento para parar todas as tarefas. Para obter mais informações sobre cancelamento, consulte [Cancelamento no PPL](cancellation-in-the-ppl.md).

> [!NOTE]
> O custo de agendamento que resulta do balanceamento de carga e suporte para recursos como cancelamento pode não superar os benefícios de executar o corpo de loop em paralelo, especialmente quando o corpo do loop é relativamente pequeno. Você pode minimizar essa sobrecarga usando um particionário no seu loop paralelo. Para obter mais informações, consulte [Particionamento de trabalho](#partitions) mais tarde neste documento.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra `parallel_for` a estrutura básica do algoritmo. Este exemplo imprime para o console cada valor na faixa [1, 5] em paralelo.

[!code-cpp[concrt-parallel-for-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_1.cpp)]

Este exemplo produz a seguinte saída de amostra:

```Output
1 2 4 3 5
```

Como `parallel_for` o algoritmo atua em cada item em paralelo, a ordem em que os valores são impressos para o console variará.

Para um exemplo completo `parallel_for` que usa o algoritmo, [veja Como: Escrever um loop de parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md).

[[Top](#top)]

## <a name="the-parallel_for_each-algorithm"></a><a name="parallel_for_each"></a>O Algoritmo parallel_for_each

O algoritmo [simultâneo::parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) executa tarefas em um contêiner iterativo, como as fornecidas pela Biblioteca Padrão C++, em paralelo. Ele usa a mesma lógica `parallel_for` de particionamento que o algoritmo usa.

O `parallel_for_each` algoritmo se assemelha ao algoritmo da Biblioteca Padrão C++: [for_each,](../../standard-library/algorithm-functions.md#for_each) exceto que o `parallel_for_each` algoritmo executa as tarefas simultaneamente. Como outros algoritmos `parallel_for_each` paralelos, não executa as tarefas em uma ordem específica.

Embora `parallel_for_each` o algoritmo funcione em iteradores de acesso avançado e de acesso aleatório, ele se sai melhor com os iteradores de acesso aleatórios.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra `parallel_for_each` a estrutura básica do algoritmo. Este exemplo imprime no console cada valor em um objeto [de conjunto std::array](../../standard-library/array-class-stl.md) em paralelo.

[!code-cpp[concrt-parallel-for-each-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_2.cpp)]

Este exemplo produz a seguinte saída de amostra:

```Output
4 5 1 2 3
```

Como `parallel_for_each` o algoritmo atua em cada item em paralelo, a ordem em que os valores são impressos para o console variará.

Para um exemplo completo `parallel_for_each` que usa o algoritmo, veja [Como: Escrever um loop de parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md).

[[Top](#top)]

## <a name="the-parallel_invoke-algorithm"></a><a name="parallel_invoke"></a>O Algoritmo parallel_invoke

O algoritmo [de concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) executa um conjunto de tarefas em paralelo. Ele não retorna até que cada tarefa termine. Este algoritmo é útil quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo.

O `parallel_invoke` algoritmo toma como parâmetros uma série de funções de trabalho (funções lambda, objetos de função ou ponteiros de função). O `parallel_invoke` algoritmo está sobrecarregado para tomar entre dois e dez parâmetros. Cada função que `parallel_invoke` você passar deve ter zero parâmetros.

Como outros algoritmos `parallel_invoke` paralelos, não executa as tarefas em uma ordem específica. O tópico [Task Parallelism](../../parallel/concrt/task-parallelism-concurrency-runtime.md) explica como o `parallel_invoke` algoritmo se relaciona com tarefas e grupos de tarefas.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra `parallel_invoke` a estrutura básica do algoritmo. Este exemplo chama simultaneamente a `twice` função em três variáveis locais e imprime o resultado para o console.

[!code-cpp[concrt-parallel-invoke-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_3.cpp)]

Esse exemplo gera a saída a seguir:

```Output
108 11.2 HelloHello
```

Para exemplos completos `parallel_invoke` que usam o algoritmo, veja [Como: Usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como: Usar parallel_invoke para executar operações paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md).

[[Top](#top)]

## <a name="the-parallel_transform-and-parallel_reduce-algorithms"></a><a name="parallel_transform_reduce"></a>Os algoritmos de parallel_transform e parallel_reduce

Os algoritmos [simultâneos::parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform) e [concurrency::parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce) são versões paralelas dos algoritmos c++ Standard Library [std::transform](../../standard-library/algorithm-functions.md#transform) e [std::accumulate](../../standard-library/numeric-functions.md#accumulate), respectivamente. As versões Do Tempo de Execução de Concurrency se comportam como as versões da Biblioteca Padrão C++, exceto que a ordem de operação não é determinada porque elas são executadas em paralelo. Use esses algoritmos quando você trabalha com um conjunto que é grande o suficiente para obter benefícios de desempenho e escalabilidade de ser processado em paralelo.

> [!IMPORTANT]
> Os `parallel_transform` `parallel_reduce` algoritmos suportam apenas o acesso aleatório, os iteradores bidirecionais e avançados porque esses iteradores produzem endereços de memória estáveis. Além disso, esses iteradores`const` devem produzir valores não-l.

### <a name="the-parallel_transform-algorithm"></a><a name="parallel_transform"></a>O Algoritmo parallel_transform

Você pode `parallel transform` usar o algoritmo para executar muitas operações de paraparada de dados. Por exemplo, você pode:

- Ajuste o brilho de uma imagem e execute outras operações de processamento de imagem.

- Suma ou pegue o produto de dot entre dois vetores e realize outros cálculos numéricos em vetores.

- Execute o ray tracing 3D, onde cada iteração se refere a um pixel que deve ser renderizado.

O exemplo a seguir mostra a estrutura `parallel_transform` básica que é usada para chamar o algoritmo. Este exemplo nega cada elemento de um std:: objeto[vetorial](../../standard-library/vector-class.md) de duas maneiras. A primeira maneira usa uma expressão lambda. A segunda maneira usa [std::negate](../../standard-library/negate-struct.md), que deriva de [std::unary_function](../../standard-library/unary-function-struct.md).

[!code-cpp[concrt-basic-parallel-transform#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_4.cpp)]

> [!WARNING]
> Este exemplo demonstra o `parallel_transform`uso básico de . Como a função de trabalho não realiza uma quantidade significativa de trabalho, não se espera um aumento significativo no desempenho neste exemplo.

O `parallel_transform` algoritmo tem duas sobrecargas. A primeira sobrecarga leva um intervalo de entrada e uma função unary. A função unária pode ser uma expressão lambda que leva um argumento, `unary_function`um objeto de função ou um tipo que deriva de . A segunda sobrecarga requer duas faixas de entrada e uma função binária. A função binária pode ser uma expressão lambda que leva dois argumentos, um objeto de função ou um tipo que deriva de [std::binary_function](../../standard-library/binary-function-struct.md). O exemplo a seguir ilustra essas diferenças.

[!code-cpp[concrt-parallel-transform-vectors#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_5.cpp)]

> [!IMPORTANT]
> O ativador que você fornece `parallel_transform` para a saída deve sobrepor completamente o iterizador de entrada ou não se sobrepor a nada. O comportamento deste algoritmo não é especificado se os iteradores de entrada e saída se sobrepõem parcialmente.

### <a name="the-parallel_reduce-algorithm"></a><a name="parallel_reduce"></a>O algoritmo parallel_reduce

O `parallel_reduce` algoritmo é útil quando você tem uma seqüência de operações que satisfazem a propriedade associativa. (Este algoritmo não requer a propriedade comutativa.) Aqui estão algumas das operações `parallel_reduce`que você pode realizar com :

- Multiplique seqüências de matrizes para produzir uma matriz.

- Multiplique um vetor por uma seqüência de matrizes para produzir um vetor.

- Calcule o comprimento de uma seqüência de cordas.

- Combine uma lista de elementos, como cordas, em um elemento.

O exemplo básico a seguir `parallel_reduce` mostra como usar o algoritmo para combinar uma seqüência de strings em uma seqüência. Como nos exemplos `parallel_transform`de , ganhos de desempenho não são esperados neste exemplo básico.

[!code-cpp[concrt-basic-parallel-reduce#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_6.cpp)]

Em muitos casos, você `parallel_reduce` pode pensar como abreviação para o uso do `parallel_for_each` algoritmo juntamente com a classe [simultable::combinável.](../../parallel/concrt/reference/combinable-class.md)

### <a name="example-performing-map-and-reduce-in-parallel"></a><a name="map_reduce_example"></a>Exemplo: Execução de Mapa e Redução em Paralelo

Uma operação *de mapa* aplica uma função a cada valor em uma seqüência. Uma operação *de redução* combina os elementos de uma seqüência em um valor. Você pode usar o C++ Standard Library [std::transform](../../standard-library/algorithm-functions.md#transform) e [std::acumular](../../standard-library/numeric-functions.md#accumulate) funções para executar o mapa e reduzir as operações. No entanto, para muitos `parallel_transform` problemas, você pode usar `parallel_reduce` o algoritmo para realizar a operação do mapa em paralelo e o algoritmo realizar a operação de redução em paralelo.

O exemplo a seguir compara o tempo que leva para calcular a soma dos números primos em série e em paralelo. A fase do mapa transforma valores não primos para 0 e a fase de redução soma os valores.

[!code-cpp[concrt-parallel-map-reduce-sum-of-primes#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_7.cpp)]

Para outro exemplo que realiza um mapa e reduz a operação em paralelo, consulte [Como: Executar mapa e reduzir operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).

[[Top](#top)]

## <a name="partitioning-work"></a><a name="partitions"></a>Trabalho de particionamento

Para paralelenear uma operação em uma fonte de dados, um passo essencial é *dividir* a fonte em várias seções que podem ser acessadas simultaneamente por vários segmentos. Um particionário especifica como um algoritmo paralelo deve particionar intervalos entre os segmentos. Como explicado anteriormente neste documento, o PPL usa um mecanismo de particionamento padrão que cria uma carga de trabalho inicial e, em seguida, usa um algoritmo de roubo de trabalho e roubo de intervalo para equilibrar essas partições quando as cargas de trabalho são desequilibradas. Por exemplo, quando uma iteração de loop completa uma série de iterações, o tempo de execução redistribui o trabalho de outros segmentos para esse segmento. No entanto, para alguns cenários, você pode querer especificar um mecanismo de particionamento diferente que seja mais adequado ao seu problema.

Os `parallel_for` `parallel_for_each`, `parallel_transform` e algoritmos fornecem versões sobrecarregadas `_Partitioner`que tomam um parâmetro adicional, . Este parâmetro define o tipo de particionário que divide o trabalho. Aqui estão os tipos de particioneiros que o PPL define:

[concorrência::affinity_partitioner](../../parallel/concrt/reference/affinity-partitioner-class.md)<br/>
Divide o trabalho em um número fixo de intervalos (normalmente o número de threads de trabalhador que estão disponíveis para trabalhar no loop). Este tipo de `static_partitioner`particionário se assemelha, mas melhora a afinidade de cache pela maneira como mapeia faixas de segmentos de trabalhador. Esse tipo de partição pode melhorar o desempenho quando um loop é executado sobre o mesmo conjunto de dados várias vezes (como um loop dentro de um loop) e os dados se encaixam no cache. Este particionário não participa totalmente do cancelamento. Também não utiliza semântica de bloqueio cooperativo e, portanto, não pode ser usado com loops paralelos que tenham uma dependência para a frente.

[simultas::auto_partitioner](../../parallel/concrt/reference/auto-partitioner-class.md)<br/>
Divide o trabalho em um número inicial de intervalos (normalmente o número de threads de trabalhador que estão disponíveis para trabalhar no loop). O tempo de execução usa esse tipo por padrão quando `_Partitioner` você não chama um algoritmo paralelo sobrecarregado que toma um parâmetro. Cada intervalo pode ser dividido em subfaixas e, assim, permite que ocorra o balanceamento de carga. Quando uma gama de trabalhos é concluída, o tempo de execução redistribui subfaixas de trabalho de outros segmentos para esse segmento. Use este particionário se sua carga de trabalho não se enquadrar em uma das outras categorias ou você precisar de suporte total para cancelamento ou bloqueio cooperativo.

[simultas::simple_partitioner](../../parallel/concrt/reference/simple-partitioner-class.md)<br/>
Divide o trabalho em intervalos de tal forma que cada faixa tenha pelo menos o número de iterações especificadas pelo tamanho do pedaço dado. Este tipo de particionário participa do balanceamento de carga; no entanto, o tempo de execução não divide intervalos em subfaixas. Para cada trabalhador, o tempo de execução verifica `_Chunk_size` o cancelamento e realiza o balanceamento de carga após a conclusão das iterações.

[simultas::static_partitioner](../../parallel/concrt/reference/static-partitioner-class.md)<br/>
Divide o trabalho em um número fixo de intervalos (normalmente o número de threads de trabalhador que estão disponíveis para trabalhar no loop). Este tipo de particionador pode melhorar o desempenho porque não usa roubo de trabalho e, portanto, tem menos sobrecarga. Use este tipo de particionário quando cada iteração de um loop paralelo executa uma quantidade fixa e uniforme de trabalho e você não precisa de suporte para cancelamento ou bloqueio cooperativo avançado.

> [!WARNING]
> Os `parallel_for_each` `parallel_transform` algoritmos suportam apenas contêineres que usam dispositivos de acesso aleatórios (como std::[vetor)](../../standard-library/vector-class.md)para os particionários estáticos, simples e de afinidade. O uso de recipientes que usam dispositivos bidirecionais e dianteiros produz um erro de tempo de compilação. O particionário padrão, `auto_partitioner`suporta todos esses três tipos de iteradores.

Normalmente, esses particioneiros são usados da mesma forma, exceto por `affinity_partitioner`. A maioria dos tipos de particionários não mantém o estado e não são modificados pelo tempo de execução. Portanto, você pode criar esses objetos particionários no local de chamada, como mostrado no exemplo a seguir.

[!code-cpp[concrt-static-partitioner#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_8.cpp)]

No entanto, `affinity_partitioner` você deve passar`const`um objeto como uma referência de valor não-, l para que o algoritmo possa armazenar estado para loops futuros para reutilização. O exemplo a seguir mostra um aplicativo básico que executa a mesma operação em um conjunto de dados em paralelo várias vezes. O uso `affinity_partitioner` de pode melhorar o desempenho porque é provável que a matriz se encaixe em cache.

[!code-cpp[concrt-affinity-partitioner#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_9.cpp)]

> [!CAUTION]
> Tenha cuidado ao modificar o código existente que depende `static_partitioner` do `affinity_partitioner`bloqueio cooperativo da semântica para usar ou . Esses tipos de particionário não usam balanceamento de carga ou roubo de alcance e, portanto, podem alterar o comportamento da sua aplicação.

A melhor maneira de determinar se usar um particionário em um determinado cenário é experimentar e medir quanto tempo leva para as operações serem concluídas sob cargas representativas e configurações de computador. Por exemplo, o particionamento estático pode fornecer um aumento de velocidade significativo em um computador com vários núcleos que tenha apenas alguns núcleos, mas pode resultar em lentidão em computadores que têm relativamente muitos núcleos.

[[Top](#top)]

## <a name="parallel-sorting"></a><a name="parallel_sorting"></a>Classificação Paralela

O PPL fornece três algoritmos de classificação: [concurrency::parallel_sort](reference/concurrency-namespace-functions.md#parallel_sort), [concurrency::parallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort)e [concurrency::parallel_radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort). Esses algoritmos de classificação são úteis quando você tem um conjunto de dados que pode se beneficiar de ser classificado em paralelo. Em particular, a classificação em paralelo é útil quando você tem um grande conjunto de dados ou quando você usa uma operação de comparação computacionalmente cara para classificar seus dados. Cada um desses algoritmos classifica elementos no lugar.

Os `parallel_sort` `parallel_buffered_sort` algoritmos e algoritmos são algoritmos baseados em comparação. Ou seja, eles comparam elementos por valor. O `parallel_sort` algoritmo não tem requisitos adicionais de memória, e é adequado para a classificação de propósito geral. O `parallel_buffered_sort` algoritmo pode `parallel_sort`ter um desempenho melhor do que , mas requer espaço O(N).

O `parallel_radixsort` algoritmo é baseado em hash. Ou seja, ele usa chaves inteiras para classificar elementos. Usando chaves, este algoritmo pode calcular diretamente o destino de um elemento em vez de usar comparações. Como, `parallel_buffered_sort`este algoritmo requer espaço O(N).

A tabela a seguir resume as propriedades importantes dos três algoritmos de classificação paralelos.

|Algoritmo|Descrição|Mecanismo de classificação|Estabilidade de classificação|Requisitos de memória|Complexidade do tempo|Acesso ao Temporter|
|---------------|-----------------|-----------------------|--------------------|-------------------------|---------------------|---------------------|
|`parallel_sort`|Tipo de comparação de propósito geral.|Compara-baseado (ascendente)|Instável|Nenhum|O(N/P)log(N/P) + 2N(P-1)/P))|Aleatório|
|`parallel_buffered_sort`|Classificação mais rápida baseada em comparações de uso geral que requer espaço O(N).|Compara-baseado (ascendente)|Instável|Requer espaço adicional de O(N)|O((N/P)log(N))|Aleatório|
|`parallel_radixsort`|Tipo baseado em chave inteiro que requer espaço O(N).|Baseado em hash|Estável|Requer espaço adicional de O(N)|O(N/P)|Aleatório|

A ilustração a seguir mostra as propriedades importantes dos três algoritmos de classificação paralelos mais graficamente.

![Comparação dos algoritmos de classificação](../../parallel/concrt/media/concrt_parallel_sorting.png "Comparação dos algoritmos de classificação")

Esses algoritmos de classificação paralela seguem as regras de cancelamento e manipulação de exceções. Para obter mais informações sobre cancelamento e tratamento de exceções no Tempo de Execução de Sion, consulte [Cancelando Algoritmos Paralelos](../../parallel/concrt/cancellation-in-the-ppl.md#algorithms) e [Manipulação de Exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

> [!TIP]
> Esses algoritmos de classificação paralela suportam a semântica move. Você pode definir um operador de atribuição de movimento para permitir que as operações de swap ocorram de forma mais eficiente. Para obter mais informações sobre a semântica de movimento e o operador de atribuição de movimento, consulte [Declarator de referência de valor rvalue: &&](../../cpp/rvalue-reference-declarator-amp-amp.md)e [Mover Construtores e Operadores de Atribuição de Movimentação (C++)](../../cpp/move-constructors-and-move-assignment-operators-cpp.md). Se você não fornecer um operador de atribuição de movimento ou função de swap, os algoritmos de classificação usarão o construtor de cópias.

O exemplo básico a `parallel_sort` seguir mostra `vector` `int` como usar para classificar um valor. Por padrão, `parallel_sort` usa [std::menos](../../standard-library/less-struct.md) para comparar valores.

[!code-cpp[concrt-basic-parallel-sort#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_10.cpp)]

Este exemplo mostra como fornecer uma função de comparação personalizada. Ele usa o método [std::complex::real](../../standard-library/complex-class.md#real) para classificar [o std::complexo\<de valores de>dupla](../../standard-library/complex-double.md) em ordem crescente.

[!code-cpp[concrt-basic-parallel-sort#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_11.cpp)]

Este exemplo mostra como fornecer uma `parallel_radixsort` função hash ao algoritmo. Este exemplo classifica pontos 3D. Os pontos são classificados com base na distância de um ponto de referência.

[!code-cpp[concrt-parallel-sort-points#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_12.cpp)]

Para ilustração, este exemplo usa um conjunto de dados relativamente pequeno. Você pode aumentar o tamanho inicial do vetor para experimentar melhorias de desempenho em relação a conjuntos maiores de dados.

Este exemplo usa uma expressão lambda como função hash. Você também pode usar uma das implementações incorporadas do std::[hash class](../../standard-library/hash-class.md) ou definir sua própria especialização. Você também pode usar um objeto de função hash personalizado, como mostrado neste exemplo:

[!code-cpp[concrt-parallel-sort-points#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_13.cpp)]

[!code-cpp[concrt-parallel-sort-points#3](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_14.cpp)]

A função hash deve retornar um tipo integral[(std::is_integral::valor](../../standard-library/is-integral-class.md) deve ser **verdadeiro**). Este tipo integral deve `size_t`ser conversível para digitar .

### <a name="choosing-a-sorting-algorithm"></a><a name="choose_sort"></a>Escolhendo um algoritmo de classificação

Em muitos `parallel_sort` casos, fornece o melhor equilíbrio de velocidade e desempenho de memória. No entanto, à medida que você aumenta o tamanho do seu conjunto de `parallel_buffered_sort` `parallel_radixsort` dados, o número de processadores disponíveis ou a complexidade da sua função de comparação, ou pode ter um desempenho melhor. A melhor maneira de determinar qual algoritmo de classificação usar em qualquer cenário é experimentar e medir quanto tempo leva para classificar dados típicos sob configurações representativas do computador. Tenha em mente as seguintes diretrizes ao escolher uma estratégia de classificação.

- O tamanho do seu conjunto de dados. Neste documento, um *pequeno* conjunto de dados contém menos de 1.000 elementos, um conjunto de dados *médio* contém entre 10.000 e 100.000 elementos, e um *grande* conjunto de dados contém mais de 100.000 elementos.

- A quantidade de trabalho que sua função de comparação ou função hash realiza.

- A quantidade de recursos de computação disponíveis.

- As características do seu conjunto de dados. Por exemplo, um algoritmo pode funcionar bem para dados que já estão quase classificados, mas não tão bem para dados que são completamente desclassificados.

- O tamanho do pedaço. O `_Chunk_size` argumento opcional especifica quando o algoritmo muda de um paralelo para uma implementação de tipo serial, pois subdivide o tipo geral em unidades de trabalho menores. Por exemplo, se você fornecer 512, o algoritmo muda para a implementação serial quando uma unidade de trabalho contém 512 ou menos elementos. Uma implementação serial pode melhorar o desempenho geral porque elimina a sobrecarga necessária para processar dados em paralelo.

Pode não valer a pena classificar um pequeno conjunto de dados em paralelo, mesmo quando você tem um grande número de recursos de computação disponíveis ou sua função de comparação ou função hash executa uma quantidade relativamente grande de trabalho. Você pode usar a função [std::classificar](../../standard-library/algorithm-functions.md#sort) para classificar pequenos conjuntos de dados. (`parallel_sort` `parallel_buffered_sort` e `sort` ligar quando você especificar um tamanho de `parallel_buffered_sort` pedaço maior que o conjunto de dados; no entanto, teria que alocar espaço O(N), o que poderia levar mais tempo devido à contenção de bloqueio ou alocação de memória.)

Se você deve conservar a memória ou seu alocador `parallel_sort` de memória está sujeito à contenção de bloqueio, use para classificar um conjunto de dados de tamanho médio. `parallel_sort`não requer espaço adicional; os outros algoritmos requerem espaço O(N).

Use `parallel_buffered_sort` para classificar conjuntos de dados de médio porte e quando seu aplicativo atender ao requisito adicional de espaço O(N). `parallel_buffered_sort`pode ser especialmente útil quando você tem um grande número de recursos de computação ou uma função de comparação cara ou função hash.

Use `parallel_radixsort` para classificar grandes conjuntos de dados e quando seu aplicativo atender ao requisito adicional de espaço O(N). `parallel_radixsort`pode ser especialmente útil quando a operação de comparação equivalente é mais cara ou quando ambas as operações são caras.

> [!CAUTION]
> A implementação de uma boa função hash requer que você conheça o intervalo do conjunto de dados e como cada elemento no conjunto de dados é transformado em um valor não assinado correspondente. Como a operação hash funciona em valores não assinados, considere uma estratégia de classificação diferente se os valores de hash não assinados não puderem ser produzidos.

O exemplo a seguir `sort`compara `parallel_buffered_sort`o `parallel_radixsort` desempenho de , `parallel_sort`e contra o mesmo grande conjunto de dados aleatórios.

[!code-cpp[concrt-choosing-parallel-sort#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_15.cpp)]

Neste exemplo, que assume que é aceitável alocar espaço O(N) durante o tipo, `parallel_radixsort` executa o melhor neste conjunto de dados nesta configuração do computador.

[[Top](#top)]

## <a name="related-topics"></a>Tópicos Relacionados

|Title|Descrição|
|-----------|-----------------|
|[Como escrever um loop parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md)|Mostra como usar `parallel_for` o algoritmo para realizar a multiplicação matricial.|
|[Como gravar um loop parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md)|Mostra como usar `parallel_for_each` o algoritmo para calcular a contagem de números primos em um objeto [std::array](../../standard-library/array-class-stl.md) em paralelo.|
|[Como usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar `parallel_invoke` o algoritmo para melhorar o desempenho do algoritmo bitônico.|
|[Como: Usar parallel_invoke para executar operações paralelas](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar `parallel_invoke` o algoritmo para melhorar o desempenho de um programa que realiza várias operações em uma fonte de dados compartilhada.|
|[Como realizar operações de mapa e redução em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)|Mostra como usar `parallel_transform` `parallel_reduce` o e algoritmos para executar um mapa e reduzir a operação que conta as ocorrências de palavras em arquivos.|
|[Biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve o PPL, que fornece um modelo de programação imperativo que promove escalabilidade e facilidade de uso para o desenvolvimento de aplicações simultâneas.|
|[Cancelamento no PPL](cancellation-in-the-ppl.md)|Explica o papel do cancelamento no PPL, como cancelar o trabalho paralelo e como determinar quando um grupo de tarefas é cancelado.|
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Explica o papel do manuseio de exceções no Tempo de Execução de Concurrency.|

## <a name="reference"></a>Referência

[função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)

[Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)

[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)

[Classe affinity_partitioner](../../parallel/concrt/reference/affinity-partitioner-class.md)

[Classe auto_partitioner](../../parallel/concrt/reference/auto-partitioner-class.md)

[Classe simple_partitioner](../../parallel/concrt/reference/simple-partitioner-class.md)

[Classe static_partitioner](../../parallel/concrt/reference/static-partitioner-class.md)

[função parallel_sort](reference/concurrency-namespace-functions.md#parallel_sort)

[Função parallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort)

[função parallel_radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort)
