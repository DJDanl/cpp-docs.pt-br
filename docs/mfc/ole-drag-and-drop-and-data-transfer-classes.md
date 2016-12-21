---
title: "Classes de transfer&#234;ncia para arrastar e soltar dados OLE | Microsoft Docs"
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
  - "transferência de dados [C++], OLE"
  - "classes de transferência de dados [C++]"
  - "arrastar e soltar [C++], Classes "
  - "arrastar e soltar OLE [C++], e classes de transferência de dados"
ms.assetid: c8ab2825-ed69-4b88-8ae6-f368b94726b8
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de transfer&#234;ncia para arrastar e soltar dados OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes são usadas em transferências de dados OLE DB.  Permitem que os dados sejam transferidos entre aplicativos usando a área de transferência ou com o arraste e remoção.  
  
 [COleDropSource](../mfc/reference/coledropsource-class.md)  
 Controla a operação de arrastar e soltar do início ao fim.  Essa classe determina quando inicia a operação de arrastar e quando termina.  Também exibe comentários de cursor durante a operação de arrastar e soltar.  
  
 [COleDataSource](../mfc/reference/coledatasource-class.md)  
 Usado quando um aplicativo para fornecer dados para uma transferência de dados.  `COleDataSource` pode ser exibido como um objeto orientado a objeto da área de transferência.  
  
 [COleDropTarget](../Topic/COleDropTarget%20Class.md)  
 Representa o destino de uma operação de arrastar e soltar.  Um objeto de `COleDropTarget` corresponde a uma janela na tela.  Determina se aceitar todos os dados removidos nela e implementa a operação real de descarte.  
  
 [COleDataObject](../mfc/reference/coledataobject-class.md)  
 Usado como o lado do destinatário a `COleDataSource`.  os objetos de`COleDataObject` fornecem acesso aos dados armazenados por um objeto de `COleDataSource` .  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)