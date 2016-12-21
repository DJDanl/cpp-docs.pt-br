---
title: "&lt;algorithm&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<algorithm>"
  - "std::<algorithm>"
  - "algorithm/std::<algorithm>"
  - "std.<algorithm>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho <algorithm>"
  - "Cabeçalho algorithm [C++]"
  - "Biblioteca Padrão C++, algoritmos"
ms.assetid: 19f97711-7a67-4a65-8fd1-9a2bd3ca327d
caps.latest.revision: 23
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;algorithm&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define as funções de modelo de contêiner da STL \(Biblioteca de Modelos Padrão\) que executam algoritmos.  
  
## Sintaxe  
  
```  
(see relevant links below for specific algorithm syntax)  
```  
  
## Comentários  
 Os algoritmos da STL são genéricos, pois eles podem funcionar em várias estruturas de dados.  As estruturas de dados nas quais eles podem operar incluem, além de classes de contêiner da STL, como `vector` e `list`, estruturas de dados definidas pelo programa e matrizes de elementos que atendem aos requisitos de um determinado algoritmo.  Os algoritmos da STL atingem esse nível de generalidade acessando e percorrendo os elementos de um contêiner indiretamente pelos iteradores.  
  
 Os algoritmos da STL processam intervalos de iteradores que geralmente são especificados pelas respectivas posições de início ou fim.  Os intervalos referenciados devem ser válidos no sentido de que todos os ponteiros nos intervalos devem ser desreferenciáveis e, dentro das sequências de cada intervalo, e a última posição deve ser acessível desde a primeira por incrementação.  
  
 Os algoritmos da STL estendem as ações que têm suporte pelas funções membro e operações de cada contêiner da STL e permitem o trabalho, por exemplo, com diferentes tipos de objeto de contêiner ao mesmo tempo.  Dois sufixos foram usados para transportar informações sobre o objetivo dos algoritmos.  
  
-   O sufixo `_if` indica que o algoritmo é usado com objetos de função operando nos valores dos elementos, e não nos valores dos próprios elementos.  O algoritmo `find_if` busca elementos cujos valores atendam ao critério especificado por um objeto de função e o algoritmo `find` busca um valor específico.  
  
-   O sufixo \_copy indica que o algoritmo, além de manipular os valores dos elementos, também copia os valores modificados em um intervalo de destino.  O algoritmo `reverse` inverte a ordem dos elementos dentro de um intervalo e o algoritmo `reverse_copy` também copia o resultado em um intervalo de destino.  
  
 Os algoritmos da STL muitas vezes são classificados em grupos que indicam algo sobre sua finalidade ou seus requisitos.  Eles incluem algoritmos modificadores que alteram o valor de elementos, em comparação com os algoritmos não modificadores.  Os algoritmos mutantes alteram a ordem dos elementos, mas não os valores de seus elementos.  A remoção dos algoritmos pode eliminar elementos de um intervalo ou uma cópia de um intervalo.  Os algoritmos de classificação reordenam de várias formas os elementos em um intervalo e os algoritmos do intervalo classificado atuam somente em algoritmos cujos elementos foram classificados de uma determinada forma.  
  
 Os algoritmos numéricos da STL fornecidos para processamento numérico têm seu próprio arquivo de cabeçalho [\<numeric\>](../standard-library/numeric.md), e os adaptadores e os objetos de função são definidos no cabeçalho [\<functional\>](../standard-library/functional.md). Os objetos de função que retornam valores boolianos são conhecidos como predicados.  O predicado binário padrão é a comparação `operator<`.  De modo geral, os elementos que estão sendo ordenados precisam ser menores que os comparáveis, de modo que, considerando dois elementos, possa ser determinado que, ou eles são equivalentes \(no sentido de que nenhum deles é menor que o outro\), ou que um é menor que o outro.  Isso resulta em uma ordenação entre os elementos não equivalentes.  
  
### Funções  
  
|||  
|-|-|  
|[adjacent\_find](../Topic/adjacent_find.md)|Procura dois elementos adjacentes que sejam iguais ou atendam a uma condição especificada.|  
|[all\_of](../Topic/all_of.md)|Retorna `true` quando uma condição está presente em cada elemento no intervalo determinado.|  
|[any\_of](../Topic/any_of.md)|Retorna `true` quando uma condição está presente, pelo menos, uma vez no intervalo de elementos especificado.|  
|[binary\_search](../Topic/binary_search.md)|Testa se há um elemento em um intervalo classificado que seja igual a um valor especificado ou equivalente a ele de modo especificado por um predicado binário.|  
|[copy](../Topic/copy.md)|Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo\-lhes novas posições em uma direção progressiva.|  
|[copy\_backward](../Topic/copy_backward.md)|Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo\-lhes novas posições em uma direção retroativa.|  
|[copy\_if](../Topic/copy_if.md)|Copia todos os elementos em um determinado intervalo que testam uma condição especificada de `true`.|  
|[copy\_n](../Topic/copy_n.md)|Copia um número especificado de elementos.|  
|[count](../Topic/count.md)|Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.|  
|[count\_if](../Topic/count_if.md)|Retorna o número de elementos em um intervalo cujos valores correspondem a uma condição especificada.|  
|[equal](../Topic/equal.md)|Compara a igualdade ou equivalência de dois intervalos, elemento por elemento, de certo modo especificado por um predicado binário.|  
|[equal\_range](../Topic/equal_range.md)|Localiza um par de posições em um intervalo ordenado, o primeiro menor ou equivalente à posição de um elemento especificado e o segundo maior que a posição do elemento, em que o sentido de equivalência ou de ordenação usada para estabelecer as posições na sequência pode ser especificado por um predicado binário.|  
|[fill](../Topic/fill.md)|Atribui o mesmo novo valor para cada elemento em um intervalo especificado.|  
|[fill\_n](../Topic/fill_n.md)|Atribuir um novo valor a um número especificado de elementos em um intervalo que começa com um elemento específico.|  
|[find](../Topic/find%20\(STL\).md)|Localiza a posição da primeira ocorrência de um elemento em um intervalo que tem um valor especificado.|  
|[find\_end](../Topic/find_end.md)|Examina um intervalo em busca da última subsequência que seja idêntica a uma sequência especificada ou que seja equivalente de certo modo especificado por um predicado binário.|  
|[find\_first\_of](../Topic/find_first_of.md)|Procura a primeira ocorrência de qualquer um dos vários valores em um intervalo de destino ou a primeira ocorrência de qualquer um dos vários elementos que são equivalentes de certo modo especificado por um predicado binário a um conjunto especificado dos elementos.|  
|[find\_if](../Topic/find_if.md)|Localiza a posição da primeira ocorrência de um elemento em um intervalo que atende a uma condição especificada.|  
|[find\_if\_not](../Topic/find_if_not.md)|Retorna o primeiro elemento no intervalo indicado que não atende a uma condição.|  
|[for\_each](../Topic/for_each.md)|Aplica um objeto de função especificado a cada elemento em uma ordem progressiva dentro de um intervalo e retorna o objeto de função.|  
|[generate](../Topic/generate.md)|Atribui os valores gerados por um objeto de função a cada elemento em um intervalo.|  
|[generate\_n](../Topic/generate_n.md)|Atribui os valores gerados por um objeto de função a um número especificado de elementos em um intervalo e retorna para uma posição antes do último valor atribuído.|  
|[includes](../Topic/includes.md)|Testa se um intervalo classificado contém todos os elementos contidos em um segundo intervalo classificado, em que o critério de equivalência ou ordenação entre elementos pode ser especificado por um predicado binário.|  
|[inplace\_merge](../Topic/inplace_merge.md)|Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[is\_heap](../Topic/is_heap.md)|Retornará `true` se os elementos no intervalo especificado formarem um heap.|  
|[is\_heap\_until](../Topic/is_heap_until.md)|Retornará `true` se o intervalo especificado formar um heap até o último elemento.|  
|[is\_partitioned](../Topic/is_partitioned.md)|Retornará `true` se todos os elementos no intervalo determinado que testam `true` para uma condição vierem antes de qualquer elemento que testa `false`.|  
|[is\_permutation](../Topic/is_permutation.md)|Determina se os elementos em determinado intervalo formam uma permutação válida.|  
|[is\_sorted](../Topic/is_sorted.md)|Retornará `true` se os elementos no intervalo especificado estiverem em ordem classificada.|  
|[is\_sorted\_until](../Topic/is_sorted_until.md)|Retornará `true` se os elementos no intervalo especificado estiverem em ordem classificada.|  
|[iter\_swap](../Topic/iter_swap.md)|Troca dois valores referenciados por um par de iteradores especificados.|  
|[lexicographical\_compare](../Topic/lexicographical_compare.md)|Compara elemento por elemento entre duas sequências para determinar qual é o menor dos dois.|  
|[lower\_bound](../Topic/lower_bound.md)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior ou equivalente a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[make\_heap](../Topic/make_heap.md)|Converte os elementos de um intervalo especificado em um heap no qual o primeiro elemento é o maior e para o qual um critério de classificação pode ser especificado com um predicado binário.|  
|[max](../Topic/max.md)|Compara dois objetos e retorna o maior dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[max\_element](../Topic/max_element.md)|Localiza a primeira ocorrência do maior elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[merge](../Topic/merge.md)|Combina todos os elementos de dois intervalos classificados de origem em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[min](../Topic/min.md)|Compara dois objetos e retorna o menor dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[min\_element](../Topic/min_element.md)|Localiza a primeira ocorrência do menor elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[minmax](../Topic/minmax.md)|Compara dois parâmetros de entrada e os retorna como um par, em ordem do menor para o maior.|  
|[minmax\_element](../Topic/minmax_element.md)|Realiza o trabalho executado por [min\_element](../Topic/min_element.md) e por [max\_element](../Topic/max_element.md) em uma chamada.|  
|[mismatch](../Topic/mismatch.md)|Compara dois intervalos, elemento por elemento, por igualdade ou equivalência de certo modo especificado por um predicado binário e localiza a primeira posição onde ocorre uma diferença.|  
|[move](../Topic/%3Calg%3E%20move.md)|Move elementos associados a um intervalo especificado.|  
|[move\_backward](../Topic/move_backward.md)|Move os elementos de um iterador para outro.  O movimento inicia com o último elemento em um intervalo especificado e termina com o primeiro elemento desse intervalo.|  
|[next\_permutation](../Topic/next_permutation.md)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.|  
|[none\_of](../Topic/none_of.md)|Retorna `true` quando uma condição nunca é apresentada entre os elementos no intervalo determinado.|  
|[nth\_element](../Topic/nth_element.md)|Particiona um intervalo de elementos, localizando corretamente o *enésimo* elemento da sequência no intervalo para que todos os elementos que vêm antes dele sejam menores ou iguais a ele e todos os elementos que vêm na sequência sejam maiores ou iguais a ele.|  
|[partial\_sort](../Topic/partial_sort.md)|Organiza um número especificado de elementos menores em um intervalo em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|  
|[partial\_sort\_copy](../Topic/partial_sort_copy.md)|Copia elementos de um intervalo de origem em um intervalo de destino, em que os elementos de origem são ordenados por menor que ou outro predicado binário especificado.|  
|[partition](../Topic/partition.md)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem.|  
|[partition\_copy](../Topic/partition_copy.md)|Copia elementos para os quais uma condição é `true` para um destino e para os quais a condição é `false` para outro.  Os elementos devem vir de um intervalo especificado.|  
|[partition\_point](../Topic/partition_point.md)|Retorna o primeiro elemento no intervalo fornecido que não atende à condição.  Os elementos são armazenados para que aqueles que atendem à condição venham antes daqueles que não atendem.|  
|[pop\_heap](../Topic/pop_heap.md)|Remove o maior elemento da frente de um heap para a penúltima posição no intervalo e, em seguida, forma um novo heap com os elementos restantes.|  
|[prev\_permutation](../Topic/prev_permutation.md)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.|  
|[push\_heap](../Topic/push_heap.md)|Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.|  
|[random\_shuffle](../Topic/random_shuffle.md)|Reorganiza uma sequência de elementos *N* de um intervalo em *N*.  possíveis organizações selecionadas aleatoriamente.|  
|[remove](../Topic/remove.md)|Elimina um valor especificado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.|  
|[remove\_copy](../Topic/remove_copy.md)|Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.|  
|[remove\_copy\_if](../Topic/remove_copy_if.md)|Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os que atendem a um predicado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.|  
|[remove\_if](../Topic/remove_if.md)|Elimina elementos que atendem a um predicado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.|  
|[replace](../Topic/replace.md)|Examina cada elemento em um intervalo e o substitui se ele corresponder a um valor especificado.|  
|[replace\_copy](../Topic/replace_copy.md)|Examina cada elemento em um intervalo de origem e o substitui se ele corresponder a um valor especificado ao copiar o resultado em um novo intervalo de destino.|  
|[replace\_copy\_if](../Topic/replace_copy_if.md)|Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.|  
|[replace\_if](../Topic/replace_if.md)|Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.|  
|[reverse](../Topic/reverse.md)|Inverte a ordem dos elementos em um intervalo.|  
|[reverse\_copy](../Topic/reverse_copy.md)|Inverte a ordem dos elementos em um intervalo de origem ao copiá\-los em um intervalo de destino|  
|[rotate](../Topic/rotate.md)|Troca os elementos em dois intervalos adjacentes.|  
|[rotate\_copy](../Topic/rotate_copy.md)|Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.|  
|[search](../Topic/search.md)|Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.|  
|[search\_n](../Topic/search_n.md)|Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.|  
|[set\_difference](../Topic/set_difference.md)|Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.|  
|[set\_intersection](../Topic/set_intersection.md)|Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[set\_symmetric\_difference](../Topic/set_symmetric_difference.md)|Une todos os elementos que pertencem a um \(mas não a ambos\) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[set\_union](../Topic/set_union.md)|Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[sort](../Topic/sort.md)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|  
|[shuffle](../Topic/std::shuffle.md)|Mistura \(reorganiza\) elementos para um determinado intervalo usando um gerador de números aleatório.|  
|[sort\_heap](../Topic/sort_heap.md)|Converte um heap em um intervalo classificado.|  
|[stable\_partition](../Topic/stable_partition.md)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.|  
|[stable\_sort](../Topic/stable_sort.md)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.|  
|[swap](../Topic/swap.md)|Troca os valores dos elementos entre dois tipos de objeto, atribuindo o conteúdo do primeiro objeto ao segundo objeto e o conteúdo do segundo ao primeiro.|  
|[swap\_ranges](../Topic/swap_ranges.md)|Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.|  
|[transform](../Topic/transform.md)|Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.|  
|[unique](../Topic/unique%20\(%3Calgorithm%3E\).md)|Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.|  
|[unique\_copy](../Topic/unique_copy.md)|Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.|  
|[upper\_bound](../Topic/upper_bound.md)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)