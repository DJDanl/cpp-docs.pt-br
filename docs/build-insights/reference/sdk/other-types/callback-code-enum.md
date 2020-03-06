---
title: CALLBACK_CODE enum
description: O C++ SDK da compilação de informações CALLBACK_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CALLBACK_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 68eaa9aa04d2f0a55ac12fb7dde14a080188a38d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332463"
---
# <a name="callback_code-enum"></a>CALLBACK_CODE enum

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

O `CALLBACK_CODE` enum é usado para controlar o fluxo de uma sessão de análise ou de registro em log. Retornar um valor CALLBACK_CODE das funções em [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) ou [RELOG_CALLBACKS](relog-callbacks-struct.md) para controlar o que deve acontecer em seguida.

## <a name="members"></a>Membros

| {1&gt;Nome&lt;1} | {1&gt;Valor&lt;1} | Descrição |
|--|--|--|
| `CALLBACK_CODE_ANALYSIS_SUCCESS` | 1 (0x00000001) | Continue a análise atual ou refazendo o log da sessão normalmente. |
| `CALLBACK_CODE_ANALYSIS_FAILURE` | 2 (0x00000002) | Cancele a sessão de análise ou registro em log atual e sinalize um erro. |
| `CALLBACK_CODE_ANALYSIS_CANCEL` | 4 (0x00000004) | Cancele a sessão de análise ou registro em log atual. |

::: moniker-end
