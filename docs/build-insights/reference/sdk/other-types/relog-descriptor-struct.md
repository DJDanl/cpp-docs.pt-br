---
title: RELOG_DESCRIPTOR estrutura
description: O C++ Build Insights SDK RELOG_DESCRIPTOR referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_DESCRIPTOR
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c3aee49fe9f609ca37082693ddcfd5e838cc96a1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328946"
---
# <a name="relog_descriptor-structure"></a>RELOG_DESCRIPTOR estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `RELOG_DESCRIPTOR` estrutura é usada com as funções [RelogA](../functions/relog-a.md) e [RelogW.](../functions/relog-w.md) Ele descreve como um rastreamento de rastreamento de eventos para Windows (ETW) deve ser relocado.

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
| `NumberOfAnalysisPasses` | O número de análises passa que deve ser feito sobre o rastreamento eTW durante a fase de análise da sessão de relogging. |
| `AnalysisCallbacks` | Um [objeto ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) que especifica quais funções chamar durante a fase de análise da sessão de relogging. |
| `RelogCallbacks` | Um [objeto RELOG_CALLBACKS](relog-callbacks-struct.md) que especifica quais funções chamar durante a fase de relogamento da sessão de relogging. |
| `SystemEventsRetentionFlags` | Uma [RELOG_RETENTION_SYSTEM_EVENT_FLAGS](relog-retention-system-event-flags-constants.md) bitmask que especifica quais eventos de ETW do sistema para manter no rastreamento relocado. |
| `AnalysisContext` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em`AnalysisCallbacks` |
| `RelogContext` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em`RelogCallbacks` |

## <a name="remarks"></a>Comentários

O relogamento de eventos ETW durante uma sessão de relogamento é `RelogCallbacks`controlado pelo usuário através das funções de retorno de chamada especificadas em . No entanto, eventos de ETW do sistema, como amostras de CPU, não são encaminhados para essas funções de retorno de chamada. Use `SystemEventsRetentionFlags` o campo para controlar o relogamento de eventos ETW do sistema.

As `AnalysisCallbacks` `RelogCallbacks` estruturas e as estruturas só aceitam ponteiros para funções não-membros. Você pode contornar essa limitação definindo-as como um ponteiro de objeto. Este ponteiro de objeto será passado como um argumento para todas as suas funções de retorno de chamada não-membros. Use este ponteiro para chamar funções de membro de dentro de suas funções de retorno de chamada não-membros.

A fase de análise de uma sessão de relogging é sempre executada antes da fase de relogamento.

::: moniker-end
