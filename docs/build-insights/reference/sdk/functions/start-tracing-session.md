---
title: StartTracingSession
description: A referência da função StartTracingSession do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StartTracingSession
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 07272404aa8bb8cff1221a88497020fedeff315e
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919989"
---
# <a name="starttracingsession"></a>StartTracingSession

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `StartTracingSession` função inicia uma sessão de rastreamento. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
RESULT_CODE StartTracingSession(
    const char*                    sessionName,
    const TRACING_SESSION_OPTIONS& options);

RESULT_CODE StartTracingSession(
    const wchar_t*                 sessionName,
    const TRACING_SESSION_OPTIONS& options);
```

### <a name="parameters"></a>Parâmetros

*sessionName*\
O nome da sessão de rastreamento a ser iniciada. Use o mesmo nome ao chamar [StopTracingSession](stop-tracing-session.md) ou qualquer outra função de rastreamento de parada.

*Opções*\
Ponteiro para um objeto [TRACING_SESSION_OPTIONS](../other-types/tracing-session-options-struct.md) . Use esse objeto para selecionar quais eventos devem ser coletados pela sessão de rastreamento.

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
