---
title: Typedef onTraceInfoFunc
description: A referência c++ Build Insights SDK OnTraceInfoFunc tipifica.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnTraceInfoFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b987d4db9852c2e52c148bb91015ad414c04d41b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329016"
---
# <a name="ontraceinfofunc-typedef"></a>Typedef onTraceInfoFunc

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O `OnTraceInfoFunc` typedef é uma das assinaturas de função utilizadas nas estruturas [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) e [RELOG_CALLBACKS.](relog-callbacks-struct.md)

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnTraceInfoFunc)(
    const TRACE_INFO_DATA*          traceInfo,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

*Traceinfo*\
Um [TRACE_INFO_DATA](../c-event-data-types/trace-info-data-struct.md) objeto que contém informações sobre o rastreamento atualmente sendo analisado ou relogado.

*callbackContexto*\
O valor de contexto definido para este retorno de chamada em [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md).

### <a name="return-value"></a>Valor retornado

Um [CALLBACK_CODE](callback-code-enum.md) valor que controla o que deve acontecer a seguir.

::: moniker-end
