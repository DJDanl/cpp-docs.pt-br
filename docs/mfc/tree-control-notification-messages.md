---
title: "Mensagens de notifica&#231;&#227;o do controle de &#225;rvore | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Classe CTreeCtrl, notificações"
  - "mensagens,  (notificação)"
  - "notificações, CTreeCtrl"
  - "notificações, controles em árvore"
  - "controles em árvore, mensagens de notificação"
ms.assetid: ac7013b4-91dd-4668-bd75-439ca0680ef9
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mensagens de notifica&#231;&#227;o do controle de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle de árvore \([CTreeCtrl](../mfc/reference/ctreectrl-class.md)\) envia notificações como as seguintes mensagens de **WM\_NOTIFY** :  
  
|Notificação|Descrição|  
|-----------------|---------------|  
|**TVN\_BEGINDRAG**|Sinaliza o início de uma operação de arrastar e soltar|  
|**TVN\_BEGINLABELEDIT**|Sinaliza o início da edição in\-loco de rótulo|  
|**TVN\_BEGINRDRAG**|Sinaliza o início de uma operação de arrastar e soltar, usando o botão direito do mouse em|  
|**TVN\_DELETEITEM**|Sinaliza a exclusão de um item específico|  
|**TVN\_ENDLABELEDIT**|Sinaliza o término da edição de rótulo|  
|**TVN\_GETDISPINFO**|Solicita informações que o controle de árvore para exibir um item requer|  
|**TVN\_ITEMEXPANDED**|Sinais que a lista pai de um item de itens filho foi expandida ou recolhida|  
|**TVN\_ITEMEXPANDING**|Sinais que a lista pai de um item de itens filho está prestes a ser expandida ou recolhido|  
|**TVN\_KEYDOWN**|Sinaliza um evento de teclado|  
|**TVN\_SELCHANGED**|Sinais que a seleção alterado de um item para outro|  
|**TVN\_SELCHANGING**|Sinais que a seleção está prestes a ser alterada de um item para outro|  
|**TVN\_SETDISPINFO**|Notificação para atualizar informações mantidas para um item|  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)