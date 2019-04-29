---
title: 'servidores: Implementação de um servidor'
ms.date: 11/04/2016
helpviewer_keywords:
- servers, implementing
- OLE server applications [MFC], implementing OLE servers
ms.assetid: 5bd57e8e-3b23-4f23-9597-496fac2d24b5
ms.openlocfilehash: 953d157f4bbad0b460947740a2622074dfc90f4f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62308011"
---
# <a name="servers-implementing-a-server"></a>servidores: Implementação de um servidor

Este artigo explica o código que o Assistente de aplicativo do MFC cria para um aplicativo de servidor de edição visual. Se você não estiver usando o Assistente de aplicativo, este artigo lista as áreas onde você deve escrever código para implementar um aplicativo de servidor.

Se você estiver usando o Assistente de aplicativo para criar um novo aplicativo de servidor, ele fornece uma quantidade significativa de código específico do servidor para você. Se você estiver adicionando funcionalidade de servidor de edição visual para um aplicativo existente, você deve duplicar o código que o Assistente para aplicativo seria fornecidas antes de adicionar o restante do código do servidor necessárias.

O código do servidor que fornece o Assistente de aplicativo se encaixa em várias categorias:

- Definindo recursos do servidor:

  - O recurso de menu usado quando o servidor está editando um item inserido em sua própria janela.

  - Os recursos de menu e barra de ferramentas usados quando o servidor está ativo em vigor.

  Para obter mais informações sobre esses recursos, consulte [Menus e recursos: Adições de servidor](../mfc/menus-and-resources-server-additions.md).

- Definir uma classe de item derivado de `COleServerItem`. Para obter mais detalhes sobre itens de servidor, consulte [servidores: Itens do servidor](../mfc/servers-server-items.md).

- Alterando a classe base da classe de documento para `COleServerDoc`. Para obter mais detalhes, consulte [servidores: Implementando documentos de servidor](../mfc/servers-implementing-server-documents.md).

- Definindo uma classe de janela com moldura derivado de `COleIPFrameWnd`. Para obter mais detalhes, consulte [servidores: Implementando o Windows de quadro in-loco](../mfc/servers-implementing-in-place-frame-windows.md).

- Criando uma entrada para o aplicativo de servidor no banco de dados de registro do Windows e registrar a nova instância do servidor com o sistema OLE. Para obter informações sobre esse tópico, consulte [registro](../mfc/registration.md).

- Inicializar e iniciar o aplicativo de servidor. Para obter informações sobre esse tópico, consulte [registro](../mfc/registration.md).

Para obter mais informações, consulte [COleServerItem](../mfc/reference/coleserveritem-class.md), [COleServerDoc](../mfc/reference/coleserverdoc-class.md), e [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md) no *referência da biblioteca de classe*.

## <a name="see-also"></a>Consulte também

[Servidores](../mfc/servers.md)<br/>
[Contêineres](../mfc/containers.md)<br/>
[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Registro](../mfc/registration.md)
