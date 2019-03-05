---
title: Classe tiled_index
ms.date: 11/04/2016
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
ms.openlocfilehash: cea1ac1d500a9cf3bcbdc1f5dde33a0002cbd363
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57257898"
---
# <a name="tiledindex-class"></a>Classe tiled_index

Fornece um índice em uma [tiled_extent](tiled-extent-class.md) objeto. Essa classe possui propriedades para acessar elementos relativa à origem do bloco local e relativo à origem global. Para obter mais informações sobre espaços lado a lado, consulte [blocos usando](../../../parallel/amp/using-tiles.md).

## <a name="syntax"></a>Sintaxe

```
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

#### <a name="parameters"></a>Parâmetros

*_Dim0*<br/>
O comprimento da dimensão mais significativa.

*_Dim1*<br/>
O comprimento da dimensão Avançar mais significativa.

*_Dim2*<br/>
O comprimento da dimensão menos significativa.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de tiled_index](#ctor)|Inicializa uma nova instância da classe `tile_index`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_tile_extent](#tiled_index__get_tile_extent)|Retorna um [extent](extent-class.md) objeto que tem os valores da `tiled_index` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[barreira constante](#tiled_index__barrier)|Armazena uma [tile_barrier](tile-barrier-class.md) objeto que representa uma barreira no quadro atual de threads.|
|||
|[Constante global](#tiled_index__global)|Armazena uma [índice](index-class.md) objeto de classificação 1, 2 ou 3 que representa o índice global em um objeto de grade.|
|[Constante local](#tiled_index__local)|Armazena uma `index` objeto de índice de classificação 1, 2 ou 3 que representa a relativa no quadro atual de um [tiled_extent](tiled-extent-class.md) objeto.|
|[Constante de classificação](#tiled_index__rank)|Armazena a classificação do `tiled_index` objeto.|
|[Constante Tile](#tiled_index__tile)|Armazena uma `index` objeto de classificação 1, 2 ou 3 que representa as coordenadas do quadro atual de um `tiled_extent` objeto.|
|[Constante tile_dim0](#tiled_index__tile_dim0)|Armazena o comprimento da dimensão mais significativa.|
|[Constante tile_dim1](#tiled_index__tile_dim1)|Armazena o comprimento da dimensão Avançar mais significativa.|
|[Constante tile_dim2](#tiled_index__tile_dim2)|Armazena o comprimento da dimensão menos significativa.|
|[tile_origin constante](#tiled_index__tile_origin)|Armazena uma `index` objeto das coordenadas de classificação 1, 2 ou 3 que representa o global da origem do quadro atual em um `tiled_extent` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[tile_extent](#tile_extent)|Obtém uma [extent](extent-class.md) objeto que tem os valores da `tiled_index` argumentos do modelo `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Tiled_index_base`

`tiled_index`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Concorrência

## <a name="tiled_index__ctor"></a>  Construtor de tiled_index

Inicializa uma nova instância da classe `tiled_index`.

## <a name="syntax"></a>Sintaxe

```
tiled_index(
    const index<rank>& _Global,
    const index<rank>& _Local,
    const index<rank>& _Tile,
    const index<rank>& _Tile_origin,
    const tile_barrier& _Barrier ) restrict(amp,cpu);

tiled_index(
    const tiled_index& _Other ) restrict(amp,cpu);
```

#### <a name="parameters"></a>Parâmetros

*_Global*<br/>
Global [índice](index-class.md) de construído `tiled_index`.

*_Local*<br/>
O local [índice](index-class.md) de construído `tiled_index`

*_Tile*<br/>
O bloco [índice](index-class.md) de construído `tiled_index`

*_Tile_origin*<br/>
A origem do bloco [índice](index-class.md) de construído `tiled_index`

*_Barrier*<br/>
O [tile_barrier](tile-barrier-class.md) objeto de construído `tiled_index`.

*_Other*<br/>
O `tile_index` objeto a ser copiado para construído `tiled_index`.

## <a name="overloads"></a>Sobrecargas

|||
|-|-|
|Nome|Descrição|
|`tiled_index(const index<rank>& _Global, const index<rank>& _Local, const index<rank>& _Tile, const index<rank>& _Tile_origin, const tile_barrier& _Barrier restrict(amp,cpu);`|Inicializa uma nova instância do `tile_index` classe do índice de bloco em coordenadas globais e a posição relativa no quadro em coordenadas locais. O `_Global` e `_Tile_origin` parâmetros são computados.|
|`tiled_index(    const tiled_index& _Other) restrict(amp,cpu);`|Inicializa uma nova instância dos `tile_index` classe copiando especificado `tiled_index` objeto.|

## <a name="tiled_index__get_tile_extent"></a>  get_tile_extent

Retorna um [extent](extent-class.md) objeto que tem os valores da `tiled_index` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.

## <a name="syntax"></a>Sintaxe

```
extent<rank> get_tile_extent()restrict(amp,cpu);
```

## <a name="return-value"></a>Valor de retorno

Uma `extent` objeto que tem os valores da `tiled_index` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.

## <a name="tiled_index__barrier"></a>  barrier

Armazena uma [tile_barrier](tile-barrier-class.md) objeto que representa uma barreira no quadro atual de threads.

## <a name="syntax"></a>Sintaxe

```
const tile_barrier barrier;
```

## <a name="tiled_index__global"></a>  global

Armazena uma [índice](index-class.md) objeto de classificação 1, 2 ou 3 que representa o índice global de um objeto.

## <a name="syntax"></a>Sintaxe

```
const index<rank> global;
```

## <a name="tiled_index__local"></a>  local

Armazena uma [índice](index-class.md) objeto de índice de classificação 1, 2 ou 3 que representa a relativa no quadro atual de um [tiled_extent](tiled-extent-class.md) objeto.

## <a name="syntax"></a>Sintaxe

```
const index<rank> local;
```

## <a name="tiled_index__rank"></a>  classificação

Armazena a classificação do `tiled_index` objeto.

## <a name="syntax"></a>Sintaxe

```
static const int rank = _Rank;
```

## <a name="tiled_index__tile"></a>  tile

Armazena uma [índice](index-class.md) objeto de classificação 1, 2 ou 3 que representa as coordenadas do quadro atual de um [tiled_extent](tiled-extent-class.md) objeto.

## <a name="syntax"></a>Sintaxe

```
const index<rank> tile;
```

## <a name="tiled_index__tile_dim0"></a>  tile_dim0

Armazena o comprimento da dimensão mais significativa.

## <a name="syntax"></a>Sintaxe

```
static const int tile_dim0 = _Dim0;
```

## <a name="tiled_index__tile_dim1"></a>  tile_dim1

Armazena o comprimento da dimensão Avançar mais significativa.

## <a name="syntax"></a>Sintaxe

```
static const int tile_dim1 = _Dim1;
```

## <a name="tiled_index__tile_dim2"></a>  tile_dim2

Armazena o comprimento da dimensão menos significativa.

## <a name="syntax"></a>Sintaxe

```
static const int tile_dim2 = _Dim2;
```

## <a name="tiled_index__tile_origin"></a>  tile_origin

Armazena uma [índice](index-class.md) objeto das coordenadas de classificação 1, 2 ou 3 que representa o global da origem do quadro atual dentro de uma [tiled_extent](tiled-extent-class.md) objeto.

## <a name="syntax"></a>Sintaxe

```
const index<rank> tile_origin
```

## <a name="tile_extent"></a>  tile_extent
  Obtém uma [extent](extent-class.md) objeto que tem os valores da `tiled_index` argumentos do modelo `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.

## <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_tile_extent)) extent<rank> tile_extent;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
