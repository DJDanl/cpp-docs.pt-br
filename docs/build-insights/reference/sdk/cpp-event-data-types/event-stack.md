---
title: Classe EventStack
description: A referência de classe do SDK do EventStack de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EventStack
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b4f1e92011acdf8272fe631843c03c2f960a1234
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920704"
---
# <a name="eventstack-class"></a>Classe EventStack

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `EventStack` classe é uma coleção de objetos de [evento](event.md) . Todos os eventos recebidos do SDK do insights de compilação do C++ vêm na forma de um `EventStack` objeto. A última entrada desta pilha é o evento que está sendo processado no momento. As entradas que precedem a última entrada são a hierarquia pai do evento atual. Para obter mais informações sobre o modelo de evento usado em informações de Build do C++, consulte [tabela de eventos](../event-table.md).

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

[Voltar](#back) 
 [operador []](#subscript-operator) 
 [Tamanho](#size)

## <a name="back"></a><a name="back"></a> Voltar

```cpp
RawEvent Back() const;
```

### <a name="return-value"></a>Valor Retornado

Um objeto [RawEvent](raw-event.md) que representa a última entrada na pilha. A última entrada em uma pilha de eventos é o evento que foi disparado.

## <a name="eventstack"></a><a name="event-stack"></a> EventStack

```cpp
EventStack(const EVENT_COLLECTION_DATA& data);
```

### <a name="parameters"></a>Parâmetros

*dado*\
Os dados brutos dos quais o `EventStack` é criado.

### <a name="remarks"></a>Comentários

Normalmente, você não precisa construir `EventStack` objetos por conta própria. Eles são fornecidos a você pelo SDK de informações de Build do C++ quando os eventos estão sendo processados durante uma sessão de análise ou de registro em log.

## <a name="operator"></a><a name="subscript-operator"></a> operador []

```cpp
RawEvent operator[] (size_t index) const;
```

### <a name="parameters"></a>Parâmetros

*index*\
O índice do elemento a ser acessado na pilha de eventos.

### <a name="return-value"></a>Valor Retornado

Um objeto [RawEvent](raw-event.md) que representa o evento armazenado na posição indicada pelo *índice* na pilha de eventos.

## <a name="size"></a><a name="size"></a> Tamanho

```cpp
size_t Size() const;
```

### <a name="return-value"></a>Valor Retornado

O tamanho da pilha de eventos.

::: moniker-end
