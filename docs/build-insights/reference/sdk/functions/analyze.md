---
title: Analisar
description: A referência da função Analyze do SDK do insights do C++ Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Analyze
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 5e593b690231adf6f04161f9c3ff6aef3217f9ef
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920314"
---
# <a name="analyze"></a>Analisar

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `Analyze` função é usada para analisar um rastreamento ETW (rastreamento de eventos para Windows) obtido do MSVC durante o rastreamento de uma compilação C++. Os eventos no rastreamento ETW são encaminhados sequencialmente para um grupo do Analyzer fornecido pelo chamador. Essa função dá suporte a análises de várias passagens que permitem o encaminhamento do fluxo de eventos para o grupo do analisador várias vezes em uma linha.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TAnalyzerGroupMembers>
RESULT_CODE Analyze(
    const char*                                   inputLogFile,
    unsigned                                      numberOfPasses,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup);

template <typename... TAnalyzerGroupMembers>
RESULT_CODE Analyze(
    const wchar_t*                                inputLogFile,
    unsigned                                      numberOfPasses,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup);
```

### <a name="parameters"></a>Parâmetros

*TAnalyzerGroupMembers*\
Esse parâmetro é sempre deduzido.

*inputLogFile*\
O rastreamento ETW de entrada do qual você deseja ler eventos.

*numberOfPasses*\
O número de etapas de análise a serem executadas no rastreamento de entrada. O rastreamento é passado pelo grupo analisador fornecido uma vez por passagem de análise.

*fileanalyzer*\
O grupo do analisador usado para a análise. Chame [MakeStaticAnalyzerGroup](make-static-analyzer-group.md) para criar um grupo do Analyzer. Para usar um grupo do analisador dinâmico obtido do [MakeDynamicAnalyzerGroup](make-dynamic-analyzer-group.md), primeiro encapsula-o dentro de um grupo do analisador estático passando seu endereço para `MakeStaticAnalyzerGroup` .

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
