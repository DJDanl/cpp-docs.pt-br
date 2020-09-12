---
title: Estrutura de INVOCATION_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ INVOCATION_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- INVOCATION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 48b4c28d3c01d61a31343894312a54ba2ab17a70
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041634"
---
# <a name="invocation_data-structure"></a>Estrutura de INVOCATION_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `INVOCATION_DATA` estrutura descreve um compilador ou invocação de vinculador.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct INVOCATION_DATA_TAG
{
    int                         MSVCToolCode;

    INVOCATION_VERSION_DATA     ToolVersion;

    const char*                 ToolVersionString;
    const wchar_t*              WorkingDirectory;
    const wchar_t*              ToolPath;

} INVOCATION_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `MSVCToolCode` | Um código que identifica o tipo de invocação. Para obter mais informações, consulte [MSVC_TOOL_CODE](msvc-tool-code-enum.md). |
| `ToolVersion` | Um objeto que armazena a versão da ferramenta invocada como um grupo de valores integrais. |
| `ToolVersionString` | Descreve a versão da ferramenta invocada na forma de texto. |
| `WorkingDirectory` | O diretório do qual a invocação foi feita. |
| `ToolPath` | O caminho absoluto da ferramenta invocada. |

::: moniker-end
