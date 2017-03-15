---
title: "Cont&#234;ineres de controle ActiveX: inserindo um controle em um aplicativo de cont&#234;iner de controle | Microsoft Docs"
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
  - "Contêineres de controle ActiveX [C++], inserindo controles"
  - "Controles ActiveX [C++], adicionando a projetos"
ms.assetid: bbb617ff-872f-43d8-b4d6-c49adb16b148
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de controle ActiveX: inserindo um controle em um aplicativo de cont&#234;iner de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Antes de poder acessar um controle ActiveX de um aplicativo de contêiner do controle ActiveX, você deve adicionar o controle ActiveX para o aplicativo de contêiner usando a caixa de diálogo [Controle ActiveX de inserção](../Topic/Insert%20ActiveX%20Control%20Dialog%20Box.md) .  
  
 Para adicionar um controle ActiveX ao projeto do contêiner do controle ActiveX, consulte [Exibindo e adicionando controles ActiveX a uma caixa de diálogo](../mfc/viewing-and-adding-activex-controls-to-a-dialog-box.md).  
  
 Uma vez que adicionar o controle, você precisa adicionar uma variável de membro \(do tipo de controle ActiveX data objects\) para a classe da caixa de diálogo.  Para obter mais informações sobre esse procedimento, consulte [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md).  
  
 Depois de adicionar a variável de membro uma classe, referenciada como uma classe de invólucro, é automaticamente criada e adicionada ao seu projeto.  Esta classe é usada como uma interface entre o contêiner do controle e o controle inserido.  
  
## Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)