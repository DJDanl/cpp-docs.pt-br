---
title: "Classes de documento | Microsoft Docs"
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
  - "vc.classes.document"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de documento"
ms.assetid: 4bf19b02-0a4f-4319-b68e-cddcba2705cb
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de documento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Documenta os objetos da classe, criados por objetos do documento modelo, gerenciar os dados do aplicativo.  Você derivará uma classe para seus documentos de uma dessas classes.  
  
 Os objetos da classe do documento interagem com os objetos de exibição.  Os objetos de exibição representam a área do cliente de uma janela, exibem dados de um documento, e permitem que os usuários interajam com ela.  Os documentos e exibições são criados por um objeto de documento modelo.  
  
 [CDocument](../Topic/CDocument%20Class.md)  
 A classe base para documentos específicos do aplicativo.  Derivar a classe ou suas classes do documento de **CDocument**.  
  
 [COleDocument](../mfc/reference/coledocument-class.md)  
 Usado para a implementação composta de documento, bem como o suporte básico do contêiner.  Funciona como um contêiner para classes derivaram\-se de [CDocItem](../mfc/reference/cdocitem-class.md).  Esta classe pode ser usada como a classe base para documentos contêiner e é a classe base para `COleServerDoc`.  
  
 [COleLinkingDoc](../mfc/reference/colelinkingdoc-class.md)  
 Uma classe derivada de `COleDocument` que fornece a infraestrutura para vincular.  Você deve derivar as classes do documento para aplicativos de contêiner desta classe em vez de `COleDocument` se desejar aos links de suporte a objetos inseridos.  
  
 [CRichEditDoc](../mfc/reference/cricheditdoc-class.md)  
 Mantém a lista de itens do cliente que estão no controle de edição sofisticado.  Usado com [CRichEditView](../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md).  
  
 [COleServerDoc](../Topic/COleServerDoc%20Class.md)  
 Usado como a classe base para o documento de aplicativo de servidor classifica.  os objetos de`COleServerDoc` fornecem o volume de suporte do servidor com interações com objetos de [COleServerItem](../mfc/reference/coleserveritem-class.md) .  O recurso visual da edição é fornecido com o uso da arquitetura do documento\/exibição de biblioteca da classe.  
  
 [CHtmlEditDoc](../mfc/reference/chtmleditdoc-class.md)  
 Fornece, [CHtmlEditView](../mfc/reference/chtmleditview-class.md), a funcionalidade do navegador da web de HTML a edição da plataforma no contexto da arquitetura de documento exibição MFC.  
  
## Classes relacionadas  
 Os objetos da classe de documentos podem ser persistentes — ou seja podem gravar seu estado para um suporte de memória e ler novamente.  MFC O fornece a classe de `CArchive` para facilitar transferir os dados de documento em um suporte de memória.  
  
 [CArchive](../mfc/reference/carchive-class.md)  
 Ele coopera com um objeto de [CFile](../mfc/reference/cfile-class.md) para o repositório persistente de ferramentas para objetos com a serialização [CObject::Serialize](../Topic/CObject::Serialize.md)\(consulte\).  
  
 Os documentos também podem conter objetos OLE.  `CDocItem` é a classe base dos itens de cliente e de servidor.  
  
 [CDocItem](../mfc/reference/cdocitem-class.md)  
 Classe base abstrata de [COleClientItem](../mfc/reference/coleclientitem-class.md) e de [COleServerItem](../mfc/reference/coleserveritem-class.md).  Os objetos das classes derivadas de `CDocItem` representam partes de documentos.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)