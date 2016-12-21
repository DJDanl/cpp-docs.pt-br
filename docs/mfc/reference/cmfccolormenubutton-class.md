---
title: "Classe de CMFCColorMenuButton | Microsoft Docs"
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
  - "CMFCColorMenuButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCColorMenuButton"
ms.assetid: 42685704-e994-4f7b-9553-62283c27b754
caps.latest.revision: 29
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCColorMenuButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCColorMenuButton` suporta um comando de menu ou um botão da barra de ferramentas que ligue uma caixa de diálogo seletor de cor.  
  
## Sintaxe  
  
```  
class CMFCColorMenuButton : public CMFCToolBarMenuButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorMenuButton::CMFCColorMenuButton](../Topic/CMFCColorMenuButton::CMFCColorMenuButton.md)|Constrói um objeto de `CMFCColorMenuButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorMenuButton::EnableAutomaticButton](../Topic/CMFCColorMenuButton::EnableAutomaticButton.md)|Ativar e desativar um botão “automático” que está localizado acima dos botões normais de cor.  \(O botão automático do sistema padrão é rotulado **Automático**.\)|  
|[CMFCColorMenuButton::EnableDocumentColors](../Topic/CMFCColorMenuButton::EnableDocumentColors.md)|Permite que a exibição de cores a específicas em vez de cores do sistema.|  
|[CMFCColorMenuButton::EnableOtherButton](../Topic/CMFCColorMenuButton::EnableOtherButton.md)|Ativar e desativar um “outro” botão que está localizado abaixo dos botões normais de cor.  \(O sistema padrão “outro” botão é rotulado **Cores mais…**.\)|  
|[CMFCColorMenuButton::EnableTearOff](../Topic/CMFCColorMenuButton::EnableTearOff.md)|Permite que a capacidade de rasgar fora um painel de cor.|  
|[CMFCColorMenuButton::GetAutomaticColor](../Topic/CMFCColorMenuButton::GetAutomaticColor.md)|Recupera a cor automático atual.|  
|[CMFCColorMenuButton::GetColor](../Topic/CMFCColorMenuButton::GetColor.md)|Recupera a cor atual do botão.|  
|[CMFCColorMenuButton::GetColorByCmdID](../Topic/CMFCColorMenuButton::GetColorByCmdID.md)|Recupera a cor que corresponde a um certo ID de comando|  
|[CMFCColorMenuButton::OnChangeParentWnd](../Topic/CMFCColorMenuButton::OnChangeParentWnd.md)|Chamado pela estrutura quando a janela pai alterar.|  
|[CMFCColorMenuButton::OpenColorDialog](../Topic/CMFCColorMenuButton::OpenColorDialog.md)|Abrir uma caixa de diálogo de seleção de cor.|  
|[CMFCColorMenuButton::SetColor](../Topic/CMFCColorMenuButton::SetColor.md)|Define a cor do botão atual da cor.|  
|[CMFCColorMenuButton::SetColorByCmdID](../Topic/CMFCColorMenuButton::SetColorByCmdID.md)|Define a cor do botão especificado no menu de cor.|  
|[CMFCColorMenuButton::SetColorName](../Topic/CMFCColorMenuButton::SetColorName.md)|Define um novo nome para a cor especificada.|  
|[CMFCColorMenuButton::SetColumnsNumber](../Topic/CMFCColorMenuButton::SetColumnsNumber.md)|Define o número de colunas que são exibidas por um objeto de `CMFCColorBar` .|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorMenuButton::CopyFrom](../Topic/CMFCColorMenuButton::CopyFrom.md)|Copia outro botão da barra de ferramentas para o botão atual.|  
|[CMFCColorMenuButton::CreatePopupMenu](../Topic/CMFCColorMenuButton::CreatePopupMenu.md)|Cria uma caixa de diálogo seletor de cor.|  
|[CMFCColorMenuButton::IsEmptyMenuAllowed](../Topic/CMFCColorMenuButton::IsEmptyMenuAllowed.md)|Indica se os menus vazias são suportados.|  
|[CMFCColorMenuButton::OnDraw](../Topic/CMFCColorMenuButton::OnDraw.md)|Chamado pela estrutura para exibir uma imagem em um botão.|  
|[CMFCColorMenuButton::OnDrawOnCustomizeList](../Topic/CMFCColorMenuButton::OnDrawOnCustomizeList.md)|Chamado pela estrutura antes que um objeto de `CMFCColorMenuButton` é exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.|  
  
## Comentários  
 Para substituir o comando de menu ou no botão da barra de ferramentas original com um objeto de `CMFCColorMenuButton` , cria o objeto de `CMFCColorMenuButton` , define estilos apropriadas de [Classe de CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) em seguida, chame o método de `ReplaceButton` da classe de [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) .  Se você personaliza uma barra de ferramentas, chame o método de [CMFCToolBarsCustomizeDialog::ReplaceButton](../Topic/CMFCToolBarsCustomizeDialog::ReplaceButton.md) .  
  
 A caixa de diálogo seletor de cores é criada durante o processamento do manipulador de eventos de [CMFCColorMenuButton::CreatePopupMenu](../Topic/CMFCColorMenuButton::CreatePopupMenu.md) .  O manipulador de eventos notifica o elemento pai com uma mensagem de `WM_COMMAND` .  O objeto de `CMFCColorMenuButton` envia a identificação do controle que é atribuído ao comando de menu ou para o botão da barra de ferramentas original.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar e configurar um botão de menu de cores usando vários métodos na classe de `CMFCColorMenuButton` .  Em o exemplo, um objeto de `CPalette` é projetado principalmente e então usado para construir um objeto da classe de `CMFCColorMenuButton` .  O objeto de `CMFCColorMenuButton` é configurado em seu ativação automática e outros botões, e definindo sua cor e o número de colunas.  Esse código é parte de [Exemplo de preenchimento da palavra](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#5](../../mfc/reference/codesnippet/CPP/cmfccolormenubutton-class_1.h)]  
[!code-cpp[NVC_MFC_WordPad#6](../../mfc/reference/codesnippet/CPP/cmfccolormenubutton-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)  
  
 [CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcolormenubutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)   
 [Classe de CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)