---
title: CALLBACK_CODE enum
description: O C++ Build Insights SDK CALLBACK_CODE referência enum.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CALLBACK_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: d0d3dcc70040f562cd40755188e545f709a807b5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329188"
---
# <a name="callback_code-enum"></a>CALLBACK_CODE enum

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O `CALLBACK_CODE` enum é usado para controlar o fluxo de uma sessão de análise ou relogging. Devolva um valor CALLBACK_CODE das funções em [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) ou [RELOG_CALLBACKS](relog-callbacks-struct.md) para controlar o que deve acontecer a seguir.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `CALLBACK_CODE_ANALYSIS_SUCCESS` | 1 (0x00000001) | Continue a análise atual ou a sessão de relogamento normalmente. |
| `CALLBACK_CODE_ANALYSIS_FAILURE` | 2 (0x000000002) | Cancele a sessão de análise ou relogamento atual e sinalize um erro. |
| `CALLBACK_CODE_ANALYSIS_CANCEL` | 4 (0x0000000004) | Cancele a sessão de análise ou relogamento atual. |

::: moniker-end
