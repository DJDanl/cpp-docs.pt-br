---
title: MakeDynamicReloggerGroup
description: A referência da função MakeDynamicReloggerGroup do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeDynamicReloggerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 6bfa5bfbe8a61148f925ba185fccc035fd44d02d
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920262"
---
# <a name="makedynamicreloggergroup"></a>MakeDynamicReloggerGroup

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `MakeDynamicReloggerGroup` função é usada para criar um grupo de reagente dinâmico. Os membros de um grupo de relogger recebem eventos um por um da esquerda para a direita até que todos os eventos em um rastreamento tenham sido processados.

## <a name="syntax"></a>Sintaxe

```cpp
auto MakeDynamicReloggerGroup(std::vector<IRelogger*> reloggers);

auto MakeDynamicReloggerGroup(std::vector<std::shared_ptr<IRelogger>> reloggers);

auto MakeDynamicReloggerGroup(std::vector<std::unique_ptr<IRelogger>> reloggers);
```

### <a name="parameters"></a>Parâmetros

*reagentes*\
Um vetor de ponteiros [IRelogger](../other-types/irelogger-class.md) incluídos no grupo de reagente dinâmico. Esses ponteiros podem ser brutos, `std::unique_ptr` ou `std::shared_ptr` . Os ponteiros do [IAnalyzer](../other-types/ianalyzer-class.md) também são considerados `IRelogger` ponteiros devido a uma relação de herança.

### <a name="return-value"></a>Valor Retornado

Um grupo de reagente dinâmico. Use a **`auto`** palavra-chave para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Diferentemente dos grupos de relogger estáticos, os membros de um grupo de reagente dinâmico não precisam ser conhecidos no momento da compilação. Você pode escolher os membros do grupo de reagente em tempo de execução com base na entrada do programa ou com base em outros valores que são desconhecidos no momento da compilação. Diferentemente dos grupos de relogger estáticos, os [`IRelogger`](../other-types/irelogger-class.md) ponteiros em um grupo de reagente dinâmico têm comportamento polimórfico e as chamadas de função virtual são expedidas corretamente. Essa flexibilidade acompanha o custo de um tempo de processamento de eventos possivelmente mais lento. Quando todos os membros do grupo de reagente são conhecidos no momento da compilação, e se você não precisar do comportamento polimórfico, considere usar um grupo de reagente estático. Para usar um grupo de reagente estático, chame [`MakeStaticReloggerGroup`](make-static-relogger-group.md) em vez disso.

Um grupo de reagente dinâmico pode ser encapsulado dentro de um grupo de reagente estático. Você passa seu endereço para [`MakeStaticReloggerGroup`](make-static-relogger-group.md) . Use essa técnica para passar grupos de reagente dinâmico para funções como [`Relog`](relog.md) , que aceitam apenas grupos de relogger estáticos.

::: moniker-end
