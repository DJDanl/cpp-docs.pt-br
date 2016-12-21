---
title: "Servidores: implementando um servidor | Microsoft Docs"
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
  - "aplicativos de servidor OLE, implementando servidores OLE"
  - "servidores, implementando"
ms.assetid: 5bd57e8e-3b23-4f23-9597-496fac2d24b5
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores: implementando um servidor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica o código que o assistente de aplicativo MFC cria para um aplicativo de servidor visual de edição.  Se você não estiver usando o assistente de aplicativo, listas deste artigo as áreas onde você deve escrever o código para implementar um aplicativo de servidor.  
  
 Se você estiver usando o assistente do aplicativo para criar um novo aplicativo de servidor, fornece uma quantidade significativa de código específico de servidor para você.  Se você estiver adicionando funcionalidade visual do servidor de edição a um aplicativo existente, você deve duplicar o código que o assistente de aplicativo ofereceria antes de adicionar o restante do código de servidor necessário.  
  
 O código de servidor que o assistente do aplicativo fornece quedas em várias categorias:  
  
-   Definindo recursos do servidor:  
  
    -   O recurso de menu usado quando o servidor editar um item inserido em sua própria janela.  
  
    -   Os recursos de menu e a barra de ferramentas usados quando o servidor estiver em vigor ativa.  
  
     Para obter mais informações sobre esses recursos, consulte [Menus e recursos: Adições de servidor](../mfc/menus-and-resources-server-additions.md).  
  
-   Definindo uma classe derivada do item de `COleServerItem`.  Para obter detalhes adicionais nos itens do servidor, consulte [Servidores: Itens do servidor](../mfc/servers-server-items.md).  
  
-   Alterando a classe base da classe do documento em `COleServerDoc`.  Para obter detalhes adicionais, consulte [Servidores: Implementando documentos do servidor](../mfc/servers-implementing-server-documents.md).  
  
-   Definindo uma classe de quadro\- janela derivada de `COleIPFrameWnd`.  Para obter detalhes adicionais, consulte [Servidores: Implementando o windows no local do quadro](../Topic/Servers:%20Implementing%20In-Place%20Frame%20Windows.md).  
  
-   Criando uma entrada para o aplicativo de servidor no base de dados e no registro do registro do windows a nova instância do servidor com o sistema OLE.  Para obter informações sobre este tópico, consulte [Registro](../mfc/registration.md).  
  
-   Inicializando e iniciando o aplicativo de servidor.  Para obter informações sobre este tópico, consulte [Registro](../mfc/registration.md).  
  
 Para obter mais informações, consulte [COleServerItem](../mfc/reference/coleserveritem-class.md), [COleServerDoc](../Topic/COleServerDoc%20Class.md), e [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)*na referência da biblioteca da classe*.  
  
## Consulte também  
 [Servidores](../mfc/servers.md)   
 [Contêineres](../mfc/containers.md)   
 [Menus e recursos \(OLE\)](../mfc/menus-and-resources-ole.md)   
 [Registro](../mfc/registration.md)