---
title: 'Tutorial: Noções básicas do Analisador de Desempenho do Windows'
description: Tutorial sobre como concluir operações básicas no Windows Performance Analyzer.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ae1050b9389527a12f5bdbea6d695c0f20510127
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323391"
---
# <a name="tutorial-windows-performance-analyzer-basics"></a>Tutorial: Noções básicas do Analisador de Desempenho do Windows

::: moniker range="<=vs-2017"

As ferramentas C++ Build Insights estão disponíveis no Visual Studio 2019. Para ver a documentação desta versão, defina o controle do seletor Visual Studio **Version** para este artigo para o Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range="vs-2019"

O uso do C++ Build Insights requer efetivamente algum conhecimento do WPA (Windows Performance Analyzer). Este artigo ajuda você a se familiarizar com as operações comuns de WPA. Para obter mais informações sobre como usar o WPA, consulte a documentação do [Analisador de Desempenho](/windows-hardware/test/wpt/windows-performance-analyzer) do Windows.

## <a name="change-the-view-mode"></a>Alterar o modo de exibição

O WPA oferece dois modos básicos de visualização para você explorar seus traços:

- modo gráfico, e
- modo tabela.

Você pode alternar entre eles usando os ícones do modo de exibição na parte superior do painel de exibição:

![Alternando entre o modo gráfico e o modo de tabela.](media/wpa-switching-view-mode.gif)

## <a name="select-presets"></a>Selecione predefinições

A maioria das visualizações do C++ Build Insights WPA tem várias predefinições para você escolher. Você pode selecionar a preconfiguração desejada usando o menu suspenso na parte superior do painel de exibição:

![Selecionando uma pré-configuração.](media/wpa-presets.png)

## <a name="zoom-in-and-out"></a>Ampliar e reduzir

Alguns traços de construção são tão grandes que é difícil descobrir os detalhes. Para ampliar uma área que lhe interessa, clique com o botão direito do mouse no gráfico e selecione **Zoom**. Você sempre pode voltar para a configuração anterior escolhendo **Desfazer Zoom**. Esta imagem mostra um exemplo de uso de uma seleção e o comando **Zoom** para ampliar uma seção do gráfico:

![Ampliando um gráfico.](media/wpa-zooming.gif)

## <a name="group-by-different-columns"></a>Grupo por diferentes colunas

Você pode personalizar a forma como seu traço é exibido. Clique no ícone de engrenagem na parte superior de um painel de exibição e reorganize as colunas no Build Explorer View Editor. As colunas encontradas acima da linha amarela nesta caixa de diálogo são as que suas linhas de dados são agrupadas. A coluna logo acima da linha amarela é especial: na vista do gráfico, é exibida nas barras coloridas.

Esta imagem mostra um gráfico de barras de exemplo de uma invocação de link. Usamos o ícone de engrenagem para abrir a caixa de diálogo Build Explorer View Editor. Em seguida, arrastamos as entradas da coluna Componente e Nome acima da linha amarela. A configuração é alterada para aumentar o nível de detalhes e ver o que realmente aconteceu dentro do linker:

![Ampliando um gráfico.](media/wpa-grouping.gif)

## <a name="see-also"></a>Confira também

[Tutorial: vcperf e Analisador de Desempenho do Windows](vcperf-and-wpa.md)\
[Referência: comandos vcperf](/cpp/build-insights/reference/vcperf-commands)\
[Referência: Visualizações do Analisador de Desempenho do Windows](/cpp/build-insights/reference/wpa-views)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
