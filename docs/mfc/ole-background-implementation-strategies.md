---
title: "Plano de fundo OLE: estrat&#233;gias de implementa&#231;&#227;o | Microsoft Docs"
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
  - "aplicativos [OLE], implementando OLE"
  - "OLE [C++], estratégia de desenvolvimento"
  - "Aplicativos OLE [C++], implementando OLE"
ms.assetid: 0875ddae-99df-488c-82c6-164074a81058
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Plano de fundo OLE: estrat&#233;gias de implementa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dependendo de seu aplicativo, há quatro possíveis estratégias de implementação para adicionar suporte OLE:  
  
-   Você estiver escrevendo um novo aplicativo.  
  
     Essa situação normalmente requer o trabalho.  Você executa o assistente de aplicativo MFC e seleciona recursos avançados ou o suporte composto do documento para criar um aplicativo do esqueleto.  Para obter mais informações sobre essas opções e o que fazer, consulte o artigo [Criando um programa MFC EXE](../Topic/MFC%20Application%20Wizard.md).  
  
-   Você tem um programa gravado com a versão 2,0 da biblioteca de classes do Microsoft ou superior que não oferece suporte a OLE.  
  
     Crie um novo aplicativo com o assistente de aplicativo MFC como mencionado anteriormente, e depois copiar e colar o código de aplicativo em seu aplicativo existente.  Isso funcionará para servidores, contêineres, ou aplicativos automatizados.  Consulte o exemplo [GARRANCHO](../top/visual-cpp-samples.md) MFC para obter um exemplo dessa estratégia.  
  
-   Você tem um programa de biblioteca de classes do Microsoft OLE que implementa o suporte da versão 1,0.  
  
     Consulte [Observação 41 técnica MFC](../Topic/TN041:%20MFC-OLE1%20Migration%20to%20MFC-OLE%202.md) para essa estratégia de conversão.  
  
-   Você tem um aplicativo que não sejam escritos usando as classes do Microsoft e que pode ou não possa ter implementado suporte OLE.  
  
     Essa situação exija a maioria de trabalho.  Uma abordagem é criar um novo aplicativo, como na primeira estratégia, e depois copiar e colar seu código existente nela.  Se seu código existente é gravado em C, você pode precisar modificá\-la para que possa criar como código C\+\+.  Se seu código C chamar a API do windows, você não precisa alterar isso para usar as classes do Microsoft.  Essa abordagem provavelmente exigirá qualquer reestruturação do programa dar suporte à arquitetura do documento\/exibição usada por versões 2,0 e superior das classes do Microsoft.  Para obter mais informações sobre essa arquitetura do, consulte [Observação 25 técnica](../mfc/tn025-document-view-and-frame-creation.md).  
  
 Depois de decidir uma estratégia, você deve ler os artigos de [Contêiner](../mfc/containers.md) ou de [Servidores](../mfc/servers.md) \(dependendo do tipo de aplicativo que você estiver escrevendo\) ou para revisar os programas de exemplo, ou ambos.  Os exemplos [OCLIENT](../top/visual-cpp-samples.md) e [HIERSVR](../top/visual-cpp-samples.md) MFC OLE mostram como implementar vários aspectos dos contêineres e servidores, respectivamente.  Em vários pontos durante todos esses artigos, será chamado de determinadas funções nestes exemplos como exemplos das técnicas que estão sendo abordados.  
  
## Consulte também  
 [Plano de fundo OLE](../mfc/ole-background.md)   
 [Contêineres: implementando um contêiner](../mfc/containers-implementing-a-container.md)   
 [Servidores: implementando um servidor](../mfc/servers-implementing-a-server.md)   
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)