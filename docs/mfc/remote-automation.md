---
title: "Automa&#231;&#227;o remota | Microsoft Docs"
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
  - "Controlador de Automação"
  - "Objetos Automation"
  - "Objetos Automation, criando"
  - "COM, Automação remota"
  - "DCOM, Automação remota"
  - "MFC COM, Automação remota"
  - "MFC, Suporte COM"
  - "Automação remota"
ms.assetid: 363f87fb-08fa-4458-b089-b46365a6d4f2
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Automa&#231;&#227;o remota
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  É recomendável que os desenvolvedores do Visual C\+\+ .NET usam DCOM em vez da automação remoto para novos aplicativos.  Visual C\+\+ .NET não oferece suporte ao Windows 95.  Os casos em que você precisaria dar suporte à automação remoto são descritos em [Onde a automação remoto se ajustar em?](../mfc/where-does-remote-automation-fit-in-q.md).  
  
 A automação remoto é um tipo de [Automação](../mfc/automation.md) que permite que um consumidor da interface executa um provedor da interface que reside em outro computador, por exemplo, em uma rede.  
  
 Este artigo explica como criar os objetos de automação que podem ser chamadas e executado remotamente, e como criar os controladores de automação que podem usar esses objetos remotos de automação.  Também revisar as opções de configuração e indica as principais diferenças entre a automação remoto e o DCOM \(distributed da versão COM e OLE que permite interfaces diferentes de aquelas relacionadas à automação a ser chamada e executado remotamente\).  
  
## Nesta seção  
 [Histórico de DCOM \(Distributed Component Object Model\)](../mfc/history-of-dcom.md)  
  
 [Onde a automação remoto se ajustar em?](../mfc/where-does-remote-automation-fit-in-q.md)  
  
 [A automação remoto fornece?](../mfc/what-does-remote-automation-provide-q.md)  
  
 [Segurança remota de automação](../mfc/security-in-remote-automation.md)  
  
 [Modelos de threading](../mfc/remote-automation-threading-models.md)  
  
 [Instalação](../Topic/Remote%20Automation%20Installation.md)  
  
 [O gerenciador de automação](../mfc/automation-manager-mfc.md)  
  
-   [O gerenciador de conexões de automação remoto](../mfc/remote-automation-connection-manager.md)  
  
-   [Componentes remotas do usuário de automação](../mfc/remote-automation-user-components.md)  
  
 [Criando programas que usam a automação remoto](../mfc/creating-programs-that-use-remote-automation.md)  
  
 [Automação remoto em execução usando AUTOCLIK e AUTODRIV](../mfc/running-remote-automation-using-autoclik-and-autodriv.md)  
  
## Consulte também  
 [MFC COM](../mfc/mfc-com.md)   
 [Automação](../mfc/automation.md)