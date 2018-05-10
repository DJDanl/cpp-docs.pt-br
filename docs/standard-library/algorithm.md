---
title: '&lt;algorithm&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <algorithm>
dev_langs:
- C++
helpviewer_keywords:
- algorithm header [C++]
- C++ Standard Library, algorithms
- <algorithm> header
ms.assetid: 19f97711-7a67-4a65-8fd1-9a2bd3ca327d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc5e181a933c0c511802a0270026635a1766a7be
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="ltalgorithmgt"></a>&lt;algorithm&gt;

Define as funções de modelo do contêiner da Biblioteca Padrão do C++ que executam algoritmos.

## <a name="syntax"></a>Sintaxe

```cpp
(see relevant links below for specific algorithm syntax)
```

## <a name="remarks"></a>Comentários

Os algoritmos da Biblioteca Padrão do C++ são genéricos, porque eles podem operar em uma variedade de estruturas de dados. As estruturas de dados nas quais eles podem operar incluem, além das classes de contêiner da Biblioteca Padrão do C++, como `vector` e `list`, estruturas de dados definidas pelo programa e matrizes de elementos que atendem aos requisitos de um determinado algoritmo. Os algoritmos da Biblioteca Padrão do C++ atingem esse nível de generalidade acessando e percorrendo os elementos de um contêiner indiretamente por meio de iteradores.

Os algoritmos da Biblioteca Padrão do C++ processam intervalos de iteradores que, geralmente, são especificados pelas sua posições iniciais ou finais. Os intervalos referenciados devem ser válidos no sentido de que todos os ponteiros nos intervalos devem ser desreferenciáveis e, dentro das sequências de cada intervalo, e a última posição deve ser acessível desde a primeira por incrementação.

Os algoritmos da Biblioteca Padrão do C++ ampliam as ações com suporte das operações e funções de membro de cada contêiner da Biblioteca Padrão do C++ e permitem, por exemplo, trabalhar com diferentes tipos de objetos do contêiner ao mesmo tempo. Dois sufixos foram usados para transportar informações sobre o objetivo dos algoritmos.

- O sufixo `_if` indica que o algoritmo é usado com objetos de função operando nos valores dos elementos, e não nos valores dos próprios elementos. O algoritmo `find_if` busca elementos cujos valores atendam ao critério especificado por um objeto de função e o algoritmo `find` busca um valor específico.

- O sufixo _copy indica que o algoritmo, além de manipular os valores dos elementos, também copia os valores modificados em um intervalo de destino. O algoritmo `reverse` inverte a ordem dos elementos dentro de um intervalo e o algoritmo `reverse_copy` também copia o resultado em um intervalo de destino.

Os algoritmos da Biblioteca Padrão do C++ geralmente são classificados em grupos que indicam algo sobre sua finalidade ou seus requisitos. Eles incluem algoritmos modificadores que alteram o valor de elementos, em comparação com os algoritmos não modificadores. Os algoritmos mutantes alteram a ordem dos elementos, mas não os valores de seus elementos. A remoção dos algoritmos pode eliminar elementos de um intervalo ou uma cópia de um intervalo. Algoritmos de classificação reordenar os elementos em um intervalo de várias maneiras e algoritmos de intervalo classificado apenas atuam em intervalos que tenham sido classificados cujos elementos de uma maneira específica.

Os algoritmos numéricos da Biblioteca Padrão do C++ que são fornecidos para processamento numérico têm seu próprio arquivo de cabeçalho [\<numeric>](../standard-library/numeric.md) e objetos de função e adaptadores de função são definidos no cabeçalho [\<functional>](../standard-library/functional.md). Os objetos de função que retornam valores boolianos são conhecidos como predicados. O predicado binário padrão é a comparação `operator<`. De modo geral, os elementos que estão sendo ordenados precisam ser menores que os comparáveis, de modo que, considerando dois elementos, possa ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes.

### <a name="function-templates"></a>Modelos de função

|Modelo de função|Descrição|
|-|-|
|[adjacent_find](../standard-library/algorithm-functions.md#adjacent_find)|Procura dois elementos adjacentes que sejam iguais ou atendam a uma condição especificada.|
|[all_of](../standard-library/algorithm-functions.md#all_of)|Retorna `true` quando uma condição está presente em cada elemento no intervalo determinado.|
|[any_of](../standard-library/algorithm-functions.md#any_of)|Retorna `true` quando uma condição está presente, pelo menos, uma vez no intervalo de elementos especificado.|
|[binary_search](../standard-library/algorithm-functions.md#binary_search)|Testa se há um elemento em um intervalo classificado que seja igual a um valor especificado ou equivalente a ele de modo especificado por um predicado binário.|
|[copy](../standard-library/algorithm-functions.md#copy)|Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção progressiva.|
|[copy_backward](../standard-library/algorithm-functions.md#copy_backward)|Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção retroativa.|
|[copy_if](../standard-library/algorithm-functions.md#copy_if)|Copia todos os elementos em um determinado intervalo que testam uma condição especificada de `true`.|
|[copy_n](../standard-library/algorithm-functions.md#copy_n)|Copia um número especificado de elementos.|
|[count](../standard-library/algorithm-functions.md#count)|Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.|
|[count_if](../standard-library/algorithm-functions.md#count_if)|Retorna o número de elementos em um intervalo cujos valores correspondem a uma condição especificada.|
|[equal](../standard-library/algorithm-functions.md#equal)|Compara a igualdade ou equivalência de dois intervalos, elemento por elemento, de certo modo especificado por um predicado binário.|
|[equal_range](../standard-library/algorithm-functions.md#equal_range)|Localiza um par de posições em um intervalo ordenado, o primeiro menor ou equivalente à posição de um elemento especificado e o segundo maior que a posição do elemento, em que o sentido de equivalência ou de ordenação usada para estabelecer as posições na sequência pode ser especificado por um predicado binário.|
|[fill](../standard-library/algorithm-functions.md#fill)|Atribui o mesmo novo valor para cada elemento em um intervalo especificado.|
|[fill_n](../standard-library/algorithm-functions.md#fill_n)|Atribuir um novo valor a um número especificado de elementos em um intervalo que começa com um elemento específico.|
|[find](../standard-library/algorithm-functions.md#find)|Localiza a posição da primeira ocorrência de um elemento em um intervalo que tem um valor especificado.|
|[find_end](../standard-library/algorithm-functions.md#find_end)|Examina um intervalo em busca da última subsequência que seja idêntica a uma sequência especificada ou que seja equivalente de certo modo especificado por um predicado binário.|
|[find_first_of](../standard-library/algorithm-functions.md#find_first_of)|Procura a primeira ocorrência de qualquer um dos vários valores em um intervalo de destino ou a primeira ocorrência de qualquer um dos vários elementos que são equivalentes de certo modo especificado por um predicado binário a um conjunto especificado dos elementos.|
|[find_if](../standard-library/algorithm-functions.md#find_if)|Localiza a posição da primeira ocorrência de um elemento em um intervalo que atende a uma condição especificada.|
|[find_if_not](../standard-library/algorithm-functions.md#find_if_not)|Retorna o primeiro elemento no intervalo indicado que não atende a uma condição.|
|[for_each](../standard-library/algorithm-functions.md#for_each)|Aplica um objeto de função especificado a cada elemento em uma ordem progressiva dentro de um intervalo e retorna o objeto de função.|
|[generate](../standard-library/algorithm-functions.md#generate)|Atribui os valores gerados por um objeto de função a cada elemento em um intervalo.|
|[generate_n](../standard-library/algorithm-functions.md#generate_n)|Atribui os valores gerados por um objeto de função a um número especificado de elementos em um intervalo e retorna para uma posição antes do último valor atribuído.|
|[includes](../standard-library/algorithm-functions.md#includes)|Testa se um intervalo classificado contém todos os elementos contidos em um segundo intervalo classificado, em que o critério de equivalência ou ordenação entre elementos pode ser especificado por um predicado binário.|
|[inplace_merge](../standard-library/algorithm-functions.md#inplace_merge)|Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[is_heap](../standard-library/algorithm-functions.md#is_heap)|Retornará `true` se os elementos no intervalo especificado formarem um heap.|
|[is_heap_until](../standard-library/algorithm-functions.md#is_heap_until)|Retornará `true` se o intervalo especificado formar um heap até o último elemento.|
|[is_partitioned](../standard-library/algorithm-functions.md#is_partitioned)|Retornará `true` se todos os elementos no intervalo determinado que testam `true` para uma condição vierem antes de qualquer elemento que testa `false`.|
|[is_permutation](../standard-library/algorithm-functions.md#is_permutation)|Determina se os elementos em determinado intervalo formam uma permutação válida.|
|[is_sorted](../standard-library/algorithm-functions.md#is_sorted)|Retornará `true` se os elementos no intervalo especificado estiverem em ordem classificada.|
|[is_sorted_until](../standard-library/algorithm-functions.md#is_sorted_until)|Retornará `true` se os elementos no intervalo especificado estiverem em ordem classificada.|
|[iter_swap](../standard-library/algorithm-functions.md#iter_swap)|Troca dois valores referenciados por um par de iteradores especificados.|
|[lexicographical_compare](../standard-library/algorithm-functions.md#lexicographical_compare)|Compara elemento por elemento entre duas sequências para determinar qual é o menor dos dois.|
|[lower_bound](../standard-library/algorithm-functions.md#lower_bound)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior ou equivalente a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[make_heap](../standard-library/algorithm-functions.md#make_heap)|Converte os elementos de um intervalo especificado em um heap no qual o primeiro elemento é o maior e para o qual um critério de classificação pode ser especificado com um predicado binário.|
|[max](../standard-library/algorithm-functions.md#max)|Compara dois objetos e retorna o maior dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[max_element](../standard-library/algorithm-functions.md#max_element)|Localiza a primeira ocorrência do maior elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[merge](../standard-library/algorithm-functions.md#merge)|Combina todos os elementos de dois intervalos classificados de origem em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[min](../standard-library/algorithm-functions.md#min)|Compara dois objetos e retorna o menor dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[min_element](../standard-library/algorithm-functions.md#min_element)|Localiza a primeira ocorrência do menor elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[minmax](../standard-library/algorithm-functions.md#minmax)|Compara dois parâmetros de entrada e os retorna como um par, em ordem do menor para o maior.|
|[minmax_element](../standard-library/algorithm-functions.md#minmax_element)|Executa o trabalho realizado por [min_element](../standard-library/algorithm-functions.md#min_element) e [max_element](../standard-library/algorithm-functions.md#max_element) em uma chamada.|
|[mismatch](../standard-library/algorithm-functions.md#mismatch)|Compara dois intervalos, elemento por elemento, por igualdade ou equivalência de certo modo especificado por um predicado binário e localiza a primeira posição onde ocorre uma diferença.|
|[&lt;alg&gt; move](../standard-library/algorithm-functions.md#alg_move)|Move elementos associados a um intervalo especificado.|
|[move_backward](../standard-library/algorithm-functions.md#move_backward)|Move os elementos de um iterador para outro. O movimento inicia com o último elemento em um intervalo especificado e termina com o primeiro elemento desse intervalo.|
|[next_permutation](../standard-library/algorithm-functions.md#next_permutation)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.|
|[none_of](../standard-library/algorithm-functions.md#none_of)|Retorna `true` quando uma condição nunca é apresentada entre os elementos no intervalo determinado.|
|[nth_element](../standard-library/algorithm-functions.md#nth_element)|Particiona um intervalo de elementos, localizando corretamente o *n*º elemento da sequência no intervalo para que todos os elementos anteriores sejam menores ou iguais a ele e todos os elementos posteriores na sequência sejam maiores ou iguais a ele.|
|[partial_sort](../standard-library/algorithm-functions.md#partial_sort)|Organiza um número especificado de elementos menores em um intervalo em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|
|[partial_sort_copy](../standard-library/algorithm-functions.md#partial_sort_copy)|Copia elementos de um intervalo de origem em um intervalo de destino, em que os elementos de origem são ordenados por menor que ou outro predicado binário especificado.|
|[partition](../standard-library/algorithm-functions.md#partition)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem.|
|[partition_copy](../standard-library/algorithm-functions.md#partition_copy)|Copia elementos para os quais uma condição é `true` para um destino e para os quais a condição é `false` para outro. Os elementos devem vir de um intervalo especificado.|
|[partition_point](../standard-library/algorithm-functions.md#partition_point)|Retorna o primeiro elemento no intervalo fornecido que não atende à condição. Os elementos são armazenados para que aqueles que atendem à condição venham antes daqueles que não atendem.|
|[pop_heap](../standard-library/algorithm-functions.md#pop_heap)|Remove o maior elemento da frente de um heap para a penúltima posição no intervalo e, em seguida, forma um novo heap com os elementos restantes.|
|[prev_permutation](../standard-library/algorithm-functions.md#prev_permutation)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.|
|[push_heap](../standard-library/algorithm-functions.md#push_heap)|Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.|
|[random_shuffle](../standard-library/algorithm-functions.md#random_shuffle)|Reorganiza uma sequência de *N* elementos em um intervalo em uma de *N*! possíveis organizações selecionadas aleatoriamente.|
|[remove](../standard-library/algorithm-functions.md#remove)|Elimina um valor especificado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.|
|[remove_copy](../standard-library/algorithm-functions.md#remove_copy)|Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.|
|[remove_copy_if](../standard-library/algorithm-functions.md#remove_copy_if)|Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os que atendem a um predicado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.|
|[remove_if](../standard-library/algorithm-functions.md#remove_if)|Elimina elementos que atendem a um predicado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.|
|[replace](../standard-library/algorithm-functions.md#replace)|Examina cada elemento em um intervalo e o substitui se ele corresponder a um valor especificado.|
|[replace_copy](../standard-library/algorithm-functions.md#replace_copy)|Examina cada elemento em um intervalo de origem e o substitui se ele corresponder a um valor especificado ao copiar o resultado em um novo intervalo de destino.|
|[replace_copy_if](../standard-library/algorithm-functions.md#replace_copy_if)|Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.|
|[replace_if](../standard-library/algorithm-functions.md#replace_if)|Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.|
|[reverse](../standard-library/algorithm-functions.md#reverse)|Inverte a ordem dos elementos em um intervalo.|
|[reverse_copy](../standard-library/algorithm-functions.md#reverse_copy)|Inverte a ordem dos elementos em um intervalo de origem ao copiá-los em um intervalo de destino|
|[rotate](../standard-library/algorithm-functions.md#rotate)|Troca os elementos em dois intervalos adjacentes.|
|[rotate_copy](../standard-library/algorithm-functions.md#rotate_copy)|Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.|
|[search](../standard-library/algorithm-functions.md#search)|Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.|
|[search_n](../standard-library/algorithm-functions.md#search_n)|Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.|
|[set_difference](../standard-library/algorithm-functions.md#set_difference)|Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.|
|[set_intersection](../standard-library/algorithm-functions.md#set_intersection)|Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[set_symmetric_difference](../standard-library/algorithm-functions.md#set_symmetric_difference)|Une todos os elementos que pertencem a um (mas não a ambos) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[set_union](../standard-library/algorithm-functions.md#set_union)|Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[sort](../standard-library/algorithm-functions.md#sort)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|
|[shuffle](../standard-library/algorithm-functions.md#shuffle)|Mistura (reorganiza) elementos para um determinado intervalo usando um gerador de números aleatório.|
|[sort_heap](../standard-library/algorithm-functions.md#sort_heap)|Converte um heap em um intervalo classificado.|
|[stable_partition](../standard-library/algorithm-functions.md#stable_partition)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.|
|[stable_sort](../standard-library/algorithm-functions.md#stable_sort)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.|
|[swap](../standard-library/algorithm-functions.md#swap)|Troca os valores dos elementos entre dois tipos de objeto, atribuindo o conteúdo do primeiro objeto ao segundo objeto e o conteúdo do segundo ao primeiro.|
|[swap_ranges](../standard-library/algorithm-functions.md#swap_ranges)|Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.|
|[transform](../standard-library/algorithm-functions.md#transform)|Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.|
|[unique](../standard-library/algorithm-functions.md#unique)|Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.|
|[unique_copy](../standard-library/algorithm-functions.md#unique_copy)|Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.|
|[upper_bound](../standard-library/algorithm-functions.md#upper_bound)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
