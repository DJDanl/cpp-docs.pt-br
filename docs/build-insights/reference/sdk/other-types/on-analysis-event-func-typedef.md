---
title: Typedef OnAnalysisEventFunc
description: A C++ referência de TYPEDEF do SDK do insights OnAnalysisEventFunc.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnAnalysisEventFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: d260f6060e759f315589abda82e31c2c2b95a65e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332428"
---
# <a name="onanalysiseventfunc-typedef"></a>Typedef OnAnalysisEventFunc

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

O `OnAnalysisEventFunc` typedef é uma das assinaturas de função usadas na estrutura de [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnAnalysisEventFunc)(
    const EVENT_COLLECTION_DATA*    eventStack,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

\ *eventStack*
A pilha de eventos do evento atual. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

\ *callbackContext*
O valor de contexto que foi definido para este retorno de chamada no [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md).

### <a name="return-value"></a>Valor retornado

Um valor [CALLBACK_CODE](callback-code-enum.md) que controla o que deve acontecer em seguida.

::: moniker-end
