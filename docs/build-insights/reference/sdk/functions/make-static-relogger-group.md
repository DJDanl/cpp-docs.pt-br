---
title: MakeStaticReloggerGroup
description: A referência de função C++ Build Insights SDK MakeStaticReloggerGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeStaticReloggerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 75b638537cb8e0cdeeb5476a3f5277e8e90d9baf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323908"
---
# <a name="makestaticreloggergroup"></a>MakeStaticReloggerGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MakeStaticReloggerGroup` função é usada para criar um grupo de relogger estático que pode ser passado para funções como [Relog](relog.md). Membros de um grupo de relogger recebem eventos um a um da esquerda para a direita até que todos os eventos em um traço tenham sido processados.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename... TReloggerPtrs>
auto MakeStaticReloggerGroup(TReloggerPtrs... reloggers);
```

### <a name="parameters"></a>Parâmetros

*TReloggerPtrs*\
Este parâmetro é sempre deduzido.

*reloggers*\
Um pacote de parâmetros de ponteiros [IRelogger](../other-types/irelogger-class.md) incluídos no grupo relogger estático. Estes ponteiros podem `std::unique_ptr`ser `std::shared_ptr`crus, ou . Os ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) também são considerados `IRelogger` ponteiros por causa de uma relação de herança.

### <a name="return-value"></a>Valor retornado

Um grupo de relogger estático. Use a **palavra-chave automática** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Ao contrário dos grupos de relogger dinâmicos, os membros de um grupo de relogger estático devem ser conhecidos no momento da compilação. Além disso, um grupo de relogger estático contém ponteiros [IRelogger](../other-types/irelogger-class.md) que não têm comportamento polimórfico. Ao usar um grupo de relogger estático para analisar um rastreamento de `IRelogger` Rastreamento de Eventos para Windows (ETW), as chamadas para a interface sempre resolvem o objeto diretamente apontado pelo membro do grupo relogger. Essa perda de flexibilidade vem com a possibilidade de tempos de processamento de eventos mais rápidos. Se os membros de um grupo de relogger não puderem ser conhecidos no `IRelogger` momento da compilação ou se você precisar de comportamento polimórfico em seus ponteiros, considere usar um grupo de relogger dinâmico. Você pode usar um grupo de relogger dinâmico chamando [o MakeDynamicReloggerGroup](make-dynamic-relogger-group.md) em vez disso.

::: moniker-end
