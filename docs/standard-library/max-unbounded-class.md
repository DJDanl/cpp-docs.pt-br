---
title: Classe max_unbounded
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::max_unbounded
- allocators/stdext::max_unbounded::allocated
- allocators/stdext::max_unbounded::deallocated
- allocators/stdext::max_unbounded::full
- allocators/stdext::max_unbounded::released
- allocators/stdext::max_unbounded::saved
helpviewer_keywords:
- stdext::max_unbounded
- stdext::max_unbounded [C++], allocated
- stdext::max_unbounded [C++], deallocated
- stdext::max_unbounded [C++], full
- stdext::max_unbounded [C++], released
- stdext::max_unbounded [C++], saved
ms.assetid: e34627a9-c231-4031-a483-cbb0514fff46
ms.openlocfilehash: fbc4351297ab8a3cc90a2a77fa31c3b134f10eab
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370989"
---
# <a name="max_unbounded-class"></a>Classe max_unbounded

Descreve um objeto da [classe max](../standard-library/allocators-header.md) que não limita o comprimento máximo de um objeto [freelist](../standard-library/freelist-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
class max_unbounded
```

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

## <a name="max_unboundedallocated"></a><a name="allocated"></a>max_unbounded::alocado

Aumenta a contagem de blocos de memória alocada.

```cpp
void allocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

Essa função membro não faz nada. É chamado após cada `cache_freelist::allocate` chamada bem sucedida por operador **novo**. O argumento *_Nx* é o número de blocos de memória no pedaço alocado pelo **operador novo**.

## <a name="max_unboundeddeallocated"></a><a name="deallocated"></a>max_unbounded::dalocado

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

## <a name="max_unboundedfull"></a><a name="full"></a>max_unbounded:full

Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.

```cpp
bool full();
```

### <a name="return-value"></a>Valor retornado

A função do membro sempre retorna **falsa**.

### <a name="remarks"></a>Comentários

Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada `deallocate` retornar **verdadeira,** coloque o bloco de memória na lista livre; se ele retornar `deallocate` falso, as chamadas do operador **excluem** para desalocar o bloco.

## <a name="max_unboundedreleased"></a><a name="released"></a>max_unbounded::liberado

Diminui a contagem de blocos de memória na lista livre.

```cpp
void released();
```

### <a name="remarks"></a>Comentários

Essa função membro não faz nada. A função membro `released` da classe max é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.

## <a name="max_unboundedsaved"></a><a name="saved"></a>max_unbounded::salvo

Aumenta a contagem de blocos de memória na lista livre.

```cpp
void saved();
```

### <a name="remarks"></a>Comentários

Essa função membro não faz nada. Ela é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
