---
title: Mensagens de notificação de controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- notifications [MFC], tree controls
- messages [MFC], notification
- CTreeCtrl class [MFC], notifications
- notifications [MFC], CTreeCtrl
- tree controls [MFC], notification messages
ms.assetid: ac7013b4-91dd-4668-bd75-439ca0680ef9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 92035d3f1a20a0fd9cc0c7b95d7238ef014033da
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36950961"
---
# <a name="tree-control-notification-messages"></a>Mensagens de notificação do controle de árvore
Um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia as mensagens de notificação a seguir como mensagens WM_NOTIFY:  
  
|Mensagem de notificação|Descrição|  
|--------------------------|-----------------|  
|TVN_BEGINDRAG|Indica o início de uma operação de arrastar e soltar|  
|TVN_BEGINLABELEDIT|Sinaliza o início da edição do rótulo no local|  
|TVN_BEGINRDRAG|Indica o início de uma operação de arrastar e soltar com o botão direito do mouse|  
|TVN_DELETEITEM|Sinaliza a exclusão de um item específico|  
|TVN_ENDLABELEDIT|Sinaliza o término de edição do rótulo|  
|TVN_GETDISPINFO|Informações de solicitações que requer que o controle de árvore para exibir um item|  
|TVN_ITEMEXPANDED|Sinaliza que a lista de um item pai de itens filho foi expandida ou recolhida|  
|TVN_ITEMEXPANDING|Sinais de que a lista de um item pai de itens filho está prestes a ser expandido ou recolhido|  
|TVN_KEYDOWN|Indica um evento de teclado|  
|TVN_SELCHANGED|Indica que a seleção foi alterada de um item para outro|  
|TVN_SELCHANGING|Sinais de que a seleção está prestes a ser alterada de um item para outro|  
|TVN_SETDISPINFO|Notificação para atualizar as informações mantidas para um item|  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

