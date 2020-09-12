---
title: Classe de enumeração AnalysisControl
description: A referência de enumeração do SDK do insights do C++ Build AnalysisControl.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalysisControl
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a7b7fc0ce404f414b3ec07449bdc110d578fa101
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90042011"
---
# <a name="analysiscontrol-enum-class"></a>Classe de enumeração AnalysisControl

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `AnalysisControl` classe enum é usada para controlar o fluxo de uma sessão de análise ou de registro em log. Retornar um `AnalysisControl` código de uma função de membro [IAnalyzer](ianalyzer-class.md) ou [IRelogger](irelogger-class.md) para controlar o que deve acontecer em seguida.

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `BLOCK` | Impede que o evento atual se propague mais no analisador ou no grupo de relogger. |
| `CANCEL` | Cancele a sessão de análise ou registro em log atual. |
| `CONTINUE` | Continue a análise atual ou refazendo o log da sessão normalmente. Propague o evento atual para o próximo analisador ou novo membro do grupo de relogger. |
| `FAILURE` | Cancele a sessão de análise ou registro em log atual e sinalize um erro. |

::: moniker-end
