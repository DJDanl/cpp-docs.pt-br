---
title: "Classe de CMFCVisualManager | Microsoft Docs"
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
  - "CMFCVisualManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCVisualManager"
ms.assetid: beed80f7-36a2-4d64-9f09-e807cfefc3fe
caps.latest.revision: 58
caps.handback.revision: 46
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCVisualManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece suporte para alterar a aparência do seu aplicativo no nível global.  A classe de `CMFCVisualManager` trabalha junto com uma classe que fornece instruções para desenhar os controles de GUI do seu aplicativo usando um estilo consistente.  Essas outras classes são referenciadas visual como gerentes e herdam de `CMFCBaseVisualManager`.  
  
## Sintaxe  
  
```  
class CMFCVisualManager : public CMFCBaseVisualManager  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCVisualManager::CMFCVisualManager`|Construtor padrão.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCVisualManager::AdjustFrames](../Topic/CMFCVisualManager::AdjustFrames.md)||  
|[CMFCVisualManager::AdjustToolbars](../Topic/CMFCVisualManager::AdjustToolbars.md)||  
|[CMFCVisualManager::AlwaysHighlight3DTabs](../Topic/CMFCVisualManager::AlwaysHighlight3DTabs.md)|Chamado pela estrutura para determinar se as guias 3D devem sempre ser desenhados usando uma cor de realce.|  
|[CMFCVisualManager::DestroyInstance](../Topic/CMFCVisualManager::DestroyInstance.md)||  
|[CMFCVisualManager::DoDrawHeaderSortArrow](../Topic/CMFCVisualManager::DoDrawHeaderSortArrow.md)||  
|[CMFCVisualManager::DrawComboDropButtonWinXP](../Topic/CMFCVisualManager::DrawComboDropButtonWinXP.md)||  
|[CMFCVisualManager::DrawPushButtonWinXP](../Topic/CMFCVisualManager::DrawPushButtonWinXP.md)||  
|[CMFCVisualManager::DrawTextOnGlass](../Topic/CMFCVisualManager::DrawTextOnGlass.md)||  
|[CMFCVisualManager::GetAutoHideButtonTextColor](../Topic/CMFCVisualManager::GetAutoHideButtonTextColor.md)|Chamado pela estrutura para recuperar a cor do texto para um automática ocultar o botão.|  
|[CMFCVisualManager::GetButtonExtraBorder](../Topic/CMFCVisualManager::GetButtonExtraBorder.md)|Chamado pela estrutura para recuperar o tamanho do botão gerado que o gerenciador visual atual necessário para desenhar um botão.|  
|[CMFCVisualManager::GetCaptionBarTextColor](../Topic/CMFCVisualManager::GetCaptionBarTextColor.md)|Chamado pela estrutura para recuperar a cor do texto de uma barra de título.|  
|[CMFCVisualManager::GetDockingTabsBordersSize](../Topic/CMFCVisualManager::GetDockingTabsBordersSize.md)|Chamado pela estrutura para recuperar o tamanho da borda de uma barra com guias entrada.|  
|[CMFCVisualManager::GetHighlightedMenuItemTextColor](../Topic/CMFCVisualManager::GetHighlightedMenuItemTextColor.md)||  
|[CMFCVisualManager::GetInstance](../Topic/CMFCVisualManager::GetInstance.md)|Retorna um ponteiro para o objeto de `CMFCVisualManager` .|  
|[CMFCVisualManager::GetMDITabsBordersSize](../Topic/CMFCVisualManager::GetMDITabsBordersSize.md)|Chamado pela estrutura para recuperar o tamanho da borda da janela de MDITabs.|  
|[CMFCVisualManager::GetMenuItemTextColor](../Topic/CMFCVisualManager::GetMenuItemTextColor.md)||  
|[CMFCVisualManager::GetMenuShadowDepth](../Topic/CMFCVisualManager::GetMenuShadowDepth.md)|Retorna um valor que determina a largura e altura de uma sombra do menu.|  
|[CMFCVisualManager::GetNcBtnSize](../Topic/CMFCVisualManager::GetNcBtnSize.md)|Chamado pela estrutura para determinar o tamanho dos botões do sistema baseados em gerenciador visual atual.  Os botões do sistema são os botões na legenda de quadro chave que mapeiam para comandos **Fechar**, **Minimizar**, **Maximizar**, e **Restaurar**.|  
|[CMFCVisualManager::GetPopupMenuBorderSize](../Topic/CMFCVisualManager::GetPopupMenuBorderSize.md)|Chamado pela estrutura para recuperar o tamanho da borda para um menu pop\-up.|  
|[CMFCVisualManager::GetPropertyGridGroupColor](../Topic/CMFCVisualManager::GetPropertyGridGroupColor.md)|Chamado pela estrutura para recuperar a cor do plano de fundo de uma lista de propriedades.|  
|[CMFCVisualManager::GetPropertyGridGroupTextColor](../Topic/CMFCVisualManager::GetPropertyGridGroupTextColor.md)|Chamado pela estrutura para recuperar a cor do texto de uma lista de propriedades.|  
|[CMFCVisualManager::GetRibbonHyperlinkTextColor](../Topic/CMFCVisualManager::GetRibbonHyperlinkTextColor.md)||  
|[CMFCVisualManager::GetRibbonPopupBorderSize](../Topic/CMFCVisualManager::GetRibbonPopupBorderSize.md)||  
|[CMFCVisualManager::GetRibbonQuickAccessToolBarTextColor](../Topic/CMFCVisualManager::GetRibbonQuickAccessToolBarTextColor.md)||  
|[CMFCVisualManager::GetRibbonSliderColors](../Topic/CMFCVisualManager::GetRibbonSliderColors.md)||  
|[CMFCVisualManager::GetShowAllMenuItemsHeight](../Topic/CMFCVisualManager::GetShowAllMenuItemsHeight.md)||  
|[CMFCVisualManager::GetSmartDockingBaseGuideColors](../Topic/CMFCVisualManager::GetSmartDockingBaseGuideColors.md)||  
|[CMFCVisualManager::GetSmartDockingHighlightToneColor](../Topic/CMFCVisualManager::GetSmartDockingHighlightToneColor.md)||  
|[CMFCVisualManager::GetSmartDockingTheme](../Topic/CMFCVisualManager::GetSmartDockingTheme.md)|Retorna um tema usado para exibir marcadores inteligentes de encaixe.|  
|[CMFCVisualManager::GetStatusBarPaneTextColor](../Topic/CMFCVisualManager::GetStatusBarPaneTextColor.md)||  
|[CMFCVisualManager::GetTabFrameColors](../Topic/CMFCVisualManager::GetTabFrameColors.md)|Chamado pela estrutura para recuperar o conjunto de cores para usar quando desenha um quadro de tabulação.|  
|[CMFCVisualManager::GetTabTextColor](../Topic/CMFCVisualManager::GetTabTextColor.md)||  
|[CMFCVisualManager::GetToolbarButtonTextColor](../Topic/CMFCVisualManager::GetToolbarButtonTextColor.md)|Chamado pela estrutura para recuperar a cor do texto atual no botão da barra de ferramentas.  Esta cor varia de acordo com o gerenciador visual atual e o estado do botão.|  
|[CMFCVisualManager::GetToolbarDisabledTextColor](../Topic/CMFCVisualManager::GetToolbarDisabledTextColor.md)|Chamado pela estrutura para determinar a cor do texto que é exibido nos elementos desativados da barra de ferramentas.|  
|[CMFCVisualManager::GetToolbarHighlightColor](../Topic/CMFCVisualManager::GetToolbarHighlightColor.md)||  
|[CMFCVisualManager::GetToolTipInfo](../Topic/CMFCVisualManager::GetToolTipInfo.md)||  
|[CMFCVisualManager::HasOverlappedAutoHideButtons](../Topic/CMFCVisualManager::HasOverlappedAutoHideButtons.md)|Especifica se os botões de sobreposição automática ocultar.|  
|[CMFCVisualManager::IsDockingTabHasBorder](../Topic/CMFCVisualManager::IsDockingTabHasBorder.md)|Especifica se o gerenciador visual atual desenha uma borda ao redor de barras de encaixe com guias.|  
|[CMFCVisualManager::IsEmbossDisabledImage](../Topic/CMFCVisualManager::IsEmbossDisabledImage.md)|Especifica se as imagens desativado devem ser colocar em alto\-relevos.|  
|[CMFCVisualManager::IsFadeInactiveImage](../Topic/CMFCVisualManager::IsFadeInactiveImage.md)|Chamado pela estrutura para determinar se as imagens inativa em uma barra de ferramentas ou em um menu aparecem permanecerá esmaecido.|  
|[CMFCVisualManager::IsMenuFlatLook](../Topic/CMFCVisualManager::IsMenuFlatLook.md)|Especifica se os botões de menu tem uma aparência aplainada.|  
|[CMFCVisualManager::IsOfficeXPStyleMenus](../Topic/CMFCVisualManager::IsOfficeXPStyleMenus.md)|Especifica se o gerenciador visual implementa menus de XP\- estilo do Office.|  
|[CMFCVisualManager::IsOwnerDrawCaption](../Topic/CMFCVisualManager::IsOwnerDrawCaption.md)|Especifica se o gerenciador visual atual implementa legendas desenhadas proprietário de uma janela do quadro.|  
|[CMFCVisualManager::IsShadowHighlightedImage](../Topic/CMFCVisualManager::IsShadowHighlightedImage.md)|Especifica se uma imagem realçado tem uma sombra.|  
|[CMFCVisualManager::OnDrawAutoHideButtonBorder](../Topic/CMFCVisualManager::OnDrawAutoHideButtonBorder.md)|Quando chamado pela estrutura para desenhar a borda de um botão. automática ocultar|  
|[CMFCVisualManager::OnDrawBarGripper](../Topic/CMFCVisualManager::OnDrawBarGripper.md)|Chamado pela estrutura quando desenhar a alça de uma barra de controle.  O usuário deve clicar na alça para mover a barra de controle.|  
|[CMFCVisualManager::OnDrawBrowseButton](../Topic/CMFCVisualManager::OnDrawBrowseButton.md)|Chamado pela estrutura quando desenhando um botão procurar que pertence a um controle de edição \([Classe de CMFCEditBrowseCtrl](../Topic/CMFCEditBrowseCtrl%20Class.md)\).|  
|[CMFCVisualManager::OnDrawButtonBorder](../Topic/CMFCVisualManager::OnDrawButtonBorder.md)|Chamado pela estrutura quando desenhar a borda de um botão da barra de ferramentas.|  
|[CMFCVisualManager::OnDrawButtonSeparator](../Topic/CMFCVisualManager::OnDrawButtonSeparator.md)||  
|[CMFCVisualManager::OnDrawCaptionBarBorder](../Topic/CMFCVisualManager::OnDrawCaptionBarBorder.md)|Chamado pela estrutura quando desenhar a borda da barra de título.|  
|[CMFCVisualManager::OnDrawCaptionBarButtonBorder](../Topic/CMFCVisualManager::OnDrawCaptionBarButtonBorder.md)||  
|[CMFCVisualManager::OnDrawCaptionBarInfoArea](../Topic/CMFCVisualManager::OnDrawCaptionBarInfoArea.md)||  
|[CMFCVisualManager::OnDrawCaptionButton](../Topic/CMFCVisualManager::OnDrawCaptionButton.md)|Chamado pela estrutura quando desenhando um botão da barra de título.|  
|[CMFCVisualManager::OnDrawCheckBox](../Topic/CMFCVisualManager::OnDrawCheckBox.md)||  
|[CMFCVisualManager::OnDrawCheckBoxEx](../Topic/CMFCVisualManager::OnDrawCheckBoxEx.md)||  
|[CMFCVisualManager::OnDrawComboBorder](../Topic/CMFCVisualManager::OnDrawComboBorder.md)|Chamado pela estrutura quando desenhar a borda de um botão da caixa combo.|  
|[CMFCVisualManager::OnDrawComboDropButton](../Topic/CMFCVisualManager::OnDrawComboDropButton.md)|Chamado pela estrutura quando desenhando um botão suspenso da caixa combo.|  
|[CMFCVisualManager::OnDrawControlBorder](../Topic/CMFCVisualManager::OnDrawControlBorder.md)||  
|[CMFCVisualManager::OnDrawDefaultRibbonImage](../Topic/CMFCVisualManager::OnDrawDefaultRibbonImage.md)|Chamado pela estrutura quando desenhar a imagem padrão de fita.|  
|[CMFCVisualManager::OnDrawEditBorder](../Topic/CMFCVisualManager::OnDrawEditBorder.md)|Chamado pela estrutura quando desenhando uma borda ao redor de um objeto de [CMFCToolBarEditBoxButton](../Topic/CMFCToolBarEditBoxButton%20Class.md) .|  
|[CMFCVisualManager::OnDrawExpandingBox](../Topic/CMFCVisualManager::OnDrawExpandingBox.md)||  
|[CMFCVisualManager::OnDrawFloatingToolbarBorder](../Topic/CMFCVisualManager::OnDrawFloatingToolbarBorder.md)|Chamado pela estrutura quando desenhando as bordas de uma barra de ferramentas flutuante.  A barra de ferramentas flutuante é uma barra de ferramentas que aparece como uma janela de mini\-linguagem quadro.|  
|[CMFCVisualManager::OnDrawHeaderCtrlBorder](../Topic/CMFCVisualManager::OnDrawHeaderCtrlBorder.md)|Chamado pela estrutura quando desenhar a borda que contém o controle cabeçalho.|  
|[CMFCVisualManager::OnDrawHeaderCtrlSortArrow](../Topic/CMFCVisualManager::OnDrawHeaderCtrlSortArrow.md)|Chamado pela estrutura quando desenhar a seta do tipo de controle header.|  
|[CMFCVisualManager::OnDrawMenuArrowOnCustomizeList](../Topic/CMFCVisualManager::OnDrawMenuArrowOnCustomizeList.md)||  
|[CMFCVisualManager::OnDrawMenuBorder](../Topic/CMFCVisualManager::OnDrawMenuBorder.md)|Chamado pela estrutura quando desenhando uma borda do menu.|  
|[CMFCVisualManager::OnDrawMenuCheck](../Topic/CMFCVisualManager::OnDrawMenuCheck.md)||  
|[CMFCVisualManager::OnDrawMenuItemButton](../Topic/CMFCVisualManager::OnDrawMenuItemButton.md)||  
|[CMFCVisualManager::OnDrawMenuLabel](../Topic/CMFCVisualManager::OnDrawMenuLabel.md)||  
|[CMFCVisualManager::OnDrawMenuResizeBar](../Topic/CMFCVisualManager::OnDrawMenuResizeBar.md)||  
|[CMFCVisualManager::OnDrawMenuScrollButton](../Topic/CMFCVisualManager::OnDrawMenuScrollButton.md)|Chamado pela estrutura quando desenhando um botão de rolagem do menu.|  
|[CMFCVisualManager::OnDrawMenuShadow](../Topic/CMFCVisualManager::OnDrawMenuShadow.md)||  
|[CMFCVisualManager::OnDrawMenuSystemButton](../Topic/CMFCVisualManager::OnDrawMenuSystemButton.md)|Chamado pela estrutura quando desenha o sistema de menu botão **Fechar**, **Minimizar**, **Maximizar**, e **Restaurar**.|  
|[CMFCVisualManager::OnDrawMiniFrameBorder](../Topic/CMFCVisualManager::OnDrawMiniFrameBorder.md)||  
|[CMFCVisualManager::OnDrawOutlookBarSplitter](../Topic/CMFCVisualManager::OnDrawOutlookBarSplitter.md)|Chamado pela estrutura quando desenhando o separador para uma barra do Outlook.  O separador é uma barra horizontal usada para agrupar controles.|  
|[CMFCVisualManager::OnDrawOutlookPageButtonBorder](../Topic/CMFCVisualManager::OnDrawOutlookPageButtonBorder.md)|Chamado pela estrutura quando desenhar a borda de um botão da página do Outlook.  Os botões de página do Outlook parecem se o painel de barra do Outlook contém mais botões de que ele pode exibir.|  
|[CMFCVisualManager::OnDrawPaneBorder](../Topic/CMFCVisualManager::OnDrawPaneBorder.md)|Chamado pela estrutura quando desenhar a borda de [Classe de CPane](../../mfc/reference/cpane-class.md).|  
|[CMFCVisualManager::OnDrawPaneCaption](../Topic/CMFCVisualManager::OnDrawPaneCaption.md)|Chamado pela estrutura quando desenhar a legenda para `CPane`.|  
|[CMFCVisualManager::OnDrawPaneDivider](../Topic/CMFCVisualManager::OnDrawPaneDivider.md)||  
|[CMFCVisualManager::OnDrawPopupWindowBorder](../Topic/CMFCVisualManager::OnDrawPopupWindowBorder.md)||  
|[CMFCVisualManager::OnDrawPopupWindowButtonBorder](../Topic/CMFCVisualManager::OnDrawPopupWindowButtonBorder.md)||  
|[CMFCVisualManager::OnDrawPopupWindowCaption](../Topic/CMFCVisualManager::OnDrawPopupWindowCaption.md)||  
|[CMFCVisualManager::OnDrawRibbonApplicationButton](../Topic/CMFCVisualManager::OnDrawRibbonApplicationButton.md)|Quando chamado pela estrutura **Botão Principal** desenhar em fita.|  
|[CMFCVisualManager::OnDrawRibbonButtonBorder](../Topic/CMFCVisualManager::OnDrawRibbonButtonBorder.md)|Chamado pela estrutura quando desenhar a borda de um botão de fita.|  
|[CMFCVisualManager::OnDrawRibbonButtonsGroup](../Topic/CMFCVisualManager::OnDrawRibbonButtonsGroup.md)|Chamado pela estrutura quando desenhando um grupo de botões em fita.|  
|[CMFCVisualManager::OnDrawRibbonCaption](../Topic/CMFCVisualManager::OnDrawRibbonCaption.md)|Chamado pela estrutura quando desenhar a legenda do quadro chave, mas somente se a barra de fita está integrado com o quadro.|  
|[CMFCVisualManager::OnDrawRibbonCaptionButton](../Topic/CMFCVisualManager::OnDrawRibbonCaptionButton.md)|Chamado pela estrutura quando desenhando um botão de legenda localizado na barra de fita.|  
|[CMFCVisualManager::OnDrawRibbonCategory](../Topic/CMFCVisualManager::OnDrawRibbonCategory.md)|Chamado pela estrutura quando desenhando uma categoria de fita.|  
|[CMFCVisualManager::OnDrawRibbonCategoryCaption](../Topic/CMFCVisualManager::OnDrawRibbonCategoryCaption.md)|Chamado pela estrutura quando a legenda para desenhar uma categoria de fita.|  
|[CMFCVisualManager::OnDrawRibbonCategoryScroll](../Topic/CMFCVisualManager::OnDrawRibbonCategoryScroll.md)||  
|[CMFCVisualManager::OnDrawRibbonCategoryTab](../Topic/CMFCVisualManager::OnDrawRibbonCategoryTab.md)|Chamado pela estrutura quando a guia para desenhar uma categoria de fita.|  
|[CMFCVisualManager::OnDrawRibbonCheckBoxOnList](../Topic/CMFCVisualManager::OnDrawRibbonCheckBoxOnList.md)||  
|[CMFCVisualManager::OnDrawRibbonColorPaletteBox](../Topic/CMFCVisualManager::OnDrawRibbonColorPaletteBox.md)||  
|[CMFCVisualManager::OnDrawRibbonDefaultPaneButtonContext](../Topic/CMFCVisualManager::OnDrawRibbonDefaultPaneButtonContext.md)||  
|[CMFCVisualManager::OnDrawRibbonDefaultPaneButton](../Topic/CMFCVisualManager::OnDrawRibbonDefaultPaneButton.md)|Chamado pela estrutura quando desenhando o botão padrão do painel fita.  O botão padrão aparece quando o usuário reduz um painel de fita de modo que é muito pequeno exibir os elementos de fita.  O botão padrão é desenhado por vez e elementos de fita são adicionados como itens em um menu suspenso.|  
|[CMFCVisualManager::OnDrawRibbonDefaultPaneButtonIndicator](../Topic/CMFCVisualManager::OnDrawRibbonDefaultPaneButtonIndicator.md)||  
|[CMFCVisualManager::OnDrawRibbonGalleryBorder](../Topic/CMFCVisualManager::OnDrawRibbonGalleryBorder.md)||  
|[CMFCVisualManager::OnDrawRibbonGalleryButton](../Topic/CMFCVisualManager::OnDrawRibbonGalleryButton.md)||  
|[CMFCVisualManager::OnDrawRibbonKeyTip](../Topic/CMFCVisualManager::OnDrawRibbonKeyTip.md)||  
|[CMFCVisualManager::OnDrawRibbonLabel](../Topic/CMFCVisualManager::OnDrawRibbonLabel.md)|Chamado pela estrutura quando desenhando o rótulo de fita.|  
|[CMFCVisualManager::OnDrawRibbonMainPanelButtonBorder](../Topic/CMFCVisualManager::OnDrawRibbonMainPanelButtonBorder.md)|Chamado pela estrutura quando desenhar a borda de um botão de fita que está localizado no painel de **Principal** .  O painel de **Principal** é o painel que aparece quando um usuário clica em **Botão Principal**.|  
|[CMFCVisualManager::OnDrawRibbonMainPanelFrame](../Topic/CMFCVisualManager::OnDrawRibbonMainPanelFrame.md)|Chamado pela estrutura quando desenhando o quadro ao redor do painel de **Principal** .|  
|[CMFCVisualManager::OnDrawRibbonMenuCheckFrame](../Topic/CMFCVisualManager::OnDrawRibbonMenuCheckFrame.md)||  
|[CMFCVisualManager::OnDrawRibbonPanel](../Topic/CMFCVisualManager::OnDrawRibbonPanel.md)|Chamado pela estrutura quando desenhando um painel de fita.|  
|[CMFCVisualManager::OnDrawRibbonPanelCaption](../Topic/CMFCVisualManager::OnDrawRibbonPanelCaption.md)|Chamado pela estrutura quando desenhar a legenda de um painel de fita.|  
|[CMFCVisualManager::OnDrawRibbonProgressBar](../Topic/CMFCVisualManager::OnDrawRibbonProgressBar.md)|Chamado pela estrutura quando desenhando um objeto de [CMFCRibbonProgressBar](../../mfc/reference/cmfcribbonprogressbar-class.md) .|  
|[CMFCVisualManager::OnDrawRibbonQuickAccessToolBarSeparator](../Topic/CMFCVisualManager::OnDrawRibbonQuickAccessToolBarSeparator.md)|Chamado pela estrutura quando desenhando um separador em **Barra de Ferramentas de Acesso Rápido**de uma fita.|  
|[CMFCVisualManager::OnDrawRibbonRecentFilesFrame](../Topic/CMFCVisualManager::OnDrawRibbonRecentFilesFrame.md)|Chamado pela estrutura quando desenhando um quadro ao redor de uma lista recente dos arquivos.|  
|[CMFCVisualManager::OnDrawRibbonSliderChannel](../Topic/CMFCVisualManager::OnDrawRibbonSliderChannel.md)|Chamado pela estrutura quando desenhando o canal de um objeto de [CMFCRibbonSlider](../../mfc/reference/cmfcribbonslider-class.md) .|  
|[CMFCVisualManager::OnDrawRibbonSliderThumb](../Topic/CMFCVisualManager::OnDrawRibbonSliderThumb.md)|Chamado pela estrutura quando desenhando o ícone de um objeto de `CMFCRibbonSlider` .|  
|[CMFCVisualManager::OnDrawRibbonSliderZoomButton](../Topic/CMFCVisualManager::OnDrawRibbonSliderZoomButton.md)|Chamado pela estrutura quando desenhando os botões de zoom de um objeto de `CMFCRibbonSlider` .|  
|[CMFCVisualManager::OnDrawRibbonStatusBarPane](../Topic/CMFCVisualManager::OnDrawRibbonStatusBarPane.md)|Chamado pela estrutura quando desenhando o painel de barra de status de uma fita.|  
|[CMFCVisualManager::OnDrawRibbonTabsFrame](../Topic/CMFCVisualManager::OnDrawRibbonTabsFrame.md)|Chamado pela estrutura quando desenhando um quadro ao redor de um conjunto de guias de fita.|  
|[CMFCVisualManager::OnDrawScrollButtons](../Topic/CMFCVisualManager::OnDrawScrollButtons.md)||  
|[CMFCVisualManager::OnDrawSeparator](../Topic/CMFCVisualManager::OnDrawSeparator.md)|Chamado pela estrutura quando desenhando um separador.  O separador é normalmente usado em uma barra de controle para separar grupos de ícones.|  
|[CMFCVisualManager::OnDrawShowAllMenuItems](../Topic/CMFCVisualManager::OnDrawShowAllMenuItems.md)||  
|[CMFCVisualManager::OnDrawSpinButtons](../Topic/CMFCVisualManager::OnDrawSpinButtons.md)|Chamado pela estrutura quando desenhando os botões de rotação.|  
|[CMFCVisualManager::OnDrawSplitterBorder](../Topic/CMFCVisualManager::OnDrawSplitterBorder.md)|Chamado pela estrutura quando desenhar a borda de uma janela de divisão.|  
|[CMFCVisualManager::OnDrawSplitterBox](../Topic/CMFCVisualManager::OnDrawSplitterBox.md)|Chamado pela estrutura quando desenhar a caixa da direita do separador para uma janela de divisão.|  
|[CMFCVisualManager::OnDrawStatusBarPaneBorder](../Topic/CMFCVisualManager::OnDrawStatusBarPaneBorder.md)|Chamado pela estrutura quando desenhar a borda de um painel statusbar.|  
|[CMFCVisualManager::OnDrawStatusBarProgress](../Topic/CMFCVisualManager::OnDrawStatusBarProgress.md)|Chamado pela estrutura quando desenhando o indicador de progresso da barra de status.|  
|[CMFCVisualManager::OnDrawStatusBarSizeBox](../Topic/CMFCVisualManager::OnDrawStatusBarSizeBox.md)|Chamado pela estrutura quando desenhar a caixa de tamanho da barra de status.|  
|[CMFCVisualManager::OnDrawTab](../Topic/CMFCVisualManager::OnDrawTab.md)|Chamado pela estrutura quando desenhando um objeto de [CMFCTabCtrl](../../mfc/reference/cmfctabctrl-class.md) .|  
|[CMFCVisualManager::OnDrawTabCloseButton](../Topic/CMFCVisualManager::OnDrawTabCloseButton.md)|Chamado pela estrutura quando desenhando o botão de **Fechar** na guia.|  
|[CMFCVisualManager::OnDrawTabContent](../Topic/CMFCVisualManager::OnDrawTabContent.md)|Chamado pela estrutura quando desenhando o interior da guia \(imagens, texto\).|  
|[CMFCVisualManager::OnDrawTabsButtonBorder](../Topic/CMFCVisualManager::OnDrawTabsButtonBorder.md)|Chamado pela estrutura quando desenhar a borda de um botão na guia.|  
|[CMFCVisualManager::OnDrawTask](../Topic/CMFCVisualManager::OnDrawTask.md)|Chamado pela estrutura quando desenhando uma tarefa no painel de tarefas.|  
|[CMFCVisualManager::OnDrawTasksGroupAreaBorder](../Topic/CMFCVisualManager::OnDrawTasksGroupAreaBorder.md)|Chamado pela estrutura quando desenhando uma borda ao redor de uma área do grupo no painel de tarefas.|  
|[CMFCVisualManager::OnDrawTasksGroupCaption](../Topic/CMFCVisualManager::OnDrawTasksGroupCaption.md)|Chamado pela estrutura quando desenhar a legenda para um grupo de trabalho no painel de tarefas.|  
|[CMFCVisualManager::OnDrawTasksGroupIcon](../Topic/CMFCVisualManager::OnDrawTasksGroupIcon.md)||  
|[CMFCVisualManager::OnDrawTearOffCaption](../Topic/CMFCVisualManager::OnDrawTearOffCaption.md)|Chamado pela estrutura quando desenhar a legenda de rasgo \- fora de uma barra de rasgo \- fora.|  
|[CMFCVisualManager::OnDrawToolBoxFrame](../Topic/CMFCVisualManager::OnDrawToolBoxFrame.md)||  
|[CMFCVisualManager::OnEraseMDIClientArea](../Topic/CMFCVisualManager::OnEraseMDIClientArea.md)|Chamado pela estrutura quando apagar a área cliente MDI.|  
|[CMFCVisualManager::OnErasePopupWindowButton](../Topic/CMFCVisualManager::OnErasePopupWindowButton.md)||  
|[CMFCVisualManager::OnEraseTabsArea](../Topic/CMFCVisualManager::OnEraseTabsArea.md)|Chamado pela estrutura quando apagar a área da guia em uma janela na guia.|  
|[CMFCVisualManager::OnEraseTabsButton](../Topic/CMFCVisualManager::OnEraseTabsButton.md)|Chamado pela estrutura quando apagar o ícone e o texto de um botão na guia.|  
|[CMFCVisualManager::OnEraseTabsFrame](../Topic/CMFCVisualManager::OnEraseTabsFrame.md)|Chamado pela estrutura quando apagar um quadro de tabulação.|  
|[CMFCVisualManager::OnFillAutoHideButtonBackground](../Topic/CMFCVisualManager::OnFillAutoHideButtonBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de um botão. de incrementos ocultar|  
|[CMFCVisualManager::OnFillBarBackground](../Topic/CMFCVisualManager::OnFillBarBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de uma barra de controle.|  
|[CMFCVisualManager::OnFillButtonInterior](../Topic/CMFCVisualManager::OnFillButtonInterior.md)|Chamado pela estrutura quando preencher o plano de fundo de um botão da barra de ferramentas.|  
|[CMFCVisualManager::OnFillCaptionBarButton](../Topic/CMFCVisualManager::OnFillCaptionBarButton.md)||  
|[CMFCVisualManager::OnFillCommandsListBackground](../Topic/CMFCVisualManager::OnFillCommandsListBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de um botão da barra de ferramentas que pertence a uma lista de comando que, por sua vez, é parte de uma caixa de diálogo de personalização.|  
|[CMFCVisualManager::OnFillHeaderCtrlBackground](../Topic/CMFCVisualManager::OnFillHeaderCtrlBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de um controle de cabeçalho.|  
|[CMFCVisualManager::OnFillMiniFrameCaption](../Topic/CMFCVisualManager::OnFillMiniFrameCaption.md)|Chamado pela estrutura quando preencher a legenda de uma janela mini do quadro.|  
|[CMFCVisualManager::OnFillOutlookBarCaption](../Topic/CMFCVisualManager::OnFillOutlookBarCaption.md)|Chamado pela estrutura quando preencher o plano de fundo de uma legenda de barra do Outlook.|  
|[CMFCVisualManager::OnFillOutlookPageButton](../Topic/CMFCVisualManager::OnFillOutlookPageButton.md)|Chamado pela estrutura quando preencher o interior de um botão na página do Outlook.|  
|[CMFCVisualManager::OnFillPopupWindowBackground](../Topic/CMFCVisualManager::OnFillPopupWindowBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de uma janela pop\-up.|  
|[CMFCVisualManager::OnFillRibbonButton](../Topic/CMFCVisualManager::OnFillRibbonButton.md)|Chamado pela estrutura quando preencher o interior de um botão de fita.|  
|[CMFCVisualManager::OnFillRibbonEdit](../Topic/CMFCVisualManager::OnFillRibbonEdit.md)|Chamado pela estrutura quando preencher o interior de um controle de edição de fita.|  
|[CMFCVisualManager::OnFillRibbonMainPanelButton](../Topic/CMFCVisualManager::OnFillRibbonMainPanelButton.md)|Chamado pela estrutura quando preencher o interior de um botão de fita posicionado no painel de **Principal** .|  
|[CMFCVisualManager::OnFillRibbonMenuFrame](../Topic/CMFCVisualManager::OnFillRibbonMenuFrame.md)|Chamado pela estrutura quando preencher o quadro de menu do painel principal de fita.|  
|[CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup](../Topic/CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup.md)||  
|[CMFCVisualManager::OnFillSplitterBackground](../Topic/CMFCVisualManager::OnFillSplitterBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de uma janela de divisão.|  
|[CMFCVisualManager::OnFillTab](../Topic/CMFCVisualManager::OnFillTab.md)|Chamado pela estrutura quando preencher o plano de fundo de um guia.|  
|[CMFCVisualManager::OnFillTasksGroupInterior](../Topic/CMFCVisualManager::OnFillTasksGroupInterior.md)|Chamado pela estrutura quando preencher o interior de um objeto de [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) em [CMFCTasksPane](../Topic/CMFCTasksPane%20Class.md).|  
|[CMFCVisualManager::OnFillTasksPaneBackground](../Topic/CMFCVisualManager::OnFillTasksPaneBackground.md)|Chamado pela estrutura quando preencher o plano de fundo de um controle de `CMFCTasksPane` .|  
|[CMFCVisualManager::OnHighlightMenuItem](../Topic/CMFCVisualManager::OnHighlightMenuItem.md)|Chamado pela estrutura quando desenhando um item de menu realçado.|  
|[CMFCVisualManager::OnHighlightRarelyUsedMenuItems](../Topic/CMFCVisualManager::OnHighlightRarelyUsedMenuItems.md)|Chamado pela estrutura quando desenhando um item de menu realçado e raramente usados.|  
|[CMFCVisualManager::OnNcPaint](../Topic/CMFCVisualManager::OnNcPaint.md)|Chamado pela estrutura quando desenhar a área não cliente.|  
|[CMFCVisualManager::OnSetWindowRegion](../Topic/CMFCVisualManager::OnSetWindowRegion.md)|Chamado pela estrutura quando definir uma região que contém quadros e menus pop\-up.|  
|[CMFCVisualManager::OnUpdateSystemColors](../Topic/CMFCVisualManager::OnUpdateSystemColors.md)|Chamado pela estrutura quando alterar a configuração de cor do sistema.|  
|[CMFCVisualManager::RedrawAll](../Topic/CMFCVisualManager::RedrawAll.md)|Redesenho de todas as barras controle no aplicativo.|  
|[CMFCVisualManager::RibbonCategoryColorToRGB](../Topic/CMFCVisualManager::RibbonCategoryColorToRGB.md)||  
|[CMFCVisualManager::SetDefaultManager](../Topic/CMFCVisualManager::SetDefaultManager.md)|Define o gerenciador visual padrão.|  
|[CMFCVisualManager::SetEmbossDisabledImage](../Topic/CMFCVisualManager::SetEmbossDisabledImage.md)|Habilita ou desabilita o modo de alto relevo para imagens desativados da barra de ferramentas.|  
|[CMFCVisualManager::SetFadeInactiveImage](../Topic/CMFCVisualManager::SetFadeInactiveImage.md)|Habilita ou desabilita o efeito de luz para imagens inativa em um menu ou na barra de ferramentas.|  
|[CMFCVisualManager::SetMenuFlatLook](../Topic/CMFCVisualManager::SetMenuFlatLook.md)|Define um sinalizador que indica se os botões de menu do aplicativo têm uma aparência aplainada.|  
|[CMFCVisualManager::SetMenuShadowDepth](../Topic/CMFCVisualManager::SetMenuShadowDepth.md)|Defina a largura e altura de sombra do menu.|  
|[CMFCVisualManager::SetShadowHighlightedImage](../Topic/CMFCVisualManager::SetShadowHighlightedImage.md)|Define um sinalizador que indica se exibir a sombra para renderizar imagens realçadas.|  
  
## Comentários  
 Porque a classe de `CMFCVisualManager` controla GUI do aplicativo, cada aplicativo pode ter uma instância de `CMFCVisualManager`, ou uma instância de uma classe derivada de `CMFCVisualManager`.  Seu aplicativo pode também funciona sem `CMFCVisualManager`.  Use o método estático `GetInstance` para obter um ponteiro para `CMFCVisualManager`atual objeto derivado de.  
  
 Para alterar a aparência do seu aplicativo você deve usar outras classes que fornece métodos para desenhar todos os elementos visuais do seu aplicativo.  Alguns exemplos de essas classes são [Classe de CMFCVisualManagerOfficeXP](../../mfc/reference/cmfcvisualmanagerofficexp-class.md), [Classe CMFCVisualManagerOffice2003](../Topic/CMFCVisualManagerOffice2003%20Class.md), e [Classe CMFCVisualManagerOffice2007](../../mfc/reference/cmfcvisualmanageroffice2007-class.md).  Quando você deseja alterar a aparência do seu aplicativo, passe um de esses gerentes visuais no método `SetDefaultManager`.  Para um exemplo que demonstra como o aplicativo pode imitar a aparência do Microsoft Office 2003, consulte [Classe CMFCVisualManagerOffice2003](../Topic/CMFCVisualManagerOffice2003%20Class.md).  
  
 Todos os métodos de desenho são virtuais.  Isso permite que você crie um estilo visual personalizado para GUI do seu aplicativo.  Se você desejar criar seu próprio estilo visual, derive uma classe de uma das classes visuais do gerente e substituir os métodos de desenho que você deseja alterar.  
  
## Exemplo  
 Este exemplo demonstra como instanciar objetos de `CMFCVisualManager` de padrão e personalizados.  
  
```  
void CMFCSkinsApp::SetSkin (int iIndex)  
{   // destroy the current visual manager  
   if (CMFCVisualManager::GetInstance () != NULL)  
   {  
      delete CMFCVisualManager::GetInstance ();  
   }  
   switch (iIndex)  
  {  
   case 0:  
      CMFCVisualManager::GetInstance (); // create the standard visual manager  
      break;  
   case 1:  
      new CMyVisualManager (); // create the first custom visual manager  
      break;  
   case 2:  
      new CMacStyle ();  // create the second custom visual manager  
      break;  
   }  
  
   // access the manager and set it properly  
   CMFCVisualManager::GetInstance ()->SetLook2000 ();  
   CMFCVisualManager::GetInstance ()->RedrawAll ();  
}  
```  
  
## Exemplo  
 O exemplo a seguir demonstra como recuperar os valores padrão de um objeto de `CMFCVisualManager` .  Este trecho de código é parte de [Exemplo do painel de tarefas](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_TasksPane#1](../../mfc/reference/codesnippet/CPP/cmfcvisualmanager-class_1.h)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)  
  
 [CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxvisualmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [CMFCVisualManager::GetInstance](../Topic/CMFCVisualManager::GetInstance.md)   
 [Gerenciador de visualização](../../mfc/visualization-manager.md)