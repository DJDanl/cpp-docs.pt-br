---
title: Estrutura de FRONT_END_FILE_DATA
description: A C++ referência da estrutura de FRONT_END_FILE_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FRONT_END_FILE_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 33232a0f83566e58e64964e84961a7ade2de7b7c
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333737"
---
# <a name="front_end_file_data-structure"></a>Estrutura de FRONT_END_FILE_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `FRONT_END_FILE_DATA` descreve o processamento de um arquivo pelo front-end do compilador.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct FRONT_END_FILE_DATA_TAG
{
    const char*         Path;

} FRONT_END_FILE_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `Path` | O caminho absoluto do arquivo, codificado em UTF-8. |

::: moniker-end
