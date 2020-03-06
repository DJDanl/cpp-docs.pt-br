---
title: Estrutura de EVENT_COLLECTION_DATA
description: A C++ referência da estrutura de EVENT_COLLECTION_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EVENT_COLLECTION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1a622a8459b6aa6d9dcbe0faaf90ae545b449466
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333807"
---
# <a name="event_collection_data-structure"></a>Estrutura de EVENT_COLLECTION_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `EVENT_COLLECTION_DATA` descreve uma matriz de elementos de [EVENT_DATA](event-data-struct.md) .

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
| `Count` | O número de elementos `EVENT_DATA` na matriz. |
| `Elements` | Ponteiro para o primeiro elemento `EVENT_DATA` na matriz. |

::: moniker-end
