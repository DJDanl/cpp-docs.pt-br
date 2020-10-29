---
title: Typedef OnRelogEventFunc
description: A referência de typedef OnRelogEventFunc do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnRelogEventFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ed639ab59b900f97d29dc69240e45b2f52f2f3b3
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919742"
---
# <a name="onrelogeventfunc-typedef"></a>Typedef OnRelogEventFunc

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

O `OnRelogEventFunc` typedef é uma das assinaturas de função usadas na estrutura de [RELOG_CALLBACKS](relog-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnRelogEventFunc)(
    const EVENT_COLLECTION_DATA*    eventStack,
    const void*                     relogSession,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos do evento atual. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

*relogSession*\
O ponteiro de sessão de reregistro para usar ao chamar o [InjectEvent](../functions/inject-event.md).

*callbackContext*\
O valor de contexto que foi definido para este retorno de chamada no [RELOG_DESCRIPTOR](analysis-descriptor-struct.md).

### <a name="return-value"></a>Valor Retornado

Um valor [CALLBACK_CODE](callback-code-enum.md) que controla o que deve acontecer em seguida.

::: moniker-end
