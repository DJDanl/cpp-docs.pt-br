---
title: MatchEvent
description: A referência da função C++ Build Insights SDK MatchEvent.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 0c60653641c676716bcdd60865433773da79325f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323863"
---
# <a name="matchevent"></a>MatchEvent

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MatchEvent` função é usada para combinar um evento com uma lista de tipos de eventos. Se o evento corresponder a um tipo na lista, ele é encaminhado para um manipulador para posterior processamento.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename        TEvent,
    typename...     TEvents,
    typename        TCallable,
    typename...     TExtraArgs>
bool MatchEvent(
    const RawEvent& event,
    TCallable&&     callable,
    TExtraArgs&&... extraArgs);
```

### <a name="parameters"></a>Parâmetros

*Tevent*\
O primeiro tipo de evento que você deseja combinar.

*Eventos T*\
Os demais tipos de eventos que você deseja combinar.

*TCallable*\
Um tipo que `operator()`suporta . Para obter mais informações sobre quais argumentos são passados para este operador, consulte a descrição do parâmetro *callable.*

*TExtraArgs*\
Os tipos de argumentos extras `MatchEvent`que foram passados para .

*Evento*\
O evento para combinar com os tipos de eventos descritos por *TEvent* e *TEvents*.

*Callable*\
`MatchEvent`invoca *callable* depois de combinar o evento com qualquer um dos tipos de evento descritos por *TEvent* e *TEvents*. O primeiro argumento passado para *callable* é um valor r do tipo de evento combinado. O *parâmetro extraArgs* é aperfeiçoado nos parâmetros restantes de *calável*.  

*extraArgs*\
Os argumentos que são encaminhados perfeitamente para *chamá-los juntamente* com o tipo de evento combinado.

### <a name="return-value"></a>Valor retornado

Um valor **bool** que é **verdade** se a correspondência foi bem sucedida, ou **falsa** de outra forma.

## <a name="remarks"></a>Comentários

Os tipos de eventos a serem usados para os parâmetros *TEvent* e *TEvents* são selecionados a partir de uma lista de classes de *captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para combiná-los, consulte [a tabela de eventos](../event-table.md).

## <a name="example"></a>Exemplo

```cpp
void MyClass::OnStartActivity(const EventStack& eventStack)
{
    // Let's assume eventStack contains:
    // [Compiler, BackEndPass, C2DLL, CodeGeneration, Thread, Function]

    auto& functionEvent = eventStack.Back(); // The Function event

    bool b1 = MatchEvent<Function, Thread>(
        functionEvent, [](auto matchedEvent){ /* Do something... */});

    bool b2 = MatchEvent<CodeGeneration, Thread>(
        functionEvent, [](auto matchedEvent){ /* Do something... */});


    // b1: true because the list of types contains Function, which is
    //     the type of the event we are trying to match.
    // b2: false because the list of types doesn't contain Function.
}
```

::: moniker-end
