---
title: INVOCATION_DATA estrutura
description: O C++ Build Insights SDK INVOCATION_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- INVOCATION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 4e1f428facac413d7a4a5c059452dd8cdb07be4c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325480"
---
# <a name="invocation_data-structure"></a>INVOCATION_DATA estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `INVOCATION_DATA` estrutura descreve uma invocação de compilador ou linker.

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

|  |  |
|--|--|
| `MSVCToolCode` | Um código que identifica o tipo da invocação. Para obter mais informações, consulte [MSVC_TOOL_CODE](msvc-tool-code-enum.md). |
| `ToolVersion` | Um objeto que armazena a versão da ferramenta invocada como um grupo de valores integrais. |
| `ToolVersionString` | Descreve a versão da ferramenta invocada em forma de texto. |
| `WorkingDirectory` | O diretório do qual a invocação foi feita. |
| `ToolPath` | O caminho absoluto da ferramenta invocada. |

::: moniker-end
