---
title: "Classe de CMFCDropDownToolBar | Microsoft Docs"
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
  - "CMFCDropDownToolBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDropDownToolBar"
ms.assetid: 78818ec5-83ce-42fa-a0d4-2d9d5ecc8770
caps.latest.revision: 37
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDropDownToolBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma barra de ferramentas que aparece quando o usuário pressiona e contém um botão da barra de ferramentas de nível superior.  
  
## Sintaxe  
  
```  
class CMFCDropDownToolBar : public CMFCToolBar  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDropDownToolBar::AllowShowOnPaneMenu](../Topic/CMFCDropDownToolBar::AllowShowOnPaneMenu.md)|Overrides \( `CPane::AllowShowOnPaneMenu`.\)|  
|[CMFCDropDownToolBar::LoadBitmap](../Topic/CMFCDropDownToolBar::LoadBitmap.md)|Overrides \( [CMFCToolBar::LoadBitmap](../Topic/CMFCToolBar::LoadBitmap.md).\)|  
|[CMFCDropDownToolBar::LoadToolBar](../Topic/CMFCDropDownToolBar::LoadToolBar.md)|Overrides \( [CMFCToolBar::LoadToolBar](../Topic/CMFCToolBar::LoadToolBar.md).\)|  
|[CMFCDropDownToolBar::OnLButtonUp](../Topic/CMFCDropDownToolBar::OnLButtonUp.md)||  
|[CMFCDropDownToolBar::OnMouseMove](../Topic/CMFCDropDownToolBar::OnMouseMove.md)||  
|[CMFCDropDownToolBar::OnSendCommand](../Topic/CMFCDropDownToolBar::OnSendCommand.md)|Overrides \( `CMFCToolBar::OnSendCommand`.\)|  
|[CMFCDropDownToolBar::OnUpdateCmdUI](../Topic/CMFCDropDownToolBar::OnUpdateCmdUI.md)|Overrides \( [CMFCToolBar::OnUpdateCmdUI](http://msdn.microsoft.com/pt-br/571a38ab-2a56-4968-9796-273516126f80).\)|  
  
### Comentários  
 Um objeto de `CMFCDropDownToolBar` combina a aparência visual de uma barra de ferramentas com o comportamento de um menu pop\-up.  Quando um usuário pressiona e mantém um botão da barra de ferramentas drop\-down \(consulte\) [Classe de CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md), uma barra de ferramentas lista suspensa aparece, e o usuário pode selecionar um botão da barra de ferramentas e enrolando a ele e liberando o botão do mouse.  Depois que o usuário seleciona um botão na barra de ferramentas lista suspensa, o botão é exibido como o botão na barra de ferramentas atual de nível superior.  
  
 Uma barra de ferramentas e não pode ser personalizada ou conectado, e não tem um estado de rasgo \- fora.  
  
 A ilustração a seguir mostra um objeto de `CMFCDropDownToolBar` :  
  
 ![Captura de tela de CMFCDropDownToolbar](../../mfc/reference/media/cmfcdropdown.png "CMFCDropDown")  
  
 Você cria um objeto de `CMFCDropDownToolBar` a mesma forma que cria uma barra de ferramentas [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)comum \(consulte\).  
  
 Para inserir a barra de ferramentas drop\-down em uma barra de ferramentas pai:  
  
 1.  Reservar uma identificação de recurso fictício no botão no recurso pai da barra de ferramentas.  
  
 2.  Crie um objeto de `CMFCDropDownToolBarButton` que contém a barra de ferramentas drop\-down \(para obter mais informações, consulte [CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](../Topic/CMFCDropDownToolbarButton::CMFCDropDownToolbarButton.md)\).  
  
 3.  Substitua o botão fictício com o objeto de `CMFCDropDownToolBarButton` usando [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md).  
  
 Para obter mais informações sobre os botões da barra de ferramentas, consulte [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).  Para um exemplo de uma barra de ferramentas lista suspensa, consulte o projeto VisualStudioDemo de exemplo.  
  
## Exemplo  
 O exemplo seguinte demonstra como usar o método de `Create` na classe de `CMFCDropDownToolBar` .  Este trecho de código é parte de [Exemplo de demonstração do Visual Studio](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#29](../../mfc/reference/codesnippet/CPP/cmfcdropdowntoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_VisualStudioDemo#30](../../mfc/reference/codesnippet/CPP/cmfcdropdowntoolbar-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxdropdowntoolbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [CMFCToolBar::Create](../Topic/CMFCToolBar::Create.md)   
 [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md)   
 [Classe de CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)