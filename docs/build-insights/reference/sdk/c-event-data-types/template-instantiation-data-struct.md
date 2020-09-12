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
ms.openlocfilehash: 15bbb25c3abac339201179e763bffd916dba0480
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040867"
---
# <a name="template_instantiation_data-structure"></a>Estrutura de TEMPLATE_INSTANTIATION_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

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

| Nome | Descrição |
|--|--|
| `SpecializationSymbolKey` | A chave para o tipo da especialização do modelo. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `PrimaryTemplateSymbolKey` | A chave para o tipo de modelo primário que era especializado. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `KindCode` | O tipo da instanciação de modelo. Para obter mais informações, consulte [TEMPLATE_INSTANTIATION_KIND_CODE](template-instantiation-kind-code-enum.md). |

## <a name="remarks"></a>Comentários

As chaves na `TEMPLATE_INSTANTIATION_DATA` estrutura são exclusivas dentro do rastreamento que está sendo analisado. No entanto, duas chaves diferentes provenientes de diferentes passagens de front-end do compilador podem apontar para dois tipos idênticos. Ao consumir `TEMPLATE_INSTANTIATION_DATA` informações de vários passos de front-end do compilador, use os eventos [SYMBOL_NAME](../event-table.md#symbol-name) para determinar se dois tipos são os mesmos. `SymbolName` os eventos são emitidos no final de uma passagem de front-end do compilador, após a ocorrência de todas as instanciações de modelo.

::: moniker-end
