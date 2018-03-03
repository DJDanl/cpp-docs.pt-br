---
title: "Mensagens de notificação de controle de árvore | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- notifications [MFC], tree controls
- messages [MFC], notification
- CTreeCtrl class [MFC], notifications
- notifications [MFC], CTreeCtrl
- tree controls [MFC], notification messages
ms.assetid: ac7013b4-91dd-4668-bd75-439ca0680ef9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e5044416ca38f6b3ead743c571ea7175022d51fe
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tree-control-notification-messages"></a>Mensagens de notificação do controle de árvore
Um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia mensagens de notificação como **WM_NOTIFY** mensagens:  
  
|Mensagem de notificação|Descrição|  
|--------------------------|-----------------|  
|**TVN_BEGINDRAG**|Indica o início de uma operação de arrastar e soltar|  
|**TVN_BEGINLABELEDIT**|Sinaliza o início da edição do rótulo no local|  
|**TVN_BEGINRDRAG**|Indica o início de uma operação de arrastar e soltar com o botão direito do mouse|  
|**TVN_DELETEITEM**|Sinaliza a exclusão de um item específico|  
|**TVN_ENDLABELEDIT**|Sinaliza o término de edição do rótulo|  
|**TVN_GETDISPINFO**|Informações de solicitações que requer que o controle de árvore para exibir um item|  
|**TVN_ITEMEXPANDED**|Sinaliza que a lista de um item pai de itens filho foi expandida ou recolhida|  
|**TVN_ITEMEXPANDING**|Sinais de que a lista de um item pai de itens filho está prestes a ser expandido ou recolhido|  
|**TVN_KEYDOWN**|Indica um evento de teclado|  
|**TVN_SELCHANGED**|Indica que a seleção foi alterada de um item para outro|  
|**TVN_SELCHANGING**|Sinais de que a seleção está prestes a ser alterada de um item para outro|  
|**TVN_SETDISPINFO**|Notificação para atualizar as informações mantidas para um item|  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

