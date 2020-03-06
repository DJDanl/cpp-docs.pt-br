---
title: RELOG_RETENTION_SYSTEM_EVENT_FLAGS constantes
description: A C++ referência de constantes do SDK do insights do Build RELOG_RETENTION_SYSTEM_EVENT_FLAGS.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_RETENTION_SYSTEM_EVENT_FLAGS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 74afc10faa26ba39a669a05aa3e3cabd1a211293
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332316"
---
# <a name="relog_retention_system_event_flags-constants"></a>RELOG_RETENTION_SYSTEM_EVENT_FLAGS constantes

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

As constantes `RELOG_RETENTION_SYSTEM_EVENT_FLAGS` são usadas para descrever quais eventos do sistema devem ser mantidos em um rastreamento reregistrado. Use-os para inicializar o campo `SystemEventsRetentionFlags` da estrutura de [RELOG_DESCRIPTOR](relog-descriptor-struct.md) .

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
| `RELOG_RETENTION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES` | Mantenha os eventos do sistema de exemplo da CPU em um rastreamento reregistrado. |
| `RELOG_RETENTION_SYSTEM_EVENT_FLAGS_ALL` | Manter todos os eventos do sistema em um rastreamento reregistrado. |

## <a name="remarks"></a>Comentários

::: moniker-end
