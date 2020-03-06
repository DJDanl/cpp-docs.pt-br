---
title: Estrutura de CL_PASS_DATA
description: A C++ referência da estrutura de CL_PASS_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CL_PASS_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3df5b5bc1cddbadc4a4d432ae021dd8b338c532e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333821"
---
# <a name="cl_pass_data-structure"></a>Estrutura de CL_PASS_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `CL_PASS_DATA` descreve uma passagem de compilação.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct CL_PASS_DATA_TAG
{
    int                         TranslationUnitPassCode;
    const wchar_t*              InputSourcePath;
    const wchar_t*              OutputObjectPath;

} CL_PASS_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `TranslationUnitPassCode` | Um código que identifica a passagem de compilação que está sendo executada. Para obter mais informações, consulte [TRANSLATION_UNIT_PASS_CODE](translation-unit-pass-code-enum.md). |
| `InputSourcePath` | O arquivo C C++ ou de origem no qual esta passagem de compilação está sendo executada. |
| `OutputObjectPath` | O arquivo de objeto que está sendo produzido pelo compilador. |

::: moniker-end
