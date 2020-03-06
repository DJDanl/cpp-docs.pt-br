---
title: Classe de enumeração AnalysisControl
description: A C++ referência de enumeração do SDK do insights do Build AnalysisControl.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalysisControl
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: cf162c11e0a7109b8d733dab79df80782398e14d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332498"
---
# <a name="analysiscontrol-enum-class"></a>Classe de enumeração AnalysisControl

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe de enumeração `AnalysisControl` é usada para controlar o fluxo de uma sessão de análise ou de registro em log. Retornar um código de `AnalysisControl` de uma função de membro [IAnalyzer](ianalyzer-class.md) ou [IRelogger](irelogger-class.md) para controlar o que deve acontecer em seguida.

## <a name="members"></a>Membros

|  |  |
|--|--|
| `BLOCK` | Impede que o evento atual se propague mais no analisador ou no grupo de relogger. |
| `CANCEL` | Cancele a sessão de análise ou registro em log atual. |
| `CONTINUE` | Continue a análise atual ou refazendo o log da sessão normalmente. Propague o evento atual para o próximo analisador ou novo membro do grupo de relogger. |
| `FAILURE` | Cancele a sessão de análise ou registro em log atual e sinalize um erro. |

::: moniker-end
