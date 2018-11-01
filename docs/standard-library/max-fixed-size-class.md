---
title: Classe max_fixed_size
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::max_fixed_size
- allocators/stdext::max_fixed_size::allocated
- allocators/stdext::max_fixed_size::deallocated
- allocators/stdext::max_fixed_size::full
- allocators/stdext::max_fixed_size::released
- allocators/stdext::max_fixed_size::saved
helpviewer_keywords:
- stdext::max_fixed_size
- stdext::max_fixed_size [C++], allocated
- stdext::max_fixed_size [C++], deallocated
- stdext::max_fixed_size [C++], full
- stdext::max_fixed_size [C++], released
- stdext::max_fixed_size [C++], saved
ms.assetid: 8c8f4588-37e9-4579-8168-ba3553800914
ms.openlocfilehash: 08510ecc3b7469e8f88a61dcb0df28541e170892
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50666446"
---
# <a name="maxfixedsize-class"></a>Classe max_fixed_size

Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo fixo.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Max>
class max_fixed_size
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Max*|A classe max que determina o número máximo de elementos para armazenar no `freelist`.|

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[max_fixed_size](#max_fixed_size)|Constrói um objeto do tipo `max_fixed_size`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[allocated](#allocated)|Aumenta a contagem de blocos de memória alocada.|
|[deallocated](#deallocated)|Diminui a contagem de blocos de memória alocada.|
|[full](#full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|
|[released](#released)|Diminui a contagem de blocos de memória na lista livre.|
|[saved](#saved)|Aumenta a contagem de blocos de memória na lista livre.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="allocated"></a>  max_fixed_size::allocated

Aumenta a contagem de blocos de memória alocada.

```cpp
void allocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função membro não faz nada. Essa função de membro é chamada após cada chamada bem-sucedida por `cache_freelist::allocate` ao operador **nova**. O argumento *_Nx* é o número de blocos de memória na parte alocada pelo operador **novos**.

## <a name="deallocated"></a>  max_fixed_size::deallocated

Diminui a contagem de blocos de memória alocada.

```cpp
void deallocated(std::size_t _Nx = 1);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O valor do incremento.|

### <a name="remarks"></a>Comentários

A função membro não faz nada. Essa função de membro é chamada após cada chamada por `cache_freelist::deallocate` ao operador **excluir**. O argumento *_Nx* é o número de blocos de memória na parte desalocada pelo operador **excluir**.

## <a name="full"></a>  max_fixed_size::full

Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.

```cpp
bool full();
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se `Max <= _Nblocks`; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar **verdadeira**, `deallocate` coloca o bloco de memória na lista livre; se ele retornar false, `deallocate` chamará o operador **excluir** para desalocar o bloco.

## <a name="max_fixed_size"></a>  max_fixed_size::max_fixed_size

Constrói um objeto do tipo `max_fixed_size`.

```cpp
max_fixed_size();
```

### <a name="remarks"></a>Comentários

Este construtor inicializa o valor armazenado `_Nblocks` como zero.

## <a name="released"></a>  max_fixed_size::released

Diminui a contagem de blocos de memória na lista livre.

```cpp
void released();
```

### <a name="remarks"></a>Comentários

Diminui o valor armazenado `_Nblocks`. A função membro `released` da [classe max](../standard-library/allocators-header.md) é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.

## <a name="saved"></a>  max_fixed_size::saved

Aumenta a contagem de blocos de memória na lista livre.

```cpp
void saved();
```

### <a name="remarks"></a>Comentários

Essa função membro aumenta a o valor armazenado `_Nblocks`. Essa função membro é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
