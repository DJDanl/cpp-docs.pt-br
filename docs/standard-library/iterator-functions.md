---
title: Funções &lt;iterator&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- xutility/std::advance
- xutility/std::back_inserter
- xutility/std::begin
- xutility/std::cbegin
- xutility/std::cend
- xutility/std::distance
- xutility/std::end
- xutility/std::front_inserter
- xutility/std::inserter
- xutility/std::make_checked_array_iterator
- xutility/std::make_move_iterator
- xutility/std::make_unchecked_array_iterator
- xutility/std::next
- xutility/std::prev
ms.assetid: 4a57c9a3-7e36-411f-8655-e0be2eec88e7
caps.latest.revision: 16
manager: ghogen
helpviewer_keywords:
- std::advance [C++]
- std::back_inserter [C++]
- std::begin [C++]
- std::cbegin [C++]
- std::cend [C++]
- std::distance [C++]
- std::end [C++]
- std::front_inserter [C++]
- std::inserter [C++]
- std::make_checked_array_iterator [C++]
- std::make_move_iterator [C++]
- std::make_unchecked_array_iterator [C++]
- std::next [C++]
- std::prev [C++]
ms.openlocfilehash: a57f1c03bc03c72238306e43056240e6d8571a73
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltiteratorgt-functions"></a>Funções &lt;iterador&gt;

||||
|-|-|-|
|[advance](#advance)|[back_inserter](#back_inserter)|[begin](#begin)|
|[cbegin](#cbegin)|[cend](#cend)|[distance](#distance)|
|[end](#end)|[front_inserter](#front_inserter)|[inserter](#inserter)|
|[make_checked_array_iterator](#make_checked_array_iterator)|[make_move_iterator](#make_move_iterator)|[make_unchecked_array_iterator](#make_unchecked_array_iterator)|
|[next](#next)|[prev](#prev)|

## <a name="advance"></a>  advance

Aumenta um iterador por um número especificado de posições.

```cpp
template <class InputIterator, class Distance>
void advance(
    InputIterator& InIt,
    Distance Off);
```

### <a name="parameters"></a>Parâmetros

`InIt` O iterador que é incrementada e que devem satisfazer os requisitos de um iterador de entrada.

`Off` Um tipo integral, que pode ser convertido para o tipo de diferença do iterador e que especifica o número de incrementos a posição do iterador é avançadas.

### <a name="remarks"></a>Comentários

O intervalo avançado não deve ser singular, onde os iteradores devem ser desreferenciados ou passar do fim.

Se **InputIterator** atender aos requisitos de um tipo de iterador bidirecional, `Off` poderá ser negativo. Se **InputIterator** for um tipo de iterador de avanço ou entrada, `Off` não deverá ser negativo.

A função de avanço tem complexidade constante quando **InputIterator** atende aos requisitos de um iterador de acesso aleatório. Caso contrário, ela terá complexidade linear e, portanto, poderá ser cara.

### <a name="example"></a>Exemplo

```cpp
// iterator_advance.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   list<int> L;
   for ( i = 1 ; i < 9 ; ++i )
   {
      L.push_back ( i );
   }
   list <int>::iterator L_Iter, LPOS = L.begin ( );

   cout << "The list L is: ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++)
      cout << *L_Iter << " ";
   cout << ")." << endl;

   cout << "The iterator LPOS initially points to the first element: "
        << *LPOS << "." << endl;

   advance ( LPOS , 4 );
   cout << "LPOS is advanced 4 steps forward to point"
        << " to the fifth element: "
        << *LPOS << "." << endl;

   advance ( LPOS , -3 );
   cout << "LPOS is moved 3 steps back to point to the "
        << "2nd element: " << *LPOS << "." << endl;
}
```

```Output
The list L is: ( 1 2 3 4 5 6 7 8 ).
The iterator LPOS initially points to the first element: 1.
LPOS is advanced 4 steps forward to point to the fifth element: 5.
LPOS is moved 3 steps back to point to the 2nd element: 2.
```

## <a name="back_inserter"></a>  back_inserter

Cria um iterador que pode inserir elementos no fim de um contêiner especificado.

```cpp
template <class Container>
back_insert_iterator<Container> back_inserter(Container& _Cont);
```

### <a name="parameters"></a>Parâmetros

`_Cont` O contêiner no qual a inserção de backup será executado.

### <a name="return-value"></a>Valor de retorno

Um `back_insert_iterator` associado ao objeto de contêiner `_Cont`.

### <a name="remarks"></a>Comentários

Dentro da Biblioteca Padrão do C++, o argumento deve se referir a um dos três contêineres de sequência que têm a função membro `push_back`: [Classe deque](../standard-library/deque-class.md), [Classe list](../standard-library/list-class.md) ou [Classe vector](../standard-library/vector-class.md).

### <a name="example"></a>Exemplo

```cpp
// iterator_back_inserter.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   vector<int> vec;
   for ( i = 0 ; i < 3 ; ++i )
   {
      vec.push_back ( i );
   }

   vector <int>::iterator vIter;
   cout << "The initial vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++)
      cout << *vIter << " ";
   cout << ")." << endl;

   // Insertions can be done with template function
   back_insert_iterator<vector<int> > backiter ( vec );
 *backiter = 30;
   backiter++;
 *backiter = 40;

   // Alternatively, insertions can be done with the
   // back_insert_iterator member function
   back_inserter ( vec ) = 500;
   back_inserter ( vec ) = 600;

   cout << "After the insertions, the vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

```Output
The initial vector vec is: ( 0 1 2 ).
After the insertions, the vector vec is: ( 0 1 2 30 40 500 600 ).
```

## <a name="begin"></a>  begin

Recupera um iterador para o primeiro elemento em um contêiner especificado.

```cpp
template <class Container>
auto begin(Container& cont)  `
   -> decltype(cont.begin());

template <class Container>
auto begin(const Container& cont)   `
   -> decltype(cont.begin());

template <class Ty, class Size>
Ty *begin(Ty (& array)[Size]);
```

### <a name="parameters"></a>Parâmetros

`cont` Um contêiner.

`array` Uma matriz de objetos do tipo `Ty`.

### <a name="return-value"></a>Valor de retorno

As duas primeiras funções de modelo retornam `cont.begin()`. A primeira função é não constante; a segunda é constante.

A terceira função de modelo retorna `array`.

### <a name="example"></a>Exemplo

É recomendável usar essa função de modelo no lugar do membro de contêiner `begin()` quando comportamento mais genérico for exigido.

```cpp
// cl.exe /EHsc /nologo /W4 /MTd
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

template <typename C> void reverse_sort(C& c) {
    using std::begin;
    using std::end;

    std::sort(begin(c), end(c), std::greater<>());
}

template <typename C> void print(const C& c) {
    for (const auto& e : c) {
        std::cout << e << " ";
    }

    std::cout << "\n";
}

int main() {
    std::vector<int> v = { 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 };

    print(v);
    reverse_sort(v);
    print(v);

    std::cout << "--\n";

    int arr[] = { 23, 70, 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1 };

    print(arr);
    reverse_sort(arr);
    print(arr);
}
```

```Output
11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
52 40 34 26 20 17 16 13 11 10 8 5 4 2 1
--
23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1
160 106 80 70 53 40 35 23 20 16 10 8 5 4 2 1
```

A função `reverse_sort` oferece suporte a contêineres de qualquer tipo, além das matrizes regulares, pois ela chama a versão não membro de `begin()`. Se `reverse_sort` fosse codificada para usar o membro de contêiner `begin()`:

```cpp
template <typename C>
void reverse_sort(C& c) {
    using std::begin;
    using std::end;

    std::sort(c.begin(), c.end(), std::greater<>());

}
```

Enviar uma matriz a ela causaria este erro de compilador:

```Output
error C2228: left of '.begin' must have class/struct/union
```

## <a name="cbegin"></a>  cbegin

Recupera um iterador const para o primeiro elemento em um contêiner especificado.

```cpp
template <class Container>
auto cbegin(const Container& cont)
   -> decltype(cont.begin());
```

### <a name="parameters"></a>Parâmetros

`cont` Um contêiner ou lista_de_inicializadores.

### <a name="return-value"></a>Valor de retorno

Uma constante `cont.begin()`.

### <a name="remarks"></a>Comentários

Essa função funciona com todos os contêineres da Biblioteca Padrão do C++ e com [initializer_list](../standard-library/initializer-list-class.md).

Você pode usar essa função membro no lugar da função de modelo `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere que `Container` será um contêiner (não `const`) modificável ou `initializer_list` de qualquer tipo que dê suporte a `begin()` e `cbegin()`.

```cpp
auto i1 = Container.begin();
// i1 is Container<T>::iterator
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator
```

## <a name="cend"></a>  cend

Recupera um iterador const para o elemento que segue o último elemento no contêiner especificado.

```cpp
template <class Container>
auto cend(const Container& cont)
   -> decltype(cont.end());
```

### <a name="parameters"></a>Parâmetros

`cont` Um contêiner ou lista_de_inicializadores.

### <a name="return-value"></a>Valor de retorno

Uma constante `cont.end()`.

### <a name="remarks"></a>Comentários

Essa função funciona com todos os contêineres da Biblioteca Padrão do C++ e com [initializer_list](../standard-library/initializer-list-class.md).

É possível usar essa função membro no lugar da função de modelo [end()](../standard-library/iterator-functions.md#end), de modo a assegurar que o valor retornado seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere que `Container` será um contêiner (não `const`) modificável ou `initializer_list` de qualquer tipo que dê suporte a `end()` e `cend()`.

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator
```

## <a name="distance"></a>  distance

Determina o número de incrementos entre as posições tratadas por dois iteradores.

```cpp
template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last);
```

### <a name="parameters"></a>Parâmetros

`first` O iterador primeiro cuja distância da segunda é determinado.

`last` O iterador segundo cuja distância da primeira é determinado.

### <a name="return-value"></a>Valor de retorno

O número de vezes que `first` deve ser incrementado até igualar `last`.

### <a name="remarks"></a>Comentários

A função de distância tem complexidade constante quando **InputIterator** atende aos requisitos de um iterador de acesso aleatório. Caso contrário, terá complexidade linear e, portanto, será potencialmente cara.

### <a name="example"></a>Exemplo

```cpp
// iterator_distance.cpp
// compile with: /EHsc
#include <iterator>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   int i;

   list<int> L;
   for ( i = -1 ; i < 9 ; ++i )
   {
      L.push_back ( 2 * i );
   }
   list <int>::iterator L_Iter, LPOS = L.begin ( );

   cout << "The list L is: ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;

   cout << "The iterator LPOS initially points to the first element: "
        << *LPOS << "." << endl;

   advance ( LPOS , 7 );
   cout << "LPOS is advanced 7 steps forward to point "
        << " to the eighth element: "
        << *LPOS << "." << endl;

   list<int>::difference_type Ldiff ;
   Ldiff = distance ( L.begin ( ) , LPOS );
   cout << "The distance from L.begin( ) to LPOS is: "
        << Ldiff << "." << endl;
}
```

```Output
The list L is: ( -2 0 2 4 6 8 10 12 14 16 ).
The iterator LPOS initially points to the first element: -2.
LPOS is advanced 7 steps forward to point  to the eighth element: 12.
The distance from L.begin( ) to LPOS is: 7.
```

## <a name="end"></a>  end

Recupera um iterador para o elemento que segue o último elemento no contêiner especificado.

```cpp
template <class Container>
auto end(Container& cont)
   -> decltype(cont.end());

template <class Container>
auto end(const Container& cont)
   -> decltype(cont.end());

template <class Ty, class Size>
Ty *end(Ty (& array)[Size]);
```

### <a name="parameters"></a>Parâmetros

`cont` Um contêiner.

`array` Uma matriz de objetos do tipo `Ty`.

### <a name="return-value"></a>Valor de retorno

As duas primeiras funções de modelo retornam `cont.end()` (a primeira é não constante e a segunda é constante).

A terceira função de modelo retorna `array + Size`.

### <a name="remarks"></a>Comentários

Para obter um exemplo de código, consulte [begin](../standard-library/iterator-functions.md#begin).

## <a name="front_inserter"></a>  front_inserter

Cria um iterador que pode inserir elementos na frente de um contêiner especificado.

```cpp
template <class Container>
front_insert_iterator<Container> front_inserter(Container& _Cont);
```

### <a name="parameters"></a>Parâmetros

`_Cont` O objeto de contêiner cujo frontal tem um elemento inserido.

### <a name="return-value"></a>Valor de retorno

Um `front_insert_iterator` associado ao objeto de contêiner `_Cont`.

### <a name="remarks"></a>Comentários

A função de membro [front_insert_iterator](../standard-library/front-insert-iterator-class.md#front_insert_iterator) da classe front_insert_iterator também pode ser usada.

Dentro da Biblioteca Padrão do C++, o argumento deve se referir a um dos dois contêineres de sequência que têm a função membro `push_back`: [Classe deque](../standard-library/deque-class.md) ou "Classe list".

### <a name="example"></a>Exemplo

```cpp
// iterator_front_inserter.cpp
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
   for ( i = -1 ; i < 9 ; ++i )
   {
      L.push_back ( i );
   }

   cout << "The list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++)
      cout << *L_Iter << " ";
   cout << ")." << endl;

   // Using the template function to insert an element
   front_insert_iterator< list < int> > Iter(L);
 *Iter = 100;

   // Alternatively, you may use the front_insert member function
   front_inserter ( L ) = 200;

   cout << "After the front insertions, the list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++)
      cout << *L_Iter << " ";
   cout << ")." << endl;
}
```

```Output
The list L is:
 ( -1 0 1 2 3 4 5 6 7 8 ).
After the front insertions, the list L is:
 ( 200 100 -1 0 1 2 3 4 5 6 7 8 ).
```

## <a name="inserter"></a>  inserter

Um modelo de função auxiliar que permite que você use `inserter(_Cont, _Where)` em vez de `insert_iterator<Container>(_Cont, _Where)`.

```cpp
template <class Container>
insert_iterator<Container>
inserter(
    Container& _Cont,
    typename Container::iterator _Where);
```

### <a name="parameters"></a>Parâmetros

`_Cont` O contêiner para o qual novos elementos devem ser adicionadas.

`_Where` Um iterador localizar o ponto de inserção.

### <a name="remarks"></a>Comentários

Retorna a função de modelo [insert_iterator](../standard-library/insert-iterator-class.md#insert_iterator)`<Container>(_Cont, _Where)`.

### <a name="example"></a>Exemplo

```cpp
// iterator_inserter.cpp
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
   for (i = 2 ; i < 5 ; ++i )
   {
      L.push_back ( 10 * i );
   }

   cout << "The list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++ )
      cout << *L_Iter << " ";
   cout << ")." << endl;

   // Using the template version to insert an element
   insert_iterator<list <int> > Iter( L, L.begin ( ) );
 *Iter = 1;

   // Alternatively, using the member function to insert an element
   inserter ( L, L.end ( ) ) = 500;

   cout << "After the insertions, the list L is:\n ( ";
   for ( L_Iter = L.begin( ) ; L_Iter != L.end( ); L_Iter++)
      cout << *L_Iter << " ";
   cout << ")." << endl;
}
```

```Output
The list L is:
 ( 20 30 40 ).
After the insertions, the list L is:
 ( 1 20 30 40 500 ).
```

## <a name="make_checked_array_iterator"></a>  make_checked_array_iterator

Cria um [checked_array_iterator](../standard-library/checked-array-iterator-class.md) que pode ser usado por outros algoritmos.

> [!NOTE]
> Essa função é uma extensão da Biblioteca Padrão do C++ da Microsoft. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.

```cpp
template <class Iter>
checked_array_iterator<Iter>
    make_checked_array_iterator(
 Iter Ptr,
    size_t Size,
    size_t Index = 0);
```

### <a name="parameters"></a>Parâmetros

`Ptr` Um ponteiro para a matriz de destino.

`Size` O tamanho da matriz de destino.

`Index` Opcional índice na matriz.

### <a name="return-value"></a>Valor de retorno

Uma instância de `checked_array_iterator`.

### <a name="remarks"></a>Comentários

A função `make_checked_array_iterator` é definida no namespace `stdext`.

Essa função usa um ponteiro bruto – que normalmente geraria preocupação sobre estouro de limites – e o encapsula em uma classe [checked_array_iterator](../standard-library/checked-array-iterator-class.md) que faz a verificação. Como essa classe é marcada como verificada, a Biblioteca Padrão do C++ não avisa sobre isso. Para obter mais informações e exemplos de código, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

No exemplo a seguir, um [vetor](../standard-library/vector-class.md) é criado e populado com 10 itens. O conteúdo do vetor é copiado em uma matriz usando o algoritmo de cópia e, em seguida, `make_checked_array_iterator` é usado para especificar o destino. Isso é seguido por uma violação intencional da verificação dos limites, de modo que uma falha de asserção de depuração é acionada.

```cpp
// make_checked_array_iterator.cpp
// compile with: /EHsc /W4 /MTd

#include <algorithm>
#include <iterator> // stdext::make_checked_array_iterator
#include <memory> // std::make_unique
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

int main()
{
    const size_t dest_size = 10;
    // Old-school but not exception safe, favor make_unique<int[]>
    // int* dest = new int[dest_size];
    unique_ptr<int[]> updest = make_unique<int[]>(dest_size);
    int* dest = updest.get(); // get a raw pointer for the demo

    vector<int> v;

    for (int i = 0; i < dest_size; ++i) {
        v.push_back(i);
    }
    print("vector v: ", v);

    copy(v.begin(), v.end(), stdext::make_checked_array_iterator(dest, dest_size));

    cout << "int array dest: ";
    for (int i = 0; i < dest_size; ++i) {
        cout << dest[i] << " ";
    }
    cout << endl;

    // Add another element to the vector to force an overrun.
    v.push_back(10);
    // The next line causes a debug assertion when it executes.
    copy(v.begin(), v.end(), stdext::make_checked_array_iterator(dest, dest_size));
}

```

## <a name="make_move_iterator"></a>  make_move_iterator

Cria um `move iterator` que contém o iterador fornecido como o iterador `stored`.

```cpp
template <class Iterator>
move_iterator<Iterator>
make_move_iterator(const Iterator& _It);
```

### <a name="parameters"></a>Parâmetros

`_It` O iterador armazenado no iterador de movimentação de novo.

### <a name="remarks"></a>Comentários

Retorna a função de modelo `move_iterator` `<Iterator>(_It)`.

## <a name="make_unchecked_array_iterator"></a>  make_unchecked_array_iterator

Cria um [unchecked_array_iterator](../standard-library/unchecked-array-iterator-class.md) que pode ser usado por outros algoritmos.

> [!NOTE]
> Essa função é uma extensão da Biblioteca Padrão do C++ da Microsoft. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.

```cpp
template <class Iter>
unchecked_array_iterator<Iter>
    make_unchecked_array_iterator(Iter Ptr);
```

### <a name="parameters"></a>Parâmetros

`Ptr` Um ponteiro para a matriz de destino.

### <a name="return-value"></a>Valor de retorno

Uma instância de `unchecked_array_iterator`.

### <a name="remarks"></a>Comentários

A função `make_unchecked_array_iterator` é definida no namespace `stdext`.

Essa função usa um ponteiro bruto e o encapsula em uma classe que não executa verificação e, portanto, a otimização não serve para nada, mas ela também silencia os avisos do compilador, como o [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Desse modo, essa é uma maneira direcionada de lidar com avisos de ponteiro não verificado, sem silenciá-los globalmente ou incorrer no custo da verificação. Para obter mais informações e exemplos de código, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

No exemplo a seguir, um [vetor](../standard-library/vector-class.md) é criado e populado com 10 itens. O conteúdo do vetor é copiado em uma matriz usando o algoritmo de cópia e, em seguida, `make_unchecked_array_iterator` é usado para especificar o destino.

```cpp
// make_unchecked_array_iterator.cpp
// compile with: /EHsc /W4 /MTd

#include <algorithm>
#include <iterator> // stdext::make_unchecked_array_iterator
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

int main()
{
    const size_t dest_size = 10;
    int *dest = new int[dest_size];
    vector<int> v;

    for (int i = 0; i < dest_size; ++i) {
        v.push_back(i);
    }
    print("vector v: ", v);

    // COMPILER WARNING SILENCED: stdext::unchecked_array_iterator is marked as checked in debug mode
    // (it performs no checking, so an overrun will trigger undefined behavior)
    copy(v.begin(), v.end(), stdext::make_unchecked_array_iterator(dest));

    cout << "int array dest: ";
    for (int i = 0; i < dest_size; ++i) {
        cout << dest[i] << " ";
    }
    cout << endl;

    delete[] dest;
}

```

## <a name="next"></a>  next

Itera um número de vezes especificado e retorna a nova posição do iterador.

```cpp
template <class InputIterator>
InputIterator next(
    InputIterator first,
    typename iterator_traits<InputIterator>::difference_type _Off = 1);
```

### <a name="parameters"></a>Parâmetros

`first` A posição atual.

`_Off` O número de vezes para repetir.

### <a name="return-value"></a>Valor de retorno

Retorna a nova posição do iterador após iterar `_Off` vezes.

### <a name="remarks"></a>Comentários

A função de modelo retorna `next` incrementado `_Off` vezes

## <a name="prev"></a>  prev

Itera em ordem inversa um número de vezes especificado e retorna a nova posição do iterador.

```cpp
template <class BidirectionalIterator>
BidirectionalIterator prev(
    BidirectionalIterator first,
    typename iterator_traits<BidirectionalIterator>::difference_type _Off = 1);
```

### <a name="parameters"></a>Parâmetros

`first` A posição atual.

`_Off` O número de vezes para repetir.

### <a name="remarks"></a>Comentários

A função de modelo retorna `next` decrementado `off` vezes.

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)<br/>
