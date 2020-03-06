---
title: Typedef OnTraceInfoFunc
description: A C++ referência de TYPEDEF do SDK do insights OnTraceInfoFunc.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnTraceInfoFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b168d6783b31454f6a2837bcad1fc81199ce9054
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332344"
---
# <a name="ontraceinfofunc-typedef"></a>Typedef OnTraceInfoFunc

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

O `OnTraceInfoFunc` typedef é uma das assinaturas de função usadas nas estruturas [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) e [RELOG_CALLBACKS](relog-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnTraceInfoFunc)(
    const TRACE_INFO_DATA*          traceInfo,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

\ *TraceInfo*
Um objeto [TRACE_INFO_DATA](../c-event-data-types/trace-info-data-struct.md) que contém informações sobre o rastreamento que está sendo analisado ou registrado no momento.

\ *callbackContext*
O valor de contexto que foi definido para este retorno de chamada no [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md).

### <a name="return-value"></a>Valor retornado

Um valor [CALLBACK_CODE](callback-code-enum.md) que controla o que deve acontecer em seguida.

::: moniker-end
