---
title: Classe max_fixed_size
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::max_fixed_size
- allocators/stdext::max_fixed_size::allocated
- allocators/stdext::max_fixed_size::deallocated
- allocators/stdext::max_fixed_size::full
- allocators/stdext::max_fixed_size::released
- allocators/stdext::max_fixed_size::saved
helpviewer_keywords:
- stdext::max_fixed_size
- stdext::max_fixed_size [C++], allocated
- stdext::max_fixed_size [C++], deallocated
- stdext::max_fixed_size [C++], full
- stdext::max_fixed_size [C++], released
- stdext::max_fixed_size [C++], saved
ms.assetid: 8c8f4588-37e9-4579-8168-ba3553800914
ms.openlocfilehash: 7f75dd71caa3cfcfec19264b1da62c6d47a3e01d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371001"
---
# <a name="max_fixed_size-class"></a>Classe max_fixed_size

Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo fixo.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Max>
class max_fixed_size
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Max*|A classe max que determina o número máximo de elementos para armazenar no `freelist`.|

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[max_fixed_size](#max_fixed_size)|Constrói um objeto do tipo `max_fixed_size`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[allocated](#allocated)|Aumenta a contagem de blocos de memória alocada.|
|[Desalocado](#deallocated)|Diminui a contagem de blocos de memória alocada.|
|[Cheio](#full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|
|[Lançado](#released)|Diminui a contagem de blocos de memória na lista livre.|
|[saved](#saved)|Aumenta a contagem de blocos de memória na lista livre.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="max_fixed_sizeallocated"></a><a name="allocated"></a>max_fixed_size::alocado

Aumenta a contagem de blocos de memória alocada.

```cpp
void allocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função membro não faz nada. Esta função de membro é `cache_freelist::allocate` chamada após cada chamada bem sucedida por operador **novo**. O argumento *_Nx* é o número de blocos de memória no pedaço alocado pelo **operador novo**.

## <a name="max_fixed_sizedeallocated"></a><a name="deallocated"></a>max_fixed_size::dalocado

Diminui a contagem de blocos de memória alocada.

```cpp
void deallocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função membro não faz nada. Esta função de membro é `cache_freelist::deallocate` chamada após cada chamada para **excluir**o operador . O argumento *_Nx* é o número de blocos de memória no pedaço desalocado pela **exclusão**do operador .

## <a name="max_fixed_sizefull"></a><a name="full"></a>max_fixed_size::full

Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.

```cpp
bool full();
```

### <a name="return-value"></a>Valor retornado

**verdade** `Max <= _Nblocks`se; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada `deallocate` retornar **verdadeira,** coloque o bloco de memória na lista livre; se ele retornar `deallocate` falso, as chamadas do operador **excluem** para desalocar o bloco.

## <a name="max_fixed_sizemax_fixed_size"></a><a name="max_fixed_size"></a>max_fixed_size:max_fixed_size

Constrói um objeto do tipo `max_fixed_size`.

```cpp
max_fixed_size();
```

### <a name="remarks"></a>Comentários

Este construtor inicializa o valor armazenado `_Nblocks` como zero.

## <a name="max_fixed_sizereleased"></a><a name="released"></a>max_fixed_size::liberado

Diminui a contagem de blocos de memória na lista livre.

```cpp
void released();
```

### <a name="remarks"></a>Comentários

Diminui o valor armazenado `_Nblocks`. A `released` função membro da [classe](../standard-library/allocators-header.md) max `cache_freelist::allocate` atual é chamada por sempre que remove um bloco de memória da lista livre.

## <a name="max_fixed_sizesaved"></a><a name="saved"></a>max_fixed_size::salvo

Aumenta a contagem de blocos de memória na lista livre.

```cpp
void saved();
```

### <a name="remarks"></a>Comentários

Essa função membro aumenta a o valor armazenado `_Nblocks`. Essa função membro é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
