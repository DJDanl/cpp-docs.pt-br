---
title: Classe reverse_iterator
ms.date: 03/27/2019
f1_keywords:
- xutility/std::reverse_iterator
- iterator/std::reverse_iterator::difference_type
- iterator/std::reverse_iterator::iterator_type
- iterator/std::reverse_iterator::pointer
- iterator/std::reverse_iterator::reference
- iterator/std::reverse_iterator::base
- iterator/std::reverse_iterator::operator_star
helpviewer_keywords:
- std::reverse_iterator [C++]
- std::reverse_iterator [C++], difference_type
- std::reverse_iterator [C++], iterator_type
- std::reverse_iterator [C++], pointer
- std::reverse_iterator [C++], reference
- std::reverse_iterator [C++], base
- std::reverse_iterator [C++], operator_star
ms.assetid: c0b34d04-ae9a-4999-9aff-28b313897ffa
ms.openlocfilehash: 882d0f7f4930e9d809098a29384a962d0aa8f4ea
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373432"
---
# <a name="reverse_iterator-class"></a>Classe reverse_iterator

O modelo de classe é um adaptador de iterator que descreve um objeto iterador reverso que se comporta como um iterador de acesso aleatório ou bidirecional, apenas ao contrário. Ela permite a travessia regressiva de um intervalo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class RandomIterator>
class reverse_iterator
```

### <a name="parameters"></a>Parâmetros

RandomIterator O tipo que representa o iterator a ser adaptado para operar ao contrário.

## <a name="remarks"></a>Comentários

Os contêineres existentes da Biblioteca Padrão C++ também definem os tipos `reverse_iterator` e `const_reverse_iterator` e têm funções membro `rbegin` e `rend` que retornam iteradores inversos. Esses iteradores apresentam semântica de substituição. O `reverse_iterator` adaptador complementa essa funcionalidade, pois oferece inserção de semântica e também pode ser usado com fluxos.

O `reverse_iterator` que requer um iterador bidirecional não deve `operator+=` `operator+`chamar `operator-=` `operator-`nenhuma `operator[]`das funções do membro, ou , que só pode ser usada com iteradores de acesso aleatório.

O intervalo de um iterador é [*primeiro*, *último*), onde o suporte quadrado à esquerda indica a inclusão do *primeiro* e o parêntese à direita indica a inclusão de elementos até, mas *excluindo-se* em si mesmo. Os mesmos elementos são incluídos na seqüência invertida [ **rev** - *primeiro*, **rev** - *passado*) de modo que se o *último* é o elemento one-past-the-end em uma seqüência, em seguida, o primeiro elemento **rev** - *primeiro* na seqüência invertida aponta para \*(*último* - 1). A identidade que relaciona a todos os iteradores inversos a seus iteradores subjacentes é:

&\*( **reverse_iterator** *(i)* == &\*( *i* - 1 ).

Na prática, isso significa que na sequência invertida, reverse_iterator fará referência ao elemento que está uma posição depois (à direita do) do elemento ao qual o iterador se referiu na sequência original. Desse modo, se um iterador tratou o elemento 6 na sequência (2, 4, 6, 8), `reverse_iterator` tratará o elemento 4 na sequência inversa (8, 6, 4, 2).

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[reverse_iterator](#reverse_iterator)|Constrói um `reverse_iterator` padrão ou um `reverse_iterator` de um iterador subjacente.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre dois `reverse_iterator`s que se referem a elementos no mesmo contêiner.|
|[iterator_type](#iterator_type)|Um tipo que fornece um iterador subjacente para um `reverse_iterator`.|
|[ponteiro](#pointer)|Um tipo que fornece um ponteiro para um elemento tratado por um `reverse_iterator`.|
|[Referência](#reference)|Um tipo que fornece uma referência a um elemento tratado por um `reverse_iterator`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[base](#base)|Recupera o iterador subjacente de seu `reverse_iterator`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator_star](#op_star)|Retorna o elemento tratado por um `reverse_iterator`.|
|[operador+](#op_add)|Adiciona um deslocamento a um iterador e retorna o novo `reverse_iterator` que trata o elemento inserido na nova posição de deslocamento.|
|[operador++](#op_add_add)|Incrementa o `reverse_iterator` até o próximo elemento.|
|[operador+=](#op_add_eq)|Adiciona um deslocamento especificado de um `reverse_iterator`.|
|[operador-](#operator-)|Subtrai um deslocamento de um `reverse_iterator` e retorna um `reverse_iterator` que trata o elemento na posição do deslocamento.|
|[operador -](#operator--)|Decrementa o `reverse_iterator` para o elemento anterior.|
|[operador-=](#operator-_eq)|Subtrai um deslocamento especificado de um `reverse_iterator`.|
|[operador->](#op-arrow)|Retorna um ponteiro para o elemento tratado pelo `reverse_iterator`.|
|[operator&#91;&#93;](#op_at)|Retorna uma referência a um deslocamento do elemento tratado por um `reverse_iterator` por um número especificado de posições.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="reverse_iteratorbase"></a><a name="base"></a>reverse_iterator::base

Recupera o iterador subjacente de seu `reverse_iterator`.

```cpp
RandomIterator base() const;
```

### <a name="return-value"></a>Valor retornado

O iterador subjacente a `reverse_iterator`.

### <a name="remarks"></a>Comentários

A identidade que relaciona a todos os iteradores inversos a seus iteradores subjacentes é:

&\*( `reverse_iterator` ( *i* ) \*= = &( *i* - 1 ).

Na prática, isso significa que, na sequência invertida, `reverse_iterator` fará referência ao elemento que está uma posição depois (à direita) do elemento ao qual o iterador se referiu na sequência original. Desse modo, se um iterador tratou o elemento 6 na sequência (2, 4, 6, 8), `reverse_iterator` tratará o elemento 4 na sequência inversa (8, 6, 4, 2).

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_base.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   vector <int>::iterator pos, bpos;
   pos = find ( vec.begin ( ), vec.end ( ), 6 );
   cout << "The iterator pos points to: " << *pos << "." << endl;

   typedef reverse_iterator<vector<int>::iterator>::iterator_type it_vec_int_type;

   reverse_iterator<it_vec_int_type> rpos ( pos );
   cout << "The reverse_iterator rpos points to: " << *rpos
        << "." << endl;

   bpos = rpos.base ( );
   cout << "The iterator underlying rpos is bpos & it points to: "
        << *bpos << "." << endl;
}
```

## <a name="reverse_iteratordifference_type"></a><a name="difference_type"></a>reverse_iterator::difference_type

Um tipo que fornece a diferença entre dois `reverse_iterator`s que se referem a elementos no mesmo contêiner.

```cpp
typedef typename iterator_traits<RandomIterator>::difference_type  difference_type;
```

### <a name="remarks"></a>Comentários

O tipo de diferença `reverse_iterator` é o mesmo que o tipo de diferença do iterador.

O tipo é um sinônimo para o `iterator_traits` \< nome de tipo de traço **iterator RandomIterator**> **::pointer**.

### <a name="example"></a>Exemplo

Consulte [reverse_iterator::operator&#91;&#93;](#op_at) para ver um exemplo de como declarar e usar `difference_type`.

## <a name="reverse_iteratoriterator_type"></a><a name="iterator_type"></a>reverse_iterator:iterator_type

Um tipo que fornece um iterador subjacente para um `reverse_iterator`.

```cpp
typedef RandomIterator iterator_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Iterator`.

### <a name="example"></a>Exemplo

Consulte [reverse_iterator::base](#base) para ver um exemplo de como declarar e usar `iterator_type`.

## <a name="reverse_iteratoroperator"></a><a name="op_star"></a>reverse_iterator:operador\*

Retorna o elemento que um reverse_iterator aborda.

```cpp
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O valor dos elementos abordados pelo reverse_iterator.

### <a name="remarks"></a>Comentários

O operador \*retorna ( **atual** - 1).

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_ref.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   vector <int>::iterator pos, bpos;
   pos = find ( vec.begin ( ), vec.end ( ), 6 );

   // Declare a difference type for a parameter
   // declare a reference return type
   reverse_iterator<vector<int>::iterator>::reference refpos = *pos;
   cout << "The iterator pos points to: " << refpos << "." << endl;
}
```

## <a name="reverse_iteratoroperator"></a><a name="op_add"></a>reverse_iterator::operador+

Adiciona um deslocamento a um iterador e retorna o novo `reverse_iterator` que trata o elemento inserido na nova posição de deslocamento.

```cpp
reverse_iterator<RandomIterator> operator+(difference_type Off) const;
```

### <a name="parameters"></a>Parâmetros

*Fora*\
O deslocamento a ser adicionado ao iterador inverso.

### <a name="return-value"></a>Valor retornado

Um `reverse_iterator` que trata o elemento de deslocamento.

### <a name="remarks"></a>Comentários

Essa função de membro pode ser usada somente se o `reverse_iterator` satisfizer os requisitos de um iterador de acesso aleatório.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_add.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   // Initializing reverse_iterators to the first element
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( );

   cout << "The iterator rVPOS1 initially points to the first "
        << "element\n in the reversed sequence: "
        << *rVPOS1 << "." << endl;

   vector <int>::reverse_iterator rVPOS2 =rVPOS1 + 2; // offset added
   cout << "After the +2 offset, the iterator rVPOS2 points\n"
        << " to the 3rd element in the reversed sequence: "
        << *rVPOS2 << "." << endl;
}
```

```Output
The vector vec is: ( 2 4 6 8 10 ).
The vector vec reversed is: ( 10 8 6 4 2 ).
The iterator rVPOS1 initially points to the first element
in the reversed sequence: 10.
After the +2 offset, the iterator rVPOS2 points
to the 3rd element in the reversed sequence: 6.
```

## <a name="reverse_iteratoroperator"></a><a name="op_add_add"></a>reverse_iterator:operador++

Incrementa o reverse_iterator para o elemento anterior.

```cpp
reverse_iterator<RandomIterator>& operator++();
reverse_iterator<RandomIterator> operator++(int);
```

### <a name="return-value"></a>Valor retornado

O primeiro operador retorna o `reverse_iterator` pré-incrementado e o segundo, o operador pós-incrementado, retorna uma cópia do `reverse_iterator` incrementado.

### <a name="remarks"></a>Comentários

Essa função de membro só pode ser usada se o `reverse_iterator` satisfizer os requisitos de um iterador bidirecional.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_incr.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i - 1 );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   // Initializing reverse_iterators to the last element
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin( );

   cout << "The iterator rVPOS1 initially points to the first "
        << "element\n in the reversed sequence: "
        << *rVPOS1 << "." << endl;

   rVPOS1++;  // postincrement, preincrement: ++rVPSO1

   cout << "After incrementing, the iterator rVPOS1 points\n"
        << " to the second element in the reversed sequence: "
        << *rVPOS1 << "." << endl;
}
```

```Output
The vector vec is: ( 1 3 5 7 9 ).
The vector vec reversed is: ( 9 7 5 3 1 ).
The iterator rVPOS1 initially points to the first element
in the reversed sequence: 9.
After incrementing, the iterator rVPOS1 points
to the second element in the reversed sequence: 7.
```

## <a name="reverse_iteratoroperator"></a><a name="op_add_eq"></a>reverse_iterator:operador+=

Adiciona um deslocamento especificado de um reverse_iterator.

```cpp
reverse_iterator<RandomIterator>& operator+=(difference_type Off);
```

### <a name="parameters"></a>Parâmetros

*Fora*\
O deslocamento pelo qual incrementar o iterador.

### <a name="return-value"></a>Valor retornado

Uma referência ao elemento tratado pelo `reverse_iterator`.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_addoff.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   }

   vector <int>::iterator vIter;

   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   // Initializing reverse_iterators to the last element
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( );

   cout << "The iterator rVPOS1 initially points to the first "
        << "element\n in the reversed sequence: "
        << *rVPOS1 << "." << endl;

   rVPOS1+=2;   // addition of an offset
   cout << "After the +2 offset, the iterator rVPOS1 now points\n"
        << " to the third element in the reversed sequence: "
        << *rVPOS1 << "." << endl;
}
```

```Output
The vector vec is: ( 2 4 6 8 10 ).
The vector vec reversed is: ( 10 8 6 4 2 ).
The iterator rVPOS1 initially points to the first element
in the reversed sequence: 10.
After the +2 offset, the iterator rVPOS1 now points
to the third element in the reversed sequence: 6.
```

## <a name="reverse_iteratoroperator-"></a><a name="operator-"></a>reverse_iterator::operador-

Subtrai um deslocamento de um `reverse_iterator` e retorna um `reverse_iterator` que trata o elemento na posição do deslocamento.

```cpp
reverse_iterator<RandomIterator> operator-(difference_type Off) const;
```

### <a name="parameters"></a>Parâmetros

*Fora*\
O deslocamento a ser subtraído do reverse_iterator.

### <a name="return-value"></a>Valor retornado

Um `reverse_iterator` que trata o elemento de deslocamento.

### <a name="remarks"></a>Comentários

Essa função de membro pode ser usada somente se o `reverse_iterator` satisfizer os requisitos de um iterador de acesso aleatório.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_sub.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 3 * i );
   }

   vector <int>::iterator vIter;

   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   // Initializing reverse_iterators to the first element
   vector <int>::reverse_iterator rVPOS1 = vec.rend ( ) - 1;

   cout << "The iterator rVPOS1 initially points to the last "
        << "element\n in the reversed sequence: "
        << *rVPOS1 << "." << endl;

   vector <int>::reverse_iterator rVPOS2 =rVPOS1 - 2; // offset subtracted
   cout << "After the -2 offset, the iterator rVPOS2 points\n"
        << " to the 2nd element from the last in the reversed sequence: "
        << *rVPOS2 << "." << endl;
}
```

```Output
The vector vec is: ( 3 6 9 12 15 ).
The vector vec reversed is: ( 15 12 9 6 3 ).
The iterator rVPOS1 initially points to the last element
in the reversed sequence: 3.
After the -2 offset, the iterator rVPOS2 points
to the 2nd element from the last in the reversed sequence: 9.
```

## <a name="reverse_iteratoroperator--"></a><a name="operator--"></a>reverse_iterator:operador-

Decrementa o reverse_iterator para o elemento anterior.

```cpp
reverse_iterator<RandomIterator>& operator--();
reverse_iterator<RandomIterator> operator--(int);
```

### <a name="return-value"></a>Valor retornado

O primeiro operador retorna o `reverse_iterator` pré-decrementado e o segundo, o operador pós-decrementado, retorna uma cópia do `reverse_iterator` decrementado.

### <a name="remarks"></a>Comentários

Essa função de membro só pode ser usada se o `reverse_iterator` satisfizer os requisitos de um iterador bidirecional.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_decr.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i - 1 );
   }

   vector <int>::iterator vIter;

   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   // Initializing reverse_iterators to the first element
   vector <int>::reverse_iterator rVPOS1 = vec.rend ( ) - 1;

   cout << "The iterator rVPOS1 initially points to the last "
        << "element\n in the reversed sequence: "
        << *rVPOS1 << "." << endl;
   rVPOS1--;  // postdecrement, predecrement: --rVPSO1

   cout << "After the decrement, the iterator rVPOS1 points\n"
        << " to the next-to-last element in the reversed sequence: "
        << *rVPOS1 << "." << endl;
}
```

```Output
The vector vec is: ( 1 3 5 7 9 ).
The vector vec reversed is: ( 9 7 5 3 1 ).
The iterator rVPOS1 initially points to the last element
in the reversed sequence: 1.
After the decrement, the iterator rVPOS1 points
to the next-to-last element in the reversed sequence: 3.
```

## <a name="reverse_iteratoroperator-"></a><a name="operator-_eq"></a>reverse_iterator:operador-=

Subtrai um deslocamento especificado de um `reverse_iterator`.

```cpp
reverse_iterator<RandomIterator>& operator-=(difference_type Off);
```

### <a name="parameters"></a>Parâmetros

*Fora*\
O deslocamento a ser subtraído de `reverse_iterator`.

### <a name="remarks"></a>Comentários

Essa função de membro pode ser usada somente se o `reverse_iterator` satisfizer os requisitos de um iterador de acesso aleatório.

O operador avalia **a corrente** + *Off* e retorna ** \*isso**.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_op_suboff.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 3 * i );
   }

   vector <int>::iterator vIter;

   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   // Initializing reverse_iterators to the first element
   vector <int>::reverse_iterator rVPOS1 = vec.rend ( ) - 1;

   cout << "The iterator rVPOS1 initially points to the last "
        << "element\n in the reversed sequence: "
        << *rVPOS1 << "." << endl;

   rVPOS1-=2;      // Subtraction of an offset
   cout << "After the -2 offset, the iterator rVPOS1 now points\n"
        << " to the 2nd element from the last in the reversed sequence: "
        << *rVPOS1 << "." << endl;
}
```

```Output
The vector vec is: ( 3 6 9 12 15 ).
The vector vec reversed is: ( 15 12 9 6 3 ).
The iterator rVPOS1 initially points to the last element
in the reversed sequence: 3.
After the -2 offset, the iterator rVPOS1 now points
to the 2nd element from the last in the reversed sequence: 9.
```

## <a name="reverse_iteratoroperator-gt"></a><a name="op-arrow"></a>reverse_iterator::operador-&gt;

Retorna um ponteiro para o elemento tratado pelo `reverse_iterator`.

```cpp
pointer operator->() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o elemento tratado pelo `reverse_iterator`.

### <a name="remarks"></a>Comentários

O operador devolve ** & \* \*isso.**

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_ptrto.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

int main( )
{
   using namespace std;

   typedef vector<pair<int,int> > pVector;
   pVector vec;
   vec.push_back(pVector::value_type(1,2));
   vec.push_back(pVector::value_type(3,4));
   vec.push_back(pVector::value_type(5,6));

   pVector::iterator pvIter;
   cout << "The vector vec of integer pairs is:\n( ";
   for ( pvIter = vec.begin ( ) ; pvIter != vec.end ( ); pvIter++)
      cout << "( " << pvIter -> first << ", " << pvIter -> second << ") ";
   cout << ")" << endl << endl;

   pVector::reverse_iterator rpvIter;
   cout << "The vector vec reversed is:\n( ";
   for ( rpvIter = vec.rbegin( ) ; rpvIter != vec.rend( ); rpvIter++ )
      cout << "( " << rpvIter -> first << ", " << rpvIter -> second << ") ";
   cout << ")" << endl << endl;

   pVector::iterator pos = vec.begin ( );
   pos++;
   cout << "The iterator pos points to:\n( " << pos -> first << ", "
   << pos -> second << " )" << endl << endl;

   pVector::reverse_iterator rpos (pos);

   // Use operator -> with return type: why type int and not int*
   int fint = rpos -> first;
   int sint = rpos -> second;

   cout << "The reverse_iterator rpos points to:\n( " << fint << ", "
   << sint << " )" << endl;
}
```

```Output
The vector vec of integer pairs is:
( ( 1, 2) ( 3, 4) ( 5, 6) )

The vector vec reversed is:
( ( 5, 6) ( 3, 4) ( 1, 2) )

The iterator pos points to:
( 3, 4 )

The reverse_iterator rpos points to:
( 1, 2 )
```

## <a name="reverse_iteratoroperator"></a><a name="op_at"></a>reverse_iterator::operador[]

Retorna uma referência a um deslocamento do elemento tratado por um `reverse_iterator` por um número especificado de posições.

```cpp
reference operator[](difference_type Off) const;
```

### <a name="parameters"></a>Parâmetros

*Fora*\
O deslocamento do endereço `reverse_iterator`.

### <a name="return-value"></a>Valor retornado

A referência ao deslocamento de elemento.

### <a name="remarks"></a>Comentários

O operador <strong>\*</strong>retorna ** \*(isso).** + `Off`

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_ret_ref.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   vector <int>::iterator pos;
   pos = find ( vec.begin ( ), vec.end ( ), 8 );
   reverse_iterator<vector<int>::iterator> rpos ( pos );

   // Declare a difference type for a parameter
   reverse_iterator<vector<int>::iterator>::difference_type diff = 2;

   cout << "The iterator pos points to: " << *pos << "." << endl;
   cout << "The iterator rpos points to: " << *rpos << "." << endl;

   // Declare a reference return type & use operator[]
   reverse_iterator<vector<int>::iterator>::reference refrpos = rpos [diff];
   cout << "The iterator rpos now points to: " << refrpos << "." << endl;
}
```

```Output
The vector vec is: ( 2 4 6 8 10 ).
The vector vec reversed is: ( 10 8 6 4 2 ).
The iterator pos points to: 8.
The iterator rpos points to: 6.
The iterator rpos now points to: 2.
```

## <a name="reverse_iteratorpointer"></a><a name="pointer"></a>reverse_iterator::pointer

Um tipo que fornece um ponteiro para um elemento tratado por um `reverse_iterator`.

```cpp
typedef typename iterator_traits<RandomIterator>::pointer pointer;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o `iterator_traits` \< nome de tipo de traço *iterator RandomIterator*> **::pointer**.

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_pointer.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

int main( )
{
   using namespace std;

   typedef vector<pair<int,int> > pVector;
   pVector vec;
   vec.push_back( pVector::value_type( 1,2 ) );
   vec.push_back( pVector::value_type( 3,4 ) );
   vec.push_back( pVector::value_type( 5,6 ) );

   pVector::iterator pvIter;
   cout << "The vector vec of integer pairs is:\n" << "( ";
   for ( pvIter = vec.begin ( ) ; pvIter != vec.end ( ); pvIter++)
      cout << "( " << pvIter -> first << ", " << pvIter -> second << ") ";
   cout << ")" << endl;

   pVector::reverse_iterator rpvIter;
   cout << "\nThe vector vec reversed is:\n" << "( ";
   for ( rpvIter = vec.rbegin( ) ; rpvIter != vec.rend( ); rpvIter++)
      cout << "( " << rpvIter -> first << ", " << rpvIter -> second << ") ";
   cout << ")" << endl;

   pVector::iterator pos = vec.begin ( );
   pos++;
   cout << "\nThe iterator pos points to:\n"
        << "( " << pos -> first << ", "
        << pos -> second << " )" << endl;

   pVector::reverse_iterator rpos (pos);
   cout << "\nThe iterator rpos points to:\n"
        << "( " << rpos -> first << ", "
        << rpos -> second << " )" << endl;
}
```

```Output
The vector vec of integer pairs is:
( ( 1, 2) ( 3, 4) ( 5, 6) )

The vector vec reversed is:
( ( 5, 6) ( 3, 4) ( 1, 2) )

The iterator pos points to:
( 3, 4 )

The iterator rpos points to:
( 1, 2 )
```

## <a name="reverse_iteratorreference"></a><a name="reference"></a>reverse_iterator::referência

Um tipo que fornece uma referência a um elemento tratado por um reverse_iterator.

```cpp
typedef typename iterator_traits<RandomIterator>::reference reference;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o `iterator_traits` \< nome do tipo de traço iterator *RandomIterator*> **::referência**.

### <a name="example"></a>Exemplo

Consulte [reverse_iterator::operador&#91;&#93;](#op_at) ou [reverse_iterator::operador*](#op_star) para exemplos `reference`de como declarar e usar .

## <a name="reverse_iteratorreverse_iterator"></a><a name="reverse_iterator"></a>reverse_iterator:reverse_iterator

Constrói um `reverse_iterator` padrão ou um `reverse_iterator` de um iterador subjacente.

```cpp
reverse_iterator();
explicit reverse_iterator(RandomIterator right);

template <class Type>
reverse_iterator(const reverse_iterator<Type>& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O iterador deve ser adaptado para um `reverse_iterator`.

### <a name="return-value"></a>Valor retornado

Um `reverse_iterator` padrão ou um `reverse_iterator` que adapta um iterador subjacente.

### <a name="remarks"></a>Comentários

A identidade que relaciona a todos os iteradores inversos a seus iteradores subjacentes é:

&\*( `reverse_iterator` ( *i* ) \*= = &( *i* - 1 ).

Na prática, isso significa que na sequência invertida, reverse_iterator fará referência ao elemento que está uma posição depois (à direita do) do elemento ao qual o iterador se referiu na sequência original. Desse modo, se um iterador tratou o elemento 6 na sequência (2, 4, 6, 8), `reverse_iterator` tratará o elemento 4 na sequência inversa (8, 6, 4, 2).

### <a name="example"></a>Exemplo

```cpp
// reverse_iterator_reverse_iterator.cpp
// compile with: /EHsc
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   vector <int>::reverse_iterator rvIter;
   cout << "The vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      cout << *rvIter << " ";
   cout << ")." << endl;

   vector <int>::iterator pos;
   pos = find ( vec.begin ( ), vec.end ( ), 4 );
   cout << "The iterator pos = " << *pos << "." << endl;

   vector <int>::reverse_iterator rpos ( pos );
   cout << "The reverse_iterator rpos = " << *rpos
        << "." << endl;
}
```

## <a name="see-also"></a>Confira também

[\<>do tempo](../standard-library/iterator.md)\
[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
