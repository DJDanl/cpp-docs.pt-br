---
title: MakeStaticAnalyzerGroup
description: A C++ referência da função MAKESTATICANALYZERGROUP do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeStaticAnalyzerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 5eabb0fcbb0a0bb0eea0f4e6bbf27b8e4c53c3ab
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332813"
---
# <a name="makestaticanalyzergroup"></a>MakeStaticAnalyzerGroup

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `MakeStaticAnalyzerGroup` é usada para criar um grupo analisador estático que pode ser passado para funções como [Analyze](analyze.md) ou [relog](relog.md). Os membros de um grupo do Analyzer recebem eventos um por um da esquerda para a direita, até que todos os eventos em um rastreamento sejam analisados.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TAnalyzerPtrs>
auto MakeStaticAnalyzerGroup(TAnalyzerPtrs... analyzers);
```

### <a name="parameters"></a>Parâmetros

\ *TAnalyzerPtrs*
Esse parâmetro é sempre deduzido.

*analisadores*\
Um pacote de parâmetros dos ponteiros do [IAnalyzer](../other-types/ianalyzer-class.md) incluídos no grupo do analisador estático. Esses ponteiros podem ser brutos, `std::unique_ptr`ou `std::shared_ptr`.

### <a name="return-value"></a>Valor retornado

Um grupo de analisador estático. Use a palavra-chave **auto** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Ao contrário dos grupos do analisador dinâmico, os membros de um grupo do analisador estático devem ser conhecidos no momento da compilação. Além disso, um grupo de analisador estático contém ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) que não têm comportamento polimórfico. Ao usar um grupo do analisador estático para analisar um rastreamento do ETW (rastreamento de eventos para Windows), as chamadas para a interface `IAnalyzer` sempre são resolvidas para o objeto diretamente apontado pelo membro do grupo do Analyzer. Essa perda de flexibilidade vem com uma possibilidade de tempos de processamento mais rápidos de eventos. Se os membros de um grupo do Analyzer não puderem ser conhecidos no momento da compilação ou se você precisar de comportamento polimórfico nos ponteiros do `IAnalyzer`, considere usar um grupo do analisador dinâmico. Para usar um grupo do analisador dinâmico, chame [MakeDynamicAnalyzerGroup](make-static-analyzer-group.md) em vez disso.

::: moniker-end
