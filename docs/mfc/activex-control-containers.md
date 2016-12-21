---
title: "Cont&#234;ineres de controle ActiveX | Microsoft Docs"
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
  - "Contêineres de controle ActiveX [C++]"
  - "Controles OLE [C++], contêineres"
ms.assetid: 0eb1a713-e607-4c79-a0c7-67c5f1fd5fab
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um contêiner do controle ActiveX é um contêiner que suporte total controles ActiveX e os pode inserir em suas próprias o windows ou caixas de diálogo.  Um controle ActiveX é um elemento reutilizável de software que pode ser usada em muitos projetos de desenvolvimento.  Os controles permitem que o usuário do aplicativo acessa bases de dados, monitoram dados, e fazem várias seleções nos seus aplicativos.  Para obter mais informações sobre os controles ActiveX, consulte o artigo [Controles ActiveX MFC](../mfc/mfc-activex-controls.md).  
  
 Controle contêiner normalmente têm dois formulários em um projeto:  
  
-   Caixas de diálogo e diálogo\- como o windows como as exibições de formulário, onde um controle ActiveX é usado em qualquer lugar na caixa de diálogo.  
  
-   O windows em um aplicativo, onde um controle ActiveX é usado em uma barra de ferramentas ou, em outro local na janela do usuário.  
  
 O contêiner do controle ActiveX interage com o controle através de [métodos](../mfc/mfc-activex-controls-methods.md) expostas e de [propriedades](../mfc/mfc-activex-controls-properties.md).  Esses métodos e propriedades, que podem ser acessados e modificados pelo contêiner do controle, são acessados por meio de uma classe de invólucro no projeto do contêiner do controle ActiveX.  O controle ActiveX inserido também pode interagir com o contêiner acionando enviar \(\) [eventos](../mfc/mfc-activex-controls-events.md) para notificar o contêiner que uma ação aconteceu.  O contêiner do controle pode escolher para atuar em cima dessas notificações ou não.  
  
 Os artigos adicionais a seguir discutem vários tópicos, de criar um projeto do contêiner do controle ActiveX a problemas básicos de implementação relacionados aos contêineres do controle ActiveX compilados com o Visual C\+\+:  
  
-   [Criando um contêiner do controle ActiveX de MFC](../mfc/reference/creating-an-mfc-activex-control-container.md)  
  
-   [Contêiner para controles ActiveX](../Topic/Containers%20for%20ActiveX%20Controls.md)  
  
-   [Contêiner do controle ActiveX: Habilitando manualmente a retenção do controle ActiveX](../Topic/ActiveX%20Control%20Containers:%20Manually%20Enabling%20ActiveX%20Control%20Containment.md)  
  
-   [Contêiner do controle ActiveX: Inserindo um controle em um aplicativo de contêiner do controle](../mfc/inserting-a-control-into-a-control-container-application.md)  
  
-   [Contêiner do controle ActiveX: Conectando um controle ActiveX a uma variável de membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md)  
  
-   [Contêiner do controle ActiveX: Eventos de manipulação de um controle ActiveX](../mfc/activex-control-containers-handling-events-from-an-activex-control.md)  
  
-   [Contêiner do controle ActiveX: Exibindo e modificando propriedades de controle](../mfc/activex-control-containers-viewing-and-modifying-control-properties.md)  
  
-   [Contêiner do controle ActiveX: Controles ActiveX de programação em um contêiner do controle ActiveX](../mfc/programming-activex-controls-in-a-activex-control-container.md)  
  
-   [Contêiner do controle ActiveX: Usando controles em um contêiner de não caixa de diálogo](../Topic/ActiveX%20Control%20Containers:%20Using%20Controls%20in%20a%20Non-Dialog%20Container.md)  
  
 Para obter mais informações sobre como usar controles ActiveX em uma caixa de diálogo, consulte os tópicos de [Editor da caixa de diálogo](../mfc/dialog-editor.md) .  
  
 Para obter uma lista dos artigos que explicam os detalhes de desenvolver controles ActiveX usando o Visual C\+\+ e classes do controle ActiveX MFC, consulte [Controles ActiveX MFC](../mfc/mfc-activex-controls.md).  Os artigos são agrupados por categorias funcionais.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)