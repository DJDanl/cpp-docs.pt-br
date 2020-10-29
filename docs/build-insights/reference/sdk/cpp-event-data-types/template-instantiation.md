---
title: Classe TemplateInstantiation
description: A referência de classe do SDK do TemplateInstantiation de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TemplateInstantiation
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7ff03aaa431f5c5e217f605698a255686411b479
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920431"
---
# <a name="templateinstantiation-class"></a>Classe TemplateInstantiation

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `TemplateInstantiation` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [TEMPLATE_INSTANTIATION](../event-table.md#template-instantiation) .

## <a name="syntax"></a>Sintaxe

```cpp
class TemplateInstantiation : public Activity
{
public:
    enum class Kind
    {
        CLASS       = TEMPLATE_INSTANTIATION_KIND_CODE_CLASS,
        FUNCTION    = TEMPLATE_INSTANTIATION_KIND_CODE_FUNCTION,
        VARIABLE    = TEMPLATE_INSTANTIATION_KIND_CODE_VARIABLE,
        CONCEPT     = TEMPLATE_INSTANTIATION_KIND_CODE_CONCEPT
    };

    TemplateInstantiation(const RawEvent& event);

    const unsigned long long& SpecializationSymbolKey() const;
    const unsigned long long& PrimaryTemplateSymbolKey() const;

    Kind Kind() const;
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `TemplateInstantiation` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[TemplateInstantiation](#template-instantiation)

### <a name="functions"></a>Funções

[Tipo](#kind) 
 [PrimaryTemplateSymbolKey](#primary-template-symbol-key) 
 [SpecializationSymbolKey](#specialization-symbol-key)

## <a name="kind"></a><a name="kind"></a> Quase

```cpp
Kind Kind() const;
```

### <a name="return-value"></a>Valor Retornado

Um código que descreve o tipo de instanciação de modelo que foi feito.

## <a name="primarytemplatesymbolkey"></a><a name="primary-template-symbol-key"></a> PrimaryTemplateSymbolKey

```cpp
const unsigned long long& PrimaryTemplateSymbolKey() const;
```

### <a name="return-value"></a>Valor Retornado

Um identificador numérico para o tipo de modelo que era especializado. Esse identificador é exclusivo em uma passagem de front-end do compilador.

## <a name="specializationsymbolkey"></a><a name="specialization-symbol-key"></a> SpecializationSymbolKey

```cpp
const unsigned long long& SpecializationSymbolKey() const;
```

### <a name="return-value"></a>Valor Retornado

Um identificador numérico para o tipo da especialização. Esse identificador é exclusivo em uma passagem de front-end do compilador.

## <a name="templateinstantiation"></a><a name="template-instantiation"></a> TemplateInstantiation

```cpp
TemplateInstantiation(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [TEMPLATE_INSTANTIATION](../event-table.md#template-instantiation) .

::: moniker-end
