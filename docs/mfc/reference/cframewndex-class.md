---
title: "Classe de CFrameWndEx | Microsoft Docs"
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
  - "CFrameWndEx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFrameWndEx"
ms.assetid: 5830aca8-4a21-4f31-91f1-dd5477ffcc8d
caps.latest.revision: 39
caps.handback.revision: 26
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFrameWndEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade de uma interface janela pop\-up ou sobrepostos de \(SDI\) do único documento do windows de quadro chave, e fornece membros para gerenciar a janela.  Estende a classe de [CFrameWnd](../../mfc/reference/cframewnd-class.md) .  
  
## Sintaxe  
  
```  
class CFrameWndEx : public CFrameWnd  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFrameWndEx::ActiveItemRecalcLayout](../Topic/CFrameWndEx::ActiveItemRecalcLayout.md)|Ajustar o layout de item OLE de cliente e da área cliente do quadro.|  
|`CFrameWndEx::AddDockSite`|Este método não é usado.|  
|[CFrameWndEx::AddPane](../Topic/CFrameWndEx::AddPane.md)|Registra uma barra de controle com o gerenciador de encaixe.|  
|[CFrameWndEx::AdjustDockingLayout](../Topic/CFrameWndEx::AdjustDockingLayout.md)|Recalcula o layout de todos os painéis que estejam conectados a janela do quadro.|  
|[CFrameWndEx::DelayUpdateFrameMenu](../Topic/CFrameWndEx::DelayUpdateFrameMenu.md)|Define o menu e então atualizações do quadro ele quando o processamento de comando estiver ocioso.|  
|[CFrameWndEx::DockPane](../Topic/CFrameWndEx::DockPane.md)|Insere o painel especificado para a janela do quadro.|  
|[CFrameWndEx::DockPaneLeftOf](../Topic/CFrameWndEx::DockPaneLeftOf.md)|Plug\-ins um painel à esquerda de outro painel.|  
|[CFrameWndEx::EnableAutoHidePanes](../Topic/CFrameWndEx::EnableAutoHidePanes.md)|Ativar o modo de incrementos ocultar os painéis para quando especificados estão conectados aos lados da janela de quadro chave.|  
|[CFrameWndEx::EnableDocking](../Topic/CFrameWndEx::EnableDocking.md)|Permite que o encaixe de painéis que pertencem a janela do quadro.|  
|[CFrameWndEx::EnableFullScreenMainMenu](../Topic/CFrameWndEx::EnableFullScreenMainMenu.md)|Mostra ou oculta o menu principal em um modo de tela inteira.|  
|[CFrameWndEx::EnableFullScreenMode](../Topic/CFrameWndEx::EnableFullScreenMode.md)|Ativar o modo de tela inteira para a janela do quadro.|  
|[CFrameWndEx::EnableLoadDockState](../Topic/CFrameWndEx::EnableLoadDockState.md)|Habilita ou desabilita a carga de estado de encaixe.|  
|[CFrameWndEx::EnablePaneMenu](../Topic/CFrameWndEx::EnablePaneMenu.md)|Habilita ou desabilita a tratamento automático do menu do painel.|  
|[CFrameWndEx::GetActivePopup](../Topic/CFrameWndEx::GetActivePopup.md)|Retorna um ponteiro para o menu pop\-up atualmente exibido.|  
|[CFrameWndEx::GetDefaultResId](../Topic/CFrameWndEx::GetDefaultResId.md)|Retorna a identificação de recursos que você especificou quando a estrutura carregou a janela do quadro.|  
|[CFrameWndEx::GetDockingManager](../Topic/CFrameWndEx::GetDockingManager.md)|Retorna o objeto de [Classe de CDockingManager](../../mfc/reference/cdockingmanager-class.md) para a janela do quadro.|  
|[CFrameWndEx::GetMenuBar](../Topic/CFrameWndEx::GetMenuBar.md)|Retorna um ponteiro para o objeto de barra de menu conectado à janela do quadro.|  
|[CFrameWndEx::GetPane](../Topic/CFrameWndEx::GetPane.md)|Retorna um ponteiro para o painel que tem um certo ID|  
|[CFrameWndEx::GetRibbonBar](../Topic/CFrameWndEx::GetRibbonBar.md)|Recupera o controle de barra de fita para o quadro.|  
|[CFrameWndEx::GetTearOffBars](../Topic/CFrameWndEx::GetTearOffBars.md)|Retorna uma lista de objetos de painel que está em um estado de rasgo \- fora.|  
|[CFrameWndEx::GetToolbarButtonToolTipText](../Topic/CFrameWndEx::GetToolbarButtonToolTipText.md)|Chamado pela estrutura quando o aplicativo para exibir a dica de ferramenta para um botão da barra de ferramentas.|  
|[CFrameWndEx::InsertPane](../Topic/CFrameWndEx::InsertPane.md)|Registra um painel com o gerenciador de encaixe.|  
|[CFrameWndEx::IsFullScreen](../Topic/CFrameWndEx::IsFullScreen.md)|Determina se a janela de quadro estiver no modo de tela inteira.|  
|[CFrameWndEx::IsMenuBarAvailable](../Topic/CFrameWndEx::IsMenuBarAvailable.md)|Determina se o ponteiro ao objeto de barra de menu é válido.|  
|[CFrameWndEx::IsPointNearDockSite](../Topic/CFrameWndEx::IsPointNearDockSite.md)|Indica se o ponto está localizado em uma zona de alinhamento.|  
|[CFrameWndEx::IsPrintPreview](../Topic/CFrameWndEx::IsPrintPreview.md)|Indica se a janela de quadro está no modo de visualização de impressão.|  
|[CFrameWndEx::LoadFrame](../Topic/CFrameWndEx::LoadFrame.md)|Este método é chamado depois da compilação para criar a janela do quadro e carregar seus recursos.|  
|[CFrameWndEx::NegotiateBorderSpace](../Topic/CFrameWndEx::NegotiateBorderSpace.md)|Negociação OLE da borda do cliente implementa.|  
|[CFrameWndEx::OnActivate](../Topic/CFrameWndEx::OnActivate.md)|A estrutura chama esse método quando a entrada do usuário é ou trocada fora do quadro.|  
|[CFrameWndEx::OnActivateApp](../Topic/CFrameWndEx::OnActivateApp.md)|Chamado pela estrutura quando o aplicativo é selecionado ou deselecionada.|  
|[CFrameWndEx::OnChangeVisualManager](../Topic/CFrameWndEx::OnChangeVisualManager.md)|Chamado pela estrutura quando uma alteração para o quadro exigir uma alteração para o gerenciador visual.|  
|[CFrameWndEx::OnClose](../Topic/CFrameWndEx::OnClose.md)|A estrutura chama esse método para fechar o quadro.|  
|[CFrameWndEx::OnCloseDockingPane](../Topic/CFrameWndEx::OnCloseDockingPane.md)|Chamado pela estrutura quando o usuário clica no botão de **Fechar** em um painel de encaixe.|  
|[CFrameWndEx::OnCloseMiniFrame](../Topic/CFrameWndEx::OnCloseMiniFrame.md)|Chamado pela estrutura quando o usuário clica no botão de **Fechar** em uma janela mini flutuante do quadro.|  
|[CFrameWndEx::OnClosePopupMenu](../Topic/CFrameWndEx::OnClosePopupMenu.md)|Chamado pela estrutura quando um menu pop\-up ativa processar uma mensagem de WM\_DESTROY.|  
|[CFrameWndEx::OnCmdMsg](../Topic/CFrameWndEx::OnCmdMsg.md)|Mensagens de comando de expedições.|  
|[CFrameWndEx::OnContextHelp](../Topic/CFrameWndEx::OnContextHelp.md)|Chamado pela estrutura para exibir o contexto relacionadas a ajuda.|  
|[CFrameWndEx::OnCreate](../Topic/CFrameWndEx::OnCreate.md)|Chamado pela estrutura do quadro é criado.|  
|[CFrameWndEx::OnDestroy](../Topic/CFrameWndEx::OnDestroy.md)|Chamado pela estrutura quando o quadro é destruído.|  
|[CFrameWndEx::OnDrawMenuImage](../Topic/CFrameWndEx::OnDrawMenuImage.md)|Chamado pela estrutura quando o aplicativo desenhar a imagem associada a um item de menu.|  
|[CFrameWndEx::OnDrawMenuLogo](../Topic/CFrameWndEx::OnDrawMenuLogo.md)|Chamado pela estrutura quando um objeto de `CMFCPopupMenu` processar uma mensagem de [WM\_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) .|  
|[CFrameWndEx::OnDWMCompositionChanged](../Topic/CFrameWndEx::OnDWMCompositionChanged.md)|Chamado pela estrutura quando a composição de \(DWM\) gerenciador de janelas da área de trabalho é ativado ou desativado.|  
|[CFrameWndEx::OnExitSizeMove](../Topic/CFrameWndEx::OnExitSizeMove.md)|Chamado pela estrutura quando o quadro parar de mover ou redimensionar.|  
|[CFrameWndEx::OnGetMinMaxInfo](../Topic/CFrameWndEx::OnGetMinMaxInfo.md)|Chamado pela estrutura quando o quadro é redimensionado para definir limites de dimensão da janela.|  
|[CFrameWndEx::OnIdleUpdateCmdUI](../Topic/CFrameWndEx::OnIdleUpdateCmdUI.md)|Chamado pela estrutura para atualizar a exibição do quadro quando o processamento de comando estiver ocioso.|  
|[CFrameWndEx::OnLButtonDown](../Topic/CFrameWndEx::OnLButtonDown.md)|A estrutura chama esse método quando o usuário pressiona o botão esquerdo do mouse.|  
|[CFrameWndEx::OnLButtonUp](../Topic/CFrameWndEx::OnLButtonUp.md)|A estrutura chama esse método quando o usuário solta o botão esquerdo do mouse.|  
|[CFrameWndEx::OnMenuButtonToolHitTest](../Topic/CFrameWndEx::OnMenuButtonToolHitTest.md)|Chamado pela estrutura quando um objeto de `CMFCToolBarButton` processar uma mensagem de `WM_NCHITTEST` .|  
|[CFrameWndEx::OnMenuChar](../Topic/CFrameWndEx::OnMenuChar.md)|Chamado pela estrutura quando um menu é exibido e o usuário pressiona uma tecla que não corresponde a um comando.|  
|[CFrameWndEx::OnMouseMove](../Topic/CFrameWndEx::OnMouseMove.md)|A estrutura chama esse método quando o ponteiro se move.|  
|[CFrameWndEx::OnMoveMiniFrame](../Topic/CFrameWndEx::OnMoveMiniFrame.md)|Chamado pela estrutura quando uma janela do painel mover.|  
|[CFrameWndEx::OnNcActivate](../Topic/CFrameWndEx::OnNcActivate.md)|Chamado pela estrutura quando a área não\-cliente do quadro deve ser redesenhada para indicar uma alteração no estado ativo.|  
|[CFrameWndEx::OnNcCalcSize](../Topic/CFrameWndEx::OnNcCalcSize.md)|Chamado pela estrutura quando o tamanho e a posição da área cliente devem ser calculados.|  
|[CFrameWndEx::OnNcHitTest](../Topic/CFrameWndEx::OnNcHitTest.md)|Chamado pela estrutura quando o ponteiro se mover ou quando um botão do mouse é pressionado ou liberado.|  
|[CFrameWndEx::OnNcMouseMove](../Topic/CFrameWndEx::OnNcMouseMove.md)|Chamado pela estrutura quando o ponteiro se mover em uma área não cliente.|  
|[CFrameWndEx::OnNcPaint](../Topic/CFrameWndEx::OnNcPaint.md)|Chamado pela estrutura quando a área não\-cliente deve ser pintada.|  
|[CFrameWndEx::OnPaneCheck](../Topic/CFrameWndEx::OnPaneCheck.md)|Chamado pela estrutura para controlar a visibilidade de um painel.|  
|[CFrameWndEx::OnPostPreviewFrame](../Topic/CFrameWndEx::OnPostPreviewFrame.md)|Chamado pela estrutura quando o usuário alterar o modo de visualização de impressão.|  
|[CFrameWndEx::OnPowerBroadcast](../Topic/CFrameWndEx::OnPowerBroadcast.md)|Chamado pela estrutura quando um evento de gerenciamento de energia ocorrer.|  
|[CFrameWndEx::OnSetMenu](../Topic/CFrameWndEx::OnSetMenu.md)|Chamado pela estrutura para substituir o menu de janela do quadro.|  
|[CFrameWndEx::OnSetPreviewMode](../Topic/CFrameWndEx::OnSetPreviewMode.md)|Chamado pela estrutura para definir o modo de visualização de impressão para o quadro.|  
|[CFrameWndEx::OnSetText](../Topic/CFrameWndEx::OnSetText.md)|Chamado pela estrutura para definir o texto de uma janela.|  
|[CFrameWndEx::OnShowCustomizePane](../Topic/CFrameWndEx::OnShowCustomizePane.md)|Chamado pela estrutura quando um rápido personalizar o painel é ativado.|  
|[CFrameWndEx::OnShowPanes](../Topic/CFrameWndEx::OnShowPanes.md)|Chamado pela estrutura para mostrar ou ocultar os painéis.|  
|[CFrameWndEx::OnShowPopupMenu](../Topic/CFrameWndEx::OnShowPopupMenu.md)|Chamado pela estrutura quando um menu pop\-up é ativado.|  
|[CFrameWndEx::OnSize](../Topic/CFrameWndEx::OnSize.md)|A estrutura chama esse método após o tamanho de quadros muda.|  
|[CFrameWndEx::OnSizing](../Topic/CFrameWndEx::OnSizing.md)|A estrutura chama esse método quando o usuário redimensiona o quadro.|  
|[CFrameWndEx::OnSysColorChange](../Topic/CFrameWndEx::OnSysColorChange.md)|Chamado pela estrutura quando as cores do sistema alterado.|  
|[CFrameWndEx::OnTearOffMenu](../Topic/CFrameWndEx::OnTearOffMenu.md)|Chamado pela estrutura quando um menu que tenha uma barra de rasgo \- fora é ativado.|  
|[CFrameWndEx::OnToolbarContextMenu](../Topic/CFrameWndEx::OnToolbarContextMenu.md)|Chamado pela estrutura para criar um menu de contexto da barra de ferramentas.|  
|[CFrameWndEx::OnToolbarCreateNew](../Topic/CFrameWndEx::OnToolbarCreateNew.md)|A estrutura chama esse método para criar uma nova barra de ferramentas.|  
|[CFrameWndEx::OnToolbarDelete](../Topic/CFrameWndEx::OnToolbarDelete.md)|Chamado pela estrutura quando uma barra de ferramentas está exclusa.|  
|[CFrameWndEx::OnUpdateFrameMenu](../Topic/CFrameWndEx::OnUpdateFrameMenu.md)|Chamado pela estrutura para definir o menu do quadro.|  
|[CFrameWndEx::OnUpdateFrameTitle](../Topic/CFrameWndEx::OnUpdateFrameTitle.md)|A estrutura chama esse método para atualizar a barra de título da janela do quadro.|  
|[CFrameWndEx::OnUpdatePaneMenu](../Topic/CFrameWndEx::OnUpdatePaneMenu.md)|Chamado pela estrutura para atualizar o menu do painel.|  
|[CFrameWndEx::OnWindowPosChanged](../Topic/CFrameWndEx::OnWindowPosChanged.md)|Chamado pela estrutura quando o tamanho de quadros, a posição, ou a ordem z alterado devido a uma chamada para um método de gerenciamento de janela.|  
|[CFrameWndEx::PaneFromPoint](../Topic/CFrameWndEx::PaneFromPoint.md)|Retorna o painel de encaixe que contém o ponto especificado.|  
|[CFrameWndEx::PreTranslateMessage](../Topic/CFrameWndEx::PreTranslateMessage.md)|Mensagens específicas da janela handles antes que elas sejam despachados.|  
|[CFrameWndEx::RecalcLayout](../Topic/CFrameWndEx::RecalcLayout.md)|Ajustar o layout do quadro e suas janelas filho.|  
|[CFrameWndEx::RemovePaneFromDockManager](../Topic/CFrameWndEx::RemovePaneFromDockManager.md)|Desregistre um painel e remova\-o da lista interna no gerenciador de encaixe.|  
|[CFrameWndEx::SetDockState](../Topic/CFrameWndEx::SetDockState.md)|Restaura o layout de encaixe para o estado de encaixe armazenado no Registro.|  
|[CFrameWndEx::SetPrintPreviewFrame](../Topic/CFrameWndEx::SetPrintPreviewFrame.md)|Define a janela de quadro de visualização de impressão.|  
|[CFrameWndEx::SetupToolbarMenu](../Topic/CFrameWndEx::SetupToolbarMenu.md)|Insere comandos definidos pelo usuário em um menu da barra de ferramentas.|  
|[CFrameWndEx::ShowFullScreen](../Topic/CFrameWndEx::ShowFullScreen.md)|Alterna o quadro chave entre a tela inteira e os modos normal.|  
|[CFrameWndEx::ShowPane](../Topic/CFrameWndEx::ShowPane.md)|Mostra ou oculta o painel especificado.|  
|[CFrameWndEx::UpdateCaption](../Topic/CFrameWndEx::UpdateCaption.md)|Chamado pela estrutura para atualizar a legenda de moldura da janela.|  
|[CFrameWndEx::WinHelp](../Topic/CFrameWndEx::WinHelp.md)|Chama o aplicativo de `WinHelp` ou a ajuda relacionada contexto.|  
  
## Exemplo  
 O exemplo a seguir demonstra como herdar uma classe de classe de `CFrameWndEx` .  O exemplo ilustra as assinaturas de método na subclasse, e como substituir o método de `OnShowPopupMenu` .  Este trecho de código é parte de [Exemplo de preenchimento da palavra](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#3](../../mfc/reference/codesnippet/CPP/cframewndex-class_1.h)]  
[!code-cpp[NVC_MFC_WordPad#4](../../mfc/reference/codesnippet/CPP/cframewndex-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CFrameWndEx](../../mfc/reference/cframewndex-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxframewndex.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)