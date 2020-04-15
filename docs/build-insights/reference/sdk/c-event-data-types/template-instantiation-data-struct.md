---
title: estrutura TEMPLATE_INSTANTIATION_DATA
description: O C++ Build Insights SDK TEMPLATE_INSTANTIATION_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TEMPLATE_INSTANTIATION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a38d19368e7c0a9912907f1da6e7a2e31ffe8d90
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325328"
---
# <a name="template_instantiation_data-structure"></a>estrutura TEMPLATE_INSTANTIATION_DATA

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TEMPLATE_INSTANTIATION_DATA` estrutura descreve uma instanciação de modelo.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct TEMPLATE_INSTANTIATION_DATA_TAG
{
    unsigned long long  SpecializationSymbolKey;
    unsigned long long  PrimaryTemplateSymbolKey;
    int                 KindCode;

} TEMPLATE_INSTANTIATION_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `SpecializationSymbolKey` | A chave para o tipo de especialização do modelo. Esse valor é único dentro do traço que está sendo analisado. |
| `PrimaryTemplateSymbolKey` | A chave para o tipo de modelo primário que foi especializado. Esse valor é único dentro do traço que está sendo analisado. |
| `KindCode` | O tipo de instanciação do modelo. Para obter mais informações, consulte [TEMPLATE_INSTANTIATION_KIND_CODE](template-instantiation-kind-code-enum.md). |

## <a name="remarks"></a>Comentários

As chaves `TEMPLATE_INSTANTIATION_DATA` da estrutura são únicas dentro do traço que está sendo analisado. No entanto, duas teclas diferentes provenientes de passes front-end de compilador diferentes podem apontar para dois tipos idênticos. Ao `TEMPLATE_INSTANTIATION_DATA` consumir informações de vários passes front-end do compilador, use os eventos [SYMBOL_NAME](../event-table.md#symbol-name) para determinar se dois tipos são os mesmos. `SymbolName`eventos são emitidos no final de um passe front-end do compilador, depois de todas as instanciações do modelo terem ocorrido.

::: moniker-end
