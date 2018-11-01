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
ms.openlocfilehash: acef79a89da88773da564fc965a607e2fd5b53f7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50626079"
---
# <a name="scrolling-and-scaling-views"></a>Rolando e colocando exibições em escala

MFC dá suporte a modos de exibição que rolagem e exibições que são dimensionados automaticamente para o tamanho da janela do quadro que exibe-os. Classe `CScrollView` dá suporte a ambos os tipos de modos de exibição.

Para obter mais informações sobre a rolagem e o dimensionamento, consulte a classe [CScrollView](../mfc/reference/cscrollview-class.md) na *referência da MFC*. Para obter um exemplo de rolagem, consulte o [exemplo de Scribble](../visual-cpp-samples.md).

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- Um modo de exibição de rolagem

- Dimensionando um modo de exibição

- [Coordenadas de exibição](/windows/desktop/gdi/window-coordinate-system)

##  <a name="_core_scrolling_a_view"></a> Um modo de exibição de rolagem

Com frequência, o tamanho de um documento é maior que o tamanho do que seu modo de exibição pode exibir. Isso pode ocorrer porque os dados do documento aumentam ou o usuário diminui a janela que o modo de exibição de quadros. Nesses casos, o modo de exibição deve oferecer suporte a rolagem.

Qualquer modo de exibição pode lidar com mensagens de barra de rolagem no seu `OnHScroll` e `OnVScroll` funções de membro. É possível que qualquer manipulação de mensagens de barra de rolagem de implementar nessas funções, fazendo todo o trabalho por conta própria, ou você pode usar o `CScrollView` classe para manipular a rolagem para você.

`CScrollView` faz o seguinte:

- Gerencia os tamanhos de janela e o visor e modos de mapeamento

- Rola automaticamente em resposta às mensagens de barra de rolagem

Você pode especificar quanto para rolar para uma "página" (quando o usuário clica em um eixo de barra de rolagem) e "linha" (quando o usuário clica em uma seta de rolagem). Planeje a esses valores de acordo com a natureza do modo de exibição. Por exemplo, você talvez queira Role em incrementos de 1 pixel para um modo de exibição de gráficos, mas em incrementos com base na altura da linha em documentos de texto.

##  <a name="_core_scaling_a_view"></a> Dimensionando um modo de exibição

Quando você quiser que o modo de exibição para ajustar automaticamente o tamanho da sua janela de quadro, você pode usar `CScrollView` para dimensionamento, em vez de rolagem. O modo de exibição lógico é ampliado ou reduzido para ajustar a área de cliente da janela exatamente. Uma exibição em escala não tem nenhuma barra de rolagem.

## <a name="see-also"></a>Consulte também

[Usando exibições](../mfc/using-views.md)

