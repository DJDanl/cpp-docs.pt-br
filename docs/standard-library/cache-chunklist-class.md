---
title: Classe cache_chunklist
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::cache_chunklist
- allocators/stdext::cache_chunklist::allocate
- allocators/stdext::cache_chunklist::deallocate
helpviewer_keywords:
- stdext::cache_chunklist
- stdext::cache_chunklist [C++], allocate
- stdext::cache_chunklist [C++], deallocate
ms.assetid: af19eccc-4ae7-4a34-bbb2-81e397424cb9
ms.openlocfilehash: d0dd6176a34bd625069511106c491225d1467d08
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366752"
---
# <a name="cache_chunklist-class"></a>Classe cache_chunklist

Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, std::size_t Nelts = 20>
class cache_chunklist
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Sz*|O número de elementos na matriz a serem alocados.|

## <a name="remarks"></a>Comentários

Este modelo de classe usa **o operador novo** para alocar pedaços de memória bruta, subalocando blocos para alocar armazenamento para um bloco de memória quando necessário; ele armazena blocos de memória desalocados em uma lista livre separada para cada pedaço e usa a **exclusão do operador** para desalocar um pedaço quando nenhum de seus blocos de memória está em uso.

Cada bloco de memória contém *bytes Sz* de memória utilizável e um ponteiro para o pedaço a que pertence. Cada pedaço `Nelts` contém blocos de memória, três ponteiros, um int e os dados que o **operador novo** e **o operador excluem** requerem.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[cache_chunklist](#cache_chunklist)|Constrói um objeto do tipo `cache_chunklist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Alocar](#allocate)|Aloca um bloco de memória.|
|[Desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="cache_chunklistallocate"></a><a name="allocate"></a>cache_chunklist::alocar

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*contagem*|O número de elementos na matriz a serem alocados.|

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

## <a name="cache_chunklistcache_chunklist"></a><a name="cache_chunklist"></a>cache_chunklist:cache_chunklist

Constrói um objeto do tipo `cache_chunklist`.

```cpp
cache_chunklist();
```

### <a name="remarks"></a>Comentários

## <a name="cache_chunklistdeallocate"></a><a name="deallocate"></a>cache_chunklist::deallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*contagem*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
