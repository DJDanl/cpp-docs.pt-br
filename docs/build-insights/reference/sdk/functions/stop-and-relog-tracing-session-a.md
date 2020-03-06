---
title: StopAndRelogTracingSessionA
description: A C++ referência da função STOPANDRELOGTRACINGSESSIONA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndRelogTracingSessionA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c9fe2ea47b378565d3ce9785b6f4cc3e541ebe80
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332701"
---
# <a name="stopandrelogtracingsessiona"></a>StopAndRelogTracingSessionA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `StopAndRelogTracingSessionA` para uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de reregistro em log é iniciada imediatamente usando o arquivo temporário como uma entrada. O rastreamento de relogin final produzido pela sessão de reregistro em log é salvo em um arquivo especificado pelo chamador. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE StopAndRelogTracingSessionA(
    const char*                 sessionName,
    const char*                 outputLogFile,
    TRACING_SESSION_STATISTICS* statistics,
    const RELOG_DESCRIPTOR*     relogDescriptor);
```

### <a name="parameters"></a>Parâmetros

*sessionname*\
O nome da sessão de rastreamento a ser interrompida. Use o mesmo nome de sessão que foi passado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

\ *outputLogFile*
O arquivo no qual gravar o rastreamento de relogin produzido pela sessão de reregistro em log.

*estatísticas*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS](../other-types/tracing-session-statistics-struct.md) . `StopAndRelogTracingSessionA` grava estatísticas de coleta de rastreamento neste objeto antes de retornar.

\ *analysisDescriptor*
Ponteiro para um objeto [RELOG_DESCRIPTOR](../other-types/analysis-descriptor-struct.md) . Use esse objeto para configurar a sessão de reregistro em log iniciada pelo `StopAndRelogTracingSessionA`.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
