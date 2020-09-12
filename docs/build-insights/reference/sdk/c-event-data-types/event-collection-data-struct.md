---
title: Estrutura de EVENT_COLLECTION_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ EVENT_COLLECTION_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EVENT_COLLECTION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 58be46d31af154bfe7ecef5c440092eaafdcbb0f
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039593"
---
# <a name="event_collection_data-structure"></a>Estrutura de EVENT_COLLECTION_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `EVENT_COLLECTION_DATA` estrutura descreve uma matriz de elementos de [EVENT_DATA](event-data-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct EVENT_COLLECTION_DATA_TAG
{
    unsigned int            Count;
    const EVENT_DATA*       Elements;

} EVENT_COLLECTION_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Count` | O número de `EVENT_DATA` elementos na matriz. |
| `Elements` | Ponteiro para o primeiro `EVENT_DATA` elemento na matriz. |

::: moniker-end
