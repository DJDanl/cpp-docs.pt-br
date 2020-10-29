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
ms.openlocfilehash: e9de87bdc4e5a1a3e25483f8ba1766609c7d7622
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923574"
---
# <a name="function_force_inlinee_data-structure"></a>Estrutura de FUNCTION_FORCE_INLINEE_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

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
