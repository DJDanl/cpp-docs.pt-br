---
title: Classe back_insert_iterator
ms.date: 11/04/2016
f1_keywords:
- iterator/std::back_insert_iterator
- iterator/std::back_insert_iterator::container_type
- iterator/std::back_insert_iterator::reference
helpviewer_keywords:
- std::back_insert_iterator [C++]
- std::back_insert_iterator [C++], container_type
- std::back_insert_iterator [C++], reference
ms.assetid: a1ee07f2-cf9f-46a1-8608-cfaf207f9713
ms.openlocfilehash: 2a0510b6df656b7925fd42a4c97d768336537424
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62376439"
---
# <a name="backinsertiterator-class"></a>Classe back_insert_iterator

Descreve um adaptador de iterador que atende aos requisitos de um iterador de saída. Insere, em vez de substituições, elementos no fim de uma sequência e, dessa forma, fornece semânticas que são diferentes da semântica de substituição fornecida pelos iteradores dos contêineres de sequência do C++. A classe `back_insert_iterator` é modelada no tipo do contêiner.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Container>
class back_insert_iterator;
```

### <a name="parameters"></a>Parâmetros

*Container*<br/>
O tipo de contêiner na parte de trás dos elementos a serem inseridos por um `back_insert_iterator`.

## <a name="remarks"></a>Comentários

O contêiner deve atender aos requisitos de uma sequência de inserção posterior em que é possível inserir elementos no fim da sequência em tempo constante amortizado. Os contêineres de sequência da Biblioteca Padrão C++ definidos pela [Classe deque](../standard-library/deque-class.md), [Classe list](../standard-library/list-class.md) e [classe Vector](../standard-library/vector-class.md) fornecem a função membro `push_back` necessária e atendem a esses requisitos. Esses três contêineres, bem como as cadeias de caracteres, podem ser adaptados para uso com `back_insert_iterator`s. Um `back_insert_iterator` sempre deve ser inicializado com seu contêiner.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[back_insert_iterator](#back_insert_iterator)|Constrói um `back_insert_iterator` que insere elementos depois do último elemento em um contêiner.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[container_type](#container_type)|Um tipo que fornece um contêiner para `back_insert_iterator`.|
|[reference](#reference)|Um tipo que fornece uma referência para `back_insert_iterator`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator*](#op_star)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída \* `i`  =  `x` para uma inserção posterior.|
|[operator++](#op_add_add)|Incrementa o `back_insert_iterator` para o próximo local no qual um valor pode ser armazenado.|
|[operator=](#op_eq)|Operador de atribuição usado para implementar a expressão do iterador de saída \* `i`  =  `x` para uma inserção posterior.|

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<iterator>

**Namespace:** std

## <a name="back_insert_iterator"></a>  back_insert_iterator::back_insert_iterator

Constrói um `back_insert_iterator` que insere elementos depois do último elemento em um contêiner.

```cpp
explicit back_insert_iterator(Container& _Cont);
```

### <a name="parameters"></a>Parâmetros

*_Cont*<br/>
O contêiner em que o `back_insert_iterator` deve inserir um elemento.

### <a name="return-value"></a>Valor de retorno

Um `back_insert_iterator` para o contêiner do parâmetro.

### <a name="example"></a>Exemplo

```cpp
// back_insert_iterator_back_insert_iterator.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for ( i = 1 ; i < 4 ; ++i )
   {
      vec.push_back ( i );
   }

   vector <int>::iterator vIter;
   cout << "The initial vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   // Insertions with member function
   back_inserter ( vec ) = 40;
   back_inserter ( vec ) = 50;

   // Alternatively, insertions can be done with template function
   back_insert_iterator<vector<int> > backiter ( vec );
*backiter = 600;
   backiter++;
*backiter = 700;

   cout << "After the insertions, the vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

```Output
The initial vector vec is: ( 1 2 3 ).
After the insertions, the vector vec is: ( 1 2 3 40 50 600 700 ).
```

## <a name="container_type"></a>  back_insert_iterator::container_type

Um tipo que fornece um contêiner para `back_insert_iterator`.

```cpp
typedef Container
container_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **Container**.

### <a name="example"></a>Exemplo

```cpp
// back_insert_iterator_container_type.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 4 ; ++i )
   {
      vec.push_back (  i );
   }

   vector <int>::iterator vIter;
   cout << "The original vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   back_insert_iterator<vector<int> >::container_type vec1 = vec;
   back_inserter ( vec1 ) = 40;

   cout << "After the insertion, the vector is: ( ";
   for ( vIter = vec1.begin ( ) ; vIter != vec1.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

```Output
The original vector vec is: ( 1 2 3 ).
After the insertion, the vector is: ( 1 2 3 40 ).
```

## <a name="op_star"></a>  back_insert_iterator::operator\*

Operador de desreferenciamento usado para implementar a expressão do iterador de saída \* *i* = *x*.

```cpp
back_insert_iterator<Container>& operator*();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao elemento inserido na parte posterior do contêiner.

### <a name="remarks"></a>Comentários

Usado para implementar a expressão do iterador de saída **\*Iter** = **value**. Se **Iter** for um iterador que trata de um elemento em uma sequência, **\*Iter** = **value** substituirá esse elemento pelo valor e não alterará o número total de elementos na sequência.

### <a name="example"></a>Exemplo

```cpp
// back_insert_iterator_back_insert.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 4 ; ++i )
   {
      vec.push_back ( i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   back_insert_iterator<vector<int> > backiter ( vec );
*backiter = 10;
   backiter++;      // Increment to the next element
*backiter = 20;
   backiter++;

   cout << "After the insertions, the vector vec becomes: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

```Output
The vector vec is: ( 1 2 3 ).
After the insertions, the vector vec becomes: ( 1 2 3 10 20 ).
```

## <a name="op_add_add"></a>  back_insert_iterator::operator++

Incrementa o `back_insert_iterator` para o próximo local no qual um valor pode ser armazenado.

```cpp
back_insert_iterator<Container>& operator++();
back_insert_iterator<Container> operator++(int);
```

### <a name="return-value"></a>Valor de retorno

Um `back_insert_iterator` que trata do próximo local no qual um valor pode ser armazenado.

### <a name="remarks"></a>Comentários

Os operadores pré-incremento e pós-incremento retornam o mesmo resultado.

### <a name="example"></a>Exemplo

```cpp
// back_insert_iterator_op_incre.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 3 ; ++i )
   {
      vec.push_back ( 10 * i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   back_insert_iterator<vector<int> > backiter ( vec );
*backiter = 30;
   backiter++;      // Increment to the next element
*backiter = 40;
   backiter++;

   cout << "After the insertions, the vector vec becomes: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

```Output
The vector vec is: ( 10 20 ).
After the insertions, the vector vec becomes: ( 10 20 30 40 ).
```

## <a name="op_eq"></a>  back_insert_iterator::operator=

Anexa ou envia um valor para o back-end de um contêiner.

```cpp
back_insert_iterator<Container>& operator=(typename Container::const_reference val);
back_insert_iterator<Container>& operator=(typename Container::value_type&& val);
```

### <a name="parameters"></a>Parâmetros

*val*<br/>
O valor a ser inserido no contêiner.

### <a name="return-value"></a>Valor de retorno

Uma referência ao último elemento inserido na parte posterior do contêiner.

### <a name="remarks"></a>Comentários

O primeiro operador membro avalia `Container.push_back( val)`,

em seguida, retorna `*this`. O segundo operador membro avalia

`container->push_back((typename Container::value_type&&)val)`,

em seguida, retorna `*this`.

### <a name="example"></a>Exemplo

```cpp
// back_insert_iterator_op_assign.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 4 ; ++i )
   {
      vec.push_back ( i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   back_insert_iterator<vector<int> > backiter ( vec );
*backiter = 10;
   backiter++;      // Increment to the next element
*backiter = 20;
   backiter++;

   cout << "After the insertions, the vector vec becomes: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

## <a name="reference"></a>  back_insert_iterator::reference

Um tipo que fornece uma referência para `back_insert_iterator`.

```cpp
typedef typename Container::reference reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma referência a um elemento da sequência controlada pelo contêiner associado.

### <a name="example"></a>Exemplo

```cpp
// back_insert_iterator_reference.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for (i = 1 ; i < 4 ; ++i )
   {
      vec.push_back ( i );
   }

   vector <int>::iterator vIter;
   cout << "The vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   back_insert_iterator<vector<int> >::reference
        RefLast = *(vec.end ( ) - 1 );
   cout << "The last element in the vector vec is: "
        << RefLast << "." << endl;
}
```

```Output
The vector vec is: ( 1 2 3 ).
The last element in the vector vec is: 3.
```

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
