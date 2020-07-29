---
title: MakeStaticAnalyzerGroup
description: A referência da função MakeStaticAnalyzerGroup do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeStaticAnalyzerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 81c5654c78e086af1c33d0791768ceea52575c51
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224169"
---
# <a name="makestaticanalyzergroup"></a>MakeStaticAnalyzerGroup

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MakeStaticAnalyzerGroup` função é usada para criar um grupo de analisador estático que pode ser passado para funções como [`Analyze`](analyze.md) ou [`Relog`](relog.md) . Os membros de um grupo do Analyzer recebem eventos um por um da esquerda para a direita, até que todos os eventos em um rastreamento sejam analisados.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TAnalyzerPtrs>
auto MakeStaticAnalyzerGroup(TAnalyzerPtrs... analyzers);
```

### <a name="parameters"></a>parâmetros

*TAnalyzerPtrs*\
Esse parâmetro é sempre deduzido.

*Analisadores*\
Um pacote de parâmetros de [`IAnalyzer`](../other-types/ianalyzer-class.md) ponteiros incluídos no grupo do analisador estático. Esses ponteiros podem ser brutos, `std::unique_ptr` ou `std::shared_ptr` .

### <a name="return-value"></a>Valor retornado

Um grupo de analisador estático. Use a **`auto`** palavra-chave para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Ao contrário dos grupos do analisador dinâmico, os membros de um grupo do analisador estático devem ser conhecidos no momento da compilação. Além disso, um grupo de analisador estático contém [`IAnalyzer`](../other-types/ianalyzer-class.md) ponteiros que não têm comportamento polimórfico. Ao usar um grupo do analisador estático para analisar um rastreamento do ETW (rastreamento de eventos para Windows), as chamadas para a `IAnalyzer` interface sempre são resolvidas para o objeto diretamente apontado pelo membro do grupo do Analyzer. Essa perda de flexibilidade vem com uma possibilidade de tempos de processamento mais rápidos de eventos. Se os membros de um grupo do analisador não puderem ser conhecidos no momento da compilação ou se você precisar de comportamento polimórfico em seus `IAnalyzer` ponteiros, considere usar um grupo do analisador dinâmico. Para usar um grupo do analisador dinâmico, chame [`MakeDynamicAnalyzerGroup`](make-static-analyzer-group.md) em vez disso.

::: moniker-end
