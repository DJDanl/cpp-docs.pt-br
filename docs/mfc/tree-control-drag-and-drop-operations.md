---
title: "Opera&#231;&#245;es de arrastar e soltar de controle de &#225;rvore | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTreeCtrl, operações arrastar e soltar"
  - "arrastar e soltar, CTreeCtrl"
  - "controles em árvore, operações arrastar e soltar"
ms.assetid: 3cf78b4c-4579-4fe1-9bc9-c5ab876e4af1
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Opera&#231;&#245;es de arrastar e soltar de controle de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle de árvore[CTreeCtrl](../mfc/reference/ctreectrl-class.md)\(\) para enviar uma notificação quando o usuário para arraste um item.  O controle envia uma notificação de [TVN\_BEGINDRAG](http://msdn.microsoft.com/library/windows/desktop/bb773504) quando o usuário inicia a arraste um item com o botão esquerdo do mouse e uma notificação de [TVN\_BEGINRDRAG](http://msdn.microsoft.com/library/windows/desktop/bb773509) quando o usuário inicia a arraste com o botão direito.  Você pode impedir que um controle de árvore envie essas mensagens de notificação do controle de árvore o estilo de **TVS\_DISABLEDRAGDROP** .  
  
 Você obtém uma imagem a ser exibida durante uma operação de arrastar chamando a função de membro de [CreateDragImage](../Topic/CTreeCtrl::CreateDragImage.md) .  O controle de árvore cria um bitmap arrastando baseado no rótulo do item que está sendo arrastado.  O controle de árvore cria uma lista de imagem, adiciona o bitmap, e o retorna um ponteiro para o objeto de [CImageList](../Topic/CImageList%20Class.md) .  
  
 Você deve fornecer o código que realmente arrasta o item.  Isso envolve normalmente utilizar os recursos arrastando da lista de funções de imagem e processar mensagens de [WM\_MOUSEMOVE](http://msdn.microsoft.com/library/windows/desktop/ms645616) e de [WM\_LBUTTONUP](http://msdn.microsoft.com/library/windows/desktop/ms645608) \(ou\) [WM\_RBUTTONUP](http://msdn.microsoft.com/library/windows/desktop/ms646243)enviadas depois que a operação de arrastar foi iniciado.  Para obter mais informações sobre as funções da lista de imagem, consulte [CImageList](../Topic/CImageList%20Class.md)*na referência de MFC* e [Listas de imagem](http://msdn.microsoft.com/library/windows/desktop/bb761389) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  Para obter mais informações sobre como arrastar uma árvore controle o item, consulte [Arrastando o item de exibição de árvore](http://msdn.microsoft.com/library/windows/desktop/bb760017), também em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
 Se os itens no controle de árvore são ser os destinos de uma operação de arrastar e soltar, você precisa saber quando o cursor do mouse em um item de destino.  Você pode localizar chamando a função de membro de [HitTest](../Topic/CTreeCtrl::HitTest.md) .  Você especifica um ponto e o inteiro, ou o endereço de uma estrutura de [TVHITTESTINFO](http://msdn.microsoft.com/library/windows/desktop/bb773448) que contém as coordenadas atuais de cursor do mouse em.  Quando a função retorna o inteiro, ou a estrutura contém um sinalizador que indica o local do cursor do mouse em relação ao controle de árvore.  Se o cursor estiver em um item no controle de árvore, a estrutura contém o identificador do item também.  
  
 Você pode indicar que um item é o destino de uma operação de arrastar e soltar chamando a função de membro de [SetItem](../Topic/CTreeCtrl::SetItem.md) para definir o estado como o valor de `TVIS_DROPHILITED` .  Um item que tenha esse estado é desenhado em estilo usado para indicar um destino de arrastar e soltar.  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)