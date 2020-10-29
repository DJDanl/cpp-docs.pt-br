---
title: 'Tutorial: Noções básicas do analisador de desempenho do Windows'
description: Tutorial sobre como concluir operações básicas no analisador de desempenho do Windows.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 75f45244b9e9b38b7dc65b604940199acafa0ede
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922212"
---
# <a name="tutorial-windows-performance-analyzer-basics"></a>Tutorial: Noções básicas do analisador de desempenho do Windows

::: moniker range="<=msvc-150"

As ferramentas de compilação do C++ estão disponíveis no Visual Studio 2019. Para ver a documentação desta versão, defina o controle do seletor de **versão** do Visual Studio para este artigo como Visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range="msvc-160"

Usar as informações de compilação do C++ efetivamente requer algum conhecimento do Windows Performance Analyzer (WPA). Este artigo ajuda você a se familiarizar com operações WPA comuns. Para obter mais informações sobre como usar o WPA, consulte a documentação do [analisador de desempenho do Windows](/windows-hardware/test/wpt/windows-performance-analyzer) .

## <a name="change-the-view-mode"></a>Alterar o modo de exibição

O WPA oferece dois modos de exibição básicos para explorar seus rastreamentos:

- modo de gráfico e
- modo de tabela.

Você pode alternar entre eles usando os ícones do modo de exibição na parte superior do painel de exibição:

![Alternando entre o modo de gráfico e o modo de tabela.](media/wpa-switching-view-mode.gif)

## <a name="select-presets"></a>Selecionar predefinições

A maioria dos modos de exibição de WPA das informações de Build do C++ tem várias predefinições para escolher. Você pode selecionar a predefinição desejada usando o menu suspenso na parte superior do painel de exibição:

![Selecionando uma predefinição.](media/wpa-presets.png)

## <a name="zoom-in-and-out"></a>Ampliar e reduzir

Alguns rastreamentos de Build são tão grandes que é difícil destacar os detalhes. Para ampliar uma área que lhe interessa, clique com o botão direito do mouse no grafo e selecione **zoom** . Você sempre pode voltar para a configuração anterior escolhendo **desfazer zoom** . Esta imagem mostra um exemplo de como usar uma seleção e o comando de **zoom** para ampliar uma seção do grafo:

![Vídeo curto mostrando o zoom em um grafo.](media/wpa-zooming.gif)

## <a name="group-by-different-columns"></a>Agrupar por colunas diferentes

Você pode personalizar a maneira como seu rastreamento é exibido. Clique no ícone de engrenagem na parte superior de um painel de exibição e Reorganize as colunas no editor de exibição do Gerenciador de compilação. As colunas encontradas acima da linha amarela nessa caixa de diálogo são as linhas de dados que são agrupadas. A coluna à direita acima da linha amarela é especial: na exibição de gráfico, ela é exibida nas barras coloridas.

Esta imagem mostra um gráfico de barras de exemplo de uma invocação de link. Usamos o ícone de engrenagem para abrir a caixa de diálogo Editor de exibição do Gerenciador de compilação. Em seguida, arrastamos as entradas de coluna Component e Name acima da linha amarela. A configuração é alterada para aumentar o nível de detalhes e para ver o que realmente aconteceu dentro do vinculador:

![Vídeo curto mostrando como você pode agrupar por colunas diferentes.](media/wpa-grouping.gif)

## <a name="see-also"></a>Veja também

[Tutorial: vcperf e analisador de desempenho do Windows](vcperf-and-wpa.md)\
[Referência: comandos vcperf](../reference/vcperf-commands.md)\
[Referência: exibições do analisador de desempenho do Windows](../reference/wpa-views.md)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
