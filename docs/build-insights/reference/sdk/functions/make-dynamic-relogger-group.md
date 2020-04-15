---
title: MakeDynamicReloggerGroup
description: A referência de função C++ Build Insights SDK MakeDynamicReloggerGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- MakeDynamicReloggerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f49e37f8e1a8b9ca9a800d20b2891a54453095ef
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323948"
---
# <a name="makedynamicreloggergroup"></a>MakeDynamicReloggerGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `MakeDynamicReloggerGroup` função é usada para criar um grupo de relogger dinâmico. Membros de um grupo de relogger recebem eventos um a um da esquerda para a direita até que todos os eventos em um traço tenham sido processados.

## <a name="syntax"></a>Sintaxe

```cpp
auto MakeDynamicReloggerGroup(std::vector<IRelogger*> reloggers);

auto MakeDynamicReloggerGroup(std::vector<std::shared_ptr<IRelogger>> reloggers);

auto MakeDynamicReloggerGroup(std::vector<std::unique_ptr<IRelogger>> reloggers);
```

### <a name="parameters"></a>Parâmetros

*reloggers*\
Um vetor de ponteiros [IRelogger](../other-types/irelogger-class.md) incluído no grupo relogger dinâmico. Estes ponteiros podem `std::unique_ptr`ser `std::shared_ptr`crus, ou . Os ponteiros [IAnalyzer](../other-types/ianalyzer-class.md) também são considerados `IRelogger` ponteiros por causa de uma relação de herança.

### <a name="return-value"></a>Valor retornado

Um grupo de relogger dinâmico. Use a **palavra-chave automática** para capturar o valor de retorno.

## <a name="remarks"></a>Comentários

Ao contrário dos grupos de relogger estáticos, os membros de um grupo de relogger dinâmico não precisam ser conhecidos no momento da compilação. Você pode escolher membros do grupo relogger em tempo de execução com base na entrada do programa ou com base em outros valores que são desconhecidos no momento da compilação. Ao contrário dos grupos de relogger estáticos, os ponteiros [IRelogger](../other-types/irelogger-class.md) dentro de um grupo de relogger dinâmico têm comportamento polimórfico e as chamadas de função virtual são despachadas corretamente. Essa flexibilidade vem ao custo de um tempo de processamento de eventos possivelmente mais lento. Quando todos os membros do grupo relogger forem conhecidos na hora da compilação e se você não precisar de comportamento polimórfico, considere usar um grupo de relogger estático. Para usar um grupo de relogger estático, ligue para [o MakeStaticReloggerGroup.](make-static-relogger-group.md)

Um grupo de relogger dinâmico pode ser encapsulado dentro de um grupo de relogger estático. Você passa seu endereço para [MakeStaticReloggerGroup](make-static-relogger-group.md). Use essa técnica para passar grupos de relogger dinâmicos para funções como [Relog](relog.md), que só aceitam grupos de relogger estáticos.

::: moniker-end
