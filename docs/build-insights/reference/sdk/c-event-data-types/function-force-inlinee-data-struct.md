---
title: Estrutura de FUNCTION_FORCE_INLINEE_DATA
description: A C++ referência da estrutura de FUNCTION_FORCE_INLINEE_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FUNCTION_FORCE_INLINEE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3d6929f2f16e9b1bd79b7fb8b383b40e031268bf
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333695"
---
# <a name="function_force_inlinee_data-structure"></a>Estrutura de FUNCTION_FORCE_INLINEE_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `FUNCTION_FORCE_INLINEE_DATA` descreve uma função com linhas forçadas.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct FUNCTION_FORCE_INLINEE_DATA_TAG
{
    const char*         Name;
    unsigned short      Size;

} FUNCTION_FORCE_INLINEE_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `Name` | O nome da função, codificado em UTF-8. |
| `Size` | O tamanho da função, como uma série de instruções intermediárias. |

::: moniker-end
