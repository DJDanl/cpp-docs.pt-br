---
title: StopAndRelogTracingSession
description: A referência da função C++ Build Insights SDK StopAndRelogTracingSession.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndRelogTracingSession
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1f6f5af63d25504226707d977791430463374328
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323661"
---
# <a name="stopandrelogtracingsession"></a>StopAndRelogTracingSession

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `StopAndRelogTracingSession` função interrompe uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de relogamento é então imediatamente iniciada usando o arquivo temporário como uma entrada. O traço relocamento final produzido pela sessão de relogamento é salvo em um arquivo especificado pelo chamador. Os executáveis que chamam essa função devem ter privilégios de administrador.

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

*sessionName*\
O nome da sessão de rastreamento para parar. Use o mesmo nome de sessão que o aprovado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

*saídaLogFile*\
O arquivo no qual escrever o traço relocouproduzido pela sessão de relogamento.

*Estatísticas*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS.](../other-types/tracing-session-statistics-struct.md) `StopAndRelogTracingSession`escreve estatísticas de coleta de vestígios neste objeto antes de retornar.

*numberOfAnalysisPasses*\
O número de análises passa para correr no rastreamento. O rastreamento é passado através do grupo analisador fornecido uma vez por passe de análise.

*systemEventsRetentionFlags*\
Uma [RELOG_RETENTION_SYSTEM_EVENT_FLAGS](../other-types/relog-retention-system-event-flags-constants.md) bitmask que especifica quais eventos de ETW do sistema para manter no rastreamento relocado.

*analyzerGroup*\
O grupo analisador utilizado para a fase de análise da sessão de relogging. Chamada [MakeStaticAnalyzegroup](make-static-analyzer-group.md) para criar um grupo de analisadores. Se você deseja usar um grupo de analisador dinâmico obtido do [MakeDynamicAnalyzerGroup,](make-dynamic-analyzer-group.md)primeiro encapsule-o dentro de um grupo de analisadores estáticos, passando seu endereço para `MakeStaticAnalyzerGroup`.

*reloggerGroup*\
O grupo relogger que reloga eventos no arquivo de rastreamento especificado no *outputLogFile*. Ligue para [o MakeStaticReloggerGroup](make-static-relogger-group.md) para criar um grupo de relogger. Se você deseja usar um grupo de relogger dinâmico obtido do [MakeDynamicReloggerGroup,](make-dynamic-relogger-group.md)primeiro encapsule-o dentro de um grupo de relogger estático, passando seu endereço para `MakeStaticReloggerGroup`.

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

### <a name="remarks"></a>Comentários

O rastreamento de entrada é transmitido através do número do grupo *analisadorOfAnalysisPasses* times. Não há opção similar para realogar passes. O rastreamento é passado pelo grupo relogger apenas uma vez, depois que todas as análises são concluídas.

O relogamento de eventos do sistema, como amostras de CPU de dentro de uma classe de relogger, não é suportado. Use o *parâmetro SystemEventsRetentionFlags* para decidir quais eventos do sistema manter no rastreamento de saída.

::: moniker-end
