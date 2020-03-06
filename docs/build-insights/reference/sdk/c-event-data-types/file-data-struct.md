---
title: Estrutura de FILE_DATA
description: A C++ referência da estrutura de FILE_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FILE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 72cae8c8eb81bdb8d94897c46c5af90c89e92ab4
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333751"
---
# <a name="file_data-structure"></a>Estrutura de FILE_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `FILE_DATA` descreve uma entrada ou saída de arquivo.

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
| `TypeCode` | Um código que descreve o tipo do arquivo. Para obter mais informações, consulte [FILE_TYPE_CODE](file-type-code-enum.md). |

::: moniker-end
