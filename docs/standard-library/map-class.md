---
title: Classe map
ms.date: 10/18/2018
f1_keywords:
- map/std::map
- map/std::map::allocator_type
- map/std::map::const_iterator
- map/std::map::const_pointer
- map/std::map::const_reference
- map/std::map::const_reverse_iterator
- map/std::map::difference_type
- map/std::map::iterator
- map/std::map::key_compare
- map/std::map::key_type
- map/std::map::mapped_type
- map/std::map::pointer
- map/std::map::reference
- map/std::map::reverse_iterator
- map/std::map::size_type
- map/std::map::value_type
- map/std::map::at
- map/std::map::begin
- map/std::map::cbegin
- map/std::map::cend
- map/std::map::clear
- map/std::map::count
- map/std::map::crbegin
- map/std::map::crend
- map/std::map::emplace
- map/std::map::emplace_hint
- map/std::map::empty
- map/std::map::end
- map/std::map::equal_range
- map/std::map::erase
- map/std::map::find
- map/std::map::get_allocator
- map/std::map::insert
- map/std::map::key_comp
- map/std::map::lower_bound
- map/std::map::max_size
- map/std::map::rbegin
- map/std::map::rend
- map/std::map::size
- map/std::map::swap
- map/std::map::upper_bound
- map/std::map::value_comp
helpviewer_keywords:
- std::map [C++]
- std::map [C++], allocator_type
- std::map [C++], const_iterator
- std::map [C++], const_pointer
- std::map [C++], const_reference
- std::map [C++], const_reverse_iterator
- std::map [C++], difference_type
- std::map [C++], iterator
- std::map [C++], key_compare
- std::map [C++], key_type
- std::map [C++], mapped_type
- std::map [C++], pointer
- std::map [C++], reference
- std::map [C++], reverse_iterator
- std::map [C++], size_type
- std::map [C++], value_type
- std::map [C++], at
- std::map [C++], begin
- std::map [C++], cbegin
- std::map [C++], cend
- std::map [C++], clear
- std::map [C++], count
- std::map [C++], crbegin
- std::map [C++], crend
- std::map [C++], emplace
- std::map [C++], emplace_hint
- std::map [C++], empty
- std::map [C++], end
- std::map [C++], equal_range
- std::map [C++], erase
- std::map [C++], find
- std::map [C++], get_allocator
- std::map [C++], insert
- std::map [C++], key_comp
- std::map [C++], lower_bound
- std::map [C++], max_size
- std::map [C++], rbegin
- std::map [C++], rend
- std::map [C++], size
- std::map [C++], swap
- std::map [C++], upper_bound
- std::map [C++], value_comp
ms.assetid: 7876f4c9-ebb4-4878-af1e-09364c43af0a
ms.openlocfilehash: d25d8837c549b425416632ee07e23bb57fbd17ae
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856706"
---
# <a name="map-class"></a>Classe map

Usado para o armazenamento e a recuperação de dados de uma coleção em que cada elemento é um par que contém um valor de dados e uma chave de classificação. O valor da chave é exclusivo e usado para classificar os dados automaticamente.

O valor de um elemento em um mapa pode ser alterado diretamente. O valor de chave é uma constante e não pode ser alterado. Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave devem ser inseridos para novos elementos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key,
    class Type,
    class Traits = less<Key>,
    class Allocator=allocator<pair <const Key, Type>>>
class map;
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O tipo de dados da chave a ser armazenado no mapa.

*Tipo*\
O tipo de dados do elemento a ser armazenado no mapa.

\ de *características*
O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no mapa. Esse argumento é opcional e o predicado binário `less<Key>` é o valor padrão.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado std::less<>, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

\ de *alocador*
O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e a desalocação do mapa da memória. Esse argumento é opcional e o valor padrão é `allocator<pair<const Key, Type> >`.

## <a name="remarks"></a>Comentários

A classe map da Biblioteca Padrão C++ é:

- Um contêiner de tamanho variável que recupera com eficiência valores de elemento com base em valores de chave associados.

- Reversível, pois fornece iteradores bidirecionais para acessar seus elementos.

- Classificada, pois seus elementos são ordenados por valores de chave, de acordo com uma função de comparação especificada.

- Exclusivo. porque cada um de seus elementos deve ter uma chave exclusiva.

- Um contêiner de par associativo, pois seus valores de dados de elemento são distintos de seus valores de chave.

- Um modelo de classe, porque a funcionalidade que ele fornece é genérica e independente do elemento ou tipo de chave. Os tipos de dados usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.

O iterador fornecido pela classe map é um iterador bidirecional, mas as funções de membro das classes [insert](#insert) e [map](#map) têm versões que usam um iterador de entrada mais fraco como parâmetros de modelo, com menos requisitos de funcionalidade do que aqueles garantidos pela classe de iteradores bidirecionais. Os conceitos de iterador diferente são relacionados por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com ele devem ser limitados por esses requisitos. Um iterador de entrada pode ser desreferenciado para fazer referência a algum objeto e pode se incrementado para o próximo iterador na sequência.

É recomendável basear a escolha do tipo de contêiner no tipo de pesquisa e inserção que é exigido pelo aplicativo. Os contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que oferecem suporte explicitamente a essas operações as executam, na pior das hipóteses, em um tempo proporcional para o logaritmo do número de elementos no contêiner. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente para os elementos removidos.

É recomendável fazer o mapa do contêiner associativo escolhido quando as condições que associam os valores às chaves forem atendidas pelo aplicativo. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras-chave que ocorrem uma única vez e que tenham valores de cadeia de caracteres associados que forneçam definições. Se uma palavra tiver mais de uma definição correta, essa chave não será exclusiva, de modo que um multimapa seria um contêiner melhor. Se apenas a lista de palavras estiver sendo armazenada, um conjunto será o contêiner apropriado. Se forem permitidas várias ocorrências das palavras, um multiset será mais adequado.

O mapa ordena os elementos que controla chamando um objeto de função armazenado do tipo [key_compare](#key_compare). Esse objeto armazenado é uma função de comparação que é acessada chamando o método [key_comp](#key_comp). De modo geral, dois elementos determinados são comparados para saber se um é menor que o outro ou se são equivalentes. Como todos os elementos são comparados, é criada uma sequência ordenada de elementos não equivalentes.

> [!NOTE]
> A função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário f (x, y) é um objeto de função que tem dois objetos Argument x e y, e um valor de retorno de **true** ou **false**. Uma ordenação imposta em um conjunto é uma ordenação fraca estrita se o predicado binário for irreflexive, antisimétrico e transitiva, e se a equivalência for transitiva, onde dois objetos x e y são definidos como equivalentes quando f (x, y) e f (y, x) forem **false**. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.
>
> No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

## <a name="members"></a>Membros

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

|||
|-|-|
|[map](#map)|Constrói uma lista de um tamanho específico, ou com elementos de um valor específico, ou com um `allocator` específico, ou como uma cópia de algum outro mapa.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[allocator_type](#allocator_type)|Um typedef para a classe `allocator` do mapa.|
|[const_iterator](#const_iterator)|Um typedef para um iterador bidirecional que pode ler um elemento **const** no mapa.|
|[const_pointer](#const_pointer)|Um typedef para um ponteiro para um elemento **const** em um mapa.|
|[const_reference](#const_reference)|Um typedef para uma referência a um elemento **const** armazenado em um mapa para leitura e execução de operações **const** .|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no mapa.|
|[difference_type](#difference_type)|Um typedef de inteiro com sinal para o número de elementos de um mapa em um intervalo entre os elementos apontado pelos iteradores.|
|[iterator](#iterator)|Um typedef para um iterador bidirecional que pode ler ou modificar qualquer elemento em um mapa.|
|[key_compare](#key_compare)|Um typedef de um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no mapa.|
|[key_type](#key_type)|Um typedef para a chave de classificação armazenada em cada elemento do mapa.|
|[mapped_type](#mapped_type)|Um typedef para os dados armazenados em cada elemento de um mapa.|
|[pointer](#pointer)|Um typedef para um ponteiro para um elemento **const** em um mapa.|
|[reference](#reference)|Um typedef de uma referência para um elemento armazenado em um mapa.|
|[reverse_iterator](#reverse_iterator)|Um typedef para um iterador bidirecional que pode ler ou modificar um elemento em um mapa invertido.|
|[size_type](#size_type)|Um typedef de inteiro não assinado para o número de elementos em um mapa|
|[value_type](#value_type)|Um typedef para o tipo de objeto armazenado como um elemento em um mapa.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[at](#at)|Localiza um elemento com um valor de chave especificado.|
|[begin](#begin)|Retorna um iterador que aponta para o primeiro elemento no mapa.|
|[cbegin](#cbegin)|Retorna um iterador const que aponta para o primeiro elemento no mapa.|
|[cend](#cend)|Retorna um iterador const que ultrapassa o fim.|
|[clear](#clear)|Apaga todos os elementos de um mapa.|
|[count](#count)|Retorna o número de elementos em um mapa cuja chave corresponde à chave especificada em um parâmetro.|
|[crbegin](#crbegin)|Retorna um iterador const que aponta para o primeiro elemento em um mapa invertido.|
|[crend](#crend)|Retorna um iterador const que aponta para o local após o último elemento em um mapa invertido.|
|[emplace](#emplace)|Insere um elemento construído adequadamente no mapa.|
|[emplace_hint](#emplace_hint)|Insere um elemento construído adequadamente no mapa, com uma dica de posicionamento.|
|[empty](#empty)|Retornará **true** se um mapa estiver vazio.|
|[end](#end)|Retorna o iterador que ultrapassa o fim.|
|[equal_range](#equal_range)|Retorna um par de iteradores. O primeiro iterador no par aponta para o primeiro elemento em um `map` com uma chave que é maior que uma chave especificada. O segundo iterador no par aponta para o primeiro elemento no `map` com uma chave que é igual ou maior que a chave.|
|[erase](#erase)|Remove das posições especificadas um elemento ou um intervalo de elementos em uma mapa.|
|[find](#find)|Retorna um iterador que aponta para o local de um elemento em um mapa que tem uma chave igual a uma chave especificada.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` que é usada para construir o mapa.|
|[insert](#insert)|Insere em uma posição especificada um elemento ou um intervalo de elementos em uma mapa.|
|[key_comp](#key_comp)|Retorna uma cópia do objeto de comparação que é usada para ordenar chaves em um mapa.|
|[lower_bound](#lower_bound)|Retorna um iterador para o primeiro elemento em um mapa que tem um valor de chave que é igual ou maior que uma chave especificada.|
|[max_size](#max_size)|Retorna o comprimento máximo do mapa.|
|[rbegin](#rbegin)|Retorna um iterador que aponta para o primeiro elemento em um mapa invertido.|
|[rend](#rend)|Retorna um iterador que aponta para o local após o último elemento em um mapa invertido.|
|[size](#size)|Retorna o número de elementos no mapa.|
|[swap](#swap)|Troca os elementos de dois mapas.|
|[upper_bound](#upper_bound)|Retorna um iterador para o primeiro elemento em um mapa que tem um valor de chave que é maior que uma chave especificada.|
|[value_comp](#value_comp)|Recupera uma cópia do objeto de comparação que é usada para ordenar valores de elemento em um mapa.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator&#91;&#93;](#op_at)|Insere um elemento em um mapa com um valor de chave especificado.|
|[operator=](#op_eq)|Substitui os elementos de um mapa por uma cópia de outro mapa.|

## <a name="allocator_type"></a>allocator_type

Um tipo que representa a classe allocator do objeto de mapa.

```cpp
typedef Allocator allocator_type;
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo para [get_allocator](#get_allocator) para obter um exemplo que usa `allocator_type`.

## <a name="at"></a>no

Localiza um elemento com um valor de chave especificado.

```cpp
Type& at(const Key& key);

const Type& at(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

chave * \
O valor de chave a ser localizado.

### <a name="return-value"></a>Valor retornado

Uma referência ao valor de dados do elemento encontrado.

### <a name="remarks"></a>Comentários

Se o valor de chave do argumento não for encontrado, a função gerará um objeto da [Classe out_of_range](../standard-library/out-of-range-class.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_at.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

typedef std::map<char, int> Mymap;
int main()
    {
    Mymap c1;

    c1.insert(Mymap::value_type('a', 1));
    c1.insert(Mymap::value_type('b', 2));
    c1.insert(Mymap::value_type('c', 3));

// find and show elements
    std::cout << "c1.at('a') == " << c1.at('a') << std::endl;
    std::cout << "c1.at('b') == " << c1.at('b') << std::endl;
    std::cout << "c1.at('c') == " << c1.at('c') << std::endl;

    return (0);
    }
```

## <a name="begin"></a>Comece

Retorna um iterador que trata o primeiro elemento no mapa.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional que trata o primeiro elemento no mapa ou o local após um mapa vazio.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_begin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;

   map <int, int> :: iterator m1_Iter;
   map <int, int> :: const_iterator m1_cIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 0, 0 ) );
   m1.insert ( Int_Pair ( 1, 1 ) );
   m1.insert ( Int_Pair ( 2, 4 ) );

   m1_cIter = m1.begin ( );
   cout << "The first element of m1 is " << m1_cIter -> first << endl;

   m1_Iter = m1.begin ( );
   m1.erase ( m1_Iter );

   // The following 2 lines would err because the iterator is const
   // m1_cIter = m1.begin ( );
   // m1.erase ( m1_cIter );

   m1_cIter = m1.begin( );
   cout << "The first element of m1 is now " << m1_cIter -> first << endl;
}
```

```Output
The first element of m1 is 0
The first element of m1 is now 1
```

## <a name="cbegin"></a>cbegin

Retorna um iterador **const** que aborda o local logo após o último elemento em um intervalo.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional **const** que aborda o primeiro elemento no intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).

### <a name="remarks"></a>Comentários

Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.

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

### <a name="return-value"></a>Valor retornado

Um iterador de acesso bidirecional **const** que aponta apenas além do fim do intervalo.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador passou do fim de seu intervalo.

Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` ser um contêiner modificável (não **const**) de qualquer tipo que ofereça suporte a `end()` e `cend()`.

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator
```

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="clear"></a>formatação

Apaga todos os elementos de um mapa.

```cpp
void clear();
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso da função de membro map::clear.

```cpp
// map_clear.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    map<int, int> m1;
    map<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    m1.insert(Int_Pair(1, 1));
    m1.insert(Int_Pair(2, 4));

    i = m1.size();
    cout << "The size of the map is initially "
         << i << "." << endl;

    m1.clear();
    i = m1.size();
    cout << "The size of the map after clearing is "
         << i << "." << endl;
}
```

```Output
The size of the map is initially 2.
The size of the map after clearing is 0.
```

## <a name="const_iterator"></a>const_iterator

Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no mapa.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

O `const_iterator` definido pelo mapa aponta para elementos que são objetos de [value_type](#value_type), que são do tipo `pair`\< **constKey**, **tipo**>, cujo primeiro membro é a chave para o elemento e cujo segundo membro é a referência mapeada mantida pelo elemento.

Para desreferenciar um `const_iterator` `cIter` apontando para um elemento em um mapa, use o operador `->`.

Para acessar o valor da chave do elemento, use `cIter` -> **primeiro**, que é equivalente a (\* `cIter`). **first**.

Para acessar o valor da Datum mapeada para o elemento, use `cIter` -> **segundo**, que é equivalente a (\* `cIter`). **second**.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo para [begin](#begin) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a>const_pointer

Um tipo que fornece um ponteiro para um elemento **const** em um mapa.

```cpp
typedef typename allocator_type::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto de mapa.

## <a name="const_reference"></a>const_reference

Um tipo que fornece uma referência para um elemento **const** armazenado em um mapa para leitura e execução de operações **const**.

```cpp
typedef typename allocator_type::const_reference const_reference;
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_const_ref.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );

   // Declare and initialize a const_reference &Ref1
   // to the key of the first element
   const int &Ref1 = ( m1.begin( ) -> first );

   // The following line would cause an error as the
   // non-const_reference cannot be used to access the key
   // int &Ref1 = ( m1.begin( ) -> first );

   cout << "The key of first element in the map is "
        << Ref1 << "." << endl;

   // Declare and initialize a reference &Ref2
   // to the data value of the first element
   int &Ref2 = ( m1.begin( ) -> second );

   cout << "The data value of first element in the map is "
        << Ref2 << "." << endl;
}
```

```Output
The key of first element in the map is 1.
The data value of first element in the map is 10.
```

## <a name="const_reverse_iterator"></a>const_reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no mapa.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar o mapa em ordem inversa.

Os `const_reverse_iterator` definidos pelo MAP apontam para elementos que são objetos de [value_type](#value_type), que são do tipo `pair<const Key, Type>`, cujo primeiro membro é a chave para o elemento e cujo segundo membro é a referência mapeada mantida pelo elemento.

Para desreferenciar um `const_reverse_iterator crIter` apontando para um elemento em um mapa, use o operador `->`.

Para acessar o valor da chave do elemento, use `crIter` -> **primeiro**, que é equivalente a (\* `crIter`). **primeiro**.

Para acessar o valor da Datum mapeada para o elemento, use `crIter` -> **segundo**, que é equivalente a (\* `crIter`). **primeiro**.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Veja o exemplo de [rend](#rend) para obter uma demonstração de como declarar e usar o `const_reverse_iterator`.

## <a name="count"></a>contar

Retorna o número de elementos em um mapa cuja chave corresponde a uma chave especificada pelo parâmetro.

```cpp
size_type count(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O valor de chave dos elementos a serem correspondidos do mapa.

### <a name="return-value"></a>Valor retornado

1, se o mapa tiver um elemento cuja chave de classificação corresponde à chave de parâmetro; 0, se o mapa não tiver um elemento com uma chave correspondente.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos *x* no intervalo

\[ lower_bound (*chave*), upper_bound (*chave*))

que será 0 ou 1, no caso do mapa, que é um contêiner associativo exclusivo.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso da função de membro map::count.

```cpp
// map_count.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    map<int, int> m1;
    map<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    m1.insert(Int_Pair(1, 1));
    m1.insert(Int_Pair(2, 1));
    m1.insert(Int_Pair(1, 4));
    m1.insert(Int_Pair(2, 1));

    // Keys must be unique in map, so duplicates are ignored
    i = m1.count(1);
    cout << "The number of elements in m1 with a sort key of 1 is: "
         << i << "." << endl;

    i = m1.count(2);
    cout << "The number of elements in m1 with a sort key of 2 is: "
         << i << "." << endl;

    i = m1.count(3);
    cout << "The number of elements in m1 with a sort key of 3 is: "
         << i << "." << endl;
}
```

```Output
The number of elements in m1 with a sort key of 1 is: 1.
The number of elements in m1 with a sort key of 2 is: 1.
The number of elements in m1 with a sort key of 3 is: 0.
```

## <a name="crbegin"></a>crbegin

Retorna um iterador const, que trata o primeiro elemento em um mapa invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional const invertido, que trata o primeiro elemento em um [mapa](../standard-library/map-class.md) invertido ou trata o que foi o último elemento `map` não invertido.

### <a name="remarks"></a>Comentários

`crbegin` é usado com um `map` invertido, assim como [begin](#begin) é usado com um `map`.

Com o valor retornado de `crbegin`, o objeto `map` não pode ser modificado

`crbegin` pode ser usado para iterar em um `map` no sentido inverso.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_crbegin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;

   map <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_crIter = m1.crbegin( );
   cout << "The first element of the reversed map m1 is "
        << m1_crIter -> first << "." << endl;
}
```

```Output
The first element of the reversed map m1 is 3.
```

## <a name="crend"></a>crend

Retorna um iterador const, que trata o local logo após o último elemento em um mapa invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador const bidirecional inverso, que trata o local logo após o último elemento em um [mapa](../standard-library/map-class.md) invertido (o local que precedeu o primeiro elemento no `map` não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um mapa invertido, assim como [end](#end) é usado com um `map`.

Com o valor de retorno `crend`, o objeto `map` não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `map`.

O valor retornado por `crend` não deve ser desreferenciado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_crend.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;

   map <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_crIter = m1.crend( );
   m1_crIter--;
   cout << "The last element of the reversed map m1 is "
        << m1_crIter -> first << "." << endl;
}
```

```Output
The last element of the reversed map m1 is 1.
```

## <a name="difference_type"></a>difference_type

Um tipo de inteiro com sinal, que pode ser usado para representar o número de elementos de um mapa em um intervalo entre os elementos apontado pelos iteradores.

```cpp
typedef allocator_type::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

`difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` é geralmente usado para representar o número de elementos no intervalo *[ first, last)* entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte pelos contêineres reversíveis, como conjunto, a subtração entre iteradores só tem suporte pelos iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como vetor.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <map>
#include <algorithm>

int main( )
{
   using namespace std;
   map <int, int> m1;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 3, 20 ) );
   m1.insert ( Int_Pair ( 2, 30 ) );

   map <int, int>::iterator m1_Iter, m1_bIter, m1_eIter;
   m1_bIter = m1.begin( );
   m1_eIter = m1.end( );

   // Count the number of elements in a map
   map <int, int>::difference_type  df_count = 1;
   m1_Iter = m1.begin( );
   while ( m1_Iter != m1_eIter)
   {
      df_count++;
      m1_Iter++;
   }

   cout << "The number of elements in the map m1 is: "
        << df_count << "." << endl;
}
```

```Output
The number of elements in the map m1 is: 4.
```

## <a name="emplace"></a>emplace

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada) em um mapa.

```cpp
template <class... Args>
pair<iterator, bool>
emplace(
    Args&&... args);
```

### <a name="parameters"></a>Parâmetros

*args*\
Os argumentos encaminhados para criar um elemento a ser inserido no mapa, a menos que ele já contenha um elemento cujo valor seja ordenado de maneira equivalente.

### <a name="return-value"></a>Valor retornado

Um [par](../standard-library/pair-structure.md) cujo componente **bool** é verdadeiro se uma inserção foi feita e false se o mapa já continha um elemento de valor equivalente na ordenação. O componente do iterador do par de valor de retorno aponta para o elemento inserido recentemente se o componente **bool** for verdadeiro ou para o elemento existente se o componente **bool** for falso.

Para acessar o componente do iterador de um `pr`de `pair`, use `pr.first`; para desreferenciá-lo, use `*pr.first`. Para acessar o componente **bool** , use `pr.second`. Para obter um exemplo, consulte o código de amostra mais adiante neste artigo.

### <a name="remarks"></a>Comentários

Nenhum iterador ou referência será invalidada por essa função.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

O [value_type](#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_emplace.cpp
// compile with: /EHsc
#include <map>
#include <string>
#include <iostream>

using namespace std;

template <typename M> void print(const M& m) {
    cout << m.size() << " elements: ";

    for (const auto& p : m) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
}

int main()
{
    map<int, string> m1;

    auto ret = m1.emplace(10, "ten");

    if (!ret.second){
        auto pr = *ret.first;
        cout << "Emplace failed, element with key 10 already exists."
            << endl << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << endl;
        cout << "map not modified" << endl;
    }
    else{
        cout << "map modified, now contains ";
        print(m1);
    }
    cout << endl;

    ret = m1.emplace(10, "one zero");

    if (!ret.second){
        auto pr = *ret.first;
        cout << "Emplace failed, element with key 10 already exists."
            << endl << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << endl;
    }
    else{
        cout << "map modified, now contains ";
        print(m1);
    }
    cout << endl;
}
```

## <a name="emplace_hint"></a>emplace_hint

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.

```cpp
template <class... Args>
iterator emplace_hint(
    const_iterator where,
    Args&&... args);
```

### <a name="parameters"></a>Parâmetros

*args*\
Os argumentos encaminhados para criar um elemento a ser inserido no mapa, a menos que o mapa já contenha esse elemento ou, de modo geral, que ele já contenha um elemento cuja chave seja ordenada de maneira equivalente.

*onde*\
O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto precede imediatamente *onde*, a inserção pode ocorrer no tempo constante amortizado em vez da hora logarítmica.)

### <a name="return-value"></a>Valor retornado

Um iterador para o elemento recém-inserido.

Se a inserção tiver falhado porque o elemento já existe, ele retornará um iterador para o elemento existente com sua chave.

### <a name="remarks"></a>Comentários

Nenhum iterador ou referência será invalidada por essa função.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

O [value_type](#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_emplace.cpp
// compile with: /EHsc
#include <map>
#include <string>
#include <iostream>

using namespace std;

template <typename M> void print(const M& m) {
    cout << m.size() << " elements: " << endl;

    for (const auto& p : m) {
        cout << "(" << p.first <<  "," << p.second << ") ";
    }

    cout << endl;
}

int main()
{
    map<string, string> m1;

    // Emplace some test data
    m1.emplace("Anna", "Accounting");
    m1.emplace("Bob", "Accounting");
    m1.emplace("Carmine", "Engineering");

    cout << "map starting data: ";
    print(m1);
    cout << endl;

    // Emplace with hint
    // m1.end() should be the "next" element after this emplacement
    m1.emplace_hint(m1.end(), "Doug", "Engineering");

    cout << "map modified, now contains ";
    print(m1);
    cout << endl;
}
```

## <a name="empty"></a>esvaziá

Testa se um mapa está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**true**, se o mapa estiver vazio; **false**, se o mapa não estiver vazio.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_empty.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1, m2;

   typedef pair <int, int> Int_Pair;
   m1.insert ( Int_Pair ( 1, 1 ) );

   if ( m1.empty( ) )
      cout << "The map m1 is empty." << endl;
   else
      cout << "The map m1 is not empty." << endl;

   if ( m2.empty( ) )
      cout << "The map m2 is empty." << endl;
   else
      cout << "The map m2 is not empty." << endl;
}
```

```Output
The map m1 is not empty.
The map m2 is empty.
```

## <a name="end"></a>completo

Retorna o iterador que ultrapassa o fim.

```cpp
const_iterator end() const;

iterator end();
```

### <a name="return-value"></a>Valor retornado

O iterador que ultrapassa o fim. Se o mapa estiver vazio, então, `map::end() == map::begin()`.

### <a name="remarks"></a>Comentários

`end` é usado para testar se um iterador passou o final de seu mapa.

O valor retornado por `end` não deve ser desreferenciado.

Para obter um exemplo de código, consulte [map::find](#find).

## <a name="equal_range"></a>equal_range

Retorna um par de iteradores que representam o [lower_bound](#lower_bound) e o [upper_bound](#upper_bound) da chave.

```cpp
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O valor de chave do argumento a ser comparado com a chave de classificação de um elemento do mapa que está sendo pesquisado.

### <a name="return-value"></a>Valor retornado

Para acessar o primeiro iterador de um par `pr` retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_equal_range.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef map <int, int, less<int> > IntMap;
   IntMap m1;
   map <int, int> :: const_iterator m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   pair <IntMap::const_iterator, IntMap::const_iterator> p1, p2;
   p1 = m1.equal_range( 2 );

   cout << "The lower bound of the element with "
        << "a key of 2 in the map m1 is: "
        << p1.first -> second << "." << endl;

   cout << "The upper bound of the element with "
        << "a key of 2 in the map m1 is: "
        << p1.second -> second << "." << endl;

   // Compare the upper_bound called directly
   m1_RcIter = m1.upper_bound( 2 );

   cout << "A direct call of upper_bound( 2 ) gives "
        << m1_RcIter -> second << "," << endl
        << "matching the 2nd element of the pair"
        << " returned by equal_range( 2 )." << endl;

   p2 = m1.equal_range( 4 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == m1.end( ) ) && ( p2.second == m1.end( ) ) )
      cout << "The map m1 doesn't have an element "
           << "with a key less than 40." << endl;
   else
      cout << "The element of map m1 with a key >= 40 is: "
           << p2.first -> first << "." << endl;
}
```

```Output
The lower bound of the element with a key of 2 in the map m1 is: 20.
The upper bound of the element with a key of 2 in the map m1 is: 30.
A direct call of upper_bound( 2 ) gives 30,
matching the 2nd element of the pair returned by equal_range( 2 ).
The map m1 doesn't have an element with a key less than 40.
```

## <a name="erase"></a>borracha

Remove um elemento ou um intervalo de elementos em um mapa das posições especificadas ou remove elementos que correspondem a uma chave especificada.

```cpp
iterator erase(
    const_iterator Where);

iterator erase(
    const_iterator First,
    const_iterator Last);

size_type erase(
    const key_type& Key);
```

### <a name="parameters"></a>Parâmetros

*Onde*\
A posição do elemento a ser removido.

*Primeiro*\
A posição do primeiro elemento a ser removido.

*Última*\
A posição logo após o último elemento a ser removido.

\ de *chave*
O valor de chave dos elementos a serem removidos.

### <a name="return-value"></a>Valor retornado

Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um elemento que será o final do mapa, se esse elemento não existir.

Para a terceira função de membro, ele retorna o número de elementos que foram removidos do mapa.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_erase.cpp
// compile with: /EHsc
#include <map>
#include <string>
#include <iostream>
#include <iterator> // next() and prev() helper functions
#include <utility>  // make_pair()

using namespace std;

using mymap = map<int, string>;

void printmap(const mymap& m) {
    for (const auto& elem : m) {
        cout << " [" << elem.first << ", " << elem.second << "]";
    }
    cout << endl << "size() == " << m.size() << endl << endl;
}

int main()
{
    mymap m1;

    // Fill in some data to test with, one at a time
    m1.insert(make_pair(1, "A"));
    m1.insert(make_pair(2, "B"));
    m1.insert(make_pair(3, "C"));
    m1.insert(make_pair(4, "D"));
    m1.insert(make_pair(5, "E"));

    cout << "Starting data of map m1 is:" << endl;
    printmap(m1);
    // The 1st member function removes an element at a given position
    m1.erase(next(m1.begin()));
    cout << "After the 2nd element is deleted, the map m1 is:" << endl;
    printmap(m1);

    // Fill in some data to test with, one at a time, using an initializer list
    mymap m2
    {
        { 10, "Bob" },
        { 11, "Rob" },
        { 12, "Robert" },
        { 13, "Bert" },
        { 14, "Bobby" }
    };

    cout << "Starting data of map m2 is:" << endl;
    printmap(m2);
    // The 2nd member function removes elements
    // in the range [First, Last)
    m2.erase(next(m2.begin()), prev(m2.end()));
    cout << "After the middle elements are deleted, the map m2 is:" << endl;
    printmap(m2);

    mymap m3;

    // Fill in some data to test with, one at a time, using emplace
    m3.emplace(1, "red");
    m3.emplace(2, "yellow");
    m3.emplace(3, "blue");
    m3.emplace(4, "green");
    m3.emplace(5, "orange");
    m3.emplace(6, "purple");
    m3.emplace(7, "pink");

    cout << "Starting data of map m3 is:" << endl;
    printmap(m3);
    // The 3rd member function removes elements with a given Key
    mymap::size_type count = m3.erase(2);
    // The 3rd member function also returns the number of elements removed
    cout << "The number of elements removed from m3 is: " << count << "." << endl;
    cout << "After the element with a key of 2 is deleted, the map m3 is:" << endl;
    printmap(m3);
}
```

## <a name="find"></a>considerar

Retorna um iterador que aponta para o local de um elemento em um mapa com uma chave igual a uma chave especificada.

```cpp
iterator find(const Key& key);

const_iterator find(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O valor da chave a ser correspondido pela chave de classificação de um elemento do mapa que está sendo pesquisado.

### <a name="return-value"></a>Valor retornado

Um iterador que se refere ao local de um elemento com uma chave especificada ou o local que substitui o último elemento no mapa (`map::end()`) se nenhuma correspondência for encontrada para a chave.

### <a name="remarks"></a>Comentários

A função de membro retorna um iterador que se refere a um elemento do mapa, cuja chave é equivalente à chave de argumento em um predicado binário que induz uma ordenação com base em uma relação de comparação menor.

Se o valor retornado de `find` for atribuído a `const_iterator`, o objeto de lista não poderá ser modificado. Se o valor de retorno de `find` for atribuído a um `iterator`, o objeto de mapa poderá ser modificado

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// compile with: /EHsc /W4 /MTd
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <utility>  // make_pair()

using namespace std;

template <typename A, typename B> void print_elem(const pair<A, B>& p) {
    cout << "(" << p.first << ", " << p.second << ") ";
}

template <typename T> void print_collection(const T& t) {
    cout << t.size() << " elements: ";

    for (const auto& p : t) {
        print_elem(p);
    }
    cout << endl;
}

template <typename C, class T> void findit(const C& c, T val) {
    cout << "Trying find() on value " << val << endl;
    auto result = c.find(val);
    if (result != c.end()) {
        cout << "Element found: "; print_elem(*result); cout << endl;
    } else {
        cout << "Element not found." << endl;
    }
}

int main()
{
    map<int, string> m1({ { 40, "Zr" }, { 45, "Rh" } });
    cout << "The starting map m1 is (key, value):" << endl;
    print_collection(m1);

    vector<pair<int, string>> v;
    v.push_back(make_pair(43, "Tc"));
    v.push_back(make_pair(41, "Nb"));
    v.push_back(make_pair(46, "Pd"));
    v.push_back(make_pair(42, "Mo"));
    v.push_back(make_pair(44, "Ru"));
    v.push_back(make_pair(44, "Ru")); // attempt a duplicate

    cout << "Inserting the following vector data into m1:" << endl;
    print_collection(v);

    m1.insert(v.begin(), v.end());

    cout << "The modified map m1 is (key, value):" << endl;
    print_collection(m1);
    cout << endl;
    findit(m1, 45);
    findit(m1, 6);
}
```

## <a name="get_allocator"></a>get_allocator

Retorna uma cópia do objeto alocador usado para construir o mapa.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor retornado

O alocador usado pelo mapa.

### <a name="remarks"></a>Comentários

Os alocadores para a classe map especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_get_allocator.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int>::allocator_type m1_Alloc;
   map <int, int>::allocator_type m2_Alloc;
   map <int, double>::allocator_type m3_Alloc;
   map <int, int>::allocator_type m4_Alloc;

   // The following lines declare objects
   // that use the default allocator.
   map <int, int> m1;
   map <int, int, allocator<int> > m2;
   map <int, double, allocator<double> > m3;

   m1_Alloc = m1.get_allocator( );
   m2_Alloc = m2.get_allocator( );
   m3_Alloc = m3.get_allocator( );

   cout << "The number of integers that can be allocated\n"
        << "before free memory is exhausted: "
        << m2.max_size( ) << ".\n" << endl;

   cout << "The number of doubles that can be allocated\n"
        << "before free memory is exhausted: "
        << m3.max_size( ) <<  ".\n" << endl;

   // The following line creates a map m4
   // with the allocator of map m1.
   map <int, int> m4( less<int>( ), m1_Alloc );

   m4_Alloc = m4.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated with the other
   if( m1_Alloc == m4_Alloc )
   {
      cout << "The allocators are interchangeable." << endl;
   }
   else
   {
      cout << "The allocators are not interchangeable." << endl;
   }
}
```

## <a name="insert"></a>inserido

Insere um elemento ou um intervalo de elementos em um mapa.

```cpp
// (1) single element
pair<iterator, bool> insert(
    const value_type& Val);

// (2) single element, perfect forwarded
template <class ValTy>
pair<iterator, bool>
insert(
    ValTy&& Val);

// (3) single element with hint
iterator insert(
    const_iterator Where,
    const value_type& Val);

// (4) single element, perfect forwarded, with hint
template <class ValTy>
iterator insert(
    const_iterator Where,
    ValTy&& Val);

// (5) range
template <class InputIterator>
void insert(
    InputIterator First,
    InputIterator Last);

// (6) initializer list
void insert(
    initializer_list<value_type>
IList);
```

### <a name="parameters"></a>Parâmetros

*Valor*\
O valor de um elemento a ser inserido no mapa, a menos que ele já contenha um elemento cuja chave seja ordenada de maneira equivalente.

*Onde*\
O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto precede imediatamente *onde*, a inserção pode ocorrer no tempo constante amortizado em vez da hora logarítmica.)

\ *ValTy*
Parâmetro de modelo que especifica o tipo de argumento que o mapa pode usar para construir um elemento de [value_type](#value_type)e o *valor* de encaminhamentos perfeitos como um argumento.

*Primeiro*\
A posição do primeiro elemento a ser copiado.

*Última*\
A posição imediatamente após o último elemento a ser copiado.

\ *InputIterator*
Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](#value_type).

*IList*\
O [initializer_list](../standard-library/initializer-list.md) do qual os elementos serão copiados.

### <a name="return-value"></a>Valor retornado

As funções de membro de elemento único, (1) e (2), retornam um [par](../standard-library/pair-structure.md) cujo componente **bool** é true se uma inserção foi feita e false se o mapa já continha um elemento cuja chave tinha um valor equivalente na ordenação. O componente do iterador do par de valor de retorno aponta para o elemento inserido recentemente se o componente **bool** for verdadeiro ou para o elemento existente se o componente **bool** for falso.

As funções do membro de elemento único com dica, (3) e (4), retornam um iterador que aponta para a posição em que o novo elemento foi inserido no mapa ou, se um elemento com uma chave equivalente já existir, para o elemento existente.

### <a name="remarks"></a>Comentários

Nenhum iterador, ponteiro ou referência é invalidado por essa função.

Durante a inserção de apenas um elemento, se uma exceção for lançada, o estado do contêiner não será modificado. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.

Para acessar o componente do iterador de um `pair` `pr` retornado pelas funções de membro de elemento único, use `pr.first`; para desreferenciar o iterador no par retornado, use `*pr.first`, fornecendo um elemento. Para acessar o componente **bool** , use `pr.second`. Para obter um exemplo, consulte o código de amostra mais adiante neste artigo.

O [value_type](#value_type) de um contêiner é um typedef que pertence ao contêiner e para o mapa, `map<K, V>::value_type` é `pair<const K, V>`. O valor de um elemento é um par ordenado no qual o primeiro componente é igual ao valor chave e o segundo componente é igual ao valor dos dados do elemento.

A função do membro de intervalo (5) insere a sequência de valores de elemento em um mapa que corresponde a cada elemento tratado por um iterador no intervalo `[First, Last)`; portanto, `Last` não é inserido. A função de membro do contêiner `end()` faz referência à posição imediatamente após o último elemento no contêiner; por exemplo, a instrução `m.insert(v.begin(), v.end());` tenta inserir todos os elementos de `v` em `m`. Apenas elementos com valores únicos no intervalo são inseridos; as duplicatas são ignoradas. Para observar quais elementos são rejeitados, use as versões de elemento único de `insert`.

A função membro da lista do inicializador (6) usa um [initializer_list](../standard-library/initializer-list.md) para copiar elementos para um mapa.

Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [map::emplace](#emplace) e [map::emplace_hint](#emplace_hint).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_insert.cpp
// compile with: /EHsc
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>  // make_pair()

using namespace std;

template <typename M> void print(const M& m) {
    cout << m.size() << " elements: ";

    for (const auto& p : m) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
}

int main()
{

    // insert single values
    map<int, int> m1;
    // call insert(const value_type&) version
    m1.insert({ 1, 10 });
    // call insert(ValTy&&) version
    m1.insert(make_pair(2, 20));

    cout << "The original key and mapped values of m1 are:" << endl;
    print(m1);

    // intentionally attempt a duplicate, single element
    auto ret = m1.insert(make_pair(1, 111));
    if (!ret.second){
        auto pr = *ret.first;
        cout << "Insert failed, element with key value 1 already exists."
            << endl << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << endl;
    }
    else{
        cout << "The modified key and mapped values of m1 are:" << endl;
        print(m1);
    }
    cout << endl;

    // single element, with hint
    m1.insert(m1.end(), make_pair(3, 30));
    cout << "The modified key and mapped values of m1 are:" << endl;
    print(m1);
    cout << endl;

    // The templatized version inserting a jumbled range
    map<int, int> m2;
    vector<pair<int, int>> v;
    v.push_back(make_pair(43, 294));
    v.push_back(make_pair(41, 262));
    v.push_back(make_pair(45, 330));
    v.push_back(make_pair(42, 277));
    v.push_back(make_pair(44, 311));

    cout << "Inserting the following vector data into m2:" << endl;
    print(v);

    m2.insert(v.begin(), v.end());

    cout << "The modified key and mapped values of m2 are:" << endl;
    print(m2);
    cout << endl;

    // The templatized versions move-constructing elements
    map<int, string>  m3;
    pair<int, string> ip1(475, "blue"), ip2(510, "green");

    // single element
    m3.insert(move(ip1));
    cout << "After the first move insertion, m3 contains:" << endl;
    print(m3);

    // single element with hint
    m3.insert(m3.end(), move(ip2));
    cout << "After the second move insertion, m3 contains:" << endl;
    print(m3);
    cout << endl;

    map<int, int> m4;
    // Insert the elements from an initializer_list
    m4.insert({ { 4, 44 }, { 2, 22 }, { 3, 33 }, { 1, 11 }, { 5, 55 } });
    cout << "After initializer_list insertion, m4 contains:" << endl;
    print(m4);
    cout << endl;
}
```

## <a name="iterator"></a>repeti

Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um mapa.

```cpp
typedef implementation-defined iterator;
```

### <a name="remarks"></a>Comentários

O iterador definido pelo mapa aponta para elementos que são objetos de [value_type](#value_type), ou seja, do tipo `pair<const Key, Type>`, cujo primeiro membro é a chave para o elemento e cujo segundo membro é a referência mapeada mantida pelo elemento.

Para desreferenciar um *ITER* de iterador apontando para um elemento em um mapa, use o operador `->`.

Para acessar o valor da chave do elemento, use `Iter->first`, que é equivalente a `(*Iter).first`. Para acessar o valor da Datum mapeada para o elemento, use `Iter->second`, que é equivalente a `(*Iter).second`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [início](#begin) para obter um exemplo de como declarar e usar `iterator`.

## <a name="key_comp"></a>key_comp

Recupera uma cópia do objeto de comparação usada para ordenar chaves em um mapa.

```cpp
key_compare key_comp() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o objeto de função que usa um mapa para ordenar os seus elementos.

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro

`bool operator(const Key& left, const Key& right);`

que retornará **true** se `left` preceder e não for igual a `right` na ordem de classificação.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_key_comp.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;

   map <int, int, less<int> > m1;
   map <int, int, less<int> >::key_compare kc1 = m1.key_comp( ) ;
   bool result1 = kc1( 2, 3 ) ;
   if( result1 == true )
   {
      cout << "kc1( 2,3 ) returns value of true, "
           << "where kc1 is the function object of m1."
           << endl;
   }
   else
   {
      cout << "kc1( 2,3 ) returns value of false "
           << "where kc1 is the function object of m1."
           << endl;
   }

   map <int, int, greater<int> > m2;
   map <int, int, greater<int> >::key_compare kc2 = m2.key_comp( );
   bool result2 = kc2( 2, 3 ) ;
   if( result2 == true )
   {
      cout << "kc2( 2,3 ) returns value of true, "
           << "where kc2 is the function object of m2."
           << endl;
   }
   else
   {
      cout << "kc2( 2,3 ) returns value of false, "
           << "where kc2 is the function object of m2."
           << endl;
   }
}
```

```Output
kc1( 2,3 ) returns value of true, where kc1 is the function object of m1.
kc2( 2,3 ) returns value of false, where kc2 is the function object of m2.
```

## <a name="key_compare"></a>key_compare

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no mapa.

```cpp
typedef Traits key_compare;
```

### <a name="remarks"></a>Comentários

`key_compare` é um sinônimo para as *características*do parâmetro de modelo.

Para obter mais informações sobre *características* , consulte o tópico [classe de mapa](../standard-library/map-class.md) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [key_comp](#key_comp) para obter um exemplo de como declarar e usar `key_compare`.

## <a name="key_type"></a>key_type

Um tipo que descreve a chave de classificação armazenada em cada elemento do mapa.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

`key_type` é um sinônimo para a *chave*de parâmetro do modelo.

Para obter mais informações sobre a *chave*, consulte a seção comentários do tópico [classe do mapa](../standard-library/map-class.md) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="lower_bound"></a>lower_bound

Retorna um iterador para o primeiro elemento em um mapa com um valor de chave que é igual ou maior que uma chave especificada.

```cpp
iterator lower_bound(const Key& key);

const_iterator lower_bound(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O valor de chave do argumento a ser comparado com a chave de classificação de um elemento do mapa que está sendo pesquisado.

### <a name="return-value"></a>Valor retornado

Um `iterator` ou `const_iterator` que resolve o local de um elemento em um mapa com uma chave que é igual ou maior que a chave de argumento, ou que resolve o local com sucesso do último elemento no mapa, se nenhuma correspondência for encontrada para a chave.

Se o valor retornado de `lower_bound` for atribuído a `const_iterator`, o objeto de lista não poderá ser modificado. Se o valor de retorno de `lower_bound` for atribuído a um `iterator`, o objeto de mapa poderá ser modificado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_lower_bound.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;
   map <int, int> :: const_iterator m1_AcIter, m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_RcIter = m1.lower_bound( 2 );
   cout << "The first element of map m1 with a key of 2 is: "
        << m1_RcIter -> second << "." << endl;

   // If no match is found for this key, end( ) is returned
   m1_RcIter = m1. lower_bound ( 4 );

   if ( m1_RcIter == m1.end( ) )
      cout << "The map m1 doesn't have an element "
           << "with a key of 4." << endl;
   else
      cout << "The element of map m1 with a key of 4 is: "
           << m1_RcIter -> second << "." << endl;

   // The element at a specific location in the map can be found
   // using a dereferenced iterator addressing the location
   m1_AcIter = m1.end( );
   m1_AcIter--;
   m1_RcIter = m1. lower_bound ( m1_AcIter -> first );
   cout << "The element of m1 with a key matching "
        << "that of the last element is: "
        << m1_RcIter -> second << "." << endl;
}
```

```Output
The first element of map m1 with a key of 2 is: 20.
The map m1 doesn't have an element with a key of 4.
The element of m1 with a key matching that of the last element is: 30.
```

## <a name="map"></a>mapeada

Cria um mapa que está vazio ou que é uma cópia de todo ou parte de algum outro mapa.

```cpp
map();

explicit map(
    const Traits& Comp);

map(
    const Traits& Comp,
    const Allocator& Al);

map(
    const map& Right);

map(
    map&& Right);

map(
    initializer_list<value_type> IList);

map(
    initializer_list<value_type> IList,
    const Traits& Comp);

map(
    initializer_list<value_type> IList,
    const Traits& Comp,
    const Allocator& Allocator);

template <class InputIterator>
map(
    InputIterator First,
    InputIterator Last);

template <class InputIterator>
map(
    InputIterator First,
    InputIterator Last,
    const Traits& Comp);

template <class InputIterator>
map(
    InputIterator First,
    InputIterator Last,
    const Traits& Comp,
    const Allocator& Al);
```

### <a name="parameters"></a>Parâmetros

*Al*\
A classe do alocador de armazenamento a ser usado neste objeto de mapa, cujo padrão é `Allocator`.

*Comp*\
A função de comparação do tipo `const Traits` usada para ordenar os elementos no mapa, cujo padrão é `hash_compare`.

\ *à direita*
O mapa do qual o conjunto criado é uma cópia.

*Primeiro*\
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*Última*\
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

*IList*\
A initializer_list da qual os elementos a serem copiados.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o mapa e que, posteriormente, pode ser retornado ao chamar [get_allocator](#get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.

Todos os construtores inicializam seu mapa.

Todos os construtores armazenam um objeto de função do tipo Traits, que é usado para estabelecer uma ordem entre as chaves do mapa e que posteriormente pode ser retornado ao chamar [key_comp](#key_comp).

Os três primeiros construtores especificam um mapa inicial vazio, o segundo que especifica o tipo de função de comparação (*comp*) a ser usado no estabelecimento da ordem dos elementos e o terceiro que especificam explicitamente o tipo de alocador (*Al*) a ser usado. A palavra-chave **Explicit** suprime determinados tipos de conversão automática de tipo.

O quarto construtor Especifica uma cópia do *direito*do mapa.

O quinto Construtor especifica uma cópia do mapa movendo-se para a *direita*.

O sexto, sétimo e oitavo construtores usam uma initializer_list da qual os membros são copiados.

Os próximos três construtores copiam o intervalo `[First, Last)` de um mapa com clareza crescente para especificar o tipo de função de comparação da classe `Traits` e do alocador.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_map.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    typedef pair <int, int> Int_Pair;
    map <int, int>::iterator m1_Iter, m3_Iter, m4_Iter, m5_Iter, m6_Iter, m7_Iter;
    map <int, int, less<int> >::iterator m2_Iter;

    // Create an empty map m0 of key type integer
    map <int, int> m0;

    // Create an empty map m1 with the key comparison
    // function of less than, then insert 4 elements
    map <int, int, less<int> > m1;
    m1.insert(Int_Pair(1, 10));
    m1.insert(Int_Pair(2, 20));
    m1.insert(Int_Pair(3, 30));
    m1.insert(Int_Pair(4, 40));

    // Create an empty map m2 with the key comparison
    // function of greater than, then insert 2 elements
    map <int, int, less<int> > m2;
    m2.insert(Int_Pair(1, 10));
    m2.insert(Int_Pair(2, 20));

    // Create a map m3 with the
    // allocator of map m1
    map <int, int>::allocator_type m1_Alloc;
    m1_Alloc = m1.get_allocator();
    map <int, int> m3(less<int>(), m1_Alloc);
    m3.insert(Int_Pair(3, 30));

    // Create a copy, map m4, of map m1
    map <int, int> m4(m1);

    // Create a map m5 by copying the range m1[ first,  last)
    map <int, int>::const_iterator m1_bcIter, m1_ecIter;
    m1_bcIter = m1.begin();
    m1_ecIter = m1.begin();
    m1_ecIter++;
    m1_ecIter++;
    map <int, int> m5(m1_bcIter, m1_ecIter);

    // Create a map m6 by copying the range m4[ first,  last)
    // and with the allocator of map m2
    map <int, int>::allocator_type m2_Alloc;
    m2_Alloc = m2.get_allocator();
    map <int, int> m6(m4.begin(), ++m4.begin(), less<int>(), m2_Alloc);

    cout << "m1 =";
    for (auto i : m1)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m2 =";
    for(auto i : m2)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m3 =";
    for (auto i : m3)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m4 =";
    for (auto i : m4)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m5 =";
    for (auto i : m5)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m6 =";
    for (auto i : m6)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a map m7 by moving m5
    cout << "m7 =";
    map<int, int> m7(move(m5));
    for (auto i : m7)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a map m8 by copying in an initializer_list
    map<int, int> m8{ { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 } } };
    cout << "m8: = ";
    for (auto i : m8)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a map m9 with an initializer_list and a comparator
    map<int, int> m9({ { 5, 5 }, { 6, 6 }, { 7, 7 }, { 8, 8 } }, less<int>());
    cout << "m9: = ";
    for (auto i : m9)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a map m10 with an initializer_list, a comparator, and an allocator
    map<int, int> m10({ { 9, 9 }, { 10, 10 }, { 11, 11 }, { 12, 12 } }, less<int>(), m9.get_allocator());
    cout << "m10: = ";
    for (auto i : m10)
        cout << i.first << " " << i.second << ", ";
    cout << endl;
}
```

## <a name="mapped_type"></a>mapped_type

Um tipo que representa os dados armazenados em um mapa.

```cpp
typedef Type mapped_type;
```

### <a name="remarks"></a>Comentários

O tipo `mapped_type` é um sinônimo para o parâmetro de modelo de *tipo* da classe.

Para obter mais informações sobre o *tipo* , consulte o tópico [classe de mapa](../standard-library/map-class.md) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `mapped_type`.

## <a name="max_size"></a>max_size

Retorna o comprimento máximo do mapa.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento máximo possível do mapa.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_max_size.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;
   map <int, int> :: size_type i;

   i = m1.max_size( );
   cout << "The maximum possible length "
        << "of the map is " << i << "."
        << endl << "(Magnitude is machine specific.)";
}
```

## <a name="op_at"></a>operador []

Insere um elemento em um mapa com um valor de chave especificado.

```cpp
Type& operator[](const Key& key);

Type& operator[](Key&& key);
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O valor de chave do elemento a ser inserido.

### <a name="return-value"></a>Valor retornado

Uma referência ao valor de dados do elemento inserido.

### <a name="remarks"></a>Comentários

Se o valor de chave do argumento não for encontrado, ele será inserido juntamente com o valor padrão do tipo de dados.

`operator[]` pode ser usado para inserir elementos em um mapa `m` usando `m[key] = DataValue;` onde `DataValue` é o valor da `mapped_type` do elemento com um valor de chave de *chave*.

Ao usar `operator[]` para inserir elementos, a referência retornada não indica se uma inserção está alterando um elemento preexistente ou criando outro. As funções membro [find](#find) e [insert](#insert) podem ser usadas para determinar se um elemento com uma chave especificada já está presente antes de uma inserção.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_op_insert.cpp
// compile with: /EHsc
#include <map>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   typedef pair <const int, int> cInt2Int;
   map <int, int> m1;
   map <int, int> :: iterator pIter;

   // Insert a data value of 10 with a key of 1
   // into a map using the operator[] member function
   m1[ 1 ] = 10;

   // Compare other ways to insert objects into a map
   m1.insert ( map <int, int> :: value_type ( 2, 20 ) );
   m1.insert ( cInt2Int ( 3, 30 ) );

   cout  << "The keys of the mapped elements are:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> first;
   cout << "." << endl;

   cout  << "The values of the mapped elements are:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> second;
   cout << "." << endl;

   // If the key already exists, operator[]
   // changes the value of the datum in the element
   m1[ 2 ] = 40;

   // operator[] will also insert the value of the data
   // type's default constructor if the value is unspecified
   m1[5];

   cout  << "The keys of the mapped elements are now:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> first;
   cout << "." << endl;

   cout  << "The values of the mapped elements are now:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> second;
   cout << "." << endl;

// insert by moving key
    map<string, int> c2;
    string str("abc");
    cout << "c2[move(str)] == " << c2[move(str)] << endl;
    cout << "c2["abc"] == " << c2["abc"] << endl;

    return (0);
}
```

```Output
The keys of the mapped elements are: 1 2 3.
The values of the mapped elements are: 10 20 30.
The keys of the mapped elements are now: 1 2 3 5.
The values of the mapped elements are now: 10 40 30 0.
c2[move(str)] == 0
c2["abc"] == 1
```

## <a name="op_eq"></a>operador =

Substitui os elementos de um mapa por uma cópia de outro mapa.

```cpp
map& operator=(const map& right);
map& operator=(map&& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O [mapa](../standard-library/map-class.md) que está sendo copiado no `map`.

### <a name="remarks"></a>Comentários

Depois de apagar quaisquer elementos existentes em uma `map`, `operator=` copia ou move o conteúdo do *lado direito* para o mapa.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_operator_as.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
   {
   using namespace std;
   map<int, int> v1, v2, v3;
   map<int, int>::iterator iter;

   v1.insert(pair<int, int>(1, 10));

   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << iter->second << " ";
   cout << endl;

   v2 = v1;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << iter->second << " ";
   cout << endl;

// move v1 into v2
   v2.clear();
   v2 = move(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << iter->second << " ";
   cout << endl;
   }
```

## <a name="pointer"></a>refere

Um tipo que fornece um ponteiro para um elemento em um mapa.

```cpp
typedef typename allocator_type::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo `pointer` pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto de mapa.

## <a name="rbegin"></a>rbegin

Retorna um iterador que trata o primeiro elemento em um mapa invertido.

```cpp
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional inverso, que trata o primeiro elemento em um mapa invertido ou trata o que foi o último elemento no mapa não invertido.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um mapa invertido, assim como [begin](#begin) é usado com um mapa.

Se o valor retornado de `rbegin` for atribuído a `const_reverse_iterator`, o objeto de mapa não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto de mapa poderá ser modificado.

`rbegin` pode ser usado para iterar em versões anteriores de um mapa.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_rbegin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;

   map <int, int> :: iterator m1_Iter;
   map <int, int> :: reverse_iterator m1_rIter;
   map <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_rIter = m1.rbegin( );
   cout << "The first element of the reversed map m1 is "
        << m1_rIter -> first << "." << endl;

   // begin can be used to start an iteration
   // through a map in a forward order
   cout << "The map is: ";
   for ( m1_Iter = m1.begin( ) ; m1_Iter != m1.end( ); m1_Iter++)
      cout << m1_Iter -> first << " ";
      cout << "." << endl;

   // rbegin can be used to start an iteration
   // through a map in a reverse order
   cout << "The reversed map is: ";
   for ( m1_rIter = m1.rbegin( ) ; m1_rIter != m1.rend( ); m1_rIter++)
      cout << m1_rIter -> first << " ";
      cout << "." << endl;

   // A map element can be erased by dereferencing to its key
   m1_rIter = m1.rbegin( );
   m1.erase ( m1_rIter -> first );

   m1_rIter = m1.rbegin( );
   cout << "After the erasure, the first element "
        << "in the reversed map is "
        << m1_rIter -> first << "." << endl;
}
```

```Output
The first element of the reversed map m1 is 3.
The map is: 1 2 3 .
The reversed map is: 3 2 1 .
After the erasure, the first element in the reversed map is 2.
```

## <a name="reference"></a>referência

Um tipo que fornece uma referência a um elemento armazenado em um mapa.

```cpp
typedef typename allocator_type::reference reference;
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_reference.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );

   // Declare and initialize a const_reference &Ref1
   // to the key of the first element
   const int &Ref1 = ( m1.begin( ) -> first );

   // The following line would cause an error because the
   // non-const_reference cannot be used to access the key
   // int &Ref1 = ( m1.begin( ) -> first );

   cout << "The key of first element in the map is "
        << Ref1 << "." << endl;

   // Declare and initialize a reference &Ref2
   // to the data value of the first element
   int &Ref2 = ( m1.begin( ) -> second );

   cout << "The data value of first element in the map is "
        << Ref2 << "." << endl;

   //The non-const_reference can be used to modify the
   //data value of the first element
   Ref2 = Ref2 + 5;
   cout << "The modified data value of first element is "
        << Ref2 << "." << endl;
}
```

```Output
The key of first element in the map is 1.
The data value of first element in the map is 10.
The modified data value of first element is 15.
```

## <a name="rend"></a>rend

Retorna um iterador que trata o local logo após o último elemento em um mapa invertido.

```cpp
const_reverse_iterator rend() const;

reverse_iterator rend();
```

### <a name="return-value"></a>Valor retornado

Um iterador bidirecional inverso, que trata a localização após o último elemento em um mapa invertido (a localização que precedeu o primeiro elemento no mapa não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um mapa invertido, assim como [end](#end) é usado com um mapa.

Se o valor retornado de `rend` for atribuído a `const_reverse_iterator`, o objeto de mapa não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto de mapa poderá ser modificado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de seu mapa.

O valor retornado por `rend` não deve ser desreferenciado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_rend.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;

   map <int, int> :: iterator m1_Iter;
   map <int, int> :: reverse_iterator m1_rIter;
   map <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_rIter = m1.rend( );
   m1_rIter--;
   cout << "The last element of the reversed map m1 is "
        << m1_rIter -> first << "." << endl;

   // begin can be used to start an iteration
   // through a map in a forward order
   cout << "The map is: ";
   for ( m1_Iter = m1.begin( ) ; m1_Iter != m1.end( ); m1_Iter++)
      cout << m1_Iter -> first << " ";
      cout << "." << endl;

   // rbegin can be used to start an iteration
   // through a map in a reverse order
   cout << "The reversed map is: ";
   for ( m1_rIter = m1.rbegin( ) ; m1_rIter != m1.rend( ); m1_rIter++)
      cout << m1_rIter -> first << " ";
      cout << "." << endl;

   // A map element can be erased by dereferencing to its key
   m1_rIter = --m1.rend( );
   m1.erase ( m1_rIter -> first );

   m1_rIter = m1.rend( );
   m1_rIter--;
   cout << "After the erasure, the last element "
        << "in the reversed map is "
        << m1_rIter -> first << "." << endl;
}
```

```Output
The last element of the reversed map m1 is 1.
The map is: 1 2 3 .
The reversed map is: 3 2 1 .
After the erasure, the last element in the reversed map is 2.
```

## <a name="reverse_iterator"></a>reverse_iterator

Um tipo que fornece um iterador bidirecional, que pode ler ou modificar um elemento em um mapa invertido.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar o mapa em ordem inversa.

Os `reverse_iterator` definidos pelo MAP apontam para elementos que são objetos de [value_type](#value_type), que são do tipo `pair<const Key, Type>`, cujo primeiro membro é a chave para o elemento e cujo segundo membro é a referência mapeada mantida pelo elemento.

Para desreferenciar um `reverse_iterator` *Sprite* que aponta para um elemento em um mapa, use o operador `->`.

Para acessar o valor da chave do elemento, use `rIter` -> **primeiro**, que é equivalente a (\* `rIter`). **first**. Para acessar o valor da Datum mapeada para o elemento, use `rIter` -> **segundo**, que é equivalente a (\* `rIter`). **first**.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.

## <a name="size"></a>tamanho

Retorna o número de elementos no mapa.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento atual do mapa.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso da função de membro map::size.

```cpp
// map_size.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    map<int, int> m1, m2;
    map<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    m1.insert(Int_Pair(1, 1));
    i = m1.size();
    cout << "The map length is " << i << "." << endl;

    m1.insert(Int_Pair(2, 4));
    i = m1.size();
    cout << "The map length is now " << i << "." << endl;
}
```

```Output
The map length is 1.
The map length is now 2.
```

## <a name="size_type"></a>size_type

Um tipo de inteiro sem sinal, que pode representar o número de elementos em um mapa.

```cpp
typedef typename allocator_type::size_type size_type;
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Veja o exemplo de [size](#size) que demonstra como declarar e usar `size_type`.

## <a name="swap"></a>permuta

Troca os elementos de dois mapas.

```cpp
void swap(
    map<Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O mapa de argumentos que fornece os elementos a serem trocados com o mapa de destino.

### <a name="remarks"></a>Comentários

A função de membro não invalida nenhuma referência, ponteiro ou iterador que designa elementos nos dois mapas, cujos elementos estão sendo trocados.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_swap.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1, m2, m3;
   map <int, int>::iterator m1_Iter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );
   m2.insert ( Int_Pair ( 10, 100 ) );
   m2.insert ( Int_Pair ( 20, 200 ) );
   m3.insert ( Int_Pair ( 30, 300 ) );

   cout << "The original map m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
   cout   << "." << endl;

   // This is the member function version of swap
   //m2 is said to be the argument map; m1 the target map
   m1.swap( m2 );

   cout << "After swapping with m2, map m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
   cout  << "." << endl;

   // This is the specialized template version of swap
   swap( m1, m3 );

   cout << "After swapping with m3, map m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
   cout   << "." << endl;
}
```

```Output
The original map m1 is: 10 20 30.
After swapping with m2, map m1 is: 100 200.
After swapping with m3, map m1 is: 300.
```

## <a name="upper_bound"></a>upper_bound

Retorna um iterador para o primeiro elemento de um mapa com uma chave cujo valor é maior que aquele de uma chave especificada.

```cpp
iterator upper_bound(const Key& key);

const_iterator upper_bound(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
O valor de chave do argumento a ser comparado com o valor da chave de classificação de um elemento do mapa que está sendo pesquisado.

### <a name="return-value"></a>Valor retornado

Um `iterator` ou `const_iterator` que resolve o local de um elemento em um mapa com uma chave maior que a chave de argumento ou que resolve o local com sucesso no último elemento no mapa, se nenhuma correspondência for encontrada para a chave.

Se o valor retornado for atribuído a `const_iterator`, o objeto de lista não poderá ser modificado. Se o valor de retorno for atribuído a um `iterator`, o objeto de mapa poderá ser modificado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_upper_bound.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;
   map <int, int> :: const_iterator m1_AcIter, m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_RcIter = m1.upper_bound( 2 );
   cout << "The first element of map m1 with a key "
        << "greater than 2 is: "
        << m1_RcIter -> second << "." << endl;

   // If no match is found for the key, end is returned
   m1_RcIter = m1. upper_bound ( 4 );

   if ( m1_RcIter == m1.end( ) )
      cout << "The map m1 doesn't have an element "
           << "with a key greater than 4." << endl;
   else
      cout << "The element of map m1 with a key > 4 is: "
           << m1_RcIter -> second << "." << endl;

   // The element at a specific location in the map can be found
   // using a dereferenced iterator addressing the location
   m1_AcIter = m1.begin( );
   m1_RcIter = m1. upper_bound ( m1_AcIter -> first );
   cout << "The 1st element of m1 with a key greater than\n"
        << "that of the initial element of m1 is: "
        << m1_RcIter -> second << "." << endl;
}
```

```Output
The first element of map m1 with a key greater than 2 is: 30.
The map m1 doesn't have an element with a key greater than 4.
The 1st element of m1 with a key greater than
that of the initial element of m1 is: 20.
```

## <a name="value_comp"></a>value_comp

A função membro retorna um objeto de função que determina a ordem dos elementos em um mapa ao comparar seus valores de chave.

```cpp
value_compare value_comp() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o objeto da função de comparação que usa um mapa para ordenar os seus elementos.

### <a name="remarks"></a>Comentários

Para um mapa *m*, se dois elementos *E1*(*K1*, *D1*) e *E2*(*K2*, *D2*) são objetos do tipo `value_type`, em que *K1* e *K1* são suas chaves do tipo `key_type` e *D1* e *D2* são seus dados do tipo `mapped_type`, `m.value_comp(e1, e2)` é equivalente a `m.key_comp(k1, k2)`. Um objeto armazenado define a função de membro

`bool operator( value_type& left, value_type& right);`

que retornará **true** se o valor de chave `left` preceder e for diferente do valor de chave de `right` na ordem de classificação.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_value_comp.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;

   map <int, int, less<int> > m1;
   map <int, int, less<int> >::value_compare vc1 = m1.value_comp( );
   pair< map<int,int>::iterator, bool > pr1, pr2;

   pr1= m1.insert ( map <int, int> :: value_type ( 1, 10 ) );
   pr2= m1.insert ( map <int, int> :: value_type ( 2, 5 ) );

   if( vc1( *pr1.first, *pr2.first ) == true )
   {
      cout << "The element ( 1,10 ) precedes the element ( 2,5 )."
           << endl;
   }
   else
   {
      cout << "The element ( 1,10 ) does not precede the element ( 2,5 )."
           << endl;
   }

   if(vc1( *pr2.first, *pr1.first ) == true )
   {
      cout << "The element ( 2,5 ) precedes the element ( 1,10 )."
           << endl;
   }
   else
   {
      cout << "The element ( 2,5 ) does not precede the element ( 1,10 )."
           << endl;
   }
}
```

```Output
The element ( 1,10 ) precedes the element ( 2,5 ).
The element ( 2,5 ) does not precede the element ( 1,10 ).
```

## <a name="value_type"></a>value_type

O tipo de objeto armazenado como um elemento em um mapa.

```cpp
typedef pair<const Key, Type> value_type;
```

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// map_value_type.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef pair <const int, int> cInt2Int;
   map <int, int> m1;
   map <int, int> :: key_type key1;
   map <int, int> :: mapped_type mapped1;
   map <int, int> :: value_type value1;
   map <int, int> :: iterator pIter;

   // value_type can be used to pass the correct type
   // explicitly to avoid implicit type conversion
   m1.insert ( map <int, int> :: value_type ( 1, 10 ) );

   // Compare other ways to insert objects into a map
   m1.insert ( cInt2Int ( 2, 20 ) );
   m1[ 3 ] = 30;

   // Initializing key1 and mapped1
   key1 = ( m1.begin( ) -> first );
   mapped1 = ( m1.begin( ) -> second );

   cout << "The key of first element in the map is "
        << key1 << "." << endl;

   cout << "The data value of first element in the map is "
        << mapped1 << "." << endl;

   // The following line would cause an error because
   // the value_type is not assignable
   // value1 = cInt2Int ( 4, 40 );

   cout  << "The keys of the mapped elements are:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> first;
   cout << "." << endl;

   cout  << "The values of the mapped elements are:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> second;
   cout << "." << endl;
}
```

## <a name="see-also"></a>Consulte também

[Contêineres](../cpp/containers-modern-cpp.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
