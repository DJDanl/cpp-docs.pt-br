---
title: Rolando e colocando exibições em escala
ms.date: 11/04/2016
helpviewer_keywords:
- message handlers [MFC]
- scaling views [MFC]
- message handling [MFC], scroll bars in view class [MFC]
- scroll bars [MFC], messages
- scrolling views [MFC]
ms.assetid: f98a3421-c336-407e-97ee-dbb2ffd76fbd
ms.openlocfilehash: 366f0e2953e5190f80a2877804bff2fc7dbbd520
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372784"
---
# <a name="scrolling-and-scaling-views"></a>Rolando e colocando exibições em escala

O MFC suporta visualizações que rolam e visualizações que são automaticamente dimensionadas para o tamanho da janela do quadro que os exibe. A `CScrollView` classe suporta ambos os tipos de pontos de vista.

Para obter mais informações sobre rolagem e dimensionamento, consulte [classe CScrollView](../mfc/reference/cscrollview-class.md) na *referência MFC*. Para obter um exemplo de rolagem, consulte a [amostra Scribble](../overview/visual-cpp-samples.md).

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- Rolando uma vista

- Dimensionando uma visão

- [Ver coordenadas](/windows/win32/gdi/window-coordinate-system)

## <a name="scrolling-a-view"></a><a name="_core_scrolling_a_view"></a>Rolando uma exibição

Freqüentemente, o tamanho de um documento é maior do que o tamanho que sua exibição pode exibir. Isso pode ocorrer porque os dados do documento aumentam ou o usuário reduz a janela que enquadra a exibição. Nesses casos, a exibição deve suportar rolagem.

Qualquer visualização pode lidar com `OnHScroll` mensagens de barra de rolagem em suas funções e `OnVScroll` membros. Você pode implementar o manuseio de mensagens de barra de rolagem nessas `CScrollView` funções, fazendo todo o trabalho sozinho, ou pode usar a classe para lidar com rolagem para você.

`CScrollView` faz o seguinte:

- Gerencia tamanhos de janelas e visualizações e modos de mapeamento

- Rola automaticamente em resposta a mensagens de barra de rolagem

Você pode especificar quanto rolar para uma "página" (quando o usuário clica em um eixo de barra de rolagem) e uma "linha" (quando o usuário clica em uma seta de rolagem). Planeje esses valores de acordo com a natureza do seu ponto de vista. Por exemplo, você pode querer rolar em incrementos de 1 pixel para uma exibição gráfica, mas em incrementos com base na altura da linha em documentos de texto.

## <a name="scaling-a-view"></a><a name="_core_scaling_a_view"></a>Dimensionando uma exibição

Quando você quiser que a vista se encaixe automaticamente `CScrollView` no tamanho da janela do quadro, você pode usar para dimensionar em vez de rolar. A visão lógica é esticada ou encolhida para se adequar exatamente à área cliente da janela. Uma exibição dimensionada não tem barras de rolagem.

## <a name="see-also"></a>Confira também

[Usando visualizações](../mfc/using-views.md)
