---
title: MakeStaticReloggerGroup
description: A referência da função MakeStaticReloggerGroup do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeStaticReloggerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1d49f15a14675f265e1f63ef8795f442f49ad5d4
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920197"
---
# <a name="makestaticreloggergroup"></a>MakeStaticReloggerGroup

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `MakeStaticReloggerGroup` função é usada para criar um grupo de reagente estático que pode ser passado para funções como [relog](relog.md). Os membros de um grupo de relogger recebem eventos um por um da esquerda para a direita até que todos os eventos em um rastreamento tenham sido processados.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TReloggerPtrs>
auto MakeStaticReloggerGroup(TReloggerPtrs... reloggers);
```

### <a name="parameters"></a>Parâmetros

*TReloggerPtrs*\
Esse parâmetro é sempre deduzido.

*reagentes*\
Um pacote de parâmetros de [`IRelogger`](../other-types/irelogger-class.md) ponteiros que é incluído no grupo de reagente estático. Esses ponteiros podem ser brutos, `std::unique_ptr` ou `std::shared_ptr` . [`IAnalyzer`](../other-types/ianalyzer-class.md) os ponteiros também são considerados `IRelogger` ponteiros devido a uma relação de herança.

### <a name="return-value"></a>Valor Retornado

Um grupo de reagente estático. Use a **`auto`** palavra-chave para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Diferentemente dos grupos de relogger dinâmicos, os membros de um grupo de reagente estático devem ser conhecidos no momento da compilação. Além disso, um grupo de reagente estático contém [`IRelogger`](../other-types/irelogger-class.md) ponteiros que não têm comportamento polimórfico. Ao usar um grupo de relogger estático para analisar um rastreamento de ETW (rastreamento de eventos para Windows), as chamadas para a `IRelogger` interface sempre são resolvidas para o objeto apontado diretamente pelo membro do grupo de relogger. Essa perda de flexibilidade vem com uma possibilidade de tempos de processamento mais rápidos de eventos. Se os membros de um grupo de relogger não puderem ser conhecidos no momento da compilação ou se você precisar de comportamento polimórfico em seus `IRelogger` ponteiros, considere o uso de um grupo de reagente dinâmico. Você pode usar um grupo de relogger dinâmico chamando [`MakeDynamicReloggerGroup`](make-dynamic-relogger-group.md) em vez disso.

::: moniker-end
