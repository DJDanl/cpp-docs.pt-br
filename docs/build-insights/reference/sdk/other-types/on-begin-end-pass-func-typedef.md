---
title: Typedef OnBeginEndPassFunc
description: A referência de typedef OnBeginEndPassFunc do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnBeginEndPassFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 2a97ae792392e5cc0dc83bab00a92d05609a4815
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922490"
---
# <a name="onbeginendpassfunc-typedef"></a>Typedef OnBeginEndPassFunc

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

O `OnBeginEndPassFunc` typedef é uma das assinaturas de função usadas nas estruturas [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) e [RELOG_CALLBACKS](relog-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnBeginEndPassFunc)(
    void*                           callbackContext);
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `callbackContext` |  |

::: moniker-end
