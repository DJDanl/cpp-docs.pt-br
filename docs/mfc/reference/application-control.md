---
title: "Controle do aplicativo | Microsoft Docs"
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
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controle do aplicativo"
ms.assetid: c1f69f15-e0fe-4515-9f36-d63d31869deb
caps.latest.revision: 12
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controle do aplicativo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

OLE requer o controle significativo sobre aplicativos e seus objetos.  Dlls OLE DB do sistema devem poder iniciar e para liberar automaticamente aplicativos, coordenar suas produção e modificação de objetos, e assim por diante.  As funções neste tópico atendem a esses requisitos.  Além de ser chamado por DLL com OLE DB do sistema, essas funções devem as vezes ser chamadas por aplicativos também.  
  
### Controle de aplicativo  
  
|||  
|-|-|  
|[AfxOleCanExitApp](../Topic/AfxOleCanExitApp.md)|Indica se o aplicativo pode terminar.|  
|[AfxOleGetMessageFilter](../Topic/AfxOleGetMessageFilter.md)|Recupera o filtro atual da mensagem de aplicativo.|  
|[AfxOleGetUserCtrl](../Topic/AfxOleGetUserCtrl.md)|Recupera o sinalizador usuário atual do controle.|  
|[AfxOleSetUserCtrl](../Topic/AfxOleSetUserCtrl.md)|Define ou limpa o sinalizador de usuário controle.|  
|[AfxOleLockApp](../Topic/AfxOleLockApp.md)|Incrementa a contagem global da estrutura do número de objetos ativos em um aplicativo.|  
|[AfxOleUnlockApp](../Topic/AfxOleUnlockApp.md)|Diminui a contagem da estrutura do número de objetos ativos em um aplicativo.|  
|[AfxOleRegisterServerClass](../Topic/AfxOleRegisterServerClass.md)|Registrar um servidor no Registro do sistema OLE.|  
|[AfxOleSetEditMenu](../Topic/AfxOleSetEditMenu.md)|Implementa a interface do usuário para o comando de objeto *typename* .|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)