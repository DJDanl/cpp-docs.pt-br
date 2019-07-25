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
ms.openlocfilehash: 8a504f58f9f64aa8b0d26b17090387c5c2b5de21
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454137"
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

Essa classe de modelo gerencia uma lista de blocos de memória de tamanho *sz* com o comprimento máximo da lista determinada pela classe máxima passada no *máximo*.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[freelist](#freelist)|Constrói um objeto do tipo `freelist`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[pop](#pop)|Remove o primeiro bloco de memória da lista livre.|
|[push](#push)|Adiciona um bloco de memória à lista.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="freelist"></a>  freelist::freelist

Constrói um objeto do tipo `freelist`.

```cpp
freelist();
```

### <a name="remarks"></a>Comentários

## <a name="pop"></a>  freelist::pop

Remove o primeiro bloco de memória da lista livre.

```cpp
void *pop();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o bloco de memória removido da lista.

### <a name="remarks"></a>Comentários

A função de membro retornará NULL se a lista estiver vazia. Caso contrário, remove o primeiro bloco de memória da lista.

## <a name="push"></a>  freelist::push

Adiciona um bloco de memória à lista.

```cpp
bool push(void* ptr);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ptr*|Um ponteiro para o bloco de memória a ser adicionado à lista livre.|

### <a name="return-value"></a>Valor de retorno

**true** se a `full` função da classe Max retornar **false**; caso contrário, a `push` função retornará **false**.

### <a name="remarks"></a>Comentários

Se a `full` função da classe Max retornar **false**, essa função de membro adicionará o bloco de memória apontado por *PTR* ao início da lista.

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)
