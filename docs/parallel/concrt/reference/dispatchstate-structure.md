---
title: Estrutura DispatchState
ms.date: 11/04/2016
f1_keywords:
- DispatchState
- CONCRTRM/concurrency::DispatchState
- CONCRTRM/concurrency::DispatchState::DispatchState::DispatchState
- CONCRTRM/concurrency::DispatchState::DispatchState::m_dispatchStateSize
- CONCRTRM/concurrency::DispatchState::DispatchState::m_fIsPreviousContextAsynchronouslyBlocked
- CONCRTRM/concurrency::DispatchState::DispatchState::m_reserved
helpviewer_keywords:
- DispatchState structure
ms.assetid: 8c52546e-1650-48a0-985f-7e4a0fc26a90
ms.openlocfilehash: 2c4103f89f7fc74c5368bafac3c82685ff9b6e03
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372691"
---
# <a name="dispatchstate-structure"></a>Estrutura DispatchState

A `DispatchState` estrutura é usada para `IExecutionContext::Dispatch` transferir o estado para o método. Descreve as circunstâncias em `Dispatch` que o método `IExecutionContext` é invocado em uma interface.

## <a name="syntax"></a>Sintaxe

```cpp
struct DispatchState;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[DispatchState::DispatchState](#ctor)|Constrói um novo objeto `DispatchState`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Estado de despacho::m_dispatchStateSize](#m_dispatchstatesize)|Tamanho desta estrutura, que é usada para a versão.|
|[Estado de despacho::m_fIsPreviousContextAsynchronouslyBlocked](#m_fispreviouscontextasynchronouslyblocked)|Diz se esse contexto `Dispatch` entrou no método porque o contexto anterior foi bloqueado de forma assíncrona. Isso é usado apenas no contexto de agendamento da `0` UMS e é definido como valor para todos os outros contextos de execução.|
|[Estado de despacho::m_reserved](#m_reserved)|Bits reservados para informações futuras.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`DispatchState`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="dispatchstatedispatchstate-constructor"></a><a name="ctor"></a>DispatchState::DispatchState Constructor

Constrói um novo objeto `DispatchState`.

```cpp
DispatchState();
```

## <a name="dispatchstatem_dispatchstatesize-data-member"></a><a name="m_dispatchstatesize"></a>DispatchState::m_dispatchStateSize Data Member

Tamanho desta estrutura, que é usada para a versão.

```cpp
unsigned long m_dispatchStateSize;
```

## <a name="dispatchstatem_fispreviouscontextasynchronouslyblocked-data-member"></a><a name="m_fispreviouscontextasynchronouslyblocked"></a>DispatchState::m_fIsPreviousContextAsynchronouslyBlocked Data Member

Diz se esse contexto `Dispatch` entrou no método porque o contexto anterior foi bloqueado de forma assíncrona. Isso é usado apenas no contexto de agendamento da `0` UMS e é definido como valor para todos os outros contextos de execução.

```cpp
unsigned int m_fIsPreviousContextAsynchronouslyBlocked : 1;
```

## <a name="dispatchstatem_reserved-data-member"></a><a name="m_reserved"></a>DispatchState::m_reserved Membro de dados

Bits reservados para informações futuras.

```cpp
unsigned int m_reserved : 31;
```

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
