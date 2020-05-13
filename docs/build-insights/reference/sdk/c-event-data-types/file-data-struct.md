---
title: FILE_DATA estrutura
description: O C++ Build Insights SDK FILE_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FILE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 6b7b0129c54fa4b1d5285bafb38761da45bab4e5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325585"
---
# <a name="file_data-structure"></a>FILE_DATA estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

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

|  |  |
|--|--|
| `Path` | O caminho absoluto do arquivo |
| `TypeCode` | Um código descrevendo o tipo do arquivo. Para obter mais informações, consulte [FILE_TYPE_CODE](file-type-code-enum.md). |

::: moniker-end
