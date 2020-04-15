---
title: Classe Template InstantiationGroup
description: A referência de classe C++ Build Insights SDK SDK InstantiationGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TemplateInstantiationGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 18dd48219c7c68ce152c381eb505fe37b19ec8dd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324266"
---
# <a name="templateinstantiationgroup-class"></a>Classe Template InstantiationGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TemplateInstantiationGroup` classe é usada com as funções [MatchEventStackStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar grupos de [eventos TEMPLATE_INSTANTIATION.](../event-table.md#template-instantiation)

## <a name="syntax"></a>Sintaxe

```cpp
class TemplateInstantiationGroup : public EventGroup<TemplateInstantiation>
{
public:
    TemplateInstantiationGroup(std::deque<TemplateInstantiation>&& group);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de sua classe `TemplateInstantiationGroup` base [EventGroup\<\> TemplateInstantiation,](event-group.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[TemplateInstantiationGroup](#template-instantiation-group)

## <a name="templateinstantiationgroup"></a><a name="template-instantiation-group"></a>TemplateInstantiationGroup

```cpp
TemplateInstantiationGroup(std::deque<TemplateInstantiation>&& group);
```

### <a name="parameters"></a>Parâmetros

*Grupo*\
Um grupo de [eventos TEMPLATE_INSTANTIATION.](../event-table.md#template-instantiation)

::: moniker-end
