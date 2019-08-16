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
ms.openlocfilehash: 7064880c5ceef8e7dc3e35bb7ef5bc700b0842d2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511221"
---
# <a name="scrolling-and-scaling-views"></a>Rolando e colocando exibições em escala

O MFC dá suporte a exibições que rolam e exibições que são dimensionadas automaticamente para o tamanho da janela do quadro que as exibe. A `CScrollView` classe oferece suporte a ambos os tipos de modos de exibição.

Para obter mais informações sobre a rolagem e o dimensionamento, consulte classe [CScrollView](../mfc/reference/cscrollview-class.md) na *referência do MFC*. Para obter um exemplo de rolagem, consulte o [exemplo de rabisco](../overview/visual-cpp-samples.md).

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- Rolando uma exibição

- Dimensionando uma exibição

- [Exibir coordenadas](/windows/win32/gdi/window-coordinate-system)

##  <a name="_core_scrolling_a_view"></a>Rolando uma exibição

Frequentemente, o tamanho de um documento é maior do que o tamanho que sua exibição pode exibir. Isso pode ocorrer porque os dados do documento aumentam ou o usuário reduz a janela que moldura a exibição. Nesses casos, a exibição deve dar suporte à rolagem.

Qualquer modo de exibição pode lidar com mensagens de barra `OnHScroll` de `OnVScroll` rolagem em suas funções e membro. Você pode implementar a manipulação de mensagens da barra de rolagem nessas funções, fazendo todo o trabalho por conta própria ou `CScrollView` pode usar a classe para lidar com a rolagem para você.

`CScrollView`o faz o seguinte:

- Gerencia tamanhos de janela e visor e modos de mapeamento

- Rola automaticamente em resposta a mensagens da barra de rolagem

Você pode especificar quanto rolar para uma "página" (quando o usuário clica em um eixo da barra de rolagem) e uma "linha" (quando o usuário clica em uma seta de rolagem). Planeje esses valores para se adequar à natureza do seu modo de exibição. Por exemplo, você pode querer rolar em incrementos de 1 pixel para um modo de exibição de gráficos, mas em incrementos com base na altura da linha em documentos de texto.

##  <a name="_core_scaling_a_view"></a>Dimensionando uma exibição

Quando desejar que a exibição se ajuste automaticamente ao tamanho da janela do quadro, você poderá usar `CScrollView` para dimensionamento em vez de rolar. A exibição lógica é ampliada ou reduzida para se ajustar exatamente à área do cliente da janela. Uma exibição dimensionada não tem barras de rolagem.

## <a name="see-also"></a>Consulte também

[Usando exibições](../mfc/using-views.md)
