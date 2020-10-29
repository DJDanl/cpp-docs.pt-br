---
title: Estrutura de NAME_VALUE_PAIR_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ NAME_VALUE_PAIR_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- NAME_VALUE_PAIR_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: bab9f7ccedc4a94478d50863f2fae248722468e2
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923548"
---
# <a name="name_value_pair_data-structure"></a>Estrutura de NAME_VALUE_PAIR_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `NAME_VALUE_PAIR_DATA` estrutura descreve um par de nome e valor.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct NAME_VALUE_PAIR_DATA_TAG
{
    const wchar_t*      Name;
    const wchar_t*      Value;
} NAME_VALUE_PAIR_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Name` | O nome. |
| `Value` | O valor. |

::: moniker-end
