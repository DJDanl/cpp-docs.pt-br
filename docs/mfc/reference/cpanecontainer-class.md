---
title: "Classe de CPaneContainer | Microsoft Docs"
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
  - "CPaneContainer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPaneContainer"
ms.assetid: beb79e08-f611-4d66-ba04-053baa79bf86
caps.latest.revision: 32
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPaneContainer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CPaneContainer` é um componente básico de modelo de encaixe implementado pelo MFC.  Um objeto de essa classe armazena ponteiros para dois painéis de encaixe ou a duas instâncias de `CPaneContainer.` também armazena um ponteiro para o divisor que separa os painéis \(ou contêineres\).  Aninhando contêiner dentro de contêineres, a estrutura pode criar uma árvore binária que representa layouts complexos de encaixe.  A raiz da árvore de binária é armazenada em um objeto de [CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) .  
  
## Sintaxe  
  
```  
class CPaneContainer : public CObject    
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneContainer::CPaneContainer](../Topic/CPaneContainer::CPaneContainer.md)|Construtor padrão.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneContainer::AddPane](../Topic/CPaneContainer::AddPane.md)||  
|[CPaneContainer::AddRef](../Topic/CPaneContainer::AddRef.md)||  
|[CPaneContainer::AddSubPaneContainer](../Topic/CPaneContainer::AddSubPaneContainer.md)||  
|[CPaneContainer::CalcAvailablePaneSpace](../Topic/CPaneContainer::CalcAvailablePaneSpace.md)||  
|[CPaneContainer::CalcAvailableSpace](../Topic/CPaneContainer::CalcAvailableSpace.md)||  
|[CPaneContainer::CalculateRecentSize](../Topic/CPaneContainer::CalculateRecentSize.md)||  
|[CPaneContainer::CheckPaneDividerVisibility](../Topic/CPaneContainer::CheckPaneDividerVisibility.md)||  
|[CPaneContainer::Copy](../Topic/CPaneContainer::Copy.md)||  
|[CPaneContainer::DeletePane](../Topic/CPaneContainer::DeletePane.md)||  
|[CPaneContainer::FindSubPaneContainer](../Topic/CPaneContainer::FindSubPaneContainer.md)||  
|[CPaneContainer::FindTabbedPane](../Topic/CPaneContainer::FindTabbedPane.md)||  
|[CPaneContainer::GetAssociatedSiblingPaneIDs](../Topic/CPaneContainer::GetAssociatedSiblingPaneIDs.md)||  
|[CPaneContainer::GetLeftPane](../Topic/CPaneContainer::GetLeftPane.md)||  
|[CPaneContainer::GetLeftPaneContainer](../Topic/CPaneContainer::GetLeftPaneContainer.md)||  
|[CPaneContainer::GetMinSize](../Topic/CPaneContainer::GetMinSize.md)||  
|[CPaneContainer::GetMinSizeLeft](../Topic/CPaneContainer::GetMinSizeLeft.md)||  
|[CPaneContainer::GetMinSizeRight](../Topic/CPaneContainer::GetMinSizeRight.md)||  
|[CPaneContainer::GetNodeCount](../Topic/CPaneContainer::GetNodeCount.md)||  
|[CPaneContainer::GetPaneDivider](../Topic/CPaneContainer::GetPaneDivider.md)||  
|[CPaneContainer::GetParentPaneContainer](../Topic/CPaneContainer::GetParentPaneContainer.md)||  
|[CPaneContainer::GetRecentPaneDividerRect](../Topic/CPaneContainer::GetRecentPaneDividerRect.md)||  
|[CPaneContainer::GetRecentPaneDividerStyle](../Topic/CPaneContainer::GetRecentPaneDividerStyle.md)||  
|[CPaneContainer::GetRecentPercent](../Topic/CPaneContainer::GetRecentPercent.md)||  
|[CPaneContainer::GetRefCount](../Topic/CPaneContainer::GetRefCount.md)||  
|[CPaneContainer::GetResizeStep](../Topic/CPaneContainer::GetResizeStep.md)||  
|[CPaneContainer::GetRightPane](../Topic/CPaneContainer::GetRightPane.md)||  
|[CPaneContainer::GetRightPaneContainer](../Topic/CPaneContainer::GetRightPaneContainer.md)||  
|[CPaneContainer::GetTotalReferenceCount](../Topic/CPaneContainer::GetTotalReferenceCount.md)||  
|[CPaneContainer::GetWindowRect](../Topic/CPaneContainer::GetWindowRect.md)||  
|[CPaneContainer::IsDisposed](../Topic/CPaneContainer::IsDisposed.md)||  
|[CPaneContainer::IsEmpty](../Topic/CPaneContainer::IsEmpty.md)||  
|[CPaneContainer::IsLeftPane](../Topic/CPaneContainer::IsLeftPane.md)||  
|[CPaneContainer::IsLeftPaneContainer](../Topic/CPaneContainer::IsLeftPaneContainer.md)||  
|[CPaneContainer::IsLeftPartEmpty](../Topic/CPaneContainer::IsLeftPartEmpty.md)||  
|[CPaneContainer::IsRightPartEmpty](../Topic/CPaneContainer::IsRightPartEmpty.md)||  
|[CPaneContainer::IsVisible](../Topic/CPaneContainer::IsVisible.md)||  
|[CPaneContainer::Move](../Topic/CPaneContainer::Move.md)||  
|[CPaneContainer::OnDeleteHidePane](../Topic/CPaneContainer::OnDeleteHidePane.md)||  
|[CPaneContainer::OnMoveInternalPaneDivider](../Topic/CPaneContainer::OnMoveInternalPaneDivider.md)||  
|[CPaneContainer::OnShowPane](../Topic/CPaneContainer::OnShowPane.md)||  
|[CPaneContainer::Release](../Topic/CPaneContainer::Release.md)||  
|[CPaneContainer::ReleaseEmptyPaneContainer](../Topic/CPaneContainer::ReleaseEmptyPaneContainer.md)||  
|[CPaneContainer::RemoveNonValidPanes](../Topic/CPaneContainer::RemoveNonValidPanes.md)||  
|[CPaneContainer::RemovePane](../Topic/CPaneContainer::RemovePane.md)||  
|[CPaneContainer::Resize](../Topic/CPaneContainer::Resize.md)||  
|[CPaneContainer::ResizePane](../Topic/CPaneContainer::ResizePane.md)||  
|[CPaneContainer::ResizePartOfPaneContainer](../Topic/CPaneContainer::ResizePartOfPaneContainer.md)||  
|[CPaneContainer::Serialize](../Topic/CPaneContainer::Serialize.md)|Leitura ou grava este objeto ou um arquivo neutro.  Overrides \( [CObject::Serialize](../Topic/CObject::Serialize.md).\)|  
|[CPaneContainer::SetPane](../Topic/CPaneContainer::SetPane.md)||  
|[CPaneContainer::SetPaneContainer](../Topic/CPaneContainer::SetPaneContainer.md)||  
|[CPaneContainer::SetPaneDivider](../Topic/CPaneContainer::SetPaneDivider.md)||  
|[CPaneContainer::SetParentPaneContainer](../Topic/CPaneContainer::SetParentPaneContainer.md)||  
|[CPaneContainer::SetRecentPercent](../Topic/CPaneContainer::SetRecentPercent.md)||  
|[CPaneContainer::SetUpByID](../Topic/CPaneContainer::SetUpByID.md)||  
|[CPaneContainer::StoreRecentDockSiteInfo](../Topic/CPaneContainer::StoreRecentDockSiteInfo.md)||  
|[CPaneContainer::StretchPaneContainer](../Topic/CPaneContainer::StretchPaneContainer.md)||  
  
### Comentários  
 Os objetos de`CPaneContainer` são criados automaticamente pela estrutura.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar uma instância da classe de `CPaneContainer` .  Este trecho de código é parte de [Defina o tamanho do painel de exemplo](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_SetPaneSize#2](../../mfc/reference/codesnippet/CPP/cpanecontainer-class_1.h)]  
[!code-cpp[NVC_MFC_SetPaneSize#1](../../mfc/reference/codesnippet/CPP/cpanecontainer-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CPaneContainer](../../mfc/reference/cpanecontainer-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpanecontainer.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Classe de CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md)