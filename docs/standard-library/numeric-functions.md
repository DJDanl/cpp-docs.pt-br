---
title: Funções &lt;numeric&gt;
description: Descreve os modelos de função fornecidos pelo cabeçalho &lt;numérico&gt;na biblioteca C++ padrão.
ms.date: 10/30/2019
f1_keywords:
- numeric/std::accumulate
- numeric/std::adjacent_difference
- numeric/std::exclusive_scan
- numeric/std::gcd
- numeric/std::inclusive_scan
- numeric/std::inner_product
- numeric/std::iota
- numeric/std::lcm
- numeric/std::partial_sum
- numeric/std::reduce
- numeric/std::transform_exclusive_scan
- numeric/std::transform_inclusive_scan
- numeric/std::transform_reduce
ms.assetid: a4b0449a-c80c-4a1d-8d9f-d7fcd0058f8b
helpviewer_keywords:
- std::accumulate [C++]
- std::adjacent_difference [C++]
- std::exclusive_scan [C++]
- std::gcd [C++]
- std::inclusive_scan [C++]
- std::inner_product [C++]
- std::iota [C++]
- std::lcm [C++]
- std::partial_sum [C++]
- std::reduce [C++]
- std::transform_exclusive_scan [C++]
- std::transform_inclusive_scan [C++]
- std::transform_reduce [C++]
ms.openlocfilehash: 88a97a3d110c684090b78570077927e32541eed7
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627454"
---
# <a name="ltnumericgt-functions"></a>Funções &lt;numeric&gt;

## <a name="accumulate"></a>acumular

Computa a soma de todos os elementos em um intervalo especificado, incluindo um valor inicial, computando somas parciais sucessivas. Ou, computa o resultado de resultados parciais sucessivos de uma operação binária especificada.

```cpp
template <class InputIterator, class Type>
Type accumulate(
    InputIterator first,
    InputIterator last,
    Type init);

template <class InputIterator, class Type, class BinaryOperation>
Type accumulate(
    InputIterator first,
    InputIterator last,
    Type init,
    BinaryOperation binary_op);
```

### <a name="parameters"></a>Parâmetros

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

### <a name="return-value"></a>Valor retornado

A soma de *init* e todos os elementos no intervalo especificado para a primeira função de modelo, ou, para a segunda função de modelo, o resultado da aplicação da operação binária *binary_op* em vez da operação Sum, a (* PartialResult, *in_ ITER*), em que *PartialResult* é o resultado de aplicativos anteriores da operação e *in_iter* é um iterador que aponta para o próximo elemento no intervalo.

### <a name="remarks"></a>Comentários

O valor inicial garante que haja um resultado bem definido quando o intervalo estiver vazio, caso em que *init* é retornado. A operação binária não precisa ser associativa ou comutadora. O resultado é inicializado para o valor inicial *init* e, em seguida, *resultado* = *binary_op*(*Result*, *in_iter*) é calculado iterativamente por meio do intervalo, em que *in_iter* é um iterador que aponta para cada elemento sucessivo no intervalo. O intervalo deve ser válido e a complexidade é linear com o tamanho do intervalo. O tipo de retorno do operador binário deve ser conversível para **Type** para garantir o fechamento durante a iteração.

### <a name="example"></a>Exemplo

```cpp
// numeric_accum.cpp
// compile with: /EHsc
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

int main( )
{
   using namespace std;

   vector <int> v1, v2(20);
   vector <int>::iterator iter1, iter2;

   int i;
   for (i = 1; i < 21; i++)
   {
      v1.push_back(i);
   }

   cout << "The original vector v1 is:\n ( " ;
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
      cout << *iter1 << " ";
   cout << ")." << endl;

   // The first member function for the accumulated sum
   int total;
   total = accumulate(v1.begin(), v1.end(), 0);

   cout << "The sum of the integers from 1 to 20 is: "
        << total << "." << endl;

   // Constructing a vector of partial sums
   int j = 0, partotal;
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
   {
      partotal = accumulate(v1.begin(), iter1 + 1, 0);
      v2[j] = partotal;
      j++;
   }

   cout << "The vector of partial sums is:\n ( " ;
   for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)
      cout << *iter2 << " ";
   cout << ")." << endl << endl;

   // The second member function for the accumulated product
   vector <int> v3, v4(10);
   vector <int>::iterator iter3, iter4;

   int s;
   for (s = 1; s < 11; s++)
   {
      v3.push_back(s);
   }

   cout << "The original vector v3 is:\n ( " ;
   for (iter3 = v3.begin(); iter3 != v3.end(); iter3++)
      cout << *iter3 << " ";
   cout << ")." << endl;

   int ptotal;
   ptotal = accumulate(v3.begin(), v3.end(), 1, multiplies<int>());

   cout << "The product of the integers from 1 to 10 is: "
        << ptotal << "." << endl;

   // Constructing a vector of partial products
   int k = 0, ppartotal;
   for (iter3 = v3.begin(); iter3 != v3.end(); iter3++) {
      ppartotal = accumulate(v3.begin(), iter3 + 1, 1, multiplies<int>());
      v4[k] = ppartotal;
      k++;
   }

   cout << "The vector of partial products is:\n ( " ;
   for (iter4 = v4.begin(); iter4 != v4.end(); iter4++)
      cout << *iter4 << " ";
   cout << ")." << endl;
}
```

```Output
The original vector v1 is:
( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ).
The sum of the integers from 1 to 20 is: 210.
The vector of partial sums is:
( 1 3 6 10 15 21 28 36 45 55 66 78 91 105 120 136 153 171 190 210 ).

The original vector v3 is:
( 1 2 3 4 5 6 7 8 9 10 ).
The product of the integers from 1 to 10 is: 3628800.
The vector of partial products is:
( 1 2 6 24 120 720 5040 40320 362880 3628800 ).
```

## <a name="adjacent_difference"></a>adjacent_difference

Computa as diferenças sucessivas entre cada elemento e seu predecessor em um intervalo de entrada. Gera os resultados para um intervalo de destino. Ou, computa o resultado de um procedimento generalizado em que a operação de diferença é substituída por outra operação binária especificada.

```cpp
template <class InputIterator, class OutIterator>
OutputIterator adjacent_difference(
    InputIterator first,
    InputIterator last,
    OutputIterator result);

template <class InputIterator, class OutIterator, class BinaryOperation>
OutputIterator adjacent_difference(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryOperation binary_op);

template <class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 adjacent_difference(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result);

template <class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2,
class BinaryOperation>
ForwardIterator2 adjacent_difference(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    BinaryOperation binary_op);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que trata o primeiro elemento no intervalo de entrada cujos elementos deverão ser diferenciados com seus respectivos antecessores ou onde o par de valores deverá ser operado por qualquer outra operação binária especificada.

*última* \
Um iterador de entrada que trata o último elemento no intervalo de entrada cujos elementos deverão ser diferenciados com seus respectivos antecessores ou onde o par de valores deverá ser operado por qualquer outra operação binária especificada.

\ de *resultado*
Um iterador de saída que trata o primeiro elemento em um intervalo de destino onde a série de diferenças ou os resultados da operação especificada deverão ser armazenados.

\ *binary_op*
A operação binária a ser aplicada na operação generalizada, substituindo a operação de subtração no procedimento de diferenciação.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda o final do intervalo de destino: `result` + (`last` - `first`).

### <a name="remarks"></a>Comentários

O *resultado* do iterador de saída pode ser o mesmo iterador que o iterador de entrada *primeiro*, para que `adjacent_difference` valores possam ser computados no local.

Para *uma sequência de valores de*1, *um*2, *um*3, em um intervalo de entrada, a primeira função de modelo armazena valores de `adjacent_difference` sucessivas *um*1, *um*2- *a*1, a3- *a*2, no intervalo de destino.

Para *uma sequência de valores de*1, *um*2, *um*3, em um intervalo de entrada, a segunda função de modelo armazena valores de `adjacent_difference` sucessivas *um*1, *um*2 *binary_op* *a*1, *um*3 *binary_op* *a*2, em o intervalo de destino.

A operação binária *binary_op* não deve ser associativa ou comutadora, pois a ordem das operações aplicadas é especificada.

### <a name="example"></a>Exemplo

```cpp
// numeric_adj_diff.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <iostream>

int main( )
{
   using namespace std;

   vector<int> V1( 10 ), V2( 10 );
   vector<int>::iterator VIter1, VIter2, VIterend, VIterend2;

   list <int> L1;
   list <int>::iterator LIter1, LIterend, LIterend2;

   int t;
   for ( t = 1 ; t <= 10 ; t++ )
   {
      L1.push_back( t * t );
   }

   cout << "The input list L1 is:\n ( " ;
   for ( LIter1 = L1.begin( ) ; LIter1 != L1.end( ) ; LIter1++ )
      cout << *LIter1 << " ";
   cout << ")." << endl;

   // The first member function for the adjacent_differences of
   // elements in a list output to a vector
   VIterend = adjacent_difference ( L1.begin ( ) , L1.end ( ) ,
      V1.begin ( ) );

   cout << "Output vector containing adjacent_differences is:\n ( " ;
   for ( VIter1 = V1.begin( ) ; VIter1 != VIterend ; VIter1++ )
      cout << *VIter1 << " ";
   cout << ")." << endl;

   // The second member function used to compute
   // the adjacent products of the elements in a list
   VIterend2 = adjacent_difference ( L1.begin ( ) , L1.end ( ) , V2.begin ( ) ,
      multiplies<int>( ) );

   cout << "The output vector with the adjacent products is:\n ( " ;
   for ( VIter2 = V2.begin( ) ; VIter2 != VIterend2 ; VIter2++ )
      cout << *VIter2 << " ";
   cout << ")." << endl;

   // Computation of adjacent_differences in place
   LIterend2 = adjacent_difference ( L1.begin ( ) , L1.end ( ) , L1.begin ( ) );
   cout << "In place output adjacent_differences in list L1 is:\n ( " ;
   for ( LIter1 = L1.begin( ) ; LIter1 != LIterend2 ; LIter1++ )
      cout << *LIter1 << " ";
   cout << ")." << endl;
}
```

## <a name="exclusive_scan"></a>exclusive_scan

Computa uma operação de soma de prefixo exclusiva usando o `std::plus<>()` ou um operador binário especificado em um intervalo, dado um valor inicial. Grava os resultados no intervalo que começa no destino especificado. Uma soma de *prefixo exclusiva* significa que o elemento *n*-th Input não está incluído na soma *n*. Sobrecargas que incluem um argumento de política de execução são executados de acordo com a política especificada.

```cpp
template<class InputIterator, class OutputIterator, class Type>
OutputIterator exclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    Type init);

template<class InputIterator, class OutputIterator, class Type, class BinaryOperation>
OutputIterator exclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    Type init,
    BinaryOperation binary_op);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type>
ForwardIterator2 exclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    Type init);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type, class BinaryOperation>
ForwardIterator2 exclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    Type init,
    BinaryOperation binary_op);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento um intervalo de destino em que a série de somas ou os resultados da operação especificada deve ser armazenado.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda o final do intervalo de destino: *resultado* + (*último* - *primeiro*).

## <a name="gcd"></a>GCD

Computa o maior divisor comum dos inteiros m e n.

```cpp
template <class M, class N>
constexpr common_type_t<M,N> gcd(M m, N n);
```

### <a name="parameters"></a>Parâmetros

*m*, *n*\
Valores do tipo integral.

### <a name="return-value"></a>Valor retornado

Retorna o maior divisor comum dos valores absolutos de *m* e *n*, ou zero se *m* e *n* forem zero. Os resultados serão indefinidos se os valores absolutos de *m* ou *n* não forem representáveis como valores do tipo `common_type_t<M,N>`.

## <a name="inclusive_scan"></a>inclusive_scan

Computa uma operação de soma de prefixo inclusiva usando `std::plus<>()` ou um operador binário especificado em um intervalo, dado um valor inicial. Grava os resultados no intervalo que começa no destino especificado. Uma soma de *prefixo inclusiva* significa que o elemento *n*-th Input está incluído na soma *n*. Sobrecargas que incluem um argumento de política de execução são executados de acordo com a política especificada.

```cpp
template<class InputIterator, class OutputIterator>
OutputIterator inclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result);

template<class InputIterator, class OutputIterator, class BinaryOperation>
OutputIterator inclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryOperation binary_op);

template<class InputIterator, class OutputIterator, class BinaryOperation, class Type>
OutputIterator inclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryOperation binary_op,
    Type init);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 inclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2,
class BinaryOperation>
ForwardIterator2 inclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    BinaryOperation binary_op);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2,
class BinaryOperation, class Type>
ForwardIterator2 inclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    BinaryOperation binary_op,
    Type init);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento um intervalo de destino em que a série de somas ou os resultados da operação especificada deve ser armazenado.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda o final do intervalo de destino: *resultado* + (*último* - *primeiro*).

## <a name="inner_product"></a>inner_product

Calcula a soma do produto em relação ao elemento de dois intervalos e a adiciona a um valor inicial especificado ou calcula o resultado de um procedimento generalizado, em que as operações binárias de produto e a soma são substituídas por outras operações binárias especificadas.

```cpp
template <class InputIterator1, class InputIterator2, class Type>
Type inner_product(
    InputIterator1   first1,
    InputIterator1   last1,
    InputIterator2   first2,
    Type             init);

template <class InputIterator1, class InputIterator2, class Type, class BinaryOperation1, class BinaryOperation2>
Type inner_product(
    InputIterator1   first1,
    InputIterator1   last1,
    InputIterator2   first2,
    Type             init,
    BinaryOperation1 binary_op1,
    BinaryOperation2 binary_op2);
```

### <a name="parameters"></a>Parâmetros

\ *first1*
Um iterador de entrada que trata o primeiro elemento no primeiro intervalo cujo produto interno ou produto interno generalizado com o segundo intervalo deverá ser calculado.

\ *last1*
Um iterador de entrada que trata o último elemento no primeiro intervalo cujo produto interno ou produto interno generalizado com o segundo intervalo deverá ser calculado.

\ *first2*
Um iterador de entrada que trata o primeiro elemento no segundo intervalo cujo produto interno ou produto interno generalizado com o primeiro intervalo deverá ser calculado.

\ de *inicialização*
Um valor inicial para o qual deve ser adicionado o produto interno ou o produto interno generalizado entre os intervalos.

\ *binary_op1*
A operação binária que substitui a operação de produto interna da soma aplicada aos produtos em relação ao elemento na generalização do produto interno.

\ *binary_op2*
A operação binária que substitui a operação em relação ao elemento do produto interno da multiplicação na generalização do produto interno.

### <a name="return-value"></a>Valor retornado

A primeira função membro retorna a soma dos produtos em relação ao elemento e adiciona a ela o valor inicial especificado. Então, para intervalos de valores *a*i e *b*i, ela retornará:

*init* *+ (1*\* *b*1) + (*a*2 \* *b*2) +... + (*a*n \* *b*n)

substituindo iterativamente *init* por *init* + (*a*i \* *b*).

A segunda função membro retorna:

*init* *binary_op1* (*a*1 *binary_op2* *b*1) *binary_op1* (*a*2 *binary_op2* *b*2) *binary_op1* ... *binary_op1* (*a*n *binary_op2* *b*n)

substituindo a *init* por iteração por *init* *binary_op1* (*a*i *binary_op2* *b*i).

### <a name="remarks"></a>Comentários

O valor inicial garante que haja um resultado bem definido quando o intervalo estiver vazio. Nesse caso, *init* é retornado. As operações binárias não precisam ser associativas ou comutadoras. O intervalo deve ser válido e a complexidade é linear com o tamanho do intervalo. O tipo de retorno do operador binário deve ser conversível para **Type** para garantir o fechamento durante a iteração.

### <a name="example"></a>Exemplo

```cpp
// numeric_inner_prod.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <iostream>

int main()
{
   using namespace std;

   vector <int> v1, v2(7), v3(7);
   vector <int>::iterator iter1, iter2, iter3;

   int i;
   for (i = 1; i <= 7; i++)
   {
      v1.push_back(i);
   }

   cout << "The original vector v1 is:\n ( " ;
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
      cout << *iter1 << " ";
   cout << ")." << endl;

   list <int> l1, l2(7);
   list <int>::iterator lIter1, lIter2;

   int t;
   for (t = 1; t <= 7; t++)
   {
      l1.push_back(t);
   }

   cout << "The original list l1 is:\n ( " ;
   for (lIter1 = l1.begin(); lIter1 != l1.end(); lIter1++)
      cout << *lIter1 << " ";
   cout << ")." << endl;

   // The first member function for the inner product
   int inprod;
   inprod = inner_product(v1.begin(), v1.end(), l1.begin(), 0);

   cout << "The inner_product of the vector v1 and the list l1 is: "
        << inprod << "." << endl;

   // Constructing a vector of partial inner_products between v1 & l1
   int j = 0, parinprod;
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
      parinprod = inner_product(v1.begin(), iter1 + 1, l1.begin(), 0);
      v2[j] = parinprod;
      j++;
   }

   cout << "Vector of partial inner_products between v1 & l1 is:\n ( " ;
   for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)
      cout << *iter2 << " ";
   cout << ")." << endl << endl;

   // The second member function used to compute
   // the product of the element-wise sums
   int inprod2;
   inprod2 = inner_product (v1.begin(), v1.end(),
      l1.begin(), 1, multiplies<int>(), plus<int>());

   cout << "The sum of the element-wise products of v1 and l1 is: "
        << inprod2 << "." << endl;

   // Constructing a vector of partial sums of element-wise products
   int k = 0, parinprod2;
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
   {
      parinprod2 =
         inner_product(v1.begin(), iter1 + 1, l1.begin(), 1,
         multiplies<int>(), plus<int>());
      v3[k] = parinprod2;
      k++;
   }

   cout << "Vector of partial sums of element-wise products is:\n ( " ;
   for (iter3 = v3.begin(); iter3 != v3.end(); iter3++)
      cout << *iter3 << " ";
   cout << ")." << endl << endl;
}
```

## <a name="iota"></a>minúscula

Armazena um valor inicial, começando com o primeiro elemento e preenchendo incrementos sucessivos desse valor (`value++`) em cada um dos elementos no intervalo `[first,  last)`.

```cpp
template <class ForwardIterator, class Type>
void iota(ForwardIterator first, ForwardIterator last, Type value);
```

### <a name="parameters"></a>Parâmetros

*primeiro* \
Um iterador de entrada que trata o primeiro elemento no intervalo a ser preenchido.

*última* \
Um iterador de entrada que trata o último elemento no intervalo a ser preenchido.

*value*\
O valor inicial a ser armazenado no primeiro elemento e incrementado sucessivamente para os elementos posteriores.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra alguns usos para a função `iota` ao preencher uma [lista](../standard-library/list.md) de inteiros e, em seguida, preencher um [vetor](../standard-library/vector.md) com o `list` para que a função [random_shuffle](../standard-library/algorithm-functions.md#random_shuffle) possa ser usada.

```cpp
// compile by using: cl /EHsc /nologo /W4 /MTd
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    list <int> intList(10);
    vector <list<int>::iterator> intVec(intList.size());

    // Fill the list
    iota(intList.begin(), intList.end(), 0);

    // Fill the vector with the list so we can shuffle it
    iota(intVec.begin(), intVec.end(), intList.begin());

    random_shuffle(intVec.begin(), intVec.end());

    // Output results
    cout << "Contents of the integer list: " << endl;
    for (auto i: intList) {
        cout << i << ' ';
    }
    cout << endl << endl;

    cout << "Contents of the integer list, shuffled by using a vector: " << endl;
    for (auto i: intVec) {
        cout << *i << ' ';
    }
    cout << endl;
}
```

## <a name="lcm"></a>LCM

```cpp
template <class M, class N>
constexpr common_type_t<M,N> lcm(M m, N n);
```

## <a name="partial_sum"></a>partial_sum

Computa uma série de somas em um intervalo de entrada do primeiro elemento por meio do elemento *n*-ésimo e armazena o resultado de cada uma dessas somas no elemento *n*º de um intervalo de destino. Ou, computa o resultado de um procedimento generalizado em que a operação sum é substituída por outra operação binária especificada.

```cpp
template <class InputIterator, class OutIt>
OutputIterator partial_sum(
    InputIterator first,
    InputIterator last,
    OutputIterator result);

template <class InputIterator, class OutIt, class Fn2>
OutputIterator partial_sum(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryOperation binary_op);
```

### <a name="parameters"></a>Parâmetros

*primeiro* \
Um iterador de entrada que trata o primeiro elemento no intervalo para ser parcialmente somado ou combinado de acordo com uma operação binária especificada.

*última* \
Um iterador de entrada que trata o último elemento no intervalo para ser parcialmente somado ou combinado, de acordo com uma operação binária especificada que está uma posição além do elemento final de fato incluído no acúmulo iterado.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento de um intervalo de destino para armazenar a série de somas parciais ou os resultados sucessivos da operação binária especificada.

\ *binary_op*
A operação Binary a ser aplicada na operação generalizada, substituindo a operação de Sum no procedimento Sum parcial.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda o final do intervalo de destino: *resultado* + (*último* - *primeiro*).

### <a name="remarks"></a>Comentários

O *resultado* do iterador de saída pode ser o mesmo iterador que o iterador de entrada *primeiro*, para que as somas parciais possam ser computadas no local.

Para *uma sequência de valores de*1, *um*2,... *um*x, em um intervalo de entrada, a primeira função de modelo armazena somas parciais sucessivas no intervalo de destino. O elemento *n*-ésimo é fornecido por *(um*de 1 + *a*2 + *a*3 +... + *a*n).

Para *uma sequência de valores de*1, *um*2, *um*3, em um intervalo de entrada, a segunda função de modelo armazena resultados parciais sucessivos no intervalo de destino. O elemento *n*-ésimo é fornecido por ((... ((*um*1 *binary_op* *a*2) *binary_op* *a*3) *binary_op* ...) *binary_op* *a*n).

A operação binária *binary_op* não deve ser associativa ou comutadora, pois a ordem das operações aplicadas é especificada.

### <a name="example"></a>Exemplo

```cpp
// numeric_partial_sum.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <iostream>

int main( )
{
   using namespace std;
   vector<int> V1( 10 ), V2( 10 );
   vector<int>::iterator VIter1, VIter2, VIterend, VIterend2;

   list <int> L1;
   list <int>::iterator LIter1, LIterend;

   int t;
   for ( t = 1 ; t <= 10 ; t++ )
   {
      L1.push_back( t );
   }

   cout << "The input list L1 is:\n ( " ;
   for ( LIter1 = L1.begin( ) ; LIter1 != L1.end( ) ; LIter1++ )
      cout << *LIter1 << " ";
   cout << ")." << endl;

   // The first member function for the partial sums of
   // elements in a list output to a vector
   VIterend = partial_sum ( L1.begin ( ) , L1.end ( ) ,
      V1.begin ( ) );

   cout << "The output vector containing the partial sums is:\n ( " ;
   for ( VIter1 = V1.begin( ) ; VIter1 != VIterend ; VIter1++ )
      cout << *VIter1 << " ";
   cout << ")." << endl;

   // The second member function used to compute
   // the partial product of the elements in a list
   VIterend2 = partial_sum ( L1.begin ( ) , L1.end ( ) , V2.begin ( ) ,
      multiplies<int>( ) );

   cout << "The output vector with the partial products is:\n ( " ;
   for ( VIter2 = V2.begin( ) ; VIter2 != VIterend2 ; VIter2++ )
      cout << *VIter2 << " ";
   cout << ")." << endl;

   // Computation of partial sums in place
   LIterend = partial_sum ( L1.begin ( ) , L1.end ( ) , L1.begin ( ) );
   cout << "The in place output partial_sum list L1 is:\n ( " ;
   for ( LIter1 = L1.begin( ) ; LIter1 != LIterend ; LIter1++ )
      cout << *LIter1 << " ";
   cout << ")." << endl;
}
```

## <a name="reduce"></a>diminu

Reduz todos os elementos em um intervalo especificado, possivelmente incluindo algum valor inicial, computando somas em uma ordem arbitrária e possivelmente permutada. Ou, reduz ao computar os resultados de uma operação binária especificada. Sobrecargas que incluem um argumento de política de execução são executados de acordo com a política especificada.

```cpp
template<class InputIterator>
typename iterator_traits<InputIterator>::value_type reduce(
    InputIterator first,
    InputIterator last);

template<class InputIterator, class Type>
Type reduce(
    InputIterator first,
    InputIterator last,
    Type init);

template<class InputIterator, class Type, class BinaryOperation>
Type reduce(
    InputIterator first,
    InputIterator last,
    Type init,
    BinaryOperation binary_op);

template<class ExecutionPolicy, class ForwardIterator>
typename iterator_traits<ForwardIterator>::value_type reduce(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last);

template<class ExecutionPolicy, class ForwardIterator, class Type>
Type reduce(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Type init);

template<class ExecutionPolicy, class ForwardIterator, class Type, class BinaryOperation>
Type reduce(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Type init,
    BinaryOperation binary_op);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento um intervalo de destino em que a série de somas ou os resultados da operação especificada deve ser armazenado.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

### <a name="return-value"></a>Valor retornado

O resultado da aplicação de *binary_op* ou `std::plus<>()` a *init* e todos os elementos no intervalo especificado para (* PartialResult, *In_iter*), em que *PartialResult* é o resultado de aplicativos anteriores da operação e *in_iter* é um iterador que aponta para algum elemento no intervalo. Em sobrecargas que não especificam *init*, o valor de *init* usado é equivalente a `typename iterator_traits<InputIterator>::value_type{}`.

### <a name="remarks"></a>Comentários

`reduce` comportamento é não determinístico, a menos que *binary_op* seja associativo e comutador. O comportamento é indefinido se *binary_op* modifica qualquer elemento ou invalida qualquer iterador no intervalo \[*primeiro*, *último*], inclusive.

## <a name="transform_exclusive_scan"></a>transform_exclusive_scan

Transforma os elementos de um intervalo com um operador unário especificado e, em seguida, computa uma operação de soma de prefixo exclusiva usando `std::plus<>()` ou um operador binário especificado no intervalo, dado um valor inicial. Grava os resultados no intervalo que começa no destino especificado. Uma soma de *prefixo exclusiva* significa que o elemento *n*-th Input não está incluído na soma *n*. Sobrecargas que incluem um argumento de política de execução são executados de acordo com a política especificada. A soma pode ser executada em uma ordem arbitrária.

```cpp
template<class InputIterator, class OutputIterator, class Type, class BinaryOperation, class UnaryOperation>
OutputIterator transform_exclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    Type init,
    BinaryOperation binary_op,
    UnaryOperation unary_op);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type, class BinaryOperation, class UnaryOperation>
ForwardIterator2 transform_exclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    Type init,
    BinaryOperation binary_op,
    UnaryOperation unary_op);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento um intervalo de destino em que a série de somas ou os resultados da operação especificada deve ser armazenado.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

\ *unary_op*
A operação unário a ser aplicada a cada elemento no intervalo especificado.

## <a name="transform_inclusive_scan"></a>transform_inclusive_scan

Transforma os elementos de um intervalo com um operador unário especificado e, em seguida, computa uma operação de soma de prefixo inclusiva usando `std::plus<>()` ou um operador binário especificado no intervalo, dado um valor inicial. Grava os resultados no intervalo que começa no destino especificado. Uma soma de *prefixo inclusiva* significa que o elemento *n*-th Input está incluído na soma *n*. Sobrecargas que incluem um argumento de política de execução são executados de acordo com a política especificada. A soma pode ser executada em uma ordem arbitrária.

```cpp
template<class InputIterator, class OutputIterator, class BinaryOperation, class UnaryOperation>
OutputIterator transform_inclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryOperation binary_op,
    UnaryOperation unary_op);

template<class InputIterator, class OutputIterator, class BinaryOperation, class UnaryOperation, class Type>
OutputIterator transform_inclusive_scan(
    InputIterator first,
    InputIterator last,
    OutputIterator result,
    BinaryOperation binary_op,
    UnaryOperation unary_op,
    Type init);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryOperation, class UnaryOperation>
ForwardIterator2 transform_inclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    BinaryOperation binary_op,
    UnaryOperation unary_op);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class BinaryOperation, class UnaryOperation, class Type>
ForwardIterator2 transform_inclusive_scan(
    ExecutionPolicy&& exec,
    ForwardIterator1 first,
    ForwardIterator1 last,
    ForwardIterator2 result,
    BinaryOperation binary_op,
    UnaryOperation unary_op,
    Type init);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento um intervalo de destino em que a série de somas ou os resultados da operação especificada deve ser armazenado.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

\ *unary_op*
A operação unário a ser aplicada a cada elemento no intervalo especificado.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

## <a name="transform_reduce"></a>transform_reduce

Transforma um intervalo de elementos e aplica um functor que reduz os elementos transformados em ordem arbitrária. Efetivamente, um `transform` seguido por um `reduce`.

```cpp
template<class InputIterator1, class InputIterator2, class Type>
Type transform_reduce(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    Type init);

template<class InputIterator1, class InputIterator2, class Type, class BinaryOperation1, class BinaryOperation2>
Type transform_reduce(
    InputIterator1 first1,
    InputIterator1 last1,
    InputIterator2 first2,
    Type init,
    BinaryOperation1 binary_op1,
    BinaryOperation2 binary_op2);

template<class InputIterator, class Type, class BinaryOperation, class UnaryOperation>
Type transform_reduce(
    InputIterator first,
    InputIterator last,
    Type init,
    BinaryOperation binary_op,
    UnaryOperation unary_op);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type>
Type transform_reduce(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    Type init);

template<class ExecutionPolicy, class ForwardIterator1, class ForwardIterator2, class Type, class BinaryOperation1, class BinaryOperation2>
Type transform_reduce(
    ExecutionPolicy&& exec,
    ForwardIterator1 first1,
    ForwardIterator1 last1,
    ForwardIterator2 first2,
    Type init,
    BinaryOperation1 binary_op1,
    BinaryOperation2 binary_op2);

template<class ExecutionPolicy, class ForwardIterator, class Type, class BinaryOperation, class UnaryOperation>
Type transform_reduce(
    ExecutionPolicy&& exec,
    ForwardIterator first,
    ForwardIterator last,
    Type init,
    BinaryOperation binary_op,
    UnaryOperation unary_op);
```

### <a name="parameters"></a>Parâmetros

\ de *exec*
Uma política de execução.

*primeiro* \
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op*.

\ *first1*
Um iterador de entrada que aborda o primeiro elemento no intervalo para somar ou combinar usando *binary_op1*.

*última* \
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ *last1*
Um iterador de entrada que aborda o último elemento no intervalo para somar ou combinar usando *binary_op1*, essa é uma posição além do elemento final realmente incluído na acumulação iterada.

\ de *resultado*
Um iterador de saída que aborda o primeiro elemento um intervalo de destino em que a série de somas ou os resultados da operação especificada deve ser armazenado.

\ de *inicialização*
Um valor inicial para o qual cada elemento é, por sua vez, adicionado ou combinado usando *binary_op*.

\ *binary_op*
A operação binária a ser aplicada a cada elemento no intervalo especificado e o resultado de seus aplicativos anteriores.

\ *unary_op*
A operação unário a ser aplicada a cada elemento no intervalo especificado.

### <a name="return-value"></a>Valor retornado

O resultado transformado e reduzido.
