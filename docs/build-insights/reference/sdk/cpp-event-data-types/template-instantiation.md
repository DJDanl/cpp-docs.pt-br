---
title: Classe de instantie de modelo
description: A referência da classe C++ Build Insights SDK Template Instantiation.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TemplateInstantiation
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ba8fd10efc6a536c9160f10b19e19e17bfaaad98
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324228"
---
# <a name="templateinstantiation-class"></a>Classe de instantie de modelo

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TemplateInstantiation` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [TEMPLATE_INSTANTIATION.](../event-table.md#template-instantiation)

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

Juntamente com os membros herdados de `TemplateInstantiation` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Instantiação do modelo](#template-instantiation)

### <a name="functions"></a>Funções

[Tipo](#kind)
[PrimaryTemplateSymbolKey](#primary-template-symbol-key)
[SpecializationSymbolKeyKeyKey](#specialization-symbol-key)

## <a name="kind"></a><a name="kind"></a>Tipo

```cpp
Kind Kind() const;
```

### <a name="return-value"></a>Valor retornado

Um código descrevendo o tipo de instanciação do modelo que foi feito.

## <a name="primarytemplatesymbolkey"></a><a name="primary-template-symbol-key"></a>Chave símbolo de modelo principal

```cpp
const unsigned long long& PrimaryTemplateSymbolKey() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador numérico para o tipo de modelo especializado. Este identificador é único dentro de um passe front-end do compilador.

## <a name="specializationsymbolkey"></a><a name="specialization-symbol-key"></a>SpecializationSymbolKey

```cpp
const unsigned long long& SpecializationSymbolKey() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador numérico para o tipo de especialização. Este identificador é único dentro de um passe front-end do compilador.

## <a name="templateinstantiation"></a><a name="template-instantiation"></a>Instantiação do modelo

```cpp
TemplateInstantiation(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [TEMPLATE_INSTANTIATION.](../event-table.md#template-instantiation)

::: moniker-end
