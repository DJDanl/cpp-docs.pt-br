---
title: "Classe de CMultiPaneFrameWnd | Microsoft Docs"
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
  - "CMultiPaneFrameWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMultiPaneFrameWnd"
ms.assetid: 989a548e-0d70-46b7-a513-8cf740e1be3e
caps.latest.revision: 36
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMultiPaneFrameWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a classe de `CMultiPaneFrameWnd` estende [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).  Pode suportar vários painéis.  Em vez de uma única identificador inserido em uma barra de controle, `CMultiPaneFrameWnd` contém um objeto que permite ao usuário para inserir um `CMultiPaneFrameWnd` a outra e para criar dinamicamente a vários flutuantes o windows, com guias de [Classe de CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) .  
  
## Sintaxe  
  
```  
class CMultiPaneFrameWnd : public CPaneFrameWnd  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMultiPaneFrameWnd::AddPane](../Topic/CMultiPaneFrameWnd::AddPane.md)|Adiciona um painel.  Overrides \( [CPaneFrameWnd::AddPane](../Topic/CPaneFrameWnd::AddPane.md).\)|  
|[CMultiPaneFrameWnd::AddRecentPane](../Topic/CMultiPaneFrameWnd::AddRecentPane.md)||  
|[CMultiPaneFrameWnd::AdjustLayout](../Topic/CMultiPaneFrameWnd::AdjustLayout.md)|Ajustar o layout da janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::AdjustLayout](../Topic/CPaneFrameWnd::AdjustLayout.md).\)|  
|[CMultiPaneFrameWnd::AdjustPaneFrames](../Topic/CMultiPaneFrameWnd::AdjustPaneFrames.md)|Overrides \( [CPaneFrameWnd::AdjustPaneFrames](../Topic/CPaneFrameWnd::AdjustPaneFrames.md).\)|  
|[CMultiPaneFrameWnd::CalcExpectedDockedRect](../Topic/CMultiPaneFrameWnd::CalcExpectedDockedRect.md)|Calcula o retângulo esperado de uma janela entrada.  Overrides \( [CPaneFrameWnd::CalcExpectedDockedRect](../Topic/CPaneFrameWnd::CalcExpectedDockedRect.md).\)|  
|[CMultiPaneFrameWnd::CanBeAttached](../Topic/CMultiPaneFrameWnd::CanBeAttached.md)|Determina se o painel atual pode inserir a outra janela do painel ou quadro.  Overrides \( [CPaneFrameWnd::CanBeAttached](../Topic/CPaneFrameWnd::CanBeAttached.md).\)|  
|[CMultiPaneFrameWnd::CanBeDockedToPane](../Topic/CMultiPaneFrameWnd::CanBeDockedToPane.md)|Determina se a janela de mini\-linguagem quadro pode encaixar um painel.  Overrides \( [CPaneFrameWnd::CanBeDockedToPane](../Topic/CPaneFrameWnd::CanBeDockedToPane.md).\)|  
|[CMultiPaneFrameWnd::CheckGripperVisibility](../Topic/CMultiPaneFrameWnd::CheckGripperVisibility.md)|Overrides \( [CPaneFrameWnd::CheckGripperVisibility](../Topic/CPaneFrameWnd::CheckGripperVisibility.md).\)|  
|[CMultiPaneFrameWnd::CloseMiniFrame](../Topic/CMultiPaneFrameWnd::CloseMiniFrame.md)|Overrides \( `CPaneFrameWnd::CloseMiniFrame`.\)|  
|[CMultiPaneFrameWnd::ConvertToTabbedDocument](../Topic/CMultiPaneFrameWnd::ConvertToTabbedDocument.md)|Converte o painel para um documento com guias.  Overrides \( [CPaneFrameWnd::ConvertToTabbedDocument](../Topic/CPaneFrameWnd::ConvertToTabbedDocument.md).\)|  
|[CMultiPaneFrameWnd::DockFrame](../Topic/CMultiPaneFrameWnd::DockFrame.md)||  
|[CMultiPaneFrameWnd::DockPane](../Topic/CMultiPaneFrameWnd::DockPane.md)|Insere o painel.  Overrides \( [CPaneFrameWnd::DockPane](../Topic/CPaneFrameWnd::DockPane.md).\)|  
|[CMultiPaneFrameWnd::DockRecentPaneToMainFrame](../Topic/CMultiPaneFrameWnd::DockRecentPaneToMainFrame.md)||  
|[CMultiPaneFrameWnd::GetCaptionText](../Topic/CMultiPaneFrameWnd::GetCaptionText.md)|Retorna o texto de legenda.  Overrides \( [CPaneFrameWnd::GetCaptionText](../Topic/CPaneFrameWnd::GetCaptionText.md).\)|  
|[CMultiPaneFrameWnd::GetPaneContainerManager](../Topic/CMultiPaneFrameWnd::GetPaneContainerManager.md)|Retorna uma referência para o objeto interno do gerenciador de contêiner.|  
|[CMultiPaneFrameWnd::GetFirstVisiblePane](../Topic/CMultiPaneFrameWnd::GetFirstVisiblePane.md)|Retorna o primeiro painel visível que está contido em uma janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::GetFirstVisiblePane](../Topic/CPaneFrameWnd::GetFirstVisiblePane.md).\)|  
|[CMultiPaneFrameWnd::GetPane](../Topic/CMultiPaneFrameWnd::GetPane.md)|Retorna um painel que está contido na janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::GetPane](../Topic/CPaneFrameWnd::GetPane.md).\)|  
|[CMultiPaneFrameWnd::GetPaneCount](../Topic/CMultiPaneFrameWnd::GetPaneCount.md)|Retorna o número de painéis que estão contidos em uma janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::GetPaneCount](../Topic/CPaneFrameWnd::GetPaneCount.md).\)|  
|[CMultiPaneFrameWnd::GetVisiblePaneCount](../Topic/CMultiPaneFrameWnd::GetVisiblePaneCount.md)|Retorna o número de painéis visíveis que estão contidos em uma janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::GetVisiblePaneCount](../Topic/CPaneFrameWnd::GetVisiblePaneCount.md).\)|  
|[CMultiPaneFrameWnd::InsertPane](../Topic/CMultiPaneFrameWnd::InsertPane.md)||  
|[CMultiPaneFrameWnd::LoadState](../Topic/CMultiPaneFrameWnd::LoadState.md)|Carrega o estado do painel do Registro.  Overrides \( [CPaneFrameWnd::LoadState](../Topic/CPaneFrameWnd::LoadState.md).\)|  
|[CMultiPaneFrameWnd::OnDockToRecentPos](../Topic/CMultiPaneFrameWnd::OnDockToRecentPos.md)|Insere a janela de mini\-linguagem quadro em sua posição mais recente.  Overrides \( [CPaneFrameWnd::OnDockToRecentPos](../Topic/CPaneFrameWnd::OnDockToRecentPos.md).\)|  
|[CMultiPaneFrameWnd::OnKillRollUpTimer](../Topic/CMultiPaneFrameWnd::OnKillRollUpTimer.md)|Para o timer de rollup.  Overrides \( [CPaneFrameWnd::OnKillRollUpTimer](../Topic/CPaneFrameWnd::OnKillRollUpTimer.md).\)|  
|[CMultiPaneFrameWnd::OnPaneRecalcLayout](../Topic/CMultiPaneFrameWnd::OnPaneRecalcLayout.md)|Ajustar o layout de um painel em uma janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::OnPaneRecalcLayout](../Topic/CPaneFrameWnd::OnPaneRecalcLayout.md).\)|  
|[CMultiPaneFrameWnd::OnSetRollUpTimer](../Topic/CMultiPaneFrameWnd::OnSetRollUpTimer.md)|Define o timer de rollup.  Overrides \( [CPaneFrameWnd::OnSetRollUpTimer](../Topic/CPaneFrameWnd::OnSetRollUpTimer.md).\)|  
|[CMultiPaneFrameWnd::OnShowPane](../Topic/CMultiPaneFrameWnd::OnShowPane.md)|Chamado pela estrutura quando um painel na janela de mini\-linguagem oculto ou quadro é exibido.  Overrides \( [CPaneFrameWnd::OnShowPane](../Topic/CPaneFrameWnd::OnShowPane.md).\)|  
|[CMultiPaneFrameWnd::PaneFromPoint](../Topic/CMultiPaneFrameWnd::PaneFromPoint.md)|Retorna se um painel contém um ponto usuário fornecido em uma janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::PaneFromPoint](../Topic/CPaneFrameWnd::PaneFromPoint.md).\)|  
|[CMultiPaneFrameWnd::RemoveNonValidPanes](../Topic/CMultiPaneFrameWnd::RemoveNonValidPanes.md)|Chamado pela estrutura para remover os painéis são válidos.  Overrides \( [CPaneFrameWnd::RemoveNonValidPanes](../Topic/CPaneFrameWnd::RemoveNonValidPanes.md).\)|  
|[CMultiPaneFrameWnd::RemovePane](../Topic/CMultiPaneFrameWnd::RemovePane.md)|Remove um painel da janela de mini\-linguagem quadro.  Overrides \( [CPaneFrameWnd::RemovePane](../Topic/CPaneFrameWnd::RemovePane.md).\)|  
|[CMultiPaneFrameWnd::ReplacePane](../Topic/CMultiPaneFrameWnd::ReplacePane.md)|Substitui um painel com o outro.  Overrides \( [CPaneFrameWnd::ReplacePane](../Topic/CPaneFrameWnd::ReplacePane.md).\)|  
|[CMultiPaneFrameWnd::SaveState](../Topic/CMultiPaneFrameWnd::SaveState.md)|Salvar o estado do painel no Registro.  Overrides \( [CPaneFrameWnd::SaveState](../Topic/CPaneFrameWnd::SaveState.md).\)|  
|[CMultiPaneFrameWnd::Serialize](../Topic/CMultiPaneFrameWnd::Serialize.md)|Overrides \( `CPaneFrameWnd::Serialize`.\)|  
|[CMultiPaneFrameWnd::SetDockState](../Topic/CMultiPaneFrameWnd::SetDockState.md)|Define o estado de encaixe.  Overrides \( [CPaneFrameWnd::SetDockState](../Topic/CPaneFrameWnd::SetDockState.md).\)|  
|[CMultiPaneFrameWnd::SetLastFocusedPane](../Topic/CMultiPaneFrameWnd::SetLastFocusedPane.md)||  
|[CMultiPaneFrameWnd::SetPreDockState](../Topic/CMultiPaneFrameWnd::SetPreDockState.md)|Define o estado predocking.  Overrides \( [CPaneFrameWnd::SetPreDockState](../Topic/CPaneFrameWnd::SetPreDockState.md).\)|  
|[CMultiPaneFrameWnd::StoreRecentDockSiteInfo](../Topic/CMultiPaneFrameWnd::StoreRecentDockSiteInfo.md)|Overrides \( [CPaneFrameWnd::StoreRecentDockSiteInfo](../Topic/CPaneFrameWnd::StoreRecentDockSiteInfo.md).\)|  
|[CMultiPaneFrameWnd::StoreRecentTabRelatedInfo](../Topic/CMultiPaneFrameWnd::StoreRecentTabRelatedInfo.md)|Overrides \( [CPaneFrameWnd::StoreRecentTabRelatedInfo](../Topic/CPaneFrameWnd::StoreRecentTabRelatedInfo.md).\)|  
  
## Comentários  
 A maioria dos métodos em métodos de esta substituição da classe na classe de [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) .  
  
 Se um painel usa o estilo de `AFX_CBRS_AUTO_ROLLUP` e plug\-ins de usuário que o painel para uma janela de quadro chave com multipainéis, o usuário pode rolar para cima a janela independentemente das configurações de estilo dos outros painéis conectados.  
  
 A estrutura automaticamente cria um objeto de `CMultiPaneFrameWnd` quando o usuário flutua um painel que usa o estilo de `CBRS_FLOAT_MULTI` .  
  
 Para obter informações sobre como derivar uma classe de classe de `CPaneFrameWnd` e de criá\-lo dinamicamente, consulte [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como recuperar um ponteiro para um objeto de `CMultiPaneFrameWnd` .  Este trecho de código é parte de [Defina o tamanho do painel de exemplo](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_SetPaneSize#4](../../mfc/reference/codesnippet/CPP/cmultipaneframewnd-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)  
  
 [CMultiPaneFrameWnd](../../mfc/reference/cmultipaneframewnd-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxMultiPaneFrameWnd.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)