---
title: estrutura TRACE_INFO_DATA
description: O C++ Build Insights SDK TRACE_INFO_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACE_INFO_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 70ae17a376f79cad7a669d81e482f551afd0ec62
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325271"
---
# <a name="trace_info_data-structure"></a>estrutura TRACE_INFO_DATA

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TRACE_INFO_DATA` estrutura descreve um traço sendo analisado ou relogado.

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

|  |  |
|--|--|
| `LogicalProcessorCount` | O número de processadores lógicos na máquina onde o rastreamento foi coletado. |
| `TickFrequency` | O número de carrapatos por segundo a ser usado ao avaliar uma duração medida em carrapatos. |
| `StartTimestamp` | Este campo é definido como um valor de tique-taque capturado no momento em que o rastreamento foi iniciado. |
| `StopTimestamp` | Este campo é definido como um valor de tique-taque capturado no momento em que o traço foi interrompido. |

## <a name="remarks"></a>Comentários

`StartTimestamp` Subtraia `StopTimestamp` para obter o número de carrapatos decorridos durante todo o traço. Use `TickFrequency` para converter o valor resultante em uma unidade de tempo. Para um exemplo que converte carrapatos em unidades de tempo, veja [EVENT_DATA](event-data-struct.md).

::: moniker-end
