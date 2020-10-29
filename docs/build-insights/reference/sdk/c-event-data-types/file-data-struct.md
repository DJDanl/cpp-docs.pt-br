---
title: Estrutura de FILE_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ FILE_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FILE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1a03c2c47be82fac2ee036a632e4df775f6c4f5f
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923600"
---
# <a name="file_data-structure"></a>Estrutura de FILE_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `FILE_DATA` estrutura descreve uma entrada ou saída de arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct FILE_DATA_TAG
{
    const wchar_t*      Path;
    int                 TypeCode;

} FILE_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Path` | O caminho absoluto do arquivo |
| `TypeCode` | Um código que descreve o tipo do arquivo. Para obter mais informações, consulte [FILE_TYPE_CODE](file-type-code-enum.md). |

::: moniker-end
