---
title: TRACING_SESSION_SYSTEM_EVENT_FLAGS constantes
description: A C++ referência de constantes do SDK do insights do Build TRACING_SESSION_SYSTEM_EVENT_FLAGS.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_SYSTEM_EVENT_FLAGS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ce0b0ea373ec53f0d5bcf228269299d69b49bb95
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332351"
---
# <a name="tracing_session_system_event_flags-constants"></a>TRACING_SESSION_SYSTEM_EVENT_FLAGS constantes

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

As constantes `TRACING_SESSION_SYSTEM_EVENT_FLAGS` são usadas para descrever os eventos do sistema a serem coletados durante um rastreamento. Use-os para inicializar o campo `SystemEventFlags` da estrutura de [TRACING_SESSION_OPTIONS](tracing-session-options-struct.md) .

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

| {1&gt;Nome&lt;1} | Eventos ativados por este sinalizador |
|--|--|
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_CONTEXT` | Esse sinalizador é ativado por padrão pelo SDK C++ de informações de compilação, mesmo que não seja especificado explicitamente. Ele habilita eventos básicos do sistema que são necessários C++ para que o Build percepções funcione corretamente. Os eventos habilitados por esse sinalizador fornecem informações sobre processos, threads e carregamento de imagem. Você não pode desabilitar esses eventos. |
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES` | Exemplos de CPU |
| `TRACING_SESSION_SYSTEM_EVENT_FLAGS_ALL` | Esse sinalizador ativa todos os eventos do sistema. |

::: moniker-end
