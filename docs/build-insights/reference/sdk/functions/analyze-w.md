---
title: AnalyzeW
description: A C++ referência da função ANALYZEW do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalyzeW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: bd9b401f08941134d3c267df5c23c5d9e981cb86
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332925"
---
# <a name="analyzew"></a>AnalyzeW

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `AnalyzeW` é usada para analisar eventos MSVC lidos de um rastreamento ETW (rastreamento de eventos de entrada para Windows).

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE AnalyzeW(
    const wchar_t*             inputLogFile,
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
