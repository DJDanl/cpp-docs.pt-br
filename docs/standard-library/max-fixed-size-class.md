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
ms.openlocfilehash: 23aa10a3398c3f20de73eb2ac6fa1372efdc32e5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228200"
---
# <a name="max_fixed_size-class"></a>Classe max_fixed_size

Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo fixo.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Max>
class max_fixed_size
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
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
|[desalocada](#deallocated)|Diminui a contagem de blocos de memória alocada.|
|[completo](#full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|
|[liberado](#released)|Diminui a contagem de blocos de memória na lista livre.|
|[saved](#saved)|Aumenta a contagem de blocos de memória na lista livre.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="max_fixed_sizeallocated"></a><a name="allocated"></a>max_fixed_size:: alocada

Aumenta a contagem de blocos de memória alocada.

```cpp
void allocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função membro não faz nada. Essa função de membro é chamada depois de cada chamada bem-sucedida do `cache_freelist::allocate` operador to **`new`** . O argumento *_Nx* é o número de blocos de memória na parte alocada pelo operador **`new`** .

## <a name="max_fixed_sizedeallocated"></a><a name="deallocated"></a>max_fixed_size::d eallocated

Diminui a contagem de blocos de memória alocada.

```cpp
void deallocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função membro não faz nada. Essa função de membro é chamada após cada operador chamar by `cache_freelist::deallocate` to **`delete`** . O argumento *_Nx* é o número de blocos de memória na parte desalocada pelo operador **`delete`** .

## <a name="max_fixed_sizefull"></a><a name="full"></a>max_fixed_size:: Full

Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.

```cpp
bool full();
```

### <a name="return-value"></a>Valor retornado

**`true`** Se `Max <= _Nblocks` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar **`true`** , `deallocate` colocará o bloco de memória na lista livre; se ele retornar false, `deallocate` chamará **`delete`** o operador para desalocar o bloco.

## <a name="max_fixed_sizemax_fixed_size"></a><a name="max_fixed_size"></a>max_fixed_size:: max_fixed_size

Constrói um objeto do tipo `max_fixed_size`.

```cpp
max_fixed_size();
```

### <a name="remarks"></a>Comentários

Este construtor inicializa o valor armazenado `_Nblocks` como zero.

## <a name="max_fixed_sizereleased"></a><a name="released"></a>max_fixed_size:: liberado

Diminui a contagem de blocos de memória na lista livre.

```cpp
void released();
```

### <a name="remarks"></a>Comentários

Diminui o valor armazenado `_Nblocks`. A `released` função membro da [classe máxima](../standard-library/allocators-header.md) atual é chamada pelo `cache_freelist::allocate` sempre que remove um bloco de memória da lista livre.

## <a name="max_fixed_sizesaved"></a><a name="saved"></a>max_fixed_size:: salvo

Aumenta a contagem de blocos de memória na lista livre.

```cpp
void saved();
```

### <a name="remarks"></a>Comentários

Essa função membro aumenta a o valor armazenado `_Nblocks`. Essa função membro é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
