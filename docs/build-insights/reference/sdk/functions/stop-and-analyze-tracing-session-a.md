---
title: StopAndAnalyzeTracingSessionA
description: A referência de função C++ Build Insights SDK StopAndAnalyzeTracingSessionA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndAnalyzeTracingSessionA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 51a979b68cd87c5e7fd07b28acec80c2d7b81cf6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323729"
---
# <a name="stopandanalyzetracingsessiona"></a>StopAndAnalyzeTracingSessionA

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `StopAndAnalyzeTracingSessionA` função interrompe uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de análise é então imediatamente iniciada usando o arquivo temporário como uma entrada. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE StopAndAnalyzeTracingSessionA(
    const char*                 sessionName,
    TRACING_SESSION_STATISTICS* statistics,
    const ANALYSIS_DESCRIPTOR*  analysisDescriptor);
```

### <a name="parameters"></a>Parâmetros

*sessionName*\
O nome da sessão de rastreamento para parar. Use o mesmo nome de sessão que o aprovado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

*Estatísticas*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS.](../other-types/tracing-session-statistics-struct.md) `StopAndAnalyzeTracingSessionA`escreve estatísticas de coleta de vestígios neste objeto antes de retornar.

*análiseDescritor*\
Ponteiro para um objeto [ANALYSIS_DESCRIPTOR.](../other-types/analysis-descriptor-struct.md) Use este objeto para configurar a sessão `StopAndAnalyzeTracingSessionA`de análise iniciada por .

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

::: moniker-end
