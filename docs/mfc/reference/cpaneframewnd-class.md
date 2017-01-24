---
title: "Classe CPaneFrameWnd | Microsoft Docs"
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
  - "CPaneFrameWnd.Serialize"
  - "CPaneFrameWnd.PreTranslateMessage"
  - "CPaneFrameWnd"
  - "CPaneFrameWnd::Serialize"
  - "PreTranslateMessage"
  - "CPaneFrameWnd::PreTranslateMessage"
  - "Serialize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CPaneFrameWnd"
  - "Método Serialize"
  - "Método PreTranslateMessage"
ms.assetid: ea3423a3-2763-482e-b763-817036ded10d
caps.latest.revision: 28
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CPaneFrameWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 Implementa uma janela de quadro simplificado que contém um painel. O painel preenche a área cliente da janela.  
  
## Sintaxe  
  
```  
class CPaneFrameWnd : public CWnd  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneFrameWnd::AddPane](../Topic/CPaneFrameWnd::AddPane.md)|Adiciona um painel.|  
|[CPaneFrameWnd::AddRemovePaneFromGlobalList](../Topic/CPaneFrameWnd::AddRemovePaneFromGlobalList.md)|Adiciona ou remove um painel da lista global.|  
|[CPaneFrameWnd::AdjustLayout](../Topic/CPaneFrameWnd::AdjustLayout.md)|Ajusta o layout da janela de quadro simplificado.|  
|[CPaneFrameWnd::AdjustPaneFrames](../Topic/CPaneFrameWnd::AdjustPaneFrames.md)||  
|[CPaneFrameWnd::CalcBorderSize](../Topic/CPaneFrameWnd::CalcBorderSize.md)|Calcula o tamanho das bordas de uma janela de quadro simplificado.|  
|[CPaneFrameWnd::CalcExpectedDockedRect](../Topic/CPaneFrameWnd::CalcExpectedDockedRect.md)|Calcule o retângulo esperado de uma janela encaixada.|  
|[CPaneFrameWnd::CanBeAttached](../Topic/CPaneFrameWnd::CanBeAttached.md)|Determina se o painel atual pode ser encaixado em outra janela do painel ou quadro.|  
|[CPaneFrameWnd::CanBeDockedToPane](../Topic/CPaneFrameWnd::CanBeDockedToPane.md)|Determina se a janela do mini\-quadro pode ser encaixada para um painel.|  
|[CPaneFrameWnd::CheckGripperVisibility](../Topic/CPaneFrameWnd::CheckGripperVisibility.md)||  
|[CPaneFrameWnd::ConvertToTabbedDocument](../Topic/CPaneFrameWnd::ConvertToTabbedDocument.md)|Converte o painel em um documento com guias.|  
|[CPaneFrameWnd::Create](../Topic/CPaneFrameWnd::Create.md)|Cria uma janela de quadro simplificado e anexa\-o para o `CPaneFrameWnd` objeto.|  
|[CPaneFrameWnd::CreateEx](../Topic/CPaneFrameWnd::CreateEx.md)|Cria uma janela de quadro simplificado e anexa\-o para o `CPaneFrameWnd` objeto.|  
|[CPaneFrameWnd::DockPane](../Topic/CPaneFrameWnd::DockPane.md)|Encaixa o painel.|  
|[CPaneFrameWnd::FindFloatingPaneByID](../Topic/CPaneFrameWnd::FindFloatingPaneByID.md)|Localiza um painel com a ID do controle especificado na lista global de painéis flutuantes.|  
|[CPaneFrameWnd::FrameFromPoint](../Topic/CPaneFrameWnd::FrameFromPoint.md)|Localiza a janela do quadro simplificado que contém um ponto fornecido pelo usuário.|  
|[CPaneFrameWnd::GetCaptionHeight](../Topic/CPaneFrameWnd::GetCaptionHeight.md)|Retorna a altura da legenda da janela de quadro simplificado.|  
|[CPaneFrameWnd::GetCaptionRect](../Topic/CPaneFrameWnd::GetCaptionRect.md)|Calcula o retângulo delimitador de uma legenda de janela de quadro simplificado.|  
|[CPaneFrameWnd::GetCaptionText](../Topic/CPaneFrameWnd::GetCaptionText.md)|Retorna o texto da legenda.|  
|[CPaneFrameWnd::GetDockingManager](../Topic/CPaneFrameWnd::GetDockingManager.md)||  
|[CPaneFrameWnd::GetDockingMode](../Topic/CPaneFrameWnd::GetDockingMode.md)|Retorna o modo de encaixe.|  
|[CPaneFrameWnd::GetFirstVisiblePane](../Topic/CPaneFrameWnd::GetFirstVisiblePane.md)|Retorna o primeiro painel visível que está contido em uma janela de quadro simplificado.|  
|[CPaneFrameWnd::GetHotPoint](../Topic/CPaneFrameWnd::GetHotPoint.md)||  
|[CPaneFrameWnd::GetPane](../Topic/CPaneFrameWnd::GetPane.md)|Retorna um painel que está contido na janela do quadro simplificado.|  
|[CPaneFrameWnd::GetPaneCount](../Topic/CPaneFrameWnd::GetPaneCount.md)|Retorna o número de painéis que estão contidos em uma janela de quadro simplificado.|  
|[CPaneFrameWnd::GetParent](../Topic/CPaneFrameWnd::GetParent.md)||  
|[CPaneFrameWnd::GetPinState](../Topic/CPaneFrameWnd::GetPinState.md)||  
|[CPaneFrameWnd::GetRecentFloatingRect](../Topic/CPaneFrameWnd::GetRecentFloatingRect.md)||  
|[CPaneFrameWnd::GetVisiblePaneCount](../Topic/CPaneFrameWnd::GetVisiblePaneCount.md)|Retorna o número de painéis visíveis que estão contidos em uma janela de quadro simplificado.|  
|[CPaneFrameWnd::HitTest](../Topic/CPaneFrameWnd::HitTest.md)|Determina qual parte de uma janela de mini\-quadro em um determinado ponto.|  
|[CPaneFrameWnd::IsCaptured](../Topic/CPaneFrameWnd::IsCaptured.md)||  
|[CPaneFrameWnd::IsDelayShow](../Topic/CPaneFrameWnd::IsDelayShow.md)||  
|[CPaneFrameWnd::IsRollDown](../Topic/CPaneFrameWnd::IsRollDown.md)|Determina se uma janela de mini\-quadro deve ser revertida para baixo.|  
|[CPaneFrameWnd::IsRollUp](../Topic/CPaneFrameWnd::IsRollUp.md)|Determina se uma janela de quadro mini deve ser acumulada.|  
|[CPaneFrameWnd::KillDockingTimer](../Topic/CPaneFrameWnd::KillDockingTimer.md)|Interrompe o timer de encaixe.|  
|[CPaneFrameWnd::LoadState](../Topic/CPaneFrameWnd::LoadState.md)|Carrega o estado do painel do registro.|  
|[CPaneFrameWnd::OnBeforeDock](../Topic/CPaneFrameWnd::OnBeforeDock.md)|Determina se é possível encaixar.|  
|[CPaneFrameWnd::OnDockToRecentPos](../Topic/CPaneFrameWnd::OnDockToRecentPos.md)|Encaixa a janela do quadro mini em sua posição mais recente.|  
|[CPaneFrameWnd::OnKillRollUpTimer](../Topic/CPaneFrameWnd::OnKillRollUpTimer.md)|Interrompe o cronômetro do pacote cumulativo de atualizações.|  
|[CPaneFrameWnd::OnMovePane](../Topic/CPaneFrameWnd::OnMovePane.md)|Move a janela de quadro simplificado por um deslocamento especificado.|  
|[CPaneFrameWnd::OnPaneRecalcLayout](../Topic/CPaneFrameWnd::OnPaneRecalcLayout.md)|Ajusta o layout de um painel independente.|  
|[CPaneFrameWnd::OnSetRollUpTimer](../Topic/CPaneFrameWnd::OnSetRollUpTimer.md)|Define o timer do pacote cumulativo de atualizações.|  
|[CPaneFrameWnd::OnShowPane](../Topic/CPaneFrameWnd::OnShowPane.md)|Chamado pela estrutura quando um painel na janela do quadro mini é ocultado ou exibido.|  
|[CPaneFrameWnd::PaneFromPoint](../Topic/CPaneFrameWnd::PaneFromPoint.md)|Retorna um painel se ele contiver um ponto dentro de uma janela de quadro mini fornecido pelo usuário.|  
|[CPaneFrameWnd::Pin](../Topic/CPaneFrameWnd::Pin.md)||  
|`CPaneFrameWnd::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows.|  
|[CPaneFrameWnd::RedrawAll](../Topic/CPaneFrameWnd::RedrawAll.md)|Todas as janelas de quadro mini é redesenhado.|  
|[CPaneFrameWnd::RemoveNonValidPanes](../Topic/CPaneFrameWnd::RemoveNonValidPanes.md)|Chamado pela estrutura para remover painéis não válido.|  
|[CPaneFrameWnd::RemovePane](../Topic/CPaneFrameWnd::RemovePane.md)|Remove um painel da janela de quadro simplificado.|  
|[CPaneFrameWnd::ReplacePane](../Topic/CPaneFrameWnd::ReplacePane.md)|Substitui um painel com outra.|  
|[CPaneFrameWnd::SaveState](../Topic/CPaneFrameWnd::SaveState.md)|Salva o estado do painel no registro.|  
|`CPaneFrameWnd::Serialize`|Lê ou grava este objeto de ou para um arquivo morto.|  
|[CPaneFrameWnd::SetCaptionButtons](../Topic/CPaneFrameWnd::SetCaptionButtons.md)|Conjuntos de botões de legenda.|  
|[CPaneFrameWnd::SetDelayShow](../Topic/CPaneFrameWnd::SetDelayShow.md)||  
|[CPaneFrameWnd::SetDockingManager](../Topic/CPaneFrameWnd::SetDockingManager.md)||  
|[CPaneFrameWnd::SetDockingTimer](../Topic/CPaneFrameWnd::SetDockingTimer.md)|Define o timer de encaixe.|  
|[CPaneFrameWnd::SetDockState](../Topic/CPaneFrameWnd::SetDockState.md)|Define o estado de encaixe.|  
|[CPaneFrameWnd::SetHotPoint](../Topic/CPaneFrameWnd::SetHotPoint.md)||  
|[CPaneFrameWnd::SetPreDockState](../Topic/CPaneFrameWnd::SetPreDockState.md)|Chamado pela estrutura para definir o estado predocking.|  
|[CPaneFrameWnd::SizeToContent](../Topic/CPaneFrameWnd::SizeToContent.md)|Ajusta o tamanho de uma janela de quadro simplificado para que seja equivalente de tamanho para um painel independente.|  
|[CPaneFrameWnd::StartTearOff](../Topic/CPaneFrameWnd::StartTearOff.md)|Lágrimas um menu.|  
|[CPaneFrameWnd::StoreRecentDockSiteInfo](../Topic/CPaneFrameWnd::StoreRecentDockSiteInfo.md)||  
|[CPaneFrameWnd::StoreRecentTabRelatedInfo](../Topic/CPaneFrameWnd::StoreRecentTabRelatedInfo.md)||  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneFrameWnd::OnCheckRollState](../Topic/CPaneFrameWnd::OnCheckRollState.md)|Determina se uma janela de mini\-quadro deve ser revertida para cima ou para baixo.|  
|[CPaneFrameWnd::OnDrawBorder](../Topic/CPaneFrameWnd::OnDrawBorder.md)|Desenha as bordas de uma janela de quadro simplificado.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPaneFrameWnd::m\_bUseSaveBits](../Topic/CPaneFrameWnd::m_bUseSaveBits.md)|Especifica se deve registrar a classe de janela com o `CS_SAVEBITS` estilo de classe.|  
  
## Comentários  
 O framework cria automaticamente uma `CPaneFrameWnd` objeto quando um painel é alternado de um estado encaixado para o estado flutuante.  
  
 Uma janela de mini\-quadro pode ser arrastada com seu conteúdo visível \(imediata de ancoragem\) ou usando um retângulo de arrastar \(encaixe padrão\). O modo de encaixe do painel do contêiner do quadro mini determina que a mini\-frame do arrastando o comportamento. Para obter mais informações, consulte [CBasePane::GetDockingMode](../Topic/CBasePane::GetDockingMode.md).  
  
 Uma janela de mini\-quadro exibe botões na legenda de acordo com o estilo de painel independente. Se o painel pode ser fechado \([CBasePane::CanBeClosed](../Topic/CBasePane::CanBeClosed.md)\), ele exibe um botão Fechar. Se o painel tem o `AFX_CBRS_AUTO_ROLLUP` estilo, ele exibe um pin.  
  
 Se você derivar uma classe de `CPaneFrameWnd`, você deve informar o framework como criá\-lo. Crie a classe substituindo [CPane::CreateDefaultMiniframe](../Topic/CPane::CreateDefaultMiniframe.md), ou defina o `CPane::m_pMiniFrameRTC` para que ele aponte para as informações de classe de tempo de execução para a sua classe de membro.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxPaneFrameWnd.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)