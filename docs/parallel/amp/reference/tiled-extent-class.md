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
ms.openlocfilehash: 77d16eefa61fb30614cb6527792014cc8655abe0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476889"
---
# <a name="tiledextent-class"></a>Classe tiled_extent

Um `tiled_extent` objeto é um `extent` objeto de um a três dimensões que subdividem o espaço de extensão em uma, duas ou blocos.

### <a name="syntax"></a>Sintaxe

```
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
O comprimento da dimensão Avançar mais significativa.

*_Dim2*<br/>
O comprimento da dimensão menos significativa.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de tiled_extent](#ctor)|Inicializa uma nova instância da classe `tiled_extent`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_tile_extent](#get_tile_extent)|Retorna um `extent` que captura os valores do objeto de `tiled_extent` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.|
|[pad](#pad)|Retorna um novo `tiled_extent` objeto com as extensões ajustadas para ser igualmente divisível pelas dimensões do bloco.|
|[Truncar](#truncate)|Retorna um novo `tiled_extent` objeto com as extensões ajustadas para baixo para ser igualmente divisível pelas dimensões do bloco.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Copia o conteúdo especificado `tiled_index` esse objeto.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante tile_dim0](#tile_dim0)|Armazena o comprimento da dimensão mais significativa.|
|[Constante tile_dim1](#tile_dim1)|Armazena o comprimento da dimensão Avançar mais significativa.|
|[Constante tile_dim2](#tile_dim2)|Armazena o comprimento da dimensão menos significativa.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[tile_extent](#tile_extent)|Obtém uma `extent` que captura os valores do objeto de `tiled_extent` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`extent`

`tiled_extent`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="ctor"> </a>  Construtor de tiled_extent

Inicializa uma nova instância da classe `tiled_extent`.

### <a name="syntax"></a>Sintaxe

```
tiled_extent();

tiled_extent(
    const Concurrency::extent<rank>& _Other );

tiled_extent(
    const tiled_extent& _Other );
```

### <a name="parameters"></a>Parâmetros

*Outro*<br/>
O `extent` ou `tiled_extent` objeto a ser copiado.

## <a name="get_tile_extent"> </a>  get_tile_extent

Retorna um `extent` que captura os valores do objeto de `tiled_extent` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```
Concurrency::extent<rank> get_tile_extent() const restrict(amp,cpu);
```

### <a name="return-value"></a>Valor de retorno

Uma `extent` objeto que captura as dimensões dessa `tiled_extent` instância.

## <a name="pad"> </a>  pad

Retorna um novo `tiled_extent` objeto com as extensões ajustadas para ser igualmente divisível pelas dimensões do bloco.

### <a name="syntax"></a>Sintaxe

```
tiled_extent pad() const;
```

### <a name="return-value"></a>Valor de retorno

O novo `tiled_extent` objeto por valor.
## <a name="truncate"> </a>  Truncar

Retorna um novo `tiled_extent` objeto com as extensões ajustadas para baixo para ser igualmente divisível pelas dimensões do bloco.

### <a name="syntax"></a>Sintaxe

```
tiled_extent truncate() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna um novo `tiled_extent` objeto com as extensões ajustadas para baixo para ser igualmente divisível pelas dimensões do bloco.

## <a name="operator_eq"> </a>  operator=

Copia o conteúdo especificado `tiled_index` esse objeto.

### <a name="syntax"></a>Sintaxe

```
tiled_extent&  operator= (
    const tiled_extent& _Other ) restrict (amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*Outro*<br/>
O `tiled_index` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `tiled_index` instância.

## <a name="tile_dim0"> </a>  tile_dim0

Armazena o comprimento da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```
static const int tile_dim0 = _Dim0;
```

## <a name="tile_dim1"> </a>  tile_dim1

Armazena o comprimento da dimensão Avançar mais significativa.

### <a name="syntax"></a>Sintaxe

```
static const int tile_dim1 = _Dim1;
```

## <a name="tile_dim2"> </a>  tile_dim2

Armazena o comprimento da dimensão menos significativa.

### <a name="syntax"></a>Sintaxe

```
static const int tile_dim2 = _Dim2;
```

## <a name="tile_extent"> </a>  tile_extent
  Obtém uma `extent` que captura os valores do objeto de `tiled_extent` argumentos do modelo `_Dim0`, `_Dim1`, e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_tile_extent)) Concurrency::extent<rank> tile_extent;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
