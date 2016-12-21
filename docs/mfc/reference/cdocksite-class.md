---
title: "Classe de CDockSite | Microsoft Docs"
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
  - "CDockSite"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDockSite"
ms.assetid: 0fcfff79-5f50-4281-b2de-a55653bbea40
caps.latest.revision: 28
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDockSite
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 Fornece funcionalidade para organizar painéis que derivam de [Classe de CPane](../../mfc/reference/cpane-class.md) em conjuntos de linhas.  
  
## Sintaxe  
  
```  
class CDockSite: public CBasePane  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockSite::AddRow](../Topic/CDockSite::AddRow.md)||  
|[CDockSite::AdjustDockingLayout](../Topic/CDockSite::AdjustDockingLayout.md)|\(Substitui [CBasePane::AdjustDockingLayout](../Topic/CBasePane::AdjustDockingLayout.md).\)|  
|[CDockSite::AdjustLayout](../Topic/CDockSite::AdjustLayout.md)|\(Substitui [CBasePane::AdjustLayout](../Topic/CBasePane::AdjustLayout.md).\)|  
|[CDockSite::AlignDockSite](../Topic/CDockSite::AlignDockSite.md)||  
|[CDockSite::CalcFixedLayout](../Topic/CDockSite::CalcFixedLayout.md)|\(Substitui [CBasePane::CalcFixedLayout](../Topic/CBasePane::CalcFixedLayout.md).\)|  
|[CDockSite::CanAcceptPane](../Topic/CDockSite::CanAcceptPane.md)|\(Substitui [CBasePane::CanAcceptPane](../Topic/CBasePane::CanAcceptPane.md).\)|  
|[CDockSite::CreateEx](../Topic/CDockSite::CreateEx.md)|\(Substitui [CBasePane::CreateEx](../Topic/CBasePane::CreateEx.md).\)|  
|[CDockSite::CreateRow](../Topic/CDockSite::CreateRow.md)||  
|[CDockSite::DockPane](../Topic/CDockSite::DockPane.md)|\(Substitui [CBasePane::DockPane](../Topic/CBasePane::DockPane.md).\)|  
|[CDockSite::DoesAllowDynInsertBefore](../Topic/CDockSite::DoesAllowDynInsertBefore.md)|\(Substitui [CBasePane::DoesAllowDynInsertBefore](../Topic/CBasePane::DoesAllowDynInsertBefore.md).\)|  
|[CDockSite::FindRowIndex](../Topic/CDockSite::FindRowIndex.md)||  
|[CDockSite::FixupVirtualRects](../Topic/CDockSite::FixupVirtualRects.md)||  
|[CDockSite::GetDockSiteID](../Topic/CDockSite::GetDockSiteID.md)||  
|[CDockSite::GetDockSiteRowsList](../Topic/CDockSite::GetDockSiteRowsList.md)||  
|[CDockSite::IsAccessibilityCompatible](../Topic/CDockSite::IsAccessibilityCompatible.md)|\(Substitui `CBasePane::IsAccessibilityCompatible`.\)|  
|[CDockSite::IsDragMode](../Topic/CDockSite::IsDragMode.md)||  
|[CDockSite::IsLastRow](../Topic/CDockSite::IsLastRow.md)||  
|[CDockSite::IsRectWithinDockSite](../Topic/CDockSite::IsRectWithinDockSite.md)||  
|[CDockSite::IsResizable](../Topic/CDockSite::IsResizable.md)|\(Substitui [CBasePane::IsResizable](../Topic/CBasePane::IsResizable.md).\)|  
|[CDockSite::MovePane](../Topic/CDockSite::MovePane.md)||  
|[CDockSite::OnInsertRow](../Topic/CDockSite::OnInsertRow.md)||  
|[CDockSite::OnRemoveRow](../Topic/CDockSite::OnRemoveRow.md)||  
|[CDockSite::OnResizeRow](../Topic/CDockSite::OnResizeRow.md)||  
|[CDockSite::OnSetWindowPos](../Topic/CDockSite::OnSetWindowPos.md)||  
|[CDockSite::OnShowRow](../Topic/CDockSite::OnShowRow.md)||  
|[CDockSite::OnSizeParent](../Topic/CDockSite::OnSizeParent.md)||  
|[CDockSite::PaneFromPoint](../Topic/CDockSite::PaneFromPoint.md)|Retorna um painel encaixado no site de encaixe no ponto especificado pelo parâmetro determinado.|  
|[CDockSite::DockPaneLeftOf](../Topic/CDockSite::DockPaneLeftOf.md)|Encaixa um painel à esquerda do outro painel.|  
|[CDockSite::FindPaneByID](../Topic/CDockSite::FindPaneByID.md)|Retorna o painel é identificado pela ID especificada.|  
|[CDockSite::GetPaneList](../Topic/CDockSite::GetPaneList.md)|Retorna uma lista de painéis são encaixados no local de encaixe.|  
|[CDockSite::RectSideFromPoint](../Topic/CDockSite::RectSideFromPoint.md)||  
|[CDockSite::RemovePane](../Topic/CDockSite::RemovePane.md)||  
|[CDockSite::RemoveRow](../Topic/CDockSite::RemoveRow.md)||  
|[CDockSite::ReplacePane](../Topic/CDockSite::ReplacePane.md)||  
|[CDockSite::RepositionPanes](../Topic/CDockSite::RepositionPanes.md)||  
|[CDockSite::ResizeDockSite](../Topic/CDockSite::ResizeDockSite.md)||  
|[CDockSite::ResizeRow](../Topic/CDockSite::ResizeRow.md)||  
|[CDockSite::ShowPane](../Topic/CDockSite::ShowPane.md)|Mostra o painel.|  
|[CDockSite::ShowRow](../Topic/CDockSite::ShowRow.md)||  
|[CDockSite::SwapRows](../Topic/CDockSite::SwapRows.md)||  
  
## Comentários  
 O framework cria `CDockSite` objetos automaticamente quando você chama [CFrameWndEx::EnableDocking](../Topic/CFrameWndEx::EnableDocking.md).  Encaixar janelas de site são posicionadas na borda da área do cliente na janela principal do quadro.  
  
 Você geralmente não precisa chamar os serviços fornecidos pelo site de encaixe porque [Classe de CFrameWndEx](../../mfc/reference/cframewndex-class.md) lida com esses serviços.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CDockSite` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#27](../../mfc/reference/codesnippet/CPP/cdocksite-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md) [CCmdTarget](../Topic/CCmdTarget%20Class.md) [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md) [CDockSite](../../mfc/reference/cdocksite-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDockSite.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CBasePane](../../mfc/reference/cbasepane-class.md)