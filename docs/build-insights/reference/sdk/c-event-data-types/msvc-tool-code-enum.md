---
title: MSVC_TOOL_CODE enum
description: O SDK do insights de compilação do C++ MSVC_TOOL_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MSVC_TOOL_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 4f539401f304d5d39983ec8f97cc8c99b19399d9
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920951"
---
# <a name="msvc_tool_code-enum"></a>MSVC_TOOL_CODE enum

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `MSVC_TOOL_CODE` enumeração.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `MSVC_TOOL_CODE_CL` | 0 (0x00000000) | O compilador (cl.exe). |
| `MSVC_TOOL_CODE_LINK` | 1 (0x00000001) | O vinculador (link.exe). |

## <a name="remarks"></a>Comentários

Usado pelas funções do SDK do C.

::: moniker-end
