---
title: TRACING_SESSION_SYSTEM_EVENT_FLAGS constantes
description: O SDK de informações de compilação do C++ TRACING_SESSION_SYSTEM_EVENT_FLAGS referência de constantes.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_SYSTEM_EVENT_FLAGS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 346c955355ffbc6c062a34bf928f16ccd3940154
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922369"
---
# <a name="tracing_session_system_event_flags-constants"></a>TRACING_SESSION_SYSTEM_EVENT_FLAGS constantes

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

As `TRACING_SESSION_SYSTEM_EVENT_FLAGS` constantes são usadas para descrever quais eventos do sistema devem ser coletados durante um rastreamento. Use-os para inicializar o campo da estrutura de [TRACING_SESSION_OPTIONS](tracing-session-options-struct.md) `SystemEventFlags` .

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

| Nome | Eventos ativados por este sinalizador |
|--|--|
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_CONTEXT` | Esse sinalizador é ativado por padrão pelo SDK de informações de compilação do C++, mesmo que não seja especificado explicitamente. Ele permite que eventos básicos do sistema que são exigidos por informações de compilação do C++ funcionem corretamente. Os eventos habilitados por esse sinalizador fornecem informações sobre processos, threads e carregamento de imagem. Você não pode desabilitar esses eventos. |
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES` | Exemplos de CPU |
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_ALL` | Esse sinalizador ativa todos os eventos do sistema. |

::: moniker-end
