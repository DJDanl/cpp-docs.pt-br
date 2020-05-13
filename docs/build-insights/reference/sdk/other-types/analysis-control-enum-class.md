---
title: Classe de enum AnalysisControl
description: O C++ Build Insights SDK AnalysisControl enum reference.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalysisControl
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e9431f878390127f2cefbe8f0ee42ca509e147de
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323637"
---
# <a name="analysiscontrol-enum-class"></a>Classe de enum AnalysisControl

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `AnalysisControl` classe enum é usada para controlar o fluxo de uma sessão de análise ou relogging. Retorne `AnalysisControl` um código de uma função de membro [IAnalyzer](ianalyzer-class.md) ou [IRelogger](irelogger-class.md) para controlar o que deve acontecer a seguir.

## <a name="members"></a>Membros

|  |  |
|--|--|
| `BLOCK` | Impede que o evento atual se propague ainda mais no grupo analisador ou relogger. |
| `CANCEL` | Cancele a sessão de análise ou relogamento atual. |
| `CONTINUE` | Continue a análise atual ou a sessão de relogamento normalmente. Propagar o evento atual para o próximo analisador ou membro do grupo relogger. |
| `FAILURE` | Cancele a sessão de análise ou relogamento atual e sinalize um erro. |

::: moniker-end
