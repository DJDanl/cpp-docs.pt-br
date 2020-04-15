---
title: Classe insert_iterator
ms.date: 11/04/2016
f1_keywords:
- iterator/std::insert_iterator
- iterator/std::insert_iterator::container_type
- iterator/std::insert_iterator::reference
helpviewer_keywords:
- std::insert_iterator [C++]
- std::insert_iterator [C++], container_type
- std::insert_iterator [C++], reference
ms.assetid: d5d86405-872e-4e3b-9e68-c69a2b7e8221
ms.openlocfilehash: 2865db023425fa301ad5440a0dc8ed491213f33f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368052"
---
# <a name="insert_iterator-class"></a>Classe insert_iterator

Descreve um adaptador de iterador que atende aos requisitos de um iterador de saída. Insere, em vez de substituições, elementos em uma sequência e, dessa forma, fornece semânticas que são diferentes da semântica de substituição fornecida pelos iteradores dos contêineres associativos e de sequência do C++. A classe `insert_iterator` é modelada no tipo do contêiner que está sendo adaptado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Container>
class insert_iterator;
```

### <a name="parameters"></a>Parâmetros

*Recipiente*\
O tipo de contêiner no qual os elementos deverão ser inseridos por um `insert_iterator`.

## <a name="remarks"></a>Comentários

O recipiente `Container` do tipo deve satisfazer os requisitos para um recipiente de tamanho variável `Container::iterator` e `Container::value_type` ter uma `Container::iterator`função de membro de inserção de dois argumentos onde os parâmetros são do tipo e que retorna um tipo . Os contêineres associativos classificados e de sequência da Biblioteca Padrão do C++ atendem a esses requisitos e podem ser adaptados para uso com `insert_iterator`s. Para contêineres associativos, o argumento de posição é tratado como uma dica, que tem o potencial de aumentar ou degradar o desempenho, dependendo da qualidade da dica. Um `insert_iterator` sempre deve ser inicializado com seu contêiner.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[insert_iterator](#insert_iterator)|Constrói um `insert_iterator` que insere um elemento em uma posição especificada em um contêiner.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[container_type](#container_type)|Um tipo que representa o contêiner no qual uma inserção geral deve ser feita.|
|[Referência](#reference)|Um tipo que fornece uma referência a um elemento em uma sequência controlada pelo contêiner associado.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador*](#op_star)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída * `i` = `x` para uma inserção geral.|
|[operador++](#op_add_add)|Incrementa o `insert_iterator` para o próximo local no qual um valor pode ser armazenado.|
|[operador=](#op_eq)|Operador de atribuição usado para implementar a expressão do iterador de saída * `i` = `x` para uma inserção geral.|

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<iterator>

**Namespace:** std

## <a name="insert_iteratorcontainer_type"></a><a name="container_type"></a>insert_iterator:container_type

Um tipo que representa o contêiner no qual uma inserção geral deve ser feita.

```cpp
typedef Container container_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo *Container*.

### <a name="example"></a>Exemplo

```cpp
// insert_iterator_container_type.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   list<int> L1;
   insert_iterator<list<int> >::container_type L2 = L1;
   inserter ( L2, L2.end ( ) ) = 20;
   inserter ( L2, L2.end ( ) ) = 10;
   inserter ( L2, L2.begin ( ) ) = 40;

   list <int>::iterator vIter;
   cout << "The list L2 is: ( ";
   for ( vIter = L2.begin ( ) ; vIter != L2.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;
}
/* Output:
The list L2 is: ( 40 20 10 ).
*/
```

## <a name="insert_iteratorinsert_iterator"></a><a name="insert_iterator"></a>insert_iterator:insert_iterator

Constrói um `insert_iterator` que insere um elemento em uma posição especificada em um contêiner.

```cpp
insert_iterator(Container& _Cont, typename Container::iterator _It);
```

### <a name="parameters"></a>Parâmetros

*_Cont*\
O contêiner no qual o `insert_iterator` deve inserir elementos.

*_It*\
A posição da inserção.

### <a name="remarks"></a>Comentários

Todos os contêineres têm a função membro de inserção chamada pelo `insert_iterator`. Para contêineres associativos, o parâmetro de posição é apenas uma sugestão. A função de inserção fornece uma maneira conveniente de inserir valores.

### <a name="example"></a>Exemplo

```cpp
// insert_iterator_insert_iterator.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   list <int>::iterator L_Iter;

   list<int> L;
   for (i = 1 ; i < 4 ; ++i )
   {
      L.push_back ( 10 * i );
   }

   cout << "The list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++)
      cout << *L_Iter << " ";
   cout << ")." << endl;

   // Using the member function to insert an element
   inserter ( L, L.begin ( ) ) = 2;

   // Alternatively, you may use the template version
   insert_iterator< list < int> > Iter(L, L.end ( ) );
*Iter = 300;

   cout << "After the insertions, the list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;
}
/* Output:
The list L is:
( 10 20 30 ).
After the insertions, the list L is:
( 2 10 20 30 300 ).
*/
```

## <a name="insert_iteratoroperator"></a><a name="op_star"></a>insert_iterator:operador*

Cancela a referência do iterador de inserção, retornando o elemento que é seu alvo.

```cpp
insert_iterator<Container>& operator*();
```

### <a name="return-value"></a>Valor retornado

A função membro retorna o valor do elemento de destino.

### <a name="remarks"></a>Comentários

Usado para implementar o = **valor**de iter da expressão ** \*** de saída . Se `Iter` é um iterator que aborda um elemento em uma seqüência, então = **value** ** \*** o valor de Iter substitui esse elemento por valor e não altera o número total de elementos na seqüência.

### <a name="example"></a>Exemplo

```cpp
// insert_iterator_op_deref.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   list <int>::iterator L_Iter;

   list<int> L;
   for (i = 0 ; i < 4 ; ++i )
   {
      L.push_back ( 2 * i );
   }

   cout << "The original list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;

   insert_iterator< list < int> > Iter(L, L.begin ( ) );
*Iter = 10;
*Iter = 20;
*Iter = 30;

   cout << "After the insertions, the list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;
}
/* Output:
The original list L is:
( 0 2 4 6 ).
After the insertions, the list L is:
( 10 20 30 0 2 4 6 ).
*/
```

## <a name="insert_iteratoroperator"></a><a name="op_add_add"></a>insert_iterator::operador++

Incrementa o `insert_iterator` para o próximo local no qual um valor pode ser armazenado.

```cpp
insert_iterator<Container>& operator++();

insert_iterator<Container> operator++(int);
```

### <a name="parameters"></a>Parâmetros

Um `insert_iterator` que trata do próximo local no qual um valor pode ser armazenado.

### <a name="remarks"></a>Comentários

Os operadores pré-incremento e pós-incremento retornam o mesmo resultado.

### <a name="example"></a>Exemplo

```cpp
// insert_iterator_op_incr.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 5 ; ++i )
   {
      vec.push_back (  i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is:\n ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   insert_iterator<vector<int> > ii ( vec, vec.begin ( ) );
*ii = 30;
   ii++;
*ii = 40;
   ii++;
*ii = 50;

   cout << "After the insertions, the vector vec becomes:\n ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;
}
/* Output:
The vector vec is:
( 1 2 3 4 ).
After the insertions, the vector vec becomes:
( 30 40 50 1 2 3 4 ).
*/
```

## <a name="insert_iteratoroperator"></a><a name="op_eq"></a>insert_iterator:operador=

Insere um valor no contêiner e retorna o iterador atualizado para apontar para o novo elemento.

```cpp
insert_iterator<Container>& operator=(
    typename Container::const_reference val,);

insert_iterator<Container>& operator=(
    typename Container::value_type&& val);
```

### <a name="parameters"></a>Parâmetros

*Val*\
O valor a ser atribuído ao contêiner.

### <a name="return-value"></a>Valor retornado

Uma referência ao elemento inserido no contêiner.

### <a name="remarks"></a>Comentários

O primeiro operador membro avalia

`Iter = container->insert(Iter, val)`;

`++Iter;`

em seguida, retorna `*this`.

O segundo operador membro avalia

`Iter = container->insert(Iter, std::move(val));`

`++Iter;`

em seguida, retorna `*this`.

### <a name="example"></a>Exemplo

```cpp
// insert_iterator_op_assign.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   int i;
   list <int>::iterator L_Iter;

   list<int> L;
   for (i = 0 ; i < 4 ; ++i )
   {
      L.push_back ( 2 * i );
   }

   cout << "The original list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;

   insert_iterator< list < int> > Iter(L, L.begin ( ) );
*Iter = 10;
*Iter = 20;
*Iter = 30;

   cout << "After the insertions, the list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;
}
/* Output:
The original list L is:
( 0 2 4 6 ).
After the insertions, the list L is:
( 10 20 30 0 2 4 6 ).
*/
```

## <a name="insert_iteratorreference"></a><a name="reference"></a>insert_iterator::referência

Um tipo que fornece uma referência a um elemento em uma sequência controlada pelo contêiner associado.

```cpp
typedef typename Container::reference reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento da sequência controlada pelo contêiner associado.

### <a name="example"></a>Exemplo

```cpp
// insert_iterator_container_reference.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   list<int> L;
   insert_iterator<list<int> > iivIter( L , L.begin ( ) );
*iivIter = 10;
*iivIter = 20;
*iivIter = 30;

   list<int>::iterator LIter;
   cout << "The list L is: ( ";
   for ( LIter = L.begin ( ) ; LIter != L.end ( ); LIter++ )
      cout << *LIter << " ";
   cout << ")." << endl;

   insert_iterator<list<int> >::reference
        RefFirst = *(L.begin ( ));
   cout << "The first element in the list L is: "
        << RefFirst << "." << endl;
}
/* Output:
The list L is: ( 10 20 30 ).
The first element in the list L is: 10.
*/
```

## <a name="see-also"></a>Confira também

[\<>do tempo](../standard-library/iterator.md)\
[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
