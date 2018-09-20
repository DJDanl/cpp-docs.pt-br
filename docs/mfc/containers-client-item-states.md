---
title: 'Contêineres: Estados de Item do cliente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE containers [MFC], client-item states
- states, OLE container client-item
- lifetime, lifetime states and OLE container client items
- client items and OLE containers
ms.assetid: e7021caa-bd07-4adb-976e-f5f3d025bc53
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e482123207c287c33a36406ba961747545af7c73
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378040"
---
# <a name="containers-client-item-states"></a>Contêineres: estados de item do cliente

Este artigo explica os diferentes estados em que um item do cliente passa seu tempo de vida.

Um item do cliente passa por vários estados, conforme ele é criado, ativado, modificado e salvo. Cada vez que as alterações de estado do item, a estrutura chama [COleClientItem::OnChange](../mfc/reference/coleclientitem-class.md#onchange) com o **OLE_CHANGED_STATE** notificação. O segundo parâmetro é um valor da `COleClientItem::ItemState` enumeração. Ele pode ser um dos seguintes:

- *COleClientItem::emptyState*

- *COleClientItem::loadedState*

- *COleClientItem::openState*

- *COleClientItem::activeState*

- *COleClientItem::activeUIState*

No estado vazio, um item do cliente ainda não está completamente um item. Memória foi alocada para ele, mas ainda não foi inicializado com os dados do item OLE. Este é o estado de um item do cliente está em quando ele tiver sido criado por meio de uma chamada para **novo** , mas ainda não foi submetido a segunda etapa da criação típico em duas etapas.

Na segunda etapa, executada por meio de uma chamada para `COleClientItem::CreateFromFile` ou outra `CreateFrom` *xxxx* função, o item é criado completamente. Os dados OLE (de um arquivo ou alguma outra origem, como a área de transferência) foi associados com o `COleClientItem`-objeto derivado. Agora o item está no estado carregado.

Quando um item foi aberto na janela do servidor mas não foi aberto no local de documento do contêiner, ele está no estado aberto (ou totalmente aberto). Nesse estado, uma hachura de cruzada geralmente é desenhada sobre a representação do item na janela do contêiner para indicar que o item está ativo em outro lugar.

Quando um item tiver sido ativado no lugar, ele passa, geralmente apenas resumidamente, por meio do estado ativo. Em seguida, ele insere o estado ativo da interface do usuário, em que o servidor foi mesclado seus menus, barras de ferramentas e outros componentes de interface do usuário com aqueles do contêiner. A presença desses componentes de interface do usuário distingue o estado ativo da interface do usuário do estado ativo. Caso contrário, o estado ativo se parece com o estado ativo da interface do usuário. Se o servidor oferecer suporte a desfazer, o servidor é necessário para manter informações de estado de desfazer do item OLE até atingir o estado aberto ou carregado.

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Ativação](../mfc/activation-cpp.md)<br/>
[Contêineres: notificações de item do cliente](../mfc/containers-client-item-notifications.md)<br/>
[Controladores](../mfc/trackers.md)<br/>
[Classe CRectTracker](../mfc/reference/crecttracker-class.md)
