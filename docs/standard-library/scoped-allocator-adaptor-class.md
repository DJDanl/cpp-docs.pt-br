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
ms.openlocfilehash: c02f5171fac862b6f79e194f5940b0adeb2e93e0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62348205"
---
# <a name="scopedallocatoradaptor-class"></a>Classe scoped_allocator_adaptor

Representa um aninhamento de alocadores.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Outer, class... Inner>
class scoped_allocator_adaptor;
```

## <a name="remarks"></a>Comentários

A classe de modelo encapsula um aninhamento um ou mais alocadores de. Cada classe desse tipo tem um alocador mais externo do tipo `outer_allocator_type`, um sinônimo de `Outer`, que é uma base pública do objeto `scoped_allocator_adaptor`. `Outer` é usado para alocar memória para ser usada por um contêiner. Você pode obter uma referência a esse objeto base do alocador chamando `outer_allocator`.

O restante do aninhamento tem tipo `inner_allocator_type`. Um alocador interno é usado para alocar memória para elementos dentro de um contêiner. Você pode obter uma referência para o objeto armazenado desse tipo chamando `inner_allocator`. Se `Inner...` não está vazio, `inner_allocator_type` tem tipo `scoped_allocator_adaptor<Inner...>` e `inner_allocator` designa um objeto de membro. Caso contrário, `inner_allocator_type` tem tipo `scoped_allocator_adaptor<Outer>` e `inner_allocator` designa o objeto inteiro.

O aninhamento se comporta como se tivesse profundidade arbitrária, replicando seu alocador encapsulado mais interno, conforme necessário.

Vários conceitos que não fazem parte da interface visível ajudam a descrever o comportamento dessa classe de modelo. Um *alocador mais externo* media todas as chamadas para os métodos construct e destroy. Ele é definido efetivamente pela função recursiva `OUTERMOST(X)`, em que `OUTERMOST(X)` é um dos seguintes.

- Se `X.outer_allocator()` for bem formado, `OUTERMOST(X)` será `OUTERMOST(X.outer_allocator())`.

- Caso contrário, `OUTERMOST(X)` é `X`.

Três tipos são definidos para fins de exposição:

|Tipo|Descrição|
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
|[Struct scoped_allocator_adaptor::rebind](#rebind_struct)|Define o tipo `Outer::rebind\<Other>::other` como um sinônimo de `scoped_allocator_adaptor\<Other, Inner...>`.|

### <a name="methods"></a>Métodos

|Nome|Descrição|
|----------|-----------------|
|[allocate](#allocate)|Aloca memória usando o alocador `Outer`.|
|[construct](#construct)|Cria um objeto.|
|[deallocate](#deallocate)|Desaloca objetos usando o alocador externo.|
|[destroy](#destroy)|Destrói um objeto especificado.|
|[inner_allocator](#inner_allocator)|Recupera uma referência ao objeto armazenado do tipo `inner_allocator_type`.|
|[max_size](#max_size)|Determina o número máximo de objetos que podem ser alocados pelo alocador externo.|
|[outer_allocator](#outer_allocator)|Recupera uma referência ao objeto armazenado do tipo `outer_allocator_type`.|
|[select_on_container_copy_construction](#select_on_container_copy_construction)|Cria um novo objeto `scoped_allocator_adaptor` com cada objeto de alocador armazenado inicializado, por meio da chamada de `select_on_container_copy_construction` para cada alocador correspondente.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<scoped_allocator>

**Namespace:** std

## <a name="allocate"></a>  scoped_allocator_adaptor::allocate

Aloca memória usando o alocador `Outer`.

```cpp
pointer allocate(size_type count);pointer allocate(size_type count, const_void_pointer hint);
```

### <a name="parameters"></a>Parâmetros

*count*<br/>
O número de elementos para os quais um armazenamento suficiente deve ser alocado.

*hint*<br/>
Um ponteiro que pode ajudar o objeto alocador localizando o endereço de um objeto alocado antes da solicitação.

### <a name="return-value"></a>Valor de retorno

A primeira função membro retorna `Outer_traits::allocate(outer_allocator(), count)`. A segunda função membro retorna `Outer_traits::allocate(outer_allocator(), count, hint)`.

## <a name="construct"></a>  scoped_allocator_adaptor::construct

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

*ptr*<br/>
Um ponteiro para o local da memória em que o objeto deve ser criado.

*args*<br/>
Uma lista de argumentos.

*first*<br/>
Um objeto do primeiro tipo em um par.

*second*<br/>
Um objeto do segundo tipo em um par.

*right*<br/>
Um objeto existente a ser movido ou copiado.

### <a name="remarks"></a>Comentários

O primeiro método constrói o objeto no *ptr* chamando `Outermost_traits::construct(OUTERMOST(*this), ptr, xargs...)`, onde `xargs...` é um dos seguintes.

- Se `uses_allocator<Ty, inner_allocator_type>` contém false, `xargs...` é `args...`.

- Se `uses_allocator<Ty, inner_allocator_type>` for true e `is_constructible<Ty, allocator_arg_t, inner_allocator_type, args...>` for true, então `xargs...` será `allocator_arg, inner_allocator(), args...`.

- Se `uses_allocator<Ty, inner_allocator_type>` for true e `is_constructible<Ty, args..., inner_allocator()>` for true, então `xargs...` será `args..., inner_allocator()`.

O segundo método constrói o objeto par em *ptr* chamando `Outermost_traits::construct(OUTERMOST(*this), &ptr->first, xargs...)`, onde `xargs...` está `first...` modificado assim como a lista acima, e `Outermost_traits::construct(OUTERMOST(*this), &ptr->second, xargs...)`, onde `xargs...` é `second...` modificado Assim como acontece na lista acima.

O terceiro método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, tuple<>, tuple<>)`.

O quarto método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, forward_as_tuple(std::forward<Uy1>(first), forward_as_tuple(std::forward<Uy2>(second))`.

O quinto método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, forward_as_tuple(right.first), forward_as_tuple(right.second))`.

O sexto método se comporta da mesma maneira que `this->construct(ptr, piecewise_construct, forward_as_tuple(std::forward<Uy1>(right.first), forward_as_tuple(std::forward<Uy2>(right.second))`.

## <a name="deallocate"></a>  scoped_allocator_adaptor::deallocate

Desaloca objetos usando o alocador externo.

```cpp
void deallocate(pointer ptr, size_type count);
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
Um ponteiro para o local inicial dos objetos a serem desalocados.

*count*<br/>
O número de objetos a serem desalocados.

## <a name="destroy"></a>  scoped_allocator_adaptor::destroy

Destrói um objeto especificado.

```cpp
template <class Ty>
void destroy(Ty* ptr)
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
Um ponteiro para o objeto a ser destruído.

### <a name="return-value"></a>Valor de retorno

`Outermost_traits::destroy(OUTERMOST(*this), ptr)`

## <a name="inner_allocator"></a>  scoped_allocator_adaptor::inner_allocator

Recupera uma referência ao objeto armazenado do tipo `inner_allocator_type`.

```cpp
inner_allocator_type& inner_allocator() noexcept;
const inner_allocator_type& inner_allocator() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto armazenado do tipo `inner_allocator_type`.

## <a name="max_size"></a>  scoped_allocator_adaptor::max_size

Determina o número máximo de objetos que podem ser alocados pelo alocador externo.

```cpp
size_type max_size();
```

### <a name="return-value"></a>Valor de retorno

`Outer_traits::max_size(outer_allocator())`

## <a name="outer_allocator"></a>  scoped_allocator_adaptor::outer_allocator

Recupera uma referência ao objeto armazenado do tipo `outer_allocator_type`.

```cpp
outer_allocator_type& outer_allocator() noexcept;
const outer_allocator_type& outer_allocator() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto armazenado do tipo `outer_allocator_type`.

## <a name="rebind_struct"></a> Struct scoped_allocator_adaptor::rebind

Define o tipo `Outer::rebind\<Other>::other` como um sinônimo de `scoped_allocator_adaptor\<Other, Inner...>`.

struct reassociação {typedef Other_traits::rebind\<outros > Other_alloc; typedef scoped_allocator_adaptor\<Other_alloc, Inner... > outros; };

## <a name="scoped_allocator_adaptor"></a> Construtor scoped_allocator_adaptor::scoped_allocator_adaptor

Constrói um objeto `scoped_allocator_adaptor`.

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
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Um `scoped_allocator_adaptor` existente.

*al*<br/>
Um alocador existente a ser usado como o alocador externo.

*rest*<br/>
Um alocador existente a ser usado como os alocadores internos.

### <a name="remarks"></a>Comentários

O primeiro padrão de construtor cria seus objetos de alocador armazenado. Cada um dos próximos três construtores cria seus objetos de alocador armazenado dos objetos correspondentes em *certa*. O último construtor cria seus objetos de alocador armazenado dos argumentos correspondentes na lista de argumentos.

## <a name="select_on_container_copy_construction"></a>  scoped_allocator_adaptor::select_on_container_copy_construction

Cria um novo objeto `scoped_allocator_adaptor` com cada objeto de alocador armazenado inicializado, por meio da chamada de `select_on_container_copy_construction` para cada alocador correspondente.

```cpp
scoped_allocator_adaptor select_on_container_copy_construction();
```

### <a name="return-value"></a>Valor de retorno

Esse método retorna efetivamente `scoped_allocator_adaptor(Outer_traits::select_on_container_copy_construction(*this), inner_allocator().select_on_container_copy_construction())`. O resultado é um novo `scoped_allocator_adaptor` objeto com cada objeto de alocador armazenado inicializado chamando `al.select_on_container_copy_construction()` para o alocador correspondente *al*.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
