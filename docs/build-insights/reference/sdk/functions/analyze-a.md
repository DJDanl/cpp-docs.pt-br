---
title: AnalyzeA
description: A referência da função Analyze do SDK do insights do C++ Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalyzeA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a2b014c35c2ebc6096b97dd3c0f86bd57e293451
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920301"
---
# <a name="analyzea"></a>AnalyzeA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `AnalyzeA` função é usada para analisar eventos MSVC lidos de um rastreamento ETW (rastreamento de eventos de entrada para Windows).

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE AnalyzeA(
    const char*                inputLogFile,
    const ANALYSIS_DESCRIPTOR* analysisDescriptor);
```

### <a name="parameters"></a>Parâmetros

*inputLogFile*\
O rastreamento ETW de entrada do qual você deseja ler eventos.

*analysisDescriptor*\
Ponteiro para um objeto [ANALYSIS_DESCRIPTOR](../other-types/analysis-descriptor-struct.md) . Use este objeto para configurar a análise.

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
