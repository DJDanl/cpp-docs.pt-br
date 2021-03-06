---
title: Classe initializer_list
description: Uma referência para a classe initializer_list na biblioteca padrão C++, conforme implementada pela Microsoft no Visual Studio.
ms.date: 01/28/2020
f1_keywords:
- initializer_list/std::initializer_list::initializer_list
- initializer_list/std::initializer_list::begin
- initializer_list/std::initializer_list::end
- initializer_list/std::initializer_list::size
ms.assetid: 1f2c0ff4-5636-4f79-b008-e75426e3d2ab
helpviewer_keywords:
- std::initializer_list::initializer_list
- std::initializer_list::begin
- std::initializer_list::end
- std::initializer_list::size
ms.openlocfilehash: 232855fbcac1e4df9af7cf956fda80201326a401
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504636"
---
# <a name="initializer_list-class"></a>Classe initializer_list

Fornece acesso a uma matriz de elementos em que cada membro é do tipo especificado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class initializer_list
```

### <a name="parameters"></a>Parâmetros

*Escreva*\
O tipo de dados do elemento a ser armazenado no `initializer_list`.

## <a name="remarks"></a>Comentários

Um `initializer_list` pode ser criado usando uma lista de inicializadores entre chaves:

```cpp
initializer_list<int> i1{ 1, 2, 3, 4 };
```

O compilador transforma listas de inicializadores entre chaves com elementos homogêneos em um `initializer_list` sempre que a assinatura de função requer um `initializer_list`. Para obter mais informações sobre como usar o `initializer_list` , consulte [inicialização uniforme e construtores de delegação](../cpp/initializing-classes-and-structs-without-constructors-cpp.md)

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[initializer_list](#initializer_list)|Constrói um objeto do tipo `initializer_list`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|`value_type`|O tipo dos elementos no `initializer_list`.|
|`reference`|Um tipo que fornece uma referência a um elemento no `initializer_list`.|
|`const_reference`|Um tipo que fornece uma referência constante a um elemento no `initializer_list`.|
|`size_type`|Um tipo que representa o número de elementos no `initializer_list`.|
|`iterator`|Um tipo que fornece um iterador para o `initializer_list`.|
|`const_iterator`|Um tipo que fornece um iterador constante para o `initializer_list`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Comece](#begin)|Retorna um ponteiro para o primeiro elemento em um `initializer_list`.|
|[end](#end)|Retorna um ponteiro para depois do último elemento em um `initializer_list`.|
|[size](#size)|Retorna o número de elementos no `initializer_list`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<initializer_list>

**Namespace:** std

## <a name="initializer_listbegin"></a><a name="begin"></a> initializer_list:: Begin

Retorna um ponteiro para o primeiro elemento em um `initializer_list`.

```cpp
constexpr const InputIterator* begin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro elemento do `initializer_list`. Se a lista estiver vazia, o ponteiro será o mesmo para o início e fim da lista.

## <a name="initializer_listend"></a><a name="end"></a> initializer_list:: End

Retorna um ponteiro para depois do último elemento em um `initializer list`.

```cpp
constexpr const InputIterator* end() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para depois do último elemento na lista. Se a lista estiver vazia, será o mesmo que o ponteiro para o primeiro elemento na lista.

## <a name="initializer_listinitializer_list"></a><a name="initializer_list"></a> initializer_list:: initializer_list

Constrói um objeto do tipo `initializer_list`.

```cpp
constexpr initializer_list() noexcept;
initializer_list(const InputIterator First, const InputIterator Last);
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*Última*\
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

### <a name="remarks"></a>Comentários

Um `initializer_list` baseia-se em uma matriz de objetos do tipo especificado. Copiar um `initializer_list` cria uma segunda instância de uma lista apontando para os mesmos objetos; os objetos subjacentes não são copiados.

### <a name="example"></a>Exemplo

```cpp
// initializer_list_class.cpp
// compile with: /EHsc
#include <initializer_list>
#include <iostream>

int main()
{
    using namespace std;
    // Create an empty initializer_list c0
    initializer_list <int> c0;

    // Create an initializer_list c1 with 1 element
    initializer_list <int> c1{ 3 };

    // Create an initializer_list c2 with 5 elements
    initializer_list <int> c2{ 5, 4, 3, 2, 1 };

    // Create a copy, initializer_list c3, of initializer_list c2
    initializer_list <int> c3(c2);

    // Create a initializer_list c4 by copying the range c3[ first,  last)
    const int* c3_ptr = c3.begin();
    c3_ptr++;
    c3_ptr++;
    initializer_list <int> c4(c3.begin(), c3_ptr);

    // Move initializer_list c4 to initializer_list c5
    initializer_list <int> c5(move(c4));

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

    cout << "c5 =";
    for (auto c : c5)
        cout << " " << c;
    cout << endl;
}
```

```Output
c1 = 3
c2 = 5 4 3 2 1
c3 = 5 4 3 2 1
c5 = 5 4
```

## <a name="initializer_listsize"></a><a name="size"></a> initializer_list:: tamanho

Retorna o número de elementos na lista.

```cpp
constexpr size_t size() const noexcept;
```

### <a name="return-value"></a>Valor retornado

O número de elementos na lista.

## <a name="see-also"></a>Consulte também

[<forward_list>](../standard-library/forward-list.md)
