---
title: MatchEventStack
description: A referência da função MatchEventStack do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEventStack
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ae476c402c3ea0cad558ce41a979b4233e0f1dd3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224117"
---
# <a name="matcheventstack"></a>MatchEventStack

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MatchEventStack` função é usada para corresponder a uma pilha de eventos em uma hierarquia de eventos específica. As hierarquias correspondentes são encaminhadas a um manipulador para processamento adicional. Para saber mais sobre eventos, pilhas de eventos e hierarquias, consulte a [tabela de eventos](../event-table.md).

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

### <a name="parameters"></a>parâmetros

*TEvent*\
O tipo do pai Eldest a ser correspondido na pilha de eventos.

*TEvents*\
Os tipos restantes que você deseja corresponder na pilha de eventos.

*TCallable*\
Um tipo que dá suporte a `operator()` . Para obter mais informações sobre quais argumentos são passados para esse operador, consulte a descrição do parâmetro *callable* .

*TExtraArgs*\
Os tipos dos argumentos extras passados para `MatchEventStack` .

*eventStack*\
A pilha de eventos para corresponder à hierarquia de tipo de evento descrita por *TEvent* e *TEvents*.

*acessível*\
Após corresponder com êxito à pilha de eventos com a hierarquia de tipo de evento descrita por *TEvent* e *TEvents*, `MatchEventStack` invoca o *callable*. Ele passa a ter um argumento r-value que possa ser *chamado* para cada tipo na hierarquia de eventos. O pacote de parâmetros *extraArgs* é encaminhado perfeitamente nos parâmetros restantes do *callable*.

*extraArgs*\
Os argumentos que são encaminhados perfeitamente para o que podem ser *chamados* junto com o tipo de evento correspondente.

### <a name="return-value"></a>Valor retornado

Um **`bool`** valor que **`true`** se corresponder com êxito ou de **`false`** outra forma.

## <a name="remarks"></a>Comentários

O último evento em *eventStack* sempre é correspondido na última entrada da lista TEvent concatenada \[ *TEvent*, *TEvents...* \] Type. Todas as outras entradas *TEvent* e *TEvents* podem corresponder a qualquer posição no *eventStack* , exceto a última, desde que estejam na mesma ordem.

Os tipos de evento a serem usados para os parâmetros *TEvent* e *TEvents* são selecionados em uma lista de *classes de captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para fazer a correspondência, consulte a [tabela de eventos](../event-table.md).

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
