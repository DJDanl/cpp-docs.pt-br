---
title: Arrastando imagens a partir de uma lista de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], dragging images from
- dragging images from image lists [MFC]
- image lists [MFC], dragging images from
- images [MFC], dragging from image lists
ms.assetid: af691db8-e4f0-4046-b7b9-9acc68d3713d
ms.openlocfilehash: ba56a38cfc5ccf808c7d95f24666fff0313ecc43
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57294506"
---
# <a name="dragging-images-from-an-image-list"></a>Arrastando imagens a partir de uma lista de imagens

[CImageList](../mfc/reference/cimagelist-class.md) inclui funções para arrastar uma imagem na tela. As funções de arrastar mover uma imagem sem problemas, cor e sem qualquer piscando do cursor. Imagens mascaradas e sem máscara podem ser arrastadas.

O [BeginDrag](../mfc/reference/cimagelist-class.md#begindrag) função de membro começa uma operação de arrastar. Os parâmetros incluem o índice da imagem para arrastar e o local do ponto ativo dentro da imagem. O ponto de acesso é um único pixel em que as funções de arrastar reconhecem como o local exato de tela da imagem. Normalmente, um aplicativo define o ponto de acesso para que ela coincida com o ponto de acesso do cursor do mouse. O [DragMove](../mfc/reference/cimagelist-class.md#dragmove) função de membro Move a imagem para um novo local.

O [DragEnter](../mfc/reference/cimagelist-class.md#dragenter) define a posição inicial da imagem arraste dentro de uma janela de função de membro e desenha a imagem na posição. Os parâmetros incluem um ponteiro para a janela na qual desenhar a imagem e um ponto que especifica as coordenadas da posição inicial dentro da janela. As coordenadas são em relação ao canto do canto superior esquerdo da janela, não a área de cliente. O mesmo é verdadeiro para todas as funções arrastando a imagem que usam as coordenadas como parâmetros. Isso significa que você precisa compensar as larguras de elementos de janela, como a borda, a barra de título e a barra de menus, ao especificar as coordenadas. Se você especificar uma **nulo** identificador de janela ao chamar `DragEnter`, as funções de arrastar desenhar a imagem no contexto de dispositivo associado com a janela da área de trabalho e as coordenadas são relativas ao canto superior esquerdo da tela.

`DragEnter` bloqueia todas as outras atualizações para a janela de determinado durante a operação de arrastar. Se você precisar fazer qualquer drawing durante uma operação de arrastar, como realce o destino de uma operação de arrastar e soltar, você pode ocultar temporariamente a imagem arrastada usando o [DragLeave](../mfc/reference/cimagelist-class.md#dragleave) função de membro. Você também pode usar o [DragShowNoLock](../mfc/reference/cimagelist-class.md#dragshownolock) função de membro.

Chame [EndDrag](../mfc/reference/cimagelist-class.md#enddrag) quando você terminar arrastando a imagem.

O [SetDragCursorImage](../mfc/reference/cimagelist-class.md#setdragcursorimage) função de membro cria uma nova imagem de arrastar, combinando a determinada imagem (normalmente uma imagem do cursor do mouse) com a imagem atual de arrastar. Como as funções de arrastar usam a nova imagem durante uma operação de arrastar, você deve usar o Windows [ShowCursor](/windows/desktop/api/winuser/nf-winuser-showcursor) função para ocultar o cursor do mouse real depois de chamar `SetDragCursorImage`. Caso contrário, o sistema pode parecer ter dois cursores de mouse para a duração da operação de arrastar.

Quando um aplicativo chama `BeginDrag`, o sistema cria uma lista de imagens interno, temporário e cópias especificadas arrastar a imagem à lista interna. Você pode recuperar um ponteiro para a lista de imagens de arrastar temporário usando o [GetDragImage](../mfc/reference/cimagelist-class.md#getdragimage) função de membro. A função também recupera a posição atual de arrastar e o deslocamento da imagem de arrastar em relação à posição de arrastar.

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
