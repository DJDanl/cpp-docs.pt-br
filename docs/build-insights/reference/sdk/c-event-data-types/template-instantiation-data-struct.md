---
title: Estrutura de TEMPLATE_INSTANTIATION_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ TEMPLATE_INSTANTIATION_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TEMPLATE_INSTANTIATION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c92fbd8ee7e1fff702757d003ab3bbe0bdabd886
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923441"
---
# <a name="template_instantiation_data-structure"></a>Estrutura de TEMPLATE_INSTANTIATION_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

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

| Nome | Descrição |
|--|--|
| `SpecializationSymbolKey` | A chave para o tipo da especialização do modelo. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `PrimaryTemplateSymbolKey` | A chave para o tipo de modelo primário que era especializado. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `KindCode` | O tipo da instanciação de modelo. Para obter mais informações, consulte [TEMPLATE_INSTANTIATION_KIND_CODE](template-instantiation-kind-code-enum.md). |

## <a name="remarks"></a>Comentários

As chaves na `TEMPLATE_INSTANTIATION_DATA` estrutura são exclusivas dentro do rastreamento que está sendo analisado. No entanto, duas chaves diferentes provenientes de diferentes passagens de front-end do compilador podem apontar para dois tipos idênticos. Ao consumir `TEMPLATE_INSTANTIATION_DATA` informações de vários passos de front-end do compilador, use os eventos [SYMBOL_NAME](../event-table.md#symbol-name) para determinar se dois tipos são os mesmos. `SymbolName` os eventos são emitidos no final de uma passagem de front-end do compilador, após a ocorrência de todas as instanciações de modelo.

::: moniker-end
