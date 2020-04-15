---
title: TRACING_SESSION_SYSTEM_EVENT_FLAGS constantes
description: O C++ Build Insights SDK TRACING_SESSION_SYSTEM_EVENT_FLAGS referência de constantes.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_SYSTEM_EVENT_FLAGS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 264d697cc905eb6b44c8ec7de835a552976f0eb8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323282"
---
# <a name="tracing_session_system_event_flags-constants"></a>TRACING_SESSION_SYSTEM_EVENT_FLAGS constantes

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

As `TRACING_SESSION_SYSTEM_EVENT_FLAGS` constantes são usadas para descrever quais eventos do sistema devem ser coletados durante um rastreamento. Use-os para inicializar o `SystemEventFlags` campo da estrutura [TRACING_SESSION_OPTIONS.](tracing-session-options-struct.md)

## <a name="syntax"></a>Sintaxe

```cpp
static const unsigned long long
    TRACING_SESSION_SYSTEM_EVENT_FLAGS_CONTEXT      = 0x1ULL;

static const unsigned long long
    TRACING_SESSION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES  = 0x2ULL;

static const unsigned long long
    TRACING_SESSION_SYSTEM_EVENT_FLAGS_ALL          = 0xFFFFFFFFFFFFFFFFULL;
```

## <a name="members"></a>Membros

| Nome | Eventos ligados por esta bandeira |
|--|--|
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_CONTEXT` | Este sinalizador é ativado por padrão pelo C++ Build Insights SDK, mesmo que não seja especificado explicitamente. Ele permite que eventos básicos do sistema que são exigidos pelo C++ Build Insights funcionem corretamente. Os eventos habilitados por este sinalizador fornecem informações sobre processos, threads e carregamento de imagens. Você não pode desativar esses eventos. |
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES` | Amostras de CPU |
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_ALL` | Esta bandeira liga todos os eventos do sistema. |

::: moniker-end
