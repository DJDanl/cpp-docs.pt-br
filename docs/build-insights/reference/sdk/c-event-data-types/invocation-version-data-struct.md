---
title: Estrutura de INVOCATION_VERSION_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ INVOCATION_VERSION_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- INVOCATION_VERSION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ebed659ade4610b50ae06f2a32851522073a58d8
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923554"
---
# <a name="invocation_version_data-structure"></a>Estrutura de INVOCATION_VERSION_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `INVOCATION_VERSION_DATA` estrutura descreve um número de versão como um grupo de valores integrais.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct INVOCATION_VERSION_DATA_TAG
{
    unsigned short VersionMajor;
    unsigned short VersionMinor;
    unsigned short BuildNumberMajor;
    unsigned short BuildNumberMinor;

} INVOCATION_VERSION_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `VersionMajor` | O número principal da versão. |
| `VersionMinor` | O número secundário da versão. |
| `BuildNumberMajor` | O número principal da compilação. |
| `BuildNumberMinor` | O número secundário da compilação. |

::: moniker-end
