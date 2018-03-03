---
title: "Processando notificações de controle de cabeçalho | Microsoft Docs"
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
- CHeaderCtrl class [MFC], processing notifications
- controls [MFC], header
- notifications [MFC], processing for CHeaderCtrl
- header controls [MFC], processing notifications
- header control notifications
ms.assetid: e6c6af7c-d458-4d33-85aa-48014ccde5f6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a442e6aadf7c91918cd523c29330e79c753b115c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="processing-header-control-notifications"></a>Processando notificações de controle do cabeçalho
Em sua classe de exibição ou a caixa de diálogo, use a janela Propriedades para criar um [OnChildNotify](../mfc/reference/cwnd-class.md#onchildnotify) função de manipulador com uma instrução switch para qualquer controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) mensagens de notificação que você deseja tratar (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)). As notificações são enviadas para a janela pai quando o usuário clica ou clica duas vezes em um item de cabeçalho, arrasta a divisória entre itens e assim por diante.  
  
 As mensagens de notificação associadas a um controle de cabeçalho são listadas em [referência de controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775239) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

