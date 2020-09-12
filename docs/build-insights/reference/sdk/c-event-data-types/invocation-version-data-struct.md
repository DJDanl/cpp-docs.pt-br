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
ms.openlocfilehash: ec54c560dd408dc3beecbc20eaac69d389c7ec37
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041553"
---
# <a name="invocation_version_data-structure"></a>Estrutura de INVOCATION_VERSION_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

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
