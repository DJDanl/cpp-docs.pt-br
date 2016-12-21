---
title: "Classe de CPaneDivider | Microsoft Docs"
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
  - "CPaneDivider"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPaneDivider"
ms.assetid: 8e828a5d-232f-4127-b8e3-7fa45a7a476e
caps.latest.revision: 25
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPaneDivider
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 A classe de `CPaneDivider` divide dois painéis, divide dois grupos de painéis, ou separa um grupo de painéis da área cliente da janela de quadro chave.  
  
## Sintaxe  
  
```  
class CPaneDivider : public CBasePane  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneDivider::CPaneDivider](../Topic/CPaneDivider::CPaneDivider.md)||  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneDivider::AddPaneContainer](../Topic/CPaneDivider::AddPaneContainer.md)||  
|[CPaneDivider::AddPane](../Topic/CPaneDivider::AddPane.md)||  
|[CPaneDivider::AddRecentPane](../Topic/CPaneDivider::AddRecentPane.md)||  
|[CPaneDivider::CalcExpectedDockedRect](../Topic/CPaneDivider::CalcExpectedDockedRect.md)||  
|[CPaneDivider::CalcFixedLayout](../Topic/CPaneDivider::CalcFixedLayout.md)|Overrides \( [CBasePane::CalcFixedLayout](../Topic/CBasePane::CalcFixedLayout.md).\)|  
|[CPaneDivider::CheckVisibility](../Topic/CPaneDivider::CheckVisibility.md)||  
|[CPaneDivider::CreateEx](../Topic/CPaneDivider::CreateEx.md)|Overrides \( [CBasePane::CreateEx](../Topic/CBasePane::CreateEx.md).\)|  
|[CPaneDivider::DoesAllowDynInsertBefore](../Topic/CPaneDivider::DoesAllowDynInsertBefore.md)|Overrides \( [CBasePane::DoesAllowDynInsertBefore](../Topic/CBasePane::DoesAllowDynInsertBefore.md).\)|  
|[CPaneDivider::DoesContainFloatingPane](../Topic/CPaneDivider::DoesContainFloatingPane.md)||  
|[CPaneDivider::FindPaneContainer](../Topic/CPaneDivider::FindPaneContainer.md)||  
|[CPaneDivider::FindTabbedPane](../Topic/CPaneDivider::FindTabbedPane.md)||  
|[CPaneDivider::GetDefaultWidth](../Topic/CPaneDivider::GetDefaultWidth.md)||  
|[CPaneDivider::GetFirstPane](../Topic/CPaneDivider::GetFirstPane.md)||  
|[CPaneDivider::GetPaneDividerStyle](../Topic/CPaneDivider::GetPaneDividerStyle.md)||  
|[CPaneDivider::GetRootContainerRect](../Topic/CPaneDivider::GetRootContainerRect.md)||  
|[CPaneDivider::GetWidth](../Topic/CPaneDivider::GetWidth.md)||  
|[CPaneDivider::Init](../Topic/CPaneDivider::Init.md)||  
|[CPaneDivider::InsertPane](../Topic/CPaneDivider::InsertPane.md)||  
|[CPaneDivider::IsAutoHideMode](../Topic/CPaneDivider::IsAutoHideMode.md)|Overrides \( [CBasePane::IsAutoHideMode](../Topic/CBasePane::IsAutoHideMode.md).\)|  
|[CPaneDivider::IsDefault](../Topic/CPaneDivider::IsDefault.md)||  
|[CPaneDivider::IsHorizontal](../Topic/CPaneDivider::IsHorizontal.md)|Overrides \( [CBasePane::IsHorizontal](../Topic/CBasePane::IsHorizontal.md).\)|  
|[CPaneDivider::Move](../Topic/CPaneDivider::Move.md)||  
|[CPaneDivider::NotifyAboutRelease](../Topic/CPaneDivider::NotifyAboutRelease.md)||  
|[CPaneDivider::OnShowPane](../Topic/CPaneDivider::OnShowPane.md)||  
|[CPaneDivider::ReleaseEmptyPaneContainers](../Topic/CPaneDivider::ReleaseEmptyPaneContainers.md)||  
|[CPaneDivider::RemovePane](../Topic/CPaneDivider::RemovePane.md)||  
|[CPaneDivider::ReplacePane](../Topic/CPaneDivider::ReplacePane.md)||  
|[CPaneDivider::RepositionPanes](../Topic/CPaneDivider::RepositionPanes.md)||  
|[CPaneDivider::Serialize](../Topic/CPaneDivider::Serialize.md)|Overrides \( `CBasePane::Serialize`.\)|  
|[CPaneDivider::SetAutoHideMode](../Topic/CPaneDivider::SetAutoHideMode.md)||  
|[CPaneDivider::SetPaneContainerManager](../Topic/CPaneDivider::SetPaneContainerManager.md)||  
|[CPaneDivider::ShowWindow](../Topic/CPaneDivider::ShowWindow.md)||  
|[CPaneDivider::StoreRecentDockSiteInfo](../Topic/CPaneDivider::StoreRecentDockSiteInfo.md)||  
|[CPaneDivider::StoreRecentTabRelatedInfo](../Topic/CPaneDivider::StoreRecentTabRelatedInfo.md)||  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneDivider::GetPanes](../Topic/CPaneDivider::GetPanes.md)|Retorna a lista de painéis que residem em [Classe de CPaneContainer](../../mfc/reference/cpanecontainer-class.md).  Esse método deve ser chamado somente para divisores padrão do painel.|  
|[CPaneDivider::GetPaneDividers](../Topic/CPaneDivider::GetPaneDividers.md)|Retorna a lista de divisores de painel que residem em [Classe de CPaneContainer](../../mfc/reference/cpanecontainer-class.md).  Esse método deve ser chamado somente para divisores padrão do painel.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneDivider::m\_nDefaultWidth](../Topic/CPaneDivider::m_nDefaultWidth.md)|Especifica a largura em pixels padrão de todos os divisores do painel no aplicativo.|  
|[CPaneDivider::m\_pSliderRTC](../Topic/CPaneDivider::m_pSliderRTC.md)|Contém um ponteiro para informações sobre `CPaneDivider`objeto derivado da classe de tempo de execução.|  
  
## Comentários  
 A estrutura cria objetos de `CPaneDivider` automaticamente quando um painel é conectado.  
  
 Há dois tipos de divisores do painel:  
  
-   um divisor padrão do painel é criado quando um grupo de painéis está conectado a um lado da janela do quadro chave.  O divisor padrão do painel contém um ponteiro para [Classe de CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) e redireciona a maioria das operações no grupo de painéis \(como redimensionar um painel, ou o encaixe de outro painel ou contêiner\) para o gerenciador de contêiner.  Cada painel de encaixe mantém um ponteiro ao divisor padrão do painel.  
  
-   Um divisor normal do painel divide apenas dois painéis em um contêiner.  Para mais informações, consulte [Classe de CPaneContainer](../../mfc/reference/cpanecontainer-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como obter um objeto de `CPaneDivider` de um objeto de `CWorkspaceBar` .  Este trecho de código é parte de [Exemplo de demonstração de guias MDI](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo#5](../../mfc/reference/codesnippet/CPP/cpanedivider-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md) [CCmdTarget](../Topic/CCmdTarget%20Class.md) [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md) [CPaneDivider](../../mfc/reference/cpanedivider-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxPaneDivider.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md)   
 [Classe de CPaneContainer](../../mfc/reference/cpanecontainer-class.md)   
 [Classe de CDockingManager](../../mfc/reference/cdockingmanager-class.md)   
 [Classe de CBasePane](../../mfc/reference/cbasepane-class.md)