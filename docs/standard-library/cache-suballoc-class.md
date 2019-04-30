---
title: Classe cache_suballoc
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::cache_suballoc
- allocators/stdext::cache_suballoc::allocate
- allocators/stdext::cache_suballoc::deallocate
helpviewer_keywords:
- stdext::cache_suballoc
- stdext::cache_suballoc [C++], allocate
- stdext::cache_suballoc [C++], deallocate
ms.assetid: 9ea9c5e9-1dcc-45d0-b3a7-a56a93d88898
ms.openlocfilehash: 06d0ef390e6ae1980b9ab20b8ceb67213837148b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62380111"
---
# <a name="cachesuballoc-class"></a>Classe cache_suballoc

Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, size_t Nelts = 20>
class cache_suballoc
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Sz*|O número de elementos na matriz a serem alocados.|

## <a name="remarks"></a>Comentários

A classe de modelo cache_suballoc armazena blocos de memória desalocados em uma lista livre com comprimento ilimitado, usando `freelist<sizeof(Type), max_unbounded>`e os subaloca blocos de memória de uma parte maior alocada com **operador new** quando a lista livre está vazio.

Cada parte contém `Sz * Nelts` bytes de memória utilizável e os dados que **operador new** e **operador delete** exigem. Partes alocadas nunca são liberadas.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[cache_suballoc](#cache_suballoc)|Constrói um objeto do tipo `cache_suballoc`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[allocate](#allocate)|Aloca um bloco de memória.|
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="allocate"></a>  cache_suballoc::allocate

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*count*|O número de elementos na matriz a serem alocados.|

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

## <a name="cache_suballoc"></a>  cache_suballoc::cache_suballoc

Constrói um objeto do tipo `cache_suballoc`.

```cpp
cache_suballoc();
```

### <a name="remarks"></a>Comentários

## <a name="deallocate"></a>  cache_suballoc::deallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*count*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
