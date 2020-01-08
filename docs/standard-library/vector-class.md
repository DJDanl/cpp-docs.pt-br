---
title: Classe vector
ms.date: 01/04/2020
f1_keywords:
- vector/std::vector::allocator_type
- vector/std::vector::const_iterator
- vector/std::vector::const_pointer
- vector/std::vector::const_reference
- vector/std::vector::const_reverse_iterator
- vector/std::vector::difference_type
- vector/std::vector::iterator
- vector/std::vector::pointer
- vector/std::vector::reference
- vector/std::vector::reverse_iterator
- vector/std::vector::size_type
- vector/std::vector::value_type
- vector/std::vector::assign
- vector/std::vector::at
- vector/std::vector::back
- vector/std::vector::begin
- vector/std::vector::capacity
- vector/std::vector::cbegin
- vector/std::vector::cend
- vector/std::vector::crbegin
- vector/std::vector::crend
- vector/std::vector::clear
- vector/std::vector::data
- vector/std::vector::emplace
- vector/std::vector::emplace_back
- vector/std::vector::empty
- vector/std::vector::end
- vector/std::vector::erase
- vector/std::vector::front
- vector/std::vector::get_allocator
- vector/std::vector::insert
- vector/std::vector::max_size
- vector/std::vector::pop_back
- vector/std::vector::push_back
- vector/std::vector::rbegin
- vector/std::vector::rend
- vector/std::vector::reserve
- vector/std::vector::resize
- vector/std::vector::shrink_to_fit
- vector/std::vector::size
- vector/std::vector::swap
helpviewer_keywords:
- std::vector [C++], allocator_type
- std::vector [C++], const_iterator
- std::vector [C++], const_pointer
- std::vector [C++], const_reference
- std::vector [C++], const_reverse_iterator
- std::vector [C++], difference_type
- std::vector [C++], iterator
- std::vector [C++], pointer
- std::vector [C++], reference
- std::vector [C++], reverse_iterator
- std::vector [C++], size_type
- std::vector [C++], value_type
- std::vector [C++], assign
- std::vector [C++], at
- std::vector [C++], back
- std::vector [C++], begin
- std::vector [C++], capacity
- std::vector [C++], cbegin
- std::vector [C++], cend
- std::vector [C++], crbegin
- std::vector [C++], crend
- std::vector [C++], clear
- std::vector [C++], data
- std::vector [C++], emplace
- std::vector [C++], emplace_back
- std::vector [C++], empty
- std::vector [C++], end
- std::vector [C++], erase
- std::vector [C++], front
- std::vector [C++], get_allocator
- std::vector [C++], insert
- std::vector [C++], max_size
- std::vector [C++], pop_back
- std::vector [C++], push_back
- std::vector [C++], rbegin
- std::vector [C++], rend
- std::vector [C++], reserve
- std::vector [C++], resize
- std::vector [C++], shrink_to_fit
- std::vector [C++], size
- std::vector [C++], swap
ms.assetid: a3e0a8f8-7565-4fe0-93e4-e4d74ae1b70d
ms.openlocfilehash: 8c4284fecf09044ceab326d858d6ffccccdeaf45
ms.sourcegitcommit: 27d9db019f6d84c94de9e6aff0170d918cee6738
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/06/2020
ms.locfileid: "75676958"
---
# <a name="vector-class"></a>Classe vector

A C++ classe de vetor de biblioteca padrão é um modelo de classe para contêineres de sequência. Um vetor armazena elementos de um determinado tipo em uma organização linear e permite acesso aleatório rápido a qualquer elemento. Um vetor é o contêiner preferido para uma sequência quando o desempenho de acesso aleatório está em um nível Premium.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type, class Allocator = allocator<Type>>
class vector
```

### <a name="parameters"></a>Parâmetros

*Tipo*\
O tipo de dados do elemento a ser armazenado no vetor

\ de *alocador*
O tipo que representa o objeto allocator armazenado que encapsula detalhes sobre a alocação e a desalocação de memória do vetor. Esse argumento é opcional e o valor padrão é `allocator<Type>`.

## <a name="remarks"></a>Comentários

Os vetores permitem inserções e exclusões em tempo constante no final da sequência. Inserir ou excluir elementos no meio de um vetor exige tempo linear. O contêiner da [classe deque](../standard-library/deque-class.md) é mais rápido em inserções e exclusões no início e no final de uma sequência. O contêiner de [classe de lista](../standard-library/list-class.md) é mais rápido em inserções e exclusões em qualquer local dentro de uma sequência.

A realocação do vetor ocorre quando uma função membro deve aumentar a sequência contida no objeto vector além da sua capacidade de armazenamento atual. Outras inserções e exclusões podem alterar vários endereços de armazenamento na sequência. Em todos esses casos, iteradores ou referências que apontam para partes alteradas da sequência tornam-se inválidos. Se nenhuma realocação ocorrer, somente os iteradores e as referências antes do ponto de inserção/exclusão permanecerão válidos.

O [vetor\<bool > classe](../standard-library/vector-bool-class.md) é uma especialização completa do vetor de modelo de classe para elementos do tipo `bool`. Ele tem um alocador para o tipo subjacente usado pela especialização.

O [vetor\<bool > classe de referência](../standard-library/vector-bool-class.md#reference_class) é uma classe aninhada cujos objetos podem fornecer referências a elementos (bits únicos) dentro de um vetor\<objeto de > bool.

## <a name="members"></a>Membros

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

|||
|-|-|
|[vector](#vector)|Constrói um vetor de tamanho específico com elementos de um valor específico, com um `allocator` específico ou como uma cópia de algum outro vetor.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` do objeto vector.|
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler um elemento **const** em um vetor.|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento **const** em um vetor.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência a um elemento **const** armazenado em um vetor. Ele é usado para ler e executar operações **const** .|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento **const** no vetor.|
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre os endereços de dois elementos em um vetor.|
|[iterator](#iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento em um vetor.|
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em um vetor.|
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor invertido.|
|[size_type](#size_type)|Um tipo que conta o número de elementos em um vetor.|
|[value_type](#value_type)|Um tipo que representa o tipo de dados armazenado em um vetor.|

### <a name="functions"></a>{1&gt;Funções&lt;1}

|||
|-|-|
|[assign](#assign)|Apaga um vetor e copia os elementos especificados para o vetor vazio.|
|[at](#at)|Retorna uma referência ao elemento em um local especificado no vetor.|
|[back](#back)|Retorna uma referência ao último elemento do vetor.|
|[begin](#begin)|Retorna um iterador de acesso aleatório para o primeiro elemento no vetor.|
|[capacity](#capacity)|Retorna o número de elementos que o vetor pode conter sem alocar mais armazenamento.|
|[cbegin](#cbegin)|Retorna um iterador de acesso aleatório const para o primeiro elemento no vetor.|
|[cend](#cend)|Retorna um iterador de acesso aleatório const que aponta para imediatamente após o fim do vetor.|
|[crbegin](#crbegin)|Retorna um iterador const para o primeiro elemento em um vetor invertido.|
|[crend](#crend)|Retorna um iterador const para o final de um vetor invertido.|
|[clear](#clear)|Apaga os elementos do vetor.|
|[data](#data)|Retorna um ponteiro para o primeiro elemento no vetor.|
|[emplace](#emplace)|Insere um elemento construído no local no vetor em uma posição especificada.|
|[emplace_back](#emplace_back)|Adiciona um elemento construído no local ao final do vetor.|
|[empty](#empty)|Testa se o contêiner do vetor está vazio.|
|[end](#end)|Retorna um iterador de acesso aleatório que aponta para o final do vetor.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um vetor das posições especificadas.|
|[front](#front)|Retorna uma referência ao primeiro elemento em um vetor.|
|[get_allocator](#get_allocator)|Retorna um objeto para a classe `allocator` usada por um vetor.|
|[insert](#insert)|Insere um elemento ou uma série de elementos no vetor em uma posição especificada.|
|[max_size](#max_size)|Retorna o tamanho máximo do vetor.|
|[pop_back](#pop_back)|Exclui o elemento no final do vetor.|
|[push_back](#push_back)|Adiciona um elemento ao final do vetor.|
|[rbegin](#rbegin)|Retorna um iterador para o primeiro elemento em um vetor invertido.|
|[rend](#rend)|Retorna um iterador para o final de um vetor invertido.|
|[reserve](#reserve)|Reserva um tamanho mínimo de armazenamento para um objeto vector.|
|[resize](#resize)|Especifica um novo tamanho para um vetor.|
|[shrink_to_fit](#shrink_to_fit)|Descarta o excesso de capacidade.|
|[size](#size)|Retorna o número de elementos no vetor.|
|[swap](#swap)|Troca os elementos de dois vetores.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator&#91;&#93;](#op_at)|Retorna uma referência para o elemento de vetor em uma posição especificada.|
|[operator=](#op_eq)|Substitui os elementos do vetor por uma cópia de outro vetor.|

## <a name="allocator_type"></a>allocator_type

Um tipo que representa a classe allocator do objeto vector.

```cpp
typedef Allocator allocator_type;
```

### <a name="remarks"></a>Comentários

`allocator_type` é um sinônimo do parâmetro de modelo `Allocator`.

### <a name="example"></a>Exemplo

Veja o exemplo de [get_allocator](#get_allocator) para obter um exemplo que usa `allocator_type`.

## <a name="assign"></a>Cancele

Apaga um vetor e copia os elementos especificados para o vetor vazio.

```cpp
void assign(size_type count, const Type& value);
void assign(initializer_list<Type> init_list);

template <class InputIterator>
void assign(InputIterator first, InputIterator last);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
A posição do primeiro elemento no intervalo de elementos a ser copiado.

*última*\
A posição do primeiro elemento após o intervalo de elementos a ser copiado.

*contagem*\
O número de cópias de um elemento sendo inserido no vetor.

*value*\
O valor do elemento sendo inserido no vetor.

*init_list*\
A initializer_list que contém os elementos a serem inseridos.

### <a name="remarks"></a>Comentários

Primeiro, `assign` apaga todos os elementos existentes em um vetor. Em seguida, o `assign` insere um intervalo especificado de elementos do vetor original em um vetor ou insere cópias de um novo elemento de valor especificado em um vetor.

### <a name="example"></a>Exemplo

```cpp
/ vector_assign.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2, v3;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 = ";
    for (auto& v : v1){
        cout << v << " ";
    }
    cout << endl;

    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (auto& v : v2){
        cout << v << " ";
    }
    cout << endl;

    v3.assign(7, 4);
    cout << "v3 = ";
    for (auto& v : v3){
        cout << v << " ";
    }
    cout << endl;

    v3.assign({ 5, 6, 7 });
    for (auto& v : v3){
        cout << v << " ";
    }
    cout << endl;
}
```

## <a name="at"></a>no

Retorna uma referência ao elemento em um local especificado no vetor.

```cpp
reference at(size_type position);

const_reference at(size_type position) const;
```

### <a name="parameters"></a>Parâmetros

\ de *posição*
O número da posição ou subscrito do elemento para referência no vetor.

### <a name="return-value"></a>Valor de retorno

Uma referência ao elemento subscrito no argumento. Se *Position* for maior que o tamanho do vetor, `at` lançará uma exceção.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `at` for atribuído a um `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `at` for atribuído a `reference`, o objeto vector poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// vector_at.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 20 );

   const int &i = v1.at( 0 );
   int &j = v1.at( 1 );
   cout << "The first element is " << i << endl;
   cout << "The second element is " << j << endl;
}
```

```Output
The first element is 10
The second element is 20
```

## <a name="back"></a>Voltar

Retorna uma referência ao último elemento do vetor.

```cpp
reference back();

const_reference back() const;
```

### <a name="return-value"></a>Valor de retorno

O último elemento do vetor. Se o vetor estiver vazio, o valor retornado será indefinido.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `back` for atribuído a um `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `back` for atribuído a `reference`, o objeto vector poderá ser modificado.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento em um vetor vazio. Para obter mais informações, consulte [iteradores marcados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// vector_back.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main() {
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 11 );

   int& i = v1.back( );
   const int& ii = v1.front( );

   cout << "The last integer of v1 is " << i << endl;
   i--;
   cout << "The next-to-last integer of v1 is "<< ii << endl;
}
```

## <a name="begin"></a>Comece

Retorna um iterador de acesso aleatório para o primeiro elemento no vetor.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório que endereça o primeiro elemento em `vector` ou ao local que vem após um `vector` vazio. Sempre Compare o valor retornado com [vector:: End](#end) para garantir que ele seja válido.

### <a name="remarks"></a>Comentários

Se o valor retornado de `begin` for atribuído a um [vetor:: const_iterator](#const_iterator), o objeto `vector` não poderá ser modificado. Se o valor retornado de `begin` for atribuído a [vector::iterator](#iterator), o objeto `vector` poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// vector_begin.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> c1;
    vector<int>::iterator c1_Iter;
    vector<int>::const_iterator c1_cIter;

    c1.push_back(1);
    c1.push_back(2);

    cout << "The vector c1 contains elements:";
    c1_Iter = c1.begin();
    for (; c1_Iter != c1.end(); c1_Iter++)
    {
        cout << " " << *c1_Iter;
    }
    cout << endl;

    cout << "The vector c1 now contains elements:";
    c1_Iter = c1.begin();
    *c1_Iter = 20;
    for (; c1_Iter != c1.end(); c1_Iter++)
    {
        cout << " " << *c1_Iter;
    }
    cout << endl;

    // The following line would be an error because iterator is const
    // *c1_cIter = 200;
}
```

```Output
The vector c1 contains elements: 1 2
The vector c1 now contains elements: 20 2
```

## <a name="capacity"></a>recurso

Retorna o número de elementos que o vetor pode conter sem alocar mais armazenamento.

```cpp
size_type capacity() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho atual do armazenamento alocado para o vetor.

### <a name="remarks"></a>Comentários

A função membro [resize](#resize) será mais eficiente se houver alocação de memória suficiente para acomodá-la. Use a função membro [reserve](#reserve) para especificar a quantidade de memória alocada.

### <a name="example"></a>Exemplo

```cpp
// vector_capacity.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 1 );
   cout << "The length of storage allocated is "
        << v1.capacity( ) << "." << endl;

   v1.push_back( 2 );
   cout << "The length of storage allocated is now "
        << v1.capacity( ) << "." << endl;
}
```

```Output
The length of storage allocated is 1.
The length of storage allocated is now 2.
```

## <a name="cbegin"></a>cbegin

Retorna um iterador **const** que aborda o primeiro elemento no intervalo.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório **const** que aponta para o primeiro elemento do intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).

### <a name="remarks"></a>Comentários

Com o valor de retorno de `cbegin`, os elementos no intervalo não podem ser modificados.

Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **const**) de qualquer tipo que ofereça suporte a `begin()` e `cbegin()`.

```cpp
auto i1 = Container.begin();
// i1 is Container<T>::iterator
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator
```

## <a name="cend"></a>cend

Retorna um iterador **const** que aborda o local logo após o último elemento em um intervalo.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório **const** que aponta muito além do fim do intervalo.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador passou do fim de seu intervalo.

Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **const**) de qualquer tipo que ofereça suporte a `end()` e `cend()`.

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator
```

O valor retornado por `cend` não deve ser desreferenciado. Use-o apenas para comparações.

## <a name="clear"></a>formatação

Apaga os elementos do vetor.

```cpp
void clear();
```

### <a name="example"></a>Exemplo

```cpp
// vector_clear.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 20 );
   v1.push_back( 30 );

   cout << "The size of v1 is " << v1.size( ) << endl;
   v1.clear( );
   cout << "The size of v1 after clearing is " << v1.size( ) << endl;
}
```

```Output
The size of v1 is 3
The size of v1 after clearing is 0
```

## <a name="const_iterator"></a>const_iterator

Um tipo que fornece um iterador de acesso aleatório que pode ler um elemento **const** em um vetor.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_iterator` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Veja o exemplo de [back](#back) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a>const_pointer

Um tipo que fornece um ponteiro para um elemento **const** em um vetor.

```cpp
typedef typename Allocator::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo `const_pointer` não pode ser usado para modificar o valor de um elemento.

Um [iterator](#iterator) é usado com mais frequência para acessar um elemento de vetor.

## <a name="const_reference"></a>const_reference

Um tipo que fornece uma referência a um elemento **const** armazenado em um vetor. Ele é usado para ler e executar operações **const** .

```cpp
typedef typename Allocator::const_reference const_reference;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reference` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

```cpp
// vector_const_ref.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 20 );

   const vector <int> v2 = v1;
   const int &i = v2.front( );
   const int &j = v2.back( );
   cout << "The first element is " << i << endl;
   cout << "The second element is " << j << endl;

   // The following line would cause an error as v2 is const
   // v2.push_back( 30 );
}
```

```Output
The first element is 10
The second element is 20
```

## <a name="const_reverse_iterator"></a>const_reverse_iterator

Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento **const** no vetor.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar por meio do vetor em ordem inversa.

### <a name="example"></a>Exemplo

Consulte [rbegin](#rbegin) para obter um exemplo de como declarar e usar um iterador.

## <a name="crbegin"></a>crbegin

Retorna um iterador const para o primeiro elemento em um vetor invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório inverso const que endereça o primeiro elemento em um [vector](../standard-library/vector-class.md) invertido ou que endereça qual foi o último elemento no `vector` não invertido.

### <a name="remarks"></a>Comentários

Com o valor de retorno de `crbegin`, o objeto de `vector` não pode ser modificado.

### <a name="example"></a>Exemplo

```cpp
// vector_crbegin.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator v1_Iter;
   vector <int>::const_reverse_iterator v1_rIter;

   v1.push_back( 1 );
   v1.push_back( 2 );

   v1_Iter = v1.begin( );
   cout << "The first element of vector is "
        << *v1_Iter << "." << endl;

   v1_rIter = v1.crbegin( );
   cout << "The first element of the reversed vector is "
        << *v1_rIter << "." << endl;
}
```

```Output
The first element of vector is 1.
The first element of the reversed vector is 2.
```

## <a name="crend"></a>crend

Retorna um iterador const que endereça o local após o último elemento em um vetor invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório inverso const que endereça o local após o último elemento em um [vector](../standard-library/vector-class.md) invertido (o local que precedeu o primeiro elemento no `vector` não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um `vector` invertido, assim como [vector::cend](#cend) é usado com um `vector`.

Com o valor de retorno de `crend` (adequadamente decrementado), o objeto de `vector` não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `vector`.

O valor retornado por `crend` não deve ser desreferenciado. Use-o apenas para comparações.

### <a name="example"></a>Exemplo

```cpp
// vector_crend.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::const_reverse_iterator v1_rIter;

   v1.push_back( 1 );
   v1.push_back( 2 );

   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )
      cout << *v1_rIter << endl;
}
```

```Output
2
1
```

## <a name="data"></a>dado

Retorna um ponteiro para o primeiro elemento no vetor.

```cpp
const_pointer data() const;

pointer data();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o primeiro elemento no [vector](../standard-library/vector-class.md) ou para o local após um `vector` vazio.

### <a name="example"></a>Exemplo

```cpp
// vector_data.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> c1;
    vector<int>::pointer c1 ptr;
    vector<int>::const_pointer c1_cPtr;

    c1.push_back(1);
    c1.push_back(2);

    cout << "The vector c1 contains elements:";
    c1_cPtr = c1.data();
    for (size_t n = c1.size(); 0 < n; --n, c1_cPtr++)
    {
        cout << " " << *c1_cPtr;
    }
    cout << endl;

    cout << "The vector c1 now contains elements:";
    c1 ptr = c1.data();
    *c1 ptr = 20;
    for (size_t n = c1.size(); 0 < n; --n, c1 ptr++)
    {
        cout << " " << *c1 ptr;
    }
    cout << endl;
}
```

```Output
The vector c1 contains elements: 1 2
The vector c1 now contains elements: 20 2
```

## <a name="difference_type"></a>difference_type

Um tipo que fornece a diferença entre dois iteradores que se referem a elementos no mesmo vetor.

```cpp
typedef typename Allocator::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

Um `difference_type` também pode ser descrito como o número de elementos entre dois ponteiros, uma vez que um ponteiro para um elemento contém o seu endereço.

Um [iterator](#iterator) é usado com mais frequência para acessar um elemento de vetor.

### <a name="example"></a>Exemplo

```cpp
// vector_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <vector>
#include <algorithm>

int main( )
{
   using namespace std;

   vector <int> c1;
   vector <int>::iterator c1_Iter, c2_Iter;

   c1.push_back( 30 );
   c1.push_back( 20 );
   c1.push_back( 30 );
   c1.push_back( 10 );
   c1.push_back( 30 );
   c1.push_back( 20 );

   c1_Iter = c1.begin( );
   c2_Iter = c1.end( );

   vector <int>::difference_type   df_typ1, df_typ2, df_typ3;

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

## <a name="emplace"></a>emplace

Insere um elemento construído no local no vetor em uma posição especificada.

```cpp
template <class... Types>
iterator emplace(
    const_iterator position,
    Types&&... args);
```

### <a name="parameters"></a>Parâmetros

\ de *posição*
A posição no [vetor](../standard-library/vector-class.md) em que o primeiro elemento é inserido.

*args*\
Argumentos de construtor. A função infere qual sobrecarga de construtor deve ser invocada com base nos argumentos fornecidos.

### <a name="return-value"></a>Valor de retorno

A função retorna um iterador que aponta para a posição em que o novo elemento foi inserido no `vector`.

### <a name="remarks"></a>Comentários

Qualquer operação de inserção pode ser cara, consulte a [classe vector](../standard-library/vector-class.md) para obter uma discussão sobre o desempenho de `vector`.

### <a name="example"></a>Exemplo

```cpp
// vector_emplace.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator Iter;

   v1.push_back( 10 );
   v1.push_back( 20 );
   v1.push_back( 30 );

   cout << "v1 =" ;
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;

// initialize a vector of vectors by moving v1
   vector < vector <int> > vv1;

   vv1.emplace( vv1.begin(), move( v1 ) );
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )
      {
      cout << "vv1[0] =";
      for (Iter = vv1[0].begin( ); Iter != vv1[0].end( ); Iter++ )
         cout << " " << *Iter;
      cout << endl;
      }
}
```

```Output
v1 = 10 20 30
vv1[0] = 10 20 30
```

## <a name="emplace_back"></a>emplace_back

Adiciona um elemento construído no local ao final do vetor.

```cpp
template <class... Types>
void emplace_back(Types&&... args);
```

### <a name="parameters"></a>Parâmetros

*args*\
Argumentos de construtor. A função infere qual sobrecarga de construtor deve ser invocada com base nos argumentos fornecidos.

### <a name="example"></a>Exemplo

```cpp
#include <vector>
struct obj
{
   obj(int, double) {}
};

int main()
{
   std::vector<obj> v;
   v.emplace_back(1, 3.14); // obj in created in place in the vector
}
```

## <a name="empty"></a>esvaziá

Testa se o vetor está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o vetor estiver vazio; **false** se o vetor não estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// vector_empty.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );

   if ( v1.empty( ) )
      cout << "The vector is empty." << endl;
   else
      cout << "The vector is not empty." << endl;
}
```

```Output
The vector is not empty.
```

## <a name="end"></a>completo

Retorna o iterador que ultrapassa o fim.

```cpp
iterator end();

const_iterator end() const;
```

### <a name="return-value"></a>Valor de retorno

O iterador que ultrapassa o fim do vetor. Se o vetor estiver vazio, `vector::end() == vector::begin()`.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `end` for atribuído a uma variável do tipo `const_iterator`, o objeto de vetor não poderá ser modificado. Se o valor de retorno de `end` for atribuído a uma variável do tipo `iterator`, o objeto de vetor poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// vector_end.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>
int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator v1_Iter;

   v1.push_back( 1 );
   v1.push_back( 2 );

   for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )
      cout << *v1_Iter << endl;
}
```

```Output
1
2
```

## <a name="erase"></a>borracha

Remove um elemento ou um intervalo de elementos em um vetor das posições especificadas.

```cpp
iterator erase(
    const_iterator position);

iterator erase(
    const_iterator first,
    const_iterator last);
```

### <a name="parameters"></a>Parâmetros

\ de *posição*
Posição do elemento a ser removido do vetor.

*primeiro*\
Posição do primeiro elemento removido do vetor.

*última*\
Posição após o último elemento removido do vetor.

### <a name="return-value"></a>Valor de retorno

Um iterador que designará o primeiro elemento restante além de todos os elementos removidos ou um ponteiro para o final do vetor se esse elemento não existir.

### <a name="example"></a>Exemplo

```cpp
// vector_erase.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator Iter;

   v1.push_back( 10 );
   v1.push_back( 20 );
   v1.push_back( 30 );
   v1.push_back( 40 );
   v1.push_back( 50 );

   cout << "v1 =" ;
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;

   v1.erase( v1.begin( ) );
   cout << "v1 =";
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;

   v1.erase( v1.begin( ) + 1, v1.begin( ) + 3 );
   cout << "v1 =";
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;
}
```

```Output
v1 = 10 20 30 40 50
v1 = 20 30 40 50
v1 = 20 50
```

## <a name="front"></a>dianteiro

Retorna uma referência ao primeiro elemento em um vetor.

```cpp
reference front();

const_reference front() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao primeiro elemento no objeto vector. Se o vetor estiver vazio, o retorno será indefinido.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `front` for atribuído a um `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `front` for atribuído a **reference**, o objeto vector poderá ser modificado.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento em um vetor vazio. Para obter mais informações, consulte [iteradores marcados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// vector_front.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 11 );

   int& i = v1.front( );
   const int& ii = v1.front( );

   cout << "The first integer of v1 is "<< i << endl;
   // by incrementing i, we move the front reference to the second element
   i++;
   cout << "Now, the first integer of v1 is "<< i << endl;
}
```

## <a name="get_allocator"></a>get_allocator

Retorna uma cópia do objeto allocator usado para construir o vetor.

```cpp
Allocator get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

O alocador usado pelo vetor.

### <a name="remarks"></a>Comentários

Os alocadores da classe vector especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Escrever e usar sua própria classe de alocador é C++ um recurso avançado.

### <a name="example"></a>Exemplo

```cpp
// vector_get_allocator.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   // The following lines declare objects that use the default allocator.
   vector<int> v1;
   vector<int, allocator<int> > v2 = vector<int, allocator<int> >(allocator<int>( )) ;

   // v3 will use the same allocator class as v1
   vector <int> v3( v1.get_allocator( ) );

   vector<int>::allocator_type xvec = v3.get_allocator( );
   // You can now call functions on the allocator class used by vec
}
```

## <a name="insert"></a>inserido

Insere um elemento, um número de elementos ou um intervalo de elementos no vetor em uma posição especificada.

```cpp
iterator insert(
    const_iterator position,
    const Type& value);

iterator insert(
    const_iterator position,
    Type&& value);

void insert(
    const_iterator position,
    size_type count,
    const Type& value);

template <class InputIterator>
void insert(
    const_iterator position,
    InputIterator first,
    InputIterator last);
```

### <a name="parameters"></a>Parâmetros

\ de *posição*
A posição no vetor em que o primeiro elemento é inserido.

*value*\
O valor do elemento sendo inserido no vetor.

*contagem*\
O número de elementos sendo inseridos no vetor.

*primeiro*\
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*última*\
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

### <a name="return-value"></a>Valor de retorno

As duas primeiras funções `insert` retornam um iterador que aponta para a posição na qual o novo elemento foi inserido no vetor.

### <a name="remarks"></a>Comentários

Como uma pré-condição, o *primeiro* e o *último* não devem ser iteradores no vetor ou o comportamento é indefinido. Qualquer operação de inserção pode ser cara, consulte a [classe vector](../standard-library/vector-class.md) para obter uma discussão sobre o desempenho de `vector`.

### <a name="example"></a>Exemplo

```cpp
// vector_insert.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator Iter;

   v1.push_back( 10 );
   v1.push_back( 20 );
   v1.push_back( 30 );

   cout << "v1 =" ;
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;

   v1.insert( v1.begin( ) + 1, 40 );
   cout << "v1 =";
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;
   v1.insert( v1.begin( ) + 2, 4, 50 );

   cout << "v1 =";
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
   cout << endl;

   const auto v2 = v1;
   v1.insert( v1.begin( )+1, v2.begin( )+2, v2.begin( )+4 );
   cout << "v1 =";
   for (Iter = v1.begin( ); Iter != v1.end( ); Iter++ )
      cout << " " << *Iter;
   cout << endl;

// initialize a vector of vectors by moving v1
   vector < vector <int> > vv1;

   vv1.insert( vv1.begin(), move( v1 ) );
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )
      {
      cout << "vv1[0] =";
      for (Iter = vv1[0].begin( ); Iter != vv1[0].end( ); Iter++ )
         cout << " " << *Iter;
      cout << endl;
      }
}
```

```Output
v1 = 10 20 30
v1 = 10 40 20 30
v1 = 10 40 50 50 50 50 20 30
v1 = 10 50 50 40 50 50 50 50 20 30
vv1[0] = 10 50 50 40 50 50 50 50 20 30
```

## <a name="iterator"></a>repeti

Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor.

```cpp
typedef implementation-defined iterator;
```

### <a name="remarks"></a>Comentários

Um tipo **iterator** pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Consulte o exemplo de [begin](#begin).

## <a name="max_size"></a> max_size

Retorna o tamanho máximo do vetor.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho máximo possível do vetor.

### <a name="example"></a>Exemplo

```cpp
// vector_max_size.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::size_type i;

   i = v1.max_size( );
   cout << "The maximum possible length of the vector is " << i << "." << endl;
}
```

## <a name="op_at"></a>operador []

Retorna uma referência para o elemento de vetor em uma posição especificada.

```cpp
reference operator[](size_type position);

const_reference operator[](size_type position) const;
```

### <a name="parameters"></a>Parâmetros

\ de *posição*
A posição do elemento de vetor.

### <a name="return-value"></a>Valor de retorno

Se a posição especificada for maior ou igual ao tamanho do contêiner, o resultado será indefinido.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `operator[]` for atribuído a um `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor de retorno de `operator[]` for atribuído a uma referência, o objeto de vetor poderá ser modificado.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento fora dos limites do vetor. Para obter mais informações, consulte [iteradores marcados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

```cpp
// vector_op_ref.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 20 );

   int& i = v1[1];
   cout << "The second integer of v1 is " << i << endl;
}
```

## <a name="op_eq"></a>operador =

Substitui os elementos do vetor por uma cópia de outro vetor.

```cpp
vector& operator=(const vector& right);

vector& operator=(vector&& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O [vetor](../standard-library/vector-class.md) sendo copiado para o `vector`.

### <a name="remarks"></a>Comentários

Depois de apagar todos os elementos existentes em uma `vector`, `operator=` copia ou move o conteúdo do *lado* para o `vector`.

### <a name="example"></a>Exemplo

```cpp
// vector_operator_as.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector<int> v1, v2, v3;
   vector<int>::iterator iter;

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
   v2 = move(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;
}
```

## <a name="pointer"></a>refere

Um tipo que fornece um ponteiro para um elemento em um vetor.

```cpp
typedef typename Allocator::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo **pointer** pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

```cpp
// vector_pointer.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
    using namespace std;
    vector<int> v;
    v.push_back( 11 );
    v.push_back( 22 );

    vector<int>::pointer ptr = &v[0];
    cout << *ptr << endl;
    ptr++;
    cout << *ptr << endl;
    *ptr = 44;
    cout << *ptr << endl;
}
```

```Output
11
22
44
```

## <a name="pop_back"></a>pop_back

Exclui o elemento no final do vetor.

```cpp
void pop_back();
```

### <a name="remarks"></a>Comentários

Para obter um exemplo de código, consulte [vector::push_back()](#push_back).

## <a name="push_back"></a> push_back

Adiciona um elemento ao final do vetor.

```cpp
void push_back(const T& value);

void push_back(T&& value);
```

### <a name="parameters"></a>Parâmetros

*value*\
O valor a ser atribuído ao elemento adicionado ao final do vetor.

### <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4
#include <vector>
#include <iostream>

using namespace std;

template <typename T> void print_elem(const T& t) {
    cout << "(" << t << ") ";
}

template <typename T> void print_collection(const T& t) {
    cout << "  " << t.size() << " elements: ";

    for (const auto& p : t) {
        print_elem(p);
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(10 + i);
    }

    cout << "vector data: " << endl;
    print_collection(v);

    // pop_back() until it's empty, printing the last element as we go
    while (v.begin() != v.end()) {
        cout << "v.back(): "; print_elem(v.back()); cout << endl;
        v.pop_back();
    }
}
```

## <a name="rbegin"></a>rbegin

Retorna um iterador para o primeiro elemento em um vetor invertido.

```cpp
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório inverso que endereça o primeiro elemento em um vetor invertido ou que endereça qual foi o último elemento no vetor não invertido.

### <a name="remarks"></a>Comentários

Se o valor de retorno de `rbegin` for atribuído a um `const_reverse_iterator`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto vector poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// vector_rbegin.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator v1_Iter;
   vector <int>::reverse_iterator v1_rIter;

   v1.push_back( 1 );
   v1.push_back( 2 );

   v1_Iter = v1.begin( );
   cout << "The first element of vector is "
        << *v1_Iter << "." << endl;

   v1_rIter = v1.rbegin( );
   cout << "The first element of the reversed vector is "
        << *v1_rIter << "." << endl;
}
```

```Output
The first element of vector is 1.
The first element of the reversed vector is 2.
```

## <a name="reference"></a>referência

Um tipo que fornece uma referência a um elemento armazenado em um vetor.

```cpp
typedef typename Allocator::reference reference;
```

### <a name="example"></a>Exemplo

Consulte [at](#at) para obter um exemplo de como usar **reference** na classe vector.

## <a name="rend"></a>rend

Retorna um iterador que endereça o local após o último elemento em um vetor invertido.

```cpp
const_reverse_iterator rend() const;
reverse_iterator rend();
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório inverso que endereça o local após o último elemento em um vetor invertido (o local que precedeu o primeiro elemento no vetor não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um vetor invertido, assim como [end](#end) é usado com um vetor.

Se o valor de retorno de `rend` for atribuído a um `const_reverse_iterator`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto vector poderá ser modificado.

`rend` pode ser usado para testar se um iterador invertido alcançou o final de seu vetor.

O valor retornado por `rend` não deve ser desreferenciado. Use-o apenas para comparações.

### <a name="example"></a>Exemplo

```cpp
// vector_rend.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::reverse_iterator v1_rIter;

   v1.push_back( 1 );
   v1.push_back( 2 );

   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )
      cout << *v1_rIter << endl;
}
```

```Output
2
1
```

## <a name="reserve"></a>reservado

Reserva um tamanho mínimo de armazenamento para um objeto vector alocando espaço se necessário.

```cpp
void reserve(size_type count);
```

### <a name="parameters"></a>Parâmetros

*contagem*\
O tamanho mínimo de armazenamento a ser alocado para o vetor.

### <a name="example"></a>Exemplo

```cpp
// vector_reserve.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   //vector <int>::iterator Iter;

   v1.push_back( 1 );
   cout << "Current capacity of v1 = "
      << v1.capacity( ) << endl;
   v1.reserve( 20 );
   cout << "Current capacity of v1 = "
      << v1.capacity( ) << endl;
}
```

```Output
Current capacity of v1 = 1
Current capacity of v1 = 20
```

## <a name="resize"></a>alonga

Especifica um novo tamanho para um vetor.

```cpp
void resize(size_type new_size);
void resize(size_type new_size, Type value);
```

### <a name="parameters"></a>Parâmetros

*new_size*\
O novo tamanho do vetor.

*value*\
O valor de inicialização de novos elementos adicionados ao vetor, caso o novo tamanho seja maior que o tamanho original. Se o valor for omitido, os novos objetos usarão o construtor padrão.

### <a name="remarks"></a>Comentários

Se o tamanho do contêiner for menor que o tamanho solicitado, *new_size*, `resize` adicionará elementos ao vetor até atingir o tamanho solicitado. Quando o tamanho do contêiner for maior que o tamanho solicitado, `resize` excluirá os elementos mais próximos ao final do contêiner até atingir o tamanho *new_size*. Nenhuma ação será tomada se o tamanho atual do contêiner for o mesmo que o tamanho solicitado.

[size](#size) reflete o tamanho atual do vetor.

### <a name="example"></a>Exemplo

```cpp
// vectorsizing.cpp
// compile with: /EHsc /W4
// Illustrates vector::reserve, vector::max_size,
// vector::resize, vector::resize, and vector::capacity.
//
// Functions:
//
//    vector::max_size - Returns maximum number of elements vector could
//                       hold.
//
//    vector::capacity - Returns number of elements for which memory has
//                       been allocated.
//
//    vector::size - Returns number of elements in the vector.
//
//    vector::resize - Reallocates memory for vector, preserves its
//                     contents if new size is larger than existing size.
//
//    vector::reserve - Allocates elements for vector to ensure a minimum
//                      size, preserving its contents if the new size is
//                      larger than existing size.
//
//    vector::push_back - Appends (inserts) an element to the end of a
//                        vector, allocating memory for it if necessary.
//
//////////////////////////////////////////////////////////////////////

// The debugger cannot handle symbols more than 255 characters long.
// The C++ Standard Library often creates symbols longer than that.
// The warning can be disabled:
//#pragma warning(disable:4786)

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

void printvstats(const vector<int>& v) {
    cout << "   the vector's size is: " << v.size() << endl;
    cout << "   the vector's capacity is: " << v.capacity() << endl;
    cout << "   the vector's maximum size is: " << v.max_size() << endl;
}

int main()
{
    // declare a vector that begins with 0 elements.
    vector<int> v;

    // Show statistics about vector.
    cout << endl << "After declaring an empty vector:" << endl;
    printvstats(v);
    print("   the vector's contents: ", v);

    // Add one element to the end of the vector.
    v.push_back(-1);
    cout << endl << "After adding an element:" << endl;
    printvstats(v);
    print("   the vector's contents: ", v);

    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }
    cout << endl << "After adding 10 elements:" << endl;
    printvstats(v);
    print("   the vector's contents: ", v);

    v.resize(6);
    cout << endl << "After resizing to 6 elements without an initialization value:" << endl;
    printvstats(v);
    print("   the vector's contents: ", v);

    v.resize(9, 999);
    cout << endl << "After resizing to 9 elements with an initialization value of 999:" << endl;
    printvstats(v);
    print("   the vector's contents: ", v);

    v.resize(12);
    cout << endl << "After resizing to 12 elements without an initialization value:" << endl;
    printvstats(v);
    print("   the vector's contents: ", v);

    // Ensure there's room for at least 1000 elements.
    v.reserve(1000);
    cout << endl << "After vector::reserve(1000):" << endl;
    printvstats(v);

    // Ensure there's room for at least 2000 elements.
    v.resize(2000);
    cout << endl << "After vector::resize(2000):" << endl;
    printvstats(v);
}
```

## <a name="reverse_iterator"></a>reverse_iterator

Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor invertido.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `reverse_iterator` é usado para iterar no vetor em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rbegin](#rbegin).

## <a name="shrink_to_fit"></a>shrink_to_fit

Descarta o excesso de capacidade.

```cpp
void shrink_to_fit();
```

### <a name="example"></a>Exemplo

```cpp
// vector_shrink_to_fit.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   //vector <int>::iterator Iter;

   v1.push_back( 1 );
   cout << "Current capacity of v1 = "
      << v1.capacity( ) << endl;
   v1.reserve( 20 );
   cout << "Current capacity of v1 = "
      << v1.capacity( ) << endl;
   v1.shrink_to_fit();
   cout << "Current capacity of v1 = "
      << v1.capacity( ) << endl;
}
```

```Output
Current capacity of v1 = 1
Current capacity of v1 = 20
Current capacity of v1 = 1
```

## <a name="size"></a>tamanho

Retorna o número de elementos no vetor.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho atual do vetor.

### <a name="example"></a>Exemplo

```cpp
// vector_size.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::size_type i;

   v1.push_back( 1 );
   i = v1.size( );
   cout << "Vector length is " << i << "." << endl;

   v1.push_back( 2 );
   i = v1.size( );
   cout << "Vector length is now " << i << "." << endl;
}
```

```Output
Vector length is 1.
Vector length is now 2.
```

## <a name="size_type"></a>size_type

Um tipo que conta o número de elementos em um vetor.

```cpp
typedef typename Allocator::size_type size_type;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [capacity](#capacity).

## <a name="swap"></a>permuta

Troca os elementos de dois vetores.

```cpp
void swap(
    vector<Type, Allocator>& right);

friend void swap(
    vector<Type, Allocator>& left,
    vector<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
Um vetor que fornece os elementos a serem trocados. Ou, um vetor cujos elementos devem ser trocados com os elementos no vetor *à esquerda*.

\ *à esquerda*
Um vetor cujos elementos devem ser trocados com os elementos no vetor *à direita*.

### <a name="example"></a>Exemplo

```cpp
// vector_swap.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1, v2;

   v1.push_back( 1 );
   v1.push_back( 2 );
   v1.push_back( 3 );

   v2.push_back( 10 );
   v2.push_back( 20 );

   cout << "The number of elements in v1 = " << v1.size( ) << endl;
   cout << "The number of elements in v2 = " << v2.size( ) << endl;
   cout << endl;

   v1.swap( v2 );

   cout << "The number of elements in v1 = " << v1.size( ) << endl;
   cout << "The number of elements in v2 = " << v2.size( ) << endl;
}
```

```Output
The number of elements in v1 = 3
The number of elements in v2 = 2

The number of elements in v1 = 2
The number of elements in v2 = 3
```

## <a name="value_type"></a> value_type

Um tipo que representa o tipo de dados armazenado em um vetor.

```cpp
typedef typename Allocator::value_type value_type;
```

### <a name="remarks"></a>Comentários

`value_type` é um sinônimo do parâmetro de modelo `Type`.

### <a name="example"></a>Exemplo

```cpp
// vector_value_type.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector<int>::value_type AnInt;
   AnInt = 44;
   cout << AnInt << endl;
}
```

```Output
44
```

## <a name="vector"></a>vetor

Constrói um vetor. Sobrecargas constroem um vetor de um tamanho específico ou com elementos de um valor específico. Ou, como uma cópia de todo ou parte de algum outro vetor. Algumas sobrecargas também permitem que você especifique o alocador a ser usado.

```cpp
vector();
explicit vector(const Allocator& allocator);
explicit vector(size_type count);
vector(size_type count, const Type& value);
vector(size_type count, const Type& value, const Allocator& allocator);

vector(const vector& source);
vector(vector&& source);
vector(initializer_list<Type> init_list, const Allocator& allocator);

template <class InputIterator>
vector(InputIterator first, InputIterator last);
template <class InputIterator>
vector(InputIterator first, InputIterator last, const Allocator& allocator);
```

### <a name="parameters"></a>Parâmetros

\ de *alocador*
A classe de alocador a ser usada com esse objeto. [get_allocator](#get_allocator) retorna a classe allocator do objeto.

*contagem*\
O número de elementos no vetor construído.

*value*\
O valor dos elementos no vetor construído.

\ de *origem*
O vetor do qual o vetor construído deve ser uma cópia.

*primeiro*\
A posição do primeiro elemento no intervalo de elementos a ser copiado.

*última*\
A posição do primeiro elemento após o intervalo de elementos a ser copiado.

*init_list*\
O `initializer_list` que contém os elementos a serem copiados.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto de alocador (*alocador*) e inicializam o vetor.

Os primeiros dois construtores especificam um vetor inicial vazio. O segundo Construtor especifica explicitamente o tipo de alocador (*alocador*) a ser usado.

O terceiro construtor Especifica uma repetição de um número especificado (*contagem*) de elementos do valor padrão para a classe `Type`.

Os quarto e quinto construtores especificam uma repetição de elementos (*Count*) *de valor de valor.*

O sexto Construtor especifica uma cópia da *origem*do vetor.

O sétimo Construtor move a *origem*do vetor.

O oitavo construtor usa initializer_list para especificar os elementos.

Os construtores nono e décimo copiam o intervalo [`first`, `last`) de um vetor.

### <a name="example"></a>Exemplo

```cpp
// vector_ctor.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector <int>::iterator v1_Iter, v2_Iter, v3_Iter, v4_Iter, v5_Iter, v6_Iter;

    // Create an empty vector v0
    vector <int> v0;

    // Create a vector v1 with 3 elements of default value 0
    vector <int> v1(3);

    // Create a vector v2 with 5 elements of value 2
    vector <int> v2(5, 2);

    // Create a vector v3 with 3 elements of value 1 and with the allocator
    // of vector v2
    vector <int> v3(3, 1, v2.get_allocator());

    // Create a copy, vector v4, of vector v2
    vector <int> v4(v2);

    // Create a new temporary vector for demonstrating copying ranges
    vector <int> v5(5);
    for (auto i : v5) {
        v5[i] = i;
    }

    // Create a vector v6 by copying the range v5[ first,  last)
    vector <int> v6(v5.begin() + 1, v5.begin() + 3);

    cout << "v1 =";
    for (auto& v : v1){
        cout << " " << v;
    }
    cout << endl;

    cout << "v2 =";
    for (auto& v : v2){
        cout << " " << v;
    }
    cout << endl;

    cout << "v3 =";
    for (auto& v : v3){
        cout << " " << v;
    }
    cout << endl;
    cout << "v4 =";
    for (auto& v : v4){
        cout << " " << v;
    }
    cout << endl;

    cout << "v5 =";
    for (auto& v : v5){
        cout << " " << v;
    }
    cout << endl;

    cout << "v6 =";
    for (auto& v : v6){
        cout << " " << v;
    }
    cout << endl;

    // Move vector v2 to vector v7
    vector <int> v7(move(v2));
    vector <int>::iterator v7_Iter;

    cout << "v7 =";
    for (auto& v : v7){
        cout << " " << v;
    }
    cout << endl;

    vector<int> v8{ { 1, 2, 3, 4 } };
    for (auto& v : v8){
        cout << " " << v ;
    }
    cout << endl;
}
```

```Output
v1 = 0 0 0v2 = 2 2 2 2 2v3 = 1 1 1v4 = 2 2 2 2 2v5 = 0 1 2 3 4v6 = 1 2v7 = 2 2 2 2 21 2 3 4
```

## <a name="see-also"></a>Veja também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
