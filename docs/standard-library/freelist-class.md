---
title: Classe freelist | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- allocators/stdext::freelist
- allocators/stdext::freelist::pop
- allocators/stdext::freelist::push
dev_langs:
- C++
helpviewer_keywords:
- stdext::freelist
- stdext::freelist [C++], pop
- stdext::freelist [C++], push
ms.assetid: 8ad7e35c-4c80-4479-8ede-1a2497b06d71
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 05354361bd460f64daced16684e9f8b70de94898
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38954106"
---
# <a name="freelist-class"></a>Classe freelist

Gerencia uma lista de blocos de memória.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Sz, class Max>
class freelist
 : public Max
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*SZ*|O número de elementos na matriz a serem alocados.|
|*Max*|A classe max, que representa o número máximo de elementos a serem armazenados na lista livre. A classe max pode ser [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md), [max_fixed_size](../standard-library/max-fixed-size-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).|

## <a name="remarks"></a>Comentários

Essa classe de modelo gerencia uma lista de blocos de memória de tamanho *Sz* com o comprimento máximo da lista determinado pela classe max passada *Max*.

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

A função membro retorna NULL se a lista estiver vazia. Caso contrário, remove o primeiro bloco de memória da lista.

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

**Verdadeiro** se o `full` função da classe max retornar **falso**; caso contrário, o `push` retornos de função **false**.

### <a name="remarks"></a>Comentários

Se o `full` função da classe max retornar **falsos**, essa função membro adiciona o bloco de memória apontado por *ptr* ao topo da lista.

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
