---
title: Classe tiled_extent
ms.date: 11/04/2016
f1_keywords:
- tiled_extent
- AMP/tiled_extent
- AMP/Concurrency::tiled_extent::tiled_extent
- AMP/Concurrency::tiled_extent::get_tile_extent
- AMP/Concurrency::tiled_extent::pad
- AMP/Concurrency::tiled_extent::truncate
- AMP/Concurrency::tiled_extent::tile_dim0
- AMP/Concurrency::tiled_extent::tile_dim1
- AMP/Concurrency::tiled_extent::tile_dim2
- AMP/Concurrency::tiled_extent::tile_extent
ms.assetid: 671ecaf8-c7b0-4ac8-bbdc-e30bd92da7c0
ms.openlocfilehash: e2248c770c7eedde59d1cb592f7d5d7c1bfbde9a
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126416"
---
# <a name="tiled_extent-class"></a>Classe tiled_extent

Um objeto de `tiled_extent` é um objeto de `extent` de uma a três dimensões que subdivide o espaço de extensão em blocos de um, dois ou três-dimensional.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    int _Dim0,
    int _Dim1,
    int _Dim2
>
class tiled_extent : public Concurrency::extent<3>;

template <
    int _Dim0,
    int _Dim1
>
class tiled_extent<_Dim0, _Dim1, 0> : public Concurrency::extent<2>;

template <
    int _Dim0
>
class tiled_extent<_Dim0, 0, 0> : public Concurrency::extent<1>;
```

### <a name="parameters"></a>Parâmetros

*_Dim0*<br/>
O comprimento da dimensão mais significativa.

*_Dim1*<br/>
O comprimento da dimensão mais significativa.

*_Dim2*<br/>
O comprimento da dimensão menos significativa.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de tiled_extent](#ctor)|Inicializa uma nova instância da classe `tiled_extent`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_tile_extent](#get_tile_extent)|Retorna um objeto `extent` que captura os valores dos argumentos do modelo `tiled_extent` `_Dim0`, `_Dim1`e `_Dim2`.|
|[bloco](#pad)|Retorna um novo objeto `tiled_extent` com extensões ajustadas para que sejam divisíveis igualmente pelas dimensões do bloco.|
|[truncate](#truncate)|Retorna um novo objeto `tiled_extent` com extensões ajustadas para que sejam divisíveis igualmente pelas dimensões do bloco.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Copia o conteúdo do objeto `tiled_index` especificado para este.|

### <a name="public-constants"></a>Constantes Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante tile_dim0](#tile_dim0)|Armazena o comprimento da dimensão mais significativa.|
|[Constante tile_dim1](#tile_dim1)|Armazena o comprimento da dimensão de próximo a mais significativa.|
|[Constante tile_dim2](#tile_dim2)|Armazena o comprimento da dimensão menos significativa.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[tile_extent](#tile_extent)|Obtém um objeto `extent` que captura os valores dos argumentos do modelo `tiled_extent` `_Dim0`, `_Dim1`e `_Dim2`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`extent`

`tiled_extent`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="ctor"></a> construtor de tiled_extent

Inicializa uma nova instância da classe `tiled_extent`.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent();

tiled_extent(
    const Concurrency::extent<rank>& _Other );

tiled_extent(
    const tiled_extent& _Other );
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `extent` ou `tiled_extent` objeto a ser copiado.

## <a name="get_tile_extent"></a> get_tile_extent

Retorna um objeto `extent` que captura os valores dos argumentos do modelo `tiled_extent` `_Dim0`, `_Dim1`e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
Concurrency::extent<rank> get_tile_extent() const restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Um objeto `extent` que captura as dimensões desta instância de `tiled_extent`.

## <a name="pad"></a> painel

Retorna um novo objeto `tiled_extent` com extensões ajustadas para que sejam divisíveis igualmente pelas dimensões do bloco.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent pad() const;
```

### <a name="return-value"></a>Valor retornado

O novo objeto `tiled_extent`, por valor.
## <a name="truncate"></a> truncar

Retorna um novo objeto `tiled_extent` com extensões ajustadas para que sejam divisíveis igualmente pelas dimensões do bloco.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent truncate() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um novo objeto `tiled_extent` com extensões ajustadas para que sejam divisíveis igualmente pelas dimensões do bloco.

## <a name="operator_eq"></a> operador =

Copia o conteúdo do objeto `tiled_index` especificado para este.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent&  operator= (
    const tiled_extent& _Other ) restrict (amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `tiled_index` do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a esta instância de `tiled_index`.

## <a name="tile_dim0"></a> tile_dim0

Armazena o comprimento da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim0 = _Dim0;
```

## <a name="tile_dim1"></a> tile_dim1

Armazena o comprimento da dimensão de próximo a mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim1 = _Dim1;
```

## <a name="tile_dim2"></a> tile_dim2

Armazena o comprimento da dimensão menos significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim2 = _Dim2;
```

## <a name="tile_extent"></a> tile_extent
  Obtém um objeto `extent` que captura os valores dos argumentos do modelo `tiled_extent` `_Dim0`, `_Dim1`e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_tile_extent)) Concurrency::extent<rank> tile_extent;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
