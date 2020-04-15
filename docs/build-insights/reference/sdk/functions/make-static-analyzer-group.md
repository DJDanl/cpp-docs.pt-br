---
title: MakeStaticAnalyzerGroup
description: A referência da função C++ Build Insights SDK MakeStaticAnalyzerGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeStaticAnalyzerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 72f7f5d7a408436902394451a52dd66efe1d93f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323938"
---
# <a name="makestaticanalyzergroup"></a>MakeStaticAnalyzerGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MakeStaticAnalyzerGroup` função é usada para criar um grupo analisador estático que pode ser passado para funções como [Analisar](analyze.md) ou [Relog](relog.md). Os membros de um grupo de analisadores recebem eventos um a um da esquerda para a direita, até que todos os eventos em um rastreamento sejam analisados.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TAnalyzerPtrs>
auto MakeStaticAnalyzerGroup(TAnalyzerPtrs... analyzers);
```

### <a name="parameters"></a>Parâmetros

*TAnalyzerPtrs*\
Este parâmetro é sempre deduzido.

*Analisadores*\
Um pacote de parâmetros de ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) incluídos no grupo analisador estático. Estes ponteiros podem `std::unique_ptr`ser `std::shared_ptr`crus, ou .

### <a name="return-value"></a>Valor retornado

Um grupo de analisadores estáticos. Use a **palavra-chave automática** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Ao contrário dos grupos de analisadores dinâmicos, os membros de um grupo analisador estático devem ser conhecidos no momento da compilação. Além disso, um grupo de analisadores estáticos contém ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) que não têm comportamento polimórfico. Ao usar um grupo de analisador estático para analisar um rastreamento de `IAnalyzer` Rastreamento de Eventos para Windows (ETW), as chamadas para a interface sempre resolvem o objeto diretamente apontado pelo membro do grupo analisador. Essa perda de flexibilidade vem com a possibilidade de tempos de processamento de eventos mais rápidos. Se os membros de um grupo analisador não puderem ser conhecidos no momento `IAnalyzer` da compilação ou se você precisar de comportamento polimórfico em seus ponteiros, considere usar um grupo analisador dinâmico. Para usar um grupo de analisadores dinâmicos, ligue para [o MakeDynamicAnalyzerGroup.](make-static-analyzer-group.md)

::: moniker-end
