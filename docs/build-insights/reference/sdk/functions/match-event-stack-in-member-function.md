---
title: MatchEventStackInMemberfunction
description: A referência da função C++ Build Insights SDK MatchEventStackInMemberFunction.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEventStackInMemberFunction
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 28842a02e7edc2e00266d8c7941798f4ce714ded
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323881"
---
# <a name="matcheventstackinmemberfunction"></a>MatchEventStackInMemberfunction

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MatchEventStackInMemberFunction` função é usada para corresponder a uma pilha de eventos com uma hierarquia de evento específica, descrita pela lista de parâmetros de uma função de membro. Hierarquias combinadas são encaminhadas para a função membro para posterior processamento. Para saber mais sobre eventos, pilhas de eventos e hierarquias, consulte [a tabela de eventos](../event-table.md).

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

### <a name="parameters"></a>Parâmetros

*TInterface*\
O tipo que contém a função do membro.

*Retorno*\
O tipo de retorno da função do membro.

*T1*, ..., *T10*\
Os tipos que descrevem a hierarquia de eventos para coincidir.

*TExtraParams*\
Os tipos de parâmetros extras aceitos pela função do membro e os tipos de hierarquia de eventos.

*TExtraArgs*\
Os tipos de argumentos extras `MatchEventStackInMemberFunction`que foram passados para .

*eventStack*\
A pilha de eventos para coincidir com a hierarquia do tipo de evento descrita por *T1* até *T10*.

*objectPtr*\
Um ponteiro para um objeto no qual *o membroFunc* é chamado.

*membroFunc*\
A função de membro que descreve a hierarquia do tipo de evento para corresponder.

*extraArgs*\
Os argumentos que são encaminhados perfeitamente para *o membroFunc* juntamente com os parâmetros de hierarquia do tipo de evento.

### <a name="return-value"></a>Valor retornado

Um valor **bool** que é **verdadeiro** se a correspondência foi bem sucedida, ou **falso** de outra forma.

## <a name="remarks"></a>Comentários

O último evento no *eventStack* é sempre compatível com a última entrada na hierarquia do tipo de evento para combinar. Todos os outros tipos na hierarquia do tipo de evento podem corresponder a qualquer posição no *eventStack,* exceto o último, desde que estejam na mesma ordem.

Os tipos de eventos a serem usados para os parâmetros *T1* e *T10* são selecionados a partir de uma lista de classes de *captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para combiná-los, consulte [a tabela de eventos](../event-table.md).

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
