---
title: Classe EventStack
description: A referência da classe C++ Build Insights SDK EventStack.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EventStack
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: eaaaedcbf57fdaf8e437a80a7823488febac3e1d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324975"
---
# <a name="eventstack-class"></a>Classe EventStack

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `EventStack` classe é uma coleção de objetos de [evento.](event.md) Todos os eventos recebidos do C++ Build Insights `EventStack` SDK vêm na forma de um objeto. A última entrada nesta pilha é o evento que está sendo processado. As entradas que precedem a última entrada são a hierarquia dos pais do evento atual. Para obter mais informações sobre o modelo de evento usado no C++ Build Insights, consulte [a tabela de eventos](../event-table.md).

## <a name="syntax"></a>Sintaxe

```cpp
class EventStack
{
public:
    EventStack(const EVENT_COLLECTION_DATA& data);

    size_t      Size() const;
    RawEvent    Back() const;
    RawEvent    operator[] (size_t index) const;
};
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

[EventStack](#event-stack)

### <a name="functions"></a>Funções

[Operador](#back)
[traseiro[]](#subscript-operator)
[Tamanho](#size)

## <a name="back"></a><a name="back"></a>Voltar

```cpp
RawEvent Back() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [RawEvent](raw-event.md) que representa a última entrada na pilha. A última entrada em uma pilha de eventos é o evento que foi acionado.

## <a name="eventstack"></a><a name="event-stack"></a>EventStack

```cpp
EventStack(const EVENT_COLLECTION_DATA& data);
```

### <a name="parameters"></a>Parâmetros

*Dados*\
Os dados brutos `EventStack` dos quais o é construído.

### <a name="remarks"></a>Comentários

Você não precisa construir `EventStack` objetos sozinho. Eles são fornecidos a você pelo C++ Build Insights SDK quando os eventos estão sendo processados durante uma sessão de análise ou relogging.

## <a name="operator"></a><a name="subscript-operator"></a>operador[]

```cpp
RawEvent operator[] (size_t index) const;
```

### <a name="parameters"></a>Parâmetros

*Índice*\
O índice do elemento a ser acessado na pilha de eventos.

### <a name="return-value"></a>Valor retornado

Um objeto [RawEvent](raw-event.md) que representa o evento armazenado na posição indicada pelo *índice* na pilha de eventos.

## <a name="size"></a><a name="size"></a> Tamanho

```cpp
size_t Size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da pilha de eventos.

::: moniker-end
