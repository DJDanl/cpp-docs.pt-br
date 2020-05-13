---
title: ANALYSIS_CALLBACKS estrutura
description: O C++ Build Insights SDK ANALYSIS_CALLBACKS referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ANALYSIS_CALLBACKS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3c6de999b19657f999f884075ee53e21a4d2f2b5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323495"
---
# <a name="analysis_callbacks-structure"></a>ANALYSIS_CALLBACKS estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ANALYSIS_CALLBACKS` estrutura é usada ao inicializar um [objeto ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR.](relog-descriptor-struct.md) Ele especifica quais funções chamar durante a análise ou relogamento de um rastreamento de rastreamento de eventos para Windows (ETW).

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct ANALYSIS_CALLBACKS_TAG
{
    OnAnalysisEventFunc     OnStartActivity;
    OnAnalysisEventFunc     OnStopActivity;
    OnAnalysisEventFunc     OnSimpleEvent;
    OnTraceInfoFunc         OnTraceInfo;
    OnBeginEndPassFunc      OnBeginAnalysis;
    OnBeginEndPassFunc      OnEndAnalysis;
    OnBeginEndPassFunc      OnBeginAnalysisPass;
    OnBeginEndPassFunc      OnEndAnalysisPass;
} ANALYSIS_CALLBACKS;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `OnStartActivity` | Chamado para processar um evento de início de atividade. |
| `OnStopActivity` | Chamado para processar um evento de parada de atividades. |
| `OnSimpleEvent` | Chamado para processar um evento simples. |
| `OnTraceInfo` | Para sessões de análise, chamadas no início de cada análise passam. Para sessões de relogamento, chamadas no início de cada passe de análise, e novamente no início do passe de relogging. Esta função só é chamada depois que o OnBeginAnalysisPass foi chamado. |
| `OnBeginAnalysis` | Para sessões de análise, chamadas antes de qualquer análise passar. Para sessões de relogging, convocadas duas vezes antes do início da fase de análise: uma vez para anunciar o início da sessão de relogging, e mais uma vez para anunciar o início da fase de análise. |
| `OnEndAnalysis` | Para sessões de análise, essa função é chamada depois que todos os passes de análise terminarem. Para sessões de relogamento, essa função é chamada quando todas as análises da fase de análise terminarem. Então, é chamado novamente depois que o passe de relogging terminou. |
| `OnBeginAnalysisPass` | Chamado ao iniciar um passe de análise ou o passe de relogamento, antes de processar qualquer evento. |
| `OnEndAnalysisPass` | Chamado ao terminar um passe de análise ou o passe de relogging, depois de processar todos os eventos. |

## <a name="remarks"></a>Comentários

A fase de análise de uma sessão de relogging é considerada parte da sessão de relogging, podendo conter vários passes de análise. Por essa `OnBeginAnalysis` razão, é chamado duas vezes seguidas no início de uma sessão de relogamento. `OnEndAnalysis`é chamado no final da fase de análise, antes de iniciar a fase de relogamento, e mais uma vez no final da fase de relogamento. A fase de relogamento contém sempre um único passe de relogging.

É possível que os analisadores participem tanto da análise quanto da fase de relogging de uma sessão de relogging. Esses analisadores podem determinar qual fase está em andamento mantendo `OnEndAnalysis` o controle dos pares onBeginAnalysis e call. Duas `OnBeginAnalysis` chamadas `OnEndAnalysis` sem nenhuma chamada significa que a fase de análise está em andamento. Duas `OnBeginAnalysis` chamadas `OnEndAnalysis` e uma chamada significa que a fase de relogamento está em andamento. Duas OnBeginAnalysis `OnEndAnalysis` e duas chamadas significam que ambas as fases terminaram.

Todos os `ANALYSIS_CALLBACKS` membros da estrutura devem apontar para uma função válida. Para obter mais informações sobre as assinaturas da função aceita, consulte [OnAnalysisEventFunc,](on-analysis-event-func-typedef.md) [OnTraceInfoFunc](on-trace-info-func-typedef.md)e [OnBeginEndPassFunc](on-begin-end-pass-func-typedef.md).

::: moniker-end
