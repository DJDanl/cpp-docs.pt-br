---
title: Operações de arrastar e soltar de controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CTreeCtrl class [MFC], drag and drop operations
- drag and drop [MFC], CTreeCtrl
- tree controls [MFC], drag and drop operations
ms.assetid: 3cf78b4c-4579-4fe1-9bc9-c5ab876e4af1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a620c2481b29b80f6d30dd6457716a652f51fd85
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tree-control-drag-and-drop-operations"></a>Operações de arrastar e soltar de controle de árvore
Um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia uma notificação quando o usuário começa a arrastar um item. O controle envia um [TVN_BEGINDRAG](http://msdn.microsoft.com/library/windows/desktop/bb773504) mensagem de notificação quando o usuário começa a arrastar um item com o botão esquerdo do mouse e um [TVN_BEGINRDRAG](http://msdn.microsoft.com/library/windows/desktop/bb773509) mensagem de notificação quando o usuário começa a arrastar com o botão direito. Você pode impedir que um controle de árvore envie essas notificações, fornecendo o controle de árvore de **TVS_DISABLEDRAGDROP** estilo.  
  
 Obtenha uma imagem a ser exibida durante uma operação de arrastar chamando o [CreateDragImage](../mfc/reference/ctreectrl-class.md#createdragimage) função de membro. O controle de árvore cria um bitmap de arrastar com base no rótulo do item que está sendo arrastado. Em seguida, cria uma lista de imagens, adiciona o bitmap a ele e retorna um ponteiro para o controle de árvore de [CImageList](../mfc/reference/cimagelist-class.md) objeto.  
  
 Você deve fornecer o código que realmente arrasta o item. Isso normalmente envolve usando os recursos de arrastar as funções de lista de imagem e processamento de [WM_MOUSEMOVE](http://msdn.microsoft.com/library/windows/desktop/ms645616) e [WM_LBUTTONUP](http://msdn.microsoft.com/library/windows/desktop/ms645608) (ou [WM_RBUTTONUP](http://msdn.microsoft.com/library/windows/desktop/ms646243)) mensagens enviadas depois que a operação de arrastar foi iniciado. Para obter mais informações sobre as funções de lista de imagens, consulte [CImageList](../mfc/reference/cimagelist-class.md) no *referência MFC* e [listas de imagens](http://msdn.microsoft.com/library/windows/desktop/bb761389) no SDK do Windows. Para obter mais informações sobre como arrastar um item de controle de árvore, consulte [arrastar o Item de exibição de árvore](http://msdn.microsoft.com/library/windows/desktop/bb760017), também no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
 Se itens em um controle de árvore devem ser o destino de uma operação de arrastar e soltar, você precisa saber quando o cursor do mouse em um item de destino. Você pode descobrir chamando o [HitTest](../mfc/reference/ctreectrl-class.md#hittest) função de membro. Especifique um ponto e inteiro ou o endereço de um [TVHITTESTINFO](http://msdn.microsoft.com/library/windows/desktop/bb773448) estrutura que contém as coordenadas atuais do cursor do mouse. Quando a função retornar, o número inteiro ou a estrutura contém um sinalizador que indica o local do cursor do mouse em relação ao controle de árvore. Se o cursor estiver em um item no controle de árvore, a estrutura contém o identificador do item também.  
  
 Você pode indicar que um item é o destino de uma operação de arrastar e soltar chamando o [SetItem](../mfc/reference/ctreectrl-class.md#setitem) a função de membro para definir o estado para o `TVIS_DROPHILITED` valor. Um item com esse estado é desenhado no estilo usado para indicar um destino de arrastar e soltar.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

