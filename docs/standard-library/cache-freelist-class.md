---
title: cache_freelist Class | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- allocators/stdext::cache_freelist
- allocators/stdext::cache_freelist::allocate
- allocators/stdext::cache_freelist::deallocate
dev_langs:
- C++
helpviewer_keywords:
- stdext::cache_freelist
- stdext::cache_freelist [C++], allocate
- stdext::cache_freelist [C++], deallocate
ms.assetid: 840694de-36ba-470f-8dae-2b723d5a8cd9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c3d3902d900e0dad5ec3e335e9c3424d58ee2674
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38960411"
---
# <a name="cachefreelist-class"></a>Classe cache_freelist

Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, class Max>
class cache_freelist
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*SZ*|O número de elementos na matriz a serem alocados.|
|*Max*|A classe max que representa o tamanho máximo da lista livre. Isso pode ser [max_fixed_size](../standard-library/max-fixed-size-class.md), [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).|

## <a name="remarks"></a>Comentários

A classe de modelo cache_freelist mantém uma lista livre de blocos de memória de tamanho *Sz*. Quando a lista livre estiver cheia, ele usa **operador delete** desalocar memória bloqueia. Quando a lista livre estiver vazia, ele usa **operador new** para alocar novos blocos de memória. O tamanho máximo da lista livre é determinado pela classe classe max passada a *máx* parâmetro.

Cada bloco de memória contém *Sz* bytes de memória utilizável e os dados que **operador new** e **operador delete** exigem.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[cache_freelist](#cache_freelist)|Constrói um objeto do tipo `cache_freelist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[allocate](#allocate)|Aloca um bloco de memória.|
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="allocate"></a>  cache_freelist::allocate

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

## <a name="cache_freelist"></a>  cache_freelist::cache_freelist

Constrói um objeto do tipo `cache_freelist`.

```cpp
cache_freelist();
```

### <a name="remarks"></a>Comentários

## <a name="deallocate"></a>  cache_freelist::deallocate

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
