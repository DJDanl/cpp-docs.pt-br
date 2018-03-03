---
title: "Função de membro OnIdle | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- OnIdle
dev_langs:
- C++
helpviewer_keywords:
- processing messages [MFC]
- OnIdle method [MFC]
- idle loop processing [MFC]
- CWinApp class [MFC], OnIdle method [MFC]
- message handling [MFC], OnIdle method [MFC]
ms.assetid: 51adc874-0075-4f76-be1c-79283f46c10b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4dfbc0a1f20cb6cc01143ed6f07a63e84b53be6b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="onidle-member-function"></a>Função de membro OnIdle
Quando não há mensagens do Windows estão sendo processadas, o framework chama o [CWinApp](../mfc/reference/cwinapp-class.md) função de membro [OnIdle](../mfc/reference/cwinapp-class.md#onidle) (descrito na referência de biblioteca do MFC).  
  
 Substituir `OnIdle` para executar tarefas em segundo plano. A versão padrão atualiza o estado dos objetos de interface do usuário, como botões da barra de ferramentas e executa a limpeza de objetos temporários criados pela estrutura no decorrer de suas operações. A figura a seguir ilustra como o loop de mensagem chama `OnIdle` quando não existem mensagens na fila.  
  
 ![Processo de loop de mensagem](../mfc/media/vc387c1.gif "vc387c1")  
O Loop de mensagens  
  
 Para obter mais informações sobre o que você pode fazer no loop ocioso, consulte [processamento de Loop ocioso](../mfc/idle-loop-processing.md).  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
