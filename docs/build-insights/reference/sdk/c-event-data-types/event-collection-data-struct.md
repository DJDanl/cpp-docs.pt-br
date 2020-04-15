---
title: EVENT_COLLECTION_DATA estrutura
description: O C++ Build Insights SDK EVENT_COLLECTION_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EVENT_COLLECTION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 88ba39ede8c86f47c2e6458332ae005eddc06fda
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325686"
---
# <a name="event_collection_data-structure"></a>EVENT_COLLECTION_DATA estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `EVENT_COLLECTION_DATA` estrutura descreve uma série de elementos [EVENT_DATA.](event-data-struct.md)

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct EVENT_COLLECTION_DATA_TAG
{
    unsigned int            Count;
    const EVENT_DATA*       Elements;

} EVENT_COLLECTION_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `Count` | O número `EVENT_DATA` de elementos na matriz. |
| `Elements` | Ponteiro para `EVENT_DATA` o primeiro elemento na matriz. |

::: moniker-end
