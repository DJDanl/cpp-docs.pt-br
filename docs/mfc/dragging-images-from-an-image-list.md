---
title: Arrastando imagens a partir de uma lista de imagens | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CImageList class [MFC], dragging images from
- dragging images from image lists [MFC]
- image lists [MFC], dragging images from
- images [MFC], dragging from image lists
ms.assetid: af691db8-e4f0-4046-b7b9-9acc68d3713d
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 792f112952493fe1ee86d52a6a235604ebee9db5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dragging-images-from-an-image-list"></a>Arrastando imagens a partir de uma lista de imagens
[CImageList](../mfc/reference/cimagelist-class.md) inclui funções para arrastar uma imagem na tela. As funções de arrastar mover uma imagem sem problemas, cor e sem qualquer piscando do cursor. Podem ser arrastadas imagens mascaradas e não mascaradas.  
  
 O [BeginDrag](../mfc/reference/cimagelist-class.md#begindrag) função membro começa uma operação de arrastar. Os parâmetros incluem o índice da imagem para arrastar e o local do ponto de acesso na imagem. O ponto de acesso é um único pixel que as funções de arrastar reconhecerem como o local exato de tela da imagem. Normalmente, um aplicativo define o ponto de acesso para que coincide com o ponto de acesso do cursor do mouse. O [DragMove](../mfc/reference/cimagelist-class.md#dragmove) função membro Move a imagem para um novo local.  
  
 O [DragEnter](../mfc/reference/cimagelist-class.md#dragenter) define a posição inicial da imagem arraste dentro de uma janela de função de membro e desenha a imagem na posição. Os parâmetros incluem um ponteiro para a janela na qual desenhar a imagem e um ponto que especifica as coordenadas da posição inicial dentro da janela. As coordenadas são em relação ao canto de superior esquerdo da janela, não a área do cliente. O mesmo é verdadeiro para todas as funções arrastando a imagem que levam as coordenadas como parâmetros. Isso significa que você precisa compensar as larguras de elementos de janela, como a borda, a barra de título e a barra de menus, ao especificar as coordenadas. Se você especificar um **nulo** identificador de janela ao chamar `DragEnter`, as funções de arrastar desenhar a imagem no contexto de dispositivo associado à janela de área de trabalho e as coordenadas são em relação ao canto superior esquerdo da tela.  
  
 `DragEnter`bloqueia todas as outras atualizações para a janela determinada durante a operação de arrastar. Se você precisar fazer qualquer desenho durante uma operação de arrastar, como realce o destino de uma operação de arrastar e soltar, você pode ocultar temporariamente a imagem arrastada usando o [DragLeave](../mfc/reference/cimagelist-class.md#dragleave) função de membro. Você também pode usar o [DragShowNoLock](../mfc/reference/cimagelist-class.md#dragshownolock) função de membro.  
  
 Chamar [EndDrag](../mfc/reference/cimagelist-class.md#enddrag) quando você terminar arrastando a imagem.  
  
 O [SetDragCursorImage](../mfc/reference/cimagelist-class.md#setdragcursorimage) função membro cria uma nova imagem de arrastar, combinando a determinada imagem (normalmente uma imagem do cursor do mouse) com a imagem de arrastar atual. Como as funções de arrastar usam a nova imagem durante uma operação de arrastar, você deve usar o Windows [ShowCursor](http://msdn.microsoft.com/library/windows/desktop/ms648396) função para ocultar o cursor do mouse real depois de chamar `SetDragCursorImage`. Caso contrário, o sistema pode parecer ter dois cursores do mouse para a duração da operação de arrastar.  
  
 Quando um aplicativo chama `BeginDrag`, o sistema cria uma lista de imagem temporário, interno e cópias especificadas arraste a imagem para a lista interna. Você pode recuperar um ponteiro para a lista de imagens de arrastar temporário usando o [GetDragImage](../mfc/reference/cimagelist-class.md#getdragimage) função de membro. A função também recupera a posição atual de arrastar e o deslocamento da imagem de arrastar em relação à posição de arrastar.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)

