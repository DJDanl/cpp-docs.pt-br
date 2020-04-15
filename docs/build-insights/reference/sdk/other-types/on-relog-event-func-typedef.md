---
title: Typedef onRelogEventFunc
description: A referência tipo Deftono C++ Build Insights SDK OnRelogEventFunc.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnRelogEventFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 2df8646d530c089b1239978d716b2b619a5b4b61
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329075"
---
# <a name="onrelogeventfunc-typedef"></a>Typedef onRelogEventFunc

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O `OnRelogEventFunc` typedef é uma das assinaturas de função utilizadas na estrutura [RELOG_CALLBACKS.](relog-callbacks-struct.md)

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnRelogEventFunc)(
    const EVENT_COLLECTION_DATA*    eventStack,
    const void*                     relogSession,
    void*                           callbackContext);
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para o evento atual. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

*sessão de relog*\
O ponteiro de sessão de relogging para usar ao chamar o [InjectEvent](../functions/inject-event.md).

*callbackContexto*\
O valor do contexto definido para este retorno de chamada em [RELOG_DESCRIPTOR](analysis-descriptor-struct.md).

### <a name="return-value"></a>Valor retornado

Um [CALLBACK_CODE](callback-code-enum.md) valor que controla o que deve acontecer a seguir.

::: moniker-end
