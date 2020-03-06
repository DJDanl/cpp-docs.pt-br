---
title: Analisar
description: A C++ referência de função de análise do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalyzeA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 9f5a7b91bf0cd6fd45f97880a99e1f56a85d74ed
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332911"
---
# <a name="analyzea"></a>Analisar

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `AnalyzeA` é usada para analisar eventos MSVC lidos de um rastreamento ETW (rastreamento de eventos de entrada para Windows).

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE AnalyzeA(
    const char*                inputLogFile,
    const ANALYSIS_DESCRIPTOR* analysisDescriptor);
```

### <a name="parameters"></a>Parâmetros

\ *inputLogFile*
O rastreamento ETW de entrada do qual você deseja ler eventos.

\ *analysisDescriptor*
Ponteiro para um objeto [ANALYSIS_DESCRIPTOR](../other-types/analysis-descriptor-struct.md) . Use este objeto para configurar a análise.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
