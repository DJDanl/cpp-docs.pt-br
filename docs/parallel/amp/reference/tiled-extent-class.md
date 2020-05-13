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
ms.openlocfilehash: ce2710da1a745efedcd6e9e524355eda41e26de2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374706"
---
# <a name="tiled_extent-class"></a>Classe tiled_extent

Um `tiled_extent` objeto `extent` é um objeto de uma a três dimensões que subdivide a extensão do espaço em telhas uni, bi ou tridimensional.

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

|Nome|Descrição|
|----------|-----------------|
|[Construtor tiled_extent](#ctor)|Inicia uma nova instância da classe `tiled_extent`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_tile_extent](#get_tile_extent)|Retorna `extent` um objeto que captura `tiled_extent` os valores dos argumentos `_Dim0`do modelo, `_Dim1`e `_Dim2`.|
|[Almofada](#pad)|Retorna um `tiled_extent` novo objeto com extensões ajustadas até serem uniformemente divisíveis pelas dimensões do azulejo.|
|[Truncar](#truncate)|Retorna um `tiled_extent` novo objeto com extensões ajustadas para baixo para ser uniformemente divisível pelas dimensões do azulejo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador=](#operator_eq)|Copia o conteúdo do `tiled_index` objeto especificado para este.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[tile_dim0 Constante](#tile_dim0)|Armazena a extensão da dimensão mais significativa.|
|[tile_dim1 Constante](#tile_dim1)|Armazena o comprimento da dimensão mais significativa.|
|[tile_dim2 Constante](#tile_dim2)|Armazena o comprimento da dimensão menos significativa.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[tile_extent](#tile_extent)|Obtém `extent` um objeto que captura `tiled_extent` os `_Dim0`valores dos argumentos do modelo, `_Dim1`e `_Dim2`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`extent`

`tiled_extent`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp.h

**Namespace:** Simultaneidade

## <a name="tiled_extent-constructor"></a><a name="ctor"> </a> construtor tiled_extent

Inicia uma nova instância da classe `tiled_extent`.

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
O `extent` `tiled_extent` ou objeto para copiar.

## <a name="get_tile_extent"></a><a name="get_tile_extent"> </a> get_tile_extent get_tile_extent

Retorna `extent` um objeto que captura `tiled_extent` os valores dos argumentos `_Dim0`do modelo, `_Dim1`e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
Concurrency::extent<rank> get_tile_extent() const restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Um `extent` objeto que captura as `tiled_extent` dimensões desta instância.

## <a name="pad"></a><a name="pad"> </a> pad

Retorna um `tiled_extent` novo objeto com extensões ajustadas até serem uniformemente divisíveis pelas dimensões do azulejo.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent pad() const;
```

### <a name="return-value"></a>Valor retornado

O `tiled_extent` novo objeto, por valor.

## <a name="truncate"></a><a name="truncate"> </a> truncar

Retorna um `tiled_extent` novo objeto com extensões ajustadas para baixo para ser uniformemente divisível pelas dimensões do azulejo.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent truncate() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um `tiled_extent` novo objeto com extensões ajustadas para baixo para ser uniformemente divisível pelas dimensões do azulejo.

## <a name="operator"></a><a name="operator_eq"> </a> operador=

Copia o conteúdo do `tiled_index` objeto especificado para este.

### <a name="syntax"></a>Sintaxe

```cpp
tiled_extent&  operator= (
    const tiled_extent& _Other ) restrict (amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `tiled_index` objeto para copiar.

### <a name="return-value"></a>Valor retornado

Uma referência `tiled_index` a este caso.

## <a name="tile_dim0"></a><a name="tile_dim0"> </a> tile_dim0

Armazena a extensão da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim0 = _Dim0;
```

## <a name="tile_dim1"></a><a name="tile_dim1"> </a> tile_dim1

Armazena o comprimento da dimensão mais significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim1 = _Dim1;
```

## <a name="tile_dim2"></a><a name="tile_dim2"> </a> tile_dim2 tile_dim2.

Armazena o comprimento da dimensão menos significativa.

### <a name="syntax"></a>Sintaxe

```cpp
static const int tile_dim2 = _Dim2;
```

## <a name="tile_extent"></a><a name="tile_extent"> </a> tile_extent

Obtém `extent` um objeto que captura `tiled_extent` os `_Dim0`valores dos argumentos do modelo, `_Dim1`e `_Dim2`.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_tile_extent)) Concurrency::extent<rank> tile_extent;
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
