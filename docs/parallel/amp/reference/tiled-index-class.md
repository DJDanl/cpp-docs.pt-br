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
ms.openlocfilehash: 46a6b3548526f0917c4e022a12bf859242e70b20
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375477"
---
# <a name="tiled_index-class"></a>Classe tiled_index

Fornece um índice em um [objeto tiled_extent.](tiled-extent-class.md) Esta classe possui propriedades de acesso a elementos relativos à origem local da telha e em relação à origem global. Para obter mais informações sobre espaços ladrilhos, consulte [Usando telhas](../../../parallel/amp/using-tiles.md).

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

|Nome|Descrição|
|----------|-----------------|
|[Construtor tiled_index](#ctor)|Inicia uma nova instância da classe `tile_index`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_tile_extent](#tiled_index__get_tile_extent)|Retorna um objeto [de extensão](extent-class.md) que `_Dim0`tem `_Dim1`os `_Dim2`valores dos argumentos do `tiled_index` modelo, e .|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[barreira constante](#tiled_index__barrier)|Armazena um [objeto tile_barrier](tile-barrier-class.md) que representa uma barreira na telha atual dos fios.|
|||
|[Constante global](#tiled_index__global)|Armazena um objeto de [índice](index-class.md) de classificação 1, 2 ou 3 que representa o índice global em um objeto de grade.|
|[Constante local](#tiled_index__local)|Armazena `index` um objeto de classificação 1, 2 ou 3 que representa o índice relativo na telha atual de um objeto [tiled_extent.](tiled-extent-class.md)|
|[classificação Constante](#tiled_index__rank)|Armazena a classificação do `tiled_index` objeto.|
|[Constante de ladrilho](#tiled_index__tile)|Armazena `index` um objeto de classificação 1, 2 ou 3 que representa `tiled_extent` as coordenadas da telha atual de um objeto.|
|[tile_dim0 Constante](#tiled_index__tile_dim0)|Armazena a extensão da dimensão mais significativa.|
|[tile_dim1 Constante](#tiled_index__tile_dim1)|Armazena o comprimento da dimensão mais significativa.|
|[tile_dim2 Constante](#tiled_index__tile_dim2)|Armazena o comprimento da dimensão menos significativa.|
|[tile_origin Constante](#tiled_index__tile_origin)|Armazena `index` um objeto de classificação 1, 2 ou 3 que representa as coordenadas globais da origem da telha atual em um `tiled_extent` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[tile_extent](#tile_extent)|Obtém um objeto [de extensão](extent-class.md) que `tiled_index` tem `_Dim0`os `_Dim1`valores dos argumentos do `tiled_index` modelo de argumentos argumentos, e `_Dim2`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Tiled_index_base`

`tiled_index`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp.h

**Namespace:** Simultaneidade

## <a name="tiled_index-constructor"></a><a name="ctor"></a>Construtor tiled_index

Inicia uma nova instância da classe `tiled_index`.

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
O [índice](index-class.md) local do construído`tiled_index`

*_Tile*<br/>
O [índice](index-class.md) de telhas dos construídos`tiled_index`

*_Tile_origin*<br/>
O [índice](index-class.md) de origem das telhas dos construídos`tiled_index`

*_Barrier*<br/>
O [tile_barrier](tile-barrier-class.md) objeto do `tiled_index`construído.

*_Other*<br/>
O `tile_index` objeto a ser copiado `tiled_index`para o construído .

### <a name="overloads"></a>Sobrecargas

|||
|-|-|
|Nome|Descrição|
|`tiled_index(const index<rank>& _Global, const index<rank>& _Local, const index<rank>& _Tile, const index<rank>& _Tile_origin, const tile_barrier& _Barrier restrict(amp,cpu);`|Inicializa uma nova instância `tile_index` da classe a partir do índice da telha em coordenadas globais e da posição relativa na telha em coordenadas locais. Os `_Global` `_Tile_origin` parâmetros são computados.|
|`tiled_index(    const tiled_index& _Other) restrict(amp,cpu);`|Inicializa uma nova instância `tile_index` da classe copiando `tiled_index` o objeto especificado.|

## <a name="get_tile_extent"></a><a name="tiled_index__get_tile_extent"></a>get_tile_extent

Retorna um objeto [de extensão](extent-class.md) que `_Dim0`tem `_Dim1`os `_Dim2`valores dos argumentos do `tiled_index` modelo, e .

### <a name="syntax"></a>Sintaxe

```cpp
extent<rank> get_tile_extent()restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Um `extent` objeto que tem `tiled_index` os valores dos argumentos `_Dim0`do modelo, `_Dim1`e `_Dim2`.

## <a name="barrier"></a><a name="tiled_index__barrier"></a>Barreira

Armazena um [objeto tile_barrier](tile-barrier-class.md) que representa uma barreira na telha atual dos fios.

### <a name="syntax"></a>Sintaxe

```cpp
const tile_barrier barrier;
```

## <a name="global"></a><a name="tiled_index__global"></a>Global

Armazena um objeto de [índice](index-class.md) de classificação 1, 2 ou 3 que representa o índice global de um objeto.

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> global;
```

## <a name="local"></a><a name="tiled_index__local"></a>Local

Armazena um objeto de [índice](index-class.md) de classificação 1, 2 ou 3 que representa o índice relativo na telha atual de um objeto [tiled_extent.](tiled-extent-class.md)

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> local;
```

## <a name="rank"></a><a name="tiled_index__rank"></a>Rank

Armazena a classificação do `tiled_index` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
static const int rank = _Rank;
```

## <a name="tile"></a><a name="tiled_index__tile"></a>Telha

Armazena um objeto de [índice](index-class.md) de classificação 1, 2 ou 3 que representa as coordenadas da telha atual de um objeto [tiled_extent.](tiled-extent-class.md)

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> tile;
```

## <a name="tile_dim0"></a><a name="tiled_index__tile_dim0"></a>tile_dim0

Armazena a extensão da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim0 = _Dim0;
```

## <a name="tile_dim1"></a><a name="tiled_index__tile_dim1"></a>tile_dim1

Armazena o comprimento da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim1 = _Dim1;
```

## <a name="tile_dim2"></a><a name="tiled_index__tile_dim2"></a>tile_dim2

Armazena o comprimento da dimensão menos significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim2 = _Dim2;
```

## <a name="tile_origin"></a><a name="tiled_index__tile_origin"></a>tile_origin

Armazena um objeto de [índice](index-class.md) de classificação 1, 2 ou 3 que representa as coordenadas globais da origem da telha atual dentro de um objeto [tiled_extent.](tiled-extent-class.md)

### <a name="syntax"></a>Sintaxe

```cpp
const index<rank> tile_origin
```

## <a name="tile_extent"></a><a name="tile_extent"></a>tile_extent

Obtém um objeto [de extensão](extent-class.md) que `tiled_index` tem `_Dim0`os `_Dim1`valores dos argumentos do `tiled_index` modelo de argumentos argumentos, e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_tile_extent)) extent<rank> tile_extent;
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
