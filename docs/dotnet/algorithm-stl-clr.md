---
title: algorithm (STL/CLR)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- <cliext/algorithm>
- cliext::adjacent_find
- cliext::binary_search
- cliext::copy
- cliext::copy_backward
- cliext::count
- cliext::count_if
- cliext::equal
- cliext::equal_range
- cliext::fill
- cliext::fill_n
- cliext::find
- cliext::find_end
- cliext::find_first_of
- cliext::find_if
- cliext::for_each
- cliext::generate
- cliext::generate_n
- cliext::includes
- cliext::inplace_merge
- cliext::iter_swap
- cliext::lexicographical_compare
- cliext::lower_bound
- cliext::make_heap
- cliext::max
- cliext::max_element
- cliext::merge
- cliext::min
- cliext::min_element
- cliext::mismatch
- cliext::next_permutation
- cliext::nth_element
- cliext::partial_sort
- cliext::partial_sort_copy
- cliext::partition
- cliext::pop_heap
- cliext::prev_permutation
- cliext::push_heap
- cliext::random_shuffle
- cliext::remove
- cliext::remove_copy
- cliext::remove_copy_if
- cliext::remove_if
- cliext::replace
- cliext::replace_copy
- cliext::replace_copy_if
- cliext::replace_if
- cliext::reverse
- cliext::reverse_copy
- cliext::rotate
- cliext::rotate_copy
- cliext::search
- cliext::search_n
- cliext::set_difference
- cliext::set_intersection
- cliext::set_symmetric_difference
- cliext::set_union
- cliext::sort
- cliext::sort_heap
- cliext::stable_partition
- cliext::stable_sort
- cliext::swap
- cliext::swap_ranges
- cliext::transform
- cliext::unique
- cliext::unique_copy
- cliext::upper_bound
helpviewer_keywords:
- algorithm functions [STL/CLR]
- <algorithm> header [STL/CLR]
- <cliext/algorithm> header [STL/CLR]
- adjacent_find function
- binary_search function [STL/CLR]
- copy function [STL/CLR]
- copy_backward function [STL/CLR]
- count function [STL/CLR]
- count_if function [STL/CLR]
- equal function [STL/CLR]
- equal_range function [STL/CLR]
- fill function
- fill_n function
- find function [STL/CLR]
- find_end function [STL/CLR]
- find_first_of function [STL/CLR]
- find_if function [STL/CLR]
- for_each function [STL/CLR]
- generate function [STL/CLR]
- generate_n function [STL/CLR]
- includes function [STL/CLR]
- inplace_merge function [STL/CLR]
- iter_swap function [STL/CLR]
- lexicographical_compare function [STL/CLR]
- lower_bound function [STL/CLR]
- make_heap function [STL/CLR]
- max function [STL/CLR]
- max_element function [STL/CLR]
- merge function [STL/CLR]
- min function [STL/CLR]
- min_element function [STL/CLR]
- mismatch function [STL/CLR]
- next_permutation function [STL/CLR]
- nth_element function [STL/CLR]
- partial_sort function [STL/CLR]
- partial_sort_copy function [STL/CLR]
- partition function [STL/CLR]
- pop_heap function [STL/CLR]
- prev_permutation function [STL/CLR]
- push_heap function [STL/CLR]
- random_shuffle function [STL/CLR]
- remove function [STL/CLR]
- remove_copy function [STL/CLR]
- remove_copy_if function [STL/CLR]
- remove_if function [STL/CLR]
- replace function [STL/CLR]
- replace_copy function [STL/CLR]
- replace_copy_if function [STL/CLR]
- replace_if function [STL/CLR]
- reverse function [STL/CLR]
- reverse_copy function [STL/CLR]
- rotate function [STL/CLR]
- rotate_copy function [STL/CLR]
- search function [STL/CLR]
- search_n function [STL/CLR]
- set_difference function [STL/CLR]
- set_intersection function [STL/CLR]
- set_symmetric_difference function [STL/CLR]
- set_union function [STL/CLR]
- sort function [STL/CLR]
- sort_heap function [STL/CLR]
- stable_partition function [STL/CLR]
- stable_sort function [STL/CLR]
- swap function [STL/CLR]
- swap_ranges function [STL/CLR]
- transform function [STL/CLR]
- unique function [STL/CLR]
- unique_copy function [STL/CLR]
- upper_bound function [STL/CLR]
ms.assetid: ee2718dc-a98d-40b8-8341-593fe7d2ac15
ms.openlocfilehash: 4abd7eaa640bb89fd97c1787bf2fd692610212fb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208945"
---
# <a name="algorithm-stlclr"></a>algorithm (STL/CLR)

Define as funções de modelo de contêiner STL/CLR que executam algoritmos.

## <a name="syntax"></a>Sintaxe

```cpp
#include <cliext/algorithm>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<cliext/algoritmo >

**Namespace:** cliext

## <a name="declarations"></a>{1&gt;{2&gt;Declarações&lt;2}&lt;1}

|Função|DESCRIÇÃO|
|--------------|-----------------|
|[adjacent_find (STL/CLR)](#adjacent_find)|Pesquisa dois elementos adjacentes que são iguais.|
|[binary_search (STL/CLR)](#binary_search)|Testa se uma sequência classificada contém um determinado valor.|
|[copy (STL/CLR)](#copy)|Copia valores de um intervalo de origem para um intervalo de destino, iterando na direção de encaminhamento.|
|[copy_backward (STL/CLR)](#copy_backward)|Copia valores de um intervalo de origem para um intervalo de destino, iterando na direção regressiva.|
|[count (STL/CLR)](#count)|Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.|
|[count_if (STL/CLR)](#count_if)|Retorna o número de elementos em um intervalo cujos valores correspondem a uma condição especificada.|
|[equal (STL/CLR)](#equal)|Compara dois intervalos, elemento por elemento.|
|[equal_range (STL/CLR)](#equal_range)|Pesquisa uma sequência ordenada de valores e retorna duas posições que delimitam uma subsequência de valores que são iguais a um determinado elemento.|
|[fill (STL/CLR)](#fill)|Atribui o mesmo novo valor para cada elemento em um intervalo especificado.|
|[fill_n (STL/CLR)](#fill_n)|Atribui um novo valor a um número especificado de elementos em um intervalo começando com um elemento específico.|
|[find (STL/CLR)](#find)|Retorna a posição da primeira ocorrência de um valor especificado.|
|[find_end (STL/CLR)](#find_end)|Retorna a última subsequência em um intervalo que é idêntico a uma sequência especificada.|
|[find_first_of (STL/CLR)](#find_first_of)|Pesquisa um intervalo para a primeira ocorrência de qualquer um de um determinado intervalo de elementos.|
|[find_if (STL/CLR)](#find_if)|Retorna a posição do primeiro elemento em uma sequência de valores em que o elemento atende a uma condição especificada.|
|[for_each (STL/CLR)](#for_each)|Aplica um objeto de função especificado a cada elemento em uma sequência de valores e retorna o objeto de função.|
|[generate (STL/CLR)](#generate)|Atribui os valores gerados por um objeto de função para cada elemento em uma sequência de valores.|
|[generate_n (STL/CLR)](#generate_n)|Atribui os valores gerados por um objeto de função a um número especificado de elementos.|
|[includes (STL/CLR)](#includes)|Testa se um intervalo classificado contém todos os elementos em um segundo intervalo classificado.|
|[inplace_merge (STL/CLR)](#inplace_merge)|Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado.|
|[iter_swap (STL/CLR)](#iter_swap)|Troca dois valores referenciados por um par de iteradores especificados.|
|[lexicographical_compare (STL/CLR)](#lexicographical_compare)|Compara duas sequências, elemento por elemento, identificando qual sequência é a menor das duas.|
|[lower_bound (STL/CLR)](#lower_bound)|Localiza a posição do primeiro elemento em uma sequência ordenada de valores que tem um valor maior ou igual a um valor especificado.|
|[make_heap (STL/CLR)](#make_heap)|Converte os elementos de um intervalo especificado em um heap em que o primeiro elemento no heap é o maior.|
|[Max (STL/CLR)](#max))|Compara dois objetos e retorna o maior dos dois.|
|[max_element (STL/CLR)](#max_element)|Localiza o maior elemento em uma sequência especificada de valores.|
|[mesclagem (STL/CLR)](#merge))|Combina todos os elementos de dois intervalos de origem classificados em um único intervalo de destino classificado.|
|[min (STL/CLR)](#min)|Compara dois objetos e retorna o menor dos dois.|
|[min_element (STL/CLR)](#min_element)|Localiza o elemento menor em uma sequência especificada de valores.|
|[mismatch (STL/CLR)](#mismatch)|Compara dois elementos Range por elemento e retorna a primeira posição em que ocorre uma diferença.|
|[next_permutation (STL/CLR)](#next_permutation)|Reordena os elementos em um intervalo para que a ordenação original seja substituída pelo modo lexicográfico próxima permutação mais ampla se ela existir.|
|[nth_element (STL/CLR)](#nth_element)|Particiona uma sequência de elementos, localizando corretamente o `n`elemento da sequência para que todos os elementos na frente dele sejam menores ou iguais a ele e todos os elementos que o seguem são maiores ou iguais a ele.|
|[partial_sort (STL/CLR)](#partial_sort)|Organiza um número especificado de elementos menores em um intervalo em ordem não decrescente.|
|[partial_sort_copy (STL/CLR)](#partial_sort_copy)|Copia elementos de um intervalo de origem em um intervalo de destino, de modo que os elementos do intervalo de origem sejam ordenados.|
|[partition (STL/CLR)](#partition)|Organiza os elementos em um intervalo, de modo que os elementos que atendem a um predicado unário precedem aqueles que não atendem a ele.|
|[pop_heap (STL/CLR)](#pop_heap)|Move o maior elemento da frente de um heap para o final e, em seguida, forma um novo heap a partir dos elementos restantes.|
|[prev_permutation (STL/CLR)](#prev_permutation)|Reordena uma sequência de elementos para que a ordenação original seja substituída pela permutação maior modo lexicográfico anterior, caso ela exista.|
|[push_heap (STL/CLR)](#push_heap)|Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.|
|[random_shuffle (STL/CLR)](#random_shuffle)|Reorganiza uma sequência de elementos `N` em um intervalo em um dos `N`! possíveis organizações selecionadas aleatoriamente.|
|[remove (STL/CLR)](#remove)|Exclui um valor especificado de um determinado intervalo sem perturbar a ordem dos elementos restantes e retorna o final de um novo intervalo livre do valor especificado.|
|[remove_copy (STL/CLR)](#remove_copy)|Copia elementos de um intervalo de origem para um intervalo de destino, exceto que os elementos de um valor especificado não são copiados, sem perturbar a ordem dos elementos restantes.|
|[remove_copy_if (STL/CLR)](#remove_copy_if)|Copia elementos de um intervalo de origem para um intervalo de destino, exceto aqueles que atendem a um predicado, sem perturbar a ordem dos elementos restantes.|
|[remove_if (STL/CLR)](#remove_if)|Exclui elementos que atendem a um predicado de um determinado intervalo sem perturbar a ordem dos elementos restantes. .|
|[replace (STL/CLR)](#replace)|Substitui os elementos em um intervalo que correspondem a um valor especificado com um novo valor.|
|[replace_copy (STL/CLR)](#replace_copy)|Copia elementos de um intervalo de origem para um intervalo de destino, substituindo os elementos que correspondem a um valor especificado com um novo valor.|
|[replace_copy_if (STL/CLR)](#replace_copy_if)|Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.|
|[replace_if (STL/CLR)](#replace_if)|Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.|
|[reverse (STL/CLR)](#reverse)|Inverte a ordem dos elementos em um intervalo.|
|[reverse_copy (STL/CLR)](#reverse_copy)|Inverte a ordem dos elementos dentro de um intervalo de origem ao copiá-los para um intervalo de destino.|
|[rotate (STL/CLR)](#rotate)|Troca os elementos em dois intervalos adjacentes.|
|[rotate_copy (STL/CLR)](#rotate_copy)|Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.|
|[search (STL/CLR)](#search_)|Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.|
|[search_n (STL/CLR)](#search_n)|Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.|
|[set_difference (STL/CLR)](#set_difference)|Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.|
|[set_intersection (STL/CLR)](#set_intersection)|Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[set_symmetric_difference (STL/CLR)](#set_symmetric_difference)|Une todos os elementos que pertencem a um (mas não a ambos) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[set_union (STL/CLR)](#set_union))|Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.|
|[sort (STL/CLR)](#sort)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.|
|[sort_heap (STL/CLR)](#sort_heap)|Converte um heap em um intervalo classificado.|
|[stable_partition (STL/CLR)](#stable_partition)|Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.|
|[stable_sort (STL/CLR)](#stable_sort)|Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.|
|[swap (STL/CLR)](#swap)|Troca os valores dos elementos entre dois tipos de objeto, atribuindo o conteúdo do primeiro objeto ao segundo objeto e o conteúdo do segundo ao primeiro.|
|[swap_ranges (STL/CLR)](#swap_ranges)|Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.|
|[transform (STL/CLR)](#transform)|Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.|
|[unique (STL/CLR)](#unique)|Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.|
|[unique_copy (STL/CLR)](#unique_copy)|Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.|
|[upper_bound (STL/CLR)](#upper_bound)|Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.|

## <a name="members"></a>Membros

## <a name="adjacent_find-stlclr"></a><a name="adjacent_find"></a>adjacent_find (STL/CLR)

Procura dois elementos adjacentes que sejam iguais ou atendam a uma condição especificada.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt> inline
    _FwdIt adjacent_find(_FwdIt _First, _FwdIt _Last);
template<class _FwdIt, class _Pr> inline
    _FwdIt adjacent_find(_FwdIt _First, _FwdIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `adjacent_find`. Para obter mais informações, consulte [adjacent_find](../standard-library/algorithm-functions.md#adjacent_find).

## <a name="binary_search-stlclr"></a><a name="binary_search"></a>binary_search (STL/CLR)

Testa se há um elemento em um intervalo classificado que seja igual a um valor especificado ou equivalente a ele de modo especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    bool binary_search(_FwdIt _First, _FwdIt _Last, const _Ty% _Val);
template<class _FwdIt, class _Ty, class _Pr> inline
    bool binary_search(_FwdIt _First, _FwdIt _Last,
        const _Ty% _Val, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `binary_search`. Para obter mais informações, consulte [binary_search](../standard-library/algorithm-functions.md#binary_search).

## <a name="copy-stlclr"></a><a name="copy"></a>cópia (STL/CLR)

Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção progressiva.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt> inline
    _OutIt copy(_InIt _First, _InIt _Last, _OutIt _Dest);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `copy`. Para obter mais informações, consulte [copiar](../standard-library/algorithm-functions.md#copy).

## <a name="copy_backward-stlclr"></a><a name="copy_backward"></a>copy_backward (STL/CLR)

Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção retroativa.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt1, class _BidIt2> inline
    _BidIt2 copy_backward(_BidIt1 _First, _BidIt1 _Last,
        _BidIt2 _Dest);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `copy_backward`. Para obter mais informações, consulte [copy_backward](../standard-library/algorithm-functions.md#copy_backward).

## <a name="count-stlclr"></a><a name="count"></a>contagem (STL/CLR)

Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _Ty> inline
    typename iterator_traits<_InIt>::difference_type
        count(_InIt _First, _InIt _Last, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `count`. Para obter mais informações, consulte [Count](../standard-library/algorithm-functions.md#count).

## <a name="count_if-stlclr"></a><a name="count_if"></a>count_if (STL/CLR)

Retorna o número de elementos em um intervalo cujos valores correspondem a uma condição especificada.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _Pr> inline
    typename iterator_traits<_InIt>::difference_type
        count_if(_InIt _First, _InIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `count_if`. Para obter mais informações, consulte [count_if](../standard-library/algorithm-functions.md#count_if).

## <a name="equal-stlclr"></a><a name="equal"></a>igual (STL/CLR)

Compara a igualdade ou equivalência de dois intervalos, elemento por elemento, de certo modo especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2> inline
    bool equal(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2);
template<class _InIt1, class _InIt2, class _Pr> inline
    bool equal(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2,
        _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `equal`. Para obter mais informações, consulte [igual](../standard-library/algorithm-functions.md#equal).

## <a name="equal_range-stlclr"></a><a name="equal_range"></a>equal_range (STL/CLR)

Localiza um par de posições em um intervalo ordenado, o primeiro menor ou equivalente à posição de um elemento especificado e o segundo maior que a posição do elemento, em que o sentido de equivalência ou de ordenação usada para estabelecer as posições na sequência pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    _PAIR_TYPE(_FwdIt) equal_range(_FwdIt _First, _FwdIt _Last,
        const _Ty% _Val);
template<class _FwdIt, class _Ty, class _Pr> inline
    _PAIR_TYPE(_FwdIt) equal_range(_FwdIt _First, _FwdIt _Last,
        const _Ty% _Val, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `equal_range`. Para obter mais informações, consulte [equal_range](../standard-library/algorithm-functions.md#equal_range).

## <a name="fill-stlclr"></a><a name="fill"></a>preenchimento (STL/CLR)

Atribui o mesmo novo valor para cada elemento em um intervalo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    void fill(_FwdIt _First, _FwdIt _Last, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `fill`. Para obter mais informações, consulte [Fill](../standard-library/algorithm-functions.md#fill).

## <a name="fill_n-stlclr"></a><a name="fill_n"></a>fill_n (STL/CLR)

Atribui um novo valor a um número especificado de elementos em um intervalo começando com um elemento específico.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _OutIt, class _Diff, class _Ty> inline
    void fill_n(_OutIt _First, _Diff _Count, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `fill_n`. Para obter mais informações, consulte [fill_n](../standard-library/algorithm-functions.md#fill_n).

## <a name="find-stlclr"></a><a name="find"></a>Localizar (STL/CLR)

Localiza a posição da primeira ocorrência de um elemento em um intervalo que tem um valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _Ty> inline
    _InIt find(_InIt _First, _InIt _Last, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `find`. Para obter mais informações, consulte [Localizar](../standard-library/algorithm-functions.md#find).

## <a name="find_end-stlclr"></a><a name="find_end"></a>find_end (STL/CLR)

Examina um intervalo em busca da última subsequência que seja idêntica a uma sequência especificada ou que seja equivalente de certo modo especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt1, class _FwdIt2> inline
    _FwdIt1 find_end(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2, _FwdIt2 _Last2);
template<class _FwdIt1, class _FwdIt2, class _Pr> inline
    _FwdIt1 find_end(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `find_end`. Para obter mais informações, consulte [find_end](../standard-library/algorithm-functions.md#find_end).

## <a name="find_first_of-stlclr"></a><a name="find_first_of"></a>find_first_of (STL/CLR)

Procura a primeira ocorrência de qualquer um dos vários valores em um intervalo de destino ou a primeira ocorrência de qualquer um dos vários elementos que são equivalentes de certo modo especificado por um predicado binário a um conjunto especificado dos elementos.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt1, class _FwdIt2> inline
    _FwdIt1 find_first_of(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2, _FwdIt2 _Last2);
template<class _FwdIt1, class _FwdIt2, class _Pr> inline
    _FwdIt1 find_first_of(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `find_first_of`. Para obter mais informações, consulte [find_first_of](../standard-library/algorithm-functions.md#find_first_of).

## <a name="find_if-stlclr"></a><a name="find_if"></a>find_if (STL/CLR)

Localiza a posição da primeira ocorrência de um elemento em um intervalo que atende a uma condição especificada.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _Pr> inline
    _InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `find_if`. Para obter mais informações, consulte [find_if](../standard-library/algorithm-functions.md#find_if).

## <a name="for_each-stlclr"></a><a name="for_each"></a>for_each (STL/CLR)

Aplica um objeto de função especificado a cada elemento em uma ordem progressiva dentro de um intervalo e retorna o objeto de função.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _Fn1> inline
    _Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `for_each`. Para obter mais informações, consulte [for_each](../standard-library/algorithm-functions.md#for_each).

## <a name="generate-stlclr"></a><a name="generate"></a>gerar (STL/CLR)

Atribui os valores gerados por um objeto de função a cada elemento em um intervalo.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Fn0> inline
    void generate(_FwdIt _First, _FwdIt _Last, _Fn0 _Func);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `generate`. Para obter mais informações, consulte [gerar](../standard-library/algorithm-functions.md#generate).

## <a name="generate_n-stlclr"></a><a name="generate_n"></a>generate_n (STL/CLR)

Atribui os valores gerados por um objeto de função a um número especificado de elementos em um intervalo e retorna para uma posição antes do último valor atribuído.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _OutIt, class _Diff, class _Fn0> inline
    void generate_n(_OutIt _Dest, _Diff _Count, _Fn0 _Func);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `generate_n`. Para obter mais informações, consulte [generate_n](../standard-library/algorithm-functions.md#generate_n).

## <a name="includes-stlclr"></a><a name="includes"></a>inclui (STL/CLR)

Testa se um intervalo classificado contém todos os elementos contidos em um segundo intervalo classificado, em que o critério de equivalência ou ordenação entre elementos pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2> inline
    bool includes(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2);
template<class _InIt1, class _InIt2, class _Pr> inline
    bool includes(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `includes`. Para obter mais informações, consulte [inclusões](../standard-library/algorithm-functions.md#includes).

## <a name="inplace_merge-stlclr"></a><a name="inplace_merge"></a>inplace_merge (STL/CLR)

Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt> inline
    void inplace_merge(_BidIt _First, _BidIt _Mid, _BidIt _Last);
template<class _BidIt, class _Pr> inline
    void inplace_merge(_BidIt _First, _BidIt _Mid, _BidIt _Last,
        _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `inplace_merge` para obter mais informações, consulte [inplace_merge](../standard-library/algorithm-functions.md#inplace_merge).

## <a name="iter_swap-stlclr"></a><a name="iter_swap"></a>iter_swap (STL/CLR)

Troca dois valores referenciados por um par de iteradores especificados.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt1, class _FwdIt2> inline
    void iter_swap(_FwdIt1 _Left, _FwdIt2 _Right);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `iter_swap`. Para obter mais informações, consulte [iter_swap](../standard-library/algorithm-functions.md#iter_swap).

## <a name="lexicographical_compare-stlclr"></a><a name="lexicographical_compare"></a>lexicographical_compare (STL/CLR)

Compara elemento por elemento entre duas sequências para determinar qual é o menor dos dois.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2> inline
    bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2);
template<class _InIt1, class _InIt2, class _Pr> inline
    bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `lexicographical_compare`. Para obter mais informações, consulte [lexicographical_compare](../standard-library/algorithm-functions.md#lexicographical_compare).

## <a name="lower_bound-stlclr"></a><a name="lower_bound"></a>lower_bound (STL/CLR)

Localiza a posição do primeiro elemento em um intervalo ordenado que tem um valor menor ou equivalente a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    _FwdIt lower_bound(_FwdIt _First, _FwdIt _Last, const _Ty% _Val);
template<class _FwdIt, class _Ty, class _Pr> inline
    _FwdIt lower_bound(_FwdIt _First, _FwdIt _Last,
        const _Ty% _Val, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `lower_bound`. Para obter mais informações, consulte [lower_bound](../standard-library/algorithm-functions.md#lower_bound).

## <a name="make_heap-stlclr"></a><a name="make_heap"></a>make_heap (STL/CLR)

Converte os elementos de um intervalo especificado em um heap no qual o primeiro elemento é o maior e para o qual um critério de classificação pode ser especificado com um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void make_heap(_RanIt _First, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void make_heap(_RanIt _First, _RanIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `make_heap`. Para obter mais informações, consulte [make_heap](../standard-library/algorithm-functions.md#make_heap).

## <a name="max-stlclr"></a><a name="max"></a>máx. (STL/CLR)

Compara dois objetos e retorna o maior dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _Ty> inline
    const _Ty max(const _Ty% _Left, const _Ty% _Right);
template<class _Ty, class _Pr> inline
    const _Ty max(const _Ty% _Left, const _Ty% _Right, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `max`. Para obter mais informações, consulte [Max](../standard-library/algorithm-functions.md#max).

## <a name="max_element-stlclr"></a><a name="max_element"></a>max_element (STL/CLR)

Localiza a primeira ocorrência do maior elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt> inline
    _FwdIt max_element(_FwdIt _First, _FwdIt _Last);
template<class _FwdIt, class _Pr> inline
    _FwdIt max_element(_FwdIt _First, _FwdIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `max_element`. Para obter mais informações, consulte [max_element](../standard-library/algorithm-functions.md#max_element).

## <a name="merge-stlclr"></a><a name="merge"></a>mesclagem (STL/CLR)

Combina todos os elementos de dois intervalos classificados de origem em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2, class _OutIt> inline
    _OutIt merge(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest);
template<class _InIt1, class _InIt2, class _OutIt, class _Pr> inline
    _OutIt merge(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `merge`. Para obter mais informações, consulte [mesclar](../standard-library/algorithm-functions.md#merge).

## <a name="min-stlclr"></a><a name="min"></a>mín. (STL/CLR)

Compara dois objetos e retorna o menor dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _Ty> inline
    const _Ty min(const _Ty% _Left, const _Ty% _Right);
template<class _Ty, class _Pr> inline
    const _Ty min(const _Ty% _Left, const _Ty% _Right, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `min`. Para obter mais informações, consulte [min](../standard-library/algorithm-functions.md#min).

## <a name="min_element-stlclr"></a><a name="min_element"></a>min_element (STL/CLR)

Localiza a primeira ocorrência do menor elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt> inline
    _FwdIt min_element(_FwdIt _First, _FwdIt _Last);
template<class _FwdIt, class _Pr> inline
    _FwdIt min_element(_FwdIt _First, _FwdIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `min_element`. Para obter mais informações, consulte [min_element](../standard-library/algorithm-functions.md#min_element).

## <a name="mismatch-stlclr"></a><a name="mismatch"></a>incompatibilidade (STL/CLR)

Compara dois intervalos, elemento por elemento, por igualdade ou equivalência de certo modo especificado por um predicado binário e localiza a primeira posição onde ocorre uma diferença.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2> inline
    _PAIR_TYPE(_InIt1)
        mismatch(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2);
template<class _InIt1, class _InIt2, class _Pr> inline
    _PAIR_TYPE(_InIt1)
        mismatch(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2,
            _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `mismatch`. Para obter mais informações, consulte [incompatibilidade](../standard-library/algorithm-functions.md#mismatch).

## <a name="next_permutation-stlclr"></a><a name="next_permutation"></a>next_permutation (STL/CLR)

Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt> inline
    bool next_permutation(_BidIt _First, _BidIt _Last);
template<class _BidIt, class _Pr> inline
    bool next_permutation(_BidIt _First, _BidIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `next_permutation`. Para obter mais informações, consulte [next_permutation](../standard-library/algorithm-functions.md#next_permutation).

## <a name="nth_element-stlclr"></a><a name="nth_element"></a>nth_element (STL/CLR)

Particiona um intervalo de elementos, localizando corretamente o `n`elemento da sequência no intervalo para que todos os elementos na frente dele sejam menores ou iguais a ele e que todos os elementos que o seguem na sequência sejam maiores ou iguais a ele.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void nth_element(_RanIt _First, _RanIt _Nth, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void nth_element(_RanIt _First, _RanIt _Nth, _RanIt _Last,
        _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `nth_element`. Para obter mais informações, consulte [nth_element](../standard-library/algorithm-functions.md#nth_element).

## <a name="partial_sort-stlclr"></a><a name="partial_sort"></a>partial_sort (STL/CLR)

Organiza um número especificado de elementos menores em um intervalo em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void partial_sort(_RanIt _First, _RanIt _Mid, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void partial_sort(_RanIt _First, _RanIt _Mid, _RanIt _Last,
        _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `partial_sort`. Para obter mais informações, consulte [partial_sort](../standard-library/algorithm-functions.md#partial_sort).

## <a name="partial_sort_copy-stlclr"></a><a name="partial_sort_copy"></a>partial_sort_copy (STL/CLR)

Copia elementos de um intervalo de origem em um intervalo de destino, em que os elementos de origem são ordenados por menor que ou outro predicado binário especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _RanIt> inline
    _RanIt partial_sort_copy(_InIt _First1, _InIt _Last1,
        _RanIt _First2, _RanIt _Last2);
template<class _InIt, class _RanIt, class _Pr> inline
    _RanIt partial_sort_copy(_InIt _First1, _InIt _Last1,
        _RanIt _First2, _RanIt _Last2, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `partial_sort_copy`. Para obter mais informações, consulte [partial_sort_copy](../standard-library/algorithm-functions.md#partial_sort_copy).

## <a name="partition-stlclr"></a><a name="partition"></a>partição (STL/CLR)

Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt, class _Pr> inline
    _BidIt partition(_BidIt _First, _BidIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `partition`. Para obter mais informações, consulte [partição](../standard-library/algorithm-functions.md#partition).

## <a name="pop_heap-stlclr"></a><a name="pop_heap"></a>pop_heap (STL/CLR)

Remove o maior elemento da frente de um heap para a penúltima posição no intervalo e, em seguida, forma um novo heap com os elementos restantes.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void pop_heap(_RanIt _First, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void pop_heap(_RanIt _First, _RanIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `pop_heap`. Para obter mais informações, consulte [pop_heap](../standard-library/algorithm-functions.md#pop_heap).

## <a name="prev_permutation-stlclr"></a><a name="prev_permutation"></a>prev_permutation (STL/CLR)

Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt> inline
    bool prev_permutation(_BidIt _First, _BidIt _Last);
template<class _BidIt, class _Pr> inline
    bool prev_permutation(_BidIt _First, _BidIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `prev_permutation`. Para obter mais informações, consulte [prev_permutation](../standard-library/algorithm-functions.md#prev_permutation).

## <a name="push_heap-stlclr"></a><a name="push_heap"></a>push_heap (STL/CLR)

Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void push_heap(_RanIt _First, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void push_heap(_RanIt _First, _RanIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `push_heap`. Para obter mais informações, consulte [push_heap](../standard-library/algorithm-functions.md#push_heap).

## <a name="random_shuffle-stlclr"></a><a name="random_shuffle"></a>random_shuffle (STL/CLR)

Reorganiza uma sequência de elementos `N` em um intervalo em um dos `N`! possíveis organizações selecionadas aleatoriamente.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void random_shuffle(_RanIt _First, _RanIt _Last);
template<class _RanIt, class _Fn1> inline
    void random_shuffle(_RanIt _First, _RanIt _Last, _Fn1% _Func);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `random_shuffle`. Para obter mais informações, consulte [random_shuffle](../standard-library/algorithm-functions.md#random_shuffle).

## <a name="remove-stlclr"></a><a name="remove"></a>remover (STL/CLR)

Elimina um valor especificado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    _FwdIt remove(_FwdIt _First, _FwdIt _Last, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `remove`. Para obter mais informações, consulte [remover](../standard-library/algorithm-functions.md#remove).

## <a name="remove_copy-stlclr"></a><a name="remove_copy"></a>remove_copy (STL/CLR)

Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt, class _Ty> inline
    _OutIt remove_copy(_InIt _First, _InIt _Last,
        _OutIt _Dest, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `remove_copy`. Para obter mais informações, consulte [remove_copy](../standard-library/algorithm-functions.md#remove_copy).

## <a name="remove_copy_if-stlclr"></a><a name="remove_copy_if"></a>remove_copy_if (STL/CLR)

Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os que atendem a um predicado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt, class _Pr> inline
    _OutIt remove_copy_if(_InIt _First, _InIt _Last, _OutIt _Dest,
        _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `remove_copy_if`. Para obter mais informações, consulte [remove_copy_if](../standard-library/algorithm-functions.md#remove_copy_if).

## <a name="remove_if-stlclr"></a><a name="remove_if"></a>remove_if (STL/CLR)

Elimina elementos que atendem a um predicado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Pr> inline
    _FwdIt remove_if(_FwdIt _First, _FwdIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `remove_if`. Para obter mais informações, consulte [remove_if](../standard-library/algorithm-functions.md#remove_if).

## <a name="replace-stlclr"></a><a name="replace"></a>Replace (STL/CLR)

Examina cada elemento em um intervalo e o substitui se ele corresponder a um valor especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    void replace(_FwdIt _First, _FwdIt _Last,
        const _Ty% _Oldval, const _Ty% _Newval);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `replace`. Para obter mais informações, consulte [replace](../standard-library/algorithm-functions.md#replace).

## <a name="replace_copy-stlclr"></a><a name="replace_copy"></a>replace_copy (STL/CLR)

Examina cada elemento em um intervalo de origem e o substitui se ele corresponder a um valor especificado ao copiar o resultado em um novo intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt, class _Ty> inline
    _OutIt replace_copy(_InIt _First, _InIt _Last, _OutIt _Dest,
        const _Ty% _Oldval, const _Ty% _Newval);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `replace_copy`. Para obter mais informações, consulte [replace_copy](../standard-library/algorithm-functions.md#replace_copy).

## <a name="replace_copy_if-stlclr"></a><a name="replace_copy_if"></a>replace_copy_if (STL/CLR)

Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt, class _Pr, class _Ty> inline
    _OutIt replace_copy_if(_InIt _First, _InIt _Last, _OutIt _Dest,
        _Pr _Pred, const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `replace_copy_if`. Para obter mais informações, consulte [replace_copy_if](../standard-library/algorithm-functions.md#replace_copy_if).

## <a name="replace_if-stlclr"></a><a name="replace_if"></a>replace_if (STL/CLR)

Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Pr, class _Ty> inline
    void replace_if(_FwdIt _First, _FwdIt _Last, _Pr _Pred,
        const _Ty% _Val);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `replace_if`. Para obter mais informações, consulte [replace_if](../standard-library/algorithm-functions.md#replace_if).

## <a name="reverse-stlclr"></a><a name="reverse"></a>inversa (STL/CLR)

Inverte a ordem dos elementos em um intervalo.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt> inline
    void reverse(_BidIt _First, _BidIt _Last);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `reverse`. Para obter mais informações, consulte [Reverse](../standard-library/algorithm-functions.md#reverse).

## <a name="reverse_copy-stlclr"></a><a name="reverse_copy"></a>reverse_copy (STL/CLR)

Inverte a ordem dos elementos dentro de um intervalo de origem ao copiá-los para um intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt, class _OutIt> inline
    _OutIt reverse_copy(_BidIt _First, _BidIt _Last, _OutIt _Dest);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `reverse_copy`. Para obter mais informações, consulte [reverse_copy](../standard-library/algorithm-functions.md#reverse_copy).

## <a name="rotate-stlclr"></a><a name="rotate"></a>girar (STL/CLR)

Troca os elementos em dois intervalos adjacentes.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt> inline
    void rotate(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `rotate`. Para obter mais informações, consulte [girar](../standard-library/algorithm-functions.md#rotate).

## <a name="rotate_copy-stlclr"></a><a name="rotate_copy"></a>rotate_copy (STL/CLR)

Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _OutIt> inline
    _OutIt rotate_copy(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last,
        _OutIt _Dest);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `rotate_copy`. Para obter mais informações, consulte [rotate_copy](../standard-library/algorithm-functions.md#rotate_copy).

## <a name="search-stlclr"></a><a name="search_"></a>Pesquisar (STL/CLR)

Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt1, class _FwdIt2> inline
    _FwdIt1 search(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2, _FwdIt2 _Last2);
template<class _FwdIt1, class _FwdIt2, class _Pr> inline
    _FwdIt1 search(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `search`. Para obter mais informações, consulte [Pesquisar](../standard-library/algorithm-functions.md#search).

## <a name="search_n-stlclr"></a><a name="search_n"></a>search_n (STL/CLR)

Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt1, class _Diff2, class _Ty> inline
    _FwdIt1 search_n(_FwdIt1 _First1, _FwdIt1 _Last1,
        _Diff2 _Count, const _Ty& _Val);
template<class _FwdIt1, class _Diff2, class _Ty, class _Pr> inline
    _FwdIt1 search_n(_FwdIt1 _First1, _FwdIt1 _Last1,
        _Diff2 _Count, const _Ty& _Val, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `search_n`. Para obter mais informações, consulte [search_n](../standard-library/algorithm-functions.md#search_n).

## <a name="set_difference-stlclr"></a><a name="set_difference"></a>set_difference (STL/CLR)

Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2, class _OutIt> inline
    _OutIt set_difference(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2,_OutIt _Dest);
template<class _InIt1, class _InIt2, class _OutIt, class _Pr> inline
    _OutIt set_difference(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `set_difference`. Para obter mais informações, consulte [set_difference](../standard-library/algorithm-functions.md#set_difference).

## <a name="set_intersection-stlclr"></a><a name="set_intersection"></a>set_intersection (STL/CLR)

Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2, class _OutIt> inline
    _OutIt set_intersection(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest);
template<class _InIt1, class _InIt2, class _OutIt, class _Pr> inline
    _OutIt set_intersection(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `set_intersection`. Para obter mais informações, consulte [set_intersection](../standard-library/algorithm-functions.md#set_intersection).

## <a name="set_symmetric_difference-stlclr"></a><a name="set_symmetric_difference"></a>set_symmetric_difference (STL/CLR)

Une todos os elementos que pertencem a um (mas não a ambos) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2, class _OutIt> inline
    _OutIt set_symmetric_difference(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest);
template<class _InIt1, class _InIt2, class _OutIt, class _Pr> inline
    _OutIt set_symmetric_difference(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `set_symmetric_difference`. Para obter mais informações, consulte [set_symmetric_difference](../standard-library/algorithm-functions.md#set_symmetric_difference).

## <a name="set_union-stlclr"></a><a name="set_union"></a>set_union (STL/CLR)

Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt1, class _InIt2, class _OutIt> inline
    _OutIt set_union(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest);
template<class _InIt1, class _InIt2, class _OutIt, class _Pr> inline
    _OutIt set_union(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `set_union`. Para obter mais informações, consulte [set_union](../standard-library/algorithm-functions.md#set_union).

## <a name="sort-stlclr"></a><a name="sort"></a>classificar (STL/CLR)

Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void sort(_RanIt _First, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void sort(_RanIt _First, _RanIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `sort`. Para obter mais informações, consulte [classificar](../mfc/reference/cmfclistctrl-class.md#sort).

## <a name="sort_heap-stlclr"></a><a name="sort_heap"></a>sort_heap (STL/CLR)

Converte um heap em um intervalo classificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _RanIt> inline
    void sort_heap(_RanIt _First, _RanIt _Last);
template<class _RanIt, class _Pr> inline
    void sort_heap(_RanIt _First, _RanIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `sort_heap`. Para obter mais informações, consulte [sort_heap](../standard-library/algorithm-functions.md#sort_heap).

## <a name="stable_partition-stlclr"></a><a name="stable_partition"></a>stable_partition (STL/CLR)

Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt, class _Pr> inline
    _BidIt stable_partition(_BidIt _First, _BidIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `stable_partition`. Para obter mais informações, consulte [stable_partition](../standard-library/algorithm-functions.md#stable_partition).

## <a name="stable_sort-stlclr"></a><a name="stable_sort"></a>stable_sort (STL/CLR)

Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _BidIt> inline
    void stable_sort(_BidIt _First, _BidIt _Last);
template<class _BidIt, class _Pr> inline
    void stable_sort(_BidIt _First, _BidIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `stable_sort`. Para obter mais informações, consulte [stable_sort](../standard-library/algorithm-functions.md#stable_sort).

## <a name="swap-stlclr"></a><a name="swap"></a>troca (STL/CLR)

Troca os valores dos elementos entre dois tipos de objeto, atribuindo o conteúdo do primeiro objeto ao segundo objeto e o conteúdo do segundo ao primeiro.

### <a name="syntax"></a>Sintaxe

```cpp
<class _Ty> inline
    void swap(_Ty% _Left, _Ty% _Right);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `swap`. Para obter mais informações, consulte [alternar](../standard-library/algorithm-functions.md#swap).

## <a name="swap_ranges-stlclr"></a><a name="swap_ranges"></a>swap_ranges (STL/CLR)

Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt1, class _FwdIt2> inline
    _FwdIt2 swap_ranges(_FwdIt1 _First1, _FwdIt1 _Last1,
        _FwdIt2 _First2);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `swap_ranges`. Para obter mais informações, consulte [swap_ranges](../standard-library/algorithm-functions.md#swap_ranges).

## <a name="transform-stlclr"></a><a name="transform"></a>transformação (STL/CLR)

Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt, class _Fn1> inline
    _OutIt transform(_InIt _First, _InIt _Last, _OutIt _Dest,
        _Fn1 _Func);
template<class _InIt1, class _InIt2, class _OutIt, class _Fn2> inline
    _OutIt transform(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2,
        _OutIt _Dest, _Fn2 _Func);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `transform`. Para obter mais informações, consulte [transformar](../standard-library/algorithm-functions.md#transform).

## <a name="unique-stlclr"></a><a name="unique"></a>exclusivo (STL/CLR)

Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt> inline
    _FwdIt unique(_FwdIt _First, _FwdIt _Last);
template<class _FwdIt, class _Pr> inline
    _FwdIt unique(_FwdIt _First, _FwdIt _Last, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `unique`. Para obter mais informações, consulte [exclusivo](../standard-library/algorithm-functions.md#unique).

## <a name="unique_copy-stlclr"></a><a name="unique_copy"></a>unique_copy (STL/CLR)

Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _InIt, class _OutIt> inline
    _OutIt unique_copy(_InIt _First, _InIt _Last, _OutIt _Dest);
template<class _InIt, class _OutIt, class _Pr> inline
    _OutIt unique_copy(_InIt _First, _InIt _Last, _OutIt _Dest,
        _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `unique_copy`. Para obter mais informações, consulte [unique_copy](../standard-library/algorithm-functions.md#unique_copy).

## <a name="upper_bound-stlclr"></a><a name="upper_bound"></a>upper_bound (STL/CLR)

Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

### <a name="syntax"></a>Sintaxe

```cpp
template<class _FwdIt, class _Ty> inline
    _FwdIt upper_bound(_FwdIt _First, _FwdIt _Last, const _Ty% _Val);
template<class _FwdIt, class _Ty, class _Pr> inline
    _FwdIt upper_bound(_FwdIt _First, _FwdIt _Last,
        const _Ty% _Val, _Pr _Pred);
```

### <a name="remarks"></a>Comentários

Essa função se comporta da mesma forma que a C++ função de biblioteca padrão `upper_bound`. Para obter mais informações, consulte [upper_bound](../standard-library/algorithm-functions.md#upper_bound).
