---
title: "Cont&#234;ineres: estados de item do cliente | Microsoft Docs"
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
  - "itens de cliente e contêineres OLE"
  - "tempo de vida, estados de tempo de vida e itens do cliente de contêiner OLE"
  - "Contêineres OLE, estados de item do cliente"
  - "estados, item do cliente de contêiner OLE"
ms.assetid: e7021caa-bd07-4adb-976e-f5f3d025bc53
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres: estados de item do cliente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica os diferentes estados que um item de cliente passa através de seu tempo de vida.  
  
 Um item de cliente passa por meio de vários estados a é criado, alterado ativado, e salvo.  Cada vez que as alterações de estado do item, a estrutura chamam [COleClientItem::OnChange](../Topic/COleClientItem::OnChange.md) à notificação de `OLE_CHANGED_STATE` .  O segundo parâmetro é um valor de enumeração de **COleClientItem::ItemState** .  Pode ser um dos seguintes:  
  
-   **COleClientItem::emptyState**  
  
-   **COleClientItem::loadedState**  
  
-   **COleClientItem::openState**  
  
-   **COleClientItem::activeState**  
  
-   **COleClientItem::activeUIState**  
  
 No estado vazia, um item do cliente não ainda é completamente um item.  A memória foi alocada para ela, mas ainda não foi inicializada com os dados do do item.  Este é o estado que um item de cliente está em quando foi criado com uma chamada a **new** mas não se submeteu na segunda etapa da criação normal de duas etapas.  
  
 Na segunda etapa, executada por uma chamada a `COleClientItem::CreateFromFile` ou a outra função de **CreateFrom***xxxx* , o item é criado completamente.  Os dados do \(de um arquivo ou de alguma outra origem, como a área de transferência\) foram associados a `COleClientItem`\- objeto derivada.  Agora o item está no estado carregado.  
  
 Quando um item foi aberto na janela do servidor em vez de aberto no lugar no documento de contêiner, é \(ou abrir completamente\) no estado aberto.  Nesse estado, uma crosshatch é desenhada em geral sobre a representação do item na janela do contêiner para indicar que o item está ativa em outro lugar.  
  
 Quando um item foi ativado no lugar, passa, normalmente apenas brevemente, por meio do estado ativo.  Insira o estado ativo da interface do usuário, em que o servidor se mesclou os menus, barras de ferramentas, e outros componentes de interface do usuário com as do contêiner.  A presença desses componentes de interface do usuário faz distinção o estado ativo da interface do usuário do estado ativo.  Caso contrário, o estado ativo se assemelha ao estado ativo da interface do usuário.  Se o servidor oferecer suporte desfazer, o servidor será necessário reter informações OLE desfazer\- estado do item até alcançar carregado ou abrir o estado.  
  
## Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Ativação](../mfc/activation-cpp.md)   
 [Contêineres: notificações de item do cliente](../mfc/containers-client-item-notifications.md)   
 [Controladores](../mfc/trackers.md)   
 [Classe de CRectTracker](../mfc/reference/crecttracker-class.md)