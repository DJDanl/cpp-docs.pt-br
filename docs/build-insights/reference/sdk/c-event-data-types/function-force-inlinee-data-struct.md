---
title: Estrutura de FUNCTION_FORCE_INLINEE_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ FUNCTION_FORCE_INLINEE_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FUNCTION_FORCE_INLINEE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: d64a23c603d1f30726f30ffc91c1889c51138ef6
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041699"
---
# <a name="function_force_inlinee_data-structure"></a>Estrutura de FUNCTION_FORCE_INLINEE_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `FUNCTION_FORCE_INLINEE_DATA` estrutura descreve uma função de linha imposta.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct FUNCTION_FORCE_INLINEE_DATA_TAG
{
    const char*         Name;
    unsigned short      Size;

} FUNCTION_FORCE_INLINEE_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Name` | O nome da função, codificado em UTF-8. |
| `Size` | O tamanho da função, como uma série de instruções intermediárias. |

::: moniker-end
