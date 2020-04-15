---
title: Analisar
description: A referência de função C++ Build Insights SDK Analyze.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Analyze
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 08b3643270cc785b3fbea36720d192b4a1473104
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324101"
---
# <a name="analyze"></a>Analisar

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Analyze` função é usada para analisar um rastreamento de rastreamento de eventos para Windows (ETW) obtido do MSVC enquanto traça uma compilação C++. Os eventos no rastreamento eTW são encaminhados sequencialmente para um grupo analisador fornecido pelo chamador. Esta função suporta análises multi-pass que permitem o encaminhamento do fluxo de eventos para o grupo analisador várias vezes seguidas.

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

*Membros do TAnalyzerGroup*\
Este parâmetro é sempre deduzido.

*inputLogFile*\
O rastreamento etw de entrada do que você deseja ler eventos.

*numberOfPasses*\
O número de análises passa para ser executado no rastreamento de entrada. O rastreamento é passado através do grupo analisador fornecido uma vez por passe de análise.

*analyzerGroup*\
O grupo analisador utilizado para a análise. Chamada [MakeStaticAnalyzegroup](make-static-analyzer-group.md) para criar um grupo de analisadores. Para usar um grupo de analisador dinâmico obtido do [MakeDynamicAnalyzerGroup,](make-dynamic-analyzer-group.md)primeiro encapsule-o dentro de um grupo de analisadores estáticos, passando seu endereço para `MakeStaticAnalyzerGroup`.

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

::: moniker-end
