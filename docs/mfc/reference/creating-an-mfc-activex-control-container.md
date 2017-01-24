---
title: "Criando um cont&#234;iner de controle ActiveX MFC | Microsoft Docs"
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
  - "vc.appwiz.activex.container"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Contêineres de controle ActiveX [C++], criando"
  - "contêineres [C++], criando"
  - "Controles ActiveX MFC [C++], contêineres"
  - "Controles OLE [C++], contêineres"
ms.assetid: ec70e137-7c14-4940-bd0e-fd4edcc63ea5
caps.latest.revision: 8
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um cont&#234;iner de controle ActiveX MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um contêiner do controle ActiveX é um programa pai que fornece o ambiente do para que um controle ActiveX \(anteriormente OLE\) seja executado.  Você pode criar um aplicativo capaz de conter controles ActiveX com ou sem o MFC, mas é muito mais fácil fazer com MFC.  
  
 Criar um programa do contêiner MFC que usa [Assistente do aplicativo MFC](../Topic/MFC%20Application%20Wizard.md) permite que você acesse muitos recursos e de automação de controles ActiveX que são implementados por classes e MFC do ActiveX.  Esses recursos incluem a edição visual, automação, criando arquivos compostos, e suporte para controles.  As opções visuais de edição do assistente de aplicativo MFC que seu programa pai dará suporte incluem a criação de um contêiner, de um mini\- servidor, de um servidor completo, e um programa que é um contêiner e um servidor.  
  
-   **New MFC Application**.  Para criar um novo MFC programe que inclui a automação, a edição visual, arquivos ou compostos, suporte ao controle, use o assistente de aplicativo MFC e escolha as opções apropriadas de automação.  
  
-   **Existing MFC Application**.  Se você estiver adicionando a retenção de controle para um aplicativo existente MFC, consulte [Contêiner de controlador OLE: Habilitando manualmente a retenção do controlador OLE](../Topic/ActiveX%20Control%20Containers:%20Manually%20Enabling%20ActiveX%20Control%20Containment.md).  
  
### Para criar um contêiner de ActiveX para qualquer um dos seguintes tipos de aplicativos  
  
1.  [Containers](../../mfc/containers.md)  
  
2.  [Edição visual](../../mfc/ole-mfc.md)  
  
3.  [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md)  
  
## Consulte também  
 [Tipos de projeto do Visual C\+\+](../../ide/visual-cpp-project-types.md)