---
title: Algoritmos paralelos
ms.date: 11/19/2018
helpviewer_keywords:
- parallel algorithms [Concurrency Runtime]
ms.assetid: 045dca7b-4d73-4558-a44c-383b88a28473
ms.openlocfilehash: c2d41ccdb8d70095f00cd18508fdff2b78392696
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69631569"
---
# <a name="parallel-algorithms"></a>Algoritmos paralelos

A PPL (biblioteca de padrões paralelos) fornece algoritmos que executam simultaneamente o trabalho em coleções de dados. Esses algoritmos são semelhantes aos fornecidos pela C++ biblioteca padrão.

Os algoritmos paralelos são compostos de uma funcionalidade existente no Tempo de Execução de Simultaneidade. Por exemplo, o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) usa um objeto [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) para executar as iterações de loop paralelo. As `parallel_for` partições de algoritmo funcionam de maneira ideal, considerando o número disponível de recursos de computação.

##  <a name="top"></a>As

- [O algoritmo parallel_for](#parallel_for)

- [O algoritmo parallel_for_each](#parallel_for_each)

- [O algoritmo parallel_invoke](#parallel_invoke)

- [Os algoritmos parallel_transform e parallel_reduce](#parallel_transform_reduce)

    - [O algoritmo parallel_transform](#parallel_transform)

    - [O algoritmo parallel_reduce](#parallel_reduce)

    - [Exemplo: Executando o mapa e a redução em paralelo](#map_reduce_example)

- [Trabalho de particionamento](#partitions)

- [Classificação paralela](#parallel_sorting)

    - [Escolhendo um algoritmo de classificação](#choose_sort)

##  <a name="parallel_for"></a>O algoritmo parallel_for

O algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) executa repetidamente a mesma tarefa em paralelo. Cada uma dessas tarefas é parametrizada por um valor de iteração. Esse algoritmo é útil quando você tem um corpo de loop que não compartilha recursos entre iterações desse loop.

O `parallel_for` algoritmo particiona as tarefas de forma ideal para execução paralela. Ele usa um algoritmo de roubo de trabalho e um roubo de intervalo para balancear essas partições quando as cargas de trabalhos são desbalanceadas. Quando uma iteração de loop é cooperada de cooperativa, o tempo de execução redistribui o intervalo de iterações atribuído ao thread atual para outros threads ou processadores. Da mesma forma, quando um thread conclui um intervalo de iterações, o tempo de execução redistribui o trabalho de outros threads para esse thread. O `parallel_for` algoritmo também dá suporte ao *paralelismo aninhado*. Quando um loop paralelo contém outro loop paralelo, o tempo de execução coordena os recursos de processamento entre os corpos de loop de forma eficiente para execução paralela.

O `parallel_for` algoritmo tem várias versões sobrecarregadas. A primeira versão usa um valor inicial, um valor final e uma função de trabalho (uma expressão lambda, um objeto de função ou um ponteiro de função). A segunda versão usa um valor inicial, um valor final, um valor pelo qual depurar e uma função de trabalho. A primeira versão dessa função usa 1 como o valor da etapa. As versões restantes têm objetos de particionador, que permitem especificar como `parallel_for` os intervalos de partição devem ser especificados entre threads. Os particionadores são explicados com mais detalhes na seção [particionamento de trabalho](#partitions) neste documento.

Você pode converter muitos `for` loops para usar `parallel_for`. No entanto `parallel_for` , o algoritmo difere `for` da instrução das seguintes maneiras:

- O `parallel_for` algoritmo`parallel_for` não executa as tarefas em uma ordem predeterminada.

- O `parallel_for` algoritmo não oferece suporte a condições de término arbitrário. O `parallel_for` algoritmo para quando o valor atual da variável de iteração é menor que `last`.

- O `_Index_type` parâmetro de tipo deve ser um tipo integral. Esse tipo integral pode ser assinado ou não assinado.

- A iteração do loop deve ser encaminhada. O `parallel_for` algoritmo gera uma exceção do tipo [std:: invalid_argument](../../standard-library/invalid-argument-class.md) se o `_Step` parâmetro for menor que 1.

- O mecanismo de tratamento de exceções para `parallel_for` o algoritmo é diferente do de um `for` loop. Se várias exceções ocorrerem simultaneamente em um corpo de loop paralelo, o tempo de execução propaga apenas uma das exceções para o thread `parallel_for`que chamou. Além disso, quando uma iteração de loop gera uma exceção, o tempo de execução não interrompe imediatamente o loop geral. Em vez disso, o loop é colocado no estado cancelado e o tempo de execução descarta todas as tarefas que ainda não foram iniciadas. Para obter mais informações sobre manipulação de exceção e algoritmos paralelos, consulte [manipulação de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Embora o `parallel_for` algoritmo não dê suporte a condições de término arbitrário, você pode usar o cancelamento para interromper todas as tarefas. Para obter mais informações sobre cancelamento, consulte [cancelamento na ppl](cancellation-in-the-ppl.md).

> [!NOTE]
>  O custo de agendamento resultante do balanceamento de carga e do suporte para recursos como cancelamento pode não superar os benefícios da execução do corpo do loop em paralelo, especialmente quando o corpo do loop é relativamente pequeno. Você pode minimizar essa sobrecarga usando um particionador em seu loop paralelo. Para obter mais informações, consulte [particionamento de trabalho](#partitions) mais adiante neste documento.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra a estrutura básica do `parallel_for` algoritmo. Este exemplo imprime no console cada valor no intervalo [1, 5] em paralelo.

[!code-cpp[concrt-parallel-for-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_1.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
1 2 4 3 5
```

Como o `parallel_for` algoritmo atua em cada item em paralelo, a ordem na qual os valores são impressos no console varia.

Para obter um exemplo completo que usa `parallel_for` o algoritmo, [consulte Como: Escreva um loop](../../parallel/concrt/how-to-write-a-parallel-for-loop.md)parallel_for.

[[Superior](#top)]

##  <a name="parallel_for_each"></a>O algoritmo parallel_for_each

O algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) executa tarefas em um contêiner iterativo, como os fornecidos pela biblioteca C++ padrão, em paralelo. Ele usa a mesma lógica de particionamento que o `parallel_for` algoritmo usa.

O `parallel_for_each` algoritmo é semelhante ao C++ algoritmo [std:: for_each](../../standard-library/algorithm-functions.md#for_each) da biblioteca padrão, exceto pelo `parallel_for_each` fato de que o algoritmo executa as tarefas simultaneamente. Assim como outros algoritmos `parallel_for_each` paralelos, o não executa as tarefas em uma ordem específica.

Embora o `parallel_for_each` algoritmo funcione em ambos os iteradores de avanço e iteradores de acesso aleatório, ele é executado melhor com iteradores de acesso aleatórios.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra a estrutura básica do `parallel_for_each` algoritmo. Este exemplo imprime no console cada valor em um objeto [std:: array](../../standard-library/array-class-stl.md) em paralelo.

[!code-cpp[concrt-parallel-for-each-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_2.cpp)]

Este exemplo produz a seguinte saída de exemplo:

```Output
4 5 1 2 3
```

Como o `parallel_for_each` algoritmo atua em cada item em paralelo, a ordem na qual os valores são impressos no console varia.

Para obter um exemplo completo que usa `parallel_for_each` o algoritmo, [consulte Como: Escreva um loop](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md)parallel_for_each.

[[Superior](#top)]

##  <a name="parallel_invoke"></a>O algoritmo parallel_invoke

O algoritmo [Concurrency::p arallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) executa um conjunto de tarefas em paralelo. Ele não retorna até que cada tarefa seja concluída. Esse algoritmo é útil quando você tem várias tarefas independentes que deseja executar ao mesmo tempo.

O `parallel_invoke` algoritmo usa como seus parâmetros uma série de funções de trabalho (funções lambda, objetos de função ou ponteiros de função). O `parallel_invoke` algoritmo está sobrecarregado para levar entre dois e dez parâmetros. Cada função que você passa para `parallel_invoke` deve usar zero parâmetros.

Assim como outros algoritmos `parallel_invoke` paralelos, o não executa as tarefas em uma ordem específica. O tópico [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) explica como o `parallel_invoke` algoritmo está relacionado a tarefas e grupos de tarefas.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra a estrutura básica do `parallel_invoke` algoritmo. Este exemplo chama simultaneamente a `twice` função em três variáveis locais e imprime o resultado no console.

[!code-cpp[concrt-parallel-invoke-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_3.cpp)]

Este exemplo gera a seguinte saída:

```Output
108 11.2 HelloHello
```

Para obter exemplos completos que usam `parallel_invoke` o algoritmo, [consulte Como: Use parallel_invoke para escrever uma rotina](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) de classificação paralela e [como: Use parallel_invoke para executar operações](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)paralelas.

[[Superior](#top)]

##  <a name="parallel_transform_reduce"></a>Os algoritmos parallel_transform e parallel_reduce

A [simultaneidade::p arallel_transform](reference/concurrency-namespace-functions.md#parallel_transform) e a [simultaneidade::p](reference/concurrency-namespace-functions.md#parallel_reduce) algoritmos de arallel_reduce C++ são versões paralelas dos algoritmos de biblioteca padrão [std:: Transform](../../standard-library/algorithm-functions.md#transform) e [std:: Accumulate](../../standard-library/numeric-functions.md#accumulate), respectivamente. As versões Tempo de Execução de Simultaneidade se comportam como as versões padrão da C++ biblioteca, exceto que a ordem da operação não é determinada porque elas são executadas em paralelo. Use esses algoritmos ao trabalhar com um conjunto que seja grande o suficiente para obter os benefícios de desempenho e escalabilidade de serem processados em paralelo.

> [!IMPORTANT]
>  Os `parallel_transform` algoritmos e `parallel_reduce` dão suporte apenas a iteradores de acesso aleatório, bidirecional e encaminhamento porque esses iteradores produzem endereços de memória estáveis. Além disso, esses iteradores devem produzir valores`const` diferentes de l.

###  <a name="parallel_transform"></a>O algoritmo parallel_transform

Você pode usar o `parallel transform` algoritmo para executar muitas operações de paralelização de dados. Por exemplo, você pode:

- Ajuste o brilho de uma imagem e execute outras operações de processamento de imagem.

- Some ou pegue o produto de ponto entre dois vetores e execute outros cálculos numéricos em vetores.

- Execute o rastreamento de Ray 3D, onde cada iteração se refere a um pixel que deve ser renderizado.

O exemplo a seguir mostra a estrutura básica usada para chamar o `parallel_transform` algoritmo. Este exemplo nega cada elemento de um objeto std::[vector](../../standard-library/vector-class.md) de duas maneiras. A primeira maneira usa uma expressão lambda. A segunda maneira usa [std:: Negate](../../standard-library/negate-struct.md), que deriva de [std:: unary_function](../../standard-library/unary-function-struct.md).

[!code-cpp[concrt-basic-parallel-transform#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_4.cpp)]

> [!WARNING]
>  Este exemplo demonstra o uso básico do `parallel_transform`. Como a função de trabalho não executa uma quantidade significativa de trabalho, um aumento significativo no desempenho não é esperado neste exemplo.

O `parallel_transform` algoritmo tem duas sobrecargas. A primeira sobrecarga usa um intervalo de entrada e uma função unário. A função unário pode ser uma expressão lambda que usa um argumento, um objeto Function ou um tipo derivado de `unary_function`. A segunda sobrecarga usa dois intervalos de entrada e uma função binária. A função Binary pode ser uma expressão lambda que usa dois argumentos, um objeto Function ou um tipo derivado de [std:: binary_function](../../standard-library/binary-function-struct.md). O exemplo a seguir ilustra essas diferenças.

[!code-cpp[concrt-parallel-transform-vectors#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_5.cpp)]

> [!IMPORTANT]
>  O iterador que você fornece para a saída `parallel_transform` de deve sobrepor completamente o iterador de entrada ou não se sobrepõe. O comportamento desse algoritmo não será especificado se os iteradores de entrada e saída forem parcialmente sobrepostos.

###  <a name="parallel_reduce"></a>O algoritmo parallel_reduce

O `parallel_reduce` algoritmo é útil quando você tem uma sequência de operações que satisfazem a propriedade associativa. (Esse algoritmo não requer a propriedade comutativa.) Aqui estão algumas das operações que você pode executar com `parallel_reduce`:

- Multiplique seqüências de matrizes para produzir uma matriz.

- Multiplique um vetor por uma sequência de matrizes para produzir um vetor.

- Calcule o comprimento de uma sequência de cadeias de caracteres.

- Combine uma lista de elementos, como cadeias de caracteres, em um elemento.

O exemplo básico a seguir mostra como usar o `parallel_reduce` algoritmo para combinar uma sequência de cadeias de caracteres em uma cadeia. Assim como nos exemplos do `parallel_transform`, os ganhos de desempenho não são esperados neste exemplo básico.

[!code-cpp[concrt-basic-parallel-reduce#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_6.cpp)]

Em muitos casos, você pode considerar `parallel_reduce` como uma abreviação para o uso `parallel_for_each` do algoritmo junto com a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) .

###  <a name="map_reduce_example"></a>Exemplo Executando o mapa e a redução em paralelo

Uma operação de *mapa* aplica uma função a cada valor em uma sequência. Uma operação de *redução* combina os elementos de uma sequência em um valor. Você pode usar as C++ funções padrão de biblioteca [std:: Transform](../../standard-library/algorithm-functions.md#transform) e [std:: Accumulate](../../standard-library/numeric-functions.md#accumulate) para executar operações de mapeamento e redução. No entanto, para muitos problemas, você pode `parallel_transform` usar o algoritmo para executar a operação de mapeamento em `parallel_reduce` paralelo e o algoritmo executa a operação de redução em paralelo.

O exemplo a seguir compara o tempo necessário para calcular a soma dos números primos em série e em paralelo. A fase de mapa transforma valores não primos em 0 e a fase de redução soma os valores.

[!code-cpp[concrt-parallel-map-reduce-sum-of-primes#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_7.cpp)]

Para outro exemplo que executa um mapa e reduz a operação em paralelo, [consulte Como: Execute operações de mapear e reduzir](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)em paralelo.

[[Superior](#top)]

##  <a name="partitions"></a>Trabalho de particionamento

Para paralelizar uma operação em uma fonte de dados, uma etapa essencial é *particionar* a origem em várias seções que podem ser acessadas simultaneamente por vários threads. Um particionador especifica como um algoritmo paralelo deve particionar intervalos entre threads. Conforme explicado anteriormente neste documento, a PPL usa um mecanismo de particionamento padrão que cria uma carga de trabalho inicial e, em seguida, usa um algoritmo de roubo de trabalhos e um roubo de intervalo para balancear essas partições quando as cargas de trabalho são desbalanceadas. Por exemplo, quando uma iteração de loop conclui um intervalo de iterações, o tempo de execução redistribui o trabalho de outros threads para esse thread. No entanto, para alguns cenários, talvez você queira especificar um mecanismo de particionamento diferente que seja mais adequado para o seu problema.

Os `parallel_for`algoritmos `parallel_for_each`, `parallel_transform` e fornecem versões sobrecarregadas que usam um parâmetro adicional, `_Partitioner`. Esse parâmetro define o tipo de particionador que divide o trabalho. Aqui estão os tipos de particionadores que a PPL define:

[concurrency::affinity_partitioner](../../parallel/concrt/reference/affinity-partitioner-class.md)<br/>
Divide o trabalho em um número fixo de intervalos (normalmente o número de threads de trabalho que estão disponíveis para funcionar no loop). Esse tipo de particionador se `static_partitioner`assemelha, mas melhora a afinidade de cache pela maneira como mapeia intervalos para threads de trabalho. Esse tipo de particionador pode melhorar o desempenho quando um loop é executado no mesmo conjunto de dados várias vezes (como um loop dentro de um loop) e os dados se ajustam no cache. Este particionador não participa totalmente do cancelamento. Ele também não usa semântica de bloqueio cooperativo e, portanto, não pode ser usado com loops paralelos que têm uma dependência de avanço.

[concurrency::auto_partitioner](../../parallel/concrt/reference/auto-partitioner-class.md)<br/>
Divide o trabalho em um número inicial de intervalos (normalmente o número de threads de trabalho que estão disponíveis para funcionar no loop). O tempo de execução usa esse tipo por padrão quando você não chama um algoritmo paralelo sobrecarregado que usa um `_Partitioner` parâmetro. Cada intervalo pode ser dividido em subintervalos e, portanto, permite que o balanceamento de carga ocorra. Quando um intervalo de trabalho é concluído, o tempo de execução redistribui subintervalos de trabalho de outros threads para esse thread. Use este particionador se sua carga de trabalho não se enquadrar em uma das outras categorias ou se você precisar de suporte completo para cancelamento ou bloqueio cooperativo.

[concurrency::simple_partitioner](../../parallel/concrt/reference/simple-partitioner-class.md)<br/>
Divide o trabalho em intervalos de forma que cada intervalo tenha pelo menos o número de iterações que são especificadas pelo tamanho da parte especificada. Este tipo de particionador participa do balanceamento de carga; no entanto, o tempo de execução não divide intervalos em subintervalos. Para cada trabalho, o tempo de execução verifica o cancelamento e executa o balanceamento `_Chunk_size` de carga após a conclusão das iterações.

[concurrency::static_partitioner](../../parallel/concrt/reference/static-partitioner-class.md)<br/>
Divide o trabalho em um número fixo de intervalos (normalmente o número de threads de trabalho que estão disponíveis para funcionar no loop). Esse tipo de particionador pode melhorar o desempenho porque não usa o roubo de trabalho e, portanto, tem menos sobrecarga. Use esse tipo de particionador quando cada iteração de um loop paralelo executar uma quantidade fixa e uniforme de trabalho e você não precisar de suporte para o cancelamento ou o bloqueio cooperativo para o encaminhamento.

> [!WARNING]
>  Os `parallel_for_each` algoritmos e `parallel_transform` dão suporte apenas a contêineres que usam iteradores de acesso aleatório (como std::[vector](../../standard-library/vector-class.md)) para os particionadores estáticos, simples e de afinidade. O uso de contêineres que usam iteradores bidirecionais e progressivos produz um erro de tempo de compilação. O particionador padrão, `auto_partitioner`, dá suporte a todos os três tipos de iteradores.

Normalmente, esses particionadores são usados da mesma forma, exceto para `affinity_partitioner`. A maioria dos tipos de particionador não mantém o estado e não é modificado pelo tempo de execução. Portanto, você pode criar esses objetos do particionador no site de chamada, conforme mostrado no exemplo a seguir.

[!code-cpp[concrt-static-partitioner#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_8.cpp)]

No entanto, você deve `affinity_partitioner` passar um objeto como uma`const`referência não-valor l para que o algoritmo possa armazenar o estado de loops futuros para reutilização. O exemplo a seguir mostra um aplicativo básico que executa a mesma operação em um conjunto de dados em paralelo várias vezes. O uso do `affinity_partitioner` pode melhorar o desempenho porque a matriz provavelmente se encaixará no cache.

[!code-cpp[concrt-affinity-partitioner#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_9.cpp)]

> [!CAUTION]
>  Tenha cuidado ao modificar o código existente que depende da semântica de bloqueio cooperativo para `static_partitioner` usar `affinity_partitioner`o ou o. Esses tipos de particionador não usam balanceamento de carga ou roubo de intervalo e, portanto, podem alterar o comportamento do seu aplicativo.

A melhor maneira de determinar se um particionador em qualquer cenário específico é experimentar e medir quanto tempo as operações levam para serem concluídas em cargas representativas e configurações de computador. Por exemplo, o particionamento estático pode fornecer um aumento de velocidade significativo em um computador com vários núcleos que tenha apenas alguns núcleos, mas pode resultar em lentidão em computadores que têm relativamente muitos núcleos.

[[Superior](#top)]

##  <a name="parallel_sorting"></a>Classificação paralela

A PPL fornece três algoritmos de classificação: [simultaneidade::p arallel_sort](reference/concurrency-namespace-functions.md#parallel_sort), [Concurrency::p arallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort)e [Concurrency::p arallel_radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort). Esses algoritmos de classificação são úteis quando você tem um conjunto de dados que pode se beneficiar de ser classificado em paralelo. Em particular, a classificação em paralelo é útil quando você tem um conjunto de dados grande ou quando usa uma operação de comparação computacionalmente dispendiosa para classificar seus dados. Cada um desses algoritmos classifica os elementos no lugar.

Os `parallel_sort` algoritmos e `parallel_buffered_sort` são algoritmos baseados em comparação. Ou seja, eles comparam elementos por valor. O `parallel_sort` algoritmo não tem requisitos de memória adicionais e é adequado para classificação de uso geral. O `parallel_buffered_sort` algoritmo pode ter um desempenho `parallel_sort`melhor do que o, mas requer O (N) espaço.

O `parallel_radixsort` algoritmo é baseado em hash. Ou seja, ele usa chaves de inteiro para classificar elementos. Usando chaves, esse algoritmo pode computar diretamente o destino de um elemento em vez de usar comparações. Assim `parallel_buffered_sort`, esse algoritmo requer o (N) espaço.

A tabela a seguir resume as propriedades importantes dos três algoritmos de classificação paralelas.

|Algoritmo|Descrição|Mecanismo de classificação|Classificar estabilidade|Requisitos de memória|Complexidade do tempo|Acesso ao iterador|
|---------------|-----------------|-----------------------|--------------------|-------------------------|---------------------|---------------------|
|`parallel_sort`|Classificação baseada em comparação de uso geral.|Baseado em comparação (crescente)|Ocorrer|Nenhum|O ((N/P) log (N/P) + 2N ((P-1)/P))|Megabit|
|`parallel_buffered_sort`|Classificação baseada em comparação de uso geral mais rápida que requer O (N) espaço.|Baseado em comparação (crescente)|Ocorrer|Requer O (N) espaço adicional|O ((N/P) log (N))|Megabit|
|`parallel_radixsort`|Classificação baseada em chave de inteiro que requer O (N) espaço.|Com base em hash|Estável|Requer O (N) espaço adicional|O (N/P)|Megabit|

A ilustração a seguir mostra as propriedades importantes dos três algoritmos de classificação paralelas de forma gráfica.

![Comparação dos algoritmos de classificação](../../parallel/concrt/media/concrt_parallel_sorting.png "Comparação dos algoritmos de classificação")

Esses algoritmos de classificação paralela seguem as regras de cancelamento e tratamento de exceção. Para obter mais informações sobre cancelamento e manipulação de exceção no Tempo de Execução de Simultaneidade, consulte [cancelando algoritmos paralelos](../../parallel/concrt/cancellation-in-the-ppl.md#algorithms) e [tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

> [!TIP]
>  Esses algoritmos de classificação paralelas dão suporte à semântica de movimentação. Você pode definir um operador de atribuição de movimentação para permitir que as operações de permuta ocorram com mais eficiência. Para obter mais informações sobre a semântica de movimentação e o operador de atribuição de movimentação, consulte o [Declarador de referência de rvalue: & &](../../cpp/rvalue-reference-declarator-amp-amp.md)e [mover construtores e mover operadores de atribuição (C++)](../../cpp/move-constructors-and-move-assignment-operators-cpp.md). Se você não fornecer um operador de atribuição de movimentação ou uma função de permuta, os algoritmos de classificação usarão o construtor de cópia.

O exemplo básico a seguir mostra como usar `parallel_sort` para classificar um `vector` dos `int` valores. Por padrão, `parallel_sort` o usa os valores [std:: less](../../standard-library/less-struct.md) para comparar.

[!code-cpp[concrt-basic-parallel-sort#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_10.cpp)]

Este exemplo mostra como fornecer uma função de comparação personalizada. Ele usa o método [std:: Complex:: real](../../standard-library/complex-class.md#real) para classificar os valores [padrão de\<> Double complexos](../../standard-library/complex-double.md) em ordem crescente.

[!code-cpp[concrt-basic-parallel-sort#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_11.cpp)]

Este exemplo mostra como fornecer uma função de hash para o `parallel_radixsort` algoritmo. Este exemplo classifica os pontos 3D. Os pontos são classificados com base na distância de um ponto de referência.

[!code-cpp[concrt-parallel-sort-points#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_12.cpp)]

Para ilustração, este exemplo usa um conjunto de dados relativamente pequeno. Você pode aumentar o tamanho inicial do vetor para experimentar com melhorias de desempenho em conjuntos de dados maiores.

Este exemplo usa uma expressão lambda como a função de hash. Você também pode usar uma das implementações internas da classe std::[hash](../../standard-library/hash-class.md) ou definir sua própria especialização. Você também pode usar um objeto de função de hash personalizado, conforme mostrado neste exemplo:

[!code-cpp[concrt-parallel-sort-points#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_13.cpp)]

[!code-cpp[concrt-parallel-sort-points#3](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_14.cpp)]

A função de hash deve retornar um tipo integral ([std:: is_integral:: Value](../../standard-library/is-integral-class.md) deve ser **true**). Este tipo integral deve ser conversível para `size_t`o tipo.

###  <a name="choose_sort"></a>Escolhendo um algoritmo de classificação

Em muitos casos, `parallel_sort` o fornece o melhor equilíbrio entre velocidade e desempenho de memória. No entanto, à medida que você aumenta o tamanho do conjunto de dados, o número de processadores disponíveis ou a complexidade da sua `parallel_buffered_sort` função `parallel_radixsort` de comparação ou pode ter um melhor desempenho. A melhor maneira de determinar qual algoritmo de classificação usar em qualquer cenário específico é experimentar e medir quanto tempo leva para classificar os dados típicos em configurações representativas do computador. Lembre-se das seguintes diretrizes ao escolher uma estratégia de classificação.

- O tamanho do conjunto de dados. Neste documento, um *pequeno* conjunto de informações contém menos de 1.000 elementos, um conjunto de informações *médio* contém entre os elementos 10.000 e 100.000, e um grande conjunto de *grandes* contém mais de 100.000 elementos.

- A quantidade de trabalho que sua função de comparação ou função de hash executa.

- A quantidade de recursos de computação disponíveis.

- As características do seu conjunto de dados. Por exemplo, um algoritmo pode ser bem executado para dados que já estão quase classificados, mas não também para dados que são completamente não classificados.

- O tamanho da parte. O argumento `_Chunk_size` opcional especifica quando o algoritmo alterna de um paralelo para uma implementação de classificação serial à medida que ele subdivide a classificação geral em unidades menores de trabalho. Por exemplo, se você fornecer 512, o algoritmo alternará para a implementação serial quando uma unidade de trabalho contiver 512 ou menos elementos. Uma implementação serial pode melhorar o desempenho geral porque elimina a sobrecarga necessária para processar dados em paralelo.

Talvez não valha a pena classificar um pequeno conjunto de pequenos em paralelo, mesmo quando você tem um grande número de recursos de computação disponíveis ou sua função de comparação ou função de hash executa uma quantidade relativamente grande de trabalho. Você pode usar a função [std:: Sort](../../standard-library/algorithm-functions.md#sort) para classificar pequenos conjuntos de valores. (`parallel_sort` e `parallel_buffered_sort` chamar `parallel_buffered_sort` quando você especificar um tamanho de parte maior do que o conjunto de data; no entanto, teria que alocar O (N) espaço, o que poderia levar mais tempo devido a contenção de bloqueio ou de memória.) `sort`

Se você precisar conservar a memória ou o alocador de memória estiver sujeito à contenção de `parallel_sort` bloqueio, use para classificar um conjunto de um DataSet de tamanho médio. `parallel_sort`Não requer espaço adicional; os outros algoritmos exigem o (N) espaço.

Use `parallel_buffered_sort` para classificar conjuntos de valores de tamanho médio e quando seu aplicativo atender ao requisito de espaço adicional (N). `parallel_buffered_sort`pode ser especialmente útil quando você tem um grande número de recursos de computação ou uma função de comparação ou de hash dispendiosa.

Use `parallel_radixsort` para classificar conjuntos de grandes maiores e quando seu aplicativo atender ao requisito de espaço adicional (N). `parallel_radixsort`pode ser especialmente útil quando a operação de comparação equivalente é mais cara ou quando ambas as operações são caras.

> [!CAUTION]
>  A implementação de uma boa função de hash requer que você conheça o intervalo do conjunto de e como cada elemento no conjunto de valores é transformado em um valor não assinado correspondente. Como a operação de hash funciona em valores não assinados, considere uma estratégia de classificação diferente se valores de hash não assinados não puderem ser produzidos.

O exemplo a seguir compara o desempenho `sort`de `parallel_sort`, `parallel_buffered_sort`, e `parallel_radixsort` com o mesmo conjunto grande de dados aleatórios.

[!code-cpp[concrt-choosing-parallel-sort#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_15.cpp)]

Neste exemplo, que pressupõe que é aceitável alocar o espaço (N) durante a classificação, `parallel_radixsort` o executa o melhor nesse conjunto de DataSet nessa configuração do computador.

[[Superior](#top)]

## <a name="related-topics"></a>Tópicos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Como: Escrever um loop parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md)|Mostra como usar o algoritmo `parallel_for` para executar a multiplicação de matriz.|
|[Como: Escrever um loop parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md)|Mostra como usar o `parallel_for_each` algoritmo para calcular a contagem de números primos em um objeto [std:: array](../../standard-library/array-class-stl.md) em paralelo.|
|[Como: Usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho do algoritmo de classificação bitônico.|
|[Como: Usar parallel_invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada.|
|[Como: Realizar operações de mapa e redução em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)|Mostra como usar os `parallel_transform` algoritmos e `parallel_reduce` para executar um mapa e reduzir a operação que conta as ocorrências de palavras em arquivos.|
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve a PPL, que fornece um modelo de programação imperativo que promove a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.|
|[Cancelamento no PPL](cancellation-in-the-ppl.md)|Explica a função de cancelamento na PPL, como cancelar o trabalho paralelo e como determinar quando um grupo de tarefas é cancelado.|
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Explica a função de manipulação de exceção no Tempo de Execução de Simultaneidade.|

## <a name="reference"></a>Referência

[Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)

[Função parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each)

[Função parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke)

[Classe affinity_partitioner](../../parallel/concrt/reference/affinity-partitioner-class.md)

[Classe auto_partitioner](../../parallel/concrt/reference/auto-partitioner-class.md)

[Classe simple_partitioner](../../parallel/concrt/reference/simple-partitioner-class.md)

[Classe static_partitioner](../../parallel/concrt/reference/static-partitioner-class.md)

[Função parallel_sort](reference/concurrency-namespace-functions.md#parallel_sort)

[Função parallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort)

[Função parallel_radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort)
