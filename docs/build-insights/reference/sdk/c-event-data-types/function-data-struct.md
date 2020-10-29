---
title: Estrutura de FUNCTION_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ FUNCTION_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FUNCTION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 42dcb5a8633f0b7a6cb2fbee8a227cd3f00e2572
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920990"
---
# <a name="function_data-structure"></a>Estrutura de FUNCTION_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `FUNCTION_DATA` estrutura descreve uma função.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct FUNCTION_DATA_TAG
{
    const char*         Name;

} FUNCTION_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Name` | O nome da função, codificado em UTF-8. |

::: moniker-end
