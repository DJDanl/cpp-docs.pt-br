---
title: "Classe de CAutoHideDockSite | Microsoft Docs"
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
  - "CAutoHideDockSite"
  - "AllowShowOnPaneMenu"
  - "CAutoHideDockSite::AllowShowOnPaneMenu"
  - "CAutoHideDockSite.AllowShowOnPaneMenu"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de AllowShowOnPaneMenu"
  - "Classe de CAutoHideDockSite"
ms.assetid: 2a0f6bec-c369-4ab7-977d-564e7946ebad
caps.latest.revision: 32
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoHideDockSite
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CAutoHideDockSite` estende [Classe de CDockSite](../../mfc/reference/cdocksite-class.md) para implementar os painéis de automática ocultar à.  
  
## Sintaxe  
  
```  
class CAutoHideDockSite : public CDockSite  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CAutoHideDockSite::CAutoHideDockSite`|Constrói um objeto de `CAutoHideDockSite` .|  
|`CAutoHideDockSite::~CAutoHideDockSite`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CAutoHideDockSite::AllowShowOnPaneMenu`|Indica se `CAutoHideDockSite` é mostrado no menu do painel.|  
|[CAutoHideDockSite::CanAcceptPane](../Topic/CAutoHideDockSite::CanAcceptPane.md)|Determina se um objeto base do painel é derivado de [Classe de CMFCAutoHideBar](../Topic/CMFCAutoHideBar%20Class.md).|  
|[CAutoHideDockSite::DockPane](../Topic/CAutoHideDockSite::DockPane.md)|Insere um painel para este objeto de `CAuotHideDockSite` .|  
|[CAutoHideDockSite::GetAlignRect](../Topic/CAutoHideDockSite::GetAlignRect.md)|Retorna o tamanho do site da plataforma em coordenadas da tela.|  
|[CAutoHideDockSite::RepositionPanes](../Topic/CAutoHideDockSite::RepositionPanes.md)|Redesenho no painel `CAutoHideDockSite` com as margens e espaçamento globais do botão.|  
|[CAutoHideDockSite::SetOffsetLeft](../Topic/CAutoHideDockSite::SetOffsetLeft.md)|Define a margem no lado esquerdo da barra de encaixe.|  
|[CAutoHideDockSite::SetOffsetRight](../Topic/CAutoHideDockSite::SetOffsetRight.md)|Define a margem no lado direito da barra de encaixe.|  
|[CAutoHideDockSite::UnSetAutoHideMode](../Topic/CAutoHideDockSite::UnSetAutoHideMode.md)|Chamadas [CMFCAutoHideBar::UnSetAutoHideMode](../Topic/CMFCAutoHideBar::UnSetAutoHideMode.md) para objetos em `CAutoHideDockSite`.|  
  
### Membros de dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CAutoHideDockSite::m\_nExtraSpace](../Topic/CAutoHideDockSite::m_nExtraSpace.md)|Define o tamanho do espaço entre as barras de ferramentas e a borda da barra de encaixe.  Este espaço é medido da borda esquerda ou a borda superior, como o alinhamento para o espaço da plataforma.|  
  
## Comentários  
 Quando você chama [CFrameWndEx::EnableAutoHidePanes](../Topic/CFrameWndEx::EnableAutoHidePanes.md), a estrutura automaticamente cria um objeto de `CAutoHideDockSite` .  Em a maioria dos casos, você não deve ter que criar uma instância diretamente ou usar esta classe.  
  
 A barra de encaixe é o intervalo entre o lado esquerdo do painel dock e o lado esquerdo de [Classe de CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CDockSite](../../mfc/reference/cdocksite-class.md)  
  
## Exemplo  
 O exemplo a seguir demonstra como recuperar um objeto de `CAutoHideDockSite` de um objeto de `CMFCAutoHideBar` , e como definir as margens esquerda e direita da barra de encaixe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#29](../../mfc/reference/codesnippet/CPP/cautohidedocksite-class_1.cpp)]  
  
## Requisitos  
 **Cabeçalho:** afxautohidedocksite.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockSite](../../mfc/reference/cdocksite-class.md)