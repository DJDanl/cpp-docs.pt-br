---
title: MatcheventInMemberfunction
description: A referência da função C++ Build Insights SDK MatchEventEventInMemberFunction.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEventInMemberFunction
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 522630da16e3f4a1294316d88140f4bc25dca2c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323895"
---
# <a name="matcheventinmemberfunction"></a>MatcheventInMemberfunction

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MatchEventInMemberFunction` função é usada para corresponder a um evento com o tipo descrito pelo primeiro parâmetro de uma função de membro. O evento combinado é encaminhado para a função de membro para posterior processamento.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename     TInterface,
    typename     TReturn,
    typename     TEvent,
    typename...  TExtraParams,
    typename...  TExtraArgs>
bool MatchEventInMemberFunction(
    const RawEvent&          event,
    TInterface*              objectPtr,
    TReturn (TInterface::*   memberFunc)(TEvent, TExtraParams...),
    TExtraArgs&&...          extraArgs);
```

### <a name="parameters"></a>Parâmetros

*TInterface*\
O tipo que contém a função do membro.

*Retorno*\
O tipo de retorno da função do membro.

*Tevent*\
O tipo de evento para combinar.

*TExtraParams*\
Os tipos de parâmetros extras aceitos pela função do membro juntamente com o tipo de evento para combinar.

*TExtraArgs*\
Os tipos de argumentos extras `MatchEventInMemberFunction`que foram passados para .

*Evento*\
O evento para combinar com o tipo de evento descrito por *TEvent*.

*objectPtr*\
Um ponteiro para um objeto no qual *o membroFunc* é chamado.

*membroFunc*\
A função de membro que descreve o tipo de evento a corresponder.

*extraArgs*\
Os argumentos que são encaminhados perfeitamente para *o membroFunc* juntamente com o parâmetro de tipo de evento.

### <a name="return-value"></a>Valor retornado

Um valor **bool** que é **verdadeiro** se a correspondência foi bem sucedida, ou **falso** de outra forma.

## <a name="remarks"></a>Comentários

O tipo de evento a ser usado para o parâmetro *TEvent* pode ser selecionado a partir de uma lista de classes de *captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para combiná-los, consulte [a tabela de eventos](../event-table.md).

## <a name="example"></a>Exemplo

```cpp
void MyClass::Foo1(Function f) {}

void MyClass::Foo2(Compiler cl) {}

void MyClass::OnStartActivity(const EventStack& eventStack)
{
    // Let's assume eventStack contains:
    // [Compiler, BackEndPass, C2DLL, CodeGeneration, Thread, Function]

    auto& functionEvent = eventStack.Back(); // The Function event

    bool b1 = MatchEventInMemberFunction(
        functionEvent, this, &MyClass::Foo1);

    bool b2 = MatchEventInMemberFunction(
        functionEvent, this, &MyClass::Foo2);

    // b1: true because the first parameter of Foo1 is Function.
    // b2: false because the first parameter of Foo2 isn't Function.
}
```

::: moniker-end
