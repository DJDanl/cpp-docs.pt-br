---
title: estrutura INVOCATION_VERSION_DATA
description: O C++ Build Insights SDK INVOCATION_VERSION_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- INVOCATION_VERSION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1211b4eb999fd63767af71c6884d7d20d6920df0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325467"
---
# <a name="invocation_version_data-structure"></a>estrutura INVOCATION_VERSION_DATA

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

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

|  |  |
|--|--|
| `VersionMajor` | O número principal da versão. |
| `VersionMinor` | A versão é menor número. |
| `BuildNumberMajor` | O número maior da construção. |
| `BuildNumberMinor` | O número menor da compilação. |

::: moniker-end
