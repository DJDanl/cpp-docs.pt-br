---
title: "Classe de CMFCBaseToolBar | Microsoft Docs"
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
  - "CMFCBaseToolBar::CreateObject"
  - "~CMFCBaseToolBar"
  - "CMFCBaseToolBar"
  - "CMFCBaseToolBar::CMFCBaseToolBar"
  - "CMFCBaseToolBar::~CMFCBaseToolBar"
  - "CMFCBaseToolBar.~CMFCBaseToolBar"
  - "CreateObject"
  - "CMFCBaseToolBar.CMFCBaseToolBar"
  - "CMFCBaseToolBar.CreateObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Destruidor ~CMFCBaseToolBar"
  - "Classe de CMFCBaseToolBar"
  - "Classe de CMFCBaseToolBar, construtor"
  - "Classe de CMFCBaseToolBar, destruidor"
  - "Método de CreateObject"
ms.assetid: 5d79206d-55e4-46f8-b1b8-042e34d7f9da
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCBaseToolBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Classe base para barras de ferramentas.  
  
## Sintaxe  
  
```  
class CMFCBaseToolBar : public CPane  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCBaseToolBar::CMFCBaseToolBar`|Construtor padrão.|  
|`CMFCBaseToolBar::~CMFCBaseToolBar`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCBaseToolBar::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CMFCBaseToolBar::GetDockingMode](../Topic/CMFCBaseToolBar::GetDockingMode.md)|Retorna o modo de encaixe.  Overrides \( [CBasePane::GetDockingMode](../Topic/CBasePane::GetDockingMode.md).\)|  
|[CMFCBaseToolBar::GetMinSize](../Topic/CMFCBaseToolBar::GetMinSize.md)|Retorna o tamanho mínimo de uma barra de ferramentas.  Overrides \( [CPane::GetMinSize](../Topic/CPane::GetMinSize.md).\)|  
|[CMFCBaseToolBar::OnAfterChangeParent](../Topic/CMFCBaseToolBar::OnAfterChangeParent.md)|Chamado pela estrutura após o pai do painel muda.  Overrides \( [CBasePane::OnAfterChangeParent](../Topic/CBasePane::OnAfterChangeParent.md).\)|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxbasetoolbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)