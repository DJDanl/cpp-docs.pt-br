---
title: Grupos com guias MDI | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- mdi [MFC], tabbed groups
- tabbed grous [MFC]
ms.assetid: 0a464f36-39b7-4e68-8b67-ec175de28377
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9606d28f6e2057072a0c9fc356e3bc7ca7cdc19b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mdi-tabbed-groups"></a>Grupos com guias MDI
O recurso de grupos com guias MDI (interface) documento vários permite que vários aplicativos de interface (MDI) do documento exibir uma ou mais janelas com guias (ou grupos do windows com guias, conhecidos como *grupos com guias*) na área do cliente MDI. As janelas tabuladas podem ser alinhadas verticalmente ou horizontalmente. Se um aplicativo hospeda mais de um grupo de guias MDI, os grupos são separados por divisores.  
  
## <a name="features"></a>Recursos  
 Estes são os recursos de grupos MDI com guias:  
  
-   Um aplicativo pode criar janelas tabuladas dinamicamente.  
  
-   Um aplicativo pode alinhar as janelas tabuladas horizontal ou verticalmente.  
  
-   Grupos de janelas com guias são separados por divisores. O usuário pode redimensionar grupos com guias usando o divisor.  
  
-   O usuário pode arrastar guias individuais entre grupos.  
  
-   O usuário pode arrastar guias individuais para criar novos grupos.  
  
-   O usuário pode mover guias ou criar novos grupos usando um menu de atalho.  
  
-   Um aplicativo pode salvar e carregar o layout de janelas com guias.  
  
-   Um aplicativo pode salvar e carregar a lista de documentos MDI.  
  
-   Um aplicativo pode acessar grupos com guias individuais e modificar seus parâmetros.  
  
### <a name="using-mdi-tabbed-groups"></a>Usar MDI grupos com guias  
 A seguir estão as tarefas comumente executadas com grupos MDI com guias:  
  
-   Para habilitar grupos MDI com guias para uma janela do quadro principal, chame [CMDIFrameWndEx::EnableMDITabbedGroups](../mfc/reference/cmdiframewndex-class.md#enablemditabbedgroups). O segundo parâmetro do método é uma instância do `CMDITabInfo` classe. Você pode usar os parâmetros padrão ou modificá-las antes de chamar `CMDIFrameWndEx::EnableMDITabbedGroups`.  
  
-   Para modificar as propriedades de um grupo com guias MDI em tempo de execução, criar ou modificar uma `CMDITabInfo` objeto e chame `CMDIFrameWndEx::EnableMDITabbedGroups` novamente  
  
-   Para obter uma lista de MDI com guias windows, chame `CMDIFrameWndEx::GetMDITabGroups`.  
  
-   Para criar um novo grupo com guias MDI ao lado de um grupo com guias active, chame `CMDIFrameWndEx::MDITabNewGroup`.  
  
-   Para alternar o foco de entrada para a janela anterior ou seguinte de um grupo com guias, chame `CMDIFrameWndEx::MDITabMoveToNextGroup`.  
  
-   Para determinar se uma janela é um membro de um MDI com guias chamada grupo `CMDIFrameWndEx::IsMemberOfMDITabGroup`.  
  
-   Para determinar se as guias MDI ou MDI tabbed groups estão habilitadas para uma janela do quadro principal, chame `CMDIFrameWndEx::AreMDITabs`. Para determinar somente se os grupos MDI com guias são habilitados, chame `CMDIFrameWndEx::IsMDITabbedGroup`.  
  
-   Para exibir um menu de atalho quando o usuário clica em uma guia ou arrasta-o para outro grupo de com guias MDI, substituir `CMDIFrameWndEx::OnShowMDITabContextMenu` no `CMDIFrameWndEx`-classe derivada. Se você não implementar esse método, o aplicativo não exibirá o menu de atalho.  
  
-   Para salvar o layout do MDI tabbed groups em um aplicativo, chame `CMDIFrameWndEx::SaveMDIState`. Para carregar um MDI salvo anteriormente com guias perfil de grupo, chame `CMDIFrameWndEx::LoadMDIState`. Você também pode chamar esses métodos para carregar ou salvar a lista de documentos abertos em um aplicativo MDI. Para obter mais informações sobre como salvar e carregar o estado MDI, consulte [CMDIFrameWndEx::LoadMDIState](../mfc/reference/cmdiframewndex-class.md#loadmdistate).  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Classe CMDIFrameWndEx](../mfc/reference/cmdiframewndex-class.md)   
 [Classe CMDIChildWndEx](../mfc/reference/cmdichildwndex-class.md)   
 [Classe CMDITabInfo](../mfc/reference/cmditabinfo-class.md)
