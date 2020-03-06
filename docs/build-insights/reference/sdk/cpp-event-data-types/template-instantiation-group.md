---
title: Classe TemplateInstantiationGroup
description: A C++ referência da classe build do SDK do insights TemplateInstantiationGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TemplateInstantiationGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 281088b4c6cbd39b2fb7677180a7966b490ec3ac
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332988"
---
# <a name="templateinstantiationgroup-class"></a>Classe TemplateInstantiationGroup

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `TemplateInstantiationGroup` é usada com as funções [MatchEventStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para fazer a correspondência de grupos de eventos de [TEMPLATE_INSTANTIATION](../event-table.md#template-instantiation) .

## <a name="syntax"></a>Sintaxe

```cpp
class TemplateInstantiationGroup : public EventGroup<TemplateInstantiation>
{
public:
    TemplateInstantiationGroup(std::deque<TemplateInstantiation>&& group);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de seu [TemplateInstantiation de evento\<\>](event-group.md) classe base, a classe `TemplateInstantiationGroup` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[TemplateInstantiationGroup](#template-instantiation-group)

## <a name="template-instantiation-group"></a>TemplateInstantiationGroup

```cpp
TemplateInstantiationGroup(std::deque<TemplateInstantiation>&& group);
```

### <a name="parameters"></a>Parâmetros

\ de *grupo*
Um grupo de eventos de [TEMPLATE_INSTANTIATION](../event-table.md#template-instantiation) .

::: moniker-end
