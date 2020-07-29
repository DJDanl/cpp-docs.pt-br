---
title: MakeDynamicAnalyzerGroup
description: A referência da função MakeDynamicAnalyzerGroup do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeDynamicAnalyzerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c4c244066b41837a8dd95b44bab2b096134ed5d4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224195"
---
# <a name="makedynamicanalyzergroup"></a>MakeDynamicAnalyzerGroup

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MakeDynamicAnalyzerGroup` função é usada para criar um grupo do analisador dinâmico. Os membros de um grupo do Analyzer recebem eventos um por um da esquerda para a direita, até que todos os eventos em um rastreamento sejam analisados.

## <a name="syntax"></a>Sintaxe

```cpp
auto MakeDynamicAnalyzerGroup(std::vector<IAnalyzer*> analyzers);

auto MakeDynamicAnalyzerGroup(std::vector<std::shared_ptr<IAnalyzer>> analyzers);

auto MakeDynamicAnalyzerGroup(std::vector<std::unique_ptr<IAnalyzer>> analyzers);
```

### <a name="parameters"></a>parâmetros

*Analisadores*\
Um vetor de ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) incluídos no grupo do analisador dinâmico. Esses ponteiros podem ser brutos, `std::unique_ptr` ou `std::shared_ptr` .

### <a name="return-value"></a>Valor retornado

Um grupo do analisador dinâmico. Use a **`auto`** palavra-chave para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Diferentemente dos grupos do analisador estático, os membros de um grupo do analisador dinâmico não precisam ser conhecidos no momento da compilação. Você pode escolher os membros do grupo do Analyzer em tempo de execução com base na entrada do programa ou com base em outros valores que são desconhecidos no momento da compilação. Ao contrário dos grupos do analisador estático, os [`IAnalyzer`](../other-types/ianalyzer-class.md) ponteiros em um grupo do analisador dinâmico têm comportamento polimórfico e as chamadas de função virtual são expedidas corretamente. Essa flexibilidade acompanha o custo de um tempo de processamento de eventos possivelmente mais lento. Quando todos os membros do grupo do Analyzer forem conhecidos no momento da compilação, e se você não precisar do comportamento polimórfico, considere usar um grupo de analisador estático. Para usar um grupo do analisador estático, chame [`MakeStaticAnalyzerGroup`](make-static-analyzer-group.md) em seu lugar.

Um grupo do analisador dinâmico pode ser encapsulado dentro de um grupo de analisador estático. Isso é feito passando seu endereço para [`MakeStaticAnalyzerGroup`](make-static-analyzer-group.md) . Use essa técnica para passar grupos do analisador dinâmico para funções como [`Analyze`](analyze.md) , que aceitam apenas grupos de analisadores estáticos.

::: moniker-end
