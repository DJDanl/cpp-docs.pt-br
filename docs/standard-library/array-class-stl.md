---
title: Classe array (Biblioteca Padrão C++)| Microsoft Docs
ms.date: 11/13/2019
f1_keywords:
- array/std::array
- array/std::array::const_iterator
- array/std::array::const_pointer
- array/std::array::const_reference
- array/std::array::const_reverse_iterator
- array/std::array::difference_type
- array/std::array::iterator
- array/std::array::pointer
- array/std::array::reference
- array/std::array::reverse_iterator
- array/std::array::size_type
- array/std::array::value_type
- array/std::array::assign
- array/std::array::at
- array/std::array::back
- array/std::array::begin
- array/std::array::cbegin
- array/std::array::cend
- array/std::array::crbegin
- array/std::array::crend
- array/std::array::data
- array/std::array::empty
- array/std::array::end
- array/std::array::fill
- array/std::array::front
- array/std::array::max_size
- array/std::array::rbegin
- array/std::array::rend
- array/std::array::size
- array/std::array::swap
- array/std::array::operator=
- array/std::array::operator[]
helpviewer_keywords:
- std::array [C++]
- std::array [C++], const_iterator
- std::array [C++], const_pointer
- std::array [C++], const_reference
- std::array [C++], const_reverse_iterator
- std::array [C++], difference_type
- std::array [C++], iterator
- std::array [C++], pointer
- std::array [C++], reference
- std::array [C++], reverse_iterator
- std::array [C++], size_type
- std::array [C++], value_type
- std::array [C++], assign
- std::array [C++], at
- std::array [C++], back
- std::array [C++], begin
- std::array [C++], cbegin
- std::array [C++], cend
- std::array [C++], crbegin
- std::array [C++], crend
- std::array [C++], data
- std::array [C++], empty
- std::array [C++], end
- std::array [C++], fill
- std::array [C++], front
- std::array [C++], max_size
- std::array [C++], rbegin
- std::array [C++], rend
- std::array [C++], size
- std::array [C++], swap
- ', '
- std::array [C++], const_iterator
- std::array [C++], const_pointer
- std::array [C++], const_reference
- std::array [C++], const_reverse_iterator
- std::array [C++], difference_type
- std::array [C++], iterator
- std::array [C++], pointer
- std::array [C++], reference
- std::array [C++], reverse_iterator
- std::array [C++], size_type
- std::array [C++], value_type
- std::array [C++], assign
- std::array [C++], at
- std::array [C++], back
- std::array [C++], begin
- std::array [C++], cbegin
- std::array [C++], cend
- std::array [C++], crbegin
- std::array [C++], crend
- std::array [C++], data
- std::array [C++], empty
- std::array [C++], end
- std::array [C++], fill
- std::array [C++], front
- std::array [C++], max_size
- std::array [C++], rbegin
- std::array [C++], rend
- std::array [C++], size
- std::array [C++], swap
ms.assetid: fdfd43a5-b2b5-4b9e-991f-93bf10fb4293
ms.openlocfilehash: e93f5089e62956e7473c95eb6835046b5fe992bf
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74189416"
---
# <a name="array-class-c-standard-library"></a>Classe array (Biblioteca padrão C++)

Descreve um objeto que controla uma sequência de tamanho `N` de elementos do tipo `Ty`. A sequência é armazenada como uma matriz de `Ty`, contida no objeto `array<Ty, N>`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty, std::size_t N>
class array;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`Ty`|O tipo de um elemento.|
|`N`|O número de elementos.|

## <a name="members"></a>Membros

|Definição do tipo|Descrição|
|-|-|
|[const_iterator](#const_iterator)|O tipo de um iterador de constante para a sequência controlada.|
|[const_pointer](#const_pointer)|O tipo de um ponteiro de constante para um elemento.|
|[const_reference](#const_reference)|O tipo de uma referência de constante para um elemento.|
|[const_reverse_iterator](#const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|
|[difference_type](#difference_type)|O tipo de uma distância com sinal entre dois elementos.|
|[iterator](#iterator)|O tipo de um iterador para a sequência controlada.|
|[pointer](#pointer)|O tipo de um ponteiro para um elemento.|
|[reference](#reference)|O tipo de uma referência para um elemento.|
|[reverse_iterator](#reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|
|[size_type](#size_type)|O tipo de uma distância sem sinal entre dois elementos.|
|[value_type](#value_type)|O tipo de um elemento.|

|Função membro|Descrição|
|-|-|
|[array](#array)|Constrói um objeto de matriz.|
|[assign](#assign)|(Obsolete. Use `fill`.) Replaces all elements.|
|[at](#at)|Acessa um elemento em uma posição especificada.|
|[back](#back)|Acessa o último elemento.|
|[begin](#begin)|Designa o início da sequência controlada.|
|[cbegin](#cbegin)|Retorna um iterador const de acesso aleatório para o primeiro elemento na matriz.|
|[cend](#cend)|Retorna um iterador const de acesso aleatório que aponta para imediatamente após o fim da matriz.|
|[crbegin](#crbegin)|Retorna um iterador const para o primeiro elemento em uma matriz invertida.|
|[crend](#crend)|Retorna um iterador const ao final de uma matriz invertido.|
|[data](#data)|Obtém o endereço do primeiro elemento.|
|[empty](#empty)|Testa se há elementos presentes.|
|[end](#end)|Designa o fim da sequência controlada.|
|[fill](#fill)|Substitui todos os elementos por um valor especificado.|
|[front](#front)|Acessa o primeiro elemento.|
|[max_size](#max_size)|Conta o número de elementos.|
|[rbegin](#rbegin)|Designa o início da sequência controlada invertida.|
|[rend](#rend)|Designa o fim da sequência controlada invertida.|
|[size](#size)|Conta o número de elementos.|
|[swap](#swap)|Alterna o conteúdo de dois contêineres.|

|Operador|Descrição|
|-|-|
|[array::operator=](#op_eq)|Substitui a sequência controlada.|
|[array::operator\[\]](#op_at)|Acessa um elemento em uma posição especificada.|

## <a name="remarks"></a>Comentários

O tipo tem um construtor padrão `array()` e um operador de atribuição padrão `operator=` e atende aos requisitos para um `aggregate`. Portanto, os objetos do tipo `array<Ty, N>` podem ser inicializados usando um inicializador agregado. Por exemplo,

```cpp
array<int, 4> ai = { 1, 2, 3 };
```

cria o objeto `ai` que contém quatro valores inteiros, inicializa os três primeiros elementos para os valores 1, 2 e 3, respectivamente, e inicializa o quarto elemento para 0.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<array>

**Namespace:** std

## <a name="array"></a>  array::array

Constrói um objeto de matriz.

```cpp
array();

array(const array& right);
```

### <a name="parameters"></a>Parâmetros

*right*\
Objeto ou intervalo a inserir.

### <a name="remarks"></a>Comentários

O construtor padrão `array()` deixa a sequência não inicializada controlada (ou padrão inicializado). Você pode usá-lo para especificar uma sequência controlada não inicializada.

O construtor de cópia `array(const array& right)` inicializa a sequência controlada com a sequência [*direita*`.begin()`, *direita*`.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de matriz *direita*.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    typedef std::array<int, 4> Myarray;

    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    Myarray c1(c0);

    // display contents " 0 1 2 3"
    for (const auto& it : c1)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0 1 2 3
```

## <a name="assign"></a>  array::assign

Obsoleto no C++ 11, substituído por [preenchimento](#fill). Substitui todos os elementos.

## <a name="at"></a>  array::at

Acessa um elemento em uma posição especificada.

```cpp
reference at(size_type off);

constexpr const_reference at(size_type off) const;
```

### <a name="parameters"></a>Parâmetros

*off*\
Posição do elemento a acessar.

### <a name="remarks"></a>Comentários

The member functions return a reference to the element of the controlled sequence at position *off*. Se a posição for inválida, a função lançará um objeto da classe `out_of_range`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display odd elements " 1 3"
    std::cout << " " << c0.at(1);
    std::cout << " " << c0.at(3);
    std::cout << std::endl;

    return (0);
}
```

## <a name="back"></a>  array::back

Acessa o último elemento.

```cpp
reference back();

constexpr const_reference back() const;
```

### <a name="remarks"></a>Comentários

As funções membro retornam uma referência ao último elemento da sequência controlada, que deve ser não vazio.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display last element " 3"
    std::cout << " " << c0.back();
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
3
```

## <a name="begin"></a>  array::begin

Designa o início da sequência controlada.

```cpp
iterator begin() noexcept;
const_iterator begin() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro retorna um iterador de acesso aleatório que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia).

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::iterator it2 = c0.begin();
    std::cout << " " << *it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="cbegin"></a>  array::cbegin

Returns a **const** iterator that addresses the first element in the range.

```cpp
const_iterator cbegin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

A **const** random-access iterator that points at the first element of the range, or the location just beyond the end of an empty range (for an empty range, `cbegin() == cend()`).

### <a name="remarks"></a>Comentários

Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.

Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. In the example, consider `Container` to be a modifiable (non- **const**) container of any kind that supports `begin()` and `cbegin()`.

```cpp
auto i1 = Container.begin();
// i1 is Container<T>::iterator
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator
```

## <a name="cend"></a>  array::cend

Returns a **const** iterator that addresses the location just beyond the last element in a range.

```cpp
const_iterator cend() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um iterador de acesso aleatório que aponta para além do fim do intervalo.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador passou do fim de seu intervalo.

Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. In the example, consider `Container` to be a modifiable (non- **const**) container of any kind that supports `end()` and `cend()`.

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator
```

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="const_iterator"></a>  array::const_iterator

O tipo de um iterador de constante para a sequência controlada.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador de acesso aleatório constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> MyArray;

int main()
{
    MyArray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    std::cout << "it1:";
    for (MyArray::const_iterator it1 = c0.begin();
        it1 != c0.end();
        ++it1) {
        std::cout << " " << *it1;
    }
    std::cout << std::endl;

    // display first element " 0"
    MyArray::const_iterator it2 = c0.begin();
    std::cout << "it2:";
    std::cout << " " << *it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
it1: 0 1 2 3
it2: 0
```

## <a name="const_pointer"></a>  array::const_pointer

O tipo de um ponteiro de constante para um elemento.

```cpp
typedef const Ty *const_pointer;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um ponteiro de constante para elementos da sequência.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::const_pointer ptr = &*c0.begin();
    std::cout << " " << *ptr;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="const_reference"></a>  array::const_reference

O tipo de uma referência de constante para um elemento.

```cpp
typedef const Ty& const_reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como uma referência constante para um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::const_reference ref = *c0.begin();
    std::cout << " " << ref;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="const_reverse_iterator"></a>  array::const_reverse_iterator

O tipo de um iterador reverso de constante para a sequência controlada.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador inverso constante para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display last element " 3"
    Myarray::const_reverse_iterator it2 = c0.rbegin();
    std::cout << " " << *it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
3
```

## <a name="crbegin"></a>  array::crbegin

Retorna um iterador const para o primeiro elemento em uma matriz invertida.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador de acesso aleatório invertido const que trata do primeiro elemento em uma matriz invertida ou que trata de qual foi o último elemento na matriz não invertida.

### <a name="remarks"></a>Comentários

Com o valor retornado de `crbegin`, o objeto de matriz não pode ser modificado.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

int main( )
{
   using namespace std;
   array<int, 2> v1 = {1, 2};
   array<int, 2>::iterator v1_Iter;
   array<int, 2>::const_reverse_iterator v1_rIter;

   v1_Iter = v1.begin( );
   cout << "The first element of array is "
        << *v1_Iter << "." << endl;

   v1_rIter = v1.crbegin( );
   cout << "The first element of the reversed array is "
        << *v1_rIter << "." << endl;
}
```

```Output
The first element of array is 1.
The first element of the reversed array is 2.
```

## <a name="crend"></a>  array::crend

Retorna um iterador const que trata o local após o último elemento em uma matriz invertida.

```cpp
const_reverse_iterator crend() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um iterador de acesso aleatório inverso const que trata o local após o último elemento em uma matriz invertida (o local que precedeu o primeiro elemento na matriz não invertida).

### <a name="remarks"></a>Comentários

`crend` é usado com uma matriz invertida assim como [array::cend](#cend) é usado com uma matriz.

Com o valor retornado de `crend` (adequadamente diminuído), o objeto de matriz não pode ser modificado.

`crend` pode ser usado para testar se um iterador invertido alcançou o final de sua matriz.

O valor retornado por `crend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

int main( )
{
   using namespace std;
   array<int, 2> v1 = {1, 2};
   array<int, 2>::const_reverse_iterator v1_rIter;

   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )
      cout << *v1_rIter << endl;
}
```

```Output
2
1
```

## <a name="data"></a>  array::data

Obtém o endereço do primeiro elemento.

```cpp
Ty *data();

const Ty *data() const;
```

### <a name="remarks"></a>Comentários

As funções membro retornam o endereço do primeiro elemento na sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::pointer ptr = c0.data();
    std::cout << " " << *ptr;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="difference_type"></a>  array::difference_type

O tipo de uma distância com sinal entre dois elementos.

```cpp
typedef std::ptrdiff_t difference_type;
```

### <a name="remarks"></a>Comentários

O tipo inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer na sequência controlada. É um sinônimo para o tipo `std::ptrdiff_t`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display distance first-last " -4"
    Myarray::difference_type diff = c0.begin() - c0.end();
    std::cout << " " << diff;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
-4
```

## <a name="empty"></a>  array::empty

Testa se nenhum elemento está presente.

```cpp
constexpr bool empty() const;
```

### <a name="remarks"></a>Comentários

A função membro retornará true somente se `N == 0`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display whether c0 is empty " false"
    std::cout << std::boolalpha << " " << c0.empty();
    std::cout << std::endl;

    std::array<int, 0> c1;

    // display whether c1 is empty " true"
    std::cout << std::boolalpha << " " << c1.empty();
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
false
true
```

## <a name="end"></a>  array::end

Designa o fim da sequência controlada.

```cpp
reference end();

const_reference end() const;
```

### <a name="remarks"></a>Comentários

As funções membro retornam um iterador de acesso aleatório que aponta para logo além do fim da sequência.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display last element " 3"
    Myarray::iterator it2 = c0.end();
    std::cout << " " << *--it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
3
```

## <a name="fill"></a>  array::fill

Apaga uma matriz e copia os elementos especificados para a matriz vazia.

```cpp
void fill(const Type& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*val*|O valor do elemento sendo inserido na matriz.|

### <a name="remarks"></a>Comentários

`fill` substitui cada elemento da matriz pelo valor especificado.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

int main()
{
    using namespace std;
    array<int, 2> v1 = { 1, 2 };

    cout << "v1 = ";
    for (const auto& it : v1)
    {
        std::cout << " " << it;
    }
    cout << endl;

    v1.fill(3);
    cout << "v1 = ";
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    cout << endl;
}
```

## <a name="front"></a>  array::front

Acessa o primeiro elemento.

```cpp
reference front();

constexpr const_reference front() const;
```

### <a name="remarks"></a>Comentários

As funções membro retornam uma referência ao primeiro elemento da sequência controlada, que deve ser não vazia.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    std::cout << " " << c0.front();
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="iterator"></a>  array::iterator

O tipo de um iterador para a sequência controlada.

```cpp
typedef implementation-defined iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador de acesso aleatório para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> MyArray;

int main()
{
    MyArray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    std::cout << "it1:";
    for (MyArray::iterator it1 = c0.begin();
        it1 != c0.end();
        ++it1) {
        std::cout << " " << *it1;
    }
    std::cout << std::endl;

    // display first element " 0"
    MyArray::iterator it2 = c0.begin();
    std::cout << "it2:";
    std::cout << " " << *it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
it1: 0 1 2 3

it2: 0
```

## <a name="max_size"></a>  array::max_size

Conta o número de elementos.

```cpp
constexpr size_type max_size() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna `N`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display (maximum) size " 4"
    std::cout << " " << c0.max_size();
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
4
```

## <a name="op_at"></a>  array::operator[]

Acessa um elemento em uma posição especificada.

```cpp
reference operator[](size_type off);

constexpr const_reference operator[](size_type off) const;
```

### <a name="parameters"></a>Parâmetros

*off*\
Posição do elemento a acessar.

### <a name="remarks"></a>Comentários

The member functions return a reference to the element of the controlled sequence at position *off*. Se a posição for inválida, o comportamento será indefinido.

There is also a non-member [get](array-functions.md#get) function available to get a reference to an element of an **array**.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display odd elements " 1 3"
    std::cout << " " << c0[1];
    std::cout << " " << c0[3];
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
1 3
```

## <a name="op_eq"></a>  array::operator=

Substitui a sequência controlada.

```cpp
array<Value> operator=(array<Value> right);
```

### <a name="parameters"></a>Parâmetros

*right*\
O contêiner a ser copiado.

### <a name="remarks"></a>Comentários

The member operator assigns each element of *right* to the corresponding element of the controlled sequence, then returns `*this`. You use it to replace the controlled sequence with a copy of the controlled sequence in *right*.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    Myarray c1;
    c1 = c0;

    // display copied contents " 0 1 2 3"
        // display contents " 0 1 2 3"
    for (auto it : c1)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0 1 2 3
```

## <a name="pointer"></a>  array::pointer

O tipo de um ponteiro para um elemento.

```cpp
typedef Ty *pointer;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um ponteiro para elementos da sequência.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::pointer ptr = &*c0.begin();
    std::cout << " " << *ptr;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="rbegin"></a>  array::rbegin

Designa o início da sequência controlada invertida.

```cpp
reverse_iterator rbegin()noexcept;
const_reverse_iterator rbegin() const noexcept;
```

### <a name="remarks"></a>Comentários

As funções membro retornam um iterador invertido que aponta pra logo além do fim da sequência controlada. Assim, ele designa o início da sequência invertida.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display last element " 3"
    Myarray::const_reverse_iterator it2 = c0.rbegin();
    std::cout << " " << *it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
3
```

## <a name="reference"></a>  array::reference

O tipo de uma referência para um elemento.

```cpp
typedef Ty& reference;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como uma referência para um elemento da sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::reference ref = *c0.begin();
    std::cout << " " << ref;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="rend"></a>  array::rend

Designa o fim da sequência controlada invertida.

```cpp
reverse_iterator rend()noexcept;
const_reverse_iterator rend() const noexcept;
```

### <a name="remarks"></a>Comentários

As funções membro retornam um iterador invertido que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia). Portanto, ele designa o fim da sequência invertida.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display first element " 0"
    Myarray::const_reverse_iterator it2 = c0.rend();
    std::cout << " " << *--it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0
```

## <a name="reverse_iterator"></a>  array::reverse_iterator

O tipo de um iterador inverso para a sequência controlada.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador invertido para a sequência controlada.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display last element " 3"
    Myarray::reverse_iterator it2 = c0.rbegin();
    std::cout << " " << *it2;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
3
```

## <a name="size"></a>  array::size

Conta o número de elementos.

```cpp
constexpr size_type size() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna `N`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display size " 4"
    std::cout << " " << c0.size();
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
4
```

## <a name="size_type"></a>  array::size_type

O tipo de uma distância sem sinal entre dois elementos.

```cpp
typedef std::size_t size_type;
```

### <a name="remarks"></a>Comentários

O tipo inteiro sem sinal descreve um objeto que pode representar o tamanho de qualquer sequência controlada. É um sinônimo para o tipo `std::size_t`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display distance last-first " 4"
    Myarray::size_type diff = c0.end() - c0.begin();
    std::cout << " " << diff;
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
4
```

## <a name="swap"></a>  array::swap

Troca o conteúdo dessa matriz com outra matriz.

```cpp
void swap(array& right);
```

### <a name="parameters"></a>Parâmetros

*right*\
Matriz com a qual trocar conteúdo.

### <a name="remarks"></a>Comentários

The member function swaps the controlled sequences between `*this` and *right*. Realiza uma série de atribuições de elemento e chamadas do construtor proporcionais a `N`.

There is also a non-member [swap](array-functions.md#swap) function available to swap two **array** instances.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    Myarray c1 = { 4, 5, 6, 7 };
    c0.swap(c1);

    // display swapped contents " 4 5 6 7"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    swap(c0, c1);

    // display swapped contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
4 5 6 7
0 1 2 3
```

## <a name="value_type"></a>  array::value_type

O tipo de um elemento.

```cpp
typedef Ty value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Ty`.

### <a name="example"></a>Exemplo

```cpp
#include <array>
#include <iostream>

typedef std::array<int, 4> Myarray;
int main()
{
    Myarray c0 = { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    // display contents " 0 1 2 3"
    for (const auto& it : c0)
    {
        Myarray::value_type val = it;
        std::cout << " " << val;
    }
    std::cout << std::endl;

    return (0);
}
```

```Output
0 1 2 3
0 1 2 3
```

## <a name="see-also"></a>Consulte também

[\<array>](../standard-library/array.md)
