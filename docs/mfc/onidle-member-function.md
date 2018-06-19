---
title: Função de membro OnIdle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bbe912db448e424f18b6d72f6e148312c5940687
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33350361"
---
# <a name="onidle-member-function"></a>Função de membro OnIdle
Quando não há mensagens do Windows estão sendo processadas, o framework chama o [CWinApp](../mfc/reference/cwinapp-class.md) função de membro [OnIdle](../mfc/reference/cwinapp-class.md#onidle) (descrito na referência de biblioteca do MFC).  
  
 Substituir `OnIdle` para executar tarefas em segundo plano. A versão padrão atualiza o estado dos objetos de interface do usuário, como botões da barra de ferramentas e executa a limpeza de objetos temporários criados pela estrutura no decorrer de suas operações. A figura a seguir ilustra como o loop de mensagem chama `OnIdle` quando não existem mensagens na fila.  
  
 ![Processo de loop de mensagem](../mfc/media/vc387c1.gif "vc387c1")  
O Loop de mensagens  
  
 Para obter mais informações sobre o que você pode fazer no loop ocioso, consulte [processamento de Loop ocioso](../mfc/idle-loop-processing.md).  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
