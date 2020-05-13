---
title: RELOG_RETENTION_SYSTEM_EVENT_FLAGS constantes
description: O C++ Build Insights SDK RELOG_RETENTION_SYSTEM_EVENT_FLAGS referência de constantes.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_RETENTION_SYSTEM_EVENT_FLAGS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7110f809a819357b31951c203c1fa6ac9fb9f42e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323464"
---
# <a name="relog_retention_system_event_flags-constants"></a>RELOG_RETENTION_SYSTEM_EVENT_FLAGS constantes

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

As `RELOG_RETENTION_SYSTEM_EVENT_FLAGS` constantes são usadas para descrever quais eventos do sistema manter em um traço relocou. Use-os para inicializar o `SystemEventsRetentionFlags` campo da [estrutura RELOG_DESCRIPTOR.](relog-descriptor-struct.md)

## <a name="syntax"></a>Sintaxe

```cpp
static const unsigned long long
    RELOG_RETENTION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES = 0x1ULL;

static const unsigned long long
    RELOG_RETENTION_SYSTEM_EVENT_FLAGS_ALL         = 0xFFFFFFFFFFFFFFFFULL;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `RELOG_RETENTION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES` | Mantenha os eventos do sistema de amostra da CPU em um rastreamento relocou. |
| `RELOG_RETENTION_SYSTEM_EVENT_FLAGS_ALL` | Mantenha todos os eventos do sistema em um rastro relogado. |

## <a name="remarks"></a>Comentários

::: moniker-end
