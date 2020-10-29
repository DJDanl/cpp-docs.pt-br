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
ms.openlocfilehash: 488faf80fc073d5bd41712f66bd263e4043f978e
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923581"
---
# <a name="front_end_file_data-structure"></a>Estrutura de FRONT_END_FILE_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

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
