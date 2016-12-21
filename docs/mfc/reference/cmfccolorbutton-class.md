---
title: "Classe de CMFCColorButton | Microsoft Docs"
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
  - "CMFCColorButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCColorButton"
  - "Membro de dados de CMFCColorButton::m_bAltColorDlg"
  - "Membro de dados de CMFCColorButton::m_bAutoSetFocus"
  - "Membro de dados de CMFCColorButton::m_Color"
  - "Membro de dados de CMFCColorButton::m_ColorAutomatic"
  - "Membro de dados de CMFCColorButton::m_lstDocColors"
  - "Membro de dados de CMFCColorButton::m_nColumns"
  - "Membro de dados de CMFCColorButton::m_pPalette"
  - "Membro de dados de CMFCColorButton::m_pPopup"
  - "Membro de dados de CMFCColorButton::m_strAutoColorText"
  - "Membro de dados de CMFCColorButton::m_strDocColorsText"
  - "Membro de dados de CMFCColorButton::m_strOtherText"
ms.assetid: 9fdf34ae-4cc5-4c5e-9d89-1c50e8a73699
caps.latest.revision: 34
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCColorButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CMFCColorButton` e as classes de [Classe de CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) são usados em conjunto para implementar um controle do selecionador de cores.  
  
## Sintaxe  
  
```  
class CMFCColorButton : public CMFCButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorButton::CMFCColorButton](../Topic/CMFCColorButton::CMFCColorButton.md)|Constrói um novo objeto de `CMFCColorButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorButton::EnableAutomaticButton](../Topic/CMFCColorButton::EnableAutomaticButton.md)|Ativar e desativar um botão “automático” que está localizado acima dos botões normais de cor.  \(O botão automático do sistema padrão é rotulado **Automático**.\)|  
|[CMFCColorButton::EnableOtherButton](../Topic/CMFCColorButton::EnableOtherButton.md)|Ativar e desativar um “outro” botão que está localizado abaixo dos botões normais de cor.  \(O sistema padrão “outro” botão é rotulado **Cores mais…**.\)|  
|[CMFCColorButton::GetAutomaticColor](../Topic/CMFCColorButton::GetAutomaticColor.md)|Recupera a cor automático atual.|  
|[CMFCColorButton::GetColor](../Topic/CMFCColorButton::GetColor.md)|Recupera a cor de um botão.|  
|[CMFCColorButton::SetColor](../Topic/CMFCColorButton::SetColor.md)|Define a cor de um botão.|  
|[CMFCColorButton::SetColorName](../Topic/CMFCColorButton::SetColorName.md)|Define um nome de cor.|  
|[CMFCColorButton::SetColumnsNumber](../Topic/CMFCColorButton::SetColumnsNumber.md)|Define o número de colunas na caixa de diálogo seletor de cor.|  
|[CMFCColorButton::SetDocumentColors](../Topic/CMFCColorButton::SetDocumentColors.md)|Especifica uma lista de cores a específicas que são exibidas na caixa de diálogo seletor de cor.|  
|[CMFCColorButton::SetPalette](../Topic/CMFCColorButton::SetPalette.md)|Especifica uma paleta de cores padrão de exibição.|  
|[CMFCColorButton::SizeToContent](../Topic/CMFCColorButton::SizeToContent.md)|Altera o tamanho do controle de botão, dependendo seu tamanho do texto e da imagem.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorButton::IsDrawXPTheme](../Topic/CMFCColorButton::IsDrawXPTheme.md)|Indica se o botão atual de cor é exibido no estilo visual do Windows XP.|  
|[CMFCColorButton::OnDraw](../Topic/CMFCColorButton::OnDraw.md)|Chamado pela estrutura para exibir uma imagem do botão.|  
|[CMFCColorButton::OnDrawBorder](../Topic/CMFCColorButton::OnDrawBorder.md)|Chamado pela estrutura para exibir a borda do botão.|  
|[CMFCColorButton::OnDrawFocusRect](../Topic/CMFCColorButton::OnDrawFocusRect.md)|Chamado pela estrutura para exibir um retângulo de foco quando o botão tem o foco.|  
|[CMFCColorButton::OnShowColorPopup](../Topic/CMFCColorButton::OnShowColorPopup.md)|Chamado pela estrutura quando a caixa de diálogo seletor de cor está prestes a ser exibida.|  
|[CMFCColorButton::RebuildPalette](../Topic/CMFCColorButton::RebuildPalette.md)|Inicializa o membro de dados protegidos de `m_pPalette` a paleta especificada ou à paleta padrão do sistema.|  
|[CMFCColorButton::UpdateColor](../Topic/CMFCColorButton::UpdateColor.md)|Chamado pela estrutura quando o usuário selecione uma cor de paleta da caixa de diálogo seletor de cor.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|`m_bAltColorDlg`|Um valor booleano.  Se `TRUE`, a estrutura exibe a caixa de diálogo de cor de [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) quando *outro* botão é clicado, ou se `FALSE`, a caixa de diálogo de cor do sistema.  o valor padrão é `TRUE`.  Para mais informações, consulte [CMFCColorButton::EnableOtherButton](../Topic/CMFCColorButton::EnableOtherButton.md).|  
|`m_bAutoSetFocus`|Um valor booleano.  Se `TRUE`, a estrutura define o foco no menu de cor quando o menu é exibido, ou se `FALSE`, não altera o foco.  o valor padrão é `TRUE`.|  
|[CMFCColorButton::m\_bEnabledInCustomizeMode](../Topic/CMFCColorButton::m_bEnabledInCustomizeMode.md)|Indica se o modo de personalização está ativado para o botão de cor.|  
|`m_Color`|Um valor de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) .  Contém a cor selecionada.|  
|`m_ColorAutomatic`|Um valor de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) .  Contém a cor padrão selecionada.|  
|`m_Colors`|[CArray](../../mfc/reference/carray-class.md) de valores de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) .  Contém as cores atualmente disponíveis.|  
|`m_lstDocColors`|[CList](../../mfc/reference/clist-class.md) de valores de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) .  Contém as cores do documento atual.|  
|`m_nColumns`|Um número inteiro.  Contém o número de colunas para exibir na grade de cores em um menu de seleção de cor.|  
|`m_pPalette`|Um ponteiro para [CPalette](../../mfc/reference/cpalette-class.md).  Contém as cores que estão disponíveis no menu de seleção atual da cor.|  
|`m_pPopup`|Um ponteiro para um objeto de [Classe de CMFCColorPopupMenu](../Topic/CMFCColorPopupMenu%20Class.md) .  O menu de seleção de cor que é exibido quando você clica no botão de cor.|  
|`m_strAutoColorText`|Uma cadeia de caracteres.  A etiqueta do botão “automático” em um menu de seleção de cor.|  
|`m_strDocColorsText`|Uma cadeia de caracteres.  O rótulo de botão em um menu de seleção de cores que exibe o documento cores.|  
|`m_strOtherText`|Uma cadeia de caracteres.  O rótulo de “outro” botão em um menu de seleção de cor.|  
  
## Comentários  
 Por padrão, a classe de `CMFCColorButton` se comporta como um botão de ação que abre uma caixa de diálogo seletor de cor.  A caixa de diálogo seletor de cor contém uma matriz de botões pequenos de cor de um “e” outro botão que exibe um selecionador de cores personalizado.  \(O sistema padrão “outro” botão é rotulado **Cores mais…**.\) Quando um usuário seleciona uma nova cor, o objeto de `CMFCColorButton` refletir a alteração e exibe a cor selecionada.  
  
 Crie um controle de botão de cores diretamente em seu código, ou usando a ferramenta de **ClassWizard** e um modelo da caixa de diálogo.  Se você criar um controle de botão de cores diretamente, adicione uma variável de `CMFCColorButton` ao seu aplicativo, e então chame o construtor e métodos de `Create` de `CMFCColorButton` objeto.  Se você usar **ClassWizard**, adicione uma variável de `CButton` para seu aplicativo em seguida, altere o tipo da variável de `CButton` a `CMFCColorButton`.  
  
 A caixa de diálogo seletor de cor \([Classe de CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)\) é exibida pelo método de [CMFCColorButton::OnShowColorPopup](../Topic/CMFCColorButton::OnShowColorPopup.md) quando a estrutura chama o manipulador de eventos de `OnLButtonDown` .  O método de [CMFCColorButton::OnShowColorPopup](../Topic/CMFCColorButton::OnShowColorPopup.md) pode ser substituído para oferecer suporte a seleção de cores personalizado.  
  
 O objeto de `CMFCColorButton` notifica o pai que uma cor for alterada enviá\-la uma notificação de `WM_COMMAND | BN_CLICKED` .  o pai usa o método de [CMFCColorButton::GetColor](../Topic/CMFCColorButton::GetColor.md) para recuperar a cor atual.  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um botão de cores usando vários métodos na classe de `CMFCColorButton` .  Os métodos define a cor do botão de cor e o número de colunas, e permitem o automático e outros botões.  Este exemplo é parte de [Exemplo de demonstração statusbar](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StatusBarDemo#10](../../mfc/reference/codesnippet/CPP/cmfccolorbutton-class_1.h)]  
[!code-cpp[NVC_MFC_StatusBarDemo#11](../../mfc/reference/codesnippet/CPP/cmfccolorbutton-class_2.cpp)]  
  
## Requisitos  
 **Cabeçalho:** afxcolorbutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCButton](../../mfc/reference/cmfcbutton-class.md)   
 [Classe de CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [CMFCColorButton::OnShowColorPopup](../Topic/CMFCColorButton::OnShowColorPopup.md)   
 [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449)   
 [Classe de CPalette](../../mfc/reference/cpalette-class.md)   
 [Classe de CArray](../../mfc/reference/carray-class.md)   
 [Classe de CList](../../mfc/reference/clist-class.md)   
 [CString](../../atl-mfc-shared/reference/cstringt-class.md)