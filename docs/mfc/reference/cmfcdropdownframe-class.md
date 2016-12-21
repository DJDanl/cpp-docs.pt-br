---
title: "Classe de CMFCDropDownFrame | Microsoft Docs"
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
  - "CMFCDropDownFrame"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDropDownFrame"
ms.assetid: 09ff81a9-de00-43ec-9df9-b626f7728c4b
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDropDownFrame
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece funcionalidade suspenso da janela do quadro às barras de ferramentas e lista os botões da barra de ferramentas lista.  
  
## Sintaxe  
  
```  
class CMFCDropDownFrame : public CMiniFrameWnd  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCDropDownFrame::CMFCDropDownFrame`|Construtor padrão.|  
|`CMFCDropDownFrame::~CMFCDropDownFrame`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCDropDownFrame::Create](../Topic/CMFCDropDownFrame::Create.md)|Cria um objeto de `CMFCDropDownFrame` .|  
|`CMFCDropDownFrame::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CMFCDropDownFrame::GetParentMenuBar](../Topic/CMFCDropDownFrame::GetParentMenuBar.md)|Recupera a barra de menu pai do quadro suspenso.|  
|[CMFCDropDownFrame::GetParentPopupMenu](../Topic/CMFCDropDownFrame::GetParentPopupMenu.md)|Recupera o menu pop\-up pai do quadro suspenso.|  
|`CMFCDropDownFrame::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCDropDownFrame::RecalcLayout](../Topic/CMFCDropDownFrame::RecalcLayout.md)|Reposiciona o quadro suspenso.|  
|[CMFCDropDownFrame::SetAutoDestroy](../Topic/CMFCDropDownFrame::SetAutoDestroy.md)|Define se a janela lista suspensa filho da barra de ferramentas é automaticamente destruída.|  
  
### Comentários  
 Esta classe não se destina a ser usada diretamente do seu código.  
  
 A estrutura usar esta classe para fornecer um comportamento do quadro a classes de `CMFCDropDownToolbar` e de `CMFCDropDownToolbarButton` .  Para obter mais informações sobre essas classes, consulte [Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md) e [Classe de CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como recuperar um ponteiro para um objeto de `CMFCDropDownFrame` de uma classe de `CFrameWnd` , e como definir a janela lista suspensa filho da barra de ferramentas seja destruída automaticamente.  
  
 [!code-cpp[NVC_MFC_RibbonApp#36](../../mfc/reference/codesnippet/CPP/cmfcdropdownframe-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)  
  
 [CMFCDropDownFrame](../../mfc/reference/cmfcdropdownframe-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxdropdowntoolbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Classe de CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)