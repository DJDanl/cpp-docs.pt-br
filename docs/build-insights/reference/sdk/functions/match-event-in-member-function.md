---
title: MatchEventInMemberFunction
description: A C++ referência da função MATCHEVENTINMEMBERFUNCTION do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MatchEventInMemberFunction
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: eabbb8a91609b1447ebcc19af32df2ffed347c24
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332799"
---
# <a name="matcheventinmemberfunction"></a>MatchEventInMemberFunction

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `MatchEventInMemberFunction` é usada para corresponder a um evento em relação ao tipo descrito pelo primeiro parâmetro de uma função de membro. O evento MATCHED é encaminhado para a função membro para processamento adicional.

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

\ *TInterface*
O tipo que contém a função de membro.

\ *TReturn*
O tipo de retorno da função de membro.

\ *TEvent*
O tipo do evento a ser correspondido.

\ *TExtraParams*
Os tipos dos parâmetros extras aceitos pela função de membro junto com o tipo de evento a ser correspondido.

\ *TExtraArgs*
Os tipos dos argumentos extras que foram passados para `MatchEventInMemberFunction`.

*event*\
O evento a ser correspondido em relação ao tipo de evento descrito por *TEvent*.

\ *objectPtr*
Um ponteiro para um objeto no qual *memberFunc* é chamado.

\ *memberFunc*
A função de membro que descreve o tipo de evento a ser correspondido.

\ *extraArgs*
Os argumentos que são encaminhados perfeitamente para *memberFunc* junto com o parâmetro de tipo de evento.

### <a name="return-value"></a>Valor retornado

Um valor **bool** que será **true** se a correspondência for bem-sucedida ou **false** caso contrário.

## <a name="remarks"></a>Comentários

O tipo de evento a ser usado para o parâmetro *TEvent* pode ser selecionado em uma lista de *classes de captura*. Para obter uma lista de eventos e as classes de captura que você pode usar para fazer a correspondência, consulte a [tabela de eventos](../event-table.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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
