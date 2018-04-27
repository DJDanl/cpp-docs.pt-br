---
title: Classe freelist | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
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
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9b332dcf7b67f6d5054ea4d160faac6ea2a5ad17
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
|`Sz`|O número de elementos na matriz a serem alocados.|
|`Max`|A classe max, que representa o número máximo de elementos a serem armazenados na lista livre. A classe max pode ser [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md), [max_fixed_size](../standard-library/max-fixed-size-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).|

## <a name="remarks"></a>Comentários

Essa classe de modelo gerencia uma lista de blocos de memória de tamanho `Sz` com o tamanho máximo da lista determinado pela classe max passada em `Max`.

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

A função membro retorna `NULL` se a lista estiver vazia. Caso contrário, remove o primeiro bloco de memória da lista.

## <a name="push"></a>  freelist::push

Adiciona um bloco de memória à lista.

```cpp
bool push(void* ptr);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`ptr`|Um ponteiro para o bloco de memória a ser adicionado à lista livre.|

### <a name="return-value"></a>Valor de retorno

`true` se a função `full` da classe max retornar `false`; caso contrário, a função `push` retorna `false`.

### <a name="remarks"></a>Comentários

Se a função `full` da classe max retornar `false`, essa função membro adicionará o bloco de memória apontado por `ptr` ao topo da lista.

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
