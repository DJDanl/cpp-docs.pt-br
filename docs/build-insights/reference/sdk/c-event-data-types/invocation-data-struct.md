---
title: Estrutura de INVOCATION_DATA
description: A C++ referência da estrutura de INVOCATION_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- INVOCATION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b2e8ddcf79201d8bcbbb8eb298b96b5c7680f90e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333688"
---
# <a name="invocation_data-structure"></a>Estrutura de INVOCATION_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `INVOCATION_DATA` descreve um compilador ou invocação de vinculador.

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
| `MSVCToolCode` | Um código que identifica o tipo de invocação. Para obter mais informações, consulte [MSVC_TOOL_CODE](msvc-tool-code-enum.md). |
| `ToolVersion` | Um objeto que armazena a versão da ferramenta invocada como um grupo de valores integrais. |
| `ToolVersionString` | Descreve a versão da ferramenta invocada na forma de texto. |
| `WorkingDirectory` | O diretório do qual a invocação foi feita. |
| `ToolPath` | O caminho absoluto da ferramenta invocada. |

::: moniker-end
