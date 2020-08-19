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
ms.openlocfilehash: 1ee422423356a18f1c81796790593a20dc03fbab
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88560707"
---
# <a name="cache_chunklist-class"></a>Classe cache_chunklist

Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, std::size_t Nelts = 20>
class cache_chunklist
```

### <a name="parameters"></a>Parâmetros

*Sz*\
O número de elementos na matriz a serem alocados.

## <a name="remarks"></a>Comentários

Esse modelo de classe usa o **operador New** para alocar partes de memória bruta, Subalocando blocos para alocar armazenamento para um bloco de memória quando necessário; Ele armazena blocos de memória desalocados em uma lista gratuita separada para cada parte e usa o **operador Delete** para desalocar uma parte quando nenhum de seus blocos de memória está em uso.

Cada bloco de memória contém os bytes de *sz* de memória utilizável e um ponteiro para a parte à qual ele pertence. Cada parte contém `Nelts` blocos de memória, três ponteiros, um int e os dados que o **operador New** e o **operador Delete** exigem.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[cache_chunklist](#cache_chunklist)|Constrói um objeto do tipo `cache_chunklist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[aloca](#allocate)|Aloca um bloco de memória.|
|[desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="cache_chunklistallocate"></a><a name="allocate"></a> cache_chunklist:: Allocate

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>Parâmetros

*contar*\
O número de elementos na matriz a serem alocados.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

## <a name="cache_chunklistcache_chunklist"></a><a name="cache_chunklist"></a> cache_chunklist:: cache_chunklist

Constrói um objeto do tipo `cache_chunklist`.

```cpp
cache_chunklist();
```

### <a name="remarks"></a>Comentários

## <a name="cache_chunklistdeallocate"></a><a name="deallocate"></a> cache_chunklist::d eallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>Parâmetros

*PTR*\
Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.

*contar*\
O número de objetos a serem desalocados do armazenamento.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
