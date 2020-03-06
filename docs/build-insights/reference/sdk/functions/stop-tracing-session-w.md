---
title: StopTracingSessionW
description: A C++ referência da função STOPTRACINGSESSIONW do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopTracingSessionW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: fbb31b600d6aee8c03cb0b52f71c0afcb8b8e3b3
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332554"
---
# <a name="stoptracingsessionw"></a>StopTracingSessionW

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `StopTracingSessionW` para uma sessão de rastreamento em andamento e produz um arquivo de rastreamento bruto. Os arquivos de rastreamento brutos podem ser passados para as funções [Analyze](analyze.md), [AnalzeA](analyze-a.md)e [AnalyzeW](analyze-w.md) para iniciar uma sessão de análise. Os arquivos de rastreamento brutos também podem ser passados para as funções [relog](relog.md), [RelogA](relog-a.md)e [RelogW](relog-w.md) para iniciar a sessão de log novamente. Os executáveis que chamam `StopTracingSessionW` devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE StopTracingSessionW(
    const wchar_t*              sessionName,
    const char*                 outputLogFile,
    TRACING_SESSION_STATISTICS* statistics);
```

### <a name="parameters"></a>Parâmetros

*sessionname*\
O nome da sessão de rastreamento a ser interrompida. Use o mesmo nome de sessão que foi passado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

\ *outputLogFile*
Caminho para o arquivo de log de saída final em que o rastreamento bruto deve ser salvo.

*estatísticas*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS](../other-types/tracing-session-statistics-struct.md) . `StopTracingSessionW` grava estatísticas de coleta de rastreamento neste objeto antes de retornar.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
