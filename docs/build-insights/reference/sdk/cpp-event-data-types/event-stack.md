---
title: Classe EventStack
description: A C++ referência da classe build do SDK do insights EventStack.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EventStack
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 6da2fd25082399b82d788c5d119a39e2f7388714
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333401"
---
# <a name="eventstack-class"></a>Classe EventStack

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `EventStack` é uma coleção de objetos de [evento](event.md) . Todos os eventos recebidos do C++ SDK de informações de compilação vêm na forma de um objeto de `EventStack`. A última entrada desta pilha é o evento que está sendo processado no momento. As entradas que precedem a última entrada são a hierarquia pai do evento atual. Para obter mais informações sobre o modelo de evento C++ usado em criar informações, consulte [tabela de eventos](../event-table.md).

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

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[EventStack](#event-stack)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Tamanho](#size) de
do operador de
de [fundo](#back) [[]](#subscript-operator)

## <a name="back"></a>Voltar

```cpp
RawEvent Back() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [RawEvent](raw-event.md) que representa a última entrada na pilha. A última entrada em uma pilha de eventos é o evento que foi disparado.

## <a name="event-stack"></a>EventStack

```cpp
EventStack(const EVENT_COLLECTION_DATA& data);
```

### <a name="parameters"></a>Parâmetros

\ de *dados*
Os dados brutos dos quais a `EventStack` é criada.

### <a name="remarks"></a>Comentários

Normalmente, você não precisa construir `EventStack` objetos por conta própria. Eles são fornecidos para você pelo SDK C++ do insights de compilação quando os eventos estão sendo processados durante uma sessão de análise ou de reregistro em log.

## <a name="subscript-operator"></a>operador []

```cpp
RawEvent operator[] (size_t index) const;
```

### <a name="parameters"></a>Parâmetros

\ de *índice*
O índice do elemento a ser acessado na pilha de eventos.

### <a name="return-value"></a>Valor retornado

Um objeto [RawEvent](raw-event.md) que representa o evento armazenado na posição indicada pelo *índice* na pilha de eventos.

## <a name="size"></a>Tamanho

```cpp
size_t Size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da pilha de eventos.

::: moniker-end
