---
title: "Fun&#231;&#227;o de membro OnIdle | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "OnIdle"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CWinApp, Método OnIdle"
  - "processamento de loop ocioso"
  - "lidando com erros, Método OnIdle"
  - "Método OnIdle"
  - "processando mensagens"
ms.assetid: 51adc874-0075-4f76-be1c-79283f46c10b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de membro OnIdle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando nenhuma mensagem do windows está sendo processada, a estrutura chama a função de membro [OnIdle](../Topic/CWinApp::OnIdle.md) de [CWinApp](../mfc/reference/cwinapp-class.md) \(descrito na referência da biblioteca MFC\).  
  
 Substituição `OnIdle` para executar tarefas em segundo plano.  A versão padrão atualiza o estado de objetos de interface do usuário como os botões da barra de ferramentas e executa a limpeza dos objetos temporários criados pela estrutura no decorrer de suas operações.  A figura a seguir ilustra como o loop de mensagem chama `OnIdle` quando não houver nenhuma mensagem na fila.  
  
 ![Processo de Loop de mensagem](../mfc/media/vc387c1.png "vc387C1")  
O loop de mensagem  
  
 Para obter mais informações sobre o que você pode fazer no loop ociosa, consulte [Processamento de loop ocioso](../Topic/Idle%20Loop%20Processing.md).  
  
## Consulte também  
 [CWinApp: a classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)