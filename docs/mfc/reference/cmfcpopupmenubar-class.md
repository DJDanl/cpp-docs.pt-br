---
title: "Classe CMFCPopupMenuBar | Microsoft Docs"
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
  - "CMFCPopupMenuBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMFCPopupMenuBar"
ms.assetid: 4c93c459-7f70-4240-8c63-280bb811e374
caps.latest.revision: 32
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CMFCPopupMenuBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma barra de menus inserida em um menu pop\-up.  
  
## Sintaxe  
  
```  
class CMFCPopupMenuBar : public CMFCToolBar  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPopupMenuBar::AdjustSizeImmediate](../Topic/CMFCPopupMenuBar::AdjustSizeImmediate.md)|Recalcula imediatamente o layout de um painel.  Overrides \( [CPane::AdjustSizeImmediate](../Topic/CPane::AdjustSizeImmediate.md).\)|  
|[CMFCPopupMenuBar::BuildOrigItems](../Topic/CMFCPopupMenuBar::BuildOrigItems.md)|Carrega itens de menu pop\-up de um recurso especificado do menu.|  
|[CMFCPopupMenuBar::CloseDelayedSubMenu](../Topic/CMFCPopupMenuBar::CloseDelayedSubMenu.md)|Fecha um botão de menu pop\-up tarde.|  
|[CMFCPopupMenuBar::ExportToMenu](../Topic/CMFCPopupMenuBar::ExportToMenu.md)|Criar um menu dos botões de pop\-up\- menu.|  
|[CMFCPopupMenuBar::FindDestintationToolBar](../Topic/CMFCPopupMenuBar::FindDestintationToolBar.md)|Localiza a barra de ferramentas onde um ponto específico se encontra.|  
|[CMFCPopupMenuBar::GetCurrentMenuImageSize](../Topic/CMFCPopupMenuBar::GetCurrentMenuImageSize.md)|Indica o tamanho de imagens de menu\- botão.|  
|[CMFCPopupMenuBar::GetDefaultMenuId](../Topic/CMFCPopupMenuBar::GetDefaultMenuId.md)|Retorna o identificador do item de menu padrão.|  
|[CMFCPopupMenuBar::GetLastCommandIndex](../Topic/CMFCPopupMenuBar::GetLastCommandIndex.md)|Obtém o índice de comando de menu recentemente chamado.|  
|[CMFCPopupMenuBar::GetOffset](../Topic/CMFCPopupMenuBar::GetOffset.md)|Obtém o deslocamento da linha da barra de menus pop\-up.|  
|[CMFCPopupMenuBar::ImportFromMenu](../Topic/CMFCPopupMenuBar::ImportFromMenu.md)|Importa os botões de menu pop\-up de um menu especificado.|  
|[CMFCPopupMenuBar::IsDropDownListMode](../Topic/CMFCPopupMenuBar::IsDropDownListMode.md)|Indica se a barra de menus pop\-up estiver no modo de lista suspensa.|  
|[CMFCPopupMenuBar::IsPaletteMode](../Topic/CMFCPopupMenuBar::IsPaletteMode.md)|Indica se a barra de menus pop\-up estiver no modo de paleta.|  
|[CMFCPopupMenuBar::IsRibbonPanel](../Topic/CMFCPopupMenuBar::IsRibbonPanel.md)|Indica se este é um painel de fita \(`FALSE` por padrão\).|  
|[CMFCPopupMenuBar::IsRibbonPanelInRegularMode](../Topic/CMFCPopupMenuBar::IsRibbonPanelInRegularMode.md)|Indica se este é um painel de fita no modo normal \(`FALSE` por padrão\).|  
|[CMFCPopupMenuBar::LoadFromHash](../Topic/CMFCPopupMenuBar::LoadFromHash.md)|Carrega um menu as.|  
|[CMFCPopupMenuBar::RestoreDelayedSubMenu](../Topic/CMFCPopupMenuBar::RestoreDelayedSubMenu.md)|Restaura um botão de menu drop\-down para fechar a barra de menus pop\-up.|  
|[CMFCPopupMenuBar::SetButtonStyle](../Topic/CMFCPopupMenuBar::SetButtonStyle.md)|Defina o estilo do botão da barra de ferramentas no índice especificado.  Overrides \( [CMFCToolBar::SetButtonStyle](../Topic/CMFCToolBar::SetButtonStyle.md).\)|  
|[CMFCPopupMenuBar::SetOffset](../Topic/CMFCPopupMenuBar::SetOffset.md)|Define o deslocamento da linha da barra de menus pop\-up.|  
|[CMFCPopupMenuBar::StartPopupMenuTimer](../Topic/CMFCPopupMenuBar::StartPopupMenuTimer.md)|Inicia o timer para um botão de menu pop\-up tarde especificado.|  
  
### Membros de Dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPopupMenuBar::m\_bDisableSideBarInXPMode](../Topic/CMFCPopupMenuBar::m_bDisableSideBarInXPMode.md)|Especifica se a barra lateral cinza será exibida quando o aplicativo tem uma aparência do Windows XP.|  
  
## Comentários  
 `CMFCPopupMenuBar` é criado ao mesmo tempo que [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md) e inserido nela.  `CMFCPopupMenuBar` abrange toda a área cliente do objeto de `CMFCPopupMenu` .  Oferece suporte a entrada de teclado e mouse.  Também comunica a entrada a `CMFCPopupMenu` e para a janela de nível superior do quadro.  
  
## Exemplo  
 O exemplo a seguir demonstra como inicializar um objeto de `CMFCPopupMenuBar` de um objeto de `CMFCPopupMenu` .  Este trecho de código é parte de [Exemplo do cliente de desenho](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient#7](../../mfc/reference/codesnippet/CPP/cmfcpopupmenubar-class_1.cpp)]  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpopupmenubar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md)