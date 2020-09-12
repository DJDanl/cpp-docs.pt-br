---
title: Estrutura de FRONT_END_FILE_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ FRONT_END_FILE_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FRONT_END_FILE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c2519bfd478776f54cee59ba08b83ea00b96beff
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041751"
---
# <a name="front_end_file_data-structure"></a>Estrutura de FRONT_END_FILE_DATA

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `FRONT_END_FILE_DATA` estrutura descreve o processamento de um arquivo pelo front-end do compilador.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct FRONT_END_FILE_DATA_TAG
{
    const char*         Path;

} FRONT_END_FILE_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Path` | O caminho absoluto do arquivo, codificado em UTF-8. |

::: moniker-end
