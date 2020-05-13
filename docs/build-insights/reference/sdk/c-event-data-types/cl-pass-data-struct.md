---
title: CL_PASS_DATA estrutura
description: O C++ Build Insights SDK CL_PASS_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CL_PASS_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b0a41e59068ade285f1ffa1a9ce13734ef5f1f32
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325706"
---
# <a name="cl_pass_data-structure"></a>CL_PASS_DATA estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `CL_PASS_DATA` estrutura descreve um passe de compilação.

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
| `TranslationUnitPassCode` | Um código que identifica o passe de compilação sendo executado. Para obter mais informações, consulte [TRANSLATION_UNIT_PASS_CODE](translation-unit-pass-code-enum.md). |
| `InputSourcePath` | O arquivo de origem C ou C++ no qual este passe de compilação está sendo executado. |
| `OutputObjectPath` | O arquivo de objeto que está sendo produzido pelo compilador. |

::: moniker-end
