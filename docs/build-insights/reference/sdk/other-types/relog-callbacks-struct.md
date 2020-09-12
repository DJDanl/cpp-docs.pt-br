---
title: Estrutura de RELOG_CALLBACKS
description: A referência de estrutura do SDK do insights de compilação do C++ RELOG_CALLBACKS.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_CALLBACKS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 55f63b05691e3d729ee42ed21049669b94053559
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041426"
---
# <a name="relog_callbacks-structure"></a>Estrutura de RELOG_CALLBACKS

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `RELOG_CALLBACKS` estrutura é usada ao inicializar um objeto de [RELOG_DESCRIPTOR](relog-descriptor-struct.md) . Ele especifica quais funções chamar durante o registro em log de um rastreamento de ETW (rastreamento de eventos para Windows).

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct RELOG_CALLBACKS_TAG
{
    OnRelogEventFunc        OnStartActivity;
    OnRelogEventFunc        OnStopActivity;
    OnRelogEventFunc        OnSimpleEvent;
    OnTraceInfoFunc         OnTraceInfo;
    OnBeginEndPassFunc      OnBeginRelogging;
    OnBeginEndPassFunc      OnEndRelogging;
    OnBeginEndPassFunc      OnBeginReloggingPass;
    OnBeginEndPassFunc      OnEndReloggingPass;
} RELOG_CALLBACKS;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `OnStartActivity` | Chamado para processar um evento de início de atividade. |
| `OnStopActivity` | Chamado para processar um evento de parada de atividade. |
| `OnSimpleEvent` | Chamado para processar um evento simples. |
| `OnTraceInfo` | Chamado uma vez no início da aprovação do reregistro em log, depois que foi `OnBeginReloggingPass` chamado. |
| `OnBeginRelogging` | Chamado ao iniciar uma sessão de reregistro em log antes que a passagem de refazer o log seja iniciada. |
| `OnEndRelogging` | Chamado ao encerrar uma sessão de reregistro depois que a passagem de refazer o log for encerrada. |
| `OnBeginReloggingPass` | Chamado ao iniciar a passagem de reregistro em log antes de processar qualquer evento. |
| `OnEndReloggingPass` | Chamado ao encerrar a aprovação do reregistro em log, após o processamento de todos os eventos. |

## <a name="remarks"></a>Comentários

Todos os membros da `RELOG_CALLBACKS` estrutura devem apontar para uma função válida. Para obter mais informações sobre as assinaturas de função aceitas, consulte [OnRelogEventFunc](on-relog-event-func-typedef.md), [OnTraceInfoFunc](on-trace-info-func-typedef.md)e [OnBeginEndPassFunc](on-begin-end-pass-func-typedef.md).

::: moniker-end
