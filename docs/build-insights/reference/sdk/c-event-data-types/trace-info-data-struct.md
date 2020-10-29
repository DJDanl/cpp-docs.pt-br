---
title: Estrutura de TRACE_INFO_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ TRACE_INFO_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACE_INFO_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ce6301b168aed9f279fc7aaee9aa3a97221fd23a
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923431"
---
# <a name="trace_info_data-structure"></a>Estrutura de TRACE_INFO_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `TRACE_INFO_DATA` estrutura descreve um rastreamento que está sendo analisado ou registrado novamente.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct TRACE_INFO_DATA_TAG
{
    unsigned long           LogicalProcessorCount;
    long long               TickFrequency;
    long long               StartTimestamp;
    long long               StopTimestamp;

} TRACE_INFO_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `LogicalProcessorCount` | O número de processadores lógicos no computador em que o rastreamento foi coletado. |
| `TickFrequency` | O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques. |
| `StartTimestamp` | Esse campo é definido como um valor de tique capturado no momento em que o rastreamento foi iniciado. |
| `StopTimestamp` | Esse campo é definido como um valor de tique capturado no momento em que o rastreamento foi interrompido. |

## <a name="remarks"></a>Comentários

Subtraia `StartTimestamp` de `StopTimestamp` para obter o número de tiques decorridos durante todo o rastreamento. Use `TickFrequency` para converter o valor resultante em uma unidade de tempo. Para obter um exemplo que converte tiques em unidades de tempo, consulte [EVENT_DATA](event-data-struct.md).

::: moniker-end
