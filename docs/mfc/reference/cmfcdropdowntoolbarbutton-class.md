---
title: "Classe de CMFCDropDownToolbarButton | Microsoft Docs"
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
  - "CMFCDropDownToolbarButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDropDownToolbarButton"
  - "Método de OnCancelMode"
ms.assetid: bc9d69e6-bd3e-4c15-9368-e80a504a0ba7
caps.latest.revision: 31
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDropDownToolbarButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um tipo de botão da barra de ferramentas que se comporta como normal quando um botão é clicado.  Em o entanto, abre uma barra de ferramentas drop\-down \([Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md) se o usuário pressiona e mantém o botão da barra de ferramentas.  
  
## Sintaxe  
  
```  
class CMFCDropDownToolbarButton : public CMFCToolBarButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](../Topic/CMFCDropDownToolbarButton::CMFCDropDownToolbarButton.md)|Constrói um objeto de `CMFCDropDownToolbarButton` .|  
|`CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDropDownToolbarButton::CopyFrom](../Topic/CMFCDropDownToolbarButton::CopyFrom.md)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual.  Overrides \( [CMFCToolBarButton::CopyFrom](../Topic/CMFCToolBarButton::CopyFrom.md).\)|  
|`CMFCDropDownToolbarButton::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CMFCDropDownToolbarButton::DropDownToolbar](../Topic/CMFCDropDownToolbarButton::DropDownToolbar.md)|Abre uma barra de ferramentas suspenso.|  
|[CMFCDropDownToolbarButton::ExportToMenuButton](../Topic/CMFCDropDownToolbarButton::ExportToMenuButton.md)|Copia texto do botão da barra de ferramentas para um menu.  Overrides \( [CMFCToolBarButton::ExportToMenuButton](../Topic/CMFCToolBarButton::ExportToMenuButton.md).\)|  
|[CMFCDropDownToolbarButton::GetDropDownToolBar](../Topic/CMFCDropDownToolbarButton::GetDropDownToolBar.md)|Recupera a barra de ferramentas lista suspensa que está associada com o botão.|  
|`CMFCDropDownToolbarButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCDropDownToolbarButton::IsDropDown](../Topic/CMFCDropDownToolbarButton::IsDropDown.md)|Determina se a barra de ferramentas e está atualmente aberto.|  
|[CMFCDropDownToolbarButton::IsExtraSize](../Topic/CMFCDropDownToolbarButton::IsExtraSize.md)|Determina se o botão pode ser exibido com uma borda estendido.  Overrides \( [CMFCToolBarButton::IsExtraSize](../Topic/CMFCToolBarButton::IsExtraSize.md).\)|  
|[CMFCDropDownToolbarButton::OnCalculateSize](../Topic/CMFCDropDownToolbarButton::OnCalculateSize.md)|Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo e o estado de encaixe especificados.  Overrides \( [CMFCToolBarButton::OnCalculateSize](../Topic/CMFCToolBarButton::OnCalculateSize.md).\)|  
|`CMFCDropDownToolbarButton::OnCancelMode`|Chamado pela estrutura para manipular a mensagem de [WM\_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) .  Overrides \( `CMCToolBarButton::OnCancelMode`.\)|  
|[CMFCDropDownToolbarButton::OnChangeParentWnd](../Topic/CMFCDropDownToolbarButton::OnChangeParentWnd.md)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.  Overrides \( [CMFCToolBarButton::OnChangeParentWnd](../Topic/CMFCToolBarButton::OnChangeParentWnd.md).\)|  
|[CMFCDropDownToolbarButton::OnClick](../Topic/CMFCDropDownToolbarButton::OnClick.md)|Chamado pela estrutura quando o usuário clica no botão do mouse.  Overrides \( [CMFCToolBarButton::OnClick](../Topic/CMFCToolBarButton::OnClick.md).\)|  
|[CMFCDropDownToolbarButton::OnClickUp](../Topic/CMFCDropDownToolbarButton::OnClickUp.md)|Chamado pela estrutura quando o usuário liberar o botão do mouse.  Overrides \( [CMFCToolBarButton::OnClickUp](../Topic/CMFCToolBarButton::OnClickUp.md).\)|  
|[CMFCDropDownToolbarButton::OnContextHelp](../Topic/CMFCDropDownToolbarButton::OnContextHelp.md)|Chamado pela estrutura quando a barra de ferramentas pai manipular uma mensagem de `WM_HELPHITTEST` .  Overrides \( [CMFCToolBarButton::OnContextHelp](../Topic/CMFCToolBarButton::OnContextHelp.md).\)|  
|[CMFCDropDownToolbarButton::OnCustomizeMenu](../Topic/CMFCDropDownToolbarButton::OnCustomizeMenu.md)|Altera o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai.  Overrides \( [CMFCToolBarButton::OnCustomizeMenu](../Topic/CMFCToolBarButton::OnCustomizeMenu.md).\)|  
|[CMFCDropDownToolbarButton::OnDraw](../Topic/CMFCDropDownToolbarButton::OnDraw.md)|Chamado pela estrutura para desenhar o botão usando os estilos e opções especificadas.  Overrides \( [CMFCToolBarButton::OnDraw](../Topic/CMFCToolBarButton::OnDraw.md).\)|  
|[CMFCDropDownToolbarButton::OnDrawOnCustomizeList](../Topic/CMFCDropDownToolbarButton::OnDrawOnCustomizeList.md)|Chamado pela estrutura para desenhar o botão no painel de **Comandos** da caixa de diálogo de **Personalizar** .  Overrides \( [CMFCToolBarButton::OnDrawOnCustomizeList](../Topic/CMFCToolBarButton::OnDrawOnCustomizeList.md).\)|  
|[CMFCDropDownToolbarButton::Serialize](../Topic/CMFCDropDownToolbarButton::Serialize.md)|Este objeto ler de um arquivo ou neutro o grava em um arquivo neutro.  Overrides \( [CMFCToolBarButton::Serialize](../Topic/CMFCToolBarButton::Serialize.md).\)|  
|[CMFCDropDownToolbarButton::SetDefaultCommand](../Topic/CMFCDropDownToolbarButton::SetDefaultCommand.md)|Define o comando padrão que a estrutura usa quando um usuário clica no botão.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDropDownToolbarButton::m\_uiShowBarDelay](../Topic/CMFCDropDownToolbarButton::m_uiShowBarDelay.md)|Especifica o período de tempo que um usuário deve manter o botão do mouse antes da barra de ferramentas lista suspensa aparece.|  
  
## Comentários  
 `CMFCDropDownToolBarButton` difere de um botão comum que tem uma pequena seta no canto inferior direito do botão.  Depois que o usuário seleciona um botão da barra de ferramentas lista suspensa, a estrutura exibe o ícone no botão da barra de ferramentas de nível superior \(o botão com uma pequena seta no canto inferior direito\).  
  
 Para obter informações sobre como implementar uma barra de ferramentas lista suspensa, consulte [Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md).  
  
 O objeto de `CMFCDropDownToolBarButton` pode ser exportado para um objeto de [Classe de CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) e ser exibido como um botão de menu com um menu pop\-up.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxdropdowntoolbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)