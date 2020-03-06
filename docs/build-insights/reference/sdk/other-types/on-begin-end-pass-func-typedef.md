---
title: Typedef OnBeginEndPassFunc
description: A C++ referência de TYPEDEF do SDK do insights OnBeginEndPassFunc.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OnBeginEndPassFunc
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 6f5e602fdc460acf8e53307e88a1a3d7ad000893
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332421"
---
# <a name="onbeginendpassfunc-typedef"></a>Typedef OnBeginEndPassFunc

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

O `OnBeginEndPassFunc` typedef é uma das assinaturas de função usadas nas estruturas [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) e [RELOG_CALLBACKS](relog-callbacks-struct.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef enum CALLBACK_CODE (BUILD_INSIGHTS_API *OnBeginEndPassFunc)(
    void*                           callbackContext);
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `callbackContext` |  |

::: moniker-end
