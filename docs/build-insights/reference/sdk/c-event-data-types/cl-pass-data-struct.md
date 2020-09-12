---
title: Estrutura de CL_PASS_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ CL_PASS_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CL_PASS_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 52ee5fdaae12784c2f59d2c47ac9a2fd80649f27
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040529"
---
# <a name="cl_pass_data-structure"></a>Estrutura de CL_PASS_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `CL_PASS_DATA` estrutura descreve uma passagem de compilação.

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

| Nome | Descrição |
|--|--|
| `TranslationUnitPassCode` | Um código que identifica a passagem de compilação que está sendo executada. Para obter mais informações, consulte [TRANSLATION_UNIT_PASS_CODE](translation-unit-pass-code-enum.md). |
| `InputSourcePath` | O arquivo de origem C ou C++ no qual esta passagem de compilação está sendo executada. |
| `OutputObjectPath` | O arquivo de objeto que está sendo produzido pelo compilador. |

::: moniker-end
