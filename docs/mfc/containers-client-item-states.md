---
title: "Contêineres: Estados de Item do cliente | Microsoft Docs"
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
- OLE containers [MFC], client-item states
- states, OLE container client-item
- lifetime, lifetime states and OLE container client items
- client items and OLE containers
ms.assetid: e7021caa-bd07-4adb-976e-f5f3d025bc53
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6bcc43d4e8b32a8766eef7c50e45bece569ef5c3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="containers-client-item-states"></a>Contêineres: estados de item do cliente
Este artigo explica os diferentes estados em que um item do cliente passa em seu tempo de vida.  
  
 Um item do cliente passa por vários estados, conforme ele é criado, ativado, modificado e salvo. Cada vez que as alterações de estado do item, o framework chama [COleClientItem::OnChange](../mfc/reference/coleclientitem-class.md#onchange) com o `OLE_CHANGED_STATE` notificação. O segundo parâmetro é um valor da **COleClientItem::ItemState** enumeração. Pode ser um dos seguintes:  
  
-   **COleClientItem::emptyState**  
  
-   **COleClientItem::loadedState**  
  
-   **COleClientItem::openState**  
  
-   **COleClientItem::activeState**  
  
-   **COleClientItem::activeUIState**  
  
 No estado vazio, um item do cliente ainda não está completamente um item. Memória foi alocada para ele, mas ainda não foi inicializado com dados do item OLE. Este é o estado de um item do cliente está em quando ela foi criada por uma chamada a **novo** , mas ainda não tiver sofrido a segunda etapa da criação de duas etapas típicas.  
  
 Na segunda etapa, realizada por meio de uma chamada para `COleClientItem::CreateFromFile` ou outro **CreateFrom***xxxx* função, o item é criado completamente. Os dados OLE (de um arquivo ou de outra fonte, como a área de transferência) foi associados a `COleClientItem`-objeto derivado. Agora o item está no estado carregado.  
  
 Quando um item foi aberto na janela do servidor mas não foi aberto no local de documento do contêiner, ele está no estado abrir (ou totalmente abrir). Nesse estado, uma cruz-hachura geralmente é desenhada sobre a representação do item na janela do contêiner para indicar que o item está ativo em outro lugar.  
  
 Quando um item tiver sido ativado no local, ele passa, normalmente apenas brevemente, por meio do estado ativo. Em seguida, entra no estado de ativo da interface do usuário, no qual o servidor foi mesclado seus menus, barras de ferramentas e outros componentes de interface do usuário com aqueles do contêiner. A presença desses componentes de interface do usuário distingue o estado ativo da interface do usuário do estado ativo. Caso contrário, o estado ativo se parece com o estado ativo da interface do usuário. Se o servidor oferece suporte para desfazer, o servidor é necessário para manter informações de estado de desfazer do item OLE até atingir o estado aberto ou carregado.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Ativação](../mfc/activation-cpp.md)   
 [Contêineres: Notificações de Item do cliente](../mfc/containers-client-item-notifications.md)   
 [Controladores](../mfc/trackers.md)   
 [Classe CRectTracker](../mfc/reference/crecttracker-class.md)
