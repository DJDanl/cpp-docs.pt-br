---
title: StopAndAnalyzeTracingSession
description: A referência da função StopAndAnalyzeTracingSession do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndAnalyzeTracingSession
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 81a8ce43ecedfa51874508193637969411ae52d6
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922709"
---
# <a name="stopandanalyzetracingsession"></a>StopAndAnalyzeTracingSession

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `StopAndAnalyzeTracingSession` função interrompe uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de análise é então iniciada imediatamente usando o arquivo temporário como uma entrada. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TAnalyzerGroupMembers>
RESULT_CODE StopAndAnalyzeTracingSession(
    const char*                                   sessionName,
    unsigned                                      numberOfAnalysisPasses,
    TRACING_SESSION_STATISTICS*                   statistics,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup);

template <typename... TAnalyzerGroupMembers>
RESULT_CODE StopAndAnalyzeTracingSession(
    const wchar_t*                                sessionName,
    unsigned                                      numberOfAnalysisPasses,
    TRACING_SESSION_STATISTICS*                   statistics,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup);
```

### <a name="parameters"></a>Parâmetros

*sessionName*\
O nome da sessão de rastreamento a ser interrompida. Use o mesmo nome de sessão que foi passado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

*numberOfAnalysisPasses*\
O número de etapas de análise a serem executadas no rastreamento. O rastreamento é passado pelo grupo analisador fornecido uma vez por passagem de análise.

*estatística*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS](../other-types/tracing-session-statistics-struct.md) . `StopAndAnalyzeTracingSession` grava estatísticas de coleção de rastreamento neste objeto antes de retornar.

*fileanalyzer*\
O grupo do analisador usado para a análise. Chame [MakeStaticAnalyzerGroup](make-static-analyzer-group.md) para criar um grupo do Analyzer. Se você quiser usar um grupo do analisador dinâmico obtido do [MakeDynamicAnalyzerGroup](make-dynamic-analyzer-group.md), primeiro encapsular-o dentro de um grupo do analisador estático passando seu endereço para `MakeStaticAnalyzerGroup` .

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
