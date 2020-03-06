---
title: StopAndRelogTracingSession
description: A C++ referência da função STOPANDRELOGTRACINGSESSION do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndRelogTracingSession
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e99568f9b509b89ccd0f0711433dec9d96d904bc
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332589"
---
# <a name="stopandrelogtracingsession"></a>StopAndRelogTracingSession

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `StopAndRelogTracingSession` para uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de reregistro em log é iniciada imediatamente usando o arquivo temporário como uma entrada. O rastreamento de relogin final produzido pela sessão de reregistro em log é salvo em um arquivo especificado pelo chamador. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename... TAnalyzerGroupMembers,
    typename... TReloggerGroupMembers>
RESULT_CODE StopAndRelogTracingSession(
    const char*                                   sessionName,
    const char*                                   outputLogFile,
    TRACING_SESSION_STATISTICS*                   statistics,
    unsigned                                      numberOfAnalysisPasses,
    unsigned long long                            systemEventsRetentionFlags,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup,
    StaticReloggerGroup<TReloggerGroupMembers...> reloggerGroup);

template <
    typename... TAnalyzerGroupMembers,
    typename... TReloggerGroupMembers>
RESULT_CODE StopAndRelogTracingSession(
    const wchar_t*                                sessionName,
    const wchar_t*                                outputLogFile,
    TRACING_SESSION_STATISTICS*                   statistics,
    unsigned                                      numberOfAnalysisPasses,
    unsigned long long                            systemEventsRetentionFlags,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup,
    StaticReloggerGroup<TReloggerGroupMembers...> reloggerGroup);
```

### <a name="parameters"></a>Parâmetros

*sessionname*\
O nome da sessão de rastreamento a ser interrompida. Use o mesmo nome de sessão que foi passado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

\ *outputLogFile*
O arquivo no qual gravar o rastreamento de relogin produzido pela sessão de reregistro em log.

*estatísticas*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS](../other-types/tracing-session-statistics-struct.md) . `StopAndRelogTracingSession` grava estatísticas de coleta de rastreamento neste objeto antes de retornar.

\ *numberOfAnalysisPasses*
O número de etapas de análise a serem executadas no rastreamento. O rastreamento é passado pelo grupo analisador fornecido uma vez por passagem de análise.

\ *systemEventsRetentionFlags*
Um [RELOG_RETENTION_SYSTEM_EVENT_FLAGS](../other-types/relog-retention-system-event-flags-constants.md) bitmask que especifica quais eventos de ETW do sistema manter no rastreamento de relogin.

\ do *fileanalyzer*
O grupo do Analyzer usado para a fase de análise da sessão de reregistro em log. Chame [MakeStaticAnalyzerGroup](make-static-analyzer-group.md) para criar um grupo do Analyzer. Se você quiser usar um grupo do analisador dinâmico obtido do [MakeDynamicAnalyzerGroup](make-dynamic-analyzer-group.md), primeiro encapsular-o dentro de um grupo do analisador estático passando seu endereço para `MakeStaticAnalyzerGroup`.

\ de *agente* novamente
O grupo de relogger que registra novamente os eventos no arquivo de rastreamento especificado em *outputLogFile*. Chame [MakeStaticReloggerGroup](make-static-relogger-group.md) para criar um grupo de relogger. Se você quiser usar um grupo de reagente dinâmico obtido do [MakeDynamicReloggerGroup](make-dynamic-relogger-group.md), primeiro encapsular-o dentro de um grupo de reagente estático, passando seu endereço para `MakeStaticReloggerGroup`.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

### <a name="remarks"></a>Comentários

O rastreamento de entrada é passado pelo grupo analisador *numberOfAnalysisPasses* vezes. Não há nenhuma opção semelhante para o reregistro em log. O rastreamento é passado Trough o grupo de relogger apenas uma vez, após a conclusão de todas as etapas de análise.

Não há suporte para o registro em log de eventos do sistema, como exemplos de CPU de uma classe de relogger. Use o parâmetro *systemEventsRetentionFlags* para decidir quais eventos do sistema manter no rastreamento de saída.

::: moniker-end
