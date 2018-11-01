---
title: Operações de arrastar e soltar de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- CTreeCtrl class [MFC], drag and drop operations
- drag and drop [MFC], CTreeCtrl
- tree controls [MFC], drag and drop operations
ms.assetid: 3cf78b4c-4579-4fe1-9bc9-c5ab876e4af1
ms.openlocfilehash: 5dc498008c6b019635cd361a950c6d2926e26541
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519360"
---
# <a name="tree-control-drag-and-drop-operations"></a>Operações de arrastar e soltar de controle de árvore

Um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia uma notificação quando o usuário começa a arrastar um item. O controle envia uma [TVN_BEGINDRAG](/windows/desktop/Controls/tvn-begindrag) mensagem de notificação quando o usuário começa a arrastar um item com o botão esquerdo do mouse e um [TVN_BEGINRDRAG](/windows/desktop/Controls/tvn-beginrdrag) mensagem de notificação quando o usuário começa a arrastar com o botão direito. Você pode impedir que um controle de árvore envie essas notificações, fornecendo o estilo TVS_DISABLEDRAGDROP de controle de árvore.

Obter uma imagem para exibir durante uma operação de arrastar, chamando o [CreateDragImage](../mfc/reference/ctreectrl-class.md#createdragimage) função de membro. O controle de árvore cria um bitmap de arrastar com base no rótulo do item que está sendo arrastado. Em seguida, o controle de árvore cria uma lista de imagens, adiciona o bitmap a ele e retorna um ponteiro para o [CImageList](../mfc/reference/cimagelist-class.md) objeto.

Você deve fornecer o código que realmente arrasta o item. Isso normalmente envolve usando os recursos de arrastar as funções da lista de imagem e processamento de [WM_MOUSEMOVE](/windows/desktop/inputdev/wm-mousemove) e [WM_LBUTTONUP](/windows/desktop/inputdev/wm-lbuttonup) (ou [WM_RBUTTONUP](/windows/desktop/inputdev/wm-rbuttonup)) mensagens enviadas depois de iniciada a operação de arrastar. Para obter mais informações sobre as funções da lista de imagens, consulte [CImageList](../mfc/reference/cimagelist-class.md) na *referência da MFC* e [imagem lista](https://msdn.microsoft.com/library/windows/desktop/bb761389) no SDK do Windows. Para obter mais informações sobre como arrastar um item de controle de árvore, consulte [arrastar o Item de exibição de árvore](/windows/desktop/Controls/tree-view-controls), também no SDK do Windows.

Se for ser os destinos de uma operação de arrastar e soltar itens em um controle de árvore, você precisa saber quando o cursor do mouse está sobre um item de destino. Você pode descobrir por meio da chamada a [HitTest](../mfc/reference/ctreectrl-class.md#hittest) função de membro. Especifique um ponto e inteiro ou o endereço de uma [TVHITTESTINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtvhittestinfo) estrutura que contém as coordenadas atuais do cursor do mouse. Quando a função retornar, o número inteiro ou a estrutura contém um sinalizador que indica o local do cursor do mouse em relação ao controle de árvore. Se o cursor estiver sobre um item no controle de árvore, a estrutura contém o identificador do item também.

Você pode indicar que um item é o destino de uma operação de arrastar e soltar chamando o [SetItem](../mfc/reference/ctreectrl-class.md#setitem) função de membro para definir o estado o `TVIS_DROPHILITED` valor. Um item que tem esse estado é desenhado no estilo usado para indicar um destino de arrastar e soltar.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

