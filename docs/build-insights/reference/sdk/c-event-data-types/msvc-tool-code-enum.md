---
title: MSVC_TOOL_CODE enum
description: O C++ SDK da compilação de informações MSVC_TOOL_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MSVC_TOOL_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: d88a2227808867b04ef3b0557aee9c869beaead1
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333667"
---
# <a name="msvc_tool_code-enum"></a>MSVC_TOOL_CODE enum

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A `MSVC_TOOL_CODE` enum.

## <a name="members"></a>Membros

| {1&gt;Nome&lt;1} | {1&gt;Valor&lt;1} | Descrição |
|--|--|--|
| `MSVC_TOOL_CODE_CL` | 0 (0x00000000) | O compilador (CL. exe). |
| `MSVC_TOOL_CODE_LINK` | 1 (0x00000001) | O vinculador (link. exe). |

## <a name="remarks"></a>Comentários

Usado pelas funções do SDK do C.

::: moniker-end