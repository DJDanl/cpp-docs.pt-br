---
title: Classe allocator_traits
ms.date: 11/04/2016
f1_keywords:
- memory/std::allocator_traits
- memory/std::allocator_traits::propagate_on_container_move_assignment
- memory/std::allocator_traits::const_pointer
- memory/std::allocator_traits::propagate_on_container_swap
- memory/std::allocator_traits::propagate_on_container_copy_assignment
- memory/std::allocator_traits::difference_type
- memory/std::allocator_traits::allocator_type
- memory/std::allocator_traits::value_type
- memory/std::allocator_traits::pointer
- memory/std::allocator_traits::size_type
- memory/std::allocator_traits::const_void_pointer
- memory/std::allocator_traits::void_pointer
- memory/std::allocator_traits::allocate
- memory/std::allocator_traits::construct
- memory/std::allocator_traits::deallocate
- memory/std::allocator_traits::destroy
- memory/std::allocator_traits::max_size
- memory/std::allocator_traits::select_on_container_copy_construction
ms.assetid: 612974b8-b5d4-4668-82fb-824bff6821d6
helpviewer_keywords:
- std::allocator_traits [C++]
- std::allocator_traits [C++], propagate_on_container_move_assignment
- std::allocator_traits [C++], const_pointer
- std::allocator_traits [C++], propagate_on_container_swap
- std::allocator_traits [C++], propagate_on_container_copy_assignment
- std::allocator_traits [C++], difference_type
- std::allocator_traits [C++], allocator_type
- std::allocator_traits [C++], value_type
- std::allocator_traits [C++], pointer
- std::allocator_traits [C++], size_type
- std::allocator_traits [C++], const_void_pointer
- std::allocator_traits [C++], void_pointer
- std::allocator_traits [C++], allocate
- std::allocator_traits [C++], construct
- std::allocator_traits [C++], deallocate
- std::allocator_traits [C++], destroy
- std::allocator_traits [C++], max_size
- std::allocator_traits [C++], select_on_container_copy_construction
ms.openlocfilehash: 470b3086b4bdfa776558122eda9e496fa6c4bcdc
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72690071"
---
# <a name="allocator_traits-class"></a>Classe allocator_traits

O modelo de classe descreve um objeto que complementa um *tipo de alocador*. Um tipo de alocador é qualquer tipo que descreve um objeto alocador que é usado para gerenciar o armazenamento alocado. Especificamente, para qualquer tipo de alocador `Alloc`, você pode usar `allocator_traits<Alloc>` para determinar todas as informações necessárias para um contêiner habilitado para alocador. Para obter mais informações, consulte a [Classe allocator](../standard-library/allocator-class.md) padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Alloc>
    class allocator_traits;
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|`allocator_type`|Esse tipo é um sinônimo do parâmetro de modelo `Alloc`.|
|`const_pointer`|Esse tipo será `Alloc::const_pointer`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::rebind<const value_type>`.|
|`const_void_pointer`|Esse tipo será `Alloc::const_void_pointer`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::rebind<const void>`.|
|`difference_type`|Esse tipo será `Alloc::difference_type`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::difference_type`.|
|`pointer`|Esse tipo será `Alloc::pointer`, se aquele tipo for bem formado, caso contrário, será `value_type *`.|
|`propagate_on_container_copy_assignment`|Esse tipo será `Alloc::propagate_on_container_copy_assignment`, se aquele tipo for bem formado, caso contrário, será `false_type`.|
|`propagate_on_container_move_assignment`|Esse tipo será `Alloc::propagate_on_container_move_assignment`, se aquele tipo for bem formado, caso contrário, será `false_type`. Se o tipo for verdadeiro, um contêiner habilitado para alocador copiará seu alocador armazenado em uma atribuição de movimentação.|
|`propagate_on_container_swap`|Esse tipo será `Alloc::propagate_on_container_swap`, se aquele tipo for bem formado, caso contrário, será `false_type`. Se o tipo for verdadeiro, um contêiner habilitado para alocador trocará seu alocador armazenado em uma troca.|
|`size_type`|Esse tipo será `Alloc::size_type`, se aquele tipo for bem formado, caso contrário, será `make_unsigned<difference_type>::type`.|
|`value_type`|Esse tipo é um sinônimo de `Alloc::value_type`.|
|`void_pointer`|Esse tipo será `Alloc::void_pointer`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::rebind<void>`.|

### <a name="static-methods"></a>Métodos estáticos

Os seguintes métodos estáticos chamam o método correspondente em um parâmetro alocador determinado.

|||
|-|-|
|[allocate](#allocate)|Método estático que aloca memória usando o parâmetro alocador determinado.|
|[construct](#construct)|Método estático que usa um alocador especificado para construir um objeto.|
|[deallocate](#deallocate)|Método estático que usa um alocador especificado para desalocar um número especificado de objetos.|
|[destroy](#destroy)|Método estático que usa um alocador especificado para chamar o destruidor em um objeto sem desalocar sua memória.|
|[max_size](#max_size)|Método estático que usa um alocador especificado para determinar o número máximo de objetos que podem ser alocados.|
|[select_on_container_copy_construction](#select_on_container_copy_construction)|Método estático que chama `select_on_container_copy_construction` no alocador especificado.|

### <a name="allocate"></a>aloca

Método estático que aloca memória usando o parâmetro alocador determinado.

```cpp
static pointer allocate(Alloc& al, size_type count);

static pointer allocate(Alloc& al, size_type count,
    typename allocator_traits<void>::const_pointer* hint);
```

#### <a name="parameters"></a>Parâmetros

*al* \
Um objeto alocador.

*contagem* \
O número de elementos a serem alocados.

\ de *dica*
Um `const_pointer` que pode ajudar o objeto alocador a atender à solicitação de armazenamento, localizando o endereço de um objeto alocado antes da solicitação. Um ponteiro nulo é tratado como nenhuma dica.

#### <a name="return-value"></a>Valor retornado

Cada método retorna um ponteiro para o objeto alocado.

O primeiro método estático retorna `al.allocate(count)`.

O segundo método retornará `al.allocate(count, hint)`, se essa expressão for bem formada, caso contrário, retornará `al.allocate(count)`.

### <a name="construct"></a>construir

Método estático que usa um alocador especificado para construir um objeto.

```cpp
template <class Uty, class Types>
static void construct(Alloc& al, Uty* ptr, Types&&... args);
```

#### <a name="parameters"></a>Parâmetros

*al* \
Um objeto alocador.

\ *PTR*
Um ponteiro para o local no qual o objeto deve ser construído.

*args* \
Uma lista de argumentos que é passada ao construtor de objetos.

#### <a name="remarks"></a>Comentários

A função de membro estática chamará `al.construct(ptr, args...)`, se essa expressão for bem formada, caso contrário, será avaliada como `::new (static_cast<void *>(ptr)) Uty(std::forward<Types>(args)...)`.

### <a name="deallocate"></a>desalocar

Método estático que usa um alocador especificado para desalocar um número especificado de objetos.

```cpp
static void deallocate(Alloc al,
    pointer ptr,
    size_type count);
```

#### <a name="parameters"></a>Parâmetros

*al* \
Um objeto alocador.

\ *PTR*
Um ponteiro para o local inicial dos objetos a serem desalocados.

*contagem* \
O número de objetos a serem desalocados.

#### <a name="remarks"></a>Comentários

Esse método chama `al.deallocate(ptr, count)`.

Esse método não gera nada.

### <a name="destroy"></a>destruir

Método estático que usa um alocador especificado para chamar o destruidor em um objeto sem desalocar sua memória.

```cpp
template <class Uty>
    static void destroy(Alloc& al, Uty* ptr);
```

#### <a name="parameters"></a>Parâmetros

*al* \
Um objeto alocador.

\ *PTR*
Um ponteiro para o local do objeto.

#### <a name="remarks"></a>Comentários

Esse método chamará `al.destroy(ptr)`, se essa expressão for bem formada, caso contrário, será avaliado como `ptr->~Uty()`.

### <a name="max_size"></a>max_size

Método estático que usa um alocador especificado para determinar o número máximo de objetos que podem ser alocados.

```cpp
static size_type max_size(const Alloc& al);
```

#### <a name="parameters"></a>Parâmetros

*al* \
Um objeto alocador.

#### <a name="remarks"></a>Comentários

Esse método retornará `al.max_size()`, se essa expressão for bem formada, caso contrário, retornará `numeric_limits<size_type>::max()`.

### <a name="select_on_container_copy_construction"></a>select_on_container_copy_construction

Método estático que chama `select_on_container_copy_construction` no alocador especificado.

```cpp
static Alloc select_on_container_copy_construction(const Alloc& al);
```

#### <a name="parameters"></a>Parâmetros

*al* \
Um objeto alocador.

#### <a name="return-value"></a>Valor retornado

Esse método retornará `al.select_on_container_copy_construction()`, se esse tipo estiver bem formado; caso contrário, retornará *Al*.

#### <a name="remarks"></a>Comentários

Esse método é usado para especificar um alocador quando o contêiner associado é construído por cópia.
