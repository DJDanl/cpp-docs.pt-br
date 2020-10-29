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
ms.openlocfilehash: 0f4887d626c5e80a0afaa393e255f8ffedbd6b1f
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922616"
---
# <a name="analysiscontrol-enum-class"></a>Classe de enumeração AnalysisControl

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `AnalysisControl` classe enum é usada para controlar o fluxo de uma sessão de análise ou de registro em log. Retornar um `AnalysisControl` código de uma função de membro [IAnalyzer](ianalyzer-class.md) ou [IRelogger](irelogger-class.md) para controlar o que deve acontecer em seguida.

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `BLOCK` | Impede que o evento atual se propague mais no analisador ou no grupo de relogger. |
| `CANCEL` | Cancele a sessão de análise ou registro em log atual. |
| `CONTINUE` | Continue a análise atual ou refazendo o log da sessão normalmente. Propague o evento atual para o próximo analisador ou novo membro do grupo de relogger. |
| `FAILURE` | Cancele a sessão de análise ou registro em log atual e sinalize um erro. |

::: moniker-end
