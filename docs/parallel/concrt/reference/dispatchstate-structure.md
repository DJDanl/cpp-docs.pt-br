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
ms.openlocfilehash: 69e00893373ccca6e2ed676fbb7f5a109c49efdf
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143053"
---
# <a name="dispatchstate-structure"></a>Estrutura DispatchState

A estrutura de `DispatchState` é usada para transferir o estado para o método `IExecutionContext::Dispatch`. Ele descreve as circunstâncias sob as quais o método `Dispatch` é invocado em uma interface `IExecutionContext`.

## <a name="syntax"></a>Sintaxe

```cpp
struct DispatchState;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Expatchstate::D ispatchstate](#ctor)|Constrói um novo objeto `DispatchState`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Expatchstate:: m_dispatchStateSize](#m_dispatchstatesize)|Tamanho dessa estrutura, que é usado para controle de versão.|
|[Expatchstate:: m_fIsPreviousContextAsynchronouslyBlocked](#m_fispreviouscontextasynchronouslyblocked)|Informa se este contexto inseriu o método `Dispatch` porque o contexto anterior foi bloqueado de forma assíncrona. Isso é usado somente no contexto de agendamento UMS e é definido como o valor `0` para todos os outros contextos de execução.|
|[Expatchstate:: m_reserved](#m_reserved)|Bits reservados para futuras informações.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`DispatchState`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="ctor"></a>Expatchstate::D Construtor ispatchstate

Constrói um novo objeto `DispatchState`.

```cpp
DispatchState();
```

## <a name="m_dispatchstatesize"></a>Membro de dados expatchstate:: m_dispatchStateSize

Tamanho dessa estrutura, que é usado para controle de versão.

```cpp
unsigned long m_dispatchStateSize;
```

## <a name="m_fispreviouscontextasynchronouslyblocked"></a>Membro de dados expatchstate:: m_fIsPreviousContextAsynchronouslyBlocked

Informa se este contexto inseriu o método `Dispatch` porque o contexto anterior foi bloqueado de forma assíncrona. Isso é usado somente no contexto de agendamento UMS e é definido como o valor `0` para todos os outros contextos de execução.

```cpp
unsigned int m_fIsPreviousContextAsynchronouslyBlocked : 1;
```

## <a name="m_reserved"></a>Membro de dados expatchstate:: m_reserved

Bits reservados para futuras informações.

```cpp
unsigned int m_reserved : 31;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
