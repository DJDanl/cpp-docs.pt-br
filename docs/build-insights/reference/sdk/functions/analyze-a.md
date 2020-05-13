---
title: AnalyzeA
description: A referência de função C++ Build Insights SDK AnalyzeA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- AnalyzeA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7c7602c49ab5f3ce67693424019e253727563293
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324137"
---
# <a name="analyzea"></a>AnalyzeA

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `AnalyzeA` função é usada para analisar eventos MSVC lidos a partir de um rastreamento de evento de entrada para Windows (ETW).

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE AnalyzeA(
    const char*                inputLogFile,
    const ANALYSIS_DESCRIPTOR* analysisDescriptor);
```

### <a name="parameters"></a>Parâmetros

*inputLogFile*\
O rastreamento etw de entrada do que você deseja ler eventos.

*análiseDescritor*\
Ponteiro para um objeto [ANALYSIS_DESCRIPTOR.](../other-types/analysis-descriptor-struct.md) Use este objeto para configurar a análise.

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

::: moniker-end
