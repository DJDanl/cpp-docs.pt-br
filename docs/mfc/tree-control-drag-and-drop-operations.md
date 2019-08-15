---
title: Operações de arrastar e soltar de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- CTreeCtrl class [MFC], drag and drop operations
- drag and drop [MFC], CTreeCtrl
- tree controls [MFC], drag and drop operations
ms.assetid: 3cf78b4c-4579-4fe1-9bc9-c5ab876e4af1
ms.openlocfilehash: 5d2c5aa511844a3d7cbe64d9a15f8ffb46046b29
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510912"
---
# <a name="tree-control-drag-and-drop-operations"></a>Operações de arrastar e soltar de controle de árvore

Um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia uma notificação quando o usuário começa a arrastar um item. O controle envia uma mensagem de notificação [TVN_BEGINDRAG](/windows/win32/Controls/tvn-begindrag) quando o usuário começa a arrastar um item com o botão esquerdo do mouse e uma mensagem de notificação [TVN_BEGINRDRAG](/windows/win32/Controls/tvn-beginrdrag) quando o usuário começa a arrastar com o botão à direita. Você pode impedir que um controle de árvore envie essas notificações, dando ao controle de árvore o estilo TVS_DISABLEDRAGDROP.

Você Obtém uma imagem a ser exibida durante uma operação de arrastar chamando a função membro [CreateDragImage](../mfc/reference/ctreectrl-class.md#createdragimage) . O controle de árvore cria um bitmap de arrastar com base no rótulo do item que está sendo arrastado. Em seguida, o controle de árvore cria uma lista de imagens, adiciona o bitmap a ela e retorna um ponteiro para o objeto [CImageList](../mfc/reference/cimagelist-class.md) .

Você deve fornecer o código que realmente arrasta o item. Isso normalmente envolve o uso dos recursos de arrastar das funções da lista de imagens e o processamento das mensagens [WM_MOUSEMOVE](/windows/win32/inputdev/wm-mousemove) e [WM_LBUTTONUP](/windows/win32/inputdev/wm-lbuttonup) (ou [WM_RBUTTONUP](/windows/win32/inputdev/wm-rbuttonup)) enviadas após o início da operação de arrastar. Para obter mais informações sobre as funções da lista de imagens, consulte [CImageList](../mfc/reference/cimagelist-class.md) nas listas de referência e [imagem](/windows/win32/controls/image-lists) do *MFC* no SDK do Windows. Para obter mais informações sobre como arrastar um item de controle de árvore, consulte [arrastando o item de exibição de árvore](/windows/win32/Controls/tree-view-controls), também na SDK do Windows.

Se os itens em um controle de árvore forem os destinos de uma operação de arrastar e soltar, você precisará saber quando o cursor do mouse está em um item de destino. Você pode descobrir chamando a função de membro [HitTest](../mfc/reference/ctreectrl-class.md#hittest) . Você especifica um ponto e um inteiro ou o endereço de uma estrutura [TVHITTESTINFO](/windows/win32/api/commctrl/ns-commctrl-tvhittestinfo) que contém as coordenadas atuais do cursor do mouse. Quando a função retorna, o inteiro ou a estrutura contém um sinalizador que indica o local do cursor do mouse relativo ao controle de árvore. Se o cursor estiver sobre um item no controle de árvore, a estrutura também conterá o identificador do item.

Você pode indicar que um item é o destino de uma operação de arrastar e soltar chamando a função de membro [SetItem](../mfc/reference/ctreectrl-class.md#setitem) para definir o estado como o `TVIS_DROPHILITED` valor. Um item que tem esse estado é desenhado no estilo usado para indicar um destino de arrastar e soltar.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
