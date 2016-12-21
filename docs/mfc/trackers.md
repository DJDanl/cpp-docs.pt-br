---
title: "Controladores | Microsoft Docs"
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
  - "aplicativos [OLE], controladores"
  - "classe CDC, controladores"
  - "Classe CRectTracker, implementando controladores"
  - "Aplicativos OLE [C++], controladores"
  - "Contêineres OLE, controladores"
  - "aplicativos de servidor OLE, controladores"
  - "controladores"
  - "acompanhando itens de OLE"
ms.assetid: dcd09399-6637-4621-80e5-d12670429787
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controladores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de [CRectTracker](../mfc/reference/crecttracker-class.md) fornece uma interface de usuário do entre itens retangulares em seu aplicativo e o usuário fornecendo uma variedade de estilo de exibição.  Esses estilos incluem bordas contínuas, chocadas, ou precipitadas; um padrão chocado que abrange o item; e redimensionar as alças que podem ser posicionados em externa ou interno de uma borda.  Os perseguidores geralmente são usados em conjunto com itens OLE, ou seja, objetos derivados de `COleClientItem`.  Os retângulos de controladores fornecem indicações visuais no status atual do item.  
  
 O exemplo [OCLIENT](../top/visual-cpp-samples.md) MFC OLE demonstra uma interface comum usando perseguidores e itens do cliente do ponto de vista de um aplicativo do contêiner.  Para ver uma demonstração dos estilos diferentes e das capacidades de um objeto controlador, consulte o exemplo [PERSEGUIDOR](../top/visual-cpp-samples.md)gerais de MFC.  
  
 Para obter mais informações sobre como implementar perseguidores em seu aplicativo OLE, consulte [Perseguidores: Implementando perseguidores em seu aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Classe de COleClientItem](../mfc/reference/coleclientitem-class.md)