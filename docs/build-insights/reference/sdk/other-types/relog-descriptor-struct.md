---
title: Estrutura de RELOG_DESCRIPTOR
description: A C++ referência da estrutura de RELOG_DESCRIPTOR do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_DESCRIPTOR
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f6f20835ed6535dd05def629200c113772e8f077
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332323"
---
# <a name="relog_descriptor-structure"></a>Estrutura de RELOG_DESCRIPTOR

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `RELOG_DESCRIPTOR` é usada com as funções [RelogA](../functions/relog-a.md) e [RelogW](../functions/relog-w.md) . Ele descreve como um rastreamento de ETW (rastreamento de eventos para Windows) deve ser registrado em log novamente.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct RELOG_DESCRIPTOR_TAG
{
    unsigned                NumberOfAnalysisPasses;
    ANALYSIS_CALLBACKS      AnalysisCallbacks;
    RELOG_CALLBACKS         RelogCallbacks;
    unsigned long long      SystemEventsRetentionFlags;
    void*                   AnalysisContext;
    void*                   RelogContext;
} RELOG_DESCRIPTOR;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `NumberOfAnalysisPasses` | O número de passagens de análise que devem ser feitas no rastreamento ETW durante a fase de análise da sessão de reregistro. |
| `AnalysisCallbacks` | Um objeto [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) que especifica quais funções chamar durante a fase de análise da sessão de reregistro em log. |
| `RelogCallbacks` | Um objeto [RELOG_CALLBACKS](relog-callbacks-struct.md) que especifica quais funções chamar durante a fase de reregistro em log da sessão de reregistro. |
| `SystemEventsRetentionFlags` | Um [RELOG_RETENTION_SYSTEM_EVENT_FLAGS](relog-retention-system-event-flags-constants.md) bitmask que especifica quais eventos de ETW do sistema manter no rastreamento de relogin. |
| `AnalysisContext` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em `AnalysisCallbacks` |
| `RelogContext` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em `RelogCallbacks` |

## <a name="remarks"></a>Comentários

O registro em log de eventos de ETW durante uma sessão de reregistro é controlado pelo usuário por meio das funções de retorno de chamada especificadas em `RelogCallbacks`. No entanto, eventos ETW do sistema, como exemplos de CPU, não são encaminhados para essas funções de retorno de chamada. Use o campo `SystemEventsRetentionFlags` para controlar o registro em log de eventos ETW do sistema.

As estruturas `AnalysisCallbacks` e `RelogCallbacks` só aceitam ponteiros para funções não membro. Você pode contornar essa limitação configurando-as para um ponteiro de objeto. Esse ponteiro de objeto será passado como um argumento para todas as suas funções de retorno de chamada de não membro. Use este ponteiro para chamar funções de membro de dentro de suas funções de retorno de chamada não membro.

A fase de análise de uma sessão de reregistro em log é sempre executada antes da fase de refazer o log.

::: moniker-end
