---
title: Funções &lt;algorithm&gt;
ms.date: 11/04/2016
f1_keywords:
- algorithm/std::adjacent_find
- algorithm/std::all_of
- algorithm/std::any_of
- algorithm/std::binary_search
- algorithm/std::copy
- algorithm/std::copy_backward
- algorithm/std::copy_if
- algorithm/std::copy_n
- algorithm/std::equal
- algorithm/std::equal_range
- algorithm/std::fill
- algorithm/std::fill_n
- algorithm/std::find
- algorithm/std::find_end
- algorithm/std::find_first_of
- algorithm/std::find_if
- algorithm/std::find_if_not
- algorithm/std::for_each
- algorithm/std::generate
- algorithm/std::generate_n
- algorithm/std::includes
- algorithm/std::inplace_merge
- algorithm/std::is_heap
- algorithm/std::is_heap_until
- algorithm/std::is_partitioned
- algorithm/std::is_permutation
- algorithm/std::is_sorted
- algorithm/std::is_sorted_until
- algorithm/std::iter_swap
- algorithm/std::lexicographical_compare
- algorithm/std::lower_bound
- algorithm/std::make_heap
- algorithm/std::max
- algorithm/std::max_element
- algorithm/std::merge
- algorithm/std::min
- algorithm/std::minmax
- algorithm/std::minmax_element
- algorithm/std::min_element
- algorithm/std::mismatch
- algorithm/std::move
- algorithm/std::move_backward
- algorithm/std::next_permutation
- algorithm/std::none_of
- algorithm/std::nth_element
- algorithm/std::partial_sort
- algorithm/std::partial_sort_copy
- algorithm/std::partition
- algorithm/std::partition_point
- algorithm/std::pop_heap
- algorithm/std::prev_permutation
- algorithm/std::push_heap
- algorithm/std::random_shuffle
- algorithm/std::remove
- algorithm/std::remove_copy
- algorithm/std::remove_copy_if
- algorithm/std::remove_if
- algorithm/std::replace
- algorithm/std::replace_copy
- algorithm/std::replace_copy_if
- algorithm/std::replace_if
- algorithm/std::reverse
- algorithm/std::reverse_copy
- algorithm/std::rotate
- algorithm/std::rotate_copy
- algorithm/std::search
- algorithm/std::search_n
- algorithm/std::set_difference
- algorithm/std::set_intersection
- algorithm/std::set_symmetric_difference
- algorithm/std::set_union
- algorithm/std::shuffle
- algorithm/std::sort
- algorithm/std::sort_heap
- algorithm/std::stable_partition
- algorithm/std::stable_sort
- algorithm/std::swap_ranges
- algorithm/std::transform
- algorithm/std::unique
- algorithm/std::unique_copy
- algorithm/std::upper_bound
- xutility/std::copy
- xutility/std::copy_backward
- xutility/std::copy_n
- xutility/std::count
- xutility/std::equal
- xutility/std::fill
- xutility/std::fill_n
- xutility/std::find
- xutility/std::is_permutation
- xutility/std::lexicographical_compare
- xutility/std::move
- xutility/std::move_backward
- xutility/std::reverse
- xutility/std::rotate
- algorithm/std::count_if
- algorithm/std::partition_copy
- algorithm/std::swap
ms.assetid: c10b0c65-410c-4c83-abf8-8b7f61bba8d0
helpviewer_keywords:
- std::adjacent_find [C++]
- std::all_of [C++]
- std::any_of [C++]
- std::binary_search [C++]
- std::copy [C++]
- std::copy_backward [C++]
- std::copy_if [C++]
- std::copy_n [C++]
- std::equal [C++]
- std::equal_range [C++]
- std::fill [C++]
- std::fill_n [C++]
- std::find [C++]
- std::find_end [C++]
- std::find_first_of [C++]
- std::find_if [C++]
- std::find_if_not [C++]
- std::for_each [C++]
- std::generate [C++]
- std::generate_n [C++]
- std::includes [C++]
- std::inplace_merge [C++]
- std::is_heap [C++]
- std::is_heap_until [C++]
- std::is_partitioned [C++]
- std::is_permutation [C++]
- std::is_sorted [C++]
- std::is_sorted_until [C++]
- std::iter_swap [C++]
- std::lexicographical_compare [C++]
- std::lower_bound [C++]
- std::make_heap [C++]
- std::max [C++]
- std::max_element [C++]
- std::merge [C++]
- std::min [C++]
- std::minmax [C++]
- std::minmax_element [C++]
- std::min_element [C++]
- std::mismatch [C++]
- std::move [C++]
- std::move_backward [C++]
- std::next_permutation [C++]
- std::none_of [C++]
- std::nth_element [C++]
- std::partial_sort [C++]
- std::partial_sort_copy [C++]
- std::partition [C++]
- std::partition_point [C++]
- std::pop_heap [C++]
- std::prev_permutation [C++]
- std::push_heap [C++]
- std::random_shuffle [C++]
- std::remove [C++]
- std::remove_copy [C++]
- std::remove_copy_if [C++]
- std::remove_if [C++]
- std::replace [C++]
- std::replace_copy [C++]
- std::replace_copy_if [C++]
- std::replace_if [C++]
- std::reverse [C++]
- std::reverse_copy [C++]
- std::rotate [C++]
- std::rotate_copy [C++]
- std::search [C++]
- std::search_n [C++]
- std::set_difference [C++]
- std::set_intersection [C++]
- std::set_symmetric_difference [C++]
- std::set_union [C++]
- std::shuffle [C++]
- std::sort [C++]
- std::sort_heap [C++]
- std::stable_partition [C++]
- std::stable_sort [C++]
- std::swap_ranges [C++]
- std::transform [C++]
- std::unique [C++]
- std::unique_copy [C++]
- std::upper_bound [C++]
- std::copy [C++]
- std::copy_backward [C++]
- std::copy_n [C++]
- std::count [C++]
- std::equal [C++]
- std::fill [C++]
- std::fill_n [C++]
- std::find [C++]
- std::is_permutation [C++]
- std::lexicographical_compare [C++]
- std::move [C++]
- std::move_backward [C++]
- std::reverse [C++]
- std::rotate [C++]
- std::count_if [C++]
- std::partition_copy [C++]
- std::swap [C++]
ms.openlocfilehash: c8c550be87eacf81fab994239e07ed2358fad39b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617658"
---
# <a name="ltalgorithmgt-functions"></a>Funções &lt;algorithm&gt;

## <a name="adjacent_find"></a><a name="adjacent_find"></a>adjacent_find

Procura dois elementos adjacentes que sejam iguais ou atendam a uma condição especificada.

```cpp
template<class ForwardIterator>
ForwardIterator adjacent_find(
    ForwardIterator first,
    ForwardIterator last);

template<class ForwardIterator , class BinaryPredicate>
ForwardIterator adjacent_find(
    ForwardIterator first,
    ForwardIterator last,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator>
ForwardIterator adjacent_find(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class BinaryPredicate>
ForwardIterator adjacent_find(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*Pred*\
O predicado binário que fornece a condição a ser atendida pelos valores dos elementos adjacentes no intervalo pesquisado.

### <a name="return-value"></a>Valor retornado

Um iterador de encaminhamento para o primeiro dos elementos adjacentes que são iguais entre si (na primeira versão) ou que atendem à condição fornecida pelo predicado binário (na segunda versão), desde que um par de elementos seja encontrado. Caso contrário, um iterador apontando para o *último* será retornado.

### <a name="remarks"></a>Comentários

O algoritmo `adjacent_find` é um algoritmo de sequência não modificável. O intervalo a ser pesquisado deve ser válido; todos os ponteiros devem ser desreferenciados dentro da sequência e a última posição deve ser acessível desde a primeira, por incrementação. A complexidade de tempo do algoritmo é linear no número de elementos contidos no intervalo.

O `operator==` usado para determinar a correspondência entre os elementos deve impor uma relação de equivalência entre seus operandos.

### <a name="example"></a>Exemplo

```cpp
// alg_adj_fnd.cpp
// compile with: /EHsc
#include <list>
#include <algorithm>
#include <iostream>

// Returns whether second element is twice the first
bool twice (int elem1, int elem2 )
{
    return elem1 * 2 == elem2;
}

int main()
{
    using namespace std;
    list<int> L;
    list<int>::iterator Iter;
    list<int>::iterator result1, result2;

    L.push_back( 50 );
    L.push_back( 40 );
    L.push_back( 10 );
    L.push_back( 20 );
    L.push_back( 20 );

    cout << "L = ( " ;
    for ( Iter = L.begin( ) ; Iter != L.end( ) ; Iter++ )
        cout << *Iter << " ";
    cout << ")" << endl;

    result1 = adjacent_find( L.begin( ), L.end( ) );
    if ( result1 == L.end( ) )
        cout << "There are not two adjacent elements that are equal."
            << endl;
    else
        cout << "There are two adjacent elements that are equal.\n"
            << "They have a value of "
            << *( result1 ) << "." << endl;

    result2 = adjacent_find( L.begin( ), L.end( ), twice );
    if ( result2 == L.end( ) )
        cout << "There are not two adjacent elements where the "
            << "second is twice the first." << endl;
    else
    {
        cout << "There are two adjacent elements where "
            << "the second is twice the first.\n"
            << "They have values of " << *(result2++)
            << " & " << *result2 << "." << endl;
    }
}
```

```Output
L = ( 50 40 10 20 20 )
There are two adjacent elements that are equal.
They have a value of 20.
There are two adjacent elements where the second is twice the first.
They have values of 10 & 20.
```

## <a name="all_of"></a><a name="all_of"></a>all_of

Retorna **true** quando uma condição está presente em cada elemento no intervalo especificado.

```cpp
template<class InputIterator, class UnaryPredicate>
bool all_of(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template <class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
bool all_of(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica onde começar a verificar uma condição. O iterador marca onde um intervalo de elementos começa.

*última*\
Um iterador de entrada que indica o fim do intervalo de elementos para verificar uma condição.

*Pred*\
Uma condição a ser testada. Esse é um objeto de função de predicado definido pelo usuário que define a condição a ser atendida por um elemento que está sendo verificado. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retornará **true** se a condição for detectada em cada elemento no intervalo indicado ou se o intervalo estiver vazio e **false** caso contrário.

### <a name="remarks"></a>Comentários

A função de modelo retornará **true** somente se, para cada `N` no intervalo `[0, last - first)` , o predicado `pred(*(first + N))` for **true**.

### <a name="example"></a>Exemplo

```cpp
// alg_all_of.cpp
// compile with: /EHsc
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;

    list<int> li { 50, 40, 10, 20, 20 };
    list<int>::iterator iter;

    cout << "li = ( ";
    for (iter = li.begin(); iter != li.end(); iter++)
        cout << *iter << " ";
    cout << ")" << endl;

    // Check if all elements in li are even.
    auto is_even = [](int elem){ return !(elem % 2); };
    if (all_of(li.begin(), li.end(), is_even))
        cout << "All the elements are even numbers.\n";
    else
        cout << "Not all the elements are even numbers.\n";
}
```

```Output
li = ( 50 40 10 20 20 )
All the elements are even numbers.
```

## <a name="any_of"></a><a name="any_of"></a>any_of

Retorna **true** quando uma condição está presente pelo menos uma vez no intervalo de elementos especificado.

```cpp
template<class InputIterator, class UnaryPredicate>
bool any_of(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template <class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
bool any_of(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica onde começar a verificar um intervalo de elementos quanto a uma condição.

*última*\
Um iterador de entrada que indica o fim do intervalo de elementos para verificar uma condição.

*Pred*\
Uma condição a ser testada. Ela é fornecida por um objeto de função de predicado definido pelo usuário. O predicado define a condição a ser atendida pelo elemento que está sendo testado. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retornará **true** se a condição for detectada pelo menos uma vez no intervalo indicado, **false** se a condição nunca for detectada.

### <a name="remarks"></a>Comentários

A função de modelo retornará **true** somente se, para alguns `N` no intervalo

`[0, last - first)`, o predicado `pred(*(first + N))` for true.

### <a name="example"></a>Exemplo

```cpp
// alg_any_of.cpp
// compile with: /EHsc
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;

    list<int> li { 51, 41, 11, 21, 20 };

    cout << "li = ( ";
    for (auto const& el : li)
        cout << el << " ";
    cout << ")" << endl;

    // Check if there is an even elememt in li.
    auto is_even = [](int const elem){ return !(elem % 2); };
    if (any_of(li.begin(), li.end(), is_even))
        cout << "There's an even element in li.\n";
    else
        cout << "There are no even elements in li.\n";
}
```

```Output
li = ( 51 41 11 21 20 )
There's an even element in li.
```

## <a name="binary_search"></a><a name="binary_search"></a>binary_search

Testa se há um elemento em um intervalo classificado que seja igual a um valor especificado ou equivalente a ele de modo especificado por um predicado binário.

```cpp
template<class ForwardIterator, class Type>
bool binary_search(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);

template<class ForwardIterator, class Type, class BinaryPredicate>
bool binary_search(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*valor*\
O valor que deve ser correspondido pelo valor do elemento ou que deve atender à condição com o valor do elemento especificado pelo predicado binário.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

**true** se um elemento for encontrado no intervalo que é igual ou equivalente ao valor especificado; caso contrário, **false**.

### <a name="remarks"></a>Comentários

O intervalo de origem classificado referenciado deve ser válido, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Cada intervalo classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo `binary_search` de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

Os intervalos de origem não são modificados por `binary_search`.

Os tipos de valor dos iteradores de avanço precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes

A complexidade do algoritmo é logarítmica para iteradores de acesso aleatório e linear, caso contrário, com o número de etapas proporcionais a ( `last`  -  `first` ).

### <a name="example"></a>Exemplo

```cpp
// alg_bin_srch.cpp
// compile with: /EHsc
#include <list>
#include <vector>
#include <algorithm>
#include <functional>      // greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser( int elem1, int elem2 )
{
    if (elem1 < 0)
        elem1 = - elem1;
    if (elem2 < 0)
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;

    list<int> List1;

    List1.push_back( 50 );
    List1.push_back( 10 );
    List1.push_back( 30 );
    List1.push_back( 20 );
    List1.push_back( 25 );
    List1.push_back( 5 );

    List1.sort();

    cout << "List1 = ( " ;
    for ( auto Iter : List1 )
        cout << Iter << " ";
    cout << ")" << endl;

    // default binary search for 10
    if ( binary_search(List1.begin(), List1.end(), 10) )
        cout << "There is an element in list List1 with a value equal to 10."
        << endl;
    else
        cout << "There is no element in list List1 with a value equal to 10."
        << endl;

    // a binary_search under the binary predicate greater
    List1.sort(greater<int>());
    if ( binary_search(List1.begin(), List1.end(), 10, greater<int>()) )
        cout << "There is an element in list List1 with a value greater than 10 "
        << "under greater than." << endl;
    else
        cout << "No element in list List1 with a value greater than 10 "
        << "under greater than." << endl;

    // a binary_search under the user-defined binary predicate mod_lesser
    vector<int> v1;

    for ( auto i = -2; i <= 4; ++i )
    {
        v1.push_back(i);
    }

    sort(v1.begin(), v1.end(), mod_lesser);

    cout << "Ordered using mod_lesser, vector v1 = ( " ;
    for ( auto Iter : v1 )
        cout << Iter << " ";
    cout << ")" << endl;

    if ( binary_search(v1.begin(), v1.end(), -3, mod_lesser) )
        cout << "There is an element with a value equivalent to -3 "
        << "under mod_lesser." << endl;
    else
        cout << "There is not an element with a value equivalent to -3 "
        << "under mod_lesser." << endl;
}
```

```Output
List1 = ( 5 10 20 25 30 50 )
There is an element in list List1 with a value equal to 10.
There is an element in list List1 with a value greater than 10 under greater than.
Ordered using mod_lesser, vector v1 = ( 0 -1 1 -2 2 3 4 )
There is an element with a value equivalent to -3 under mod_lesser.
```

## <a name="clamp"></a><a name="clamp"></a>fixe

Compara um valor com um limite superior e inferior e retorna uma referência ao valor se estiver entre os limites, ou uma referência para o limite superior ou inferior se o valor estiver acima ou abaixo deles, respectivamente.

```cpp
template<class Type>
constexpr const Type& clamp(
    const Type& value,
    const Type& lower,
    const Type& upper);

template<class Type, class Compare>
constexpr const Type& clamp(
    const Type& value,
    const Type& lower,
    const Type& upper,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor a ser comparado com *maiúsculas* e *minúsculas*.

*canto*\
O limite inferior dos valores para fixe *valor* .

*canto superior*\
O limite superior de valores para fixe *valor* .

*Pred*\
Um predicado usado para comparar *valor* com *inferior* ou *superior*. Um predicado de comparação usa dois argumentos e retorna **true** se o primeiro está em certo sentido menor do que o segundo e, caso contrário, **false**.

### <a name="return-value"></a>Valor retornado

Retorna uma referência para *diminuir* If `value < lower` ou uma referência para *Upper* If `upper < value` . Caso contrário, ele retorna uma referência ao *valor*.

### <a name="remarks"></a>Comentários

O comportamento será indefinido se *Upper* *for menor que menor.*

## <a name="copy"></a><a name="copy"></a>CopiarObjeto

Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção progressiva.

```cpp
template<class InputIterator, class OutputIterator>
OutputIterator copy(
    InputIterator first,
    InputIterator last,
    OutputIterator destBeg);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 copy(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que trata da posição do primeiro elemento no intervalo de origem.

*última*\
Um iterador de entrada que trata da posição que está logo após o elemento final no intervalo de origem.

*destBeg*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda a posição que é um passado do elemento final no intervalo de destino, ou seja, os endereços do iterador `result` + (*último*  -  *primeiro*).

### <a name="remarks"></a>Comentários

O intervalo de origem deve ser válido e deve haver espaço suficiente no destino para conter todos os elementos que estão sendo copiados.

Como o algoritmo copia os elementos de origem na ordem que começa com o primeiro elemento, o intervalo de destino pode se sobrepor ao intervalo de origem, desde que a *última* posição do intervalo de origem não esteja contida no intervalo de destino. `copy`pode ser usado para deslocar elementos para a esquerda, mas não para a direita, a menos que não haja nenhuma sobreposição entre os intervalos de origem e de destino. Para deslocar qualquer número de posições para a direita, use o algoritmo [copy_backward](algorithm-functions.md#copy_backward).

O algoritmo `copy` modifica somente os valores apontados pelos iteradores, atribuindo novos valores a elementos no intervalo de destino. Não pode ser usado para criar novos elementos e não pode inserir os elementos diretamente em um contêiner vazio.

### <a name="example"></a>Exemplo

```cpp
// alg_copy.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
        v1.push_back( 10 * i );

    int ii;
    for ( ii = 0 ; ii <= 10 ; ii++ )
        v2.push_back( 3 * ii );

    cout << "v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")" << endl;

    // To copy the first 3 elements of v1 into the middle of v2
    copy( v1.begin( ), v1.begin( ) + 3, v2.begin( ) + 4 );

    cout << "v2 with v1 insert = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")" << endl;

    // To shift the elements inserted into v2 two positions
    // to the left
    copy( v2.begin( )+4, v2.begin( ) + 7, v2.begin( ) + 2 );

    cout << "v2 with shifted insert = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")" << endl;
}
```

```Output
v1 = ( 0 10 20 30 40 50 )
v2 = ( 0 3 6 9 12 15 18 21 24 27 30 )
v2 with v1 insert = ( 0 3 6 9 0 10 20 21 24 27 30 )
v2 with shifted insert = ( 0 3 0 10 20 10 20 21 24 27 30 )
```

## <a name="copy_backward"></a><a name="copy_backward"></a>copy_backward

Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção retroativa.

```cpp
template<class BidirectionalIterator1, class BidirectionalIterator2>
BidirectionalIterator2 copy_backward(
    BidirectionalIterator1 first,
    BidirectionalIterator1 last,
    BidirectionalIterator2 destEnd);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador bidirecional que trata da posição do primeiro elemento no intervalo de origem.

*última*\
Um iterador bidirecional que trata da posição que está logo atrás do elemento final no intervalo de origem.

*destEnd*\
Um iterador bidirecional que trata da posição que está logo atrás do elemento final no intervalo de destino.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda a posição que é uma passada do elemento final no intervalo de destino, ou seja, o iterador resolve os endereços *destEnd* -(*último*  -  *primeiro*).

### <a name="remarks"></a>Comentários

O intervalo de origem deve ser válido e deve haver espaço suficiente no destino para conter todos os elementos que estão sendo copiados.

O `copy_backward` algoritmo impõe requisitos mais rígidos do que o `copy` algoritmo. Seus iteradores de entrada e de saída devem ser bidirecionais.

Os algoritmos `copy_backward` e [move_backward](algorithm-functions.md#move_backward) são os únicos da Biblioteca Padrão do C++ que designam o intervalo de saída com um iterador apontando para o fim do intervalo de destino.

Como o algoritmo copia os elementos de origem na ordem que começa com o último elemento, o intervalo de destino pode se sobrepor ao intervalo de origem, desde que a *primeira* posição do intervalo de origem não esteja contida no intervalo de destino. `copy_backward` pode ser usado para deslocar elementos à direita mas não à esquerda, a menos que não haja nenhuma sobreposição entre os intervalos de origem e destino. Para deslocar qualquer número de posições para a esquerda, use o algoritmo [copy](algorithm-functions.md#copy).

O algoritmo `copy_backward` modifica somente os valores apontados pelos iteradores, atribuindo novos valores a elementos no intervalo de destino. Não pode ser usado para criar novos elementos e não pode inserir os elementos diretamente em um contêiner vazio.

### <a name="example"></a>Exemplo

```cpp
// alg_copy_bkwd.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 0 ; i <= 5 ; ++i )
        v1.push_back( 10 * i );

    int ii;
    for ( ii = 0 ; ii <= 10 ; ++ii )
        v2.push_back( 3 * ii );

    cout << "v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; ++Iter1 )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; ++Iter2 )
        cout << *Iter2 << " ";
    cout << ")" << endl;

    // To copy_backward the first 3 elements of v1 into the middle of v2
    copy_backward( v1.begin( ), v1.begin( ) + 3, v2.begin( ) + 7 );

    cout << "v2 with v1 insert = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; ++Iter2 )
        cout << *Iter2 << " ";
    cout << ")" << endl;

    // To shift the elements inserted into v2 two positions
    // to the right
    copy_backward( v2.begin( )+4, v2.begin( ) + 7, v2.begin( ) + 9 );

    cout << "v2 with shifted insert = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; ++Iter2 )
        cout << *Iter2 << " ";
    cout << ")" << endl;
}
```

```Output
v1 = ( 0 10 20 30 40 50 )
v2 = ( 0 3 6 9 12 15 18 21 24 27 30 )
v2 with v1 insert = ( 0 3 6 9 0 10 20 21 24 27 30 )
v2 with shifted insert = ( 0 3 6 9 0 10 0 10 20 27 30 )
```

## <a name="copy_if"></a><a name="copy_if"></a>copy_if

Em um intervalo de elementos, o copia os elementos que são **verdadeiros** para a condição especificada.

```cpp
template<class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator copy_if(
    InputIterator first,
    InputIterator last,
    OutputIterator dest,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class UnaryPredicate>
ForwardIterator2 copy_if(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica o início de um intervalo em que a condição deve verificada.

*última*\
Um iterador de entrada que indica o fim do intervalo.

*dest*\
O iterador de saída que indica o destino para os elementos copiados.

*Pred*\
A condição usada para testar cada elemento no intervalo. Essa condição é fornecida por um objeto de função de predicado definido pelo usuário. Um predicado unário usa um argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Um iterador de saída igual a *dest* é incrementado uma vez para cada elemento que atende à condição. Em outras palavras, o valor de retorno menos o *dest* é igual ao número de elementos copiados.

### <a name="remarks"></a>Comentários

A função de modelo avalia

`if (pred(*first + N)) * dest++ = *(first + N))`

uma única vez para cada `N` no intervalo `[0, last - first)`, para aumentar estritamente os valores de `N`, começando com o valor mais baixo. Se *dest* e *primeiro* designar regiões de armazenamento, *dest* não deverá estar no intervalo `[ first, last )` .

### <a name="example"></a>Exemplo

```cpp
// alg_copy_if.cpp
// compile with: /EHsc
#include <list>
#include <algorithm>
#include <iostream>

void listlist(std::list<int> l)
{
    std::cout << "( ";
    for (auto const& el : l)
        std::cout << el << " ";
    std::cout << ")" << std::endl;
}

int main()
{
    using namespace std;
    list<int> li{ 46, 59, 88, 72, 79, 71, 60, 5, 40, 84 };
    list<int> le(li.size()); // le = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    list<int> lo(li.size()); // lo = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    cout << "li = ";
    listlist(li);

    // is_even checks if the element is even.
    auto is_even = [](int const elem) { return !(elem % 2); };
    // use copy_if to select only even elements from li
    // and copy them to le, starting from le's begin position
    auto ec = copy_if(li.begin(),li.end(), le.begin(), is_even);
    le.resize(std::distance(le.begin(), ec));  // shrink le to new size

    cout << "Even numbers are le = ";
    listlist(le);

    // is_odd checks if the element is odd.
    auto is_odd = [](int const elem) { return (elem % 2); };
    // use copy_if to select only odd elements from li
    // and copy them to lo, starting from lo's begin position
    auto oc = copy_if(li.begin(), li.end(), lo.begin(), is_odd);
    lo.resize(std::distance(lo.begin(), oc));  // shrink lo to new size

    cout << "Odd numbers are lo = ";
    listlist(lo);
}
```

```Output
li = ( 46 59 88 72 79 71 60 5 40 84 )
Even numbers are le = ( 46 88 72 60 40 84 )
Odd numbers are lo = ( 59 79 71 5 )
```

## <a name="copy_n"></a><a name="copy_n"></a>copy_n

Copia um número especificado de elementos.

```cpp
template<class InputIterator, class Size, class OutputIterator>
OutputIterator copy_n(
    InputIterator first,
    Size count,
    OutputIterator dest);

template<class ExecutionPolicy, class ForwardIterator1, class Size, class ForwardIterator2>
ForwardIterator2 copy_n(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    Size count,
    ForwardIterator2 dest);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica de onde copiar elementos.

*contar*\
Um tipo de inteiro marcado ou desmarcado que especifica o número de elementos a copiar.

*dest*\
Um iterador de saída que indica onde copiar os elementos.

### <a name="return-value"></a>Valor retornado

Retorna um iterador de saída onde elementos foram copiados. É o mesmo que o valor retornado do parâmetro *dest* .

### <a name="remarks"></a>Comentários

A função de modelo avalia `*(dest + N) = *(first + N))` uma vez para cada `N` no intervalo `[0, count)`, para aumentar estritamente os valores de `N`, começando com o valor mais baixo. Em seguida, ele retorna `dest + N`. Se *dest* e *primeiro* designar regiões de armazenamento, *dest* não deverá estar no intervalo `[first, last)` .

### <a name="example"></a>Exemplo

```cpp
// alg_copy_n.cpp
// compile with: cl /EHsc /W4 alg_copy_n.cpp
#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string s1{"dandelion"};
    string s2{"badger"};

    cout << s1 << " + " << s2 << " = ";

    // Copy the first 3 letters from s1
    // to the first 3 positions in s2
    copy_n(s1.begin(), 3, s2.begin());

    cout << s2 << endl;
}
```

```Output
dandelion + badger = danger
```

## <a name="count"></a><a name="count"></a>contar

Retorna o número de elementos em um intervalo cujos valores correspondem a um valor especificado.

```cpp
template<class InputIterator, class Type>
typename iterator_traits<InputIterator>::difference_type count(
    InputIterator first,
    InputIterator last,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class Type>
typename iterator_traits<ForwardIterator>::difference_type
count(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que trata da posição do primeiro elemento no intervalo a ser percorrido.

*última*\
Um iterador de entrada que trata da posição logo após o elemento final no intervalo a ser percorrido.

*valor*\
O valor dos elementos a serem contados.

### <a name="return-value"></a>Valor retornado

O tipo de diferença do `InputIterator` que conta o número de elementos no intervalo [*primeiro*, *último*) que têm *valor*de valor.

### <a name="remarks"></a>Comentários

O `operator==` usado para determinar a correspondência entre um elemento e o valor especificado deve impor uma relação de equivalência entre os operandos.

Esse algoritmo é generalizado para contar os elementos que atendem a qualquer predicado com a função de modelo [count_if](algorithm-functions.md#count_if).

### <a name="example"></a>Exemplo

```cpp
// alg_count.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(10);

    cout << "v1 = ( " ;
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << *Iter << " ";
    cout << ")" << endl;

    vector<int>::iterator::difference_type result;
    result = count(v1.begin(), v1.end(), 10);
    cout << "The number of 10s in v2 is: " << result << "." << endl;
}
```

```Output
v1 = ( 10 20 10 40 10 )
The number of 10s in v2 is: 3.
```

## <a name="count_if"></a><a name="count_if"></a>count_if

Retorna o número de elementos em um intervalo cujos valores atendem a uma condição especificada.

```cpp
template<class InputIterator, class UnaryPredicate>
typename iterator_traits<InputIterator>::difference_type count_if(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
typename iterator_traits<ForwardIterator>::difference_type
count_if(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de entrada que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define a condição a ser atendida para que um elemento seja contado. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

O número de elementos que atendem à condição especificada pelo predicado.

### <a name="remarks"></a>Comentários

Essa função de modelo é uma generalização do algoritmo [count](algorithm-functions.md#count), substituindo o predicado "igual a um valor específico" por qualquer predicado.

### <a name="example"></a>Exemplo

```cpp
// alg_count_if.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

bool greater10(int value)
{
    return value > 10;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(10);

    cout << "v1 = ( ";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << *Iter << " ";
    cout << ")" << endl;

    vector<int>::iterator::difference_type result1;
    result1 = count_if(v1.begin(), v1.end(), greater10);
    cout << "The number of elements in v1 greater than 10 is: "
         << result1 << "." << endl;
}
```

```Output
v1 = ( 10 20 10 40 10 )
The number of elements in v1 greater than 10 is: 2.
```

## <a name="equal"></a><a name="equal"></a>iguais

Compara dois intervalos, elemento por elemento, quanto à igualdade ou equivalência, em um sentido especificado por um predicado binário.

Use `std::equal` ao comparar elementos de diferentes tipos de contêiner (por exemplo `vector` e `list`) ou ao comparar tipos de elementos diferentes ou quando precisar comparar subintervalos de contêineres. Caso contrário, ao comparar elementos do mesmo tipo no mesmo tipo de contêiner, use o `operator==` não membro que é fornecido para cada contêiner.

Use as sobrecargas de intervalo duplo no código do C++14, porque as sobrecargas que usam apenas um único iterador para o segundo intervalo não detectarão as diferenças se o segundo intervalo for maior que o primeiro intervalo e resultarão em um comportamento indefinido se o segundo intervalo for menor que o primeiro intervalo.

```cpp
template<class InputIterator1, class InputIterator2>
bool equal(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2);

template<class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    BinaryPredicate pred); // C++14

template<class InputIterator1, class InputIterator2>
bool equal(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2);

template<class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
bool equal(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
bool equal(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
bool equal(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
bool equal(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro intervalo a ser testado.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro intervalo a ser testado.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo a ser testado.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo intervalo a ser testado.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

**true** somente se os intervalos forem idênticos ou equivalentes no predicado binário ao comparar elemento por elemento, caso contrário, **false**.

### <a name="remarks"></a>Comentários

O intervalo a ser pesquisado deve ser válido, todos os iteradores devem ser desreferenciáveis e a última posição deve ser acessível desde a primeira por incrementação.

Se os dois intervalos tiverem o mesmo comprimento, a complexidade de tempo do algoritmo será linear no número de elementos contidos no intervalo. Caso contrário, a função retornará **false**imediatamente.

Nem o `operator==` nem o predicado definido pelo usuário é necessário para impor uma relação de equivalência que seja simétrica, reflexiva e transitiva entre seus operandos.

### <a name="example"></a>Exemplo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v1 { 0, 5, 10, 15, 20, 25 };
    vector<int> v2 { 0, 5, 10, 15, 20, 25 };
    vector<int> v3 { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };

    // Using range-and-a-half equal:
    bool b = equal(v1.begin(), v1.end(), v2.begin());
    cout << "v1 and v2 are equal: "
       << b << endl; // true, as expected

    b = equal(v1.begin(), v1.end(), v3.begin());
    cout << "v1 and v3 are equal: "
       << b << endl; // true, surprisingly

    // Using dual-range equal:
    b = equal(v1.begin(), v1.end(), v3.begin(), v3.end());
    cout << "v1 and v3 are equal with dual-range overload: "
       << b << endl; // false

    return 0;
}
```

## <a name="equal_range"></a><a name="equal_range"></a>equal_range

Dado um intervalo ordenado, localiza o subintervalo no qual todos os elementos são equivalentes a um determinado valor.

```cpp
template<class ForwardIterator, class Type>
pair<ForwardIterator, ForwardIterator> equal_range(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);

template<class ForwardIterator, class Type, class Compare>
pair<ForwardIterator, ForwardIterator> equal_range(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*valor*\
O valor que está sendo pesquisado no intervalo ordenado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado de comparação usa dois argumentos e retorna **true** quando satisfeito e **falso** quando não estiver satisfeito.

### <a name="return-value"></a>Valor retornado

Um par de iteradores de encaminhamento que especificam um subintervalo, contido dentro do intervalo pesquisado, no qual todos os elementos são equivalentes ao *valor* no sentido definido pelo predicado binário usado ( *Pred* ou o padrão, menor que).

Se nenhum elemento no intervalo for equivalente ao *valor*, os iteradores posteriores no par retornado serão iguais e especificarão o ponto em que o *valor* poderia ser inserido sem perturbar a ordem do intervalo.

### <a name="remarks"></a>Comentários

O primeiro iterador do par retornado pelo algoritmo é [lower_bound](algorithm-functions.md#lower_bound) e o segundo iterador é [upper_bound](algorithm-functions.md#upper_bound).

O intervalo deve ser classificado de acordo com o predicado fornecido para `equal_range`. Por exemplo, se você pretende usar o predicado “maior que”, o intervalo deve ser classificado em ordem decrescente.

Os elementos no subintervalo possivelmente vazio definidos pelo par de iteradores retornados por `equal_range` serão equivalentes ao *valor* no Sense definido pelo predicado usado.

A complexidade do algoritmo é logarítmica para iteradores de acesso aleatório e linear, caso contrário, com o número de etapas proporcionais ao (*último*  -  *primeiro*).

### <a name="example"></a>Exemplo

```cpp
// alg_equal_range.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // greater<int>()
#include <iostream>
#include <string>
using namespace std;

template<class T> void dump_vector( const vector<T>& v, pair<typename vector<T>::iterator, typename vector<T>::iterator> range )
{
    // prints vector v with range delimited by [ and ]

    for ( typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i )
    {
        if ( i == range.first )
        {
            cout << "[ ";
        }
        if ( i == range.second )
        {
            cout << "] ";
        }

        cout << *i << " ";
    }
    cout << endl;
}

template<class T> void equal_range_demo( const vector<T>& original_vector, T value )
{
    vector<T> v(original_vector);

    sort( v.begin(), v.end() );
    cout << "Vector sorted by the default binary predicate <:" << endl << '\t';
    for ( vector<T>::const_iterator i = v.begin(); i != v.end(); ++i )
    {
        cout << *i << " ";
    }
    cout << endl << endl;

    pair<vector<T>::iterator, vector<T>::iterator> result
        = equal_range( v.begin(), v.end(), value );

    cout << "Result of equal_range with value = " << value << ":" << endl << '\t';
    dump_vector( v, result );
    cout << endl;
}

template<class T, class F> void equal_range_demo( const vector<T>& original_vector, T value, F pred, string predname )
{
    vector<T> v(original_vector);

    sort( v.begin(), v.end(), pred );
    cout << "Vector sorted by the binary predicate " << predname << ":" << endl << '\t';
    for ( typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i )
    {
        cout << *i << " ";
    }
    cout << endl << endl;

    pair<typename vector<T>::iterator, typename vector<T>::iterator> result
        = equal_range( v.begin(), v.end(), value, pred );

    cout << "Result of equal_range with value = " << value << ":" << endl << '\t';
    dump_vector( v, result );
    cout << endl;
}

// Return whether absolute value of elem1 is less than absolute value of elem2
bool abs_lesser( int elem1, int elem2 )
{
    return abs(elem1) < abs(elem2);
}

// Return whether string l is shorter than string r
bool shorter_than(const string& l, const string& r)
{
    return l.size() < r.size();
}

int main()
{
    vector<int> v1;

    // Constructing vector v1 with default less than ordering
    for ( int i = -1; i <= 4; ++i )
    {
        v1.push_back(i);
    }

    for ( int i =-3; i <= 0; ++i )
    {
        v1.push_back( i );
    }

    equal_range_demo( v1, 3 );
    equal_range_demo( v1, 3, greater<int>(), "greater" );
    equal_range_demo( v1, 3, abs_lesser, "abs_lesser" );

    vector<string> v2;

    v2.push_back("cute");
    v2.push_back("fluffy");
    v2.push_back("kittens");
    v2.push_back("fun");
    v2.push_back("meowmeowmeow");
    v2.push_back("blah");

    equal_range_demo<string>( v2, "fred" );
    equal_range_demo<string>( v2, "fred", shorter_than, "shorter_than" );
}
```

## <a name="fill"></a><a name="fill"></a>ficar

Atribui o mesmo novo valor para cada elemento em um intervalo especificado.

```cpp
template<class ForwardIterator, class Type>
void fill(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class Type>
void fill(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento no intervalo a ser percorrido.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final no intervalo a ser percorrido.

*valor*\
O valor a ser atribuído aos elementos no intervalo [*primeiro*, *último*).

### <a name="remarks"></a>Comentários

O intervalo de destino deve ser válido, todos os ponteiros devem ser desreferenciáveis e a última posição deve ser acessível desde a primeira por incrementação. A complexidade é linear com o tamanho do intervalo.

### <a name="example"></a>Exemplo

```cpp
// alg_fill.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
    {
        v1.push_back( 5 * i );
    }

    cout << "Vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // Fill the last 5 positions with a value of 2
    fill( v1.begin( ) + 5, v1.end( ), 2 );

    cout << "Modified v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;
}
```

```Output
Vector v1 = ( 0 5 10 15 20 25 30 35 40 45 )
Modified v1 = ( 0 5 10 15 20 2 2 2 2 2 )
```

## <a name="fill_n"></a><a name="fill_n"></a>fill_n

Atribui um novo valor a um número especificado de elementos em um intervalo começando com um elemento específico.

```cpp
template<class OutputIterator, class Size, class Type>
OutputIterator fill_n(
    OutputIterator first,
    Size count,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class Size, class Type>
ForwardIterator fill_n(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    Size count,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de saída que aborda a posição do primeiro elemento no intervalo a ser atribuído ao *valor*do valor.

*contar*\
Um tipo de inteiro com sinal ou sem sinal que especifica o número de elementos aos quais o valor será atribuído.

*valor*\
O valor a ser atribuído aos elementos no intervalo [*primeiro*, *primeiro + contagem*).

### <a name="return-value"></a>Valor retornado

Um iterador para o elemento que segue o último elemento preenchido se a *contagem* > zero, caso contrário o primeiro elemento.

### <a name="remarks"></a>Comentários

O intervalo de destino deve ser válido, todos os ponteiros devem ser desreferenciáveis e a última posição deve ser acessível desde a primeira por incrementação. A complexidade é linear com o tamanho do intervalo.

### <a name="example"></a>Exemplo

```cpp
// alg_fill_n.cpp
// compile using /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v;

    for ( auto i = 0 ; i < 9 ; ++i )
        v.push_back( 0 );

    cout << " vector v = ( " ;
    for ( const auto &w : v )
        cout << w << " ";
    cout << ")" << endl;

    // Fill the first 3 positions with a value of 1, saving position.
    auto pos = fill_n( v.begin(), 3, 1 );

    cout << "modified v = ( " ;
    for ( const auto &w : v )
        cout << w << " ";
    cout << ")" << endl;

    // Fill the next 3 positions with a value of 2, using last position.
    fill_n( pos, 3, 2 );

    cout << "modified v = ( " ;
    for ( const auto &w : v )
        cout << w << " ";
    cout << ")" << endl;

    // Fill the last 3 positions with a value of 3, using relative math.
    fill_n( v.end()-3, 3, 3 );

    cout << "modified v = ( " ;
    for ( const auto &w : v )
        cout << w << " ";
    cout << ")" << endl;
}
```

## <a name="find"></a><a name="find"></a>considerar

Localiza a posição da primeira ocorrência de um elemento em um intervalo que tem um valor especificado.

```cpp
template<class InputIterator, class Type>
InputIterator find(
    InputIterator first,
    InputIterator last,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class Type>
ForwardIterator find(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que aborda a posição do primeiro elemento do intervalo a ser pesquisado quanto ao valor especificado.

*última*\
Um iterador de entrada que aborda a posição um após o elemento final do intervalo a ser pesquisado quanto ao valor especificado.

*valor*\
O valor a ser procurado.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que aborda a primeira ocorrência do valor especificado no intervalo pesquisado. Se nenhum elemento for encontrado com um valor equivalente, retornará *Last*.

### <a name="remarks"></a>Comentários

O `operator==` usado para determinar a correspondência entre um elemento e o valor especificado deve impor uma relação de equivalência entre os operandos.

Para obter um exemplo de código usando `find()`, consulte [find_if](algorithm-functions.md#find_if).

## <a name="find_end"></a><a name="find_end"></a>find_end

Examina um intervalo em busca da última subsequência que seja idêntica a uma sequência especificada ou que seja equivalente de certo modo especificado por um predicado binário.

```cpp
template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ForwardIterator1, class ForwardIterator2, class Pred>
ForwardIterator1 find_end(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    Pred pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator1
find_end(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1,
class ForwardIterator2, class BinaryPredicate>
ForwardIterator1
find_end(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*first1*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*last1*\
Um iterador de avanço que trata da posição logo após o último elemento no intervalo a ser pesquisado.

*first2*\
Um iterador de avanço que trata da posição do primeiro elemento no intervalo a ser pesquisado.

*last2*\
Um iterador de avanço que trata da posição logo após o último elemento no intervalo a ser pesquisado.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador posterior que aborda a posição do primeiro elemento da última subsequência dentro de [first1, last1) que corresponde à sequência especificada [first2, last2).

### <a name="remarks"></a>Comentários

O `operator==` usado para determinar a correspondência entre um elemento e o valor especificado deve impor uma relação de equivalência entre os operandos.

Os intervalos referenciados devem ser válidos; todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível desde a primeira, por incrementação.

### <a name="example"></a>Exemplo

```cpp
// alg_find_end.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// Return whether second element is twice the first
bool twice ( int elem1, int elem2 )
{
    return 2 * elem1 == elem2;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    list<int> L1;
    vector<int>::iterator Iter1, Iter2;
    list<int>::iterator L1_Iter, L1_inIter;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }

    int ii;
    for ( ii = 1 ; ii <= 4 ; ii++ )
    {
        L1.push_back( 5 * ii );
    }

    int iii;
    for ( iii = 2 ; iii <= 4 ; iii++ )
    {
        v2.push_back( 10 * iii );
    }

    cout << "Vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "List L1 = ( " ;
    for ( L1_Iter = L1.begin( ) ; L1_Iter!= L1.end( ) ; L1_Iter++ )
        cout << *L1_Iter << " ";
    cout << ")" << endl;

    cout << "Vector v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
        cout << ")" << endl;

    // Searching v1 for a match to L1 under identity
    vector<int>::iterator result1;
    result1 = find_end ( v1.begin( ), v1.end( ), L1.begin( ), L1.end( ) );

    if ( result1 == v1.end( ) )
        cout << "There is no match of L1 in v1."
            << endl;
    else
        cout << "There is a match of L1 in v1 that begins at "
            << "position "<< result1 - v1.begin( ) << "." << endl;

    // Searching v1 for a match to L1 under the binary predicate twice
    vector<int>::iterator result2;
    result2 = find_end ( v1.begin( ), v1.end( ), v2.begin( ), v2.end( ), twice );

    if ( result2 == v1.end( ) )
        cout << "There is no match of L1 in v1."
            << endl;
    else
        cout << "There is a sequence of elements in v1 that "
            << "are equivalent to those\n in v2 under the binary "
            << "predicate twice and that begins at position "
            << result2 - v1.begin( ) << "." << endl;
}
```

```Output
Vector v1 = ( 0 5 10 15 20 25 0 5 10 15 20 25 )
List L1 = ( 5 10 15 20 )
Vector v2 = ( 20 30 40 )
There is a match of L1 in v1 that begins at position 7.
There is a sequence of elements in v1 that are equivalent to those
in v2 under the binary predicate twice and that begins at position 8.
```

## <a name="find_first_of"></a><a name="find_first_of"></a>find_first_of

Procura a primeira ocorrência de qualquer um dos vários valores em um intervalo de destino ou a primeira ocorrência de qualquer um dos vários elementos que são equivalentes de certo modo especificado por um predicado binário a um conjunto especificado dos elementos.

```cpp
template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_first_of(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 find_first_of(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator1
find_first_of(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1,
class ForwardIterator2, class BinaryPredicate>
ForwardIterator1
find_first_of(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*first1*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*last1*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*first2*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser correspondido.

*last2*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser correspondido.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que aborda a posição do primeiro elemento da primeira subsequência que corresponda à sequência especificada ou que seja equivalente em um sentido especificado por um predicado binário.

### <a name="remarks"></a>Comentários

O `operator==` usado para determinar a correspondência entre um elemento e o valor especificado deve impor uma relação de equivalência entre os operandos.

Os intervalos referenciados devem ser válidos; todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível desde a primeira, por incrementação.

### <a name="example"></a>Exemplo

```cpp
// alg_find_first_of.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// Return whether second element is twice the first
bool twice ( int elem1, int elem2 )
{
    return 2 * elem1 == elem2;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    list<int> L1;
    vector<int>::iterator Iter1, Iter2;
    list<int>::iterator L1_Iter, L1_inIter;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }

    int ii;
    for ( ii = 3 ; ii <= 4 ; ii++ )
    {
        L1.push_back( 5 * ii );
    }

    int iii;
    for ( iii = 2 ; iii <= 4 ; iii++ )
    {
        v2.push_back( 10 * iii );
    }

    cout << "Vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "List L1 = ( " ;
    for ( L1_Iter = L1.begin( ) ; L1_Iter!= L1.end( ) ; L1_Iter++ )
        cout << *L1_Iter << " ";
    cout << ")" << endl;

    cout << "Vector v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
        cout << ")" << endl;

    // Searching v1 for first match to L1 under identity
    vector<int>::iterator result1;
    result1 = find_first_of ( v1.begin( ), v1.end( ), L1.begin( ), L1.end( ) );

    if ( result1 == v1.end( ) )
        cout << "There is no match of L1 in v1."
            << endl;
    else
        cout << "There is at least one match of L1 in v1"
            << "\n and the first one begins at "
            << "position "<< result1 - v1.begin( ) << "." << endl;

    // Searching v1 for a match to L1 under the binary predicate twice
    vector<int>::iterator result2;
    result2 = find_first_of ( v1.begin( ), v1.end( ), v2.begin( ), v2.end( ), twice );

    if ( result2 == v1.end( ) )
        cout << "There is no match of L1 in v1."
            << endl;
    else
        cout << "There is a sequence of elements in v1 that "
            << "are equivalent\n to those in v2 under the binary "
            << "predicate twice\n and the first one begins at position "
            << result2 - v1.begin( ) << "." << endl;
}
```

```Output
Vector v1 = ( 0 5 10 15 20 25 0 5 10 15 20 25 )
List L1 = ( 15 20 )
Vector v2 = ( 20 30 40 )
There is at least one match of L1 in v1
and the first one begins at position 3.
There is a sequence of elements in v1 that are equivalent
to those in v2 under the binary predicate twice
and the first one begins at position 2.
```

## <a name="find_if"></a><a name="find_if"></a>find_if

Localiza a posição da primeira ocorrência de um elemento em um intervalo que atende a uma condição especificada.

```cpp
template<class InputIterator, class UnaryPredicate>
InputIterator find_if(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
ForwardIterator find_if(
    ExecutionPolicy&& exec,
    ForwardIterator first, ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de entrada que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de entrada que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*Pred*\
O objeto de função de predicado definido pelo usuário ou a [expressão lambda](../cpp/lambda-expressions-in-cpp.md) que define a condição a ser atendida pelo elemento que está sendo pesquisado. Um predicado unário usa um único argumento e retorna **true** se for satisfeito ou **false** se não for satisfeito. A assinatura de *Pred* deve ser efetivamente `bool pred(const T& arg);` , em que `T` é um tipo no qual `InputIterator` pode ser convertido implicitamente quando não referenciado. A palavra-chave **const** é mostrada apenas para ilustrar que o objeto Function ou lambda não deve modificar o argumento.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que se refere ao primeiro elemento no intervalo que satisfaz a condição especificada pelo predicado (o predicado resulta em **true**). Se nenhum elemento for encontrado para atender ao predicado, retornará *Last*.

### <a name="remarks"></a>Comentários

Essa função de modelo é uma generalização do algoritmo [find](algorithm-functions.md#find), que substitui o predicado "igual a um valor específico" por qualquer predicado. Para obter a lógica oposta (localizar o primeiro elemento que não atende ao predicado), consulte [find_if_not](algorithm-functions.md#find_if_not).

### <a name="example"></a>Exemplo

```cpp
// cl.exe /W4 /nologo /EHsc /MTd
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename S> void print(const S& s) {
for (const auto& p : s) {
        cout << "(" << p << ") ";
    }
    cout << endl;
}

// Test std::find()
template <class InputIterator, class T>
void find_print_result(InputIterator first, InputIterator last, const T& value) {

    // call <algorithm> std::find()
    auto p = find(first, last, value);

    cout << "value " << value;
    if (p == last) {
        cout << " not found." << endl;
    } else {
        cout << " found." << endl;
    }
}

// Test std::find_if()
template <class InputIterator, class Predicate>
void find_if_print_result(InputIterator first, InputIterator last,
    Predicate Pred, const string& Str) {

    // call <algorithm> std::find_if()
    auto p = find_if(first, last, Pred);

    if (p == last) {
        cout << Str << " not found." << endl;
    } else {
        cout << "first " << Str << " found: " << *p << endl;
    }
}

// Function to use as the UnaryPredicate argument to find_if() in this example
bool is_odd_int(int i) {
    return ((i % 2) != 0);
}

int main()
{
    // Test using a plain old array.
    const int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "array x[] contents: ";
    print(x);
    // Using non-member std::begin()/std::end() to get input iterators for the plain old array.
    cout << "Test std::find() with array..." << endl;
    find_print_result(begin(x), end(x), 10);
    find_print_result(begin(x), end(x), 42);
    cout << "Test std::find_if() with array..." << endl;
    find_if_print_result(begin(x), end(x), is_odd_int, "odd integer"); // function name
    find_if_print_result(begin(x), end(x), // lambda
        [](int i){ return ((i % 2) == 0); }, "even integer");

    // Test using a vector.
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back((i + 1) * 10);
    }
    cout << endl << "vector v contents: ";
    print(v);
    cout << "Test std::find() with vector..." << endl;
    find_print_result(v.begin(), v.end(), 20);
    find_print_result(v.begin(), v.end(), 12);
    cout << "Test std::find_if() with vector..." << endl;
    find_if_print_result(v.begin(), v.end(), is_odd_int, "odd integer");
    find_if_print_result(v.begin(), v.end(), // lambda
        [](int i){ return ((i % 2) == 0); }, "even integer");
}
```

## <a name="find_if_not"></a><a name="find_if_not"></a>find_if_not

Retorna o primeiro elemento no intervalo indicado que não atende a uma condição.

```cpp
template<class InputIterator, class UnaryPredicate>
InputIterator find_if_not(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
ForwardIterator find_if_not(
    ExecutionPolicy&& exec,
    ForwardIterator first, ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de entrada que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de entrada que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*Pred*\
O objeto de função de predicado definido pelo usuário ou a [expressão lambda](../cpp/lambda-expressions-in-cpp.md) que define a condição que não deve ser atendida pelo elemento que está sendo pesquisado. Um predicado unário usa um único argumento e retorna **true** se for satisfeito ou **false** se não for satisfeito. A assinatura de *Pred* deve ser efetivamente `bool pred(const T& arg);` , em que `T` é um tipo no qual `InputIterator` pode ser convertido implicitamente quando não referenciado. A palavra-chave **const** é mostrada apenas para ilustrar que o objeto Function ou lambda não deve modificar o argumento.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que se refere ao primeiro elemento no intervalo que não satisfaz a condição especificada pelo predicado (o predicado resulta em **false**). Se todos os elementos atenderem ao predicado (o predicado resulta em **true** para todos os elementos), retornará *Last*.

### <a name="remarks"></a>Comentários

Essa função de modelo é uma generalização do algoritmo [find](algorithm-functions.md#find), que substitui o predicado "igual a um valor específico" por qualquer predicado. Para a lógica oposta (localizar o primeiro elemento que atenda ao predicado), consulte [find_if](algorithm-functions.md#find_if).

Para obter um exemplo de código que se adapta imediatamente a `find_if_not()`, consulte [find_if](algorithm-functions.md#find_if).

## <a name="for_each"></a><a name="for_each"></a>for_each

Aplica um objeto de função especificado a cada elemento em uma ordem progressiva dentro de um intervalo e retorna o objeto de função.

```cpp
template<class InputIterator, class Function>
Function for_each(
    InputIterator first,
    InputIterator last,
    Function func);

template<class ExecutionPolicy, class ForwardIterator, class Function>
void for_each(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Function func);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de entrada que trata da posição do primeiro elemento no intervalo no qual a operação ocorrerá.

*última*\
Um iterador de entrada que trata da posição logo após o elemento final no intervalo no qual a operação ocorre.

*Func*\
Objeto de função definido pelo usuário que é aplicado a cada elemento no intervalo.

### <a name="return-value"></a>Valor retornado

Uma cópia do objeto de função depois que ele foi aplicado a todos os elementos no intervalo.

### <a name="remarks"></a>Comentários

O algoritmo `for_each` é muito flexível, permitindo a modificação de cada elemento dentro de um intervalo, de diferentes maneiras, especificadas pelo usuário. As funções de modelos podem ser reutilizadas em um formulário modificado passando parâmetros diferentes. As funções definidas pelo usuário podem acumular informações em um estado interno que o algoritmo pode retornar após o processamento de todos os elementos no intervalo.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A complexidade é linear com no máximo (a*última*  -  *primeira*) comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_for_each.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

// The function object multiplies an element by a Factor
template <class Type>
class MultValue
{
private:
    Type Factor;   // The value to multiply by
public:
    // Constructor initializes the value to multiply by
    MultValue ( const Type& value ) : Factor ( value ) {
    }

    // The function call for the element to be multiplied
    void operator( ) ( Type& elem ) const
    {
        elem *= Factor;
    }
};

// The function object to determine the average
class Average
{
private:
    long num;      // The number of elements
    long sum;      // The sum of the elements
public:
    // Constructor initializes the value to multiply by
    Average( ) : num ( 0 ) , sum ( 0 )
    {
    }

    // The function call to process the next elment
    void operator( ) ( int elem )
    {
        num++;      // Increment the element count
        sum += elem;   // Add the value to the partial sum
    }

    // return Average
    operator double( )
    {
        return static_cast<double> (sum) /
            static_cast<double> (num);
    }
};

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    // Constructing vector v1
    int i;
    for ( i = -4 ; i <= 2 ; i++ )
    {
        v1.push_back( i );
    }

    cout << "Original vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Using for_each to multiply each element by a Factor
    for_each ( v1.begin( ), v1.end( ), MultValue<int> ( -2 ) );

    cout << "Multiplying the elements of the vector v1\n "
            << "by the factor -2 gives:\n v1mod1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // The function object is templatized and so can be
    // used again on the elements with a different Factor
    for_each (v1.begin( ), v1.end( ), MultValue<int> (5 ) );

    cout << "Multiplying the elements of the vector v1mod\n "
            << "by the factor 5 gives:\n v1mod2 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // The local state of a function object can accumulate
    // information about a sequence of actions that the
    // return value can make available, here the Average
    double avemod2 = for_each ( v1.begin( ), v1.end( ),
        Average( ) );
    cout << "The average of the elements of v1 is:\n Average ( v1mod2 ) = "
            << avemod2 << "." << endl;
}
```

```Output
Original vector v1 = ( -4 -3 -2 -1 0 1 2 ).
Multiplying the elements of the vector v1
by the factor -2 gives:
v1mod1 = ( 8 6 4 2 0 -2 -4 ).
Multiplying the elements of the vector v1mod
by the factor 5 gives:
v1mod2 = ( 40 30 20 10 0 -10 -20 ).
The average of the elements of v1 is:
Average ( v1mod2 ) = 10.
```

## <a name="for_each_n"></a><a name="for_each_n"></a>for_each_n

```cpp
template<class InputIterator, class Size, class Function>
InputIterator for_each_n(
    InputIterator first,
    Size n,
    Function f);

template<class ExecutionPolicy, class ForwardIterator, class Size, class Function>
ForwardIterator for_each_n(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    Size n,
    Function f);
```

## <a name="generate"></a><a name="generate"></a>gerou

Atribui os valores gerados por um objeto de função a cada elemento em um intervalo.

```cpp
template<class ForwardIterator, class Generator>
void generate(
    ForwardIterator first,
    ForwardIterator last,
    Generator gen);

template<class ExecutionPolicy, class ForwardIterator, class Generator>
void generate(
    ExecutionPolicy&& exec,
    ForwardIterator first, ForwardIterator last,
    Generator gen);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento no intervalo ao qual os valores devem ser atribuídos.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final no intervalo ao qual os valores devem ser atribuídos.

*geral*\
Um objeto de função que é chamado sem argumentos e usado para gerar os valores a serem atribuídos a cada um dos elementos no intervalo.

### <a name="remarks"></a>Comentários

O objeto de função é invocado para cada elemento no intervalo e não precisa retornar o mesmo valor toda vez que é chamado. Ele pode, por exemplo, ler de um arquivo ou consultar e modificar um estado local. Deve ser possível converter o tipo de resultado do gerador para o tipo de valor dos iteradores de encaminhamento do intervalo.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A complexidade é linear, com chamadas exatamente ( `last`  -  `first` ) para o gerador que está sendo necessário.

### <a name="example"></a>Exemplo

```cpp
// alg_generate.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>

int main()
{
    using namespace std;

    // Assigning random values to vector integer elements
    vector<int> v1 ( 5 );
    vector<int>::iterator Iter1;
    deque<int> deq1 ( 5 );
    deque<int>::iterator d1_Iter;

    generate ( v1.begin( ), v1.end( ), rand );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Assigning random values to deque integer elements
    generate ( deq1.begin( ), deq1.end( ), rand );

    cout << "Deque deq1 is ( " ;
    for ( d1_Iter = deq1.begin( ) ; d1_Iter != deq1.end( ) ; d1_Iter++ )
        cout << *d1_Iter << " ";
    cout << ")." << endl;
}
```

```Output
Vector v1 is ( 41 18467 6334 26500 19169 ).
Deque deq1 is ( 15724 11478 29358 26962 24464 ).
```

## <a name="generate_n"></a><a name="generate_n"></a>generate_n

Atribui os valores gerados por um objeto de função a um número especificado de elementos em um intervalo e retorna para uma posição antes do último valor atribuído.

```cpp
template<class OutputIterator, class Diff, class Generator>
void generate_n(
    OutputIterator first,
    Diff count,
    Generator gen);

template<class ExecutionPolicy, class ForwardIterator, class Size, class Generator>
ForwardIterator generate_n(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    Size count,
    Generator gen);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo ao qual os valores são atribuídos.

*contar*\
Um tipo de inteiro com sinal e sem sinal que especifica o número de elementos a terem um valor atribuído pela função do gerador.

*geral*\
Um objeto de função que é chamado sem argumentos e usado para gerar os valores a serem atribuídos a cada um dos elementos no intervalo.

### <a name="remarks"></a>Comentários

O objeto de função é invocado para cada elemento no intervalo e não precisa retornar o mesmo valor toda vez que é chamado. Ele pode, por exemplo, ler de um arquivo ou consultar e modificar um estado local. Deve ser possível converter o tipo de resultado do gerador para o tipo de valor dos iteradores de encaminhamento do intervalo.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A complexidade é linear, com exatamente `count` chamadas para o gerador solicitado.

### <a name="example"></a>Exemplo

```cpp
// cl.exe /EHsc /nologo /W4 /MTd
#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

template <typename C>
void print(const string& s, const C& c)
{
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

int main()
{
    const int elemcount = 5;
    vector<int> v(elemcount);
    deque<int> dq(elemcount);

    // Set up random number distribution
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> dist(-9, 9);

    // Call generate_n, using a lambda for the third parameter
    generate_n(v.begin(), elemcount, [&](){ return dist(engine); });
    print("vector v is: ", v);

    generate_n(dq.begin(), elemcount, [&](){ return dist(engine); });
    print("deque dq is: ", dq);
}
```

## <a name="includes"></a><a name="includes"></a>incluir

Testa se um intervalo classificado contém todos os elementos contidos em um segundo intervalo classificado, em que o critério de equivalência ou ordenação entre elementos pode ser especificado por um predicado binário.

```cpp
template<class InputIterator1, class InputIterator2>
bool includes(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2);

template<class InputIterator1, class InputIterator2, class Compare>
bool includes(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
bool includes(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Compare>
bool includes(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro entre dois intervalos de origem classificados a serem testados para verificar se todos os elementos do segundo estão contidos no primeiro.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro entre dois intervalos de origem classificados a serem testados para verificar se todos os elementos do segundo estão contidos no primeiro.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo entre dois intervalos de origem classificados consecutivos a serem testados para verificar se todos os elementos do segundo estão contidos no primeiro.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo entre dois intervalos de origem classificados consecutivos a serem testados para verificar se todos os elementos do segundo estão contidos no primeiro.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado de comparação usa dois argumentos e retorna **true** quando satisfeito e **falso** quando não estiver satisfeito.

### <a name="return-value"></a>Valor retornado

**true** se o primeiro intervalo classificado contiver todos os elementos no segundo intervalo classificado, caso contrário, **false**.

### <a name="remarks"></a>Comentários

Outra maneira de pensar esse teste é que ele determinou se o segundo intervalo de origem é um subconjunto do primeiro intervalo de origem.

Os intervalos de origem classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível desde a primeira por incrementação.

Cada intervalo de origem classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo includes, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

Os intervalos de origem não são modificados pelo algoritmo `merge` .

Os tipos de valor dos iteradores de entrada precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Mais precisamente, o algoritmo testa se todos os elementos no primeiro intervalo classificado em um predicado binário especificado têm ordenação equivalente aos que estão no segundo intervalo classificado.

A complexidade do algoritmo é linear com no máximo `2 * ((last1 - first1) - (last2 - first2)) - 1` comparações para intervalos de origem não vazios.

### <a name="example"></a>Exemplo

```cpp
// alg_includes.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser (int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1a, v1b;
    vector<int>::iterator Iter1a, Iter1b;

    // Constructing vectors v1a & v1b with default less-than ordering
    int i;
    for ( i = -2 ; i <= 4 ; i++ )
    {
        v1a.push_back( i );
    }

    int ii;
    for ( ii =-2 ; ii <= 3 ; ii++ )
    {
        v1b.push_back( ii );
    }

    cout << "Original vector v1a with range sorted by the\n "
            << "binary predicate less than is v1a = ( " ;
    for ( Iter1a = v1a.begin( ) ; Iter1a != v1a.end( ) ; Iter1a++ )
        cout << *Iter1a << " ";
    cout << ")." << endl;

    cout << "Original vector v1b with range sorted by the\n "
            << "binary predicate less than is v1b = ( " ;
    for ( Iter1b = v1b.begin( ) ; Iter1b != v1b.end( ) ; Iter1b++ )
        cout << *Iter1b << " ";
    cout << ")." << endl;

    // Constructing vectors v2a & v2b with ranges sorted by greater
    vector<int> v2a ( v1a ) , v2b ( v1b );
    vector<int>::iterator Iter2a, Iter2b;
    sort ( v2a.begin( ), v2a.end( ), greater<int>( ) );
    sort ( v2b.begin( ), v2b.end( ), greater<int>( ) );
    v2a.pop_back( );

    cout << "Original vector v2a with range sorted by the\n "
            << "binary predicate greater is v2a = ( " ;
    for ( Iter2a = v2a.begin( ) ; Iter2a != v2a.end( ) ; Iter2a++ )
        cout << *Iter2a << " ";
    cout << ")." << endl;

    cout << "Original vector v2b with range sorted by the\n "
            << "binary predicate greater is v2b = ( " ;
    for ( Iter2b = v2b.begin( ) ; Iter2b != v2b.end( ) ; Iter2b++ )
        cout << *Iter2b << " ";
    cout << ")." << endl;

    // Constructing vectors v3a & v3b with ranges sorted by mod_lesser
    vector<int> v3a ( v1a ), v3b ( v1b ) ;
    vector<int>::iterator Iter3a, Iter3b;
    reverse (v3a.begin( ), v3a.end( ) );
    v3a.pop_back( );
    v3a.pop_back( );
    sort ( v3a.begin( ), v3a.end( ), mod_lesser );
    sort ( v3b.begin( ), v3b.end( ), mod_lesser );

    cout << "Original vector v3a with range sorted by the\n "
            << "binary predicate mod_lesser is v3a = ( " ;
    for ( Iter3a = v3a.begin( ) ; Iter3a != v3a.end( ) ; Iter3a++ )
        cout << *Iter3a << " ";
    cout << ")." << endl;

    cout << "Original vector v3b with range sorted by the\n "
            << "binary predicate mod_lesser is v3b = ( " ;
    for ( Iter3b = v3b.begin( ) ; Iter3b != v3b.end( ) ; Iter3b++ )
        cout << *Iter3b << " ";
    cout << ")." << endl;

    // To test for inclusion under an asscending order
    // with the default binary predicate less<int>( )
    bool Result1;
    Result1 = includes ( v1a.begin( ), v1a.end( ),
        v1b.begin( ), v1b.end( ) );
    if ( Result1 )
        cout << "All the elements in vector v1b are "
            << "contained in vector v1a." << endl;
    else
        cout << "At least one of the elements in vector v1b "
            << "is not contained in vector v1a." << endl;

    // To test for inclusion under descending
    // order specify binary predicate greater<int>( )
    bool Result2;
    Result2 = includes ( v2a.begin( ), v2a.end( ),
        v2b.begin( ), v2b.end( ), greater<int>( ) );
    if ( Result2 )
        cout << "All the elements in vector v2b are "
            << "contained in vector v2a." << endl;
    else
        cout << "At least one of the elements in vector v2b "
            << "is not contained in vector v2a." << endl;

    // To test for inclusion under a user
    // defined binary predicate mod_lesser
    bool Result3;
    Result3 = includes ( v3a.begin( ), v3a.end( ),
        v3b.begin( ), v3b.end( ), mod_lesser );
    if ( Result3 )
        cout << "All the elements in vector v3b are "
            << "contained under mod_lesser in vector v3a."
            << endl;
    else
        cout << "At least one of the elements in vector v3b is "
            << " not contained under mod_lesser in vector v3a."
            << endl;
}
```

```Output
Original vector v1a with range sorted by the
binary predicate less than is v1a = ( -2 -1 0 1 2 3 4 ).
Original vector v1b with range sorted by the
binary predicate less than is v1b = ( -2 -1 0 1 2 3 ).
Original vector v2a with range sorted by the
binary predicate greater is v2a = ( 4 3 2 1 0 -1 ).
Original vector v2b with range sorted by the
binary predicate greater is v2b = ( 3 2 1 0 -1 -2 ).
Original vector v3a with range sorted by the
binary predicate mod_lesser is v3a = ( 0 1 2 3 4 ).
Original vector v3b with range sorted by the
binary predicate mod_lesser is v3b = ( 0 -1 1 -2 2 3 ).
All the elements in vector v1b are contained in vector v1a.
At least one of the elements in vector v2b is not contained in vector v2a.
At least one of the elements in vector v3b is not contained under mod_lesser in vector v3a.
```

## <a name="inplace_merge"></a><a name="inplace_merge"></a>inplace_merge

Combina os elementos de dois intervalos classificados consecutivos em um único intervalo classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class BidirectionalIterator>
void inplace_merge(
    BidirectionalIterator first,
    BidirectionalIterator middle,
    BidirectionalIterator last);

template<class BidirectionalIterator, class Compare>
void inplace_merge(
    BidirectionalIterator first,
    BidirectionalIterator middle,
    BidirectionalIterator last,
    Compare pred);

template<class ExecutionPolicy, class BidirectionalIterator>
void inplace_merge(
    ExecutionPolicy&& exec,
    BidirectionalIterator first,
    BidirectionalIterator middle,
    BidirectionalIterator last);

template<class ExecutionPolicy, class BidirectionalIterator, class Compare>
void inplace_merge(
    ExecutionPolicy&& exec,
    BidirectionalIterator first,
    BidirectionalIterator middle,
    BidirectionalIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador bidirecional que trata da posição do primeiro elemento no primeiro entre dois intervalos classificados consecutivos a serem combinados e classificados em um único intervalo.

*meio*\
Um iterador bidirecional que trata da posição do primeiro elemento no segundo entre dois intervalos classificados consecutivos a serem combinados e classificados em um único intervalo.

*última*\
Um iterador bidirecional que trata da posição logo após o último elemento no segundo entre dois intervalos classificados consecutivos a serem combinados e classificados em um único intervalo.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado de comparação usa dois argumentos e deve retornar **true** quando o primeiro elemento for menor do que o segundo elemento e **false** caso contrário.

### <a name="remarks"></a>Comentários

Os intervalos consecutivos classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível desde primeira por incrementação.

Cada intervalo consecutivo classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo `inplace_merge`, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados. A operação é estável, pois a ordem relativa dos elementos em cada intervalo é preservada. Quando há elementos equivalentes nos dois intervalos de origem, o elemento no primeiro intervalo precede o elemento do segundo no intervalo combinado.

A complexidade depende da memória disponível, pois o algoritmo aloca memória para um buffer temporário. Se houver memória suficiente disponível, o melhor caso será linear com `(last - first) - 1` comparações; se nenhuma memória auxiliar estiver disponível, o pior caso será `N log(N)` , em que *N*  =  *último*  -  *primeiro*.

### <a name="example"></a>Exemplo

```cpp
// alg_inplace_merge.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      //For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1, Iter2, Iter3;

    // Constructing vector v1 with default less-than ordering
    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii =-5 ; ii <= 0 ; ii++ )
    {
        v1.push_back( ii );
    }

    cout << "Original vector v1 with subranges sorted by the\n "
            << "binary predicate less than is v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // Constructing vector v2 with ranges sorted by greater
    vector<int> v2 ( v1 );
    vector<int>::iterator break2;
    break2 = find ( v2.begin( ), v2.end( ), -5 );
    sort ( v2.begin( ), break2 , greater<int>( ) );
    sort ( break2 , v2.end( ), greater<int>( ) );
    cout << "Original vector v2 with subranges sorted by the\n "
            << "binary predicate greater is v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")" << endl;

    // Constructing vector v3 with ranges sorted by mod_lesser
    vector<int> v3 ( v1 );
    vector<int>::iterator break3;
    break3 = find ( v3.begin( ), v3.end( ), -5 );
    sort ( v3.begin( ), break3 , mod_lesser );
    sort ( break3 , v3.end( ), mod_lesser );
    cout << "Original vector v3 with subranges sorted by the\n "
            << "binary predicate mod_lesser is v3 = ( " ;
    for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")" << endl;

    vector<int>::iterator break1;
    break1 = find (v1.begin( ), v1.end( ), -5 );
    inplace_merge ( v1.begin( ), break1, v1.end( ) );
    cout << "Merged inplace with default order,\n vector v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // To merge inplace in descending order, specify binary
    // predicate greater<int>( )
    inplace_merge ( v2.begin( ), break2 , v2.end( ) , greater<int>( ) );
    cout << "Merged inplace with binary predicate greater specified,\n "
            << "vector v2mod = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")" << endl;

    // Applying a user defined (UD) binary predicate mod_lesser
    inplace_merge ( v3.begin( ), break3, v3.end( ), mod_lesser );
    cout << "Merged inplace with binary predicate mod_lesser specified,\n "
            << "vector v3mod = ( " ; ;
    for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")" << endl;
}
```

```Output
Original vector v1 with subranges sorted by the
binary predicate less than is v1 = ( 0 1 2 3 4 5 -5 -4 -3 -2 -1 0 )
Original vector v2 with subranges sorted by the
binary predicate greater is v2 = ( 5 4 3 2 1 0 0 -1 -2 -3 -4 -5 )
Original vector v3 with subranges sorted by the
binary predicate mod_lesser is v3 = ( 0 1 2 3 4 5 0 -1 -2 -3 -4 -5 )
Merged inplace with default order,
vector v1mod = ( -5 -4 -3 -2 -1 0 0 1 2 3 4 5 )
Merged inplace with binary predicate greater specified,
vector v2mod = ( 5 4 3 2 1 0 0 -1 -2 -3 -4 -5 )
Merged inplace with binary predicate mod_lesser specified,
vector v3mod = ( 0 0 1 -1 2 -2 3 -3 4 -4 5 -5 )
```

## <a name="is_heap"></a><a name="is_heap"></a>is_heap

Retorna **true** se os elementos no intervalo especificado formam um heap.

```cpp
template<class RandomAccessIterator>
bool is_heap(
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class RandomAccessIterator, class Compare>
bool is_heap(
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);

template<class ExecutionPolicy, class RandomAccessIterator>
bool is_heap(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class ExecutionPolicy, class RandomAccessIterator, class Compare>
bool is_heap(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de acesso aleatório que indica o início de um intervalo a ser verificado quanto a um heap.

*última*\
Um iterador de acesso aleatório que indica o final de um intervalo.

*Pred*\
Uma condição a ser testada para ordenar elementos. Um predicado de comparação usa dois argumentos e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retornará **true** se os elementos no intervalo especificado formarem um heap, **false** se não tiverem.

### <a name="remarks"></a>Comentários

A primeira função de modelo retorna [is_heap_until](algorithm-functions.md#is_heap_until) `(first , last) == last` .

A segunda função de modelo retorna

`is_heap_until(first, last, pred) == last`.

## <a name="is_heap_until"></a><a name="is_heap_until"></a>is_heap_until

Retorna um iterador posicionado no primeiro elemento no intervalo [ `first` , `last` ) que não satisfaz a condição de ordenação de heap ou *terminar* se o intervalo formar um heap.

```cpp
template<class RandomAccessIterator>
RandomAccessIterator is_heap_until(
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class RandomAccessIterator, class Compare>
RandomAccessIterator is_heap_until(
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);

template<class ExecutionPolicy, class RandomAccessIterator>
RandomAccessIterator is_heap_until(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class ExecutionPolicy, class RandomAccessIterator, class Compare>
RandomAccessIterator is_heap_until(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de acesso aleatório que especifica o primeiro elemento de um intervalo para verificar se há um heap.

*última*\
Um iterador de acesso aleatório que especifica o final do intervalo para verificar se há um heap.

*Pred*\
Um predicado binário que especifica a condição de ordenação fraca estrita que define um heap. O predicado padrão é `std::less<>` quando *Pred* não é especificado.

### <a name="return-value"></a>Valor retornado

Retorna o *último* se o intervalo especificado forma um heap ou contém um ou menos elementos. Caso contrário, retornará um iterador para o primeiro elemento encontrado que não atenda à condição do heap.

### <a name="remarks"></a>Comentários

A primeira função de modelo retorna o último iterador `next` em `[first, last)`, em que `[first, next)` é um heap ordenado pelo objeto de função `std::less<>`. Se a distância `last - first` for menor que 2, a função retornará *Last*.

A segunda função de modelo se comporta da mesma forma que a primeira, exceto pelo fato de que ela usa o predicado *Pred* em vez de `std::less<>` como a condição de ordenação de heap.

## <a name="is_partitioned"></a><a name="is_partitioned"></a>is_partitioned

Retorna **true** se todos os elementos no intervalo especificado que testam **true** para uma condição vierem antes de qualquer elemento que teste **false**.

```cpp
template<class InputIterator, class UnaryPredicate>
bool is_partitioned(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template <class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
bool is_partitioned(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica onde um intervalo começa a verificar uma condição.

*última*\
Um iterador de entrada que indica o final de um intervalo.

*Pred*\
A condição a ser testada. Ela é fornecida por um objeto de função de predicado definido pelo usuário que define a condição a ser atendida pelo elemento que está sendo pesquisado. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retorna **true** quando todos os elementos no intervalo especificado que testam **true** para uma condição são anteriores a quaisquer elementos que testam **false**e, caso contrário, retorna **false**.

### <a name="remarks"></a>Comentários

A função de modelo retornará **true** somente se todos os elementos no `[first, last)` forem particionados por *Pred*; ou seja, todos os elementos `X` em `[first, last)` para o qual `pred (X)` é verdadeiro ocorrerão antes que todos os elementos sejam `Y` `pred (Y)` **false**.

## <a name="is_permutation"></a><a name="is_permutation"></a>is_permutation

Retornará true se os dois intervalos contiverem os mesmos elementos, estando os elementos na mesma ordem ou não. Use as sobrecargas de intervalo duplo no código do C++14, porque as sobrecargas que usam apenas um único iterador para o segundo intervalo não detectarão as diferenças se o segundo intervalo for maior que o primeiro intervalo e resultarão em um comportamento indefinido se o segundo intervalo for menor que o primeiro intervalo.

```cpp
template<class ForwardIterator1, class ForwardIterator2>
bool is_permutation(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2);

template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
bool is_permutation(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    BinaryPredicate Pred);

// C++14
template<class ForwardIterator1, class ForwardIterator2>
bool is_permutation(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
bool is_permutation(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*first1*\
Um iterador de avanço que se refere ao primeiro elemento do intervalo.

*last1*\
Um iterador de avanço que se refere ao elemento logo após o último do intervalo.

*first2*\
Um iterador de avanço que se refere ao primeiro elemento de um segundo intervalo, usado para comparação.

*last2*\
Um iterador de avanço que se refere a um elemento logo após o último de um segundo intervalo, usado para comparação.

*Pred*\
Um predicado que testa a equivalência e retorna um **bool**.

### <a name="return-value"></a>Valor retornado

**true** quando os intervalos puderem ser reorganizados para que sejam idênticos de acordo com o predicado de comparador; caso contrário, **false**.

### <a name="remarks"></a>Comentários

`is_permutation` tem complexidade quadrática no pior caso.

A primeira função de modelo pressupõe que há tantos elementos no intervalo que começam em *first2* como no intervalo designado por `[first1, last1)` . Se houver mais elementos no segundo intervalo, eles serão ignorados, se houver menos, ocorrerá um comportamento indefinido. A terceira função de modelo (C++14 e posterior) não faz essa suposição. Ambos retornarão **true** somente se, para cada elemento X no intervalo designado por `[first1, last1)` há tantos elementos Y no mesmo intervalo para o qual X = = Y, como existem no intervalo que começa em *first2* ou `[first2, last2)` . Aqui, é `operator==` necessário executar uma comparação emparelhada entre seus operandos.

A segunda e a quarta função de modelo comportam-se da mesma forma, exceto que elas substituem `operator==(X, Y)` por `Pred(X, Y)`. Para comportar-se corretamente, o predicado deve ser simétrico, reflexivo e transitivo.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `is_permutation`:

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<int> vec_1{ 2, 3, 0, 1, 4, 5 };
    vector<int> vec_2{ 5, 4, 0, 3, 1, 2 };

    vector<int> vec_3{ 4, 9, 13, 3, 6, 5 };
    vector<int> vec_4{ 7, 4, 11, 9, 2, 1 };

    cout << "(1) Compare using built-in == operator: ";
    cout << boolalpha << is_permutation(vec_1.begin(), vec_1.end(),
        vec_2.begin(), vec_2.end()) << endl; // true

    cout << "(2) Compare after modifying vec_2: ";
    vec_2[0] = 6;
    cout << is_permutation(vec_1.begin(), vec_1.end(),
        vec_2.begin(), vec_2.end()) << endl; // false

    // Define equivalence as "both are odd or both are even"
    cout << "(3) vec_3 is a permutation of vec_4: ";
    cout << is_permutation(vec_3.begin(), vec_3.end(),
        vec_4.begin(), vec_4.end(),
        [](int lhs, int rhs) { return lhs % 2 == rhs % 2; }) << endl; // true

    // Initialize a vector using the 's' string literal to specify a std::string
    vector<string> animals_1{ "dog"s, "cat"s, "bird"s, "monkey"s };
    vector<string> animals_2{ "donkey"s, "bird"s, "meerkat"s, "cat"s };

    // Define equivalence as "first letters are equal":
    bool is_perm = is_permutation(animals_1.begin(), animals_1.end(), animals_2.begin(), animals_2.end(),
        [](const string& lhs, const string& rhs)
    {
        return lhs[0] == rhs[0]; //std::string guaranteed to have at least a null terminator
    });

    cout << "animals_2 is a permutation of animals_1: " << is_perm << endl; // true

    cout << "Press a letter" << endl;
    char c;
    cin >> c;

    return 0;
}
```

## <a name="is_sorted"></a><a name="is_sorted"></a>is_sorted

Retornará **true** se os elementos no intervalo especificado estiverem em ordem classificada.

```cpp
template<class ForwardIterator>
bool is_sorted(
    ForwardIterator first,
    ForwardIterator last);

template<class ForwardIterator, class Compare>
bool is_sorted(
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);

template<class ExecutionPolicy, class ForwardIterator>
bool is_sorted(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class Compare>
bool is_sorted(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que indica onde começa o intervalo a ser verificado.

*última*\
Um iterador de avanço que indica o final de um intervalo.

*Pred*\
A condição de teste para determinar uma ordem entre dois elementos. Um predicado de comparação usa dois argumentos e retorna **true** ou **false**. Executa a mesma tarefa que `operator<`.

### <a name="remarks"></a>Comentários

A primeira função de modelo retorna [is_sorted_until](#is_sorted_until) `( first, last ) == last` . A `operator<` função executa a comparação de ordem.

A segunda função de modelo retorna `is_sorted_until( first, last , pred ) == last`. A função de predicado *Pred* executa a comparação de ordem.

## <a name="is_sorted_until"></a><a name="is_sorted_until"></a>is_sorted_until

Retorna um `ForwardIterator` que é definido como o último elemento que está na ordem classificada de um intervalo especificado.

A segunda versão permite que você forneça um objeto de função de comparação que retorna **true** quando dois elementos fornecidos estão em ordem classificada; caso contrário, **false** .

```cpp
template<class ForwardIterator>
ForwardIterator is_sorted_until(
    ForwardIterator first,
    ForwardIterator last);

template<class ForwardIterator, class Compare>
ForwardIterator is_sorted_until(
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);

template<class ExecutionPolicy, class ForwardIterator>
ForwardIterator is_sorted_until(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class Compare>
ForwardIterator is_sorted_until(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que indica onde começa o intervalo a ser verificado.

*última*\
Um iterador de avanço que indica o final de um intervalo.

*Pred*\
A condição de teste para determinar uma ordem entre dois elementos. Um predicado de comparação usa dois argumentos e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retorna um `ForwardIterator` definido como o último elemento na ordem classificada. A sequência classificada começa a partir da *primeira*.

### <a name="remarks"></a>Comentários

A primeira função de modelo retorna o último iterador `next` em `[first, last]` para que `[first, next)` seja uma sequência classificada ordenada por `operator<`. Se `distance()` for menor que 2, a função retornará *Last*.

A segunda função de modelo comporta-se da mesma forma, exceto que ela substitui `operator<(X, Y)` por `pred(X, Y)`.

## <a name="iter_swap"></a><a name="iter_swap"></a>iter_swap

Troca dois valores referenciados por um par de iteradores especificados.

```cpp
template<class ForwardIterator1, class ForwardIterator2>
void iter_swap( ForwardIterator1 left, ForwardIterator2 right );
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Um dos iteradores de avanço cujo valor deverá ser trocado.

*Certo*\
O segundo dos iteradores de avanço cujo valor deverá ser trocado.

### <a name="remarks"></a>Comentários

`swap`deve ser usado em preferência ao **iter_swap**, que foi incluído no padrão C++ para compatibilidade com versões anteriores. Se `Fit1` e `Fit2` são iteradores de encaminhamento, `iter_swap( Fit1, Fit2 )` é equivalente a `swap( *Fit1, *Fit2 )` .

Os tipos de valor dos iteradores de avanço de entrada devem ter o mesmo valor.

### <a name="example"></a>Exemplo

```cpp
// alg_iter_swap.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt
{
public:
    CInt( int n = 0 ) : m_nVal( n ){}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ){}
    CInt&   operator=( const CInt& rhs ) { m_nVal =
    rhs.m_nVal; return *this; }
    bool operator<( const CInt& rhs ) const
        { return ( m_nVal < rhs.m_nVal );}
    friend ostream& operator<<( ostream& osIn, const CInt& rhs );

private:
    int m_nVal;
};

inline ostream& operator<<( ostream& osIn, const CInt& rhs )
{
    osIn << "CInt(" << rhs.m_nVal << ")";
    return osIn;
}

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
};

int main()
{
    CInt c1 = 5, c2 = 1, c3 = 10;
    deque<CInt> deq1;
    deque<CInt>::iterator d1_Iter;

    deq1.push_back ( c1 );
    deq1.push_back ( c2 );
    deq1.push_back ( c3 );

    cout << "The original deque of CInts is deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl;

    // Exchanging first and last elements with iter_swap
    iter_swap ( deq1.begin( ), --deq1.end( ) );

    cout << "The deque of CInts with first & last elements swapped is:\n deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl;

    // Swapping back first and last elements with swap
    swap ( *deq1.begin( ), *(deq1.end( ) -1 ) );

    cout << "The deque of CInts with first & last elements swapped back is:\n deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl;

    // Swapping a vector element with a deque element
    vector<int> v1;
    vector<int>::iterator Iter1;
    deque<int> deq2;
    deque<int>::iterator d2_Iter;

    int i;
    for ( i = 0 ; i <= 3 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii = 4 ; ii <= 5 ; ii++ )
    {
        deq2.push_back( ii );
    }

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Deque deq2 is ( " ;
    for ( d2_Iter = deq2.begin( ) ; d2_Iter != deq2.end( ) ; d2_Iter++ )
        cout << *d2_Iter << " ";
    cout << ")." << endl;

    iter_swap ( v1.begin( ), deq2.begin( ) );

    cout << "After exchanging first elements,\n vector v1 is: v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl << " & deque deq2 is: deq2 = ( ";
    for ( d2_Iter = deq2.begin( ) ; d2_Iter != deq2.end( ) ; d2_Iter++ )
        cout << *d2_Iter << " ";
    cout << ")." << endl;
}
```

```Output
The original deque of CInts is deq1 = ( CInt(5), CInt(1), CInt(10) ).
The deque of CInts with first & last elements swapped is:
deq1 = ( CInt(10), CInt(1), CInt(5) ).
The deque of CInts with first & last elements swapped back is:
deq1 = ( CInt(5), CInt(1), CInt(10) ).
Vector v1 is ( 0 1 2 3 ).
Deque deq2 is ( 4 5 ).
After exchanging first elements,
vector v1 is: v1 = ( 4 1 2 3 ).
& deque deq2 is: deq2 = ( 0 5 ).
```

## <a name="lexicographical_compare"></a><a name="lexicographical_compare"></a>lexicographical_compare

Compara elemento por elemento entre duas sequências para determinar qual é o menor dos dois.

```cpp
template<class InputIterator1, class InputIterator2>
bool lexicographical_compare(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2 );

template<class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
bool lexicographical_compare(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Compare>
bool lexicographical_compare(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro intervalo a ser comparado.

*last1*\
Um iterador de entrada que trata da posição logo após o elemento final no primeiro intervalo a ser comparado.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo a ser comparado.

*last2*\
Um iterador de entrada que trata da posição logo após o elemento final no segundo intervalo a ser comparado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado de comparação usa dois argumentos e retorna **true** quando satisfeito e **falso** quando não estiver satisfeito.

### <a name="return-value"></a>Valor retornado

**true** se o primeiro intervalo for lexicograficamente menor que o segundo intervalo, caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma comparação lexicográfica entre as sequências faz a comparação elemento por elemento até:

- localizar dois elementos correspondentes diferentes e o resultado da comparação entre eles será considerado o resultado da comparação entre as sequências.

- que nenhuma desigualdade seja localizada, mas se uma sequência tiver mais elementos que a outra, a sequência mais curta será considerada menor do que a sequência mais longa.

- Nenhuma desigualdade é encontrada e as sequências têm o mesmo número de elementos e, portanto, as sequências são iguais e o resultado da comparação é **false**.

### <a name="example"></a>Exemplo

```cpp
// alg_lex_comp.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// Return whether second element is twice the first
bool twice ( int elem1, int elem2 )
{
    return 2 * elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    list<int> L1;
    vector<int>::iterator Iter1, Iter2;
    list<int>::iterator L1_Iter, L1_inIter;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }
    int ii;
    for ( ii = 0 ; ii <= 6 ; ii++ )
    {
        L1.push_back( 5 * ii );
    }

    int iii;
    for ( iii = 0 ; iii <= 5 ; iii++ )
    {
        v2.push_back( 10 * iii );
    }

    cout << "Vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "List L1 = ( " ;
    for ( L1_Iter = L1.begin( ) ; L1_Iter!= L1.end( ) ; L1_Iter++ )
        cout << *L1_Iter << " ";
    cout << ")" << endl;

    cout << "Vector v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
        cout << ")" << endl;

    // Self lexicographical_comparison of v1 under identity
    bool result1;
    result1 = lexicographical_compare (v1.begin( ), v1.end( ),
                    v1.begin( ), v1.end( ) );
    if ( result1 )
        cout << "Vector v1 is lexicographically_less than v1." << endl;
    else
        cout << "Vector v1 is not lexicographically_less than v1." << endl;

    // lexicographical_comparison of v1 and L2 under identity
    bool result2;
    result2 = lexicographical_compare (v1.begin( ), v1.end( ),
                    L1.begin( ), L1.end( ) );
    if ( result2 )
        cout << "Vector v1 is lexicographically_less than L1." << endl;
    else
        cout << "Vector v1 is lexicographically_less than L1." << endl;

    bool result3;
    result3 = lexicographical_compare (v1.begin( ), v1.end( ),
                    v2.begin( ), v2.end( ), twice );
    if ( result3 )
        cout << "Vector v1 is lexicographically_less than v2 "
            << "under twice." << endl;
    else
        cout << "Vector v1 is not lexicographically_less than v2 "
            << "under twice." << endl;
}
```

```Output
Vector v1 = ( 0 5 10 15 20 25 )
List L1 = ( 0 5 10 15 20 25 30 )
Vector v2 = ( 0 10 20 30 40 50 )
Vector v1 is not lexicographically_less than v1.
Vector v1 is lexicographically_less than L1.
Vector v1 is not lexicographically_less than v2 under twice.
```

## <a name="lower_bound"></a><a name="lower_bound"></a>lower_bound

Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior ou equivalente a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class ForwardIterator, class Type>
ForwardIterator lower_bound(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value );

template<class ForwardIterator, class Type, class BinaryPredicate>
ForwardIterator lower_bound(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value,
    BinaryPredicate pred );
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*última*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*valor*\
O valor cuja primeira posição ou primeira posição possível está sendo pesquisado no intervalo ordenado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço na posição do primeiro elemento em um intervalo ordenado com um valor maior ou equivalente a um valor especificado, em que a equivalência seja especificada com um predicado binário.

### <a name="remarks"></a>Comentários

O intervalo de origem classificado referenciado deve ser válido, todos os iteradores devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Um intervalo classificado é uma pré-condição de uso de `lower_bound` e tem a ordenação igual à especificada com um predicado binário.

O intervalo não é modificado pelo algoritmo `lower_bound`.

Os tipos de valor dos iteradores de avanço precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes

A complexidade do algoritmo é logarítmica para iteradores de acesso aleatório e linear, caso contrário, com o número de etapas proporcionais a ( `last - first` ).

### <a name="example"></a>Exemplo

```cpp
// alg_lower_bound.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;

    vector<int> v1;
    // Constructing vector v1 with default less-than ordering
    for ( auto i = -1 ; i <= 4 ; ++i )
    {
        v1.push_back( i );
    }

    for ( auto ii =-3 ; ii <= 0 ; ++ii )
    {
        v1.push_back( ii );
    }

    cout << "Starting vector v1 = ( " ;
    for (const auto &Iter : v1)
        cout << Iter << " ";
    cout << ")." << endl;

    sort(v1.begin(), v1.end());
    cout << "Original vector v1 with range sorted by the\n "
        << "binary predicate less than is v1 = ( " ;
    for (const auto &Iter : v1)
        cout << Iter << " ";
    cout << ")." << endl;

    // Constructing vector v2 with range sorted by greater
    vector<int> v2(v1);

    sort(v2.begin(), v2.end(), greater<int>());

    cout << "Original vector v2 with range sorted by the\n "
        << "binary predicate greater is v2 = ( " ;
    for (const auto &Iter : v2)
        cout << Iter << " ";
    cout << ")." << endl;

    // Constructing vectors v3 with range sorted by mod_lesser
    vector<int> v3(v1);
    sort(v3.begin(), v3.end(), mod_lesser);

    cout << "Original vector v3 with range sorted by the\n "
        << "binary predicate mod_lesser is v3 = ( " ;
    for (const auto &Iter : v3)
        cout << Iter << " ";
    cout << ")." << endl;

    // Demonstrate lower_bound

    vector<int>::iterator Result;

    // lower_bound of 3 in v1 with default binary predicate less<int>()
    Result = lower_bound(v1.begin(), v1.end(), 3);
    cout << "The lower_bound in v1 for the element with a value of 3 is: "
        << *Result << "." << endl;

    // lower_bound of 3 in v2 with the binary predicate greater<int>( )
    Result = lower_bound(v2.begin(), v2.end(), 3, greater<int>());
    cout << "The lower_bound in v2 for the element with a value of 3 is: "
        << *Result << "." << endl;

    // lower_bound of 3 in v3 with the binary predicate mod_lesser
    Result = lower_bound(v3.begin(), v3.end(), 3, mod_lesser);
    cout << "The lower_bound in v3 for the element with a value of 3 is: "
        << *Result << "." << endl;
}
```

## <a name="make_heap"></a><a name="make_heap"></a>make_heap

Converte os elementos de um intervalo especificado em um heap no qual o primeiro elemento é o maior e para o qual um critério de classificação pode ser especificado com um predicado binário.

```cpp
template<class RandomAccessIterator>
void make_heap(
    RandomAccessIterator first,
    RandomAccessIterator last );

template<class RandomAccessIterator, class BinaryPredicate>
void make_heap(
    RandomAccessIterator first,
    RandomAccessIterator last,
    BinaryPredicate pred );
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser convertido em um heap.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser convertido em um heap.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="remarks"></a>Comentários

Os heaps têm duas propriedades:

- O primeiro elemento sempre é o maior.

- Elementos podem ser adicionados ou removidos em tempo logarítmico.

Os heaps são a maneira ideal de implementar filas de prioridade e são usados na implementação da [Classe priority_queue](priority-queue-class.md) do adaptador de contêiner da Biblioteca Padrão do C++.

A complexidade é linear, exigindo `3 * (last - first)` comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_make_heap.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main() {
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    random_shuffle( v1.begin( ), v1.end( ) );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Make v1 a heap with default less than ordering
    make_heap ( v1.begin( ), v1.end( ) );
    cout << "The heaped version of vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Make v1 a heap with greater than ordering
    make_heap ( v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "The greater-than heaped version of v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="max"></a><a name="max"></a>maximizar

Compara dois objetos e retorna o maior dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class Type>
constexpr Type& max(
    const Type& left,
    const Type& right);
template<class Type, class Pr>
constexpr Type& max(
    const Type& left,
    const Type& right,
    BinaryPredicate pred);
template<class Type>
constexpr Type& max (
    initializer_list<Type> ilist);
template<class Type, class Pr>
constexpr Type& max(
    initializer_list<Type> ilist,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
O primeiro dos dois objetos que estão sendo comparados.

*Certo*\
O segundo dos dois objetos que estão sendo comparados.

*Pred*\
Um predicado binário usado para comparar os dois objetos.

*inList*\
A lista do inicializador que contém os objetos a serem comparados.

### <a name="return-value"></a>Valor retornado

O maior entre dois objetos, a menos que nenhum seja maior e, nesse caso, retorna o primeiro dos dois objetos. No caso de um initializer_list, retorna o maior entre os objetos na lista.

### <a name="remarks"></a>Comentários

O algoritmo `max` não costuma ter objetos passados como parâmetros. A maioria dos algoritmos da Biblioteca Padrão do C++ opera em um intervalo de elementos cujas posições são especificadas por iteradores passados como parâmetros. Se você precisar de uma função que opere em um intervalo de elementos, use [max_element](algorithm-functions.md#max_element). O Visual Studio 2017 habilita o **constexpr** nas sobrecargas que usam um initializer_list.

### <a name="example"></a>Exemplo

```cpp
// alg_max.cpp
// compile with: /EHsc
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt
{
public:
    CInt( int n = 0 ) : m_nVal( n ){}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ){}
    CInt&   operator=( const CInt& rhs ) {m_nVal =
    rhs.m_nVal; return *this;}
    bool operator<( const CInt& rhs ) const
        {return ( m_nVal < rhs.m_nVal );}
    friend ostream& operator<<( ostream& osIn, const CInt& rhs );

private:
    int m_nVal;
};

inline ostream& operator<<( ostream& osIn, const CInt& rhs )
{
    osIn << "CInt( " << rhs.m_nVal << " )";
    return osIn;
}

// Return whether absolute value of elem1 is greater than
// absolute value of elem2
bool abs_greater ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = -elem1;
    if ( elem2 < 0 )
        elem2 = -elem2;
    return elem1 < elem2;
};

int main()
{
    int a = 6, b = -7;
    // Return the integer with the larger absolute value
    const int& result1 = max(a, b, abs_greater);
    // Return the larger integer
    const int& result2 = max(a, b);

    cout << "Using integers 6 and -7..." << endl;
    cout << "The integer with the greater absolute value is: "
            << result1 << "." << endl;
    cout << "The integer with the greater value is: "
            << result2 << "." << endl;
    cout << endl;

    // Comparing the members of an initializer_list
    const int& result3 = max({ a, b });
    const int& result4 = max({ a, b }, abs_greater);

    cout << "Comparing the members of an initializer_list..." << endl;
    cout << "The member with the greater value is: " << result3 << endl;
    cout << "The integer with the greater absolute value is: " << result4 << endl;

    // Comparing set containers with elements of type CInt
    // using the max algorithm
    CInt c1 = 1, c2 = 2, c3 = 3;
    set<CInt> s1, s2, s3;
    set<CInt>::iterator s1_Iter, s2_Iter, s3_Iter;

    s1.insert ( c1 );
    s1.insert ( c2 );
    s2.insert ( c2 );
    s2.insert ( c3 );

    cout << "s1 = (";
    for ( s1_Iter = s1.begin( ); s1_Iter != --s1.end( ); s1_Iter++ )
        cout << " " << *s1_Iter << ",";
    s1_Iter = --s1.end( );
    cout << " " << *s1_Iter << " )." << endl;

    cout << "s2 = (";
    for ( s2_Iter = s2.begin( ); s2_Iter != --s2.end( ); s2_Iter++ )
        cout << " " << *s2_Iter << ",";
    s2_Iter = --s2.end( );
    cout << " " << *s2_Iter << " )." << endl;

    s3 = max ( s1, s2 );
    cout << "s3 = max ( s1, s2 ) = (";
    for ( s3_Iter = s3.begin( ); s3_Iter != --s3.end( ); s3_Iter++ )
        cout << " " << *s3_Iter << ",";
    s3_Iter = --s3.end( );
    cout << " " << *s3_Iter << " )." << endl << endl;

    // Comparing vectors with integer elements using the max algorithm
    vector<int> v1, v2, v3, v4, v5;
    vector<int>::iterator Iter1, Iter2, Iter3, Iter4, Iter5;

    int i;
    for ( i = 0 ; i <= 2 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii = 0 ; ii <= 2 ; ii++ )
    {
        v2.push_back( ii );
    }

    int iii;
    for ( iii = 0 ; iii <= 2 ; iii++ )
    {
        v3.push_back( 2 * iii );
    }

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Vector v2 is ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    cout << "Vector v3 is ( " ;
    for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;

    v4 = max ( v1, v2 );
    v5 = max ( v1, v3 );

    cout << "Vector v4 = max (v1,v2) is ( " ;
    for ( Iter4 = v4.begin( ) ; Iter4 != v4.end( ) ; Iter4++ )
        cout << *Iter4 << " ";
    cout << ")." << endl;

    cout << "Vector v5 = max (v1,v3) is ( " ;
    for ( Iter5 = v5.begin( ) ; Iter5 != v5.end( ) ; Iter5++ )
        cout << *Iter5 << " ";
    cout << ")." << endl;
}
```

```Output
Using integers 6 and -7...
The integer with the greater absolute value is: -7
The integer with the greater value is: 6.
Comparing the members of an initializer_list...The member with the greater value is: 6The integer with the greater absolute value is: -7
s1 = ( CInt( 1 ), CInt( 2 ) ).
s2 = ( CInt( 2 ), CInt( 3 ) ).
s3 = max ( s1, s2 ) = ( CInt( 2 ), CInt( 3 ) ).

Vector v1 is ( 0 1 2 ).
Vector v2 is ( 0 1 2 ).
Vector v3 is ( 0 2 4 ).
Vector v4 = max (v1,v2) is ( 0 1 2 ).
Vector v5 = max (v1,v3) is ( 0 2 4 ).
```

## <a name="max_element"></a><a name="max_element"></a>max_element

Localiza a primeira ocorrência do maior elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class ForwardIterator>
constexpr ForwardIterator max_element(
    ForwardIterator first,
    ForwardIterator last );

template<class ForwardIterator, class Compare>
constexpr ForwardIterator max_element(
    ForwardIterator first,
    ForwardIterator last,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator>
ForwardIterator max_element(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class Compare>
ForwardIterator max_element(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento do intervalo no qual será pesquisado o maior elemento.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final do intervalo no qual será pesquisado o maior elemento.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado de comparação usa dois argumentos e deve retornar **true** quando o primeiro elemento for menor do que o segundo elemento e **false** caso contrário.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que trata da posição da primeira ocorrência do maior elemento no intervalo pesquisado.

### <a name="remarks"></a>Comentários

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

A complexidade é linear: as `(last - first) - 1` comparações são necessárias para um intervalo não vazio.

### <a name="example"></a>Exemplo

```cpp
// alg_max_element.cpp
// compile with: /EHsc
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt
{
public:
    CInt( int n = 0 ) : m_nVal( n ){}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ){}
    CInt& operator=( const CInt& rhs ) {m_nVal =
    rhs.m_nVal; return *this;}
    bool operator<( const CInt& rhs ) const
        {return ( m_nVal < rhs.m_nVal );}
    friend ostream& operator<<( ostream& osIn, const CInt& rhs );

private:
    int m_nVal;
};

inline ostream& operator<<(ostream& osIn, const CInt& rhs)
{
    osIn << "CInt( " << rhs.m_nVal << " )";
    return osIn;
}

// Return whether modulus of elem1 is greater than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
};

int main()
{
    // Searching a set container with elements of type CInt
    // for the maximum element
    CInt c1 = 1, c2 = 2, c3 = -3;
    set<CInt> s1;
    set<CInt>::iterator s1_Iter, s1_R1_Iter, s1_R2_Iter;

    s1.insert ( c1 );
    s1.insert ( c2 );
    s1.insert ( c3 );

    cout << "s1 = (";
    for ( s1_Iter = s1.begin( ); s1_Iter != --s1.end( ); s1_Iter++ )
        cout << " " << *s1_Iter << ",";
    s1_Iter = --s1.end( );
    cout << " " << *s1_Iter << " )." << endl;

    s1_R1_Iter = max_element ( s1.begin( ), s1.end( ) );

    cout << "The largest element in s1 is: " << *s1_R1_Iter << endl;
    cout << endl;

    // Searching a vector with elements of type int for the maximum
    // element under default less than & mod_lesser binary predicates
    vector<int> v1;
    vector<int>::iterator v1_Iter, v1_R1_Iter, v1_R2_Iter;

    int i;
    for ( i = 0 ; i <= 3 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii = 1 ; ii <= 4 ; ii++ )
    {
        v1.push_back( - 2 * ii );
    }

    cout << "Vector v1 is ( " ;
    for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )
        cout << *v1_Iter << " ";
    cout << ")." << endl;

    v1_R1_Iter = max_element ( v1.begin( ), v1.end( ) );
    v1_R2_Iter = max_element ( v1.begin( ), v1.end( ), mod_lesser);

    cout << "The largest element in v1 is: " << *v1_R1_Iter << endl;
    cout << "The largest element in v1 under the mod_lesser"
            << "\n binary predicate is: " << *v1_R2_Iter << endl;
}
```

## <a name="merge"></a><a name="merge"></a>Mescle

Combina todos os elementos de dois intervalos de origem classificados em um único intervalo de destino classificado, no qual o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator merge(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result );

template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator merge(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator>
ForwardIterator merge(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator, class Compare>
ForwardIterator merge(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro entre dois intervalos de origem classificados a serem combinados e classificados em um único intervalo.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro entre dois intervalos de origem classificados a serem combinados e classificados em um único intervalo.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo entre dois intervalos de origem classificados consecutivos a serem combinados e classificados em um único intervalo.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo entre dois intervalos de origem classificados consecutivos a serem combinados e classificados em um único intervalo.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino no qual os dois intervalos de origem devem ser combinados em um único intervalo classificado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado de comparação usa dois argumentos e deve retornar **true** quando o primeiro elemento for menor do que o segundo elemento e **false** caso contrário.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o último elemento no intervalo de destino classificado.

### <a name="remarks"></a>Comentários

Os intervalos de origem classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

O intervalo de destino não deve se sobrepor a nenhum dos intervalos de origem e deve ser grande o suficiente para conter o intervalo de destino.

Cada intervalo de origem classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo `merge`, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

A operação é estável, pois a ordem relativa dos elementos em cada intervalo é preservada no intervalo de destino. Os intervalos de origem não são modificados pelo algoritmo `merge` .

Os tipos de valor dos iteradores de entrada precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Quando há elementos equivalentes nos dois intervalos de origem, os elementos do primeiro intervalo precedem os elementos do segundo intervalo de origem no intervalo de destino.

A complexidade do algoritmo é linear com no máximo `(last1 - first1) - (last2 - first2) - 1` comparações.

A [classe list](list-class.md) fornece uma função de membro "merge" para mesclar os elementos de duas listas.

### <a name="example"></a>Exemplo

```cpp
// alg_merge.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>   // For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 ) {
    if (elem1 < 0)
        elem1 = - elem1;
    if (elem2 < 0)
        elem2 = - elem2;
    return elem1 < elem2;
}

int main() {
    using namespace std;
    vector<int> v1a, v1b, v1 ( 12 );
    vector<int>::iterator Iter1a, Iter1b, Iter1;

    // Constructing vector v1a and v1b with default less than ordering
    int i;
    for ( i = 0 ; i <= 5 ; i++ )
        v1a.push_back( i );

    int ii;
    for ( ii =-5 ; ii <= 0 ; ii++ )
        v1b.push_back( ii );

    cout << "Original vector v1a with range sorted by the\n "
            << "binary predicate less than is v1a = ( " ;
    for ( Iter1a = v1a.begin( ) ; Iter1a != v1a.end( ) ; Iter1a++ )
        cout << *Iter1a << " ";
    cout << ")." << endl;

    cout << "Original vector v1b with range sorted by the\n "
            << "binary predicate less than is v1b = ( " ;
    for ( Iter1b = v1b.begin( ) ; Iter1b != v1b.end( ) ; Iter1b++ )
        cout << *Iter1b << " ";
    cout << ")." << endl;

    // Constructing vector v2 with ranges sorted by greater
    vector<int> v2a ( v1a ) , v2b ( v1b ) , v2 ( v1 );
    vector<int>::iterator Iter2a, Iter2b, Iter2;
    sort ( v2a.begin( ), v2a.end( ), greater<int>( ) );
    sort ( v2b.begin( ), v2b.end( ), greater<int>( ) );

    cout << "Original vector v2a with range sorted by the\n "
            << "binary predicate greater is   v2a = ( " ;
    for ( Iter2a = v2a.begin( ) ; Iter2a != v2a.end( ) ; Iter2a++ )
        cout << *Iter2a << " ";
    cout << ")." << endl;

    cout << "Original vector v2b with range sorted by the\n "
            << "binary predicate greater is   v2b = ( " ;
    for ( Iter2b = v2b.begin( ) ; Iter2b != v2b.end( ) ; Iter2b++ )
        cout << *Iter2b << " ";
    cout << ")." << endl;

    // Constructing vector v3 with ranges sorted by mod_lesser
    vector<int> v3a( v1a ), v3b( v1b ) , v3( v1 );
    vector<int>::iterator Iter3a, Iter3b, Iter3;
    sort ( v3a.begin( ), v3a.end( ), mod_lesser );
    sort ( v3b.begin( ), v3b.end( ), mod_lesser );

    cout << "Original vector v3a with range sorted by the\n "
            << "binary predicate mod_lesser is   v3a = ( " ;
    for ( Iter3a = v3a.begin( ) ; Iter3a != v3a.end( ) ; Iter3a++ )
        cout << *Iter3a << " ";
    cout << ")." << endl;

    cout << "Original vector v3b with range sorted by the\n "
            << "binary predicate mod_lesser is   v3b = ( " ;
    for ( Iter3b = v3b.begin( ) ; Iter3b != v3b.end( ) ; Iter3b++ )
        cout << *Iter3b << " ";
    cout << ")." << endl;

    // To merge inplace in ascending order with default binary
    // predicate less<int>( )
    merge ( v1a.begin( ), v1a.end( ), v1b.begin( ), v1b.end( ), v1.begin( ) );
    cout << "Merged inplace with default order,\n vector v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To merge inplace in descending order, specify binary
    // predicate greater<int>( )
    merge ( v2a.begin( ), v2a.end( ), v2b.begin( ), v2b.end( ),
        v2.begin( ), greater<int>( ) );
    cout << "Merged inplace with binary predicate greater specified,\n "
            << "vector v2mod = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    // Applying A user-defined (UD) binary predicate mod_lesser
    merge ( v3a.begin( ), v3a.end( ), v3b.begin( ), v3b.end( ),
        v3.begin( ), mod_lesser );
    cout << "Merged inplace with binary predicate mod_lesser specified,\n "
            << "vector v3mod = ( " ; ;
    for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;
}
```

## <a name="min"></a><a name="min"></a> min

Compara dois objetos e retorna o menor dos dois, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class Type>
constexpr const Type& min(
    const Type& left,
    const Type& right);

template<class Type, class Pr>
constexpr const Type& min(
    const Type& left,
    const Type& right,
    BinaryPredicate pred);

template<class Type>
constexpr Type min(
    initializer_list<Type> ilist);

template<class Type, class Pr>
constexpr Type min(
    initializer_list<Type> ilist,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
O primeiro dos dois objetos que estão sendo comparados.

*Certo*\
O segundo dos dois objetos que estão sendo comparados.

*Pred*\
Um predicado binário usado para comparar os dois objetos.

*inList*\
O `initializer_list` que contém os membros a serem comparados.

### <a name="return-value"></a>Valor retornado

O menor entre os dois objetos, a menos que nenhum seja menor e, nesse caso, retorna o primeiro entre os dois objetos. No caso de um `initializer_list` , ele retorna o mínimo dos objetos na lista.

### <a name="remarks"></a>Comentários

O algoritmo `min` não costuma ter objetos passados como parâmetros. A maioria dos algoritmos da Biblioteca Padrão do C++ opera em um intervalo de elementos cujas posições são especificadas por iteradores passados como parâmetros. Se você precisar de uma função que use um intervalo de elementos, use [min_element](algorithm-functions.md#min_element). o [constexpr](../cpp/constexpr-cpp.md) foi habilitado nas `initializer_list` sobrecargas no Visual Studio 2017.

### <a name="example"></a>Exemplo

```cpp
// alg_min.cpp
// compile with: /EHsc
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt
{
public:
    CInt( int n = 0 ) : m_nVal( n ){}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ){}
    CInt& operator=( const CInt& rhs ) {m_nVal =
    rhs.m_nVal; return *this;}
    bool operator<( const CInt& rhs ) const
        {return ( m_nVal < rhs.m_nVal );}
    friend ostream& operator<<(ostream& osIn, const CInt& rhs);

private:
    int m_nVal;
};

inline ostream& operator<<( ostream& osIn, const CInt& rhs )
{
    osIn << "CInt( " << rhs.m_nVal << " )";
    return osIn;
}

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
};

int main()
{
    // Comparing integers directly using the min algorithm with
    // binary predicate mod_lesser & with default less than
    int a = 6, b = -7, c = 7 ;
    const int& result1 = min ( a, b, mod_lesser );
    const int& result2 = min ( b, c );

    cout << "The mod_lesser of the integers 6 & -7 is: "
        << result1 << "." << endl;
    cout << "The lesser of the integers -7 & 7 is: "
        << result2 << "." << endl;
    cout << endl;

    // Comparing the members of an initializer_list
    const int& result3 = min({ a, c });
    const int& result4 = min({ a, b }, mod_lesser);

    cout << "The lesser of the integers 6 & 7 is: "
        << result3 << "." << endl;
    cout << "The mod_lesser of the integers 6 & -7 is: "
        << result4 << "." << endl;
    cout << endl;

    // Comparing set containers with elements of type CInt
    // using the min algorithm
    CInt c1 = 1, c2 = 2, c3 = 3;
    set<CInt> s1, s2, s3;
    set<CInt>::iterator s1_Iter, s2_Iter, s3_Iter;

    s1.insert ( c1 );
    s1.insert ( c2 );
    s2.insert ( c2 );
    s2.insert ( c3 );

    cout << "s1 = (";
    for ( s1_Iter = s1.begin( ); s1_Iter != --s1.end( ); s1_Iter++ )
        cout << " " << *s1_Iter << ",";
    s1_Iter = --s1.end( );
        cout << " " << *s1_Iter << " )." << endl;

    cout << "s2 = (";
    for ( s2_Iter = s2.begin( ); s2_Iter != --s2.end( ); s2_Iter++ )
        cout << " " << *s2_Iter << ",";
    s2_Iter = --s2.end( );
    cout << " " << *s2_Iter << " )." << endl;

    s3 = min ( s1, s2 );
    cout << "s3 = min ( s1, s2 ) = (";
    for ( s3_Iter = s3.begin( ); s3_Iter != --s3.end( ); s3_Iter++ )
        cout << " " << *s3_Iter << ",";
    s3_Iter = --s3.end( );
    cout << " " << *s3_Iter << " )." << endl << endl;

    // Comparing vectors with integer elements using min algorithm
    vector<int> v1, v2, v3, v4, v5;
    vector<int>::iterator Iter1, Iter2, Iter3, Iter4, Iter5;

    int i;
    for ( i = 0 ; i <= 2 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii = 0 ; ii <= 2 ; ii++ )
    {
        v2.push_back( ii );
    }

    int iii;
    for ( iii = 0 ; iii <= 2 ; iii++ )
    {
        v3.push_back( 2 * iii );
    }

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Vector v2 is ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    cout << "Vector v3 is ( " ;
    for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;

    v4 = min ( v1, v2 );
    v5 = min ( v1, v3 );

    cout << "Vector v4 = min ( v1,v2 ) is ( " ;
    for ( Iter4 = v4.begin( ) ; Iter4 != v4.end( ) ; Iter4++ )
        cout << *Iter4 << " ";
    cout << ")." << endl;

    cout << "Vector v5 = min ( v1,v3 ) is ( " ;
    for ( Iter5 = v5.begin( ) ; Iter5 != v5.end( ) ; Iter5++ )
        cout << *Iter5 << " ";
    cout << ")." << endl;
}
```

```Output
The mod_lesser of the integers 6 & -7 is: 6.
The lesser of the integers -7 & 7 is: -7.
The lesser of the integers 6 & 7 is: 6.The mod_lesser of the integers 6 & -7 is: 6.
s1 = ( CInt( 1 ), CInt( 2 ) ).
s2 = ( CInt( 2 ), CInt( 3 ) ).
s3 = min ( s1, s2 ) = ( CInt( 1 ), CInt( 2 ) ).

Vector v1 is ( 0 1 2 ).
Vector v2 is ( 0 1 2 ).
Vector v3 is ( 0 2 4 ).
Vector v4 = min ( v1,v2 ) is ( 0 1 2 ).
Vector v5 = min ( v1,v3 ) is ( 0 1 2 ).
```

## <a name="min_element"></a><a name="min_element"></a>min_element

Localiza a primeira ocorrência do menor elemento em um intervalo especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class ForwardIterator>
constexpr ForwardIterator min_element(
    ForwardIterator first,
    ForwardIterator last );

template<class ForwardIterator, class Compare>
constexpr ForwardIterator min_element(
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);

template<class ExecutionPolicy, class ForwardIterator>
ForwardIterator min_element(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class Compare>
ForwardIterator min_element(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento do intervalo no qual será pesquisado o menor elemento.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final do intervalo no qual o menor elemento será pesquisado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado de comparação usa dois argumentos e deve retornar **true** quando o primeiro elemento for menor do que o segundo elemento e **false** caso contrário.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que trata da posição da primeira ocorrência do menor elemento no intervalo pesquisado.

### <a name="remarks"></a>Comentários

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

A complexidade é linear: as `(last - first) - 1` comparações são necessárias para um intervalo não vazio.

### <a name="example"></a>Exemplo

```cpp
// alg_min_element.cpp
// compile with: /EHsc
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt
{
public:
    CInt( int n = 0 ) : m_nVal( n ){}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ){}
    CInt& operator=( const CInt& rhs ) {m_nVal =
    rhs.m_nVal; return *this;}
    bool operator<( const CInt& rhs ) const
        {return ( m_nVal < rhs.m_nVal );}
    friend ostream& operator<<( ostream& osIn, const CInt& rhs );

private:
    int m_nVal;
};

inline ostream& operator<<( ostream& osIn, const CInt& rhs )
{
    osIn << "CInt( " << rhs.m_nVal << " )";
    return osIn;
}

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
};

int main()
{
    // Searching a set container with elements of type CInt
    // for the minimum element
    CInt c1 = 1, c2 = 2, c3 = -3;
    set<CInt> s1;
    set<CInt>::iterator s1_Iter, s1_R1_Iter, s1_R2_Iter;

    s1.insert ( c1 );
    s1.insert ( c2 );
    s1.insert ( c3 );

    cout << "s1 = (";
    for ( s1_Iter = s1.begin( ); s1_Iter != --s1.end( ); s1_Iter++ )
        cout << " " << *s1_Iter << ",";
    s1_Iter = --s1.end( );
    cout << " " << *s1_Iter << " )." << endl;

    s1_R1_Iter = min_element ( s1.begin( ), s1.end( ) );

    cout << "The smallest element in s1 is: " << *s1_R1_Iter << endl;
    cout << endl;

    // Searching a vector with elements of type int for the maximum
    // element under default less than & mod_lesser binary predicates
    vector<int> v1;
    vector<int>::iterator v1_Iter, v1_R1_Iter, v1_R2_Iter;

    int i;
    for ( i = 0 ; i <= 3 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii = 1 ; ii <= 4 ; ii++ )
    {
        v1.push_back( - 2 * ii );
    }

    cout << "Vector v1 is ( " ;
    for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )
        cout << *v1_Iter << " ";
    cout << ")." << endl;

    v1_R1_Iter = min_element ( v1.begin( ), v1.end( ) );
    v1_R2_Iter = min_element ( v1.begin( ), v1.end( ), mod_lesser);

    cout << "The smallest element in v1 is: " << *v1_R1_Iter << endl;
    cout << "The smallest element in v1 under the mod_lesser"
        << "\n binary predicate is: " << *v1_R2_Iter << endl;
}
```

```Output
s1 = ( CInt( -3 ), CInt( 1 ), CInt( 2 ) ).
The smallest element in s1 is: CInt( -3 )

Vector v1 is ( 0 1 2 3 -2 -4 -6 -8 ).
The smallest element in v1 is: -8
The smallest element in v1 under the mod_lesser
binary predicate is: 0
```

## <a name="minmax_element"></a><a name="minmax_element"></a>minmax_element

Executa o trabalho realizado por `min_element` e `max_element` em uma chamada.

```cpp
template<class ForwardIterator>
constexpr pair<ForwardIterator, ForwardIterator> minmax_element(
    ForwardIterator first,
    ForwardIterator last);

template<class ForwardIterator, class Compare>
constexpr pair<ForwardIterator, ForwardIterator> minmax_element(
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);

template<class ExecutionPolicy, class ForwardIterator>
pair<ForwardIterator, ForwardIterator> minmax_element(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class Compare>
pair<ForwardIterator, ForwardIterator> minmax_element(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que indica o início de um intervalo.

*última*\
Um iterador de avanço que indica o final de um intervalo.

*Pred*\
Um objeto de função de predicado definido pelo usuário que define o sentido no qual um elemento é menor do que o outro. O predicado de comparação usa dois argumentos e deve retornar **true** quando o primeiro for menor que o segundo, e **false** caso contrário.

### <a name="return-value"></a>Valor retornado

Retornos

`pair<ForwardIterator, ForwardIterator>( min_element(first, last), max_element(first, last))`.

### <a name="remarks"></a>Comentários

Retorna a primeira função de modelo

`pair<ForwardIterator,ForwardIterator>(min_element(first,last), max_element(first,last))`.

A segunda função de modelo comporta-se da mesma forma, exceto que ela substitui `operator<(X, Y)` por `pred(X, Y)`.

Se a sequência não estiver vazia, a função executará comparações de “no máximo” `3 * (last - first - 1) / 2`.

## <a name="minmax"></a><a name="minmax"></a>por minMax

Compara dois parâmetros de entrada e retorna-os como um par, na ordem do menor para o maior.

```cpp
template<class Type>
constexpr pair<const Type&, const Type&> minmax(
    const Type& left,
    const Type& right);

template<class Type, class BinaryPredicate>
constexpr pair<const Type&, const Type&> minmax(
    const Type& left,
    const Type& right,
    BinaryPredicate pred);

template<class Type>
constexpr pair<Type&, Type&> minmax(
    initializer_list<Type> ilist);

template<class Type, class BinaryPredicate>
constexpr pair<Type&, Type&> minmax(
    initializer_list<Type> ilist,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
O primeiro dos dois objetos que estão sendo comparados.

*Certo*\
O segundo dos dois objetos que estão sendo comparados.

*Pred*\
Um predicado binário usado para comparar os dois objetos.

*inList*\
O `initializer_list` que contém os membros a serem comparados.

### <a name="remarks"></a>Comentários

A primeira função de modelo retorna `pair<const Type&, const Type&>( right, left )` se *Right* for menor que *Left*. Caso contrário, ele retornará `pair<const Type&, const Type&>( left, right )`.

A segunda função de membro retorna um par em que o primeiro elemento é menor e o segundo é o maior quando comparado pelo predicado *Pred*.

As funções de modelo restantes se comportam da mesma forma, exceto que substituem os parâmetros *esquerdo* e *direito* por *inList*.

A função executa exatamente uma comparação.

## <a name="mismatch"></a><a name="mismatch"></a>entre

Compara dois intervalos, elemento por elemento e localiza a primeira posição em que ocorre uma diferença.

Use as sobrecargas de intervalo duplo no código do C++14, porque as sobrecargas que usam apenas um único iterador para o segundo intervalo não detectarão as diferenças se o segundo intervalo for maior que o primeiro intervalo e resultarão em um comportamento indefinido se o segundo intervalo for menor que o primeiro intervalo.

```cpp
template<class InputIterator1, class InputIterator2>
pair<InputIterator1, InputIterator2>>
mismatch(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2 );

template<class InputIterator1, class InputIterator2, class BinaryPredicate> pair<InputIterator1, InputIterator2>>
mismatch(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    BinaryPredicate pred );

//C++14
template<class InputIterator1, class InputIterator2>
pair<InputIterator1, InputIterator2>>
mismatch(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2 );

template<class InputIterator1, class InputIterator2, class BinaryPredicate> pair<InputIterator1, InputIterator2>>
mismatch(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    BinaryPredicate pred);

//C++17
template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
pair<ForwardIterator1, ForwardIterator2>
mismatch(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
pair<ForwardIterator1, ForwardIterator2>
mismatch(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
pair<ForwardIterator1, ForwardIterator2>
mismatch(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
pair<ForwardIterator1, ForwardIterator2>
mismatch(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro intervalo a ser testado.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro intervalo a ser testado.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo a ser testado.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo intervalo a ser testado.

*Pred*\
Objeto de função de predicado definido pelo usuário que compara os elementos atuais em cada intervalo e determina se eles são equivalentes. Retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um par de iteradores que tratam das posições da incompatibilidade nos dois intervalos, o primeiro iterador de componente para a posição no primeiro intervalo e o segundo iterador de componente para a posição no segundo intervalo. Se não houver nenhuma diferença entre os elementos nos intervalos comparados ou se o predicado binário na segunda versão for atendido por todos os pares de elementos dos dois intervalos, o primeiro iterador de componente apontará para a posição logo após o elemento final no primeiro intervalo e o segundo iterador de componente para a posição logo após o elemento final testado no segundo intervalo.

### <a name="remarks"></a>Comentários

A primeira função de modelo assume que há tantos elementos no intervalo que começa em first2 quantos há no intervalo designado por [first1, last1). Se houver mais no segundo intervalo, eles serão ignorados; Se houver menos, o comportamento indefinido será resultado.

O intervalo a ser pesquisado deve ser válido, todos os iteradores devem ser desreferenciáveis e a última posição deve ser acessível desde a primeira por incrementação.

A complexidade de tempo do algoritmo é linear no número de elementos contidos no intervalo mais curto.

O predicado definido pelo usuário não é necessário para impor uma relação de equivalência que seja simétrica, reflexiva e transitiva entre seus operandos.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar a incompatibilidade. A sobrecarga do C++03 é mostrada apenas para demonstrar como ele pode produzir um resultado inesperado.

```cpp
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Return whether first element is twice the second
// Note that this is not a symmetric, reflexive and transitive equivalence.
// mismatch and equal accept such predicates, but is_permutation does not.
bool twice(int elem1, int elem2)
{
    return elem1 == elem2 * 2;
}

void PrintResult(const string& msg, const pair<vector<int>::iterator, vector<int>::iterator>& result,
    const vector<int>& left, const vector<int>& right)
{
    // If either iterator stops before reaching the end of its container,
    // it means a mismatch was detected.
    if (result.first != left.end() || result.second != right.end())
    {
        string leftpos(result.first == left.end() ? "end" : to_string(*result.first));
        string rightpos(result.second == right.end() ? "end" : to_string(*result.second));
        cout << msg << "mismatch. Left iterator at " << leftpos
            << " right iterator at " << rightpos << endl;
    }
    else
    {
        cout << msg << " match." << endl;
    }
}

int main()
{

    vector<int> vec_1{ 0, 5, 10, 15, 20, 25 };
    vector<int> vec_2{ 0, 5, 10, 15, 20, 25, 30 };

    // Testing different length vectors for mismatch (C++03)
    auto match_vecs = mismatch(vec_1.begin(), vec_1.end(), vec_2.begin());
    bool is_mismatch = match_vecs.first != vec_1.end();
    cout << "C++03: vec_1 and vec_2 are a mismatch: " << boolalpha << is_mismatch << endl;

    // Using dual-range overloads:

    // Testing different length vectors for mismatch (C++14)
    match_vecs = mismatch(vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.end());
    PrintResult("C++14: vec_1 and vec_2: ", match_vecs, vec_1, vec_2);

    // Identify point of mismatch between vec_1 and modified vec_2.
    vec_2[3] = 42;
    match_vecs = mismatch(vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.end());
    PrintResult("C++14 vec_1 v. vec_2 modified: ", match_vecs, vec_1, vec_2);

    // Test vec_3 and vec_4 for mismatch under the binary predicate twice (C++14)
    vector<int> vec_3{ 10, 20, 30, 40, 50, 60 };
    vector<int> vec_4{ 5, 10, 15, 20, 25, 30 };
    match_vecs = mismatch(vec_3.begin(), vec_3.end(), vec_4.begin(), vec_4.end(), twice);
    PrintResult("vec_3 v. vec_4 with pred: ", match_vecs, vec_3, vec_4);

    vec_4[5] = 31;
    match_vecs = mismatch(vec_3.begin(), vec_3.end(), vec_4.begin(), vec_4.end(), twice);
    PrintResult("vec_3 v. modified vec_4 with pred: ", match_vecs, vec_3, vec_4);

    // Compare a vector<int> to a list<int>
    list<int> list_1{ 0, 5, 10, 15, 20, 25 };
    auto match_vec_list = mismatch(vec_1.begin(), vec_1.end(), list_1.begin(), list_1.end());
    is_mismatch = match_vec_list.first != vec_1.end() || match_vec_list.second != list_1.end();
    cout << "vec_1 and list_1 are a mismatch: " << boolalpha << is_mismatch << endl;

    char c;
    cout << "Press a key" << endl;
    cin >> c;

}
```

```Output
C++03: vec_1 and vec_2 are a mismatch: false
C++14: vec_1 and vec_2: mismatch. Left iterator at end right iterator at 30
C++14 vec_1 v. vec_2 modified: mismatch. Left iterator at 15 right iterator at 42
C++14 vec_3 v. vec_4 with pred: match.
C++14 vec_3 v. modified vec_4 with pred: mismatch. Left iterator at 60 right iterator at 31
C++14: vec_1 and list_1 are a mismatch: false
Press a key
```

## <a name="ltalggt-move"></a><a name="alg_move"></a> &lt;alg&gt; move

Move elementos associados a um intervalo especificado.

```cpp
template<class InputIterator, class OutputIterator>
OutputIterator move(
    InputIterator first,
    InputIterator last,
    OutputIterator dest);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 move(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica onde começa o intervalo de elementos a ser movido.

*última*\
Um iterador de entrada que indica o final de um intervalo de elementos a ser movido.

*dest*\
O iterador de saída que deve conter os elementos movidos.

### <a name="remarks"></a>Comentários

A função de modelo avalia `*(dest + N) = move(*(first + N))` uma vez para cada `N` no intervalo `[0, last - first)`, para aumentar estritamente os valores de `N`, começando com o valor mais baixo. Em seguida, ele retorna `dest + N`. Se `dest` e *primeiro* designar regiões de armazenamento, *dest* não deve estar no intervalo `[first, last)` .

## <a name="move_backward"></a><a name="move_backward"></a>move_backward

Move os elementos de um iterador para outro. O movimento inicia com o último elemento em um intervalo especificado e termina com o primeiro elemento desse intervalo.

```cpp
template<class BidirectionalIterator1, class BidirectionalIterator2>
BidirectionalIterator2 move_backward(
    BidirectionalIterator1 first,
    BidirectionalIterator1 last,
    BidirectionalIterator2 destEnd);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador que indica o início de um intervalo do qual elementos serão movidos.

*última*\
Um iterador que indica o final de um intervalo do qual elementos serão movidos. Esse elemento não é movido.

*destEnd*\
Um iterador bidirecional que trata da posição que está logo atrás do elemento final no intervalo de destino.

### <a name="remarks"></a>Comentários

A função de modelo avalia `*(destEnd - N - 1) = move(*(last - N - 1))` uma vez para cada `N` no intervalo `[0, last - first)`, para aumentar estritamente os valores de `N`, começando com o valor mais baixo. Em seguida, ele retorna `destEnd - (last - first)`. Se *destEnd* e *primeiro* designar regiões de armazenamento, *destEnd* não deverá estar no intervalo `[first, last)` .

`move` e `move_backward` são funcionalmente equivalentes ao uso de `copy` e `copy_backward` com um iterador de movimentação.

## <a name="next_permutation"></a><a name="next_permutation"></a>next_permutation

Reordena os elementos em um intervalo para que a ordenação original seja substituída pela próxima permutação lexicograficamente maior, se ela existir, em que o sentido de próxima pode ser especificado com um predicado binário.

```cpp
template<class BidirectionalIterator>
bool next_permutation(
    BidirectionalIterator first,
    BidirectionalIterator last);

template<class BidirectionalIterator, class BinaryPredicate>
bool next_permutation(
    BidirectionalIterator first,
    BidirectionalIterator last,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador bidirecional que aponta para a posição do primeiro elemento no intervalo a ser permutado.

*última*\
Um iterador bidirecional que aponta para uma posição após o elemento final no intervalo para ser permutado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

**true** se a lexicograficamente próxima permutação existir e tiver substituído a ordem original do intervalo, caso contrário, **false**, quando a ordenação é transformada na permutação lexicograficamente menor.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

O predicado binário padrão é menor que e os elementos no intervalo devem ser menores que comparáveis para garantir que a próxima permutação seja bem definida.

A complexidade é linear com no máximo as `(last - first) / 2` trocas.

### <a name="example"></a>Exemplo

```cpp
// alg_next_perm.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt
{
public:
    CInt( int n = 0 ) : m_nVal( n ) {}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ) {}
    CInt& operator=( const CInt& rhs ) {m_nVal =
        rhs.m_nVal; return *this;}
    bool operator<( const CInt& rhs ) const
        { return ( m_nVal < rhs.m_nVal ); }
    friend ostream& operator<<( ostream& osIn, const CInt& rhs );

private:
    int m_nVal;
};

inline ostream& operator<<( ostream& osIn, const CInt& rhs )
{
    osIn << "CInt( " << rhs.m_nVal << " )";
    return osIn;
}

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
};

int main()
{
    // Reordering the elements of type CInt in a deque
    // using the prev_permutation algorithm
    CInt c1 = 5, c2 = 1, c3 = 10;
    bool deq1Result;
    deque<CInt> deq1, deq2, deq3;
    deque<CInt>::iterator d1_Iter;

    deq1.push_back ( c1 );
    deq1.push_back ( c2 );
    deq1.push_back ( c3 );

    cout << "The original deque of CInts is deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl;

    deq1Result = next_permutation ( deq1.begin( ), deq1.end( ) );

    if ( deq1Result )
        cout << "The lexicographically next permutation "
            << "exists and has\nreplaced the original "
            << "ordering of the sequence in deq1." << endl;
    else
        cout << "The lexicographically next permutation doesn't "
            << "exist\n and the lexicographically "
            << "smallest permutation\n has replaced the "
            << "original ordering of the sequence in deq1." << endl;

    cout << "After one application of next_permutation,\n deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl << endl;

    // Permuting vector elements with binary function mod_lesser
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = -3 ; i <= 3 ; i++ )
    {
        v1.push_back( i );
    }

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    next_permutation ( v1.begin( ), v1.end( ), mod_lesser );

    cout << "After the first next_permutation, vector v1 is:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    int iii = 1;
    while ( iii <= 5 ) {
        next_permutation ( v1.begin( ), v1.end( ), mod_lesser );
        cout << "After another next_permutation of vector v1,\n v1 =   ( " ;
        for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ;Iter1 ++ )
            cout << *Iter1 << " ";
        cout << ")." << endl;
        iii++;
    }
}
```

```Output
The original deque of CInts is deq1 = ( CInt( 5 ), CInt( 1 ), CInt( 10 ) ).
The lexicographically next permutation exists and has
replaced the original ordering of the sequence in deq1.
After one application of next_permutation,
deq1 = ( CInt( 5 ), CInt( 10 ), CInt( 1 ) ).

Vector v1 is ( -3 -2 -1 0 1 2 3 ).
After the first next_permutation, vector v1 is:
v1 = ( -3 -2 -1 0 1 3 2 ).
After another next_permutation of vector v1,
v1 =   ( -3 -2 -1 0 2 1 3 ).
After another next_permutation of vector v1,
v1 =   ( -3 -2 -1 0 2 3 1 ).
After another next_permutation of vector v1,
v1 =   ( -3 -2 -1 0 3 1 2 ).
After another next_permutation of vector v1,
v1 =   ( -3 -2 -1 0 3 2 1 ).
After another next_permutation of vector v1,
v1 =   ( -3 -2 -1 1 0 2 3 ).
```

## <a name="nth_element"></a><a name="nth_element"></a>nth_element

Particiona um intervalo de elementos, localizando corretamente o *n*° elemento da sequência no intervalo para que todos os elementos na frente dele sejam menores ou iguais a ele e que todos os elementos que o seguem na sequência sejam maiores ou iguais a ele.

```cpp
template<class RandomAccessIterator>
void nth_element(
    RandomAccessIterator first,
    RandomAccessIterator nth,
    RandomAccessIterator last);

template<class RandomAccessIterator, class Compare>
void nth_element(
    RandomAccessIterator first,
    RandomAccessIterator nth,
    RandomAccessIterator last,
    Compare pred);

template<class ExecutionPolicy, class RandomAccessIterator>
void nth_element(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator nth,
    RandomAccessIterator last);

template<class ExecutionPolicy, class RandomAccessIterator, class Compare>
void nth_element(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator nth,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser particionado.

*enésimo*\
Um iterador de acesso aleatório que trata da posição do elemento a ser ordenado corretamente no limite da partição.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser particionado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Um predicado de comparação usa dois argumentos e retorna **true** quando satisfeito e **falso** quando não estiver satisfeito.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

O `nth_element` algoritmo não garante que os elementos nos subintervalos de qualquer lado do elemento *n*-ésimo sejam classificados. Portanto, ele dá menos garantias do que `partial_sort`, que ordena os elementos no intervalo abaixo de algum elemento escolhido e pode ser usado como uma alternativa mais rápida que `partial_sort` quando a ordenação do intervalo inferior não é necessária.

Os elementos são equivalentes, mas não necessariamente iguais, quando nenhum é menor que o outro.

A média de uma complexidade de classificação é linear em relação ao *último-primeiro*.

### <a name="example"></a>Exemplo

```cpp
// alg_nth_elem.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether first element is greater than the second
bool UDgreater ( int elem1, int elem2 ) {
    return elem1 > elem2;
}

int main() {
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
        v1.push_back( 3 * i );

    int ii;
    for ( ii = 0 ; ii <= 5 ; ii++ )
        v1.push_back( 3 * ii + 1 );

    int iii;
    for ( iii = 0 ; iii <= 5 ; iii++ )
        v1.push_back( 3 * iii +2 );

    cout << "Original vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    nth_element(v1.begin( ), v1.begin( ) + 3, v1.end( ) );
    cout << "Position 3 partitioned vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // To sort in descending order, specify binary predicate
    nth_element( v1.begin( ), v1.begin( ) + 4, v1.end( ),
            greater<int>( ) );
    cout << "Position 4 partitioned (greater) vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    random_shuffle( v1.begin( ), v1.end( ) );
    cout << "Shuffled vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // A user-defined (UD) binary predicate can also be used
    nth_element( v1.begin( ), v1.begin( ) + 5, v1.end( ), UDgreater );
    cout << "Position 5 partitioned (UDgreater) vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;
}
```

## <a name="none_of"></a><a name="none_of"></a>none_of

Retorna **true** quando uma condição nunca está presente entre os elementos no intervalo especificado.

```cpp
template<class InputIterator, class UnaryPredicate>
bool none_of(
    InputIterator first,
    InputIterator last,
    UnaryPredicate pred);

template <class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
bool none_of(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica onde começar a verificar um intervalo de elementos quanto a uma condição.

*última*\
Um iterador de entrada que indica o final de um intervalo de elementos.

*Pred*\
A condição a ser testada. Ela é fornecida por um objeto de função de predicado definido pelo usuário que define a condição. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retornará **true** se a condição não for detectada pelo menos uma vez no intervalo indicado e **false** se a condição for detectada.

### <a name="remarks"></a>Comentários

A função de modelo retornará **true** somente se, para alguns `N` no intervalo `[0, last - first)` , o predicado `pred(*(first + N))` for sempre **false**.

## <a name="partial_sort"></a><a name="partial_sort"></a>partial_sort

Organiza um número especificado de elementos menores em um intervalo em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.

```cpp
template<class RandomAccessIterator>
void partial_sort(
    RandomAccessIterator first,
    RandomAccessIterator sortEnd,
    RandomAccessIterator last);

template<class RandomAccessIterator, class Compare>
void partial_sort(
    RandomAccessIterator first,
    RandomAccessIterator sortEnd,
    RandomAccessIterator last
    Compare pred);

template<class ExecutionPolicy, class RandomAccessIterator>
void partial_sort(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator middle,
    RandomAccessIterator last);

template<class ExecutionPolicy, class RandomAccessIterator, class Compare>
void partial_sort(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator middle,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*sortEnd*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no subintervalo a ser classificado.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado parcialmente.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Os elementos são equivalentes, mas não necessariamente iguais, quando nenhum é menor que o outro. O `sort` algoritmo não é estável e não garante que a ordenação relativa de elementos equivalentes será preservada. O algoritmo `stable_sort` preserva essa ordenação original.

A complexidade média de classificação parcial é *O*(( `last` -  `first` ) log ( `sortEnd` -  `first` )).

### <a name="example"></a>Exemplo

```cpp
// alg_partial_sort.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether first element is greater than the second
bool UDgreater ( int elem1, int elem2 )
{
    return elem1 > elem2;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 2 * i );
    }

    int ii;
    for ( ii = 0 ; ii <= 5 ; ii++ )
    {
        v1.push_back( 2 * ii +1 );
    }

    cout << "Original vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    partial_sort(v1.begin( ), v1.begin( ) + 6, v1.end( ) );
    cout << "Partially sorted vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // To partially sort in descending order, specify binary predicate
    partial_sort(v1.begin( ), v1.begin( ) + 4, v1.end( ), greater<int>( ) );
    cout << "Partially resorted (greater) vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // A user-defined (UD) binary predicate can also be used
    partial_sort(v1.begin( ), v1.begin( ) + 8, v1.end( ), UDgreater );
    cout << "Partially resorted (UDgreater) vector:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;
}
```

```Output
Original vector:
v1 = ( 0 2 4 6 8 10 1 3 5 7 9 11 )
Partially sorted vector:
v1 = ( 0 1 2 3 4 5 10 8 6 7 9 11 )
Partially resorted (greater) vector:
v1 = ( 11 10 9 8 0 1 2 3 4 5 6 7 )
Partially resorted (UDgreater) vector:
v1 = ( 11 10 9 8 7 6 5 4 0 1 2 3 )
```

## <a name="partial_sort_copy"></a><a name="partial_sort_copy"></a>partial_sort_copy

Copia elementos de um intervalo de origem em um intervalo de destino, em que os elementos de origem são ordenados por menor que ou outro predicado binário especificado.

```cpp
template<class InputIterator, class RandomAccessIterator>
RandomAccessIterator partial_sort_copy(
    InputIterator first1,
    InputIterator last1,
    RandomAccessIterator first2,
    RandomAccessIterator last2 );

template<class InputIterator, class RandomAccessIterator, class Compare>
RandomAccessIterator partial_sort_copy(
    InputIterator first1,
    InputIterator last1,
    RandomAccessIterator first2,
    RandomAccessIterator last2,
    Compare pred);

template<class ExecutionPolicy, class ForwardIterator, class RandomAccessIterator>
RandomAccessIterator partial_sort_copy(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    RandomAccessIterator result_first,
    RandomAccessIterator result_last);

template<class ExecutionPolicy, class ForwardIterator, class RandomAccessIterator, class Compare>
RandomAccessIterator partial_sort_copy(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    RandomAccessIterator result_first,
    RandomAccessIterator result_last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no intervalo de origem.

*last1*\
Um iterador de entrada que trata da posição logo após o elemento final no intervalo de origem.

*first2*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo de destino classificado.

*last2*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo de destino classificado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador de acesso aleatório que trata do elemento no intervalo de destino, uma posição após o último elemento inserido do intervalo de origem.

### <a name="remarks"></a>Comentários

Os intervalos de origem e de destino não devem se sobrepor e devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

O predicado binário deve fornecer uma ordenação fraca estrita para que os elementos que não são equivalentes sejam ordenados, mas os elementos que são equivalentes não sejam. Dois elementos são equivalentes quanto a “menor que”, mas não são necessariamente iguais, quando nenhum é menor que o outro.

### <a name="example"></a>Exemplo

```cpp
// alg_partial_sort_copy.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iostream>

int main() {
    using namespace std;
    vector<int> v1, v2;
    list<int> list1;
    vector<int>::iterator iter1, iter2;
    list<int>::iterator list1_Iter, list1_inIter;

    int i;
    for (i = 0; i <= 9; i++)
        v1.push_back(i);

    random_shuffle(v1.begin(), v1.end());

    list1.push_back(60);
    list1.push_back(50);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);
    list1.push_back(10);

    cout << "Vector v1 = ( " ;
    for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
        cout << *iter1 << " ";
    cout << ")" << endl;

    cout << "List list1 = ( " ;
    for (list1_Iter = list1.begin();
         list1_Iter!= list1.end();
         list1_Iter++)
        cout << *list1_Iter << " ";
    cout << ")" << endl;

    // Copying a partially sorted copy of list1 into v1
    vector<int>::iterator result1;
    result1 = partial_sort_copy(list1.begin(), list1.end(),
             v1.begin(), v1.begin() + 3);

    cout << "List list1 Vector v1 = ( " ;
    for (iter1 = v1.begin() ; iter1 != v1.end() ; iter1++)
        cout << *iter1 << " ";
    cout << ")" << endl;
    cout << "The first v1 element one position beyond"
         << "\n the last L 1 element inserted was " << *result1
         << "." << endl;

    // Copying a partially sorted copy of list1 into v2
    int ii;
    for (ii = 0; ii <= 9; ii++)
        v2.push_back(ii);

    random_shuffle(v2.begin(), v2.end());
    vector<int>::iterator result2;
    result2 = partial_sort_copy(list1.begin(), list1.end(),
             v2.begin(), v2.begin() + 6);

    cout << "List list1 into Vector v2 = ( " ;
    for (iter2 = v2.begin() ; iter2 != v2.end(); iter2++)
        cout << *iter2 << " ";
    cout << ")" << endl;
    cout << "The first v2 element one position beyond"
         << "\n the last L 1 element inserted was " << *result2
         << "." << endl;
}
```

## <a name="partition"></a><a name="partition"></a>particion

Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem.

```cpp
template<class BidirectionalIterator, class UnaryPredicate>
BidirectionalIterator partition(
    BidirectionalIterator first,
    BidirectionalIterator last,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
ForwardIterator partition(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador bidirecional que trata da posição do primeiro elemento no intervalo a ser particionado.

*última*\
Um iterador bidirecional que trata da posição logo após o elemento final no intervalo a ser particionado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define a condição a ser atendida se um elemento precisar ser classificado. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional que trata da posição do primeiro elemento no intervalo que não atende à condição do predicado.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Os elementos *a* e *b* são equivalentes, mas não necessariamente iguais, se ambos `pred( a, b )` for false e `pred( b, a )` for false, em que *Pred* é o predicado especificado pelo parâmetro. O `partition` algoritmo não é estável e não garante que a ordenação relativa de elementos equivalentes será preservada. O algoritmo `stable_partition` preserva essa ordenação original.

A complexidade é linear: há `(last - first)` aplicativos de *Pred* e na maioria das `(last - first)/2` trocas.

### <a name="example"></a>Exemplo

```cpp
// alg_partition.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

bool greater5 ( int value )
{
    return value > 5;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 0 ; i <= 10 ; i++ )
    {
        v1.push_back( i );
    }
    random_shuffle( v1.begin( ), v1.end( ) );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Partition the range with predicate greater10
    partition ( v1.begin( ), v1.end( ), greater5 );
    cout << "The partitioned set of elements in v1 is: ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="partition_copy"></a><a name="partition_copy"></a>partition_copy

Copia os elementos para os quais uma condição é **verdadeira** para um destino e para o qual a condição é **falsa** para outra. Os elementos devem vir de um intervalo especificado.

```cpp
template<class InputIterator, class OutputIterator1, class OutputIterator2, class UnaryPredicate>
pair<OutputIterator1, OutputIterator2> partition_copy(
    InputIterator first,
    InputIterator last,
    OutputIterator1 dest1,
    OutputIterator2 dest2,
    UnaryPredicate pred);

template <class ExecutionPolicy, class ForwardIterator, class ForwardIterator1, class ForwardIterator2, class UnaryPredicate>
pair<ForwardIterator1, ForwardIterator2> partition_copy(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    ForwardIterator1 out_true,
    ForwardIterator2 out_false,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que indica o início de um intervalo no qual uma condição será verificada.

*última*\
Um iterador de entrada que indica o final de um intervalo.

*dest1*\
Um iterador de saída usado para copiar elementos que retornam true para uma condição testada usando *Pred*.

*dest2*\
Um iterador de saída usado para copiar elementos que retornam false para uma condição testada usando *Pred*.

*Pred*\
A condição a ser testada. Ela é fornecida por um objeto de função de predicado definido pelo usuário que define a condição a ser testada. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="remarks"></a>Comentários

A função de modelo copia cada elemento `X` de `[first,last)` para `*dest1++` se `pred(X)` for true ou para `*dest2++` se não. Ele retorna `pair<OutputIterator1, OutputIterator2>(dest1, dest2)`.

## <a name="partition_point"></a><a name="partition_point"></a>partition_point

Retorna o primeiro elemento no intervalo fornecido que não atende à condição. Os elementos são armazenados para que aqueles que atendem à condição venham antes daqueles que não atendem.

```cpp
template<class ForwardIterator, class UnaryPredicate>
ForwardIterator partition_point(
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um `ForwardIterator` que indica o início de um intervalo no qual uma condição será verificada.

*última*\
Um `ForwardIterator` que indica o final de um intervalo.

*Pred*\
A condição a ser testada. Ela é fornecida por um objeto de função de predicado definido pelo usuário que define a condição a ser atendida pelo elemento que está sendo pesquisado. Um predicado unário usa um único argumento e retorna **true** ou **false**.

### <a name="return-value"></a>Valor retornado

Retorna um `ForwardIterator` que se refere ao primeiro elemento que não preenche a condição testada por *Pred*, ou retorna *Last* se um não for encontrado.

### <a name="remarks"></a>Comentários

A função de modelo localiza o primeiro iterador `it` no `[first, last)` para o qual `pred(*it)` é **false**. A sequência deve ser ordenada por *Pred*.

## <a name="pop_heap"></a><a name="pop_heap"></a>pop_heap

Remove o maior elemento da frente de um heap para a penúltima posição no intervalo e, em seguida, forma um novo heap com os elementos restantes.

```cpp
template<class RandomAccessIterator>
void pop_heap(
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class RandomAccessIterator, class BinaryPredicate>
void pop_heap(
    RandomAccessIterator first,
    RandomAccessIterator last,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no heap.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no heap.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="remarks"></a>Comentários

O algoritmo `pop_heap` é o inverso da operação executada pelo algoritmo push_heap, no qual um elemento na posição ao lado da última de um intervalo é adicionado a um heap que consiste nos elementos anteriores do intervalo, quando o elemento que está sendo adicionado ao heap é maior do que cada um dos elementos que já estão no heap.

Os heaps têm duas propriedades:

- O primeiro elemento sempre é o maior.

- Elementos podem ser adicionados ou removidos em tempo logarítmico.

Os heaps são a maneira ideal de implementar filas de prioridade e são usados na implementação da [Classe priority_queue](priority-queue-class.md) do adaptador de contêiner da Biblioteca Padrão do C++.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

O intervalo que exclui o elemento recém-adicionado ao final deve ser um heap.

A complexidade é logarítmica, exigindo no máximo `log (last - first)` comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_pop_heap.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 1 ; i <= 9 ; i++ )
        v1.push_back( i );

    // Make v1 a heap with default less than ordering
    random_shuffle( v1.begin( ), v1.end( ) );
    make_heap ( v1.begin( ), v1.end( ) );
    cout << "The heaped version of vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Add an element to the back of the heap
    v1.push_back( 10 );
    push_heap( v1.begin( ), v1.end( ) );
    cout << "The reheaped v1 with 10 added is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Remove the largest element from the heap
    pop_heap( v1.begin( ), v1.end( ) );
    cout << "The heap v1 with 10 removed is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl << endl;

    // Make v1 a heap with greater-than ordering with a 0 element
    make_heap ( v1.begin( ), v1.end( ), greater<int>( ) );
    v1.push_back( 0 );
    push_heap( v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "The 'greater than' reheaped v1 puts the smallest "
        << "element first:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Application of pop_heap to remove the smallest element
    pop_heap( v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "The 'greater than' heaped v1 with the smallest element\n "
        << "removed from the heap is: ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="prev_permutation"></a><a name="prev_permutation"></a>prev_permutation

Reordena os elementos em um intervalo para que a ordenação original seja substituída pela permutação lexicograficamente maior anterior caso exista, em que o sentido de anterior pode ser especificado com um predicado binário.

```cpp
template<class BidirectionalIterator>
bool prev_permutation(
    BidirectionalIterator first,
    BidirectionalIterator last);

template<class BidirectionalIterator, class BinaryPredicate>
bool prev_permutation(
    BidirectionalIterator first,
    BidirectionalIterator last,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador bidirecional que aponta para a posição do primeiro elemento no intervalo a ser permutado.

*última*\
Um iterador bidirecional que aponta para uma posição após o elemento final no intervalo para ser permutado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

**true** se a permutação anterior do modo lexicográfico existir e tiver substituído a ordenação original do intervalo; caso contrário, **false**, caso em que a ordem é transformada na maior permutação modo lexicográfico.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

O predicado binário padrão é menor que e os elementos no intervalo devem ser menores do que o comparável para garantir que a permutação anterior seja bem definida.

A complexidade é linear, com no máximo ( `last`  -  `first` )/2 trocas.

### <a name="example"></a>Exemplo

```cpp
// alg_prev_perm.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;
class CInt;
ostream& operator<<( ostream& osIn, const CInt& rhs );

class CInt {
public:
    CInt( int n = 0 ) : m_nVal( n ){}
    CInt( const CInt& rhs ) : m_nVal( rhs.m_nVal ){}
    CInt&   operator=( const CInt& rhs ) {m_nVal =
    rhs.m_nVal; return *this;}
    bool operator<( const CInt& rhs ) const
        {return ( m_nVal < rhs.m_nVal );}
    friend ostream& operator<<( ostream& osIn, const CInt& rhs );

private:
    int m_nVal;
};

inline ostream& operator<<( ostream& osIn, const CInt& rhs ) {
    osIn << "CInt( " << rhs.m_nVal << " )";
    return osIn;
}

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser (int elem1, int elem2 ) {
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
};

int main()
{
    // Reordering the elements of type CInt in a deque
    // using the prev_permutation algorithm
    CInt c1 = 1, c2 = 5, c3 = 10;
    bool deq1Result;
    deque<CInt> deq1, deq2, deq3;
    deque<CInt>::iterator d1_Iter;

    deq1.push_back ( c1 );
    deq1.push_back ( c2 );
    deq1.push_back ( c3 );

    cout << "The original deque of CInts is deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl;

    deq1Result = prev_permutation ( deq1.begin( ), deq1.end( ) );

    if ( deq1Result )
        cout << "The lexicographically previous permutation "
            << "exists and has \nreplaced the original "
            << "ordering of the sequence in deq1." << endl;
    else
        cout << "The lexicographically previous permutation doesn't "
            << "exist\n and the lexicographically "
            << "smallest permutation\n has replaced the "
            << "original ordering of the sequence in deq1." << endl;

    cout << "After one application of prev_permutation,\n deq1 = (";
    for ( d1_Iter = deq1.begin( ); d1_Iter != --deq1.end( ); d1_Iter++ )
        cout << " " << *d1_Iter << ",";
    d1_Iter = --deq1.end( );
    cout << " " << *d1_Iter << " )." << endl << endl;

    // Permutating vector elements with binary function mod_lesser
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = -3 ; i <= 3 ; i++ )
        v1.push_back( i );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    prev_permutation ( v1.begin( ), v1.end( ), mod_lesser );

    cout << "After the first prev_permutation, vector v1 is:\n v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    int iii = 1;
    while ( iii <= 5 ) {
        prev_permutation ( v1.begin( ), v1.end( ), mod_lesser );
        cout << "After another prev_permutation of vector v1,\n v1 =   ( " ;
        for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ;Iter1 ++ )
            cout << *Iter1 << " ";
        cout << ")." << endl;
        iii++;
    }
}
```

```Output
The original deque of CInts is deq1 = ( CInt( 1 ), CInt( 5 ), CInt( 10 ) ).
The lexicographically previous permutation doesn't exist
and the lexicographically smallest permutation
has replaced the original ordering of the sequence in deq1.
After one application of prev_permutation,
deq1 = ( CInt( 10 ), CInt( 5 ), CInt( 1 ) ).

Vector v1 is ( -3 -2 -1 0 1 2 3 ).
After the first prev_permutation, vector v1 is:
v1 = ( -3 -2 0 3 2 1 -1 ).
After another prev_permutation of vector v1,
v1 =   ( -3 -2 0 3 -1 2 1 ).
After another prev_permutation of vector v1,
v1 =   ( -3 -2 0 3 -1 1 2 ).
After another prev_permutation of vector v1,
v1 =   ( -3 -2 0 2 3 1 -1 ).
After another prev_permutation of vector v1,
v1 =   ( -3 -2 0 2 -1 3 1 ).
After another prev_permutation of vector v1,
v1 =   ( -3 -2 0 2 -1 1 3 ).
```

## <a name="push_heap"></a><a name="push_heap"></a>push_heap

Adiciona um elemento que está no fim de um intervalo a um heap existente que consiste em elementos anteriores no intervalo.

```cpp
template<class RandomAccessIterator>
void push_heap(
    RandomAccessIterator first,
    RandomAccessIterator last );

template<class RandomAccessIterator, class BinaryPredicate>
void push_heap(
    RandomAccessIterator first,
    RandomAccessIterator last,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no heap.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser convertido em um heap.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="remarks"></a>Comentários

O elemento deve primeiro ser enviado de volta ao final de um heap existente e, em seguida, o algoritmo será usado para adicionar esse elemento ao heap existente.

Os heaps têm duas propriedades:

- O primeiro elemento sempre é o maior.

- Elementos podem ser adicionados ou removidos em tempo logarítmico.

Os heaps são a maneira ideal de implementar filas de prioridade e são usados na implementação da [Classe priority_queue](priority-queue-class.md) do adaptador de contêiner da Biblioteca Padrão do C++.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

O intervalo que exclui o elemento recém-adicionado ao final deve ser um heap.

A complexidade é logarítmica, exigindo no máximo `log(last - first)` comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_push_heap.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main() {
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 1 ; i <= 9 ; i++ )
        v1.push_back( i );

    random_shuffle( v1.begin( ), v1.end( ) );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Make v1 a heap with default less than ordering
    make_heap ( v1.begin( ), v1.end( ) );
    cout << "The heaped version of vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Add an element to the heap
    v1.push_back( 10 );
    cout << "The heap v1 with 10 pushed back is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    push_heap( v1.begin( ), v1.end( ) );
    cout << "The reheaped v1 with 10 added is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl << endl;

    // Make v1 a heap with greater than ordering
    make_heap ( v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "The greater-than heaped version of v1 is\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    v1.push_back(0);
    cout << "The greater-than heap v1 with 11 pushed back is\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    push_heap( v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "The greater than reheaped v1 with 11 added is\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="random_shuffle"></a><a name="random_shuffle"></a>random_shuffle

A função std:: random_shuffle () foi preterida, substituída por [std:: ordem aleatória](algorithm-functions.md#shuffle). Para obter um exemplo de código e mais informações, consulte [\<random>](random.md) e o Stack Overflow postar [por que os métodos std:: random_shuffle estão sendo preteridos no c++ 14?](https://go.microsoft.com/fwlink/p/?linkid=397954).

## <a name="remove"></a><a name="remove"></a>exclu

Elimina um valor especificado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.

```cpp
template<class ForwardIterator, class Type>
ForwardIterator remove(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class Type>
ForwardIterator remove(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento no intervalo do qual os elementos estão sendo removidos.

*última*\
Um iterador de avanço que da primeira posição após o elemento final no intervalo do qual os elementos estão sendo removidos.

*valor*\
O valor a ser removido do intervalo.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que trata da nova posição final do intervalo modificado, uma posição após o elemento final da sequência excedente livre do valor especificado.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A ordem dos elementos não removidos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear; Há () comparações `last`  -  `first` para igualdade.

A [classe List](list-class.md) tem uma versão de função membro mais eficiente do `remove` , que também vincula ponteiros.

### <a name="example"></a>Exemplo

```cpp
// alg_remove.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1, Iter2, new_end;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle ( v1.begin( ), v1.end( ) );
    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Remove elements with a value of 7
    new_end = remove ( v1.begin( ), v1.end( ), 7 );

    cout << "Vector v1 with value 7 removed is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To change the sequence size, use erase
    v1.erase (new_end, v1.end( ) );

    cout << "Vector v1 resized with value 7 removed is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="remove_copy"></a><a name="remove_copy"></a>remove_copy

Copia os elementos de um intervalo de origem em um intervalo de destino, exceto os elementos de um valor especificado não são copiados, sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo de destino.

```cpp
template<class InputIterator, class OutputIterator, class Type>
OutputIterator remove_copy(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type>
ForwardIterator2 remove_copy(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que trata da posição do primeiro elemento no intervalo do qual os elementos estão sendo removidos.

*última*\
Um iterador de entrada que trata da posição logo após o elemento final no intervalo do qual os elementos estão sendo removidos.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino para o qual os elementos estão sendo removidos.

*valor*\
O valor a ser removido do intervalo.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que trata da nova posição final do intervalo de destino, logo após o elemento final da cópia da sequência restante livre do valor especificado.

### <a name="remarks"></a>Comentários

Os intervalos de origem e de destino referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível a partir da primeira por incrementação.

Deve haver espaço suficiente no intervalo de destino para conter os elementos restantes que serão copiados depois que os elementos do valor especificado forem removidos.

A ordem dos elementos não removidos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear; Há () comparações `last`  -  `first` para igualdade e no máximo ( `last`  -  `first` ) atribuições.

### <a name="example"></a>Exemplo

```cpp
// alg_remove_copy.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2(10);
    vector<int>::iterator Iter1, Iter2, new_end;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle (v1.begin( ), v1.end( ) );
    cout << "The original vector v1 is:     ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Remove elements with a value of 7
    new_end = remove_copy ( v1.begin( ), v1.end( ), v2.begin( ), 7 );

    cout << "Vector v1 is left unchanged as ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Vector v2 is a copy of v1 with the value 7 removed:\n ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;
}
```

## <a name="remove_copy_if"></a><a name="remove_copy_if"></a>remove_copy_if

Copia elementos de um intervalo de origem para um intervalo de destino, exceto para elementos que atendem a um predicado. Os elementos são copiados sem perturbar a ordem dos elementos restantes. Retorna o fim de um novo intervalo de destino.

```cpp
template<class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator remove_copy_if(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class UnaryPredicate>
ForwardIterator2 remove_copy_if(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que trata da posição do primeiro elemento no intervalo do qual os elementos estão sendo removidos.

*última*\
Um iterador de entrada que trata da posição logo após o elemento final no intervalo do qual os elementos estão sendo removidos.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino para o qual os elementos estão sendo removidos.

*Pred*\
O predicado unário que deve ser atendido é o valor de um elemento que deve ser substituído.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que trata da nova posição final do intervalo de destino, logo após o elemento final da sequência restante livre dos elementos que atendem ao predicado.

### <a name="remarks"></a>Comentários

O intervalo de origem referenciado deve ser válido, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível a partir da primeira por incrementação.

Deve haver espaço suficiente no intervalo de destino para conter os elementos restantes que serão copiados depois que os elementos do valor especificado forem removidos.

A ordem dos elementos não removidos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear: há () comparações `last`  -  `first` de igualdade e no máximo ( `last`  -  `first` ) atribuições.

Para obter informações de como essas funções se comportam, consulte [Iteradores verificados](checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// alg_remove_copy_if.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

bool greater6 ( int value ) {
    return value > 6;
}

int main()
{
    using namespace std;
    vector<int> v1, v2(10);
    vector<int>::iterator Iter1, Iter2, new_end;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle ( v1.begin( ), v1.end( ) );
    cout << "The original vector v1 is:      ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Remove elements with a value greater than 6
    new_end = remove_copy_if ( v1.begin( ), v1.end( ),
        v2.begin( ), greater6 );

    cout << "After the appliation of remove_copy_if to v1,\n "
         << "vector v1 is left unchanged as ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Vector v2 is a copy of v1 with values greater "
         << "than 6 removed:\n ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != new_end ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;
}
```

## <a name="remove_if"></a><a name="remove_if"></a>remove_if

Elimina elementos que atendem a um predicado de um determinado intervalo sem afetar a ordem dos elementos restantes e retornando ao fim de um novo intervalo livre do valor especificado.

```cpp
template<class ForwardIterator, class UnaryPredicate>
ForwardIterator remove_if(
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator, class UnaryPredicate>
ForwardIterator remove_if(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que aponta para a posição do primeiro elemento no intervalo do qual os elementos estão sendo removidos.

*última*\
Um iterador de avanço que aponta para a posição logo após o elemento final no intervalo do qual os elementos estão sendo removidos.

*Pred*\
O predicado unário que deve ser atendido é o valor de um elemento que deve ser substituído.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que trata da nova posição final do intervalo modificado, uma posição após o elemento final da sequência excedente livre do valor especificado.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A ordem dos elementos não removidos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear: há () comparações `last`  -  `first` para igualdade.

A lista tem uma versão mais eficiente da função de membro de remover, que vincula os ponteiros novamente.

### <a name="example"></a>Exemplo

```cpp
// alg_remove_if.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

bool greater6 ( int value )
{
    return value > 6;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2, new_end;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle ( v1.begin( ), v1.end( ) );
    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Remove elements satisfying predicate greater6
    new_end = remove_if (v1.begin( ), v1.end( ), greater6 );

    cout << "Vector v1 with elements satisfying greater6 removed is\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To change the sequence size, use erase
    v1.erase (new_end, v1.end( ) );

    cout << "Vector v1 resized elements satisfying greater6 removed is\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="replace"></a><a name="replace"></a>Substitua

Examina cada elemento em um intervalo e o substitui se ele corresponder a um valor especificado.

```cpp
template<class ForwardIterator, class Type>
void replace(
    ForwardIterator first,
    ForwardIterator last,
    const Type& oldVal,
    const Type& newVal);

template<class ExecutionPolicy, class ForwardIterator, class Type>
void replace(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    const Type& oldVal,
    const Type& newVal);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que aponta para a posição do primeiro elemento no intervalo cujos elementos estão sendo substituídos.

*última*\
Um iterador de avanço que aponta para a posição logo após o elemento final no intervalo cujos elementos estão sendo substituídos.

*oldVal*\
O valor anterior dos elementos que estão sendo substituídos.

*newVal*\
O novo valor que está sendo atribuído aos elementos com o valor anterior.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A ordem dos elementos não substituídos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear; Há () comparações `last`  -  `first` para igualdade e no máximo ( `last`  -  `first` ) atribuições de novos valores.

### <a name="example"></a>Exemplo

```cpp
// alg_replace.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle (v1.begin( ), v1.end( ) );
    cout << "The original vector v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Replace elements with a value of 7 with a value of 700
    replace (v1.begin( ), v1.end( ), 7 , 700);

    cout << "The vector v1 with a value 700 replacing that of 7 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="replace_copy"></a><a name="replace_copy"></a>replace_copy

Examina cada elemento em um intervalo de origem e o substitui se ele corresponder a um valor especificado ao copiar o resultado em um novo intervalo de destino.

```cpp
template<class InputIterator, class OutputIterator, class Type>
OutputIterator replace_copy(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    const Type& oldVal,
    const Type& newVal);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type>
ForwardIterator2 replace_copy(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    const Type& oldVal,
    const Type& newVal);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que aponta para a posição do primeiro elemento no intervalo cujos elementos estão sendo substituídos.

*última*\
Um iterador de entrada que aponta para a posição logo após o elemento final no intervalo cujos elementos estão sendo substituídos.

*disso*\
Um iterador de saída que aponta para o primeiro elemento no intervalo de destino para o qual a sequência alterada de elementos está sendo copiada.

*oldVal*\
O valor anterior dos elementos que estão sendo substituídos.

*newVal*\
O novo valor que está sendo atribuído aos elementos com o valor anterior.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aponta para a posição um anterior ao elemento final no intervalo de destino em que a sequência alterada de elementos é copiada.

### <a name="remarks"></a>Comentários

Os intervalos de origem e de destino referenciados não devem se sobrepor e deve ser válidos: todos os ponteiros devem ser desreferenciáveis e, dentro das sequências, a última posição deve ser acessível a partir da primeira por incrementação.

A ordem dos elementos não substituídos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear: há () comparações `last`  -  `first` de igualdade e no máximo ( `last`  -  `first` ) atribuições de novos valores.

### <a name="example"></a>Exemplo

```cpp
// alg_replace_copy.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    list<int> L1 (15);
    vector<int>::iterator Iter1;
    list<int>::iterator L_Iter1;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle ( v1.begin( ), v1.end( ) );

    int iii;
    for ( iii = 0 ; iii <= 15 ; iii++ )
        v1.push_back( 1 );

    cout << "The original vector v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Replace elements in one part of a vector with a value of 7
    // with a value of 70 and copy into another part of the vector
    replace_copy ( v1.begin( ), v1.begin( ) + 14,v1.end( ) -15, 7 , 70);

    cout << "The vector v1 with a value 70 replacing that of 7 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Replace elements in a vector with a value of 70
    // with a value of 1 and copy into a list
    replace_copy ( v1.begin( ), v1.begin( ) + 14,L1.begin( ), 7 , 1);

    cout << "The list copy L1 of v1 with the value 0 replacing "
            << "that of 7 is:\n ( " ;
    for ( L_Iter1 = L1.begin( ) ; L_Iter1 != L1.end( ) ; L_Iter1++ )
        cout << *L_Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="replace_copy_if"></a><a name="replace_copy_if"></a>replace_copy_if

Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.

```cpp
template<class InputIterator, class OutputIterator, class UnaryPredicate, class Type>
OutputIterator replace_copy_if(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    UnaryPredicate pred,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class UnaryPredicate, class Type>
ForwardIterator2 replace_copy_if(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    UnaryPredicate pred,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que aponta para a posição do primeiro elemento no intervalo cujos elementos estão sendo substituídos.

*última*\
Um iterador de entrada que aponta para a posição logo após o elemento final no intervalo cujos elementos estão sendo substituídos.

*disso*\
Um iterador de saída que aponta para a posição do primeiro elemento no intervalo de destino para o qual os elementos estão sendo copiados.

*Pred*\
O predicado unário que deve ser atendido é o valor de um elemento que deve ser substituído.

*valor*\
O novo valor que está sendo atribuído aos elementos cujos valores anteriores atendem ao predicado.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aponta para a posição um anterior ao elemento final no intervalo de destino em que a sequência alterada de elementos é copiada.

### <a name="remarks"></a>Comentários

Os intervalos de origem e de destino referenciados não devem se sobrepor e deve ser válidos: todos os ponteiros devem ser desreferenciáveis e, dentro das sequências, a última posição deve ser acessível a partir da primeira por incrementação.

A ordem dos elementos não substituídos permanece estável.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear; Há () comparações `last`  -  `first` para igualdade e no máximo ( `last`  -  `first` ) atribuições de novos valores.

### <a name="example"></a>Exemplo

```cpp
// alg_replace_copy_if.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

bool greater6 ( int value )
{
    return value > 6;
}

int main()
{
    using namespace std;
    vector<int> v1;
    list<int> L1 (13);
    vector<int>::iterator Iter1;
    list<int>::iterator L_Iter1;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle ( v1.begin( ), v1.end( ) );

    int iii;
    for ( iii = 0 ; iii <= 13 ; iii++ )
        v1.push_back( 1 );

    cout << "The original vector v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Replace elements with a value of 7 in the 1st half of a vector
    // with a value of 70 and copy it into the 2nd half of the vector
    replace_copy_if ( v1.begin( ), v1.begin( ) + 14,v1.end( ) -14,
        greater6 , 70);

    cout << "The vector v1 with values of 70 replacing those greater"
        << "\n than 6 in the 1st half & copied into the 2nd half is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Replace elements in a vector with a value of 70
    // with a value of 1 and copy into a list
    replace_copy_if ( v1.begin( ), v1.begin( ) + 13,L1.begin( ),
        greater6 , -1 );

    cout << "A list copy of vector v1 with the value -1\n replacing "
        << "those greater than 6 is:\n ( " ;
    for ( L_Iter1 = L1.begin( ) ; L_Iter1 != L1.end( ) ; L_Iter1++ )
        cout << *L_Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="replace_if"></a><a name="replace_if"></a>replace_if

Examina cada elemento em um intervalo e o substitui se ele atender a um predicado especificado.

```cpp
template<class ForwardIterator, class UnaryPredicate, class Type>
void replace_if(
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class UnaryPredicate, class Type>
void replace_if(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    UnaryPredicate pred,
    const Type& value);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que aponta para a posição do primeiro elemento no intervalo cujos elementos estão sendo substituídos.

*última*\
Um iterador que aponta para a posição logo após o elemento final no intervalo cujos elementos estão sendo substituídos.

*Pred*\
O predicado unário que deve ser atendido é o valor de um elemento que deve ser substituído.

*valor*\
O novo valor que está sendo atribuído aos elementos cujos valores anteriores atendem ao predicado.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A ordem dos elementos não substituídos permanece estável.

O algoritmo `replace_if` é uma generalização do algoritmo `replace` , permitindo que qualquer predicado seja especificado, em vez de igualdade, em um valor constante especificado.

O `operator==` usado para determinar a equalidade entre os elementos deve impor uma relação de equivalência entre seus operandos.

A complexidade é linear: há () comparações `last`  -  `first` de igualdade e no máximo ( `last`  -  `first` ) atribuições de novos valores.

### <a name="example"></a>Exemplo

```cpp
// alg_replace_if.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

bool greater6 ( int value )
{
    return value > 6;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
        v1.push_back( 7 );

    random_shuffle ( v1.begin( ), v1.end( ) );
    cout << "The original vector v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Replace elements satisfying the predicate greater6
    // with a value of 70
    replace_if ( v1.begin( ), v1.end( ), greater6 , 70);

    cout << "The vector v1 with a value 70 replacing those\n "
         << "elements satisfying the greater6 predicate is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="reverse"></a><a name="reverse"></a>ordem

Inverte a ordem dos elementos em um intervalo.

```cpp
template<class BidirectionalIterator>
void reverse(
    BidirectionalIterator first,
    BidirectionalIterator last);

template<class ExecutionPolicy, class BidirectionalIterator>
void reverse(
    ExecutionPolicy&& exec,
    BidirectionalIterator first,
    BidirectionalIterator last);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador bidirecional que aponta para a posição do primeiro elemento no intervalo no qual os elementos estão sendo permutados.

*última*\
Um iterador bidirecional que aponta para a posição logo após o elemento final no intervalo no qual os elementos estão sendo permutados.

### <a name="remarks"></a>Comentários

O intervalo de origem referenciado deve ser válido, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível a partir da primeira por incrementação.

### <a name="example"></a>Exemplo

```cpp
// alg_reverse.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
    {
        v1.push_back( i );
    }

    cout << "The original vector v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Reverse the elements in the vector
    reverse (v1.begin( ), v1.end( ) );

    cout << "The modified vector v1 with values reversed is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

```Output
The original vector v1 is:
( 0 1 2 3 4 5 6 7 8 9 ).
The modified vector v1 with values reversed is:
( 9 8 7 6 5 4 3 2 1 0 ).
```

## <a name="reverse_copy"></a><a name="reverse_copy"></a>reverse_copy

Inverte a ordem dos elementos em um intervalo de origem ao copiá-los em um intervalo de destino

```cpp
template<class BidirectionalIterator, class OutputIterator>
OutputIterator reverse_copy(
    BidirectionalIterator first,
    BidirectionalIterator last,
    OutputIterator result);

template<class ExecutionPolicy, class BidirectionalIterator, class ForwardIterator>
ForwardIterator reverse_copy(
    ExecutionPolicy&& exec,
    BidirectionalIterator first,
    BidirectionalIterator last,
    ForwardIterator result);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador bidirecional que aponta para a posição do primeiro elemento no intervalo de origem no qual os elementos estão sendo permutados.

*última*\
Um iterador bidirecional que aponta para a posição logo após o elemento final no intervalo de origem no qual os elementos estão sendo permutados.

*disso*\
Um iterador de saída que aponta para a posição do primeiro elemento no intervalo de destino para o qual os elementos estão sendo copiados.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aponta para a posição um anterior ao elemento final no intervalo de destino em que a sequência alterada de elementos é copiada.

### <a name="remarks"></a>Comentários

Os intervalos de origem e de destino referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível a partir da primeira por incrementação.

### <a name="example"></a>Exemplo

```cpp
// alg_reverse_copy.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2( 10 );
    vector<int>::iterator Iter1, Iter2;

    int i;
    for ( i = 0 ; i <= 9 ; i++ )
    {
        v1.push_back( i );
    }

    cout << "The original vector v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Reverse the elements in the vector
    reverse_copy (v1.begin( ), v1.end( ), v2.begin( ) );

    cout << "The copy v2 of the reversed vector v1 is:\n ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    cout << "The original vector v1 remains unmodified as:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;
}
```

## <a name="rotate"></a><a name="rotate"></a>girar

Troca os elementos em dois intervalos adjacentes.

```cpp
template<class ForwardIterator>
void rotate(
    ForwardIterator first,
    ForwardIterator middle,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator>
ForwardIterator rotate(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator middle,
    ForwardIterator last);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento do intervalo a ser girado.

*meio*\
Um iterador de avanço que define o limite dentro do intervalo que trata da posição do primeiro elemento na segunda parte do intervalo cujos elementos devem ser trocados com os que estão na primeira parte do intervalo.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final no intervalo a ser girado.

### <a name="remarks"></a>Comentários

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível a partir da primeira por incrementação.

A complexidade é linear com no máximo ( `last`  -  `first` ) trocas.

### <a name="example"></a>Exemplo

```cpp
// alg_rotate.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

int main() {
    using namespace std;
    vector<int> v1;
    deque<int> d1;
    vector<int>::iterator v1Iter1;
    deque<int>::iterator d1Iter1;

    int i;
    for ( i = -3 ; i <= 5 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii =0 ; ii <= 5 ; ii++ )
    {
        d1.push_back( ii );
    }

    cout << "Vector v1 is ( " ;
    for ( v1Iter1 = v1.begin( ) ; v1Iter1 != v1.end( ) ;v1Iter1 ++ )
        cout << *v1Iter1 << " ";
    cout << ")." << endl;

    rotate ( v1.begin( ), v1.begin( ) + 3 , v1.end( ) );
    cout << "After rotating, vector v1 is ( " ;
    for ( v1Iter1 = v1.begin( ) ; v1Iter1 != v1.end( ) ;v1Iter1 ++ )
        cout << *v1Iter1 << " ";
    cout << ")." << endl;

    cout << "The original deque d1 is ( " ;
    for ( d1Iter1 = d1.begin( ) ; d1Iter1 != d1.end( ) ;d1Iter1 ++ )
        cout << *d1Iter1 << " ";
    cout << ")." << endl;

    int iii = 1;
    while ( iii <= d1.end( ) - d1.begin( ) ) {
        rotate ( d1.begin( ), d1.begin( ) + 1 , d1.end( ) );
        cout << "After the rotation of a single deque element to the back,\n d1 is   ( " ;
        for ( d1Iter1 = d1.begin( ) ; d1Iter1 != d1.end( ) ;d1Iter1 ++ )
            cout << *d1Iter1 << " ";
        cout << ")." << endl;
        iii++;
    }
}
```

```Output
Vector v1 is ( -3 -2 -1 0 1 2 3 4 5 ).
After rotating, vector v1 is ( 0 1 2 3 4 5 -3 -2 -1 ).
The original deque d1 is ( 0 1 2 3 4 5 ).
After the rotation of a single deque element to the back,
d1 is   ( 1 2 3 4 5 0 ).
After the rotation of a single deque element to the back,
d1 is   ( 2 3 4 5 0 1 ).
After the rotation of a single deque element to the back,
d1 is   ( 3 4 5 0 1 2 ).
After the rotation of a single deque element to the back,
d1 is   ( 4 5 0 1 2 3 ).
After the rotation of a single deque element to the back,
d1 is   ( 5 0 1 2 3 4 ).
After the rotation of a single deque element to the back,
d1 is   ( 0 1 2 3 4 5 ).
```

## <a name="rotate_copy"></a><a name="rotate_copy"></a>rotate_copy

Troca os elementos em dois intervalos adjacentes em um intervalo de origem e copia o resultado em um intervalo de destino.

```cpp
template<class ForwardIterator, class OutputIterator>
OutputIterator rotate_copy(
    ForwardIterator first,
    ForwardIterator middle,
    ForwardIterator last,
    OutputIterator result );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 rotate_copy(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 middle,
    ForwardIterator1 last,
    ForwardIterator2 result);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento do intervalo a ser girado.

*meio*\
Um iterador de avanço que define o limite dentro do intervalo que trata da posição do primeiro elemento na segunda parte do intervalo cujos elementos devem ser trocados com os que estão na primeira parte do intervalo.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final no intervalo a ser girado.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o elemento final no intervalo de destino.

### <a name="remarks"></a>Comentários

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível a partir da primeira por incrementação.

A complexidade é linear com no máximo ( `last`  -  `first` ) trocas.

### <a name="example"></a>Exemplo

```cpp
// alg_rotate_copy.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1 , v2 ( 9 );
    deque<int> d1 , d2 ( 6 );
    vector<int>::iterator v1Iter , v2Iter;
    deque<int>::iterator d1Iter , d2Iter;

    int i;
    for ( i = -3 ; i <= 5 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii =0 ; ii <= 5 ; ii++ )
        d1.push_back( ii );

    cout << "Vector v1 is ( " ;
    for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ;v1Iter ++ )
        cout << *v1Iter << " ";
    cout << ")." << endl;

    rotate_copy ( v1.begin( ), v1.begin( ) + 3 , v1.end( ), v2.begin( ) );
    cout << "After rotating, the vector v1 remains unchanged as:\n v1 = ( " ;
    for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ;v1Iter ++ )
        cout << *v1Iter << " ";
    cout << ")." << endl;

    cout << "After rotating, the copy of vector v1 in v2 is:\n v2 = ( " ;
    for ( v2Iter = v2.begin( ) ; v2Iter != v2.end( ) ;v2Iter ++ )
        cout << *v2Iter << " ";
    cout << ")." << endl;

    cout << "The original deque d1 is ( " ;
    for ( d1Iter = d1.begin( ) ; d1Iter != d1.end( ) ;d1Iter ++ )
        cout << *d1Iter << " ";
    cout << ")." << endl;

    int iii = 1;
    while ( iii <= d1.end( ) - d1.begin( ) )
    {
        rotate_copy ( d1.begin( ), d1.begin( ) + iii , d1.end( ), d2.begin( ) );
        cout << "After the rotation of a single deque element to the back,\n d2 is   ( " ;
        for ( d2Iter = d2.begin( ) ; d2Iter != d2.end( ) ;d2Iter ++ )
            cout << *d2Iter << " ";
        cout << ")." << endl;
        iii++;
    }
}
```

## <a name="sample"></a><a name="sample"></a>Nova

```cpp
template<class PopulationIterator, class SampleIterator, class Distance, class UniformRandomBitGenerator>
SampleIterator sample(
    PopulationIterator first,
    PopulationIterator last,
    SampleIterator out,
    Distance n,
    UniformRandomBitGenerator&& g);
```

## <a name="search"></a><a name="search"></a>procurando

Procura a primeira ocorrência de uma sequência em um intervalo de destino cujos elementos são iguais àqueles em uma determinada sequência de elementos ou cujos elementos são equivalentes de certo modo especificado por um predicado binário para os elementos na sequência determinada.

```cpp
template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 search(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 search(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    BinaryPredicate pred);

template <class ForwardIterator, class Searcher>
ForwardIterator search(
    ForwardIterator first,
    ForwardIterator last,
    const Searcher& searcher);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*last1*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*first2*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser correspondido.

*last2*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser correspondido.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

*Searcher*\
O pesquisador que encapsula o padrão a ser procurado e o algoritmo de pesquisa a ser usado. Para obter mais informações sobre os pesquisadores, consulte classe [default_searcher](default-searcher-class.md), classe [boyer_moore_horspool_searcher](boyer-moore-horspool-searcher-class.md)e [classe boyer_moore_searcher](boyer-moore-searcher-class.md).

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que aborda a posição do primeiro elemento da primeira subsequência que corresponda à sequência especificada ou que seja equivalente em um sentido especificado por um predicado binário.

### <a name="remarks"></a>Comentários

O `operator==` usado para determinar a correspondência entre um elemento e o valor especificado deve impor uma relação de equivalência entre os operandos.

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

A média de complexidade é linear em relação ao tamanho do intervalo pesquisado e o pior caso de complexidade também é linear em relação ao tamanho da sequência que está sendo pesquisada.

### <a name="example"></a>Exemplo

```cpp
// alg_search.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// Return whether second element is twice the first
bool twice (int elem1, int elem2 )
{
    return 2 * elem1 == elem2;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    list<int> L1;
    vector<int>::iterator Iter1, Iter2;
    list<int>::iterator L1_Iter, L1_inIter;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }

    int ii;
    for ( ii = 4 ; ii <= 5 ; ii++ )
    {
        L1.push_back( 5 * ii );
    }

    int iii;
    for ( iii = 2 ; iii <= 4 ; iii++ )
    {
        v2.push_back( 10 * iii );
    }

    cout << "Vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    cout << "List L1 = ( " ;
    for ( L1_Iter = L1.begin( ) ; L1_Iter!= L1.end( ) ; L1_Iter++ )
        cout << *L1_Iter << " ";
    cout << ")" << endl;

    cout << "Vector v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
        cout << ")" << endl;

    // Searching v1 for first match to L1 under identity
    vector<int>::iterator result1;
    result1 = search (v1.begin( ), v1.end( ), L1.begin( ), L1.end( ) );

    if ( result1 == v1.end( ) )
        cout << "There is no match of L1 in v1."
            << endl;
    else
        cout << "There is at least one match of L1 in v1"
            << "\n and the first one begins at "
            << "position "<< result1 - v1.begin( ) << "." << endl;

    // Searching v1 for a match to L1 under the binary predicate twice
    vector<int>::iterator result2;
    result2 = search (v1.begin( ), v1.end( ), v2.begin( ), v2.end( ), twice );

    if ( result2 == v1.end( ) )
        cout << "There is no match of L1 in v1."
            << endl;
    else
        cout << "There is a sequence of elements in v1 that "
            << "are equivalent\n to those in v2 under the binary "
            << "predicate twice\n and the first one begins at position "
            << result2 - v1.begin( ) << "." << endl;
}
```

```Output
Vector v1 = ( 0 5 10 15 20 25 0 5 10 15 20 25 )
List L1 = ( 20 25 )
Vector v2 = ( 20 30 40 )
There is at least one match of L1 in v1
and the first one begins at position 4.
There is a sequence of elements in v1 that are equivalent
to those in v2 under the binary predicate twice
and the first one begins at position 2.
```

## <a name="search_n"></a><a name="search_n"></a>search_n

Procura a primeira subsequência em um intervalo de um número especificado de elementos com um valor particular ou uma relação com esse valor, conforme especificado por um predicado binário.

```cpp
template<class ForwardIterator1, class Diff2, class Type>
ForwardIterator1 search_n(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    Diff2 count,
    const Type& value);

template<class ForwardIterator1, class Diff2, class Type, class BinaryPredicate>
ForwardIterator1 search_n(
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    Diff2 count,
    const Type& value,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator, class Size, class Type>
ForwardIterator search_n(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Size count,
    const Type& value);

template<class ExecutionPolicy, class ForwardIterator, class Size, class Type, class BinaryPredicate>
ForwardIterator search_n(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Size count,
    const Type& value,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de avanço que aborda a posição do primeiro elemento do intervalo a ser pesquisado.

*last1*\
Um iterador de avanço que aborda a posição um após o elemento final do intervalo a ser pesquisado.

*contar*\
O tamanho da subsequência que está sendo pesquisada.

*valor*\
O valor dos elementos na sequência que está sendo pesquisada.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que aborda a posição do primeiro elemento da primeira subsequência que corresponda à sequência especificada ou que seja equivalente em um sentido especificado por um predicado binário.

### <a name="remarks"></a>Comentários

O `operator==` usado para determinar a correspondência entre um elemento e o valor especificado deve impor uma relação de equivalência entre os operandos.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A complexidade é linear em relação ao tamanho do pesquisado.

### <a name="example"></a>Exemplo

```cpp
// alg_search_n.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// Return whether second element is 1/2 of the first
bool one_half ( int elem1, int elem2 )
{
    return elem1 == 2 * elem2;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }

    for ( i = 0 ; i <= 2 ; i++ )
    {
        v1.push_back( 5 );
    }

    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 5 * i );
    }

    for ( i = 0 ; i <= 2 ; i++ )
    {
        v1.push_back( 10 );
    }

    cout << "Vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // Searching v1 for first match to (5 5 5) under identity
    vector<int>::iterator result1;
    result1 = search_n ( v1.begin( ), v1.end( ), 3, 5 );

    if ( result1 == v1.end( ) )
        cout << "There is no match for a sequence ( 5 5 5 ) in v1."
            << endl;
    else
        cout << "There is at least one match of a sequence ( 5 5 5 )"
            << "\n in v1 and the first one begins at "
            << "position "<< result1 - v1.begin( ) << "." << endl;

    // Searching v1 for first match to (5 5 5) under one_half
    vector<int>::iterator result2;
    result2 = search_n (v1.begin( ), v1.end( ), 3, 5, one_half );

    if ( result2 == v1.end( ) )
        cout << "There is no match for a sequence ( 5 5 5 ) in v1"
            << " under the equivalence predicate one_half." << endl;
    else
        cout << "There is a match of a sequence ( 5 5 5 ) "
            << "under the equivalence\n predicate one_half "
            << "in v1 and the first one begins at "
            << "position "<< result2 - v1.begin( ) << "." << endl;
}
```

```Output
Vector v1 = ( 0 5 10 15 20 25 5 5 5 0 5 10 15 20 25 10 10 10 )
There is at least one match of a sequence ( 5 5 5 )
in v1 and the first one begins at position 6.
There is a match of a sequence ( 5 5 5 ) under the equivalence
predicate one_half in v1 and the first one begins at position 15.
```

## <a name="set_difference"></a><a name="set_difference"></a>set_difference

Une todos os elementos que pertencem a um intervalo de origem classificado, mas não a um segundo intervalo de origem classificado, em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado específico.

```cpp
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_difference(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result );

template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator set_difference(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator>
ForwardIterator set_difference(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator, class Compare>
ForwardIterator set_difference(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a diferença entre os dois intervalos de origem.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a diferença entre os dois intervalos de origem.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a diferença entre os dois intervalos de origem.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a diferença entre os dois intervalos de origem.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino, em que os dois intervalos de origem devem ser unidos em um único intervalo classificado, representando a diferença entre os dois intervalos de origem.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado binário usa dois argumentos e deve retornar **true** quando o primeiro elemento é menor que o segundo elemento, caso contrário, **false**.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o último elemento no intervalo de destino classificado, que representa a diferença entre os dois intervalos de origem.

### <a name="remarks"></a>Comentários

Os intervalos de origem classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

O intervalo de destino não deve se sobrepor a nenhum dos intervalos de origem e deve ser grande o suficiente para conter o intervalo de origem.

Cada intervalo de origem classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo `set_difference`, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

A operação é estável, pois a ordem relativa dos elementos em cada intervalo é preservada no intervalo de destino. Os intervalos de origem não são modificados pelo algoritmo merge.

Os tipos de valor dos iteradores de entrada precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Quando há elementos equivalentes nos dois intervalos de origem, os elementos do primeiro intervalo precedem os elementos do segundo intervalo de origem no intervalo de destino. Se os intervalos de origem contiverem duplicatas de um elemento de modo que haja mais no primeiro intervalo de origem do que no segundo, o intervalo de destino conterá o número em que as ocorrências desses elementos no primeiro intervalo de origem excederem as ocorrências desses elementos no segundo intervalo de origem.

A complexidade do algoritmo é linear com no máximo `2 * ((last1 - first1) - (last2 - first2)) - 1` comparações para intervalos de origem não vazios.

### <a name="example"></a>Exemplo

```cpp
// alg_set_diff.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser (int elem1, int elem2 )
{
    if (elem1 < 0)
        elem1 = - elem1;
    if (elem2 < 0)
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1a, v1b, v1 ( 12 );
    vector<int>::iterator Iter1a, Iter1b, Iter1, Result1;

    // Constructing vectors v1a & v1b with default less-than ordering
    int i;
    for ( i = -1 ; i <= 4 ; i++ )
    {
        v1a.push_back( i );
    }

    int ii;
    for ( ii =-3 ; ii <= 0 ; ii++ )
    {
        v1b.push_back( ii );
    }

    cout << "Original vector v1a with range sorted by the\n "
         << "binary predicate less than is v1a = ( " ;
    for ( Iter1a = v1a.begin( ) ; Iter1a != v1a.end( ) ; Iter1a++ )
        cout << *Iter1a << " ";
    cout << ")." << endl;

    cout << "Original vector v1b with range sorted by the\n "
         << "binary predicate less than is v1b = ( " ;
    for ( Iter1b = v1b.begin( ) ; Iter1b != v1b.end( ) ; Iter1b++ )
        cout << *Iter1b << " ";
    cout << ")." << endl;

    // Constructing vectors v2a & v2b with ranges sorted by greater
    vector<int> v2a ( v1a ) , v2b ( v1b ) , v2 ( v1 );
    vector<int>::iterator Iter2a, Iter2b, Iter2, Result2;
    sort ( v2a.begin( ), v2a.end( ), greater<int>( ) );
    sort ( v2b.begin( ), v2b.end( ), greater<int>( ) );

    cout << "Original vector v2a with range sorted by the\n "
         << "binary predicate greater is   v2a = ( " ;
    for ( Iter2a = v2a.begin( ) ; Iter2a != v2a.end( ) ; Iter2a++ )
        cout << *Iter2a << " ";
    cout << ")." << endl;

    cout << "Original vector v2b with range sorted by the\n "
         << "binary predicate greater is   v2b = ( " ;
    for ( Iter2b = v2b.begin( ) ; Iter2b != v2b.end( ) ; Iter2b++ )
        cout << *Iter2b << " ";
    cout << ")." << endl;

    // Constructing vectors v3a & v3b with ranges sorted by mod_lesser
    vector<int> v3a ( v1a ), v3b ( v1b ) , v3 ( v1 );
    vector<int>::iterator Iter3a, Iter3b, Iter3, Result3;
    sort ( v3a.begin( ), v3a.end( ), mod_lesser );
    sort ( v3b.begin( ), v3b.end( ), mod_lesser );

    cout << "Original vector v3a with range sorted by the\n "
         << "binary predicate mod_lesser is   v3a = ( " ;
    for ( Iter3a = v3a.begin( ) ; Iter3a != v3a.end( ) ; Iter3a++ )
        cout << *Iter3a << " ";
    cout << ")." << endl;

    cout << "Original vector v3b with range sorted by the\n "
         << "binary predicate mod_lesser is   v3b = ( " ;
    for ( Iter3b = v3b.begin( ) ; Iter3b != v3b.end( ) ; Iter3b++ )
        cout << *Iter3b << " ";
    cout << ")." << endl;

    // To combine into a difference in asscending
    // order with the default binary predicate less<int>( )
    Result1 = set_difference ( v1a.begin( ), v1a.end( ),
        v1b.begin( ), v1b.end( ), v1.begin( ) );
    cout << "Set_difference of source ranges with default order,"
         << "\n vector v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != Result1 ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To combine into a difference in descending
    // order specify binary predicate greater<int>( )
    Result2 = set_difference ( v2a.begin( ), v2a.end( ),
        v2b.begin( ), v2b.end( ),v2.begin( ), greater<int>( ) );
    cout << "Set_difference of source ranges with binary"
         << "predicate greater specified,\n vector v2mod = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != Result2 ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    // To combine into a difference applying a user
    // defined binary predicate mod_lesser
    Result3 = set_difference ( v3a.begin( ), v3a.end( ),
        v3b.begin( ), v3b.end( ), v3.begin( ), mod_lesser );
    cout << "Set_difference of source ranges with binary "
         << "predicate mod_lesser specified,\n vector v3mod = ( " ; ;
    for ( Iter3 = v3.begin( ) ; Iter3 != Result3 ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;
}
```

## <a name="set_intersection"></a><a name="set_intersection"></a>set_intersection

Une todos os elementos que pertencem a ambos os intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_intersection(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result);

template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator set_intersection(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result,
    Compare pred);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator>
ForwardIterator set_intersection(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator, class Compare>
ForwardIterator set_intersection(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a intersecção entre os dois intervalos de origem.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a intersecção entre os dois intervalos de origem.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a intersecção entre os dois intervalos de origem.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a intersecção entre os dois intervalos de origem.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino, em que os dois intervalos de origem devem ser unidos em um único intervalo classificado, representando a interseção entre os dois intervalos de origem.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado binário usa dois argumentos e deve retornar **true** quando o primeiro elemento é menor que o segundo elemento, caso contrário, **false**.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o último elemento no intervalo de destino classificado, que representa a intersecção entre os dois intervalos de origem.

### <a name="remarks"></a>Comentários

Os intervalos de origem classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

O intervalo de destino não deve se sobrepor a nenhum dos intervalos de origem e deve ser grande o suficiente para conter o intervalo de destino.

Cada intervalo de origem classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo merge, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

A operação é estável, pois a ordem relativa dos elementos em cada intervalo é preservada no intervalo de destino. Os intervalos de origem não são modificados pelo algoritmo.

Os tipos de valor dos iteradores de entrada precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Quando há elementos equivalentes nos dois intervalos de origem, os elementos do primeiro intervalo precedem os elementos do segundo intervalo de origem no intervalo de destino. Se os intervalos de origem contiverem duplicatas de um elemento, o intervalo de destino conterá o número máximo dos elementos que ocorrem em ambos os intervalos de origem.

A complexidade do algoritmo é linear com no máximo `2 * ((last1 - first1) + (last2 - first2)) - 1` comparações para intervalos de origem não vazios.

### <a name="example"></a>Exemplo

```cpp
// alg_set_intersection.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>   // For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser (int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1a, v1b, v1 ( 12 );
    vector<int>::iterator Iter1a, Iter1b, Iter1, Result1;

    // Constructing vectors v1a & v1b with default less than ordering
    int i;
    for ( i = -1 ; i <= 3 ; i++ )
        v1a.push_back( i );

    int ii;
    for ( ii =-3 ; ii <= 1 ; ii++ )
        v1b.push_back( ii );

    cout << "Original vector v1a with range sorted by the\n "
         << "binary predicate less than is v1a = ( " ;
    for ( Iter1a = v1a.begin( ) ; Iter1a != v1a.end( ) ; Iter1a++ )
        cout << *Iter1a << " ";
    cout << ")." << endl;

    cout << "Original vector v1b with range sorted by the\n "
         << "binary predicate less than is v1b = ( " ;
    for ( Iter1b = v1b.begin( ) ; Iter1b != v1b.end( ) ; Iter1b++ )
        cout << *Iter1b << " ";
    cout << ")." << endl;

    // Constructing vectors v2a & v2b with ranges sorted by greater
    vector<int> v2a ( v1a ) , v2b ( v1b ) , v2 ( v1 );
    vector<int>::iterator Iter2a, Iter2b, Iter2, Result2;
    sort ( v2a.begin( ), v2a.end( ), greater<int>( ) );
    sort ( v2b.begin( ), v2b.end( ), greater<int>( ) );

    cout << "Original vector v2a with range sorted by the\n "
         << "binary predicate greater is   v2a = ( " ;
    for ( Iter2a = v2a.begin( ) ; Iter2a != v2a.end( ) ; Iter2a++ )
        cout << *Iter2a << " ";
    cout << ")." << endl;

    cout << "Original vector v2b with range sorted by the\n "
         << "binary predicate greater is   v2b = ( " ;
    for ( Iter2b = v2b.begin( ) ; Iter2b != v2b.end( ) ; Iter2b++ )
        cout << *Iter2b << " ";
    cout << ")." << endl;

    // Constructing vectors v3a & v3b with ranges sorted by mod_lesser
    vector<int> v3a ( v1a ), v3b ( v1b ) , v3 ( v1 );
    vector<int>::iterator Iter3a, Iter3b, Iter3, Result3;
    sort ( v3a.begin( ), v3a.end( ), mod_lesser );
    sort ( v3b.begin( ), v3b.end( ), mod_lesser );

    cout << "Original vector v3a with range sorted by the\n "
         << "binary predicate mod_lesser is   v3a = ( " ;
    for ( Iter3a = v3a.begin( ) ; Iter3a != v3a.end( ) ; Iter3a++ )
        cout << *Iter3a << " ";
    cout << ")." << endl;

    cout << "Original vector v3b with range sorted by the\n "
         << "binary predicate mod_lesser is   v3b = ( " ;
    for ( Iter3b = v3b.begin( ) ; Iter3b != v3b.end( ) ; Iter3b++ )
        cout << *Iter3b << " ";
    cout << ")." << endl;

    // To combine into an intersection in asscending order with the
    // default binary predicate less<int>( )
    Result1 = set_intersection ( v1a.begin( ), v1a.end( ),
        v1b.begin( ), v1b.end( ), v1.begin( ) );
    cout << "Intersection of source ranges with default order,"
         << "\n vector v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != Result1 ; ++Iter1 )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To combine into an intersection in descending order, specify
    // binary predicate greater<int>( )
    Result2 = set_intersection ( v2a.begin( ), v2a.end( ),
        v2b.begin( ), v2b.end( ),v2.begin( ), greater<int>( ) );
    cout << "Intersection of source ranges with binary predicate"
            << " greater specified,\n vector v2mod = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != Result2 ; ++Iter2 )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    // To combine into an intersection applying a user-defined
    // binary predicate mod_lesser
    Result3 = set_intersection ( v3a.begin( ), v3a.end( ),
        v3b.begin( ), v3b.end( ), v3.begin( ), mod_lesser );
    cout << "Intersection of source ranges with binary predicate "
            << "mod_lesser specified,\n vector v3mod = ( " ; ;
    for ( Iter3 = v3.begin( ) ; Iter3 != Result3 ; ++Iter3 )
        cout << *Iter3 << " ";
    cout << ")." << endl;
}
```

## <a name="set_symmetric_difference"></a><a name="set_symmetric_difference"></a>set_symmetric_difference

Une todos os elementos que pertencem a um (mas não a ambos) dos intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_symmetric_difference(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result );

template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator set_symmetric_difference(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator>
ForwardIterator set_symmetric_difference(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator, class Compare>
ForwardIterator set_symmetric_difference(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a diferença simétrica entre os dois intervalos de origem.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a diferença simétrica entre os dois intervalos de origem.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a diferença simétrica entre os dois intervalos de origem.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a diferença simétrica entre os dois intervalos de origem.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino, em que os dois intervalos de origem devem ser unidos em um único intervalo classificado, representando a diferença simétrica entre os dois intervalos de origem.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado binário usa dois argumentos e deve retornar **true** quando o primeiro elemento é menor que o segundo elemento, caso contrário, **false**.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o último elemento no intervalo de destino classificado, que representa a diferença simétrica entre os dois intervalos de origem.

### <a name="remarks"></a>Comentários

Os intervalos de origem classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

O intervalo de destino não deve se sobrepor a nenhum dos intervalos de origem e deve ser grande o suficiente para conter o intervalo de destino.

Cada intervalo de origem classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo `merge*`, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

A operação é estável, pois a ordem relativa dos elementos em cada intervalo é preservada no intervalo de destino. Os intervalos de origem não são modificados pelo algoritmo merge.

Os tipos de valor dos iteradores de entrada precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Quando há elementos equivalentes nos dois intervalos de origem, os elementos do primeiro intervalo precedem os elementos do segundo intervalo de origem no intervalo de destino. Se os intervalos de origem contiverem duplicatas de um elemento, o intervalo de destino conterá o valor absoluto do número em que as ocorrências dos elementos em um dos intervalos de origem excedem as ocorrências desses elementos no segundo intervalo de origem.

A complexidade do algoritmo é linear com no máximo `2 * ((last1 - first1) - (last2 - first2)) - 1` comparações para intervalos de origem não vazios.

### <a name="example"></a>Exemplo

```cpp
// alg_set_sym_diff.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser (int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1a, v1b, v1 ( 12 );
    vector<int>::iterator Iter1a, Iter1b, Iter1, Result1;

    // Constructing vectors v1a & v1b with default less-than ordering
    int i;
    for ( i = -1 ; i <= 4 ; i++ )
    {
        v1a.push_back( i );
    }

    int ii;
    for ( ii =-3 ; ii <= 0 ; ii++ )
    {
        v1b.push_back( ii );
    }

    cout << "Original vector v1a with range sorted by the\n "
         << "binary predicate less than is v1a = ( " ;
    for ( Iter1a = v1a.begin( ) ; Iter1a != v1a.end( ) ; Iter1a++ )
        cout << *Iter1a << " ";
    cout << ")." << endl;

    cout << "Original vector v1b with range sorted by the\n "
         << "binary predicate less than is v1b = ( " ;
    for ( Iter1b = v1b.begin( ) ; Iter1b != v1b.end( ) ; Iter1b++ )
        cout << *Iter1b << " ";
    cout << ")." << endl;

    // Constructing vectors v2a & v2b with ranges sorted by greater
    vector<int> v2a ( v1a ) , v2b ( v1b ) , v2 ( v1 );
    vector<int>::iterator Iter2a, Iter2b, Iter2, Result2;
    sort ( v2a.begin( ), v2a.end( ), greater<int>( ) );
    sort ( v2b.begin( ), v2b.end( ), greater<int>( ) );

    cout << "Original vector v2a with range sorted by the\n "
         << "binary predicate greater is   v2a = ( " ;
    for ( Iter2a = v2a.begin( ) ; Iter2a != v2a.end( ) ; Iter2a++ )
        cout << *Iter2a << " ";
    cout << ")." << endl;

    cout << "Original vector v2b with range sorted by the\n "
         << "binary predicate greater is   v2b = ( " ;
    for ( Iter2b = v2b.begin( ) ; Iter2b != v2b.end( ) ; Iter2b++ )
        cout << *Iter2b << " ";
    cout << ")." << endl;

    // Constructing vectors v3a & v3b with ranges sorted by mod_lesser
    vector<int> v3a ( v1a ), v3b ( v1b ) , v3 ( v1 );
    vector<int>::iterator Iter3a, Iter3b, Iter3, Result3;
    sort ( v3a.begin( ), v3a.end( ), mod_lesser );
    sort ( v3b.begin( ), v3b.end( ), mod_lesser );

    cout << "Original vector v3a with range sorted by the\n "
         << "binary predicate mod_lesser is   v3a = ( " ;
    for ( Iter3a = v3a.begin( ) ; Iter3a != v3a.end( ) ; Iter3a++ )
        cout << *Iter3a << " ";
    cout << ")." << endl;

    cout << "Original vector v3b with range sorted by the\n "
         << "binary predicate mod_lesser is   v3b = ( " ;
    for ( Iter3b = v3b.begin( ) ; Iter3b != v3b.end( ) ; Iter3b++ )
        cout << *Iter3b << " ";
    cout << ")." << endl;

    // To combine into a symmetric difference in ascending
    // order with the default binary predicate less<int>( )
    Result1 = set_symmetric_difference ( v1a.begin( ), v1a.end( ),
        v1b.begin( ), v1b.end( ), v1.begin( ) );
    cout << "Set_symmetric_difference of source ranges with default order,"
         << "\n vector v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != Result1 ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To combine into a symmetric difference in descending
    // order, specify binary predicate greater<int>( )
    Result2 = set_symmetric_difference ( v2a.begin( ), v2a.end( ),
        v2b.begin( ), v2b.end( ),v2.begin( ), greater<int>( ) );
    cout << "Set_symmetric_difference of source ranges with binary"
         << "predicate greater specified,\n vector v2mod = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != Result2 ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    // To combine into a symmetric difference applying a user
    // defined binary predicate mod_lesser
    Result3 = set_symmetric_difference ( v3a.begin( ), v3a.end( ),
        v3b.begin( ), v3b.end( ), v3.begin( ), mod_lesser );
    cout << "Set_symmetric_difference of source ranges with binary "
         << "predicate mod_lesser specified,\n vector v3mod = ( " ; ;
    for ( Iter3 = v3.begin( ) ; Iter3 != Result3 ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;
}
```

## <a name="set_union"></a><a name="set_union"></a>set_union

Une todos os elementos que pertencem a pelo menos um dos dois intervalos de origem classificados em um único intervalo de destino classificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_union(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result );

template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator set_union(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    InputIterator2 last2,
    OutputIterator result,
    Compare pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator>
ForwardIterator set_union(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator, class Compare>
ForwardIterator set_union(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator2 last2,
    ForwardIterator result,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a união entre os dois intervalos de origem.

*last1*\
Um iterador de entrada que trata da posição logo após o último elemento no primeiro entre dois intervalos de origem classificados, a serem unidos e classificados em um único intervalo, representando a união entre os dois intervalos de origem.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a união entre os dois intervalos de origem.

*last2*\
Um iterador de entrada que trata da posição logo após o último elemento no segundo entre dois intervalos de origem classificados consecutivos, a serem unidos e classificados em um único intervalo, representando a união entre os dois intervalos de origem.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino, em que os dois intervalos de origem devem ser unidos em um único intervalo classificado, representando a união entre os dois intervalos de origem.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. O predicado binário usa dois argumentos e deve retornar **true** quando o primeiro elemento é menor que o segundo elemento, caso contrário, **false**.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o último elemento no intervalo de destino classificado, que representa a união entre os dois intervalos de origem.

### <a name="remarks"></a>Comentários

Os intervalos de origem classificados referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação.

O intervalo de destino não deve se sobrepor a nenhum dos intervalos de origem e deve ser grande o suficiente para conter o intervalo de destino.

Cada intervalo de origem classificado deve ser organizado como uma pré-condição para a aplicação do algoritmo `merge`, de acordo com a mesma ordenação que deve ser usada pelo algoritmo para classificar os intervalos combinados.

A operação é estável, pois a ordem relativa dos elementos em cada intervalo é preservada no intervalo de destino. Os intervalos de origem não são modificados pelo algoritmo `merge` .

Os tipos de valor dos iteradores de entrada precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Quando há elementos equivalentes nos dois intervalos de origem, os elementos do primeiro intervalo precedem os elementos do segundo intervalo de origem no intervalo de destino. Se os intervalos de origem contiverem duplicatas de um elemento, o intervalo de destino conterá o número máximo dos elementos que ocorrem em ambos os intervalos de origem.

A complexidade do algoritmo é linear com no máximo `2 * ((last1 - first1) - (last2 - first2)) - 1` comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_set_union.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;
    vector<int> v1a, v1b, v1 ( 12 );
    vector<int>::iterator Iter1a, Iter1b, Iter1, Result1;

    // Constructing vectors v1a & v1b with default less than ordering
    int i;
    for ( i = -1 ; i <= 3 ; i++ )
    {
        v1a.push_back( i );
    }

    int ii;
    for ( ii =-3 ; ii <= 1 ; ii++ )
    {
        v1b.push_back( ii );
    }

    cout << "Original vector v1a with range sorted by the\n "
         << "binary predicate less than is v1a = ( " ;
    for ( Iter1a = v1a.begin( ) ; Iter1a != v1a.end( ) ; Iter1a++ )
        cout << *Iter1a << " ";
    cout << ")." << endl;

    cout << "Original vector v1b with range sorted by the\n "
         << "binary predicate less than is v1b = ( " ;
    for ( Iter1b = v1b.begin( ) ; Iter1b != v1b.end( ) ; Iter1b++ )
        cout << *Iter1b << " ";
    cout << ")." << endl;

    // Constructing vectors v2a & v2b with ranges sorted by greater
    vector<int> v2a ( v1a ) , v2b ( v1b ) , v2 ( v1 );
    vector<int>::iterator Iter2a, Iter2b, Iter2, Result2;
    sort ( v2a.begin( ), v2a.end( ), greater<int>( ) );
    sort ( v2b.begin( ), v2b.end( ), greater<int>( ) );

    cout << "Original vector v2a with range sorted by the\n "
         << "binary predicate greater is   v2a = ( " ;
    for ( Iter2a = v2a.begin( ) ; Iter2a != v2a.end( ) ; Iter2a++ )
        cout << *Iter2a << " ";
    cout << ")." << endl;

    cout << "Original vector v2b with range sorted by the\n "
         << "binary predicate greater is   v2b = ( " ;
    for ( Iter2b = v2b.begin( ) ; Iter2b != v2b.end( ) ; Iter2b++ )
        cout << *Iter2b << " ";
    cout << ")." << endl;

    // Constructing vectors v3a & v3b with ranges sorted by mod_lesser
    vector<int> v3a ( v1a ), v3b ( v1b ) , v3 ( v1 );
    vector<int>::iterator Iter3a, Iter3b, Iter3, Result3;
    sort ( v3a.begin( ), v3a.end( ), mod_lesser );
    sort ( v3b.begin( ), v3b.end( ), mod_lesser );

    cout << "Original vector v3a with range sorted by the\n "
         << "binary predicate mod_lesser is   v3a = ( " ;
    for ( Iter3a = v3a.begin( ) ; Iter3a != v3a.end( ) ; Iter3a++ )
        cout << *Iter3a << " ";
    cout << ")." << endl;

    cout << "Original vector v3b with range sorted by the\n "
         << "binary predicate mod_lesser is   v3b = ( " ;
    for ( Iter3b = v3b.begin( ) ; Iter3b != v3b.end( ) ; Iter3b++ )
        cout << *Iter3b << " ";
    cout << ")." << endl;

    // To combine into a union in ascending order with the default
        // binary predicate less<int>( )
    Result1 = set_union ( v1a.begin( ), v1a.end( ),
        v1b.begin( ), v1b.end( ), v1.begin( ) );
    cout << "Union of source ranges with default order,"
         << "\n vector v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != Result1 ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // To combine into a union in descending order, specify binary
    // predicate greater<int>( )
    Result2 = set_union ( v2a.begin( ), v2a.end( ),
        v2b.begin( ), v2b.end( ),v2.begin( ), greater<int>( ) );
    cout << "Union of source ranges with binary predicate greater "
         << "specified,\n vector v2mod = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != Result2 ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    // To combine into a union applying a user-defined
    // binary predicate mod_lesser
    Result3 = set_union ( v3a.begin( ), v3a.end( ),
        v3b.begin( ), v3b.end( ), v3.begin( ), mod_lesser );
    cout << "Union of source ranges with binary predicate "
         << "mod_lesser specified,\n vector v3mod = ( " ; ;
    for ( Iter3 = v3.begin( ) ; Iter3 != Result3 ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;
}
```

## <a name="shuffle"></a><a name="shuffle"></a>embaralha

Embaralha (reorganiza) elementos para um determinado intervalo usando um gerador de número aleatório.

```cpp
template<class RandomAccessIterator, class UniformRandomNumberGenerator>
void shuffle(
    RandomAccessIterator first,
    RandomAccessIterator last,
    UniformRandomNumberGenerator&& gen);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador para o primeiro elemento no intervalo a ser embaralhado, incluindo-o. Deve atender os requisitos de `RandomAccessIterator` e `ValueSwappable`.

*última*\
Um iterador para o último elemento no intervalo a ser embaralhado, excluindo-o. Deve atender os requisitos de `RandomAccessIterator` e `ValueSwappable`.

*geral*\
Um gerador de número aleatório que a função `shuffle()` usará para a operação. Deve atender aos requisitos de um `UniformRandomNumberGenerator`.

### <a name="remarks"></a>Comentários

Para obter mais informações e um exemplo de código que usa o `shuffle()` , consulte [\<random>](random.md) .

## <a name="sort"></a><a name="sort"></a>organizar

Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário.

```cpp
template<class RandomAccessIterator>
void sort(
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class RandomAccessIterator, class Compare>
void sort(
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);

template<class ExecutionPolicy, class RandomAccessIterator>
void sort(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class ExecutionPolicy, class RandomAccessIterator, class Compare>
void sort(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Esse predicado binário usa dois argumentos e retorna **true** se os dois argumentos estiverem em ordem; caso contrário, **false** . Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência. Para obter mais informações, consulte [Algoritmos](algorithms.md).

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Os elementos são equivalentes, mas não necessariamente iguais, quando nenhum é menor que o outro. O algoritmo `sort` não é estável e, portanto, não assegura que a ordenação relativa dos elementos equivalentes será preservada. O algoritmo `stable_sort` preserva essa ordenação original.

A média de uma complexidade de classificação é `O( N log N )` , em que *N*é o  =  *último*  -  *primeiro*.

### <a name="example"></a>Exemplo

```cpp
// alg_sort.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether first element is greater than the second
bool UDgreater ( int elem1, int elem2 )
{
    return elem1 > elem2;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 2 * i );
    }

    int ii;
    for ( ii = 0 ; ii <= 5 ; ii++ )
    {
        v1.push_back( 2 * ii + 1 );
    }

    cout << "Original vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    sort( v1.begin( ), v1.end( ) );
    cout << "Sorted vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // To sort in descending order. specify binary predicate
    sort( v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "Resorted (greater) vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // A user-defined (UD) binary predicate can also be used
    sort( v1.begin( ), v1.end( ), UDgreater );
    cout << "Resorted (UDgreater) vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;
}
```

```Output
Original vector v1 = ( 0 2 4 6 8 10 1 3 5 7 9 11 )
Sorted vector v1 = ( 0 1 2 3 4 5 6 7 8 9 10 11 )
Resorted (greater) vector v1 = ( 11 10 9 8 7 6 5 4 3 2 1 0 )
Resorted (UDgreater) vector v1 = ( 11 10 9 8 7 6 5 4 3 2 1 0 )
```

## <a name="sort_heap"></a><a name="sort_heap"></a>sort_heap

Converte um heap em um intervalo classificado.

```cpp
template<class RandomAccessIterator>
void sort_heap(
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class RandomAccessIterator, class Compare>
void sort_heap(
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Um iterador de acesso aleatório que trata da posição do primeiro elemento no heap de destino.

*última*\
Um iterador de acesso aleatório que trata da posição logo após o elemento final no heap de destino.

*Pred*\
Objeto de função de predicado definido pelo usuário que define o sentido em que um elemento é menor que outro. Um predicado de comparação usa dois argumentos e retorna **true** quando satisfeito e **falso** quando não estiver satisfeito.

### <a name="remarks"></a>Comentários

Os heaps têm duas propriedades:

- O primeiro elemento sempre é o maior.

- Elementos podem ser adicionados ou removidos em tempo logarítmico.

Após a aplicação desse algoritmo, o intervalo no qual ele foi aplicado não é mais um heap.

Essa não é uma classificação estável porque a ordem relativa dos elementos equivalentes não é necessariamente preservada.

Os heaps são a maneira ideal de implementar filas de prioridade e são usados na implementação da [Classe priority_queue](priority-queue-class.md) do adaptador de contêiner da Biblioteca Padrão do C++.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

A complexidade é no máximo `N log N` , em que *N*é o  =  *último*  -  *primeiro*.

### <a name="example"></a>Exemplo

```cpp
// alg_sort_heap.cpp
// compile with: /EHsc
#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

void print(const string& s, const vector<int>& v)
{
    cout << s << ": ( ";

    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << ")" << endl;
}

int main()
{
    vector<int> v;
    for (int i = 1; i <= 9; ++i)
    {
        v.push_back(i);
    }
    print("Initially", v);

    random_shuffle(v.begin(), v.end());
    print("After random_shuffle", v);

    make_heap(v.begin(), v.end());
    print("     After make_heap", v);

    sort_heap(v.begin(), v.end());
    print("     After sort_heap", v);

    random_shuffle(v.begin(), v.end());
    print("             After random_shuffle", v);

    make_heap(v.begin(), v.end(), greater<int>());
    print("After make_heap with greater<int>", v);

    sort_heap(v.begin(), v.end(), greater<int>());
    print("After sort_heap with greater<int>", v);
}
```

## <a name="stable_partition"></a><a name="stable_partition"></a>stable_partition

Classifica os elementos de um intervalo em dois conjuntos separados, com esses elementos atendendo a um predicado unário que precede aqueles que não o atendem, preservando a ordem relativa dos elementos equivalentes.

```cpp
template<class BidirectionalIterator, class UnaryPredicate>
BidirectionalIterator stable_partition(
    BidirectionalIterator first,
    BidirectionalIterator last,
    UnaryPredicate pred );

template<class ExecutionPolicy, class BidirectionalIterator, class UnaryPredicate>
BidirectionalIterator stable_partition(
    ExecutionPolicy&& exec,
    BidirectionalIterator first,
    BidirectionalIterator last,
    UnaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador bidirecional que trata da posição do primeiro elemento no intervalo a ser particionado.

*última*\
Um iterador bidirecional que trata da posição logo após o elemento final no intervalo a ser particionado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define a condição a ser atendida se um elemento precisar ser classificado. Um predicado unário usa um único argumento e retorna **true** se for satisfeito ou **false** se não for satisfeito.

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional que trata da posição do primeiro elemento no intervalo que não atende à condição do predicado.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Os elementos *a* e *b* são equivalentes, mas não necessariamente iguais, se ambos `pred( a, b )` for false e `pred( b, a )` for false, em que *Pred* é o predicado especificado pelo parâmetro. O `stable_partition` algoritmo é estável e garante que a ordenação relativa de elementos equivalentes será preservada. O algoritmo `partition` não preserva necessariamente essa ordenação original.

### <a name="example"></a>Exemplo

```cpp
// alg_stable_partition.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

bool greater5 ( int value )
{
    return value > 5;
}

int main()
{
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2, result;

    int i;
    for ( i = 0 ; i <= 10 ; i++ )
        v1.push_back( i );

    int ii;
    for ( ii = 0 ; ii <= 4 ; ii++ )
        v1.push_back( 5 );

    random_shuffle(v1.begin( ), v1.end( ) );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Partition the range with predicate greater10
    result = stable_partition (v1.begin( ), v1.end( ), greater5 );
    cout << "The partitioned set of elements in v1 is:\n ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "The first element in v1 to fail to satisfy the"
         << "\n predicate greater5 is: " << *result << "." << endl;
}
```

## <a name="stable_sort"></a><a name="stable_sort"></a>stable_sort

Organiza os elementos de um intervalo especificado em ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário e preserva a ordenação relativa de elementos equivalentes.

```cpp
template<class BidirectionalIterator>
void stable_sort(
    BidirectionalIterator first,
    BidirectionalIterator last );

template<class BidirectionalIterator, class Compare>
void stable_sort(
    BidirectionalIterator first,
    BidirectionalIterator last,
    Compare pred );

template<class ExecutionPolicy, class RandomAccessIterator>
void stable_sort(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last);

template<class ExecutionPolicy, class RandomAccessIterator, class Compare>
void stable_sort(
    ExecutionPolicy&& exec,
    RandomAccessIterator first,
    RandomAccessIterator last,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador bidirecional que trata da posição do primeiro elemento no intervalo a ser classificado.

*última*\
Um iterador bidirecional que trata da posição logo após o elemento final no intervalo a ser classificado.

*Pred*\
Objeto de função de predicado definido pelo usuário que define os critérios de comparação a serem atendidos pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="remarks"></a>Comentários

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Os elementos são equivalentes, mas não necessariamente iguais, quando nenhum é menor que o outro. O `sort` algoritmo é estável e garante que a ordenação relativa de elementos equivalentes será preservada.

A complexidade do tempo de execução do `stable_sort` depende da quantidade de memória disponível, mas o melhor caso (com memória suficiente) é `O(N log N)` e o pior caso é `O(N (log N)^2)` , em que *N*é o  =  *último*  -  *primeiro*. Normalmente, o `sort` algoritmo é significativamente mais rápido do que `stable_sort` .

### <a name="example"></a>Exemplo

```cpp
// alg_stable_sort.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether first element is greater than the second
bool UDgreater (int elem1, int elem2 )
{
    return elem1 > elem2;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter1;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 2 * i );
    }

    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( 2 * i );
    }

    cout << "Original vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    stable_sort(v1.begin( ), v1.end( ) );
    cout << "Sorted vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // To sort in descending order, specify binary predicate
    stable_sort(v1.begin( ), v1.end( ), greater<int>( ) );
    cout << "Resorted (greater) vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;

    // A user-defined (UD) binary predicate can also be used
    stable_sort(v1.begin( ), v1.end( ), UDgreater );
    cout << "Resorted (UDgreater) vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")" << endl;
}
```

```Output
Original vector v1 = ( 0 2 4 6 8 10 0 2 4 6 8 10 )
Sorted vector v1 = ( 0 0 2 2 4 4 6 6 8 8 10 10 )
Resorted (greater) vector v1 = ( 10 10 8 8 6 6 4 4 2 2 0 0 )
Resorted (UDgreater) vector v1 = ( 10 10 8 8 6 6 4 4 2 2 0 0 )
```

## <a name="swap"></a><a name="swap"></a>permuta

A primeira substituição troca os valores de dois objetos. A segunda substituição troca os valores entre duas matrizes de objetos.

```cpp
template<class Type>
void swap(
    Type& left,
    Type& right);
template<class Type, size_t N>
void swap(
    Type (& left)[N],
    Type (& right)[N]);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Para a primeira substituição, o primeiro objeto a ter seu conteúdo trocado. Para a segunda substituição, a primeira matriz de objetos a ter seu conteúdo trocado.

*Certo*\
Para a primeira substituição, o segundo objeto a ter seu conteúdo trocado. Para a segunda substituição, a segunda matriz de objetos a ter seu conteúdo trocado.

### <a name="remarks"></a>Comentários

A primeira sobrecarga é projetada para operar em objetos individuais. A segunda sobrecarga troca o conteúdo dos objetos entre duas matrizes.

### <a name="example"></a>Exemplo

```cpp
// alg_swap.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2, result;

    for ( int i = 0 ; i <= 10 ; i++ )
    {
        v1.push_back( i );
    }

    for ( int ii = 0 ; ii <= 4 ; ii++ )
    {
        v2.push_back( 5 );
    }

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Vector v2 is ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    swap( v1, v2 );

    cout << "Vector v1 is ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    cout << "Vector v2 is ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;
}
```

```Output
Vector v1 is ( 0 1 2 3 4 5 6 7 8 9 10 ).
Vector v2 is ( 5 5 5 5 5 ).
Vector v1 is ( 5 5 5 5 5 ).
Vector v2 is ( 0 1 2 3 4 5 6 7 8 9 10 ).
```

## <a name="swap_ranges"></a><a name="swap_ranges"></a>swap_ranges

Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.

```cpp
template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 swap_ranges(
   ForwardIterator1 first1,
   ForwardIterator1 last1,
   ForwardIterator2 first2 );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 swap_ranges(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de avanço que aponta para a primeira posição do primeiro intervalo cujos elementos devem ser trocados.

*last1*\
Um iterador de avanço que aponta para a posição logo após a posição final do primeiro intervalo cujos elementos devem ser trocados.

*first2*\
Um iterador de avanço que aponta para a primeira posição do segundo intervalo cujos elementos devem ser trocados.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que aponta para a posição logo após a posição final do segundo intervalo cujos elementos devem ser trocados.

### <a name="remarks"></a>Comentários

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação. O segundo intervalo precisa ser tão grande quanto o primeiro intervalo.

A complexidade é linear com *last1*  -  *first1* permutações executadas. Se elementos de contêineres do mesmo tipo forem trocados, a função de membro `swap` desse contêiner deverá ser usada, porque a função de membro normalmente tem uma complexidade constante.

### <a name="example"></a>Exemplo

```cpp
// alg_swap_ranges.cpp
// compile with: /EHsc
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1;
    deque<int> d1;
    vector<int>::iterator v1Iter1;
    deque<int>::iterator d1Iter1;

    int i;
    for ( i = 0 ; i <= 5 ; i++ )
    {
        v1.push_back( i );
    }

    int ii;
    for ( ii =4 ; ii <= 9 ; ii++ )
    {
        d1.push_back( 6 );
    }

    cout << "Vector v1 is ( " ;
    for ( v1Iter1 = v1.begin( ) ; v1Iter1 != v1.end( ) ;v1Iter1 ++ )
        cout << *v1Iter1 << " ";
    cout << ")." << endl;

    cout << "Deque d1 is  ( " ;
    for ( d1Iter1 = d1.begin( ) ; d1Iter1 != d1.end( ) ;d1Iter1 ++ )
        cout << *d1Iter1 << " ";
    cout << ")." << endl;

    swap_ranges ( v1.begin( ), v1.end( ), d1.begin( ) );

    cout << "After the swap_range, vector v1 is ( " ;
    for ( v1Iter1 = v1.begin( ) ; v1Iter1 != v1.end( ) ;v1Iter1 ++ )
        cout << *v1Iter1 << " ";
    cout << ")." << endl;

    cout << "After the swap_range deque d1 is   ( " ;
    for ( d1Iter1 = d1.begin( ) ; d1Iter1 != d1.end( ) ;d1Iter1 ++ )
        cout << *d1Iter1 << " ";
    cout << ")." << endl;
}
```

```Output
Vector v1 is ( 0 1 2 3 4 5 ).
Deque d1 is  ( 6 6 6 6 6 6 ).
After the swap_range, vector v1 is ( 6 6 6 6 6 6 ).
After the swap_range deque d1 is   ( 0 1 2 3 4 5 ).
```

## <a name="transform"></a><a name="transform"></a>tenha

Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino.

```cpp
template<class InputIterator, class OutputIterator, class UnaryFunction>
OutputIterator transform(
    InputIterator first1,
    InputIterator last1,
    OutputIterator result,
    UnaryFunction func );

template<class InputIterator1, class InputIterator2, class OutputIterator, class BinaryFunction>
OutputIterator transform(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    OutputIterator result,
    BinaryFunction func );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class UnaryOperation>
ForwardIterator2 transform(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    UnaryOperation op);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class ForwardIterator, class BinaryOperation>
ForwardIterator transform(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    ForwardIterator result,
    BinaryOperation binary_op);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*first1*\
Um iterador de entrada que trata da posição do primeiro elemento no primeiro intervalo de origem no qual a operação ocorrerá.

*last1*\
Um iterador de entrada que trata da posição logo após o elemento final no primeiro intervalo de origem no qual a operação ocorrerá.

*first2*\
Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo de origem no qual a operação ocorrerá.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino.

*Func*\
Objeto de função unário definido pelo usuário usado na primeira versão do algoritmo que é aplicado a cada elemento no primeiro intervalo de origem ou um objeto de função binário UD (definido pelo usuário) usado na segunda versão do algoritmo que é aplicado em pares, em uma ordem progressiva, nos dois intervalos de origem.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o elemento final no intervalo de destino que está recebendo os elementos de saída transformados pelo objeto de função.

### <a name="remarks"></a>Comentários

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de cada sequência, a última posição deve ser acessível a partir da primeira por incrementação. O intervalo de destino deve ser grande o suficiente para conter o intervalo de origem transformado.

Se o *resultado* for definido como igual a *first1* na primeira versão do algoritmo, os intervalos de origem e de destino serão os mesmos e a sequência será modificada no local. Mas o *resultado* pode não tratar de uma posição dentro do intervalo [ `first1` + 1, `last1` ).

A complexidade é linear com no máximo ( `last1`  -  `first1` ) comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_transform.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

// The function object multiplies an element by a Factor
template <class Type>
class MultValue
{
private:
    Type Factor;   // The value to multiply by
public:
    // Constructor initializes the value to multiply by
    MultValue ( const Type& value ) : Factor ( value ) { }

    // The function call for the element to be multiplied
    Type operator( ) ( Type& elem ) const
    {
        return elem * Factor;
    }
};

int main()
{
    using namespace std;
    vector<int> v1, v2 ( 7 ), v3 ( 7 );
    vector<int>::iterator Iter1, Iter2 , Iter3;

    // Constructing vector v1
    int i;
    for ( i = -4 ; i <= 2 ; i++ )
    {
        v1.push_back( i );
    }

    cout << "Original vector v1 = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Modifying the vector v1 in place
    transform (v1.begin( ), v1.end( ), v1.begin( ), MultValue<int> ( 2 ) );
    cout << "The elements of the vector v1 multiplied by 2 in place gives:"
            << "\n v1mod = ( " ;
    for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 << " ";
    cout << ")." << endl;

    // Using transform to multiply each element by a factor of 5
    transform ( v1.begin( ), v1.end( ), v2.begin( ), MultValue<int> ( 5 ) );

    cout << "Multiplying the elements of the vector v1mod\n "
            << "by the factor 5 & copying to v2 gives:\n v2 = ( " ;
    for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 << " ";
    cout << ")." << endl;

    // The second version of transform used to multiply the
    // elements of the vectors v1mod & v2 pairwise
    transform ( v1.begin( ), v1.end( ), v2.begin( ), v3.begin( ),
        multiplies<int>( ) );

    cout << "Multiplying elements of the vectors v1mod and v2 pairwise "
            << "gives:\n v3 = ( " ;
    for ( Iter3 = v3.begin( ) ; Iter3 != v3.end( ) ; Iter3++ )
        cout << *Iter3 << " ";
    cout << ")." << endl;
}
```

```Output
Original vector v1 = ( -4 -3 -2 -1 0 1 2 ).
The elements of the vector v1 multiplied by 2 in place gives:
v1mod = ( -8 -6 -4 -2 0 2 4 ).
Multiplying the elements of the vector v1mod
by the factor 5 & copying to v2 gives:
v2 = ( -40 -30 -20 -10 0 10 20 ).
Multiplying elements of the vectors v1mod and v2 pairwise gives:
v3 = ( 320 180 80 20 0 20 80 ).
```

## <a name="unique"></a><a name="unique"></a>diferente

Remove elementos duplicados que são adjacentes um ao outro em um intervalo especificado.

```cpp
template<class ForwardIterator>
ForwardIterator unique(
    ForwardIterator first,
    ForwardIterator last);

template<class ForwardIterator, class BinaryPredicate>
ForwardIterator unique(
    ForwardIterator first,
    ForwardIterator last,
    BinaryPredicate pred);

template<class ExecutionPolicy, class ForwardIterator>
ForwardIterator unique(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class BinaryPredicate>
ForwardIterator unique(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento no intervalo a ser verificado quanto à remoção de duplicatas.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final no intervalo a ser verificado quanto à remoção de duplicatas.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço para o novo final da sequência modificada que não contém nenhuma duplicata consecutiva, tratando da posição logo após o último elemento não removido.

### <a name="remarks"></a>Comentários

As duas formas de algoritmo removem a segunda duplicata de um par consecutivo de elementos iguais.

A operação do algoritmo é estável, de modo que a ordem relativa dos elementos não excluídos não é alterada.

O intervalo referenciado deve ser válido; todos os ponteiros devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação. o número de elementos na sequência não é alterado pelo algoritmo `unique` e os elementos além do final da sequência modificada são de referência, mas não especificados.

A complexidade é linear, exigindo `(last - first) - 1` comparações.

A lista fornece uma função de membro "unique" mais eficiente, que poderá ter um desempenho melhor.

Esses algoritmos não podem ser usados em um contêiner associativo.

### <a name="example"></a>Exemplo

```cpp
// alg_unique.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>

using namespace std;

// Return whether modulus of elem1 is equal to modulus of elem2
bool mod_equal ( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 == elem2;
};

int main()
{
    vector<int> v1;
    vector<int>::iterator v1_Iter1, v1_Iter2, v1_Iter3,
            v1_NewEnd1, v1_NewEnd2, v1_NewEnd3;

    int i;
    for ( i = 0 ; i <= 3 ; i++ )
    {
        v1.push_back( 5 );
        v1.push_back( -5 );
    }

    int ii;
    for ( ii = 0 ; ii <= 3 ; ii++ )
    {
        v1.push_back( 4 );
    }
    v1.push_back( 7 );

    cout << "Vector v1 is ( " ;
    for ( v1_Iter1 = v1.begin( ) ; v1_Iter1 != v1.end( ) ; v1_Iter1++ )
        cout << *v1_Iter1 << " ";
    cout << ")." << endl;

    // Remove consecutive duplicates
    v1_NewEnd1 = unique ( v1.begin( ), v1.end( ) );

    cout << "Removing adjacent duplicates from vector v1 gives\n ( " ;
    for ( v1_Iter1 = v1.begin( ) ; v1_Iter1 != v1_NewEnd1 ; v1_Iter1++ )
        cout << *v1_Iter1 << " ";
    cout << ")." << endl;

    // Remove consecutive duplicates under the binary prediate mod_equals
    v1_NewEnd2 = unique ( v1.begin( ), v1_NewEnd1 , mod_equal );

    cout << "Removing adjacent duplicates from vector v1 under the\n "
            << " binary predicate mod_equal gives\n ( " ;
    for ( v1_Iter2 = v1.begin( ) ; v1_Iter2 != v1_NewEnd2 ; v1_Iter2++ )
        cout << *v1_Iter2 << " ";
    cout << ")." << endl;

    // Remove elements if preceded by an element that was greater
    v1_NewEnd3 = unique ( v1.begin( ), v1_NewEnd2, greater<int>( ) );

    cout << "Removing adjacent elements satisfying the binary\n "
            << " predicate mod_equal from vector v1 gives ( " ;
    for ( v1_Iter3 = v1.begin( ) ; v1_Iter3 != v1_NewEnd3 ; v1_Iter3++ )
        cout << *v1_Iter3 << " ";
    cout << ")." << endl;
}
```

```Output
Vector v1 is ( 5 -5 5 -5 5 -5 5 -5 4 4 4 4 7 ).
Removing adjacent duplicates from vector v1 gives
( 5 -5 5 -5 5 -5 5 -5 4 7 ).
Removing adjacent duplicates from vector v1 under the
  binary predicate mod_equal gives
( 5 4 7 ).
Removing adjacent elements satisfying the binary
  predicate mod_equal from vector v1 gives ( 5 7 ).
```

## <a name="unique_copy"></a><a name="unique_copy"></a>unique_copy

Copia elementos de um intervalo de origem em um intervalo de destino, exceto os elementos duplicados que são adjacentes um ao outro.

```cpp
template<class InputIterator, class OutputIterator>
OutputIterator unique_copy(
    InputIterator first,
    InputIterator last,
    OutputIterator result );

template<class InputIterator, class OutputIterator, class BinaryPredicate>
OutputIterator unique_copy(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryPredicate pred );

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 unique_copy(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2,
class BinaryPredicate>
ForwardIterator2 unique_copy(ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    BinaryPredicate pred);
```

### <a name="parameters"></a>Parâmetros

*exec*\
A política de execução a ser usada.

*primeiro*\
Um iterador de avanço que trata da posição do primeiro elemento no intervalo de origem a ser copiado.

*última*\
Um iterador de avanço que trata da posição logo após o elemento final no intervalo de origem a ser copiado.

*disso*\
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino que está recebendo a cópia com as duplicatas consecutivas removidas.

*Pred*\
Objeto de função de predicado definido pelo usuário, que define a condição a ser atendida se dois elementos forem executados como equivalentes. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o elemento final no intervalo de destino que está recebendo a cópia com as duplicatas consecutivas removidas.

### <a name="remarks"></a>Comentários

As duas formas de algoritmo removem a segunda duplicata de um par consecutivo de elementos iguais.

A operação do algoritmo é estável, de modo que a ordem relativa dos elementos não excluídos não é alterada.

Os intervalos referenciados devem ser válidos, todos os ponteiros devem ser desreferenciáveis e, dentro de uma sequência, a última posição deve ser acessível a partir da primeira por incrementação.

A complexidade é linear, exigindo ( `last`  -  `first` ) comparações.

### <a name="example"></a>Exemplo

```cpp
// alg_unique_copy.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>

using namespace std;

// Return whether modulus of elem1 is equal to modulus of elem2
bool mod_equal ( int elem1, int elem2 ) {
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 == elem2;
};

int main() {
    vector<int> v1;
    vector<int>::iterator v1_Iter1, v1_Iter2,
            v1_NewEnd1, v1_NewEnd2;

    int i;
    for ( i = 0 ; i <= 1 ; i++ ) {
        v1.push_back( 5 );
        v1.push_back( -5 );
    }

    int ii;
    for ( ii = 0 ; ii <= 2 ; ii++ )
        v1.push_back( 4 );
    v1.push_back( 7 );

    int iii;
    for ( iii = 0 ; iii <= 5 ; iii++ )
        v1.push_back( 10 );

    cout << "Vector v1 is\n ( " ;
    for ( v1_Iter1 = v1.begin( ) ; v1_Iter1 != v1.end( ) ; v1_Iter1++ )
        cout << *v1_Iter1 << " ";
    cout << ")." << endl;

    // Copy first half to second, removing consecutive duplicates
    v1_NewEnd1 = unique_copy ( v1.begin( ), v1.begin( ) + 8, v1.begin( ) + 8 );

    cout << "Copying the first half of the vector to the second half\n "
            << "while removing adjacent duplicates gives\n ( " ;
    for ( v1_Iter1 = v1.begin( ) ; v1_Iter1 != v1_NewEnd1 ; v1_Iter1++ )
        cout << *v1_Iter1 << " ";
    cout << ")." << endl;

    int iv;
    for ( iv = 0 ; iv <= 7 ; iv++ )
        v1.push_back( 10 );

    // Remove consecutive duplicates under the binary prediate mod_equals
    v1_NewEnd2 = unique_copy ( v1.begin( ), v1.begin( ) + 14,
        v1.begin( ) + 14 , mod_equal );

    cout << "Copying the first half of the vector to the second half\n "
            << " removing adjacent duplicates under mod_equals gives\n ( " ;
    for ( v1_Iter2 = v1.begin( ) ; v1_Iter2 != v1_NewEnd2 ; v1_Iter2++ )
        cout << *v1_Iter2 << " ";
    cout << ")." << endl;
}
```

## <a name="upper_bound"></a><a name="upper_bound"></a>upper_bound

Localiza a posição do primeiro elemento em um intervalo ordenado com um valor que é maior a um valor especificado, em que o critério de ordenação pode ser especificado por um predicado binário.

```cpp
template<class ForwardIterator, class Type>
ForwardIterator upper_bound(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value);

template<class ForwardIterator, class Type, class Compare>
ForwardIterator upper_bound(
    ForwardIterator first,
    ForwardIterator last,
    const Type& value,
    Compare pred);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
A posição do primeiro elemento no intervalo a ser pesquisado.

*última*\
A posição logo após o elemento final no intervalo a ser pesquisado.

*valor*\
O valor no intervalo ordenado que precisa ser excedido pelo valor do elemento tratado pelo iterador retornado.

*Pred*\
Objeto de função de predicado de comparação definido pelo usuário que define o sentido no qual um elemento é menor do que o outro. Um predicado de comparação usa dois argumentos e retorna **true** quando satisfeito e **falso** quando não estiver satisfeito.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço para a posição do primeiro elemento que tem um valor maior que um valor especificado.

### <a name="remarks"></a>Comentários

O intervalo de origem classificado referenciado deve ser válido, todos os iteradores devem ser desreferenciáveis e, dentro da sequência, a última posição deve ser acessível desde a primeira por incrementação.

Um intervalo classificado é uma pré-condição do uso de `upper_bound` e onde o critério de ordenação é o mesmo especificado pelo predicado de comparação.

O intervalo não é modificado por `upper_bound`.

Os tipos de valor dos iteradores de avanço precisam ser comparáveis como “menores que” para serem ordenados, de modo que, considerando dois elementos, possa ser determinado que eles são equivalentes (no sentido de que nenhum é menor que o outro) ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes

A complexidade do algoritmo é logarítmica para iteradores de acesso aleatório e linear, caso contrário, com o número de etapas proporcionais a ( `last - first` ).

### <a name="example"></a>Exemplo

```cpp
// alg_upper_bound.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser( int elem1, int elem2 )
{
    if ( elem1 < 0 )
        elem1 = - elem1;
    if ( elem2 < 0 )
        elem2 = - elem2;
    return elem1 < elem2;
}

int main()
{
    using namespace std;

    vector<int> v1;
    // Constructing vector v1 with default less-than ordering
    for ( auto i = -1 ; i <= 4 ; ++i )
    {
        v1.push_back( i );
    }

    for ( auto ii =-3 ; ii <= 0 ; ++ii )
    {
        v1.push_back( ii );
    }

    cout << "Starting vector v1 = ( " ;
    for (const auto &Iter : v1)
        cout << Iter << " ";
    cout << ")." << endl;

    sort(v1.begin(), v1.end());
    cout << "Original vector v1 with range sorted by the\n "
        << "binary predicate less than is v1 = ( " ;
    for (const auto &Iter : v1)
        cout << Iter << " ";
    cout << ")." << endl;

    // Constructing vector v2 with range sorted by greater
    vector<int> v2(v1);

    sort(v2.begin(), v2.end(), greater<int>());

    cout << "Original vector v2 with range sorted by the\n "
        << "binary predicate greater is v2 = ( " ;
    for (const auto &Iter : v2)
        cout << Iter << " ";
    cout << ")." << endl;

    // Constructing vectors v3 with range sorted by mod_lesser
    vector<int> v3(v1);
    sort(v3.begin(), v3.end(), mod_lesser);

    cout << "Original vector v3 with range sorted by the\n "
        << "binary predicate mod_lesser is v3 = ( " ;
    for (const auto &Iter : v3)
        cout << Iter << " ";
    cout << ")." << endl;

    // Demonstrate upper_bound

    vector<int>::iterator Result;

    // upper_bound of 3 in v1 with default binary predicate less<int>()
    Result = upper_bound(v1.begin(), v1.end(), 3);
    cout << "The upper_bound in v1 for the element with a value of 3 is: "
        << *Result << "." << endl;

    // upper_bound of 3 in v2 with the binary predicate greater<int>( )
    Result = upper_bound(v2.begin(), v2.end(), 3, greater<int>());
    cout << "The upper_bound in v2 for the element with a value of 3 is: "
        << *Result << "." << endl;

    // upper_bound of 3 in v3 with the binary predicate mod_lesser
    Result = upper_bound(v3.begin(), v3.end(), 3, mod_lesser);
    cout << "The upper_bound in v3 for the element with a value of 3 is: "
        << *Result << "." << endl;
}
```
