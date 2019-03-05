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
ms.openlocfilehash: 5244ae5df99b06c77f4eb27317e5829b21fabf24
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274382"
---
# <a name="writeonlytextureview-class"></a>Classe writeonly_texture_view

Fornece acesso somente escrita para uma textura.

## <a name="syntax"></a>Sintaxe

```
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

#### <a name="parameters"></a>Parâmetros

*value_type*<br/>
O tipo dos elementos na textura.

*_Rank*<br/>
A classificação da textura.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`scalar_type`||
|`value_type`|O tipo dos elementos na textura.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de writeonly_texture_view](#ctor)|Inicializa uma nova instância da classe `writeonly_texture_view`.|
|[~ writeonly_texture_view destruidor](#ctor)|Destrói o `writeonly_texture_view` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[set](#set)|Define o valor do elemento no índice especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Copia especificado `writeonly_texture_view` objeto para esse outro.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Obtém a classificação do `writeonly_texture_view` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Texture_base`

`writeonly_texture_view`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Concurrency:: Graphics

##  <a name="dtor"></a> ~writeonly_texture_view

Destrói o `writeonly_texture_view` objeto.

```
~writeonly_texture_view() restrict(amp,cpu);
```

##  <a name="operator_eq"></a> operator=

Copia especificado `writeonly_texture_view` objeto para esse outro.

```
writeonly_texture_view<value_type, _Rank>& operator= (
    const writeonly_texture_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
`writeonly_texture_view` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `writeonly_texture_view` objeto.

##  <a name="rank"></a> classificação

Obtém a classificação do `writeonly_texture_view` objeto.

```
static const int rank = _Rank;
```

##  <a name="set"></a> set

Define o valor do elemento no índice especificado.

```
void set(
    const index<_Rank>& _Index,
    const value_type& value) const restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento.

*value*<br/>
O novo valor do elemento.

##  <a name="ctor"></a> writeonly_texture_view

Inicializa uma nova instância da classe `writeonly_texture_view`.

```
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
A textura que é usada para criar o `writeonly_texture_view`.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
