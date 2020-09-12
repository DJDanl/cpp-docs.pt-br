---
title: classe span (biblioteca C++ padrão) | Microsoft Docs
description: Referência de API para a classe de span da biblioteca de modelos padrão (STL), que fornece uma exibição leve sobre uma sequência de objetos contígua.
ms.date: 05/28/2020
f1_keywords:
- span/std::span
- span/std::span::const_pointer
- span/std::span::const_reference
- span/std::span::difference_type
- span/std::span::element_type
- span/std::span::iterator
- span/std::span::pointer
- span/std::span::reference
- span/std::span::reverse_iterator
- span/std::span::size_type
- span/std::span::value_type
- span/std::span::at
- span/std::span::assign
- span/std::span::back
- span/std::span::begin
- span/std::span::data
- span/std::span::empty
- span/std::span::end
- span/std::span::front
- span/std::span::rbegin
- span/std::span::rend
- span/std::span::size
- span/std::span::size_bytes
- span/std::span::operator=
- span/std::span::operator[]
helpviewer_keywords:
- std::span [C++]
- std::span [C++], const_pointer
- std::span [C++], const_reference
- std::span [C++], difference_type
- std::span [C++], element_type
- std::span [C++], iterator
- std::span [C++], pointer
- std::span [C++], reference
- std::span [C++], reverse_iterator
- std::span [C++], size_type
- std::span [C++], value_type
- std::span [C++], assign
- std::span [C++], at
- std::span [C++], back
- std::span [C++], begin
- std::span [C++], data
- std::span [C++], empty
- std::span [C++], end
- std::span [C++], front
- std::span [C++], rbegin
- std::span [C++], rend
- std::span [C++], size
- std::span [C++], size_bytes
ms.openlocfilehash: 297104820f5498e59397db9025aed1675984a060
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039958"
---
# <a name="span-class-c-standard-library"></a>classe span (biblioteca C++ padrão)

Fornece uma exibição leve sobre uma sequência contígua de objetos. Um Span fornece uma maneira segura de iterar e indexar objetos que são organizados de volta para trás na memória, como objetos armazenados em uma matriz interna, `std::array` ou `std::vector` .

Se, normalmente, você acessar uma sequência de objetos back-to-back usando um ponteiro e um índice, uma `span` é uma alternativa mais segura e leve.

O tamanho de um `span` pode ser definido em tempo de compilação, especificando-o como um argumento de modelo ou em tempo de execução, especificando `dynamic_extent` .

## <a name="syntax"></a>Sintaxe

```cpp
template<class T, size_t Extent = dynamic_extent>
class span;
```

### <a name="template-parameters"></a>Parâmetros de modelo

`T`\
 O tipo dos elementos no span.

`Extent`\
 O número de elementos no span, se especificado no momento da compilação. Caso contrário,  `std::dynamic_extent` se o número de elementos for especificado em tempo de execução.

[Guia de dedução](#deduction_guides)

## <a name="members"></a>Membros

| **Definições de tipo** | **Descrição** |
|-|-|
| [const_pointer](#pointer) | O tipo de um ponteiro para um **`const`** elemento. |
| [const_reference](#reference) | O tipo de uma referência a um **`const`** elemento. |
| [difference_type](#difference_type) | O tipo de uma distância com sinal entre dois elementos. |
| [element_type](#element_type) | O tipo de um elemento span. |
| [repeti](#iterator) | O tipo de um iterador para um Span. |
| [refere](#pointer) | O tipo de um ponteiro para um elemento. |
| [reference](#reference) | O tipo de uma referência para um elemento. |
| [reverse_iterator](#reverse_iterator) | O tipo de um iterador reverso para um Span. |
| [size_type](#size_type) | O tipo para o resultado da distância não assinada entre dois elementos no span. |
| [value_type](#value_type) | O tipo de um elemento, sem **`const`** **`volatile`** qualificações ou. |
| **Construtores** | **Descrição** |
|[compreende](#span)| Construa um `span`.|
| **Suporte a iteradores** | **Descrição** |
|[Comece](#begin) | Obtenha um iterador apontando para o primeiro elemento no span.|
|[completo](#end) | Obtenha um iterador apontando para o fim da extensão. |
|[rbegin](#rbegin) | Obter um iterador reverso apontando para o último elemento do span; ou seja, o início do intervalo invertido.|
|[rend](#rend) | Obter um iterador reverso apontando para a frente do span; ou seja, o final do intervalo invertido.|
| **Elementos de acesso**| **Descrição** |
|[Voltar](#back) | Obter o último elemento no span.|
|[data](#data) | Obtenha o endereço do primeiro elemento no span.|
|[dianteiro](#front) | Obter o primeiro elemento no span.|
|[operador\[\]](#op_at) | Acessar um elemento em uma posição especificada.|
| **Observadores** | **Descrição** |
|[empty](#empty)| Testar se o intervalo está vazio.|
|[size](#size) | Obtém o número de elementos no span.|
|[size_bytes](#size_bytes) | Obtenha o tamanho da extensão em bytes.|
| **Subexibições** | **Descrição**|
| [first](#first_view) | Obtenha um subspan da frente do span.|
| [last](#last_view) | Obtenha um subspan da parte traseira do span.|
| [subspan](#sub_view) | Obtenha um subspan de qualquer lugar no span.|
| **Operadores** | **Descrição** |
|[span:: Operator =](#op_eq)| Substitua o span.|
|[operador span::\[\]](#op_at)| Obtém o elemento na posição especificada. |

## <a name="remarks"></a>Comentários

Todas as `span` funções de membro têm complexidade constante de tempo.

Ao contrário de `array` ou `vector` , um Span não "possui" os elementos dentro dele. Um Span não libera nenhum armazenamento para os itens dentro dele porque ele não possui o armazenamento para esses objetos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<span>

**Namespace:** std

**Opção do compilador:** [/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md)

## <a name="spanback"></a><a name="back"></a> `span::back`

Obter o último elemento no span.

```cpp
constexpr reference back() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao último elemento no span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    cout << mySpan.back();
}
```

```Output
2
```

## <a name="spanbegin"></a><a name="begin"></a> `span::begin`

Obtenha um iterador que aponte para o primeiro elemento no intervalo.

```cpp
constexpr iterator begin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o primeiro elemento no span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    auto i = mySpan.begin();
    cout << *i;
}
```

```Output
0
```

## <a name="spandata"></a><a name="data"></a> `span::data`

Obtenha um ponteiro para o início dos dados de span.

```cpp
constexpr pointer data() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro item armazenado no span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);
    auto i = mySpan.data();
    cout << *i;
}
```

```Output
0
```

## <a name="spandifference_type"></a><a name="difference_type"></a> `span::difference_type`

O número de elementos entre dois elementos em um Span.

```cpp
using difference_type = std::ptrdiff_t;
```

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    span<int>::difference_type distance = mySpan.end() - mySpan.begin();
    cout << distance << std::endl;
}
```

```Output
3
```

## <a name="spanelement_type"></a><a name="element_type"></a> `span::element_type`

O tipo dos elementos no span.

```cpp
using element_type = T;
```

### <a name="remarks"></a>Comentários

O tipo é extraído do parâmetro de modelo `T` quando um Span é criado.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    span<int>::element_type et = mySpan[2];
    cout << et << endl;
}
```

```Output
2
```

## <a name="spanempty"></a><a name="empty"></a> `span::empty`

Se a extensão contém elementos.

```cpp
constexpr bool empty() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Retorna **`true`** If `this->size() == 0` . Caso contrário **`false`** .

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);
    bool isEmpty = mySpan.empty(); // isEmpty == false
}
```

## <a name="spanend"></a><a name="end"></a> `span::end`

Obtenha um iterador até o fim da extensão.

```cpp
constexpr iterator end() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aponta muito além do fim do intervalo.

### <a name="remarks"></a>Comentários

`end` é usado para testar se um iterador passou do fim de seu intervalo.

Não desfaça referência ao valor retornado por este iterador. Use-o para identificar se o iterador atingiu além do último elemento no span.

### <a name="example"></a>Exemplo

```cpp
// Iteration
for (auto it = s1.begin(); it != s1.end(); ++it)
{
    cout << *it;
}
```

## <a name="spanfirst"></a><a name="first_view"></a> `span::first`

Obtenha um subspan, extraído da frente desta extensão.

```cpp
constexpr auto first(size_type count) const noexcept;
template <size_t count> constexpr auto first() const noexcept;
```

### <a name="parameters"></a>Parâmetros

*contar*\
O número de elementos da frente deste intervalo para colocar no subintervalo.  
O número de elementos é especificado como um parâmetro para o modelo ou para a função, conforme ilustrado abaixo.

### <a name="return-value"></a>Valor retornado

Um Span que contém `count` elementos da frente desta extensão.

### <a name="remarks"></a>Comentários

Use a versão de modelo dessa função quando possível para validar o `count` no momento da compilação e para preservar informações sobre a extensão, uma vez que ela retorna um intervalo de extensão fixa.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    auto first2 = mySpan.first(2);
    cout << "mySpan.first(2): ";
    for (auto& i : first2)
    {
        cout << i;
    }

    cout << "\nmySpan.first<2>: ";
    auto viewSpan = mySpan.first<2>();
    for (auto& i : viewSpan)
    {
        cout << i;
    }
}
```

```Output
mySpan.first(2): 01
mySpan.first<2>: 01
```

## <a name="spanfront"></a><a name="front"></a> `span::front`

Obter o primeiro elemento no span.

```cpp
constexpr reference front() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao primeiro elemento no span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    auto i = mySpan.front();
    cout << i;
}
```

```Output
0
```

## <a name="spaniterator"></a><a name="iterator"></a> `span::iterator`

O tipo de um iterador sobre elementos span.

```cpp
using iterator = implementation-defined-iterator-type;
```

### <a name="remarks"></a>Comentários

Esse tipo serve como um iterador sobre os elementos em um Span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    span<int>::iterator it = mySpan.begin();
    cout << *it++ << *it++ << *it;
}
```

```Output
012
```

## <a name="spanlast"></a><a name="last_view"></a> `span::last`

Obtenha um subspan, extraído do final deste span.

```cpp
constexpr span<element_type, dynamic_extent> last(const size_type count) const noexcept;
template <size_t count> constexpr span<element_type, count> last() const noexcept;
```

### <a name="parameters"></a>Parâmetros

*contar*\
O número de elementos do final desta extensão para colocar no subintervalo.
O número pode ser especificado como um parâmetro para o modelo ou para a função, conforme ilustrado abaixo.

### <a name="return-value"></a>Valor retornado

Uma extensão que contém os últimos `count` elementos desta extensão.

### <a name="remarks"></a>Comentários

Use a versão de modelo dessa função quando possível para validar o `count` no momento da compilação e para preservar informações sobre a extensão, uma vez que ela retorna um intervalo de extensão fixa.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    auto first2 = mySpan.last(2);
    cout << "mySpan.last(2): ";
    for (auto& i : last2)
    {
        cout << i;
    }

    cout << "\nmySpan.last<2>: ";
    auto viewSpan = mySpan.last<2>();
    for (auto& i : viewSpan)
    {
        cout << i;
    }
}
```

```Output
mySpan.last(2): 12
mySpan.last<2>: 12
```

## <a name="spanoperator"></a><a name="op_at"></a> `span::operator[]`

Obter o elemento no intervalo em uma posição especificada.

```cpp
constexpr reference operator[](size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*desvio*\
Elemento baseado em zero no span para acessar.

### <a name="return-value"></a>Valor retornado

Uma referência ao elemento no *deslocamento*de posição. Se a posição for inválida, o comportamento será indefinido.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);
    cout << mySpan[1];
}
```

```Output
1
```

## <a name="spanoperator"></a><a name="op_eq"></a> `span::operator=`

Atribua outro intervalo a este.

```cpp
constexpr span& operator=(const span& other) noexcept = default;
```

### <a name="parameters"></a>Parâmetros

*outros*\
O intervalo a ser atribuído a este.

### <a name="return-value"></a>Valor retornado

`*this`

### <a name="remarks"></a>Comentários

A atribuição faz uma cópia superficial do ponteiro de dados e do tamanho. Uma cópia superficial é segura porque uma `span` não aloca memória para os elementos que ela contém.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);
    span<int> mySpan2;
    mySpan2 = mySpan;
    for (auto &i : mySpan2)
    {
        cout << it;
    }
}
```

```Output
012
```

## <a name="spanpointer"></a><a name="pointer"></a> `span::pointer`

Os tipos para um ponteiro e **`const`** ponteiro para um elemento span.

```cpp
using pointer = T*;
using const_pointer = const T*;
```

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    // pointer
    span<int>::pointer ptr = &mySpan[2];
    *ptr = 9;
    cout << mySpan[2];

    // const pointer
    span<int>::const_pointer cPtr = &mySpan[0];
    // *cPtr = 9; error - const
    cout << *cPtr;
}
```

```Output
90
```

## <a name="spanrbegin"></a><a name="rbegin"></a> `span::rbegin`

Obtenha um iterador reverso apontando para o último elemento desta extensão.

```cpp
constexpr reverse_iterator rbegin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do intervalo invertido.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    for (auto rIt = s1.rbegin(); rIt != s1.rend(); ++rIt)
    {
        cout << *rIt;
    }
}
```

```Output
210
```

## <a name="spanreference"></a><a name="reference"></a> `span::reference`

Os tipos de uma referência, e uma **`const`** referência, para um elemento span.

```cpp
using reference = T&;
using const_reference = const T&;
```

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    // reference
    span<int>::reference ref = mySpan[0];
    ref = 9;
    cout << mySpan[0];
    // const reference
    span<int>::const_reference cRef = mySpan[1];
    // cRef = 9; error because const
    cout << cRef;
}
```

```Output
91
```

## <a name="spanrend"></a><a name="rend"></a> `span::rend`

Obtenha um iterador de acesso aleatório que aponte apenas para além do fim do intervalo invertido.

```cpp
constexpr reverse_iterator rend() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um iterador reverso para o espaço reservado seguindo o último elemento no intervalo invertido; ou seja, o espaço reservado antes do primeiro elemento no intervalo não invertido.

### <a name="remarks"></a>Comentários

`rend` é usado com um Span invertido da mesma forma que [span:: End](#end) é usado com um Span. Use-o para testar se um iterador reverso atingiu o final de seu alcance.

O valor retornado por `rend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    for (auto rIt = s1.rbegin(); rIt != s1.rend(); ++rIt)
    {
        cout << *rIt;
    }
}
```

## <a name="spanreverse_iterator"></a><a name="reverse_iterator"></a> `span::reverse_iterator`

O tipo de um iterador reverso para um Span.

```cpp
using reverse_iterator = std::reverse_iterator<iterator>;
```

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    span<int>::reverse_iterator rIt = mySpan.rbegin();
    cout << *rIt++ << *rIt++ << *rIt;
}
```

```Output
210
```

## <a name="spansize"></a><a name="size"></a> `span::size`

Obtém o número de elementos no span.

```cpp
constexpr size_t size() const noexcept;
```

### <a name="return-value"></a>Valor retornado

O número de elementos no span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);
    cout << mySpan.size();
}
```

```Output
3
```

## <a name="spansize_bytes"></a><a name="size_bytes"></a> `span::size_bytes`

Obtenha o tamanho dos elementos na extensão em bytes.

```cpp
constexpr size_type size_bytes() const noexcept;
```

### <a name="return-value"></a>Valor retornado

O número de bytes que todos os elementos no span ocupam; Isto é, `sizeof(element_type)` multiplicado pelo número de elementos no span.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);
    cout << mySpan.size_bytes(); // 3 elements * 4 (size of an int)
}
```

```Output
12
```

## <a name="spansize_type"></a><a name="size_type"></a> `span::size_type`

Um tipo não assinado, adequado para armazenar o número de elementos em um intervalo.

```cpp
using size_type = size_t;
```

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    span<int>::size_type szType = mySpan.size();
    cout << szType;
}
```

```Output
3
```

## <a name="spanspan"></a><a name="span"></a> `span::span`

`span` construtores.

```cpp
constexpr span() noexcept
requires (Extent == 0 || Extent == dynamic_extent) = default;

template <class It>
constexpr explicit(Extent != dynamic_extent)
span(It first, size_type count) noexcept

template <class It, class End>
constexpr explicit(Extent != dynamic_extent)
span(It first, End last) noexcept(noexcept(last - first))

template <class T, size_t N>
requires (Extent == dynamic_extent || Extent == N) && is_convertible_v<T (*)[], T (*)[]>
constexpr span(array<T, N>& arr) noexcept

template <class T, size_t N>
requires (Extent == dynamic_extent || Extent == N) && is_convertible_v<const T (*)[], T (*)[]>
constexpr span(const array<T, N>& arr) noexcept

template <size_t N>
requires (Extent == dynamic_extent || Extent == N)
constexpr span(type_identity_t<T> (&arr)[N]) noexcept

template <class R>
constexpr explicit(Extent != dynamic_extent)
span(R&& r)

// default copy ctor
constexpr span(const span& other) noexcept = default;

// converting  ctor
template <class T, size_t OtherExtent>
requires (Extent == dynamic_extent || OtherExtent == dynamic_extent ||
              Extent == OtherExtent) && is_convertible_v<T (*)[], T (*)[]>
constexpr explicit(Extent != dynamic_extent && OtherExtent == dynamic_extent)
span(const span<T, OtherExtent>& other) noexcept
```

### <a name="parameters"></a>Parâmetros

*arr*\
Construa um intervalo de uma matriz.

*contar*\
Número de elementos que estarão no intervalo.

*primeiro*\
Iterador para o primeiro elemento no span.

*última*\
Iterador para apenas o último elemento no span.

*P*\
O número de elementos que estarão no intervalo.

*outros*\
Faça uma cópia desse span.

*d*\
Construa uma extensão a partir deste intervalo.

### <a name="remarks"></a>Comentários

Um Span não libera o armazenamento de itens na extensão porque ele não possui o armazenamento dos objetos dentro dele.

|Construtor  | Descrição  |
|---------|---------|
|`span()` | Construa um Span vazio. Considerado somente durante a resolução de sobrecarga quando o parâmetro de modelo `Extent` é `0` ou `dynamic_extent` .|
|`span(It first, size_type count)` | Construa um intervalo a partir dos primeiros `count` elementos do iterador `first` .  Considerado somente durante a resolução de sobrecarga quando o parâmetro de modelo `Extent` não é `dynamic_extent` . |
|`span(It first, End last)` | Construa um intervalo a partir dos elementos no iterador `first` até o fim `last` ser atingido. Considerado somente durante a resolução de sobrecarga quando o parâmetro de modelo `Extent` não é `dynamic_extent` . `It` deve ser um `contiguous_iterator` .  |
|`span(array<T, N>& arr) noexcept;`<br /><br />`span(const array<T, N>& arr) noexcept;`<br /><br />`span(type_identity_t<element_type> (&arr)[N]) noexcept;` |  Construa um Span a partir de `N` elementos da matriz especificada. Considerado somente durante a resolução de sobrecarga quando o parâmetro `Extent` de modelo é `dynamic_extent` ou igual a `N` . |
|`span(R&& r)` |  Construa uma extensão a partir de um intervalo. Somente participará na resolução de sobrecarga se o parâmetro de modelo `Extent` não estiver `dynamic_extent` .|
|`span(const span& other)` |  O construtor de cópia gerado pelo compilador. Uma cópia superficial do ponteiro de dados é segura porque o span não aloca a memória para conter os elementos. |
|`span(const span<OtherElementType, OtherExtent>& s) noexcept;` | Convertendo Construtor: Construa um intervalo de outro span. Somente participará na resolução de sobrecarga se o `Extent` parâmetro `dynamic_extent` de modelo `N` for `dynamic_extent` ou for igual a `Extent` .|

### <a name="example"></a>Exemplo

```cpp
#include <span>

using namespace std;

int main()
{
    const int MAX=10;

    int x[MAX];
    for (int i = 0; i < MAX; i++)
    {
        x[i] = i;
    }

    span<int, MAX> span1{ x }; // fixed-size span: compiler error if size of x doesn't match template argument MAX
    span<int> span2{ x }; // size is inferred from x
    span<const int> span3 = span2; // converting constructor
    span<int> span4( span2 ); // copy constructor
}
```

## <a name="spansubspan"></a><a name="sub_view"></a> `span::subspan`

Obter um subintervalo desta extensão.

```cpp
constexpr auto subspan(size_type offset, size_type count = dynamic_extent) const noexcept;

template <size_t offset, size_t count = dynamic_extent>
constexpr auto subspan() const noexcept
```

### <a name="parameters"></a>Parâmetros

*contar*\
O número de elementos a serem colocados no subintervalo. Se `count` for `dynamic_extent` (o valor padrão), o subintervalo será obtido de `offset` até o final deste intervalo.

*desvio*\
O local neste intervalo para iniciar o subintervalo.

### <a name="return-value"></a>Valor retornado

Uma extensão a partir `offset` desta extensão. Contém `count` elementos.

### <a name="remarks"></a>Comentários

Uma versão de modelo dessa função está disponível e verifica a contagem em tempo de compilação, que preserva as informações sobre o intervalo retornando um intervalo de extensão fixa.

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    cout << "mySpan.subspan(1,2): ";
    for (auto& i : mySpan.subspan(1,2))
    {
        cout << i;
    }
    cout << "\nmySpan.subspan<1,2>: ";
    for (auto& i : mySpan.subspan<1,2>())
    {
        cout << i;
    }
    cout << "\nmySpan.subspan<1>: ";
    for (auto& i : mySpan.subspan<1>)
    {
        cout << i;
    }
}
```

```Output
mySpan.subspan(1,2): 12
mySpan.subspan<1,2>: 12
mySpan.subspan<1>: 12
```

## <a name="spanvalue_type"></a><a name="value_type"></a> `span::value_type`

O tipo do elemento na extensão, sem **`const`** ou **`volatile`** qualificações.

```cpp
using value_type = std::remove_cv_t<T>;
```

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

int main()
{
    int a[] = { 0,1,2 };
    span<int> mySpan(a);

    span<int>::value_type vType = mySpan[2];
    cout << vType;
}
```

```Output
2
```

## <a name="deduction-guides"></a><a name="deduction_guides"></a> Guias de dedução

Os guias de dedução a seguir são fornecidos para o span.

```cpp
// Allows the extent to be deduced from std::array and C++ built-in arrays

template <class T, size_t Extent>
span(T (&)[Extent]) -> span<T, Extent>;

template <class T, size_t Size>
span(array<T, Size>&) -> span<T, Size>;

template <class T, size_t Size>
span(const array<T, Size>&) -> span<const T, Size>;

// Allows the element type to be deduced from the iterator and the end of the span.
// The iterator must be contiguous

template <contiguous_iterator It, class End>
span(It, End) -> span<remove_reference_t<iter_reference_t<It>>>;

// Allows the element type to be deduced from a range.
// The range must be contiguous

template <ranges::contiguous_range Rng>
span(Rng &&) -> span<remove_reference_t<ranges::range_reference_t<Rng>>>;
```

## <a name="see-also"></a>Confira também

[\<span>](../standard-library/span.md)  
[Como usar a dedução de argumento de modelo de classe](https://devblogs.microsoft.com/cppblog/how-to-use-class-template-argument-deduction/)
