---
title: "Classe CMFCVisualManagerWindows7 | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "afxvisualmanagerwindows7/CMFCVisualManagerWindows7"
  - "CMFCVisualManagerWindows7"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMFCVisualManagerWindows7"
ms.assetid: e8d87df1-0c09-4b58-8ade-4e911f796e42
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CMFCVisualManagerWindows7
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CMFCVisualManagerWindows7` fornece a um aplicativo a aparência de um aplicativo de [!INCLUDE[win7](../../build/includes/win7_md.md)] .  
  
## Sintaxe  
  
```  
class CMFCVisualManagerWindows7 : public CMFCVisualManagerWindows;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCVisualManagerWindows7::CMFCVisualManagerWindows7](../Topic/CMFCVisualManagerWindows7::CMFCVisualManagerWindows7.md)|Construtor padrão.|  
|[CMFCVisualManagerWindows7::~CMFCVisualManagerWindows7](../Topic/CMFCVisualManagerWindows7::~CMFCVisualManagerWindows7.md)|Usar como padrão o destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCVisualManagerWindows7::CleanStyle`|Limpa o estilo visual atual e redefina o estilo visual padrão.|  
|`CMFCVisualManagerWindows7::CleanUp`|Limpa todos os objetos na interface do usuário e redefina os menus.|  
|`CMFCVisualManagerWindows7::DrawNcBtn`|Desenha um botão na área não\-cliente do elemento.  A estrutura usar esse método para desenhar minimiza, maximize, feche e botões de minimizar no canto superior direito de moldura da janela.  Este método é chamado quando o programa usa um tema não Aero.|  
|`CMFCVisualManagerWindows7::DrawNcText`|Desenha texto na área não\-cliente do elemento.  A estrutura usar esse método para desenhar o título do aplicativo na barra de título na parte superior da janela do quadro.|  
|`CMFCVisualManagerWindows7::DrawSeparator`|Desenha um separador em [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).|  
|`CMFCVisualManagerWindows7::GetRibbonBar`|Recupera [Classe de CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) associado com a interface do usuário.|  
|[CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor](../Topic/CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor.md)|Obtém uma cor do plano de fundo da caixa de edição de fita.|  
|`CMFCVisualManagerWindows7::GetRibbonPopupBorderSize`|Substitui [CMFCVisualManager::GetRibbonPopupBorderSize](../Topic/CMFCVisualManager::GetRibbonPopupBorderSize.md)|  
|`CMFCVisualManagerWindows7::GetRibbonQuickAccessToolBarChevronOffset`|Substitui [CMFCVisualManager::GetRibbonQuickAccessToolBarChevronOffset](../Topic/CMFCVisualManager::GetRibbonQuickAccessToolBarChevronOffset.md)|  
|`CMFCVisualManagerWindows7::GetRibbonQuickAccessToolBarRightMargin`|Substitui [CMFCVisualManager::GetRibbonQuickAccessToolBarRightMargin](../Topic/CMFCVisualManager::GetRibbonQuickAccessToolBarRightMargin.md)|  
|`CMFCVisualManagerWindows7::IsHighlightWholeMenuItem`|Substitui [CMFCVisualManagerWindows::IsHighlightWholeMenuItem](../Topic/CMFCVisualManagerWindows::IsHighlightWholeMenuItem.md)|  
|`CMFCVisualManagerWindows7::IsOwnerDrawMenuCheck`|Substitui [CMFCVisualManager::IsOwnerDrawMenuCheck](../Topic/CMFCVisualManager::IsOwnerDrawMenuCheck.md)|  
|`CMFCVisualManagerWindows7::IsRibbonPresent`|Determina se `CMFCRibbonBar` estiver presente e visível.|  
|`CMFCVisualManagerWindows7::OnDrawButtonBorder`|Substitui [CMFCVisualManagerWindows::OnDrawButtonBorder](../Topic/CMFCVisualManagerWindows::OnDrawButtonBorder.md)|  
|`CMFCVisualManagerWindows7::OnDrawCheckBoxEx`|Substitui [CMFCVisualManagerWindows::OnDrawCheckBoxEx](../Topic/CMFCVisualManagerWindows::OnDrawCheckBoxEx.md)|  
|`CMFCVisualManagerWindows7::OnDrawComboDropButton`|Substitui [CMFCVisualManagerWindows::OnDrawComboDropButton](../Topic/CMFCVisualManagerWindows::OnDrawComboDropButton.md)|  
|`CMFCVisualManagerWindows7::OnDrawDefaultRibbonImage`|Substitui [CMFCVisualManager::OnDrawDefaultRibbonImage](../Topic/CMFCVisualManager::OnDrawDefaultRibbonImage.md)|  
|`CMFCVisualManagerWindows7::OnDrawMenuBorder`|Substitui [CMFCVisualManagerWindows::OnDrawMenuBorder](../Topic/CMFCVisualManagerWindows::OnDrawMenuBorder.md)|  
|`CMFCVisualManagerWindows7::OnDrawMenuCheck`|Substitui [CMFCVisualManager::OnDrawMenuCheck](../Topic/CMFCVisualManager::OnDrawMenuCheck.md)|  
|`CMFCVisualManagerWindows7::OnDrawMenuLabel`|Substitui [CMFCVisualManager::OnDrawMenuLabel](../Topic/CMFCVisualManager::OnDrawMenuLabel.md)|  
|`CMFCVisualManagerWindows7::OnDrawRadioButton`|Substitui `CMFCVisualManager::OnDrawRadioButton`|  
|`CMFCVisualManagerWindows7::OnDrawRibbonApplicationButton`|Substitui [CMFCVisualManager::OnDrawRibbonApplicationButton](../Topic/CMFCVisualManager::OnDrawRibbonApplicationButton.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonButtonBorder`|Substitui [CMFCVisualManager::OnDrawRibbonButtonBorder](../Topic/CMFCVisualManager::OnDrawRibbonButtonBorder.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonCaption`|Substitui [CMFCVisualManager::OnDrawRibbonCaption](../Topic/CMFCVisualManager::OnDrawRibbonCaption.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonCaptionButton`|Substitui [CMFCVisualManager::OnDrawRibbonCaptionButton](../Topic/CMFCVisualManager::OnDrawRibbonCaptionButton.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonCategory`|Substitui [CMFCVisualManager::OnDrawRibbonCategory](../Topic/CMFCVisualManager::OnDrawRibbonCategory.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonCategoryTab`|Substitui [CMFCVisualManager::OnDrawRibbonCategoryTab](../Topic/CMFCVisualManager::OnDrawRibbonCategoryTab.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonDefaultPaneButton`|Substitui [CMFCVisualManager::OnDrawRibbonDefaultPaneButton](../Topic/CMFCVisualManager::OnDrawRibbonDefaultPaneButton.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonGalleryButton`|Substitui [CMFCVisualManager::OnDrawRibbonGalleryButton](../Topic/CMFCVisualManager::OnDrawRibbonGalleryButton.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonLaunchButton`|Substitui `CMFCVisualManager::OnDrawRibbonLaunchButton`|  
|`CMFCVisualManagerWindows7::OnDrawRibbonMenuCheckFrame`|Substitui [CMFCVisualManager::OnDrawRibbonMenuCheckFrame](../Topic/CMFCVisualManager::OnDrawRibbonMenuCheckFrame.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonPanel`|Substitui [CMFCVisualManager::OnDrawRibbonPanel](../Topic/CMFCVisualManager::OnDrawRibbonPanel.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonPanelCaption`|Substitui [CMFCVisualManager::OnDrawRibbonPanelCaption](../Topic/CMFCVisualManager::OnDrawRibbonPanelCaption.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonProgressBar`|Substitui [CMFCVisualManager::OnDrawRibbonProgressBar](../Topic/CMFCVisualManager::OnDrawRibbonProgressBar.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonRecentFilesFrame`|Substitui [CMFCVisualManager::OnDrawRibbonRecentFilesFrame](../Topic/CMFCVisualManager::OnDrawRibbonRecentFilesFrame.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonSliderChannel`|Substitui [CMFCVisualManager::OnDrawRibbonSliderChannel](../Topic/CMFCVisualManager::OnDrawRibbonSliderChannel.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonSliderThumb`|Substitui [CMFCVisualManager::OnDrawRibbonSliderThumb](../Topic/CMFCVisualManager::OnDrawRibbonSliderThumb.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonSliderZoomButton`|Substitui [CMFCVisualManager::OnDrawRibbonSliderZoomButton](../Topic/CMFCVisualManager::OnDrawRibbonSliderZoomButton.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonStatusBarPane`|Substitui [CMFCVisualManager::OnDrawRibbonStatusBarPane](../Topic/CMFCVisualManager::OnDrawRibbonStatusBarPane.md)|  
|`CMFCVisualManagerWindows7::OnDrawRibbonTabsFrame`|Substitui [CMFCVisualManager::OnDrawRibbonTabsFrame](../Topic/CMFCVisualManager::OnDrawRibbonTabsFrame.md)|  
|`CMFCVisualManagerWindows7::OnDrawStatusBarSizeBox`|Substitui [CMFCVisualManagerWindows::OnDrawStatusBarSizeBox](../Topic/CMFCVisualManagerWindows::OnDrawStatusBarSizeBox.md)|  
|`CMFCVisualManagerWindows7::OnFillBarBackground`|Substitui [CMFCVisualManagerWindows::OnFillBarBackground](../Topic/CMFCVisualManagerWindows::OnFillBarBackground.md)|  
|`CMFCVisualManagerWindows7::OnFillButtonInterior`|Substitui [CMFCVisualManagerWindows::OnFillButtonInterior](../Topic/CMFCVisualManagerWindows::OnFillButtonInterior.md)|  
|[CMFCVisualManagerWindows7::OnFillMenuImageRect](../Topic/CMFCVisualManagerWindows7::OnFillMenuImageRect.md)|A estrutura chama esse método quando preenche a área em torno de imagens de item de menu.|  
|`CMFCVisualManagerWindows7::OnFillRibbonButton`|Substitui [CMFCVisualManager::OnFillRibbonButton](../Topic/CMFCVisualManager::OnFillRibbonButton.md)|  
|`CMFCVisualManagerWindows7::OnFillRibbonQuickAccessToolBarPopup`|Substitui [CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup](../Topic/CMFCVisualManager::OnFillRibbonQuickAccessToolBarPopup.md)|  
|`CMFCVisualManagerWindows7::OnHighlightMenuItem`|Substitui [CMFCVisualManagerWindows::OnHighlightMenuItem](../Topic/CMFCVisualManagerWindows::OnHighlightMenuItem.md)|  
|`CMFCVisualManagerWindows7::OnNcActivate`|Substitui [CMFCVisualManager::OnNcActivate](../Topic/CMFCVisualManager::OnNcActivate.md)|  
|`CMFCVisualManagerWindows7::OnNcPaint`|Substitui [CMFCVisualManager::OnNcPaint](../Topic/CMFCVisualManager::OnNcPaint.md)|  
|`CMFCVisualManagerWindows7::OnUpdateSystemColors`|Substitui [CMFCVisualManagerWindows::OnUpdateSystemColors](../Topic/CMFCVisualManagerWindows::OnUpdateSystemColors.md)|  
|`CMFCVisualManagerWindows7::SetResourceHandle`|Define a alça de recurso que descreve os atributos do visual.|  
|`CMFCVisualManagerWindows7::SetStyle`|Defina o esquema de cores de `CMFCVisualManagerWindows7` GUI.|  
  
## Comentários  
 Use a classe de `CMFCVisualManagerWindows7` para alterar a aparência do seu aplicativo imitar um aplicativo padrão de [!INCLUDE[win7](../../build/includes/win7_md.md)] .  Esta classe não pode ser válido se seu aplicativo estiver sendo executado em uma versão do windows anteriores ao [!INCLUDE[win7](../../build/includes/win7_md.md)].  Em esse cenário, o aplicativo usa o gerenciador visual padrão definido em [CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md).  
  
 O CMFCVisualManagerWindows7 herda vários métodos de [Classe de CMFCVisualManagerWindows](../../mfc/reference/cmfcvisualmanagerwindows-class.md) e da classe de `CMFCVisualManager` .  Os métodos listados na seção anterior são novos métodos da classe `CMFCVisualManagerWindows7` .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)  
  
 [CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)  
  
 [CMFCVisualManagerOfficeXP](../../mfc/reference/cmfcvisualmanagerofficexp-class.md)  
  
 [CMFCVisualManagerWindows](../../mfc/reference/cmfcvisualmanagerwindows-class.md)  
  
 `CMFCVisualManagerWindows7`  
  
## Requisitos  
 **Cabeçalho:** afxvisualmanagerwindows7.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)   
 [Classe de CMFCVisualManagerWindows](../../mfc/reference/cmfcvisualmanagerwindows-class.md)   
 [CMFCVisualManager::SetDefaultManager](../Topic/CMFCVisualManager::SetDefaultManager.md)