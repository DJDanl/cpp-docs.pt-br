---
title: Arrastando imagens a partir de uma lista de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CImageList class [MFC], dragging images from
- dragging images from image lists [MFC]
- image lists [MFC], dragging images from
- images [MFC], dragging from image lists
ms.assetid: af691db8-e4f0-4046-b7b9-9acc68d3713d
ms.openlocfilehash: 3035e6f21d38568b364fce02358c3baed4870bc3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508642"
---
# <a name="dragging-images-from-an-image-list"></a>Arrastando imagens a partir de uma lista de imagens

[CImageList](../mfc/reference/cimagelist-class.md) inclui funções para arrastar uma imagem na tela. As funções de arrastar movem uma imagem suavemente, em cores e sem qualquer piscar do cursor. Imagens mascaradas e não mascaradas podem ser arrastadas.

A função membro [BeginDrag](../mfc/reference/cimagelist-class.md#begindrag) inicia uma operação de arrastar. Os parâmetros incluem o índice da imagem a arrastar e o local do ponto de acesso dentro da imagem. O ponto de acesso é um único pixel que as funções de arrastar reconhecem como o local exato da tela da imagem. Normalmente, um aplicativo define o ponto de acesso para que coincida com o ponto de acesso do cursor do mouse. A função membro [DragMove](../mfc/reference/cimagelist-class.md#dragmove) move a imagem para um novo local.

A função membro [DragEnter](../mfc/reference/cimagelist-class.md#dragenter) define a posição inicial da imagem de arrastar dentro de uma janela e desenha a imagem na posição. Os parâmetros incluem um ponteiro para a janela na qual desenhar a imagem e um ponto que especifica as coordenadas da posição inicial dentro da janela. As coordenadas são relativas ao canto superior esquerdo da janela, não à área do cliente. O mesmo é verdadeiro para todas as funções de arrastar imagem que usam coordenadas como parâmetros. Isso significa que você deve compensar as larguras dos elementos da janela, como a borda, a barra de título e a barra de menus, ao especificar as coordenadas. Se você especificar um identificador de janela **nulo** ao `DragEnter`chamar, as funções de arrastar desenharão a imagem no contexto do dispositivo associado à janela da área de trabalho e as coordenadas serão relativas ao canto superior esquerdo da tela.

`DragEnter`bloqueia todas as outras atualizações na janela especificada durante a operação de arrastar. Se você precisar fazer qualquer desenho durante uma operação de arrastar, como realçar o destino de uma operação de arrastar e soltar, você poderá ocultar temporariamente a imagem arrastada usando a função de membro [DragLeave](../mfc/reference/cimagelist-class.md#dragleave) . Você também pode usar a função de membro [DragShowNoLock](../mfc/reference/cimagelist-class.md#dragshownolock) .

Chame [endarraste](../mfc/reference/cimagelist-class.md#enddrag) quando terminar de arrastar a imagem.

A função membro [SetDragCursorImage](../mfc/reference/cimagelist-class.md#setdragcursorimage) cria uma nova imagem de arrastar combinando a imagem determinada (normalmente uma imagem de cursor do mouse) com a imagem de arrastar atual. Como as funções de arrastar usam a nova imagem durante uma operação de arrastar, você deve usar a função do [cursor](/windows/win32/api/winuser/nf-winuser-showcursor) do Windows para ocultar o cursor real `SetDragCursorImage`do mouse após a chamada. Caso contrário, o sistema pode parecer ter dois cursores de mouse para a duração da operação de arrastar.

Quando um aplicativo chama `BeginDrag`, o sistema cria uma lista de imagens temporária e interna e copia a imagem de arrastar especificada para a lista interna. Você pode recuperar um ponteiro para a lista temporária de imagens de arrastar usando a função de membro [GetDragImage](../mfc/reference/cimagelist-class.md#getdragimage) . A função também recupera a posição de arrastar atual e o deslocamento da imagem de arrastar em relação à posição de arrastar.

## <a name="see-also"></a>Consulte também

[Usando CImageList](../mfc/using-cimagelist.md)<br/>
[Controles](../mfc/controls-mfc.md)
