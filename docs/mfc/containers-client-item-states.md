---
title: 'Contêineres: estados de item do cliente'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE containers [MFC], client-item states
- states, OLE container client-item
- lifetime, lifetime states and OLE container client items
- client items and OLE containers
ms.assetid: e7021caa-bd07-4adb-976e-f5f3d025bc53
ms.openlocfilehash: 660b544a0f061ae2e4435777cdd934367f2e7652
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228642"
---
# <a name="containers-client-item-states"></a>Contêineres: estados de item do cliente

Este artigo explica os diferentes Estados que um item de cliente passa durante seu tempo de vida.

Um item de cliente passa por vários Estados conforme ele é criado, ativado, modificado e salvo. Sempre que o estado do item é alterado, a estrutura chama [COleClientItem:: OnChange](reference/coleclientitem-class.md#onchange) com a notificação **OLE_CHANGED_STATE** . O segundo parâmetro é um valor da `COleClientItem::ItemState` enumeração. Pode ser um dos seguintes:

- *COleClientItem:: emptyState*

- *COleClientItem:: loadedState*

- *COleClientItem:: openState*

- *COleClientItem:: activeState*

- *COleClientItem:: activeUIState*

No estado vazio, um item de cliente ainda não é completamente um item. A memória foi alocada para ela, mas ainda não foi inicializada com os dados do item OLE. Esse é o estado em que um item de cliente está quando foi criado por meio de uma chamada para **`new`** , mas ainda não passou pela segunda etapa da criação típica de duas etapas.

Na segunda etapa, executada por meio de uma chamada para `COleClientItem::CreateFromFile` ou outra `CreateFrom` função *xxxx* , o item é completamente criado. Os dados OLE (de um arquivo ou de alguma outra fonte, como a área de transferência) foram associados ao `COleClientItem` objeto derivado. Agora o item está no estado Loaded.

Quando um item tiver sido aberto na janela do servidor em vez de aberto no local no documento do contêiner, ele estará no estado aberto (ou totalmente aberto). Nesse estado, uma hachura cruzada geralmente é desenhada pela representação do item na janela do contêiner para indicar que o item está ativo em outro lugar.

Quando um item é ativado no local, ele passa, normalmente, apenas brevemente, por meio do estado ativo. Em seguida, ele entra no estado ativo da interface do usuário, no qual o servidor mesclou seus menus, barras de ferramentas e outros componentes de interface do usuário com aqueles do contêiner. A presença desses componentes de interface do usuário distingue o estado ativo da IU do estado ativo. Caso contrário, o estado ativo é semelhante ao estado ativo da interface do usuário. Se o servidor oferecer suporte a desfazer, o servidor será solicitado a manter as informações de desfazer estado do item OLE até atingir o estado carregado ou aberto.

## <a name="see-also"></a>Confira também

[Contêineres](containers.md)<br/>
[Ativação](activation-cpp.md)<br/>
[Contêineres: notificações de item de cliente](containers-client-item-notifications.md)<br/>
[Controladores](trackers.md)<br/>
[Classe CRectTracker](reference/crecttracker-class.md)
