---
title: Classe max_variable_size
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::max_variable_size
- allocators/stdext::max_variable_size::allocated
- allocators/stdext::max_variable_size::deallocated
- allocators/stdext::max_variable_size::full
- allocators/stdext::max_variable_size::released
- allocators/stdext::max_variable_size::saved
helpviewer_keywords:
- stdext::max_variable_size
- stdext::max_variable_size [C++], allocated
- stdext::max_variable_size [C++], deallocated
- stdext::max_variable_size [C++], full
- stdext::max_variable_size [C++], released
- stdext::max_variable_size [C++], saved
ms.assetid: 9f2e9df0-4148-4b37-bc30-f8eca0ef86ae
ms.openlocfilehash: 79e37d8c464a009e4a5196aeacc8d4a718e355b9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370963"
---
# <a name="max_variable_size-class"></a>Classe max_variable_size

Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo aproximadamente proporcional ao número de blocos de memória alocados.

## <a name="syntax"></a>Sintaxe

```cpp
class max_variable_size
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[max_variable_size](#max_variable_size)|Constrói um objeto do tipo `max_variable_size`.|

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

## <a name="max_variable_sizeallocated"></a><a name="allocated"></a>max_variable_size::alocado

Aumenta a contagem de blocos de memória alocada.

```cpp
void allocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

Esta função *_Nx* de membro adiciona `_Nallocs`_Nx ao valor armazenado . Esta função de membro é `cache_freelist::allocate` chamada após cada chamada bem sucedida por operador **novo**. O argumento *_Nx* é o número de blocos de memória no pedaço alocado pelo **operador novo**.

## <a name="max_variable_sizedeallocated"></a><a name="deallocated"></a>max_variable_size::dalocado

Diminui a contagem de blocos de memória alocada.

```cpp
void deallocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função do *_Nx* membro subtrai `_Nallocs`_Nx do valor armazenado . Esta função de membro é `cache_freelist::deallocate` chamada após cada chamada para **excluir**o operador . O argumento *_Nx* é o número de blocos de memória no pedaço desalocado pela **exclusão**do operador .

## <a name="max_variable_sizefull"></a><a name="full"></a>max_variable_size::full

Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.

```cpp
bool full();
```

### <a name="return-value"></a>Valor retornado

**verdade** `_Nallocs / 16 + 16 <= _Nblocks`se .

### <a name="remarks"></a>Comentários

Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada `deallocate` retornar **verdadeira,** coloque o bloco de memória na lista livre; se ele retornar `deallocate` falso, as chamadas do operador **excluem** para desalocar o bloco.

## <a name="max_variable_sizemax_variable_size"></a><a name="max_variable_size"></a>max_variable_size:max_variable_size

Constrói um objeto do tipo `max_variable_size`.

```cpp
max_variable_size();
```

### <a name="remarks"></a>Comentários

O construtor inicializa os valores armazenados `_Nblocks` e `_Nallocs` como zero.

## <a name="max_variable_sizereleased"></a><a name="released"></a>max_variable_size::liberado

Diminui a contagem de blocos de memória na lista livre.

```cpp
void released();
```

### <a name="remarks"></a>Comentários

Essa função membro diminui a o valor armazenado `_Nblocks`. A função membro `released` da classe max é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.

## <a name="max_variable_sizesaved"></a><a name="saved"></a>max_variable_size::salvo

Aumenta a contagem de blocos de memória na lista livre.

```cpp
void saved();
```

### <a name="remarks"></a>Comentários

Essa função membro aumenta a o valor armazenado `_Nblocks`. Essa função membro é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
