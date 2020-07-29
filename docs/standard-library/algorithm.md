---
title: '&lt;algorithm&gt;'
ms.date: 11/04/2016
f1_keywords:
- <algorithm>
helpviewer_keywords:
- algorithm header [C++]
- C++ Standard Library, algorithms
- <algorithm> header
ms.assetid: 19f97711-7a67-4a65-8fd1-9a2bd3ca327d
ms.openlocfilehash: a2a48eec2ed75fffd711a8704cb8c896f8ee7242
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87205529"
---
# <a name="ltalgorithmgt"></a>&lt;algorithm&gt;

Define as funções de modelo do contêiner da Biblioteca Padrão do C++ que executam algoritmos.

## <a name="syntax"></a>Sintaxe

```cpp
(see relevant links below for specific algorithm syntax)
```

> [!NOTE]
> A \<algorithm> biblioteca também usa a `#include <initializer_list>` instrução.

## <a name="remarks"></a>Comentários

Os algoritmos da Biblioteca Padrão do C++ são genéricos, porque eles podem operar em uma variedade de estruturas de dados. As estruturas de dados nas quais eles podem operar incluem, além das classes de contêiner da Biblioteca Padrão do C++, como `vector` e `list`, estruturas de dados definidas pelo programa e matrizes de elementos que atendem aos requisitos de um determinado algoritmo. Os algoritmos da Biblioteca Padrão do C++ atingem esse nível de generalidade acessando e percorrendo os elementos de um contêiner indiretamente por meio de iteradores.

Os algoritmos da Biblioteca Padrão do C++ processam intervalos de iteradores que, geralmente, são especificados pelas sua posições iniciais ou finais. Os intervalos referenciados devem ser válidos no sentido de que todos os ponteiros nos intervalos devem ser desreferenciáveis e, dentro das sequências de cada intervalo, e a última posição deve ser acessível desde a primeira por incrementação.

Os algoritmos da Biblioteca Padrão do C++ ampliam as ações com suporte das operações e funções de membro de cada contêiner da Biblioteca Padrão do C++ e permitem, por exemplo, trabalhar com diferentes tipos de objetos do contêiner ao mesmo tempo. Dois sufixos foram usados para transportar informações sobre o objetivo dos algoritmos.

- O `_if` sufixo indica que o algoritmo é usado com objetos de função operando nos valores dos elementos em vez de nos próprios elementos. O algoritmo `find_if` busca elementos cujos valores atendam ao critério especificado por um objeto de função e o algoritmo `find` busca um valor específico.

- O sufixo _copy indica que o algoritmo, além de manipular os valores dos elementos, também copia os valores modificados em um intervalo de destino. O algoritmo `reverse` inverte a ordem dos elementos dentro de um intervalo e o algoritmo `reverse_copy` também copia o resultado em um intervalo de destino.

Os algoritmos da Biblioteca Padrão do C++ geralmente são classificados em grupos que indicam algo sobre sua finalidade ou seus requisitos. Eles incluem algoritmos modificadores que alteram o valor de elementos, em comparação com os algoritmos não modificadores. Os algoritmos mutantes alteram a ordem dos elementos, mas não os valores de seus elementos. A remoção dos algoritmos pode eliminar elementos de um intervalo ou uma cópia de um intervalo. Os algoritmos de classificação reordenam os elementos em um intervalo de várias maneiras e os algoritmos de intervalo classificados só atuam em intervalos cujos elementos foram classificados de uma maneira específica.

Os algoritmos numéricos de biblioteca padrão C++ que são fornecidos para processamento numérico têm seu próprio arquivo [\<numeric>](numeric.md) de cabeçalho, e os objetos de função e adaptadores são definidos nos objetos de função de cabeçalho [\<functional>](functional.md) que retornam valores Boolianos são conhecidos como predicados. O predicado binário padrão é a comparação `operator<`. De modo geral, os elementos que estão sendo ordenados precisam ser menores que os comparáveis, de modo que, considerando dois elementos, possa ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes.

### <a name="function-templates"></a>Modelos de função

|||
|-|-|
|[adjacent_find](algorithm-functions.md#adjacent_find)|Procura dois elementos adjacentes que sejam iguais ou atendam a uma condição especificada.|
|[all_of](algorithm-functions.md#all_of)|Retorna **`true`** quando uma condição está presente em cada elemento no intervalo especificado.|
|[any_of](algorithm-functions.md#any_of)|Retorna **`true`** quando uma condição está presente pelo menos uma vez no intervalo de elementos especificado.|
|[binary_search](algorithm-functions.md#binary_search)|Testa se há um elemento em um intervalo classificado que seja igual a um valor especificado ou equivalente a ele de modo especificado por um predicado binário.|
|[fixe](algorithm-functions.md#clamp)||
|[copy](algorithm-functions.md#copy)|Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção progressiva.|
|[copy_backward](algorithm-functions.md#copy_backward)|Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção retroativa.|
|[copy_if](algorithm-functions.md#copy_if)|Copiar todos os elementos em um determinado intervalo que são testados **`true`** para uma condição especificada|
|[copy_n](algorithm-functions.md#copy_n)|Copia um número especificado de elementos.|
|[contagem](algorithm-functions.md#count)|Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.|
|[count_if](algorithm-functions.md#count_if)|Retorna o número de elementos em um intervalo cujos valores correspondem a uma condição especificada.|
|[iguais](algorithm-functions.md#equal)|Compara a igualdade ou equivalência de dois intervalos, elemento por elemento, de certo modo especificado por um predicado binário.|
|[equal_range](algorithm-functions.md#equal_range)|Localiza um par de posições em um intervalo ordenado, o primeiro menor ou equivalente à posição de um elemento especificado e o segundo maior que a posição do elemento, em que o sentido de equivalência ou de ordenação usada para estabelecer as posições na sequência pode ser especificado por um predicado binário.|
|[ficar](algorithm-functions.md#fill)|Atribui o mesmo novo valor para cada elemento em um intervalo especificado.|
|[fill_n](algorithm-functions.md#fill_n)|Atribuir um novo valor a um número especificado de elementos em um intervalo que começa com um elemento específico.|
|[find](algorithm-functions.md#find)|Localiza a posição da primeira ocorrência de um elemento em um intervalo que tem um valor especificado.|
|[find_end](algorithm-functions.md#find_end)|Examina um intervalo em busca da última subsequência que seja idêntica a uma sequência especificada ou que seja equivalente de certo modo especificado por um predicado binário.|
|[find_first_of](algorithm-functions.md#find_first_of)|Procura a primeira ocorrência de qualquer um dos vários valores em um intervalo de destino ou a primeira ocorrência de qualquer um dos vários elementos que são equivalentes de certo modo especificado por um predicado binário a um conjunto especificado dos elementos.|
|[find_if](algorithm-functions.md#find_if)|Localiza a posição da primeira ocorrência de um elemento em um intervalo que atende a uma condição especificada.|
|[find_if_not](algorithm-functions.md#find_if_not)|Retorna o primeiro elemento no intervalo indicado que não atende a uma condição.|
|[for_each](algorithm-functions.md#for_each)|Aplica um objeto de função especificado a cada elemento em uma ordem progressiva dentro de um intervalo e retorna o objeto de função.|
|[for_each_n](algorithm-functions.md#for_each_n)||
|[gerou](algorithm-functions.md#generate)|Atribui os valores gerados por um objeto de função a cada elemento em um intervalo.|
|[generate_n](algorithm-functions.md#generate_n)|Atribui os valores gerados por um objeto de função a um número especificado de elementos em um intervalo e retorna para uma posição antes do último valor atribuído.|
|[incluir](algorithm-functions.md#includes)|Testa se um intervalo classificado contém todos os elementos contidos em um segundo intervalo classificado, em que o critério de equivalência ou ordenação entre elementos pode ser especificado por um predicado binário.|
|[inplace_merge](algorithm-functions.md#inplace_merge)|Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[is_heap](algorithm-functions.md#is_heap)|Retorna **`true`** se os elementos no intervalo especificado formam um heap.|
|[is_heap_until](algorithm-functions.md#is_heap_until)|Retorna **`true`** se o intervalo especificado forma um heap até o último elemento.|
|[is_partitioned](algorithm-functions.md#is_partitioned)|Retorna **`true`** se todos os elementos no intervalo especificado que testam **`true`** uma condição vierem antes dos elementos que são testados **`false`** .|
|[is_permutation](algorithm-functions.md#is_permutation)|Determina se os elementos em determinado intervalo formam uma permutação válida.|
|[is_sorted](algorithm-functions.md#is_sorted)|Retorna **`true`** se os elementos no intervalo especificado estão em ordem classificada.|
|[is_sorted_until](algorithm-functions.md#is_sorted_until)|Retorna **`true`** se os elementos no intervalo especificado estão em ordem classificada.|
|[iter_swap](algorithm-functions.md#iter_swap)|Troca dois valores referenciados por um par de iteradores especificados.|
|[lexicographical_compare](algorithm-functions.md#lexicographical_compare)|Compara elemento por elemento entre duas sequências para determinar qual é o menor dos dois.|
|[lower_bound](algorithm-functions.md#lower_bound)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior ou equivalente a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[make_heap](algorithm-functions.md#make_heap)|Converte os elementos de um intervalo especificado em um heap no qual o primeiro elemento é o maior e para o qual um critério de classificação pode ser especificado com um predicado binário.|
|[max](algorithm-functions.md#max)|Compara dois objetos e retorna o maior dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[max_element](algorithm-functions.md#max_element)|Localiza a primeira ocorrência do maior elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[Mescle](algorithm-functions.md#merge)|Combina todos os elementos de dois intervalos classificados de origem em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[min](algorithm-functions.md#min)|Compara dois objetos e retorna o menor dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[min_element](algorithm-functions.md#min_element)|Localiza a primeira ocorrência do menor elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[por minMax](algorithm-functions.md#minmax)|Compara dois parâmetros de entrada e os retorna como um par, em ordem do menor para o maior.|
|[minmax_element](algorithm-functions.md#minmax_element)|Executa o trabalho realizado por [min_element](algorithm-functions.md#min_element) e [max_element](algorithm-functions.md#max_element) em uma chamada.|
|[entre](algorithm-functions.md#mismatch)|Compara dois intervalos, elemento por elemento, por igualdade ou equivalência de certo modo especificado por um predicado binário e localiza a primeira posição onde ocorre uma diferença.|
|[&lt;mover para alg &gt;](algorithm-functions.md#alg_move)|Move elementos associados a um intervalo especificado.|
|[move_backward](algorithm-functions.md#move_backward)|Move os elementos de um iterador para outro. O movimento inicia com o último elemento em um intervalo especificado e termina com o primeiro elemento desse intervalo.|
|[next_permutation](algorithm-functions.md#next_permutation)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.|
|[none_of](algorithm-functions.md#none_of)|Retorna **`true`** quando uma condição nunca está presente entre os elementos no intervalo especificado.|
|[nth_element](algorithm-functions.md#nth_element)|Particiona um intervalo de elementos, localizando corretamente o *n*° elemento da sequência no intervalo para que todos os elementos na frente dele sejam menores ou iguais a ele e que todos os elementos que o seguem na sequência sejam maiores ou iguais a ele.|
|[partial_sort](algorithm-functions.md#partial_sort)|Organiza um número especificado de elementos menores em um intervalo em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|
|[partial_sort_copy](algorithm-functions.md#partial_sort_copy)|Copia elementos de um intervalo de origem em um intervalo de destino, em que os elementos de origem são ordenados por menor que ou outro predicado binário especificado.|
|[particion](algorithm-functions.md#partition)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem.|
|[partition_copy](algorithm-functions.md#partition_copy)|Copia os elementos para os quais uma condição é **`true`** para um destino e para o qual a condição é **`false`** para outra. Os elementos devem vir de um intervalo especificado.|
|[partition_point](algorithm-functions.md#partition_point)|Retorna o primeiro elemento no intervalo fornecido que não atende à condição. Os elementos são armazenados para que aqueles que atendem à condição venham antes daqueles que não atendem.|
|[pop_heap](algorithm-functions.md#pop_heap)|Remove o maior elemento da frente de um heap para a penúltima posição no intervalo e, em seguida, forma um novo heap com os elementos restantes.|
|[prev_permutation](algorithm-functions.md#prev_permutation)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.|
|[push_heap](algorithm-functions.md#push_heap)|Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.|
|[random_shuffle](algorithm-functions.md#random_shuffle)|Reorganiza uma sequência de *N* elementos em um intervalo em uma de *N*! possíveis organizações selecionadas aleatoriamente.|
|[remove](algorithm-functions.md#remove)|Elimina um valor especificado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.|
|[remove_copy](algorithm-functions.md#remove_copy)|Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.|
|[remove_copy_if](algorithm-functions.md#remove_copy_if)|Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os que atendem a um predicado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.|
|[remove_if](algorithm-functions.md#remove_if)|Elimina elementos que atendem a um predicado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.|
|[replace](algorithm-functions.md#replace)|Examina cada elemento em um intervalo e o substitui se ele corresponder a um valor especificado.|
|[replace_copy](algorithm-functions.md#replace_copy)|Examina cada elemento em um intervalo de origem e o substitui se ele corresponder a um valor especificado ao copiar o resultado em um novo intervalo de destino.|
|[replace_copy_if](algorithm-functions.md#replace_copy_if)|Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.|
|[replace_if](algorithm-functions.md#replace_if)|Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.|
|[ordem](algorithm-functions.md#reverse)|Inverte a ordem dos elementos em um intervalo.|
|[reverse_copy](algorithm-functions.md#reverse_copy)|Inverte a ordem dos elementos em um intervalo de origem ao copiá-los em um intervalo de destino|
|[girar](algorithm-functions.md#rotate)|Troca os elementos em dois intervalos adjacentes.|
|[rotate_copy](algorithm-functions.md#rotate_copy)|Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.|
|[Nova](algorithm-functions.md#sample)||
|[search](algorithm-functions.md#search)|Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.|
|[search_n](algorithm-functions.md#search_n)|Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.|
|[set_difference](algorithm-functions.md#set_difference)|Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.|
|[set_intersection](algorithm-functions.md#set_intersection)|Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[set_symmetric_difference](algorithm-functions.md#set_symmetric_difference)|Une todos os elementos que pertencem a um (mas não a ambos) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[set_union](algorithm-functions.md#set_union)|Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[sort](algorithm-functions.md#sort)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|
|[ordem aleatória](algorithm-functions.md#shuffle)|Mistura (reorganiza) elementos para um determinado intervalo usando um gerador de números aleatório.|
|[sort_heap](algorithm-functions.md#sort_heap)|Converte um heap em um intervalo classificado.|
|[stable_partition](algorithm-functions.md#stable_partition)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.|
|[stable_sort](algorithm-functions.md#stable_sort)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.|
|[permuta](algorithm-functions.md#swap)|Troca os valores dos elementos entre dois tipos de objeto, atribuindo o conteúdo do primeiro objeto ao segundo objeto e o conteúdo do segundo ao primeiro.|
|[swap_ranges](algorithm-functions.md#swap_ranges)|Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.|
|[tenha](algorithm-functions.md#transform)|Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.|
|[unique](algorithm-functions.md#unique)|Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.|
|[unique_copy](algorithm-functions.md#unique_copy)|Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.|
|[upper_bound](algorithm-functions.md#upper_bound)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](cpp-standard-library-reference.md)
