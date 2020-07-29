---
title: Classe max_none
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::max_none
- allocators/stdext::max_none::allocated
- allocators/stdext::max_none::deallocated
- allocators/stdext::max_none::full
- allocators/stdext::max_none::released
- allocators/stdext::max_none::saved
helpviewer_keywords:
- stdext::max_none
- stdext::max_none [C++], allocated
- stdext::max_none [C++], deallocated
- stdext::max_none [C++], full
- stdext::max_none [C++], released
- stdext::max_none [C++], saved
ms.assetid: 12ab5376-412e-479c-86dc-2c3d6a3559b6
ms.openlocfilehash: a8eee77afebdc78ef7c5b3b9ecacb8762b354567
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222284"
---
# <a name="max_none-class"></a>Classe max_none

Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo igual a zero.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Max>
class max_none
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*Max*|A classe max que determina o número máximo de elementos para armazenar no `freelist`.|

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

## <a name="max_noneallocated"></a><a name="allocated"></a>max_none:: alocada

Aumenta a contagem de blocos de memória alocada.

```cpp
void allocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

Essa função membro não faz nada. Ele é chamado depois de cada chamada bem-sucedida do `cache_freelist::allocate` operador to **`new`** . O argumento *_Nx* é o número de blocos de memória na parte alocada pelo operador **`new`** .

## <a name="max_nonedeallocated"></a><a name="deallocated"></a>max_none::d eallocated

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

## <a name="max_nonefull"></a><a name="full"></a>max_none:: Full

Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.

```cpp
bool full();
```

### <a name="return-value"></a>Valor retornado

Essa função de membro sempre retorna **`true`** .

### <a name="remarks"></a>Comentários

Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar **`true`** , `deallocate` coloca o bloco de memória na lista livre; se ele retornar **`false`** , o `deallocate` operador chamará **`delete`** para desalocar o bloco.

## <a name="max_nonereleased"></a><a name="released"></a>max_none:: liberado

Diminui a contagem de blocos de memória na lista livre.

```cpp
void released();
```

### <a name="remarks"></a>Comentários

Essa função membro não faz nada. A função membro `released` da classe max é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.

## <a name="max_nonesaved"></a><a name="saved"></a>max_none:: salvo

Aumenta a contagem de blocos de memória na lista livre.

```cpp
void saved();
```

### <a name="remarks"></a>Comentários

Essa função membro não faz nada. Ela é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
