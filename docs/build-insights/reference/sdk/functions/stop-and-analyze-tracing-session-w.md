---
title: StopAndAnalyzeTracingSessionW
description: A referência da função StopAndAnalyzeTracingSessionW do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndAnalyzeTracingSessionW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e353e9d0038fcd764a9c4d03170f0a3c949bc43d
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919976"
---
# <a name="stopandanalyzetracingsessionw"></a>StopAndAnalyzeTracingSessionW

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `StopAndAnalyzeTracingSessionW` função interrompe uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de análise é então iniciada imediatamente usando o arquivo temporário como uma entrada. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE StopAndAnalyzeTracingSessionW(
    const wchar_t*              sessionName,
    TRACING_SESSION_STATISTICS* statistics,
    const ANALYSIS_DESCRIPTOR*  analysisDescriptor);
```

### <a name="parameters"></a>Parâmetros

*sessionName*\
O nome da sessão de rastreamento a ser interrompida. Use o mesmo nome de sessão que foi passado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

*estatística*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS](../other-types/tracing-session-statistics-struct.md) . `StopAndAnalyzeTracingSessionW` grava estatísticas de coleção de rastreamento neste objeto antes de retornar.

*analysisDescriptor*\
Ponteiro para um objeto [ANALYSIS_DESCRIPTOR](../other-types/analysis-descriptor-struct.md) . Use esse objeto para configurar a sessão de análise que é iniciada pelo `StopAndAnalyzeTracingSessionW` .

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
