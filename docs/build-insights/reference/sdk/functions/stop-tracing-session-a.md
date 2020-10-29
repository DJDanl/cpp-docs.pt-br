---
title: StopTracingSessionA
description: A referência da função StopTracingSessionA do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopTracingSessionA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 211538c1756d41b91dab6d43f33f4b4a41ceb70c
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922648"
---
# <a name="stoptracingsessiona"></a>StopTracingSessionA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `StopTracingSessionA` função interrompe uma sessão de rastreamento em andamento e produz um arquivo de rastreamento bruto. Os arquivos de rastreamento brutos podem ser passados para as funções [Analyze](analyze.md), [AnalzeA](analyze-a.md)e [AnalyzeW](analyze-w.md) para iniciar uma sessão de análise. Os arquivos de rastreamento brutos também podem ser passados para as funções [relog](relog.md), [RelogA](relog-a.md)e [RelogW](relog-w.md) para iniciar a sessão de log novamente. Os executáveis `StopTracingSessionA` que chamam devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE StopTracingSessionA(
    const char*                 sessionName,
    const char*                 outputLogFile,
    TRACING_SESSION_STATISTICS* statistics);
```

### <a name="parameters"></a>Parâmetros

*sessionName*\
O nome da sessão de rastreamento a ser interrompida. Use o mesmo nome de sessão que foi passado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

*outputLogFile*\
Caminho para o arquivo de log de saída final em que o rastreamento bruto deve ser salvo.

*estatística*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS](../other-types/tracing-session-statistics-struct.md) . `StopTracingSessionA` grava estatísticas de coleção de rastreamento neste objeto antes de retornar.

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
