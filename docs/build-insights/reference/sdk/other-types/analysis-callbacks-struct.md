---
title: Estrutura de ANALYSIS_CALLBACKS
description: A referência de estrutura do SDK do insights de compilação do C++ ANALYSIS_CALLBACKS.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ANALYSIS_CALLBACKS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3fae97370ff9366ffc2fbd8d046a73c30125e554
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919924"
---
# <a name="analysis_callbacks-structure"></a>Estrutura de ANALYSIS_CALLBACKS

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `ANALYSIS_CALLBACKS` estrutura é usada ao inicializar um objeto de [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md) . Ele especifica quais funções chamar durante a análise ou o registro em log de um rastreamento de ETW (rastreamento de eventos para Windows).

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

| Nome | Descrição |
|--|--|
| `OnStartActivity` | Chamado para processar um evento de início de atividade. |
| `OnStopActivity` | Chamado para processar um evento de parada de atividade. |
| `OnSimpleEvent` | Chamado para processar um evento simples. |
| `OnTraceInfo` | Para sessões de análise, chamadas no início de cada passagem de análise. Para fazer logon em sessões, chamadas no início de cada passagem de análise e novamente no início da passagem de novo registro em log. Essa função é chamada somente depois que OnBeginAnalysisPass tiver sido chamado. |
| `OnBeginAnalysis` | Para sessões de análise, chamadas antes de qualquer passagem de análise ter começado. Para sessões de reregistro em log, chamadas duas vezes antes da fase de análise ter começado: uma vez para anunciar o início da sessão de reregistro e mais uma vez para anunciar o início da fase de análise. |
| `OnEndAnalysis` | Para sessões de análise, essa função é chamada após a finalização de todos os passos de análise. Para sessões de reregistro em log, essa função é chamada quando todas as etapas de análise da fase de análise terminam. Em seguida, ele é chamado novamente depois que a passagem de refazer o log for encerrada. |
| `OnBeginAnalysisPass` | Chamado ao iniciar uma passagem de análise ou a passagem de reregistro em log antes de processar qualquer evento. |
| `OnEndAnalysisPass` | Chamado ao encerrar uma passagem de análise ou a passagem de reregistro em log após o processamento de todos os eventos. |

## <a name="remarks"></a>Comentários

A fase de análise de uma sessão de reregistro em log é considerada parte da sessão de reregistro em log e pode conter várias passagens de análise. Por esse motivo, `OnBeginAnalysis` é chamado duas vezes em uma linha no início de uma sessão de reregistro em log. `OnEndAnalysis` é chamado no final da fase de análise, antes de iniciar a fase de novo registro em log e novamente no final da fase de reregistro em log. A fase de reregistro sempre contém uma única passagem de relogin.

É possível que os analisadores façam parte da fase de análise e reregistro em log de uma sessão de reregistro em log. Esses analisadores podem determinar qual fase está em andamento no momento, acompanhando os pares de OnBeginAnalysis e `OnEndAnalysis` chamada. Duas `OnBeginAnalysis` chamadas sem qualquer `OnEndAnalysis` chamada significa que a fase de análise está em andamento. Duas `OnBeginAnalysis` chamadas e uma `OnEndAnalysis` chamada significam que a fase de reregistro em log está em andamento. Duas OnBeginAnalysis e duas `OnEndAnalysis` chamadas significam que as duas fases foram encerradas.

Todos os membros da `ANALYSIS_CALLBACKS` estrutura devem apontar para uma função válida. Para obter mais informações sobre as assinaturas de função aceitas, consulte [OnAnalysisEventFunc](on-analysis-event-func-typedef.md), [OnTraceInfoFunc](on-trace-info-func-typedef.md)e [OnBeginEndPassFunc](on-begin-end-pass-func-typedef.md).

::: moniker-end
