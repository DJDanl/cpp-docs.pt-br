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
ms.openlocfilehash: 17daaa6feb784c501d180a982cd4ad2b405ccf67
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921081"
---
# <a name="event_collection_data-structure"></a>Estrutura de EVENT_COLLECTION_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

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
