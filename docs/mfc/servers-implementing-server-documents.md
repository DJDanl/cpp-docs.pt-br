---
title: "Servidores: implementando documentos de servidor | Microsoft Docs"
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
  - "aplicativos de servidor OLE, gerenciando documentos de servidor"
  - "documentos de servidor, implementando"
  - "servidores, documentos de servidor"
ms.assetid: cca1451a-ad09-47ed-b56e-bccd78fc86d1
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores: implementando documentos de servidor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica as etapas que você deve usar para implementar com êxito um documento de servidor se você não especificou a opção OLE do servidor no assistente do aplicativo.  
  
#### Para definir uma classe de documento de servidor  
  
1.  Derivar a sua classe de documento de `COleServerDoc` em vez de **CDocument**.  
  
2.  Crie uma classe do item do servidor de `COleServerItem`derivada.  
  
3.  Implementar a função de membro de `OnGetEmbeddedItem` da sua classe do documento de servidor.  
  
     `OnGetEmbeddedItem` é chamado quando o usuário de um aplicativo de contêiner criar ou editar um item inserido.  Deve retornar um item que representa o documento inteiro.  Isso deve ser um objeto do `COleServerItem`\- classe derivada.  
  
4.  Substitua a função de membro de `Serialize` para serializar o conteúdo do documento.  Você não precisa serializar a lista de itens do servidor a menos que você esteja usando os para representar dados nativos no documento.  Para obter mais informações, veja *que implementa itens do servidor* no artigo [Servidores: Itens do servidor](../mfc/servers-server-items.md).  
  
 Quando um documento de servidor é criada, a estrutura registra automaticamente o documento com as dlls OLE DB do sistema.  Isso permite que as dlls para identificar os documentos de servidor.  
  
 Para obter mais informações, consulte [COleServerItem](../mfc/reference/coleserveritem-class.md) e [COleServerDoc](../Topic/COleServerDoc%20Class.md)*na referência da biblioteca da classe*.  
  
## Consulte também  
 [Servidores](../mfc/servers.md)   
 [Servidores: itens de servidor](../mfc/servers-server-items.md)   
 [Servidores: implementando um servidor](../mfc/servers-implementing-a-server.md)   
 [Servidores: implementando janelas de quadro in\-loco](../Topic/Servers:%20Implementing%20In-Place%20Frame%20Windows.md)