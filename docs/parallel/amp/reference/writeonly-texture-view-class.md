---
title: Classe writeonly_texture_view
ms.date: 11/04/2016
f1_keywords:
- writeonly_texture_view
- AMP_GRAPHICS/writeonly_texture_view
- AMP_GRAPHICS/Concurrency::graphics::writeonly_texture_view
- AMP_GRAPHICS/Concurrency::graphics::writeonly_texture_view::set
- AMP_GRAPHICS/Concurrency::graphics::rank Constant
ms.assetid: 8d117ad3-0a1c-41ae-b29c-7c95fdd4d04d
ms.openlocfilehash: 8978a548ed246c59d7e7f007f1180685c7343a14
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126234"
---
# <a name="writeonly_texture_view-class"></a>Classe writeonly_texture_view

Fornece acesso de WriteOnly a uma textura.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename value_type,
    int _Rank
>
class writeonly_texture_view;

template <
    typename value_type,
    int _Rank
>
class writeonly_texture_view<value_type, _Rank> : public details::_Texture_base<value_type, _Rank>;
```

### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo dos elementos na textura.

*_Rank*<br/>
A classificação da textura.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`scalar_type`||
|`value_type`|O tipo dos elementos na textura.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de writeonly_texture_view](#ctor)|Inicializa uma nova instância da classe `writeonly_texture_view`.|
|[~ writeonly_texture_view destruidor](#ctor)|Destrói o objeto `writeonly_texture_view`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[set](#set)|Define o valor do elemento no índice especificado.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Copia o objeto `writeonly_texture_view` especificado para este.|

### <a name="public-constants"></a>Constantes Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Obtém a classificação do objeto de `writeonly_texture_view`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Texture_base`

`writeonly_texture_view`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp_graphics. h

**Namespace:** Simultaneidade:: Graphics

## <a name="dtor"></a>~ writeonly_texture_view

Destrói o objeto `writeonly_texture_view`.

```cpp
~writeonly_texture_view() restrict(amp,cpu);
```

## <a name="operator_eq"></a>operador =

Copia o objeto `writeonly_texture_view` especificado para este.

```cpp
writeonly_texture_view<value_type, _Rank>& operator= (
    const writeonly_texture_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
`writeonly_texture_view` objeto do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de `writeonly_texture_view`.

## <a name="rank"></a>Fique

Obtém a classificação do objeto de `writeonly_texture_view`.

```cpp
static const int rank = _Rank;
```

## <a name="set"></a>Definição

Define o valor do elemento no índice especificado.

```cpp
void set(
    const index<_Rank>& _Index,
    const value_type& value) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento.

*value*<br/>
O novo valor do elemento.

## <a name="ctor"></a>writeonly_texture_view

Inicializa uma nova instância da classe `writeonly_texture_view`.

```cpp
writeonly_texture_view(
    texture<value_type,
    _Rank>& _Src) restrict(amp);

writeonly_texture_view(
    const writeonly_texture_view<value_type,
    _Rank>& _Src) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação da textura.

*value_type*<br/>
O tipo dos elementos na textura.

*_Src*<br/>
A textura usada para criar o `writeonly_texture_view`.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
