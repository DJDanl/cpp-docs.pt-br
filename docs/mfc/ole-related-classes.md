---
title: "Classes relacionadas a OLE | Microsoft Docs"
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
  - "vc.classes.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classes ActiveX [C++]"
  - "OLE [C++], Classes "
  - "Classes OLE [C++]"
ms.assetid: 2135cf54-1d9d-4e0e-91b4-943b3440effa
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes relacionadas a OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes fornecem um número de serviços diferentes, variando de exceções à entrada e as saídas do arquivo.  
  
 [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md)  
 Usado para criar itens quando solicitado de outros contêineres.  Essa classe serve como a classe base para tipos específicos de mais fábricas, incluindo `COleTemplateServer`.  
  
 [COleMessageFilter](../mfc/reference/colemessagefilter-class.md)  
 Usado para gerenciar a simultaneidade com chamadas de procedimento remoto superficial OLE \(LRPC\).  
  
 [COleStreamFile](../Topic/COleStreamFile%20Class.md)  
 Usa a interface COM `IStream` para fornecer acesso aos arquivos de `CFile` compostos.  Essa classe derivada de `CFile`\(\) habilita a serialização MFC para usar o armazenamento estruturado OLE.  
  
 [CRectTracker](../mfc/reference/crecttracker-class.md)  
 Usado para permitir mover, redimensionar, e redirecionamento de itens no local.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)