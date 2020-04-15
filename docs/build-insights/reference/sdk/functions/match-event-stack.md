---
title: MatchEventStack
description: A referência da função C++ Build Insights SDK MatchEventStack.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEventStack
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a223d420e8c48667fbd1c6569f02d0486f597b5e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323870"
---
# <a name="matcheventstack"></a>MatchEventStack

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MatchEventStack` função é usada para combinar uma pilha de eventos com uma hierarquia de eventos específica. Hierarquias combinadas são encaminhadas a um manipulador para posterior processamento. Para saber mais sobre eventos, pilhas de eventos e hierarquias, consulte [a tabela de eventos](../event-table.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename          TEvent,
    typename...       TEvents,
    typename          TCallable,
    typename...       TExtraArgs>
bool MatchEventStack(
    const EventStack& eventStack,
    TCallable&&       callable,
    TExtraArgs&&...   extraArgs);
```

### <a name="parameters"></a>Parâmetros

*Tevent*\
O tipo do pai mais velho para combinar na pilha de eventos.

*Eventos T*\
Os demais tipos que você deseja combinar na pilha de eventos.

*TCallable*\
Um tipo que `operator()`suporta . Para obter mais informações sobre quais argumentos são passados para este operador, consulte a descrição do parâmetro *callable.*

*TExtraArgs*\
Os tipos de argumentos `MatchEventStack`extras passaram para .

*eventStack*\
A pilha de eventos para coincidir com a hierarquia do tipo de evento descrita por *TEvent* e *TEvents*.

*Callable*\
Ao combinar com sucesso a pilha de eventos com a `MatchEventStack` hierarquia do tipo de evento descrita por *TEvent* e *TEvents,* invoca *callable*. Ele passa para um argumento de valor r *para* cada tipo na hierarquia de eventos. O *parâmetro extraArgs* é aperfeiçoado nos parâmetros restantes de *calável*.

*extraArgs*\
Os argumentos que são encaminhados perfeitamente para *chamá-los juntamente* com o tipo de evento combinado.

### <a name="return-value"></a>Valor retornado

Um valor **bool** que é **verdadeiro** se a correspondência foi bem sucedida, ou **falso** de outra forma.

## <a name="remarks"></a>Comentários

O último evento no *eventStack* é sempre compatível com a \[última entrada no *TEvent*concatenado , *TEvents...* \] lista de tipos. Todas as outras entradas *TEvent* e *TEvents* podem corresponder a qualquer posição no *eventStack,* exceto a última, desde que estejam na mesma ordem.

Os tipos de eventos a serem usados para os parâmetros *TEvent* e *TEvents* são selecionados a partir de uma lista de classes de *captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para combiná-los, consulte [a tabela de eventos](../event-table.md).

## <a name="example"></a>Exemplo

```cpp
void MyClass::OnStartActivity(const EventStack& eventStack)
{
    // Let's assume eventStack contains:
    // [Compiler, BackEndPass, C2DLL, CodeGeneration, Thread, Function]

    bool b1 = MatchEventStack<Compiler, BackEndPass, C2DLL,
                CodeGeneration, Thread, Function>(
        eventStack, [](Compiler cl, BackEndPass bep, C2DLL c2,
            CodeGeneration cg, Thread t, Function f){ /* Do something ... */ });

    bool b2 = MatchEventStack<Compiler, Function>(
        eventStack, [](Compiler cl, Function f){ /* Do something... */ });

    bool b3 = MatchEventStack<Thread, Compiler, Function>(
        eventStack, [](Thread t, Compiler cl Function f){ /* Do something... */ });

    bool b4 = MatchEventStack<Compiler>(
        eventStack, [](Compiler cl){ /* Do something... */ });


    // b1: true because the list of types matches the eventStack exactly.
    // b2: true because Function is the last entry in both the type list
    //     and 'eventStack', and also because Compiler comes before
    //     Function in 'eventStack' and in the type list.
    // b3: false because, even though both Thread and Compiler come
    //     before Function in 'eventStack', they aren't listed in the
    //     right order in the type list.
    // b4: false because the last entry in the type list is Compiler,
    //     which doesn't match the last entry in 'eventStack' (Function).
}
```

::: moniker-end
