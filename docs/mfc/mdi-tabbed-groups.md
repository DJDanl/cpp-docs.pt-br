---
title: "Grupos com guias MDI | Microsoft Docs"
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
  - "mdi, grupos com guias"
  - "grupos com guias"
ms.assetid: 0a464f36-39b7-4e68-8b67-ec175de28377
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Grupos com guias MDI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O recurso listado \(MDI\) de grupos interface de documentos \(MDI\) permite que aplicativos de interface de documentos exibir uma ou várias janelas tabuladas \(ou grupos de janelas tabuladas, conhecidos como *grupos com guias*\) na área de cliente MDI.  As janelas tabuladas podem ser alinhadas verticalmente ou horizontalmente.  Se um aplicativo hospeda mais de um grupo listado MDI, os grupos são separados por separadores.  
  
## Recursos  
 Os seguintes são os recursos MDI catalogaram grupos:  
  
-   Um aplicativo pode criar janelas tabuladas dinamicamente.  
  
-   Um aplicativo pode alinhar janelas tabuladas horizontal ou verticalmente.  
  
-   Os grupos de janelas tabuladas são separados por separadores.  O usuário pode redimensionar grupos com guias usando o separador.  
  
-   O usuário pode arrastar guias individuais entre grupos.  
  
-   O usuário pode arrastar guias individuais para criar novos grupos.  
  
-   O usuário pode mover guias ou criar novos grupos usando um menu de atalho.  
  
-   Um aplicativo pode salvar e carregar o layout de janelas tabuladas.  
  
-   Um aplicativo pode salvar e carregar a lista de documentos MDI.  
  
-   Um aplicativo pode acessar grupos com guias individuais e modificar seus parâmetros.  
  
### Usando grupos com guia MDI  
 São tarefas executadas normalmente com documentos catalogaram grupos:  
  
-   Para habilitar MDI catalogou grupos para uma janela do quadro principal, chama [CMDIFrameWndEx::EnableMDITabbedGroups](../Topic/CMDIFrameWndEx::EnableMDITabbedGroups.md).  O segundo parâmetro desse método é uma instância da classe de `CMDITabInfo` .  Você pode usar os parâmetros padrão ou alterá\-los antes de chamar `CMDIFrameWndEx::EnableMDITabbedGroups`.  
  
-   Para alterar em tempo de execução as propriedades de um grupo listado MDI, criar ou modificar um objeto de `CMDITabInfo` e chamar novamente `CMDIFrameWndEx::EnableMDITabbedGroups`  
  
-   Para obter uma lista de documentos catalogou o windows, chama `CMDIFrameWndEx::GetMDITabGroups`.  
  
-   Para criar um novo MDI catalogou o grupo ao lado de um grupo com guias ativa, chama `CMDIFrameWndEx::MDITabNewGroup`.  
  
-   Para mudar o foco de entrada janela anterior ou próximo de um grupo com guias, chame `CMDIFrameWndEx::MDITabMoveToNextGroup`.  
  
-   Para determinar se uma janela é um membro de uma chamada listado MDI `CMDIFrameWndEx::IsMemberOfMDITabGroup`do grupo.  
  
-   Para determinar se as guias MDI ou grupos com guia documentos estão habilitados para uma janela do quadro principal, chame `CMDIFrameWndEx::AreMDITabs`.  Para determinar se apenas documentos catalogou grupos são habilitados, chame `CMDIFrameWndEx::IsMDITabbedGroup`.  
  
-   Para exibir um menu de atalho quando o usuário clica em uma guia ou o arrastar a outro grupo listado MDI, substitua `CMDIFrameWndEx::OnShowMDITabContextMenu` em `CMDIFrameWndEx`\- classe derivada.  Se você não implementa esse método, o aplicativo não exibirá o menu de atalho.  
  
-   Para salvar o layout MDI catalogou grupos em um aplicativo, chama `CMDIFrameWndEx::SaveMDIState`.  Para carregar documentos salva anteriormente catalogou o perfil de grupo, chama `CMDIFrameWndEx::LoadMDIState`.  Você também pode chamar esses métodos para carregar ou salvar a lista de documentos abertos em um aplicativo MDI.  Para obter mais informações sobre o estado MDI de salvamento e carregamento, consulte [CMDIFrameWndEx::LoadMDIState](../Topic/CMDIFrameWndEx::LoadMDIState.md).  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Classe CMDIFrameWndEx](../Topic/CMDIFrameWndEx%20Class.md)   
 [Classe CMDIChildWndEx](../Topic/CMDIChildWndEx%20Class.md)   
 [Classe de CMDITabInfo](../Topic/CMDITabInfo%20Class.md)