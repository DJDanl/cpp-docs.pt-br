---
title: "Classe de CDockingPanesRow | Microsoft Docs"
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
  - "CDockingPanesRow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDockingPanesRow"
ms.assetid: e7a17832-0ebb-4bce-b799-cec9b60f76fe
caps.latest.revision: 25
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDockingPanesRow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia uma lista de painéis que estão localizados na mesma horizontal ou vertical linha \(coluna\) de um site de encaixe.  
  
## Sintaxe  
  
```  
class CDockingPanesRow : public CObject  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CDockingPanesRow::CDockingPanesRow`|Construtor padrão.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockingPanesRow::AddPane](../Topic/CDockingPanesRow::AddPane.md)||  
|[CDockingPanesRow::AddPaneFromRow](../Topic/CDockingPanesRow::AddPaneFromRow.md)||  
|[CDockingPanesRow::ArrangePanes](../Topic/CDockingPanesRow::ArrangePanes.md)|Organiza os painéis em uma linha de acordo com os parâmetros de espaçamento e margem especificada.|  
|[CDockingPanesRow::CalcFixedLayout](../Topic/CDockingPanesRow::CalcFixedLayout.md)||  
|[CDockingPanesRow::Create](../Topic/CDockingPanesRow::Create.md)||  
|[CDockingPanesRow::ExpandStretchedPanes](../Topic/CDockingPanesRow::ExpandStretchedPanes.md)||  
|[CDockingPanesRow::ExpandStretchedPanesRect](../Topic/CDockingPanesRow::ExpandStretchedPanesRect.md)||  
|[CDockingPanesRow::FixupVirtualRects](../Topic/CDockingPanesRow::FixupVirtualRects.md)||  
|[CDockingPanesRow::GetAvailableLength](../Topic/CDockingPanesRow::GetAvailableLength.md)||  
|[CDockingPanesRow::GetAvailableSpace](../Topic/CDockingPanesRow::GetAvailableSpace.md)||  
|[CDockingPanesRow::GetClientRect](../Topic/CDockingPanesRow::GetClientRect.md)||  
|[CDockingPanesRow::GetDockSite](../Topic/CDockingPanesRow::GetDockSite.md)||  
|[CDockingPanesRow::GetExtraSpace](../Topic/CDockingPanesRow::GetExtraSpace.md)||  
|[CDockingPanesRow::GetGroupFromPane](../Topic/CDockingPanesRow::GetGroupFromPane.md)||  
|[CDockingPanesRow::GetID](../Topic/CDockingPanesRow::GetID.md)||  
|[CDockingPanesRow::GetMaxPaneSize](../Topic/CDockingPanesRow::GetMaxPaneSize.md)||  
|[CDockingPanesRow::GetPaneCount](../Topic/CDockingPanesRow::GetPaneCount.md)||  
|[CDockingPanesRow::GetPaneList](../Topic/CDockingPanesRow::GetPaneList.md)||  
|[CDockingPanesRow::GetRowAlignment](../Topic/CDockingPanesRow::GetRowAlignment.md)||  
|[CDockingPanesRow::GetRowHeight](../Topic/CDockingPanesRow::GetRowHeight.md)||  
|[CDockingPanesRow::GetRowOffset](../Topic/CDockingPanesRow::GetRowOffset.md)||  
|[CDockingPanesRow::GetVisibleCount](../Topic/CDockingPanesRow::GetVisibleCount.md)||  
|[CDockingPanesRow::GetWindowRect](../Topic/CDockingPanesRow::GetWindowRect.md)||  
|[CDockingPanesRow::HasPane](../Topic/CDockingPanesRow::HasPane.md)||  
|[CDockingPanesRow::IsEmpty](../Topic/CDockingPanesRow::IsEmpty.md)||  
|[CDockingPanesRow::IsExclusiveRow](../Topic/CDockingPanesRow::IsExclusiveRow.md)||  
|[CDockingPanesRow::IsHorizontal](../Topic/CDockingPanesRow::IsHorizontal.md)||  
|[CDockingPanesRow::IsVisible](../Topic/CDockingPanesRow::IsVisible.md)||  
|[CDockingPanesRow::Move](../Topic/CDockingPanesRow::Move.md)||  
|[CDockingPanesRow::MovePane](../Topic/CDockingPanesRow::MovePane.md)||  
|[CDockingPanesRow::OnResizePane](../Topic/CDockingPanesRow::OnResizePane.md)||  
|[CDockingPanesRow::RedrawAll](../Topic/CDockingPanesRow::RedrawAll.md)||  
|[CDockingPanesRow::RemovePane](../Topic/CDockingPanesRow::RemovePane.md)||  
|[CDockingPanesRow::ReplacePane](../Topic/CDockingPanesRow::ReplacePane.md)||  
|[CDockingPanesRow::RepositionPanes](../Topic/CDockingPanesRow::RepositionPanes.md)||  
|[CDockingPanesRow::Resize](../Topic/CDockingPanesRow::Resize.md)||  
|[CDockingPanesRow::ResizeByPaneDivider](../Topic/CDockingPanesRow::ResizeByPaneDivider.md)||  
|[CDockingPanesRow::ScreenToClient](../Topic/CDockingPanesRow::ScreenToClient.md)||  
|[CDockingPanesRow::SetExtra](../Topic/CDockingPanesRow::SetExtra.md)||  
|[CDockingPanesRow::ShowDockSiteRow](../Topic/CDockingPanesRow::ShowDockSiteRow.md)||  
|[CDockingPanesRow::ShowPane](../Topic/CDockingPanesRow::ShowPane.md)||  
|[CDockingPanesRow::UpdateVisibleState](../Topic/CDockingPanesRow::UpdateVisibleState.md)||  
  
## Comentários  
 `CDockingPanesRow` objetos são criados internamente por objetos de site de encaixe.  
  
## Exemplo  
 O exemplo a seguir demonstra como obter um `CDockingPanesRow` do objeto de uma `CMFCAutoHideBar` objeto.  
  
 [!code-cpp[NVC_MFC_RibbonApp#26](../../mfc/reference/codesnippet/CPP/cdockingpanesrow-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDockingPanesRow](../../mfc/reference/cdockingpanesrow-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDockingPanesRow.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Classe de CDockSite](../../mfc/reference/cdocksite-class.md)   
 [Classe de CPane](../../mfc/reference/cpane-class.md)