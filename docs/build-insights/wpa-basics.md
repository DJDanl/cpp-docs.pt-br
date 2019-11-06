---
title: 'C++Informações de compilação: Noções básicas do analisador de desempenho do Windows'
description: Tutorial sobre como concluir operações básicas no analisador de desempenho do Windows.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 4bd91698561175d876b7a3351a0ed6e85ef73a35
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73633080"
---
# <a name="c-build-insights-windows-performance-analyzer-basics"></a>C++Informações de compilação: Noções básicas do analisador de desempenho do Windows

::: moniker range="<=vs-2017"

As C++ ferramentas de informações de compilação estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2019.

::: moniker-end
::: moniker range="vs-2019"

Usar C++ o Build insights efetivamente requer algum conhecimento do Windows Performance Analyzer (WPA). Este artigo ajuda você a se familiarizar com operações WPA comuns. Para obter mais informações sobre como usar o WPA, consulte a documentação do [analisador de desempenho do Windows](/windows-hardware/test/wpt/windows-performance-analyzer) .

## <a name="change-the-view-mode"></a>Alterar o modo de exibição

O WPA oferece dois modos de exibição básicos para explorar seus rastreamentos:

- modo de gráfico e
- modo de tabela.

Você pode alternar entre eles usando os ícones do modo de exibição na parte superior do painel de exibição:

![Alternando entre o modo de gráfico e o modo de tabela.](media/wpa-switching-view-mode.gif)

## <a name="select-presets"></a>Selecionar predefinições

A C++ maioria das exibições de WPA dos insights de compilação tem várias predefinições para escolher. Você pode selecionar a predefinição desejada usando o menu suspenso na parte superior do painel de exibição:

![Selecionando uma predefinição.](media/wpa-presets.png)

## <a name="zoom-in-and-out"></a>Ampliar e reduzir

Alguns rastreamentos de Build são tão grandes que é difícil destacar os detalhes. Para ampliar uma área que lhe interessa, clique com o botão direito do mouse no grafo e selecione **zoom**. Você sempre pode voltar para a configuração anterior escolhendo **desfazer zoom**. Esta imagem mostra um exemplo de como usar uma seleção e o comando de **zoom** para ampliar uma seção do grafo:

![Zoom em um grafo.](media/wpa-zooming.gif)

## <a name="group-by-different-columns"></a>Agrupar por colunas diferentes

Você pode personalizar a maneira como seu rastreamento é exibido. Clique no ícone de engrenagem na parte superior de um painel de exibição e Reorganize as colunas no editor de exibição do Gerenciador de compilação. As colunas encontradas acima da linha amarela nessa caixa de diálogo são as linhas de dados que são agrupadas. A coluna à direita acima da linha amarela é especial: na exibição de gráfico, ela é exibida nas barras coloridas.

Esta imagem mostra um gráfico de barras de exemplo de uma invocação de link. Usamos o ícone de engrenagem para abrir a caixa de diálogo Editor de exibição do Gerenciador de compilação. Em seguida, arrastamos as entradas de coluna Component e Name acima da linha amarela. A configuração é alterada para aumentar o nível de detalhes e para ver o que realmente aconteceu dentro do vinculador:

![Zoom em um grafo.](media/wpa-grouping.gif)

## <a name="see-also"></a>Consulte também

[Introdução às informações C++ de compilação](get-started-with-cpp-build-insights.md)\
\ de [referência do vcperf. exe](vcperf-reference.md)
[Referência de exibições do analisador de desempenho do Windows](wpa-views-reference.md)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
