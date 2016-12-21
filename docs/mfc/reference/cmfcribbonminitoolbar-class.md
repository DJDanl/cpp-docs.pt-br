---
title: "Classe de CMFCRibbonMiniToolBar | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMFCRibbonMiniToolBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonMiniToolBar"
ms.assetid: 7017e963-aeaf-4fe9-b540-e15a7ed41e94
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonMiniToolBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma barra de ferramentas pop\-up contextuais.  
  
## Sintaxe  
  
```  
class CMFCRibbonMiniToolBar : public CMFCRibbonPanelMenu  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCRibbonMiniToolBar::CMFCRibbonMiniToolBar`|Construtor padrão.|  
|`CMFCRibbonMiniToolBar::~CMFCRibbonMiniToolBar`|Destruidor.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCRibbonMiniToolBar::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|`CMFCRibbonMiniToolBar::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) objeto associado esse tipo de classe.|  
|[CMFCRibbonMiniToolBar::IsContextMenuMode](../Topic/CMFCRibbonMiniToolBar::IsContextMenuMode.md)||  
|[CMFCRibbonMiniToolBar::IsRibbonMiniToolBar](../Topic/CMFCRibbonMiniToolBar::IsRibbonMiniToolBar.md)|\(Substitui `CMFCPopupMenu::IsRibbonMiniToolBar`.\)|  
|[CMFCRibbonMiniToolBar::SetCommands](../Topic/CMFCRibbonMiniToolBar::SetCommands.md)|Define a lista de comandos a ser exibido na barra de ferramentas.|  
|[CMFCRibbonMiniToolBar::Show](../Topic/CMFCRibbonMiniToolBar::Show.md)|Exibe a Minibarra de ferramentas em coordenadas especificadas da tela.|  
|[CMFCRibbonMiniToolBar::ShowWithContextMenu](../Topic/CMFCRibbonMiniToolBar::ShowWithContextMenu.md)|Exibe a Minibarra de ferramentas juntamente com um menu de contexto.|  
  
## Comentários  
 A Minibarra de ferramentas normalmente é exibida depois que o usuário seleciona um objeto em um documento.  Por exemplo, depois que o usuário seleciona um bloco de texto de programa de processamento de uma palavra, o aplicativo exibe uma Minibarra de ferramentas que contém os comandos de formatação de texto.  
  
 A Minibarra de ferramentas se torna transparente quando o ponteiro do mouse está fora dos limites da Minibarra de ferramentas.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)  
  
 [CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md)  
  
 `CMFCRibbonPanelMenu`  
  
 [CMFCRibbonMiniToolBar](../../mfc/reference/cmfcribbonminitoolbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxRibbonMiniToolBar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)