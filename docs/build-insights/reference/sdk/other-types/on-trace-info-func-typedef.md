---
title: Typedef OnTraceInfoFunc
description: A referência de typedef OnTraceInfoFunc do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnTraceInfoFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 4aaa865fd0f907a67179e7ee967f23a9827b0026
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922469"
---
# <a name="ontraceinfofunc-typedef"></a>Typedef OnTraceInfoFunc

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

O `OnTraceInfoFunc` typedef é uma das assinaturas de função usadas nas estruturas [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) e [RELOG_CALLBACKS](relog-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnTraceInfoFunc)(
    const TRACE_INFO_DATA*          traceInfo,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

*traceInfo*\
Um objeto [TRACE_INFO_DATA](../c-event-data-types/trace-info-data-struct.md) que contém informações sobre o rastreamento que está sendo analisado ou registrado no momento.

*callbackContext*\
O valor de contexto que foi definido para este retorno de chamada no [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md).

### <a name="return-value"></a>Valor Retornado

Um valor [CALLBACK_CODE](callback-code-enum.md) que controla o que deve acontecer em seguida.

::: moniker-end
