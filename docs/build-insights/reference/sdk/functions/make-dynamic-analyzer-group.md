---
title: MakeDynamicAnalyzerGroup
description: A referência da função C++ Build Insights SDK MakeDynamicAnalyzerGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeDynamicAnalyzerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 148eeea41f29ac6dd75653feed7f3f3f8c301911
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323966"
---
# <a name="makedynamicanalyzergroup"></a>MakeDynamicAnalyzerGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MakeDynamicAnalyzerGroup` função é usada para criar um grupo analisador dinâmico. Os membros de um grupo de analisadores recebem eventos um a um da esquerda para a direita, até que todos os eventos em um rastreamento sejam analisados.

## <a name="syntax"></a>Sintaxe

```cpp
auto MakeDynamicAnalyzerGroup(std::vector<IAnalyzer*> analyzers);

auto MakeDynamicAnalyzerGroup(std::vector<std::shared_ptr<IAnalyzer>> analyzers);

auto MakeDynamicAnalyzerGroup(std::vector<std::unique_ptr<IAnalyzer>> analyzers);
```

### <a name="parameters"></a>Parâmetros

*Analisadores*\
Um vetor de ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) incluído no grupo analisador dinâmico. Estes ponteiros podem `std::unique_ptr`ser `std::shared_ptr`crus, ou .

### <a name="return-value"></a>Valor retornado

Um grupo de analisadores dinâmicos. Use a **palavra-chave automática** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Ao contrário dos grupos analisadores estáticos, os membros de um grupo analisador dinâmico não precisam ser conhecidos no momento da compilação. Você pode escolher membros do grupo analisador em tempo de execução com base na entrada do programa ou com base em outros valores que são desconhecidos no momento da compilação. Ao contrário dos grupos de analisadores estáticos, os ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) dentro de um grupo de analisador dinâmico têm comportamento polimórfico e as chamadas de função virtual são despachadas corretamente. Essa flexibilidade vem ao custo de um tempo de processamento de eventos possivelmente mais lento. Quando todos os membros do grupo analisador são conhecidos no momento da compilação, e se você não precisar de comportamento polimórfico, considere usar um grupo analisador estático. Para usar um grupo de analisadores estáticos, chame [MakeStaticAnalyzerGroup.](make-static-analyzer-group.md)

Um grupo analisador dinâmico pode ser encapsulado dentro de um grupo analisador estático. É feito passando seu endereço para [MakeStaticAnalyzerGroup](make-static-analyzer-group.md). Use essa técnica para passar grupos de analisadores dinâmicos para funções como [Analyze,](analyze.md)que só aceitam grupos de analisadores estáticos.

::: moniker-end
