---
title: Classe list
ms.date: 11/04/2016
f1_keywords:
- list/std::list
- list/std::list::allocator_type
- list/std::list::const_iterator
- list/std::list::const_pointer
- list/std::list::const_reference
- list/std::list::const_reverse_iterator
- list/std::list::difference_type
- list/std::list::iterator
- list/std::list::pointer
- list/std::list::reference
- list/std::list::reverse_iterator
- list/std::list::size_type
- list/std::list::value_type
- list/std::list::assign
- list/std::list::back
- list/std::list::begin
- list/std::list::cbegin
- list/std::list::cend
- list/std::list::clear
- list/std::list::crbegin
- list/std::list::crend
- list/std::list::emplace
- list/std::list::emplace_back
- list/std::list::emplace_front
- list/std::list::empty
- list/std::list::end
- list/std::list::erase
- list/std::list::front
- list/std::list::get_allocator
- list/std::list::insert
- list/std::list::max_size
- list/std::list::merge
- list/std::list::pop_back
- list/std::list::pop_front
- list/std::list::push_back
- list/std::list::push_front
- list/std::list::rbegin
- list/std::list::remove
- list/std::list::remove_if
- list/std::list::rend
- list/std::list::resize
- list/std::list::reverse
- list/std::list::size
- list/std::list::sort
- list/std::list::splice
- list/std::list::swap
- list/std::list::unique
helpviewer_keywords:
- std::list [C++]
- std::list [C++], allocator_type
- std::list [C++], const_iterator
- std::list [C++], const_pointer
- std::list [C++], const_reference
- std::list [C++], const_reverse_iterator
- std::list [C++], difference_type
- std::list [C++], iterator
- std::list [C++], pointer
- std::list [C++], reference
- std::list [C++], reverse_iterator
- std::list [C++], size_type
- std::list [C++], value_type
- std::list [C++], assign
- std::list [C++], back
- std::list [C++], begin
- std::list [C++], cbegin
- std::list [C++], cend
- std::list [C++], clear
- std::list [C++], crbegin
- std::list [C++], crend
- std::list [C++], emplace
- std::list [C++], emplace_back
- std::list [C++], emplace_front
- std::list [C++], empty
- std::list [C++], end
- std::list [C++], erase
- std::list [C++], front
- std::list [C++], get_allocator
- std::list [C++], insert
- std::list [C++], max_size
- std::list [C++], merge
- std::list [C++], pop_back
- std::list [C++], pop_front
- std::list [C++], push_back
- std::list [C++], push_front
- std::list [C++], rbegin
- std::list [C++], remove
- std::list [C++], remove_if
- std::list [C++], rend
- std::list [C++], resize
- std::list [C++], reverse
- std::list [C++], size
- std::list [C++], sort
- std::list [C++], splice
- std::list [C++], swap
- std::list [C++], unique
ms.assetid: d3707f4a-10fd-444f-b856-f9ca2077c1cd
ms.openlocfilehash: bf59438ca30462866cd90e281903356b863e36aa
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224845"
---
# <a name="list-class"></a>Classe list

A classe de lista de bibliotecas padrão do C++ é um modelo de classe de contêineres de sequência que mantém seus elementos em uma organização linear e permite inserções e exclusões eficientes em qualquer local dentro da sequência. A sequência é armazenada como uma lista vinculada bidirecional de elementos, cada um contendo um membro de algum tipo de *Type*.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type, class Allocator= allocator<Type>>
class list
```

### <a name="parameters"></a>parâmetros

*Escreva*\
O tipo de dados do elemento a ser armazenado na lista.

*Alocador*\
O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória da lista. Esse argumento é opcional e o valor padrão é `allocator<Type>`.

## <a name="remarks"></a>Comentários

A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Vetores devem ser o contêiner preferencial para gerenciar uma sequência quando o acesso aleatório a qualquer elemento é alto e inserção e exclusões de elementos apenas são necessárias no final de uma sequência. O desempenho do contêiner de deque de classe é superior quando o acesso aleatório é necessário e as inserções e exclusões no início e final de uma sequência são essenciais.

As funções de membro da lista [mesclar](#merge), [inverter](#reverse), [exclusiva](#unique), [remover](#remove) e [remove_if](#remove_if) foram otimizadas para funcionar com objetos da lista e oferecer uma alternativa de alto desempenho para os seus correspondentes genéricos.

A realocação da lista ocorre quando uma função de membro deve inserir ou apagar elementos da lista. Nesses casos, somente iteradores ou referências que apontem para partes apagadas da sequência controladas tornam-se inválidos.

Inclua o cabeçalho Standard da biblioteca padrão C++ \<list> para definir a lista de modelos de classe de [contêiner](../standard-library/stl-containers.md) e vários modelos de suporte.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[list](#list)|Constrói uma lista de um tamanho específico, ou com elementos de um valor específico, ou com um `allocator` específico, ou como uma cópia de alguma outra lista.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para um objeto de lista.|
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador bidirecional que pode ler um **`const`** elemento em uma lista.|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um **`const`** elemento em uma lista.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência a um **`const`** elemento armazenado em uma lista para leitura e execução de **`const`** operações.|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer **`const`** elemento em uma lista.|
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre dois iteradores que se referem a elementos na mesma lista.|
|[repeti](#iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em uma lista.|
|[refere](#pointer)|Um tipo que fornece um ponteiro para um elemento em uma lista.|
|[reference](#reference)|Um tipo que fornece uma referência a um **`const`** elemento armazenado em uma lista para leitura e execução de **`const`** operações.|
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em uma lista invertida.|
|[size_type](#size_type)|Um tipo que conta o número de elementos em uma lista.|
|[value_type](#value_type)|Um tipo que representa o tipo de dados armazenado em uma lista.|

### <a name="functions"></a>Funções

|||
|-|-|
|[assign](#assign)|Apaga os elementos de uma lista e copia um novo conjunto de elementos na lista de destino.|
|[Voltar](#back)|Retorna uma referência ao último elemento de uma lista.|
|[Comece](#begin)|Retorna um iterador que trata o primeiro elemento em uma lista.|
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento em uma lista.|
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em uma lista.|
|[formatação](#clear)|Apaga todos os elementos de uma lista.|
|[crbegin](#crbegin)|Retorna um iterador const que trata o primeiro elemento em uma lista invertida.|
|[crend](#crend)|Retorna um iterador const que trata o local após o último elemento em uma lista invertida.|
|[emplace](#emplace)|Insere um elemento construído no local em uma lista na posição especificada.|
|[emplace_back](#emplace_back)|Adiciona um elemento construído no local ao final de uma lista.|
|[emplace_front](#emplace_front)|Adiciona um elemento construído no local ao início de uma lista.|
|[empty](#empty)|Testa se uma lista está vazia.|
|[completo](#end)|Retorna um iterador que trata o local após o último elemento em uma lista.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos das posições especificadas.|
|[dianteiro](#front)|Retorna uma referência ao primeiro elemento em uma lista.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` usada para construir uma lista.|
|[insert](#insert)|Insere um elemento ou um número de elementos ou um intervalo de elementos em uma lista, na posição especificada.|
|[max_size](#max_size)|Retorna o tamanho máximo de uma lista.|
|[Mescle](#merge)|Remove os elementos da lista de argumentos, insere-os na lista de destino e organiza o conjunto novo e combinado de elementos em ordem crescente ou em alguma outra ordem especificada.|
|[pop_back](#pop_back)|Exclui o elemento no final de uma lista.|
|[pop_front](#pop_front)|Exclui o elemento no começo de uma lista.|
|[push_back](#push_back)|Adiciona um elemento ao fim da lista.|
|[push_front](#push_front)|Adiciona um elemento ao começo da lista.|
|[rbegin](#rbegin)|Retorna um iterador que trata o primeiro elemento em uma lista inversa.|
|[remove](#remove)|Apaga elementos em uma lista que correspondem a um valor especificado.|
|[remove_if](#remove_if)|Apaga os elementos da lista para a qual um predicado especificado foi atendido.|
|[rend](#rend)|Retorna um iterador que trata o local após o último elemento em uma lista invertida.|
|[alonga](#resize)|Especifica um novo tamanho para uma lista.|
|[ordem](#reverse)|Reverte a ordem na qual os elementos ocorrem em uma lista.|
|[size](#size)|Retorna o número de elementos em uma lista.|
|[sort](#sort)|Organiza os elementos de uma lista em ordem crescente ou com respeito a alguma outra relação de ordem.|
|[splice](#splice)|Remove os elementos da lista de argumentos e os insere na lista de destino.|
|[permuta](#swap)|Troca os elementos das duas listas.|
|[unique](#unique)|Remove elementos duplicados adjacentes ou elementos adjacentes que satisfazem algum predicado binário da lista.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#op_eq)|Substitui os elementos da lista por uma cópia de outra lista.|

## <a name="requirements"></a>Requisitos

**Cabeçalho**:\<list>

## <a name="allocator_type"></a><a name="allocator_type"></a>allocator_type

Um tipo que representa a classe de alocador para um objeto de lista.

```cpp
typedef Allocator allocator_type;
```

### <a name="remarks"></a>Comentários

`allocator_type`é um sinônimo para o *alocador*de parâmetro de modelo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_allocator](#get_allocator).

## <a name="assign"></a><a name="assign"></a>Cancele

Apaga os elementos de uma lista e copia um novo conjunto de elementos na lista de destino.

```cpp
void assign(
    size_type Count,
    const Type& Val);

void assign
    initializer_list<Type> IList);

template <class InputIterator>
void assign(
    InputIterator First,
    InputIterator Last);
```

### <a name="parameters"></a>parâmetros

*Primeiro*\
Posição do elemento primeiro no intervalo de elementos ser copiado da lista de argumentos.

*Última*\
Posição do primeiro elemento além do intervalo de elementos a ser copiado da lista de argumentos.

*Contar*\
O número de cópias de um elemento sendo inseridos na lista.

*Val*\
O valor do elemento sendo inserido na lista.

*IList*\
O initializer_list que contém os elementos a serem inseridos.

### <a name="remarks"></a>Comentários

Depois de apagar os elementos da lista de destino, atribua às inserções um intervalo especificado de elementos a partir da lista original ou de alguma outra lista na lista de destino ou insira cópias de um novo elemento de um valor especificado na lista de destino

### <a name="example"></a>Exemplo

```cpp
// list_assign.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main()
{
    using namespace std;
    list<int> c1, c2;
    list<int>::const_iterator cIter;

    c1.push_back(10);
    c1.push_back(20);
    c1.push_back(30);
    c2.push_back(40);
    c2.push_back(50);
    c2.push_back(60);

    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    c1.assign(++c2.begin(), c2.end());
    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    c1.assign(7, 4);
    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    c1.assign({ 10, 20, 30, 40 });
    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;
}
```

```Output
c1 = 10 20 30c1 = 50 60c1 = 4 4 4 4 4 4 4c1 = 10 20 30 40
```

## <a name="back"></a><a name="back"></a>Voltar

Retorna uma referência ao último elemento de uma lista.

```cpp
reference back();

const_reference back() const;
```

### <a name="return-value"></a>Valor retornado

O último elemento da lista. Se a lista estiver vazia, o valor de retorno será indefinido.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `back` for atribuído a `const_reference`, o objeto de lista não poderá ser modificado. Se o valor retornado de `back` for atribuído à `reference`, o objeto de lista poderá ser modificado.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento em uma lista vazia.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.

### <a name="example"></a>Exemplo

```cpp
// list_back.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );
   c1.push_back( 11 );

   int& i = c1.back( );
   const int& ii = c1.front( );

   cout << "The last integer of c1 is " << i << endl;
   i--;
   cout << "The next-to-last integer of c1 is " << ii << endl;
}
```

```Output
The last integer of c1 is 11
The next-to-last integer of c1 is 10
```

## <a name="begin"></a><a name="begin"></a>Comece

Retorna um iterador que trata o primeiro elemento em uma lista.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional que aborda o primeiro elemento na lista ou o local que substitui uma lista vazia.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `begin` for atribuído a um `const_iterator` , os elementos no objeto de lista não poderão ser modificados. Se o valor de retorno de `begin` for atribuído a um `iterator` , os elementos no objeto de lista poderão ser modificados.

### <a name="example"></a>Exemplo

```cpp
// list_begin.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;
   list <int>::const_iterator c1_cIter;

   c1.push_back( 1 );
   c1.push_back( 2 );

   c1_Iter = c1.begin( );
   cout << "The first element of c1 is " << *c1_Iter << endl;

*c1_Iter = 20;
   c1_Iter = c1.begin( );
   cout << "The first element of c1 is now " << *c1_Iter << endl;

   // The following line would be an error because iterator is const
   // *c1_cIter = 200;
}
```

```Output
The first element of c1 is 1
The first element of c1 is now 20
```

## <a name="cbegin"></a><a name="cbegin"></a>cbegin

Retorna um **`const`** iterador que aborda o primeiro elemento no intervalo.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um **`const`** iterador de acesso bidirecional que aponta para o primeiro elemento do intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()` ).

### <a name="remarks"></a>Comentários

Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.

Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **`const`** ) de qualquer tipo que dê suporte a `begin()` e `cbegin()` .

```cpp
auto i1 = Container.begin();
// i1 is Container<T>::iterator
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator
```

## <a name="cend"></a><a name="cend"></a>cend

Retorna um **`const`** iterador que aborda o local logo após o último elemento em um intervalo.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor retornado

Um **`const`** iterador de acesso bidirecional que aponta muito além do fim do intervalo.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador passou do fim de seu intervalo.

Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **`const`** ) de qualquer tipo que dê suporte a `end()` e `cend()` .

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator
```

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="clear"></a><a name="clear"></a>formatação

Apaga todos os elementos de uma lista.

```cpp
void clear();
```

### <a name="example"></a>Exemplo

```cpp
// list_clear.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main() {
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   cout << "The size of the list is initially " << c1.size( ) << endl;
   c1.clear( );
   cout << "The size of list after clearing is " << c1.size( ) << endl;
}
```

```Output
The size of the list is initially 3
The size of list after clearing is 0
```

## <a name="const_iterator"></a><a name="const_iterator"></a>const_iterator

Um tipo que fornece um iterador bidirecional que pode ler um **`const`** elemento em uma lista.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Consulte o exemplo de [back](#back).

## <a name="const_pointer"></a><a name="const_pointer"></a>const_pointer

Fornece um ponteiro para um **`const`** elemento em uma lista.

```cpp
typedef typename Allocator::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto de lista.

## <a name="const_reference"></a><a name="const_reference"></a>const_reference

Um tipo que fornece uma referência a um **`const`** elemento armazenado em uma lista para leitura e execução de **`const`** operações.

```cpp
typedef typename Allocator::const_reference const_reference;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_reference` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

```cpp
// list_const_ref.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );
   c1.push_back( 20 );

   const list <int> c2 = c1;
   const int &i = c2.front( );
   const int &j = c2.back( );
   cout << "The first element is " << i << endl;
   cout << "The second element is " << j << endl;

   // The following line would cause an error because c2 is const
   // c2.push_back( 30 );
}
```

```Output
The first element is 10
The second element is 20
```

## <a name="const_reverse_iterator"></a><a name="const_reverse_iterator"></a>const_reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler qualquer **`const`** elemento em uma lista.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para percorrer a lista em ordem inversa.

### <a name="example"></a>Exemplo

Consulte o exemplo de [rbegin](#rbegin).

## <a name="crbegin"></a><a name="crbegin"></a>crbegin

Retorna um iterador const que trata o primeiro elemento em uma lista invertida.

```cpp
const_reverse_iterator rbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional constante invertido que trata o primeiro elemento em uma lista invertida (ou tratando o que foi o último elemento no `list` não invertido).

### <a name="remarks"></a>Comentários

`crbegin` é usado com uma lista invertida assim como [list::begin](#begin) é usado com uma `list`.

Com o valor de retorno de `crbegin`, o objeto não pode ser modificado. [list::rbegin](#rbegin) pode ser usado para iterar por meio de uma lista no sentido inverso.

### <a name="example"></a>Exemplo

```cpp
// list_crbegin.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::const_reverse_iterator c1_crIter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );
   c1_crIter = c1.crbegin( );
   cout << "The last element in the list is " << *c1_crIter << "." << endl;
}
```

```Output
The last element in the list is 30.
```

## <a name="crend"></a><a name="crend"></a>crend

Retorna um iterador const que trata o local após o último elemento em uma lista invertida.

```cpp
const_reverse_iterator rend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional inverso const que aborda a localização que vem após o último elemento em uma [lista](../standard-library/list-class.md) invertida (o local que precedeu o primeiro elemento na `list` não invertida).

### <a name="remarks"></a>Comentários

`crend` é usado com uma lista invertida, assim como [list::end](#end) é usado com uma `list`.

Com o valor de retorno `crend`, o objeto `list` não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `list`.

O valor retornado por `crend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// list_crend.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::const_reverse_iterator c1_crIter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   c1_crIter = c1.crend( );
   c1_crIter --;  // Decrementing a reverse iterator moves it forward in
                 // the list (to point to the first element here)
   cout << "The first element in the list is: " << *c1_crIter << endl;
}
```

```Output
The first element in the list is: 10
```

## <a name="difference_type"></a><a name="difference_type"></a>difference_type

Um tipo de inteiro marcado que pode ser usado para representar o número de elementos de uma lista em um intervalo entre os elementos apontados por iteradores.

```cpp
typedef typename Allocator::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

`difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` geralmente é usado para representar o número de elementos no intervalo [`first`, `last`) entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte de contêineres reversíveis como conjunto, a subtração entre iteradores só terá suporte de iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como uma [classe de vetores](../standard-library/vector-class.md).

### <a name="example"></a>Exemplo

```cpp
// list_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <list>
#include <algorithm>

int main( )
{
   using namespace std;

   list <int> c1;
   list <int>::iterator   c1_Iter, c2_Iter;

   c1.push_back( 30 );
   c1.push_back( 20 );
   c1.push_back( 30 );
   c1.push_back( 10 );
   c1.push_back( 30 );
   c1.push_back( 20 );

   c1_Iter = c1.begin( );
   c2_Iter = c1.end( );

    list <int>::difference_type df_typ1, df_typ2, df_typ3;

   df_typ1 = count( c1_Iter, c2_Iter, 10 );
   df_typ2 = count( c1_Iter, c2_Iter, 20 );
   df_typ3 = count( c1_Iter, c2_Iter, 30 );
   cout << "The number '10' is in c1 collection " << df_typ1 << " times.\n";
   cout << "The number '20' is in c1 collection " << df_typ2 << " times.\n";
   cout << "The number '30' is in c1 collection " << df_typ3 << " times.\n";
}
```

```Output
The number '10' is in c1 collection 1 times.
The number '20' is in c1 collection 2 times.
The number '30' is in c1 collection 3 times.
```

## <a name="emplace"></a><a name="emplace"></a>emplace

Insere um elemento construído no local em uma lista na posição especificada.

```cpp
void emplace(iterator Where, Type&& val);
```

### <a name="parameters"></a>parâmetros

*Posição*\
A posição na [lista](../standard-library/list-class.md) de destino em que o primeiro elemento é inserido.

*Val*\
O elemento adicionado ao final da `list`.

### <a name="remarks"></a>Comentários

Se uma exceção for gerada, a `list` permanecerá inalterada e a exceção será emitida novamente.

### <a name="example"></a>Exemplo

```cpp
// list_emplace.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   list <string> c2;
   string str("a");

   c2.emplace(c2.begin(), move( str ) );
   cout << "Moved first element: " << c2.back( ) << endl;
}
```

```Output
Moved first element: a
```

## <a name="emplace_back"></a><a name="emplace_back"></a>emplace_back

Adiciona um elemento construído no local ao final de uma lista.

```cpp
void emplace_back(Type&& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O elemento adicionado ao final da [lista](../standard-library/list-class.md).

### <a name="remarks"></a>Comentários

Se uma exceção for gerada, a `list` permanecerá inalterada e a exceção será emitida novamente.

### <a name="example"></a>Exemplo

```cpp
// list_emplace_back.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   list <string> c2;
   string str("a");

   c2.emplace_back( move( str ) );
   cout << "Moved first element: " << c2.back( ) << endl;
}
```

```Output
Moved first element: a
```

## <a name="emplace_front"></a><a name="emplace_front"></a>emplace_front

Adiciona um elemento construído no local ao início de uma lista.

```cpp
void emplace_front(Type&& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O elemento adicionado ao início da [lista](../standard-library/list-class.md).

### <a name="remarks"></a>Comentários

Se uma exceção for gerada, a `list` permanecerá inalterada e a exceção será emitida novamente.

### <a name="example"></a>Exemplo

```cpp
// list_emplace_front.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   list <string> c2;
   string str("a");

   c2.emplace_front( move( str ) );
   cout << "Moved first element: " << c2.front( ) << endl;
}
```

```Output
Moved first element: a
```

## <a name="empty"></a><a name="empty"></a>esvaziá

Testa se uma lista está vazia.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** se a lista estiver vazia; **`false`** se a lista não estiver vazia.

### <a name="example"></a>Exemplo

```cpp
// list_empty.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );
   if ( c1.empty( ) )
      cout << "The list is empty." << endl;
   else
      cout << "The list is not empty." << endl;
}
```

```Output
The list is not empty.
```

## <a name="end"></a><a name="end"></a>completo

Retorna um iterador que trata o local após o último elemento em uma lista.

```cpp
const_iterator end() const;
iterator end();
```

### <a name="return-value"></a>Valor retornado

Retorna um iterador bidirecional que trata o local após o último elemento em uma lista. Se a lista estiver vazia, então, `list::end == list::begin`.

### <a name="remarks"></a>Comentários

`end`é usado para testar se um iterador atingiu o final de sua lista.

### <a name="example"></a>Exemplo

```cpp
// list_end.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   c1_Iter = c1.end( );
   c1_Iter--;
   cout << "The last integer of c1 is " << *c1_Iter << endl;

   c1_Iter--;
*c1_Iter = 400;
   cout << "The new next-to-last integer of c1 is "
        << *c1_Iter << endl;

   // If a const iterator had been declared instead with the line:
   // list <int>::const_iterator c1_Iter;
   // an error would have resulted when inserting the 400

   cout << "The list is now:";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
}
```

```Output
The last integer of c1 is 30
The new next-to-last integer of c1 is 400
The list is now: 10 400 30
```

## <a name="erase"></a><a name="erase"></a>borracha

Remove um elemento ou um intervalo de elementos das posições especificadas.

```cpp
iterator erase(iterator Where);
iterator erase(iterator first, iterator last);
```

### <a name="parameters"></a>parâmetros

*Posição*\
Posição do elemento a ser removido da lista.

*primeiro*\
Posição do primeiro elemento removido da lista.

*última*\
Posição além do último elemento removido da lista.

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um ponteiro para o fim da lista se não houver tal elemento.

### <a name="remarks"></a>Comentários

Nenhuma realocação ocorre, por isso, referências e iteradores tornam-se inválidos somente para os elementos apagados.

`erase` nunca gera uma exceção.

### <a name="example"></a>Exemplo

```cpp
// list_erase.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator Iter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );
   c1.push_back( 40 );
   c1.push_back( 50 );
   cout << "The initial list is:";
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
      cout << " " << *Iter;
   cout << endl;

   c1.erase( c1.begin( ) );
   cout << "After erasing the first element, the list becomes:";
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
      cout << " " << *Iter;
   cout << endl;
   Iter = c1.begin( );
   Iter++;
   c1.erase( Iter, c1.end( ) );
   cout << "After erasing all elements but the first, the list becomes: ";
   for (Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
      cout << " " << *Iter;
   cout << endl;
}
```

```Output
The initial list is: 10 20 30 40 50
After erasing the first element, the list becomes: 20 30 40 50
After erasing all elements but the first, the list becomes:  20
```

## <a name="front"></a><a name="front"></a>dianteiro

Retorna uma referência ao primeiro elemento em uma lista.

```cpp
reference front();
const_reference front() const;
```

### <a name="return-value"></a>Valor retornado

Se a lista estiver vazia, o retorno será indefinido.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `front` for atribuído a `const_reference`, o objeto de lista não poderá ser modificado. Se o valor retornado de `front` for atribuído à `reference`, o objeto de lista poderá ser modificado.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento em uma lista vazia.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.

### <a name="example"></a>Exemplo

```cpp
// list_front.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main() {
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );

   int& i = c1.front();
   const int& ii = c1.front();

   cout << "The first integer of c1 is " << i << endl;
   i++;
   cout << "The first integer of c1 is " << ii << endl;
}
```

```Output
The first integer of c1 is 10
The first integer of c1 is 11
```

## <a name="get_allocator"></a><a name="get_allocator"></a>get_allocator

Retorna uma cópia do objeto alocador usado para construir uma lista.

```cpp
Allocator get_allocator() const;
```

### <a name="return-value"></a>Valor retornado

O alocador usado pela lista.

### <a name="remarks"></a>Comentários

Alocadores para a classe de lista especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>Exemplo

```cpp
// list_get_allocator.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   // The following lines declare objects
   // that use the default allocator.
   list <int> c1;
   list <int, allocator<int> > c2 = list <int, allocator<int> >( allocator<int>( ) );

   // c3 will use the same allocator class as c1
   list <int> c3( c1.get_allocator( ) );

   list<int>::allocator_type xlst = c1.get_allocator( );
   // You can now call functions on the allocator class used by c1
}
```

## <a name="insert"></a><a name="insert"></a>inserido

Insere um elemento ou um número de elementos ou um intervalo de elementos em uma lista, na posição especificada.

```cpp
iterator insert(iterator Where, const Type& Val);
iterator insert(iterator Where, Type&& Val);

void insert(iterator Where, size_type Count, const Type& Val);
iterator insert(iterator Where, initializer_list<Type> IList);

template <class InputIterator>
void insert(iterator Where, InputIterator First, InputIterator Last);
```

### <a name="parameters"></a>parâmetros

*Posição*\
A posição na lista de destino em que o primeiro elemento é inserido.

*Val*\
O valor do elemento sendo inserido na lista.

*Contar*\
O número de elementos sendo inseridos na lista.

*Primeiro*\
A posição do primeiro elemento no intervalo de elementos na lista de argumentos a ser copiada.

*Última*\
A posição do primeiro elemento além do intervalo de elementos na lista de argumentos a ser copiada.

### <a name="return-value"></a>Valor retornado

As duas primeiras funções de entrada retornam um iterador que aponta para a posição onde o novo elemento foi inserido na lista.

### <a name="example"></a>Exemplo

```cpp
// list_class_insert.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    list <int> c1, c2;
    list <int>::iterator Iter;

    c1.push_back(10);
    c1.push_back(20);
    c1.push_back(30);
    c2.push_back(40);
    c2.push_back(50);
    c2.push_back(60);

    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    Iter = c1.begin();
    Iter++;
    c1.insert(Iter, 100);
    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    Iter = c1.begin();
    Iter++;
    Iter++;
    c1.insert(Iter, 2, 200);

    cout << "c1 =";
    for(auto c : c1)
        cout << " " << c;
    cout << endl;

    c1.insert(++c1.begin(), c2.begin(), --c2.end());

    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    // initialize a list of strings by moving
    list < string > c3;
    string str("a");

    c3.insert(c3.begin(), move(str));
    cout << "Moved first element: " << c3.front() << endl;

    // Assign with an initializer_list
    list <int> c4{ {1, 2, 3, 4} };
    c4.insert(c4.begin(), { 5, 6, 7, 8 });

    cout << "c4 =";
    for (auto c : c4)
        cout << " " << c;
    cout << endl;
}
```

## <a name="iterator"></a><a name="iterator"></a>repeti

Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em uma lista.

```cpp
typedef implementation-defined iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `iterator` pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Consulte o exemplo de [begin](#begin).

## <a name="list"></a><a name="list"></a>lista

Constrói uma lista de um tamanho específico, ou com elementos de um valor específico, ou com um alocador específico, ou como uma cópia de toda ou parte de alguma outra lista.

```cpp
list();
explicit list(const Allocator& Al);
explicit list(size_type Count);
list(size_type Count, const Type& Val);
list(size_type Count, const Type& Val, const Allocator& Al);

list(const list& Right);
list(list&& Right);
list(initializer_list<Type> IList, const Allocator& Al);

template <class InputIterator>
list(InputIterator First, InputIterator Last);

template <class InputIterator>
list(InputIterator First, InputIterator Last, const Allocator& Al);
```

### <a name="parameters"></a>parâmetros

*&*\
A classe de alocador a ser usada com esse objeto.

*Contar*\
O número de elementos na lista construída.

*Val*\
O valor dos elementos na lista.

*Certo*\
A lista da qual a lista construída é uma cópia.

*Primeiro*\
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*Última*\
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

*IList*\
O initializer_list que contém os elementos a serem copiados.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto de alocador (*Al*) e inicializam a lista.

[get_allocator](#get_allocator) retorna uma cópia do objeto alocador usado para construir uma lista.

Os dois primeiros construtores especificam uma lista inicial vazia, a segunda especificando o tipo de alocador (*Al*) a ser usado.

O terceiro construtor Especifica uma repetição de um número especificado (*contagem*) de elementos do valor padrão para classe `Type` .

Os quarto e quinto construtores especificam uma repetição de elementos (*Count*) do valor *Val*.

O sexto Construtor especifica uma cópia da lista *à direita*.

O sétimo Construtor move a lista para a *direita*.

O oitavo construtor usa initializer_list para especificar os elementos.

Os dois construtores seguintes copiam o intervalo `[First, Last)` de uma lista.

Nenhum dos construtores executa realocações provisórias.

### <a name="example"></a>Exemplo

```cpp
// list_class_list.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main()
{
    using namespace std;
    // Create an empty list c0
    list <int> c0;

    // Create a list c1 with 3 elements of default value 0
    list <int> c1(3);

    // Create a list c2 with 5 elements of value 2
    list <int> c2(5, 2);

    // Create a list c3 with 3 elements of value 1 and with the
    // allocator of list c2
    list <int> c3(3, 1, c2.get_allocator());

    // Create a copy, list c4, of list c2
    list <int> c4(c2);

    // Create a list c5 by copying the range c4[ first,  last)
    list <int>::iterator c4_Iter = c4.begin();
    c4_Iter++;
    c4_Iter++;
    list <int> c5(c4.begin(), c4_Iter);

    // Create a list c6 by copying the range c4[ first,  last) and with
    // the allocator of list c2
    c4_Iter = c4.begin();
    c4_Iter++;
    c4_Iter++;
    c4_Iter++;
    list <int> c6(c4.begin(), c4_Iter, c2.get_allocator());

    cout << "c1 =";
    for (auto c : c1)
        cout << " " << c;
    cout << endl;

    cout << "c2 =";
    for (auto c : c2)
        cout << " " << c;
    cout << endl;

    cout << "c3 =";
    for (auto c : c3)
        cout << " " << c;
    cout << endl;

    cout << "c4 =";
    for (auto c : c4)
        cout << " " << c;
    cout << endl;

    cout << "c5 =";
    for (auto c : c5)
        cout << " " << c;
    cout << endl;

    cout << "c6 =";
    for (auto c : c6)
        cout << " " << c;
    cout << endl;

    // Move list c6 to list c7
    list <int> c7(move(c6));
    cout << "c7 =";
    for (auto c : c7)
        cout << " " << c;
    cout << endl;

    // Construct with initializer_list
    list<int> c8({ 1, 2, 3, 4 });
    cout << "c8 =";
    for (auto c : c8)
        cout << " " << c;
    cout << endl;
}
```

```Output
c1 = 0 0 0c2 = 2 2 2 2 2c3 = 1 1 1c4 = 2 2 2 2 2c5 = 2 2c6 = 2 2 2c7 = 2 2 2c8 = 1 2 3 4
```

## <a name="max_size"></a><a name="max_size"></a>max_size

Retorna o tamanho máximo de uma lista.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento máximo possível da lista.

### <a name="example"></a>Exemplo

```cpp
// list_max_size.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::size_type i;

   i = c1.max_size( );
   cout << "Maximum possible length of the list is " << i << "." << endl;
}
```

## <a name="merge"></a><a name="merge"></a>Mescle

Remove os elementos da lista de argumentos, insere-os na lista de destino e organiza o conjunto novo e combinado de elementos em ordem crescente ou em alguma outra ordem especificada.

```cpp
void merge(list<Type, Allocator>& right);

template <class Traits>
void merge(list<Type, Allocator>& right, Traits comp);
```

### <a name="parameters"></a>parâmetros

*Certo*\
A lista de argumentos a ser mesclada com a lista de destino.

*às*\
O operador de comparação usado para ordenar os elementos da lista de destino.

### <a name="remarks"></a>Comentários

A lista de argumentos *à direita* é mesclada com a lista de destino.

Listas de argumento e de destino devem ser solicitadas com a mesma relação de comparação pela qual a sequência resultante deve ser organizada. A ordem padrão para a primeira função de membro é ordem crescente. A segunda função de membro impõe a *composição* de operação de comparação especificada pelo usuário da classe `Traits` .

### <a name="example"></a>Exemplo

```cpp
// list_merge.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1, c2, c3;
   list <int>::iterator c1_Iter, c2_Iter, c3_Iter;

   c1.push_back( 3 );
   c1.push_back( 6 );
   c2.push_back( 2 );
   c2.push_back( 4 );
   c3.push_back( 5 );
   c3.push_back( 1 );

   cout << "c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   cout << "c2 =";
   for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )
      cout << " " << *c2_Iter;
   cout << endl;

   c2.merge( c1 );  // Merge c1 into c2 in (default) ascending order
   c2.sort( greater<int>( ) );
   cout << "After merging c1 with c2 and sorting with >: c2 =";
   for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )
      cout << " " << *c2_Iter;
   cout << endl;

   cout << "c3 =";
   for ( c3_Iter = c3.begin( ); c3_Iter != c3.end( ); c3_Iter++ )
      cout << " " << *c3_Iter;
   cout << endl;

   c2.merge( c3, greater<int>( ) );
   cout << "After merging c3 with c2 according to the '>' comparison relation: c2 =";
   for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )
      cout << " " << *c2_Iter;
   cout << endl;
}
```

```Output
c1 = 3 6
c2 = 2 4
After merging c1 with c2 and sorting with >: c2 = 6 4 3 2
c3 = 5 1
After merging c3 with c2 according to the '>' comparison relation: c2 = 6 5 4 3 2 1
```

## <a name="operator"></a><a name="op_eq"></a>operador =

Substitui os elementos da lista por uma cópia de outra lista.

```cpp
list& operator=(const list& right);
list& operator=(list&& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
A [lista](../standard-library/list-class.md) que está sendo copiada para o `list`.

### <a name="remarks"></a>Comentários

Depois de apagar todos os elementos existentes em um `list` , o operador copia ou move o conteúdo do *lado* para o `list` .

### <a name="example"></a>Exemplo

```cpp
// list_operator_as.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list<int> v1, v2, v3;
   list<int>::iterator iter;

   v1.push_back(10);
   v1.push_back(20);
   v1.push_back(30);
   v1.push_back(40);
   v1.push_back(50);

   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   v2 = v1;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;

// move v1 into v2
   v2.clear();
   v2 = forward< list<int> >(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;
}
```

## <a name="pointer"></a>Ponteiro <a name="pointer"></a>

Fornece um ponteiro para um elemento em uma lista.

```cpp
typedef typename Allocator::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo `pointer` pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto de lista.

## <a name="pop_back"></a><a name="pop_back"></a>pop_back

Exclui o elemento no final de uma lista.

```cpp
void pop_back();
```

### <a name="remarks"></a>Comentários

O último elemento não deve estar vazio. `pop_back` nunca gera uma exceção.

### <a name="example"></a>Exemplo

```cpp
// list_pop_back.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 1 );
   c1.push_back( 2 );
   cout << "The first element is: " << c1.front( ) << endl;
   cout << "The last element is: " << c1.back( ) << endl;

   c1.pop_back( );
   cout << "After deleting the element at the end of the list, "
           "the last element is: " << c1.back( ) << endl;
}
```

```Output
The first element is: 1
The last element is: 2
After deleting the element at the end of the list, the last element is: 1
```

## <a name="pop_front"></a><a name="pop_front"></a>pop_front

Exclui o elemento no começo de uma lista.

```cpp
void pop_front();
```

### <a name="remarks"></a>Comentários

O primeiro elemento não deve estar vazio. `pop_front` nunca gera uma exceção.

### <a name="example"></a>Exemplo

```cpp
// list_pop_front.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 1 );
   c1.push_back( 2 );
   cout << "The first element is: " << c1.front( ) << endl;
   cout << "The second element is: " << c1.back( ) << endl;

   c1.pop_front( );
   cout << "After deleting the element at the beginning of the list, "
         "the first element is: " << c1.front( ) << endl;
}
```

```Output
The first element is: 1
The second element is: 2
After deleting the element at the beginning of the list, the first element is: 2
```

## <a name="push_back"></a><a name="push_back"></a>push_back

Adiciona um elemento ao fim da lista.

```cpp
void push_back(const Type& val);
void push_back(Type&& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O elemento adicionado ao final da lista.

### <a name="remarks"></a>Comentários

Se uma exceção for gerada, a lista permanecerá inalterada e a exceção será gerada novamente.

### <a name="example"></a>Exemplo

```cpp
// list_push_back.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 1 );
   if ( c1.size( ) != 0 )
      cout << "Last element: " << c1.back( ) << endl;

   c1.push_back( 2 );
   if ( c1.size( ) != 0 )
      cout << "New last element: " << c1.back( ) << endl;

// move initialize a list of strings
   list <string> c2;
   string str("a");

   c2.push_back( move( str ) );
   cout << "Moved first element: " << c2.back( ) << endl;
}
```

```Output
Last element: 1
New last element: 2
Moved first element: a
```

## <a name="push_front"></a><a name="push_front"></a>push_front

Adiciona um elemento ao começo da lista.

```cpp
void push_front(const Type& val);
void push_front(Type&& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O elemento adicionado ao início da lista.

### <a name="remarks"></a>Comentários

Se uma exceção for gerada, a lista permanecerá inalterada e a exceção será gerada novamente.

### <a name="example"></a>Exemplo

```cpp
// list_push_front.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_front( 1 );
   if ( c1.size( ) != 0 )
      cout << "First element: " << c1.front( ) << endl;

   c1.push_front( 2 );
   if ( c1.size( ) != 0 )
      cout << "New first element: " << c1.front( ) << endl;

// move initialize a list of strings
   list <string> c2;
   string str("a");

   c2.push_front( move( str ) );
   cout << "Moved first element: " << c2.front( ) << endl;
}
```

```Output
First element: 1
New first element: 2
Moved first element: a
```

## <a name="rbegin"></a><a name="rbegin"></a>rbegin

Retorna um iterador que aborda o primeiro elemento em uma lista invertida.

```cpp
const_reverse_iterator rbegin() const;
reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional invertido que aborda o primeiro elemento em uma lista invertida (ou que aborda o último elemento na lista não invertida).

### <a name="remarks"></a>Comentários

`rbegin` é usado com uma lista invertida assim como [begin](#begin) é usado com uma lista.

Se o valor de retorno de `rbegin` for atribuído a `const_reverse_iterator`, o objeto de lista não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído à `reverse_iterator`, o objeto de lista poderá ser modificado.

`rbegin` pode ser usado para iterar através de uma lista para trás.

### <a name="example"></a>Exemplo

```cpp
// list_rbegin.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;
   list <int>::reverse_iterator c1_rIter;

   // If the following line replaced the line above, *c1_rIter = 40;
   // (below) would be an error
   //list <int>::const_reverse_iterator c1_rIter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );
   c1_rIter = c1.rbegin( );
   cout << "The last element in the list is " << *c1_rIter << "." << endl;

   cout << "The list is:";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   // rbegin can be used to start an iteration through a list in
   // reverse order
   cout << "The reversed list is:";
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )
      cout << " " << *c1_rIter;
   cout << endl;

   c1_rIter = c1.rbegin( );
*c1_rIter = 40;
   cout << "The last element in the list is now " << *c1_rIter << "." << endl;
}
```

```Output
The last element in the list is 30.
The list is: 10 20 30
The reversed list is: 30 20 10
The last element in the list is now 40.
```

## <a name="reference"></a><a name="reference"></a>referência

Um tipo que fornece uma referência a um elemento armazenado em uma lista.

```cpp
typedef typename Allocator::reference reference;
```

### <a name="example"></a>Exemplo

```cpp
// list_ref.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );
   c1.push_back( 20 );

   int &i = c1.front( );
   int &j = c1.back( );
   cout << "The first element is " << i << endl;
   cout << "The second element is " << j << endl;
}
```

```Output
The first element is 10
The second element is 20
```

## <a name="remove"></a><a name="remove"></a>exclu

Apaga elementos em uma lista que correspondem a um valor especificado.

```cpp
void remove(const Type& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O valor que, se mantido por um elemento, resultará na remoção de tal elemento da lista.

### <a name="remarks"></a>Comentários

A ordem dos elementos restantes não é afetada.

### <a name="example"></a>Exemplo

```cpp
// list_remove.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter, c2_Iter;

   c1.push_back( 5 );
   c1.push_back( 100 );
   c1.push_back( 5 );
   c1.push_back( 200 );
   c1.push_back( 5 );
   c1.push_back( 300 );

   cout << "The initial list is c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   list <int> c2 = c1;
   c2.remove( 5 );
   cout << "After removing elements with value 5, the list becomes c2 =";
   for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )
      cout << " " << *c2_Iter;
   cout << endl;
}
```

```Output
The initial list is c1 = 5 100 5 200 5 300
After removing elements with value 5, the list becomes c2 = 100 200 300
```

## <a name="remove_if"></a><a name="remove_if"></a>remove_if

Apaga os elementos da lista para a qual um predicado especificado foi atendido.

```cpp
template <class Predicate>
void remove_if(Predicate pred)
```

### <a name="parameters"></a>parâmetros

*Pred*\
O predicado unário que, se atendido por um elemento, resultará na exclusão de tal elemento da lista.

### <a name="example"></a>Exemplo

```cpp
// list_remove_if.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

template <class T> class is_odd : public std::unary_function<T, bool>
{
public:
   bool operator( ) ( T& val )
   {
   return ( val % 2 ) == 1;
   }
};

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter, c2_Iter;

   c1.push_back( 3 );
   c1.push_back( 4 );
   c1.push_back( 5 );
   c1.push_back( 6 );
   c1.push_back( 7 );
   c1.push_back( 8 );

   cout << "The initial list is c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   list <int> c2 = c1;
   c2.remove_if( is_odd<int>( ) );

   cout << "After removing the odd elements, "
        << "the list becomes c2 =";
   for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )
      cout << " " << *c2_Iter;
   cout << endl;
}
```

```Output
The initial list is c1 = 3 4 5 6 7 8
After removing the odd elements, the list becomes c2 = 4 6 8
```

## <a name="rend"></a><a name="rend"></a>rend

Retorna um iterador que aborda o local após o último elemento em uma lista invertida.

```cpp
const_reverse_iterator rend() const;
reverse_iterator rend();
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional inverso que aborda a localização que vem após o último elemento em uma lista invertida (o local que precedeu o primeiro elemento na lista não invertida).

### <a name="remarks"></a>Comentários

`rend` é usado com uma lista invertida, assim como [end](#end) é usado com uma lista.

Se o valor de retorno de `rend` for atribuído a `const_reverse_iterator`, o objeto de lista não poderá ser modificado. Se o valor retornado de `rend` for atribuído à `reverse_iterator`, o objeto de lista poderá ser modificado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de sua lista.

O valor retornado por `rend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// list_rend.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;
   list <int>::reverse_iterator c1_rIter;

   // If the following line had replaced the line above, an error would
   // have resulted in the line modifying an element (commented below)
   // because the iterator would have been const
   // list <int>::const_reverse_iterator c1_rIter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   c1_rIter = c1.rend( );
   c1_rIter --;  // Decrementing a reverse iterator moves it forward in
                 // the list (to point to the first element here)
   cout << "The first element in the list is: " << *c1_rIter << endl;

   cout << "The list is:";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   // rend can be used to test if an iteration is through all of the
   // elements of a reversed list
   cout << "The reversed list is:";
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )
      cout << " " << *c1_rIter;
   cout << endl;

   c1_rIter = c1.rend( );
   c1_rIter--;  // Decrementing the reverse iterator moves it backward
                // in the reversed list (to the last element here)

*c1_rIter = 40;  // This modification of the last element would have
                    // caused an error if a const_reverse iterator had
                    // been declared (as noted above)

   cout << "The modified reversed list is:";
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )
      cout << " " << *c1_rIter;
   cout << endl;
}
```

```Output
The first element in the list is: 10
The list is: 10 20 30
The reversed list is: 30 20 10
The modified reversed list is: 30 20 40
```

## <a name="resize"></a><a name="resize"></a>alonga

Especifica um novo tamanho para uma lista.

```cpp
void resize(size_type _Newsize);
void resize(size_type _Newsize, Type val);
```

### <a name="parameters"></a>parâmetros

*_Newsize*\
O novo tamanho da lista.

*Val*\
O valor dos novos elementos a serem adicionados à lista, caso o novo tamanho seja maior que o tamanho original. Se o valor for omitido, os novos elementos receberão o valor padrão para a classe.

### <a name="remarks"></a>Comentários

Se o tamanho da lista for menor que o tamanho solicitado, *_Newsize*, os elementos serão adicionados à lista até atingir o tamanho solicitado.

Se o tamanho da lista for maior que o tamanho solicitado, os elementos mais próximos ao final da lista serão excluídos até que a lista atinja o tamanho *_Newsize*.

Se o tamanho atual da lista for igual ao tamanho solicitado, nenhuma ação será realizada.

[size](#size) reflete o tamanho atual da lista.

### <a name="example"></a>Exemplo

```cpp
// list_resize.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   c1.resize( 4,40 );
   cout << "The size of c1 is " << c1.size( ) << endl;
   cout << "The value of the last element is " << c1.back( ) << endl;

   c1.resize( 5 );
   cout << "The size of c1 is now " << c1.size( ) << endl;
   cout << "The value of the last element is now " << c1.back( ) << endl;

   c1.resize( 2 );
   cout << "The reduced size of c1 is: " << c1.size( ) << endl;
   cout << "The value of the last element is now " << c1.back( ) << endl;
}
```

```Output
The size of c1 is 4
The value of the last element is 40
The size of c1 is now 5
The value of the last element is now 0
The reduced size of c1 is: 2
The value of the last element is now 20
```

## <a name="reverse"></a><a name="reverse"></a>ordem

Reverte a ordem na qual os elementos ocorrem em uma lista.

```cpp
void reverse();
```

### <a name="example"></a>Exemplo

```cpp
// list_reverse.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;

   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   cout << "c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   c1.reverse( );
   cout << "Reversed c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;
}
```

```Output
c1 = 10 20 30
Reversed c1 = 30 20 10
```

## <a name="reverse_iterator"></a><a name="reverse_iterator"></a>reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em uma lista invertida.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `reverse_iterator` é usado para iterar a lista em ordem inversa.

### <a name="example"></a>Exemplo

Consulte o exemplo de [rbegin](#rbegin).

## <a name="size"></a><a name="size"></a>tamanho

Retorna o número de elementos em uma lista.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento atual da lista.

### <a name="example"></a>Exemplo

```cpp
// list_size.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::size_type i;

   c1.push_back( 5 );
   i = c1.size( );
   cout << "List length is " << i << "." << endl;

   c1.push_back( 7 );
   i = c1.size( );
   cout << "List length is now " << i << "." << endl;
}
```

```Output
List length is 1.
List length is now 2.
```

## <a name="size_type"></a><a name="size_type"></a>size_type

Um tipo que conta o número de elementos em uma lista.

```cpp
typedef typename Allocator::size_type size_type;
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [size](#size).

## <a name="sort"></a><a name="sort"></a>organizar

Organiza os elementos de uma lista em ordem crescente ou com respeito a alguma outra ordem especificada pelo usuário.

```cpp
void sort();

template <class Traits>
    void sort(Traits comp);
```

### <a name="parameters"></a>parâmetros

*às*\
O operador de comparação usado para ordenar elementos sucessivos.

### <a name="remarks"></a>Comentários

A primeira função de membro coloca os elementos em ordem crescente por padrão.

A função de modelo de membro ordena os elementos de acordo com a *composição* de operação de comparação especificada pelo usuário da classe `Traits` .

### <a name="example"></a>Exemplo

```cpp
// list_sort.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter;

   c1.push_back( 20 );
   c1.push_back( 10 );
   c1.push_back( 30 );

   cout << "Before sorting: c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   c1.sort( );
   cout << "After sorting c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   c1.sort( greater<int>( ) );
   cout << "After sorting with 'greater than' operation, c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;
}
```

```Output
Before sorting: c1 = 20 10 30
After sorting c1 = 10 20 30
After sorting with 'greater than' operation, c1 = 30 20 10
```

## <a name="splice"></a><a name="splice"></a>junção

Remove elementos de uma lista de origem e os insere em uma lista de destino.

```cpp
// insert the entire source list
void splice(const_iterator Where, list<Type, Allocator>& Source);
void splice(const_iterator Where, list<Type, Allocator>&& Source);

// insert one element of the source list
void splice(const_iterator Where, list<Type, Allocator>& Source, const_iterator Iter);
void splice(const_iterator Where, list<Type, Allocator>&& Source, const_iterator Iter);

// insert a range of elements from the source list
void splice(const_iterator Where, list<Type, Allocator>& Source, const_iterator First, const_iterator Last);
void splice(const_iterator Where, list<Type, Allocator>&& Source, const_iterator First, const_iterator Last);
```

### <a name="parameters"></a>parâmetros

*Posição*\
A posição na lista de destino antes da inserção.

*Original*\
A lista de origem a ser inserida na lista de destino.

*Iter*\
O elemento a ser inserido da lista de origem.

*Primeiro*\
O primeiro elemento no intervalo a ser inserido da lista de origem.

*Última*\
A primeira posição além do último elemento no intervalo a ser inserido da lista de origem.

### <a name="remarks"></a>Comentários

O primeiro par de funções de membro insere todos os elementos na lista de origem na lista de destino antes da posição referenciada por *onde* e remove todos os elementos da lista de origem. ( `&Source` não deve ser igual a **`this`** .)

O segundo par de funções de membro insere o elemento referido por *ITER* antes da posição na lista de destino referenciada por *onde* e remove *ITER* da lista de origem. (Se `Where == Iter || Where == ++Iter`, nenhuma alteração ocorrerá.)

O terceiro par de funções de membro insere o intervalo designado por [ `First` , `Last` ) antes do elemento na lista de destino referenciado por *onde* e remove esse intervalo de elementos da lista de origem. (Se `&Source == this` , o intervalo `[First, Last)` não deve incluir o elemento apontado por *Where*.)

Se a união no intervalo inserir elementos `N` e `&Source != this`, um objeto da classe [iterator](../standard-library/forward-list-class.md#iterator) será incrementado `N` vezes.

Em todos os iteradores de casos, ponteiros ou referências a elementos de união permanecem válidos e são transferidos para o contêiner de destino.

### <a name="example"></a>Exemplo

```cpp
// list_splice.cpp
// compile with: /EHsc /W4
#include <list>
#include <iostream>

using namespace std;

template <typename S> void print(const S& s) {
    cout << s.size() << " elements: ";

    for (const auto& p : s) {
        cout << "(" << p << ") ";
    }

    cout << endl;
}

int main()
{
    list<int> c1{10,11};
    list<int> c2{20,21,22};
    list<int> c3{30,31};
    list<int> c4{40,41,42,43};

    list<int>::iterator where_iter;
    list<int>::iterator first_iter;
    list<int>::iterator last_iter;

    cout << "Beginning state of lists:" << endl;
    cout << "c1 = ";
    print(c1);
    cout << "c2 = ";
    print(c2);
    cout << "c3 = ";
    print(c3);
    cout << "c4 = ";
    print(c4);

    where_iter = c2.begin();
    ++where_iter; // start at second element
    c2.splice(where_iter, c1);
    cout << "After splicing c1 into c2:" << endl;
    cout << "c1 = ";
    print(c1);
    cout << "c2 = ";
    print(c2);

    first_iter = c3.begin();
    c2.splice(where_iter, c3, first_iter);
    cout << "After splicing the first element of c3 into c2:" << endl;
    cout << "c3 = ";
    print(c3);
    cout << "c2 = ";
    print(c2);

    first_iter = c4.begin();
    last_iter = c4.end();
    // set up to get the middle elements
    ++first_iter;
    --last_iter;
    c2.splice(where_iter, c4, first_iter, last_iter);
    cout << "After splicing a range of c4 into c2:" << endl;
    cout << "c4 = ";
    print(c4);
    cout << "c2 = ";
    print(c2);
}
```

```Output
Beginning state of lists:c1 = 2 elements: (10) (11)c2 = 3 elements: (20) (21) (22)c3 = 2 elements: (30) (31)c4 = 4 elements: (40) (41) (42) (43)After splicing c1 into c2:c1 = 0 elements:c2 = 5 elements: (20) (10) (11) (21) (22)After splicing the first element of c3 into c2:c3 = 1 elements: (31)c2 = 6 elements: (20) (10) (11) (30) (21) (22)After splicing a range of c4 into c2:c4 = 2 elements: (40) (43)c2 = 8 elements: (20) (10) (11) (30) (41) (42) (21) (22)
```

## <a name="swap"></a><a name="swap"></a>permuta

Troca os elementos das duas listas.

```cpp
void swap(list<Type, Allocator>& right);
friend void swap(list<Type, Allocator>& left, list<Type, Allocator>& right)
```

### <a name="parameters"></a>parâmetros

*Certo*\
A lista que fornece os elementos a serem alternados ou a lista cujos elementos devem ser trocados com os da lista *à esquerda*.

*mantida*\
Uma lista cujos elementos devem ser trocados por aqueles da lista *à direita*.

### <a name="example"></a>Exemplo

```cpp
// list_swap.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1, c2, c3;
   list <int>::iterator c1_Iter;

   c1.push_back( 1 );
   c1.push_back( 2 );
   c1.push_back( 3 );
   c2.push_back( 10 );
   c2.push_back( 20 );
   c3.push_back( 100 );

   cout << "The original list c1 is:";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   c1.swap( c2 );

   cout << "After swapping with c2, list c1 is:";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   swap( c1,c3 );

   cout << "After swapping with c3, list c1 is:";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;
}
```

```Output
The original list c1 is: 1 2 3
After swapping with c2, list c1 is: 10 20
After swapping with c3, list c1 is: 100
```

## <a name="unique"></a><a name="unique"></a>diferente

Remove elementos duplicados adjacentes ou elementos adjacentes que satisfazem algum predicado binário da lista.

```cpp
void unique();

template <class BinaryPredicate>
void unique(BinaryPredicate pred);
```

### <a name="parameters"></a>parâmetros

*Pred*\
O predicado binário usado para comparar elementos sucessivos.

### <a name="remarks"></a>Comentários

Essa função pressupõe que a lista é classificada, para que todos os elementos duplicados sejam adjacentes. Duplicatas que não sejam adjacentes não serão excluídas.

A primeira função de membro remove todos os elementos que compara igual ao seu elemento anterior.

A segunda função de membro remove todos os elementos que satisfaçam a função de predicado *Pred* quando comparados com seu elemento anterior. Você pode usar qualquer um dos objetos de função binária declarados no \<functional> cabeçalho para o argumento *Pred* ou você pode criar o seu próprio.

### <a name="example"></a>Exemplo

```cpp
// list_unique.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list <int> c1;
   list <int>::iterator c1_Iter, c2_Iter,c3_Iter;
   not_equal_to<int> mypred;

   c1.push_back( -10 );
   c1.push_back( 10 );
   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 20 );
   c1.push_back( -10 );

   cout << "The initial list is c1 =";
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )
      cout << " " << *c1_Iter;
   cout << endl;

   list <int> c2 = c1;
   c2.unique( );
   cout << "After removing successive duplicate elements, c2 =";
   for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )
      cout << " " << *c2_Iter;
   cout << endl;

   list <int> c3 = c2;
   c3.unique( mypred );
   cout << "After removing successive unequal elements, c3 =";
   for ( c3_Iter = c3.begin( ); c3_Iter != c3.end( ); c3_Iter++ )
      cout << " " << *c3_Iter;
   cout << endl;
}
```

```Output
The initial list is c1 = -10 10 10 20 20 -10
After removing successive duplicate elements, c2 = -10 10 20 -10
After removing successive unequal elements, c3 = -10 -10
```

## <a name="value_type"></a><a name="value_type"></a>value_type

Um tipo que representa o tipo de dados armazenado em uma lista.

```cpp
typedef typename Allocator::value_type value_type;
```

### <a name="remarks"></a>Comentários

`value_type` é um sinônimo do parâmetro de modelo *Type*.

### <a name="example"></a>Exemplo

```cpp
// list_value_type.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   list<int>::value_type AnInt;
   AnInt = 44;
   cout << AnInt << endl;
}
```

```Output
44
```
