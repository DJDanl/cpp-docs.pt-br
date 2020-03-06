---
title: MatchEvent
description: A C++ referência da função MATCHEVENT do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f8022953e2f56f7c8917f161b094c50e0c5ecbdf
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332771"
---
# <a name="matchevent"></a>MatchEvent

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `MatchEvent` é usada para corresponder a um evento em uma lista de tipos de eventos. Se o evento corresponder a um tipo na lista, ele será encaminhado para um manipulador para processamento adicional.

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

\ *TEvent*
O primeiro tipo de evento que você deseja corresponder.

\ *TEvents*
Os tipos de evento restantes que você deseja corresponder.

\ *TCallable*
Um tipo que dá suporte a `operator()`. Para obter mais informações sobre quais argumentos são passados para esse operador, consulte a descrição do parâmetro *callable* .

\ *TExtraArgs*
Os tipos dos argumentos extras que foram passados para `MatchEvent`.

*event*\
O evento a ser correspondido nos tipos de evento descritos por *TEvent* e *TEvents*.

\ *callable*
`MatchEvent` invoca o *callable* depois de corresponder com êxito o evento com qualquer um dos tipos de evento descritos por *TEvent* e *TEvents*. O primeiro argumento passado para *callable* é um valor r-value do tipo de evento MATCHED. O pacote de parâmetros *extraArgs* é encaminhado perfeitamente nos parâmetros restantes do *callable*.  

\ *extraArgs*
Os argumentos que são encaminhados perfeitamente para o que podem ser *chamados* junto com o tipo de evento correspondente.

### <a name="return-value"></a>Valor retornado

Um valor **bool** **verdadeiro** se a correspondência for bem-sucedida ou **false** caso contrário.

## <a name="remarks"></a>Comentários

Os tipos de evento a serem usados para os parâmetros *TEvent* e *TEvents* são selecionados em uma lista de *classes de captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para fazer a correspondência, consulte a [tabela de eventos](../event-table.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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
