---
title: cache_suballoc Class | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- allocators/stdext::cache_suballoc
- allocators/stdext::cache_suballoc::allocate
- allocators/stdext::cache_suballoc::deallocate
dev_langs:
- C++
helpviewer_keywords:
- stdext::cache_suballoc
- stdext::cache_suballoc [C++], allocate
- stdext::cache_suballoc [C++], deallocate
ms.assetid: 9ea9c5e9-1dcc-45d0-b3a7-a56a93d88898
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 28dc4e52e2f114600ad3a22697500ce9d8594113
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33850301"
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
|`Sz`|O número de elementos na matriz a serem alocados.|

## <a name="remarks"></a>Comentários

A classe de modelo cache_suballoc armazena blocos de memória desalocados em uma lista livre com comprimento ilimitado, usando `freelist<sizeof(Type), max_unbounded>` e subaloca blocos de memória de uma parte maior alocada com `operator new` quando a lista livre está vazia.

Cada parte contém `Sz * Nelts` bytes de memória utilizável e os dados que `operator new` e `operator delete` requerem. Partes alocadas nunca são liberadas.

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
|`count`|O número de elementos na matriz a serem alocados.|

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
|`ptr`|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|`count`|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
