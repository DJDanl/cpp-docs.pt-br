---
title: MakeDynamicAnalyzerGroup
description: A C++ referência da função MAKEDYNAMICANALYZERGROUP do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeDynamicAnalyzerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f409d685c6af6514b73cd837d668a962c1a0d01a
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332827"
---
# <a name="makedynamicanalyzergroup"></a>MakeDynamicAnalyzerGroup

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `MakeDynamicAnalyzerGroup` é usada para criar um grupo do analisador dinâmico. Os membros de um grupo do Analyzer recebem eventos um por um da esquerda para a direita, até que todos os eventos em um rastreamento sejam analisados.

## <a name="syntax"></a>Sintaxe

```cpp
auto MakeDynamicAnalyzerGroup(std::vector<IAnalyzer*> analyzers);

auto MakeDynamicAnalyzerGroup(std::vector<std::shared_ptr<IAnalyzer>> analyzers);

auto MakeDynamicAnalyzerGroup(std::vector<std::unique_ptr<IAnalyzer>> analyzers);
```

### <a name="parameters"></a>Parâmetros

*analisadores*\
Um vetor de ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) incluídos no grupo do analisador dinâmico. Esses ponteiros podem ser brutos, `std::unique_ptr`ou `std::shared_ptr`.

### <a name="return-value"></a>Valor retornado

Um grupo do analisador dinâmico. Use a palavra-chave **auto** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Diferentemente dos grupos do analisador estático, os membros de um grupo do analisador dinâmico não precisam ser conhecidos no momento da compilação. Você pode escolher os membros do grupo do Analyzer em tempo de execução com base na entrada do programa ou com base em outros valores que são desconhecidos no momento da compilação. Ao contrário dos grupos do analisador estático, os ponteiros do [IAnalyzer](../other-types/ianalyzer-class.md) em um grupo do analisador dinâmico têm comportamento polimórfico e as chamadas de função virtual são expedidas corretamente. Essa flexibilidade acompanha o custo de um tempo de processamento de eventos possivelmente mais lento. Quando todos os membros do grupo do Analyzer forem conhecidos no momento da compilação, e se você não precisar do comportamento polimórfico, considere usar um grupo de analisador estático. Para usar um grupo do analisador estático, chame [MakeStaticAnalyzerGroup](make-static-analyzer-group.md) em vez disso.

Um grupo do analisador dinâmico pode ser encapsulado dentro de um grupo de analisador estático. Isso é feito passando seu endereço para [MakeStaticAnalyzerGroup](make-static-analyzer-group.md). Use essa técnica para passar grupos do analisador dinâmico para funções como, por exemplo, [analisar](analyze.md), que aceitam apenas grupos de analisadores estáticos.

::: moniker-end
