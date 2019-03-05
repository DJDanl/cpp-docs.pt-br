---
title: 'servidores: Implementando documentos de servidor'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE server applications [MFC], managing server documents
- OLE server applications [MFC], implementing OLE servers
- servers, server documents
- server documents [MFC], implementing
ms.assetid: cca1451a-ad09-47ed-b56e-bccd78fc86d1
ms.openlocfilehash: 17ced1cdb0b40b13fbda68150030efde5735ba7b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261863"
---
# <a name="servers-implementing-server-documents"></a>servidores: Implementando documentos de servidor

Este artigo explica as etapas que você deve adotar para implementar com êxito um documento do servidor, se você não especificou a opção de servidor OLE no Assistente do aplicativo.

#### <a name="to-define-a-server-document-class"></a>Para definir uma classe de documento do servidor

1. Derive sua classe de documento da `COleServerDoc` em vez de `CDocument`.

1. Criar uma classe de item de servidor derivada `COleServerItem`.

1. Implementar o `OnGetEmbeddedItem` a função de membro da sua classe de documento do servidor.

   `OnGetEmbeddedItem` é chamado quando o usuário de um aplicativo de contêiner cria ou edita um item inserido. Ele deverá retornar um item que representa o documento inteiro. Isso deve ser um objeto do seu `COleServerItem`-classe derivada.

1. Substituir o `Serialize` a função de membro para serializar o conteúdo do documento. Você não precisa serializar a lista de itens do servidor, a menos que você os estiver usando para representar os dados nativos no documento. Para obter mais informações, consulte *itens do servidor implementando* no artigo [servidores: Itens do servidor](../mfc/servers-server-items.md).

Quando um documento do servidor é criado, a estrutura registra automaticamente o documento com as DLLs do sistema OLE. Isso permite que as DLLs identificar os documentos de servidor.

Para obter mais informações, consulte [COleServerItem](../mfc/reference/coleserveritem-class.md) e [COleServerDoc](../mfc/reference/coleserverdoc-class.md) no *referência da biblioteca de classe*.

## <a name="see-also"></a>Consulte também

[Servidores](../mfc/servers.md)<br/>
[servidores: Itens do servidor](../mfc/servers-server-items.md)<br/>
[servidores: Implementação de um servidor](../mfc/servers-implementing-a-server.md)<br/>
[servidores: Implementando o Windows de quadro in-loco](../mfc/servers-implementing-in-place-frame-windows.md)
