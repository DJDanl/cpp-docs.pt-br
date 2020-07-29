---
title: MatchEventStackInMemberFunction
description: A referência da função MatchEventStackInMemberFunction do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEventStackInMemberFunction
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: db02ce5656bf8970ead7b49d5580f7d81bebb1b2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224130"
---
# <a name="matcheventstackinmemberfunction"></a>MatchEventStackInMemberFunction

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MatchEventStackInMemberFunction` função é usada para corresponder a uma pilha de eventos em uma hierarquia de eventos específica, descrita pela lista de parâmetros de uma função de membro. As hierarquias correspondentes são encaminhadas para a função de membro para processamento adicional. Para saber mais sobre eventos, pilhas de eventos e hierarquias, consulte a [tabela de eventos](../event-table.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename     TInterface,
    typename     TReturn,
    typename     T1,
    typename...  TExtraParams,
    typename...  TExtraArgs>
bool MatchEventStackInMemberFunction(
    const EventStack&         eventStack,
    TInterface*               objectPtr,
    TReturn (TInterface::*    memberFunc)(T1, TExtraParams...),
    TExtraArgs&&...           extraArgs);

template <
    typename     TInterface,
    typename     TReturn,
    typename     T1,
    typename     T2,
    typename...  TExtraParams,
    typename...  TExtraArgs>
bool MatchEventStackInMemberFunction(
    const EventStack&         eventStack,
    TInterface*               objectPtr,
    TReturn (TInterface::*    memberFunc)(T1, T2, TExtraParams...),
    TExtraArgs&&...           extraArgs);

// Etc...

template <
    typename     TInterface,
    typename     TReturn,
    typename     T1,
    typename     T2,
    typename     T3,
    typename     T4,
    typename     T5,
    typename     T6,
    typename     T7,
    typename     T8,
    typename     T9,
    typename     T10,
    typename...  TExtraParams,
    typename...  TExtraArgs>
bool MatchEventStackInMemberFunction(
    const EventStack&         eventStack,
    TInterface*               objectPtr,
    TReturn (TInterface::*    memberFunc)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TExtraParams...),
    TExtraArgs&&...           extraArgs);
```

### <a name="parameters"></a>parâmetros

*TInterface*\
O tipo que contém a função de membro.

*TReturn*\
O tipo de retorno da função de membro.

*T1*,..., *T10*\
Os tipos que descrevem a hierarquia de eventos a serem correspondentes.

*TExtraParams*\
Os tipos dos parâmetros extras aceitos pela função de membro e os tipos de hierarquia de eventos.

*TExtraArgs*\
Os tipos dos argumentos extras que foram passados para `MatchEventStackInMemberFunction` .

*eventStack*\
A pilha de eventos para corresponder à hierarquia de tipo de evento descrita por *T1* por meio de *T10*.

*objectPtr*\
Um ponteiro para um objeto no qual *memberFunc* é chamado.

*memberFunc*\
A função de membro que descreve a hierarquia de tipo de evento para corresponder.

*extraArgs*\
Os argumentos que são encaminhados perfeitamente para *memberFunc* junto com os parâmetros de hierarquia de tipo de evento.

### <a name="return-value"></a>Valor retornado

Um **`bool`** valor que **`true`** se corresponder com êxito ou de **`false`** outra forma.

## <a name="remarks"></a>Comentários

O último evento em *eventStack* sempre é correspondido em relação à última entrada na hierarquia de tipo de evento para corresponder. Todos os outros tipos na hierarquia de tipo de evento podem corresponder a qualquer posição no *eventStack* , exceto o último, desde que eles estejam na mesma ordem.

Os tipos de evento a serem usados para os parâmetros *T1* a *T10* são selecionados em uma lista de *classes de captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para fazer a correspondência, consulte a [tabela de eventos](../event-table.md).

## <a name="example"></a>Exemplo

```cpp
void MyClass::Foo1(Compiler cl, BackEndPass bep, C2DLL c2,
    CodeGeneration cg, Thread t, Function f) { }

void MyClass::Foo2(Compiler cl, Function f) { }

void MyClass::Foo3(Thread t, Compiler cl, Function f) { }

void MyClass::Foo4(Compiler cl) { }

void MyClass::OnStartActivity(const EventStack& eventStack)
{
    // Let's assume eventStack contains:
    // [Compiler, BackEndPass, C2DLL, CodeGeneration, Thread, Function]

    bool b1 = MatchEventStackInMemberFunction(
        eventStack, this, &MyClass::Foo1);

    bool b2 = MatchEventStackInMemberFunction(
        eventStack, this, &MyClass::Foo2);

    bool b3 = MatchEventStackInMemberFunction(
        eventStack, this, &MyClass::Foo3);

    bool b4 = MatchEventStackInMemberFunction(
        eventStack, this, &MyClass::Foo4);

    // b1: true because the parameter types of Foo1 match the eventStack
    //     exactly.
    // b2: true because Function is the last entry in both the member
    //     function parameter list and 'eventStack', and also because
    //     Compiler comes before Function in 'eventStack' and in the
    //     parameter type list.
    // b3: false because, even though both Thread and Compiler come
    //     before Function in 'eventStack', the member function parameter
    //     list doesn't list them in the right order.
    // b4: false because the last entry in the member function parameter
    //     list is Compiler, which doesn't match the last entry in 'eventStack'
    //     (Function).
}
```

::: moniker-end
