---
title: Classe tiled_index
ms.date: 03/27/2019
f1_keywords:
- tiled_index
- AMP/tiled_index
- AMP/Concurrency::tiled_index::tiled_index
- AMP/Concurrency::tiled_index::get_tile_extent
- AMP/Concurrency::tiled_index::barrier
- AMP/Concurrency::tiled_index::global
- AMP/Concurrency::tiled_index::local
- AMP/Concurrency::tiled_index::rank
- AMP/Concurrency::tiled_index::tile
- AMP/Concurrency::tiled_index::tile_dim0
- AMP/Concurrency::tiled_index::tile_dim1
- AMP/Concurrency::tiled_index::tile_dim2
- AMP/Concurrency::tiled_index::tile_origin
- AMP/Concurrency::tiled_index::tile_extent
helpviewer_keywords:
- tiled_index class
ms.assetid: 0ce2ae26-f1bb-4436-b473-a9e1b619bb38
ms.openlocfilehash: eda01667a6b239284c682ba6ae3f9b857c713447
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142419"
---
# <a name="tiled_index-class"></a>Classe tiled_index

Fornece um índice em um objeto [tiled_extent](tiled-extent-class.md) . Essa classe tem propriedades para acessar elementos relativos à origem do bloco local e em relação à origem global. Para obter mais informações sobre espaços em ladrilhos, consulte [usando blocos](../../../parallel/amp/using-tiles.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <
    int _Dim0,
    int _Dim1 = 0,
    int _Dim2 = 0
>
class tiled_index : public _Tiled_index_base<3>;

template <
    int _Dim0,
    int _Dim1
>
class tiled_index<_Dim0, _Dim1, 0> : public _Tiled_index_base<2>;

template <
    int _Dim0
>
class tiled_index<_Dim0, 0, 0> : public _Tiled_index_base<1>;
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
|[Construtor de tiled_index](#ctor)|Inicializa uma nova instância da classe `tile_index`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_tile_extent](#tiled_index__get_tile_extent)|Retorna um objeto de [extensão](extent-class.md) que tem os valores dos argumentos do modelo de `tiled_index` `_Dim0`, `_Dim1`e `_Dim2`.|

### <a name="public-constants"></a>Constantes Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante de barreira](#tiled_index__barrier)|Armazena um objeto [tile_barrier](tile-barrier-class.md) que representa uma barreira no bloco atual de threads.|
|||
|[Constante global](#tiled_index__global)|Armazena um objeto de [índice](index-class.md) da classificação 1, 2 ou 3 que representa o índice global em um objeto de grade.|
|[Constante local](#tiled_index__local)|Armazena um objeto `index` da classificação 1, 2 ou 3 que representa o índice relativo no bloco atual de um objeto [tiled_extent](tiled-extent-class.md) .|
|[Constante de classificação](#tiled_index__rank)|Armazena a classificação do objeto `tiled_index`.|
|[Constante de bloco](#tiled_index__tile)|Armazena um objeto `index` da classificação 1, 2 ou 3 que representa as coordenadas do bloco atual de um objeto `tiled_extent`.|
|[Constante tile_dim0](#tiled_index__tile_dim0)|Armazena o comprimento da dimensão mais significativa.|
|[Constante tile_dim1](#tiled_index__tile_dim1)|Armazena o comprimento da dimensão de próximo a mais significativa.|
|[Constante tile_dim2](#tiled_index__tile_dim2)|Armazena o comprimento da dimensão menos significativa.|
|[Constante tile_origin](#tiled_index__tile_origin)|Armazena um objeto `index` da classificação 1, 2 ou 3 que representa as coordenadas globais da origem do bloco atual em um objeto `tiled_extent`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[tile_extent](#tile_extent)|Obtém um objeto de [extensão](extent-class.md) que tem os valores dos argumentos do modelo de `tiled_index` `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`e `_Dim2`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Tiled_index_base`

`tiled_index`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="ctor"></a>Construtor de tiled_index

Inicializa uma nova instância da classe `tiled_index`.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_index(
    const index<rank>& _Global,
    const index<rank>& _Local,
    const index<rank>& _Tile,
    const index<rank>& _Tile_origin,
    const tile_barrier& _Barrier ) restrict(amp,cpu);

tiled_index(
    const tiled_index& _Other ) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Global*<br/>
O [índice](index-class.md) global do `tiled_index`construído.

*_Local*<br/>
O [índice](index-class.md) local do `tiled_index` construído

*_Tile*<br/>
O [índice](index-class.md) de bloco do `tiled_index` construído

*_Tile_origin*<br/>
O [índice](index-class.md) de origem do bloco do `tiled_index` construído

*_Barrier*<br/>
O objeto [tile_barrier](tile-barrier-class.md) do `tiled_index`construído.

*_Other*<br/>
O objeto `tile_index` a ser copiado para o `tiled_index`construído.

### <a name="overloads"></a>Sobrecargas

|||
|-|-|
|{1&gt;Nome&lt;1}|Descrição|
|`tiled_index(const index<rank>& _Global, const index<rank>& _Local, const index<rank>& _Tile, const index<rank>& _Tile_origin, const tile_barrier& _Barrier restrict(amp,cpu);`|Inicializa uma nova instância da classe `tile_index` do índice do bloco em coordenadas globais e a posição relativa no bloco em coordenadas locais. Os parâmetros `_Global` e `_Tile_origin` são computados.|
|`tiled_index(    const tiled_index& _Other) restrict(amp,cpu);`|Inicializa uma nova instância da classe `tile_index` copiando o objeto de `tiled_index` especificado.|

## <a name="tiled_index__get_tile_extent"></a>get_tile_extent

Retorna um objeto de [extensão](extent-class.md) que tem os valores dos argumentos do modelo de `tiled_index` `_Dim0`, `_Dim1`e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
extent<rank> get_tile_extent()restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Um objeto `extent` que tem os valores dos argumentos do modelo `tiled_index` `_Dim0`, `_Dim1`e `_Dim2`.

## <a name="tiled_index__barrier"></a>obstáculo

Armazena um objeto [tile_barrier](tile-barrier-class.md) que representa uma barreira no bloco atual de threads.

### <a name="syntax"></a>Sintaxe

```cpp
const tile_barrier barrier;
```

## <a name="tiled_index__global"></a>geral

Armazena um objeto de [índice](index-class.md) da classificação 1, 2 ou 3 que representa o índice global de um objeto.

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> global;
```

## <a name="tiled_index__local"></a>local

Armazena um objeto de [índice](index-class.md) da classificação 1, 2 ou 3 que representa o índice relativo no bloco atual de um objeto de [tiled_extent](tiled-extent-class.md) .

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> local;
```

## <a name="tiled_index__rank"></a>Fique

Armazena a classificação do objeto `tiled_index`.

### <a name="syntax"></a>Sintaxe

```cpp
static const int rank = _Rank;
```

## <a name="tiled_index__tile"></a>bloco

Armazena um objeto de [índice](index-class.md) da classificação 1, 2 ou 3 que representa as coordenadas do bloco atual de um objeto de [tiled_extent](tiled-extent-class.md) .

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> tile;
```

## <a name="tiled_index__tile_dim0"></a>tile_dim0

Armazena o comprimento da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim0 = _Dim0;
```

## <a name="tiled_index__tile_dim1"></a>tile_dim1

Armazena o comprimento da dimensão de próximo a mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim1 = _Dim1;
```

## <a name="tiled_index__tile_dim2"></a>tile_dim2

Armazena o comprimento da dimensão menos significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim2 = _Dim2;
```

## <a name="tiled_index__tile_origin"></a>tile_origin

Armazena um objeto de [índice](index-class.md) da classificação 1, 2 ou 3 que representa as coordenadas globais da origem do bloco atual dentro de um objeto de [tiled_extent](tiled-extent-class.md) .

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> tile_origin
```

## <a name="tile_extent"></a>tile_extent

Obtém um objeto de [extensão](extent-class.md) que tem os valores dos argumentos do modelo de `tiled_index` `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_tile_extent)) extent<rank> tile_extent;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
