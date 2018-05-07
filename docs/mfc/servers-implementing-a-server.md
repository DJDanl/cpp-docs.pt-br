---
title: 'Servidores: Implementando um servidor | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- servers, implementing
- OLE server applications [MFC], implementing OLE servers
ms.assetid: 5bd57e8e-3b23-4f23-9597-496fac2d24b5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0ea51d6cd811572d73b0de64072f3d335e2682fd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="servers-implementing-a-server"></a>Servidores: implementando um servidor
Este artigo explica o código de que Assistente de aplicativo MFC cria para um aplicativo de servidor de edição visual. Se você não estiver usando o Assistente de aplicativo, este artigo lista as áreas em que você deve escrever código para implementar um aplicativo de servidor.  
  
 Se você estiver usando o Assistente de aplicativo para criar um novo aplicativo de servidor, ele fornece uma quantidade significativa de código específico do servidor para você. Se você estiver adicionando funcionalidade de servidor de edição visual para um aplicativo existente, você deverá duplicar o código que o Assistente de aplicativo deve ter fornecido antes de adicionar o restante do código do servidor necessários.  
  
 O código do servidor que fornece o Assistente de aplicativo se encaixa em várias categorias:  
  
-   Definindo recursos do servidor:  
  
    -   O recurso de menu usado quando o servidor estiver editando um item inserido em sua própria janela.  
  
    -   Os recursos de menu e barra de ferramentas usados quando o servidor está ativo no local.  
  
     Para obter mais informações sobre esses recursos, consulte [Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md).  
  
-   Definir uma classe de item derivado de `COleServerItem`. Para obter mais detalhes sobre itens do servidor, consulte [servidores: itens de servidor](../mfc/servers-server-items.md).  
  
-   Alterando a classe base da classe do documento para `COleServerDoc`. Para obter mais detalhes, consulte [servidores: Implementando documentos de servidor](../mfc/servers-implementing-server-documents.md).  
  
-   Definir uma classe de janela com moldura derivado de `COleIPFrameWnd`. Para obter mais detalhes, consulte [servidores: Implementando janelas com moldura no local](../mfc/servers-implementing-in-place-frame-windows.md).  
  
-   Criando uma entrada para o aplicativo do servidor do banco de dados de registro do Windows e registrando a nova instância do servidor com o sistema OLE. Para obter informações sobre este tópico, consulte [registro](../mfc/registration.md).  
  
-   Inicializar e iniciar o aplicativo do servidor. Para obter informações sobre este tópico, consulte [registro](../mfc/registration.md).  
  
 Para obter mais informações, consulte [COleServerItem](../mfc/reference/coleserveritem-class.md), [COleServerDoc](../mfc/reference/coleserverdoc-class.md), e [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md) no *referência da biblioteca de classe*.  
  
## <a name="see-also"></a>Consulte também  
 [Servidores](../mfc/servers.md)   
 [Contêineres](../mfc/containers.md)   
 [Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)   
 [Registro](../mfc/registration.md)

