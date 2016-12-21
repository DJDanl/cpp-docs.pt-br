---
title: "Classe de CDockingManager | Microsoft Docs"
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
  - "CDockingManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDockingManager"
ms.assetid: 98e69c43-55d8-4f43-b861-4fda80ec1e32
caps.latest.revision: 37
caps.handback.revision: 26
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDockingManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade principal que os controles que passa o layout em uma janela de quadro chave.  
  
## Sintaxe  
  
```  
class CDockingManager : public CObject  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockingManager::AddDockSite](../Topic/CDockingManager::AddDockSite.md)|Cria um painel dock e adicioná\-la à lista de barras de controle.|  
|[CDockingManager::AddHiddenMDITabbedBar](../Topic/CDockingManager::AddHiddenMDITabbedBar.md)|Adiciona um identificador para um painel de barra à lista de painéis catalogados MDI ocultos de barra.|  
|[CDockingManager::AddMiniFrame](../Topic/CDockingManager::AddMiniFrame.md)|Adiciona um quadro à lista de mini quadros.|  
|[CDockingManager::AddPane](../Topic/CDockingManager::AddPane.md)|Registra um painel com o gerenciador de encaixe.|  
|[CDockingManager::AdjustDockingLayout](../Topic/CDockingManager::AdjustDockingLayout.md)|Recalcula e ajusta o layout de todos os painéis em uma janela do quadro.|  
|[CDockingManager::AdjustPaneFrames](../Topic/CDockingManager::AdjustPaneFrames.md)|Faz com que a mensagem de `WM_NCCALCSIZE` a ser enviada a todos os painéis e janelas de `CPaneFrameWnd` .|  
|[CDockingManager::AdjustRectToClientArea](../Topic/CDockingManager::AdjustRectToClientArea.md)|Ajustar o alinhamento de um retângulo.|  
|[CDockingManager::AlignAutoHidePane](../Topic/CDockingManager::AlignAutoHidePane.md)|Redimensiona um painel de encaixe no modo de autohide de modo que recebe a largura ou altura completa da área cliente do quadro cercada por sites da plataforma.|  
|[CDockingManager::AutoHidePane](../Topic/CDockingManager::AutoHidePane.md)|Cria uma barra de ferramentas de autohide.|  
|[CDockingManager::BringBarsToTop](../Topic/CDockingManager::BringBarsToTop.md)|Traz barras entradas que tem o alinhamento especificado para a parte superior.|  
|[CDockingManager::BuildPanesMenu](../Topic/CDockingManager::BuildPanesMenu.md)|Adiciona nomes dos painéis e barras de ferramentas de encaixe para um menu.|  
|[CDockingManager::CalcExpectedDockedRect](../Topic/CDockingManager::CalcExpectedDockedRect.md)|Calcula o retângulo esperado de uma janela entrada.|  
|[CDockingManager::Create](../Topic/CDockingManager::Create.md)|Cria um gerente de encaixe.|  
|[CDockingManager::DeterminePaneAndStatus](../Topic/CDockingManager::DeterminePaneAndStatus.md)|Determina o painel que contém um determinado ponto e seu status de encaixe.|  
|[CDockingManager::DisableRestoreDockState](../Topic/CDockingManager::DisableRestoreDockState.md)|Habilita ou desabilita a carga de encaixe de layout do Registro.|  
|[CDockingManager::DockPane](../Topic/CDockingManager::DockPane.md)|Insere um painel para outro painel ou a uma janela do quadro.|  
|[CDockingManager::DockPaneLeftOf](../Topic/CDockingManager::DockPaneLeftOf.md)|Insere um painel à esquerda de outro painel.|  
|[CDockingManager::EnableAutoHidePanes](../Topic/CDockingManager::EnableAutoHidePanes.md)|Permite que o encaixe do painel para o quadro chave, cria um painel dock, e adicioná\-la à lista de barras de controle.|  
|[CDockingManager::EnableDocking](../Topic/CDockingManager::EnableDocking.md)|Cria um painel dock e permite que o encaixe do painel para o quadro chave.|  
|[CDockingManager::EnableDockSiteMenu](../Topic/CDockingManager::EnableDockSiteMenu.md)|Exibe um botão adicional que abre um menu pop\-up nas legendas de todos os painéis de encaixe.|  
|[CDockingManager::EnablePaneContextMenu](../Topic/CDockingManager::EnablePaneContextMenu.md)|Indica que a biblioteca oferece para exibir um menu de contexto especial que tenha uma lista de barras de ferramentas do aplicativo e painéis de encaixe quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem de WM\_CONTEXTMENU.|  
|[CDockingManager::FindDockSite](../Topic/CDockingManager::FindDockSite.md)|Recupera o painel de barra que está na posição especificada e que tem o alinhamento especificado.|  
|[CDockingManager::FindDockSiteByPane](../Topic/CDockingManager::FindDockSiteByPane.md)|Retorna o painel de barra que tem a identificação do painel de barra de destino.|  
|[CDockingManager::FindPaneByID](../Topic/CDockingManager::FindPaneByID.md)|Localiza um painel por certo ID de controle|  
|[CDockingManager::FixupVirtualRects](../Topic/CDockingManager::FixupVirtualRects.md)|Confirma as posições atuais da barra de ferramentas para retângulos virtuais.|  
|[CDockingManager::FrameFromPoint](../Topic/CDockingManager::FrameFromPoint.md)|Retorna o quadro que contém o ponto especificado.|  
|[CDockingManager::GetClientAreaBounds](../Topic/CDockingManager::GetClientAreaBounds.md)|Obtém o retângulo que contém os limites da área cliente.|  
|[CDockingManager::GetDockingMode](../Topic/CDockingManager::GetDockingMode.md)|Retorna o modo de encaixe atual.|  
|[CDockingManager::GetDockSiteFrameWnd](../Topic/CDockingManager::GetDockSiteFrameWnd.md)|Obtém um ponteiro para o quadro da janela pai.|  
|[CDockingManager::GetEnabledAutoHideAlignment](../Topic/CDockingManager::GetEnabledAutoHideAlignment.md)|Retorna o alinhamento ativado painéis.|  
|[CDockingManager::GetMiniFrames](../Topic/CDockingManager::GetMiniFrames.md)|Obtém uma lista de miniframes.|  
|[CDockingManager::GetOuterEdgeBounds](../Topic/CDockingManager::GetOuterEdgeBounds.md)|Obtém um retângulo que contém as bordas externas do quadro.|  
|[CDockingManager::GetPaneList](../Topic/CDockingManager::GetPaneList.md)|Retorna uma lista de painéis que pertencem ao gerenciador de encaixe.  Isso inclui todos os painéis flutuante.|  
|[CDockingManager::GetSmartDockingManager](../Topic/CDockingManager::GetSmartDockingManager.md)|Recupera um ponteiro para o gerenciador inteligente de encaixe.|  
|[CDockingManager::GetSmartDockingManagerPermanent](../Topic/CDockingManager::GetSmartDockingManagerPermanent.md)|Recupera um ponteiro para o gerenciador inteligente de encaixe.|  
|[CDockingManager::GetSmartDockingParams](../Topic/CDockingManager::GetSmartDockingParams.md)|Retorna os parâmetros inteligentes de encaixe para o gerenciador de encaixe.|  
|[CDockingManager::GetSmartDockingTheme](../Topic/CDockingManager::GetSmartDockingTheme.md)|Um método estático que retorna um tema usado para exibir marcadores inteligentes de encaixe.|  
|[CDockingManager::HideAutoHidePanes](../Topic/CDockingManager::HideAutoHidePanes.md)|Oculta um painel que se está em modo de autohide.|  
|[CDockingManager::InsertDockSite](../Topic/CDockingManager::InsertDockSite.md)|Cria um painel dock e inseri\-lo na lista de barras de controle.|  
|[CDockingManager::InsertPane](../Topic/CDockingManager::InsertPane.md)|Insere um painel de controle na lista de barras de controle.|  
|[CDockingManager::IsDockSiteMenu](../Topic/CDockingManager::IsDockSiteMenu.md)|Especifica se um menu pop\-up é exibido nas legendas de todos os painéis.|  
|[CDockingManager::IsInAdjustLayout](../Topic/CDockingManager::IsInAdjustLayout.md)|Determina se os layouts de todos os painéis são definidos.|  
|[CDockingManager::IsOLEContainerMode](../Topic/CDockingManager::IsOLEContainerMode.md)|Especifica se o gerenciador de encaixe está no modo OLE do recipiente.|  
|[CDockingManager::IsPointNearDockSite](../Topic/CDockingManager::IsPointNearDockSite.md)|Determina se um ponto está especificado pelo site da plataforma.|  
|[CDockingManager::IsPrintPreviewValid](../Topic/CDockingManager::IsPrintPreviewValid.md)|Determina se o modo de visualização de impressão é definido.|  
|[CDockingManager::LoadState](../Topic/CDockingManager::LoadState.md)|Carrega o estado do gerenciador de encaixe do Registro.|  
|[CDockingManager::LockUpdate](../Topic/CDockingManager::LockUpdate.md)|Bloqueia a janela determinada.|  
|[CDockingManager::OnActivateFrame](../Topic/CDockingManager::OnActivateFrame.md)|Chamado pela estrutura quando a janela de quadro chave é feita ativo ou desativada.|  
|[CDockingManager::OnClosePopupMenu](../Topic/CDockingManager::OnClosePopupMenu.md)|Chamado pela estrutura quando um menu pop\-up ativa processar uma mensagem de WM\_DESTROY.|  
|[CDockingManager::OnMoveMiniFrame](../Topic/CDockingManager::OnMoveMiniFrame.md)|Chamado pela estrutura para mover uma janela de mini\-linguagem quadro.|  
|[CDockingManager::OnPaneContextMenu](../Topic/CDockingManager::OnPaneContextMenu.md)|Chamado pela estrutura quando criar um menu que tenha uma lista de painéis.|  
|[CDockingManager::PaneFromPoint](../Topic/CDockingManager::PaneFromPoint.md)|Retorna o painel que contém o ponto especificado.|  
|[CDockingManager::ProcessPaneContextMenuCommand](../Topic/CDockingManager::ProcessPaneContextMenuCommand.md)|Chamado pela estrutura para marque ou desmarque a caixa de seleção para o comando especificado e para recalcular o layout de um painel mostrado.|  
|[CDockingManager::RecalcLayout](../Topic/CDockingManager::RecalcLayout.md)|Recalcula o layout interno de controles atuais na lista de controles.|  
|[CDockingManager::ReleaseEmptyPaneContainers](../Topic/CDockingManager::ReleaseEmptyPaneContainers.md)|Libera os contêineres vazios de painel.|  
|[CDockingManager::RemoveHiddenMDITabbedBar](../Topic/CDockingManager::RemoveHiddenMDITabbedBar.md)|Remove o painel oculto especificado de barra.|  
|[CDockingManager::RemoveMiniFrame](../Topic/CDockingManager::RemoveMiniFrame.md)|Remove um elemento especificado da lista de mini quadros.|  
|[CDockingManager::RemovePaneFromDockManager](../Topic/CDockingManager::RemovePaneFromDockManager.md)|Desregistre um painel e remova\-o da lista no gerenciador de encaixe.|  
|[CDockingManager::ReplacePane](../Topic/CDockingManager::ReplacePane.md)|Substitui um painel com o outro.|  
|[CDockingManager::ResortMiniFramesForZOrder](../Topic/CDockingManager::ResortMiniFramesForZOrder.md)|Recorrem quadros na lista de mini quadros.|  
|[CDockingManager::SaveState](../Topic/CDockingManager::SaveState.md)|Salvar o estado do gerenciador de encaixe para o Registro.|  
|[CDockingManager::SendMessageToMiniFrames](../Topic/CDockingManager::SendMessageToMiniFrames.md)|Envia a mensagem especificada para todos os quadros mini.|  
|[CDockingManager::Serialize](../Topic/CDockingManager::Serialize.md)|Grava o gerenciador de encaixe para um arquivo neutro.  Overrides \( [CObject::Serialize](../Topic/CObject::Serialize.md).\)|  
|[CDockingManager::SetAutohideZOrder](../Topic/CDockingManager::SetAutohideZOrder.md)|Defina o tamanho, a largura, e altura das barras de controle e o painel especificado.|  
|[CDockingManager::SetDockingMode](../Topic/CDockingManager::SetDockingMode.md)|Defina o modo de encaixe.|  
|[CDockingManager::SetDockState](../Topic/CDockingManager::SetDockState.md)|Define o estado de encaixe de barras de controle, mini de quadros, e barras de autohide.|  
|[CDockingManager::SetPrintPreviewMode](../Topic/CDockingManager::SetPrintPreviewMode.md)|Defina o modo de visualização de impressão das barras que é exibido na visualização de impressão.|  
|[CDockingManager::SetSmartDockingParams](../Topic/CDockingManager::SetSmartDockingParams.md)|Defina os parâmetros que definem o comportamento de encaixe inteligente.|  
|[CDockingManager::ShowDelayShowMiniFrames](../Topic/CDockingManager::ShowDelayShowMiniFrames.md)|Mostra ou oculta as janelas de mini quadros.|  
|[CDockingManager::ShowPanes](../Topic/CDockingManager::ShowPanes.md)|Mostra ou oculta os painéis de barras do controle e de autohide.|  
|[CDockingManager::StartSDocking](../Topic/CDockingManager::StartSDocking.md)|Inicia o encaixe inteligente da janela especificada de acordo com o alinhamento do gerenciador de encaixe inteligente.|  
|[CDockingManager::StopSDocking](../Topic/CDockingManager::StopSDocking.md)|Para o encaixe inteligente.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockingManager::m\_bHideDockingBarsInContainerMode](../Topic/CDockingManager::m_bHideDockingBarsInContainerMode.md)|Especifica se o gerenciador de encaixe oculta os painéis no modo OLE do recipiente.|  
|[CDockingManager::m\_dockModeGlobal](../Topic/CDockingManager::m_dockModeGlobal.md)|Especifica o modo global de encaixe.|  
|[CDockingManager::m\_nDockSensitivity](../Topic/CDockingManager::m_nDockSensitivity.md)|Especifica a sensibilidade de encaixe.|  
|[CDockingManager::m\_nTimeOutBeforeDockingBarDock](../Topic/CDockingManager::m_nTimeOutBeforeDockingBarDock.md)|Especifica o tempo, em milissegundos, antes que um painel de encaixe está conectado no modo imediato de encaixe.|  
|[CDockingManager::m\_nTimeOutBeforeToolBarDock](../Topic/CDockingManager::m_nTimeOutBeforeToolBarDock.md)|Especifica o tempo, em milissegundos, antes que uma barra de ferramentas está entrada para a janela do quadro chave.|  
  
## Comentários  
 A janela de quadro chave cria e inicializa essa classe automaticamente.  
  
 O objeto do gerenciador de encaixe contém uma lista de todos os painéis que estão no layout de encaixe, e também uma lista de todas as janelas de [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) que pertencem a janela de quadro chave.  
  
 A classe implementa de `CDockingManager` alguns serviços que você pode usar para localizar um painel ou uma janela de `CPaneFrameWnd` .  Você geralmente não chamar esses serviços diretamente como envolvidos no objeto da janela de quadro chave.  Para mais informações, consulte [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).  
  
## Dicas de personalização  
 As dicas a seguir aplicam a `CDockingManager` objetos:  
  
-   [CDockingManager Class](../../mfc/reference/cdockingmanager-class.md) oferece suporte para esses modos de encaixe:  
  
    -   `AFX_DOCK_TYPE::DT_IMMEDIATE`  
  
    -   `AFX_DOCK_TYPE::DT_STANDARD`  
  
    -   `AFX_DOCK_TYPE::DT_SMART`  
  
     Esses modos de encaixe são definidos por [CDockingManager::m\_dockModeGlobal](../Topic/CDockingManager::m_dockModeGlobal.md) e definidos [CDockingManager::SetDockingMode](../Topic/CDockingManager::SetDockingMode.md)chamando.  
  
-   Se você desejar criar uma forma não flutuante, o painel não redimensionável, chama o método de [CDockingManager::AddPane](../Topic/CDockingManager::AddPane.md) .  Este método registra o painel com o gerenciador de encaixe, que é responsável pelo layout do painel.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CDockingManager` para configurar um objeto de `CDockingManager` .  O exemplo a seguir mostra como exibir um botão adicional que abre um menu pop\-up nas legendas de todos os painéis de encaixe e como definir o modo de encaixe do objeto.  Este trecho de código é parte de [Exemplo de demonstração do Visual Studio](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#24](../../mfc/reference/codesnippet/CPP/cdockingmanager-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDockingManager](../../mfc/reference/cdockingmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDockingManager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Classe de CFrameWndEx](../../mfc/reference/cframewndex-class.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)   
 [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)