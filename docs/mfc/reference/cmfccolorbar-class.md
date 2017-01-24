---
title: "Classe de CMFCColorBar | Microsoft Docs"
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
  - "CMFCColorBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCColorBar"
  - "Membro de dados de CMFCColorBar::m_bInternal"
  - "Membro de dados de CMFCColorBar::m_bIsEnabled"
  - "Membro de dados de CMFCColorBar::m_bIsTearOff"
  - "Membro de dados de CMFCColorBar::m_BoxSize"
  - "Membro de dados de CMFCColorBar::m_bShowDocColorsWhenDocked"
  - "Membro de dados de CMFCColorBar::m_bStdColorDlg"
  - "Membro de dados de CMFCColorBar::m_ColorAutomatic"
  - "Membro de dados de CMFCColorBar::m_ColorNames"
  - "Membro de dados de CMFCColorBar::m_colors"
  - "Membro de dados de CMFCColorBar::m_ColorSelected"
  - "Membro de dados de CMFCColorBar::m_lstDocColors"
  - "Membro de dados de CMFCColorBar::m_nCommandID"
  - "Membro de dados de CMFCColorBar::m_nHorzMargin"
  - "Membro de dados de CMFCColorBar::m_nHorzOffset"
  - "Membro de dados de CMFCColorBar::m_nNumColumns"
  - "Membro de dados de CMFCColorBar::m_nNumColumnsVert"
  - "Membro de dados de CMFCColorBar::m_nNumRowsHorz"
  - "Membro de dados de CMFCColorBar::m_nRowHeight"
  - "Membro de dados de CMFCColorBar::m_nVertMargin"
  - "Membro de dados de CMFCColorBar::m_nVertOffset"
  - "Membro de dados de CMFCColorBar::m_Palette"
  - "Membro de dados de CMFCColorBar::m_pParentBtn"
  - "Membro de dados de CMFCColorBar::m_pParentRibbonBtn"
  - "Membro de dados de CMFCColorBar::m_pWndPropList"
  - "Membro de dados de CMFCColorBar::m_strAutoColor"
  - "Membro de dados de CMFCColorBar::m_strDocColors"
  - "Membro de dados de CMFCColorBar::m_strOtherColor"
ms.assetid: 4756ee40-25a5-4cee-af7f-acab7993d1c7
caps.latest.revision: 35
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCColorBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe representa uma barra de `CMFCColorBar` de controle de encaixe que pode selecionar cores em um documento ou em um aplicativo.  
  
## Sintaxe  
  
```  
class CMFCColorBar : public CMFCPopupMenuBar  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorBar::CMFCColorBar](../Topic/CMFCColorBar::CMFCColorBar.md)|Constrói um objeto de `CMFCColorBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorBar::ContextToSize](../Topic/CMFCColorBar::ContextToSize.md)|Calcula as margens verticais e horizontais que são necessárias para conter os botões do controle de barra de cor e então ajuste o local dos botões.|  
|[CMFCColorBar::CreateControl](../Topic/CMFCColorBar::CreateControl.md)|Cria uma janela de controle de barra de cor, anexá\-la ao objeto de `CMFCColorBar` , e redimensiona o controle para conter a paleta especificada de cores.|  
|[CMFCColorBar::Create](../Topic/CMFCColorBar::Create.md)|Cria uma janela de controle de barra de cor e anexá\-la ao objeto de `CMFCColorBar` .|  
|[CMFCColorBar::EnableAutomaticButton](../Topic/CMFCColorBar::EnableAutomaticButton.md)|Mostra ou oculta o botão automático.|  
|[CMFCColorBar::EnableOtherButton](../Topic/CMFCColorBar::EnableOtherButton.md)|Habilita ou desabilita a exibição de uma caixa de diálogo que permite ao usuário selecione mais cores.|  
|[CMFCColorBar::GetColor](../Topic/CMFCColorBar::GetColor.md)|Recupera a cor selecionada.|  
|[CMFCColorBar::GetCommandID](../Topic/CMFCColorBar::GetCommandID.md)|Recupera a identificação de comando do controle atual da barra de cor.|  
|[CMFCColorBar::GetHighlightedColor](../Topic/CMFCColorBar::GetHighlightedColor.md)|Recupera a cor que significa que um botão de cor tem o foco; isto é, o botão está *quente*.|  
|[CMFCColorBar::GetHorzMargin](../Topic/CMFCColorBar::GetHorzMargin.md)|Recupera a margem horizontal, que é o espaço entre a célula esquerda ou direita da cor e o limite da área cliente.|  
|[CMFCColorBar::GetVertMargin](../Topic/CMFCColorBar::GetVertMargin.md)|Recupera a margem vertical, que é o espaço entre a parte superior ou célula de cor inferior e o limite da área cliente.|  
|[CMFCColorBar::IsTearOff](../Topic/CMFCColorBar::IsTearOff.md)|Indica se a barra de cor atual é encaixável.|  
|[CMFCColorBar::SetColor](../Topic/CMFCColorBar::SetColor.md)|Define a cor que é selecionada no momento.|  
|[CMFCColorBar::SetColorName](../Topic/CMFCColorBar::SetColorName.md)|Define um novo nome para uma cor especificada.|  
|[CMFCColorBar::SetCommandID](../Topic/CMFCColorBar::SetCommandID.md)|Define um novo ID de comando para um controle de barra de cor.|  
|[CMFCColorBar::SetDocumentColors](../Topic/CMFCColorBar::SetDocumentColors.md)|Define a lista de cores que são usadas no documento atual.|  
|[CMFCColorBar::SetHorzMargin](../Topic/CMFCColorBar::SetHorzMargin.md)|Define a margem horizontal, que é o espaço entre a célula esquerda ou direita da cor e o limite da área cliente.|  
|[CMFCColorBar::SetVertMargin](../Topic/CMFCColorBar::SetVertMargin.md)|Define a margem vertical, que é o espaço entre a parte superior ou célula de cor inferior e o limite da área cliente.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorBar::AdjustLocations](../Topic/CMFCColorBar::AdjustLocations.md)|Ajustar as posições dos botões de cor sobre o controle de barra de cor.|  
|[CMFCColorBar::AllowChangeTextLabels](../Topic/CMFCColorBar::AllowChangeTextLabels.md)|Indica se o rótulo de texto dos botões de cor pode alterar.|  
|[CMFCColorBar::AllowShowOnList](../Topic/CMFCColorBar::AllowShowOnList.md)|Indica se o objeto do controle de barra de cor pode aparecer em uma lista de barra de ferramentas durante o processo de personalização.|  
|[CMFCColorBar::CalcSize](../Topic/CMFCColorBar::CalcSize.md)|Chamado pela estrutura como parte do processo de cálculo de layout.|  
|[CMFCColorBar::CreatePalette](../Topic/CMFCColorBar::CreatePalette.md)|Initalizes uma paleta com cores em uma matriz especificada de cores.|  
|[CMFCColorBar::GetColorGridSize](../Topic/CMFCColorBar::GetColorGridSize.md)|Calcula o número de linhas e colunas na grade de um controle de barra de cor.|  
|[CMFCColorBar::GetExtraHeight](../Topic/CMFCColorBar::GetExtraHeight.md)|Calcula a altura adicional que a barra de cor atual necessário para exibir os diversos elementos de interface do usuário como o botão de **Outro** , documentam cores, e assim por diante.|  
|[CMFCColorBar::InitColors](../Topic/CMFCColorBar::InitColors.md)|Inicializa uma matriz de cores com cores em uma paleta especificada ou em paleta padrão do sistema.|  
|[CMFCColorBar::OnKey](../Topic/CMFCColorBar::OnKey.md)|Chamado pela estrutura quando um usuário pressiona um botão do teclado.|  
|[CMFCColorBar::OnSendCommand](../Topic/CMFCColorBar::OnSendCommand.md)|Chamado pela estrutura para fechar uma hierarquia de controles pop\-up.|  
|[CMFCColorBar::OnUpdateCmdUI](../Topic/CMFCColorBar::OnUpdateCmdUI.md)|Chamado pela estrutura para ativar ou desativar um item da interface do usuário de um controle de barra de cor antes de item são exibidas.|  
|[CMFCColorBar::OpenColorDialog](../Topic/CMFCColorBar::OpenColorDialog.md)|Abrir uma caixa de diálogo de cor.|  
|[CMFCColorBar::Rebuild](../Topic/CMFCColorBar::Rebuild.md)|Redesenho o completamente controle de barra de cor.|  
|[CMFCColorBar::SelectPalette](../Topic/CMFCColorBar::SelectPalette.md)|Defina a paleta lógica de contexto específico de dispositivo para a paleta de botão do controle pai atual da barra de cor.|  
|[CMFCColorBar::SetPropList](../Topic/CMFCColorBar::SetPropList.md)|Define o membro de dados protegidos de `m_pWndPropList` ao ponteiro especificado para um controle de grade de propriedade.|  
|[CMFCColorBar::ShowCommandMessageString](../Topic/CMFCColorBar::ShowCommandMessageString.md)|Solicitar a janela do quadro que possui o controle de barra de cor para atualizar a linha de mensagem na barra de status.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|`m_bInternal`|Um campo booleano que determina se os eventos do mouse são processados.  Normalmente, os eventos do mouse são processados quando este campo é `TRUE` e modo de personalização é `FALSE`.|  
|`m_bIsEnabled`|Um valor booleano que indica se um controle está habilitado.|  
|`m_bIsTearOff`|Um valor booleano que indica se o controle de barra de cor suporte ao encaixe.|  
|`m_BoxSize`|Um objeto de [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o tamanho de uma célula em uma grade de barra de cor.|  
|`m_bShowDocColorsWhenDocked`|Um valor booleano que indica se mostrar cores de documento enquanto a barra de cor é entrada.  Para mais informações, consulte [CMFCColorBar::SetDocumentColors](../Topic/CMFCColorBar::SetDocumentColors.md).|  
|`m_bStdColorDlg`|Um valor booleano que indica se mostrar o sistema padrão cores a caixa de diálogo ou a caixa de diálogo de [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) .  Para mais informações, consulte [CMFCColorBar::EnableOtherButton](../Topic/CMFCColorBar::EnableOtherButton.md).|  
|`m_ColorAutomatic`|[COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) que armazena a cor automático atual.  Para mais informações, consulte [CMFCColorBar::EnableOtherButton](../Topic/CMFCColorBar::EnableOtherButton.md).|  
|`m_ColorNames`|Um objeto de [CMap](../../mfc/reference/cmap-class.md) que associa um conjunto de RGB cores com seus nomes.|  
|`m_colors`|[CArray](../../mfc/reference/carray-class.md) de valores de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) que contém as cores que são exibidas no controle de barra de cor.|  
|`m_ColorSelected`|Um valor de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) que é a cor que o usuário tiver selecionado no momento do controle de barra de cor.|  
|`m_lstDocColors`|[CList](../../mfc/reference/clist-class.md) de valores de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) que contém as cores que são usadas no momento em um documento.|  
|`m_nCommandID`|Um inteiro sem sinal que é a identificação de comando de um botão de cor.|  
|`m_nHorzMargin`|Um número inteiro que será a margem horizontal entre a cor botões em uma grade de cores.|  
|`m_nHorzOffset`|Um inteiro que é o deslocamento horizontal ao centro do botão de cor.  Esse valor é útil se o botão exibe o texto ou uma imagem além de uma cor.|  
|`m_nNumColumns`|Um inteiro que é o número de colunas em uma grade de controle de barra de cor de cores.|  
|`m_nNumColumnsVert`|Um inteiro que é o número de colunas em uma grade orientada horizontalmente de cores.|  
|`m_nNumRowsHorz`|Um inteiro que é o número de colunas em uma grade orientada horizontalmente de cores.|  
|`m_nRowHeight`|Um inteiro que é a uma altura de uma linha de cor botões em uma grade de cores.|  
|`m_nVertMargin`|Um número inteiro que será a margem vertical entre a cor botões em uma grade de cores.|  
|`m_nVertOffset`|Um inteiro que é o deslocamento vertical no centro do botão de cor.  Esse valor é útil se o botão exibe o texto ou uma imagem além de uma cor.|  
|`m_Palette`|[CPalette](../../mfc/reference/cpalette-class.md) cores que são usadas no controle de barra de cor.|  
|`m_pParentBtn`|Um ponteiro para um objeto de [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) que é o pai do botão atual.  Esse valor é útil se o botão de cor em uma hierarquia de controles de barra de ferramentas ou está em um controle de grade de propriedade de cor.|  
|`m_pParentRibbonBtn`|Um ponteiro para um objeto de [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md) que está em fita e é o botão pai do botão atual.  Esse valor é útil se o botão de cor em uma hierarquia de controles de barra de ferramentas ou está em um controle de grade de propriedade de cor.|  
|`m_pWndPropList`|Um ponteiro para um objeto de [CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) .|  
|`m_strAutoColor`|[CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no botão de **Automático** .  Para mais informações, consulte [CMFCColorBar::EnableAutomaticButton](../Topic/CMFCColorBar::EnableAutomaticButton.md).|  
|`m_strDocColors`|[CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no botão de cores do documento.  Para mais informações, consulte [CMFCColorBar::SetDocumentColors](../Topic/CMFCColorBar::SetDocumentColors.md).|  
|`m_strOtherColor`|[CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no *outro* botão.  Para mais informações, consulte [CMFCColorBar::EnableOtherButton](../Topic/CMFCColorBar::EnableOtherButton.md).|  
  
## Comentários  
 Geralmente, você não criar um objeto de `CMFCColorBar` diretamente.  Em vez de isso, [Classe de CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) \(usado em menus e barras de ferramentas\) ou [Classe de CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) cria o objeto de `CMFCColorBar` .  
  
 a classe de `CMFCColorBar` fornece a seguinte funcionalidade:  
  
-   Ajustar automaticamente a lista de cores do documento.  
  
-   Salvar e restaurar seu estado, juntamente com o estado do documento.  
  
-   Gerencia o botão “automático”.  
  
-   Usa o controle de [Classe de CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md) selecionem uma cor personalizado.  
  
-   Suporta um estado fora de rasgo “\-” \(se é criada usando [Classe de CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md)\).  
  
 Para incorporar funcionalidade de `CMFCColorBar` em seu aplicativo:  
  
1.  Crie um botão normal do menu e atribua uma identificação, por exemplo ID\_CHAR\_COLOR.  
  
2.  Em sua classe de janela do quadro, substituir o método de [CFrameWndEx::OnShowPopupMenu](../Topic/CFrameWndEx::OnShowPopupMenu.md) e substitua o botão normal do menu com um objeto de [Classe de CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) \(chamando [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md)\).  
  
3.  Definir os estilos e habilita ou desabilita os recursos do objeto de `CMFCColorBar` durante a criação de [Classe de CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md) .  O objeto de `CMFCColorMenuButton` dinamicamente cria o objeto de `CMFCColorBar` depois que a estrutura chama o método de `CreatePopupMenu` .  
  
 Quando o usuário clica em um botão de controle de barra de cor, a estrutura usa a macro de `ON_COMMAND` para notificar o pai do controle de barra de cor.  Em o, macro o parâmetro de identificação de comando é o valor que você atribuiu ao botão de controle de barra de cor na etapa 1 \(ID\_CHAR\_COLOR em esse exemplo\).  Para obter mais informações, consulte as classes de [Classe de CMFCColorMenuButton](../../mfc/reference/cmfccolormenubutton-class.md), de [Classe de CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md), de [Classe de CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md), de [Classe de CFrameWndEx](../../mfc/reference/cframewndex-class.md), e de [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) .  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar uma barra de cores usando vários métodos na classe de `CMFCColorBar` .  Os métodos definem o horizontal e vertical as margens, permitem que o outro botão, crie uma janela de controle de barra de cor, e define a cor selecionada.  Este exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#1](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#1)]  
[!CODE [NVC_MFC_NewControls#2](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#2)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)  
  
 [CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcolorbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)