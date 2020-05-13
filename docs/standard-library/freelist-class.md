---
title: Classe freelist
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::freelist
- allocators/stdext::freelist::pop
- allocators/stdext::freelist::push
helpviewer_keywords:
- stdext::freelist
- stdext::freelist [C++], pop
- stdext::freelist [C++], push
ms.assetid: 8ad7e35c-4c80-4479-8ede-1a2497b06d71
ms.openlocfilehash: 712c1f1638b954d1580eb527dd9eab7401917517
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317199"
---
# <a name="freelist-class"></a>Classe freelist

Gerencia uma lista de blocos de memória.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, class Max>
class freelist : public Max
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Sz*|O número de elementos na matriz a serem alocados.|
|*Max*|A classe max, que representa o número máximo de elementos a serem armazenados na lista livre. A classe max pode ser [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md), [max_fixed_size](../standard-library/max-fixed-size-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).|

## <a name="remarks"></a>Comentários

Este modelo de classe gerencia uma lista de blocos de memória de tamanho *Sz* com o comprimento máximo da lista determinado pela classe máxima aprovada em *Max*.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[freelist](#freelist)|Constrói um objeto do tipo `freelist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Pop](#pop)|Remove o primeiro bloco de memória da lista livre.|
|[Empurrar](#push)|Adiciona um bloco de memória à lista.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="freelistfreelist"></a><a name="freelist"></a>lista livre::lista livre

Constrói um objeto do tipo `freelist`.

```cpp
freelist();
```

### <a name="remarks"></a>Comentários

## <a name="freelistpop"></a><a name="pop"></a>freelist::pop

Remove o primeiro bloco de memória da lista livre.

```cpp
void *pop();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o bloco de memória removido da lista.

### <a name="remarks"></a>Comentários

A função membro retorna NULL se a lista estiver vazia. Caso contrário, remove o primeiro bloco de memória da lista.

## <a name="freelistpush"></a><a name="push"></a>lista livre::push

Adiciona um bloco de memória à lista.

```cpp
bool push(void* ptr);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro para o bloco de memória a ser adicionado à lista livre.|

### <a name="return-value"></a>Valor retornado

**verdade** se `full` a função da classe máxima retorna **falsa;** caso contrário, `push` a função retorna **falsa**.

### <a name="remarks"></a>Comentários

Se `full` a função da classe máxima retornar **falsa,** esta função de membro adicionará o bloco de memória apontado por *ptr* ao cabeça da lista.

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
