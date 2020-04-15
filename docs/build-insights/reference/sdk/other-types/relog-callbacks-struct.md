---
title: estrutura RELOG_CALLBACKS
description: O C++ Build Insights SDK RELOG_CALLBACKS referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_CALLBACKS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 60e7db81a48731090a23b82332704a79a51e97df
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328966"
---
# <a name="relog_callbacks-structure"></a>estrutura RELOG_CALLBACKS

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `RELOG_CALLBACKS` estrutura é usada ao inicializar um [objeto RELOG_DESCRIPTOR.](relog-descriptor-struct.md) Ele especifica quais funções chamar durante o relogamento de um rastreamento de rastreamento de eventos para Windows (ETW).

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

|  |  |
|--|--|
| `OnStartActivity` | Chamado para processar um evento de início de atividade. |
| `OnStopActivity` | Chamado para processar um evento de parada de atividades. |
| `OnSimpleEvent` | Chamado para processar um evento simples. |
| `OnTraceInfo` | Chamado uma vez no início do `OnBeginReloggingPass` passe de relogging, depois foi chamado. |
| `OnBeginRelogging` | Chamado ao iniciar uma sessão de relogamento, antes do passe de relogamento ter começado. |
| `OnEndRelogging` | Chamado ao encerrar uma sessão de relogamento, após o término do passe de relogging. |
| `OnBeginReloggingPass` | Chamado ao iniciar o relogging pass, antes de processar qualquer evento. |
| `OnEndReloggingPass` | Chamado ao terminar o relogging pass, depois de processar todos os eventos. |

## <a name="remarks"></a>Comentários

Todos os `RELOG_CALLBACKS` membros da estrutura devem apontar para uma função válida. Para obter mais informações sobre as assinaturas da função aceita, consulte [OnRelogEventFunc,](on-relog-event-func-typedef.md) [OnTraceInfoFunc](on-trace-info-func-typedef.md)e [OnBeginEndPassFunc](on-begin-end-pass-func-typedef.md).

::: moniker-end
