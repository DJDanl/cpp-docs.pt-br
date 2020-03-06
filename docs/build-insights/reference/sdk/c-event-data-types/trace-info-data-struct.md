---
title: Estrutura de TRACE_INFO_DATA
description: A C++ referência da estrutura de TRACE_INFO_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACE_INFO_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 04cb5c013bca8879507983d169b38e5af0f1322b
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333583"
---
# <a name="trace_info_data-structure"></a>Estrutura de TRACE_INFO_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `TRACE_INFO_DATA` descreve um rastreamento que está sendo analisado ou registrado novamente.

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
| `LogicalProcessorCount` | O número de processadores lógicos no computador em que o rastreamento foi coletado. |
| `TickFrequency` | O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques. |
| `StartTimestamp` | Esse campo é definido como um valor de tique capturado no momento em que o rastreamento foi iniciado. |
| `StopTimestamp` | Esse campo é definido como um valor de tique capturado no momento em que o rastreamento foi interrompido. |

## <a name="remarks"></a>Comentários

Subtraia `StartTimestamp` de `StopTimestamp` para obter o número de tiques decorridos durante todo o rastreamento. Use `TickFrequency` para converter o valor resultante em uma unidade de tempo. Para obter um exemplo que converte tiques em unidades de tempo, consulte [EVENT_DATA](event-data-struct.md).

::: moniker-end
