---
title: algoritmo (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: <cliext/algorithm>
dev_langs: C++
helpviewer_keywords:
- algorithm functions [STL/CLR]
- <algorithm> header [STL/CLR]
- <cliext/algorithm> header [STL/CLR]
ms.assetid: ee2718dc-a98d-40b8-8341-593fe7d2ac15
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7dac0e574122342c96b28a2f5ccbeb1ea5088ae9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="algorithm-stlclr"></a>algorithm (STL/CLR)
Define as funções de modelo de contêiner STL/CLR que executam algoritmos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <cliext/algorithm>  
```  
  
## <a name="functions"></a>Funções  
  
|Função|Descrição|  
|--------------|-----------------|  
|[adjacent_find (STL/CLR)](../dotnet/adjacent-find-stl-clr.md)|Procura por dois elementos adjacentes que são iguais.|  
|[binary_search (STL/CLR)](../dotnet/binary-search-stl-clr.md)|Testa se uma sequência classificada contém um determinado valor.|  
|[copy (STL/CLR)](../dotnet/copy-stl-clr.md)|Valores de cópias de um intervalo de origem para um intervalo de destino, iteração no sentido de encaminhamento.|  
|[copy_backward (STL/CLR)](../dotnet/copy-backward-stl-clr.md)|Valores de cópias de um intervalo de origem para um intervalo de destino, a iteração na direção com versões anteriores.|  
|[count (STL/CLR)](../dotnet/count-stl-clr.md)|Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.|  
|[count_if (STL/CLR)](../dotnet/count-if-stl-clr.md)|Retorna o número de elementos em um intervalo cujos valores correspondem a uma condição especificada.|  
|[equal (STL/CLR)](../dotnet/equal-stl-clr.md)|Compara dois intervalos, elemento por elemento.|  
|[equal_range (STL/CLR)](../dotnet/equal-range-stl-clr.md)|Pesquisa uma sequência ordenada de valores e retorna duas posições que delimitam uma subsequência de valores que são todos iguais para um determinado elemento.|  
|[fill (STL/CLR)](../dotnet/fill-stl-clr.md)|Atribui o mesmo novo valor para cada elemento em um intervalo especificado.|  
|[fill_n (STL/CLR)](../dotnet/fill-n-stl-clr.md)|Atribui um novo valor a um número especificado de elementos em um intervalo começando com um elemento específico.|  
|[find (STL/CLR)](../dotnet/find-stl-clr.md)|Retorna a posição da primeira ocorrência de um valor especificado.|  
|[find_end (STL/CLR)](../dotnet/find-end-stl-clr.md)|Retorna a último subsequência em um intervalo que é idêntico a uma sequência especificada.|  
|[find_first_of (STL/CLR)](../dotnet/find-first-of-stl-clr.md)|Pesquisa um intervalo para a primeira ocorrência de qualquer um de um determinado intervalo de elementos.|  
|[find_if (STL/CLR)](../dotnet/find-if-stl-clr.md)|Retorna a posição do primeiro elemento em uma sequência de valores, onde o elemento satisfazem uma condição especificada.|  
|[for_each (STL/CLR)](../dotnet/for-each-stl-clr.md)|Aplica-se a um objeto de função especificado para cada elemento em uma sequência de valores e retorna o objeto de função.|  
|[generate (STL/CLR)](../dotnet/generate-stl-clr.md)|Atribui os valores gerados por um objeto de função para cada elemento em uma sequência de valores.|  
|[generate_n (STL/CLR)](../dotnet/generate-n-stl-clr.md)|Atribui os valores gerados por um objeto de função para um número especificado de elementos.|  
|[includes (STL/CLR)](../dotnet/includes-stl-clr.md)|Testa se um intervalo classificado contém todos os elementos em um segundo intervalo classificado.|  
|[inplace_merge (STL/CLR)](../dotnet/inplace-merge-stl-clr.md)|Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado.|  
|[iter_swap (STL/CLR)](../dotnet/iter-swap-stl-clr.md)|Troca dois valores referenciados por um par de iteradores especificados.|  
|[lexicographical_compare (STL/CLR)](../dotnet/lexicographical-compare-stl-clr.md)|Compara duas sequências, ao elemento, identificar quais sequência é o menor dos dois.|  
|[lower_bound (STL/CLR)](../dotnet/lower-bound-stl-clr.md)|Localiza a posição do primeiro elemento em uma sequência ordenada de valores que tem um valor maior que ou igual ao valor especificado.|  
|[make_heap (STL/CLR)](../dotnet/make-heap-stl-clr.md)|Converte os elementos de um intervalo especificado em um heap, em que o primeiro elemento na pilha é o maior.|  
|[max (STL/CLR)](../dotnet/max-stl-clr.md)|Compara dois objetos e retorna o maior dos dois.|  
|[max_element (STL/CLR)](../dotnet/max-element-stl-clr.md)|Localiza o maior elemento em uma sequência especificada de valores.|  
|[merge (STL/CLR)](../dotnet/merge-stl-clr.md)|Combina todos os elementos de dois intervalos de origem classificada em um intervalo de destino único, classificados.|  
|[min (STL/CLR)](../dotnet/min-stl-clr.md)|Compara dois objetos e retorna o menor dos dois.|  
|[min_element (STL/CLR)](../dotnet/min-element-stl-clr.md)|Localiza o menor elemento em uma sequência especificada de valores.|  
|[mismatch (STL/CLR)](../dotnet/mismatch-stl-clr.md)|Compara dois intervalos pelo elemento e retorna a primeira posição em que ocorre uma diferença.|  
|[next_permutation (STL/CLR)](../dotnet/next-permutation-stl-clr.md)|Reorganiza os elementos em um intervalo para que a ordem original é substituída pela próxima lexicograficamente permutação maior se ele existir.|  
|[nth_element (STL/CLR)](../dotnet/nth-element-stl-clr.md)|Partições de uma sequência de elementos, localizando corretamente o `n`elemento th da sequência de forma que todos os elementos na frente dele são menor ou igual a ele e todos os elementos que se seguem são maior ou igual a ele.|  
|[partial_sort (STL/CLR)](../dotnet/partial-sort-stl-clr.md)|Organiza um número especificado de elementos menor em um intervalo em ordem nondescending.|  
|[partial_sort_copy (STL/CLR)](../dotnet/partial-sort-copy-stl-clr.md)|Copia elementos de um intervalo de origem em um intervalo de destino, de modo que os elementos do intervalo de origem são ordenados.|  
|[partition (STL/CLR)](../dotnet/partition-stl-clr.md)|Organiza elementos em um intervalo, de modo que os elementos que satisfazem um predicado unário precedem os que não atendem às exigências.|  
|[pop_heap (STL/CLR)](../dotnet/pop-heap-stl-clr.md)|Move o maior elemento do início de um heap para o fim e, em seguida, um novo heap de elementos restantes de formulários.|  
|[prev_permutation (STL/CLR)](../dotnet/prev-permutation-stl-clr.md)|Reorganiza uma sequência de elementos para que a ordem original é substituída pela permutação maior lexicograficamente anterior se ele existir.|  
|[push_heap (STL/CLR)](../dotnet/push-heap-stl-clr.md)|Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.|  
|[random_shuffle (STL/CLR)](../dotnet/random-shuffle-stl-clr.md)|Reorganiza uma sequência de `N` elementos em um intervalo em um dos `N`! possíveis organizações selecionadas aleatoriamente.|  
|[remove (STL/CLR)](../dotnet/remove-stl-clr.md)|Exclui um valor especificado de um determinado intervalo sem afetar a ordem dos elementos restantes e retorna o fim de um novo intervalo livre do valor especificado.|  
|[remove_copy (STL/CLR)](../dotnet/remove-copy-stl-clr.md)|Copia elementos de um intervalo de origem para um intervalo de destino, exceto que os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes.|  
|[remove_copy_if (STL/CLR)](../dotnet/remove-copy-if-stl-clr.md)|Elementos de cópias de um intervalo de origem para um intervalo de destino, exceto aqueles que satisfazem um predicado, sem afetar a ordem dos elementos restantes.|  
|[remove_if (STL/CLR)](../dotnet/remove-if-stl-clr.md)|Exclui os elementos que satisfazem um predicado de um determinado intervalo sem afetar a ordem dos elementos restantes. .|  
|[replace (STL/CLR)](../dotnet/replace-stl-clr.md)|Substitui os elementos em um intervalo que correspondem a um valor especificado com um novo valor.|  
|[replace_copy (STL/CLR)](../dotnet/replace-copy-stl-clr.md)|Elementos de cópias de um intervalo de origem para um intervalo de destino, substituindo os elementos que correspondem a um valor especificado com um novo valor.|  
|[replace_copy_if (STL/CLR)](../dotnet/replace-copy-if-stl-clr.md)|Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.|  
|[replace_if (STL/CLR)](../dotnet/replace-if-stl-clr.md)|Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.|  
|[reverse (STL/CLR)](../dotnet/reverse-stl-clr.md)|Inverte a ordem dos elementos em um intervalo.|  
|[reverse_copy (STL/CLR)](../dotnet/reverse-copy-stl-clr.md)|Inverte a ordem dos elementos dentro de um intervalo de origem ao copiá-los para um intervalo de destino.|  
|[rotate (STL/CLR)](../dotnet/rotate-stl-clr.md)|Troca os elementos em dois intervalos adjacentes.|  
|[rotate_copy (STL/CLR)](../dotnet/rotate-copy-stl-clr.md)|Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.|  
|[search (STL/CLR)](../dotnet/search-stl-clr.md)|Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.|  
|[search_n (STL/CLR)](../dotnet/search-n-stl-clr.md)|Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.|  
|[set_difference (STL/CLR)](../dotnet/set-difference-stl-clr.md)|Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.|  
|[set_intersection (STL/CLR)](../dotnet/set-intersection-stl-clr.md)|Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[set_symmetric_difference (STL/CLR)](../dotnet/set-symmetric-difference-stl-clr.md)|Une todos os elementos que pertencem a um (mas não a ambos) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[set_union (STL/CLR)](../dotnet/set-union-stl-clr.md)|Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
|[sort (STL/CLR)](../dotnet/sort-stl-clr.md)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|  
|[sort_heap (STL/CLR)](../dotnet/sort-heap-stl-clr.md)|Converte um heap em um intervalo classificado.|  
|[stable_partition (STL/CLR)](../dotnet/stable-partition-stl-clr.md)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.|  
|[stable_sort (STL/CLR)](../dotnet/stable-sort-stl-clr.md)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.|  
|[swap (STL/CLR)](../dotnet/swap-stl-clr.md)|Troca os valores dos elementos entre dois tipos de objeto, atribuindo o conteúdo do primeiro objeto ao segundo objeto e o conteúdo do segundo ao primeiro.|  
|[swap_ranges (STL/CLR)](../dotnet/swap-ranges-stl-clr.md)|Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.|  
|[transform (STL/CLR)](../dotnet/transform-stl-clr.md)|Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.|  
|[unique (STL/CLR)](../dotnet/unique-stl-clr.md)|Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.|  
|[unique_copy (STL/CLR)](../dotnet/unique-copy-stl-clr.md)|Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.|  
|[upper_bound (STL/CLR)](../dotnet/upper-bound-stl-clr.md)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)