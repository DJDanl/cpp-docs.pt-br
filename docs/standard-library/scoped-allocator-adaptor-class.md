---
title: Classe scoped_allocator_adaptor
ms.date: 11/04/2016
f1_keywords:
- scoped_allocator/std::scoped_allocator_adaptor
- scoped_allocator/std::scoped_allocator_adaptor::rebind Struct
- scoped_allocator/std::scoped_allocator_adaptor::allocate
- scoped_allocator/std::scoped_allocator_adaptor::construct
- scoped_allocator/std::scoped_allocator_adaptor::deallocate
- scoped_allocator/std::scoped_allocator_adaptor::destroy
- scoped_allocator/std::scoped_allocator_adaptor::inner_allocator
- scoped_allocator/std::scoped_allocator_adaptor::max_size
- scoped_allocator/std::scoped_allocator_adaptor::outer_allocator
- scoped_allocator/std::scoped_allocator_adaptor::select_on_container_copy_construction
helpviewer_keywords:
- std::scoped_allocator_adaptor
- std::scoped_allocator_adaptor::allocate
- std::scoped_allocator_adaptor::construct
- std::scoped_allocator_adaptor::deallocate
- std::scoped_allocator_adaptor::destroy
- std::scoped_allocator_adaptor::inner_allocator
- std::scoped_allocator_adaptor::max_size
- std::scoped_allocator_adaptor::outer_allocator
- std::scoped_allocator_adaptor::select_on_container_copy_construction
ms.assetid: 0d9b06a1-9a4a-4669-9470-8805cae48e89
ms.openlocfilehash: b08cf1858cb0f9bf4dc6201edc2502d48754ff77
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373391"
---
# <a name="scoped_allocator_adaptor-class"></a>Classe scoped_allocator_adaptor

Representa um aninhamento de alocadores.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Outer, class... Inner>
class scoped_allocator_adaptor;
```

## <a name="remarks"></a>Comentários

O modelo de classe encapsula um ninho de um ou mais alocadores. Cada classe desse tipo tem um alocador mais externo do tipo `outer_allocator_type`, um sinônimo de `Outer`, que é uma base pública do objeto `scoped_allocator_adaptor`. `Outer` é usado para alocar memória para ser usada por um contêiner. Você pode obter uma referência a esse objeto base do alocador chamando `outer_allocator`.

O restante do aninhamento tem tipo `inner_allocator_type`. Um alocador interno é usado para alocar memória para elementos dentro de um contêiner. Você pode obter uma referência para o objeto armazenado desse tipo chamando `inner_allocator`. Se `Inner...` não está vazio, `inner_allocator_type` tem tipo `scoped_allocator_adaptor<Inner...>` e `inner_allocator` designa um objeto de membro. Caso contrário, `inner_allocator_type` tem tipo `scoped_allocator_adaptor<Outer>` e `inner_allocator` designa o objeto inteiro.

O aninhamento se comporta como se tivesse profundidade arbitrária, replicando seu alocador encapsulado mais interno, conforme necessário.

Vários conceitos que não fazem parte da interface visível ajudam a descrever o comportamento deste modelo de classe. Um *alocador mais externo* media todas as chamadas para os métodos construct e destroy. Ele é definido efetivamente pela função recursiva `OUTERMOST(X)`, em que `OUTERMOST(X)` é um dos seguintes.

- Se `X.outer_allocator()` for bem formado, `OUTERMOST(X)` será `OUTERMOST(X.outer_allocator())`.

- Caso contrário, `OUTERMOST(X)` é `X`.

Três tipos são definidos para fins de exposição:

|Type|Descrição|
|----------|-----------------|
|`Outermost`|O tipo de `OUTERMOST(*this)`.|
|`Outermost_traits`|`allocator_traits<Outermost>`|
|`Outer_traits`|`allocator_traits<Outer>`|

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|----------|-----------------|
|[scoped_allocator_adaptor](#scoped_allocator_adaptor)|Constrói um objeto `scoped_allocator_adaptor`.|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`const_pointer`|Esse tipo é um sinônimo do `const_pointer` que está associado com o alocador `Outer`.|
|`const_void_pointer`|Esse tipo é um sinônimo do `const_void_pointer` que está associado com o alocador `Outer`.|
|`difference_type`|Esse tipo é um sinônimo do `difference_type` que está associado com o alocador `Outer`.|
|`inner_allocator_type`|Esse tipo é um sinônimo do tipo do adaptador aninhado `scoped_allocator_adaptor<Inner...>`.|
|`outer_allocator_type`|Esse tipo é um sinônimo do tipo do alocador base `Outer`.|
|`pointer`|Esse tipo é um sinônimo do `pointer` associado com o alocador `Outer`.|
|`propagate_on_container_copy_assignment`|O tipo é true somente se `Outer_traits::propagate_on_container_copy_assignment` for true ou `inner_allocator_type::propagate_on_container_copy_assignment` for true.|
|`propagate_on_container_move_assignment`|O tipo é true somente se `Outer_traits::propagate_on_container_move_assignment` for true ou `inner_allocator_type::propagate_on_container_move_assignment` for true.|
|`propagate_on_container_swap`|O tipo é true somente se `Outer_traits::propagate_on_container_swap` for true ou `inner_allocator_type::propagate_on_container_swap` for true.|
|`size_type`|Esse tipo é um sinônimo do `size_type` associado com o alocador `Outer`.|
|`value_type`|Esse tipo é um sinônimo do `value_type` associado com o alocador `Outer`.|
|`void_pointer`|Esse tipo é um sinônimo do `void_pointer` associado com o alocador `Outer`.|

### <a name="structs"></a>Structs

|Nome|Descrição|
|----------|-----------------|
|[scoped_allocator_adaptor::religar struct](#rebind_struct)|Define o tipo `Outer::rebind\<Other>::other` como um sinônimo de `scoped_allocator_adaptor\<Other, Inner...>`.|

### <a name="methods"></a>Métodos

|Nome|Descrição|
|----------|-----------------|
|[Alocar](#allocate)|Aloca memória usando o alocador `Outer`.|
|[construct](#construct)|Cria um objeto.|
|[Desalocar](#deallocate)|Desaloca objetos usando o alocador externo.|
|[Destruir](#destroy)|Destrói um objeto especificado.|
|[inner_allocator](#inner_allocator)|Recupera uma referência ao objeto armazenado do tipo `inner_allocator_type`.|
|[Max_size](#max_size)|Determina o número máximo de objetos que podem ser alocados pelo alocador externo.|
|[outer_allocator](#outer_allocator)|Recupera uma referência ao objeto armazenado do tipo `outer_allocator_type`.|
|[select_on_container_copy_construction](#select_on_container_copy_construction)|Cria um novo objeto `scoped_allocator_adaptor` com cada objeto de alocador armazenado inicializado, por meio da chamada de `select_on_container_copy_construction` para cada alocador correspondente.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_as)||
|[operador==](#op_eq_eq)||
|[operador!=](#op_noeq)||

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<scoped_allocator>

**Namespace:** std

## <a name="scoped_allocator_adaptorallocate"></a><a name="allocate"></a>scoped_allocator_adaptor:alocar

Aloca memória usando o alocador `Outer`.

```cpp
pointer allocate(size_type count);pointer allocate(size_type count, const_void_pointer hint);
```

### <a name="parameters"></a>Parâmetros

*Contar*\
O número de elementos para os quais um armazenamento suficiente deve ser alocado.

*Dica*\
Um ponteiro que pode ajudar o objeto alocador localizando o endereço de um objeto alocado antes da solicitação.

### <a name="return-value"></a>Valor retornado

A primeira função membro retorna `Outer_traits::allocate(outer_allocator(), count)`. A segunda função membro retorna `Outer_traits::allocate(outer_allocator(), count, hint)`.

## <a name="scoped_allocator_adaptorconstruct"></a><a name="construct"></a>scoped_allocator_adaptor::construir

Cria um objeto.

```cpp
template <class Ty, class... Atypes>
void construct(Ty* ptr, Atypes&&... args);

template <class Ty1, class Ty2, class... Atypes1, class... Atypes2>
void construct(pair<Ty1, Ty2>* ptr, piecewise_construct_t,
    tuple<Atypes1&&...>
first, tuple<Atypes1&&...> second);

template <class Ty1, class Ty2>
void construct(pair<Ty1, Ty2>* ptr);

template <class Ty1, class Ty2, class Uy1, class Uy2>
void construct(pair<Ty1, Ty2>* ptr,
    class Uy1&& first, class Uy2&& second);

template <class Ty1, class Ty2, class Uy1, class Uy2>
void construct(pair<Ty1, Ty2>* ptr, const pair<Uy1, Uy2>& right);

template <class Ty1, class Ty2, class Uy1, class Uy2>
void construct(pair<Ty1, Ty2>* ptr, pair<Uy1, Uy2>&& right);
```

### <a name="parameters"></a>Parâmetros

*Ptr*\
Um ponteiro para o local da memória em que o objeto deve ser criado.

*Args*\
Uma lista de argumentos.

*Primeiro*\
Um objeto do primeiro tipo em um par.

*Segundo*\
Um objeto do segundo tipo em um par.

*Certo*\
Um objeto existente a ser movido ou copiado.

### <a name="remarks"></a>Comentários

O primeiro método constrói o objeto `Outermost_traits::construct(OUTERMOST(*this), ptr, xargs...)`em `xargs...` *ptr* chamando , onde está um dos seguintes.

- Se `uses_allocator<Ty, inner_allocator_type>` contém false, `xargs...` é `args...`.

- Se `uses_allocator<Ty, inner_allocator_type>` for true e `is_constructible<Ty, allocator_arg_t, inner_allocator_type, args...>` for true, então `xargs...` será `allocator_arg, inner_allocator(), args...`.

- Se `uses_allocator<Ty, inner_allocator_type>` for true e `is_constructible<Ty, args..., inner_allocator()>` for true, então `xargs...` será `args..., inner_allocator()`.

O segundo método constrói o objeto de `Outermost_traits::construct(OUTERMOST(*this), &ptr->first, xargs...)`par `xargs...` `first...` em *ptr,* chamando `Outermost_traits::construct(OUTERMOST(*this), &ptr->second, xargs...)`, onde é modificado como na lista acima, e , onde `xargs...` é `second...` modificado como na lista acima.

O terceiro método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, tuple<>, tuple<>)`.

O quarto método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, forward_as_tuple(std::forward<Uy1>(first), forward_as_tuple(std::forward<Uy2>(second))`.

O quinto método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, forward_as_tuple(right.first), forward_as_tuple(right.second))`.

O sexto método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, forward_as_tuple(std::forward<Uy1>(right.first), forward_as_tuple(std::forward<Uy2>(right.second))`.

## <a name="scoped_allocator_adaptordeallocate"></a><a name="deallocate"></a>scoped_allocator_adaptor::deallocate

Desaloca objetos usando o alocador externo.

```cpp
void deallocate(pointer ptr, size_type count);
```

### <a name="parameters"></a>Parâmetros

*Ptr*\
Um ponteiro para o local inicial dos objetos a serem desalocados.

*Contar*\
O número de objetos a serem desalocados.

## <a name="scoped_allocator_adaptordestroy"></a><a name="destroy"></a>scoped_allocator_adaptor::destroy

Destrói um objeto especificado.

```cpp
template <class Ty>
void destroy(Ty* ptr)
```

### <a name="parameters"></a>Parâmetros

*Ptr*\
Um ponteiro para o objeto a ser destruído.

### <a name="return-value"></a>Valor retornado

`Outermost_traits::destroy(OUTERMOST(*this), ptr)`

## <a name="scoped_allocator_adaptorinner_allocator"></a><a name="inner_allocator"></a>scoped_allocator_adaptor:inner_allocator

Recupera uma referência ao objeto armazenado do tipo `inner_allocator_type`.

```cpp
inner_allocator_type& inner_allocator() noexcept;
const inner_allocator_type& inner_allocator() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto armazenado do tipo `inner_allocator_type`.

## <a name="scoped_allocator_adaptormax_size"></a><a name="max_size"></a>scoped_allocator_adaptor:max_size

Determina o número máximo de objetos que podem ser alocados pelo alocador externo.

```cpp
size_type max_size();
```

### <a name="return-value"></a>Valor retornado

`Outer_traits::max_size(outer_allocator())`

## <a name="a-nameop_as--scoped_allocator_adaptoroperator"></a><a name="op_as">scoped_allocator_adaptor:operador=

```cpp
scoped_allocator_adaptor& operator=(const scoped_allocator_adaptor&) = default;
scoped_allocator_adaptor& operator=(scoped_allocator_adaptor&&) = default;
```

## <a name="a-nameop_eq_eq--scoped_allocator_adaptoroperator"></a><a name="op_eq_eq">scoped_allocator_adaptor:operador==

```cpp
template <class OuterA1, class OuterA2, class... InnerAllocs>
bool operator==(const scoped_allocator_adaptor<OuterA1, InnerAllocs...>& a,
const scoped_allocator_adaptor<OuterA2, InnerAllocs...>& b) noexcept;
```

## <a name="a-nameop_noeq--scoped_allocator_adaptoroperator"></a><a name="op_noeq">scoped_allocator_adaptor::operador!=

```cpp
template <class OuterA1, class OuterA2, class... InnerAllocs>
bool operator!=(const scoped_allocator_adaptor<OuterA1, InnerAllocs...>& a,
const scoped_allocator_adaptor<OuterA2, InnerAllocs...>& b) noexcept;
```

## <a name="scoped_allocator_adaptorouter_allocator"></a><a name="outer_allocator"></a>scoped_allocator_adaptor:outer_allocator

Recupera uma referência ao objeto armazenado do tipo `outer_allocator_type`.

```cpp
outer_allocator_type& outer_allocator() noexcept;
const outer_allocator_type& outer_allocator() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto armazenado do tipo `outer_allocator_type`.

## <a name="scoped_allocator_adaptorrebind-struct"></a><a name="rebind_struct"></a>scoped_allocator_adaptor::religar struct

Define o tipo `Outer::rebind\<Other>::other` como um sinônimo de `scoped_allocator_adaptor\<Other, Inner...>`.

religar struct{ typedef Other_traits::religar\<Outras>\<Other_alloc; typedef scoped_allocator_adaptor Other_alloc, Inner...> outro; };

## <a name="scoped_allocator_adaptorscoped_allocator_adaptor-constructor"></a><a name="scoped_allocator_adaptor"></a>scoped_allocator_adaptor:scoped_allocator_adaptor Construtor

Constrói um objeto `scoped_allocator_adaptor`. Também inclui um destruidor.

```cpp
scoped_allocator_adaptor();

scoped_allocator_adaptor(const scoped_allocator_adaptor& right) noexcept;
template <class Outer2>
scoped_allocator_adaptor(
const scoped_allocator_adaptor<Outer2, Inner...>& right) noexcept;
template <class Outer2>
scoped_allocator_adaptor(
scoped_allocator_adaptor<Outer2, Inner...>&& right) noexcept;
template <class Outer2>
scoped_allocator_adaptor(Outer2&& al,
    const Inner&... rest) noexcept;

~scoped_allocator_adaptor();
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Um `scoped_allocator_adaptor` existente.

*Al*\
Um alocador existente a ser usado como o alocador externo.

*Resto*\
Um alocador existente a ser usado como os alocadores internos.

### <a name="remarks"></a>Comentários

O primeiro padrão de construtor cria seus objetos de alocador armazenado. Cada um dos três construtores seguintes constrói seus objetos alocadores armazenados a partir dos objetos correspondentes à *direita*. O último construtor cria seus objetos de alocador armazenado dos argumentos correspondentes na lista de argumentos.

## <a name="scoped_allocator_adaptorselect_on_container_copy_construction"></a><a name="select_on_container_copy_construction"></a>scoped_allocator_adaptor:select_on_container_copy_construction

Cria um novo objeto `scoped_allocator_adaptor` com cada objeto de alocador armazenado inicializado, por meio da chamada de `select_on_container_copy_construction` para cada alocador correspondente.

```cpp
scoped_allocator_adaptor select_on_container_copy_construction();
```

### <a name="return-value"></a>Valor retornado

Esse método retorna efetivamente `scoped_allocator_adaptor(Outer_traits::select_on_container_copy_construction(*this), inner_allocator().select_on_container_copy_construction())`. O resultado é `scoped_allocator_adaptor` um novo objeto com cada objeto `al.select_on_container_copy_construction()` alocador armazenado inicializado, chamando para o alocador correspondente *al*.

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
