---
title: Typedef OnAnalysisEventFunc
description: A referência de typedef OnAnalysisEventFunc do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnAnalysisEventFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 069c89a01fa466e86986a821e5dd9d0b09f5c81a
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919781"
---
# <a name="onanalysiseventfunc-typedef"></a>Typedef OnAnalysisEventFunc

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

O `OnAnalysisEventFunc` typedef é uma das assinaturas de função usadas na estrutura de [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnAnalysisEventFunc)(
    const EVENT_COLLECTION_DATA*    eventStack,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos do evento atual. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

*callbackContext*\
O valor de contexto que foi definido para este retorno de chamada no [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md).

### <a name="return-value"></a>Valor Retornado

Um valor [CALLBACK_CODE](callback-code-enum.md) que controla o que deve acontecer em seguida.

::: moniker-end
