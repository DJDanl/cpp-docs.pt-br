---
title: Alocadores
ms.date: 11/04/2016
helpviewer_keywords:
- allocators
- C++ Standard Library, allocators
ms.assetid: ac95023b-9e7d-49f5-861a-bf7a9a340746
ms.openlocfilehash: abef6f4e641b7936157ee063443a5b2a220fdd52
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623510"
---
# <a name="allocators"></a>Alocadores

Alocadores são usados pela Biblioteca Padrão do C++ para tratar da alocação e da desalocação de elementos armazenados em contêineres. Todos os contêineres da Biblioteca Padrão do C++, exceto o std::array, têm um parâmetro de modelo do tipo `allocator<Type>`, em que `Type` representa o tipo do elemento de contêiner. Por exemplo, a classe vector é declarada da seguinte maneira:

```cpp
template <
    class Type,
    class Allocator = allocator<Type>
>
class vector
```

A Biblioteca Padrão do C++ fornece uma implementação padrão de um alocador. No C++ 11 e posterior, o alocador padrão é atualizado para exibir uma interface menor, o novo alocador é chamado de *alocador mínimo*. Especificamente, o membro `construct()` do alocador mínimo dá suporte à semântica de movimentação, o que pode melhorar bastante o desempenho. Na maioria dos casos, esse alocador padrão é suficiente. No C++ 11, todos os tipos e funções da Biblioteca Padrão que usam um parâmetro do tipo alocador dão suporte à interface de alocador mínimo, incluindo `std::function`, `shared_ptr, allocate_shared()` e `basic_string`.  Para obter mais informações sobre o alocador padrão, consulte a [Classe allocator](allocator-class.md).

## <a name="writing-your-own-allocator-c11"></a>Criando seu próprio alocador (C++11)

O alocador padrão usa **novo** e **excluir** para alocar e desalocar memória. Se quiser usar um método de alocação de memória diferente, como usar memória compartilhada, você deverá criar seu próprio alocador. Se você estiver usando o C++11 e precisar criar um novo alocador personalizado, crie-o como um alocador mínimo, se possível. Mesmo se você já implementou um alocador do estilo antigo, considere modificá-lo para transformá-lo em um *alocador mínimo* e aproveitar o método `construct()` mais eficiente que será fornecido automaticamente.

Um alocador mínimo requer muito menos clichê e permite que você se concentre nas funções de membro `allocate` e `deallocate` que fazem todo o trabalho. Ao criar um alocador mínimo, não implemente nenhum membro, exceto os que são mostrados no exemplo a seguir:

1. um construtor de cópia de conversão (veja o exemplo)

1. operator==

1. operator!=

1. allocate

1. deallocate

O membro padrão do C++11 `construct()`, que será fornecido para você, faz avanços perfeitos e habilita a semântica de movimentação, é muito mais eficiente em muitos casos do que a versão mais antiga.

> [!WARNING]
> No tempo de compilação, a Biblioteca Padrão do C++ usa a classe allocator_traits para detectar quais membros você forneceu explicitamente e fornece uma implementação padrão para todos os membros que não estão presentes. Não interfira nesse mecanismo fornecendo uma especialização de allocator_traits para o alocador!

O exemplo a seguir mostra uma implementação mínima de um alocador que usa `malloc` e `free`. Observe o uso do novo tipo de exceção `std::bad_array_new_length` que será gerado se o tamanho da matriz for menor que zero ou maior que o tamanho máximo permitido.

```cpp
#pragma once
#include <stdlib.h> //size_t, malloc, free
#include <new> // bad_alloc, bad_array_new_length
#include <memory>
template <class T>
struct Mallocator
{
    typedef T value_type;
    Mallocator() noexcept {} //default ctor not required by C++ Standard Library

    // A converting copy constructor:
    template<class U> Mallocator(const Mallocator<U>&) noexcept {}
    template<class U> bool operator==(const Mallocator<U>&) const noexcept
    {
        return true;
    }
    template<class U> bool operator!=(const Mallocator<U>&) const noexcept
    {
        return false;
    }
    T* allocate(const size_t n) const;
    void deallocate(T* const p, size_t) const noexcept;
};

template <class T>
T* Mallocator<T>::allocate(const size_t n) const
{
    if (n == 0)
    {
        return nullptr;
    }
    if (n > static_cast<size_t>(-1) / sizeof(T))
    {
        throw std::bad_array_new_length();
    }
    void* const pv = malloc(n * sizeof(T));
    if (!pv) { throw std::bad_alloc(); }
    return static_cast<T*>(pv);
}

template<class T>
void Mallocator<T>::deallocate(T * const p, size_t) const noexcept
{
    free(p);
}
```

## <a name="writing-your-own-allocator-c03"></a>Criando seu próprio alocador (C++03)

No C++03, qualquer alocador usado com contêineres da Biblioteca Padrão do C++ deve implementar as seguintes definições de tipo:

|||
|-|-|
|`const_pointer`|`rebind`|
|`const_reference`|`reference`|
|`difference_type`|`size_type`|
|`pointer`|`value_type`|

Além disso, qualquer alocador usado com contêineres da Biblioteca Padrão do C++ deve implementar os seguintes métodos:

|||
|-|-|
|Construtor|`deallocate`|
|Construtor de cópia|`destroy`|
|Destruidor|`max_size`|
|`address`|`operator==`|
|`allocate`|`operator!=`|
|`construct`||

Para obter mais informações sobre esses métodos e definições de tipo, consulte a [Classe allocator](allocator-class.md).

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão do C++](cpp-standard-library-reference.md)
