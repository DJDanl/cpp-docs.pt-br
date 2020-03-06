---
title: MakeStaticReloggerGroup
description: A C++ referência da função MAKESTATICRELOGGERGROUP do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeStaticReloggerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 06927af89b16d9de1148e555868dd2022c59b171
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332806"
---
# <a name="makestaticreloggergroup"></a>MakeStaticReloggerGroup

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `MakeStaticReloggerGroup` é usada para criar um grupo de reagente estático que pode ser passado para funções como [relog](relog.md). Os membros de um grupo de relogger recebem eventos um por um da esquerda para a direita até que todos os eventos em um rastreamento tenham sido processados.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TReloggerPtrs>
auto MakeStaticReloggerGroup(TReloggerPtrs... reloggers);
```

### <a name="parameters"></a>Parâmetros

\ *TReloggerPtrs*
Esse parâmetro é sempre deduzido.

*reagentes*\
Um pacote de parâmetros de ponteiros do [IRelogger](../other-types/irelogger-class.md) que está incluído no grupo de reagente estático. Esses ponteiros podem ser brutos, `std::unique_ptr`ou `std::shared_ptr`. Os ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) também são considerados ponteiros de `IRelogger` devido a uma relação de herança.

### <a name="return-value"></a>Valor retornado

Um grupo de reagente estático. Use a palavra-chave **auto** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Diferentemente dos grupos de relogger dinâmicos, os membros de um grupo de reagente estático devem ser conhecidos no momento da compilação. Além disso, um grupo de reagente estático contém ponteiros [IRelogger](../other-types/irelogger-class.md) que não têm comportamento polimórfico. Ao usar um grupo de relogger estático para analisar um rastreamento de ETW (rastreamento de eventos para Windows), as chamadas para a interface `IRelogger` sempre são resolvidas para o objeto diretamente apontado pelo membro do grupo relogger. Essa perda de flexibilidade vem com uma possibilidade de tempos de processamento mais rápidos de eventos. Se os membros de um grupo de relogger não puderem ser conhecidos no momento da compilação ou se você precisar de comportamento polimórfico em seus ponteiros de `IRelogger`, considere usar um grupo de reagente dinâmico. Você pode usar um grupo de relogger dinâmico chamando [MakeDynamicReloggerGroup](make-dynamic-relogger-group.md) em vez disso.

::: moniker-end
