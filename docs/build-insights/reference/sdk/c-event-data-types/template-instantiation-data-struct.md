---
title: Estrutura de TEMPLATE_INSTANTIATION_DATA
description: A C++ referência da estrutura de TEMPLATE_INSTANTIATION_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TEMPLATE_INSTANTIATION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 9aa669d715dbe56ce7e889330f46f307f520710f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333618"
---
# <a name="template_instantiation_data-structure"></a>Estrutura de TEMPLATE_INSTANTIATION_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `TEMPLATE_INSTANTIATION_DATA` descreve uma instanciação de modelo.

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
| `SpecializationSymbolKey` | A chave para o tipo da especialização do modelo. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `PrimaryTemplateSymbolKey` | A chave para o tipo de modelo primário que era especializado. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `KindCode` | O tipo da instanciação de modelo. Para obter mais informações, consulte [TEMPLATE_INSTANTIATION_KIND_CODE](template-instantiation-kind-code-enum.md). |

## <a name="remarks"></a>Comentários

As chaves na estrutura de `TEMPLATE_INSTANTIATION_DATA` são exclusivas dentro do rastreamento que está sendo analisado. No entanto, duas chaves diferentes provenientes de diferentes passagens de front-end do compilador podem apontar para dois tipos idênticos. Ao consumir `TEMPLATE_INSTANTIATION_DATA` informações de vários passos de front-end do compilador, use os eventos de [SYMBOL_NAME](../event-table.md#symbol-name) para determinar se dois tipos são os mesmos. `SymbolName` eventos são emitidos no final de uma passagem de front-end do compilador, após a ocorrência de todas as instanciações de modelo.

::: moniker-end
