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
ms.openlocfilehash: d757909d3e54fed35bf42b943b9f9740dffee115
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366743"
---
# <a name="cache_freelist-class"></a>Classe cache_freelist

Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, class Max>
class cache_freelist
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Sz*|O número de elementos na matriz a serem alocados.|
|*Max*|A classe max que representa o tamanho máximo da lista livre. Isso pode ser [max_fixed_size](../standard-library/max-fixed-size-class.md), [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).|

## <a name="remarks"></a>Comentários

O modelo de classe cache_freelist mantém uma lista gratuita de blocos de memória de tamanho *Sz*. Quando a lista gratuita está completa, ela usa a **exclusão do operador** para desalocar blocos de memória. Quando a lista livre está vazia, ela usa **o operador novo** para alocar novos blocos de memória. O tamanho máximo da lista livre é determinado pela classe max aprovada no parâmetro *Max.*

Cada bloco de memória contém *bytes Sz* de memória utilizável e os dados que o **operador novo** e o **operador excluem** requerem.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[cache_freelist](#cache_freelist)|Constrói um objeto do tipo `cache_freelist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Alocar](#allocate)|Aloca um bloco de memória.|
|[Desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="cache_freelistallocate"></a><a name="allocate"></a>cache_freelist:alocar

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

## <a name="cache_freelistcache_freelist"></a><a name="cache_freelist"></a>cache_freelist:cache_freelist

Constrói um objeto do tipo `cache_freelist`.

```cpp
cache_freelist();
```

### <a name="remarks"></a>Comentários

## <a name="cache_freelistdeallocate"></a><a name="deallocate"></a>cache_freelist::deallocate

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
