---
title: StartTracingSession
description: A C++ referência da função STARTTRACINGSESSION do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StartTracingSession
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: de9d46b4a684d66bf01f76e7ea753694cf40d2cd
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332617"
---
# <a name="starttracingsession"></a>StartTracingSession

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `StartTracingSession` inicia uma sessão de rastreamento. Os executáveis que chamam essa função devem ter privilégios de administrador.

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

*sessionname*\
O nome da sessão de rastreamento a ser iniciada. Use o mesmo nome ao chamar [StopTracingSession](stop-tracing-session.md) ou qualquer outra função de rastreamento de parada.

*opções*\
Ponteiro para um objeto [TRACING_SESSION_OPTIONS](../other-types/tracing-session-options-struct.md) . Use esse objeto para selecionar quais eventos devem ser coletados pela sessão de rastreamento.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
