---
title: Classe cache_freelist
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::cache_freelist
- allocators/stdext::cache_freelist::allocate
- allocators/stdext::cache_freelist::deallocate
helpviewer_keywords:
- stdext::cache_freelist
- stdext::cache_freelist [C++], allocate
- stdext::cache_freelist [C++], deallocate
ms.assetid: 840694de-36ba-470f-8dae-2b723d5a8cd9
ms.openlocfilehash: bbe0ff0f2297afcec99bd162ebe6a6d3e10f9bce
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88560720"
---
# <a name="cache_freelist-class"></a>Classe cache_freelist

Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, class Max>
class cache_freelist
```

### <a name="parameters"></a>parâmetros

*Sz*\
O número de elementos na matriz a serem alocados.

*Maximizar*\
A classe max que representa o tamanho máximo da lista livre. Isso pode ser [max_fixed_size](../standard-library/max-fixed-size-class.md), [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).

## <a name="remarks"></a>Comentários

O modelo de classe cache_freelist mantém uma lista gratuita de blocos de memória de tamanho *sz*. Quando a lista livre está cheia, ela usa o **operador Delete** para desalocar os blocos de memória. Quando a lista livre está vazia, ela usa o **operador novo** para alocar novos blocos de memória. O tamanho máximo da lista livre é determinado pela classe máxima da classe passada no parâmetro *Max* .

Cada bloco de memória contém os bytes de *sz* de memória utilizável e os dados que o **operador New** e o **operador Delete** exigem.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[cache_freelist](#cache_freelist)|Constrói um objeto do tipo `cache_freelist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[aloca](#allocate)|Aloca um bloco de memória.|
|[desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="cache_freelistallocate"></a><a name="allocate"></a> cache_freelist:: Allocate

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>parâmetros

*contar*\
O número de elementos na matriz a serem alocados.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

## <a name="cache_freelistcache_freelist"></a><a name="cache_freelist"></a> cache_freelist:: cache_freelist

Constrói um objeto do tipo `cache_freelist`.

```cpp
cache_freelist();
```

### <a name="remarks"></a>Comentários

## <a name="cache_freelistdeallocate"></a><a name="deallocate"></a> cache_freelist::d eallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>parâmetros

*PTR*\
Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.

*contar*\
O número de objetos a serem desalocados do armazenamento.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
