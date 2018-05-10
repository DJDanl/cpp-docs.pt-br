---
title: Paralelo algoritmos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parallel algorithms [Concurrency Runtime]
ms.assetid: 045dca7b-4d73-4558-a44c-383b88a28473
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 365acd15c61b52631fc75018ab4c3a017d3eed8f
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="parallel-algorithms"></a>Algoritmos paralelos
A biblioteca de padrões paralelos (PPL) fornece algoritmos que executam o trabalho simultaneamente em conjuntos de dados. Esses algoritmos são semelhantes aos fornecidos pela biblioteca C++ padrão.  
  

 Os algoritmos paralelos são compostos de funcionalidade existente no tempo de execução de simultaneidade. Por exemplo, o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo usa um [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto para executar as iterações do loop paralelo. O `parallel_for` partições de algoritmo funcionam de maneira ideal, dada o número de recursos de computação disponíveis.  

  
##  <a name="top"></a> Seções  
  
- [O algoritmo parallel_for](#parallel_for)  
  
- [O algoritmo parallel_for_each](#parallel_for_each)  
  
- [O algoritmo parallel_invoke](#parallel_invoke)  
  
- [Os algoritmos parallel_transform e parallel_reduce](#parallel_transform_reduce)  
  
    - [O algoritmo parallel_transform](#parallel_transform)  
  
    - [O algoritmo parallel_reduce](#parallel_reduce)  
  
    - [Exemplo: Executar mapeamento e redução em paralelo](#map_reduce_example)  
  
- [Trabalho de particionamento](#partitions)  
  
- [Classificando paralela](#parallel_sorting)  
  
    - [Escolhendo um algoritmo de classificação](#choose_sort)  
  
##  <a name="parallel_for"></a> O algoritmo parallel_for  

 O [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo executa repetidamente a mesma tarefa em paralelo. Cada uma dessas tarefas é parametrizada por um valor de iteração. Esse algoritmo é útil quando você tem um corpo do loop que não compartilhe recursos entre iterações do loop.  
  
 O `parallel_for` algoritmo partições tarefas de forma ideal para execução paralela. Ele usa um algoritmo e roubo de saldo essas partições quando as cargas de trabalho estão faltando um intervalo de roubo de trabalho. Quando uma iteração de loop bloqueia trabalhem de forma, o tempo de execução redistribui o intervalo de iterações que é atribuído ao thread atual para outros threads ou processadores. Da mesma forma, quando um thread conclui um intervalo de iterações, o tempo de execução redistribui o trabalho de outros threads para esse thread. O `parallel_for` algoritmo também dá suporte a *aninhados paralelismo*. Quando um loop paralelo contém outro loop paralelo, o tempo de execução coordena os recursos de processamento entre os corpos de loop de uma maneira eficiente para execução paralela.  
  
 O `parallel_for` algoritmo tem várias versões sobrecarregadas. A primeira versão tem um valor inicial, um valor de término e uma função de trabalho (uma expressão lambda, o objeto de função ou o ponteiro de função). A segunda versão tem um valor inicial, um valor de término, um valor pelo qual a etapa e uma função de trabalho. A primeira versão dessa função usa 1 como o valor da etapa. As versões restantes usam objetos de particionador, que permitem que você especifique como `parallel_for` deve particionar intervalos entre threads. Particionadores são explicadas em mais detalhes na seção [trabalho particionamento](#partitions) neste documento.  
  
 Você pode converter muitos `for` loops usar `parallel_for`. No entanto, o `parallel_for` difere do algoritmo de `for` instrução das seguintes maneiras:  
  
-   O `parallel_for` algoritmo `parallel_for` não executa as tarefas em uma ordem predeterminada.  
  
-   O `parallel_for` algoritmo não oferece suporte a condições de encerramento arbitrário. O `parallel_for` algoritmo é interrompido quando o valor atual da variável de iteração é um menor `last`.  
  
-   O `_Index_type` parâmetro de tipo deve ser um tipo integral. Esse tipo integral pode ser assinado ou não assinado.  
  
-   A iteração de loop deve ser para a frente. O `parallel_for` algoritmo gera uma exceção do tipo [std::invalid_argument](../../standard-library/invalid-argument-class.md) se o `_Step` parâmetro for menor que 1.  
  
-   O mecanismo de tratamento de exceção para o `parallel_for` algoritmo difere de um `for` loop. Se várias exceções ocorrem simultaneamente em um corpo do loop paralelo, o tempo de execução propaga apenas uma das exceções para o thread de chamada `parallel_for`. Além disso, quando uma iteração de loop gera uma exceção, o tempo de execução não parar imediatamente o loop geral. Em vez disso, o loop é colocado no estado de cancelamento e o tempo de execução descarta quaisquer tarefas que ainda não foram iniciados. Para obter mais informações sobre os algoritmos paralelos e de manipulação de exceção, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
 Embora o `parallel_for` algoritmo não oferece suporte a condições de encerramento arbitrária, você pode usar cancelamento para parar todas as tarefas. Para obter mais informações sobre cancelamento, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
> [!NOTE]
>  O custo de agendamento que resultados de balanceamento de carga e suporte para recursos como o cancelamento não podem superar os benefícios de executar o corpo do loop em paralelo, especialmente quando o corpo do loop for relativamente pequeno. Você pode minimizar essa sobrecarga usando um particionador em seu loop paralelo. Para obter mais informações, consulte [trabalho particionamento](#partitions) mais adiante neste documento.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica do `parallel_for` algoritmo. Este exemplo imprime no console cada valor no intervalo [1, 5] em paralelo.  
  
 [!code-cpp[concrt-parallel-for-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_1.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir:  
  
```Output  
1 2 4 3 5  
```  
  
 Porque o `parallel_for` algoritmo age em cada item em paralelo, a ordem na qual os valores são impressas no console pode variar.  
  
 Para obter um exemplo completo que usa o `parallel_for` algoritmo, consulte [como: gravar um Loop parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md).  
  
 [[Superior](#top)]  
  
##  <a name="parallel_for_each"></a> O algoritmo parallel_for_each  

 O [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo executa as tarefas em um contêiner iterativo, como as fornecidas pela biblioteca padrão C++, em paralelo. Ele usa a mesma lógica de particionamento que o `parallel_for` usa o algoritmo.  
  
 O `parallel_for_each` algoritmo é semelhante a biblioteca padrão C++ [std::for_each](../../standard-library/algorithm-functions.md#for_each) algoritmo, exceto que o `parallel_for_each` algoritmo executa as tarefas simultaneamente. Como outros algoritmos paralelos, `parallel_for_each` não executa as tarefas em uma ordem específica.  
  
 Embora o `parallel_for_each` algoritmo funciona em iteradores direta e iteradores de acesso aleatório, ele executa melhor com os iteradores de acesso aleatório.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica do `parallel_for_each` algoritmo. Este exemplo imprime no console cada valor em uma [std:: array](../../standard-library/array-class-stl.md) objeto em paralelo.  
  
 [!code-cpp[concrt-parallel-for-each-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_2.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir:  
  
```Output  
4 5 1 2 3  
```  
  
 Porque o `parallel_for_each` algoritmo age em cada item em paralelo, a ordem na qual os valores são impressas no console pode variar.  
  
 Para obter um exemplo completo que usa o `parallel_for_each` algoritmo, consulte [como: gravar um Loop parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md).  
  
 [[Superior](#top)]  
  
##  <a name="parallel_invoke"></a> O algoritmo parallel_invoke  

 O [concurrency::parallel_invoke](reference/concurrency-namespace-functions.md#parallel_invoke) algoritmo executa um conjunto de tarefas em paralelo. Ele não retorna até que cada tarefa seja concluída. Esse algoritmo é útil quando você tem várias tarefas independentes que você deseja executar ao mesmo tempo.  
  
 O `parallel_invoke` algoritmo usa como seus parâmetros de uma série de funções de trabalho (funções lambda, objetos de função ou ponteiros de função). O `parallel_invoke` algoritmo está sobrecarregado para levar entre 10 e dois parâmetros. Cada função que você transmite a `parallel_invoke` deve ter zero parâmetros.  
  
 Como outros algoritmos paralelos, `parallel_invoke` não executa as tarefas em uma ordem específica. O tópico [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md) explica como o `parallel_invoke` algoritmo relaciona a grupos de tarefas e tarefas.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra a estrutura básica do `parallel_invoke` algoritmo. Este exemplo chama simultaneamente a `twice` função em três variáveis locais e imprime o resultado para o console.  
  
 [!code-cpp[concrt-parallel-invoke-structure#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_3.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
108 11.2 HelloHello  
```  
  
 Para obter exemplos de conclusão que usam o `parallel_invoke` algoritmo, consulte [como: usar parallel_invoke para escrever uma rotina de classificação paralela](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md) e [como: usar parallel_invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md).  
  
 [[Superior](#top)]  
  
##  <a name="parallel_transform_reduce"></a> Os algoritmos parallel_transform e parallel_reduce  

 O [concurrency::parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform) e [concurrency::parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce) algoritmos são versões paralelas dos algoritmos de biblioteca padrão C++ [std::transform](../../standard-library/algorithm-functions.md#transform)e [std::accumulate](../../standard-library/numeric-functions.md#accumulate), respectivamente. As versões de tempo de execução de simultaneidade se comportam como as versões da biblioteca padrão C++, exceto que a ordem de operação não é determinada como elas são executadas em paralelo. Use esses algoritmos quando você trabalha com um conjunto que é grande o suficiente para obter benefícios de desempenho e escalabilidade do que está sendo processada em paralelo.  
  
> [!IMPORTANT]
>  O `parallel_transform` e `parallel_reduce` algoritmos dão suporte apenas acesso aleatório, bidirecionais e encaminhar iteradores porque esses iteradores geram endereços de memória estável. Além disso, esses iteradores devem produzir não`const` valores l.  
  
###  <a name="parallel_transform"></a> O algoritmo parallel_transform  
 Você pode usar o `parallel transform` algoritmo para realizar muitas operações de paralelização de dados. Por exemplo, você pode:  
  
-   Ajustar o brilho de uma imagem e executar outras operações de processamento de imagem.  
  
-   Soma ou levar o produto entre dois vetores e outros cálculos numéricos em vetores.  
  
-   Execute um rastreamento de raio 3D, onde cada iteração refere-se a um pixel deve ser renderizado.  
  
 O exemplo a seguir mostra a estrutura básica que é usada para chamar o `parallel_transform` algoritmo. Esse exemplo nega cada elemento de um std::[vetor](../../standard-library/vector-class.md) objeto de duas maneiras. O primeiro modo usa uma expressão lambda. O segundo modo usa [std::negate](../../standard-library/negate-struct.md), que é derivado de [std::unary_function](../../standard-library/unary-function-struct.md).  
  
 [!code-cpp[concrt-basic-parallel-transform#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_4.cpp)]  
  
> [!WARNING]
>  Este exemplo demonstra o uso básico de `parallel_transform`. Porque a função de trabalho não executa uma quantidade significativa de trabalho, um aumento significativo no desempenho não é esperado neste exemplo.  
  
 O `parallel_transform` algoritmo tem duas sobrecargas. A primeira sobrecarga entra em um intervalo de entrada e uma função unário. A função unário pode ser uma expressão lambda que leva um argumento, um objeto de função ou um tipo que deriva de `unary_function`. A segunda sobrecarga leva dois intervalos de entrada e uma função de binária. A função binária pode ser uma expressão lambda que leva dois argumentos, um objeto de função ou um tipo que deriva de [std::binary_function](../../standard-library/binary-function-struct.md). O exemplo a seguir ilustra essas diferenças.  
  
 [!code-cpp[concrt-parallel-transform-vectors#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_5.cpp)]  
  
> [!IMPORTANT]
>  O iterador fornecidas para a saída de `parallel_transform` devem sobrepor completamente o iterador de entrada ou não se sobrepõem. O comportamento desse algoritmo é não especificado se os iteradores de entrada e saídos se sobrepõem parcialmente.  
  
###  <a name="parallel_reduce"></a> O algoritmo parallel_reduce  
 O `parallel_reduce` algoritmo é útil quando você tem uma sequência de operações que satisfazem a propriedade associativa. (Esse algoritmo não requer a propriedade comutativa.) Aqui estão algumas das operações que podem ser executadas com `parallel_reduce`:  
  
-   Multiplique sequências de matrizes para produzir uma matriz.  
  
-   Multiplique um vetor por uma sequência de matrizes para produzir um vetor.  
  
-   Calcule o comprimento de uma sequência de cadeias de caracteres.  
  
-   Combina uma lista de elementos, como cadeias de caracteres, em um elemento.  
  
 O exemplo básico a seguir mostra como usar o `parallel_reduce` algoritmo para combinar uma sequência de cadeias de caracteres em uma cadeia de caracteres. Assim como acontece com os exemplos de `parallel_transform`, ganhos de desempenho não são esperados neste exemplo básico.  
  
 [!code-cpp[concrt-basic-parallel-reduce#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_6.cpp)]  
  
 Em muitos casos, você pode pensar `parallel_reduce` como um atalho para o uso do `parallel_for_each` algoritmo junto com o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe.  
  
###  <a name="map_reduce_example"></a> Exemplo: Executar mapeamento e redução em paralelo  

 Um *mapa* operação se aplica a uma função para cada valor em uma sequência. Um *reduzir* operação combina os elementos de uma sequência em um valor. Você pode usar a biblioteca padrão C++ [std::transform](../../standard-library/algorithm-functions.md#transform) e [std::accumulate](../../standard-library/numeric-functions.md#accumulate) funções para executar o mapa e reduzir as operações. No entanto, para muitos problemas, você pode usar o `parallel_transform` algoritmo para realizar a operação de mapa em paralelo e o `parallel_reduce` algoritmo executar a operação de redução em paralelo.  

  
 O exemplo a seguir compara o tempo que leva para calcular a soma de números primos em série e em paralelo. A fase de mapa transforma valores não primo como 0 e a soma de fase de reduzir os valores.  
  
 [!code-cpp[concrt-parallel-map-reduce-sum-of-primes#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_7.cpp)]  
  
 Outro exemplo que executa um mapa e reduzir a operação em paralelo, consulte [como: executar o mapa e reduzir operações em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md).  
  
 [[Superior](#top)]  
  
##  <a name="partitions"></a> Trabalho de particionamento  
 Para paralelizar a uma operação em uma fonte de dados, uma etapa essencial é *partição* a fonte em várias seções que podem ser acessadas simultaneamente por vários threads. Um particionador Especifica como um algoritmo em paralelo deve particionar intervalos entre threads. Conforme explicado anteriormente neste documento, PPL usa um mecanismo que cria uma carga de trabalho inicial e, em seguida, usa um algoritmo e roubo de saldo essas partições quando as cargas de trabalho estão faltando um intervalo de roubo de trabalho de particionamento de padrão. Por exemplo, quando uma iteração de loop é concluído em um intervalo de iterações, o tempo de execução redistribui o trabalho de outros threads para esse thread. No entanto, para alguns cenários, convém especificar um mecanismo de particionamento diferente que é mais adequado para o seu problema.  
  
 O `parallel_for`, `parallel_for_each`, e `parallel_transform` algoritmos fornecem versões sobrecarregadas que usam um parâmetro adicional, `_Partitioner`. Esse parâmetro define o tipo de particionador que divide o trabalho. Aqui estão os tipos de particionadores PPL define:  
  
 [Concurrency::affinity_partitioner](../../parallel/concrt/reference/affinity-partitioner-class.md)  
 Divisões de trabalho para um número fixo de intervalos (normalmente o número de threads de trabalho que estão disponíveis para trabalhar em loop). É semelhante a este tipo de particionador `static_partitioner`, mas melhora a afinidade do cache, a maneira como ele mapeia os intervalos de threads de trabalho. Esse tipo de particionador pode melhorar o desempenho quando um loop é executado sobre o mesmo conjunto de dados várias vezes (como um loop dentro de um loop) e os dados se encaixa no cache. Este particionador não totalmente participa de cancelamento. Ele também não usa semântica de bloqueio cooperativa e, portanto, não pode ser usado com loops paralelos que têm uma dependência direta.  
  
 [Concurrency::auto_partitioner](../../parallel/concrt/reference/auto-partitioner-class.md)  
 Divisões de trabalho para um número inicial de intervalos (normalmente o número de threads de trabalho que estão disponíveis para trabalhar em loop). O tempo de execução usa esse tipo por padrão, quando você não chama um algoritmo paralelo sobrecarregado que usa um `_Partitioner` parâmetro. Cada intervalo pode ser dividido em subintervalos e, portanto, permite o balanceamento de carga ocorra. Quando um intervalo de trabalho for concluído, o tempo de execução redistribui subintervalos de trabalho de outros threads para esse thread. Use este particionador se sua carga de trabalho não se encaixam em uma das outras categorias ou precisar de suporte completo para o cancelamento ou de bloqueio cooperativo.  
  
 [Concurrency::simple_partitioner](../../parallel/concrt/reference/simple-partitioner-class.md)  
 Divide funciona em intervalos, de modo que cada intervalo tenha pelo menos o número de iterações que são especificados pelo tamanho do bloco especificado. Esse tipo de particionador participa de balanceamento de carga; No entanto, o tempo de execução não dividir intervalos em subintervalos. Para cada funcionário, o tempo de execução verifica o cancelamento e executa o balanceamento de carga após `_Chunk_size` iterações concluir.  
  
 [Concurrency::static_partitioner](../../parallel/concrt/reference/static-partitioner-class.md)  
 Divisões de trabalho para um número fixo de intervalos (normalmente o número de threads de trabalho que estão disponíveis para trabalhar em loop). Esse tipo de particionador pode melhorar o desempenho porque ela não usa o roubo de trabalho e, portanto, tem menos sobrecarga. Use esse tipo de particionador cada iteração de um loop paralelo executa uma quantidade fixa e uniforme de trabalho e você não precisar do suporte ao cancelamento ou encaminhar bloqueio cooperativo.  
  
> [!WARNING]
>  O `parallel_for_each` e `parallel_transform` algoritmos dão suporte a apenas os contêineres que usam os iteradores de acesso aleatório (como std::[vetor](../../standard-library/vector-class.md)) para os particionadores estático, simples e afinidade. O uso de contêineres que usam bidirecional e iteradores forward produz um erro de tempo de compilação. O particionador padrão, `auto_partitioner`, dá suporte a todos os três desses tipos de iterador.  
  
 Normalmente, essas particionadores são usados da mesma forma, exceto para `affinity_partitioner`. A maioria dos tipos de particionador não mantêm o estado e não são modificados pelo tempo de execução. Portanto, você pode criar esses objetos particionador no site de chamada, conforme mostrado no exemplo a seguir.  
  
 [!code-cpp[concrt-static-partitioner#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_8.cpp)]  
  
 No entanto, você deve passar um `affinity_partitioner` objeto como não`const`, valor de l referência para que o algoritmo possa armazenar o estado para futuras loops reutilizar. O exemplo a seguir mostra um aplicativo básico que executa a mesma operação em um conjunto de dados em paralelo várias vezes. O uso de `affinity_partitioner` pode melhorar o desempenho porque a matriz é provável o ajuste no cache.  
  
 [!code-cpp[concrt-affinity-partitioner#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_9.cpp)]  
  
> [!CAUTION]
>  Tenha cuidado ao modificar o código existente que se baseia na semântica de bloqueio cooperativa usar `static_partitioner` ou `affinity_partitioner`. Esses tipos de particionador não usam balanceamento de carga ou roubo de intervalo e, portanto, é podem alterar o comportamento do seu aplicativo.  
  
 A melhor maneira de determinar se deve usar um particionador em qualquer determinado cenário é testá-las e medir o tempo de operações sejam concluídas em cargas de representante e configurações do computador. Por exemplo, o particionamento estático pode fornecer um aumento de velocidade significativo em um computador com vários núcleos que tenha apenas alguns núcleos, mas pode resultar em lentidão em computadores que têm relativamente muitos núcleos.  
  
 [[Superior](#top)]  
  
##  <a name="parallel_sorting"></a> Classificando paralela  

 PPL fornece três algoritmos de classificação: [concurrency::parallel_sort](reference/concurrency-namespace-functions.md#parallel_sort), [concurrency::parallel_buffered_sort](reference/concurrency-namespace-functions.md#parallel_buffered_sort), e [concurrency::parallel_radixsort](reference/concurrency-namespace-functions.md#parallel_radixsort). Esses algoritmos de classificação são úteis quando você tem um conjunto de dados que podem se beneficiar sejam classificados em paralelo. Em particular, a classificação em paralelo é útil quando você tiver um grande conjunto de dados ou quando você usa uma operação de comparação de computação dispendiosa para classificar os dados. Cada um desses algoritmos classifica elementos em vigor.  

  
 O `parallel_sort` e `parallel_buffered_sort` algoritmos são ambos os algoritmos com base em comparar. Ou seja, eles se comparam elementos por valor. O `parallel_sort` algoritmo não tem nenhum requisito de memória adicional e é adequado para classificação de uso geral. O `parallel_buffered_sort` algoritmo pode executar melhor do que `parallel_sort`, mas isso exige espaço (n).  
  
 O `parallel_radixsort` algoritmo é baseado em hash. Ou seja, ele usa chaves de inteiro para classificar os elementos. Usando chaves, esse algoritmo pode calcular diretamente o destino de um elemento em vez de usar comparações. Como `parallel_buffered_sort`, esse algoritmo requer espaço (n).  
  
 A tabela a seguir resume as propriedades importantes dos algoritmos de classificação três paralelos.  
  
|Algoritmo|Descrição|Mecanismo de classificação|Estabilidade de classificação|Requisitos de memória|Complexidade de tempo|Acesso de iterador|  
|---------------|-----------------|-----------------------|--------------------|-------------------------|---------------------|---------------------|  
|`parallel_sort`|Classificação a comparação de uso geral.|Com base em comparação (crescente)|Instável|Nenhum|O((N/P)log(N/P) + 2N((P-1)/P))|Aleatório|  
|`parallel_buffered_sort`|Mais rápida para fins gerais com base em comparação de classificação que requer espaço (n).|Com base em comparação (crescente)|Instável|Requer espaço adicional de (n)|O((N/P)log(N))|Aleatório|  
|`parallel_radixsort`|Classificação baseada em chave inteiro que requer espaço (n).|Com base em hash|Estável|Requer espaço adicional de (n)|O(N/P)|Aleatório|  
  
 A ilustração a seguir mostra as propriedades importantes dos algoritmos de classificação paralelas três mais graficamente.  
  
 ![Comparação dos algoritmos de classificação](../../parallel/concrt/media/concrt_parallel_sorting.png "concrt_parallel_sorting")  
  
 Esses algoritmos de classificação paralelo seguem as regras de cancelamento e manipulação de exceção. Para obter mais informações sobre o tratamento de exceção no tempo de execução de simultaneidade e de cancelamento, consulte [Cancelando algoritmos paralelos](../../parallel/concrt/cancellation-in-the-ppl.md#algorithms) e [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
> [!TIP]
>  Esses algoritmos de classificação paralelo suportam a semântica de animação. Você pode definir um operador de atribuição de movimentação para permitir operações de troca de ocorrer com mais eficiência. Para obter mais informações sobre a semântica de animação e o operador de atribuição de movimentação, consulte [Declarador de referência Rvalue: & &](../../cpp/rvalue-reference-declarator-amp-amp.md), e [construtores mover e mova operadores de atribuição (C++)](../../cpp/move-constructors-and-move-assignment-operators-cpp.md). Se você não fornecer um operador de atribuição de movimentação ou a função de troca, os algoritmos de classificação usam o construtor de cópia.  
  
 O exemplo básico a seguir mostra como usar `parallel_sort` para classificar um `vector` de `int` valores. Por padrão, `parallel_sort` usa [STD](../../standard-library/less-struct.md) para comparar valores.  
  
 [!code-cpp[concrt-basic-parallel-sort#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_10.cpp)]  
  
 Este exemplo mostra como fornecer uma função de comparação personalizada. Ele usa o [std::complex::real](../../standard-library/complex-class.md#real) método para classificar [std::complex\<duplo >](../../standard-library/complex-double.md) valores em ordem crescente.  
  
 [!code-cpp[concrt-basic-parallel-sort#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_11.cpp)]  
  
 Este exemplo mostra como fornecer uma função de hash para o `parallel_radixsort` algoritmo. Este exemplo classifica pontos 3D. Os pontos são classificados com base na sua distância de um ponto de referência.  
  
 [!code-cpp[concrt-parallel-sort-points#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_12.cpp)]  
  
 Para ilustração, este exemplo usa um conjunto de dados relativamente pequeno. Você pode aumentar o tamanho inicial do vetor para fazer experiências com melhorias de desempenho em grandes conjuntos de dados.  
  
 Este exemplo usa uma expressão lambda como a função de hash. Você também pode usar uma das implementações internas da std::[classe hash](../../standard-library/hash-class.md) ou definir seu próprio especialização. Você também pode usar um objeto de função de hash personalizados, conforme mostrado neste exemplo:  
  
 [!code-cpp[concrt-parallel-sort-points#2](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_13.cpp)]  
  
 [!code-cpp[concrt-parallel-sort-points#3](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_14.cpp)]  
  
 A função de hash deve retornar um tipo integral ([std::is_integral::value](../../standard-library/is-integral-class.md) devem ser `true`). Esse tipo integral deve ser conversível para o tipo `size_t`.  
  
###  <a name="choose_sort"></a> Escolhendo um algoritmo de classificação  
 Em muitos casos, `parallel_sort` fornece o melhor equilíbrio entre desempenho de memória e velocidade. No entanto, como você aumentar o tamanho do seu conjunto de dados, o número de processadores disponíveis ou a complexidade de sua função de comparação, `parallel_buffered_sort` ou `parallel_radixsort` podem executar melhor. A melhor maneira de determinar qual algoritmo de classificação a ser usado em qualquer determinado cenário é testá-las e medir quanto tempo demora para classificar dados típicos em configurações do computador representativo. Lembre-se as diretrizes a seguir quando você escolher uma estratégia de classificação.  
  
-   O tamanho do seu conjunto de dados. Neste documento, uma *pequeno* conjunto de dados contém menos de 1.000 elementos, um *médio* conjunto de dados contém entre 10.000 e 100.000 elementos e um *grande* conjunto de dados contém mais de 100.000 elementos.  
  
-   A quantidade de trabalho que executa a função de comparação ou função de hash.  
  
-   A quantidade de recursos de computação disponíveis.  
  
-   As características de seu conjunto de dados. Por exemplo, um algoritmo pode executar bem para dados que já quase são classificados, mas não bem para dados que não estão classificados completamente.  
  
-   O tamanho da parte. Opcional `_Chunk_size` argumento especifica quando o algoritmo alterna entre um paralelo para uma implementação de classificação serial conforme ele subdivide a classificação geral em unidades menores de trabalho. Por exemplo, se você fornecer 512, o algoritmo alterna para implementação serial quando uma unidade de trabalho contém elementos 512 ou menos. Uma implementação serial pode melhorar o desempenho geral, pois elimina a sobrecarga que é necessária para processar dados em paralelo.  
  
 Não pode ser útil para classificar um pequeno conjunto de dados em paralelo, mesmo quando você tiver um grande número de recursos de computação disponíveis ou sua função comparar ou a função de hash realiza uma quantidade relativamente grande de trabalho. Você pode usar [std:: Sort](../../standard-library/algorithm-functions.md#sort) função classificar pequenos conjuntos de dados. (`parallel_sort` e `parallel_buffered_sort` chamar `sort` quando você especificar um tamanho de bloco que é maior do que o conjunto de dados; no entanto, `parallel_buffered_sort` precisa alocar espaço (n), o que pode levar mais tempo devido a alocação de memória ou de contenção de bloqueio.)  
  
 Se você precisa conservar a memória ou o alocador de memória está sujeito a contenção de bloqueio, use `parallel_sort` para classificar um conjunto de dados de médio porte. `parallel_sort` não requer a nenhum espaço adicional; os outros algoritmos requerem espaço (n).  
  
 Use `parallel_buffered_sort` para classificar os conjuntos de dados de médio porte e quando seu aplicativo atende o requisito de espaço adicional (n). `parallel_buffered_sort` pode ser especialmente útil quando você tiver um grande número de recursos de computação ou uma função comparar caro ou função de hash.  
  
 Use `parallel_radixsort` para classificar grandes conjuntos de dados e quando seu aplicativo atende o requisito de espaço adicional (n). `parallel_radixsort` pode ser especialmente útil quando a operação de comparação equivalente é mais cara ou quando as duas operações são caras.  
  
> [!CAUTION]
>  Implementar uma função de hash bom requer que você sabe o intervalo de conjunto de dados e como cada elemento do conjunto de dados é transformado em um valor sem sinal correspondente. Como a operação de hash funciona em valores sem sinal, considere uma estratégia de classificação diferente se valores de hash não assinados não podem ser gerados.  
  
 O exemplo a seguir compara o desempenho de `sort`, `parallel_sort`, `parallel_buffered_sort`, e `parallel_radixsort` em relação ao mesmo conjunto grande de dados aleatórios.  
  
 [!code-cpp[concrt-choosing-parallel-sort#1](../../parallel/concrt/codesnippet/cpp/parallel-algorithms_15.cpp)]  
  
 Neste exemplo, que assume que é aceitável para alocar espaço (n) durante a classificação, `parallel_radixsort` o melhor desempenho nesse conjunto de dados de configuração de computador.  
  
 [[Superior](#top)]  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Como escrever um loop parallel_for](../../parallel/concrt/how-to-write-a-parallel-for-loop.md)|Mostra como usar o `parallel_for` algoritmo para realizar a multiplicação de matrizes.|  
|[Como gravar um loop parallel_for_each](../../parallel/concrt/how-to-write-a-parallel-for-each-loop.md)|Mostra como usar o `parallel_for_each` algoritmo para calcular a contagem de números primos em uma [std:: array](../../standard-library/array-class-stl.md) objeto em paralelo.|  
|[Como usar parallel_invoke para escrever uma rotina de classificação em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-write-a-parallel-sort-routine.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho do algoritmo de classificação bitonic.|  
|[Como usar Parallel.Invoke para executar operações em paralelo](../../parallel/concrt/how-to-use-parallel-invoke-to-execute-parallel-operations.md)|Mostra como usar o `parallel_invoke` algoritmo para melhorar o desempenho de um programa que executa várias operações em uma fonte de dados compartilhada.|  
|[Como realizar operações de mapa e redução em paralelo](../../parallel/concrt/how-to-perform-map-and-reduce-operations-in-parallel.md)|Mostra como usar o `parallel_transform` e `parallel_reduce` algoritmos para executar um mapa e reduzir a operação de contagem de ocorrências de palavras em arquivos.|  
|[PPL (Biblioteca de Padrões Paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md)|Descreve a PPL, que fornece um modelo de programação imperativo que promova a escalabilidade e a facilidade de uso para o desenvolvimento de aplicativos simultâneos.|  
|[Cancelamento no PPL](cancellation-in-the-ppl.md)|Explica a função de cancelamento no PPL, como cancelar o trabalho paralelo e como determinar quando um grupo de tarefas é cancelado.|  
|[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)|Explica a função de manipulação de exceção no tempo de execução de simultaneidade.|  
  
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


